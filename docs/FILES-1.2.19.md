# Renegades 1.2.19: files and hashes

Every file in the release zip, `Outpost2-Renegades-1.2.19.zip`, with its size and SHA-256, so a copy can be checked
against the release.

| Zip | Size | SHA-256 |
|---|---:|---|
| `Outpost2-Renegades-1.2.19.zip` | 12,740,871 | `76f0ab547e5bfe00c61c371a7b567a4a64968dc22de9bc16490764bfae692bd2` |

The zip holds 43 files (28,240,785 bytes) and one empty folder, `OPU/logs/`, where OP2Lua writes the missions'
logs. It unzips into the Outpost 2 folder. It has **no `outpost2.ini`** and **no `Renegades.ini`**: the game's own
settings file is left as it is, and the loader writes its `Renegades.ini` on its first start, so unzipping it over
an older release keeps the campaign. The loader adds its lines to `OPU\outpost2.ini` when it runs (the module's
registration, and before each mission IntroAVI=0, CheckForUpdates=0 and ShowUnitHPBars=0).

`Renegades.exe` and `Renegades.dll` carry version 1.2.19.0; `OP2LuaCore.dll` is OP2Lua 0.8.12; `op2launcher.exe` and
`Launcher.dll` are 0.9.6. Compared with 1.2.15, these files changed: `OPU/maps/Renegades/q03Lua.lua`, `OPU/maps/Renegades/README.txt`, `OPU/OP2LuaCore.dll`, `OPU/Renegades.dll`, `OPU/Renegades.exe`, `OPU/renegades/lang.de.ini`, `OPU/renegades/lang.en.ini`, `OPU/renegades/lang.es.ini`, `OPU/renegades/lang.fr.ini`, `OPU/renegades/lang.pt.ini`, `OPU/renegades/README.txt`. Only Mission 3's
script changed, so 1.2.15's saves of Missions 1, 2 and 4 carry on.
`.gitattributes` keeps Git from changing any file's line endings, so a copy from this repository hashes the same.

## `OPU/`: the loader, the module and what they use

| File | Size | SHA-256 |
|---|---:|---|
| `Launcher.dll` | 168,448 | `51e8cf50f08bb2526bb5240b6af1e6fa113456629acb47ca536625ef64fe2588` |
| `op2launcher.exe` | 145,920 | `d483e2c6ba5e7b5128d38e9f4f8921e2007c77362ed19b544b875c5e8a1d8f1d` |
| `OP2LuaCore.dll` | 3,156,992 | `7d6a7dd0cb79af68c19ec2055daeaffd4c1d015bc768f4560258b9932cfaf408` |
| `ren2res.dll` | 526,848 | `9cc5c63a9867ec97659b1ba4fb5ebd9e758fc71d61fdf15e2a7c1729054bc2ba` |
| `Renegades.dll` | 160,768 | `e500621cf0779db8f9cfc1eb856751082b5804331077a7d5586558faf47a6a80` |
| `Renegades.exe` | 17,067,520 | `83d63360f484f20ccffcc749a2b19569d90c49f2a2ea353f5811946d327fce53` |

## `OPU/renegades/`: Renegades' menu art and texts, the loader's background and its texts in five languages

| File | Size | SHA-256 |
|---|---:|---|
| `background03.png` | 2,358,376 | `aa0a643cfe733345a995de68bc070791ccb9a6e7c1c62e7ca805fa4b96fdf49c` |
| `lang.de.ini` | 6,132 | `3dac5f87cb7bffc4eac3a0c96407e73fd32c53313e42323478d774699484500a` |
| `lang.en.ini` | 5,946 | `9bc9222d63d088f617b37e7b88c9f4eb4bd3626a78bc0413f23120b3adf145da` |
| `lang.es.ini` | 6,173 | `b5f936896f0a5bd22ecb39fda2a8d6bc073ebe0262e62bba0c9826cbf0f1ef8f` |
| `lang.fr.ini` | 6,436 | `8b609b2eca6016e0506d6a1a10c0c0d5784674898f9bc0e2bb05aeaeb2a03493` |
| `lang.pt.ini` | 6,145 | `668aa739a3b38a9c436771e991f249cd05cc9a5be07d8ed24dc30657ce084f04` |
| `README.txt` | 3,996 | `611229dbf0024562ff45f805899c9b7e1b58d7f2f07bd9d298dc4f57b882204d` |
| `ren.vol` | 68,974 | `78f48d149a536b003adce4093f9c3826ff063d4dbe131403833a7d2bd4769068` |
| `renegmbl.raw` | 29,484 | `0be5fd7015c85e80e15271e6649083bef33782302586cf260f228a9e7c90f2ee` |
| `renshres.dll` | 3,080,192 | `05834c8be1d6d9af02102de4a482bcf55d022eed6757c84dad5e19fae7dcd01b` |

## `OPU/maps/Renegades/`: the four missions, their maps, tech trees and voice lines

