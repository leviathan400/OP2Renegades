# What the Renegades DLLs do

Found by running the DLLs in op2-missionhost (op2dll `inspect`, `calls`, `forecast`) and reading their bytes at the
addresses involved (`tools/`), 2026-11-12. None of it has been checked in the game yet. Game addresses are those of
GOG 1.2.0.7's `Outpost2.exe`, on which OPU 1.4.1 builds; mission addresses are at the DLLs' base, `0x11000000`.

## The files

| File | What |
|---|---|
| `modren/q01.dll`-`q04.dll` | The four missions (campaign missions 1-4, Plymouth). |
| `modren/ren.vol`, `ren1.vol` | The maps (`Q01.MAP`-`Q04.map`) and tech trees (`Q01.tek`-`Q03.tek`). |
| `modren/op2mod.dll` | Adds the mod's `.vol` files to the game, with `op2ext`'s `AddVolToList`. |
| `modren/q0N.mo3` | Each mission's music (MO3); `modren/music2.mp3` another track no DLL names. All from *7th Legion* (1997): not reused (`MUSIC.md`). |
| `install/renshell.dll` | The Renegades menu shell. It uses OPU's `ODASL.dll` and `op2ext`'s `StubExt`. |
| `install/op2extra.dll` | An `IUnit` class the missions call (below). It imports only `kernel32`. |
| `install/op2ext.dll` | The 2006 community extension: `GetGameDir`, `GetCurrentModDir`, `AddVolToList`. |
| `install/bass.dll` | BASS 2.2 (packed), the music library. |
| `install/renegmbl.raw` | A 29,484-byte image, 156 × 189: swapped into the game's graphics by each mission's `DllMain`. |
| `install/outpost2.ren` | The mod's `outpost2.ini`: game options and `ART_PATH=modren`. |

## What every mission DLL imports

- **The game API** (`Outpost2.exe`): 109 functions (q01) to 154 (q03).
- **BASS 2.2:** `Init`, `Free`, `GetVersion`, `ErrorGetCode`, `SetConfig`, `MusicLoad`, `MusicFree`,
  `StreamCreateFile`, `ChannelPlay`, `ChannelStop`, `ChannelIsActive`, `ChannelGetInfo`, `ChannelGetPosition`,
  `ChannelSetPosition` and `ChannelGetData`.
  - The argument counts, read from the missions' call sites, are 2.2's: `StreamCreateFile` 5, `MusicLoad` 6,
    `ChannelSetPosition` 3 dwords, `ChannelGetPosition` 1. 2.4 widened them.
  - The calls go through `jmp [IAT]` thunks.
- **`op2ext.dll`:** `GetGameDir(char*)` (cdecl, a 0x50-byte buffer) and `GetCurrentModDir()` (cdecl, returns a
  string, null without a mod).
- **`imagehlp.dll`:** `ImageLoad` and `ImageUnload`.
- **`op2extra.dll`:** an `IUnit` class. Each mission uses its own selection of:
  - `GetDamage`, `GetBusy`, `GetCargo`, `GetFactoryCargo`, `GetTruckCargo`, `GetLights`, `IsIdled`, `IsInRect`;
  - `Repair`, `Salvage`, `Poof`, `Dismantle`, `Build`, `SetOffensive`, `SetEMPticks`, `Doze`.

  `op2extra.dll` imports nothing from the game, so these must read and write the game's unit memory at fixed
  addresses. Not decompiled yet.
- **`user32`:** `MessageBoxA`. **`kernel32`:** the usual C runtime set, with `CreateFileA`, `GetFileSize` and
  `ReadFile`.

Exports beyond a mission's usual ones:
- all four: `StatusProc`, `NoResponseToTrigger`, `UninstallMusicHook`, and two `IUnit` methods of their own;
- q02 and q03: `InitMap`;
- q02: `Research3304Done`, `Research3305Done`, `Research3401Done`;
- q04: `gotCodes`, `gotNothing`, `gotPanther`, `gotRPG`, `gotRareOre`, `gotScientists`.

