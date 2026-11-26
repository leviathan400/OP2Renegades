# Crash leads

Places in the DLLs that can crash the game or break a unit. They were found by decompiling the DLLs with Ghidra
(`../decompile/`, `decompile/*.md`) and are not yet reproduced in the game. Each one says how to check it. Addresses
are q01's unless named. All four missions share the framework involved, at other addresses.

## 1. A long install path crashes the mission at start or save (very likely)

- **What happens.** The mission keeps its own full path in an 80-byte buffer (`0x1101218C`). It fills it with
  `GetModuleFileNameA(module, buffer, 0x50)`. `GetSaveRegions` (`0x11004630`) passes the buffer to `imagehlp`'s
  `ImageLoad` to find its `.save` section, and uses the result without checking it.
- **The failure.**
  1. A path of 80 characters or more is truncated.
  2. `ImageLoad` then can't find the file and returns null.
  3. `GetSaveRegions` reads through null (`+0x14`, `+0x18`, `+0x0C`) and crashes.
- **When it runs.** The game calls `GetSaveRegions` when the mission starts and when it saves. So Renegades would
  crash on some installs and not others, depending only on where it's installed.
- **Example.** `C:\Program Files (x86)\GOG Galaxy\Games\Outpost 2\OPU\mods\Renegades\modren\q01.dll` is 83
  characters.
- **Where.** All four missions keep the path in a 0x50-byte buffer: q01 `0x1101218C`, q02 `0x1101C2A8`, q03
  `0x11029180`, q04 `0x11020930`.
- **To check.** Install it under a long path and under a short one, and compare.

## 2. A saved game can crash if the DLL loads at another address (likely)

- **What gets saved.** The missions' events (the event table at `0x110121E0`, objects from a pool at `0x110129E8`)
  live in the `.save` section, which the game saves and restores. Each event holds absolute addresses: its vtable
  (`0x1100C328` for one kind) and the callback it runs.
- **The failure.** Those addresses are only right if the DLL loads at its own base, `0x11000000`. If Windows relocates
  it when a save is loaded, because something else already sits there, the first `AIProc` calls through stale
  pointers.
- **What the authors guarded.** The missions do warn when a save comes from another build: "Timestamp does not match
  DLL. This saved game might crash!", comparing the DLL's PE `TimeDateStamp`. Nothing guards against relocation.
- **To check.** Load a save with another DLL loaded at `0x11000000` first, or see whether OPU 1.4.1's own modules use
  that range.

## 3. `op2extra.dll`'s `SetEMPticks(0)` wipes a unit's flags (real, but no mission takes that path)

- **The bug.** `IUnit::SetEMPticks(t)` (`op2extra` `0x1000190F`) sets the EMP timer (+0x50). For `t ≠ 0` it sets only
  the EMP bit (bit 19 of the flags at +0x44). For `t = 0` it writes 0 to the **whole** flags word at +0x44. That
  clears whether the unit is a vehicle or a building, can be damaged, is Eden's, is offensive, and has its lights on.
- **Who calls it.** Only q04 calls it, and with `-1` (EMPed for good), so the wipe never happens in these missions. A
  remake must not copy it.

## 4. `SetOffensive` changes what the game thinks a unit is

- **What it does.** `IUnit::SetOffensive` (`op2extra` `0x1000195E`) toggles bit 4 of the flags at +0x44,
  `MoFlagOffensive`, "unit is a combat unit type" (TethysAPI).
- **Who calls it.** q03 turns Microwave units non-offensive and back. q04 turns its damaged Panther non-offensive.
- **The risk.** Game code that trusts that bit for a Lynx or Panther may misbehave. Not observed yet.

## 5. Events that throw are hidden behind a message box

- **What the runner does.** The event runner (`0x11004900`, from `AIProc`) runs each event inside a C++ exception
  handler. A failing event shows "Error executing event %02X ID=%02X CallBack=%08X" and the game goes on.
- **What it hides.** Hardware faults (access violations) are not C++ exceptions in this build, so those still crash.
  When players report that box, the callback address in it names the event that failed.

## 6. Fixed-size tables

- **Events:** at most 512. More shows "Maximum number of events reached!", and the event is dropped, so whatever it
  would have done never happens.
- **The pool:** 2,048 blocks of 16 bytes (32 KB). When it runs out, the C runtime's "new: Out of memory" error path
  ends the game.
