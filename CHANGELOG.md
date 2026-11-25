# Changelog

## 1.2.19 (2026-11-25)

Everything since 1.2.15: Consequences fixes, an end-of-mission screen, clearer saved-game messages. (1.2.16 to 1.2.18
went to testing only and were never published here.)

### Consequences (Mission 3)

- **No more crash after destroying Eden's northern smelter.** Once it was gone, an Eden vehicle driving over its
  tile could become the "smelter" of Eden's third mining group, and the game crashed as soon as a truck brought it
  ore. The original Renegades has the same fault; the remake now sets that group up only with a real mine and smelter.
- **More food at the start:** 3,800 on Easy, 2,500 on Normal and 2,000 on Hard (the original gives 2,100, 1,600 and
  1,300), as the colony could starve before its first Agridome fed it.
- **The defectors' messages point the right way.** Clicking "A group of colonists wants to defect." or "To transfer
  colonists, put the evac next to a residence." in the message pane goes to the defectors' Evac, "Colonists
  transferred safely." to the Residence, and each "New mission objective" to your first Standard Lab, as in the
  original. Before, a click went to the map's top-left corner, Eden's base. (Bring the Evac next to one of your own
  Residences.)

### The loader

- **An end-of-mission screen:** "Mission Accomplished!" or "Mission Failed", the final game mark, the units and
  structures you built and lost to enemies, and what comes next ("On to Mission 4.", or the campaign won).
- **A crash is reported.** If Outpost 2 crashes in a mission, the screen says "Outpost 2 crashed", with where, and the
  log in `OPU\logs` that holds the details. If Outpost 2 is closed during a mission, it says so too.

### The game

- **OP2Lua 0.8.12** (`OPU\OP2LuaCore.dll`; 1.2.15 had 0.8.9):
  - **A saved game that can't carry on says so clearly:** "GAME LOAD MISSION FAIL" and the reason, twice, the second
    time with a sound. That happens when a mission's script has changed since the save, as Consequences' has in this
    release.
  - The objectives of such a game read "Objective unknown" instead of garbage or a crash.
- **The Game Options pane shows the release:** "1.4.1 REN 1.2.19" in place of "Version 1.4.1-OPU".
- **Saves from 1.2.15:** Relocation, Onslaught and Raid carry on. Consequences' load with its script stopped; start
  that mission again.

## 1.2.15 (2026-11-23)

Everything since 1.2.11: saved games. (1.2.12 to 1.2.14 went to testing only and were never published.)

### Saved games

- **A saved mission carries on where you saved it.** Its timers, events, objectives and the enemy's attacks pick up
  where they were, and the message log says "GAME LOAD SUCCESSFUL". Before, a loaded Renegades mission had lost its
  script and couldn't be finished.
- **Load Game in the loader** (L on the main menu) lists your saves with each one's map, mission, when it was saved
  and the game mark, and starts Outpost 2 straight into the one you pick. After a loaded game the loader goes back to
  the campaign's mission menu, or to the main menu for a save of another mission.
- **Renegades has its own save slots,** `OPU\saves\SGAME0.REN` to `SGAME9.REN`, as the original Renegades had, apart
  from your other Outpost 2 saves. They load only in a game started from the Renegades loader: Outpost 2 on its own
  refuses them, as it lacks Renegades' look and menus.
- **Saves from 1.2.11 and earlier don't carry on:** they hold no mission script. Start the mission again.
- From now on a release changes a mission's script only when the mission itself changes, so your saves keep working
  across releases.

### The loader

- **Sound effects volume** in Preferences, with LESS and MORE as in the original.
- **Wider Briefing, Objectives and story windows,** so more of the text shows at once.
- The mission window's unit and structure counts say **"lost to enemies"**: they are Outpost 2's own counts, which
  leave out what quakes, meteors and lava destroy.
- **Only one loader at a time.** Starting it again brings the open one to the front.
- Each mission's start and end are written to `OPU\logs\Renegades-loader.log`, and the missions log each objective
  met and each failure, which helps with play-test reports.

### The game

- **Your name from Preferences** is your name in the game.
- Each mission starts with "Renegades v1.2.15" in the message log.
- **OP2Lua 0.8.9** (`OPU\OP2LuaCore.dll`; 1.2.11 had 0.8.7): saved games keep the missions' scripts.
- **op2launcher 0.9.6** (`OPU\op2launcher.exe` and `Launcher.dll`): starts a saved game for the loader's Load Game.
  Update both with the release.
- `Renegades.dll` writes its log to `OPU\logs\Renegades-module.log`. An older `OPU\renegades\Renegades.log` is no
  longer used and can be deleted.

## 1.2.11 (2026-11-22)

Fixes from the first play tests.

### The loader

- **A won mission always counts.** After a win the loader could say "The mission was not finished" and the campaign
  didn't move on (it happened after Onslaught's evacuation). Outpost 2 shows the win only for a moment as it leaves
  the mission; the loader now also takes the mission's own record of it.
- **A new background,** `OPU\renegades\background03.png`. 1.2.10's `background02.png` is no longer used and can be
  deleted.

### The missions

- **Onslaught keeps the kits you stored.** The kits in the Structure Factory you bring from Relocation were replaced
  by Onslaught's own (Guard Post kits, and on Easy a Residence and an Agridome), so a Smelter or Structure Factory kit
  you had packed was gone. Now the factory comes through as you left it.
