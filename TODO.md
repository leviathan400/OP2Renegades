# To do

What's planned for Renegades, and where help is welcome. Ideas, opinions and offers of help are welcome on the
[Renegades forum board](https://forum.outpost2.net/index.php/board,33.0.html); pull requests are too.

The remakes first match their originals as closely as the game can measure, so they can be compared side by side.
Changes from the originals (fixes of their faults, balance) are held back here until then, and each one goes in as a
listed change in the mission's script. Several are open questions for players: say what you think on the board.

## Play testing

- **Play each mission to a win**, carried on into the next: Relocation, Onslaught, Consequences and Raid. Reports,
  saved games and screenshots on the board help most. Every game starts from the same random start for now (seed 1),
  so a problem you report can be played again exactly; the first message-log line names the version you play.
- **Saving and loading.** Since 1.2.15 a saved mission carries on where it was. Check that a saved game of each
  mission loads and plays on to its end, saved at different points of the mission, from the loader's Load Game and
  from the game's own Load window. A save whose mission has changed since says "GAME LOAD MISSION FAIL" (1.2.19);
  start that mission again.
- **The loader's Preferences**, and the loader on a Windows set to another language.

## The missions

### Onslaught (q02)

- **The scorched-earth team.** Once your evacuation convoy is ready, Plymouth sends six more RPG Lynx to burn the base
  you're leaving every 2,000 ticks the convoy waits, with no limit. Cap it at one team at a time, send it once, or
  leave it as the original? Did you meet more than one team?

### Consequences (q03)

- **Eden's waves** add their one-shot events again each time, so several can wait at once. Keep one of each.
- Kept as the original: Eden's third mining group is set up again on every pass once its mine stands. Setting it up
  once changes how Eden builds and plays, so it stays as Eddy-B made it.

### Raid (q04)

- **The Lynx overflow.** With few Lynx carried over from Consequences, the original's share-out runs past its eight
  start places onto the entry point, Eden's scout waypoints and the patrol route (Easy starts 10 Lynx, Normal 16).
  Cap it at the eight places.
- **A minimum start force.** The original can't start without carried Lynx, so the remake gives Hard eight Microwave
  Lynx. Should every difficulty get that minimum?
- **The difficulty.** Raid's difficulty flags are only set by its "You're cheating!" check, so an honest game plays the
  same at every difficulty apart from Eden's assault size, the escorts and the late reinforcements. Should the parts
  meant for Hard (a second Vehicle Factory, a fourth hiding place, a bigger attack group) play on Hard?
- **The scientists' swapped checks.** Losing the lab that does *not* hold the scientists fails the mission. Swap them.

## The loader and the look

- **Background graphics.** More backgrounds: the loader's main menu has a new one since 1.2.10; the start-campaign
  form and the website still have the original's.
- **The logo.** A remake of the Renegades logo (the loader's splash, the website).
- **The icon.** A remake of the loader's icon, with the sizes Windows uses (16 to 256 pixels; the original is one
  32 x 32 image).
- **The voice lines.** Remakes of the seven savant lines (`ren228.wav`-`ren234.wav`).
- **A random seed.** Once play testing is done, a random start per game as the original, still recorded so a game can
  be started again the same way.
- **The statistics.** The loader's history records the structures lost as 0; it reads the game's statistics from the
  wrong place.
- **Other systems.** The loader on Linux and macOS, where the game runs under Wine or similar. Its watching of the
  game is Windows-only now.
- **Missions updated without a new download.** Fetch the missions' latest versions from the Outpost 2 maps database
  (over HTTPS, checked against a hash), with the release's copies as the fallback.

## Translations

The loader speaks English, German, Spanish, French and Portuguese (`OPU/renegades/lang.<code>.ini`).

- **A native speaker's reading** of the German, Spanish, French and Portuguese texts.
- **More languages.** Copy `lang.en.ini` to `lang.<code>.ini` (`pl`, `ru`, ...) and translate the quoted texts.

Renegades' own briefings, objectives and story are in English only.

## Not doing

- **Renegades' music.** The original's songs come from another game, *7th Legion* (1997), so they can't be shipped.
  The remakes play Outpost 2's own soundtrack.