- **The risk.** A long game that keeps adding events without removing them can hit either limit.

## 7. Winning q03 leaves q04 unable to start (found in headless runs, confirmed in the code, not yet seen in a played game)

- **The carry-over.** q02, q03 and q04 each start from a file the mission before wrote into the game folder when its
  DLL unloaded: `Q01.mis`, `Q02.mis`, `Q03.mis`. Without it their setup returns 0 and the game says "Could not
  initialize game" (`HARNESS-RUNS.md`).
- **The fault.** q01 writes its file when the game's end reason (`0x56EB34`) is 3, MissionAccomplished. q03 tests the
  other way round (`0x11006A33`, used at `0x11005F7F`): it writes `Q03.mis` only when the mission was not won. The
  branch after the check is `JZ` in q01 (`0x110038B7`) and `JNZ` in q03 (`0x11005FD4`). A won q03 also skips
  rendering `music2.wav` (`decompile/q03.md`).
- **What a player sees.** After winning q03, q04 fails to start, unless a `Q03.mis` from an earlier lost or abandoned
  q03 is still in the game folder. Then q04 starts from that older, wrong state.
- **To check.** Win q03 in a played game, then start q04.

## 8. Unloading a won mission stalls while rendering the next music (seen in headless runs)

- **What happens.** After writing its `.mis` file, the unloading DLL decodes the next mission's music to
  `music2.wav` with BASS (`BASS_Init`, a stream, a loop writing the samples; q01 `0x11001106`). It runs inside
  `DLL_PROCESS_DETACH`, while Windows holds the loader lock.
- **Seen.** In the harness runs (music off), q01, q02 and q03 stopped there every time, before the file was opened,
  until the run's timeout. BASS starting its threads under the loader lock would deadlock like that.
- **In a played game** the music is on, so BASS may already be running and skip that. Not checked. If it does stall,
  the game would freeze between a won mission and the next one.

## Not crashes, but differences under OPU

- **Music.** The missions replace the music manager's methods (`0x565420`, `0x450340`-`0x450F28`) to play `.mo3`
  files through BASS 2.2. OPU 1.4.1 changes the game's music code. If those methods moved, the hooks would land in
  the wrong place.
- **Graphics.** `DllMain` points a graphics table entry (`0x4FF814`) at `renegmbl.raw`, relative to
  `[0x546B98]+0xEC`, with no check that the object exists.

## 9. op2ext's `/loadmod` overflows a heap block (found 2026-11-12; the game dies at start, or not, by luck)

- **The fault** (OPU 1.3.0.5's op2ext, read from its disassembly):
  - `GetCurrentModDir()` (`0x1000130E`) returns `_strdup(the mod folder)` (`0x100013F7`), a block exactly as long as
    the path.
  - The `/loadmod` start (`0x100013FF`) appends `\op2mod.dll` to that copy with `strcat` (`0x1000144D`), writing 11
    bytes past the block.
- **What happens.** Whether that hits anything depends on the heap's layout, which the environment and the account
  move.
  - The user's normal PowerShell: the game died at start every time, in ntdll's heap code. That was op2ext's next
    allocation, `AddVolToList`, from `op2mod.dll`'s `mod_init` (`../runs/`, OP2TestHarness's `crash.txt`).
  - The same command as administrator, or from another session: no crash.
- **Renegades' own 2006 op2ext** (the one its installer puts in) appends `\op2mod.dll` the same way, in place
  (`0x100014A7`-`0x100014C6`). Its mod folder function returns a copy made the same way as far as read, so it very
  likely has the same overflow. Not fully traced.
- **The likely effect.** Some "Renegades crashes at start" reports, on some machines and accounts, and "run it as
  administrator" fixing it.
- **OP2TestHarness** patches the 1.3.0.5 build when it starts the game (`harness.log`: "op2ext 1.3.0.5: ...").
- **For players.** A remake that doesn't depend on that op2ext avoids it.

## 10. Finishing q03 with no Lynx leaves q04 unable to start (seen in a headless run, 2026-11-17)

- **The rule** (`decompile/q04.md`, "The carry-over from `Q03.mis`"). q04 carries over only Player 1's Microwave and
  Stickyfoam Lynx from `Q03.mis` and shares them out over eight start slots. When it counts none, its setup returns 0
  (`0x11004348`), and the game says "Could not initialize game".
