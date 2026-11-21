# Changelog

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
