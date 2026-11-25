// Renegades.cpp - Renegades.dll, an op2ext ".ini module" giving a Renegades game its in-game look, in memory only:
//   - the in-game art from ren2res.dll instead of out2res.dll (the "OP: RENEGADES" title, the blue frames, the
//     loading screen, the About box; ../findings/REN2RES.md);
//   - the Renegades R in the command pane, from renegmbl.raw (in OPU\renegades, or beside the module), in place of
//     the colony emblem;
//   - the difficulty the loader picked (RENEGADES_DIFFICULTY), which op2launcher's start can't pass;
//   - the random seed the loader chose (RENEGADES_SEED), in place of the clock's;
//   - the player's name from the loader's Preferences in the game's player record, which op2launcher's start leaves
//     empty, and the "Renegades v<release>" message at a mission's start (the missions' scripts carry no version);
//   - saved games as SGAMEn.REN, Renegades' own slots, as the original mod made them, with a Renegades save tag so
//     that only a Renegades game loads them.
// Nothing on disk is changed, and it only acts when the Renegades loader started the game (environment variable
// RENEGADES_LAUNCH=1, inherited by the game). Any other game is stock; so is the next one after a crash.
//
// op2ext contract: [ExternalModules] Renegades=yes, [Renegades] Dll=Renegades.dll (relative to the OPU folder).
// op2ext calls InitMod("Renegades") at start-up and DestroyMod() at exit.
//
// Game addresses (Outpost2.exe 1.2.0.7 / OPU 1.4.1):
//   0x4E96C0  "out2res.dll", the name TApp::Init (0x485B20) looks up with ResManager::GetFilePath and loads
//             with LoadLibraryA (0x485C57-0x485C7F)
//   0x56E86C  TApp (0x56E868) +4, hOut2ResLib: the handle every later LoadImage of the in-game art uses
//   0x546B98  the graphics object the sprite manager makes (set at 0x404236); its +0xEC is a pixel base
//   0x4FF814  the graphics table entry Renegades' missions pointed at renegmbl.raw (offset from that base)
//   0x4998F0  Dans_RULE_UIFrame::LoadResourceImages, 0x499970 FreeResourceImages: the game window frame's bitmaps
//
// Under OPU 1.4.1 op2ext starts modules after TApp::Init has loaded out2res.dll, so the module loads ren2res.dll,
// swaps the handle, and has the frame reload its bitmaps (the "OP: RENEGADES" title).

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

static HINSTANCE g_hInst = nullptr;
static std::string g_dir;          // this module's folder, trailing backslash
static std::string g_logPath;
static bool g_active = false;

static const uintptr_t kResName = 0x4E96C0;
static const uintptr_t kResHandle = 0x56E86C;
static const uintptr_t kGraphics = 0x546B98;
static const uintptr_t kEmblemEntry = 0x4FF814;
// Dans_RULE_UIFrame: FreeResourceImages and LoadResourceImages (no arguments; they work on globals), and the table of
// its 25 frame bitmap handles they fill (ids from 0x4D6990; index 13 is bitmap 181, 14 is 179, the title logo).
static const uintptr_t kFreeFrameImages = 0x499970;
static const uintptr_t kLoadFrameImages = 0x4998F0;
static const uintptr_t kFrameImages = 0x575588;
// "OP2Shell.dll", the menu shell's name the game loads (pointer at 0x4E96B0)
static const uintptr_t kShellName = 0x4E96A0;

