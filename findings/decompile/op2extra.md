# op2extra.dll

An `IUnit` class that Renegades' missions use for what the 1997 mission SDK can't do, much like the community's HFL.
Decompiled with Ghidra (`../../decompile/op2extra/`): 111 functions, base `0x10000000`. All 30 exports and `DllMain` are read below
(from the disassembly; the code between `0x10001000` and `0x1000197D` is all of it, the rest is the C runtime).

- **Imports.** Six of the SDK's `Unit` methods from `Outpost2.exe` (`GetType`, `IsVehicle`, `OwnerID`, `Location`,
  `GetCargo`, `operator=`), and `kernel32` for the runtime.
- **The object.** An `IUnit` is one dword, the unit id, laid out like the SDK's `Unit`, so a mission can treat a
  `Unit` as an `IUnit`. The constructor (`0x100015DE`) sets the id to 0; `operator=` (`0x10001006`) forwards to
  `Unit::operator=`.
- **No checks.** Nothing checks that the unit is live or the id valid; reads and writes go straight to the unit array.

## How it reaches the game

Three game addresses are kept as static pointers (`0x10006030`-`0x10006038`; values read from the DLL's `.data`):

| Pointer | Game address | What |
|---|---|---|
| `0x10006030` | `0x40E300` | `PlayerImpl::ProcessCommandPacket`, the game's handler for a player's command packet. |
| `0x10006034` | `0x472D90` | Turns a tech id into a research topic index, called on the object at `0x56C230` (presumably the game's research object). Used by `Research`. Not checked against the game. |
| `0x10006038` | `0x4E1348` | The unit-type table (`MapObjectType*` by map id). |

- **Unit memory.** `UnitAddress` (`0x100015E4`, private): the unit array pointer at `0x54F848`, plus id × 0x78. The
  reads below inline the same sum.
- **Players.** A player is `0x56EF1C` + player × 0xC24 (`PlayerImpl`).

These are the GOG 1.2.0.7 / OPU addresses. op2-missionhost already answers `ProcessCommandPacket` and mirrors the unit
array and players at them.

## Commands: packets to the owner's player

Each command checks the unit's type, builds a packet on the stack, and passes it to `ProcessCommandPacket` of the
unit's owner (`OwnerID`), as if that player had given the order. Nothing is returned; a unit of the wrong type is
silently ignored.

- **Packet.** The command type (dword), the data's length (word), two dwords set to 0 (TethysAPI's time stamp and net
  id), then the data at +0xE. Command numbers are the game's (TethysAPI's `CommandType`).
- **Coordinates.** No conversion: the mission's `LOCATION` and `MAP_RECT` values go into the packet as they are.

| Function (address) | Only for | Command | Data (in order; words unless said) |
|---|---|---|---|
| `Doze(MAP_RECT)` (`0x100015F0`, builder `0x10001019`) | Robo-Dozer (0x0C) | 1 `ctMoDoze`, len 0xB | byte 1 (unit count), unit id, x1, y1, x2, y2 |
| `Dock()` (`0x1000161D`, `0x1000108C`) | vehicles (`IsVehicle`) | 3 `ctMoDock`, len 3 | byte 1, unit id |
| `DockGarage()` (`0x10001634`, `0x100010DC`) | vehicles | 4 `ctMoDockEG`, len 3 | byte 1, unit id |
| `Build(LOCATION)` (`0x1000164B`, `0x1000112F`) | ConVec (0x02) with a kit; Robo-Miner, GeoCon (0x09-0x0A) | 6 `ctMoBuild`, len 0x13 | byte 1, unit id, 1 (waypoint count), a waypoint dword, rect x−w−1, y−h−1, x, y, then 0xFFFF. See below. |
| `Produce(type, weapon)` (`0x10001660`, `0x10001243`) | Arachnid, Consumer, Structure, Vehicle Factory (0x2D-0x30), Spaceport (0x37) | 9 `ctMoProduce`, len 0xC | factory id, type (dword), weapon or cargo (dword), 0xFFFF |
| `TransferCargo(bay)` (`0x1000168E`, `0x100012A4`) | anything | 0xA `ctMoTransferCargo`, len **2** | unit id, bay, 0. The length covers only the id (see Still open). |
| `LoadCargo()` (`0x1000169E`, `0x100012FF`) | anything | 0xB `ctMoLoadCargo`, len 2 | unit id |
| `UnloadCargo()` (`0x100016A7`, `0x1000134E`) | anything | 0xC `ctMoUnloadCargo`, len 2 | unit id |
| `DumpCargo()` (`0x100016B0`, `0x1000139D`) | vehicles | 0xE `ctMoDumpCargo`, len 2 | unit id |
| `Research(tech, scientists)` (`0x100016C7`, `0x100013EC`) | Basic Lab (0x21), Standard and Advanced Lab (0x31-0x32) | 0x16 `ctMoResearch`, len 6 | lab id, topic index (the tech id through `0x472D90`), scientists |
| `TrainScientists(n)` (`0x100016F7`, `0x1000145C`) | University (0x26) | 0x17 `ctMoTrainScientists`, len 4 | unit id, n |
| `Salvage(MAP_RECT, unit)` (`0x10001716`, `0x10001518`) | Cargo Truck (0x01) | 0x1F `ctMoSalvage`, len 0xC | truck id, x1, y1, x2, y2, the second unit's id (q03 passes its GORF) |
| `Poof()` (`0x10001747`, `0x1000158F`) | vehicles | 0x2A `ctMoPoof`, len 2 | unit id. The unit vanishes (no explosion). |
| `Repair(unit)` (`0x1000175E`) | ConVec, Spider (0x02-0x03), Repair Vehicle (0x0E) | 0x1C `ctMoRepairObj`, len 9 | byte 1, unit id, 0, target id, 0xFFFF |
| `Reprogram(unit)` (`0x1000178A`) | Spider (0x03) | 0x1D `ctMoReprogram`, len 9 | as Repair |
| `Dismantle(unit)` (`0x100017AC`) | ConVec (0x02) | 0x1E `ctMoDismantle`, len 9 | as Repair |

