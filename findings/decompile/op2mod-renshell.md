# op2mod.dll and renshell.dll

## op2mod.dll (in `modren/`)

A mod for op2ext (the 2006 community extension), base `0x1F000000`, 68 functions, almost all C runtime.
- **`mod_init` patches the game first.** It copies a table of 23 patches into the exe's memory (`0x1F005050`-
  `0x1F005163`; each is the game address, the source bytes, a length). Most write `REN` over `OP2` in the exe's
  strings. Among them:
  - `OP2Shell.dll` → `RENShell.dll`, which is how the Renegades menu gets loaded;
  - `out2res` → `REN2res`;
  - the ini and saved-game extensions → `.REN`;
  - `P` → `Q` at `0x4E971C`, the campaign DLL name format `Q%02d.DLL` the missions check for.

  The full list is in `renshell.md`.
- **Then the archives.** It adds `ren.vol`, `extra.vol` and `ren1.vol` to the game's list, in that order, with
  op2ext's `AddVolToList`.
- **`mod_run` and `mod_destroy`** share one address, and do nothing.

Checked by reading the table from the DLL (2026-11-17): 23 entries, the first ones `REN` at `0x4E96A0`, `0x4E96C0`
and `0x4E061C`, and `Q` at `0x4E971C`.

## renshell.dll (the Renegades menu)

See `renshell.md`. It's the game's own `OP2Shell.dll` with a few changes:
- **Same layout.** It has the same five sections, at the same addresses and sizes, as OPU 1.3.6's shell, and the same
  relocations.
- **Few changes.** Outside the import table, the two differ in 44 short runs, 221 bytes in all (checked 2026-11-17).

The shell doesn't write the `Q` (op2mod does), and keeps no difficulty file of its own. The missions' 0x20-byte
difficulty block is the previous mission's `Q0N.mis` header.
