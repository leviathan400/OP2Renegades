# renshell.dll: the Renegades menu shell

Read from Ghidra's output (`../../decompile/renshell/`), the disassembly, and the DLL's bytes, parsed with small Python
scripts. Nothing here was run in the game. Shell addresses are at its base `0x13000000`. Game addresses are
`Outpost2.exe`'s. They are checked in the OPU 1.3.6 exe (`Desktop\OP2-136`) and in the OPU 1.4.1 copy
(`Tools\renegades-test-game`), and are the same in both.

## What it is

**It's the game's own shell with a few changes.** `renshell.dll` is the stock `OP2Shell.dll` with its bytes
edited. It isn't a new build.
- **Same layout.** Its sections have the same addresses and sizes as the `OP2Shell.dll` that comes with OPU 1.3.6.
- **27 changed runs.** Apart from the import table, these are all the changes:

| Where | Stock | Renegades |
|---|---|---|
| `0x130117B2` (export DLL name) | `OP2Shell.dll` | `renShell.dll` |
| `0x13012270` (the story archive) | `STORY.VOL` | `REN.vol` |
| `0x13012314` (the colony name) | `Plymouth` | `Renegades` |
| `0x130122E4`, `0x13012328` | `%s Mission %i Menu`, `%s Mission %i: Briefing` | `%s Mission %i` (both) |
| `0x130122B4`-`0x130122D8` | `&OBJECTIVES`, `&BRIEFING`, `MAIN MENU` | `&Objectives`, `&Briefing`, `Main Menu` |
| `0x130123A0`, `0x130123B0` | `Outpost 2 Error`, `Could not open story file.` | `Renegades Error`, `Could not open ren.vol` |
| `0x13012484` (the resource DLL) | `op2shres.dll` | `renshres.dll` |
| `0x13012494` (the menu music) | `music1.wav` | `music2.wav` |
| `0x13002F83`-`0x13002FB1` (start-campaign dialog, `WM_INITDIALOG`) | sets both radio groups, colony (`0x3F6`/`0x3F7`) and difficulty | sets the difficulty group only, then calls the new code at `0x13010550`; the rest is NOPs |
| `0x13010550`-`0x130105B8` (new code, in the slack after `.text`) | zeros | adds the prologue text box (below) |
| `0x13011004` (79 bytes of `.rdata`) | debug directory | zeroed |

So nearly everything the menu does is the stock shell's behaviour, with Renegades' strings, resources and story
files.

**The pieces it uses:**
- **`modren\renshres.dll`.** The stock `op2shres.dll` edited: it still has "Outpost 2 Shell", Sierra, version
  1.2.0.5. It holds the dialogs and bitmaps (below).
- **`ren.vol` (through `ResManager`).** The text files: `CH_TITLE.TXT`, `CREDITS.TXT`, `S_P00`-`S_P04.RTF` (story),
  `B_P01`-`B_P04.RTF` (briefings), `O_P0N_E/M/H.RTF` (objectives by difficulty), `color.bmp`.
- **`RICHED32.DLL`.** For the rich-text story, briefing and objectives boxes.
- **The game's `ODASL.dll`.** The dialog skin: ordinal 1 at start-up, 8 and 9 around every modal dialog.
- **Not loaded by the shell:** `modren\ren2res.dll` (an edited `out2res.dll` that the game loads, see below) and
  `modren\helphook.dll` (Sierra's 1997 WinHelp hook, the game's).

## How it's loaded and how it hooks the game

**`op2mod.dll` loads it, not the shell.** `op2mod.dll`'s `mod_init` doesn't only add the `.vol` files.
- **The patch table.** It first copies a table of 23 string patches (`0x1F005050`-`0x1F005163`: game address, source,
  length) straight into the exe's `.data` (`0x1F001014`). There's no `VirtualProtect`; `.data` is writable.
- **What's patched.** The game addresses are below. This corrects `op2mod-renshell.md`, which says `mod_init` does
  nothing else.

