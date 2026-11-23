-- q04Lua.lua  -  Outpost : Renegades - Raid (Lua)
-- Converted from q04.dll. With q04Lua.placement.lua (what every difficulty makes alike),
-- this makes the colony's start: what changes with the difficulty, and the beacons the setup rolls.
-- The objectives, the computer players' AI and the mission's events (below the converted part) are written by hand.
-- Games run: Easy 151, Normal 151, Hard 151.
-- Coordinates are the in-game status-bar ones (map file tile + 1); a kit's are relative to its start.

-- The play log: each objective met and each failure condition that fires go in this mission's log
-- (OPU\logs\OP2Lua-q0NLua.log) with the mark, for looking back over play tests. mission.failure takes a label here as
-- its second argument (the game's takes only the trigger). The same in q01-q04.
do
  local function watch(kind, t, label)
    if not (t and when) then return end
    when(function() return t.valid and t:has_fired(players[1]) end,
         function() print(("%s: %s (mark %d)"):format(kind, label or "?", game.tick() // 100)) end)
  end
  local victory, failure = mission.victory, mission.failure
  mission.victory = function(t, text, ...)
    local r = victory(t, text, ...)
    watch("Objective met", r or t, text)
    return r
  end
  mission.failure = function(t, label)
    local r = failure(t)
    watch("Failure", r or t, label)
    return r
  end
end

-- The win, for the Renegades loader: a game started by op2launcher never tells the script it ended, and Outpost 2
-- sets its end reason only as it leaves the mission, which the loader can miss. So once every victory condition
-- still standing has fired (the game then ends as won; Raid makes some of them as it goes) q04.carry is written,
-- as q01-q03 write theirs, holding only the win: the loader takes a q0N.carry written since the launch as won.
-- Again in on_end when the game reports a win. The loader deletes it when a new campaign starts.
local carry_wins = {}
do
  local victory = mission.victory
  mission.victory = function(...)
    local t = victory(...)
    carry_wins[#carry_wins + 1] = t
    return t
  end
end

-- Every victory condition still standing has fired for the human player.
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

local function save_win(why)
  if not campaign then print("This OP2LuaCore has no campaign store: no q04.carry written") return end
  local ok, err = campaign.save("q04", { won = true, mission = "q04" })
  print(("Win marker q04.carry (%s): %s%s"):format(why, ok and "saved" or "not saved", err and (": " .. err) or ""))
end

function on_end(result)
  if result and result.result == "won" then save_win("the game reports the win") end
end

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
        ore = 10000, rare_ore = 10000,
        research = { 12898 },
        tech_level = 0,
        view = { 39, 121 },
        units = {
          { type = "Scout", direction = "North", lights = false, at = { 36, 126 } },
          { type = "Scout", direction = "North", lights = false, at = { 38, 126 } },
          { type = "Spider", direction = "North", lights = false, at = { 42, 126 } },
          { type = "CargoTruck", direction = "North", lights = false, at = { 36, 124 } },
          { type = "CargoTruck", direction = "North", lights = false, at = { 38, 124 } },
          { type = "CargoTruck", direction = "North", lights = false, at = { 40, 124 } },
          { type = "CargoTruck", direction = "North", lights = false, at = { 42, 124 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 32, 124 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 46, 124 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 34, 124 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 44, 124 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 32, 126 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 46, 126 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 34, 126 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 44, 126 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 39, 121 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 57, 5 } },
        },
      },
      [2] = {
        ore = 2000,
        research = {  },
        tech_level = 12,
        units = {
        },
      },
      [3] = {
        research = { 12899 },
        tech_level = 12,
        units = {
        },
      },
      [4] = {
        research = {  },
        units = {
        },
      },
    },
    walls = {
    },
    beacons = {
    },
  },
  Normal = {
    players = {
      [1] = {
        ore = 10000, rare_ore = 10000,
        research = { 12898 },
        tech_level = 0,
        view = { 39, 121 },
        units = {
          { type = "Scout", direction = "North", lights = false, at = { 36, 126 } },
          { type = "Scout", direction = "North", lights = false, at = { 38, 126 } },
          { type = "Spider", direction = "North", lights = false, at = { 42, 126 } },
          { type = "CargoTruck", direction = "North", lights = false, at = { 36, 124 } },
          { type = "CargoTruck", direction = "North", lights = false, at = { 38, 124 } },
          { type = "CargoTruck", direction = "North", lights = false, at = { 40, 124 } },
          { type = "CargoTruck", direction = "North", lights = false, at = { 42, 124 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 32, 124 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 46, 124 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 34, 124 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 44, 124 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 32, 126 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 46, 126 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 34, 126 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 44, 126 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 39, 121 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 57, 5 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 53, 5 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 26, 29 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 42, 34 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 33, 45 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 29, 52 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 40, 39 } },
        },
      },
      [2] = {
        ore = 2000,
        research = {  },
        tech_level = 12,
        units = {
        },
      },
      [3] = {
        research = { 12899 },
        tech_level = 12,
        units = {
        },
      },
      [4] = {
        research = {  },
        units = {
        },
      },
    },
    walls = {
    },
    beacons = {
    },
  },
  Hard = {
    players = {
      [1] = {
        ore = 10000, rare_ore = 10000,
        research = { 12898 },
        tech_level = 0,
        view = { 39, 121 },
        units = {
          { type = "Scout", direction = "North", lights = false, at = { 36, 126 } },
          { type = "Scout", direction = "North", lights = false, at = { 38, 126 } },
          { type = "Spider", direction = "North", lights = false, at = { 42, 126 } },
          { type = "CargoTruck", direction = "North", lights = false, at = { 36, 124 } },
          { type = "CargoTruck", direction = "North", lights = false, at = { 38, 124 } },
          { type = "CargoTruck", direction = "North", lights = false, at = { 40, 124 } },
          { type = "CargoTruck", direction = "North", lights = false, at = { 42, 124 } },
          -- No Lynx came from the stand-in q03 at Hard, so the original can't start (findings/CRASH-LEADS.md 10).
          -- The remake starts with one Microwave Lynx on each of the eight slots instead.
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 32, 124 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 46, 124 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 34, 124 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 44, 124 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 32, 126 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 46, 126 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 34, 126 } },
          { type = "Lynx", weapon = "Microwave", direction = "North", lights = false, at = { 44, 126 } },
        },
      },
      [2] = {
        ore = 2000,
        research = {  },
        tech_level = 12,
        units = {
        },
      },
      [3] = {
        research = { 12899 },
        tech_level = 12,
        units = {
        },
      },
      [4] = {
        research = {  },
        units = {
        },
      },
    },
    walls = {
    },
    beacons = {
    },
  },
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