// TApp::OnLoadScript (0x487590), the start op2launcher uses, sets player 1's flags with `and eax, ~0x10; or eax, 8`
// (0x48767C): the 2-bit difficulty field (bits 3-4) is always 1, Normal.
static const uintptr_t kStartDifficulty = 0x48767C;
static const unsigned char kStartDifficultyStock[6] = { 0x83, 0xE0, 0xEF, 0x83, 0xC8, 0x08 };
static bool g_difficultyPatched = false;
// The same routine seeds the game from the clock: after timeGetTime it computes `shl eax,16; mov ecx,[esp+132h];
// xor ecx,eax` (0x48765B, 12 bytes), ecx = (t << 16) ^ t, and stores ecx as GameStartInfo's random seed at 0x487675
// (eax is reloaded right after).
static const uintptr_t kStartSeed = 0x48765B;
static const unsigned char kStartSeedStock[12] = { 0xC1, 0xE0, 0x10, 0x8B, 0x8C, 0x24, 0x32, 0x01, 0x00, 0x00, 0x33, 0xC8 };
static bool g_seedPatched = false;
// It leaves GameStartInfo's player names empty (it zeroes the struct at [esp+80h] and only copies the script name),
// so the player record has no name. It then starts the game with `call TethysGame::StartGame` (0x487758, a __thiscall
// on 0x56EA98 taking the GameStartInfo); that call is pointed at StartGameWithName, which fills player 0's name
// (GameStartInfo +0x60, 13 bytes) as OP2TestHarness fills "Harness", and the game copies it into the record.
static const uintptr_t kStartGameCall = 0x487758;
static const uintptr_t kStartGame = 0x4893B0;
static const size_t kGsiPlayerName = 0x60;
static const size_t kNameSize = 13;
// The saved games' extension, as Renegades' original op2mod.dll made it (findings/decompile/renshell.md): the save
// dialog names each slot from "SGAME%d.OP2" (0x4E0614, 13 places in 0x417100-0x418F5F) and its index "SGAME10.OP2"
// (0x4E0628, at 0x416F9D), so their "OP2" becomes "REN" and a Renegades game keeps its own ten slots. OPU 1.4.1 only
// supplies the folder (OPUPatch hooks 0x416F78 for OPU\saves\), so the saves are OPU\saves\SGAMEn.REN. The two
// "op2" in the file filter text "... (*.op2)" / "*.op2" (0x4E5AB7, 0x4E5ABE) follow, as in the original.
static const uintptr_t kSaveExts[] = { 0x4E061C, 0x4E0630, 0x4E5AB7, 0x4E5ABE };
static const char* const kSaveExtStock[] = { "OP2", "OP2", "op2", "op2" };
static bool g_saveExtPatched[4] = {};
// Every save starts with a tag the game checks on load as a string (TethysGame::VerifySavedGameFileTag, 0x48A190).
// OPU 1.4.1 points the game's save and load code at its own "OUTPOST2 1.4.0-OPU SAVE" in OPUPatch.dll (in place of
// the stock tag at 0x4D6380); a Renegades game makes that string "OUTPOST2 1.4.0-REN SAVE" (same length), so its saves
// carry the Renegades tag, it loads only those, and OPU 1.4.1 without this module refuses them, whatever the file is
// called: a Renegades save needs the Renegades game around it.
static const char kOpuSaveTag[] = "OUTPOST2 1.4.0-OPU SAVE";
static const char kRenSaveTag[] = "OUTPOST2 1.4.0-REN SAVE";
static char* g_saveTag = nullptr;
static unsigned char g_startGameCallStock[5] = {};
static bool g_startGamePatched = false;
static char g_playerName[kNameSize] = "";

static bool g_namePatched = false;
static HMODULE g_ren2res = nullptr;
static std::vector<unsigned char> g_emblem;    // renegmbl.raw, kept for the life of the game
static DWORD g_emblemOriginal = 0;
static bool g_emblemSaved = false;
static volatile LONG g_stop = 0;
static HANDLE g_thread = nullptr;

