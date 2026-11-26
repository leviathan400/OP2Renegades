# Decompile findings

What the decompiled DLLs show, written in our own words: what each part does, the data it keeps and the addresses
involved. The raw Ghidra output these come from is in `../../decompile/<dll>/`, and the remakes don't copy from it.

| File | What |
|---|---|
| `q01.md` | Relocation: the goal by difficulty, Eden's groups, the timetable and every event, with addresses. Measured against a Lua remake in the game. |
| `q02.md` | q02: the carry-over from `Q01.mis`, the evacuation objectives, Eden's AI and every event. No failure condition: q02 can't be lost. |
| `q03.md` | q03: the carry-over from `Q02.mis`, the kit and evacuation objectives, the defectors and `SetOffensive`, the inverted carry-over write. |
| `q04.md` | q04: the carry-over from `Q03.mis`, the convoy and the Spider prototype, the callback objectives, `SetEMPticks`. Its difficulty flags are only set by the "You're cheating!" branch. |
| `mission-framework.md` | What all four missions share: entry points, the event system, the save section and its pool, music, the menu and difficulty checks. |
| `op2extra.md` | `op2extra.dll`'s `IUnit`, all 30 exports: which game command each sends, which unit fields it reads or writes, and which mission calls it where. |
| `op2mod-renshell.md` | The op2ext mod: its 23 patches to the game (the shell's name, the `Q`, the `.REN` extensions) and the `.vol` files. |
| `renshell.md` | The Renegades menu: the stock `OP2Shell.dll` with few changes; how a campaign starts and continues, the difficulty, and its leads (a "Mission 5" after q04). |
| `../CRASH-LEADS.md` | Places in the DLLs that can crash the game, from this work. |

## How the decompile was made

`../../tools/ghidra/decompile.ps1` runs Ghidra 12.2 headless (with JDK 25) and `ExportAnalysis.java` over the seven
DLLs. Each DLL gets:
- `decompiled.c`: every function's C, headed by address, name and callers;
- `disassembly.txt`: every instruction, each function headed by its name;
- `functions.tsv`, `strings.tsv`, `imports.tsv` and `exports.tsv`.

Code addresses the missions pass as values, their event callbacks, are made into functions before the export, so
they're decompiled too (q01 23, q02 30, q03 54, q04 38).

| DLL | Functions | Decompiled |
|---|---|---|
| q01 | 358 | 336 |
| q02 | 510 | 485 |
| q03 | 544 | 514 |
| q04 | 442 | 413 |
| op2extra | 111 | 110 |
| op2mod | 68 | 67 |
| renshell | 217 | 214 |

The rest are imports and thunks. No function failed to decompile. Ghidra names the game API calls (`TethysGame::`,
`Unit::`, `TethysGame::CreateUnit` and so on) from the mangled imports. Mission functions without an export are
`FUN_<address>`.