-- The beacons and Player 2's base (0x11010108, 0x11010598), made before player 1's start as the original makes
-- them.
local START_BEACONS = {
    { type = "MiningBeacon", ore = "Common", yield = "Bar3", variant = "Low", at = { 41, 94 } },
    { type = "MiningBeacon", ore = "Common", yield = "Bar3", variant = "Mid", at = { 58, 41 } },
    { type = "MiningBeacon", ore = "Rare", yield = "Bar3", variant = "Low", at = { 11, 42 } },
    { type = "Fumarole", ore = "Random", yield = "Random", variant = "Random", at = { 20, 110 } },
    { type = "Fumarole", ore = "Random", yield = "Random", variant = "Random", at = { 33, 90 } },
}
local PLY_START = {
    -- Player 2
    { type = "CommandCenter", player = 2, at = { 30, 31 } },
    { type = "StructureFactory", player = 2, at = { 35, 31 } },
    { type = "Tokamak", player = 2, at = { 22, 22 } },
    { type = "Tokamak", player = 2, at = { 50, 43 } },
    { type = "Tokamak", player = 2, at = { 50, 36 } },
    { type = "CommonOreMine", player = 2, at = { 41, 94 } },
    { type = "CommonOreMine", player = 2, at = { 58, 41 } },
    { type = "RareOreSmelter", player = 2, at = { 20, 47 } },
    { type = "CommandCenter", player = 2, at = { 60, 31 } },
    { type = "CommonOreSmelter", player = 2, at = { 60, 34 } },
    { type = "CommonOreMine", player = 2, at = { 11, 42 } },
    { type = "VehicleFactory", player = 2, at = { 33, 47 } },
    { type = "Residence", player = 2, at = { 24, 53 } },
    { type = "RobotCommand", player = 2, at = { 30, 28 } },
    { type = "CommonOreSmelter", player = 2, at = { 40, 81 } },
    { type = "Agridome", player = 2, at = { 28, 37 } },
    { type = "StandardLab", player = 2, at = { 26, 31 } },
    { type = "AdvancedLab", player = 2, at = { 40, 34 } },
    { type = "Residence", player = 2, at = { 27, 34 } },
    { type = "Nursery", player = 2, at = { 32, 36 } },
    { type = "University", player = 2, at = { 42, 39 } },
    { type = "Residence", player = 2, at = { 24, 57 } },
    { type = "Agridome", player = 2, at = { 27, 45 } },
    { type = "AdvancedLab", player = 2, at = { 27, 52 } },
    { type = "GuardPost", weapon = "Microwave", player = 2, at = { 41, 90 } },
    { type = "GuardPost", weapon = "Microwave", player = 2, at = { 29, 33 } },
    { type = "GuardPost", weapon = "Microwave", player = 2, at = { 24, 45 } },
    { type = "GuardPost", weapon = "Microwave", player = 2, at = { 40, 30 } },
    { type = "GuardPost", weapon = "Microwave", player = 2, at = { 20, 50 } },
    { type = "GuardPost", weapon = "Microwave", player = 2, at = { 13, 44 } },
    { type = "CargoTruck", direction = "East", player = 2, at = { 41, 84 } },
    { type = "CargoTruck", direction = "East", player = 2, at = { 40, 89 } },
    { type = "CargoTruck", direction = "East", player = 2, at = { 40, 91 } },
    { type = "CargoTruck", direction = "East", player = 2, at = { 61, 36 } },
    { type = "CargoTruck", direction = "East", player = 2, at = { 57, 40 } },
    { type = "CargoTruck", direction = "East", player = 2, at = { 17, 48 } },
    { type = "Lynx", weapon = "Microwave", direction = "SouthWest", player = 2, at = { 15, 48 } },
    { type = "Lynx", weapon = "Microwave", direction = "South", player = 2, at = { 27, 62 } },
    { type = "Lynx", weapon = "Microwave", direction = "NorthWest", player = 2, at = { 56, 38 } },
    { type = "Lynx", weapon = "Microwave", direction = "East", player = 2, at = { 62, 28 } },
}

-- ---------------------------------------------------------------------------------------------------------------
-- The mission itself, written by hand from q04.dll (Renegades' own event list, ../../findings/decompile/q04.md).
-- The DLL's numbers are kept as it has them: P() and RECT() turn its internal tiles (x + 32 on this 64-wide map) into
-- status-bar ones. Its layouts already hold status-bar tiles (it adds 0x1F and -1 to them).
-- ---------------------------------------------------------------------------------------------------------------

local function P(x, y) return { x - 31, y + 1 } end
local function RECT(x1, y1, x2, y2) return { math.max(x1 - 31, 1), y1 + 1, x2 - 31, y2 + 1 } end
local function IX(unit) return unit.x + 31 end

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

local HUMAN, PLY, EDEN, WRECK = 1, 2, 3, 4                  -- the DLL's players 0-3
local ENTRY = { 0x46, 0x78 }                                -- 0x11011840

local state = {
  d = 0,                       -- 0x11017004: the difficulty (the three flags stay clear in a fresh game)
  got = {},                    -- 0x110178CC-0x110178D0: rpg, rare, panther, codes, scientists
  parts_made = false,          -- 0x110178D1
  panther_made = false,        -- 0x110178D2
  allied = false,              -- 0x110178D4
  beaten = false,              -- 0x110178D5
  waves = 0,                   -- 0x110170C4
  rearms = 0,                  -- 0x110170C8
  wp = { 0, 1 },               -- 0x110170BC, 0x110170C0: the Eden scouts' waypoint indexes
  doze = 0,                    -- 0x110170B8
}
local g = {}
local keep = {}
local ev = {}
local repairers = {}

local function make(type, player, at, direction, weapon)
  return game.create_unit{ type = type, player = player, at = at, direction = DIRS[direction or 0],
                           weapon = weapon, exact = true }[1]
end

-- The game reuses a dead unit's id, so a kept handle can come to hold another unit: `type` checks it's still the
-- kind it was (findings/CRASH-LEADS.md 12).
local function alive(u, type) return u ~= nil and u.alive and (type == nil or u.type == type) end

-- ---------------------------------------------------------------------------------------------------------------
-- The DLL's events, as q03's (mission-framework.md): newest first each cycle, a new one waits a cycle.
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

local function cancel(e) if e then e.dead = true end end                         -- 0x11005590

local function draw(min, max) return min == max and min or min + game.rand(max - min) end

local function time_event(one_shot, min, max, fn)                               -- 0x11005A30
  if min > max then min, max = max, min end
  local e = { one_shot = one_shot, fn = fn, last = 0 }
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
local function once(min, max, fn) return time_event(true, min, max, fn) end
local function repeating(min, max, fn) return time_event(false, min, max, fn) end

local function condition_event(one_shot, test, fn)
  local e = { one_shot = one_shot, fn = fn }
  function e:run()
    local v = test()
    if v then fire(self, v ~= true and v or nil) end
  end
  return add_event(e)
end

local COMPARE = { [0] = function(a, b) return a == b end, function(a, b) return a <= b end,
                  function(a, b) return a >= b end, function(a, b) return a < b end, function(a, b) return a > b end }

-- A player's units of a type, with a weapon (or a truck's cargo) when given (0x11005DF0, 0x11005F10).
local function count(player, type, with)
  if not with then return players[player]:unit_count(type) end
  local n = 0
  for _, v in ipairs(players[player]:units(type)) do
    if v.weapon == with or v.cargo == with then n = n + 1 end
  end
  return n
