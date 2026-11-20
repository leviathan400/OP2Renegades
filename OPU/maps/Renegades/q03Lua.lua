-- q03Lua.lua  -  Outpost : Renegades - Consequences (Lua) v1.2.8
-- Converted from q03.dll. With q03Lua.placement.lua (what every difficulty makes alike),
-- this makes the colony's start: what changes with the difficulty, and the beacons the setup rolls.
-- The objectives, the computer players' AI and the mission's events (below the converted part) are written by hand.
-- Games run: Easy 151, Normal 151, Hard 151.
-- Coordinates are the in-game status-bar ones (map file tile + 1); a kit's are relative to its start.

-- The release this mission belongs to (as in the header), posted in the message log at the start, without a sound.
local VERSION = "1.2.8"

-- Beacons rolled each game, alike at every difficulty: `count` of the `spots` (no two alike) with the
-- `kinds` by pick, anywhere in an `area` (x1, y1, x2, y2), or a tile's kind picked from `ways`.
local BEACONS = {
  rolled = {
  },
}

-- By difficulty (players[1].difficulty), for each player: colonists, stores, research, Structure Factory
-- kits by bay, the camera, units on fixed tiles, units each on a tile rolled in its `area`, and a kit of
-- units on a start rolled from `starts` or anywhere in `start_area`; then the tubes, walls and beacons
-- only this difficulty makes.
local DIFFICULTIES = {
  Easy = {
    players = {
      [1] = {
        workers = 40, scientists = 15, kids = 0, food = 2100, ore = 0,
        research = { 2106, 3607 },
        tech_level = 2,
        view = { 125, 125 },
        units = {
          { type = "Lynx", weapon = "Microwave", direction = "East", at = { 126, 125 } },
          { type = "Lynx", weapon = "Microwave", direction = "East", at = { 126, 126 } },
          { type = "Lynx", weapon = "Microwave", direction = "East", at = { 125, 125 } },
          { type = "Lynx", weapon = "Microwave", direction = "East", at = { 125, 126 } },
          { type = "RoboMiner", direction = "East", at = { 124, 125 } },
          { type = "RoboDozer", direction = "East", at = { 124, 126 } },
          { type = "RoboMiner", direction = "East", at = { 123, 125 } },
          { type = "RoboSurveyor", direction = "East", at = { 123, 126 } },
        },
      },
      [2] = {
        ore = 10000,
        research = {  },
        tech_level = 3,
        units = {
          { type = "GuardPost", weapon = "Laser", at = { 22, 22 } },
          { type = "GuardPost", weapon = "Laser", at = { 15, 24 } },
          { type = "GuardPost", weapon = "Laser", at = { 23, 15 } },
          { type = "GuardPost", weapon = "Laser", at = { 7, 14 } },
          { type = "GuardPost", weapon = "Laser", at = { 14, 11 } },
          { type = "StandardLab", at = { 17, 12 } },
        },
      },
      [3] = {
        research = { 12898 },
        tech_level = 3,
        units = {
        },
      },
    },
    walls = {
    },
    beacons = {
      { type = "MiningBeacon", ore = "Common", yield = "Bar1", variant = "High", at = { 89, 65 } },
      { type = "MiningBeacon", ore = "Common", yield = "Bar1", variant = "Mid", at = { 108, 48 } },
    },
  },
  Normal = {
    players = {
      [1] = {
        workers = 35, scientists = 12, kids = 0, food = 1600, ore = 0,
        research = { 2106, 3607 },
        tech_level = 2,
        view = { 125, 125 },
        units = {
          { type = "Lynx", weapon = "Microwave", direction = "East", at = { 126, 125 } },
          { type = "Lynx", weapon = "Microwave", direction = "East", at = { 126, 126 } },
          { type = "RoboDozer", direction = "East", at = { 125, 125 } },
          { type = "RoboMiner", direction = "East", at = { 125, 126 } },
          { type = "RoboMiner", direction = "East", at = { 124, 125 } },
          { type = "RoboSurveyor", direction = "East", at = { 124, 126 } },
        },
      },
      [2] = {
        ore = 10000,
        research = {  },
        tech_level = 3,
        units = {
        },
      },
      [3] = {
        research = { 12898 },
        tech_level = 3,
        units = {
        },
      },
    },
    walls = {
    },
    beacons = {
      { type = "MiningBeacon", ore = "Common", yield = "Bar1", variant = "Low", at = { 89, 65 } },
      { type = "MiningBeacon", ore = "Common", yield = "Bar1", variant = "High", at = { 108, 48 } },
    },
  },
  Hard = {
    players = {
      [1] = {
        workers = 30, scientists = 10, kids = 0, food = 1300, ore = 0,
        research = { 2106, 3607 },
        tech_level = 2,
        view = { 125, 125 },
        units = {
          { type = "RoboDozer", direction = "East", at = { 126, 125 } },
          { type = "RoboMiner", direction = "East", at = { 126, 126 } },
          { type = "RoboSurveyor", direction = "East", at = { 125, 125 } },
        },
      },
      [2] = {
        ore = 10000,
        research = {  },
        tech_level = 3,
        units = {
        },
      },
      [3] = {
        research = { 12898 },
        tech_level = 3,
        units = {
        },
      },
    },
    walls = {
    },
    beacons = {
      { type = "MiningBeacon", ore = "Common", yield = "Bar1", variant = "Low", at = { 89, 65 } },
      { type = "MiningBeacon", ore = "Common", yield = "Bar1", variant = "High", at = { 108, 48 } },
    },
  },
}

-- Where lava may flow (x1, y1, x2, y2).
local LAVA_POSSIBLE = {
  { 96, 21, 99, 21 },
  { 95, 22, 99, 22 },
  { 91, 23, 99, 23 },
  { 90, 24, 98, 25 },
  { 91, 26, 97, 26 },
  { 92, 27, 97, 27 },
  { 91, 28, 96, 28 },
  { 91, 29, 95, 29 },
  { 92, 30, 95, 30 },
  { 92, 31, 97, 31 },
  { 89, 32, 97, 32 },
  { 88, 33, 95, 34 },
  { 87, 35, 95, 35 },
  { 87, 36, 94, 37 },
  { 88, 38, 95, 38 },
  { 71, 39, 74, 39 },
  { 77, 39, 82, 39 },
  { 87, 39, 95, 39 },
  { 71, 40, 82, 40 },
  { 87, 40, 92, 42 },
  { 71, 41, 83, 41 },
  { 73, 42, 83, 42 },
  { 104, 42, 106, 42 },
  { 118, 42, 119, 42 },
  { 72, 43, 82, 43 },
  { 84, 43, 92, 43 },
  { 103, 43, 110, 43 },
  { 117, 43, 120, 44 },
  { 72, 44, 79, 44 },
  { 84, 44, 91, 44 },
  { 103, 44, 111, 44 },
  { 71, 45, 77, 45 },
  { 85, 45, 90, 45 },
  { 101, 45, 120, 45 },
  { 66, 46, 77, 46 },
  { 84, 46, 91, 46 },
  { 99, 46, 121, 47 },
  { 64, 47, 77, 47 },
  { 81, 47, 91, 47 },
  { 63, 48, 76, 48 },
  { 78, 48, 90, 48 },
  { 99, 48, 122, 48 },
  { 62, 49, 71, 49 },
  { 74, 49, 75, 49 },
  { 78, 49, 91, 49 },
  { 99, 49, 123, 49 },
  { 58, 50, 68, 50 },
  { 77, 50, 91, 50 },
  { 98, 50, 123, 50 },
  { 58, 51, 66, 51 },
  { 77, 51, 88, 51 },
  { 97, 51, 122, 51 },
  { 58, 52, 65, 52 },
  { 76, 52, 87, 52 },
  { 97, 52, 121, 52 },
  { 55, 53, 64, 53 },
  { 76, 53, 83, 53 },
  { 100, 53, 117, 53 },
  { 53, 54, 62, 55 },
  { 76, 54, 82, 54 },
  { 101, 54, 113, 54 },
  { 115, 54, 117, 54 },
  { 72, 55, 74, 55 },
  { 76, 55, 79, 55 },
  { 101, 55, 117, 55 },
  { 54, 56, 62, 56 },
  { 69, 56, 78, 56 },
  { 100, 56, 103, 56 },
  { 106, 56, 117, 56 },
  { 119, 56, 121, 56 },
  { 53, 57, 78, 57 },
  { 100, 57, 102, 57 },
  { 109, 57, 121, 57 },
  { 53, 58, 59, 59 },
  { 62, 58, 78, 58 },
  { 101, 58, 102, 58 },
  { 111, 58, 121, 58 },
  { 65, 59, 77, 59 },
  { 110, 59, 120, 60 },
  { 51, 60, 59, 60 },
  { 66, 60, 74, 60 },
  { 50, 61, 59, 65 },
  { 66, 61, 72, 64 },
  { 109, 61, 120, 62 },
  { 109, 63, 119, 63 },
  { 108, 64, 120, 64 },
  { 68, 65, 72, 65 },
  { 108, 65, 121, 66 },
  { 49, 66, 58, 68 },
  { 69, 66, 73, 67 },
  { 108, 67, 120, 68 },
  { 68, 68, 73, 68 },
  { 50, 69, 57, 69 },
  { 67, 69, 73, 69 },
  { 107, 69, 119, 69 },
  { 49, 70, 56, 70 },
  { 67, 70, 72, 70 },
  { 106, 70, 119, 71 },
  { 49, 71, 54, 71 },
  { 67, 71, 68, 71 },
  { 48, 72, 53, 72 },
  { 107, 72, 118, 72 },
  { 47, 73, 52, 73 },
  { 85, 73, 88, 73 },
  { 108, 73, 118, 73 },
  { 46, 74, 52, 75 },
  { 84, 74, 88, 74 },
  { 107, 74, 108, 74 },
  { 110, 74, 118, 74 },
  { 120, 74, 121, 74 },
  { 81, 75, 88, 75 },
  { 103, 75, 104, 75 },
  { 107, 75, 121, 75 },
  { 45, 76, 50, 76 },
  { 80, 76, 89, 76 },
  { 102, 76, 122, 77 },
  { 45, 77, 47, 77 },
  { 79, 77, 89, 78 },
  { 45, 78, 49, 78 },
  { 103, 78, 121, 78 },
  { 44, 79, 49, 79 },
  { 79, 79, 90, 80 },
  { 102, 79, 121, 79 },
  { 44, 80, 52, 81 },
  { 99, 80, 121, 80 },
  { 68, 81, 73, 81 },
  { 78, 81, 89, 81 },
  { 98, 81, 121, 81 },
  { 45, 82, 51, 83 },
  { 67, 82, 88, 82 },
  { 98, 82, 122, 82 },
  { 66, 83, 87, 83 },
  { 99, 83, 122, 83 },
  { 47, 84, 51, 85 },
  { 63, 84, 86, 85 },
  { 100, 84, 108, 84 },
  { 112, 84, 121, 84 },
  { 101, 85, 107, 86 },
  { 112, 85, 120, 86 },
  { 47, 86, 52, 86 },
  { 64, 86, 85, 86 },
  { 48, 87, 52, 87 },
  { 63, 87, 65, 87 },
  { 74, 87, 84, 87 },
  { 102, 87, 103, 87 },
  { 113, 87, 120, 87 },
  { 50, 88, 54, 88 },
  { 62, 88, 64, 88 },
  { 74, 88, 83, 88 },
  { 113, 88, 118, 89 },
  { 51, 89, 55, 90 },
  { 61, 89, 64, 89 },
  { 75, 89, 80, 89 },
  { 60, 90, 64, 90 },
  { 75, 90, 79, 92 },
  { 112, 90, 118, 90 },
  { 51, 91, 54, 91 },
  { 59, 91, 64, 92 },
  { 111, 91, 118, 91 },
  { 50, 92, 54, 92 },
  { 110, 92, 115, 92 },
  { 117, 92, 117, 92 },
  { 50, 93, 55, 93 },
  { 61, 93, 64, 93 },
  { 75, 93, 76, 93 },
  { 110, 93, 114, 93 },
  { 51, 94, 66, 94 },
  { 75, 94, 75, 95 },
  { 110, 94, 113, 94 },
  { 50, 95, 66, 95 },
  { 108, 95, 112, 95 },
  { 50, 96, 56, 96 },
  { 60, 96, 64, 96 },
  { 71, 96, 75, 96 },
  { 108, 96, 113, 97 },
  { 50, 97, 55, 99 },
  { 61, 97, 75, 97 },
  { 61, 98, 74, 98 },
  { 87, 98, 92, 99 },
  { 108, 98, 112, 98 },
  { 46, 99, 47, 99 },
  { 63, 99, 73, 100 },
  { 107, 99, 111, 99 },
  { 45, 100, 55, 100 },
  { 75, 100, 75, 100 },
  { 81, 100, 84, 102 },
  { 88, 100, 92, 100 },
  { 106, 100, 111, 101 },
  { 45, 101, 54, 101 },
  { 69, 101, 71, 101 },
  { 73, 101, 77, 101 },
  { 87, 101, 92, 101 },
  { 45, 102, 51, 102 },
  { 69, 102, 78, 102 },
  { 87, 102, 88, 102 },
  { 105, 102, 111, 102 },
  { 41, 103, 51, 104 },
  { 60, 103, 60, 103 },
  { 68, 103, 85, 103 },
  { 104, 103, 110, 103 },
  { 67, 104, 85, 104 },
  { 88, 104, 93, 104 },
  { 104, 104, 108, 104 },
  { 40, 105, 52, 105 },
  { 66, 105, 94, 105 },
  { 104, 105, 107, 105 },
  { 40, 106, 54, 106 },
  { 66, 106, 92, 108 },
  { 94, 106, 94, 107 },
  { 105, 106, 106, 107 },
  { 42, 107, 54, 107 },
  { 41, 108, 52, 108 },
  { 94, 108, 97, 108 },
  { 100, 108, 107, 108 },
  { 41, 109, 46, 109 },
  { 65, 109, 108, 109 },
  { 41, 110, 45, 110 },
  { 64, 110, 108, 110 },
  { 41, 111, 44, 111 },
  { 63, 111, 107, 112 },
  { 63, 113, 106, 113 },
  { 67, 114, 67, 114 },
  { 70, 114, 90, 114 },
  { 94, 114, 104, 114 },
  { 75, 115, 89, 115 },
  { 95, 115, 102, 115 },
  { 75, 116, 87, 116 },
  { 99, 116, 101, 116 },
  { 78, 117, 86, 117 },
  { 80, 118, 85, 118 },
  { 80, 119, 83, 119 },
  { 70, 120, 72, 120 },
  { 81, 120, 83, 120 },
  { 67, 121, 73, 121 },
  { 79, 121, 87, 122 },
  { 66, 122, 74, 122 },
  { 66, 123, 86, 124 },
  { 64, 125, 86, 126 },
  { 64, 127, 84, 127 },
  { 63, 128, 85, 128 },
}

