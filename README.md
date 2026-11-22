# Outpost 2: Renegades

**Outpost 2: Renegades** is a four-mission Plymouth campaign for Outpost 2, made by Eddy-B and the Renegades team in
2004-2006: *Relocation*, *Onslaught*, *Consequences* and *Raid*. Its source code was lost, and some of its missions
crashed. This repository holds the campaign remade as [OP2Lua](https://github.com/leviathan400/OP2Lua) missions for
Outpost 2 with the Outpost Universe update (OPU 1.4.1).

- **Website and download:** https://renegades.outpostuniverse.org
- **Forum:** the Renegades board, https://forum.outpost2.net/index.php/board,33.0.html

## What's here

Release 1.2.11, file for file as its zip installs it (the zip's SHA-256 and every file's are in
[docs/FILES-1.2.11.md](docs/FILES-1.2.11.md); what changed in each release is in [CHANGELOG.md](CHANGELOG.md), and the
earlier releases' files and hashes in [docs/FILES-1.2.10.md](docs/FILES-1.2.10.md), [docs/FILES-1.2.8.md](docs/FILES-1.2.8.md) and
[docs/FILES-1.2.0.md](docs/FILES-1.2.0.md)):

| Files | What |
|---|---|
| `OPU/Renegades.exe` | The Renegades loader: the campaign's menus in Renegades' own look. It starts each mission and follows the game. |
| `OPU/Renegades.dll`, `OPU/ren2res.dll` | The module that gives a Renegades game its own look (the "OP: RENEGADES" title, the R in the command pane), and Renegades' in-game art it uses. |
| `OPU/OP2LuaCore.dll` | The [OP2Lua](https://github.com/leviathan400/OP2Lua) runtime (0.8.6) the missions need. |
| `OPU/op2launcher.exe`, `OPU/Launcher.dll` | Start a mission straight from the loader. |
| `OPU/renegades/` | Renegades' menu art and texts (`renshres.dll`, `ren.vol`), the R (`renegmbl.raw`), the loader's background (`background03.png`), its texts in English, German, Spanish, French and Portuguese (`lang.en.ini`, `lang.de.ini`, `lang.es.ini`, `lang.fr.ini`, `lang.pt.ini`) and the install notes with the credits (`README.txt`). |
| `OPU/maps/Renegades/q01Lua` ... `q04Lua` (`.dll`, `.lua`, `.placement.lua`) | The four missions: Relocation, Onslaught, Consequences and Raid. Each `.dll` is OP2Lua's mission DLL, the `.lua` its script (objectives, events, the computer player's AI) and the `.placement.lua` the units and structures it places at the start. |
| `OPU/maps/Renegades/Q01.MAP` ... `Q04.MAP`, `Q01.TEK` ... `Q03.TEK` | Renegades' own maps and tech trees, from the original campaign. |
| `OPU/maps/Renegades/ren228.wav` ... `ren234.wav` | Renegades' voice lines, played by the missions. |
| `module/` | Not in the zip: the source of `Renegades.dll` and how to build it ([module/README.md](module/README.md)). |

The release has no `outpost2.ini`, so the game's own settings stay as they are, and no `Renegades.ini`: the loader
writes its settings on its first start, so unzipping a newer release over an older one keeps your campaign. The
mission scripts are plain Lua: open a `.lua` file to see how a mission is set up and what it does.

## Playing

1. You need Outpost 2 with OPU 1.4.1.
2. Download the release zip from the [website](https://renegades.outpostuniverse.org) and unzip it into your
   Outpost 2 folder (the one holding `Outpost2.exe` and the `OPU` folder), keeping the folders. Copying this
   repository's `OPU` folder there does the same, with an empty `OPU\logs` folder added (Git keeps no empty folders),
   where OP2Lua writes the missions' logs.
3. Start `OPU\Renegades.exe`.

The first start registers the module with OPU (two lines in `OPU\outpost2.ini`); it only acts on a game the loader
starts. The loader shows Renegades' own menus, prologue, briefings, objectives and story. It starts each mission at
the difficulty you picked, follows the game, records the result and moves the campaign on after a win; each mission
after the first starts from what you won the one before with. `Renegades.exe /select` picks any one mission.

The loader speaks English, German, Spanish, French and Portuguese: your Windows language on the first start if it has it,
else English; change it in its Preferences. To translate it, copy `OPU\renegades\lang.en.ini` to
`lang.<code>.ini` and translate the quoted texts.

The loader opens with its new background, sized to fit your screen. For the original look, Renegades' own picture in
a smaller window, set `ClassicBackground=1` in `OPU\renegades\Renegades.ini`.

To update, unzip the new release over the old one.

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

The Lua remakes are by Leviathan. Outpost 2: Divided Destiny is by Dynamix and Sierra; the Outpost Universe update (OPU) is by the
Outpost Universe community.

Questions, bug reports and play-test notes are welcome on the
[Renegades forum board](https://forum.outpost2.net/index.php/board,33.0.html).

## Helping

Renegades is a community effort. [TODO.md](TODO.md) lists what's planned and where help is welcome: play testing,
the open questions about the missions, new art, translations and the loader. Say what you think, or what you'd like to
take on, on the forum board.
