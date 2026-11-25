# Renegades.dll

The source of `OPU\Renegades.dll`, the module that gives a Renegades game its own in-game look. It's an
[op2ext](https://github.com/OutpostUniverse/op2ext) module for Outpost 2 with OPU 1.4.1, loaded by the game at
start-up like OPU's own modules.

## What it does

When the Renegades loader starts a game, the module:

- **uses Renegades' in-game art** from `ren2res.dll` instead of the game's `out2res.dll`: the "OP: RENEGADES" title
  at the window's top left, the blue frames, the loading screen and the About box;
- **puts the Renegades R in the command pane** in place of the colony emblem, from `OPU\renegades\renegmbl.raw`;
- **says "Renegades" for "Outpost 2"** in 13 of the game's own texts: the window and taskbar title, the save
  dialog's "Renegades Games (*.REN)", the quit prompt and a few messages;
- **gives Renegades its own saved games,** `OPU\saves\SGAME0.REN` to `SGAME9.REN`, as the original Renegades named
  them, apart from other games' `.OP2` saves. They carry a Renegades save tag, so only a game the loader started
  loads them: Outpost 2 on its own refuses one, even renamed;
- **puts your name from the loader's Preferences** into the game, where the mission start leaves it empty;
- **posts "Renegades v1.2.19"** in the message log at a mission's start, from its own version, so the missions'
  scripts carry no version and a release leaves them, and your saved games, as they are;
- **shows the release in the Game Options pane:** "1.4.1 REN 1.2.19" in place of OPU's "Version 1.4.1-OPU", with
  OPU's version read from OPU itself (`OPUPatch.dll`) and the release from the module's own version;
- **plays the difficulty you picked** in the loader. OPU's mission starter always starts Normal, so the loader
  passes the difficulty to the module (`RENEGADES_DIFFICULTY`: 0 Easy, 1 Normal, 2 Hard);
- **starts from the random seed the loader chose** (`RENEGADES_SEED`) instead of one from the clock, so a play-test
  game can be played again from the same start.

## Only a Renegades game, and only in memory

- It acts only when the environment variable `RENEGADES_LAUNCH=1` is set, which the loader does for the game it
  starts. Any other game (a colony game, multiplayer, the stock campaign) is left exactly as it is.
- Every change is made in the running game's memory. Nothing on disk is changed: `out2res.dll` and the game's files
  are never touched. At exit the module puts back what it changed, and a crash leaves nothing behind either.
- Before each change it checks that the game's code or text is what it expects. If not (another build of the game),
  it leaves that part alone and says so in its log.

The menu shell from the original Renegades (`renshell.dll`) can be tried with `RENEGADES_SHELL=1`, but it's off: on
OPU 1.4.1 the game hangs going back to its menus with it, and the loader is the menu anyway.

## Building

`build.bat` builds a 32-bit `Renegades.dll` with Microsoft Visual C++ (Visual Studio or its Build Tools, with the C++
workload). It finds Visual Studio itself, uses a static runtime (`/MT`, so players need no redistributable), and links
`gdi32.lib`. `Renegades.rc` is the DLL's version information; its version is the release's.

```bat
cd module
build.bat
```

## Installing by hand

The release zip installs it, and the loader registers it on its first start. By hand: put `Renegades.dll` and
`ren2res.dll` in the game's `OPU` folder and `renegmbl.raw` in `OPU\renegades`, then add to `OPU\outpost2.ini`:

```ini
[ExternalModules]
Renegades=yes

[Renegades]
Dll=Renegades.dll
```

## Its log

Each start adds to `OPU\logs\Renegades-module.log`: whether it was a Renegades launch and what it changed. A normal
start on Normal (times left out):

```
=== InitMod (section 'Renegades'): a Renegades launch
ren2res: the name at 0x4E96C0 is now ren2res.dll (patched)
ren2res: the game had loaded out2res.dll already; its handle now points at ...\OPU\ren2res.dll
ren2res: the frame's bitmaps reloaded from ren2res.dll (title 179: loaded)
texts: "Outpost 2" -> "Renegades" in 13 of 13 of the game's texts
difficulty: Normal for the mission's player (patched)
seed: 1 (patched)
start: name 'Player' for player 0, message 'Renegades v1.2.19' (patched)
saves: SGAMEn.REN and SGAME10.REN, the extension in 4 of 4 places
save tag: "OUTPOST2 1.4.0-REN SAVE" (patched): only a Renegades game loads its saves
versions: Outpost2.exe 1.2.0.7, OPU 1.4.1, Renegades 1.2.19; the pane's line is "Version 1.4.1-OPU"
version line: "1.4.1 REN 1.2.19" (patched)
shell: the stock menu shell (RENEGADES_SHELL=1 tries Renegades' renshell.dll)
emblem: loaded ...\OPU\renegades\renegmbl.raw
emblem: set (graphics 0x029E74C0, base 0x05C60436, entry was 0x0042E774)
```

Add it to a bug report if the title, the R or the difficulty looks wrong.