- **The count skips the first unit record it keeps** (`0x11004FBB`). So a q03 that ends with one Lynx can count as
  none, if that Lynx is the first vehicle in the file. Not checked.
- **Seen.** In the Hard campaign run, q03 ended at tick 5000 with no Lynx left, and q04 failed to start. The same run
  on Easy (4 Lynx) and Normal (2) started it (`HARNESS-RUNS.md`). op2dll's q04 setup on that `Q03.mis` stops at the
  same place (`../runs/q04-setup-calls-Hard.txt`).
- **What a player sees.** Losing every Lynx in q03, then going on to q04: "Could not initialize game", and no way on
  but replaying q03. With few Lynx, the slots overrun into the next tables, and some start on wrong tiles
  (`decompile/q04.md`).
- **For the remakes.** Give q04 a fixed minimum start force, or let it start without carried Lynx.

## 11. Removing a unit from a group it isn't in faults the game (found in the Lua remakes, 2026-11-17)

- **Seen.** q03's Lua remake crashed the game twice in fed 90,000-tick headless runs (OPU 1.4.1), both inside
  `ScGroup::RemoveUnit` (`0x00479C30`), faulting at `0x0042BD94`-`0x0042BDDB` ("couldn't read 0x00000002"):
  - removing a ConVec from player 3's builders after another event had moved it to the Exit group;
  - removing player 3's Structure Factory a second time while moving the builders into a new group: the group lists
    it twice, because `0x11003880` takes it again (its last `TakeUnit(local_18)` gets the factory when no ConVec was
    made).
- **The originals.** q03 checks membership before it removes (`0x11001F55` with `0x11007720`), and its group mover
  (`0x11007520`) walks a `GroupEnumerator`; its fed runs on OPU 1.3.6 didn't crash. q02's south base
  (`0x11002C1C`) removes the closest ConVec, of any owner, from the west rebuild group **without** a check, so the
  original could hit this when that ConVec isn't in the group. Not seen yet.
- **In the remakes.** Every removal checks membership first, and a group's units are moved once each.

## 12. A kept unit's id is reused after it dies, and orders go to the new unit (found in the Lua remakes, 2026-11-17)

- **Seen.** q04's Lua remake crashed the game on Normal at tick 7,100 (OPU 1.4.1), in the game's own code
  (`0x0040A104`, under the window procedure), right after an order to doze. Player 2's Robo-Dozer had died at tick
  5,100 (command 47, Death); the game gave its id to another unit, and the dozing step (every 400 ticks) went on
  ordering whatever unit held it. Stopping the dozing with the dozer ended the crash.
