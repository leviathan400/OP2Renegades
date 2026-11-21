-- q02Lua.lua  -  Outpost : Renegades - Onslaught (Lua) v1.2.10
-- Converted from q02.dll. With q02Lua.placement.lua (what every difficulty makes alike),
-- this makes the colony's start: what changes with the difficulty, and the beacons the setup rolls.
-- The objectives, the computer players' AI and the mission's events (below the converted part) are written by hand.
-- Games run: Easy 151, Normal 151, Hard 151.
-- Coordinates are the in-game status-bar ones (map file tile + 1); a kit's are relative to its start.

-- The release this mission belongs to (as in the header), posted in the message log at the start, without a sound.
local VERSION = "1.2.10"

-- Beacons rolled each game, alike at every difficulty: `count` of the `spots` (no two alike) with the
-- `kinds` by pick, anywhere in an `area` (x1, y1, x2, y2), or a tile's kind picked from `ways`.
local BEACONS = {
  rolled = {
  },
}

-- The stand-in carry-over's tubes (Q01.mis from the harness: q01 ended as won at tick 2900, alike at every
-- difficulty), made only when there's no q01.carry.
local STANDIN_TUBES = {
  { 11, 45 }, { 11, 46 }, { 12, 45 }, { 12, 46 }, { 15, 23 }, { 15, 24 }, { 15, 25 }, { 16, 23 }, { 16, 24 }, { 16, 25 },
  { 16, 27 }, { 16, 28 }, { 17, 23 }, { 17, 24 }, { 17, 25 }, { 17, 26 }, { 17, 27 }, { 17, 28 }, { 17, 29 }, { 18, 23 },
  { 18, 24 }, { 18, 25 }, { 18, 27 }, { 18, 28 }, { 19, 24 }, { 19, 28 }, { 20, 23 }, { 20, 24 }, { 20, 25 }, { 21, 23 },
  { 21, 24 }, { 21, 25 }, { 22, 23 }, { 22, 24 }, { 22, 25 }, { 22, 26 }, { 23, 23 }, { 23, 24 }, { 23, 25 }, { 24, 24 },
  { 110, 4 }, { 110, 5 }, { 110, 6 }, { 111, 4 }, { 111, 5 }, { 111, 6 }, { 112, 4 }, { 112, 5 }, { 112, 6 }, { 112, 7 },
  { 113, 4 }, { 113, 5 }, { 113, 6 }, { 113, 30 }, { 114, 5 }, { 114, 30 }, { 115, 4 }, { 115, 5 }, { 116, 4 }, { 116, 5 },
  { 116, 6 }, { 117, 4 }, { 117, 5 }, { 118, 5 }, { 119, 4 }, { 119, 5 }, { 119, 6 }, { 120, 4 }, { 120, 5 }, { 120, 6 },
  { 121, 4 }, { 121, 5 }, { 121, 6 }, { 121, 7 }, { 122, 4 }, { 122, 5 }, { 122, 6 }, { 123, 5 }, { 126, 60 }, { 126, 61 },
  { 127, 60 }, { 127, 61 },
}

