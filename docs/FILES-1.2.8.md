# Renegades 1.2.8: files and hashes

Every file in the release zip, `Outpost2-Renegades-1.2.8.zip`, with its size and SHA-256, so a copy can be checked
against the release.

| Zip | Size | SHA-256 |
|---|---:|---|
| `Outpost2-Renegades-1.2.8.zip` | 10,223,873 | `7f1adbacc7d9a205cd589d3033e924ce71d4e4d424c0c7f68275d5d4ba0ebe82` |

The zip holds 41 files (25,271,233 bytes) and one empty folder, `OPU/logs/`, where OP2Lua writes the missions'
logs. It unzips into the Outpost 2 folder. It has **no `outpost2.ini`** and **no `Renegades.ini`**: the game's own
settings file is left as it is, and the loader writes its `Renegades.ini` on its first start, so unzipping it over
an older release keeps the campaign. The loader adds its lines to `OPU\outpost2.ini` when it runs (the module's
registration, and before each mission IntroAVI=0, CheckForUpdates=0 and ShowUnitHPBars=0).

`Renegades.exe` and `Renegades.dll` carry version 1.2.8.0; `OP2LuaCore.dll` is OP2Lua 0.8.3. Compared with 1.2.0,
`OPU/renegades/Renegades.ini` is gone and the four `lang.*.ini` files are new. `.gitattributes` keeps Git from
changing any file's line endings, so a copy from this repository hashes the same.

## `OPU/`: the loader, the module and what they use

| File | Size | SHA-256 |
|---|---:|---|
| `Launcher.dll` | 164,352 | `d001edd31cd6c72e8779c7fe9b6fe3a9788c2a7dc068dbeabd5d256bb6b65eb7` |
| `op2launcher.exe` | 144,384 | `c235cbcd60efe8b35f7ea434c62e878de987fa9d958521076e1eef6048ebb416` |
| `OP2LuaCore.dll` | 2,784,768 | `ea2249c151f639c56a308c0362acc2d949e794678a845b2ca5f509b72330b35e` |
| `ren2res.dll` | 526,848 | `9cc5c63a9867ec97659b1ba4fb5ebd9e758fc71d61fdf15e2a7c1729054bc2ba` |
| `Renegades.dll` | 152,064 | `7cf0cb219754201af2f678e43c662544e8278278748c497555cbec192c5f3f52` |
| `Renegades.exe` | 16,864,256 | `76ddda4ebed2f42e650691dba66955c4fe02aff78bde9e06714e8180a0dac6ac` |

## `OPU/renegades/`: Renegades' menu art and texts, the loader's texts in four languages

| File | Size | SHA-256 |
|---|---:|---|
| `lang.de.ini` | 5,105 | `12000211f89d5876f9645f310e60d1a48623168e4648196b2d7c00f320017180` |
| `lang.en.ini` | 4,945 | `a5a6a9f3f994a64ab4d99ab3ff7d54c6ec94c3bc596e6cd23ebe6d093fbff5de` |
| `lang.es.ini` | 5,137 | `761b0af9b85c2e8655cbe0c299d255d8fbf883b296cef6674f17ea29ab8f720d` |
| `lang.pt.ini` | 5,149 | `3ee87e806e2659b8614b72b5035f131e6c8f29b51673133fafbd04886efb9df5` |
| `README.txt` | 3,675 | `df8ca9e32944fa9958b5c3a17e0672d95cf0e2bdded0a9aa8c3ef4a3ff9b3bb8` |
| `ren.vol` | 68,974 | `78f48d149a536b003adce4093f9c3826ff063d4dbe131403833a7d2bd4769068` |
| `renegmbl.raw` | 29,484 | `0be5fd7015c85e80e15271e6649083bef33782302586cf260f228a9e7c90f2ee` |
| `renshres.dll` | 3,080,192 | `05834c8be1d6d9af02102de4a482bcf55d022eed6757c84dad5e19fae7dcd01b` |

## `OPU/maps/Renegades/`: the four missions, their maps, tech trees and voice lines