-- The beacons alike at every difficulty and Eden's start (0x11014458 from its third entry, 0x11014D40,
-- 0x11014D80), made after the difficulty's two beacons as the original makes them. The Lynx at (23, 38) and the
-- Rail Gun post at (26, 37) are where the original has them at tick 1.
local START_BEACONS = {
    { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "Low", at = { 82, 80 } },
    { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "High", at = { 89, 107 } },
    { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "Low", at = { 47, 105 } },
    { type = "MiningBeacon", ore = "Common", yield = "Bar3", variant = "Low", at = { 48, 27 } },
    { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "High", at = { 7, 88 } },
    { type = "MiningBeacon", ore = "Common", yield = "Bar2", variant = "High", at = { 70, 7 } },
    { type = "Fumarole", ore = "Random", yield = "Random", variant = "Random", at = { 65, 103 } },
    { type = "Fumarole", ore = "Random", yield = "Random", variant = "Random", at = { 102, 81 } },
    { type = "Fumarole", ore = "Random", yield = "Random", variant = "Random", at = { 62, 79 } },
}
local EDEN_START = {
    -- Player 2
    { type = "CommandCenter", player = 2, at = { 8, 20 } },
    { type = "CommonOreMine", player = 2, at = { 49, 27 } },
    { type = "CommonOreSmelter", player = 2, at = { 19, 23 } },
    { type = "Tokamak", player = 2, at = { 4, 4 } },
    { type = "StructureFactory", player = 2, at = { 9, 23 } },
    { type = "Residence", player = 2, at = { 8, 12 } },
    { type = "Agridome", player = 2, at = { 11, 12 } },
    { type = "CommonStorage", player = 2, at = { 21, 18 } },
    { type = "Tokamak", player = 2, at = { 9, 4 } },
    { type = "Residence", player = 2, at = { 21, 15 } },
    { type = "Agridome", player = 2, at = { 13, 22 } },
    { type = "Residence", player = 2, at = { 13, 25 } },
    { type = "Lynx", weapon = "Laser", direction = "East", player = 2, at = { 23, 24 } },
    { type = "Lynx", weapon = "Laser", direction = "SouthEast", player = 2, at = { 22, 20 } },
    { type = "Lynx", weapon = "Laser", direction = "NorthWest", player = 2, at = { 20, 11 } },
    { type = "Lynx", weapon = "Laser", direction = "West", player = 2, at = { 6, 22 } },
    { type = "GuardPost", weapon = "RailGun", player = 2, at = { 84, 4 } },
    { type = "GuardPost", weapon = "RailGun", player = 2, at = { 84, 12 } },
    { type = "Lynx", weapon = "Laser", direction = "East", player = 2, at = { 84, 8 } },
    { type = "GuardPost", weapon = "Laser", player = 2, at = { 45, 30 } },
    { type = "Lynx", weapon = "Laser", direction = "South", player = 2, at = { 46, 28 } },
    { type = "Lynx", weapon = "Laser", direction = "West", player = 2, at = { 46, 32 } },
    { type = "Lynx", weapon = "Laser", direction = "East", player = 2, at = { 52, 26 } },
    { type = "Lynx", weapon = "Laser", direction = "South", player = 2, at = { 49, 42 } },
    { type = "Lynx", weapon = "Laser", direction = "East", player = 2, at = { 53, 40 } },
    { type = "CommandCenter", player = 2, at = { 5, 78 } },
    { type = "CommonOreSmelter", player = 2, at = { 5, 81 } },
    { type = "CommonOreMine", player = 2, at = { 8, 88 } },
    { type = "GuardPost", weapon = "RailGun", player = 2, at = { 22, 87 } },
    { type = "GuardPost", weapon = "RailGun", player = 2, at = { 32, 71 } },
    { type = "GuardPost", weapon = "RailGun", player = 2, at = { 41, 63 } },
    { type = "GuardPost", weapon = "RailGun", player = 2, at = { 47, 45 } },
    { type = "GuardPost", weapon = "RailGun", player = 2, at = { 26, 37 } },
    { type = "GuardPost", weapon = "RailGun", player = 2, at = { 20, 44 } },
    { type = "GuardPost", weapon = "RailGun", player = 2, at = { 20, 37 } },
    { type = "GuardPost", weapon = "Laser", player = 2, at = { 8, 81 } },
    { type = "GuardPost", weapon = "Laser", player = 2, at = { 8, 77 } },
    { type = "GuardPost", weapon = "Laser", player = 2, at = { 5, 75 } },
    { type = "GuardPost", weapon = "Laser", player = 2, at = { 21, 68 } },
    { type = "GuardPost", weapon = "Laser", player = 2, at = { 61, 24 } },
    { type = "GuardPost", weapon = "Laser", player = 2, at = { 54, 20 } },
    { type = "CargoTruck", direction = "South", player = 2, at = { 5, 84 } },
    { type = "CargoTruck", direction = "SouthEast", player = 2, at = { 5, 87 } },
    { type = "Lynx", weapon = "Laser", direction = "West", player = 2, at = { 8, 86 } },
    { type = "Lynx", weapon = "Laser", direction = "East", player = 2, at = { 4, 88 } },
    { type = "Lynx", weapon = "Laser", direction = "South", player = 2, at = { 23, 38 } },
    { type = "Lynx", weapon = "Laser", direction = "East", player = 2, at = { 21, 40 } },
    { type = "Lynx", weapon = "Laser", direction = "SouthWest", player = 2, at = { 29, 63 } },
    { type = "Lynx", weapon = "Laser", direction = "NorthWest", player = 2, at = { 30, 65 } },
    { type = "CargoTruck", direction = "SouthEast", player = 2, at = { 25, 26 } },
    { type = "CargoTruck", direction = "East", player = 2, at = { 28, 28 } },
    { type = "CargoTruck", direction = "East", player = 2, at = { 32, 28 } },
    { type = "ConVec", direction = "West", player = 2, at = { 8, 26 } },
    { type = "ConVec", direction = "NorthWest", player = 2, at = { 19, 13 } },
}

local kits_set = false
local function make_unit(player, u, at, kits, exact)
  local made = game.create_unit{ type = u.type, player = player, at = at, direction = u.direction,
                                 weapon = u.weapon, lights = u.lights, exact = exact }
  if u.cargo and made[1] then made[1]:set_cargo(u.cargo, u.amount) end
  -- A ConVec's kit with its weapon (a Guard Post kit's).
  if u.topping and made[1] then made[1]:set_kit(u.weapon, u.topping) end
  -- A carried-over ConVec's kit (and its topping, if any).
  if u.kit and made[1] then made[1]:set_kit(u.kit, u.topping) end
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
    if t.roll then
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
-- The mission itself, written by hand from q03.dll (Renegades' own event list, ../../findings/decompile/q03.md).
-- The DLL's numbers are kept as it has them: P() and RECT() turn its internal tiles (x + 32 on this 128-wide map)
-- into status-bar ones. Its unit tables and plans already hold status-bar tiles (it adds 0x1F and -1 to them), so
-- those are written here as they are.
-- ---------------------------------------------------------------------------------------------------------------

local function P(x, y) return { x - 31, y + 1 } end
-- A rectangle's west edge at internal x 0x1F (one column off the map) is taken as the map's first column: the game
-- would wrap a status-bar x of 0 to the east edge.
local function RECT(x1, y1, x2, y2) return { math.max(x1 - 31, 1), y1 + 1, x2 - 31, y2 + 1 } end
local function IX(unit) return unit.x + 31 end              -- a unit's tile as the DLL has it

-- Renegades' own voice lines: its extra.vol replaced the game's sounds 178-184 (savnt228-234). The remakes ship them as
-- ren228.wav-ren234.wav beside the mission and play them with OP2Lua's game.play_wav (0.8.1), the message itself
-- silent; on an older core, the stock sound id plays, as before.
local function voice(text, id)
  if game.play_wav and id >= 178 and id <= 184 then
    game.message(text, false)
    game.play_wav("ren" .. (id + 50) .. ".wav")
  else
    game.message(text, id)
  end
end
local function IY(unit) return unit.y - 1 end
local DIRS = { [0] = "East", "SouthEast", "South", "SouthWest", "West", "NorthWest", "North", "NorthEast" }

local HUMAN, EDEN, PLY = 1, 2, 3                            -- the DLL's players 0, 1 and 2

local state = {
  d = 0,                       -- 0x1101C004: 0 Easy, 1 Normal, 2 Hard
  arrivals = 0,                -- 0x110200F4: Plymouth's arrivals so far
  waves = 0,                   -- 0x110200F8
  wave_size = 0,               -- 0x110200FC
  raids = 0,                   -- 0x11020170
  attacks_on = true,           -- 0x1101C0EA: Eden's attack manager runs
  escorting = false,           -- 0x1101C0E8: the transfer check runs
  engaged = false,             -- 0x1101C0EB: the escort has seen player 1's Lynx
  defected = false,            -- 0x1101C0EC
  lava = {},                   -- 0x1101C0F0: the tiles the eruption makes lava-possible later
  salvage_at = { 0, 0 },       -- 0x11020148: where the salvage truck was at the last check
  ply_builders_records = 0,    -- how many times player 3's Factory has the Builders recorded (not in the DLL)
}
local g = {}                   -- the DLL's groups
local keep = {}                -- the units it keeps
local ev = {}                  -- the events it keeps, to remove later
local vc = {}                  -- the victory conditions and triggers it changes later
local repairers = {}           -- 0x110160CC: a structure's repairer, by the structure's id and player

-- ---------------------------------------------------------------------------------------------------------------
-- The carry-over from q02 (InitMap, 0x1100487D; ../../findings/decompile/q03.md). q02's remake keeps it as q02.carry
-- in OP2Lua's campaign store (the format is in tools/carry/writer.lua). Without one (a mission picked on its own, a
-- core without the store) the start is the stand-in's, as before.
-- ---------------------------------------------------------------------------------------------------------------

