# Renegades' music

Renegades plays its own music in place of Outpost 2's: a song per mission, and after a win the menus play the song of
the mission just won. **The remakes don't bring it back.** The music comes from another game, *7th Legion* (1997),
so it can't be shipped with the remakes (copyright). They play Outpost 2's own soundtrack, and nothing from these
files is in a release, on the website or on GitHub.

## The files

All are in the original install, kept in SVN under `install/` as it shipped.

| File | Size | What |
|---|---:|---|
| `modren/q01.mo3`-`q04.mo3` | 162,437-216,791 | Each mission's song. MO3 (header `MO3\x01`) is Un4seen's compressed tracker-module format (the samples of an IT/XM/MOD song compressed), which BASS plays. |
| `modren/music2.mp3` | 1,990,611 | An MP3 (MPEG-1 Layer III, 128 kbit/s, 44.1 kHz: about two minutes if constant bit rate). No DLL in the install names it (below), so what plays it, if anything, isn't known. |
| `install/bass.dll` | | BASS 2.2 (packed), Un4seen's audio library, which plays the songs. |
| `install/mo3dec.exe` | 32,768 | Un4seen's MO3 decoder, shipped with the install; the missions don't call it. |
| `install/music2.wav` | 21,947,948 | Not part of the shipped install: a song a mission rendered when it unloaded (below), left from a play of the original. |

Names in the binaries (a search of every DLL and EXE in `install/` for `.mo3`, `music2`, `music1.wav`, `op2.clm`):
each mission DLL holds its own `q0N.mo3` and `music2.wav`; `renshell.dll` holds `music2.wav`; nothing holds
`music2.mp3`.

## How it plays

- **In a mission.** Each mission DLL plays its `q0N.mo3` with BASS 2.2, from the mod folder that `op2ext` reports,
  and hooks the game's music manager (the object at `0x565420` and five of its methods) so the game's own music
  stays off (`DLLS.md`, "Music through BASS"). `InitProc` stops unless `BASS_GetVersion` is 2.2 and the song loads.
  q03 jumps to order `0x1B` of its song 950 ticks into a part of the mission (`decompile/q03.md`; the remake leaves
  the jump out, `lua/q03/q03Lua.lua`).
- **Between missions.** When a mission unloads after a win it renders its own song into `music2.wav` in the game
  folder with BASS (q02 its `q02.mo3`, q04 its `q04.mo3`: `decompile/q02.md`, `q04.md`), so the menu after a
  mission plays that mission's song. (`decompile/renshell.md` says "the next track"; the mission specs say their
  own.) This render is the stall seen in headless runs: it runs while Windows holds a lock (`CRASH-LEADS.md` 8,
  `../REPORT.md`).
- **In the menus.** Renegades' menu shell finds `music2.wav` through the game's resource manager and plays every
  `.wav` in that folder in turn with Windows' MCI, on the main menu and the mission menu, when `Music=1`
  (`decompile/renshell.md`). Outpost 2's own menu track is `music1.wav`.

## In the remakes

- **No Renegades music.** The missions play Outpost 2's soundtrack as any mission does; the loader plays none.
  The loader's Preferences still has the game's own Music box (`OPU\outpost2.ini` `[Game] Music`).
- **No render between missions,** so no hang after a win.
- **The voice lines are different:** `ren228`-`ren234.wav` are Renegades' own savant lines (`extra.vol`), and the
  remakes play them (`TODO.md`, "The voice lines").
