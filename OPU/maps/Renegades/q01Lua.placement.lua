-- q01Lua.placement.lua  -  Outpost : Renegades - Relocation (Lua) v1.2.8
-- Converted from q01.dll: what its setup makes at every difficulty. What changes with the
-- difficulty (more units on Easy, colonists, stores, research) and the beacons it rolls are in q01Lua.lua.
-- Coordinates are the in-game status-bar ones (map file tile + 1).
return {
  name = "Outpost : Renegades - Relocation (Lua)", map = "Q01.MAP", tech = "Q01.tek",
  type = "1", max_tech = 3, players_count = 2,

  players = {
    [1] = { colony = "Plymouth", human = true, color = "Red" },
    [2] = { colony = "Eden", human = false, color = "Blue" },
  },

  units = {
    -- Player 1
    { type = "CommandCenter", player = 1, at = { 17, 28 } },
    { type = "StructureFactory", player = 1, at = { 17, 24 } },
    { type = "CommonOreSmelter", player = 1, at = { 22, 24 } },
    { type = "Tokamak", player = 1, at = { 12, 46 } },
    { type = "ConVec", direction = "NorthWest", player = 1, at = { 18, 21 } },
    { type = "ConVec", direction = "North", player = 1, at = { 16, 21 } },
    { type = "CargoTruck", direction = "East", player = 1, at = { 25, 22 } },
    { type = "CargoTruck", direction = "SouthEast", player = 1, at = { 25, 25 } },
    { type = "CargoTruck", direction = "North", player = 1, at = { 22, 21 } },
    { type = "RoboSurveyor", direction = "SouthEast", player = 1, at = { 23, 27 } },
    { type = "RoboMiner", direction = "NorthEast", player = 1, at = { 21, 29 } },
    { type = "RoboMiner", direction = "NorthWest", player = 1, at = { 13, 28 } },
    { type = "RoboDozer", direction = "South", player = 1, at = { 17, 31 } },
    -- Player 2
    { type = "CommandCenter", player = 2, at = { 116, 5 } },
    { type = "CommonOreSmelter", player = 2, at = { 112, 5 } },
    { type = "Tokamak", player = 2, at = { 126, 61 } },
    { type = "StructureFactory", player = 2, at = { 121, 5 } },
    { type = "CargoTruck", direction = "South", player = 2, at = { 107, 17 } },
    { type = "CargoTruck", direction = "South", player = 2, at = { 108, 9 } },
    { type = "CargoTruck", direction = "South", player = 2, at = { 109, 25 } },
    { type = "CommonOreMine", player = 2, at = { 114, 30 } },
  },

  walls = {
  },

  beacons = {
    { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "Mid", at = { 56, 23 } },
    { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "Random", at = { 114, 30 } },
    { type = "MiningBeacon", ore = "Common", yield = "Bar3", variant = "Mid", at = { 109, 43 } },
    { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "Mid", at = { 103, 57 } },
    { type = "MiningBeacon", ore = "Common", yield = "Bar3", variant = "Random", at = { 121, 38 } },
    { type = "MiningBeacon", ore = "Common", yield = "Bar1", variant = "Mid", at = { 17, 10 } },
    { type = "Fumarole", ore = "Random", yield = "Random", variant = "Random", at = { 66, 5 } },
  },
}
