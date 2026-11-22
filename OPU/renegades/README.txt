OUTPOST 2: RENEGADES - the Lua remakes
=====================================

Outpost 2: Renegades is a four-mission Plymouth campaign made by Eddy-B and the Renegades team in 2004-2006:
Relocation, Onslaught, Consequences and Raid. Its source code was lost and some of its missions crashed. This is the
campaign remade as OP2Lua missions for Outpost 2 with the Outpost Universe update (OPU 1.4.1), with a loader that
brings back its own menus.

Credits: Eddy-B (mission programming); Hooman, Hacker and Cynex (additional coding); TH300 (map designs);
MoogleKupoHax, Shuffles and Freeza-CII (additional graphics); Gwyned (novella); beta-testing by Mez, Leviathan, TH300,
Baikon, PlayingOP, Invictus, op2Hacker, ZigZagJoe, Gwyned and wizisi.


INSTALL
-------

Needs Outpost 2 with OPU 1.4.1.

1. Unzip into your Outpost 2 folder (the one holding Outpost2.exe and the OPU folder), keeping the folders.
2. Start OPU\Renegades.exe.

The first start registers Renegades.dll with OPU's extension loader (two lines in OPU\outpost2.ini). The module
only acts on a game the loader starts; every other game stays as it was.

Before each mission the loader also sets three of the game's own options in OPU\outpost2.ini ([Game]): no intro
video (IntroAVI=0), no "check for updates?" question (CheckForUpdates=0) and no unit health bars (ShowUnitHPBars=0).
They stay set for every game; change them back in the game's options if you want them.

Updating: unzip the new release over the old one. The zip has no Renegades.ini (the loader writes it on its first
start), so your place in the campaign, its difficulty and your folders are kept.

What goes where:
  OPU\Renegades.exe           the loader, beside OPULauncher.exe
  OPU\renegades\              Renegades' menu art and texts (renshres.dll, ren.vol), the R (renegmbl.raw), the
                              loader's background (background03.png; ClassicBackground=1 in Renegades.ini shows the
                              original's picture in a smaller window instead), and the
                              loader's settings and history, and its texts in English, German, Spanish, French
                              and Portuguese (lang.en.ini, lang.de.ini, lang.es.ini, lang.fr.ini, lang.pt.ini):
                              the first start picks Windows' language if there's a file for it; change it in
                              Preferences, or Lang=en / de / es / fr / pt in Renegades.ini. To translate the
                              loader, copy lang.en.ini to lang.<code>.ini.
  OPU\Renegades.dll           the in-game look: the "OP: RENEGADES" title, the R in the command pane
  OPU\ren2res.dll             Renegades' in-game art, used by Renegades.dll
  OPU\OP2LuaCore.dll          OP2Lua 0.8.6 (the missions need it; it replaces an older one)
  OPU\op2launcher.exe, Launcher.dll   start a mission straight from the loader
  OPU\maps\Renegades\         the four missions, their maps and Renegades' voice lines
  OPU\logs\                   where OP2Lua writes the missions' logs

PLAYING
-------

  Outpost Renegades   the campaign, mission by mission (the prologue, briefings, objectives and story are Renegades' own)
  Renegades.exe /select   pick any one mission and a difficulty
  Renegades.exe /debug    debug mode for this run: more on the mission form, Force Quit, and renegades\Renegades-debug.txt

The loader follows the game: when a mission ends it records the result (renegades\Renegades-history.csv), closes
Outpost 2 once it's back at its menu, and moves the campaign on after a win.

The game plays at the difficulty you pick, and each mission after the first starts from what you left in the one
before (as the original campaign did). During the play tests every game starts from the same random seed (1),
so a problem you report can be played again from the same start; the seed is in renegades\Renegades-history.csv.