local function load_carry_over(name)
  if not campaign then print("This OP2LuaCore has no campaign store: the stand-in start") return nil end
  local data, err = campaign.load(name)
  if not data then print("No " .. name .. ".carry (" .. tostring(err) .. "): the stand-in start") end
  return data
end

-- What carries over (0x1100472D): player 1's vehicles in file order, each kind up to its limit at the difficulty
-- (0 Easy, 1 Normal, 2 Hard); a food truck's load is set to 200. The n-th kept goes at (126 - n/2, 125 + n%2),
-- facing East, lights on (0x11004971).
local CARRY_LIMITS = {
  food_truck = { 2, 2, 1 }, metal_truck = { 4, 3, 2 }, Lynx = { 4, 2, 0 }, RoboMiner = { 2, 2, 1 },
  RoboSurveyor = { 1, 1, 1 }, RoboDozer = { 1, 1, 1 }, Earthworker = { 1, 1, 1 },
  CommandCenter = { 1, 1, 1 }, StructureFactory = { 1, 1, 1 }, CommonOreSmelter = { 1, 1, 1 }, Tokamak = { 1, 1, 1 },
}
local function carried_vehicles(c, d)
  local taken, list = {}, {}
  for _, r in ipairs(c.units or {}) do
    if r.player == HUMAN and r.vehicle then
      local kind = r.type
      if r.type == "CargoTruck" then
        kind = r.cargo == "Food" and "food_truck" or r.cargo == "CommonMetal" and "metal_truck" or "none"
      elseif r.type == "ConVec" then
        kind = r.kit or "none"
        if not CARRY_LIMITS[kind] then kind = "none" end
      end
      local limit = kind == "none" and 0 or CARRY_LIMITS[kind] and CARRY_LIMITS[kind][d + 1]
      if not limit or (taken[kind] or 0) < limit then
        taken[kind] = (taken[kind] or 0) + 1
        local n = #list
        local u = { type = r.type, direction = "East", lights = true, at = { 126 - n // 2, 125 + n % 2 } }
        if r.type == "CargoTruck" then
          u.cargo, u.amount = r.cargo, r.cargo == "Food" and 200 or r.amount
        elseif r.type == "ConVec" then
          u.kit, u.topping = r.kit, r.weapon
        else
          u.weapon = r.weapon
        end
        list[#list + 1] = u
      end
    end
  end
  return list
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

-- The DLL writes q03.mis only when the game did NOT end as won (0x11005FD4, findings/CRASH-LEADS.md 7), so a won
-- q03 leaves q04 unable to start. The remake writes it on the win, as q01 and q02 do (../../TODO.md).
function on_end(result)
  if result and result.result == "won" then save_carry_over("q03", state.d, "the game reports the win") end
end

local function make(type, player, at, direction, weapon)
  return game.create_unit{ type = type, player = player, at = at, direction = DIRS[direction or 0],
                           weapon = weapon, exact = true }[1]
end

-- The game reuses a dead unit's id, so a kept handle can come to hold another unit: `type` checks it's still the
-- kind it was (findings/CRASH-LEADS.md 12).
local function alive(u, type) return u ~= nil and u.alive and (type == nil or u.type == type) end

-- ---------------------------------------------------------------------------------------------------------------
-- The DLL's events (mission-framework.md), worked as its runner works them: every game cycle, from the newest event
-- to the oldest. An event made during a pass waits for the next one; a one-shot event goes once it fires; an
-- inactive one waits until it's switched on.
-- ---------------------------------------------------------------------------------------------------------------

local events = {}

local function add_event(e)
  if #events >= 512 then
    print("Maximum number of events reached!")
    return nil
  end
  e.skip = true
  if e.active == nil then e.active = true end
  events[#events + 1] = e
  return e
end

local function run_events()
  for i = #events, 1, -1 do
    local e = events[i]
    if e.active and not e.skip and not e.dead then e:run() end
  end
  local kept = {}
  for _, e in ipairs(events) do
    e.skip = false
    if not e.dead then kept[#kept + 1] = e end
  end
  events = kept
end

local function fire(e, value)
  if e.one_shot then e.dead = true end
  e.fn(value == nil and e.value or value)
end

local function cancel(e) if e then e.dead = true end end                         -- 0x11006EE0

-- A time event (0x110079C0): due `min` + GetRand(max - min) after it's made, or exactly `min` when they're equal;
-- a repeating one is due that long again after each run, drawn after its callback (0x11007980).
local function draw(min, max) return min == max and min or min + game.rand(max - min) end

local function time_event(active, one_shot, min, max, fn, value)
  if min > max then min, max = max, min end
  local e = { active = active, one_shot = one_shot, fn = fn, value = value, last = 0 }
  e.due = game.tick() + draw(min, max)
  function e:run()
    local t = game.tick()
    if t >= self.due and self.last < self.due then
      fire(self)
      if self.dead then return end
      self.due = self.due + draw(min, max)
    end
    self.last = t
  end
  return add_event(e)
end
local function once(min, max, fn, value) return time_event(true, true, min, max, fn, value) end
local function repeating(min, max, fn) return time_event(true, false, min, max, fn) end

-- The other kinds: they fire when `test()` gives a value (the unit, for the tile event).
local function condition_event(one_shot, test, fn, value)
  local e = { one_shot = one_shot, fn = fn, value = value }
  function e:run()
    local v = test()
    if v then fire(self, v ~= true and v or nil) end
  end
  return add_event(e)
end

local COMPARE = { [0] = function(a, b) return a == b end, function(a, b) return a <= b end,
                  function(a, b) return a >= b end, function(a, b) return a < b end, function(a, b) return a > b end }

-- A player's units of a type, with a weapon or kit (nil: any): vehicles, or buildings (0x11007420, 0x11007300).
local function count(player, type, weapon)
  if not weapon then return players[player]:unit_count(type) end
  local n = 0
  for _, v in ipairs(players[player]:units(type)) do
    if v.weapon == weapon then n = n + 1 end
  end
  return n
end

-- A player's working structures of a type (0x11007390): not idle (0x12), being built (0x21) or taken down (0x22).
local function operational(player, type)
  local n = 0
  for _, b in ipairs(players[player]:buildings(type)) do
    local c = b.command
    if c ~= 0x12 and c ~= 0x21 and c ~= 0x22 then n = n + 1 end
  end
  return n
end

local function count_event(player, type, n, compare, fn, value)                -- 0x11007B00, one-shot
  return condition_event(true, function() return COMPARE[compare](count(player, type), n) end, fn, value)
end

local function working_event(player, type, n, compare, fn)                     -- 0x11007870, one-shot
  return condition_event(true, function() return COMPARE[compare](operational(player, type), n) end, fn)
end

local function group_count_event(group, n, compare, fn)                         -- 0x11001121, one-shot
  return condition_event(true, function() return COMPARE[compare](group():unit_count(), n) end, fn)
end

-- A group's losses (0x11007E50), against its count now. Mode 2: three quarters left, 3: half left, else none.
local function loss_event(group, mode, fn)
  local n = group:unit_count()
  local left = mode == 2 and (n * 3) // 4 or mode == 3 and n // 2 or 0
  return condition_event(true, function() return group:unit_count() <= left end, fn)
end

local function owned_in(player, r)
  for _, v in ipairs(game.units_in_rect(r)) do
    if v.owner == player - 1 then return true end
  end
  return false
end

-- Any of the player's units in x, y to x + w, y + h (0x11007CC0), or none in a rectangle (0x11001417).
local function area_event(one_shot, player, x, y, w, h, fn)
  local r = RECT(x, y, x + w, y + h)
  return condition_event(one_shot, function() return owned_in(player, r) end, fn)
end

local function empty_area_event(one_shot, player, r, fn)
  return condition_event(one_shot, function() return not owned_in(player, r) end, fn)
end

-- The player's unit on a tile (0x11008000).
local function tile_event(one_shot, player, x, y, fn)
  local at = P(x, y)
  return condition_event(one_shot, function()
    for _, v in ipairs(game.units_in_rect({ at[1], at[2], at[1], at[2] })) do
      if v.owner == player - 1 and v.x == at[1] and v.y == at[2] then return v end
    end
  end, fn)
end

local function research_event(tech, player, fn)                                 -- 0x110080A0, one-shot
  return condition_event(true, function() return players[player]:has_tech(tech) end, fn)
end

-- ---------------------------------------------------------------------------------------------------------------
-- Group helpers
-- ---------------------------------------------------------------------------------------------------------------

local function fight(player, rect)
  local grp = ai.fight_group(player)
  if rect then grp:set_rect(rect) end
  return grp
end

-- The game's ScGroup::TakeUnit doesn't take a unit out of the group it was in: it then sits in two groups' lists, and
-- removing it later from the older one corrupts the game's list (a crash in ScGroup::RemoveUnit, 0x0042BDCA; the
-- DLL's own takes, e.g. 0x110075D0, can leave it so too). So here a unit is taken out of the group that last took it
-- before another takes it, and is only removed from that group (findings/CRASH-LEADS.md 11).
local holder = {}

local function is_member(group, u)
  for _, v in ipairs(group:units()) do
    if v == u then return true end
  end
  return false
end

local function remove_from(group, u)
  if not (u and group and group.valid) then return end
  local h = holder[u.id]
  if h and h ~= group then return end
  if is_member(group, u) then group:remove_unit(u) end
  holder[u.id] = nil
end

local function take(group, u)
  if not (u and group and group.valid) then return end
  local h = holder[u.id]
  if h and h ~= group and h.valid and is_member(h, u) then h:remove_unit(u) end
  group:take_unit(u)
  holder[u.id] = group
end

-- A group can list a unit twice (player 3's Structure Factory: 0x11003880 takes it again), and the game faults on
-- the second removal, so each unit moves once.
local function move_units(from, to, type)
  local moved = {}
  for _, v in ipairs(from:units()) do
    if (not type or v.type == type) and not moved[v.id] then
      moved[v.id] = true
      remove_from(from, v)
      take(to, v)
    end
  end
end

-- A player's units of a type and weapon in a rectangle join the group (0x110075D0).
local function take_in_rect(group, r, player, type, weapon)
  for _, v in ipairs(game.units_in_rect(r)) do
    if v.owner == player - 1 and (not type or v.type == type) and (not weapon or v.weapon == weapon) then
      take(group, v)
    end
  end
end

-- A table's structures, tube and wall lines and Guard Posts, for a building group to keep standing (0x110017A9),
-- and a list of buildings (0x110018D6). Both in status-bar tiles.
local function record_line(group, x1, y1, x2, y2, wall)                         -- 0x11001634, status-bar tiles
  if x1 ~= x2 and y1 ~= y2 then
    record_line(group, x1, y1, x2, y1, wall)
    record_line(group, x2, y1, x2, y2, wall)
    return
  end
  local dx = x2 > x1 and 1 or x2 < x1 and -1 or 0
  local dy = y2 > y1 and 1 or y2 < y1 and -1 or 0
  local x, y = x1, y1
  local function rec()
    if wall then group:record_wall({ x, y }, "Wall") else group:record_tube({ x, y }) end
  end
  rec()
  while x ~= x2 or y ~= y2 do
    x, y = x + dx, y + dy
    rec()
  end
end

local function record_table(group, t)
  for _, s in ipairs(t.structures or {}) do group:record_building({ s[1], s[2] }, s[3]) end
  for _, l in ipairs(t.tubes or {}) do record_line(group, l[1], l[2], l[3], l[4]) end
  for _, l in ipairs(t.walls or {}) do record_line(group, l[1], l[2], l[3], l[4], true) end
  for _, gp in ipairs(t.posts or {}) do group:record_building({ gp[1], gp[2] }, "GuardPost", gp[3]) end
end

local function record_list(group, list)
  for _, b in ipairs(list) do group:record_building({ b[1], b[2] }, b[3], b[4]) end
end

-- The DLL's tables (read from q03.dll), in status-bar tiles.
local EDEN_BASE = {                                                             -- 0x11014D40
  structures = { { 8, 20, "CommandCenter" }, { 49, 27, "CommonOreMine" }, { 19, 23, "CommonOreSmelter" },
                 { 4, 4, "Tokamak" }, { 9, 23, "StructureFactory" }, { 8, 12, "Residence" }, { 11, 12, "Agridome" },
                 { 21, 18, "CommonStorage" }, { 9, 4, "Tokamak" }, { 21, 15, "Residence" }, { 13, 22, "Agridome" },
                 { 13, 25, "Residence" } },
  tubes = { { 8, 12, 21, 20 }, { 21, 20, 8, 12 }, { 8, 23, 21, 20 } },
  walls = { { 25, 39, 24, 38 }, { 19, 39, 22, 38 } },
  posts = { { 84, 4, "RailGun" }, { 84, 12, "RailGun" }, { 45, 30, "Laser" } },
}
local EDEN_POSTS = { { 22, 22 }, { 15, 24 }, { 23, 15 }, { 7, 14 }, { 14, 11 } }   -- 0x11014D60, 0x11014668
local EDEN_PLAN = {                                                             -- 0x11014DC0
  structures = { { 14, 4, "Tokamak" }, { 17, 15, "AdvancedLab" }, { 5, 20, "RobotCommand" }, { 13, 19, "GORF" } },
  tubes = { { 25, 37, 19, 30 }, { 19, 37, 14, 37 } },
}
local EDEN_RAILGUN_POSTS = { { 49, 30, "GuardPost", "RailGun" }, { 13, 37, "GuardPost", "RailGun" },
                             { 4, 37, "GuardPost", "RailGun" } }                -- 0x11014AB8
local EDEN_SOUTH = {                                                            -- 0x11014DA0
  structures = { { 5, 78, "CommandCenter" }, { 5, 81, "CommonOreSmelter" }, { 8, 88, "CommonOreMine" } },
  posts = { { 8, 77, "Laser" }, { 5, 75, "Laser" }, { 21, 68, "Laser" }, { 8, 81, "RailGun" }, { 5, 84, "Laser" } },
}
local PLY_LIST_1 = {                                                            -- 0x11014AF8
  { 13, 71, "GuardPost", "Microwave" }, { 16, 74, "GuardPost", "Microwave" }, { 9, 73, "VehicleFactory" },
  { 2, 77, "GuardPost", "Microwave" }, { 10, 80, "GuardPost", "Microwave" }, { 10, 83, "Residence" },
  { 5, 84, "GuardPost", "Microwave" }, { 13, 74, "Agridome" }, { 5, 93, "Tokamak" }, { 13, 84, "AdvancedLab" },
  { 10, 86, "CommonStorage" }, { 16, 83, "GuardPost", "Microwave" }, { 13, 87, "GuardPost", "Microwave" } }
local PLY_TABLE = {                                                             -- 0x11014DE0
  tubes = { { 9, 73, 5, 78 }, { 10, 73, 11, 73 }, { 10, 81, 5, 78 }, { 7, 77, 7, 82 }, { 5, 84, 11, 84 } },
  walls = { { 3, 71, 3, 75 } },
}
local PLY_LIST_2 = {                                                            -- 0x11014C50
  { 13, 76, "GuardPost", "RPG" }, { 5, 72, "GuardPost", "RPG" }, { 3, 85, "Nursery" }, { 19, 85, "University" },
  { 16, 88, "Residence" }, { 19, 88, "Agridome" }, { 22, 87, "GuardPost", "RPG" } }

-- ---------------------------------------------------------------------------------------------------------------
-- Eden's base and mining
-- ---------------------------------------------------------------------------------------------------------------

local base_part_2

-- Eden's mining (0x11001FEC): of its first two mines and smelters, the one with the smaller y is the northern.
local function eden_mining()
  local mines = players[EDEN]:buildings("CommonOreMine")
  local smelters = players[EDEN]:buildings("CommonOreSmelter")
  local m1, m2, s1, s2 = mines[1], mines[2], smelters[1], smelters[2]
  if m1 and m2 and m2.y < m1.y then m1, m2 = m2, m1 end
  if s1 and s2 and s2.y < s1.y then s1, s2 = s2, s1 end
  keep.mine_n, keep.mine_s, keep.smelter_n, keep.smelter_s = m1, m2, s1, s2
  if m1 and s1 then
    g.mining1:setup(m1, s1, RECT(0x31, 0x16, 0x36, 0x18))
    g.mining1:set_targ_count("CargoTruck", nil, 4)
  end
  if m2 and s2 then
    g.mining2:setup(m2, s2, RECT(0x23, 0x52, 0x27, 0x56))
    g.mining2:set_targ_count("CargoTruck", nil, 2)
  end
  for _, t in ipairs(players[EDEN]:units("CargoTruck")) do
    if IY(t) < 0x51 then take(g.mining1, t) else take(g.mining2, t) end
  end
end

-- The computer players' groups (0x11004A66), in the DLL's order.
local function make_groups()
  local d = state.d
  g.mining1 = ai.mining_group(EDEN)                                             -- 0x1101C054
  g.mining2 = ai.mining_group(EDEN)                                             -- 0x1101C058
  g.mining3 = ai.mining_group(EDEN)                                             -- 0x1101C05C
  g.ply_mining = ai.mining_group(PLY)                                           -- 0x1101C060
  g.truck_park = fight(EDEN, RECT(0x2E, 7, 0x32, 9))                            -- 0x1101C0C8
  g.builders = ai.building_group(EDEN)                                          -- 0x1101C064
  g.builders:set_targ_count("ConVec", nil, 2)
  g.builders:set_targ_count("Earthworker", nil, 1)
  g.builders:set_rect(RECT(0x25, 0x18, 0x2A, 0x1C))
  g.miner_builder = ai.building_group(EDEN)                                     -- 0x1101C068
  g.miner_builder:set_targ_count("ConVec", nil, 1)
  g.miner_builder:set_rect(RECT(0x25, 0x18, 0x2A, 0x1C))
  g.ply_builders = ai.building_group(PLY)                                       -- 0x1101C074
  g.ply_builders:set_targ_count("ConVec", nil, 1)
  g.ply_builders:set_targ_count("Earthworker", nil, 1)
  g.ply_builders:set_rect(RECT(0x26, 0x4D, 0x2A, 0x50))
  g.unused_builders = ai.building_group(EDEN)                                   -- 0x1101C070
  g.unused_builders:set_targ_count("ConVec", nil, 2)
  g.unused_builders:set_rect(RECT(0x26, 0x4D, 0x2A, 0x50))
  g.exit = fight(PLY, RECT(0x20, 100, 0x22, 0x66))                              -- 0x1101C08C
  g.north_guard = ai.fight_group(EDEN)                                          -- 0x1101C07C
  take_in_rect(g.north_guard, RECT(0x22, 8, 0x36, 0x18), EDEN, "Lynx", "Laser")
  g.north_guard:set_targ_count("Lynx", "Laser", d * 2 + 4)
  g.north_guard:do_guard_rect()
  g.north_guard:set_rect(RECT(0x22, 8, 0x36, 0x18))
  g.north_guard:add_guarded_rect(RECT(0x20, 0, 0x38, 0x1E))
  g.ridge_guard = ai.fight_group(EDEN)                                          -- 0x1101C080
  g.ridge_guard:set_targ_count("Lynx", "Laser", 4)
  g.ridge_guard:do_guard_rect()
  g.ridge_guard:set_rect(RECT(0x24, 0x22, 0x33, 0x23))
  g.ridge_guard:add_guarded_rect(RECT(0x20, 0x23, 0x34, 0x26))
  g.east_guard = ai.fight_group(EDEN)                                           -- 0x1101C084
  take_in_rect(g.east_guard, RECT(0x6E, 1, 0x73, 0xF), EDEN, "Lynx", "Laser")
  g.east_guard:set_targ_count("Lynx", "Laser", d + 3)
  g.east_guard:do_guard_rect()
  g.east_guard:set_rect(RECT(0x6E, 0, 0x71, 0xE))
  g.east_guard:add_guarded_rect(RECT(0x72, 0, 0x76, 0xE))
  g.south_raiders = ai.fight_group(EDEN)                                        -- 0x1101C088
  g.south_raiders:do_guard_rect()
  g.south_raiders:set_rect(RECT(0x22, 0x4B, 0x27, 0x58))
  g.south_raiders:set_attack_type("ConVec")
  g.staging = ai.fight_group(EDEN)                                              -- 0x1101C090
  g.staging:set_targ_count("Lynx", "Laser", 10)
  g.staging:set_rect(RECT(0x2F, 0x1D, 0x34, 0x20))
  g.attack = ai.fight_group(EDEN)                                               -- 0x1101C094
  g.attack:set_combine_fire()
  g.attack:set_attack_type("Lynx")
  g.attack:do_guard_rect()
  g.attack:set_rect(RECT(0x22, 0x48, 0x2B, 0x56))
  g.attack:add_guarded_rect(RECT(0x20, 0x44, 0x32, 0x61))
  g.unused_a = fight(EDEN, RECT(0x2A, 0x51, 0x2F, 0x57))                        -- 0x1101C0A0
  g.unused_b = fight(EDEN, RECT(0x21, 0x46, 0x2F, 0x4A))                        -- 0x1101C0A4
  g.outpost = ai.fight_group(EDEN)                                              -- 0x1101C0A8
  take_in_rect(g.outpost, RECT(0x50, 0x26, 0x54, 0x29), EDEN, "Lynx", "Laser")
  g.outpost:set_rect(RECT(0x50, 0x26, 0x54, 0x2A))
  g.outpost:add_guarded_rect(RECT(0x52, 0x2B, 0x5A, 0x31))
  g.outpost:add_guarded_rect(RECT(0x55, 0x30, 0x59, 0x33))
  g.outpost:add_guarded_rect(RECT(0x49, 0x22, 0x50, 0x2C))
  g.outpost:set_targ_count("Lynx", "Laser", d + 2)
  g.outpost:set_targ_count("Lynx", "RailGun", d)
  g.scout_patrol = ai.fight_group(EDEN)                                         -- 0x1101C0AC, route 0x1101C0D0
  local route = {}
  for i, p in ipairs({ { 0x36, 0x28 }, { 0x4B, 0x5C }, { 0x4D, 0x3A }, { 0x63, 7 }, { 0x85, 0x13 }, { 0x84, 0x45 },
                       { 0x6E, 0x40 }, { 0x79, 0x12 }, { 0x53, 0x2A }, { 0x58, 0xE }, { 0x49, 0x1D } }) do
    route[i] = P(p[1], p[2])
  end
  g.scout_patrol:set_patrol(route)
  g.dead_code = fight(EDEN, RECT(0x20, 0x47, 0x29, 0x5A))                       -- 0x1101C0C4
  g.ply_guard = ai.fight_group(PLY)                                             -- 0x1101C098
  g.ply_guard:do_guard_rect()
  g.ply_guard:set_rect(RECT(0x22, 0x4C, 0x25, 0x55))
  g.ply_guard:add_guarded_rect(RECT(0x20, 0x47, 0x29, 0x5A))
  g.ply_guard:set_combine_fire()
  g.ply_guard:set_attack_type("GuardPost")
  g.defence_a = ai.fight_group(PLY)                                             -- 0x1101C0B0
  g.defence_b = ai.fight_group(PLY)                                             -- 0x1101C0B4
  g.defence_c = ai.fight_group(PLY)                                             -- 0x1101C0B8
  g.defence_d = ai.fight_group(PLY)                                             -- 0x1101C0BC
  g.escort = ai.fight_group(PLY)                                                -- 0x1101C0C0
  g.ply_unused = ai.fight_group(PLY)                                            -- 0x1101C09C
  g.ply_unused:do_guard_rect()
  g.ply_unused:set_rect(RECT(0x2A, 0x14, 0x36, 0x1C))
  g.ply_unused:add_guarded_rect(RECT(0x25, 9, 0x2B, 0x14))
  g.ply_unused:set_combine_fire()
  g.factory = ai.building_group(EDEN)                                           -- 0x1101C06C
  g.factory:record_veh_reinforce_group(g.mining1, 600)
  g.factory:record_veh_reinforce_group(g.mining2, 900)
  g.factory:record_veh_reinforce_group(g.north_guard, 800)
  g.factory:record_veh_reinforce_group(g.ridge_guard, 500)
  g.factory:record_veh_reinforce_group(g.east_guard, 200)
  g.factory:record_veh_reinforce_group(g.builders, 400)
  g.factory:record_veh_reinforce_group(g.outpost, 50)
  g.ply_factory = ai.building_group(PLY)                                        -- 0x1101C078
  g.evac = ai.fight_group(PLY)                                                  -- 0x1101C0CC
  g.evac:set_targ_count("EvacuationTransport", nil, 1)
  g.evac:set_rect(RECT(0x27, 0x51, 0x2B, 0x53))
  eden_mining()
end

-- After 2200 ticks of a working Advanced Lab (0x110022AB): Staging wants Rail Gun Lynx, and three Rail Gun posts.
local function advanced_lab_works()
  g.staging:clear_targ_count()
  g.staging:set_targ_count("Lynx", "Laser", 7)
  g.staging:set_targ_count("Lynx", "RailGun", 4)
  record_list(g.builders, EDEN_RAILGUN_POSTS)
end

-- Eden's base plan, part 2 (0x110021C8).
base_part_2 = function()
  g.builders:record_building({ 0x31 - 31, 0x12 + 1 }, "Nursery")
  g.builders:record_building({ 0x2A - 31, 0xE + 1 }, "University")
  g.builders:record_building({ 0x32 - 31, 0x1A + 1 }, "VehicleFactory", nil, g.factory)
  g.builders:record_building({ 0x2D - 31, 0xD + 1 }, "CommonStorage")
  local posts = {}
  for i, p in ipairs(EDEN_POSTS) do posts[i] = { p[1], p[2], "GuardPost", "Laser" } end
  record_list(g.builders, posts)
  record_table(g.builders, EDEN_PLAN)
  working_event(EDEN, "AdvancedLab", 0, 4, function() once(2200, 2200, advanced_lab_works) end)   -- 0x11002292
end

-- Eden's base plan, part 1 (0x110022F0). On Easy the five Laser Guard Posts and the Standard Lab are already up
-- (made with the start), so part 2 follows at once; otherwise it waits for a working Standard Lab.
local function base_part_1()
  for _, v in ipairs(players[EDEN]:units("ConVec")) do take(g.builders, v) end
  keep.eden_sf = players[EDEN]:buildings("StructureFactory")[1]                  -- 0x1101C044
  if keep.eden_sf then take(g.builders, keep.eden_sf) end
  record_table(g.builders, EDEN_BASE)
  g.builders:record_building(P(0x30, 0xB), "StandardLab")
  if state.d ~= 0 then
    working_event(EDEN, "StandardLab", 0, 4, base_part_2)
  else
    base_part_2()
  end
  record_line(g.builders, 0x2D - 31, 0x26 + 1, 0x21 - 31, 0x24 + 1, true)
end

-- ---------------------------------------------------------------------------------------------------------------
-- Player 3's base
-- ---------------------------------------------------------------------------------------------------------------

local ply_part_1, ply_settles

-- Part 5 (0x11003CD5, 4200 ticks after part 4).

-- Player 3's Factory reinforces the Builders at 200 (parts 3 and 5 both record it), counted so Plymouth settling
-- can take every record off before the group is destroyed.
local function record_ply_builders()
  g.ply_factory:record_veh_reinforce_group(g.ply_builders, 200)
  state.ply_builders_records = state.ply_builders_records + 1
end

local function ply_part_5()
  players[PLY]:mark_research(5602)
  local function wants(grp, mw, rpg)
    grp:clear_targ_count()
    grp:set_targ_count("Lynx", "Microwave", mw)
    grp:set_targ_count("Lynx", "RPG", rpg)
  end
  wants(g.defence_a, 2, 1)
  wants(g.defence_b, 3, 2)
  wants(g.defence_c, 2, 1)
  g.defence_d:do_guard_rect()
  g.defence_d:set_rect(RECT(0x2A, 0x54, 0x2F, 0x58))
  g.defence_d:add_guarded_rect(RECT(0x23, 0x4A, 0x38, 0x57))
  g.defence_d:set_targ_count("Lynx", "Microwave", 2)
  g.defence_d:set_targ_count("Lynx", "RPG", 1)
  record_ply_builders()
  record_list(g.ply_builders, PLY_LIST_2)
end

local defectors_start

-- Part 4 (0x11003C21): a working Advanced Lab.
local function ply_part_4()
  cancel(ev.part4)
  ev.part4 = nil
  record_line(g.ply_builders, 0x30 - 31, 0x54 + 1, 0x2F - 31, 0x55 + 1)
  record_line(g.ply_builders, 0x32 - 31, 0x50 + 1, 0x34 - 31, 0x52 + 1, true)
  record_line(g.ply_builders, 0x35 - 31, 0x54 + 1, 0x37 - 31, 0x54 + 1, true)
  g.factory:unrecord_veh_group(g.outpost)
  g.factory:record_veh_reinforce_group(g.outpost, 500)
  once(4200, 4200, ply_part_5)
  defectors_start()
end

-- Part 3 (0x11003B26): a working Vehicle Factory.
local function ply_part_3()
  cancel(ev.part3)
  ev.part3 = nil
  local vf = players[PLY]:buildings("VehicleFactory")[1]
  if vf then take(g.ply_factory, vf) end
  record_ply_builders()
  g.ply_factory:record_veh_reinforce_group(g.defence_a, 500)
  g.ply_factory:record_veh_reinforce_group(g.defence_b, 1200)
  g.ply_factory:record_veh_reinforce_group(g.defence_c, 800)
  g.ply_factory:record_veh_reinforce_group(g.ply_mining, 300)
  g.defence_a:set_targ_count("Lynx", "Microwave", 2)
  g.defence_b:set_targ_count("Lynx", "Microwave", 4)
  g.defence_c:set_targ_count("Lynx", "Microwave", 2)
  cancel(ev.part4)
  ev.part4 = working_event(PLY, "AdvancedLab", 0, 4, ply_part_4)
end

local function to_exit(u)
  if alive(u) then
    remove_from(g.ply_builders, u)
    take(g.exit, u)
  end
end

-- Part 2 (0x11003880): a working Structure Factory.
local function ply_part_2()
  local sf = players[PLY]:buildings("StructureFactory")[1]
  if sf then take(g.ply_builders, sf) end
  record_list(g.ply_builders, PLY_LIST_1)
  record_line(g.ply_builders, 0x29 - 31, 0x43 + 1, 0x2F - 31, 0x47 + 1, true)
  record_table(g.ply_builders, PLY_TABLE)
  local function guard(grp, rect, guarded)
    grp:clear_guarded_rects()
    grp:do_guard_rect()
    grp:set_rect(rect)
    for _, r in ipairs(guarded) do grp:add_guarded_rect(r) end
  end
  guard(g.defence_a, RECT(0x22, 0x4B, 0x2C, 0x53), { RECT(0x20, 0x46, 0x2E, 0x58), RECT(0x2A, 0x41, 0x31, 0x46),
                                                       RECT(0x20, 0x59, 0x27, 100) })
  guard(g.defence_b, RECT(0x2D, 0x44, 0x32, 0x48), { RECT(0x22, 0x46, 0x2F, 0x54) })
  guard(g.defence_c, RECT(0x20, 0x44, 0x23, 0x4A), { RECT(0x20, 0x44, 0x2E, 0x53) })
  to_exit(keep.smelter_convec)
  to_exit(keep.tokamak_convec)
  local convec
  if game.tick() > 50000 and count(PLY, "ConVec") < 2 then
    convec = make("ConVec", PLY, P(0x20, 0x5E), 0)
    take(g.ply_builders, convec)
  end
  cancel(ev.part3)
  ev.part3 = working_event(PLY, "VehicleFactory", 0, 4, ply_part_3)
  g.mining1:set_targ_count("CargoTruck", nil, 5)
end

-- Player 3's mine and smelter (0x11002BE0).
local function ply_mining()
  local mine = players[PLY]:buildings("CommonOreMine")[1]
  local smelter = players[PLY]:buildings("CommonOreSmelter")[1]
  if mine and smelter then
    g.ply_mining:setup(mine, smelter, RECT(0x23, 0x52, 0x27, 0x56))
    g.ply_mining:set_targ_count("CargoTruck", nil, 2)
  end
end

-- Part 1 (0x11003503), when player 3 has a smelter. With value 1 it only hands the Tokamak ConVec to the Builders.
ply_part_1 = function(value)
  if value == 1 then
    if alive(keep.tokamak_convec) then take(g.ply_builders, keep.tokamak_convec) end
    return
  end
  local trucks = count(PLY, "CargoTruck")
  local tokamaks = 0
  for _, t in ipairs(players[PLY]:buildings("Tokamak")) do
    if t.max_hp - t.hp <= 800 then tokamaks = tokamaks + 1 end
  end
  if count(PLY, "StructureFactory") == 0 then
    to_exit(keep.sf_convec)
    keep.sf_convec = make("ConVec", PLY, P(0x20, 0x5F), 0)
    keep.sf_convec:set_kit("StructureFactory")
    g.ply_builders:record_building(P(0x29, 0x4C), "StructureFactory")
  end
  if not alive(keep.sf_convec) then keep.sf_convec = make("ConVec", PLY, P(0x20, 0x5F), 0) end
  take(g.ply_builders, keep.sf_convec)
  if tokamaks == 0 then
    if alive(keep.tokamak_convec) then take(g.exit, keep.tokamak_convec) end
    keep.tokamak_convec = make("ConVec", PLY, P(0x20, 0x60), 0)
    keep.tokamak_convec:set_kit("Tokamak")
    g.ply_builders:record_building(P(0x24, 0x5F), "Tokamak")
    local at = P(0x24, 0x5F)
    local there
    for _, v in ipairs(game.units_in_rect({ at[1], at[2], at[1], at[2] })) do
      if v.x == at[1] and v.y == at[2] then there = v break end
    end
    if not there then
      keep.tokamak_convec:build(at)
      take(g.ply_builders, keep.tokamak_convec)
    else
      keep.tokamak_convec:dismantle(there)
      count_event(PLY, "Tokamak", 0, 0, ply_part_1, 1)
    end
  end
  for n = trucks, 1 do
    take(g.ply_mining, make("CargoTruck", PLY, P(0x20, 0x5C + n), 6))
  end
  ply_mining()
  g.ply_mining:set_targ_count("CargoTruck", nil, 3)
  for _ = 1, 2 do take(g.defence_b, make("Lynx", PLY, P(0x1F, 0x5C), 7, "Microwave")) end
  g.defence_b:do_guard_rect()
  g.defence_b:set_rect(RECT(0x2B, 0x4C, 0x2F, 0x4E))
  g.defence_b:add_guarded_rect(RECT(0x22, 0x46, 0x2F, 0x4C))
  g.defence_b:add_guarded_rect(RECT(0x33, 0x42, 0x35, 0x44))
  working_event(PLY, "StructureFactory", 0, 4, ply_part_2)
end

-- Mining 3 at the new mine (0x11002B0D): the first units on (0x65, 6) and (0x37, 0xA).
local function mining_3()
  local function on(x, y)
    local at = P(x, y)
    for _, v in ipairs(game.units_in_rect({ at[1], at[2], at[1], at[2] })) do
      if v.x == at[1] and v.y == at[2] then return v end
    end
  end
  local mine, smelter = on(0x65, 6), on(0x37, 0xA)
  if mine and smelter then
    g.mining3:setup(mine, smelter, RECT(0x37, 8, 0x3B, 0xC))
    g.mining3:set_targ_count("CargoTruck", nil, 4)
    g.factory:record_veh_reinforce_group(g.mining3, 1200)
    if g.mining3:unit_count() < 3 then move_units(g.truck_park, g.mining3) end
  end
end

-- Plymouth settles (0x1100301D): once Eden's south base is gone, and 2000 ticks after Eden's attacks stop.
ply_settles = function()
  local miners = count(PLY, "RoboMiner")
  local has_cc = count(PLY, "CommandCenter") > 0
  local has_smelter = count(PLY, "CommonOreSmelter") > 0
  cancel(ev.refill)
  ev.refill = nil
  cancel(ev.empty)
  ev.empty = nil
  move_units(g.ply_guard, g.defence_a)
  g.defence_a:do_guard_rect()
  g.defence_a:set_rect(RECT(0x30, 0x51, 0x33, 0x58))
  g.defence_a:add_guarded_rect(RECT(0x33, 0x4B, 0x38, 0x57))
  g.defence_a:add_guarded_rect(RECT(0x1F, 0x43, 0x33, 0x53))
  -- Every record of the old group goes, not one: part 3 and part 5 both record it, and the DLL's one UnRecordVehGroup
  -- left the other pointing at the destroyed group, which faults the game (findings/CRASH-LEADS.md 13).
  for _ = 1, math.max(state.ply_builders_records, 1) do g.ply_factory:unrecord_veh_group(g.ply_builders) end
  state.ply_builders_records = 0
  local nb = ai.building_group(PLY)
  nb:set_targ_count("ConVec", nil, 1)
  nb:set_targ_count("Earthworker", nil, 1)
  nb:set_rect(RECT(0x26, 0x4D, 0x2A, 0x53))
  move_units(g.ply_builders, nb)
  g.ply_builders:destroy()
  g.ply_builders = nb
  take_in_rect(g.ply_builders, RECT(0x20, 0, 0x50, 0x7F), PLY, "ConVec")
  local mine = players[PLY]:buildings("CommonOreMine")[1]
  if mine and mine.max_hp - mine.hp > 800 then
    mine:kill()
    mine = nil
  end
  if miners == 0 and not mine then
    local m = make("RoboMiner", PLY, P(0x1F, 0x5E), 0)
    m:set_lights(true)
    m:deploy(P(0x27, 0x57))
  end
  if not has_smelter then
    if alive(keep.smelter_convec) then take(g.exit, keep.smelter_convec) end
    keep.smelter_convec = make("ConVec", PLY, P(0x20, 0x5C), 0)                -- 0x1101C038
    keep.smelter_convec:set_kit("CommonOreSmelter")
    g.ply_builders:record_building(P(0x24, 0x50), "CommonOreSmelter")
    take(g.ply_builders, keep.smelter_convec)
  end
  if not has_cc then
    if alive(keep.cc_convec) then
      remove_from(g.ply_builders, keep.cc_convec)
      take(g.exit, keep.cc_convec)
    end
    keep.cc_convec = make("ConVec", PLY, P(0x20, 0x60), 0)                     -- 0x1101C034
    keep.cc_convec:set_kit("CommandCenter")
    g.ply_builders:record_building(P(0x24, 0x4D), "CommandCenter")
  end
  if not alive(keep.cc_convec) then keep.cc_convec = make("ConVec", PLY, P(0x20, 0x60), 0) end
  take(g.ply_builders, keep.cc_convec)
  count_event(PLY, "CommonOreSmelter", 0, 4, ply_part_1)
  g.miner_builder:set_targ_count("RoboMiner", nil, 1)
  g.factory:record_veh_reinforce_group(g.miner_builder, 0x7FFF)
  if count(EDEN, "CommonOreMine") < 2 or count(EDEN, "CommonOreSmelter") < 2 then
    g.miner_builder:record_building(P(0x65, 6), "CommonOreMine")
    g.builders:record_building(P(0x37, 10), "CommonOreSmelter")
    g.builders:record_building(P(0x65, 3), "GuardPost", "Laser")
    g.builders:record_building(P(0x65, 9), "GuardPost", "Laser")
    g.builders:record_building(P(0x22, 0x1A), "Tokamak")
    tile_event(false, EDEN, 0x65, 6, mining_3)
  end
end

-- ---------------------------------------------------------------------------------------------------------------
-- Plymouth arrives, and Eden attacks
-- ---------------------------------------------------------------------------------------------------------------

local arrive

-- More for the Guard group once it's down to half (0x11002F76).
local function refill()
  for _ = 1, 1 + state.arrivals do take(g.ply_guard, make("Lynx", PLY, P(0x1F, 0x61), 7, "Microwave")) end
  take(g.ply_guard, make("Lynx", PLY, P(0x1F, 0x63), 6, "RPG"))
  cancel(ev.refill)
  ev.refill = loss_event(g.ply_guard, 3, refill)
end

-- The South raiders take Eden's Laser Lynx in the south (0x11003FA7).
local function raiders_take()
  take_in_rect(g.south_raiders, RECT(0x20, 0x3D, 0x42, 0x59), EDEN, "Lynx", "Laser")
end

-- Plymouth arrives (0x11002CFE): at 12,000, and again when Eden has beaten it.
arrive = function()
  if ev.again then
    cancel(ev.again)
    ev.again = nil
  end
  state.arrivals = state.arrivals + 1
  local k = state.arrivals
  for _ = 1, 4 + 2 * k do take(g.ply_guard, make("Lynx", PLY, P(0x1F, 0x61), 7, "Microwave")) end
  for _ = 1, 2 do take(g.ply_guard, make("Lynx", PLY, P(0x1F, 0x63), 6, "RPG")) end
  ev.empty = empty_area_event(false, EDEN, RECT(0x1F, 0x47, 0x2E, 100), ply_settles)
  if k == 1 then
    g.factory:unrecord_veh_group(g.mining2)
    g.mining2:set_targ_count("CargoTruck", nil, 0)
    move_units(g.mining2, g.truck_park)
  end
  ev.refill = loss_event(g.ply_guard, 3, refill)
  g.factory:record_veh_reinforce_group(g.staging, 8000)
  if game.rand(3) == 0 then once(400, 400, raiders_take) end
  if k > 1 then
    g.builders:clear_targ_count()
    g.factory:unrecord_veh_group(g.builders)
    local nb = ai.building_group(EDEN)
    move_units(g.builders, nb)
    g.builders:disable()
    g.builders:destroy()
    nb:set_targ_count("ConVec", nil, 2)
    nb:set_targ_count("Earthworker", nil, 1)
    nb:set_rect(RECT(0x25, 0x18, 0x2A, 0x1C))
    g.builders = nb
    record_table(g.builders, EDEN_BASE)
    base_part_2()
    record_line(g.builders, 0x2D - 31, 0x26 + 1, 0x21 - 31, 0x24 + 1, true)
    g.factory:record_veh_reinforce_group(g.builders, 400)
  end
end

-- Eden's salvage (0x110040E2, 0x11003FE2): a truck from Mining 1 clears the rubble south of its base for its GORF.
local function salvage_tick()
  if not (alive(keep.salvage_truck, "CargoTruck") and alive(keep.gorf, "GORF")) then return end
  local t = keep.salvage_truck
  if state.salvage_at[1] == IX(t) and state.salvage_at[2] == IY(t) and t.cargo ~= "CommonRubble" then
    t:salvage(RECT(0x20, 0x40, 0x36, 0x60), keep.gorf)
  end
  state.salvage_at = { IX(t), IY(t) }
end

local function salvage()
  keep.gorf = players[EDEN]:buildings("GORF")[1]
  if alive(keep.gorf) then
    if not keep.salvage_truck then
      for _, v in ipairs(g.mining1:units()) do
        if v.type == "CargoTruck" and v.cargo == "Empty" and v.alive and not (IX(v) == 0x4F and IY(v) == 0x1A) then
          remove_from(g.mining1, v)
          keep.salvage_truck = v
          v:stop()
          break
        end
      end
    end
    if keep.salvage_truck then
      ev.salvage.active = true
      salvage_tick()
      return
    end
  end
  once(500, 500, salvage)
end

-- Player 3's base has lost its mine (0x110043C0).
local function ply_mine_lost()
  if count(PLY, "Lynx") < 1 then
    move_units(g.staging, g.attack)
    g.factory:unrecord_veh_group(g.staging)
    return
  end
  g.factory:record_veh_reinforce_group(g.staging, 8000)
end

-- Player 3 has no Lynx left (0x11004240).
local function ply_lynx_gone()
  if count(PLY, "GuardPost") == 0 then
    g.factory:unrecord_veh_group(g.staging)
    move_units(g.staging, g.attack)
    record_table(g.builders, EDEN_SOUTH)
    once(500, 500, salvage)
  end
  if not ev.again then ev.again = once(3000, 5000, arrive) end
end

local scout_raid

-- (0x11004564)
local function raid_later()
  local t = (3 - state.d) * 1000
  once(t, t * 2, scout_raid)
end

-- A scout raid (0x1100440C).
scout_raid = function()
  move_units(g.staging, g.scout_patrol, "Scout")
  if state.d ~= 2 and not players[HUMAN]:has_tech(3408) then
    group_count_event(function() return g.staging end, 2, 2, raid_later)
    return
  end
  state.raids = state.raids + 1
  if state.raids > 3 then
    g.scout_patrol:do_guard_rect()                                              -- ClearPatrolMode isn't in OP2Lua
    g.scout_patrol:set_attack_type("GuardPost")
    g.scout_patrol:set_rect(RECT(0x6E, 0x28, 0x8C, 0x50))
  end
  if state.raids > 5 then state.raids = 5 end
  g.staging:clear_targ_count()
  g.staging:set_targ_count("Lynx", "RailGun", 0)
  g.staging:set_targ_count("Lynx", "Laser", 0)
  local laser = state.raids
  if state.raids > 3 then
    if not players[HUMAN]:has_tech(3851) then
      state.raids = 3
    else
      g.staging:set_targ_count("Lynx", "RailGun", state.raids - 3)
    end
    laser = math.min(state.raids, 3)
  end
  g.staging:set_targ_count("Lynx", "Laser", laser)
  move_units(g.staging, g.scout_patrol)
  group_count_event(function() return g.staging end, state.raids, 2, raid_later)
end

-- Eden's attack manager (0x11003E3C), every 100 from the dispatcher while it's on.
local function attack_manager()
  if not g.staging.valid then return end
  local n = g.staging:unit_count()
  if count(PLY, "GuardPost") + count(PLY, "Lynx") < n then
    state.wave_size = n
  else
    if n <= state.wave_size then return end
    state.wave_size = state.wave_size + 1
  end
  if state.wave_size < 5 then state.wave_size = 5 end
  state.waves = state.waves + 1
  if state.waves < 2 then once(900, 900, raiders_take) end
  move_units(g.staging, g.attack)
  if players[PLY]:buildings("CommonOreMine")[1] then count_event(PLY, "CommonOreMine", 0, 0, ply_mine_lost) end
  count_event(PLY, "Lynx", 0, 0, ply_lynx_gone)
  if game.tick() > 50000 or state.wave_size > 9 then
    state.attacks_on = false
    once(2000, 2000, ply_settles)
    g.staging:clear_targ_count()
    g.staging:set_targ_count("Scout", nil, 2)
    group_count_event(function() return g.staging end, 2, 0, raid_later)
  end
end

-- ---------------------------------------------------------------------------------------------------------------
-- The defectors
-- ---------------------------------------------------------------------------------------------------------------

local defection

-- The escort's move order (0x11002929, every 50): it keeps around the Evac, and fights once player 1's Lynx come.
local function escort_follow()
  local evac = keep.evac
  if not alive(evac, "EvacuationTransport") then return end
  local x, y = IX(evac), IY(evac)
  if g.escort:unit_count() == 0 then return end
  g.escort:clear_guarded_rects()
  g.escort:do_patrol_only()
  g.escort:set_rect(RECT(x - 2, y - 2, x + 3, y + 3))
  if not state.engaged then
    for _, v in ipairs(game.units_in_rect(RECT(x - 6, y - 6, x + 7, y + 7))) do
      if v.owner == 0 and v.type == "Lynx" then
        for _, e in ipairs(g.escort:units()) do e:set_offensive(true) end
        g.escort:do_attack_enemy()
        g.escort:set_attack_type("Lynx")
        state.engaged = true
        break
      end
    end
  end
end

-- The escort (0x11002A51): up to four Microwave Lynx from Defence A.
local function escort_start()
  local n = 0
  for _, v in ipairs(g.defence_a:units()) do
    if n >= 4 then break end
    if v.weapon == "Microwave" then
      remove_from(g.defence_a, v)
      v:set_offensive(false)                                                    -- op2extra's SetOffensive(false)
      take(g.escort, v)
      n = n + 1
    end
  end
  escort_follow()
  repeating(50, 50, escort_follow)
end

-- The transfer (0x11002867, every 100 from the dispatcher): next to a working Residence of player 1.
local function transfer()
  local evac = keep.evac
  if not alive(evac, "EvacuationTransport") then
    vc.lost:enable()
    return
  end
  local x, y = IX(evac), IY(evac)
  for _, v in ipairs(game.units_in_rect(RECT(x - 1, y - 1, x + 2, y + 2))) do
    if v.type == "Residence" and v.owner == 0 then
      if v.alive and not v.idled and evac.kit == "Panther" then                -- 0x110027B8
        voice("Colonists transferred safely.", 0xB2)
        local p = players[HUMAN]
        p.scientists = p.scientists + 5
        p.workers = p.workers + 10
        p.kids = p.kids + 10
        evac:set_kit("None")
        evac:clear_special_target()
        if vc.target then vc.target:destroy() vc.target = nil end
        if vc.failure then vc.failure:destroy() vc.failure = nil end
        state.escorting = false
        vc.escorted:enable()
      end
      return
    end
  end
end

-- The defection (0x110025B8): a player 3 unit reached the meeting point.
defection = function()
  if state.defected then return end
  if g.evac.valid then
    g.ply_factory:unrecord_veh_group(g.evac)
    remove_from(g.evac, keep.evac)
  end
  keep.evac:do_transfer(HUMAN)
  state.defected = true
  game.message("A group of colonists wants to defect.", 0xA2)
  vc.target = trigger.special_target{ target = keep.evac, type = "Residence", one_shot = true, enabled = false }
  state.escorting = true
  vc.wait:destroy()
  vc.escorted = trigger.time{ time = 10, enabled = false }
  vc.lost = trigger.time{ time = 10, enabled = false }
  vc.failure = mission.failure(vc.lost)
  mission.victory(vc.escorted, "Escort defectors to safety")
  game.message("New mission objective: Escort defectors to safety", 0x7A)
  game.message("To transfer colonists, put the evac next to a residence.", 0)
  empty_area_event(true, HUMAN, RECT(0x20, 0x43, 0x3E, 0x5A), escort_start)
  cancel(ev.evac_gone)
  ev.evac_gone = nil
end

-- 500 ticks after loading, the Evac's group drives to the meeting point (0x1100256D).
local function to_meeting()
  if state.defected then return end
  g.evac:set_rect(RECT(0x38, 0x4B, 0x3B, 0x4E))
  area_event(true, PLY, 0x38, 0x4B, 3, 3, defection)
end

-- Player 3 has one Evac Transport (0x110024F3).
local function loading()
  if state.defected then return end
  local evac = g.evac:first_of_type("EvacuationTransport")
  if evac then
    keep.evac = evac
    evac:set_kit("Panther")
    once(500, 500, to_meeting)
    cancel(ev.evac_gone)
    ev.evac_gone = count_event(PLY, "EvacuationTransport", 0, 0, defectors_start)
  end
end

-- No working Vehicle Factory for player 3 (0x11002425): an Evac Transport comes at the west edge.
local function evac_without_factory()
  cancel(ev.no_factory)
  ev.no_factory = nil
  if not state.defected and not keep.evac then
    keep.evac = make("EvacuationTransport", PLY, P(0x22, 0x5A), 0)
    keep.evac:set_kit("Panther")
    take(g.evac, keep.evac)
  end
end

-- An Evacuation Transport for the defectors (0x1100247B): at tick 80,000 or player 3's part 4.
defectors_start = function()
  cancel(ev.evac_gone)
  ev.evac_gone = nil
  if state.defected then return end
  g.ply_factory:record_veh_reinforce_group(g.evac, 200)
  count_event(PLY, "EvacuationTransport", 1, 0, loading)
  if not ev.no_factory then
    ev.no_factory = working_event(PLY, "VehicleFactory", 1, 3, evac_without_factory)
  end
end

-- ---------------------------------------------------------------------------------------------------------------
-- Disasters, the repair AI and the rest
-- ---------------------------------------------------------------------------------------------------------------

local function quake()                                                          -- 0x11004599: the y draw first
  local y = game.rand(100)
  local x = game.rand(0x5A)
  game.create_earthquake(P(x + 0x39, y + 1), 1)
end

local function meteor()                                                         -- 0x110045C0
  local y = game.rand(0x50)
  local x = game.rand(0x3C)
  game.create_meteor(P(x + 0x60, y + 0x28), 1)
end

-- The lava's later reach (0x110046FF): every recorded tile becomes lava-possible.
local function lava_spreads()
  for _, at in ipairs(state.lava) do game.set_lava_possible({ at[1], at[2], at[1], at[2] }) end
end

-- The volcano (0x110045E9).
local function volcano()
  game.set_tile(P(0x61, 0x5C), 0x450)
  game.set_tile(P(0x62, 0x5C), 0x45B)
  game.set_tile(P(0x61, 0x5D), 0x466)
  game.set_tile(P(0x62, 0x5D), 0x471)
  game.create_eruption(P(0x61, 0x5D), 0x50)
  local t = (9 - state.d) * 2000
  once(t, t, lava_spreads)
  once(950, 950, function() end)                                               -- the music's jump (0x11004590)
end

-- The tiles the eruption will reach (0x11004673): 0x1C7-0x1D6. The rest of that scan is op2dll's LAVA_POSSIBLE.
local function record_lava()
  for y = 1, 0x80 do
    for x = 0x1F, 0x9F do
      local t = game.tile(P(x, y))
      if t > 0x1C6 and t < 0x1D7 and #state.lava < 2047 then state.lava[#state.lava + 1] = P(x, y) end
    end
  end
end

-- The exit (0x11003DD5): the Exit group's units at the south-west corner vanish.
local function exit_check()
  for _, v in ipairs(g.exit:units()) do
    if IY(v) > 99 and IY(v) < 0x67 then v:remove() end
  end
end

-- The dispatcher (0x110055FE, every 100).
local function dispatcher()
  if state.attacks_on then attack_manager() end
  if state.escorting then transfer() end
end

-- The computer players' repairs (0x11006DEF, every 500), as q02's: the closest idle, empty ConVec not on a Structure
-- Factory's dock, or a Repair Vehicle, within 8 tiles (0x11006BBC: the search stops once the distance's high word
-- reaches 8; in the game a ConVec 50 tiles away isn't sent).
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

-- Objectives research adds (0x11005670-0x11005823): a building or units, and "New mission objective: ...".
local function added(trig, text, what)
  return function()
    mission.victory(trig(), text)
    game.message("New mission objective" .. what, 0x7A)
  end
end
local function operational_trigger(type)
  return function() return trigger.operational{ type = type, compare = ">", count = 0, player = HUMAN, one_shot = false } end
end
local function count_trigger(type, n)
  return function() return trigger.count{ type = type, compare = ">=", count = n, player = HUMAN } end
end

-- InitProc's part after the carry-over (0x11005892), in its order.
function setup_mission(difficulty)
  state.d = ({ Easy = 0, Normal = 1, Hard = 2 })[difficulty]
  local d = state.d
  record_lava()
  make_groups()
  area_event(false, PLY, 0x20, 100, 0x21, 0x66, exit_check)                     -- 0x11005629
  repeating(100, 100, dispatcher)
  ev.salvage = time_event(false, false, 200, 200, salvage_tick)
  base_part_1()
  repeating(500, 500, repairs)                                                  -- 0x11006B19

  research_event(5052, HUMAN, added(operational_trigger("Garage"), "Have at least 1 Garage operational",
                                    ": Construct a Garage"))
  mission.victory(trigger.research{ tech = 5052, player = HUMAN }, "Reconstruct the spider database")
  research_event(3303, HUMAN, added(operational_trigger("MedicalCenter"), "Have at least 1 Medical Center operational",
                                    ": Construct a Medical Center"))
  if d ~= 0 then
    mission.victory(trigger.research{ tech = 3303, player = HUMAN }, "Completely research Health Maintenance")
  end
  research_event(3301, HUMAN, added(operational_trigger("DIRT"), "Have at least 1 DIRT operational",
                                    ": Construct a DIRT"))
  if d ~= 0 then
    mission.victory(trigger.research{ tech = 3301, player = HUMAN }, "Completely research Emergency Response Systems")
  end
  research_event(3851, HUMAN, added(count_trigger("Lynx", 10), "Have at least 10 Lynx", ": Build 10 Lynx"))
  mission.victory(trigger.research{ tech = 3851, player = HUMAN }, "Completely research Mobile Weapons Platform")
  mission.victory(trigger.research{ tech = 3202, player = HUMAN }, "Research Vulcanology")
  research_event(3401, HUMAN, added(count_trigger("Scout", 2), "Have at least 2 Scouts", ": Build 2 Scouts"))
  local t3401 = trigger.research{ tech = 3401, player = HUMAN }
  local t3201 = trigger.research{ tech = 3201, player = HUMAN }
  mission.victory(trigger.set{ t3401, t3201 }, "Rebuild lost databases")
  vc.wait = mission.victory(trigger.kit{ type = "Spaceport", count = 1, player = EDEN }, "Wait for Plymouth defectors")
  mission.failure(trigger.resource{ resource = "Colonists", compare = "<", amount = 10, player = HUMAN })
  mission.victory(trigger.evac{ player = HUMAN }, "Have enough evacuation transports for your population")

  repeating(4000, 6000, quake)
  repeating(4000, 8000, meteor)
  local v = ({ 21000, 18000, 16000 })[d + 1]
  once(v, v, volcano)
  once(12000, 12000, arrive)
  once(80000, 80000, defectors_start)
  -- The carry-over for q04, once every victory condition still standing has been met.
  when(carry_won, function() save_carry_over("q03", state.d, "all the victory conditions met") end)
end

function on_tick() run_events() end

function on_init()
  game.message("Renegades v" .. VERSION, false)
  local difficulty = DIFFICULTIES[players[1].difficulty] and players[1].difficulty or "Normal"
  local d = DIFFICULTIES[difficulty]
  print("Difficulty: " .. difficulty)
  make_things(d)
  roll_beacons(BEACONS.rolled)
  for _, b in ipairs(START_BEACONS) do game.create_beacon(b) end
  for _, u in ipairs(EDEN_START) do
    if u.type == "Tube" or u.type == "Wall" then
      if u.type == "Tube" then game.create_tube(u.at) else game.create_wall("Wall", u.at) end
    else
      make_unit(players[u.player], u, u.at, nil, true)
    end
  end
  -- InitMap (0x1100487D): the difficulty check, then player 1's vehicles from q02.carry in place of the stand-in's.
  -- The rest of the start (colonists, stores, Eden's Easy-only posts) follows the checked difficulty.
  local carried = load_carry_over("q02")
  if carried then
    local NAMES = { [0] = "Easy", "Normal", "Hard" }
    local cd = carried.colony and carried.colony.difficulty
    if cd and NAMES[cd] and NAMES[cd] ~= difficulty then
      game.message("You're cheating ! Difficulty reset to " .. ({ [0] = "easy", "medium", "hard" })[cd] .. " :-)")
      difficulty = NAMES[cd]
      d = DIFFICULTIES[difficulty]
    end
    d.players[1].units = carried_vehicles(carried, ({ Easy = 0, Normal = 1, Hard = 2 })[difficulty])
  end
  for id, p in pairs(d.players) do make_player(players[id], p) end
  -- The setup's own map edits, after its units (and the draws it makes for them).
  game.initial_set_tile({ 66, 93 }, 1095)
  game.initial_set_tile({ 67, 93 }, 1107)
  game.initial_set_tile({ 66, 94 }, 1118)
  game.initial_set_tile({ 67, 94 }, 1129)
  game.set_cell_type({ 128, 128 }, 6)
  game.set_cell_type({ 127, 128 }, 6)
  game.set_cell_type({ 126, 128 }, 6)
  game.set_cell_type({ 125, 128 }, 6)
  game.set_cell_type({ 124, 128 }, 6)
  game.set_cell_type({ 123, 128 }, 6)
  game.set_cell_type({ 122, 128 }, 6)
  game.set_cell_type({ 121, 128 }, 6)
  game.set_cell_type({ 120, 128 }, 6)
  game.set_cell_type({ 119, 128 }, 6)
  game.set_cell_type({ 118, 128 }, 6)
  game.set_cell_type({ 117, 128 }, 6)
  game.set_cell_type({ 116, 128 }, 6)
  game.set_cell_type({ 115, 128 }, 6)
  game.set_cell_type({ 114, 128 }, 6)
  game.set_cell_type({ 113, 128 }, 6)
  game.set_cell_type({ 112, 128 }, 6)
  game.set_cell_type({ 111, 128 }, 6)
  game.set_cell_type({ 110, 128 }, 6)
  game.set_cell_type({ 109, 128 }, 6)
  game.set_cell_type({ 108, 128 }, 6)
  game.set_cell_type({ 107, 128 }, 6)
  game.set_cell_type({ 106, 128 }, 6)
  game.set_cell_type({ 105, 128 }, 6)
  game.set_cell_type({ 104, 128 }, 6)
  game.set_cell_type({ 103, 128 }, 6)
  game.set_cell_type({ 102, 128 }, 6)
  game.set_cell_type({ 101, 128 }, 6)
  game.set_cell_type({ 100, 128 }, 6)
  game.set_cell_type({ 99, 128 }, 6)
  game.set_cell_type({ 98, 128 }, 6)
  game.set_cell_type({ 97, 128 }, 6)
  game.set_cell_type({ 96, 128 }, 6)
  game.set_cell_type({ 95, 128 }, 6)
  game.set_cell_type({ 94, 128 }, 6)
  game.set_cell_type({ 93, 128 }, 6)
  game.set_cell_type({ 92, 128 }, 6)
  game.set_cell_type({ 91, 128 }, 6)
  game.set_cell_type({ 90, 128 }, 6)
  game.set_cell_type({ 89, 128 }, 6)
  game.set_cell_type({ 88, 128 }, 6)
  game.set_cell_type({ 87, 128 }, 6)
  game.set_cell_type({ 86, 128 }, 6)
  game.set_cell_type({ 85, 128 }, 6)
  game.set_cell_type({ 84, 128 }, 6)
  game.set_cell_type({ 83, 128 }, 6)
  game.set_cell_type({ 82, 128 }, 6)
  game.set_cell_type({ 81, 128 }, 6)
  game.set_cell_type({ 80, 128 }, 6)
  game.set_cell_type({ 79, 128 }, 6)
  game.set_cell_type({ 78, 128 }, 6)
  game.set_cell_type({ 77, 128 }, 6)
  game.set_cell_type({ 76, 128 }, 6)
  game.set_cell_type({ 75, 128 }, 6)
  game.set_cell_type({ 74, 128 }, 6)
  game.set_cell_type({ 73, 128 }, 6)
  game.set_cell_type({ 72, 128 }, 6)
  game.set_cell_type({ 71, 128 }, 6)
  game.set_cell_type({ 70, 128 }, 6)
  game.set_cell_type({ 69, 128 }, 6)
  game.set_cell_type({ 68, 128 }, 6)
  game.set_cell_type({ 67, 128 }, 6)
  game.set_cell_type({ 66, 128 }, 6)
  game.set_cell_type({ 65, 128 }, 6)
  game.set_cell_type({ 64, 128 }, 6)
  game.set_cell_type({ 63, 128 }, 6)
  game.set_cell_type({ 62, 128 }, 6)
  game.set_cell_type({ 61, 128 }, 6)
  game.set_cell_type({ 60, 128 }, 6)
  game.set_cell_type({ 59, 128 }, 6)
  game.set_cell_type({ 58, 128 }, 6)
  game.set_cell_type({ 57, 128 }, 6)
  game.set_cell_type({ 56, 128 }, 6)
  game.set_cell_type({ 55, 128 }, 6)
  game.set_cell_type({ 54, 128 }, 6)
  game.set_cell_type({ 53, 128 }, 6)
  game.set_cell_type({ 52, 128 }, 6)
  game.set_cell_type({ 51, 128 }, 6)
  game.set_cell_type({ 50, 128 }, 6)
  game.set_cell_type({ 49, 128 }, 6)
  game.set_cell_type({ 48, 128 }, 6)
  game.set_cell_type({ 47, 128 }, 6)
  game.set_cell_type({ 46, 128 }, 6)
  game.set_cell_type({ 45, 128 }, 6)
  game.set_cell_type({ 44, 128 }, 6)
  game.set_cell_type({ 43, 128 }, 6)
  game.set_cell_type({ 42, 128 }, 6)
  game.set_cell_type({ 41, 128 }, 6)
  game.set_cell_type({ 40, 128 }, 6)
  game.set_cell_type({ 39, 128 }, 6)
  game.set_cell_type({ 38, 128 }, 6)
  game.set_cell_type({ 37, 128 }, 6)
  game.set_cell_type({ 36, 128 }, 6)
  game.set_cell_type({ 35, 128 }, 6)
  game.set_cell_type({ 34, 128 }, 6)
  game.set_cell_type({ 33, 128 }, 6)
  game.set_cell_type({ 32, 128 }, 6)
  game.set_cell_type({ 31, 128 }, 6)
  game.set_cell_type({ 30, 128 }, 6)
  game.set_cell_type({ 29, 128 }, 6)
  game.set_cell_type({ 28, 128 }, 6)
  game.set_cell_type({ 27, 128 }, 6)
  game.set_cell_type({ 26, 128 }, 6)
  game.set_cell_type({ 25, 128 }, 6)
  game.set_cell_type({ 24, 128 }, 6)
  game.set_cell_type({ 23, 128 }, 6)
  game.set_cell_type({ 22, 128 }, 6)
  game.set_cell_type({ 21, 128 }, 6)
  game.set_cell_type({ 20, 128 }, 6)
  game.set_cell_type({ 19, 128 }, 6)
  game.set_cell_type({ 18, 128 }, 6)
  game.set_cell_type({ 17, 128 }, 6)
  game.set_cell_type({ 16, 128 }, 6)
  game.set_cell_type({ 15, 128 }, 6)
  game.set_cell_type({ 14, 128 }, 6)
  game.set_cell_type({ 13, 128 }, 6)
  game.set_cell_type({ 12, 128 }, 6)
  game.set_cell_type({ 11, 128 }, 6)
  game.set_cell_type({ 10, 128 }, 6)
  game.set_cell_type({ 9, 128 }, 6)
  game.set_cell_type({ 8, 128 }, 6)
  game.set_cell_type({ 7, 128 }, 6)
  game.set_cell_type({ 6, 128 }, 6)
  game.set_cell_type({ 5, 128 }, 6)
  game.set_cell_type({ 4, 128 }, 6)
  game.set_cell_type({ 3, 128 }, 6)
  game.set_cell_type({ 2, 128 }, 6)
  game.set_cell_type({ 1, 128 }, 6)
  game.set_cell_type({ 0, 128 }, 6)
  game.set_daylight_everywhere(false)
  game.set_daylight_moves(true)
  game.set_initial_light_level(143)
  -- ForceMoraleGood (0x11005EF0): the game then holds player 1 at 99, the top level, which OP2Lua calls "Excellent".
  if difficulty == "Easy" then game.morale_steady("Excellent") end
  if difficulty == "Normal" then game.free_morale() end
  if difficulty == "Hard" then game.free_morale() end
  for _, r in ipairs(LAVA_POSSIBLE) do game.set_lava_possible(r) end

  setup_mission(difficulty)
end

-- Where this differs from q03.dll, on purpose or for want of an exact match (../../findings/decompile/q03.md):
-- - Renegades' voice lines (its extra.vol's savnt228-234, sounds 178-184) play from ren228.wav-ren234.wav beside
--   the mission through OP2Lua's game.play_wav, not through the game's sound table: OPU 1.4.1 can't load the
--   mod's extra.vol. On a core without game.play_wav the stock sounds play.
-- - Measured against the DLL in the game (q03.md): unfed, every unit matches to the end and the mission is lost on
--   the same tick at every difficulty; fed for 90,000 ticks, it ends on the same tick too, and Eden's AI drifts
--   after Plymouth arrives (from tick 12,900 on Easy); why is open.
-- - A unit is taken out of the group that last took it before another takes it, and only removed from that group:
--   the game's TakeUnit leaves it in the old group's list too, and removing it from that list later crashes the game
--   (findings/CRASH-LEADS.md 11). The DLL's own takes can leave a unit in two lists.
-- - Player 1's vehicles come from q02.carry, which q02's remake writes when it's won, in place of Q02.mis; without
--   one, from the stand-in carry-over (q02 won at tick 2900 in the harness), baked in by op2dll. The "You're
--   cheating!" check is a message, not a message box.
-- - q03.carry is written when q03 is won; the DLL writes q03.mis only when it isn't, so q04 can't follow a win.
-- - Needs OP2Lua 0.7.10 or later for unit:set_offensive (op2extra's SetOffensive), which holds the escorts' fire.
-- - The scout patrol's ClearPatrolMode (after the third raid) is a DoGuardRect: OP2Lua has no ClearPatrolMode.
-- - Messages go to the message list; the DLL points some at a unit or the first Standard Lab.
-- - The volcano's music jump (0x11004590) is left out.
-- - "Closest" (a repairer) is by straight-line tile distance; the game's ClosestEnumerator measures its own way.
-- - The defectors' Evac carries a "Panther" as its cargo (map id 6, as the DLL's SetCargo(6)), the DLL's mark for
--   colonists aboard.
-- - A rectangle starting one column off the map (x 0x1F) starts at the map's first column here.
-- - Plymouth settling takes every Factory record of its Builders off before destroying the group: the DLL records it
--   in parts 3 and 5 and takes off one, so settling again after part 5 crashes the game (findings/CRASH-LEADS.md 13).
-- - Kept as in the DLL: the repeating tile event on (0x65, 6) reruns Mining 3's setup every cycle once something
--   stands there. Each run records Mining 3 with Eden's Factory again, and the duplicate records weight the Factory's
--   choice of what to build, so running it once changes how Eden plays (measured 2026-11-19, ../../TODO.md).
-- - Kept as in the DLL though probably a slip: Eden's waves add their one-shot events again on every wave.