## The special things

### They only run from the Renegades menu

`InitProc` first calls a check (q01 `0x11003F46`): is the byte at `0x4E971C` `'Q'`? If not, it shows "Please run
Renegades missions from the Renegades game menu" with the game's own message box and returns.
- `0x4E971C` is the game's file name format for Plymouth campaign missions, `"P%02d.DLL"` (next to `"E%02d.DLL"`).
- `op2mod.dll` patches it to `"Q%02d.DLL"` when the game starts with `/loadmod modren` (one of its 23 patches,
  `decompile/op2mod-renshell.md`), so the Plymouth campaign slot loads `Q01.DLL`-`Q04.DLL`. The menu shell doesn't.
- The string is at that address in the GOG 1.2.0.7 exe, so Renegades' hard-coded game addresses look right for OPU.

The next function along (q01 `0x11003F53`) tests whether the dword at `0x56EB34` equals 3. Not traced yet.

### `DllMain` swaps in their own image

q01 `0x1100107A`:
1. Saves the game's dword at `0x4FF814`.
2. Reads the whole of `renegmbl.raw` (`CreateFileA`, `GetFileSize`, `malloc`, `ReadFile`).
3. Writes `buffer - [[0x546B98] + 0xEC]` to `0x4FF814`.

- `[0x546B98]` is a graphics object the game creates with its SpriteManager (`0x4EFD68`, set at `0x404236`).
- `0x4FF814` isn't used as a literal anywhere in the exe, so it's an entry in a table the game indexes.
- The image is 156 × 189, presumably the Renegades emblem in place of a game one. Which picture it replaces isn't
  checked.

### Music through BASS, hooked into the game's music manager

The files, the menu music and why the remakes leave it out: `MUSIC.md`.

- **The hook table.** Every mission holds this table (q01 `.data`): `0x400000`, `0x565420`, `0x450ED9`, `0x450F28`,
  `0x450340`, `0x450DC0`, `0x450E63`. These are the game object at `0x565420` and five of its methods.
  `MusicManager::SetMusicPlaylist` is at `0x4511B0` beside them, so it is almost certainly the music manager.
- **Exports.** The missions export `UninstallMusicHook`.
- **Playback.** They play their `q0N.mo3` with BASS, from the folder `op2ext` reports. `InitProc` stops unless
  `BASS_GetVersion` is `0x20002` (2.2) and a load returns a handle.

### A difficulty check against the previous mission's carry-over

- **The check.** The setup reads 0x20 bytes from a file into a block whose first dword it compares with
  `_Player::Difficulty()` for player 1 (q04 `0x11004252`, block at `0x110118D0`).
- **When they differ:** it shows "You're cheating!\r\nDifficulty reset to %s :-þ" (q04).
- **Which file:** the previous mission's `Q0N.mis`. Its 0x20-byte header holds the difficulty that mission was played
  at and player 1's stores (`decompile/q04.md`, `decompile/renshell.md`). The menu writes no settings file.
- **In op2-missionhost:** without the file the block stays 0 (Easy). So the op2dll runs give each difficulty the
  carry-over of a campaign played at it (`../runs/README.md`).

### Their own save section

Each mission finds its own `.save` section by name, through `ImageLoad` on its own path, and records its address and
size. The section is 0x91E8 (q01) to 0x9984 (q04) bytes. It presumably backs `GetSaveRegions`, saving the mission's
state with the game.

### Their own error checks

Each shows these with the game's message box (`0x41E0E0`, called through a pointer the DLL keeps). They're leads for
the crash hunt:
- "Maximum number of events reached!" (ERROR): a fixed-size event table.
- "WARNING !!\r\nTimestamp does not match DLL\r\nThis saved game might crash!": loading a save made with another build
  of the DLL.
- "Error executing event %02X\r\nID=%02X\r\nCallBack=%08X" (EventError).
- q02: "Error reading file at %04X:\r\n(%04X,%04X)= %04X" (DEBUG).

## What op2-missionhost needed

See `../op2-missionhost/README.md`.