| File | Size | SHA-256 |
|---|---:|---|
| `Q01.MAP` | 64,725 | `dcb45b27f905468c5f1d337863aed44e133560ad6585183a864b253b4112aedd` |
| `Q01.TEK` | 16,998 | `5f806715820163a899ea255778768c39b8b8df9612e3a3c6e3ac00d08aee5ff0` |
| `q01Lua.dll` | 109,056 | `d5f46a2f5a43d29debbb1f7cc1dd65a08735586ecb58fad880ca9f2b426de844` |
| `q01Lua.lua` | 31,690 | `a7740bbb530006d6ae4744c209d86dcf5c96a4f5507abe29f198dfac4eec8da7` |
| `q01Lua.placement.lua` | 2,912 | `24814845050ba6394da9da73a2cd19ecdb799a99e0fe418c2b3ed68166767246` |
| `Q02.MAP` | 97,493 | `936692e0e94695203e50a1afc7b1810cd581237d0e3ca2b8ea14396fabe91953` |
| `Q02.TEK` | 22,365 | `7743759ef62aee756b1dba3794e46b7be2c1ee63752d6de1181c062291ad4a3b` |
| `q02Lua.dll` | 109,056 | `6d5d15070644d6ed086a83387d6e9255070630adc2796304f435fe9d61a0e3cd` |
| `q02Lua.lua` | 102,160 | `9e5ce6ea43ccbb7a5803ea1aedde40cf69945becfb01d9d3548a05e67d3f5d41` |
| `q02Lua.placement.lua` | 745 | `002d2525ed2bd64af4f1cc5e3083ec31415a95681eadf39e6f9d4be53c401c59` |
| `Q03.MAP` | 97,493 | `53756fb22a1f42a437a4d2bd11f4a5a6b90a69130ad3b170b7a2567e790bf019` |
| `Q03.TEK` | 32,999 | `f574c27419d7918a90fe5a6a4be0199f80cabad6be3fdcb6bce48d99fbd5ac85` |
| `q03Lua.dll` | 109,056 | `28cd8903cb0a14a7cb8312c086027b192bb60a93025ac834fb6e6043d278a4e1` |
| `q03Lua.lua` | 94,626 | `413a8518bc67c12154bbd3ea5045de427411f7a99671f6052ec1c1dd2b3b2994` |
| `q03Lua.placement.lua` | 4,092 | `2000987604791ec7c33ad2863506306fc1902c8df2dd301eebf4ca951f250e04` |
| `Q04.MAP` | 128,599 | `7752c27c6e7ba41c5ab5468037ca7cedb1c57cfe2b5f68fe952ae890f350cb21` |
| `q04Lua.dll` | 109,056 | `a760d8ee3475988b0a34bb855a09d55fc9bb2929cd5550db7db7ac870cb25699` |
| `q04Lua.lua` | 61,250 | `16ec6e315c44f915214e27596ab08ed350eb1ab6df1711788a8999b61d327e1d` |
| `q04Lua.placement.lua` | 5,030 | `0ac8606190d198e721f7367d60f21beb9a4470d0c6d3acd7822e789fa7802f93` |
| `README.txt` | 606 | `1eda708d9e1216a63d4052ffcd391fef05e83060d88bf7a851cda4868082ba12` |
| `ren228.wav` | 34,488 | `7217576d1b51d34bf5a529abcdcdcb81e3459ad72073875d5001be8709eee1b9` |
| `ren229.wav` | 55,890 | `b6aaee49006407c8c4453263b0b5ac463d86d1c59c34510271c22bde1cbc13dc` |
| `ren230.wav` | 38,014 | `618209cb150dafa8c7e96395e34f1a64898040aad4c4ff0b322a1a9b5b1beff1` |
| `ren231.wav` | 26,172 | `ed785090a9bdacfd78bb529eaa2d6191d6c20537568d7db6811b31b40ffde064` |
| `ren232.wav` | 43,950 | `8c6fdae55161a6f2728bd7384981eed8a15eff8b4f8ac1fb89d2802ebf558657` |
| `ren233.wav` | 20,098 | `a52d4651b8a0a3a56bf658a553a03a8f2147ddf200cc96e25c94fde7436d37eb` |
| `ren234.wav` | 23,816 | `ae8539f249ed82b5bce90e868790abe8a8adc8596995e542b80f6abfefc6b4c8` |

## Checking a copy

[`SHA256SUMS-1.2.19.txt`](SHA256SUMS-1.2.19.txt) lists the same hashes in the form `sha256sum` reads, with paths from the
Outpost 2 folder. From this repository's root, while it holds 1.2.19:

```
sha256sum -c docs/SHA256SUMS-1.2.19.txt
```

From an Outpost 2 folder, give the list's own path: `sha256sum -c path/to/SHA256SUMS-1.2.19.txt`.

In PowerShell, one file at a time:

```
Get-FileHash OPU\Renegades.exe -Algorithm SHA256
```
