# The mission framework

All four Renegades missions are built on one framework, compiled into each DLL with the same strings, at different
addresses. Described here from q01's decompile (Ghidra, `../../decompile/q01/`). The same parts are in q02-q04: the
same strings, the 0x50-byte path buffer, `GetSaveRegions`, the event runner.

## Entry points

| Export | What it does (q01) |
|---|---|
| `DllMain` | Swaps the game's graphics table entry at `0x4FF814` for `renegmbl.raw` (`../DLLS.md`). Stores the DLL's own path for later (`0x110046D0`, into the 0x50-byte buffer at `0x1101218C`). Prepares the music (`q01.mo3`, `0x11003862`). |
| `InitProc` (`0x11002D9F`) | Checks for the campaign's `Q` (`0x11003F46`), which `op2mod.dll` writes into the game. Then the setup: colony, units, objectives, and the first events. |
| `AIProc` (`0x11004730`) | Only runs the event list (`0x11004900` on the list at `0x110121E0`). All the mission's logic after the setup is in its events. |
| `GetSaveRegions` (`0x11004630`) | Gives the game the `.save` section to save: `ImageLoad` of its own path, then the section named `.save`. It also takes the DLL's `TimeDateStamp` for the save check. `../CRASH-LEADS.md` 1. |
| `StatusProc`, `UninstallMusicHook`, `NoResponseToTrigger` | Status for the shell or game; removing the music hook; the callback of triggers that call nothing. |

## Events

The mission's own trigger system, kept entirely in the `.save` section, so it's saved with the game.

**The list** (`0x110121E0`): an array of pointers and a count, at most 512 (0x200).
- Adding an event already listed does nothing.
- Adding one to a full list shows "Maximum number of events reached!" (ERROR) and drops it (`0x11004810`).

**The runner** (`0x11004900`, every game cycle from `AIProc`):
1. Checks the save's timestamp (`0x110048C0`). The first time, a fresh game takes the DLL's own `TimeDateStamp`. A
   save whose stamp differs gets "WARNING !! Timestamp does not match DLL. This saved game might crash!" once.
2. Walks the list from the end. Each event that is active and not marked "skip this pass" runs (its first virtual
   method). Every event's "skip" mark is then cleared, so a new event runs from the next cycle.
3. Each run is inside a C++ exception handler. An exception shows "Error executing event %02X ID=%02X
   CallBack=%08X" (EventError), and the runner goes on.
4. A second pass removes the events marked for deletion and frees them (`0x110049E0`).

**An event** (base at `0x11004740`/`0x11004780`):

| Offset | What |
|---|---|
| +0x00 | vtable |
| +0x04 | 2 bytes, zeroed |
| +0x06 | flags |
| +0x08 | a user value passed to the callback |
| +0x0C | the callback |

The flags:

| Bit | Meaning |
|---|---|
| 0x01 | active |
| 0x02 | repeating |
| 0x04 | one-shot |
| 0x08 | new: skip the pass it was made in |
| 0x20 | delete |

Firing (`0x110047C0`) calls the callback; a one-shot event then marks itself for deletion.

**The four kinds:**

| vtable | Run method | Size | What it waits on |
|---|---|---|---|
| `0x1100C328` | `0x110040E0` | 0x20 | **Time.** A due tick and a range: +0x10 minimum, +0x14 maximum, +0x18 due, +0x1C the last tick seen. It fires once the game tick reaches the due tick. A repeating one is then due again after the minimum plus `GetRand(maximum − minimum)`, or exactly the minimum when they're equal (`0x110040A0`). Made by `0x11004120`. |
| `0x1100C32C` | `0x11004220` | 0x20 | **A unit count.** For player +0x10 (when that player exists), count the units of type +0x14 with weapon or cargo +0x18 (`0x1100135C`). Compare the count with +0x1C by the comparison at +0x11 (`0x11004B20`). Made by `0x11004270`. |
| `0x1100C330` | `0x11004390` | 0x14 | **A group's losses.** Group id at +0x10, its unit count when the event was made at +0x11. The threshold at +0x12 is three quarters of that count (mode 2), half (mode 3) or 0. It fires when the group has that many units or fewer. Made by `0x11004410`. |
| `0x1100C334` | `0x110044D0` | 0x24 | **An area.** A map rectangle (+0x14) and a byte (+0x10, probably the player). Made by `0x11004540`. |

## Memory: a pool inside `.save`

- **The pool.** Events are allocated from a pool inside the `.save` section (`0x11004A40`): 2,048 blocks of 16 bytes
  from `0x110129E8`, with a map of one byte per block at `0x1101A9E8`.
- **Map bytes.** Each one says how many blocks an allocation takes (0xFF for the blocks after the first). Freeing
  (`0x11004AD0`) clears them, and rejects a pointer whose map byte is out of range ("delete: Invalid pointer
  supplied").
- **Out of room.** The pool running out takes the C runtime's "new: Out of memory" path.
- **Why it's done this way.** Because the events live in `.save`, they survive a save and reload. So do their vtable
  and callback addresses, which is `../CRASH-LEADS.md` 2.

## The other checks

- **Menu.** `0x11003F46` returns whether the byte at `0x4E971C` is `'Q'`: the game's `"P%02d.DLL"`, which `op2mod.dll`
  patches when the game starts with `/loadmod modren` (`op2mod-renshell.md`).
- **Won?** `0x11003F53` returns whether the game's end reason at `0x56EB34` is 3, MissionAccomplished. On unload the
  DLL writes its carry-over `Q0N.mis` when it is (q03's test is the other way round: `../CRASH-LEADS.md` 7).
- **Difficulty.** A 0x20-byte block read from a file (q04 `0x110118D0`), whose first dword must equal
  `_Player::Difficulty()` for player 1. Otherwise "You're cheating!", and the difficulty is reset (`../DLLS.md`).
- **Message boxes.** All through the game's own `OP2MessageBox` (`0x41E0E0`), called through a pointer the DLL keeps
  in its data (`0x1100C33C` in q01).
