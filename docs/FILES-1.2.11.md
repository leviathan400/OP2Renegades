# Renegades 1.2.11: files and hashes

Every file in the release zip, `Outpost2-Renegades-1.2.11.zip`, with its size and SHA-256, so a copy can be checked
against the release.

| Zip | Size | SHA-256 |
|---|---:|---|
| `Outpost2-Renegades-1.2.11.zip` | 12,660,082 | `c53f7df601735efec2a7a2ac7d02f1148a2f28c3d56472e8254db8e23feb9e70` |

The zip holds 43 files (28,037,183 bytes) and one empty folder, `OPU/logs/`, where OP2Lua writes the missions'
logs. It unzips into the Outpost 2 folder. It has **no `outpost2.ini`** and **no `Renegades.ini`**: the game's own
settings file is left as it is, and the loader writes its `Renegades.ini` on its first start, so unzipping it over
an older release keeps the campaign. The loader adds its lines to `OPU\outpost2.ini` when it runs (the module's
registration, and before each mission IntroAVI=0, CheckForUpdates=0 and ShowUnitHPBars=0).

`Renegades.exe` and `Renegades.dll` carry version 1.2.11.0; `OP2LuaCore.dll` is OP2Lua 0.8.6. Compared with 1.2.10,
`OPU/renegades/background03.png` (the loader's background) replaces `background02.png`.
`.gitattributes` keeps Git from changing any file's line endings, so a copy from this repository hashes the same.

## `OPU/`: the loader, the module and what they use

| File | Size | SHA-256 |
|---|---:|---|
| `Launcher.dll` | 164,352 | `d001edd31cd6c72e8779c7fe9b6fe3a9788c2a7dc068dbeabd5d256bb6b65eb7` |
| `op2launcher.exe` | 144,384 | `c235cbcd60efe8b35f7ea434c62e878de987fa9d958521076e1eef6048ebb416` |
| `OP2LuaCore.dll` | 3,051,520 | `df1f3bedcaedc3c76670b96631e04ccd8fd8a2e3be6f1510e9552d7bc53068c1` |
| `ren2res.dll` | 526,848 | `9cc5c63a9867ec97659b1ba4fb5ebd9e758fc71d61fdf15e2a7c1729054bc2ba` |
| `Renegades.dll` | 152,064 | `1369462f35de06420e4487c058bd72a2fb10b739c33308eeaebb5bbd5f246f1e` |
| `Renegades.exe` | 16,993,792 | `4e5215ed69fb3434e6969a12193912d8bdae2b9a9d6c312835673460a6eb8826` |

## `OPU/renegades/`: Renegades' menu art and texts, the loader's background and its texts in five languages

| File | Size | SHA-256 |
|---|---:|---|
| `background03.png` | 2,358,376 | `aa0a643cfe733345a995de68bc070791ccb9a6e7c1c62e7ca805fa4b96fdf49c` |
| `lang.de.ini` | 5,452 | `881cbfea893fe7900c8230f256b275004cd95406eb786fd34eb8ce28fde1c2f9` |
| `lang.en.ini` | 5,248 | `e8a0d1c844b29040d66f5295fca8024db5a33402ab0dab2b93ec483af92155a0` |
| `lang.es.ini` | 5,474 | `1dec539e1f29d3a1d74a11af81a990d0d9843579aef30301961d74e48c3156b0` |
| `lang.fr.ini` | 5,737 | `f4fa306b5ed50cd9cea529d6c608a3ae38c2bb2e323f0949c685b07559c1a129` |
| `lang.pt.ini` | 5,471 | `6ce07b482b9c8d8f9bcfa4b350457e69e464825c10d3df9447af293f8f9ae774` |
| `README.txt` | 3,900 | `10d51dd1c285ff102e2c3b088f7ed5db623f80308af13636555028a30ba06747` |
| `ren.vol` | 68,974 | `78f48d149a536b003adce4093f9c3826ff063d4dbe131403833a7d2bd4769068` |
| `renegmbl.raw` | 29,484 | `0be5fd7015c85e80e15271e6649083bef33782302586cf260f228a9e7c90f2ee` |
| `renshres.dll` | 3,080,192 | `05834c8be1d6d9af02102de4a482bcf55d022eed6757c84dad5e19fae7dcd01b` |

## `OPU/maps/Renegades/`: the four missions, their maps, tech trees and voice lines

| File | Size | SHA-256 |
|---|---:|---|
| `Q01.MAP` | 64,725 | `dcb45b27f905468c5f1d337863aed44e133560ad6585183a864b253b4112aedd` |
| `Q01.TEK` | 16,998 | `5f806715820163a899ea255778768c39b8b8df9612e3a3c6e3ac00d08aee5ff0` |
| `q01Lua.dll` | 109,056 | `d5f46a2f5a43d29debbb1f7cc1dd65a08735586ecb58fad880ca9f2b426de844` |
| `q01Lua.lua` | 30,514 | `852b153cdfd5c95d5144031d31641a20b3dfd3f997c6cd49519f7da4791bcfe5` |
| `q01Lua.placement.lua` | 2,920 | `b5874789864c287e0151cf52093997f73d9c5864c93c70c66f9b0a1549b6311f` |
| `Q02.MAP` | 97,493 | `936692e0e94695203e50a1afc7b1810cd581237d0e3ca2b8ea14396fabe91953` |
| `Q02.TEK` | 22,365 | `7743759ef62aee756b1dba3794e46b7be2c1ee63752d6de1181c062291ad4a3b` |
| `q02Lua.dll` | 109,056 | `6d5d15070644d6ed086a83387d6e9255070630adc2796304f435fe9d61a0e3cd` |
| `q02Lua.lua` | 101,144 | `68e4a4185f8fe06911baa54ee768eae099dc1d5df4c1bea8943b20735565b7ed` |
| `q02Lua.placement.lua` | 753 | `60789476a2676e5fa87f8b5ac3bec27d18ae71e0c176fb710b5b8c37dcef148c` |
| `Q03.MAP` | 97,493 | `53756fb22a1f42a437a4d2bd11f4a5a6b90a69130ad3b170b7a2567e790bf019` |
| `Q03.TEK` | 32,999 | `f574c27419d7918a90fe5a6a4be0199f80cabad6be3fdcb6bce48d99fbd5ac85` |
| `q03Lua.dll` | 109,056 | `28cd8903cb0a14a7cb8312c086027b192bb60a93025ac834fb6e6043d278a4e1` |
| `q03Lua.lua` | 91,466 | `d5bdcefafadb6288ac656c5ddc7449c9b2cb1020aca3fb3f005b7d6a3c1abf51` |
| `q03Lua.placement.lua` | 4,100 | `9d8ad3a27f8128f60d344db73222ee6442f359e3d5868d05a509742192414b34` |
| `Q04.MAP` | 128,599 | `7752c27c6e7ba41c5ab5468037ca7cedb1c57cfe2b5f68fe952ae890f350cb21` |
| `q04Lua.dll` | 109,056 | `a760d8ee3475988b0a34bb855a09d55fc9bb2929cd5550db7db7ac870cb25699` |
| `q04Lua.lua` | 60,051 | `502aa21fe30364e37f4a62d58fd20abf06abfd473536c3dc8e87761a73184852` |
| `q04Lua.placement.lua` | 5,038 | `c807a521c4b39c021a12aa984b31fd7b5efbf2d3aa9923345a86f15594d42ab3` |
| `README.txt` | 605 | `3d482507a1133629f05022d4cefc5f3c42b826eb3907cdb9883405596c93a7cd` |
| `ren228.wav` | 34,488 | `7217576d1b51d34bf5a529abcdcdcb81e3459ad72073875d5001be8709eee1b9` |
| `ren229.wav` | 55,890 | `b6aaee49006407c8c4453263b0b5ac463d86d1c59c34510271c22bde1cbc13dc` |
| `ren230.wav` | 38,014 | `618209cb150dafa8c7e96395e34f1a64898040aad4c4ff0b322a1a9b5b1beff1` |
| `ren231.wav` | 26,172 | `ed785090a9bdacfd78bb529eaa2d6191d6c20537568d7db6811b31b40ffde064` |
| `ren232.wav` | 43,950 | `8c6fdae55161a6f2728bd7384981eed8a15eff8b4f8ac1fb89d2802ebf558657` |
| `ren233.wav` | 20,098 | `a52d4651b8a0a3a56bf658a553a03a8f2147ddf200cc96e25c94fde7436d37eb` |
| `ren234.wav` | 23,816 | `ae8539f249ed82b5bce90e868790abe8a8adc8596995e542b80f6abfefc6b4c8` |

## Checking a copy

[`SHA256SUMS-1.2.11.txt`](SHA256SUMS-1.2.11.txt) lists the same hashes in the form `sha256sum` reads, with paths from the
Outpost 2 folder. From this repository's root, while it holds 1.2.11:

```
sha256sum -c docs/SHA256SUMS-1.2.11.txt
```

From an Outpost 2 folder, give the list's own path: `sha256sum -c path/to/SHA256SUMS-1.2.11.txt`.

In PowerShell, one file at a time:

```
Get-FileHash OPU\Renegades.exe -Algorithm SHA256
```