end

local function count_event(player, type, with, n, compare, fn)                  -- 0x11006060, one-shot
  return condition_event(true, function() return COMPARE[compare](count(player, type, with), n) end, fn)
end

-- The player's unit on a tile (0x11005C30, repeating here).
local function tile_event(player, x, y, fn)
  local at = P(x, y)
  return condition_event(false, function()
    for _, v in ipairs(game.units_in_rect({ at[1], at[2], at[1], at[2] })) do
      if v.owner == player - 1 and v.x == at[1] and v.y == at[2] then return v end
    end
  end, fn)
end

local function loss_event(group, mode, fn)                                      -- 0x11005D80
  local n = group:unit_count()
  local left = mode == 2 and (n * 3) // 4 or mode == 3 and n // 2 or 0
  return condition_event(true, function() return group:unit_count() <= left end, fn)
end

-- ---------------------------------------------------------------------------------------------------------------
-- Groups: each unit kept in one group (q03's lesson, findings/CRASH-LEADS.md 11)
-- ---------------------------------------------------------------------------------------------------------------

local holder = {}

local function is_member(group, u)
  for _, v in ipairs(group:units()) do
    if v == u then return true end
  end
  return false
end

local function take(group, u)
  if not (u and group and group.valid) then return end
  local h = holder[u.id]
  if h and h ~= group and h.valid and is_member(h, u) then h:remove_unit(u) end
  group:take_unit(u)
  holder[u.id] = group
end

local function fight(player, rect)
  local grp = ai.fight_group(player)
  if rect then grp:set_rect(rect) end
  return grp
end

-- 0x110014B0-style line recording, in status-bar tiles: along x, then along y from the corner (recorded twice).
local function record_line(group, x1, y1, x2, y2)
  if x1 ~= x2 and y1 ~= y2 then
    record_line(group, x1, y1, x2, y1)
    record_line(group, x2, y1, x2, y2)
    return
  end
  local dx = x2 > x1 and 1 or x2 < x1 and -1 or 0
  local dy = y2 > y1 and 1 or y2 < y1 and -1 or 0
  local x, y = x1, y1
  group:record_tube({ x, y })
  while x ~= x2 or y ~= y2 do
    x, y = x + dx, y + dy
    group:record_tube({ x, y })
  end
end

-- Player 2's layouts (read from q04.dll), in status-bar tiles: what the base builders keep standing (0x110016A0).
local LAYOUT = {                                                                -- 0x11010598
  structures = { { 30, 31, "CommandCenter" }, { 35, 31, "StructureFactory" }, { 22, 22, "Tokamak" },
                 { 50, 43, "Tokamak" }, { 50, 36, "Tokamak" }, { 41, 94, "CommonOreMine" }, { 58, 41, "CommonOreMine" },
                 { 20, 47, "RareOreSmelter" }, { 60, 31, "CommandCenter" }, { 60, 34, "CommonOreSmelter" },
                 { 11, 42, "CommonOreMine" }, { 33, 47, "VehicleFactory" }, { 24, 53, "Residence" },
                 { 30, 28, "RobotCommand" }, { 40, 81, "CommonOreSmelter" }, { 28, 37, "Agridome" },
                 { 26, 31, "StandardLab" }, { 40, 34, "AdvancedLab" }, { 27, 34, "Residence" }, { 32, 36, "Nursery" },
                 { 42, 39, "University" }, { 24, 57, "Residence" }, { 27, 45, "Agridome" }, { 27, 52, "AdvancedLab" } },
  tubes = { { 30, 31, 40, 41 }, { 30, 41, 40, 41 }, { 23, 47, 30, 31 }, { 34, 65, 25, 47 }, { 41, 81, 34, 65 } },
  posts = { { 41, 90, "Microwave" }, { 29, 33, "Microwave" }, { 24, 45, "Microwave" }, { 40, 30, "Microwave" },
            { 20, 50, "Microwave" }, { 13, 44, "Microwave" } },
}
local HARD_LAYOUT = {                                                           -- 0x110105D8
  tubes = { { 41, 90, 40, 83 }, { 44, 94, 41, 90 }, { 35, 97, 41, 94 }, { 42, 81, 42, 78 }, { 14, 44, 24, 47 },
            { 23, 67, 25, 65 } },
  posts = { { 45, 94, "RPG" }, { 41, 41, "RPG" }, { 42, 77, "RPG" }, { 32, 28, "RPG" }, { 22, 67, "RPG" },
            { 35, 97, "RPG" } },
}

local function record_layout(group, t)
  for _, s in ipairs(t.structures or {}) do group:record_building({ s[1], s[2] }, s[3]) end
  for _, l in ipairs(t.tubes or {}) do record_line(group, l[1], l[2], l[3], l[4]) end
  for _, gp in ipairs(t.posts or {}) do group:record_building({ gp[1], gp[2] }, "GuardPost", gp[3]) end
end

-- ---------------------------------------------------------------------------------------------------------------
-- Losing, and the loot
-- ---------------------------------------------------------------------------------------------------------------

-- 0x11003477: the mission is lost 10 ticks later.
local function lose()
  mission.failure(trigger.time{ time = 10 }, "something the raid needed was lost")
end

local function all_data() return state.got.rpg and state.got.rare and state.got.panther and state.got.codes end

local function new_objective(text) game.message(text, 0x7A) end                -- 0x11003250

local garage_lost

function gotNothing() game.message("Nothing found.", 0x59) end

function gotRPG()
  state.got.rpg = true
  voice("Retrieved RPG data.", 0xB6)
end

function gotRareOre()
  state.got.rare = true
  voice("Retrieved Rare Ore technologies", 0xB4)
end

function gotCodes()
  state.got.codes = true
  game.message("Retrieved security codes.", 0xA0)
end

function gotPanther()
  state.got.panther = true
  voice("Retrieved Panther design plans", 0xB6)
  mission.victory(trigger.count{ type = "Garage", compare = "==", count = 0, player = PLY }, "Destroy garages")
  count_event(PLY, "Garage", nil, 2, 3, garage_lost)
  count_event(PLY, "Garage", nil, 1, 3, garage_lost)
  mission.victory(trigger.count{ type = "VehicleFactory", compare = "==", count = 0, player = PLY },
                  "Destroy vehicle factories")
  new_objective("Destroy all vehicle factories and garages")
end

local function entry_escape(t)
  t.at, t.width, t.height, t.player = { x = ENTRY[1] - 6, y = ENTRY[2] - 6, raw = true }, 12, 12, HUMAN
  return trigger.escape(t)
end

function gotScientists()
  state.got.scientists = true
  voice("Scientists captured", 0xB2)
  keep.evac:set_kit("Lynx")                                                    -- the DLL's SetCargo(5, 0)
  mission.victory(entry_escape{ type = "EvacuationTransport", count = 1, cargo = 5, amount = 0 },
                  "Escort scientists to entry point")
  new_objective("New objective")
end

-- The parts (0x11003E72) and the wrecked Panther (0x11003FB2), made once each when their building falls.
local function parts_loaded()                                                   -- 0x11004027
  game.set_tile(keep.parts_at, keep.parts_tile)
  mission.failure(trigger.count{ type = "CargoTruck", cargo = 9, compare = "==", count = 0, player = HUMAN },
                  "no truck with the unit parts")
end

local function make_parts()
  if state.parts_made then return end
  game.create_wreckage(keep.parts_at, 0, true)
  game.set_tile(keep.parts_at, 0x66F)
  game.set_cell_type(keep.parts_at, 4)
  mission.victory(entry_escape{ type = "CargoTruck", count = 1, cargo = 9, amount = 1 }, "Bring unit parts to entry point")
  count_event(HUMAN, "CargoTruck", "Wreckage", 1, 0, parts_loaded)
  mission.failure(trigger.count{ type = "CargoTruck", compare = "==", count = 0, player = HUMAN }, "no Cargo Truck")
  new_objective("New objective")
  state.parts_made = true
end

local function panther_taken()                                                  -- 0x11003D79
  mission.victory(entry_escape{ type = "Panther", count = 1 }, "Escort Panther to entry point")
  mission.failure(trigger.count{ type = "Panther", cargo = "Microwave", compare = "==", count = 0, player = HUMAN },
                  "the Panther lost")
  new_objective("New objective")
end

local function make_panther(x, y)
  if state.panther_made then return end
  local p = make("Panther", WRECK, P(x, y), 0, "Microwave")
  p:set_damage(250)
  p:set_emp(-1)                                                                 -- op2extra's SetEMPticks(-1)
  p:set_offensive(false)                                                        -- op2extra's SetOffensive(false)
  count_event(HUMAN, "Panther", "Microwave", 0, 4, panther_taken)
  state.panther_made = true
end

-- Player 2's losses (0x110040A2-0x11004234).
local function vf_lost()
  if not state.got.panther then lose() end
  if keep.parts_place == 0 then make_parts() end
  if keep.panther_place == 0 then make_panther(0x40, 0x2E)
  elseif keep.panther_place == 3 then make_panther(0x3A, 0x1A) end
end

garage_lost = function()                                                        -- 0x1100415C
  if not alive(keep.garage1, "Garage") then
    if keep.parts_place == 1 then make_parts() end
    if keep.panther_place == 1 then make_panther(0x42, 0x24) end
  end
  if not alive(keep.garage2, "Garage") then
    if keep.parts_place == 2 then make_parts() end
    if keep.panther_place == 2 then make_panther(0x42, 0x27) end
  end
end

-- ---------------------------------------------------------------------------------------------------------------
-- Player 2: groups, mining, dozing, reinforcements, rebuild
-- ---------------------------------------------------------------------------------------------------------------

local DOZE = { RECT(0x48, 0x53, 0x49, 0x5B), RECT(0x48, 0x53, 0x49, 0x5B), RECT(0x2E, 0x2B, 0x2F, 0x2E),
               RECT(0x2E, 0x2B, 0x2F, 0x2E), RECT(0x59, 0x24, 0x5C, 0x26), RECT(0x59, 0x24, 0x5C, 0x26) }

local function dozing_step()                                                    -- 0x11002080, every 400
  local dz = keep.dozer
  -- The game reuses a dead unit's id, and the DLL keeps ordering whatever unit now has the dozer's: an order to doze
  -- given to another unit crashed the game (findings/CRASH-LEADS.md 12). So the dozing stops with the dozer.
  if not (alive(dz) and dz.type == "RoboDozer" and dz.owner == PLY - 1) then
    cancel(ev.dozing)
    ev.dozing = nil
    return
  end
  if dz.command == 1 then return end                                            -- still dozing (Doze, 1)
  state.doze = state.doze + 1
  if DOZE[state.doze + 1] then dz:doze(DOZE[state.doze + 1]) end
  if not DOZE[state.doze + 2] then
    cancel(ev.dozing)
    ev.dozing = nil
  end
end

local function start_dozing()                                                   -- 0x11001FFE
  keep.dozer = players[PLY]:units("RoboDozer")[1]
  if not keep.dozer then return end
  keep.dozer:doze(DOZE[1])
  ev.dozing = repeating(400, 400, dozing_step)
  state.doze = 0
end

local function make_groups()                                                    -- 0x11002B0D
  keep.convec = make("ConVec", PLY, P(0x42, 0x2E), 0)                           -- 0x11017044
  keep.sf = players[PLY]:buildings("StructureFactory")[1]                       -- 0x11017040
  keep.vf = players[PLY]:buildings("VehicleFactory")[1]                         -- 0x11017038
  if keep.sf then keep.sf:set_factory_cargo(1, "VehicleFactory") end            -- the DLL's bay 0
  g.mining_n = ai.mining_group(PLY)                                             -- 0x11017058
  g.mining_s = ai.mining_group(PLY)                                             -- 0x1101705C
  g.mining_rare = ai.mining_group(PLY)                                          -- 0x11017060
  g.builders = ai.building_group(PLY)                                           -- 0x11017064
  g.builders:set_targ_count("ConVec", nil, 2)
  g.builders:set_targ_count("Earthworker", nil, 1)
  g.builders:set_targ_count("RoboDozer", nil, 1)
  g.builders:set_rect(RECT(0x3E, 0x20, 0x44, 0x21))
  take(g.builders, keep.sf)
  take(g.builders, keep.convec)
  record_layout(g.builders, LAYOUT)
  record_layout(g.builders, HARD_LAYOUT)
  g.rebuilders = ai.building_group(PLY)                                         -- 0x11017068
  g.rebuilders:set_rect(RECT(0x3E, 0x20, 0x44, 0x21))
  g.rebuilders:set_lights(true)
  g.defence = ai.fight_group(PLY)                                               -- 0x11017074
  g.defence:set_targ_count("Lynx", "Microwave", 4)
  g.defence:set_targ_count("Lynx", "RPG", 2)
  g.defence:set_targ_count("Panther", "Microwave", 3)
  g.defence:set_targ_count("Panther", "RPG", 1)
  g.defence:do_guard_rect()
  g.defence:set_rect(RECT(0x37, 0x19, 0x4C, 0x29))
  g.defence:add_guarded_rect(RECT(0x2E, 0x2A, 0x42, 0x31))
  g.defence:add_guarded_rect(RECT(0x36, 0x31, 0x3C, 0x3A))
  g.defence:set_attack_type("Lynx")
  g.attack = ai.fight_group(PLY)                                                -- 0x11017078
  g.attack:set_targ_count("Lynx", "Microwave", 4)
  g.attack:set_targ_count("Lynx", "RPG", 1)
  g.factory = ai.building_group(PLY)                                            -- 0x1101706C
  take(g.factory, keep.vf)
  g.factory:record_veh_reinforce_group(g.defence, 2000)
  g.factory:record_veh_reinforce_group(g.mining_n, 1000)
  g.factory:record_veh_reinforce_group(g.mining_s, 1000)
  g.factory:record_veh_reinforce_group(g.mining_rare, 500)
  g.factory:record_veh_reinforce_group(g.builders, 4000)
  g.factory:record_veh_reinforce_group(g.attack, 8000)
  g.assault = fight(EDEN, RECT(0x52, 0xB, 0x59, 0xE))                           -- 0x1101707C
  g.escort_a = fight(EDEN, RECT(0x4A, 0x16, 0x4F, 0x19))                        -- 0x11017080
  g.escort_a:set_lights(false)
  g.escort_b = fight(EDEN, RECT(0x4A, 0x16, 0x4F, 0x19))                        -- 0x11017084
  g.escort_b:set_lights(false)
  g.late_guard = ai.fight_group(PLY)                                            -- 0x11017088
  count_event(PLY, "RoboDozer", nil, 1, 0, start_dozing)
end

-- Player 2's mining (0x11001D50): the first two common mines and smelters, sorted north/south by y, and the rare
-- pair. Trucks by where they stand: south of y 0x50 to the south group, else east of x 0x50 to the north, else rare.
local function mining()
  local function pair(type)
    local list = players[PLY]:buildings(type)
    local a, b = list[1], list[2]
    if a and b and b.y < a.y then a, b = b, a end
    return a, b
  end
  local mine_n, mine_s = pair("CommonOreMine")
  local smelter_n, smelter_s = pair("CommonOreSmelter")
  local rare_mine = players[PLY]:buildings("RareOreMine")[1]
  local rare_smelter = players[PLY]:buildings("RareOreSmelter")[1]
  if mine_n and smelter_n then g.mining_n:setup(mine_n, smelter_n, RECT(0x47, 0x50, 0x4A, 0x53)) end
  g.mining_n:set_targ_count("CargoTruck", nil, 2)
  if mine_s and smelter_s then g.mining_s:setup(mine_s, smelter_s, RECT(0x5B, 0x21, 0x5E, 0x24)) end
  g.mining_s:set_targ_count("CargoTruck", nil, 3)
  if rare_mine and rare_smelter then g.mining_rare:setup(rare_mine, rare_smelter, RECT(0x30, 0x2E, 0x32, 0x31)) end
  g.mining_rare:set_targ_count("CargoTruck", nil, 2)
  for _, t in ipairs(players[PLY]:units("CargoTruck")) do
    if IY(t) < 0x51 then
      take(IX(t) < 0x51 and g.mining_rare or g.mining_n, t)
    else
      take(g.mining_s, t)
    end
  end
end

local function patrol()                                                         -- 0x11001F88
  local route = {}
  for i, p in ipairs({ { 0x4C, 0x1A }, { 0x36, 0xE }, { 0x2F, 0x45 }, { 0x48, 0x67 }, { 0x5A, 0x4B }, { 0x4C, 0x25 } }) do
    route[i] = P(p[1], p[2])
  end
  g.attack:set_patrol(route)
  take(g.attack, make("Lynx", PLY, P(0x4B, 0x1C), 0, "Microwave"))
  take(g.attack, make("Lynx", PLY, P(0x38, 0x23), 0, "Microwave"))
end

-- The rebuild (0x1100294D, 300 ticks after the reinforcements): kits from the west edge for what's gone.
local function rebuild()
  local convecs = count(PLY, "ConVec")
  local cc_west = false
  for _, b in ipairs(players[PLY]:buildings("CommandCenter")) do
    if IX(b) == 0x3D then cc_west = true break end
  end
  local sfs, vfs, toks = count(PLY, "StructureFactory"), count(PLY, "VehicleFactory"), count(PLY, "Tokamak")
  local mines = count(PLY, "CommonOreMine")
  local function kit(type, y, mode, at)                                         -- 0x110027EB
    local cv = make("ConVec", PLY, P(0x20, y), 0)
    cv:set_kit(type)
    if mode == 1 then
      take(g.builders, cv)
    else
      take(g.rebuilders, cv)
      g.rebuilders:record_building(P(at[1], at[2]), type)
    end
  end
  if mines < 2 then make("RoboMiner", PLY, P(0x21, 0x10), 0) end
  if mines < 1 then make("RoboMiner", PLY, P(0x21, 0xF), 0) end
  if not cc_west then
    kit("CommandCenter", 0xE, 2, { 0x3D, 0x1E })
    convecs = convecs + 1
  end
  if sfs == 0 then
    kit("StructureFactory", 0xF, convecs > 0 and 2 or 1, { 0x42, 0x1E })
    convecs = convecs + 1
  end
  if toks == 0 then
    kit("Tokamak", 0x10, convecs > 1 and 2 or 1, { 0x35, 0x15 })
    convecs = convecs + 1
  end
  if vfs == 0 then
    if convecs < 3 then
      kit("VehicleFactory", 0x10, 2, { 0x39, 0x1A })
      convecs = convecs + 1
    else
      g.rebuilders:record_building(P(0x39, 0x1A), "VehicleFactory")
    end
  end
  while convecs < 3 do
    kit("VehicleFactory", 0x10, 2, { 0x39, 0x1A })
    convecs = convecs + 1
  end
end

-- Plymouth's reinforcements (0x1100284D): 2d + 4 rows of a Microwave and an RPG Lynx on the west edge.
local function reinforcements()
  for y = state.d * 2 + 0x15, 0x12, -1 do
    take(g.late_guard, make("Lynx", PLY, P(0x21, y), 0, "Microwave"))
    take(g.late_guard, make("Lynx", PLY, P(0x20, y), 0, "RPG"))
  end
  g.late_guard:do_guard_rect()
  g.late_guard:set_rect(RECT(0x37, 0x19, 0x4C, 0x29))
  g.late_guard:add_guarded_rect(RECT(0x1F, 0xC, 0x5F, 0x37))
  g.late_guard:add_guarded_rect(RECT(0x2A, 0x37, 0x54, 0x62))
  g.late_guard:set_attack_type("Lynx")
  g.late_guard:set_attack_type("Panther")
  g.late_guard:set_combine_fire()
  once(300, 300, rebuild)
end

-- ---------------------------------------------------------------------------------------------------------------
-- Eden's raid
-- ---------------------------------------------------------------------------------------------------------------

local WAYPOINTS = { [0] = { 0x58, 4 }, { 0x54, 4 }, { 0x39, 0x1C }, { 0x49, 0x21 }, { 0x40, 0x2C }, { 0x3C, 0x33 },
                    { 0x47, 0x26 }, { 0x33, 0x2C }, { 0x56, 0 }, { 0x56, 0 } }

local function ally()                                                           -- 0x110020DD
  game.message("We might be able to help each other out!", 0)
  voice("It seems those Eden units are here for the same reason", 0xB7)
  state.allied = true
  players[EDEN]:ally_with(HUMAN)
end

local leg

-- A scout's next leg (0x11002244 for A, 0x1100235B for B).
leg = function(k)
  local scout, grp = keep.scouts[k], k == 1 and g.escort_a or g.escort_b
  cancel(ev.leg[k])
  ev.leg[k] = nil
  if not alive(scout, "Scout") then return end
  state.wp[k] = state.wp[k] + 2
  if state.wp[k] < 10 then
    local w = WAYPOINTS[state.wp[k]]
    scout:move(P(w[1], w[2]))
    grp:set_rect(RECT(w[1] - 2, w[2] - 2, w[1] + 2, w[2] + 2))
    -- 0x11002126, 0x110021B5: an Eden unit on the waypoint; when it's the Scout, the next leg in 50.
    ev.leg[k] = tile_event(EDEN, w[1], w[2], function()
      if not alive(scout, "Scout") then
        cancel(ev.leg[k])
      elseif IX(scout) == w[1] and IY(scout) == w[2] then
        cancel(ev.leg[k])
        ev.leg[k] = once(50, 50, function() leg(k) end)
      end
    end)
  else
    scout:remove()
    grp:do_exit_map()
    if all_data() then g.assault:do_exit_map() end
  end
  if state.wp[k] > 3 and not state.allied then ally() end
end

-- An escort (0x11002531 for A, 0x1100261F for B): Laser Lynx up to the difficulty, and its Scout if it's gone.
local function escort(k)
  local grp = k == 1 and g.escort_a or g.escort_b
  local n = state.d - grp:unit_count() + 1
  if n >= 0 then
    for i = 0, n do
      local x = k == 1 and (0x5E - 2 * n + 2 * i) or (0x52 + 2 * n - 2 * i)
      take(grp, make("Lynx", EDEN, P(x, 1), 2, "Laser"))
    end
  end
  if not alive(keep.scouts[k], "Scout") then
    keep.scouts[k] = make("Scout", EDEN, P(k == 1 and 0x60 or 0x50, 1), 2)
    grp:do_guard_unit()
    grp:set_target_unit(keep.scouts[k])
    grp:set_follow_mode(1)
    grp:set_rect(RECT(0x4A, 0x16, 0x4F, 0x19))
    grp:set_attack_type("Lynx")
    grp:set_attack_type("GuardPost")
    state.wp[k] = state.wp[k] - 2
    leg(k)
  end
end

local escorts

-- 0x11002765: once Eden has no Scouts, the escorts come again 2200 later.
local function escorts_again() ev.escort_timer = once(2200, 2200, escorts) end

-- 0x1100270A, 400 after an assault, while it isn't beaten.
escorts = function()
  if state.beaten then return end
  local a = state.wp[1] < 10
  if a then escort(1) end
  local b = state.wp[2] < 10
  if b then escort(2) end
  if a or b then
    state.rearms = state.rearms + 1
    if state.rearms < 2 then count_event(EDEN, "Scout", nil, 0, 0, escorts_again) end
  end
end

local assault

-- 0x11002783: an assault beaten.
local function assault_beaten()
  g.assault:do_guard_rect()
  g.assault:set_rect(RECT(0x52, 0xB, 0x59, 0xE))
  state.waves = state.waves + 1
  state.beaten = true
  if state.waves < 3 and not all_data() then once(2000, 2000, assault) end
end

-- An Eden assault (0x1100244C).
assault = function()
  local posts, vfs = count(PLY, "GuardPost"), count(PLY, "VehicleFactory")
  local n = state.waves + 2 + state.d * 2
  if posts < 4 then n = n - 1 end
  if posts < 2 then n = n - 1 end
  if vfs == 0 then n = n - 2 end
  for i = n - 1, 0, -1 do
    take(g.assault, make("Lynx", EDEN, P(0x55 + 2 * i, 1), 2, "RailGun"))
  end
  g.assault:do_attack_enemy()
  g.assault:set_attack_type("GuardPost")
  g.assault:set_combine_fire()
  cancel(ev.escort_timer)
  ev.escort_timer = nil
  once(400, 400, escorts)
  state.beaten = false
  loss_event(g.assault, 2, assault_beaten)
end

-- ---------------------------------------------------------------------------------------------------------------
-- The repair AI (0x110054E9), as q02's and q03's
-- ---------------------------------------------------------------------------------------------------------------

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

-- ---------------------------------------------------------------------------------------------------------------
-- The objectives (0x110034D5)
-- ---------------------------------------------------------------------------------------------------------------

local function target(unit, type, fn)
  return trigger.special_target{ target = unit, type = type, one_shot = true, on = fn }
end

local function objectives()
  local p = players[PLY]
  local adv = p:buildings("AdvancedLab")
  local rare = p:buildings("RareOreSmelter")[1]
  local std, uni = p:buildings("StandardLab")[1], p:buildings("University")[1]
  local robot = p:buildings("RobotCommand")[1]
  local ccs = p:buildings("CommandCenter")
  for _, b in ipairs({ adv[1], adv[2], std, uni, robot, ccs[1], ccs[2], keep.vf }) do
    if b then b:set_opp_fired_upon(false) end
  end
  local holder_lab, decoy_lab = uni, std
  if keep.sci == 1 then holder_lab, decoy_lab = std, uni end
  local t = target(holder_lab, "EvacuationTransport", gotScientists)
  holder_lab:set_kit("Lynx")                                                    -- the DLL's SetCargo(5, 0)
  mission.victory(t, "Capture Plymouth scientists")
  target(decoy_lab, "EvacuationTransport", gotNothing)
  mission.failure(trigger.count{ type = "EvacuationTransport", compare = "==", count = 0, player = HUMAN },
                  "no Evacuation Transport")
  local rpg_lab, decoy = adv[2], adv[1]
  if keep.rpg == 1 then rpg_lab, decoy = adv[1], adv[2] end
  keep.rpg_lab = rpg_lab                                                        -- 0x1101701C
  mission.victory(target(rpg_lab, "Scout", gotRPG), "Transmit RPG data")
  target(decoy, "Scout", gotNothing)
  mission.victory(target(rare, "Scout", gotRareOre), "Transmit Rare Ore technologies")
  mission.victory(target(keep.vf, "Scout", gotPanther), "Transmit Panther design plans")
  local places = { [0] = robot, ccs[1], ccs[2] }
  keep.codes = places[keep.codes_place]                                         -- 0x11017018
  keep.codes_type = keep.codes and keep.codes.type
  mission.victory(target(keep.codes, "Scout", gotCodes), "Transmit security codes")
  for i = 0, 2 do
    if i ~= keep.codes_place then target(places[i], "Scout", gotNothing) end
  end
  keep.garage1 = make("Garage", PLY, P(0x42, 0x24), 0)                          -- 0x1101700C
  keep.garage2 = make("Garage", PLY, P(0x42, 0x27), 0)                          -- 0x11017010
  keep.garage1:set_opp_fired_upon(false)
  keep.garage2:set_opp_fired_upon(false)
  count_event(PLY, "RareOreSmelter", nil, 1, 3, function() if not state.got.rare then lose() end end)
  count_event(PLY, "RobotCommand", nil, 1, 3,
              function() if not state.got.codes and keep.codes_place == 0 then lose() end end)
  local function cc_lost() if not state.got.codes and not alive(keep.codes, keep.codes_type) then lose() end end
  count_event(PLY, "CommandCenter", nil, 2, 3, cc_lost)
  count_event(PLY, "CommandCenter", nil, 1, 3, cc_lost)
  -- The scientists' two checks, swapped as in the DLL (0x11004204, 0x1100421C).
  count_event(PLY, "StandardLab", nil, 1, 3,
              function() if not state.got.scientists and keep.sci == 0 then lose() end end)
  count_event(PLY, "University", nil, 1, 3,
              function() if not state.got.scientists and keep.sci == 1 then lose() end end)
  local function adv_lost() if not state.got.rpg and not alive(keep.rpg_lab, "AdvancedLab") then lose() end end
  count_event(PLY, "AdvancedLab", nil, 2, 3, adv_lost)
  count_event(PLY, "AdvancedLab", nil, 1, 3, adv_lost)
  count_event(PLY, "VehicleFactory", nil, 1, 3, vf_lost)
  count_event(HUMAN, "Scout", nil, 1, 3, function() if not all_data() then lose() end end)   -- 0x11003D6A
  mission.victory(trigger.count{ type = "Spider", compare = "==", count = 1, player = HUMAN },
                  "Spider prototype must survive")
  mission.failure(trigger.count{ type = "Spider", compare = "==", count = 0, player = HUMAN }, "the Spider prototype lost")
  game.create_marker(P(ENTRY[1], ENTRY[2]), "Circle")
  keep.evac = make("EvacuationTransport", HUMAN, P(0x47, 0x7D), 6)              -- 0x11017014
  keep.evac:set_lights(true)
  condition_event(true, carry_won, function() save_win("all the victory conditions met") end)
end

-- InitProc's part after the carry-over (0x11004475), in its order.
function setup_mission(difficulty)
  state.d = ({ Easy = 0, Normal = 1, Hard = 2 })[difficulty]
  keep.scouts = {}
  ev.leg = {}
  -- The hiding places (0x110045FE): with the hard flag clear, three places for the parts and the Panther, and the
  -- Panther plans in the first Vehicle Factory.
  keep.parts_place = game.rand(3)                                               -- 0x110170A0
  keep.panther_place = game.rand(3)                                             -- 0x110170A4
  keep.rpg = game.rand(2)                                                       -- 0x110170AC
  keep.sci = game.rand(2)                                                       -- 0x110170B4
  keep.codes_place = game.rand(3)                                               -- 0x110170B0
  local y, x
  if keep.parts_place == 0 then
    y = game.rand(3); x = game.rand(3)
    keep.parts_at = P(x + 0x3F, y + 0x2D)
  elseif keep.parts_place == 1 then
    y = game.rand(2); x = game.rand(3)
    keep.parts_at = P(x + 0x41, y + 0x23)
  else
    y = game.rand(2); x = game.rand(3)
    keep.parts_at = P(x + 0x41, y + 0x26)
  end
  keep.parts_tile = game.tile(keep.parts_at)
  make_groups()
  objectives()
  mining()
  patrol()
  for _, u in ipairs(players[HUMAN]:units()) do u:set_lights(false) end        -- 0x110031FD
  repeating(500, 500, repairs)                                                  -- 0x11005213
  once(4200, 4800, assault)
  once(18000, 20000, reinforcements)
  -- The attack when player 1 turns any vehicle's lights on (0x11001112, op2extra's GetLights; 0x11003241). Needs
  -- OP2Lua's unit.lights (0.7.10).
  condition_event(true, function()
    for _, v in ipairs(players[HUMAN]:units()) do
      if v.is_vehicle and v.lights then return true end
    end
  end, function() g.attack:do_attack_enemy() end)
