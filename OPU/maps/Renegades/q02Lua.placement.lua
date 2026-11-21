-- q02Lua.placement.lua  -  Outpost : Renegades - Onslaught (Lua) v1.2.10
-- Converted from q02.dll: what its setup makes at every difficulty. What changes with the
-- difficulty (more units on Easy, colonists, stores, research) and the beacons it rolls are in q02Lua.lua.
-- Coordinates are the in-game status-bar ones (map file tile + 1).
return {
  name = "Outpost : Renegades - Onslaught (Lua)", map = "Q02.map", tech = "Q02.tek",
  type = "2", max_tech = 3, players_count = 3,

  players = {
    [1] = { colony = "Plymouth", human = true, color = "Red" },
    [2] = { colony = "Eden", human = false, color = "Blue" },
    [3] = { colony = "Plymouth", human = false, color = "Black" },
  },

  units = {
  },

  walls = {
  },

  beacons = {
  },
}