Repair, Reprogram and Dismantle share one builder (`0x100014B3`) that takes the command number as its first argument.
The command names for 9, 0xA-0xC, 0xE, 0x17, 0x1D and 0x1F are TethysAPI's, matched by the export names; the numbers
are what the code sends.

**Build in detail** (`0x1000112F`):
- **ConVec.** Its kit comes from `GetCargo` (`0x1000183B`); with no kit (≤ 0) nothing is sent. w and h are the kit
  type's words at +0x248 and +0x24A in the type table (presumably the footprint, size − 1 or similar: the rect spans
  w + 2 by h + 2 tiles; guess). The location is moved to x + (w+1)/2, y + (h+1)/2 (signed, rounded toward 0) before
  the rect and waypoint are made from it.
- **Robo-Miner, GeoCon.** w = h = 0 and no centring: the rect is (x−1, y−1)-(x, y).
- **The waypoint dword.** Low word x × 32 + 16, high word y × 16. In TethysAPI's waypoint packing (x pixel in the low
  15 bits, y pixel from bit 15) that is the tile's centre in x but its top edge in y (y × 32). An interpretation, not
  measured.

**Research's missing-tech check is dead** (`0x10001400`): the topic index is zero-extended to 16 bits and then tested
for negative, which can never be true, so the packet is always sent (with 0xFFFF if `0x472D90` returns −1).

## Reads of the unit's fields

| Function (address) | Returns |
|---|---|
| `GetDamage()` (`0x1000188C`) | the damage, +0x1E (signed short) |
| `GetBusy()` (`0x100017CE`) | the current command, +0x21 (signed byte) |
| `IsIdled()` (`0x10001937`) | whether `GetBusy` is 0x12 (`ctMoIdle`) |
| `GetLights()` (`0x10001945`) | bit 0 of the flags at +0x44: a vehicle's headlights (TethysAPI; op2-rs measured it, `harness/oracle/FINDINGS.md`) |
| `GetCargo(&kit, &weapon)` (`0x1000183B`) | kit = +0x24 (signed **byte**); weapon = +0x4F (signed byte) when the kit is non-zero, else 0 |
| `GetCargo()` (`0x10001000`) | a jump straight to the SDK's `Unit::GetCargo`; same export name, no mission imports it |
| `GetTruckCargo(&cargo)` (`0x10001869`) | reads +0x24 as a **dword**: cargo = its low 4 bits; returns the dword / 16 (signed) as the amount |
| `GetFactoryCargo(bay, &kit, &weapon)` (`0x100017DF`) | Structure Factory (0x2F): +0x61+bay and +0x48+bay. Spaceport (0x37): +0x6E (the same for every bay) and +0x61+bay. Any other type: both 0. The bay isn't range-checked. |
| `IsInRect(MAP_RECT)` (`0x100018E1`, helper `0x1000189D`) | whether `Unit::Location` lies in the rect, edges included. The corners are put in order first, so a reversed rect works. |

## Writes to the unit's fields

| Function (address) | What it writes |
|---|---|
| `SetEMPticks(t)` (`0x1000190F`) | +0x50 = t (sign-extended to a dword). For t ≠ 0 it sets bit 19 of the flags (`MoFlagEMPed`, via the byte at +0x46). For t = 0 it writes 0 to the **whole** flags dword at +0x44 (`../CRASH-LEADS.md` 3). |
| `SetOffensive(b)` (`0x1000195E`) | sets or clears bit 4 of the flags at +0x44 (`MoFlagOffensive`, "unit is a combat unit type"; `../CRASH-LEADS.md` 4) |

## What the missions use

All four construct `IUnit`s throughout (`??0IUnit@@QAE@XZ`). Call sites (the mission function, then the call):