| File | Size | SHA-256 |
|---|---:|---|
| `Q01.MAP` | 64,725 | `dcb45b27f905468c5f1d337863aed44e133560ad6585183a864b253b4112aedd` |
| `Q01.TEK` | 16,998 | `5f806715820163a899ea255778768c39b8b8df9612e3a3c6e3ac00d08aee5ff0` |
| `q01Lua.dll` | 109,056 | `d5f46a2f5a43d29debbb1f7cc1dd65a08735586ecb58fad880ca9f2b426de844` |
| `q01Lua.lua` | 29,801 | `6694d17a4a175535b26d2320df78156751b718a3610919bb19c7a0ce9f64bde3` |
| `q01Lua.placement.lua` | 2,919 | `1e6eef46304383630d0516be7d7decced3952bd3989d52511b3cd152969633c9` |
| `Q02.MAP` | 97,493 | `936692e0e94695203e50a1afc7b1810cd581237d0e3ca2b8ea14396fabe91953` |
| `Q02.TEK` | 22,365 | `7743759ef62aee756b1dba3794e46b7be2c1ee63752d6de1181c062291ad4a3b` |
| `q02Lua.dll` | 109,056 | `6d5d15070644d6ed086a83387d6e9255070630adc2796304f435fe9d61a0e3cd` |
| `q02Lua.lua` | 100,112 | `b55395c0f6e07da4e574a5d1c9882f00900ee18cc1d4da6abecab99719124ea7` |
| `q02Lua.placement.lua` | 752 | `1787249db6def95b4a061a09bf136c6f604fb90a3494c989d8024d7aa70346d8` |
| `Q03.MAP` | 97,493 | `53756fb22a1f42a437a4d2bd11f4a5a6b90a69130ad3b170b7a2567e790bf019` |
| `Q03.TEK` | 32,999 | `f574c27419d7918a90fe5a6a4be0199f80cabad6be3fdcb6bce48d99fbd5ac85` |
| `q03Lua.dll` | 109,056 | `28cd8903cb0a14a7cb8312c086027b192bb60a93025ac834fb6e6043d278a4e1` |
| `q03Lua.lua` | 90,753 | `3dc0f8f26e070af8ee6465401c8b4c3a36dd5272bd570329739c24eb8cce3059` |
| `q03Lua.placement.lua` | 4,099 | `1050d15ca1119ae6ede518ce3a06043b35df620ec66e7d999e8f3a59fbbf3f9c` |
| `Q04.MAP` | 128,599 | `7752c27c6e7ba41c5ab5468037ca7cedb1c57cfe2b5f68fe952ae890f350cb21` |
| `q04Lua.dll` | 109,056 | `a760d8ee3475988b0a34bb855a09d55fc9bb2929cd5550db7db7ac870cb25699` |
| `q04Lua.lua` | 58,498 | `423ea6eb3827847eebc51738db6457447ea82dc95986dac050224dad58d93b26` |
| `q04Lua.placement.lua` | 5,037 | `dbe164a1ad688dbd9fe25db80503dca335e7f9c6d967cba4b951a94436ad8698` |
| `README.txt` | 605 | `3d482507a1133629f05022d4cefc5f3c42b826eb3907cdb9883405596c93a7cd` |
| `ren228.wav` | 34,488 | `7217576d1b51d34bf5a529abcdcdcb81e3459ad72073875d5001be8709eee1b9` |
| `ren229.wav` | 55,890 | `b6aaee49006407c8c4453263b0b5ac463d86d1c59c34510271c22bde1cbc13dc` |
| `ren230.wav` | 38,014 | `618209cb150dafa8c7e96395e34f1a64898040aad4c4ff0b322a1a9b5b1beff1` |
| `ren231.wav` | 26,172 | `ed785090a9bdacfd78bb529eaa2d6191d6c20537568d7db6811b31b40ffde064` |
| `ren232.wav` | 43,950 | `8c6fdae55161a6f2728bd7384981eed8a15eff8b4f8ac1fb89d2802ebf558657` |
| `ren233.wav` | 20,098 | `a52d4651b8a0a3a56bf658a553a03a8f2147ddf200cc96e25c94fde7436d37eb` |
| `ren234.wav` | 23,816 | `ae8539f249ed82b5bce90e868790abe8a8adc8596995e542b80f6abfefc6b4c8` |

## Checking a copy

[`SHA256SUMS-1.2.8.txt`](SHA256SUMS-1.2.8.txt) lists the same hashes in the form `sha256sum` reads, with paths from the
Outpost 2 folder. From this repository's root, while it holds 1.2.8:

```
sha256sum -c docs/SHA256SUMS-1.2.8.txt
```

From an Outpost 2 folder, give the list's own path: `sha256sum -c path/to/SHA256SUMS-1.2.8.txt`.

In PowerShell, one file at a time:

```
Get-FileHash OPU\Renegades.exe -Algorithm SHA256
```