-- By difficulty (players[1].difficulty), for each player: colonists, stores, research, Structure Factory
-- kits by bay, the camera, units on fixed tiles, units each on a tile rolled in its `area`, and a kit of
-- units on a start rolled from `starts` or anywhere in `start_area`; then the tubes, walls and beacons
-- only this difficulty makes.
local DIFFICULTIES = {
  Easy = {
    players = {
      [1] = {
        workers = 30, scientists = 8, kids = 0, food = 3000, ore = 5000,
        research = { 2114, 3201, 3408 },
        tech_level = 2,
        kits = { [1] = { "Residence" }, [2] = { "Agridome" }, [3] = { "GuardPost", "Microwave" }, [4] = { "GuardPost", "Microwave" }, [5] = { "GuardPost", "Microwave" }, [6] = { "GuardPost", "Microwave" } },
        view = { 17, 28 },
        units = {
        },
      },
      [2] = {
        food = 10000, ore = 10000,
        research = {  },
        tech_level = 12,
        units = {
        },
      },
      [3] = {
        research = {  },
        units = {
        },
      },
    },
    walls = {
    },
    made = {
      { type = "Agridome", lights = true, player = 2, at = { 135, 4 } },
      { type = "Residence", lights = true, player = 2, at = { 138, 4 } },
      { type = "CommandCenter", lights = true, player = 2, at = { 138, 7 } },
      { type = "VehicleFactory", lights = true, player = 2, at = { 143, 7 } },
      { type = "StructureFactory", lights = true, player = 2, at = { 148, 7 } },
      { type = "CargoTruck", direction = "South", lights = true, player = 2, at = { 107, 14 } },
      { type = "CargoTruck", direction = "South", lights = true, player = 2, at = { 108, 9 } },
      { type = "CargoTruck", direction = "South", lights = true, player = 2, at = { 109, 25 } },
      { type = "Lynx", weapon = "Laser", direction = "SouthEast", lights = true, player = 2, at = { 108, 8 } },
      { type = "Lynx", weapon = "Laser", direction = "West", lights = true, player = 2, at = { 114, 11 } },
      { type = "CommandCenter", lights = true, player = 2, at = { 246, 9 } },
      { type = "VehicleFactory", lights = true, player = 2, at = { 241, 9 } },
      { type = "Residence", lights = true, player = 2, at = { 249, 9 } },
      { type = "Agridome", lights = true, player = 2, at = { 249, 6 } },
      { type = "RobotCommand", lights = true, player = 2, at = { 245, 7 } },
      { type = "CommonOreSmelter", lights = true, player = 2, at = { 251, 12 } },
      { type = "CommonStorage", lights = true, player = 2, at = { 251, 10 } },
      { type = "Tokamak", lights = true, player = 2, at = { 245, 14 } },
      { type = "CargoTruck", direction = "South", lights = true, player = 2, at = { 249, 14 } },
      { type = "CargoTruck", direction = "South", lights = true, player = 2, at = { 249, 17 } },
      { type = "CargoTruck", direction = "South", lights = true, player = 2, at = { 249, 20 } },
      { type = "Lynx", weapon = "Laser", direction = "SouthEast", lights = true, player = 2, at = { 240, 8 } },
      { type = "Lynx", weapon = "Laser", direction = "West", lights = true, player = 2, at = { 239, 10 } },
      { type = "Lynx", weapon = "Laser", direction = "South", lights = true, player = 2, at = { 249, 13 } },
      { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "Low", at = { 56, 23 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "Random", at = { 114, 30 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar3", variant = "Low", at = { 109, 43 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "Low", at = { 103, 57 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar3", variant = "Random", at = { 121, 38 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar1", variant = "Random", at = { 17, 10 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar3", variant = "Random", at = { 135, 58 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "Random", at = { 165, 7 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "High", at = { 213, 40 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar3", variant = "Random", at = { 241, 26 }, beacon = true },
      { type = "Fumarole", ore = "Random", yield = "Random", variant = "Random", at = { 66, 5 }, beacon = true },
      { type = "Fumarole", ore = "Random", yield = "Random", variant = "Random", at = { 195, 22 }, beacon = true },
      { carry_over = true },   -- the stand-in carry-over from here (InitMap's part)
      { type = "CommandCenter", player = 1, at = { 17, 28 } },
      { type = "Tokamak", player = 1, at = { 12, 46 } },
      { type = "StructureFactory", player = 1, at = { 17, 24 } },
      { type = "CommonOreSmelter", player = 1, at = { 22, 24 } },
      { type = "CommandCenter", player = 2, at = { 116, 5 } },
      { type = "Tokamak", player = 2, at = { 127, 61 } },
      { type = "StructureFactory", player = 2, at = { 121, 5 } },
      { type = "CommonOreSmelter", player = 2, at = { 112, 5 } },
      { type = "CommonOreMine", player = 2, at = { 114, 30 } },
      { type = "ConVec", direction = "East", player = 1, at = { 18, 21 } },
      { type = "ConVec", direction = "East", player = 1, at = { 16, 21 } },
      { type = "CargoTruck", direction = "East", player = 1, at = { 23, 25 } },
      { type = "CargoTruck", direction = "East", player = 1, at = { 25, 25 } },
      { type = "CargoTruck", direction = "East", player = 1, at = { 22, 21 } },
      { type = "RoboSurveyor", direction = "East", player = 1, at = { 23, 27 } },
      { type = "RoboMiner", direction = "East", player = 1, at = { 21, 29 } },
      { type = "RoboMiner", direction = "East", player = 1, at = { 13, 28 } },
      { type = "RoboDozer", direction = "East", player = 1, at = { 17, 31 } },
    },
    beacons = {
    },
  },
  Normal = {
    players = {
      [1] = {
        workers = 26, scientists = 6, kids = 0, food = 3000, ore = 5000,
        research = { 2114, 3201, 3408 },
        tech_level = 2,
        kits = { [3] = { "GuardPost", "Microwave" }, [4] = { "GuardPost", "Microwave" }, [5] = { "GuardPost", "Microwave" }, [6] = { "GuardPost", "Microwave" } },
        view = { 17, 28 },
        units = {
        },
      },
      [2] = {
        food = 10000, ore = 10000,
        research = {  },
        tech_level = 12,
        units = {
        },
      },
      [3] = {
        research = {  },
        units = {
        },
      },
    },
    walls = {
    },
    made = {
      { type = "Agridome", lights = true, player = 2, at = { 135, 4 } },
      { type = "Residence", lights = true, player = 2, at = { 138, 4 } },
      { type = "CommandCenter", lights = true, player = 2, at = { 138, 7 } },
      { type = "VehicleFactory", lights = true, player = 2, at = { 143, 7 } },
      { type = "StructureFactory", lights = true, player = 2, at = { 148, 7 } },
      { type = "CargoTruck", direction = "South", lights = true, player = 2, at = { 107, 14 } },
      { type = "CargoTruck", direction = "South", lights = true, player = 2, at = { 108, 9 } },
      { type = "CargoTruck", direction = "South", lights = true, player = 2, at = { 109, 25 } },
      { type = "Lynx", weapon = "Laser", direction = "SouthEast", lights = true, player = 2, at = { 108, 8 } },
      { type = "Lynx", weapon = "Laser", direction = "West", lights = true, player = 2, at = { 114, 11 } },
      { type = "CommandCenter", lights = true, player = 2, at = { 246, 9 } },
      { type = "VehicleFactory", lights = true, player = 2, at = { 241, 9 } },
      { type = "Residence", lights = true, player = 2, at = { 249, 9 } },
      { type = "Agridome", lights = true, player = 2, at = { 249, 6 } },
      { type = "RobotCommand", lights = true, player = 2, at = { 245, 7 } },
      { type = "CommonOreSmelter", lights = true, player = 2, at = { 251, 12 } },
      { type = "CommonStorage", lights = true, player = 2, at = { 251, 10 } },
      { type = "Tokamak", lights = true, player = 2, at = { 245, 14 } },
      { type = "CargoTruck", direction = "South", lights = true, player = 2, at = { 249, 14 } },
      { type = "CargoTruck", direction = "South", lights = true, player = 2, at = { 249, 17 } },
      { type = "CargoTruck", direction = "South", lights = true, player = 2, at = { 249, 20 } },
      { type = "Lynx", weapon = "Laser", direction = "SouthEast", lights = true, player = 2, at = { 240, 8 } },
      { type = "Lynx", weapon = "Laser", direction = "West", lights = true, player = 2, at = { 239, 10 } },
      { type = "Lynx", weapon = "Laser", direction = "South", lights = true, player = 2, at = { 249, 13 } },
      { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "Low", at = { 56, 23 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "Random", at = { 114, 30 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar3", variant = "Low", at = { 109, 43 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "Low", at = { 103, 57 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar3", variant = "Random", at = { 121, 38 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar1", variant = "Random", at = { 17, 10 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar3", variant = "Random", at = { 135, 58 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "Random", at = { 165, 7 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "High", at = { 213, 40 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar3", variant = "Random", at = { 241, 26 }, beacon = true },
      { type = "Fumarole", ore = "Random", yield = "Random", variant = "Random", at = { 66, 5 }, beacon = true },
      { type = "Fumarole", ore = "Random", yield = "Random", variant = "Random", at = { 195, 22 }, beacon = true },
      { carry_over = true },   -- the stand-in carry-over from here (InitMap's part)
      { type = "CommandCenter", player = 1, at = { 17, 28 } },
      { type = "Tokamak", player = 1, at = { 12, 46 } },
      { type = "StructureFactory", player = 1, at = { 17, 24 } },
      { type = "CommonOreSmelter", player = 1, at = { 22, 24 } },
      { type = "CommandCenter", player = 2, at = { 116, 5 } },
      { type = "Tokamak", player = 2, at = { 127, 61 } },
      { type = "StructureFactory", player = 2, at = { 121, 5 } },
      { type = "CommonOreSmelter", player = 2, at = { 112, 5 } },
      { type = "CommonOreMine", player = 2, at = { 114, 30 } },
      { type = "ConVec", direction = "East", player = 1, at = { 18, 21 } },
      { type = "ConVec", direction = "East", player = 1, at = { 16, 21 } },
      { type = "CargoTruck", direction = "East", player = 1, at = { 23, 25 } },
      { type = "CargoTruck", direction = "East", player = 1, at = { 25, 25 } },
      { type = "CargoTruck", direction = "East", player = 1, at = { 22, 21 } },
      { type = "RoboSurveyor", direction = "East", player = 1, at = { 23, 27 } },
      { type = "RoboMiner", direction = "East", player = 1, at = { 21, 29 } },
      { type = "RoboMiner", direction = "East", player = 1, at = { 13, 28 } },
      { type = "RoboDozer", direction = "East", player = 1, at = { 17, 31 } },
    },
    beacons = {
    },
  },
  Hard = {
    players = {
      [1] = {
        workers = 24, scientists = 5, kids = 0, food = 2000, ore = 4000,
        research = { 2114, 3201, 3408 },
        tech_level = 2,
        kits = { [5] = { "GuardPost", "Microwave" }, [6] = { "GuardPost", "Microwave" } },
        view = { 17, 28 },
        units = {
        },
      },
      [2] = {
        food = 10000, ore = 10000,
        research = {  },
        tech_level = 12,
        units = {
        },
      },
      [3] = {
        research = {  },
        units = {
        },
      },
    },
    walls = {
    },
    made = {
      { type = "Agridome", lights = true, player = 2, at = { 135, 4 } },
      { type = "Residence", lights = true, player = 2, at = { 138, 4 } },
      { type = "CommandCenter", lights = true, player = 2, at = { 138, 7 } },
      { type = "VehicleFactory", lights = true, player = 2, at = { 143, 7 } },
      { type = "StructureFactory", lights = true, player = 2, at = { 148, 7 } },
      { type = "CargoTruck", direction = "South", lights = true, player = 2, at = { 107, 14 } },
      { type = "CargoTruck", direction = "South", lights = true, player = 2, at = { 108, 9 } },
      { type = "CargoTruck", direction = "South", lights = true, player = 2, at = { 109, 25 } },
      { type = "Lynx", weapon = "Laser", direction = "SouthEast", lights = true, player = 2, at = { 108, 8 } },
      { type = "Lynx", weapon = "Laser", direction = "West", lights = true, player = 2, at = { 114, 11 } },
      { type = "CommandCenter", lights = true, player = 2, at = { 246, 9 } },
      { type = "VehicleFactory", lights = true, player = 2, at = { 241, 9 } },
      { type = "Residence", lights = true, player = 2, at = { 249, 9 } },
      { type = "Agridome", lights = true, player = 2, at = { 249, 6 } },
      { type = "RobotCommand", lights = true, player = 2, at = { 245, 7 } },
      { type = "CommonOreSmelter", lights = true, player = 2, at = { 251, 12 } },
      { type = "CommonStorage", lights = true, player = 2, at = { 251, 10 } },
      { type = "Tokamak", lights = true, player = 2, at = { 245, 14 } },
      { type = "CargoTruck", direction = "South", lights = true, player = 2, at = { 249, 14 } },
      { type = "CargoTruck", direction = "South", lights = true, player = 2, at = { 249, 17 } },
      { type = "CargoTruck", direction = "South", lights = true, player = 2, at = { 249, 20 } },
      { type = "Lynx", weapon = "Laser", direction = "SouthEast", lights = true, player = 2, at = { 240, 8 } },
      { type = "Lynx", weapon = "Laser", direction = "West", lights = true, player = 2, at = { 239, 10 } },
      { type = "Lynx", weapon = "Laser", direction = "South", lights = true, player = 2, at = { 249, 13 } },
      { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "Low", at = { 56, 23 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "Random", at = { 114, 30 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar3", variant = "Low", at = { 109, 43 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "Low", at = { 103, 57 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar3", variant = "Random", at = { 121, 38 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar1", variant = "Random", at = { 17, 10 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar3", variant = "Random", at = { 135, 58 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "Random", at = { 165, 7 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "High", at = { 213, 40 }, beacon = true },
      { type = "MiningBeacon", ore = "Common", yield = "Bar3", variant = "Random", at = { 241, 26 }, beacon = true },
      { type = "Fumarole", ore = "Random", yield = "Random", variant = "Random", at = { 66, 5 }, beacon = true },
      { type = "Fumarole", ore = "Random", yield = "Random", variant = "Random", at = { 195, 22 }, beacon = true },
      { carry_over = true },   -- the stand-in carry-over from here (InitMap's part)
      { type = "CommandCenter", player = 1, at = { 17, 28 } },
      { type = "Tokamak", player = 1, at = { 12, 46 } },
      { type = "StructureFactory", player = 1, at = { 17, 24 } },
      { type = "CommonOreSmelter", player = 1, at = { 22, 24 } },
      { type = "CommandCenter", player = 2, at = { 116, 5 } },
      { type = "Tokamak", player = 2, at = { 127, 61 } },
      { type = "StructureFactory", player = 2, at = { 121, 5 } },
      { type = "CommonOreSmelter", player = 2, at = { 112, 5 } },
      { type = "CommonOreMine", player = 2, at = { 114, 30 } },
      { type = "ConVec", direction = "East", player = 1, at = { 18, 21 } },
      { type = "ConVec", direction = "East", player = 1, at = { 16, 21 } },
      { type = "CargoTruck", direction = "East", player = 1, at = { 23, 25 } },
      { type = "CargoTruck", direction = "East", player = 1, at = { 25, 25 } },
      { type = "CargoTruck", direction = "East", player = 1, at = { 22, 21 } },
      { type = "RoboSurveyor", direction = "East", player = 1, at = { 23, 27 } },
      { type = "RoboMiner", direction = "East", player = 1, at = { 21, 29 } },
      { type = "RoboMiner", direction = "East", player = 1, at = { 13, 28 } },
      { type = "RoboDozer", direction = "East", player = 1, at = { 17, 31 } },
    },
    beacons = {
    },
  },
}

-- Where lava may flow (x1, y1, x2, y2).
local LAVA_POSSIBLE = {
  { 225, 3, 226, 3 },
  { 220, 4, 227, 4 },
  { 220, 5, 228, 5 },
  { 221, 6, 228, 6 },
  { 220, 7, 228, 7 },
  { 219, 8, 221, 8 },
  { 226, 8, 229, 11 },
  { 216, 9, 221, 9 },
  { 215, 10, 221, 10 },
  { 215, 11, 222, 11 },
  { 214, 12, 222, 12 },
  { 226, 12, 228, 12 },
  { 214, 13, 228, 13 },
  { 207, 14, 210, 14 },
  { 214, 14, 227, 14 },
  { 196, 15, 200, 15 },
  { 203, 15, 229, 15 },
  { 195, 16, 229, 16 },
  { 192, 17, 229, 17 },
  { 191, 18, 229, 18 },
  { 190, 19, 229, 20 },
  { 191, 21, 230, 21 },
  { 198, 22, 231, 22 },
  { 198, 23, 244, 23 },
  { 200, 24, 245, 24 },
  { 202, 25, 225, 25 },
  { 228, 25, 232, 25 },
  { 237, 25, 244, 25 },
  { 211, 26, 221, 26 },
  { 236, 26, 244, 27 },
  { 211, 27, 214, 27 },
  { 218, 27, 222, 27 },
  { 220, 28, 222, 28 },
  { 237, 28, 248, 28 },
  { 252, 28, 253, 28 },
  { 236, 29, 256, 29 },
  { 241, 30, 256, 32 },
  { 231, 33, 236, 33 },
  { 238, 33, 256, 36 },
  { 230, 34, 235, 35 },
  { 231, 36, 236, 36 },
  { 229, 37, 256, 38 },
  { 228, 39, 229, 39 },
  { 233, 39, 256, 39 },
  { 232, 40, 256, 40 },
  { 232, 41, 239, 41 },
  { 246, 41, 249, 41 },
  { 254, 41, 256, 41 },
  { 230, 42, 237, 42 },
  { 255, 42, 256, 43 },
  { 230, 43, 231, 43 },
  { 233, 43, 236, 43 },
  { 231, 44, 234, 45 },
  { 232, 46, 234, 46 },
}

local kits_set = false
local function make_unit(player, u, at, kits, exact)
  local made = game.create_unit{ type = u.type, player = player, at = at, direction = u.direction,
                                 weapon = u.weapon, lights = u.lights, exact = exact }
  if u.cargo and made[1] then made[1]:set_cargo(u.cargo, u.amount) end
  -- A ConVec's kit with its weapon (a Guard Post kit's).
  if u.topping and made[1] then made[1]:set_kit(u.weapon, u.topping) end
  -- A vehicle the setup parks in a Garage: its bay, by the Garage's dock.
  if u.garage and made[1] then made[1]:put_in_garage(u.garage.bay, u.garage.at) end
  if u.type == "StructureFactory" and kits and made[1] then
    for bay, kit in pairs(kits) do made[1]:set_factory_cargo(bay, kit[1], kit[2]) end
    kits_set = true
  end
end

-- One player's start at the chosen difficulty.
function make_player(player, p)
  if p.tech_level then player:set_tech_level(p.tech_level) end
  for _, tech in ipairs(p.research) do player:mark_research(tech) end
  -- Only the numbers the setup sets.
  for _, k in ipairs({ "ore", "rare_ore", "food", "workers", "scientists", "kids" }) do
    if p[k] then player[k] = p[k] end
  end
  for _, u in ipairs(p.units) do make_unit(player, u, u.at, p.kits, true) end
  -- As the setup draws them: the game's own MAP_RECT::RandPt.
  for _, u in ipairs(p.rolled or {}) do make_unit(player, u, game.rand_point(u.area), p.kits, true) end
  local start = p.starts and p.starts[game.rand(#p.starts) + 1]
  local s = p.start_area
  -- A start drawn in a row or a column draws only along it (CPS2: one GetRand(91) for x).
  local function along(lo, hi) return hi > lo and lo + game.rand(hi - lo + 1) or lo end
  if s then start = { along(s[1], s[3]), along(s[2], s[4]) } end
  local function place(t) return start and { start[1] + t[1], start[2] + t[2] } or t end
  -- The original asks for every unit of a kit on one tile; the game finds each a place nearby.
  for _, u in ipairs(p.kit or {}) do make_unit(player, u, place(u.at), p.kits, false) end
  -- A Structure Factory alike at every difficulty is the placement's; its bays are the difficulty's (Eden 1).
  if p.kits and not kits_set then
    local f = player:buildings("StructureFactory")[1]
    if f then
      for bay, kit in pairs(p.kits) do f:set_factory_cargo(bay, kit[1], kit[2]) end
    end
  end
  kits_set = false
  if p.view then player:center_view(place(p.view)) end
end

function make_walls(walls)
  for _, w in ipairs(walls) do
    if w[1] == "Tube" then game.create_tube(w[2]) else game.create_wall(w[1], w[2]) end
  end
end

function make_things(d)
  make_walls(d.walls)
  for _, b in ipairs(d.beacons) do game.create_beacon(b) end
end

local function copy(t)
  local c = {}
  for k, v in pairs(t) do c[k] = v end
  return c
end

-- The difficulty's units and beacons in the order the original makes them; `roll = k` rolls the k-th of `rolled`.
function make_in_order(d, rolled)
  for _, t in ipairs(d.made or {}) do
    if t.carry_over then
      -- InitMap's part: from q01.carry when there is one (the rest of the list is the stand-in's).
      if carry_point() then return end
    elseif t.roll then
      roll_beacons({ rolled[t.roll] })
    elseif t.beacon then
      local b = copy(t)
      b.beacon = nil
      game.create_beacon(b)
    else
      make_unit(players[t.player], t, t.at, d.players[t.player] and d.players[t.player].kits, true)
    end
  end
end

function roll_beacons(rolled)
  for _, r in ipairs(rolled) do
    if r.table then
      -- As the setup draws them: an index into its table, again while it repeats one; all picks, then the beacons.
      local picks, seen = {}, {}
      while #picks < r.count do
        local v = game.rand(#r.table)
        if not seen[v] then seen[v] = true picks[#picks + 1] = v end
      end
      for i, v in ipairs(picks) do
        local b = copy(r.kinds[i])
        b.at = r.table[v + 1]
        game.create_beacon(b)
      end
    elseif r.spots then
      local spots = {}
      for i, s in ipairs(r.spots) do spots[i] = s end
      for i = 1, r.count do
        local b = copy(r.kinds[i])
        b.at = table.remove(spots, game.rand(#spots) + 1)
        game.create_beacon(b)
      end
    elseif r.area then
      local a, b = r.area, copy(r)
      b.area, b.draws, b.x_draw, b.base = nil, nil, nil, nil
      if r.draws then
        -- As the setup draws it: two numbers, one added to the base's x and the other to its y.
        local d = { game.rand(r.draws[1]), game.rand(r.draws[2]) }
        b.at = { r.base[1] + d[r.x_draw], r.base[2] + d[3 - r.x_draw] }
      else
        b.at = { a[1] + game.rand(a[3] - a[1] + 1), a[2] + game.rand(a[4] - a[2] + 1) }
      end
      game.create_beacon(b)
    else
      game.create_beacon(r.ways[game.rand(#r.ways) + 1])
    end
  end
end

-- ---------------------------------------------------------------------------------------------------------------
-- The mission itself, written by hand from q02.dll (Renegades' own event list, ../../findings/decompile/q02.md).
-- The DLL's numbers are kept as it has them: P() and RECT() turn its internal tiles (x + 32 on this 256-wide map)
-- into status-bar ones, so each line can be checked against the address it came from.
-- ---------------------------------------------------------------------------------------------------------------

local function P(x, y) return { x - 31, y + 1 } end
local function RECT(x1, y1, x2, y2) return { x1 - 31, y1 + 1, x2 - 31, y2 + 1 } end
local function IX(unit) return unit.x + 31 end              -- a unit's tile as the DLL has it
local function IY(unit) return unit.y - 1 end
local DIRS = { [0] = "East", "SouthEast", "South", "SouthWest", "West", "NorthWest", "North", "NorthEast" }

local HUMAN, EDEN, PICKUP = 1, 2, 3                         -- the DLL's players 0, 1 and 2
local EVAC = { 0x10D, 0x36 }                                -- the evacuation point (0x110015DB)

local state = {
  d = 0,                       -- 0x1101C0F4: 0 Easy, 1 Normal, 2 Hard
  food = 0, metal = 0,         -- 0x1101C100, 0x1101C104: trucks of food and of metal to evacuate
  short = {},                  -- 0x1101C108-0x1101C114: what the convoy brings
  cc = { 0, 0 },               -- 0x1101C0CC: player 1's first Command Center
  research = { [3401] = true, [3304] = true, [3305] = true },  -- 0x1101C118-0x1101C11A: not done yet
  pickup_calls = 0,            -- 0x1101C11C
  convoy_seen = false,         -- 0x1101C122
  east_want = 0,               -- 0x1101C0EC
  team = {},                   -- 0x1101C144: the latest scorched-earth team
}
local g = {}                   -- the DLL's groups
local keep = {}                -- the units it keeps
local vc = {}                  -- the victory conditions it removes later
local repairers = {}           -- 0x110162AC: a structure's repairer, by the structure's id and player

-- ---------------------------------------------------------------------------------------------------------------
-- The carry-over from q01 (InitMap, 0x11004A36; ../../findings/decompile/q02.md). q01's remake keeps it as q01.carry
-- in OP2Lua's campaign store (its format is in q01Lua.lua). Without one (a mission picked on its own, a core without
-- the store) the start is the stand-in's, as before.
-- ---------------------------------------------------------------------------------------------------------------

local carry = { data = nil, difficulty = nil }

local function load_carry_over(name)
  if not campaign then print("This OP2LuaCore has no campaign store: the stand-in start") return nil end
  local data, err = campaign.load(name)
  if not data then print("No " .. name .. ".carry (" .. tostring(err) .. "): the stand-in start") end
  return data
end

-- InitMap's distance: the enumerator's squared distance in pixels (32 a tile) shifted right by 9, so 2 x tiles².
-- It fits the stand-in: of q01's trucks 3, 3.2 and 3.6 tiles from the smelter, only the last (2 x 13 = 26 > 0x19)
-- was moved.
local function distance(a, b)
  local dx, dy = a.x - b.x, a.y - b.y
  return 2 * (dx * dx + dy * dy)
end

-- The closest structure to `at` not owned by Eden, a Common Ore Smelter with `smelter` (0x11004B5E).
local function closest_structure(at, smelter)
  local best, best_d
  for id = 1, game.num_players() do
    if id ~= EDEN then
      for _, s in ipairs(players[id]:buildings(smelter and "CommonOreSmelter" or nil)) do
        local dd = distance(s, at)
        if not best_d or dd < best_d then best, best_d = s, dd end
      end
    end
  end
  return best, best_d
end

-- Rebuilds q01's carry-over as InitMap does. Returns the difficulty q01 was played at.
local function build_carry_over(c)
  -- 1. The map cells (0x11006737): dozed and rubble get their type and tile, a normal wall a Wall, a 0x1A cell a Tube.
  for _, r in ipairs(c.cells or {}) do
    local at, t = { r[1], r[2] }, r[3]
    if t == 0x15 or t == 0x16 then
      game.set_cell_type(at, t)
      if r[4] then game.set_tile(at, r[4]) end
    elseif t == 0x17 then
      game.create_wall("Wall", at)
    elseif t == 0x1A then
      game.create_tube(at)
    end
  end
  -- 2. Player 1's structures, then Eden's (0x110064F3), each at its saved tile; factories get their bays back.
  for _, id in ipairs({ HUMAN, EDEN }) do
    for _, r in ipairs(c.units or {}) do
      if r.player == id and not r.vehicle then
        local made = game.create_unit{ type = r.type, player = players[id], at = { r.x, r.y }, weapon = r.weapon,
                                       exact = true }
        if made[1] and r.bays then
          for bay, b in ipairs(r.bays) do
            if b[1] ~= "None" then made[1]:set_factory_cargo(bay, b[1], b[2]) end
          end
        end
        if id == HUMAN and r.type == "CommandCenter" then players[HUMAN]:center_view({ r.x, r.y }) end
      end
    end
  end
  -- 3. Player 1's vehicles; Eden's are never made (0x1100690B).
  local list = {}
  for _, r in ipairs(c.units or {}) do
    if r.player == HUMAN and r.vehicle then list[#list + 1] = r end
  end
  -- 5-6. From the list's end: a vehicle far from the base is brought to it (0x11004B5E-0x11004C93), then made
  -- (0x110069DD): trucks empty, ConVecs with their kit, the rest with their weapon, lights on.
  local has_smelter = #players[HUMAN]:buildings("CommonOreSmelter") > 0
  for i = #list, 1, -1 do
    local r = list[i]
    local at, exact = { r.x, r.y }, true
    local truck = r.type == "CargoTruck"
    local s, sd = closest_structure(r, truck and has_smelter)
    if s then
      if truck and sd > 0x19 then
        at, exact = { s.x, s.y }, false
      elseif sd > 0x50 then
        local x = s.x - 5 + game.rand(11)
        at, exact = { x, s.y - 5 + game.rand(11) }, false
      end
    end
    local made = game.create_unit{ type = r.type, player = players[HUMAN], at = at,
                                   weapon = r.type ~= "ConVec" and not truck and r.weapon or nil, exact = exact }
    if made[1] and r.type == "ConVec" and r.kit then made[1]:set_kit(r.kit, r.weapon) end
  end
  return c.colony and c.colony.difficulty
end

-- Called where the made lists reach InitMap's part: true when q01.carry was rebuilt (skip the stand-in's units).
function carry_point()
  if carry.data then
    carry.difficulty = build_carry_over(carry.data)
    return true
  end
  for _, t in ipairs(STANDIN_TUBES) do game.create_tube(t) end
  return false
end

-- ---------------------------------------------------------------------------------------------------------------
-- The carry-over writer, the same in q01-q03 (master copy: tools/carry/writer.lua; paste it in whole, OP2Lua has
-- no require). The original DLL writes Q0N.mis as the game unloads it after a win (0x11005FA7 in q02;
-- ../../findings/decompile/q02.md, "The carry-over q02 writes"); the remake keeps the same contents with OP2Lua's
-- campaign store as q0N.carry beside this DLL. Status-bar tiles, Lua's 1-based players, the API's names:
-- - cells: { x, y, cell type, tile }, for each cell whose type is above 0xF (the tile for dozed and rubble only);
-- - colony: the human player's difficulty (0-2), food, kids, ore, rare ore, scientists and workers (no RLV count);
-- - units: every player's, the highest first, structures then vehicles: type, player, x, y, weapon, a ConVec's kit,
--   a truck's cargo and amount, and a Structure Factory's or Spaceport's six bays ({ kit, weapon or cargo }).
-- A game started by op2launcher never tells the script it ended, so it's written once every victory condition
-- still standing has fired (the game then ends as won), and again in on_end when the game reports a win.
-- ---------------------------------------------------------------------------------------------------------------

local carry_wins = {}
do
  local victory = mission.victory
  mission.victory = function(...)
    local t = victory(...)
    carry_wins[#carry_wins + 1] = t
    return t
  end
end

-- Every victory condition still standing has fired for the human player (players[1] in q01-q04).
local function carry_won()
  local any = false
  for _, t in ipairs(carry_wins) do
    if t.valid then
      if not t:has_fired(players[1]) then return false end
      any = true
    end
  end
  return any
end

local function carry_over(mission_name, difficulty)
  local size = game.map_size()
  local cells = {}
  for y = 1, size.h do
    for x = 1, size.w do
      local t = game.cell(x, y).type
      if t > 0xF then
        cells[#cells + 1] = (t == 0x15 or t == 0x16) and { x, y, t, game.tile({ x, y }) } or { x, y, t }
      end
    end
  end
  local p = players[1]
  local colony = { difficulty = difficulty, food = p.food, kids = p.kids, ore = p.ore, rare_ore = p.rare_ore,
                   scientists = p.scientists, workers = p.workers }
  local function named(v) return v and v ~= "None" and v ~= "" and v ~= "Empty" and v or nil end
  local units = {}
  local function add(id, u)
    local r = { type = u.type, player = id, x = u.x, y = u.y, vehicle = u.is_vehicle or nil,
                weapon = named(u.weapon), kit = u.type == "ConVec" and named(u.kit) or nil }
    if named(u.cargo) then r.cargo, r.amount = u.cargo, u.cargo_amount end
    if u.type == "StructureFactory" or u.type == "Spaceport" then
      r.bays = {}
      for bay = 1, 6 do
        local kit, extra = u:factory_cargo(bay)
        r.bays[bay] = { kit or "None", extra }
      end
    end
    units[#units + 1] = r
  end
  for id = game.num_players(), 1, -1 do
    for _, u in ipairs(players[id]:units()) do if u.is_building then add(id, u) end end
    for _, u in ipairs(players[id]:units()) do if u.is_vehicle then add(id, u) end end
  end
  return { mission = mission_name, tick = game.tick(), colony = colony, cells = cells, units = units }
end

local function save_carry_over(mission_name, difficulty, why)
  if not campaign then print("This OP2LuaCore has no campaign store: no carry-over written") return end
  local data = carry_over(mission_name, difficulty)
  local ok, err = campaign.save(mission_name, data)
  print(("Carry-over %s.carry (%s): %s, %d cells, %d units%s"):format(mission_name, why,
        ok and "saved" or "not saved", #data.cells, #data.units, err and (": " .. err) or ""))
end

function on_end(result)
  if result and result.result == "won" then save_carry_over("q02", state.d, "the game reports the win") end
end

local function make(type, player, at, direction, weapon)
  return game.create_unit{ type = type, player = player, at = at, direction = DIRS[direction or 0],
                           weapon = weapon, exact = true }[1]
end

local function route(points)
  local r = {}
  for i, p in ipairs(points) do r[i] = P(p[1], p[2]) end
  return r
end

-- The DLL's events (mission-framework.md), worked as its runner works them: every game cycle, from the newest event
-- to the oldest. An event made during a pass waits for the next one; a one-shot event goes once it fires.
local events = {}

local function add_event(ev)
  if #events >= 512 then
    print("Maximum number of events reached!")
    return nil
  end
  ev.skip = true
  events[#events + 1] = ev
  return ev
end

local function run_events()
  for i = #events, 1, -1 do
    local ev = events[i]
    if not ev.skip and not ev.dead then ev:run() end
  end
  local kept = {}
  for _, ev in ipairs(events) do
    ev.skip = false
    if not ev.dead then kept[#kept + 1] = ev end
  end
  events = kept
end

local function fire(ev, value)
  if ev.one_shot then ev.dead = true end
  ev.fn(value)
end

-- A time event (0x11007700): due `min` + GetRand(max - min) ticks after it's made, or exactly `min` when they're
-- equal; a repeating one is due that long again after each run, drawn after its callback (0x110076C0).
local function draw(min, max) return min == max and min or min + game.rand(max - min) end

local function time_event(one_shot, min, max, fn)
  local now = game.tick()
  local ev = { one_shot = one_shot, fn = fn, last = now, due = now + draw(min, max) }
  function ev:run()
    local t = game.tick()
    if t >= self.due and self.last < self.due then
      fire(self)
      if self.dead then return end
      self.due = self.due + draw(min, max)
    end
    self.last = t
  end
  return add_event(ev)
end
local function once(min, max, fn) return time_event(true, min, max, fn) end
local function repeating(min, max, fn) return time_event(false, min, max, fn) end

-- The other kinds, all one-shot in q02: they fire with what `test()` found (the unit, for the tile events).
local function condition_event(test, fn)
  local ev = { one_shot = true, fn = fn }
  function ev:run()
    local v = test()
    if v then fire(self, v) end
  end
  return add_event(ev)
end

local COMPARE = { [0] = function(a, b) return a == b end, function(a, b) return a <= b end,
                  function(a, b) return a >= b end, function(a, b) return a < b end, function(a, b) return a > b end }

-- A unit count (0x11007840).
local function count_event(player, type, n, compare, fn)
  return condition_event(function() return COMPARE[compare](players[player]:unit_count(type), n) end, fn)
end

-- A player's working structures of a type (0x11007210): not idle (0x12), being built (0x21) or taken down (0x22).
local function operational(player, type)
  local n = 0
  for _, b in ipairs(players[player]:buildings(type)) do
    local c = b.command
    if c ~= 0x12 and c ~= 0x21 and c ~= 0x22 then n = n + 1 end
  end
  return n
end

-- More than none of them (0x11007420).
local function operational_event(player, type, fn)
  return condition_event(function() return operational(player, type) > 0 end, fn)
end

-- The player's unit on a tile (0x11007910), or a structure there that isn't busy with command 0x1E, 0x21 or 0x22
-- (0x11007035).
local function unit_on_tile(player, x, y, structure)
  local at = P(x, y)
  for _, v in ipairs(game.units_in_rect({ at[1], at[2], at[1], at[2] })) do
    if v.owner == player - 1 and v.x == at[1] and v.y == at[2] then
      local c = v.command
      if not structure or (v.is_building and c ~= 0x1E and c ~= 0x21 and c ~= 0x22) then return v end
    end
  end
end

local function tile_event(player, x, y, fn)                 -- 0x11007A00
  return condition_event(function() return unit_on_tile(player, x, y, false) end, fn)
end

local function structure_event(player, x, y, fn)            -- 0x11007104
  return condition_event(function() return unit_on_tile(player, x, y, true) end, fn)
end

-- Any of the player's units in the rectangle x, y to x + w, y + h (0x11007B70).
local function area_event(player, x, y, w, h, fn)
  local r = RECT(x, y, x + w, y + h)
  return condition_event(function()
    for _, v in ipairs(game.units_in_rect(r)) do
      if v.owner == player - 1 then return true end
    end
  end, fn)
end

-- A group's losses (0x110075B0), against its count now. Mode 1: none left, 2: three quarters left, 3: half left.
local function loss_event(group, mode, fn)
  local n = group:unit_count()
  local left = mode == 2 and (n * 3) // 4 or mode == 3 and n // 2 or 0
  return condition_event(function() return group:unit_count() <= left end, fn)
end

local function fight(player, rect, lights)
  local grp = ai.fight_group(player)
  if rect then grp:set_rect(rect) end
  grp:set_lights(lights)
  return grp
end

local function first_at(player, type, x)                   -- the first of the player's `type` at internal x
  for _, b in ipairs(players[player]:buildings(type)) do
    if IX(b) == x then return b end
  end
end

-- ---------------------------------------------------------------------------------------------------------------
-- The setup
-- ---------------------------------------------------------------------------------------------------------------

-- InitMap's last steps (0x1100491A, 0x11004CAF): the Command Center the convoy heads for, what the convoy brings
-- (the targets less what came from q01), and Eden's vehicle factories (the last on each side of x 0xC9).
local function after_carry_over()
  local cc = players[HUMAN]:buildings("CommandCenter")[1]
  if cc then state.cc = { IX(cc), IY(cc) } end
  local s = { ConVec = state.d == 2 and 1 or 2, CargoTruck = state.d == 2 and 3 or 4, RoboMiner = 3 - state.d,
              RoboSurveyor = 1 }
  for _, v in ipairs(players[HUMAN]:units()) do
    if v.is_vehicle and s[v.type] then s[v.type] = s[v.type] - 1 end
  end
  s.RoboMiner = s.RoboMiner - players[HUMAN]:unit_count("CommonOreMine")
  state.short = s
  for _, f in ipairs(players[EDEN]:buildings("VehicleFactory")) do
    if IX(f) < 0xC9 then keep.west_vf = f else keep.east_vf = f end
  end
end

-- Eden's groups (0x11004DAC). Guards want 2d + 2 Laser Lynx; the raid sources 2d + 1.
local function make_groups()
  local d2 = state.d * 2
  local cx, cy = state.cc[1], state.cc[2]
  g.west_mining = ai.mining_group(EDEN)                                         -- 0x1101C0C0
  g.west_mining:set_lights(true)
  g.east_mining = ai.mining_group(EDEN)                                         -- 0x1101C0C4
  g.east_mining:set_lights(true)
  g.west_rebuild = ai.building_group(EDEN)                                      -- 0x1101C0A8
  g.west_rebuild:set_rect(RECT(0x94, 6, 0x9A, 8))
  g.west_rebuild:set_lights(true)
  g.south_base = ai.building_group(EDEN)                                        -- 0x1101C0AC
  g.south_base:set_rect(RECT(0xA8, 0x2F, 0xAC, 0x31))
  g.south_base:set_lights(true)
  g.new_base = ai.building_group(EDEN)                                          -- 0x1101C0B0
  g.new_base:set_lights(true)
  g.west_factory = ai.building_group(EDEN)                                      -- 0x1101C0B4
  g.west_factory:set_rect(RECT(0xA4, 2, 0xB5, 8))
  g.west_factory:set_lights(true)
  g.east_factory = ai.building_group(EDEN)                                      -- 0x1101C0B8
  g.east_factory:set_rect(RECT(0x10E, 4, 0x11A, 0xC))
  g.east_factory:set_lights(true)
  g.south_factory = ai.building_group(EDEN)                                     -- 0x1101C0BC
  g.south_factory:set_lights(true)
  g.staging = fight(EDEN, RECT(0x89, 0xD, 0x8F, 0x11), true)                    -- 0x1101C074
  g.east_production = fight(EDEN, RECT(0x10E, 4, 0x11A, 0xC), true)             -- 0x1101C070
  g.attack = ai.fight_group(EDEN)                                               -- 0x1101C078
  g.attack:set_rect(RECT(cx - 6, cy - 10, cx + 10, cy + 4))
  g.attack:do_attack_enemy()
  g.attack:set_lights(true)
  g.raid_source_south = ai.fight_group(EDEN)                                    -- 0x1101C07C
  g.raid_source_south:set_rect(RECT(0x8A, 0x25, 0x8E, 0x2A))
  g.raid_source_south:set_targ_count("Lynx", "Laser", d2 + 1)
  g.raid_source_south:set_lights(true)
  g.raid_source_north = ai.fight_group(EDEN)                                    -- 0x1101C080
  g.raid_source_north:set_rect(RECT(0x81, 6, 0x85, 10))
  g.raid_source_north:set_targ_count("Lynx", "Laser", d2 + 1)
  g.raid_source_north:set_lights(true)
  g.raiders_south = fight(EDEN, nil, false)                                     -- 0x1101C084
  g.raiders_north = fight(EDEN, nil, false)                                     -- 0x1101C088
  g.strike_south = fight(EDEN, RECT(cx - 3, cy - 3, cx + 2, cy + 2), false)     -- 0x1101C08C
  g.strike_north = fight(EDEN, RECT(cx - 3, cy - 3, cx + 2, cy + 2), false)     -- 0x1101C090
  local guards = {
    { "west_guard", RECT(0x8B, 2, 0x95, 8), d2 + 2 },                           -- 0x1101C060
    { "table_guard", RECT(0xA4, 2, 0xB1, 9), d2 + 2 },                          -- 0x1101C064
    { "east_guard", RECT(0x110, 3, 0x11D, 0xE), d2 + 2 },                       -- 0x1101C068
    { "south_guard", RECT(0xA2, 0x2D, 0xAA, 0x32), 2 },                         -- 0x1101C06C
  }
  for _, gd in ipairs(guards) do
    local grp = ai.fight_group(EDEN)
    grp:set_rect(gd[2])
    grp:set_targ_count("Lynx", "Laser", gd[3])
    grp:set_lights(true)
    g[gd[1]] = grp
  end
end

-- Eden's three patrols (0x1100378F), each with its Lynx.
local function make_patrols()
  local patrols = {
    { "north_patrol", RECT(0x8B, 4, 0x98, 0x16), { { 0x8B, 2 }, { 0x8D, 0x21 }, { 0x95, 7 } },
      { { 0x8D, 0x10, 3 }, { 0x90, 0x19, 2 }, { 0x8D, 8, 1 } } },                                        -- 0x1101C054
    { "middle_patrol", RECT(0xB3, 0x14, 0xBB, 0x3C), { { 0xB8, 0x3C }, { 0xB5, 0x14 } },
      { { 0xB5, 0x16, 3 }, { 0xB7, 0x28, 2 }, { 0xB8, 0x39, 1 } } },                                     -- 0x1101C058
    { "east_patrol", RECT(0xC0, 0xA, 0xD7, 0x37),
      { { 0xC8, 0x37 }, { 0xC0, 0x1D }, { 0xC8, 0xA }, { 0xD7, 0x11 }, { 0xC9, 0x28 }, { 0xD4, 0x31 } },
      { { 0xAF, 8, 3 }, { 0xB1, 2, 2 } } },                                                              -- 0x1101C05C
  }
  for _, p in ipairs(patrols) do
    local grp = ai.fight_group(EDEN)
    grp:set_rect(p[2])
    grp:set_patrol(route(p[3]))
    grp:set_lights(true)
    for _, l in ipairs(p[4]) do grp:take_unit(make("Lynx", EDEN, P(l[1], l[2]), l[3], "Laser")) end
    grp:set_targ_count("Lynx", "Laser", state.d * 2 + 2)
    g[p[1]] = grp
  end
end

-- 0x11001448: a line of tubes (or walls) from one end to the other, or, when both ends differ, an L: along x, then
-- along y from the corner (which is recorded twice).
local function record_line(group, x1, y1, x2, y2, wall)
  if x1 ~= x2 and y1 ~= y2 then
    record_line(group, x1, y1, x2, y1, wall)
    record_line(group, x2, y1, x2, y2, wall)
    return
  end
  local dx = x2 > x1 and 1 or x2 < x1 and -1 or 0
  local dy = y2 > y1 and 1 or y2 < y1 and -1 or 0
  local x, y = x1, y1
  local function rec()
    if wall then group:record_wall(P(x, y), "Wall") else group:record_tube(P(x, y)) end
  end
  rec()
  while x ~= x2 or y ~= y2 do
    x, y = x + dx, y + dy
    rec()
  end
end

local start_south_mining, start_south_base

-- The west factory and who it feeds (0x110029FB).
local function west_factory()
  if keep.west_vf then g.west_factory:take_unit(keep.west_vf) end
  g.west_factory:record_veh_reinforce_group(g.west_mining, 400)
  g.west_factory:record_veh_reinforce_group(g.west_rebuild, 800)
  g.west_factory:record_veh_reinforce_group(g.west_guard, 250)
  g.west_factory:record_veh_reinforce_group(g.table_guard, 200)
  g.west_factory:record_veh_reinforce_group(g.raid_source_south, 100)
  g.west_factory:record_veh_reinforce_group(g.raid_source_north, 400)
end

-- Eden's builders and what they keep standing (0x11002ECD).
local function setup_bases()
  keep.convec_w = make("ConVec", EDEN, P(0x98, 6), 4)                         -- 0x1101C010
  keep.convec_sw = make("ConVec", EDEN, P(0xA6, 5), 3)                        -- 0x1101C018
  keep.earthworker = make("Earthworker", EDEN, P(0x8D, 7), 0)                 -- 0x1101C014
  local sfs = players[EDEN]:buildings("StructureFactory")
  keep.west_sf, keep.new_sf = sfs[1], sfs[2]                                   -- 0x1101C02C, 0x1101C030
  if not keep.new_sf then
    keep.new_sf = make("StructureFactory", EDEN, P(0x110, 4), 0)
    game.create_tube(P(0x114, 3))
  end
  keep.new_sf:set_factory_cargo(6, "CommandCenter")                            -- the DLL's bays 5 and 4
  keep.new_sf:set_factory_cargo(5, "CommonOreSmelter")
  local x, y = IX(keep.new_sf), IY(keep.new_sf)
  local nb = g.new_base
  nb:set_rect(RECT(x - 3, y - 3, x + 2, y + 2))
  nb:take_unit(keep.new_sf)
  nb:set_targ_count("ConVec", nil, 1)
  nb:set_targ_count("RoboMiner", nil, 1)
  nb:record_building(P(0xCB, 0xE), "CommandCenter")
  nb:record_building(P(0xCA, 0xA), "CommonOreSmelter")
  nb:record_building(P(0xD1, 3), "Tokamak")
  nb:record_building(P(0xC4, 6), "CommonOreMine")
  for _, at in ipairs({ { 0xCB, 0x10 }, { 0xCD, 9 }, { 0xC6, 0xA } }) do
    nb:record_building(P(at[1], at[2]), "GuardPost", "Laser")
  end

  local w = g.west_rebuild
  w:record_building(P(0x91, 0x1D), "CommonOreMine")
  w:record_building(P(0x8F, 4), "CommonOreSmelter")
  w:record_building(P(0x89, 6), "GuardPost", "Laser")
  w:record_building(P(0x8E, 0x10), "GuardPost", "Laser")
  -- 0x11002A76: the south base's Command Center and Structure Factory, their kits, and what follows from them.
  w:record_building(P(0xA4, 0x2F), "CommandCenter")
  w:record_building(P(0xA9, 0x2F), "StructureFactory")
  if keep.west_sf then
    keep.west_sf:set_factory_cargo(2, "CommandCenter")                         -- the DLL's bays 1 and 2
    keep.west_sf:set_factory_cargo(3, "StructureFactory")
  end
  tile_event(EDEN, 0xA0, 0x31, start_south_mining)
  structure_event(EDEN, 0xA9, 0x2F, start_south_base)
  w:record_building(P(0x8A, 2), "Tokamak")
  w:record_building(P(0x9B, 5), "CommonStorage")
  for _, at in ipairs({ { 0x8E, 0x22 }, { 0x8F, 0x19 }, { 0x8A, 0x10 }, { 0x93, 6 }, { 0x9D, 5 } }) do
    w:record_building(P(at[1], at[2]), "GuardPost", "Laser")
  end
  w:record_building(P(0xA6, 3), "Agridome")
  w:record_building(P(0xA9, 3), "Residence")
  w:record_building(P(0xA9, 6), "CommandCenter")
  w:record_building(P(0xAF, 2), "StandardLab")
  w:record_building(P(0xB3, 3), "Agridome")
  w:record_building(P(0xA9, 8), "GuardPost", "Laser")
  w:record_building(P(0xAC, 3), "GuardPost", "Laser")
  w:record_building(P(0x9C, 2), "Residence")
  w:record_building(P(0xA4, 5), "GuardPost", "Laser")
  -- 0x11003320-0x11003453
  record_line(w, 0x91, 4, 0xA8, 4)
  record_line(w, 0x8F, 7, 0x89, 7)
  record_line(w, 0xAB, 3, 0xAE, 3)
  record_line(w, 0x8D, 8, 0x8D, 0x10)
  record_line(w, 0x8C, 0x10, 0x8B, 0x18)
  record_line(w, 0x8C, 0x18, 0x8F, 0x18)
  record_line(w, 0x8E, 0x19, 0x8E, 0x21)
  record_line(w, 0x8F, 7, 0x93, 6)
  record_line(w, 0xA2, 0, 0xA2, 3, true)
  record_line(w, 0xA2, 5, 0xA2, 9, true)
  w:take_unit(keep.convec_w)
  w:take_unit(keep.convec_sw)
  w:take_unit(keep.earthworker)
  if keep.west_sf then w:take_unit(keep.west_sf) end
  w:set_targ_count("ConVec", nil, 2)
  w:set_targ_count("RoboMiner", nil, 1)
  w:set_targ_count("Earthworker", nil, 1)
  west_factory()
end

-- Eden's south base. Mining starts once one of its units stands on the smelter's tile (0x11002B0B): the mine at
-- (0x98, 0x25), or the last one listed, with that unit as the smelter.
start_south_mining = function(unit)
  local mines = players[EDEN]:buildings("CommonOreMine")
  local mine = mines[#mines]
  for _, m in ipairs(mines) do
    if IX(m) == 0x98 and IY(m) == 0x25 then mine = m break end
  end
  g.south_mining = ai.mining_group(EDEN)                                        -- 0x1101C0C8
  if mine then g.south_mining:setup(mine, unit, RECT(0x9C, 0x2F, 0xA3, 0x34)) end
  g.south_mining:set_targ_count("CargoTruck", nil, 4)
  g.west_factory:record_veh_reinforce_group(g.south_mining, 5000)
end

local function south_factory(vf)                                                -- 0x11002E06
  keep.south_vf = vf
  g.west_factory:unrecord_veh_group(g.south_base)
  if g.south_mining then g.west_factory:unrecord_veh_group(g.south_mining) end
  g.west_factory:unrecord_veh_group(g.south_guard)
  g.south_factory:take_unit(vf)
  g.south_factory:record_veh_reinforce_group(g.south_base, 500)
  if g.south_mining then g.south_factory:record_veh_reinforce_group(g.south_mining, 5000) end
  g.south_factory:record_veh_reinforce_group(g.south_guard, 200)
  g.south_guard:set_targ_count("Lynx", "Laser", state.d * 2 + 4)
  g.south_guard:clear_guarded_rects()
  g.south_guard:set_rect(RECT(0x98, 0x26, 0xAB, 0x35))
end

-- The south Structure Factory is up (0x11002C1C): the ConVec closest to it, whoever owns it, builds the south base.
start_south_base = function(sf)
  local best, best_d
  for _, v in ipairs(game.units_in_rect({ 1, 1, 256, 64 })) do
    if v.type == "ConVec" then
      local dx, dy = v.x - sf.x, v.y - sf.y
      local dist = dx * dx + dy * dy
      if not best_d or dist < best_d then best, best_d = v, dist end
    end
  end
  if best then
    -- The DLL removes it from the west rebuild group unchecked; the game's ScGroup::RemoveUnit faults on a unit that
    -- isn't in the group (q03's remake crashed so, at 0x0042BDDB), so only a member is removed here.
    for _, v in ipairs(g.west_rebuild:units()) do
      if v == best then
        g.west_rebuild:remove_unit(best)
        break
      end
    end
    g.south_base:take_unit(best)
  end
  g.south_base:take_unit(sf)
  g.west_rebuild:record_building(P(0x98, 0x25), "CommonOreMine")
  local s = g.south_base
  s:record_building(P(0xA1, 0x2E), "Residence")
  s:record_building(P(0xA0, 0x31), "CommonOreSmelter")
  s:record_building(P(0xA4, 0x32), "Nursery")
  s:record_building(P(0xA0, 0x25), "Tokamak")
  s:record_building(P(0x9F, 0x35), "VehicleFactory")
  for _, at in ipairs({ { 0xAC, 0x2F }, { 0x9F, 0x2A }, { 0x9C, 0x30 }, { 0xA6, 0x32 } }) do
    s:record_building(P(at[1], at[2]), "GuardPost", "Laser")
  end
  s:set_targ_count("ConVec", nil, 1)
  g.west_factory:record_veh_reinforce_group(g.south_base, 500)
  g.west_factory:record_veh_reinforce_group(g.south_guard, 800)
  structure_event(EDEN, 0x9F, 0x35, south_factory)
end

-- West mining, once Eden has its second smelter (0x110027C5): the first smelter and mine west of x 0x93.
local function start_west_mining()
  local function west(type)
    local list, pick = players[EDEN]:buildings(type), nil
    for _, b in ipairs(list) do
      pick = b
      if IX(b) <= 0x93 then break end
    end
    return pick
  end
  keep.west_smelter = west("CommonOreSmelter")
  keep.west_mine = west("CommonOreMine")
  g.west_mining:setup(keep.west_mine, keep.west_smelter, RECT(0x8D, 5, 0x93, 9))
  g.west_mining:set_targ_count("CargoTruck", nil, state.d + 3)
end

-- Eden's mines and smelters (0x110025AF). With one smelter, the west mining waits for a second.
local function setup_mines()
  keep.west_mine = players[EDEN]:buildings("CommonOreMine")[1]                -- 0x1101C034
  if not keep.west_mine then keep.west_mine = make("CommonOreMine", EDEN, P(0x91, 0x1D), 0) end
  keep.east_mine = make("CommonOreMine", EDEN, P(0x111, 0x19), 0)             -- 0x1101C03C
  local smelters = players[EDEN]:buildings("CommonOreSmelter")
  keep.west_smelter, keep.east_smelter = smelters[1], smelters[2]              -- 0x1101C038, 0x1101C040
  local two = keep.east_smelter ~= nil
  if two then
    g.west_mining:setup(keep.west_mine, keep.west_smelter, RECT(0x8D, 5, 0x93, 9))
    g.west_mining:set_targ_count("CargoTruck", nil, state.d + 3)
  else
    keep.east_smelter = keep.west_smelter
    if keep.west_sf then keep.west_sf:set_factory_cargo(6, "CommonOreSmelter") end
    g.west_mining:disable()
    count_event(EDEN, "CommonOreSmelter", 2, 0, start_west_mining)
  end
  if keep.east_smelter then g.east_mining:setup(keep.east_mine, keep.east_smelter, RECT(0x117, 9, 0x11C, 0xE)) end
  g.east_mining:set_targ_count("CargoTruck", nil, 4)
  g.east_factory:record_veh_reinforce_group(g.east_mining, 400)
  for _, t in ipairs(players[EDEN]:units("CargoTruck")) do
    if IX(t) < 0xC9 then
      g.west_mining:take_unit(t)
      if not two then t:move(P(0x92, 7)) end
    else
      g.east_mining:take_unit(t)
    end
  end
end

-- ---------------------------------------------------------------------------------------------------------------
-- The objectives
-- ---------------------------------------------------------------------------------------------------------------

local function evac_rect() return { x = EVAC[1] - 6, y = EVAC[2] - 6, raw = true } end

local function escape(t)
  t.at, t.width, t.height, t.player = evac_rect(), 12, 12, HUMAN
  return trigger.escape(t)
end

-- "New mission objective..." (0x11001ADE). The DLL points it at the player's first Standard Lab.
local function new_objectives(what) game.message("New mission objective" .. what, 0x7A) end

local function operational_victory(type, text)
  return mission.victory(trigger.operational{ type = type, compare = ">", count = 0, player = HUMAN, one_shot = false },
                         text)
end

local function remove(key)
  if vc[key] then
    vc[key]:destroy()
    vc[key] = nil
  end
end

-- The research objectives (0x11001B31): after the Standard Lab (Easy), from the start (Normal), never (Hard).
local function research_objectives()
  remove("lab")
  vc[3305] = mission.victory(trigger.research{ tech = 3305, player = HUMAN, on = Research3305Done },
                             "Complete Research Training Programs")
  vc[3304] = mission.victory(trigger.research{ tech = 3304, player = HUMAN, on = Research3304Done },
                             "Complete Offspring Enhancement")
  vc[3401] = mission.victory(trigger.research{ tech = 3401, player = HUMAN, on = Research3401Done },
                             "Complete Cybernetic Teleoperation")
  if state.d == 0 then new_objectives("s") end
end

local pickup_check

-- The Vehicle Factory works (0x11002435): now the convoy's trucks and ConVecs.
local function vehicle_factory_works()
  remove("VehicleFactory")
  local trucks = state.food + state.metal
  count_event(HUMAN, "CargoTruck", trucks, 2, pickup_check)
  mission.victory(trigger.count{ type = "CargoTruck", compare = ">=", count = trucks, player = HUMAN },
                  "Have at least " .. trucks .. " cargo trucks")
  count_event(HUMAN, "ConVec", 4, 2, pickup_check)
  mission.victory(trigger.count{ type = "ConVec", compare = ">=", count = 4, player = HUMAN }, "Have at least 4 convecs")
  new_objectives("s")
end

-- A research topic done (0x11001C7F, 0x11001D41, 0x11001DEE), once: its objective gives way to a building's.
local function research_done(tech, type, works, what)
  if not state.research[tech] then return false end
  remove(tech)
  operational_event(HUMAN, type, works)
  vc[type] = operational_victory(type, "Build a " .. what)
  if state.d ~= 2 then new_objectives(": build a " .. what) end
  state.research[tech] = false
  return true
end

function Research3401Done()
  if research_done(3401, "VehicleFactory", vehicle_factory_works, "Vehicle Factory") then
    g.east_factory:record_veh_reinforce_group(g.east_guard, 200)
  end
end

function Research3304Done()
  research_done(3304, "Nursery", function() remove("Nursery") end, "Nursery")          -- 0x11002577
end

function Research3305Done()
  research_done(3305, "University", function() remove("University") end, "University") -- 0x11002593
end

-- ---------------------------------------------------------------------------------------------------------------
-- Plymouth's help for player 1
-- ---------------------------------------------------------------------------------------------------------------

-- Reinforcements (0x11004032): Microwave Lynx from the south-west corner, four on Easy, two otherwise.
local function reinforcements()
  local x = state.cc[1] + 6
  for _ = 1, state.d == 0 and 4 or 2 do
    local l = make("Lynx", HUMAN, P(0x21, 0x3C), 7, "Microwave")
    l:move(P(x, state.cc[2]))
    l:set_lights(true)
    x = x + 1
  end
  game.message("Reinforcements have arrived", 0xA2)
end

-- 0x110040B2: when player 1 has fewer than 9 Lynx (7 on Hard).
local function reinforcement_check()
  if players[HUMAN]:unit_count("Lynx") < (state.d == 2 and 7 or 9) then reinforcements() end
end

-- The convoy (0x1100289E): what the start lacks, from the south-west corner to beside the Command Center.
local function convoy()
  local x, y, any = state.cc[1], state.cc[2] + 2, false
  for _, type in ipairs({ "ConVec", "CargoTruck", "RoboSurveyor", "RoboMiner" }) do
    for _ = 1, state.short[type] do
      local v = make(type, HUMAN, P(0x21, 0x3C), 0)
      v:move(P(x, y))
      v:set_lights(true)
      x, any = x + 1, true
    end
    state.short[type] = -1
  end
  if any then game.message("A new convoy has arrived", 0xA2) end
end

-- ---------------------------------------------------------------------------------------------------------------
-- The pickup team (player 3)
-- ---------------------------------------------------------------------------------------------------------------

-- 0x11004684: player 1's convoy east of internal x `line` carries the food and metal, a ConVec with each of the
-- four kits, a RoboMiner and a RoboSurveyor.
local function convoy_ready(line)
  local food, metal, n = 0, 0, {}
  for _, v in ipairs(players[HUMAN]:units()) do
    if v.is_vehicle and IX(v) > line then
      if v.type == "CargoTruck" then
        if v.cargo == "Food" then food = food + v.cargo_amount
        elseif v.cargo == "CommonMetal" then metal = metal + v.cargo_amount end
      elseif v.type == "ConVec" then
        n[v.kit] = (n[v.kit] or 0) + 1
      elseif v.type == "RoboMiner" or v.type == "RoboSurveyor" then
        n[v.type] = (n[v.type] or 0) + 1
      end
    end
  end
  if food < state.food * 1000 or metal < state.metal * 1000 then return false end
  for _, k in ipairs({ "Tokamak", "CommandCenter", "StructureFactory", "CommonOreSmelter", "RoboMiner", "RoboSurveyor" }) do
    if not n[k] then return false end
  end
  return true
end

-- 0x1100443A: the scorched-earth team attacks the first of player 1's buildings it finds, or leaves.
local TARGETS = { "StandardLab", "University", "VehicleFactory", "CommandCenter", "StructureFactory", "Residence",
                  "Agridome" }
local function scorched_attack()
  local target
  for _, type in ipairs(TARGETS) do
    target = players[HUMAN]:buildings(type)[1]
    if target then break end
  end
  for _, l in ipairs(state.team) do
    if l.alive and l.type == "Lynx" then                         -- a reused id holds another unit (CRASH-LEADS 12)
      if target then l:attack(target) else g.leaving:take_unit(l) end
    end
  end
end

-- 0x1100451E: six RPG Lynx from the south-west corner, every time the check finds the convoy far enough east.
local function scorched_earth()
  local team = {}
  for i = 0, 5 do
    local l = make("Lynx", PICKUP, P(0x20 + i // 2, 0x3C + i % 2), 7, "RPG")
    l:set_lights(true)
    team[#team + 1] = l
  end
  state.team = team
  g.leaving = ai.fight_group(PICKUP)                                            -- 0x1101C0A4
  g.leaving:set_rect(RECT(0x20, state.cc[2] - 3, 0x22, state.cc[2] + 3))
  g.leaving:do_exit_map()
  repeating(100, 100, scorched_attack)
  scorched_attack()
end

-- The convoy check (0x110047A6, every 2000).
local function convoy_check()
  if not state.convoy_seen and convoy_ready(0x96) then
    state.convoy_seen = true
    g.south_guard:clear_guarded_rects()
    g.south_guard:set_rect(RECT(0xB2, 0x14, 0xBA, 0x1E))
    g.south_guard:do_attack_enemy()
  end
  if convoy_ready(0xB8) then scorched_earth() end
end

local top_up_a, top_up_d

-- 0x110040DD: C takes A's Lynx, and A gets new ones.
top_up_a = function()
  g.c:take_all_units(g.a)
  for i = state.d + 1, 0, -1 do
    g.a:take_unit(make("Lynx", PICKUP, P(0x11D - i // 2, 0x39 - i % 2), 4, "Microwave"))
  end
  g.c:set_combine_fire()
  loss_event(g.c, 3, top_up_a)
end

-- 0x11004170: more RPG Lynx for D.
top_up_d = function()
  for i = state.d + 2, 0, -1 do
    g.d:take_unit(make("Lynx", PICKUP, P(0x21 + i // 2, 0x3D - i % 2), 7, "RPG"))
  end
  loss_event(g.d, 3, top_up_d)
end

-- 0x11004410: B is gone, so C attacks.
local function c_attacks()
  g.c:clear_guarded_rects()
  g.c:set_follow_mode(0)
  g.c:do_attack_enemy()
  g.c:set_combine_fire()
end

-- 0x11004389: B has reached Eden's west base: three more RPG Lynx, and B guards player 1's Command Center.
local function b_reaches_west()
  for i = 2, 0, -1 do g.b:take_unit(make("Lynx", PICKUP, P(i + 0x20, 0x3C), 7, "RPG")) end
  g.b:clear_guarded_rects()
  local cx, cy = state.cc[1], state.cc[2]
  g.b:set_rect(RECT(cx - 10, cy - 6, cx + 10, cy + 6))
end

-- 0x11004311: B goes for Eden's Guard Posts west of x 0xB0, and Eden's east guard attacks.
local function b_attacks()
  g.b:set_attack_type("GuardPost")
  g.b:do_attack_enemy()
  g.b:clear_guarded_rects()
  g.b:set_rect(RECT(0x1F, 2, 0xB0, 0x28))
  g.east_guard:do_attack_enemy()
  area_event(PICKUP, 0x8A, 10, 6, 3, b_reaches_west)
end

-- 0x110042C2
local function b_moves_on()
  g.b:clear_guarded_rects()
  g.b:set_rect(RECT(0xB2, 0x14, 0xBA, 0x1E))
  once(2500, 2500, b_attacks)
end

-- 0x110041E5: B and C move out west, C following B.
local function move_out()
  local r = RECT(0xDB, 0x1E, 0xE2, 0x28)
  g.b:set_rect(r)
  g.c:set_rect(r)
  g.b:set_combine_fire()
  g.c:do_guard_group()
  g.c:set_target_group(g.b)
  g.c:set_follow_mode(1)
  g.east_guard:clear_targ_count()
  g.east_guard:set_targ_count("Lynx", "Laser", state.d * 2 + 2)
  once(4000, 4000, b_moves_on)
end

-- The pickup team arrives (0x11001E9B): four groups of player 3's Lynx.
local function pickup_team()
  local d = state.d
  local r = RECT(EVAC[1] - 6, EVAC[2] - 6, EVAC[1] + 6, EVAC[2] + 6)
  g.a = fight(PICKUP, r, true)                                                  -- 0x1101C094
  g.a:set_combine_fire()
  g.b = fight(PICKUP, r, true)                                                  -- 0x1101C098
  g.b:set_combine_fire()
  g.c = fight(PICKUP, r, true)                                                  -- 0x1101C09C
  g.d = fight(PICKUP, nil, true)                                                -- 0x1101C0A0
  g.d:set_attack_type("Lynx")
  g.d:set_combine_fire()
  g.d:do_attack_enemy()
  for i = d * 2 + 5, 0, -1 do
    g.b:take_unit(make("Lynx", PICKUP, P(0x11C - i // 2, 0x3A - i % 2), 5, "RPG"))
    g.c:take_unit(make("Lynx", PICKUP, P(0x11C - i // 2, 0x3C - i % 2), 6, "Microwave"))
  end
  for i = d + 1, 0, -1 do
    g.a:take_unit(make("Lynx", PICKUP, P(0x11D - i % 2, 0x37 - i // 2), 4, "Microwave"))
  end
  for i = d + 2, 0, -1 do
    g.d:take_unit(make("Lynx", PICKUP, P(0x21 + i // 2, 0x3D - i % 2), 7, "RPG"))
  end
  game.message("Your pickup-team has arrived. Get ready to evacuate", 0xA2)
  once(1000, 1000, move_out)
  loss_event(g.c, 3, top_up_a)
  loss_event(g.b, 3, top_up_d)
  loss_event(g.b, 1, c_attacks)
  repeating(2000, 2000, convoy_check)
end

-- 0x11004600, every 100: every vehicle of player 1 within 12 of the evacuation point lets the last objective count.
local function all_vehicles_check()
  local r = RECT(EVAC[1] - 12, EVAC[2] - 12, EVAC[1] + 12, EVAC[2] + 12)
  for _, v in ipairs(players[HUMAN]:units()) do
    if v.is_vehicle and not (v.x >= r[1] and v.x <= r[3] and v.y >= r[2] and v.y <= r[4]) then return end
  end
  state.all_vehicles:enable()
end

-- The pickup check (0x110021FA), called by both count events: the first call does nothing; then it waits for the
-- food, metal and vehicles the evacuation needs, checking again every 500.
pickup_check = function()
  state.pickup_calls = state.pickup_calls + 1
  if state.pickup_calls < 2 then return end
  local p = players[HUMAN]
  local food, metal, n = p.food, p.ore, {}
  for _, v in ipairs(p:units()) do
    if v.is_vehicle then
      if v.type == "CargoTruck" then
        if v.cargo == "Food" then food = food + v.cargo_amount
        elseif v.cargo == "CommonMetal" then metal = metal + v.cargo_amount end
      end
      n[v.type] = (n[v.type] or 0) + 1
    end
  end
  if food < state.food * 1000 or metal < state.metal * 1000 or (n.CargoTruck or 0) < state.food + state.metal
     or (n.ConVec or 0) < 4 or (n.RoboMiner or 0) < 1 or (n.RoboSurveyor or 0) < 1 then
    once(500, 500, pickup_check)
    return
  end
  game.create_marker(P(EVAC[1], EVAC[2]), "Circle")
  game.message("Get ready to evacuate", 0)
  -- A "Message from the Council" box in the DLL.
  game.message("We've sent a team to pick you up. Get ready to evacuate to (" .. EVAC[1] - 0x1F .. ","
               .. EVAC[2] + 1 .. ")!", 0)
  once(500, 500, pickup_team)
  repeating(100, 100, all_vehicles_check)
  state.all_vehicles = trigger.time{ time = 10, enabled = false }
  mission.victory(state.all_vehicles, "Evacuate ALL your vehicles to (" .. EVAC[1] - 0x1F .. "," .. EVAC[2] + 1 .. ")")
  reinforcement_check()
end

-- ---------------------------------------------------------------------------------------------------------------
-- Eden
-- ---------------------------------------------------------------------------------------------------------------

-- 0x11003F9D: staging's Lynx west of x 0x90 join the attack; a full east production goes to staging.
local function east_cycle()
  for _, v in ipairs(g.staging:units()) do
    if IX(v) < 0x90 then
      g.staging:remove_unit(v)
      g.attack:take_unit(v)
    end
  end
  if g.east_production:unit_count() == state.east_want then g.staging:take_all_units(g.east_production) end
end

-- East production starts (0x11003F33).
local function east_production()
  state.east_want = state.d * 2 + 2
  if keep.east_vf then g.east_factory:take_unit(keep.east_vf) end
  g.east_factory:record_veh_reinforce_group(g.east_production, 80)
  g.east_production:set_targ_count("Lynx", "Laser", state.east_want)
  local t = (6 - state.d) * 1000
  repeating(t, t, east_cycle)
end

-- 0x1100369E: east mining waits for the new base's mine and smelter.
local function east_mining_retry()
  local mine, smelter = first_at(EDEN, "CommonOreMine", 0xC4), first_at(EDEN, "CommonOreSmelter", 0xCA)
  if mine and smelter then
    g.east_mining:setup(mine, smelter, RECT(0xC6, 8, 0xCC, 0xC))
  else
    once(500, 500, east_mining_retry)
  end
end

-- East mining moves to the new base (0x110034B1), once none of its trucks carries anything.
local function east_mining_moves()
  local loaded = 0
  for _, t in ipairs(g.east_mining:units()) do
    if t.cargo ~= "Empty" then loaded = loaded + 1 end
  end
  g.east_mining:set_targ_count("CargoTruck", nil, 3)
  local mine, smelter = first_at(EDEN, "CommonOreMine", 0xC4), first_at(EDEN, "CommonOreSmelter", 0xCA)
  if loaded > 0 then
    g.east_mining:setup(mine or keep.west_mine, keep.east_smelter, RECT(0x8D, 5, 0x93, 9))
    once(500, 500, east_mining_moves)
    return
  end
  if mine and smelter then
    g.east_mining:setup(mine, smelter, RECT(0xC6, 8, 0xCC, 0xC))
  else
    once(500, 500, east_mining_retry)
  end
  g.east_factory:unrecord_veh_group(g.east_production)
end

-- The eruption (0x11004893, at 12500).
local function eruption()
  game.set_tile(P(0xFD, 9), 0x450)
  game.set_tile(P(0xFE, 9), 0x45B)
  game.set_tile(P(0xFD, 0xA), 0x466)
  game.set_tile(P(0xFE, 0xA), 0x471)
  game.create_eruption(P(0xFD, 0xA), 0x3C)
  g.west_factory:record_veh_reinforce_group(g.new_base, 5000)
  once(7000, 7000, east_mining_moves)
end

-- A raid check (0x11003BD0 south, 0x11003DD3 north), between ticks 6500 and 13000 of every 16500: the raid source's
-- Lynx past its line become raiders; until tick 20000 they go for the first of player 1's mines or buildings above
-- Guard Post in the scan rectangle; otherwise, when Eden reaches the area, those west of x 0x46 strike the
-- Command Center (0x11003B2B, 0x11003B5F).
local function raid_check(r)
  local t = game.tick() % 16500
  if not (t > 6500 and t < 13000) then return end
  for _, v in ipairs(r.source:units()) do
    if r.leaves(v) then
      r.source:remove_unit(v)
      r.raiders:take_unit(v)
    end
  end
  if game.tick() < 20001 then
    for _, v in ipairs(game.units_in_rect(r.scan)) do
      if v.owner == 0 and (v.type_id >= 0x18 or v.type_id == 0x15) then
        local x, y = IX(v), IY(v)
        r.raiders:clear_guarded_rects()
        r.raiders:set_rect(RECT(x - 3, y - 3, x + 3, y + 3))
        return
      end
    end
  end
  if r.raiders:unit_count() > 0 then
    area_event(EDEN, r.area[1], r.area[2], r.area[3], r.area[4], function()
      for _, v in ipairs(r.raiders:units()) do
        if IX(v) < 0x46 then
          r.raiders:remove_unit(v)
          r.strike:take_unit(v)
        end
      end
    end)
  end
end

local function raid_south()
  raid_check{ source = g.raid_source_south, raiders = g.raiders_south, strike = g.strike_south,
              leaves = function(v) return IY(v) > 0x22 end, scan = RECT(0x20, 0x20, 0x96, 0x3E),
              area = { 0x40, 0x1E, 5, 0x3E } }
end

local function raid_north()
  raid_check{ source = g.raid_source_north, raiders = g.raiders_north, strike = g.strike_north,
              leaves = function(v) return IX(v) < 0x87 end, scan = RECT(0x20, 0, 0x96, 0xD),
              area = { 0x40, 0, 5, 0x20 } }
end

-- The computer players' repairs (0x11006FBB, every 500). Each damaged structure (101 or more) of theirs gets the
-- closest idle, empty ConVec not on a Structure Factory's dock (0x11006D07), or a Repair Vehicle, within 8 tiles
-- (0x11006D88: the search stops once the distance's high word reaches 8).
local function on_factory_dock(v)
  local x = v.x + (players[v.owner + 1].is_eden and -1 or 2)
  for _, s in ipairs(game.units_in_rect({ x, v.y - 1, x, v.y - 1 })) do
    if s.x == x and s.y == v.y - 1 then return s.type == "StructureFactory" end
  end
  return false
end

local function closest_repairer(b, p)
  local best, best_d
  for _, v in ipairs(players[p]:units()) do
    if v.is_vehicle and v.alive and not v.busy then
      local ok
      if v.type == "ConVec" then
        ok = not on_factory_dock(v) and (v.kit == "None" or v.kit == "" or v.kit == nil)
      else
        ok = v.type == "RepairVehicle"
      end
      if ok then
        local dx, dy = v.x - b.x, v.y - b.y
        local dist = dx * dx + dy * dy
        if dist < 64 and (not best_d or dist < best_d) then best, best_d = v, dist end
      end
    end
  end
  return best
end

local function repair_one(b, p)
  local key = b.id * 7 + (p - 1)
  if b.max_hp - b.hp < 101 then
    repairers[key] = nil
    return
  end
  local c = b.command
  if not b.alive or c == 0x1E or c == 0x21 or c == 0x22 then return end
  local r = repairers[key]
  if r then
    if r.alive and r.command == 0x1C and r.type == "ConVec" then return end
    repairers[key] = nil
  end
  local v = closest_repairer(b, p)
  if v then
    v:repair(b)
    repairers[key] = v
  end
end

local function repairs()
  for p = 1, game.num_players() do
    if not players[p].is_human then
      local by_type = {}
      for _, b in ipairs(players[p]:buildings()) do
        local t = b.type_id
        if t >= 0x15 and t <= 0x3A and t ~= 0x17 then
          by_type[t] = by_type[t] or {}
          by_type[t][#by_type[t] + 1] = b
        end
      end
      for t = 0x15, 0x3A do
        for _, b in ipairs(by_type[t] or {}) do repair_one(b, p) end
      end
    end
  end
end

-- Disasters (0x1100486A, 0x11004818, 0x11004841): the y draw comes first.
local function meteor()
  local y = game.rand(0x3E)
  local x = game.rand(0xFF)
  game.create_meteor(P(x + 0x20, y + 1), 1)
end

local function quake_middle()
  local y = game.rand(0x1E)
  local x = game.rand(0x1E)
  game.create_earthquake(P(x + 0x40, y + 8), 1)
end

local function quake_anywhere()
  local y = game.rand(0x3E)
  local x = game.rand(0xFF)
  game.create_earthquake(P(x + 0x20, y + 1), 1)
end

local function nothing() end                                                    -- NoResponseToTrigger

-- Eden's extra Lynx by difficulty (0x11014BF0 on Normal and Hard, 0x11014C10 on Hard), lights on (0x110012EE).
local EXTRA_LYNX = {
  { { 0x8E, 0x1C, 5 }, { 0x91, 0x1B, 4 }, { 0x8F, 0x20, 2 } },
  { { 0x8D, 8, 5 }, { 0x91, 3, 2 }, { 0x95, 7, 1 } },
}
local function extra_lynx(t)
  for _, l in ipairs(EXTRA_LYNX[t]) do make("Lynx", EDEN, P(l[1], l[2]), l[3], "Laser"):set_lights(true) end
end

-- InitProc's part after the carry-over (0x11005597), in its order.
function setup_mission(difficulty)
  state.d = ({ Easy = 0, Normal = 1, Hard = 2 })[difficulty]
  local d = state.d
  players[HUMAN]:ally_with(PICKUP)
  players[PICKUP]:ally_with(HUMAN)
  after_carry_over()
  make_groups()
  make_patrols()
  setup_bases()
  repeating(500, 500, repairs)                                                  -- 0x11006CE5

  mission.victory(escape{ type = "ConVec", count = 1, cargo = 0x36, amount = 0 }, "Evacuate a Common Ore Smelter kit")
  mission.victory(escape{ type = "ConVec", count = 1, cargo = 0x2F, amount = 0 }, "Evacuate a Structure Factory kit")
  mission.victory(escape{ type = "ConVec", count = 1, cargo = 0x1C, amount = 0 }, "Evacuate a Command Center kit")
  mission.victory(escape{ type = "ConVec", count = 1, cargo = 0x3A, amount = 0 }, "Evacuate a Tokamak kit")
  mission.victory(escape{ type = "RoboMiner", count = 1 }, "Evacuate at least 1 Robo-Miner")
  mission.victory(escape{ type = "RoboSurveyor", count = 1 }, "Evacuate at least 1 Robo-Surveyor")

  if d == 0 then
    repeating(4000, 8000, meteor)
    once(20000, 30000, nothing)
    once(10000, 10000, reinforcements)
    once(2500, 2500, east_production)
    state.food, state.metal = 2, 4
    operational_event(HUMAN, "StandardLab", research_objectives)
    vc.lab = operational_victory("StandardLab", "Build a Standard Lab")
  elseif d == 1 then
    extra_lynx(1)
    repeating(2000, 4000, meteor)
    repeating(2500, 3500, quake_middle)
    once(15000, 20000, nothing)
    east_production()
    state.food, state.metal = 3, 5
    research_objectives()
  else
    extra_lynx(1)
    extra_lynx(2)
    repeating(1500, 2500, meteor)
    repeating(1000, 1500, quake_middle)
    once(10000, 12000, nothing)
    east_production()
    state.food, state.metal = 3, 6
    Research3401Done()
    Research3304Done()
    Research3305Done()
  end
  mission.victory(escape{ type = "CargoTruck", count = state.food, cargo = 1, amount = 1000 },
                  "Evacuate " .. state.food * 1000 .. " units of food")
  mission.victory(escape{ type = "CargoTruck", count = state.metal, cargo = 4, amount = 1000 },
                  "Evacuate " .. state.metal * 1000 .. " units of Common Metals")
  -- Not in the DLL (../../TODO.md): lost once there's no Command Center and no ConVec left to build one.
  mission.failure(trigger.set{
    trigger.count{ type = "CommandCenter", compare = "==", count = 0, player = HUMAN },
    trigger.count{ type = "ConVec", compare = "==", count = 0, player = HUMAN },
  })
  setup_mines()
  local check = d == 2 and 4000 or 2500
  repeating(check, check, reinforcement_check)
  once(2500, 2500, convoy)
  once(12500, 12500, eruption)
  repeating(2000, 5000, quake_anywhere)
  repeating(4000, 4000, raid_south)
  repeating(3200, 3200, raid_north)
  -- The carry-over for q03, once every victory condition still standing has been met.
  when(carry_won, function() save_carry_over("q02", state.d, "all the victory conditions met") end)
end

function on_tick() run_events() end

function on_init()
  game.message("Renegades v" .. VERSION, false)
  local difficulty = DIFFICULTIES[players[1].difficulty] and players[1].difficulty or "Normal"
  local d = DIFFICULTIES[difficulty]
  print("Difficulty: " .. difficulty)
  carry.data = load_carry_over("q01")
  make_things(d)
  make_in_order(d, BEACONS.rolled)
  for id, p in pairs(d.players) do make_player(players[id], p) end
  -- The setup's own map edits, after its units (and the draws it makes for them).
  game.initial_set_tile({ 222, 10 }, 1095)
  game.initial_set_tile({ 223, 10 }, 1107)
  game.initial_set_tile({ 222, 11 }, 1118)
  game.initial_set_tile({ 223, 11 }, 1129)
  game.set_cell_type({ 256, 64 }, 6)
  game.set_cell_type({ 255, 64 }, 6)
  game.set_cell_type({ 254, 64 }, 6)
  game.set_cell_type({ 253, 64 }, 6)
  game.set_cell_type({ 252, 64 }, 6)
  game.set_cell_type({ 251, 64 }, 6)
  game.set_cell_type({ 250, 64 }, 6)
  game.set_cell_type({ 249, 64 }, 6)
  game.set_cell_type({ 248, 64 }, 6)
  game.set_cell_type({ 247, 64 }, 6)
  game.set_cell_type({ 246, 64 }, 6)
  game.set_cell_type({ 245, 64 }, 6)
  game.set_cell_type({ 244, 64 }, 6)
  game.set_cell_type({ 243, 64 }, 6)
  game.set_cell_type({ 242, 64 }, 6)
  game.set_cell_type({ 241, 64 }, 6)
  game.set_cell_type({ 240, 64 }, 6)
  game.set_cell_type({ 239, 64 }, 6)
  game.set_cell_type({ 238, 64 }, 6)
  game.set_cell_type({ 237, 64 }, 6)
  game.set_cell_type({ 236, 64 }, 6)
  game.set_cell_type({ 235, 64 }, 6)
  game.set_cell_type({ 234, 64 }, 6)
  game.set_cell_type({ 233, 64 }, 6)
  game.set_cell_type({ 232, 64 }, 6)
  game.set_cell_type({ 231, 64 }, 6)
  game.set_cell_type({ 230, 64 }, 6)
  game.set_cell_type({ 229, 64 }, 6)
  game.set_cell_type({ 228, 64 }, 6)
  game.set_cell_type({ 227, 64 }, 6)
  game.set_cell_type({ 226, 64 }, 6)
  game.set_cell_type({ 225, 64 }, 6)
  game.set_cell_type({ 224, 64 }, 6)
  game.set_cell_type({ 223, 64 }, 6)
  game.set_cell_type({ 222, 64 }, 6)
  game.set_cell_type({ 221, 64 }, 6)
  game.set_cell_type({ 220, 64 }, 6)
  game.set_cell_type({ 219, 64 }, 6)
  game.set_cell_type({ 218, 64 }, 6)
  game.set_cell_type({ 217, 64 }, 6)
  game.set_cell_type({ 216, 64 }, 6)
  game.set_cell_type({ 215, 64 }, 6)
  game.set_cell_type({ 214, 64 }, 6)
  game.set_cell_type({ 213, 64 }, 6)
  game.set_cell_type({ 212, 64 }, 6)
  game.set_cell_type({ 211, 64 }, 6)
  game.set_cell_type({ 210, 64 }, 6)
  game.set_cell_type({ 209, 64 }, 6)
  game.set_cell_type({ 208, 64 }, 6)
  game.set_cell_type({ 207, 64 }, 6)
  game.set_cell_type({ 206, 64 }, 6)
  game.set_cell_type({ 205, 64 }, 6)
  game.set_cell_type({ 204, 64 }, 6)
  game.set_cell_type({ 203, 64 }, 6)
  game.set_cell_type({ 202, 64 }, 6)
  game.set_cell_type({ 201, 64 }, 6)
  game.set_cell_type({ 200, 64 }, 6)
  game.set_cell_type({ 199, 64 }, 6)
  game.set_cell_type({ 198, 64 }, 6)
  game.set_cell_type({ 197, 64 }, 6)
  game.set_cell_type({ 196, 64 }, 6)
  game.set_cell_type({ 195, 64 }, 6)
  game.set_cell_type({ 194, 64 }, 6)
  game.set_cell_type({ 193, 64 }, 6)
  game.set_cell_type({ 192, 64 }, 6)
  game.set_cell_type({ 191, 64 }, 6)
  game.set_cell_type({ 190, 64 }, 6)
  game.set_cell_type({ 189, 64 }, 6)
  game.set_cell_type({ 188, 64 }, 6)
  game.set_cell_type({ 187, 64 }, 6)
  game.set_cell_type({ 186, 64 }, 6)
  game.set_cell_type({ 185, 64 }, 6)
  game.set_cell_type({ 184, 64 }, 6)
  game.set_cell_type({ 183, 64 }, 6)
  game.set_cell_type({ 182, 64 }, 6)
  game.set_cell_type({ 181, 64 }, 6)
  game.set_cell_type({ 180, 64 }, 6)
  game.set_cell_type({ 179, 64 }, 6)
  game.set_cell_type({ 178, 64 }, 6)
  game.set_cell_type({ 177, 64 }, 6)
  game.set_cell_type({ 176, 64 }, 6)
  game.set_cell_type({ 175, 64 }, 6)
  game.set_cell_type({ 174, 64 }, 6)
  game.set_cell_type({ 173, 64 }, 6)
  game.set_cell_type({ 172, 64 }, 6)
  game.set_cell_type({ 171, 64 }, 6)
  game.set_cell_type({ 170, 64 }, 6)
  game.set_cell_type({ 169, 64 }, 6)
  game.set_cell_type({ 168, 64 }, 6)
  game.set_cell_type({ 167, 64 }, 6)
  game.set_cell_type({ 166, 64 }, 6)
  game.set_cell_type({ 165, 64 }, 6)
  game.set_cell_type({ 164, 64 }, 6)
  game.set_cell_type({ 163, 64 }, 6)
  game.set_cell_type({ 162, 64 }, 6)
  game.set_cell_type({ 161, 64 }, 6)
  game.set_cell_type({ 160, 64 }, 6)
  game.set_cell_type({ 159, 64 }, 6)
  game.set_cell_type({ 158, 64 }, 6)
  game.set_cell_type({ 157, 64 }, 6)
  game.set_cell_type({ 156, 64 }, 6)
  game.set_cell_type({ 155, 64 }, 6)
  game.set_cell_type({ 154, 64 }, 6)
  game.set_cell_type({ 153, 64 }, 6)
  game.set_cell_type({ 152, 64 }, 6)
  game.set_cell_type({ 151, 64 }, 6)
  game.set_cell_type({ 150, 64 }, 6)
  game.set_cell_type({ 149, 64 }, 6)
  game.set_cell_type({ 148, 64 }, 6)
  game.set_cell_type({ 147, 64 }, 6)
  game.set_cell_type({ 146, 64 }, 6)
  game.set_cell_type({ 145, 64 }, 6)
  game.set_cell_type({ 144, 64 }, 6)
  game.set_cell_type({ 143, 64 }, 6)
  game.set_cell_type({ 142, 64 }, 6)
  game.set_cell_type({ 141, 64 }, 6)
  game.set_cell_type({ 140, 64 }, 6)
  game.set_cell_type({ 139, 64 }, 6)
  game.set_cell_type({ 138, 64 }, 6)
  game.set_cell_type({ 137, 64 }, 6)
  game.set_cell_type({ 136, 64 }, 6)
  game.set_cell_type({ 135, 64 }, 6)
  game.set_cell_type({ 134, 64 }, 6)
  game.set_cell_type({ 133, 64 }, 6)
  game.set_cell_type({ 132, 64 }, 6)
  game.set_cell_type({ 131, 64 }, 6)
  game.set_cell_type({ 130, 64 }, 6)
  game.set_cell_type({ 129, 64 }, 6)
  game.set_cell_type({ 128, 64 }, 6)
  game.set_cell_type({ 127, 64 }, 6)
  game.set_cell_type({ 126, 64 }, 6)
  game.set_cell_type({ 125, 64 }, 6)
  game.set_cell_type({ 124, 64 }, 6)
  game.set_cell_type({ 123, 64 }, 6)
  game.set_cell_type({ 122, 64 }, 6)
  game.set_cell_type({ 121, 64 }, 6)
  game.set_cell_type({ 120, 64 }, 6)
  game.set_cell_type({ 119, 64 }, 6)
  game.set_cell_type({ 118, 64 }, 6)
  game.set_cell_type({ 117, 64 }, 6)
  game.set_cell_type({ 116, 64 }, 6)
  game.set_cell_type({ 115, 64 }, 6)
  game.set_cell_type({ 114, 64 }, 6)
  game.set_cell_type({ 113, 64 }, 6)
  game.set_cell_type({ 112, 64 }, 6)
  game.set_cell_type({ 111, 64 }, 6)
  game.set_cell_type({ 110, 64 }, 6)
  game.set_cell_type({ 109, 64 }, 6)
  game.set_cell_type({ 108, 64 }, 6)
  game.set_cell_type({ 107, 64 }, 6)
  game.set_cell_type({ 106, 64 }, 6)
  game.set_cell_type({ 105, 64 }, 6)
  game.set_cell_type({ 104, 64 }, 6)
  game.set_cell_type({ 103, 64 }, 6)
  game.set_cell_type({ 102, 64 }, 6)
  game.set_cell_type({ 101, 64 }, 6)
  game.set_cell_type({ 100, 64 }, 6)
  game.set_cell_type({ 99, 64 }, 6)
  game.set_cell_type({ 98, 64 }, 6)
  game.set_cell_type({ 97, 64 }, 6)
  game.set_cell_type({ 96, 64 }, 6)
  game.set_cell_type({ 95, 64 }, 6)
  game.set_cell_type({ 94, 64 }, 6)
  game.set_cell_type({ 93, 64 }, 6)
  game.set_cell_type({ 92, 64 }, 6)
  game.set_cell_type({ 91, 64 }, 6)
  game.set_cell_type({ 90, 64 }, 6)
  game.set_cell_type({ 89, 64 }, 6)
  game.set_cell_type({ 88, 64 }, 6)
  game.set_cell_type({ 87, 64 }, 6)
  game.set_cell_type({ 86, 64 }, 6)
  game.set_cell_type({ 85, 64 }, 6)
  game.set_cell_type({ 84, 64 }, 6)
  game.set_cell_type({ 83, 64 }, 6)
  game.set_cell_type({ 82, 64 }, 6)
  game.set_cell_type({ 81, 64 }, 6)
  game.set_cell_type({ 80, 64 }, 6)
  game.set_cell_type({ 79, 64 }, 6)
  game.set_cell_type({ 78, 64 }, 6)
  game.set_cell_type({ 77, 64 }, 6)
  game.set_cell_type({ 76, 64 }, 6)
  game.set_cell_type({ 75, 64 }, 6)
  game.set_cell_type({ 74, 64 }, 6)
  game.set_cell_type({ 73, 64 }, 6)
  game.set_cell_type({ 72, 64 }, 6)
  game.set_cell_type({ 71, 64 }, 6)
  game.set_cell_type({ 70, 64 }, 6)
  game.set_cell_type({ 69, 64 }, 6)
  game.set_cell_type({ 68, 64 }, 6)
  game.set_cell_type({ 67, 64 }, 6)
  game.set_cell_type({ 66, 64 }, 6)
  game.set_cell_type({ 65, 64 }, 6)
  game.set_cell_type({ 64, 64 }, 6)
  game.set_cell_type({ 63, 64 }, 6)
  game.set_cell_type({ 62, 64 }, 6)
  game.set_cell_type({ 61, 64 }, 6)
  game.set_cell_type({ 60, 64 }, 6)
  game.set_cell_type({ 59, 64 }, 6)
  game.set_cell_type({ 58, 64 }, 6)
  game.set_cell_type({ 57, 64 }, 6)
  game.set_cell_type({ 56, 64 }, 6)
  game.set_cell_type({ 55, 64 }, 6)
  game.set_cell_type({ 54, 64 }, 6)
  game.set_cell_type({ 53, 64 }, 6)
  game.set_cell_type({ 52, 64 }, 6)
  game.set_cell_type({ 51, 64 }, 6)
  game.set_cell_type({ 50, 64 }, 6)
  game.set_cell_type({ 49, 64 }, 6)
  game.set_cell_type({ 48, 64 }, 6)
  game.set_cell_type({ 47, 64 }, 6)
  game.set_cell_type({ 46, 64 }, 6)
  game.set_cell_type({ 45, 64 }, 6)
  game.set_cell_type({ 44, 64 }, 6)
  game.set_cell_type({ 43, 64 }, 6)
  game.set_cell_type({ 42, 64 }, 6)
  game.set_cell_type({ 41, 64 }, 6)
  game.set_cell_type({ 40, 64 }, 6)
  game.set_cell_type({ 39, 64 }, 6)
  game.set_cell_type({ 38, 64 }, 6)
  game.set_cell_type({ 37, 64 }, 6)
  game.set_cell_type({ 36, 64 }, 6)
  game.set_cell_type({ 35, 64 }, 6)
  game.set_cell_type({ 34, 64 }, 6)
  game.set_cell_type({ 33, 64 }, 6)
  game.set_cell_type({ 32, 64 }, 6)
  game.set_cell_type({ 31, 64 }, 6)
  game.set_cell_type({ 30, 64 }, 6)
  game.set_cell_type({ 29, 64 }, 6)
  game.set_cell_type({ 28, 64 }, 6)
  game.set_cell_type({ 27, 64 }, 6)
  game.set_cell_type({ 26, 64 }, 6)
  game.set_cell_type({ 25, 64 }, 6)
  game.set_cell_type({ 24, 64 }, 6)
  game.set_cell_type({ 23, 64 }, 6)
  game.set_cell_type({ 22, 64 }, 6)
  game.set_cell_type({ 21, 64 }, 6)
  game.set_cell_type({ 20, 64 }, 6)
  game.set_cell_type({ 19, 64 }, 6)
  game.set_cell_type({ 18, 64 }, 6)
  game.set_cell_type({ 17, 64 }, 6)
  game.set_cell_type({ 16, 64 }, 6)
  game.set_cell_type({ 15, 64 }, 6)
  game.set_cell_type({ 14, 64 }, 6)
  game.set_cell_type({ 13, 64 }, 6)
  game.set_cell_type({ 12, 64 }, 6)
  game.set_cell_type({ 11, 64 }, 6)
  game.set_cell_type({ 10, 64 }, 6)
  game.set_cell_type({ 9, 64 }, 6)
  game.set_cell_type({ 8, 64 }, 6)
  game.set_cell_type({ 7, 64 }, 6)
  game.set_cell_type({ 6, 64 }, 6)
  game.set_cell_type({ 5, 64 }, 6)
  game.set_cell_type({ 4, 64 }, 6)
  game.set_cell_type({ 3, 64 }, 6)
  game.set_cell_type({ 2, 64 }, 6)
  game.set_cell_type({ 1, 64 }, 6)
  game.set_cell_type({ 0, 64 }, 6)
  -- The stand-in carry-over's dozed cells (Q01.mis), when there's no q01.carry.
  if not carry.data then
    game.set_cell_type({ 109, 3 }, 21)
    game.set_tile({ 109, 3 }, 409)
    game.set_cell_type({ 110, 3 }, 21)
    game.set_tile({ 110, 3 }, 409)
    game.set_cell_type({ 111, 3 }, 21)
    game.set_tile({ 111, 3 }, 409)
    game.set_cell_type({ 112, 3 }, 21)
    game.set_tile({ 112, 3 }, 409)
    game.set_cell_type({ 113, 3 }, 21)
    game.set_tile({ 113, 3 }, 409)
    game.set_cell_type({ 114, 3 }, 21)
    game.set_tile({ 114, 3 }, 409)
    game.set_cell_type({ 115, 3 }, 21)
    game.set_tile({ 115, 3 }, 409)
    game.set_cell_type({ 116, 3 }, 21)
    game.set_tile({ 116, 3 }, 409)
    game.set_cell_type({ 117, 3 }, 21)
    game.set_tile({ 117, 3 }, 409)
    game.set_cell_type({ 118, 3 }, 21)
    game.set_tile({ 118, 3 }, 409)
    game.set_cell_type({ 119, 3 }, 21)
    game.set_tile({ 119, 3 }, 409)
    game.set_cell_type({ 120, 3 }, 21)
    game.set_tile({ 120, 3 }, 409)
    game.set_cell_type({ 121, 3 }, 21)
    game.set_tile({ 121, 3 }, 409)
    game.set_cell_type({ 122, 3 }, 21)
    game.set_tile({ 122, 3 }, 409)
    game.set_cell_type({ 123, 3 }, 21)
    game.set_tile({ 123, 3 }, 409)
    game.set_cell_type({ 109, 4 }, 21)
    game.set_tile({ 109, 4 }, 409)
    game.set_cell_type({ 114, 4 }, 21)
    game.set_tile({ 114, 4 }, 409)
    game.set_cell_type({ 118, 4 }, 21)
    game.set_tile({ 118, 4 }, 409)
    game.set_cell_type({ 123, 4 }, 21)
    game.set_tile({ 123, 4 }, 409)
    game.set_cell_type({ 109, 5 }, 21)
    game.set_tile({ 109, 5 }, 409)
    game.set_cell_type({ 109, 6 }, 21)
    game.set_tile({ 109, 6 }, 409)
    game.set_cell_type({ 114, 6 }, 21)
    game.set_tile({ 114, 6 }, 409)
    game.set_cell_type({ 115, 6 }, 21)
    game.set_tile({ 115, 6 }, 409)
    game.set_cell_type({ 117, 6 }, 21)
    game.set_tile({ 117, 6 }, 409)
    game.set_cell_type({ 118, 6 }, 21)
    game.set_tile({ 118, 6 }, 409)
    game.set_cell_type({ 123, 6 }, 21)
    game.set_tile({ 123, 6 }, 409)
    game.set_cell_type({ 109, 7 }, 21)
    game.set_tile({ 109, 7 }, 409)
    game.set_cell_type({ 110, 7 }, 21)
    game.set_tile({ 110, 7 }, 409)
    game.set_cell_type({ 111, 7 }, 21)
    game.set_tile({ 111, 7 }, 409)
    game.set_cell_type({ 113, 7 }, 21)
    game.set_tile({ 113, 7 }, 409)
    game.set_cell_type({ 114, 7 }, 21)
    game.set_tile({ 114, 7 }, 409)
    game.set_cell_type({ 118, 7 }, 21)
    game.set_tile({ 118, 7 }, 409)
    game.set_cell_type({ 119, 7 }, 21)
    game.set_tile({ 119, 7 }, 409)
    game.set_cell_type({ 120, 7 }, 21)
    game.set_tile({ 120, 7 }, 409)
    game.set_cell_type({ 122, 7 }, 21)
    game.set_tile({ 122, 7 }, 409)
    game.set_cell_type({ 123, 7 }, 21)
    game.set_tile({ 123, 7 }, 409)
    game.set_cell_type({ 14, 22 }, 21)
    game.set_tile({ 14, 22 }, 409)
    game.set_cell_type({ 15, 22 }, 21)
    game.set_tile({ 15, 22 }, 409)
    game.set_cell_type({ 16, 22 }, 21)
    game.set_tile({ 16, 22 }, 409)
    game.set_cell_type({ 17, 22 }, 21)
    game.set_tile({ 17, 22 }, 409)
    game.set_cell_type({ 18, 22 }, 21)
    game.set_tile({ 18, 22 }, 409)
    game.set_cell_type({ 19, 22 }, 21)
    game.set_tile({ 19, 22 }, 409)
    game.set_cell_type({ 20, 22 }, 21)
    game.set_tile({ 20, 22 }, 409)
    game.set_cell_type({ 21, 22 }, 21)
    game.set_tile({ 21, 22 }, 409)
    game.set_cell_type({ 22, 22 }, 21)
    game.set_tile({ 22, 22 }, 409)
    game.set_cell_type({ 23, 22 }, 21)
    game.set_tile({ 23, 22 }, 409)
    game.set_cell_type({ 24, 22 }, 21)
    game.set_tile({ 24, 22 }, 409)
    game.set_cell_type({ 14, 23 }, 21)
    game.set_tile({ 14, 23 }, 409)
    game.set_cell_type({ 19, 23 }, 21)
    game.set_tile({ 19, 23 }, 409)
    game.set_cell_type({ 24, 23 }, 21)
    game.set_tile({ 24, 23 }, 409)
    game.set_cell_type({ 14, 24 }, 21)
    game.set_tile({ 14, 24 }, 409)
    game.set_cell_type({ 14, 25 }, 21)
    game.set_tile({ 14, 25 }, 409)
    game.set_cell_type({ 19, 25 }, 21)
    game.set_tile({ 19, 25 }, 409)
    game.set_cell_type({ 24, 25 }, 21)
    game.set_tile({ 24, 25 }, 409)
    game.set_cell_type({ 14, 26 }, 21)
    game.set_tile({ 14, 26 }, 409)
    game.set_cell_type({ 15, 26 }, 21)
    game.set_tile({ 15, 26 }, 409)
    game.set_cell_type({ 16, 26 }, 21)
    game.set_tile({ 16, 26 }, 409)
    game.set_cell_type({ 18, 26 }, 21)
    game.set_tile({ 18, 26 }, 409)
    game.set_cell_type({ 19, 26 }, 21)
    game.set_tile({ 19, 26 }, 409)
    game.set_cell_type({ 20, 26 }, 21)
    game.set_tile({ 20, 26 }, 409)
    game.set_cell_type({ 21, 26 }, 21)
    game.set_tile({ 21, 26 }, 409)
    game.set_cell_type({ 23, 26 }, 21)
    game.set_tile({ 23, 26 }, 409)
    game.set_cell_type({ 24, 26 }, 21)
    game.set_tile({ 24, 26 }, 409)
    game.set_cell_type({ 15, 27 }, 21)
    game.set_tile({ 15, 27 }, 409)
    game.set_cell_type({ 19, 27 }, 21)
    game.set_tile({ 19, 27 }, 409)
    game.set_cell_type({ 15, 28 }, 21)
    game.set_tile({ 15, 28 }, 409)
    game.set_cell_type({ 15, 29 }, 21)
    game.set_tile({ 15, 29 }, 409)
    game.set_cell_type({ 16, 29 }, 21)
    game.set_tile({ 16, 29 }, 409)
    game.set_cell_type({ 18, 29 }, 21)
    game.set_tile({ 18, 29 }, 409)
    game.set_cell_type({ 19, 29 }, 21)
    game.set_tile({ 19, 29 }, 409)
    game.set_cell_type({ 112, 29 }, 21)
    game.set_tile({ 112, 29 }, 409)
    game.set_cell_type({ 113, 29 }, 21)
    game.set_tile({ 113, 29 }, 409)
    game.set_cell_type({ 114, 29 }, 21)
    game.set_tile({ 114, 29 }, 409)
    game.set_cell_type({ 115, 29 }, 21)
    game.set_tile({ 115, 29 }, 409)
    game.set_cell_type({ 112, 30 }, 21)
    game.set_tile({ 112, 30 }, 409)
    game.set_cell_type({ 115, 30 }, 21)
    game.set_tile({ 115, 30 }, 409)
    game.set_cell_type({ 112, 31 }, 21)
    game.set_tile({ 112, 31 }, 409)
    game.set_cell_type({ 113, 31 }, 21)
    game.set_tile({ 113, 31 }, 409)
    game.set_cell_type({ 114, 31 }, 21)
    game.set_tile({ 114, 31 }, 409)
    game.set_cell_type({ 115, 31 }, 21)
    game.set_tile({ 115, 31 }, 409)
    game.set_cell_type({ 10, 44 }, 21)
    game.set_tile({ 10, 44 }, 1670)
    game.set_cell_type({ 11, 44 }, 21)
    game.set_tile({ 11, 44 }, 1670)
    game.set_cell_type({ 12, 44 }, 21)
    game.set_tile({ 12, 44 }, 1670)
    game.set_cell_type({ 13, 44 }, 21)
    game.set_tile({ 13, 44 }, 1670)
    game.set_cell_type({ 10, 45 }, 21)
    game.set_tile({ 10, 45 }, 1670)
    game.set_cell_type({ 13, 45 }, 21)
    game.set_tile({ 13, 45 }, 1670)
    game.set_cell_type({ 10, 46 }, 21)
    game.set_tile({ 10, 46 }, 1670)
    game.set_cell_type({ 13, 46 }, 21)
    game.set_tile({ 13, 46 }, 1670)
    game.set_cell_type({ 10, 47 }, 21)
    game.set_tile({ 10, 47 }, 1670)
    game.set_cell_type({ 11, 47 }, 21)
    game.set_tile({ 11, 47 }, 1670)
    game.set_cell_type({ 12, 47 }, 21)
    game.set_tile({ 12, 47 }, 1670)
    game.set_cell_type({ 13, 47 }, 21)
    game.set_tile({ 13, 47 }, 1670)
    game.set_cell_type({ 125, 59 }, 21)
    game.set_tile({ 125, 59 }, 409)
    game.set_cell_type({ 126, 59 }, 21)
    game.set_tile({ 126, 59 }, 409)
    game.set_cell_type({ 127, 59 }, 21)
    game.set_tile({ 127, 59 }, 409)
    game.set_cell_type({ 128, 59 }, 21)
    game.set_tile({ 128, 59 }, 409)
    game.set_cell_type({ 125, 60 }, 21)
    game.set_tile({ 125, 60 }, 409)
    game.set_cell_type({ 128, 60 }, 21)
    game.set_tile({ 128, 60 }, 409)
    game.set_cell_type({ 125, 61 }, 21)
    game.set_tile({ 125, 61 }, 409)
    game.set_cell_type({ 128, 61 }, 21)
    game.set_tile({ 128, 61 }, 409)
    game.set_cell_type({ 125, 62 }, 21)
    game.set_tile({ 125, 62 }, 409)
    game.set_cell_type({ 126, 62 }, 21)
    game.set_tile({ 126, 62 }, 409)
    game.set_cell_type({ 127, 62 }, 21)
    game.set_tile({ 127, 62 }, 409)
    game.set_cell_type({ 128, 62 }, 21)
    game.set_tile({ 128, 62 }, 409)
  end
  game.set_cell_type({ 195, 22 }, 6)
  game.set_daylight_everywhere(false)
  game.set_daylight_moves(true)
  game.free_morale()
  for _, r in ipairs(LAVA_POSSIBLE) do game.set_lava_possible(r) end

  -- The difficulty check (0x11004A20): q01 played at another difficulty sets the mission's own (not the player's).
  -- The DLL says it in a message box; OP2Lua has none, so it's a message.
  local NAMES = { [0] = "Easy", "Normal", "Hard" }
  if carry.difficulty and NAMES[carry.difficulty] and NAMES[carry.difficulty] ~= difficulty then
    game.message("You're cheating ! Difficulty reset to " .. ({ [0] = "easy", "medium", "hard" })[carry.difficulty] .. " :-)")
    difficulty = NAMES[carry.difficulty]
  end
  setup_mission(difficulty)
end

-- Where this differs from q02.dll, on purpose or for want of an exact match (../../findings/decompile/q02.md):
-- - Measured against the DLL in the game (q02.md): every unit matches at tick 1, and Plymouth's convoy and
--   reinforcements come on the same ticks at every difficulty. Eden's own AI drifts from tick 100-500 (a factory a
--   little early, trucks a tile apart); why is open.
-- - The start is rebuilt from q01.carry, which q01's remake writes when it's won, in place of Q01.mis. Without
--   one, it's the stand-in carry-over (q01 won at tick 2900 in the harness), baked in by op2dll, with InitMap's
--   moves of far-off vehicles already done. The "You're cheating!" check is a message, not a message box.
--   InitMap's distance is taken as 2 x tiles² (squared pixels >> 9), which fits the stand-in's one moved truck.
-- - A failure condition the DLL lacks: lost with no Command Center and no ConVec. Capping the scorched-earth team is
--   in ../../TODO.md.
-- - Messages go to the message list: the DLL points "New mission objective..." at the first Standard Lab, and shows
--   the Council's "We've sent a team to pick you up" in a message box.
-- - "Common Metals" in the metal objective; the DLL says "Commom".
-- - "Closest" (the south base's ConVec, a repairer) is by straight-line tile distance; the game's ClosestEnumerator
--   measures its own way, and its ties may fall differently.
-- - East production's "full" test uses the group's unit count; the DLL calls ScGroup::UnitCount(0).
-- - The tile events look for a unit whose tile is that tile; the DLL uses the game's LocationEnumerator.
-- - The south base takes the closest ConVec out of the west rebuild group only when it's in it: the DLL doesn't check,
--   and the game faults on removing a unit that isn't (findings/CRASH-LEADS.md 11).