| Game address | String there | Becomes |
|---|---|---|
| `0x4E96A0` (shell DLL name, pointer at `0x4E96B0`) | `OP2Shell.dll` | `RENShell.dll` |
| `0x4E5AD3` | `Failed to load OP2Shell.dll` | `... RENShell.dll` |
| `0x4E96C0` (read at `0x485C65`) | `out2res.dll` | `REN2res.dll` |
| `0x4DF36C` (read at `0x410583`, `0x4106B4`, `0x4107BC`) | `INI` | `REN`: the config file becomes `outpost2.ren` |
| `0x4E061C`+8, `0x4E0630`+8 | `SGAME%d.OP2`, `SGAME10.OP2` | `.REN` saves |
| `0x4E5AA4`+19, `0x4E5ABE` | `(*.op2)`, `*.op2` | `*.REN` in the load dialog |
| `0x4E971C` (read at `0x487737`, `0x489415`) | `P%02d.DLL` | **`Q%02d.DLL`** (one byte) |
| `0x4E973C` (read at `0x487B36`, `0x488213`) | the version, `1.3.0.4` / `1.2.0.7` | `1.0.0.0` |
| 13 texts (`0x4E484A`, `0x4E4870`, `0x4E555C`, `0x4E561A`, `0x4E57FE`, `0x4E580C`, `0x4E5AA4`, `0x4E5BE0`, `0x4E5C6C`, `0x4E5DEC`, `0x4E6124`, `0x4E7CC6`, `0x4E7CEE`) | `Outpost 2` | `Renegades` |

- **Where the `Q` comes from.** It's this table, in memory. That's why the 1.3.6 copies pass the missions' menu check
  with `P%02d.DLL` still on disk (`../HARNESS-RUNS.md`).
- **The exe stays the same.** The original bytes are whatever the exe holds: each patch overwrites a fixed length.
- **Patch sites look the same on both versions.** The strings sit at these addresses in 1.3.6 and in 1.4.1.

**The shell itself writes nothing into the exe.**
- **One fixed game address.** Its only absolute game address is in the added code: a call through the game's import
  slot `0x5837D4`. That slot is `USER32!SendMessageA` in both exes.
- **Everything else** goes through the game's exported classes, imported by name: `TApp`, `TFrame`, `IWnd`,
  `IDlgWnd`, `CConfig` (`gConfigFile`), `ResManager` (`g_ResManager`).

**Entry points:**
- **`DllMain` (`0x13001000`)**, when attached:
  1. stores its instance;
  2. loads `renshres.dll` from the path `ResManager::GetFilePath` gives, which finds it in `modren` through
     `ART_PATH`;
  3. sets up ODASL, unless `SpiffyDraw=0`;
  4. seeds `rand`, initializes the common controls and loads `RICHED32.DLL` (`0x13007B70`).

  When detached, it shuts the frame down (`0x13009350`).
- **`CreateShell(reason, GameStartInfo*)` (`0x13001060`, ordinal 1)**:
  1. creates the frame window "Outpost 2", sized from `[GAME_WINDOW]`, with bitmap 190 from `renshres.dll` as the
     background (`0x13007DC0`);
  2. stores the reason at `0x13015A40`;
  3. copies the game's 0x3DD-byte `GameStartInfo` into its own copy at `0x13015A44`, or zeroes it when given none;
  4. returns the frame object (`0x130158F0`).

  Its window procedure (`0x13007F10`) then runs the menu as posted messages `0x720`-`0x742`.

## What the player sees

The dialogs are in `renshres.dll`, by resource ID.

| Dialog | Title | Contents |
|---|---|---|
| 137 main menu | OUTPOST: RENEGADES | Outpost Renegades, Colony Games, Load Game, Preferences, Help, About Renegades, Quit. "New Tutorials" is there but disabled. "DEBUG TEST..." is hidden when the menu opens (`0x13002900`). There's no multiplayer button. |
| 140 start campaign | Outpost: Renegades --- Start Campaign | Difficulty radios "Too easy" / "Normal" (default) / "Insane", OK, Abort. A rich-text box with the prologue `S_P00.RTF` is added by `0x13010550`. The colony radio `0x3F7` is hidden at (1, −10), and `0x3F6` is gone. |
| 219 mission menu | "Renegades Mission N" | Briefing, Objectives, Story, Start Mission, Leave Campaign |
| 216 text view | "Renegades Mission N" / "... : Objectives" / "Renegades Part N" | rich text from `ren.vol`, Select Chapter / Mission Menu |
| 215 chapters | Renegades story --- Chapters | the chapter list, View Story, Mission Menu |
| 222 / 223 / 224 | Colony Games / Scores / Enter your name | the stock colony games (`c*.dll`), Easy/Normal/Hard |
| 142 | Preferences | Music, Sound, Ambient, Overlay, shadows, Intro AVI, completed objectives, volumes, game and scroll speed |
| 213 | About | `CREDITS.TXT` in a list, "Copyright 2004-2006 Eddy-B", "Version 1.0" |
| 146 | splash | bitmap 145 for 5 s (`0x13003BE0`) |
| 152, 214 | Start Debug ("Debugging is diabled"), Pick a Script | stock debug leftovers behind the hidden button |