static void Log(const char* fmt, ...) {
    if (g_logPath.empty()) return;
    FILE* f = nullptr;
    if (fopen_s(&f, g_logPath.c_str(), "a") != 0 || !f) return;
    SYSTEMTIME t;
    GetLocalTime(&t);
    fprintf(f, "%04d-%02d-%02d %02d:%02d:%02d  ", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
    va_list a;
    va_start(a, fmt);
    vfprintf(f, fmt, a);
    va_end(a);
    fputc('\n', f);
    fclose(f);
}

// Writes `len` bytes at a game address, making the page writable for the write.
static bool Poke(uintptr_t addr, const void* src, size_t len) {
    DWORD old = 0;
    if (!VirtualProtect(reinterpret_cast<void*>(addr), len, PAGE_EXECUTE_READWRITE, &old)) return false;
    memcpy(reinterpret_cast<void*>(addr), src, len);
    VirtualProtect(reinterpret_cast<void*>(addr), len, old, &old);
    return true;
}

static bool FileExists(const std::string& p) {
    DWORD a = GetFileAttributesA(p.c_str());
    return a != INVALID_FILE_ATTRIBUTES && !(a & FILE_ATTRIBUTE_DIRECTORY);
}

// The in-game art. Before TApp::Init has loaded it, rename the file it looks for (same length, so nothing else
// moves); ResManager finds ren2res.dll in the OPU folder. If it's already loaded, load ours and hand the game
// that handle instead (art the game already took from the stock file stays stock until reloaded).
static void UseRen2Res() {
    static const char stock[] = "out2res.dll";
    static const char ours[] = "ren2res.dll";
    // The name, always: TApp::Init can load the file again after this module has run (seen in OPU 1.4.1: the handle
    // went back to out2res.dll and the frame reloaded the stock title), and then it finds ren2res.dll itself.
    if (memcmp(reinterpret_cast<void*>(kResName), stock, sizeof(stock)) != 0) {
        Log("ren2res: the name at 0x4E96C0 isn't \"out2res.dll\": another build of the game? Left alone.");
        return;
    }
    g_namePatched = Poke(kResName, ours, sizeof(ours));
    Log("ren2res: the name at 0x4E96C0 is now ren2res.dll (%s)", g_namePatched ? "patched" : "NOT patched");
    HMODULE loaded = *reinterpret_cast<HMODULE*>(kResHandle);
    if (!loaded) {
        Log("ren2res: not loaded yet: the game will load ren2res.dll");
        return;
    }
    std::string path = g_dir + "ren2res.dll";
    if (!FileExists(path)) {
        Log("ren2res: already loaded by the game, and %s is missing", path.c_str());
        return;
    }
    g_ren2res = LoadLibraryA(path.c_str());
    if (!g_ren2res) {
        Log("ren2res: LoadLibrary(%s) failed, error %lu", path.c_str(), GetLastError());
        return;
    }
    Poke(kResHandle, &g_ren2res, sizeof(g_ren2res));
    Log("ren2res: the game had loaded out2res.dll already; its handle now points at %s", path.c_str());

    // The game window's frame took its 25 bitmaps (the title logo 179/181 among them, ids at 0x4D6990) from the stock
    // file when it was set up. Reload them from ours, as the game does itself: free them, then load them again.
    static const unsigned char loadStart[] = { 0x83, 0xEC, 0x18, 0x33, 0xC0, 0xB9, 0x19, 0x00, 0x00, 0x00 };
    if (memcmp(reinterpret_cast<void*>(kLoadFrameImages), loadStart, sizeof(loadStart)) != 0) {
        Log("ren2res: LoadResourceImages at 0x4998F0 isn't the expected code: the frame keeps the stock title");
        return;
    }
    reinterpret_cast<void(__cdecl*)()>(kFreeFrameImages)();
    reinterpret_cast<void(__cdecl*)()>(kLoadFrameImages)();
    HANDLE title = *reinterpret_cast<HANDLE*>(kFrameImages + 14 * 4);
    Log("ren2res: the frame's bitmaps reloaded from ren2res.dll (title 179: %s)", title ? "loaded" : "MISSING");
}

// "Outpost 2" -> "Renegades" in the game's own texts, as op2mod.dll did (its patch table at 0x1F005050, the same 13
// addresses and the same 9 bytes): the window's and taskbar's title (0x4E5DEC), the online manual, the save dialog's
// "Renegades Games (*.op2)", the quit prompt and the game's messages about its CD and display. Each is checked to read
// "Outpost 2" (two are "OUTPOST 2") before it's changed, and put back at exit.
static const uintptr_t kTexts[] = { 0x4E484A, 0x4E4870, 0x4E555C, 0x4E561A, 0x4E57FE, 0x4E580C, 0x4E5AA4,
                                    0x4E5BE0, 0x4E5C6C, 0x4E5DEC, 0x4E6124, 0x4E7CC6, 0x4E7CEE };
static char g_textOriginal[sizeof(kTexts) / sizeof(kTexts[0])][9];
static bool g_textPatched[sizeof(kTexts) / sizeof(kTexts[0])] = {};

static void UseRenegadesTexts() {
    int done = 0, n = static_cast<int>(sizeof(kTexts) / sizeof(kTexts[0]));
    for (int i = 0; i < n; ++i) {
        char* at = reinterpret_cast<char*>(kTexts[i]);
        if (_strnicmp(at, "Outpost 2", 9) != 0) {
            Log("texts: 0x%08lX doesn't read \"Outpost 2\": left alone", static_cast<DWORD>(kTexts[i]));
            continue;
        }
        memcpy(g_textOriginal[i], at, 9);
        g_textPatched[i] = Poke(kTexts[i], "Renegades", 9);
        done += g_textPatched[i];
    }
    Log("texts: \"Outpost 2\" -> \"Renegades\" in %d of %d of the game's texts", done, n);
}

// The menu shell: Renegades' renshell.dll (the stock OP2Shell.dll with 27 edits, ../findings/decompile/renshell.md)
// in place of OP2Shell.dll, by name, as op2mod.dll did: the game looks the name up at 0x4E96A0 (through the pointer
// at 0x4E96B0) when it opens its menus. renshell loads renshres.dll (its dialogs and art) by name, found in the OPU
// folder, and reads its texts from ren.vol, added to the game's archives here with op2ext's AddVolToList.
static bool g_shellPatched = false;

static void UseRenShell() {
    static const char stock[] = "OP2Shell.dll";
    static const char ours[] = "RENShell.dll";
    for (const char* f : { "renshell.dll", "renshres.dll", "ren.vol" }) {
        if (!FileExists(g_dir + f)) {
            Log("shell: %s%s is missing: the stock menu stays", g_dir.c_str(), f);
            return;
        }
    }
    if (memcmp(reinterpret_cast<void*>(kShellName), stock, sizeof(stock)) != 0) {
        Log("shell: the name at 0x4E96A0 isn't \"OP2Shell.dll\": another build of the game? Left alone.");
        return;
    }
    using AddVolFn = void(__cdecl*)(const char*);
    HMODULE op2ext = GetModuleHandleA("op2ext.dll");
    auto addVol = op2ext ? reinterpret_cast<AddVolFn>(GetProcAddress(op2ext, "AddVolToList")) : nullptr;
    if (!addVol) {
        Log("shell: op2ext.dll's AddVolToList not found: the stock menu stays");
        return;
    }
    std::string vol = g_dir + "ren.vol";
    addVol(vol.c_str());
    Log("shell: added %s to the game's archives", vol.c_str());
    g_shellPatched = Poke(kShellName, ours, sizeof(ours));
    Log("shell: the name at 0x4E96A0 is now RENShell.dll (%s)", g_shellPatched ? "patched" : "NOT patched");
}

// The difficulty the loader picked (RENEGADES_DIFFICULTY 0 Easy, 1 Normal, 2 Hard): OnLoadScript's two instructions
// become `and eax, ~0x18; or eax, d << 3`, so the mission's player 1 gets it as _Player::Difficulty(). Without the
// variable the game keeps its Normal.
static void UseDifficulty() {
    char v[8] = "";
    GetEnvironmentVariableA("RENEGADES_DIFFICULTY", v, sizeof(v));
    if (!v[0]) {
        Log("difficulty: no RENEGADES_DIFFICULTY: the game's own (Normal)");
        return;
    }
    if (v[1] || v[0] < '0' || v[0] > '2') {
        Log("difficulty: RENEGADES_DIFFICULTY=%s isn't 0, 1 or 2: the game's own (Normal)", v);
        return;
    }
    if (memcmp(reinterpret_cast<void*>(kStartDifficulty), kStartDifficultyStock, sizeof(kStartDifficultyStock)) != 0) {
        Log("difficulty: the code at 0x48767C isn't the expected one: another build of the game? Left alone.");
        return;
    }
    const int d = v[0] - '0';
    const unsigned char ours[6] = { 0x83, 0xE0, 0xE7, 0x83, 0xC8, static_cast<unsigned char>(d << 3) };
    g_difficultyPatched = Poke(kStartDifficulty, ours, sizeof(ours));
    Log("difficulty: %s for the mission's player (%s)", d == 0 ? "Easy" : d == 1 ? "Normal" : "Hard",
        g_difficultyPatched ? "patched" : "NOT patched");
}

// The seed the loader chose (RENEGADES_SEED, a decimal number): the clock seed's three instructions become
// `mov ecx, seed` and seven nops, so the game starts from that seed. Without the variable the clock's stays.
static void UseSeed() {
    char v[16] = "";
    GetEnvironmentVariableA("RENEGADES_SEED", v, sizeof(v));
    if (!v[0]) {
        Log("seed: no RENEGADES_SEED: the game's own (from the clock)");
        return;
    }
    char* end = nullptr;
    unsigned long seed = strtoul(v, &end, 10);
    if (*end) {
        Log("seed: RENEGADES_SEED=%s isn't a number: the game's own (from the clock)", v);
        return;
    }
    if (memcmp(reinterpret_cast<void*>(kStartSeed), kStartSeedStock, sizeof(kStartSeedStock)) != 0) {
        Log("seed: the code at 0x48765B isn't the expected one: another build of the game? Left alone.");
        return;
    }
    unsigned char ours[12] = { 0xB9, 0, 0, 0, 0, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
    const DWORD s = static_cast<DWORD>(seed);
    memcpy(ours + 1, &s, 4);
    g_seedPatched = Poke(kStartSeed, ours, sizeof(ours));
    Log("seed: %lu (%s)", static_cast<unsigned long>(s), g_seedPatched ? "patched" : "NOT patched");
}

// "Renegades v1.2.14" in the message log at a mission's start: the release, from this module's own version resource
// (Renegades.rc), so the missions' scripts don't carry it. A saved game keeps a mission's script only with the same
// .lua (OP2Lua 0.8.8 checks the whole file), so a version inside the scripts would stop every save at each release.
static char g_startMessage[64] = "";

// The module's file version as "1.2.14", from its VS_FIXEDFILEINFO (major.minor.build; the fourth number is 0).
static bool ModuleVersion(char* out, size_t size) {
    HRSRC r = FindResourceA(g_hInst, MAKEINTRESOURCEA(1), MAKEINTRESOURCEA(16));   // RT_VERSION
    HGLOBAL g = r ? LoadResource(g_hInst, r) : nullptr;
    const auto* p = g ? static_cast<const unsigned char*>(LockResource(g)) : nullptr;
    const DWORD n = r ? SizeofResource(g_hInst, r) : 0;
    for (DWORD i = 0; p && i + sizeof(VS_FIXEDFILEINFO) <= n; i += 4) {
        const auto* f = reinterpret_cast<const VS_FIXEDFILEINFO*>(p + i);
        if (f->dwSignature == 0xFEEF04BD) {
            sprintf_s(out, size, "%u.%u.%u", HIWORD(f->dwFileVersionMS), LOWORD(f->dwFileVersionMS), HIWORD(f->dwFileVersionLS));
            return true;
        }
    }
    return false;
}

// Posts the start message silently, as the scripts' game.message(text, false) did: the game's TethysGame::AddMessage
// export (static __fastcall: pixel x, pixel y, text, player -1 for all, sound) always plays a sound, so the sound
// manager's on flag (0x56D250 + 0x920) is off for the call, as OP2Lua does it.
static void PostStartMessage() {
    using AddMessage = void(__fastcall*)(int, int, const char*, int, int);
    static const auto add = reinterpret_cast<AddMessage>(
        GetProcAddress(GetModuleHandleA(nullptr), "?AddMessage@TethysGame@@SIXHHPADHH@Z"));
    if (!add || !g_startMessage[0]) return;
    int* soundOn = reinterpret_cast<int*>(0x56D250 + 0x920);
    const int was = *soundOn;
    *soundOn = 0;
    add(0, 0, g_startMessage, -1, 0);
    *soundOn = was;
}

// The Game Options pane's version line: gameOptionsView (0x566708) + 0x254, which its constructor (0x464FE0) fills
// with "%s %s\n" and OPU 1.4.1 overwrites with "Version 1.4.1-OPU" (OPUPatch.dll copies 18 bytes there); the buffer
// runs to the game-speed copy at +0x388 (307 characters). A Renegades game shows "<OPU's version> REN <release>" there
// ("1.4.1 REN 1.2.18", 16 characters: as long as OPU's line, so it fits the pane).
static const uintptr_t kVersionLine = 0x566708 + 0x254;
static const size_t kVersionLineSize = 0x388 - 0x254;
static char g_versionLine[64] = "";
static char g_versionLineStock[64] = "";
static bool g_versionLinePatched = false;

// A file's version resource as "1.2.0.7", or "" when it has none.
static std::string FileVersion(const char* path) {
    DWORD ignored = 0;
    const DWORD n = GetFileVersionInfoSizeA(path, &ignored);
    std::vector<unsigned char> buf(n);
    VS_FIXEDFILEINFO* f = nullptr;
    UINT len = 0;
    if (!n || !GetFileVersionInfoA(path, 0, n, buf.data()) ||
        !VerQueryValueA(buf.data(), "\\", reinterpret_cast<void**>(&f), &len) || !f) {
        return "";
    }
    char s[32];
    sprintf_s(s, "%u.%u.%u.%u", HIWORD(f->dwFileVersionMS), LOWORD(f->dwFileVersionMS), HIWORD(f->dwFileVersionLS),
              LOWORD(f->dwFileVersionLS));
    return s;
}

// Puts the Renegades version line in, once the pane holds OPU's "Version ..." (again at each mission's start, in
// case OPU writes its line after this module's InitMod). Anything else there is left alone.
static void SetVersionLine() {
    if (!g_versionLine[0]) return;
    const char* now = reinterpret_cast<const char*>(kVersionLine);
    if (strcmp(now, g_versionLine) == 0) return;
    if (strncmp(now, "Version ", 8) != 0) return;
    if (!g_versionLinePatched) strncpy_s(g_versionLineStock, now, _TRUNCATE);
    g_versionLinePatched = Poke(kVersionLine, g_versionLine, strlen(g_versionLine) + 1) || g_versionLinePatched;
}

// OPU's version from its own line in OPUPatch.dll's image ("Version 1.4.1-OPU" gives "1.4.1"; OPUPatch.dll has no
// version resource), or "" when OPUPatch isn't loaded or holds no such line.
static std::string OpuVersion() {
    HMODULE m = GetModuleHandleA("OPUPatch.dll");
    if (!m) return "";
    const auto* base = reinterpret_cast<const unsigned char*>(m);
    const auto* nt = reinterpret_cast<const IMAGE_NT_HEADERS*>(base + reinterpret_cast<const IMAGE_DOS_HEADER*>(base)->e_lfanew);
    const size_t size = nt->OptionalHeader.SizeOfImage;
    for (size_t i = 0; i + 12 <= size; ++i) {
        if (base[i] != 'V' || memcmp(base + i, "Version ", 8) != 0) continue;
        size_t n = 0;
        while (i + 8 + n < size && (isdigit(base[i + 8 + n]) || base[i + 8 + n] == '.')) ++n;
        if (n && i + 8 + n + 4 <= size && memcmp(base + i + 8 + n, "-OPU", 4) == 0) {
            return std::string(reinterpret_cast<const char*>(base + i + 8), n);
        }
    }
    return "";
}

// The game's, OPU's and the release's versions in the log, and the pane's version line made from them: OPU's version
// from OPUPatch.dll (OpuVersion), Outpost2.exe's from its version resource, the release from this module's.
static void UseVersionLine() {
    char exe[MAX_PATH] = "";
    GetModuleFileNameA(nullptr, exe, MAX_PATH);
    const std::string opu = OpuVersion();
    char release[32] = "";
    ModuleVersion(release, sizeof(release));
    Log("versions: Outpost2.exe %s, OPU %s, Renegades %s; the pane's line is \"%.40s\"", FileVersion(exe).c_str(),
        opu.empty() ? "? (OPUPatch.dll not loaded, or no \"Version ...-OPU\" in it)" : opu.c_str(), release[0] ? release : "?",
        reinterpret_cast<const char*>(kVersionLine));
    if (opu.empty() || !release[0]) return;
    sprintf_s(g_versionLine, "%s REN %s", opu.c_str(), release);
    SetVersionLine();
    Log("version line: \"%s\" (%s)", g_versionLine,
        g_versionLinePatched ? "patched" : "not yet: OPU's line isn't there; tried again at the mission's start");
}

// The game's TethysGame::StartGame, called on with the player's name filled in, then the start message once the
// mission has started. __fastcall with the unused EDX takes `this` in ECX and the GameStartInfo on the stack, popped
// by the callee, as the __thiscall call site expects.
static int __fastcall StartGameHook(void* game, void*, char* gsi) {
    if (g_playerName[0]) memcpy(gsi + kGsiPlayerName, g_playerName, kNameSize);
    SetVersionLine();
    using StartGame = int(__thiscall*)(void*, char*);
    const int ok = reinterpret_cast<StartGame>(kStartGame)(game, gsi);
    if (ok) PostStartMessage();
    return ok;
}

// The mission's start (TApp::OnLoadScript's call of TethysGame::StartGame at 0x487758) goes through StartGameHook:
// - the player's name from the loader's Preferences (`[Game] Name` in OPU\outpost2.ini, at most 12 characters), so the
//   game's player record has it as in a multiplayer game (tools that read the record, saved games); without one, the
//   game's own empty name;
// - the "Renegades v<release>" start message.
static void UseStartHook() {
    char name[64] = "";
    GetPrivateProfileStringA("Game", "Name", "", name, sizeof(name), (g_dir + "outpost2.ini").c_str());
    strncpy_s(g_playerName, name, _TRUNCATE);
    char version[32] = "";
    if (ModuleVersion(version, sizeof(version))) sprintf_s(g_startMessage, "Renegades v%s", version);
    const unsigned char* at = reinterpret_cast<const unsigned char*>(kStartGameCall);
    const uintptr_t target = kStartGameCall + 5 + *reinterpret_cast<const int32_t*>(at + 1);
    if (at[0] != 0xE8 || target != kStartGame) {
        Log("start: the code at 0x487758 isn't the expected call: another build of the game? Left alone.");
        return;
    }
    memcpy(g_startGameCallStock, at, sizeof(g_startGameCallStock));
    unsigned char ours[5] = { 0xE8 };
    const int32_t rel = static_cast<int32_t>(reinterpret_cast<uintptr_t>(&StartGameHook) - (kStartGameCall + 5));
    memcpy(ours + 1, &rel, 4);
    g_startGamePatched = Poke(kStartGameCall, ours, sizeof(ours));
    Log("start: name '%s' for player 0, message '%s' (%s)", g_playerName[0] ? g_playerName : "(the game's own)",
        g_startMessage[0] ? g_startMessage : "(no version found)", g_startGamePatched ? "patched" : "NOT patched");
}

// Saved games as SGAMEn.REN and SGAME10.REN (see kSaveExts).
static void UseRenSaves() {
    int done = 0;
    for (size_t i = 0; i < sizeof(kSaveExts) / sizeof(kSaveExts[0]); ++i) {
        if (memcmp(reinterpret_cast<void*>(kSaveExts[i]), kSaveExtStock[i], 3) != 0) {
            Log("saves: the text at 0x%08X isn't '%s': another build of the game? Left alone.",
                static_cast<unsigned>(kSaveExts[i]), kSaveExtStock[i]);
            continue;
        }
        g_saveExtPatched[i] = Poke(kSaveExts[i], "REN", 3);
        done += g_saveExtPatched[i];
    }
    Log("saves: SGAMEn.REN and SGAME10.REN, the extension in %d of 4 places", done);
}

// OPU's save tag in OPUPatch.dll's image, or null when OPUPatch isn't loaded or holds no such string.
static char* FindOpuSaveTag() {
    HMODULE m = GetModuleHandleA("OPUPatch.dll");
    if (!m) return nullptr;
    auto* base = reinterpret_cast<unsigned char*>(m);
    auto* dos = reinterpret_cast<IMAGE_DOS_HEADER*>(base);
    auto* nt = reinterpret_cast<IMAGE_NT_HEADERS*>(base + dos->e_lfanew);
    const size_t size = nt->OptionalHeader.SizeOfImage, len = sizeof(kOpuSaveTag);   // with the NUL
    for (size_t i = 0; i + len <= size; ++i) {
        if (base[i] == 'O' && memcmp(base + i, kOpuSaveTag, len) == 0) return reinterpret_cast<char*>(base + i);
    }
    return nullptr;
}

// The Renegades save tag (see kRenSaveTag). OPUPatch is loaded before this module (its op2ext entry comes first).
static void UseRenSaveTag() {
    char* tag = FindOpuSaveTag();
    if (!tag) {
        Log("save tag: OPU's \"%s\" not found in OPUPatch.dll: saves keep the game's tag", kOpuSaveTag);
        return;
    }
    if (Poke(reinterpret_cast<uintptr_t>(tag), kRenSaveTag, sizeof(kRenSaveTag))) g_saveTag = tag;
    Log("save tag: \"%s\" (%s): only a Renegades game loads its saves", kRenSaveTag, g_saveTag ? "patched" : "NOT patched");
}

static bool LoadEmblem() {
    // the loader's folder (OPU\renegades) first, then beside this module
    std::string path = g_dir + "renegades\\renegmbl.raw";
    if (!FileExists(path)) path = g_dir + "renegmbl.raw";
    FILE* f = nullptr;
    if (fopen_s(&f, path.c_str(), "rb") != 0 || !f) {
        Log("emblem: renegmbl.raw not found in %sRenegades or %s", g_dir.c_str(), g_dir.c_str());
        return false;
    }
    fseek(f, 0, SEEK_END);
    long n = ftell(f);
    fseek(f, 0, SEEK_SET);
    g_emblem.resize(n > 0 ? n : 0);
    size_t got = n > 0 ? fread(g_emblem.data(), 1, g_emblem.size(), f) : 0;
    fclose(f);
    if (n != 156 * 189 || got != g_emblem.size()) {
        Log("emblem: %s is %ld bytes, expected %d (156 x 189)", path.c_str(), n, 156 * 189);
        g_emblem.clear();
        return false;
    }
    Log("emblem: loaded %s", path.c_str());
    return true;
}

// The emblem table entry holds an offset from the graphics object's pixel base, so it can only be set once that
// object exists; the base is checked again each time, in case the game makes a new one.
static DWORD WINAPI EmblemThread(LPVOID) {
    DWORD lastBase = 0;
    HMODULE lastRes = *reinterpret_cast<volatile HMODULE*>(kResHandle);
    while (!InterlockedCompareExchange(&g_stop, 0, 0)) {
        // the in-game art handle: log each change, to see when the game loads its resource DLL again
        HMODULE res = *reinterpret_cast<volatile HMODULE*>(kResHandle);
        if (res != lastRes) {
            char name[MAX_PATH] = "?";
            if (res) GetModuleFileNameA(res, name, MAX_PATH);
            HANDLE title = *reinterpret_cast<volatile HANDLE*>(kFrameImages + 14 * 4);
            BITMAP bm = {};
            if (title) GetObjectA(title, sizeof(bm), &bm);
            Log("ren2res: the game's art handle changed to 0x%08lX (%s); frame title now %ld x %ld",
                static_cast<DWORD>(reinterpret_cast<uintptr_t>(res)), name, bm.bmWidth, bm.bmHeight);
            lastRes = res;
        }
        DWORD gfx = *reinterpret_cast<volatile DWORD*>(kGraphics);
        DWORD base = gfx ? *reinterpret_cast<volatile DWORD*>(gfx + 0xEC) : 0;
        if (base) {
            DWORD want = static_cast<DWORD>(reinterpret_cast<uintptr_t>(g_emblem.data())) - base;
            DWORD now = *reinterpret_cast<volatile DWORD*>(kEmblemEntry);
            if (now != want) {
                if (!g_emblemSaved) {
                    g_emblemOriginal = now;
                    g_emblemSaved = true;
                }
                Poke(kEmblemEntry, &want, sizeof(want));
                if (base != lastBase) Log("emblem: set (graphics 0x%08lX, base 0x%08lX, entry was 0x%08lX)", gfx, base, now);
                lastBase = base;
            }
        }
        Sleep(200);
    }
    return 0;
}

extern "C" __declspec(dllexport) void InitMod(const char* iniSectionName) {
    char path[MAX_PATH] = "";
    GetModuleFileNameA(g_hInst, path, MAX_PATH);
    g_dir = path;
    g_dir = g_dir.substr(0, g_dir.find_last_of("\\/") + 1);
    // the log goes in OPU\logs, beside OP2Lua's and the loader's (made if the release's empty folder is gone)
    CreateDirectoryA((g_dir + "logs").c_str(), nullptr);
    DWORD a = GetFileAttributesA((g_dir + "logs").c_str());
    g_logPath = g_dir + ((a != INVALID_FILE_ATTRIBUTES && (a & FILE_ATTRIBUTE_DIRECTORY)) ? "logs\\Renegades-module.log" : "Renegades-module.log");

    char flag[8] = "";
    GetEnvironmentVariableA("RENEGADES_LAUNCH", flag, sizeof(flag));
    g_active = strcmp(flag, "1") == 0;
    Log("=== InitMod (section '%s'): %s", iniSectionName ? iniSectionName : "?",
        g_active ? "a Renegades launch" : "not a Renegades launch, doing nothing");
    if (!g_active) return;

    UseRen2Res();
    UseRenegadesTexts();
    UseDifficulty();
    UseSeed();
    UseStartHook();
    UseRenSaves();
    UseRenSaveTag();
    UseVersionLine();
    // The menu shell swap is opt-in (RENEGADES_SHELL=1): in OPU 1.4.1 the game hung going back to its menus with
    // RENShell.dll (2026-11-18), and the loader is the menu anyway.
    char shellFlag[8] = "";
    GetEnvironmentVariableA("RENEGADES_SHELL", shellFlag, sizeof(shellFlag));
    if (strcmp(shellFlag, "1") == 0) {
        UseRenShell();
    } else {
        Log("shell: the stock menu shell (RENEGADES_SHELL=1 tries Renegades' renshell.dll)");
    }
    if (LoadEmblem()) g_thread = CreateThread(nullptr, 0, EmblemThread, nullptr, 0, nullptr);
}

extern "C" __declspec(dllexport) void DestroyMod() {
    if (!g_active) return;
    InterlockedExchange(&g_stop, 1);
    if (g_thread) {
        WaitForSingleObject(g_thread, 2000);
        CloseHandle(g_thread);
        g_thread = nullptr;
    }
    if (g_emblemSaved) Poke(kEmblemEntry, &g_emblemOriginal, sizeof(g_emblemOriginal));
    if (g_namePatched) Poke(kResName, "out2res.dll", 12);
    if (g_shellPatched) Poke(kShellName, "OP2Shell.dll", 13);
    if (g_difficultyPatched) Poke(kStartDifficulty, kStartDifficultyStock, sizeof(kStartDifficultyStock));
    if (g_seedPatched) Poke(kStartSeed, kStartSeedStock, sizeof(kStartSeedStock));
    if (g_startGamePatched) Poke(kStartGameCall, g_startGameCallStock, sizeof(g_startGameCallStock));
    for (size_t i = 0; i < sizeof(kSaveExts) / sizeof(kSaveExts[0]); ++i) {
        if (g_saveExtPatched[i]) Poke(kSaveExts[i], kSaveExtStock[i], 3);
    }
    if (g_saveTag) Poke(reinterpret_cast<uintptr_t>(g_saveTag), kOpuSaveTag, sizeof(kOpuSaveTag));
    if (g_versionLinePatched) Poke(kVersionLine, g_versionLineStock, strlen(g_versionLineStock) + 1);
    for (size_t i = 0; i < sizeof(kTexts) / sizeof(kTexts[0]); ++i) {
        if (g_textPatched[i]) Poke(kTexts[i], g_textOriginal[i], 9);
    }
    Log("=== DestroyMod: put back what was changed");
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        g_hInst = hModule;
        DisableThreadLibraryCalls(hModule);
    }
    return TRUE;
}
