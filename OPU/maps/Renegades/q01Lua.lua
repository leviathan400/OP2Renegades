-- q01Lua.lua  -  Outpost : Renegades - Relocation (Lua) v1.2.8
-- Converted from q01.dll. With q01Lua.placement.lua (what every difficulty makes alike),
-- this makes the colony's start: what changes with the difficulty, and the beacons the setup rolls.
-- The objectives, Eden's AI and the mission's events (below the converted part) are written by hand.
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
        workers = 28, scientists = 5, kids = 0, food = 2500, ore = 1800, rare_ore = 0,
        research = { 2114, 3201, 3408 },
        tech_level = 3,
        kits = { [1] = { "Residence" }, [2] = { "Agridome" }, [3] = { "GuardPost", "Microwave" }, [4] = { "GuardPost", "Microwave" }, [5] = { "GuardPost", "Microwave" }, [6] = { "GuardPost", "Microwave" } },
        view = { 17, 28 },
        units = {
        },
      },
      [2] = {
        workers = 0, scientists = 0, kids = 0, food = 0, ore = 0, rare_ore = 0,
        research = {  },
        tech_level = 12,
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
        workers = 25, scientists = 5, kids = 0, food = 2000, ore = 1200, rare_ore = 0,
        research = { 2114, 3201, 3408 },
        tech_level = 3,
        kits = { [3] = { "GuardPost", "Microwave" }, [4] = { "GuardPost", "Microwave" }, [5] = { "GuardPost", "Microwave" }, [6] = { "GuardPost", "Microwave" } },
        view = { 17, 28 },
        units = {
        },
      },
      [2] = {
        workers = 0, scientists = 0, kids = 0, food = 0, ore = 0, rare_ore = 0,
        research = {  },
        tech_level = 12,
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
        workers = 20, scientists = 5, kids = 0, food = 1000, ore = 600, rare_ore = 0,
        research = { 2114, 3201, 3408 },
        tech_level = 3,
        kits = { [5] = { "GuardPost", "Microwave" }, [6] = { "GuardPost", "Microwave" } },
        view = { 17, 28 },
        units = {
        },
      },
      [2] = {
        workers = 0, scientists = 0, kids = 0, food = 0, ore = 0, rare_ore = 0,
        research = {  },
        tech_level = 12,
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

local function make_unit(player, u, at, kits, exact)
  local made = game.create_unit{ type = u.type, player = player, at = at, direction = u.direction,
                                 weapon = u.weapon, lights = u.lights, exact = exact }
  if u.cargo and made[1] then made[1]:set_cargo(u.cargo, u.amount) end
  if u.type == "StructureFactory" and kits and made[1] then
    for bay, kit in pairs(kits) do made[1]:set_factory_cargo(bay, kit[1], kit[2]) end
  end
end

-- One player's start at the chosen difficulty.
function make_player(player, p)
  if p.tech_level then player:set_tech_level(p.tech_level) end
  for _, tech in ipairs(p.research) do player:mark_research(tech) end
  player.workers, player.scientists, player.kids = p.workers, p.scientists, p.kids
  player.food, player.ore, player.rare_ore = p.food, p.ore, p.rare_ore
  for _, u in ipairs(p.units) do make_unit(player, u, u.at, p.kits, true) end
  for _, u in ipairs(p.rolled or {}) do
    local a = u.area
    make_unit(player, u, { a[1] + game.rand(a[3] - a[1] + 1), a[2] + game.rand(a[4] - a[2] + 1) }, p.kits, true)
  end
  local start = p.starts and p.starts[game.rand(#p.starts) + 1]
  local s = p.start_area
  if s then start = { s[1] + game.rand(s[3] - s[1] + 1), s[2] + game.rand(s[4] - s[2] + 1) } end
  local function place(t) return start and { start[1] + t[1], start[2] + t[2] } or t end
  -- The original asks for every unit of a kit on one tile; the game finds each a place nearby.
  for _, u in ipairs(p.kit or {}) do make_unit(player, u, place(u.at), p.kits, false) end
  -- The player's Structure Factory is the placement's; its bays are the difficulty's.
  if p.kits then
    local f = player:buildings("StructureFactory")[1]
    if f then
      for bay, kit in pairs(p.kits) do f:set_factory_cargo(bay, kit[1], kit[2]) end
    end
  end
  if p.view then player:center_view(place(p.view)) end
end

function make_things(d)
  for _, w in ipairs(d.walls) do
    if w[1] == "Tube" then game.create_tube(w[2]) else game.create_wall(w[1], w[2]) end
  end
  for _, b in ipairs(d.beacons) do game.create_beacon(b) end
end

local function copy(t)
  local c = {}
  for k, v in pairs(t) do c[k] = v end
  return c
end

function roll_beacons(rolled)
  for _, r in ipairs(rolled) do
    if r.spots then
      local spots = {}
      for i, s in ipairs(r.spots) do spots[i] = s end
      for i = 1, r.count do
        local b = copy(r.kinds[i])
        b.at = table.remove(spots, game.rand(#spots) + 1)
        game.create_beacon(b)
      end
    elseif r.area then
      local a, b = r.area, copy(r)
      b.area = nil
      b.at = { a[1] + game.rand(a[3] - a[1] + 1), a[2] + game.rand(a[4] - a[2] + 1) }
      game.create_beacon(b)
    else
      game.create_beacon(r.ways[game.rand(#r.ways) + 1])
    end
  end
end

-- ---------------------------------------------------------------------------------------------------------------
-- The mission itself, written by hand from q01.dll (Renegades' own event list, ../../findings/decompile/q01.md).
-- The DLL's numbers are kept as it has them: P() and RECT() turn its internal tiles (x + 32 on this 128-wide map)
-- into status-bar ones, so each line can be checked against the address it came from.
-- ---------------------------------------------------------------------------------------------------------------

local function P(x, y) return { x - 31, y + 1 } end
local function RECT(x1, y1, x2, y2) return { x1 - 31, y1 + 1, x2 - 31, y2 + 1 } end
local DIRS = { [0] = "East", "SouthEast", "South", "SouthWest", "West", "NorthWest", "North", "NorthEast" }

local HUMAN, EDEN = 1, 2
local START = { 0x30, 0x1B }                 -- the Command Center's tile; reinforcements head for START - (4, -4)

-- What each difficulty asks for and gives (InitProc 0x11002D9F). `fail_*`: the mission is lost below these.
local GOALS = {
  Easy   = { food = 2000, ore = 4000, colonists = 15, scientists = 2, fail_colonists = 12, fail_scientists = 2,
             scouts = { 4000, 5000 }, base_at = 5000, first_wave = { 6000, 8000 }, second_wave = { 10000, 13000 } },
  Normal = { food = 2500, ore = 5000, colonists = 16, scientists = 2, fail_colonists = 16, fail_scientists = 2,
             scouts = { 3000, 4000 }, base_at = 5000, first_wave = { 5000, 7000 }, second_wave = { 9000, 11000 } },
  Hard   = { food = 3000, ore = 6000, colonists = 18, scientists = 3, fail_colonists = 18, fail_scientists = 3,
             scouts = { 2000, 4000 }, base_at = 4000, first_wave = { 5000, 7000 }, second_wave = { 8000, 10000 } },
}

-- The DLL's events (mission-framework.md): a time event is due `min` + GetRand(max - min) ticks after it's made, and
-- a repeating one is due that long again after each run. The draws come in the order the DLL makes its events.
local function delay(min, max) return min + (max > min and game.rand(max - min) or 0) end

local function once(min, max, fn)
  at(game.tick() + delay(min, max), fn)
end

local function repeating(min, max, fn)
  local due = game.tick() + delay(min, max)
  local function run()
    fn()
    due = due + delay(min, max)
    at(due, run)
  end
  at(due, run)
end

-- A group-loss event (0x11004410): `fn` once the group is down to a share of the units it has now. Mode 1: none
-- left, 2: three quarters left, 3: half left.
local function on_losses(group, mode, fn)
  local n = group:unit_count()
  local left = mode == 2 and (n * 3) // 4 or mode == 3 and n // 2 or 0
  when(function() return group:unit_count() <= left end, fn)
end

local function make(type, player, at, direction, weapon)
  return game.create_unit{ type = type, player = player, at = at, direction = DIRS[direction or 0],
                           weapon = weapon, exact = true }[1]
end

local state = {
  difficulty = 0,         -- 0 Easy, 1 Normal, 2 Hard
  reinforcements = 2,     -- 0x11012050: Plymouth reinforcement waves left
  wave_size = 0,          -- 0x11012044: Lynx in Eden's next attack wave
  base_started = false,   -- 0x11012057
  first_wave_sent = false, second_wave_sent = false,
}
local g = {}              -- Eden's groups, named after what they do

-- Plymouth reinforcements (0x1100246e): three Microwave Lynx from the south-west corner.
local function reinforce()
  local last
  for _ = 1, 3 do
    last = make("Lynx", HUMAN, P(0x21, 0x3C), 0, "Microwave")
    last:move(P(START[1] - 4, START[2] + 4))
    last:set_lights(true)
  end
  game.message(state.reinforcements < 2 and "No more reinforcements available !" or "Reinforcements have arrived",
               0xA2)
end

-- Extra Cargo Trucks (0x11001cfd): three on Easy, two otherwise.
local function extra_trucks()
  local n = state.difficulty == 0 and 3 or 2
  for _ = 1, n do
    local t = make("CargoTruck", HUMAN, P(0x21, 0x3C), 0)
    t:move(P(START[1] - 4, START[2] + 4))
    t:set_lights(true)
  end
  game.message(n .. " extra cargo trucks have arrived", 0xA2)
end

-- Eden's scouts (0x11001b5c): three, each patrolling its own route.
local ROUTES = {
  { { 0x78, 0x0E }, { 0x60, 0x06 }, { 0x7D, 0x24 }, { 0x8E, 0x29 }, { 0x8E, 0x0F } },                          -- 0x110103f0
  { { 0x88, 0x2F }, { 0x5B, 0x37 }, { 0x54, 0x17 }, { 0x8D, 0x0E } },                                          -- 0x11010420
  { { 0x8A, 0x18 }, { 0x5A, 0x3A }, { 0x22, 0x3C }, { 0x31, 0x1A }, { 0x32, 0x08 }, { 0x55, 0x17 }, { 0x85, 0x0A } }, -- 0x110103b0
}
local function route(points)
  local r = {}
  for i, p in ipairs(points) do r[i] = P(p[1], p[2]) end
  return r
end

local function send_scouts()
  local starts = { { 2, 4 }, { 4, 3 }, { 6, 3 } }            -- y and direction of each scout at x 0x9E
  for i, s in ipairs(starts) do
    local group = ai.fight_group(EDEN)
    group:set_patrol(route(ROUTES[i]))
    group:take_unit(make("Scout", EDEN, P(0x9E, s[1]), s[2]))
  end
end

-- Lynx for the group near the Tokamak (0x110024f0): one, two above Easy.
local function tokamak_guard()
  g.tokamak_guard:take_unit(make("Lynx", EDEN, P(0x9E, 3), 0, "Laser"))
  if state.difficulty ~= 0 then g.tokamak_guard:take_unit(make("Lynx", EDEN, P(0x9E, 3), 0, "Laser")) end
end

-- Eden's first force (0x110026c1), at its time or when the player comes near Eden's base, whichever is first.
local function first_wave()
  if state.first_wave_sent then return end
  state.first_wave_sent = true
  for _ = 1, state.difficulty + 2 do g.patrol_north:take_unit(make("Lynx", EDEN, P(0x9E, 2), 3, "Laser")) end
  if state.difficulty ~= 0 then
    for _ = 1, state.difficulty + 1 do g.base_guard:take_unit(make("Lynx", EDEN, P(0x9E, 5), 3, "Laser")) end
  end
  tokamak_guard()
end

local next_wave

-- An attack wave has been beaten (0x110028d5): the next comes, bigger, and Plymouth may send help.
local function wave_beaten()
  once(2000, 4000, next_wave)
  state.reinforcements = state.reinforcements - 1
  if state.reinforcements > 0 then once(1000, 2000, reinforce) end
  state.wave_size = math.min(state.wave_size + 1, state.difficulty * 2 + 5)
end

-- The next attack wave (0x11002841), facing every which way, sent at the player.
next_wave = function()
  for _ = 1, state.wave_size do
    g.attack:take_unit(make("Lynx", EDEN, P(0x9C, 4), game.rand(8), "Laser"))
  end
  on_losses(g.attack, 2, wave_beaten)
end

-- Eden's second force (0x11002768): a patrol, and above Easy the first attack.
local function second_wave()
  if state.second_wave_sent then return end
  state.second_wave_sent = true
  g.patrol_west:take_unit(make("Lynx", EDEN, P(0x9E, 2), 3, "Laser"))
  g.patrol_west:take_unit(make("Lynx", EDEN, P(0x9E, 4), 3, "Laser"))
  if state.difficulty ~= 0 then
    g.attack:take_unit(make("Lynx", EDEN, P(0x9E, 4), 4, "Laser"))
    g.attack:take_unit(make("Lynx", EDEN, P(0x9E, 6), 4, "Laser"))
  end
  on_losses(g.attack, 1, wave_beaten)
end

-- The raiders aimed at the player's Tokamak (0x1100257a, every 3200 ticks): they wait beside it, or attack
-- anything when there is none. Between ticks 9500 and 13500 of every 16000, the Tokamak guards south of row 0x22
-- join them, up to four, and new guards come (0x1100255c); on Hard, again once a quarter of the raiders are lost.
local refill_guards
local function aim_raiders()
  local tokamak = players[HUMAN]:buildings("Tokamak")[1]
  if tokamak then
    g.raiders:clear_guarded_rects()
    g.raiders:set_rect({ tokamak.x - 3, tokamak.y - 3, tokamak.x + 3, tokamak.y + 3 })
  else
    g.raiders:do_attack_enemy()
  end
  local t = game.tick() % 16000
  if t > 9500 and t < 13500 then
    for _, u in ipairs(g.tokamak_guard:units()) do
      if g.raiders:unit_count() == 4 then break end
      if u.y - 1 > 0x22 then
        g.tokamak_guard:remove_unit(u)
        g.raiders:take_unit(u)
      end
    end
    if state.difficulty == 2 then on_losses(g.raiders, 2, refill_guards) end
    refill_guards()
  end
end

refill_guards = function() once(500, 1000, tokamak_guard) end

-- Eden's base builders (0x11001f2a). The first time: a ConVec, an Earthworker and a RoboMiner come in, and the
-- building group is told what to keep standing. Every time: its lost vehicles are replaced (0x11001de7), and its
-- Tokamak is kept repaired.
local builders = {}
local tokamak_watch = false

local function replace_lost_builders()
  for _, b in ipairs(builders) do
    if not b.unit.alive then
      b.unit = make(b.type, EDEN, P(0x9E, 5), 4)
      g.base:take_unit(b.unit)
    end
  end
end

local repairer
local function repair_tokamak()                              -- 0x11001e91, every 500 ticks
  local tokamak = g.eden_tokamak
  if not (tokamak and tokamak.alive) then return end
  if tokamak.max_hp - tokamak.hp >= 201 then
    if not (repairer and repairer.alive) then
      repairer = make("ConVec", EDEN, P(0x9F, 0x3A), 4)
      g.repair:take_unit(repairer)
    end
    repairer:repair(tokamak)
  end
  if tokamak.hp == tokamak.max_hp and repairer and repairer.alive then g.repair:do_exit_map() end
end

-- 0x1100163e: a straight run of tubes from one end to the other, or, when both ends differ, an L: along x, then
-- along y from the corner (which is recorded twice, as the DLL does).
local function record_tube_line(x1, y1, x2, y2)
  if x1 ~= x2 and y1 ~= y2 then
    record_tube_line(x1, y1, x2, y1)
    record_tube_line(x2, y1, x2, y2)
    return
  end
  local dx = x2 > x1 and 1 or x2 < x1 and -1 or 0
  local dy = y2 > y1 and 1 or y2 < y1 and -1 or 0
  local x, y = x1, y1
  g.base:record_tube(P(x, y))
  while x ~= x2 or y ~= y2 do
    x, y = x + dx, y + dy
    g.base:record_tube(P(x, y))
  end
end

local function build_base()
  if not state.base_started then
    state.base_started = true
    builders = {
      { type = "ConVec", unit = make("ConVec", EDEN, P(0x9E, 5), 4) },
      { type = "Earthworker", unit = make("Earthworker", EDEN, P(0x9E, 5), 2) },
      { type = "RoboMiner", unit = make("RoboMiner", EDEN, P(0x9E, 5), 4) },
    }
    g.base = ai.building_group(EDEN)
    g.base:set_rect(RECT(0x94, 6, 0x9A, 8))
    g.base:record_building(P(0x91, 0x1D), "CommonOreMine")
    for _, at in ipairs({ { 0x89, 6 }, { 0x8E, 0x10 }, { 0x8F, 0x19 } }) do
      g.base:record_building(P(at[1], at[2]), "GuardPost", "Laser")
    end
    g.base:record_building(P(0x9B, 5), "CommonStorage")
    for _, at in ipairs({ { 0x8E, 0x22 }, { 0x8A, 0x10 }, { 0x93, 6 } }) do
      g.base:record_building(P(at[1], at[2]), "GuardPost", "Laser")
    end
    g.base:record_building(P(0x8A, 2), "Tokamak")
    record_tube_line(0x8F, 7, 0x89, 7)
    record_tube_line(0x8D, 8, 0x8D, 0x10)
    record_tube_line(0x8C, 0x10, 0x8B, 0x18)
    record_tube_line(0x8C, 0x18, 0x8F, 0x18)
    record_tube_line(0x8E, 0x19, 0x8E, 0x21)
    record_tube_line(0x8F, 7, 0x93, 6)
    for _, b in ipairs(builders) do g.base:take_unit(b.unit) end
    local factory = players[EDEN]:buildings("StructureFactory")[1]
    if factory then g.base:take_unit(factory) end
    g.robominer = builders[3]
    repeating(1200, 1200, replace_lost_builders)
  else
    replace_lost_builders()
  end
  g.eden_tokamak = players[EDEN]:buildings("Tokamak")[1]
  if not tokamak_watch then                                 -- the DLL adds another 500-tick watch on every call
    tokamak_watch = true
    repeating(500, 500, repair_tokamak)
  end
end

-- Eden's mining (0x110022e9): once it has a mine and a smelter, its Cargo Trucks run ore between them and are kept
-- at three or more (0x11002254). When the mine is gone a RoboMiner is sent for a new one (0x11002412).
local start_mining
local function keep_trucks()
  local alive = 0
  for _, u in ipairs(g.mining:units()) do if u.alive then alive = alive + 1 end end
  if alive <= 2 then g.mining:take_unit(make("CargoTruck", EDEN, P(0x9E, 4), 4)) end
end

local function mine_lost()
  if state.base_started then
    g.robominer = { type = "RoboMiner", unit = make("RoboMiner", EDEN, P(0x9E, 5), 4) }
    builders[3] = g.robominer
    g.base:take_unit(g.robominer.unit)
  end
  when(function() return players[EDEN]:unit_count("CommonOreMine") == 1 end, start_mining)
  build_base()
end

start_mining = function()
  local mine = players[EDEN]:buildings("CommonOreMine")[1]
  local smelter = players[EDEN]:buildings("CommonOreSmelter")[1]
  if not (mine and smelter) then
    once(500, 500, start_mining)
    return
  end
  g.mining:setup(mine, smelter, RECT(0x8D, 5, 0x93, 9))
  for _, u in ipairs(players[EDEN]:units("CargoTruck")) do g.mining:take_unit(u) end
  repeating(500, 500, keep_trucks)
  when(function() return players[EDEN]:unit_count("CommonOreMine") == 0 end, mine_lost)
  if g.base and g.robominer then g.base:remove_unit(g.robominer.unit) end
end

-- Disasters: earthquakes all over (0x11002965), more near the middle above Easy (0x1100293c), and meteors that
-- miss the player's start (0x1100298c).
local function quake_anywhere()
  local y = game.rand(0x3E)
  local x = game.rand(100)
  game.create_earthquake(P(x + 0x20, y + 1), 1)
end

local function quake_middle()
  local y = game.rand(0x1E)
  local x = game.rand(0x1E)
  game.create_earthquake(P(x + 0x40, y + 8), 1)
end

local function meteor()
  local x, y
  repeat
    x, y = game.rand(0x6E), game.rand(0x40)
  until not (x >= 0x0D and x <= 0x19 and y >= 0x15 and y <= 0x1E)
  game.create_meteor(P(x + 0x1F, y - 1), 1)
end

local function make_eden_groups()                           -- 0x110029f1
  g.patrol_north = ai.fight_group(EDEN)
  g.patrol_north:set_rect(RECT(0x8B, 4, 0x98, 0x16))
  g.patrol_north:set_patrol(route({ { 0x8B, 2 }, { 0x8D, 0x21 }, { 0x95, 7 } }))
  g.patrol_north:set_lights(true)
  g.patrol_west = ai.fight_group(EDEN)
  g.patrol_west:set_rect(RECT(0x8B, 4, 0x98, 0x16))
  g.patrol_west:set_patrol(route({ { 0x88, 0x0E }, { 0x57, 0x17 }, { 0x30, 9 }, { 0x28, 0x30 }, { 0x2E, 0x2C },
                                   { 0x8A, 0x30 } }))
  g.patrol_west:set_lights(true)
  g.base_guard = ai.fight_group(EDEN)
  g.base_guard:set_rect(RECT(0x8B, 3, 0x9C, 0x0A))
  g.base_guard:do_guard_rect()
  g.base_guard:set_lights(true)
  g.attack = ai.fight_group(EDEN)
  g.attack:set_rect(RECT(0x2D, 0x15, 0x36, 0x1C))             -- beside the player's start
  g.attack:do_attack_enemy()
  g.attack:set_lights(true)
  g.tokamak_guard = ai.fight_group(EDEN)
  g.tokamak_guard:set_rect(RECT(0x88, 0x26, 0x8E, 0x2A))
  g.tokamak_guard:set_lights(true)
  g.raiders = ai.fight_group(EDEN)
  g.raiders:set_rect(RECT(0x2B, 0x2C, 0x2D, 0x2E))
  g.raiders:set_lights(false)
  g.mining = ai.mining_group(EDEN)
  g.repair = ai.fight_group(EDEN)
  g.repair:set_rect(RECT(0x9B, 0x32, 0x9F, 0x35))
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
  if result and result.result == "won" then save_carry_over("q01", state.difficulty, "the game reports the win") end
end

-- One of the player's units in the rectangle (an area event, 0x110044d0).
local function player_in(r)
  return function()
    for _, u in ipairs(game.units_in_rect(r)) do if u.owner == HUMAN - 1 then return true end end
    return false
  end
end

function on_init()
  game.message("Renegades v" .. VERSION, false)
  local difficulty = DIFFICULTIES[players[1].difficulty] and players[1].difficulty or "Normal"
  local d = DIFFICULTIES[difficulty]
  local goals = GOALS[difficulty]
  state.difficulty = ({ Easy = 0, Normal = 1, Hard = 2 })[difficulty]
  state.wave_size = state.difficulty == 0 and 0 or 1
  print("Difficulty: " .. difficulty)
  -- The bottom row, and one tile by Eden's base, can't be crossed (0x1100137f, 0x11002EE1). Older OP2LuaCore
  -- builds have no set_cell_type.
  if game.set_cell_type then
    for x = 1, 127 do game.set_cell_type({ x, 64 }, 6) end
    game.set_cell_type(P(0x96, 9), 6)
  else
    print("set_cell_type isn't in this OP2LuaCore: the bottom row stays passable")
  end
  make_things(d)
  roll_beacons(BEACONS.rolled)
  for id, p in pairs(d.players) do make_player(players[id], p) end
  game.set_daylight_everywhere(false)
  game.set_daylight_moves(true)
  game.free_morale()
  make_eden_groups()

  -- Relocation: the base packed into kits, ready to move.
  mission.victory(trigger.kit{type = "CommonOreSmelter", count = 1, player = HUMAN}, "Have a Common Ore Smelter kit in storage")
  mission.victory(trigger.kit{type = "StructureFactory", count = 1, player = HUMAN}, "Have a Structure Factory kit in storage")
  mission.victory(trigger.kit{type = "CommandCenter", count = 1, player = HUMAN}, "Have a Command Center kit in storage")
  mission.victory(trigger.kit{type = "Tokamak", count = 1, player = HUMAN}, "Have a Tokamak kit in storage")
  mission.failure(trigger.resource{resource = "Colonists", compare = "<", amount = goals.fail_colonists, player = HUMAN})
  mission.failure(trigger.resource{resource = "Scientists", compare = "<", amount = goals.fail_scientists, player = HUMAN})

  -- Eden's timetable, in the order the DLL makes it (each draw from the game's random numbers in turn).
  once(goals.scouts[1], goals.scouts[2], send_scouts)
  once(goals.base_at, goals.base_at, build_base)
  once(7500, 7500, reinforce)
  once(goals.first_wave[1], goals.first_wave[2], first_wave)
  once(goals.second_wave[1], goals.second_wave[2], second_wave)
  once(10000, 10000, reinforce)
  if state.difficulty == 0 then
    once(4000, 8000, meteor)
  else
    repeating(4000, 8000, meteor)
    repeating(2500, 5500, quake_middle)
  end

  mission.victory(trigger.resource{resource = "Food", compare = ">=", amount = goals.food, player = HUMAN},
                  "Store " .. goals.food .. " units of food")
  mission.victory(trigger.resource{resource = "CommonOre", compare = ">=", amount = goals.ore, player = HUMAN},
                  "Collect " .. goals.ore .. " units of Common Metals")
  mission.victory(trigger.resource{resource = "Colonists", compare = ">=", amount = goals.colonists, player = HUMAN},
                  "Have at least " .. goals.colonists .. " total colonists surviving")
  mission.victory(trigger.resource{resource = "Scientists", compare = ">=", amount = goals.scientists, player = HUMAN},
                  "Have at least " .. goals.scientists .. " scientists surviving")
  -- The carry-over for q02, once every victory condition has been met.
  when(carry_won, function() save_carry_over("q01", state.difficulty, "all the victory conditions met") end)

  -- Coming near Eden's base brings its forces out early.
  when(player_in(RECT(0x87, 1, 0x87 + 0x18, 1 + 0x20)), first_wave)
  when(player_in(RECT(0x8A, 1, 0x8A + 0x18, 1 + 0x0A)), second_wave)
  mission.failure(trigger.operational{type = "CommandCenter", compare = "==", count = 0, player = HUMAN})

  -- What follows from the mines on both sides. Eden's mine (P(0x91, 0x1D)) is made by the placement.
  when(function() return players[EDEN]:unit_count("CommonOreMine") == 0 end, build_base)
  local truck_delay = state.difficulty * 1000
  when(function() return players[HUMAN]:unit_count("CommonOreMine") == 1 end,
       function() once(truck_delay + 2500, truck_delay + 2500, extra_trucks) end)
  when(function() return players[HUMAN]:unit_count("CargoTruck") == 0 end,
       function() once(truck_delay + 500, truck_delay + 500, extra_trucks) end)
  start_mining()
  repeating(3000, 7000, quake_anywhere)
  repeating(3200, 3200, aim_raiders)
end

-- Where this differs from q01.dll, on purpose or for want of an exact match (../../findings/decompile/q01.md):
-- - Measured against the DLL in the game (q01.md): Eden's units match it tile for tile until tick 8,400 on Easy
--   and 15,900 on Normal, and to the end on Hard. On Easy, Eden's Earthworker then starts on another tube tile;
--   why is open.
-- - One Tokamak repair watch, where the DLL adds another each time its base builder runs.
-- - "Common Metals" in the ore objective; the DLL says "Commom".
-- - The repair ConVec carries nothing; the DLL makes it with 0x40 as its cargo.
-- - The DLL's flag at 0x1101205a, which would rebuild Eden's base after a wave, is never set, so that's left out.
