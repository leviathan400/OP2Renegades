# Outpost 2: Renegades

**Outpost 2: Renegades** is a four-mission Plymouth campaign for Outpost 2, made by Eddy-B and the Renegades team in
2004-2006: *Relocation*, *Onslaught*, *Consequences* and *Raid*. Its source code was lost, and some of its missions
crashed. This repository holds the campaign remade as [OP2Lua](https://github.com/leviathan400/OP2Lua) missions for
Outpost 2 with the Outpost Universe update (OPU 1.4.1).

- **Website and download:** https://renegades.outpostuniverse.org
- **Forum:** the Renegades board, https://forum.outpost2.net/index.php/board,33.0.html

## What's here

The mission files as release 1.2.0 installs them, under `OPU/maps/Renegades/`:

| Files | What |
|---|---|
| `q01Lua` ... `q04Lua` (`.dll`, `.lua`, `.placement.lua`) | The four missions: Relocation, Onslaught, Consequences and Raid. Each `.dll` is OP2Lua's mission DLL, the `.lua` its script (objectives, events, the computer player's AI) and the `.placement.lua` the units and structures it places at the start. |
| `Q01.MAP` ... `Q04.MAP`, `Q01.TEK` ... `Q03.TEK` | Renegades' own maps and tech trees, from the original campaign. |
| `ren228.wav` ... `ren234.wav` | Renegades' voice lines, played by the missions. |

The scripts are plain Lua: open a `.lua` file to see how a mission is set up and what it does.

## Playing

The campaign is played through the Renegades loader, `OPU\Renegades.exe`, which comes in the release zip on the
[website](https://renegades.outpostuniverse.org), not in this repository. The zip also has the OP2Lua runtime
(`OP2LuaCore.dll`) the missions need, and the module that gives a Renegades game its own look (the "OP: RENEGADES"
title and the R in the command pane).

1. You need Outpost 2 with OPU 1.4.1.
2. Unzip the release into your Outpost 2 folder (the one holding `Outpost2.exe` and the `OPU` folder), keeping the
   folders.
3. Start `OPU\Renegades.exe`.

The loader shows Renegades' own menus, prologue, briefings, objectives and story. It starts each mission, follows
the game, records the result and moves the campaign on after a win. `Renegades.exe /select` picks any one mission.

## The remakes

Each mission was remade from what the original does, measured by running both in the real game, not from its lost
source:

- **Relocation** (q01) plays as the original.
- **Onslaught**, **Consequences** and **Raid** (q02-q04) match their originals from the start and through their
  mission events; the computer player's AI drifts from the original later in a game.

Renegades' own in-game menu shell doesn't run on OPU 1.4.1; the loader takes its place.

## Credits

Outpost 2: Renegades was made by **Eddy-B** (copyright 2004-2006), with, from its own credits:

- mission programming: Eddy-B; additional coding: Hooman, Hacker and Cynex;
- map designs: TH300;
- additional graphics: MoogleKupoHax, Shuffles and Freeza-CII;
- novella: Gwyned;
- beta-testing: Mez, Leviathan, TH300, Baikon, PlayingOP, Invictus, op2Hacker, ZigZagJoe, Gwyned and wizisi.

The Lua remakes are by Leviathan. Outpost 2 is by Dynamix and Sierra; the Outpost Universe update (OPU) is by the
Outpost Universe community.

Questions, bug reports and play-test notes are welcome on the
[Renegades forum board](https://forum.outpost2.net/index.php/board,33.0.html).
