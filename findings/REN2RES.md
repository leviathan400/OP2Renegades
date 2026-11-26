# ren2res.dll against the game's out2res.dll

`modren/ren2res.dll` is Renegades' copy of `out2res.dll`, the game's in-game resources (the stock name `out2res.dll`
at `0x4E96C0` is patched to `REN2res.dll` by `op2mod.dll`, `decompile/renshell.md`). This compares its resources with
the stock ones, to know what a Renegades build of the file needs to change.

**How:** `tools/bmpcompare.py` decodes each bitmap of both to RGB and compares the pixels, so differences in how the
files were written don't count:
- **Stock:** `SVN/opu/op2skin/odasl/out2res_bmp/` (the game's `out2res.dll` bitmaps);
- **Renegades:** `decompile/ren2res/resources/` (`tools/resextract.py` on `install/modren/ren2res.dll`).

The dialogs and icons were compared with `resextract.py`'s text dumps against OPU 1.4.1's `out2res.dll`.
Side-by-side pictures of each change are in `ren2res-compare/<id>.png`: stock left, Renegades middle, the changed
pixels in red on the right. The full table is `ren2res-compare/compare.tsv`.

## What Renegades changes

Of the 36 bitmaps, **29 are identical in pixels**. A byte-for-byte check flags more (188, 192, 207, 242, 251, 255,
264, 265), but those differ only in how the file is written, not in what they show.

| Resource | Stock | Renegades |
|---|---|---|
| Bitmaps **179, 181** | "OUTPOST 2", 95 × 16 (179 grey, 181 green) | "OP: RENEGADES", 140 × 16: the logo in the game window's top bar, grey and green |
| Bitmaps **252, 254** | 260 × 22 frames with red edges | the same frames with blue edges |
| Bitmaps **257, 258** | 101 × 22 frames with red edges | the same with light blue edges |
| Bitmap **259** | "OUTPOST 2 DIVIDED DESTINY - LOADING -", 320 × 116 | the same art, scorched and worn, the "O" of LOADING blown out |
| Dialog **100** | the in-game About box: "Copyright (c) 1996, 1997, Dynamix Inc." | the same, moved up 5 units, and a second line "Renegades (c) 2004, 2005 Eddy-B" |
| Icon **1** (added) | none | `ren.ico`, the Renegades icon |

Nothing else in the file is changed, and nothing is missing: every stock resource is still there. So the in-game
blue look is four frames (252, 254, 257, 258) and the title logo; the rest of the game's UI is stock. The menus'
blue is `renshres.dll`'s (`decompile/renshell.md`, "The blue look" on the website). The R in the command pane isn't
here either: each mission swaps it in from `renegmbl.raw` (`DLLS.md`).

Where the game draws 252-258 isn't checked: the 260 × 22 and 101 × 22 sizes suggest the in-game panels' buttons and
bars. A run with each swapped in, one at a time, would show it.

## For the remakes (done, 2026-11-18)

- **Renegades' own `ren2res.dll` is used as it is.** Both it and `out2res.dll` are resource-only (no code, no entry
  point, no imports), and every stock resource in it shows the same as OPU's 2025 file. The same art built on OPU's
  file is kept as `../module/ren2res-opu2025.dll` (`../tools/make_ren2res.py`).
- **`../module/Renegades.dll`**, an op2ext module, loads it for a Renegades launch only, without touching
  `out2res.dll` on disk: it changes the name at `0x4E96C0` in memory before `TApp::Init` loads the file. Working in the
  user's game: the "OP: RENEGADES" title and, from `renegmbl.raw`, the R in the command pane
  (`../module/README.md`, with what was found getting there).