- **The originals.** They keep units by id the same way, and `IsLive()` is true for the new unit. q04's dozing step
  (`0x11002080`) only checks that the command isn't Doze before ordering the next rectangle, so a dead dozer's id gets
  doze orders. q04's original didn't hit it in these runs (its dozer survived on Normal); it would when the dozer dies
  before its last rectangle. Other kept units (Eden's Scouts in q04, q03's salvage truck and the defectors' Evac) are
  checked with `IsLive()` alone too.
- **In the remakes.** A kept unit is checked for its type as well before it's given orders or counted as standing.

## 13. q03: Plymouth settling a second time destroys a group its Factory still reinforces (found 2026-11-19)

- **Seen.** q03's remake, Normal, seed 1, fed 3,000 food every 1,000 ticks (`run-mission.py ... --difficulty 1
  --ticks 90000 --script feed.txt`), OPU 1.4.1: at mark 556 (tick 55,607) an access violation at `0x427031` reading
  `0x2F0`, in the game's `BuildGroup::ProduceReinforcements` (`0x426F50`; the function index of the op2decompile
  knowledge base), which walks a building group's vehicle-reinforcement records and reads each target group. Repeats
  exactly with seed 1.
- **Why** (a run logging every record, unrecord and destroy):
  - m144: Plymouth settles (`0x1100301D`) the first time: player 3's Builders group is unrecorded once, destroyed and
    remade;
  - m295: part 3 (`0x11003B26`) records the new Builders with player 3's Factory;
  - m547: part 5 (`0x11003CD5`) records the same Builders **again**;
  - m556: Plymouth settles a second time (after tick 50,000 or Eden's waves passing size 9): one `UnRecordVehGroup`
    takes off one of the two records, the group is destroyed, and the Factory's next pass reads the other record's
    destroyed group.
- **The original does the same.** q03.dll's part 5 and part 3 both call `RecordVehReinforceGroup` for the Builders and
  Plymouth settling calls `UnRecordVehGroup` once (`../decompile/q03/imports.tsv`, the callers of each). The game's
  `RecordVehReinforceGroup` (`0x425A10`) appends a record without looking for a duplicate and `UnRecordVehGroup`
  (`0x425AD0`) removes the first match only (op2decompile's annotations). So the original crashes whenever Plymouth
  settles after part 5 has run.
- **When a game gets there.** Plymouth settles again 2000 ticks after Eden's attack manager stops (after tick 50,000,
  or once its waves pass size 9); part 5 comes 4200 ticks after part 4 (a working Advanced Lab). In the headless runs
  of the original's behaviour the second settle came first, so they never crashed; a game where Plymouth's Advanced
  Lab comes earlier does. First seen in a run of a trial Mining 3 change that did exactly that (later dropped,
  `../TODO.md`).
- **Shown on the original's behaviour** (2026-11-19): a test-only hook calling Plymouth settling 900 ticks after part 5,
  fed runs, seed 1. The committed remake (as the DLL) crashed at `0x427031` at Easy, Normal and Hard (m642, m590, m599).
- **Fixed in the remake** (`../lua/q03/q03Lua.lua`, `record_ply_builders` and Plymouth settling): the records are
  counted and all taken off before the group is destroyed. With the same hook: no error at any difficulty, through
  up to six settle cycles. Without the hook, the fixed remake plays exactly as before, unit for unit, at every
  difficulty to the end of the runs (tick 90,000 Easy; lost at 73,480 Normal, 65,544 Hard): nothing else changes,
  Eden's AI included.

## 14. q03: Mining 3 takes a vehicle as its smelter (seen in a played game, 2026-11-24; cause read, not yet reproduced)

- **Seen.** q03's remake 1.2.15, Easy, played from the loader: at mark 874 (tick 87,427, after the defectors came at
  mark 734) an access violation at `0x47B5F5` reading `0x4`, in the game's own AI tick, not in the script
  (`OPU\logs\OP2Lua-q03Lua.log`). The stack, read with op2decompile's index: `LevelDLL.ProcessTriggers` (`0x403230`,
  the groups' AI step) → `MineGroup.FindAssociatedSmelter` (`0x429F40`, returning at `0x42A028`) → `0x444FE0` →
  `0x47B5E0`.
- **Why.** `FindAssociatedSmelter`, with a smelter unit set, calls slot 40 of that unit's vtable, a structure check.
  Read from `Outpost2.exe`: slot 40 is `0x483710` for most structures, the smelters
  among them, but `0x444FE0` for the Lynx, Panther, Scorpion,
  Scout, Spider, Robo-Miner, GeoCon, Earthworker, Repair Vehicle and Evac Transport, code that
  treats its argument as a stream and faults. So the group's smelter was a vehicle. `RemoveDeadAndCapturedUnits`
  (`0x4299B0`) clears a dead or captured smelter, but not a live one of the wrong kind, so it must have been one of
  Eden's own vehicles.
- **How it gets one.** Mining 3's setup (`0x11002B0D`) takes the first unit of any kind on `(0x65, 6)` and
  `(0x37, 0xA)`, and its tile event on `(0x65, 6)` repeats, firing every cycle while Eden's mine stands there. Once
  the smelter on `(0x37, 0xA)` is gone, an Eden vehicle passing its tile becomes the smelter, and the first truck
  carrying ore crashes the game. The save at mark 729 (`SGAME1.REN`) still had Mining 3 with a real mine (#149) and
  smelter (#40).
- **The original does the same** (`../decompile/q03/decompiled.c`, `FUN_11002b0d`: two `LocationEnumerator`s, no
  type check).
- **Fixed in the remake** (`../lua/q03/q03Lua.lua`, `mining_3`): the setup runs only with a Common Ore Mine and a
  Common Ore Smelter on those tiles; the Factory record, the truck count and the truck park's move still run every
  time, so Eden's Factory plays as before. Not yet checked with a run that destroys Eden's smelter.