**The flow** (window procedure `0x13007F10`, jump table `0x13009038`):
1. **Start-up** (`0x73A`, by the reason; jump table `0x130090C4`):

   | Reason | What happens |
   |---|---|
   | 1, start-up | `IntroAVI` (off in `outpost2.ren`) plays `I.AVI`, otherwise the splash; then the main menu |
   | 2 | multiplayer (`TApp::DoNetGame`) |
   | 3 | a game ended won |
   | 4 | a game ended lost |
   | 7-9 | multiplayer statistics |
   | others | the main menu |

2. **Main menu** (`0x720`). A 60-second idle timer, reset by keyboard and mouse hooks, starts a demo (`0x741`):
   `ademo1`-`3.dll` in turn, counted by the ini key `Demo`.
3. **"Outpost Renegades"** (`0x729`) opens the start-campaign dialog. On OK (`0x13002F60`) it:
   - zeroes the whole `GameStartInfo`;
   - sets the campaign flag, bit 3 of +0x00;
   - sets the mission index (+0x16A) to 0;
   - sets the colony to Plymouth: bit 2 of +0x30 cleared, bit 5 set, because the colony button no longer exists;
   - sets the difficulty in bits 3-4 of +0x30: "Too easy" 0, "Normal" 0x08, "Insane" 0x10.

   Then, with `ShowMovies` on (default), it plays `IP.AVI` (Plymouth's intro), and opens the mission menu.
4. **Mission menu** (`0x73B`, `0x130056E0`):
   - **Title.** "Renegades Mission (index + 1)".
   - **Music.** It starts the menu music if it isn't playing.
   - **Briefing** (`0x73D`) shows `B_P%02i.RTF`, with index + 1.
   - **Objectives** (`0x73C`, `0x13005A80`) shows `O_P%02i_%c.RTF`, with `e`, `m` or `h` from the difficulty bits.
   - **Story** (`0x735`) lists chapter titles from `CH_TITLE.TXT`. The file has 13 Eden lines, then 13 for
     Plymouth/Renegades: "One: Relocation", "Two: Onslaught", "Three: Consequences", "Four: Raid", then "Five: -" to
     "Twelve: -", "Epilogue". The list shows the Plymouth lines up to index + 1, so only chapters reached so far
     (`0x13004F20`). A chapter opens `S_P%02i.RTF` (`0x13005330`).
   - **Start Mission** goes to `0x733`.
   - **Leave Campaign** goes back to the main menu.

## How a mission starts and how the campaign continues

**Starting** (`0x733`, `0x130086CD`). The shell only fills in the start info and hands it to the game:
1. +0xB2 gets a seed, `timeGetTime ^ (timeGetTime << 16)`.
2. Bit 3 of +0x0C is cleared.
3. +0xAE gets `GameSpeed` (clamped to 1-10) × 4.
4. It stops the menu music.
5. It calls `TApp::StartSingleGame(&info)`, then `TApp::ActivateGame`. A 0 result goes back to the main menu.

The shell never names the mission DLL. With the campaign flag set, the game builds it from the mission index with
the format at `0x4E971C`, so index 0 loads `Q01.DLL` (`../HARNESS-RUNS.md`).

**Continuing.** It's the stock mechanism, not Renegades code.
- **The handover.** When a game ends, the game calls `CreateShell` again, with the reason and its own copy of the
  start info.
- **Won (reason 3).** The shell plays a "won" movie chosen by the mission index, then opens the mission menu. That
  menu shows the next mission, so the game must have raised the index; the shell never changes it.
  - The movies are `MPBW.AVI` after q01-q03 and `MPUW.AVI` after q04 (table at `0x13008A0C`, read at `0x13008BB2`).
  - At index 12 it plays `MPF.AVI` and opens the story instead (`0x13008B97`).
- **Lost (reason 4).** It plays `MPBL.AVI` (q01-q03) or `MPUL.AVI` (q04), and the mission menu offers the same
  mission again (`0x13008C72`).
- **The difficulty is carried along.** It stays in the start info from mission to mission, and the menu has no way
  to change it.
- **What it never does:**
  - looks for `Q0N.mis` or for the next DLL;
  - limits the campaign to four missions;
  - stores campaign progress anywhere. "Outpost Renegades" always starts at q01, and between sessions the only way
    back into the campaign is a saved game (Load Game: `TApp::GetLoadName` and `OnLoadGame`, `.REN` files after
    `op2mod`'s patch).

**After q04 (a lead, not seen).** A won q04 should give a "Renegades Mission 5" menu:
- Briefing, Objectives and the chapter "Five" would each show "Could not open ren.vol", because `B_P05`, `O_P05_*`
  and `S_P05` don't exist (`0x13007880`).
- Start Mission would ask the game for `Q05.DLL`, which doesn't exist.

## The difficulty and settings files

**The shell has no difficulty file.** The difficulty goes only into the start info, bits 3-4 of +0x30, where the
game reads it as Player 1's difficulty.
- **The missions' 0x20-byte block** isn't a shell file. It's the header of the previous mission's `Q0N.mis`, written
  by the mission DLL itself when it unloads. Its first dword is the difficulty at that mission's end (`q02.md`,
  `q03.md`, `q04.md`). `mission-framework.md`'s "settings block read from a file" is that file.
- **When "You're cheating!" can show.** Through this shell the difficulty can't change between missions. So the box
  only appears when a `Q0N.mis` comes from another run at another difficulty, or is missing on Normal or Hard (q03).
- **`ColonyGameScores` / `Difficulty%i`** (`0x13006E50`, written around `0x130074BA`-`0x13007690`) is the stock
  colony-game score table: `Count`, `Game%i`, `Name%i`, `Time%i`, `Difficulty%i` ("Easy"/"Normal"/"Hard", default
  "Normal"), `Date%i`. It has nothing to do with the campaign.

**Settings.** All the shell's settings go through the game's `CConfig`, section `[Game]`:
- the preferences: `Music`, `Sound`, `Ambient`, `Overlay`, `MobileShadows`, `StationaryShadows`, `IntroAVI`,
  `Comp_Obj`, `ScrollRate`, `GameSpeed`, `MusicVol`, `SoundVol` (`0x130032C0`);
- `SpiffyDraw`, `ShowMovies`, `Demo`;
- `[GAME_WINDOW]` `MAXIMIZED`, `H_SIZE` and `V_SIZE`.

With `op2mod`'s `INI`→`REN` patch, that file is `outpost2.ren`.

**Nothing else is stored:** no registry (no ADVAPI32 import), no version checks (the "Version"/"1.01" formatter at
`0x13009460` is stock), and no file written at mission end.

**Music.** `0x13007C60` finds `music2.wav` through `ResManager` and plays every `*.WAV` in that folder in turn, with
MCI. It subclasses the frame window for the MCI notifications (`0x13001A0E`, prop `oldmuzakproc`).
- **Where it plays.** On the main menu and the mission menu, when `Music=1`.
- **Who writes the file.** The missions render their next track into `music2.wav` when they unload (`q01.md`), so
  the mission menu between missions plays that track.

## OPU 1.4.1 versus 1.3.6

- **The shell's own fixed address is the same in both.** `0x5837D4` is `SendMessageA` in both. The exported classes
  are imported by name.
- **The difference is whether `op2mod`'s `mod_init` runs before the game loads its shell.** Under 1.3.6 (the
  Renegades op2ext, `/loadmod modren`) it does.