end

function on_tick() run_events() end

-- ---------------------------------------------------------------------------------------------------------------
-- The carry-over from q03 (0x11004267; ../../findings/decompile/q04.md). q03's remake keeps it as q03.carry in
-- OP2Lua's campaign store (the format is in tools/carry/writer.lua). Only player 1's Lynx carry over. Without a
-- file (a mission picked on its own, a core without the store) the start is the stand-in's, as before.
-- ---------------------------------------------------------------------------------------------------------------

local function load_carry_over(name)
  if not campaign then print("This OP2LuaCore has no campaign store: the stand-in start") return nil end
  local data, err = campaign.load(name)
  if not data then print("No " .. name .. ".carry (" .. tostring(err) .. "): the stand-in start") end
  return data
end

-- The Lynx slots (0x11011800), and past them the tables the overflow runs on into: the entry point, Eden's scout
-- waypoints and the patrol route (whose last entry, (-1, -1), is off the map: no Lynx is made there).
local LYNX_SLOTS = { { 0x3F, 0x7B }, { 0x4D, 0x7B }, { 0x41, 0x7B }, { 0x4B, 0x7B }, { 0x3F, 0x7D }, { 0x4D, 0x7D },
                     { 0x41, 0x7D }, { 0x4B, 0x7D }, ENTRY }
