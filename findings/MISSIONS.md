# The four missions

From op2dll runs of the DLLs in op2-missionhost (`../runs/`), 2026-11-12, at Easy. This is an overview. Each mission's
full spec, at every difficulty, is in `decompile/q0N.md`. The setups at Normal and Hard are in `../runs/` (redone
2026-11-17 on carry-over from campaigns at those difficulties). All four have since run in the game
(`HARNESS-RUNS.md`), and all four are remade in OP2Lua (`../lua/`). "Player 1" is the human, the game's player 0.

| | q01 Relocation | q02 Onslaught | q03 Consequences | q04 Raid |
|---|---|---|---|---|
| Map | `Q01.MAP`, 128 × 64 | `Q02.map`, 256 × 64 | `Q03.map`, 128 × 128 | `Q04.map`, 64 × 128 |
| Tech tree | `Q01.tek` | `Q02.tek` | `Q03.tek` | `Q03.tek` |
| Tech level | 3 | 3 | 5 | 5 |
| Players | 2 | 3 | 3 | 4 |
| Unit mission | no | no | no | yes |
| Setup | 12 vehicles, 9 structures, 7 beacons | 11 vehicles, 13 structures, 12 beacons | 23 vehicles, 31 structures, 11 beacons, 90 walls and tubes | 17 vehicles, 30 structures, 5 beacons, 113 walls and tubes |
| Triggers the setup makes | the objectives (below) | none | none | none |

## q01: Relocation

- **Players.**
  - Player 1: Plymouth (colour 1), starting with a Command Center, a Structure Factory (4 kits in its bays), a Smelter,
    a Tokamak, two ConVecs, three Cargo Trucks, a Robo-Surveyor, two Robo-Miners and a Robo-Dozer.
  - Player 2: Eden, a computer player (Command Center, Smelter, Tokamak, Structure Factory, three Cargo Trucks).
- **Colony.**
  - Easy starts with 28 workers, 5 scientists, 1,800 ore and 2,500 food. Normal and Hard start with 25 workers,
    1,200 ore and 2,000 food.
  - The Structure Factory holds four Microwave Guard Post kits at every difficulty. Easy adds a Residence and an
    Agridome kit.
  - A resource failure condition's limit is 12 on Easy and 16 on Normal.
- **Objectives** (victory conditions):
  - "Have a Common Ore Smelter kit in storage";
  - "Have a Structure Factory kit in storage";
  - "Have a Command Center kit in storage";
  - "Have a Tokamak kit in storage";
  - four more on resources, with no text.

  Failure conditions on resources, and one more made later. So the mission is about packing up the base to move:
  "Relocation".
- **Messages.** "Reinforcements have arrived" (twice by mark 100 in a replay, from `AIProc`) and "No more
  reinforcements available !".
- **Replay with nobody playing:** lost at mark 174, when a resource failure condition fires. `AIProc` is busy the
  whole time: about 680,000 game calls in 17,000 ticks, mostly unit enumerations.

## q02: Onslaught

- **Players.**
  - Player 1: Plymouth.
  - Player 2: Eden, a computer player starting with 10,000 ore and 10,000 food.
  - Player 3: Plymouth, a computer player (colour 6).
- **Messages:**
  - "Your pickup-team has arrived. Get ready to evacuate";
  - "Get ready to evacuate";
  - "A new convoy has arrived";
  - "Reinforcements have arrived";
  - a "Message from the Council" box: "We've sent a team to pick you up\r\nGet ready to evacuate to (%d,%d)!".
- **Exports:** `InitMap`, and `Research3304Done`, `Research3305Done`, `Research3401Done`: callbacks for research
  topics 3304, 3305 and 3401.

## q03: Consequences

- **Players.**
  - Player 1: Plymouth (colour 3).
  - Player 2: Eden, a computer player with 10,000 ore.
  - Player 3: Plymouth, a computer player.
- **Messages:**
  - "A group of colonists wants to defect.";
  - "To transfer colonists, put the evac next to a residence.";
  - "Colonists transferred safely.".
- **Setup.** Rolls some beacons' variant. It also reads the whole map tile by tile: 16,512 `GetTile` calls, about
  one per tile of the 128 × 128 map. It then marks about 3,000 tiles where lava may flow (`SetLavaPossible`) and
  changes 129 cells (`SetCellType`): about 21,600 game calls in all.
- **Exports:** `InitMap`.

## q04: Raid

- **A unit mission.**
- **Players.**
  - Player 1: Plymouth (colour 3), starting with 10,000 common and 10,000 rare ore.
  - Player 2: Plymouth, a computer player.
  - Player 3: Eden, a computer player.
  - Player 4: Plymouth, a computer player.
- **Messages:**
  - "We might be able to help each other out!";
  - "It seems those Eden units are here for the same reason";
  - what a raid can turn up: "Nothing found.", "Retrieved RPG data.", "Retrieved Rare Ore technologies", "Retrieved
    Panther design plans", "Scientists captured", "Retrieved security codes.".
- **Exports:** a callback for each raid result: `gotNothing`, `gotRPG`, `gotRareOre`, `gotPanther`, `gotScientists`,
  `gotCodes`.

## Open questions

- **How q02-q04 start.** Their setups give the human no colonists and make no triggers. Their objectives and events
  must come from somewhere else: `InitMap`, `StatusProc`, their event system run from `AIProc`, or the Renegades
  menu.
- **Idle replays.** In replays with nobody playing, q02-q04 make no game calls for 3,000 marks. Their events may
  wait on the player, and they may read units through `op2extra.dll`'s memory access, which op2dll's call log
  doesn't show.
- **The difficulty file.** Which file the missions read their difficulty from, and what else is in its 0x20 bytes.