| Export | q01 | q02 | q03 | q04 |
|---|---|---|---|---|
| `GetDamage` | repair check `0x11001E91` (`0x11001E9C`, `0x11001F04`) | AI repairs `0x11006E37` (`0x11006E98`) | Plymouth settles `0x1100301D` (`0x11003234`), base part 1 `0x11003503` (`0x110036A7`), repair AI `0x11006C6B` (`0x11006CCC`) | repair pass `0x11005365` (`0x110053C6`) |
| `Repair` | repair check `0x11001E91` (`0x11001EFD`) | `0x11006E37` (`0x11006F7B`) | `0x11006C6B` (`0x11006DAF`) | `0x11005365` (`0x110054A9`) |
| `GetBusy` | - | `0x11006E37` (`0x11006ED3`, `0x11006F07`); events `0x11007035` (`0x11007091`), `0x110071F0` (`0x110071F4`) | `0x11006C6B` (`0x11006D07`, `0x11006D3B`); working-building event `0x11007390` (`0x11007394`) | `0x11005365` (`0x11005401`, `0x11005435`); dozing `0x11002080` (`0x1100208A`); `0x11005E80` (`0x11005E84`) |
| `IsIdled` | - | - | transfer check `0x11002867` (`0x11002906`) | - |
| `GetCargo(&,&)` | carry-over writer `0x110039E5` (`0x11003CAF`) | writer `0x11005FE6` (`0x110062B0`); repair search `0x11006D88` (`0x11006E15`) | writer `0x11006102` (`0x110063CC`); repair search `0x11006BBC` (`0x11006C49`) | writer `0x1100492F` (`0x11004BF9`); repair search `0x110052B6` (`0x11005343`) |
| `GetTruckCargo` | writer `0x110039E5` (`0x11003CC5`) | pickup check `0x110021FA` (`0x1100229A`), convoy check `0x11004684` (`0x11004739`), writer `0x11005FE6` (`0x110062C6`) | salvage `0x11003FE2` (`0x11004058`), `0x110040E2` (`0x11004186`), writer `0x11006102` (`0x110063E2`) | writer `0x1100492F` (`0x11004C0F`) |
| `GetFactoryCargo` | writer `0x110039E5` (`0x11003BE8`) | writer `0x11005FE6` (`0x110061E9`) | writer `0x11006102` (`0x11006305`) | writer `0x1100492F` (`0x11004B32`) |
| `IsInRect` | - | all-vehicles check `0x11004600` (`0x11004662`) | - | - |
| `Build` | - | - | `0x1100301D` (`0x1100328C`), `0x11003503` (`0x1100376C`) | - |
| `Dismantle` | - | - | `0x11003503` (`0x1100373C`) | - |
| `Salvage` | - | - | `0x11003FE2` (`0x110040B2`) | - |
| `Poof` | - | - | the Exit `0x11003DD5` (`0x11003E22`) | Scout waypoints `0x11002244` (`0x110022F1`), `0x1100235B` (`0x11002408`) |
| `SetOffensive` | - | - | escort `0x11002A51` (`0x11002AC3`, false); every 50 `0x11002929` (`0x11002A26`, true) | Panther taken `0x11003D79` (`0x11003D9C`, false); wrecked Panther `0x11003FB2` (`0x11003FFE`, false) |
| `SetEMPticks` | - | - | - | wrecked Panther `0x11003FB2` (`0x11003FF5`, −1 only) |
| `Doze` | - | - | - | dozing `0x11001FFE` (`0x11002053`), `0x11002080` (`0x110020B4`) |
| `GetLights` | - | - | - | lights trigger check `0x110010C0` (`0x110010F5`) |

- **Never used by a mission:** `Dock`, `DockGarage`, `Produce`, `TransferCargo`, `LoadCargo`, `UnloadCargo`,
  `DumpCargo`, `Research`, `TrainScientists`, `Reprogram`, `GetCargo()` and `operator=`. A remake doesn't need them.
- **The carry-over writers** call `GetFactoryCargo` for each of a factory's bays, and `GetCargo` / `GetTruckCargo`
  for ConVecs and trucks.

In an OP2Lua remake, the commands map to the unit methods of OP2Lua's API, and the reads to its unit properties.

## Still open

- **TransferCargo's length** (`0x100012CC`): the packet says 2 bytes but holds the id, the bay and a 0. A local
  handler reading the bay from the packet works; a copy limited to the length (network, replay) would lose the bay.
  Unused by the missions.
- **What the Repair-family data's extra words mean** (`0x100014B3`): the 0 before the target id and the trailing
  0xFFFF. Same for Produce's and Build's trailing 0xFFFF.
- **Build's waypoint and rect** (`0x100011B9`-`0x10001217`): whether the game uses the y × 32 (not centred) waypoint,
  and what +0x248/+0x24A of the type are exactly. q03 uses Build; measure in the harness before copying the
  placement.
- **`0x472D90` and `0x56C230`**: what they are and what they return for an unknown tech.
- **Spaceport bays** (`0x1000180C`): +0x6E as the "kit" for every bay is read correctly from the code, but what the
  field holds is unchecked (q02's reader treats Spaceport pairs oddly too, `q02.md`).
- **Truck cargo width**: `GetCargo` reads +0x24 as a byte and `GetTruckCargo` as a dword; which fields share that
  dword isn't confirmed beyond the low 4 bits.
- **The remaining q02/q04 `GetBusy` callers** (`0x110071F0`, `0x11005E80`) aren't named in the mission specs.