- **Guard Post kits keep their turret.** A ConVec carrying a Guard Post kit into the next mission lost the kit's
  turret. Each vehicle in the carry-over now saves only what it really carries (a ConVec's kit and its turret, a
  truck's cargo, a tank's weapon).
- **Raid records its win** in a small `q04.carry`, so the loader sees the end of the campaign.
- **OP2Lua 0.8.7** (`OPU\OP2LuaCore.dll`; 1.2.10 had 0.8.6): it reads a ConVec kit's turret, and drops a runaway
  script call instead of freezing the game.
- Each mission starts with "Renegades v1.2.11" in the message log.

## 1.2.10 (2026-11-21)

Everything since 1.2.8. (1.2.9 went to testing only and was never published.)

### The loader

- **A new background.** The loader opens in a larger window (1448 x 1086) with a new picture behind the menu,
  `OPU\renegades\background02.png`. For the original look, Renegades' own picture in a 1024 x 768 window, set
  `ClassicBackground=1` in `OPU\renegades\Renegades.ini`.
- **Fits smaller screens.** On a screen too small for the window (less the taskbar), the window and its background
  shrink to fit, keeping their shape; the menus and texts stay their size.
- **Checks that OPU 1.4.1 is installed.** Renegades needs Outpost 2 with the Outpost Universe update; unzipped into
  an Outpost 2 folder without it, the game stayed at its menu and no mission ever loaded. Now the loader says OPU
  1.4.1 is needed, opens the Outpost 2 page at https://outpost2.net/outpost2.html to download it once you press
  OK, and closes.
- **French.** The loader's texts are also in French (`OPU\renegades\lang.fr.ini`, `Lang=fr`).
- **Briefings and objectives look as in the original.** The Briefing form has the briefing on the left and the
  mission's picture on the right, with Renegades' blueprint behind; Objectives and the story chapters show their
  text across the form. The texts are in the colours and sizes their files give (the objectives in blue, as in the
  original). The mission menu has the blueprint behind its buttons too.
- **A larger Start Campaign form,** so more of the prologue shows at once.
- **Keys on the main menu:** R (Outpost Renegades), C (Colony Games), P (Preferences), H (Help), A (About) and Q
  (Quit), on their own, in every language.

### The missions

- **OP2Lua 0.8.6.** The missions run on OP2Lua 0.8.6 (`OPU\OP2LuaCore.dll`; 1.2.8 had 0.8.3). Its fixes since 0.8.3
  include colony morale and orders to a unit given the tick it was made. Tried headless on all four missions at each
  difficulty: no script errors, and each ends as on 0.8.3; the computer player's moves drift a little later in a game.
- Each mission starts with "Renegades v1.2.10" in the message log.

## 1.2.8 (2026-11-20)

Everything since 1.2.0 (2026-11-19), the first release.

### The missions

- **The campaign carries on from mission to mission.** As in the original campaign, each mission you win leaves what
  you had for the next one: Onslaught, Consequences and Raid start from the base, units and stores you finished the
  mission before with. Without a won mission before it, a mission starts from its own base, as in 1.2.0. Starting a
  new campaign clears what was carried.
- **The difficulty you pick is the one you play.** 1.2.0 always played Normal, whatever the campaign or Select Mission
  was set to.
- **Consequences no longer crashes when the Plymouth colony settles a second time.** The original mission has the
  same crash.
- **Every game starts from the same random start** (seed 1) while the missions are being play-tested, so a problem you
  report can be played again exactly. The seed is recorded in `OPU\renegades\Renegades-history.csv`.
- **The message log names the release.** Each mission starts with "Renegades v1.2.8" in the message log, without a
  sound, so a screenshot shows which version you play.

### The loader

- **In your language.** The loader's menus, forms and messages come in English, German, Spanish and Portuguese
  (`OPU\renegades\lang.<code>.ini`). On the first start it picks your Windows language if it has it, else English;
  change it in Preferences (a drop-down) or with `Lang=` in `OPU\renegades\Renegades.ini`. Renegades' own briefings,
  objectives and story are in English. To translate the loader, copy `lang.en.ini` to `lang.<code>.ini` and translate
  the quoted texts.
- **"The mission was failed."** after a lost mission, as Outpost 2 says it.
- **Help** describes the campaign; it no longer says Colony Games plays a mission (Renegades has no colony games yet).
- **A clear message if it's in the wrong place.** Started anywhere but the `OPU` folder of an Outpost 2 install,
  `Renegades.exe` says where it is and where it belongs, and closes.
- **Debug mode is off unless you turn it on** (Preferences, `Debug=1`, or `Renegades.exe /debug` for one run).

### Installing and updating

- **Updating keeps your campaign.** The zip no longer holds a `Renegades.ini`: the loader writes it on its first start.
  Unzip a new release over the old one and your place in the campaign, its difficulty and your folders stay.
- **OP2Lua 0.8.3** (`OPU\OP2LuaCore.dll`), which the carry-over needs, in place of 0.8.2.
- **New files:** the language files `OPU\renegades\lang.en.ini`, `lang.de.ini`, `lang.es.ini` and `lang.pt.ini`.
  Gone: `OPU\renegades\Renegades.ini`.

### Coming from 1.2.0

Unzip 1.2.8 over your Outpost 2 folder as before; your place in the campaign is kept. 1.2.0 carried nothing between
missions, so your next mission starts from its own base. From your next win on, each mission starts from the one
before it.