for i = 0, 9 do LYNX_SLOTS[#LYNX_SLOTS + 1] = WAYPOINTS[i] end
for _, w in ipairs({ { 0x4C, 0x1A }, { 0x36, 0x0E }, { 0x2F, 0x45 }, { 0x48, 0x67 }, { 0x5A, 0x4B }, { 0x4C, 0x25 } }) do
  LYNX_SLOTS[#LYNX_SLOTS + 1] = w
end

-- The count and the split into eight (0x11004fbb, 0x11004348-0x110043e7), faults included: the first vehicle record
-- isn't counted, and with few Lynx the split runs past the eight slots. Microwave Lynx, then Stickyfoam, facing
-- North, lights off. No Lynx at all fails the original's setup; the remake then makes eight Microwave Lynx, as on
-- Hard from the stand-in.
local function carried_lynx(c)
  local m, s, first = 0, 0, true
  for _, r in ipairs(c.units or {}) do
    if r.vehicle then
      if first then
        first = false
      elseif r.player == HUMAN and r.type == "Lynx" then
        if r.weapon == "Microwave" then m = m + 1 elseif r.weapon == "Stickyfoam" then s = s + 1 end
      end
    end
  end
  local a, b
  local t = (m + s) * 5 // 4
  if t == 0 then
    print("No Lynx in q03.carry: the original can't start; eight Microwave Lynx instead")
    a, b = 8, 0
  else
    a, b = (10 * m + 10) // t, (10 * s + 10) // t
    local spare = m - a
    while b > 4 and spare ~= 0 do a, b, spare = a + 1, b - 1, spare - 1 end
    while a + b < 8 do
      if spare > 0 then a, spare = a + 1, spare - 1 else b = b + 1 end
    end
    while a + b > 8 do
      if spare > 0 then a, spare = a - 1, spare + 1 else b = b - 1 end
    end
  end
  print(("q03.carry: %d Microwave and %d Stickyfoam Lynx; %d Microwave, %d Stickyfoam made"):format(m, s, a,
        math.max(b, 0)))
  local list = {}
  local function add(weapon)
    local slot = LYNX_SLOTS[#list + 1]
    if slot and slot[1] >= 0 then
      list[#list + 1] = { type = "Lynx", weapon = weapon, direction = "North", lights = false,
                          at = { slot[1] - 31, slot[2] + 1 } }
    else
      list[#list + 1] = false
    end
  end
  for _ = 1, a do add("Microwave") end
  for _ = 1, b do add("Stickyfoam") end
  local made = {}
  for _, u in ipairs(list) do if u then made[#made + 1] = u end end
  return made
end

-- A saved game resumed with the script's state: OP2Lua (0.8.8) calls this on the first tick after the load. A save
-- whose state couldn't be put back (another version of this script) doesn't get here; OP2Lua says so itself.
function on_load_save()
  game.message("GAME LOAD SUCCESSFUL", false)
end

function on_init()
  local difficulty = DIFFICULTIES[players[1].difficulty] and players[1].difficulty or "Normal"
  local d = DIFFICULTIES[difficulty]
  print("Difficulty: " .. difficulty)
  -- Player 1's start: the layout's units, then the Lynx (from q03.carry, else the stand-in's).
  local carried = load_carry_over("q03")
  local lynx = d.players[1].units
  if carried then
    lynx = {}
    for _, u in ipairs(d.players[1].units) do if u.type ~= "Lynx" then lynx[#lynx + 1] = u end end
    for _, u in ipairs(carried_lynx(carried)) do lynx[#lynx + 1] = u end
  end
  -- The players first (0x11004475), then the beacons, Player 2's base, Player 1's start and the Lynx from q03.
  for id, p in pairs(d.players) do
    local stats = {}
    for k, v in pairs(p) do if k ~= "units" and k ~= "view" then stats[k] = v end end
    stats.units = {}
    make_player(players[id], stats)
  end
  players[1]:ally_with(4)
  for _, b in ipairs(START_BEACONS) do game.create_beacon(b) end
  for _, u in ipairs(PLY_START) do make_unit(players[u.player], u, u.at, nil, true) end
  for _, u in ipairs(lynx) do make_unit(players[1], u, u.at, nil, true) end
  players[1]:center_view({ 39, 121 })
  game.set_daylight_moves(false)
  game.set_daylight_everywhere(false)
  -- The difficulty check (0x110042e0): q03 played at another difficulty sets the mission's own (not the player's).
  local NAMES = { [0] = "Easy", "Normal", "Hard" }
  local cd = carried and carried.colony and carried.colony.difficulty
  if cd and NAMES[cd] and NAMES[cd] ~= difficulty then
    game.message("You're cheating ! Difficulty reset to " .. ({ [0] = "easy", "medium", "hard" })[cd] .. " :-)")
    difficulty = NAMES[cd]
  end
  setup_mission(difficulty)
end

-- Where this differs from q04.dll, on purpose or for want of an exact match (../../findings/decompile/q04.md):
-- - Renegades' voice lines (its extra.vol's savnt228-234, sounds 178-184) play from ren228.wav-ren234.wav beside
--   the mission through OP2Lua's game.play_wav, not through the game's sound table: OPU 1.4.1 can't load the
--   mod's extra.vol. On a core without game.play_wav the stock sounds play.
-- - The Lynx come from q03.carry, which q03's remake writes when it's won, in place of Q03.mis, split as the DLL
--   does, its overflow included. Without one, from the stand-in carry-over (q03 at tick 5000 in the harness), baked
--   in by op2dll (Easy 10, Normal 16). The "You're cheating!" check is a message; the difficulty flags it sets
--   gate the hard-only parts the remake leaves out (below). An overflow onto the patrol route's end mark (-1, -1)
--   makes no Lynx there.
-- - Hard starts with eight Microwave Lynx on the eight slots: from that carry-over the original can't start at all
--   (no Lynx, findings/CRASH-LEADS.md 10).
-- - The three difficulty flags are clear, as in a fresh game of the original (they're only set by its "You're
--   cheating!" branch), so the hard-only parts (second Vehicle Factory, fourth hiding place) are left out.
-- - Needs OP2Lua 0.7.10 or later: unit.lights, unit:set_emp and unit:set_offensive (op2extra's GetLights,
--   SetEMPticks and SetOffensive). The Panther's EMP lasts 65,535 ticks, the longest the game's timer holds.
-- - "Panther taken" (0x11003D79) makes an empty unit slot non-offensive; that does nothing, so it's left out.
-- - The Evacuation Transport's and the scientists' lab's "cargo 5" is set as a kit (map id 5, a "Lynx").
-- - The escorts' "combat units" count (ScGroup::UnitCount(0)) is the group's unit count.
-- - Each unit is kept in one group (findings/CRASH-LEADS.md 11).
-- - Messages go to the message list.