- **Under 1.4.1, OPU's op2ext refused `modren` in the game folder** (`../HARNESS-RUNS.md`); a 1.4.1 `/loadmod` mod
  keeps its folder in `OPU\`, so that's most likely the place (`HARNESS-RUNS.md`, "`/loadmod` on 1.4.1 after all"). Then nothing renames the shell, the config,
  `out2res` or the `P`. The game loads OPU's own `OP2Shell.dll` and there's no Renegades menu.
- **Patch sites.** All 23 are at the same addresses in both exes, with the same contents except the version string.

### Tried on OPU 1.4.1 (2026-11-18, `../../module/`)

The remakes' module (`Renegades.dll`, an op2ext module) does part of `op2mod`'s work in memory, for a game the
loader starts:
- **`out2res` → `ren2res` works**: the name at `0x4E96C0`, changed in `InitMod`. op2ext under OPU starts modules before
  `TApp::Init` (OPUPatch is one too, and patches the game from its own `InitMod`), so the game then loads
  `ren2res.dll` itself. Swapping the loaded handle at `0x56E86C` instead doesn't last: `TApp::Init` loads `out2res.dll`
  over it. Read from the running game's memory.
- **The R** (`renegmbl.raw`) works, set at `0x4FF814` once the graphics object exists.
- **The shell doesn't**: with `OP2Shell.dll` → `RENShell.dll` at `0x4E96A0` and `ren.vol` added with op2ext's
  `AddVolToList` (`renshell.dll`, `renshres.dll`, `ren.vol` in the OPU folder), the game hung leaving a mission, on its
  way back to the menus. No crash report, and the menu never showed. Not traced. Candidates:
  - OPUPatch patches the shell by module name (`Patcher::PatchContext("OP2Shell.dll")`, e.g. its main-menu
    background hook at `0x13007EB9`), so `RENShell.dll` runs without OPU's shell fixes;
  - `renshres.dll` is loaded unchecked (`0x13007B70`, below): if OPU's file search doesn't find it by that name, every
    dialog fails;
  - the `P` → `Q` patch was left out on purpose, so its campaign would have started the stock Plymouth missions.

  It's now opt-in (`RENEGADES_SHELL=1`); the loader is the menu, and it closes the game when a mission ends.

## Crash and failure leads

| Where | What |
|---|---|
| `0x13002F9D` → `0x13010550` | The added code calls `SendMessageA` through the game's import slot `0x5837D4`. Any exe whose slot differs crashes when the start-campaign dialog opens. |
| `0x13010550` | The added code lies past `.text`'s virtual size (`0x13010548`), in the file's slack. It runs because the loader maps the whole raw page. A loader or tool that honours the virtual size would leave zeros there. |
| `0x13007B70` | `LoadLibrary(renshres.dll)` isn't checked. Without `ART_PATH=modren` the instance is null, and every dialog and the background bitmap fail. `CreateShell` doesn't check the bitmap (`0x13007DC0`). |
| `0x13001060` | It copies a fixed 0x3DD bytes of the game's `GameStartInfo`. This assumes the stock struct size. |
| `0x13004F20` | Reads at most 2000 bytes of `CH_TITLE.TXT` into a stack buffer, with no terminator. Then it walks index + 14 lines with `strchr` and doesn't check for null. A mission index above 12 dereferences null. That's not reachable from q01-q04. |
| `0x13007880` | The RTF loader opens `REN.vol` with `OpenFile`, only to test it's there. On a failed stream it leaks that handle and shows "Could not open ren.vol", whichever file was missing. |
| after q04 | The "Mission 5" menu and the request for `Q05.DLL` above. |
| `op2mod` `0x1F001014` | Writes 23 strings to fixed exe addresses, unchecked. Lengths are fixed (e.g. 9 bytes of "Renegades" over "Outpost 2"). |

## Still open

- **The game's side of the handover (not read).** Which game functions call `CreateShell` with reasons 1-11, and
  where the game raises the mission index on a win. Inferred from the shell's index-12 check and the stock campaign.
- **What a won q04 really does,** with the shell, in the game (the "Mission 5" lead).
- **The start-info layout beyond the fields used here:** +0x00 bits 0-1 (set by the debug script picker and demos),
  +0x0C, +0x60 onward (statistics strings), and how the game maps bits 3-4 of +0x30 to `Player::Difficulty`.
- **The import table.** It differs from the stock shell's by about 4,900 bytes (binding or rebuild); not examined.
- **The debug path.** The "Pick a Script" dialog's procedure (`0x130049E0`), behind the hidden button, wasn't read.
- **The menu music.** Which `*.WAV` files a real install's folder holds, and the play order.
- **Whether OPU 1.4.1 can be made to run `mod_init` early enough.** Its op2ext calls modules from `TApp::Init`; when
  the shell is loaded relative to that isn't checked.
- **The splash and backgrounds.** Bitmaps 145 and 190 in `renshres.dll` weren't looked at.
