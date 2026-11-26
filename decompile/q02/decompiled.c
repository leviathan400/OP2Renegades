// ---- 11001000 FUN_11001000  (called by: FUN_11001050@11001050, FUN_1100106e@1100106e)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_11001000(uint param_1,undefined4 param_2)

{
  if (param_1 < 0x16) {
    **(undefined4 **)(&DAT_11014054 + param_1 * 4) = param_2;
    _DAT_00567140 = param_1;
    _DAT_00567144 = 0x565664;
    (*(code *)0x458e00)();
  }
  return;
}


// ---- 11001039 FUN_11001039  (called by: FUN_11001050@11001050)

undefined4 __cdecl FUN_11001039(uint param_1)

{
  if (param_1 < 0x16) {
    return **(undefined4 **)(&DAT_11014054 + param_1 * 4);
  }
  return 0xffffffff;
}


// ---- 11001050 FUN_11001050  (called by: FUN_11005e31@11005e31)

int FUN_11001050(void)

{
  int iVar1;
  
  iVar1 = FUN_11001039(0xe);
  if (iVar1 != 0) {
    FUN_11001000(0xe,1);
  }
  return iVar1;
}


// ---- 1100106e FUN_1100106e  (called by: FUN_11005e31@11005e31)

void FUN_1100106e(void)

{
  FUN_11001000(0xe,0);
  return;
}


// ---- 1100107a FUN_1100107a  (called by: FUN_11005e63@11005e63)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1100107a(void)

{
  HANDLE hFile;
  DWORD _Size;
  DWORD local_4;
  
  DAT_11016230 = _DAT_004ff814;
  hFile = CreateFileA(s_renegmbl_raw_110140ac,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                      (HANDLE)0x0);
  _Size = GetFileSize(hFile,(LPDWORD)0x0);
  DAT_11016234 = _malloc(_Size);
  ReadFile(hFile,DAT_11016234,_Size,&local_4,(LPOVERLAPPED)0x0);
  CloseHandle(hFile);
  _DAT_004ff814 = (int)DAT_11016234 - *(int *)(_DAT_00546b98 + 0xec);
  return;
}


// ---- 110010ef FUN_110010ef  (called by: FUN_11005e63@11005e63)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_110010ef(void)

{
  _DAT_004ff814 = DAT_11016230;
  FUN_110085b8(DAT_11016234);
  return;
}


// ---- 11001106 FUN_11001106  (called by: FUN_11006c74@11006c74)

undefined4 __cdecl FUN_11001106(undefined4 param_1,LPCSTR param_2)

{
  int iVar1;
  FILE *_File;
  uint uVar2;
  undefined1 unaff_BP;
  char local_4e4c [19952];
  undefined4 uStackY_5c;
  undefined4 uVar3;
  
  FUN_11008ba0(unaff_BP);
  if (param_2 == (LPCSTR)0x0) {
    uVar3 = 1;
  }
  else {
    iVar1 = BASS_GetVersion();
    if (iVar1 == 0x20002) {
      BASS_SetConfig();
      BASS_Init();
      iVar1 = BASS_StreamCreateFile();
      if ((iVar1 == 0) && (iVar1 = BASS_MusicLoad(), iVar1 == 0)) {
        uVar3 = 4;
      }
      else {
        _File = (FILE *)FUN_11008b89(param_2,&DAT_11014878);
        if (_File != (FILE *)0x0) {
          BASS_ChannelGetInfo();
          FUN_11008a1f((char *)&WAVE_11014860,0x14,1,(int *)_File);
          FUN_11008a1f(local_4e4c + 0x4e34,0x10,1,(int *)_File);
          FUN_11008a1f(&DAT_11014854,8,1,(int *)_File);
          while (iVar1 = BASS_ChannelIsActive(), iVar1 != 0) {
            uVar2 = BASS_ChannelGetData();
            FUN_11008a1f(local_4e4c,1,uVar2,(int *)_File);
            BASS_ChannelGetPosition();
          }
          FUN_110088b9((int *)_File);
          iVar1 = FUN_11008736((char *)_File);
          FUN_1100867d((int *)_File,4,0);
          __putw(iVar1 + -8,_File);
          FUN_110088b9((int *)_File);
          FUN_1100867d((int *)_File,0x28,0);
          __putw(iVar1 + -0x2c,_File);
          FUN_110088b9((int *)_File);
          uStackY_5c = 0x1100127c;
          FUN_11008600(_File);
          return 0;
        }
        uVar3 = 5;
      }
    }
    else {
      uVar3 = 2;
    }
  }
  return uVar3;
}


// ---- 11001286 FUN_11001286  (called by: FUN_110012ee@110012ee)

void __cdecl FUN_11001286(int param_1,int param_2,int param_3,int param_4,map_id param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_4;
  iVar1 = param_2;
  iVar3 = param_3;
  if (param_3 < param_1) {
    iVar3 = param_1;
    param_1 = param_3;
  }
  if (param_4 < param_2) {
    param_4 = param_2;
    param_2 = iVar2;
  }
  for (; param_1 <= iVar3; param_1 = param_1 + 1) {
    TethysGame::CreateWallOrTube(param_1,iVar1,0,param_5);
  }
  for (; param_2 <= param_4; param_2 = param_2 + 1) {
    TethysGame::CreateWallOrTube(param_3,param_2,0,param_5);
  }
  return;
}


// ---- 110012ee FUN_110012ee  (called by: InitProc@11005597)

void __cdecl FUN_110012ee(undefined4 param_1,int param_2,int param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_c;
  int local_8;
  
  piVar1 = param_4;
  local_c = 0;
  local_8 = 0;
  if (0 < *param_4) {
    param_4 = (int *)0x0;
    do {
      piVar2 = (int *)((int)param_4 + piVar1[1]);
      TethysGame::CreateUnit(&local_c,piVar2[2],*piVar2 + param_2,piVar2[1] + param_3,param_1,0,0);
      Unit::DoSetLights((Unit *)&local_c,1);
      local_8 = local_8 + 1;
      param_4 = param_4 + 3;
    } while (local_8 < *piVar1);
  }
  iVar3 = 0;
  if (0 < piVar1[2]) {
    param_4 = (int *)0x0;
    do {
      piVar2 = (int *)((int)param_4 + piVar1[3]);
      FUN_11001286(*piVar2 + param_2,piVar2[1] + param_3,piVar2[2] + param_2,piVar2[3] + param_3,
                   0x11);
      param_4 = param_4 + 4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < piVar1[2]);
  }
  iVar3 = 0;
  if (0 < piVar1[4]) {
    param_4 = (int *)0x0;
    do {
      piVar2 = (int *)((int)param_4 + piVar1[5]);
      FUN_11001286(*piVar2 + param_2,piVar2[1] + param_3,piVar2[2] + param_2,piVar2[3] + param_3,
                   0x12);
      param_4 = param_4 + 4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < piVar1[4]);
  }
  local_8 = 0;
  if (0 < piVar1[6]) {
    param_4 = (int *)0x0;
    do {
      piVar2 = (int *)(piVar1[7] + (int)param_4);
      TethysGame::CreateUnit
                (&local_c,piVar2[2],*piVar2 + param_2,piVar2[1] + param_3,param_1,piVar2[3],
                 piVar2[4]);
      Unit::DoSetLights((Unit *)&local_c,1);
      local_8 = local_8 + 1;
      param_4 = param_4 + 5;
    } while (local_8 < piVar1[6]);
  }
  return;
}


// ---- 11001417 FUN_11001417  (called by: InitProc@11005597)

void __cdecl FUN_11001417(int param_1,int param_2)

{
  int *piVar1;
  
  if (0 < param_1) {
    piVar1 = (int *)(param_2 + 0x10);
    do {
      TethysGame::CreateBeacon(piVar1[-2],piVar1[-4],piVar1[-3],piVar1[-1],*piVar1,piVar1[1]);
      piVar1 = piVar1 + 6;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}


// ---- 11001448 FUN_11001448  (called by: FUN_11001448@11001448, FUN_11002ecd@11002ecd)

void FUN_11001448(void)

{
  int unaff_EBP;
  int iVar1;
  int iVar2;
  
  FUN_11008fa8();
  iVar1 = *(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar1 == *(int *)(unaff_EBP + 0x14)) {
    if (*(int *)(unaff_EBP + 0x1c) == 0x11) {
      iVar2 = *(int *)(unaff_EBP + 0x10);
      *(int *)(unaff_EBP + -0x14) = iVar1;
      *(int *)(unaff_EBP + -0x10) = iVar2;
      BuildingGroup::RecordTube((BuildingGroup *)(unaff_EBP + 8),(LOCATION *)(unaff_EBP + -0x14));
    }
    else {
      iVar2 = *(int *)(unaff_EBP + 0x10);
      *(int *)(unaff_EBP + -0x14) = iVar1;
      *(int *)(unaff_EBP + -0x10) = iVar2;
      BuildingGroup::RecordWall
                ((BuildingGroup *)(unaff_EBP + 8),(LOCATION *)(unaff_EBP + -0x14),
                 *(map_id *)(unaff_EBP + 0x1c));
    }
    if (iVar2 == *(int *)(unaff_EBP + 0x18)) {
      *(undefined4 *)(unaff_EBP + 0x10) = 0;
    }
    else {
      *(uint *)(unaff_EBP + 0x10) = ((*(int *)(unaff_EBP + 0x18) < iVar2) - 1 & 2) - 1;
    }
    do {
      iVar2 = iVar2 + *(int *)(unaff_EBP + 0x10);
      if (*(int *)(unaff_EBP + 0x1c) == 0x11) {
        *(int *)(unaff_EBP + -0x14) = iVar1;
        *(int *)(unaff_EBP + -0x10) = iVar2;
        BuildingGroup::RecordTube((BuildingGroup *)(unaff_EBP + 8),(LOCATION *)(unaff_EBP + -0x14));
      }
      else {
        *(int *)(unaff_EBP + -0x1c) = iVar1;
        *(int *)(unaff_EBP + -0x18) = iVar2;
        BuildingGroup::RecordWall
                  ((BuildingGroup *)(unaff_EBP + 8),(LOCATION *)(unaff_EBP + -0x1c),
                   *(map_id *)(unaff_EBP + 0x1c));
      }
    } while (iVar2 != *(int *)(unaff_EBP + 0x18));
  }
  else {
    iVar2 = *(int *)(unaff_EBP + 0x10);
    if (iVar2 == *(int *)(unaff_EBP + 0x18)) {
      if (*(int *)(unaff_EBP + 0x1c) == 0x11) {
        *(int *)(unaff_EBP + 0xc) = iVar1;
        *(int *)(unaff_EBP + 0x10) = iVar2;
        BuildingGroup::RecordTube((BuildingGroup *)(unaff_EBP + 8),(LOCATION *)(unaff_EBP + 0xc));
      }
      else {
        *(int *)(unaff_EBP + 0xc) = iVar1;
        *(int *)(unaff_EBP + 0x10) = iVar2;
        BuildingGroup::RecordWall
                  ((BuildingGroup *)(unaff_EBP + 8),(LOCATION *)(unaff_EBP + 0xc),
                   *(map_id *)(unaff_EBP + 0x1c));
      }
      *(uint *)(unaff_EBP + 0x10) = ((*(int *)(unaff_EBP + 0x14) < iVar1) - 1 & 2) - 1;
      do {
        iVar1 = iVar1 + *(int *)(unaff_EBP + 0x10);
        if (*(int *)(unaff_EBP + 0x1c) == 0x11) {
          *(int *)(unaff_EBP + -0x1c) = iVar1;
          *(int *)(unaff_EBP + -0x18) = iVar2;
          BuildingGroup::RecordTube
                    ((BuildingGroup *)(unaff_EBP + 8),(LOCATION *)(unaff_EBP + -0x1c));
        }
        else {
          *(int *)(unaff_EBP + -0x14) = iVar1;
          *(int *)(unaff_EBP + -0x10) = iVar2;
          BuildingGroup::RecordWall
                    ((BuildingGroup *)(unaff_EBP + 8),(LOCATION *)(unaff_EBP + -0x14),
                     *(map_id *)(unaff_EBP + 0x1c));
        }
      } while (iVar1 != *(int *)(unaff_EBP + 0x14));
    }
    else {
      FUN_11001448();
      FUN_11001448();
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 110015bd GetCargo  (called by: -)

/* public: enum map_id __thiscall IUnit::GetCargo(void) */

map_id __thiscall IUnit::GetCargo(IUnit *this)

{
  map_id mVar1;
  
                    /* WARNING: Could not recover jumptable at 0x110015bd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x15bd  2  ?GetCargo@IUnit@@QAE?AW4map_id@@XZ */
  mVar1 = Unit::GetCargo((Unit *)this);
  return mVar1;
}


// ---- 110015c3 operator=  (called by: -)

/* public: class IUnit & __thiscall IUnit::operator=(class IUnit const &) */

IUnit * __thiscall IUnit::operator=(IUnit *this,IUnit *param_1)

{
                    /* 0x15c3  1  ??4IUnit@@QAEAAV0@ABV0@@Z */
  Unit::operator=((Unit *)this,(Unit *)param_1);
  return this;
}


// ---- 110015fa FUN_110015fa  (called by: -)

void FUN_110015fa(void)

{
  FUN_110017de();
  return;
}


// ---- 11001604 FUN_11001604  (called by: -)

void FUN_11001604(void)

{
  FUN_11009045(0x11001610);
  return;
}


// ---- 11001610 FUN_11001610  (called by: -)

void FUN_11001610(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_11008fa8();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0x24;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x130));
  *(undefined1 *)(unaff_EBP + -4) = 0x23;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 300));
  *(undefined1 *)(unaff_EBP + -4) = 0x22;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x128));
  *(undefined1 *)(unaff_EBP + -4) = 0x21;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x124));
  *(undefined1 *)(unaff_EBP + -4) = 0x20;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x120));
  *(undefined1 *)(unaff_EBP + -4) = 0x1f;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x11c));
  *(undefined1 *)(unaff_EBP + -4) = 0x1e;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x118));
  *(undefined1 *)(unaff_EBP + -4) = 0x1d;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x114));
  *(undefined1 *)(unaff_EBP + -4) = 0x1c;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xb8));
  *(undefined1 *)(unaff_EBP + -4) = 0x1b;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xb4));
  *(undefined1 *)(unaff_EBP + -4) = 0x1a;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xb0));
  *(undefined1 *)(unaff_EBP + -4) = 0x19;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xac));
  *(undefined1 *)(unaff_EBP + -4) = 0x18;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xa8));
  *(undefined1 *)(unaff_EBP + -4) = 0x17;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xa4));
  *(undefined1 *)(unaff_EBP + -4) = 0x16;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xa0));
  *(undefined1 *)(unaff_EBP + -4) = 0x15;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x9c));
  *(undefined1 *)(unaff_EBP + -4) = 0x14;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x98));
  *(undefined1 *)(unaff_EBP + -4) = 0x13;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x94));
  *(undefined1 *)(unaff_EBP + -4) = 0x12;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x90));
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x8c));
  *(undefined1 *)(unaff_EBP + -4) = 0x10;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x88));
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x84));
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x80));
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x7c));
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x78));
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x74));
  *(undefined1 *)(unaff_EBP + -4) = 10;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x70));
  *(undefined1 *)(unaff_EBP + -4) = 9;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x6c));
  *(undefined1 *)(unaff_EBP + -4) = 8;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x68));
  *(undefined1 *)(unaff_EBP + -4) = 7;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 100));
  *(undefined1 *)(unaff_EBP + -4) = 6;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x60));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x5c));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x58));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x54));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x50));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x4c));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x48));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x44));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 110017de FUN_110017de  (called by: FUN_110015fa@110015fa)

IUnit * FUN_110017de(void)

{
  int *piVar1;
  IUnit *this;
  int unaff_EBP;
  IUnit *this_00;
  
  FUN_11008fa8();
  *(IUnit **)(unaff_EBP + -0x14) = this;
  IUnit::IUnit(this);
  IUnit::IUnit(this + 4);
  IUnit::IUnit(this + 8);
  IUnit::IUnit(this + 0xc);
  IUnit::IUnit(this + 0x10);
  IUnit::IUnit(this + 0x14);
  IUnit::IUnit(this + 0x18);
  IUnit::IUnit(this + 0x1c);
  IUnit::IUnit(this + 0x20);
  IUnit::IUnit(this + 0x24);
  IUnit::IUnit(this + 0x28);
  IUnit::IUnit(this + 0x2c);
  IUnit::IUnit(this + 0x30);
  IUnit::IUnit(this + 0x34);
  IUnit::IUnit(this + 0x38);
  IUnit::IUnit(this + 0x3c);
  IUnit::IUnit(this + 0x40);
  FightGroup::FightGroup((FightGroup *)(this + 0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FightGroup::FightGroup((FightGroup *)(this + 0x48));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FightGroup::FightGroup((FightGroup *)(this + 0x4c));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FightGroup::FightGroup((FightGroup *)(this + 0x50));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FightGroup::FightGroup((FightGroup *)(this + 0x54));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FightGroup::FightGroup((FightGroup *)(this + 0x58));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FightGroup::FightGroup((FightGroup *)(this + 0x5c));
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FightGroup::FightGroup((FightGroup *)(this + 0x60));
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FightGroup::FightGroup((FightGroup *)(this + 100));
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FightGroup::FightGroup((FightGroup *)(this + 0x68));
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FightGroup::FightGroup((FightGroup *)(this + 0x6c));
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FightGroup::FightGroup((FightGroup *)(this + 0x70));
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FightGroup::FightGroup((FightGroup *)(this + 0x74));
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FightGroup::FightGroup((FightGroup *)(this + 0x78));
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  FightGroup::FightGroup((FightGroup *)(this + 0x7c));
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  FightGroup::FightGroup((FightGroup *)(this + 0x80));
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  FightGroup::FightGroup((FightGroup *)(this + 0x84));
  *(undefined1 *)(unaff_EBP + -4) = 0x10;
  FightGroup::FightGroup((FightGroup *)(this + 0x88));
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  FightGroup::FightGroup((FightGroup *)(this + 0x8c));
  *(undefined1 *)(unaff_EBP + -4) = 0x12;
  FightGroup::FightGroup((FightGroup *)(this + 0x90));
  *(undefined1 *)(unaff_EBP + -4) = 0x13;
  FightGroup::FightGroup((FightGroup *)(this + 0x94));
  *(undefined1 *)(unaff_EBP + -4) = 0x14;
  BuildingGroup::BuildingGroup((BuildingGroup *)(this + 0x98));
  *(undefined1 *)(unaff_EBP + -4) = 0x15;
  BuildingGroup::BuildingGroup((BuildingGroup *)(this + 0x9c));
  *(undefined1 *)(unaff_EBP + -4) = 0x16;
  BuildingGroup::BuildingGroup((BuildingGroup *)(this + 0xa0));
  *(undefined1 *)(unaff_EBP + -4) = 0x17;
  BuildingGroup::BuildingGroup((BuildingGroup *)(this + 0xa4));
  *(undefined1 *)(unaff_EBP + -4) = 0x18;
  BuildingGroup::BuildingGroup((BuildingGroup *)(this + 0xa8));
  *(undefined1 *)(unaff_EBP + -4) = 0x19;
  BuildingGroup::BuildingGroup((BuildingGroup *)(this + 0xac));
  *(undefined1 *)(unaff_EBP + -4) = 0x1a;
  MiningGroup::MiningGroup((MiningGroup *)(this + 0xb0));
  *(undefined1 *)(unaff_EBP + -4) = 0x1b;
  MiningGroup::MiningGroup((MiningGroup *)(this + 0xb4));
  *(undefined1 *)(unaff_EBP + -4) = 0x1c;
  MiningGroup::MiningGroup((MiningGroup *)(this + 0xb8));
  *(undefined1 *)(unaff_EBP + -4) = 0x1d;
  *(undefined4 *)(this + 0xbc) = 0;
  *(undefined4 *)(this + 0xc0) = 0;
  MAP_RECT::MAP_RECT((MAP_RECT *)(this + 0xc4));
  Trigger::Trigger((Trigger *)(this + 0x114));
  *(undefined1 *)(unaff_EBP + -4) = 0x1e;
  Trigger::Trigger((Trigger *)(this + 0x118));
  *(undefined1 *)(unaff_EBP + -4) = 0x1f;
  Trigger::Trigger((Trigger *)(this + 0x11c));
  *(undefined1 *)(unaff_EBP + -4) = 0x20;
  Trigger::Trigger((Trigger *)(this + 0x120));
  *(undefined1 *)(unaff_EBP + -4) = 0x21;
  Trigger::Trigger((Trigger *)(this + 0x124));
  *(undefined1 *)(unaff_EBP + -4) = 0x22;
  Trigger::Trigger((Trigger *)(this + 0x128));
  *(undefined1 *)(unaff_EBP + -4) = 0x23;
  Trigger::Trigger((Trigger *)(this + 300));
  *(undefined1 *)(unaff_EBP + -4) = 0x24;
  Trigger::Trigger((Trigger *)(this + 0x130));
  *(undefined1 *)(unaff_EBP + -4) = 0x25;
  this_00 = this + 0x134;
  *(undefined4 *)(unaff_EBP + -0x10) = 6;
  do {
    IUnit::IUnit(this_00);
    this_00 = this_00 + 4;
    piVar1 = (int *)(unaff_EBP + -0x10);
    *piVar1 = *piVar1 + -1;
  } while (*piVar1 != 0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined4 *)(this + 0xf8) = 0;
  *(undefined4 *)(this + 0xfc) = 0;
  *(undefined4 *)(this + 0x100) = 0;
  *(undefined4 *)(this + 0x104) = 0;
  this[0xec] = (IUnit)0x0;
  this[0x108] = (IUnit)0x1;
  this[0x109] = (IUnit)0x1;
  this[0x10a] = (IUnit)0x1;
  *(undefined4 *)(this + 0x10c) = 0;
  this[0xed] = (IUnit)0x0;
  this[0x110] = (IUnit)0x0;
  this[0x111] = (IUnit)0x0;
  this[0x112] = (IUnit)0x0;
  *(undefined4 *)(this + 0x14c) = 0xe;
  *(undefined4 *)(this + 0x150) = 0xf;
  *(undefined4 *)(this + 0x154) = 0;
  return this;
}


// ---- 11001ada StatusProc  (called by: -)

undefined4 StatusProc(void)

{
                    /* 0x1ada  15  StatusProc */
  return 0;
}


// ---- 11001add NoResponseToTrigger  (called by: -)

void NoResponseToTrigger(void)

{
                    /* 0x1add  11  NoResponseToTrigger */
  return;
}


// ---- 11001ade FUN_11001ade  (called by: FUN_11001b31@11001b31, FUN_11002435@11002435, Research3304Done@11001d41, Research3305Done@11001dee, Research3401Done@11001c7f)

void __cdecl FUN_11001ade(undefined4 param_1)

{
  PlayerBuildingEnum *this;
  Unit *pUVar1;
  PlayerBuildingEnum local_10 [8];
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  scr_snprintf(&DAT_11019ab0,0x50,s_New_mission_objective_s_11014ff8,param_1);
  pUVar1 = (Unit *)&local_8;
  this = (PlayerBuildingEnum *)PlayerBuildingEnum::PlayerBuildingEnum(local_10,0,0x31);
  PlayerBuildingEnum::GetNext(this,pUVar1);
  TethysGame::AddMessage(&DAT_11019ab0,0,local_8,0x7a);
  return;
}


// ---- 11001b31 FUN_11001b31  (called by: InitProc@11005597)

void FUN_11001b31(void)

{
  int iVar1;
  Trigger *pTVar2;
  int unaff_EBP;
  
  FUN_11008fa8();
  iVar1 = ScStub::IsInitialized((ScStub *)&DAT_1101c134);
  if (iVar1 != 0) {
    ScStub::Destroy((ScStub *)&DAT_1101c134);
  }
  CreateResearchTrigger(unaff_EBP + -0x10,1,0,0xce9,(char *)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  pTVar2 = (Trigger *)
           CreateVictoryCondition(unaff_EBP + -0x14,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x10));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  Trigger::operator=((Trigger *)&DAT_1101c13c,pTVar2);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  pTVar2 = (Trigger *)CreateResearchTrigger(unaff_EBP + -0x14,1,0,0xce8,(char *)0x0);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  Trigger::operator=((Trigger *)(unaff_EBP + -0x10),pTVar2);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  pTVar2 = (Trigger *)
           CreateVictoryCondition(unaff_EBP + -0x14,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x10));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  Trigger::operator=((Trigger *)&DAT_1101c138,pTVar2);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  pTVar2 = (Trigger *)CreateResearchTrigger(unaff_EBP + -0x14,1,0,0xd49,(char *)0x0);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  Trigger::operator=((Trigger *)(unaff_EBP + -0x10),pTVar2);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  pTVar2 = (Trigger *)
           CreateVictoryCondition(unaff_EBP + -0x14,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x10));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  Trigger::operator=((Trigger *)&DAT_1101c140,pTVar2);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  if (DAT_1101c0e8 != '\0') {
    FUN_11001ade(&DAT_11015010);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11001c7f Research3401Done  (called by: InitProc@11005597)

void Research3401Done(void)

{
  int iVar1;
  Trigger *pTVar2;
  ScStub local_c [4];
  ScStub local_8 [4];
  
                    /* 0x1c7f  14  Research3401Done */
  if (DAT_1101c118 != '\0') {
    iVar1 = ScStub::IsInitialized((ScStub *)&DAT_1101c140);
    if (iVar1 != 0) {
      ScStub::Destroy((ScStub *)&DAT_1101c140);
    }
    FUN_11007420('\x01','\x01',0,0x30,0,4,FUN_11002435,0);
    CreateOperationalTrigger((int)local_8,1,0,0,0x30,0,(char *)0x4);
    pTVar2 = (Trigger *)CreateVictoryCondition((int)local_c,1,(Trigger *)0x0,(char *)local_8);
    Trigger::operator=((Trigger *)&DAT_1101c130,pTVar2);
    ScStub::~ScStub(local_c);
    if (DAT_1101c0ea == '\0') {
      FUN_11001ade(s___build_a_Vehicle_Factory_110150b8);
    }
    BuildingGroup::RecordVehReinforceGroup
              ((BuildingGroup *)&DAT_1101c0b8,(ScGroup *)&DAT_1101c068,200);
    DAT_1101c118 = '\0';
    ScStub::~ScStub(local_8);
  }
  return;
}


// ---- 11001d41 Research3304Done  (called by: InitProc@11005597)

void Research3304Done(void)

{
  int iVar1;
  Trigger *pTVar2;
  ScStub local_c [4];
  ScStub local_8 [4];
  
                    /* 0x1d41  12  Research3304Done */
  if (DAT_1101c11a != '\0') {
    iVar1 = ScStub::IsInitialized((ScStub *)&DAT_1101c138);
    if (iVar1 != 0) {
      ScStub::Destroy((ScStub *)&DAT_1101c138);
    }
    FUN_11007420('\x01','\x01',0,0x23,0,4,FUN_11002577,0);
    CreateOperationalTrigger((int)local_8,1,0,0,0x23,0,(char *)0x4);
    pTVar2 = (Trigger *)CreateVictoryCondition((int)local_c,1,(Trigger *)0x0,(char *)local_8);
    Trigger::operator=((Trigger *)&DAT_1101c128,pTVar2);
    ScStub::~ScStub(local_c);
    if (DAT_1101c0ea == '\0') {
      FUN_11001ade(s___build_a_Nursery_110150d4);
    }
    DAT_1101c11a = '\0';
    ScStub::~ScStub(local_8);
  }
  return;
}


// ---- 11001dee Research3305Done  (called by: InitProc@11005597)

void Research3305Done(void)

{
  int iVar1;
  Trigger *pTVar2;
  ScStub local_c [4];
  ScStub local_8 [4];
  
                    /* 0x1dee  13  Research3305Done */
  if (DAT_1101c119 != '\0') {
    iVar1 = ScStub::IsInitialized((ScStub *)&DAT_1101c13c);
    if (iVar1 != 0) {
      ScStub::Destroy((ScStub *)&DAT_1101c13c);
    }
    FUN_11007420('\x01','\x01',0,0x26,0,4,FUN_11002593,0);
    CreateOperationalTrigger((int)local_8,1,0,0,0x26,0,(char *)0x4);
    pTVar2 = (Trigger *)CreateVictoryCondition((int)local_c,1,(Trigger *)0x0,(char *)local_8);
    Trigger::operator=((Trigger *)&DAT_1101c12c,pTVar2);
    ScStub::~ScStub(local_c);
    if (DAT_1101c0ea == '\0') {
      FUN_11001ade(s___build_a_University_110150e8);
    }
    DAT_1101c119 = '\0';
    ScStub::~ScStub(local_8);
  }
  return;
}


// ---- 11001e9b FUN_11001e9b  (called by: -)

void FUN_11001e9b(void)

{
  int iVar1;
  undefined4 *puVar2;
  FightGroup *pFVar3;
  void *unaff_ESI;
  int iVar4;
  undefined4 uVar5;
  undefined4 uStack_74;
  undefined4 uVar6;
  undefined4 uStack_5c;
  IUnit local_2c [2];
  ScStub aSStack_2a [2];
  undefined4 local_28 [2];
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 local_10 [3];
  undefined4 uStack_4;
  
  uStack_4 = 0x11001ea5;
  FUN_11008fa8();
  IUnit::IUnit(local_2c);
  puVar2 = (undefined4 *)
           MAP_RECT::MAP_RECT((MAP_RECT *)local_10,DAT_11016240 + -6,DAT_11016244 + -6,
                              DAT_11016240 + 6,DAT_11016244 + 6);
  local_20 = *puVar2;
  uStack_1c = puVar2[1];
  uStack_18 = puVar2[2];
  uStack_14 = puVar2[3];
  pFVar3 = (FightGroup *)CreateFightGroup(local_28);
  uStack_4 = 0;
  FightGroup::operator=((FightGroup *)&DAT_1101c094,pFVar3);
  uStack_4 = 0xffffffff;
  ScStub::~ScStub((ScStub *)(local_2c + -8));
  FightGroup::SetRect((FightGroup *)&DAT_1101c094,(MAP_RECT *)local_2c);
  ScGroup::SetLights((ScGroup *)&DAT_1101c094,1);
  FightGroup::SetCombineFire((FightGroup *)&DAT_1101c094);
  pFVar3 = (FightGroup *)CreateFightGroup(local_2c + -8);
  local_10[0] = 1;
  uStack_5c = 0x11001f6d;
  FightGroup::operator=((FightGroup *)&DAT_1101c098,pFVar3);
  local_10[0] = 0xffffffff;
  ScStub::~ScStub((ScStub *)(local_2c + -0x14));
  uStack_5c = 0x11001f89;
  FightGroup::SetRect((FightGroup *)&DAT_1101c098,(MAP_RECT *)(local_2c + -0xc));
  uStack_5c = 0x11001f93;
  ScGroup::SetLights((ScGroup *)&DAT_1101c098,1);
  FightGroup::SetCombineFire((FightGroup *)&DAT_1101c098);
  uStack_5c = *(undefined4 *)(Player_exref + 0x1c);
  pFVar3 = (FightGroup *)CreateFightGroup(local_2c + -0x14);
  uStack_1c = 2;
  FightGroup::operator=((FightGroup *)&DAT_1101c09c,pFVar3);
  uStack_1c = 0xffffffff;
  ScStub::~ScStub((ScStub *)(local_2c + -0x20));
  FightGroup::SetRect((FightGroup *)&DAT_1101c09c,(MAP_RECT *)(local_2c + -0x18));
  ScGroup::SetLights((ScGroup *)&DAT_1101c09c,1);
  iVar1 = *(int *)(Player_exref + 0x18);
  pFVar3 = (FightGroup *)CreateFightGroup(local_2c + -0x20);
  local_28[0] = 3;
  uStack_74 = 0x11002021;
  FightGroup::operator=((FightGroup *)&DAT_1101c0a0,pFVar3);
  local_28[0] = 0xffffffff;
  ScStub::~ScStub((ScStub *)(local_2c + -0x2c));
  uStack_74 = 0x1100203a;
  ScGroup::SetLights((ScGroup *)&DAT_1101c0a0,1);
  uStack_74 = 0x11002044;
  FightGroup::SetAttackType((FightGroup *)&DAT_1101c0a0,5);
  FightGroup::SetCombineFire((FightGroup *)&DAT_1101c0a0);
  FightGroup::DoAttackEnemy((FightGroup *)&DAT_1101c0a0);
  for (iVar4 = DAT_1101c0f8 + 5; -1 < iVar4; iVar4 = iVar4 + -1) {
    uVar6 = 5;
    uStack_74 = 0x40;
    TethysGame::CreateUnit(&uStack_5c,5,0x11c - iVar4 / 2,0x3a - iVar4 % 2,2);
    ScGroup::TakeUnit((ScGroup *)&DAT_1101c098,uVar6);
    uVar5 = 6;
    TethysGame::CreateUnit(&uStack_74,5,uVar6,iVar1 + 0x3c,2,0x3e,6);
    ScGroup::TakeUnit((ScGroup *)&DAT_1101c09c,uVar5);
  }
  for (iVar4 = DAT_1101c0f4 + 1; -1 < iVar4; iVar4 = iVar4 + -1) {
    uVar5 = 4;
    uStack_74 = 0x3e;
    TethysGame::CreateUnit(&uStack_5c,5,0x11d - iVar4 % 2,0x37 - iVar4 / 2,2);
    ScGroup::TakeUnit((ScGroup *)&DAT_1101c094,uVar5);
  }
  for (iVar4 = DAT_1101c0f4 + 2; -1 < iVar4; iVar4 = iVar4 + -1) {
    uVar5 = 7;
    uStack_74 = 0x40;
    TethysGame::CreateUnit(&uStack_5c,5,iVar4 / 2 + 0x21,0x3d - iVar4 % 2,2);
    ScGroup::TakeUnit((ScGroup *)&DAT_1101c0a0,uVar5);
  }
  uStack_74 = uStack_5c;
  TethysGame::AddMessage(s_Your_pickup_team_has_arrived__Ge_11015100,0);
  FUN_11007770('\x01','\x01',1000,FUN_110041e5,0);
  FUN_110075b0('\x01','\x01',(ScStub *)&DAT_1101c09c,3,FUN_110040dd,0);
  FUN_110075b0('\x01','\x01',(ScStub *)&DAT_1101c098,3,FUN_11004170,0);
  FUN_110075b0('\x01','\x01',(ScStub *)&DAT_1101c098,1,FUN_11004410,0);
  FUN_11007770('\x01','\0',2000,FUN_110047a6,0);
  ExceptionList = unaff_ESI;
  return;
}


// ---- 110021fa FUN_110021fa  (called by: -)

void FUN_110021fa(void)

{
  code *this;
  int iVar1;
  int iVar2;
  map_id mVar3;
  Trigger *pTVar4;
  int unaff_EBP;
  char *pcVar5;
  
  FUN_11008fa8();
  DAT_1101c11c = DAT_1101c11c + 1;
  if (1 < DAT_1101c11c) {
    IUnit::IUnit((IUnit *)(unaff_EBP + -0x10));
    this = Player_exref;
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    iVar1 = _Player::FoodStored((_Player *)this);
    iVar2 = _Player::Ore((_Player *)Player_exref);
    *(int *)(unaff_EBP + -0x14) = iVar2;
    PlayerVehicleEnum::PlayerVehicleEnum((PlayerVehicleEnum *)(unaff_EBP + -0x2c),0);
    while (iVar2 = PlayerVehicleEnum::GetNext
                             ((PlayerVehicleEnum *)(unaff_EBP + -0x2c),(Unit *)(unaff_EBP + -0x10)),
          iVar2 != 0) {
      mVar3 = Unit::GetType((Unit *)(unaff_EBP + -0x10));
      if (mVar3 == 1) {
        iVar2 = IUnit::GetTruckCargo
                          ((IUnit *)(unaff_EBP + -0x10),(Truck_Cargo *)(unaff_EBP + -0x28));
        if (*(int *)(unaff_EBP + -0x28) == 1) {
          iVar1 = iVar1 + iVar2;
        }
        else if (*(int *)(unaff_EBP + -0x28) == 4) {
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + iVar2;
        }
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
      }
      else if (mVar3 == 2) {
        *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
      }
      else if (mVar3 == 8) {
        *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
      }
      else if (mVar3 == 9) {
        *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
      }
    }
    if ((((iVar1 < DAT_1101c100 * 1000) || (*(int *)(unaff_EBP + -0x14) < DAT_1101c104 * 1000)) ||
        (*(int *)(unaff_EBP + -0x18) < DAT_1101c104 + DAT_1101c100)) ||
       (((*(int *)(unaff_EBP + -0x1c) < 4 || (*(int *)(unaff_EBP + -0x20) < 1)) ||
        (*(int *)(unaff_EBP + -0x24) < 1)))) {
      FUN_11007770('\x01','\x01',500,FUN_110021fa,0);
    }
    else {
      TethysGame::PlaceMarker((Unit *)(unaff_EBP + -0x10),DAT_11016240,DAT_11016244,0);
      TethysGame::AddMessage
                (s_Get_ready_to_evacuate_110151bc,0,*(undefined4 *)(unaff_EBP + -0x10),0);
      scr_snprintf(&DAT_11019ab0,0x50,s_We_ve_sent_a_team_to_pick_you_up_11015178,
                   DAT_11016240 + -0x1f,DAT_11016244 + 1);
      (*DAT_11015464)(s_Message_from_the_Council_1101515c,0);
      FUN_11007770('\x01','\x01',500,FUN_11001e9b,0);
      FUN_11007770('\x01','\0',100,FUN_11004600,0);
      pcVar5 = s_NoResponseToTrigger_1101487c;
      pTVar4 = (Trigger *)CreateTimeTrigger(unaff_EBP + -0x24,0,1,(char *)0xa);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      Trigger::operator=((Trigger *)&DAT_1101c124,pTVar4);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      ScStub::~ScStub((ScStub *)(unaff_EBP + -0x24));
      scr_snprintf(&DAT_1101c258,0x50,s_Evacuate_ALL_your_vehicles_to____11015134,
                   DAT_11016240 + -0x1f,DAT_11016244 + 1,pcVar5);
      CreateVictoryCondition(unaff_EBP + -0x30,1,(Trigger *)0x0,&DAT_1101c124);
      ScStub::~ScStub((ScStub *)(unaff_EBP + -0x30));
      FUN_110040b2();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11002435 FUN_11002435  (called by: -)

void FUN_11002435(void)

{
  int iVar1;
  Trigger *pTVar2;
  int unaff_EBP;
  char *pcVar3;
  
  FUN_11008fa8();
  iVar1 = ScStub::IsInitialized((ScStub *)&DAT_1101c130);
  if (iVar1 != 0) {
    ScStub::Destroy((ScStub *)&DAT_1101c130);
  }
  FUN_11007840('\x01','\x01',0,1,0xffffffff,(char)DAT_1101c104 + (char)DAT_1101c100,2,FUN_110021fa,0
              );
  pcVar3 = s_NoResponseToTrigger_1101487c;
  CreateCountTrigger(unaff_EBP + -0x10,1,0,0,1,-1,DAT_1101c104 + DAT_1101c100,(char *)0x2);
  iVar1 = DAT_1101c104 + DAT_1101c100;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  scr_snprintf(&DAT_1101c208,0x50,s_Have_at_least__d_cargo_trucks_110151ec,iVar1,pcVar3);
  CreateVictoryCondition(unaff_EBP + -0x14,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x10));
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  FUN_11007840('\x01','\x01',0,2,0xffffffff,4,2,FUN_110021fa,0);
  pTVar2 = (Trigger *)CreateCountTrigger(unaff_EBP + -0x14,1,0,0,2,-1,4,(char *)0x2);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  Trigger::operator=((Trigger *)(unaff_EBP + -0x10),pTVar2);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  CreateVictoryCondition(unaff_EBP + -0x14,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x10));
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  FUN_11001ade(&DAT_11015010);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11002577 FUN_11002577  (called by: -)

void FUN_11002577(void)

{
  int iVar1;
  
  iVar1 = ScStub::IsInitialized((ScStub *)&DAT_1101c128);
  if (iVar1 != 0) {
    ScStub::Destroy((ScStub *)&DAT_1101c128);
  }
  return;
}


// ---- 11002593 FUN_11002593  (called by: -)

void FUN_11002593(void)

{
  int iVar1;
  
  iVar1 = ScStub::IsInitialized((ScStub *)&DAT_1101c12c);
  if (iVar1 != 0) {
    ScStub::Destroy((ScStub *)&DAT_1101c12c);
  }
  return;
}


// ---- 110025af FUN_110025af  (called by: InitProc@11005597)

void FUN_110025af(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  PlayerBuildingEnum *this;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  map_id mVar6;
  int *piVar7;
  IUnit *pIVar8;
  undefined4 uVar9;
  undefined4 uStack_54;
  Unit *pUVar10;
  IUnit local_34 [2];
  MAP_RECT aMStack_32 [2];
  PlayerVehicleEnum local_30 [4];
  PlayerBuildingEnum aPStack_2c [4];
  PlayerBuildingEnum local_28 [4];
  MAP_RECT aMStack_24 [12];
  PlayerBuildingEnum local_18 [24];
  
  IUnit::IUnit(local_34);
  PlayerVehicleEnum::PlayerVehicleEnum(local_30,1);
  PlayerBuildingEnum::PlayerBuildingEnum(local_18,1,0x36);
  pUVar10 = (Unit *)&DAT_1101c034;
  uStack_54 = 0x110025eb;
  this = (PlayerBuildingEnum *)PlayerBuildingEnum::PlayerBuildingEnum(local_28,1,0x15);
  iVar3 = PlayerBuildingEnum::GetNext(this,pUVar10);
  if (iVar3 == 0) {
    uStack_54 = 0x1d;
    TethysGame::CreateUnit(&DAT_1101c034,0x15,0x91);
  }
  uStack_54 = 0x19;
  uVar9 = 0x111;
  TethysGame::CreateUnit(&DAT_1101c03c,0x15,0x111);
  PlayerBuildingEnum::GetNext(aPStack_2c,(Unit *)&DAT_1101c038);
  iVar3 = PlayerBuildingEnum::GetNext(aPStack_2c,(Unit *)&DAT_1101c040);
  uVar2 = DAT_1101c038;
  uVar1 = DAT_1101c034;
  if (iVar3 != 0) {
    uVar4 = MAP_RECT::MAP_RECT((MAP_RECT *)(local_34 + -8),0x8d,5,0x93,9);
    MiningGroup::Setup((MiningGroup *)&DAT_1101c0c0,uVar1,uVar2,uVar4);
    ScGroup::SetTargCount((ScGroup *)&DAT_1101c0c0,1,0,DAT_1101c0f4 + 3);
  }
  else {
    Unit::operator=((Unit *)&DAT_1101c040,(Unit *)&DAT_1101c038);
    Unit::SetFactoryCargo((Unit *)&DAT_1101c02c,5,0x36,0);
    ScStub::Disable((ScStub *)&DAT_1101c0c0);
    FUN_11007840('\x01','\x01',1,0x36,0xffffffff,2,0,FUN_110027c5,0);
  }
  uVar2 = DAT_1101c040;
  uVar1 = DAT_1101c03c;
  uVar4 = MAP_RECT::MAP_RECT(aMStack_24,0x117,9,0x11c,0xe);
  MiningGroup::Setup((MiningGroup *)&DAT_1101c0c4,uVar1,uVar2,uVar4);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0c4,1,0,4);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c0b8,(ScGroup *)&DAT_1101c0c4,400);
  while (iVar5 = PlayerVehicleEnum::GetNext
                           ((PlayerVehicleEnum *)(local_34 + -0x1c),(Unit *)&uStack_54), 0 < iVar5)
  {
    mVar6 = Unit::GetType((Unit *)&uStack_54);
    if (mVar6 == 1) {
      pIVar8 = local_34 + -0x14;
      piVar7 = (int *)Unit::Location((Unit *)&uStack_54);
      if (*piVar7 < 0xc9) {
        ScGroup::TakeUnit((ScGroup *)&DAT_1101c0c0,uVar9,pIVar8);
        if (iVar3 == 0) {
          Unit::DoMove((Unit *)&uStack_54,0x92,7);
        }
      }
      else {
        ScGroup::TakeUnit((ScGroup *)&DAT_1101c0c4,uVar9,pIVar8);
      }
    }
  }
  return;
}


// ---- 110027c5 FUN_110027c5  (called by: -)

void FUN_110027c5(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  PlayerBuildingEnum aPStack_20 [2];
  PlayerBuildingEnum aPStack_1e [6];
  PlayerBuildingEnum aPStack_18 [8];
  MAP_RECT aMStack_10 [16];
  
  PlayerBuildingEnum::PlayerBuildingEnum(aPStack_20,1,0x36);
  iVar3 = PlayerBuildingEnum::GetNext(aPStack_20,(Unit *)&DAT_1101c038);
  while ((iVar3 != 0 && (piVar4 = (int *)Unit::Location((Unit *)&DAT_1101c038), 0x93 < *piVar4))) {
    iVar3 = PlayerBuildingEnum::GetNext(aPStack_20 + -4,(Unit *)&DAT_1101c038);
  }
  PlayerBuildingEnum::PlayerBuildingEnum(aPStack_18,1,0x15);
  do {
    iVar3 = PlayerBuildingEnum::GetNext(aPStack_18,(Unit *)&DAT_1101c034);
    if (iVar3 == 0) break;
    piVar4 = (int *)Unit::Location((Unit *)&DAT_1101c034);
  } while (0x93 < *piVar4);
  uVar2 = DAT_1101c038;
  uVar1 = DAT_1101c034;
  uVar5 = MAP_RECT::MAP_RECT(aMStack_10,0x8d,5,0x93,9);
  MiningGroup::Setup((MiningGroup *)&DAT_1101c0c0,uVar1,uVar2,uVar5);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0c0,1,0,DAT_1101c0f4 + 3);
  ScStub::Enable((ScStub *)&DAT_1101c0c0);
  return;
}


// ---- 1100289e FUN_1100289e  (called by: -)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1100289e(void)

{
  bool bVar1;
  int iVar2;
  int local_14;
  undefined4 local_8;
  
  bVar1 = false;
  IUnit::IUnit((IUnit *)&local_8);
  local_14 = DAT_1101c0cc;
  iVar2 = DAT_1101c0d0 + 2;
  _DAT_1101c108 = _DAT_1101c108 + -1;
  if (-1 < _DAT_1101c108) {
    bVar1 = true;
    do {
      TethysGame::CreateUnit(&local_8,2,0x21,0x3c,0,0,0);
      Unit::DoMove((Unit *)&local_8,local_14,iVar2);
      Unit::DoSetLights((Unit *)&local_8,1);
      local_14 = local_14 + 1;
      _DAT_1101c108 = _DAT_1101c108 + -1;
    } while (-1 < _DAT_1101c108);
  }
  _DAT_1101c10c = _DAT_1101c10c + -1;
  if (-1 < _DAT_1101c10c) {
    bVar1 = true;
    do {
      TethysGame::CreateUnit(&local_8,1,0x21,0x3c,0,0,0);
      Unit::DoMove((Unit *)&local_8,local_14,iVar2);
      Unit::DoSetLights((Unit *)&local_8,1);
      local_14 = local_14 + 1;
      _DAT_1101c10c = _DAT_1101c10c + -1;
    } while (-1 < _DAT_1101c10c);
  }
  _DAT_1101c114 = _DAT_1101c114 + -1;
  if (-1 < _DAT_1101c114) {
    bVar1 = true;
    do {
      TethysGame::CreateUnit(&local_8,8,0x21,0x3c,0,0,0);
      Unit::DoMove((Unit *)&local_8,local_14,iVar2);
      Unit::DoSetLights((Unit *)&local_8,1);
      local_14 = local_14 + 1;
      _DAT_1101c114 = _DAT_1101c114 + -1;
    } while (-1 < _DAT_1101c114);
  }
  _DAT_1101c110 = _DAT_1101c110 + -1;
  if (-1 < _DAT_1101c110) {
    bVar1 = true;
    do {
      TethysGame::CreateUnit(&local_8,9,0x21,0x3c,0,0,0);
      Unit::DoMove((Unit *)&local_8,local_14,iVar2);
      Unit::DoSetLights((Unit *)&local_8,1);
      local_14 = local_14 + 1;
      _DAT_1101c110 = _DAT_1101c110 + -1;
    } while (-1 < _DAT_1101c110);
  }
  if (bVar1) {
    TethysGame::AddMessage(s_A_new_convoy_has_arrived_1101520c,0,local_8,0xa2);
  }
  return;
}


// ---- 110029fb FUN_110029fb  (called by: FUN_11002ecd@11002ecd)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_110029fb(void)

{
  _DAT_1101c0f0 = DAT_1101c0f8 + 3;
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c0b4,DAT_1101c020);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c0b4,(ScGroup *)&DAT_1101c0c0,400);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c0b4,(ScGroup *)&DAT_1101c0a8,800);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c0b4,(ScGroup *)&DAT_1101c060,0xfa);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c0b4,(ScGroup *)&DAT_1101c064,200);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c0b4,(ScGroup *)&DAT_1101c07c,100);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c0b4,(ScGroup *)&DAT_1101c080,400);
  return;
}


// ---- 11002a76 FUN_11002a76  (called by: FUN_11002ecd@11002ecd)

void FUN_11002a76(void)

{
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = 0xa4;
  local_4 = 0x2f;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&local_8,0x1c,0);
  local_8 = 0xa9;
  local_4 = 0x2f;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&local_8,0x2f,0);
  Unit::SetFactoryCargo((Unit *)&DAT_1101c02c,1,0x1c,0);
  Unit::SetFactoryCargo((Unit *)&DAT_1101c02c,2,0x2f,0);
  FUN_11007a00('\x01','\x01',1,(LOCATION)0xa0,0x31,FUN_11002b0b);
  FUN_11007104('\x01','\x01',1,(LOCATION)0xa9,0x2f,FUN_11002c1c);
  return;
}


// ---- 11002b0b FUN_11002b0b  (called by: -)

void FUN_11002b0b(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  MiningGroup *pMVar4;
  undefined4 uVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar6;
  int unaff_EBP;
  undefined8 uVar7;
  
  FUN_11008fa8();
  Unit::SetId((Unit *)&DAT_1101c048,*(int *)(*(int *)(unaff_EBP + 8) + 8));
  PlayerBuildingEnum::PlayerBuildingEnum((PlayerBuildingEnum *)(unaff_EBP + -0x14),1,0x15);
  iVar2 = PlayerBuildingEnum::GetNext
                    ((PlayerBuildingEnum *)(unaff_EBP + -0x14),(Unit *)&DAT_1101c044);
  uVar6 = extraout_EDX;
  while (iVar2 != 0) {
    piVar3 = (int *)Unit::Location((Unit *)&DAT_1101c044);
    if (*piVar3 == 0x98) {
      uVar7 = Unit::Location((Unit *)&DAT_1101c044);
      uVar6 = (undefined4)((ulonglong)uVar7 >> 0x20);
      if (*(int *)((int)uVar7 + 4) == 0x25) break;
    }
    iVar2 = PlayerBuildingEnum::GetNext
                      ((PlayerBuildingEnum *)(unaff_EBP + -0x14),(Unit *)&DAT_1101c044);
    uVar6 = extraout_EDX_00;
  }
  pMVar4 = (MiningGroup *)
           CreateMiningGroup(unaff_EBP + 8,uVar6,*(undefined4 *)(Player_exref + 0xc),
                             *(undefined4 *)(Player_exref + 0x10),
                             *(undefined4 *)(Player_exref + 0x14));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  MiningGroup::operator=((MiningGroup *)&DAT_1101c0c8,pMVar4);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + 8));
  uVar1 = DAT_1101c048;
  uVar6 = DAT_1101c044;
  uVar5 = MAP_RECT::MAP_RECT((MAP_RECT *)(unaff_EBP + -0x34),0x9c,0x2f,0xa3,0x34);
  MiningGroup::Setup((MiningGroup *)&DAT_1101c0c8,uVar6,uVar1,uVar5);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0c8,1,0,4);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c0b4,(ScGroup *)&DAT_1101c0c8,5000);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11002c1c FUN_11002c1c  (called by: -)

void __cdecl FUN_11002c1c(int param_1)

{
  LOCATION *pLVar1;
  int iVar2;
  map_id mVar3;
  ClosestEnumerator local_4c [52];
  undefined4 local_18;
  undefined4 local_14;
  ulong local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  IUnit::IUnit((IUnit *)&local_c);
  Unit::SetId((Unit *)&local_c,*(int *)(param_1 + 8));
  pLVar1 = (LOCATION *)Unit::Location((Unit *)&local_c);
  ClosestEnumerator::ClosestEnumerator(local_4c,pLVar1);
  do {
    iVar2 = ClosestEnumerator::GetNext(local_4c,(Unit *)&local_8,&local_10);
    if (iVar2 == 0) break;
    mVar3 = Unit::GetType((Unit *)&local_8);
  } while (mVar3 != 2);
  ScGroup::RemoveUnit((ScGroup *)&DAT_1101c0a8,local_8);
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c0ac,local_8);
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c0ac,local_c);
  local_18 = 0x98;
  local_14 = 0x25;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&local_18,0x15,0);
  local_18 = 0xa1;
  local_14 = 0x2e;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0ac,(LOCATION *)&local_18,0x1e,0);
  local_18 = 0xa0;
  local_14 = 0x31;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0ac,(LOCATION *)&local_18,0x36,0);
  local_18 = 0xa4;
  local_14 = 0x32;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0ac,(LOCATION *)&local_18,0x23,0);
  local_18 = 0xa0;
  local_14 = 0x25;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0ac,(LOCATION *)&local_18,0x3a,0);
  local_18 = 0x9f;
  local_14 = 0x35;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0ac,(LOCATION *)&local_18,0x30,0);
  local_18 = 0xac;
  local_14 = 0x2f;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0ac,(LOCATION *)&local_18,0x17,0x3d);
  local_18 = 0x9f;
  local_14 = 0x2a;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0ac,(LOCATION *)&local_18,0x17,0x3d);
  local_18 = 0x9c;
  local_14 = 0x30;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0ac,(LOCATION *)&local_18,0x17,0x3d);
  local_18 = 0xa6;
  local_14 = 0x32;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0ac,(LOCATION *)&local_18,0x17,0x3d);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0ac,2,0,1);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c0b4,(ScGroup *)&DAT_1101c0ac,500);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c0b4,(ScGroup *)&DAT_1101c06c,800);
  FUN_11007104('\x01','\x01',1,(LOCATION)0x9f,0x35,FUN_11002e06);
  return;
}


// ---- 11002e06 FUN_11002e06  (called by: -)

void __cdecl FUN_11002e06(int param_1)

{
  MAP_RECT *pMVar1;
  MAP_RECT local_14 [16];
  
  Unit::SetId((Unit *)&DAT_1101c028,*(int *)(param_1 + 8));
  BuildingGroup::UnRecordVehGroup((BuildingGroup *)&DAT_1101c0b4,(ScGroup *)&DAT_1101c0ac);
  BuildingGroup::UnRecordVehGroup((BuildingGroup *)&DAT_1101c0b4,(ScGroup *)&DAT_1101c0c8);
  BuildingGroup::UnRecordVehGroup((BuildingGroup *)&DAT_1101c0b4,(ScGroup *)&DAT_1101c06c);
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c0bc,DAT_1101c028);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c0bc,(ScGroup *)&DAT_1101c0ac,500);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c0bc,(ScGroup *)&DAT_1101c0c8,5000);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c0bc,(ScGroup *)&DAT_1101c06c,200);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c06c,5,0x3d,DAT_1101c0f8 + 4);
  FightGroup::ClearGuarderdRects((FightGroup *)&DAT_1101c06c);
  pMVar1 = (MAP_RECT *)MAP_RECT::MAP_RECT(local_14,0x98,0x26,0xab,0x35);
  FightGroup::SetRect((FightGroup *)&DAT_1101c06c,pMVar1);
  return;
}


// ---- 11002ecd FUN_11002ecd  (called by: InitProc@11005597)

void FUN_11002ecd(void)

{
  int iVar1;
  LOCATION *pLVar2;
  MAP_RECT *pMVar3;
  undefined4 *puVar4;
  int iStack_60;
  int iStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  uStack_34 = 4;
  uStack_38 = 0;
  uStack_3c = 1;
  uStack_40 = 6;
  uStack_44 = 0x98;
  uStack_48 = 0x11002eff;
  TethysGame::CreateUnit(&DAT_1101c010,2);
  uStack_48 = 3;
  uStack_4c = 0;
  uStack_50 = 1;
  uStack_54 = 5;
  uStack_58 = 0xa6;
  iStack_5c = 0x11002f17;
  TethysGame::CreateUnit(&DAT_1101c018,2);
  iStack_5c = 0;
  iStack_60 = 0;
  TethysGame::CreateUnit(&DAT_1101c014,0xf,0x8d,7,1);
  PlayerBuildingEnum::PlayerBuildingEnum((PlayerBuildingEnum *)&uStack_54,1,0x2f);
  PlayerBuildingEnum::GetNext((PlayerBuildingEnum *)&uStack_54,(Unit *)&DAT_1101c02c);
  iVar1 = PlayerBuildingEnum::GetNext((PlayerBuildingEnum *)&uStack_54,(Unit *)&DAT_1101c030);
  if (iVar1 == 0) {
    TethysGame::CreateUnit(&DAT_1101c030,0x2f,0x110,4,1,0,0);
    TethysGame::CreateWallOrTube(0x114,3,0,0x11);
  }
  Unit::SetFactoryCargo((Unit *)&DAT_1101c030,5,0x1c,0);
  Unit::SetFactoryCargo((Unit *)&DAT_1101c030,4,0x36,0);
  puVar4 = &uStack_4c;
  pLVar2 = (LOCATION *)Unit::Location((Unit *)&DAT_1101c030);
  LOCATION::operator=((LOCATION *)&iStack_60,pLVar2);
  pMVar3 = (MAP_RECT *)
           MAP_RECT::MAP_RECT((MAP_RECT *)&uStack_50,iStack_60 + -3,iStack_5c + -3,iStack_60 + 2,
                              iStack_5c + 2);
  BuildingGroup::SetRect((BuildingGroup *)&DAT_1101c0b0,pMVar3);
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c0b0,DAT_1101c030,puVar4);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0b0,2,0,1);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0b0,9,0,1);
  uStack_54 = 0xcb;
  uStack_50 = 0xe;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0b0,(LOCATION *)&uStack_54,0x1c,0);
  uStack_54 = 0xca;
  uStack_50 = 10;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0b0,(LOCATION *)&uStack_54,0x36,0);
  uStack_54 = 0xd1;
  uStack_50 = 3;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0b0,(LOCATION *)&uStack_54,0x3a,0);
  uStack_54 = 0xc4;
  uStack_50 = 6;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0b0,(LOCATION *)&uStack_54,0x15,0);
  uStack_54 = 0xcb;
  uStack_50 = 0x10;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0b0,(LOCATION *)&uStack_54,0x17,0x3d);
  uStack_54 = 0xcd;
  uStack_50 = 9;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0b0,(LOCATION *)&uStack_54,0x17,0x3d);
  uStack_54 = 0xc6;
  uStack_50 = 10;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0b0,(LOCATION *)&uStack_54,0x17,0x3d);
  uStack_54 = 0x91;
  uStack_50 = 0x1d;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&uStack_54,0x15,0);
  uStack_54 = 0x8f;
  uStack_50 = 4;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&uStack_54,0x36,0);
  uStack_54 = 0x89;
  uStack_50 = 6;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&uStack_54,0x17,0x3d);
  uStack_54 = 0x8e;
  uStack_50 = 0x10;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&uStack_54,0x17,0x3d);
  FUN_11002a76();
  uStack_54 = 0x8a;
  uStack_50 = 2;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&uStack_54,0x3a,0);
  uStack_54 = 0x9b;
  uStack_50 = 5;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&uStack_54,0x19,0);
  uStack_54 = 0x8e;
  uStack_50 = 0x22;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&uStack_54,0x17,0x3d);
  uStack_54 = 0x8f;
  uStack_50 = 0x19;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&uStack_54,0x17,0x3d);
  uStack_54 = 0x8a;
  uStack_50 = 0x10;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&uStack_54,0x17,0x3d);
  uStack_54 = 0x93;
  uStack_50 = 6;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&uStack_54,0x17,0x3d);
  uStack_54 = 0x9d;
  uStack_50 = 5;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&uStack_54,0x17,0x3d);
  uStack_54 = 0xa6;
  uStack_50 = 3;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&uStack_54,0x27,0);
  uStack_54 = 0xa9;
  uStack_50 = 3;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&uStack_54,0x1e,0);
  uStack_54 = 0xa9;
  uStack_50 = 6;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&uStack_54,0x1c,0);
  uStack_54 = 0xaf;
  uStack_50 = 2;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&uStack_54,0x31,0);
  uStack_54 = 0xb3;
  uStack_50 = 3;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&uStack_54,0x27,0);
  uStack_54 = 0xa9;
  uStack_50 = 8;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&uStack_54,0x17,0x3d);
  uStack_54 = 0xac;
  uStack_50 = 3;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&uStack_54,0x17,0x3d);
  uStack_54 = 0x9c;
  uStack_50 = 2;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&uStack_54,0x1e,0);
  uStack_54 = 0xa4;
  uStack_50 = 5;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c0a8,(LOCATION *)&uStack_54,0x17,0x3d);
  FUN_11001448();
  FUN_11001448();
  FUN_11001448();
  uStack_54 = 0x8d;
  FUN_11001448();
  FUN_11001448();
  FUN_11001448();
  uStack_54 = 0x8e;
  FUN_11001448();
  FUN_11001448();
  FUN_11001448();
  FUN_11001448();
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c0a8,DAT_1101c010);
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c0a8,DAT_1101c018);
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c0a8,DAT_1101c014);
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c0a8,DAT_1101c02c);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0a8,2,0,2);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0a8,9,0,1);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0a8,0xf,0,1);
  FUN_110029fb();
  return;
}


// ---- 110034b1 FUN_110034b1  (called by: -)

void FUN_110034b1(void)

{
  undefined4 uVar1;
  int iVar2;
  map_id mVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  MAP_RECT local_30 [8];
  undefined1 local_28 [8];
  PlayerBuildingEnum local_20 [8];
  PlayerBuildingEnum local_18 [8];
  GroupEnumerator local_10 [4];
  int local_c;
  IUnit local_8 [4];
  
  IUnit::IUnit(local_8);
  local_c = ScGroup::TotalUnitCount((ScGroup *)&DAT_1101c0c4);
  GroupEnumerator::GroupEnumerator(local_10,(ScGroup *)&DAT_1101c0c4);
  while (iVar2 = GroupEnumerator::GetNext(local_10,(Unit *)local_8), iVar2 != 0) {
    mVar3 = Unit::GetCargo((Unit *)local_8);
    if (mVar3 == 0) {
      local_c = local_c + -1;
    }
  }
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0c4,1,0,3);
  PlayerBuildingEnum::PlayerBuildingEnum(local_18,1,0x15);
  PlayerBuildingEnum::PlayerBuildingEnum(local_20,1,0x36);
  iVar2 = PlayerBuildingEnum::GetNext(local_18,(Unit *)&DAT_1101c04c);
  while ((iVar2 != 0 && (piVar4 = (int *)Unit::Location((Unit *)&DAT_1101c04c), *piVar4 != 0xc4))) {
    iVar2 = PlayerBuildingEnum::GetNext(local_18,(Unit *)&DAT_1101c04c);
  }
  do {
    iVar2 = PlayerBuildingEnum::GetNext(local_20,(Unit *)&DAT_1101c050);
    if (iVar2 == 0) break;
    piVar4 = (int *)Unit::Location((Unit *)&DAT_1101c050);
  } while (*piVar4 != 0xca);
  if (0 < local_c) {
    puVar9 = local_28;
    piVar4 = (int *)Unit::Location((Unit *)&DAT_1101c04c);
    uVar6 = DAT_1101c04c;
    uVar1 = DAT_1101c040;
    uVar7 = DAT_1101c034;
    if (*piVar4 == 0xc4) {
      uVar5 = MAP_RECT::MAP_RECT(local_30,0x8d,5,0x93,9);
      uVar7 = uVar6;
    }
    else {
      uVar5 = MAP_RECT::MAP_RECT(local_30,0x8d,5,0x93,9);
    }
    MiningGroup::Setup((MiningGroup *)&DAT_1101c0c4,uVar7,uVar1,uVar5,puVar9);
    FUN_11007770('\x01','\x01',500,FUN_110034b1,0);
    return;
  }
  puVar9 = local_28;
  piVar4 = (int *)Unit::Location((Unit *)&DAT_1101c04c);
  if (*piVar4 == 0xc4) {
    puVar8 = local_28;
    piVar4 = (int *)Unit::Location((Unit *)&DAT_1101c050);
    uVar1 = DAT_1101c050;
    uVar7 = DAT_1101c04c;
    if (*piVar4 == 0xca) {
      uVar6 = MAP_RECT::MAP_RECT(local_30,0xc6,8,0xcc,0xc);
      MiningGroup::Setup((MiningGroup *)&DAT_1101c0c4,uVar7,uVar1,uVar6,puVar8,puVar9);
      goto LAB_11003689;
    }
  }
  FUN_11007770('\x01','\x01',500,FUN_1100369e,0);
LAB_11003689:
  BuildingGroup::UnRecordVehGroup((BuildingGroup *)&DAT_1101c0b8,(ScGroup *)&DAT_1101c070);
  return;
}


// ---- 1100369e FUN_1100369e  (called by: -)

void FUN_1100369e(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  MAP_RECT local_24 [8];
  undefined1 local_1c [8];
  PlayerBuildingEnum local_14 [8];
  PlayerBuildingEnum local_c [8];
  
  PlayerBuildingEnum::PlayerBuildingEnum(local_c,1,0x15);
  PlayerBuildingEnum::PlayerBuildingEnum(local_14,1,0x36);
  iVar3 = PlayerBuildingEnum::GetNext(local_c,(Unit *)&DAT_1101c04c);
  while ((iVar3 != 0 && (piVar4 = (int *)Unit::Location((Unit *)&DAT_1101c04c), *piVar4 != 0xc4))) {
    iVar3 = PlayerBuildingEnum::GetNext(local_c,(Unit *)&DAT_1101c04c);
  }
  do {
    iVar3 = PlayerBuildingEnum::GetNext(local_14,(Unit *)&DAT_1101c050);
    if (iVar3 == 0) break;
    piVar4 = (int *)Unit::Location((Unit *)&DAT_1101c050);
  } while (*piVar4 != 0xca);
  puVar7 = local_1c;
  piVar4 = (int *)Unit::Location((Unit *)&DAT_1101c04c);
  if (*piVar4 == 0xc4) {
    puVar6 = local_1c;
    piVar4 = (int *)Unit::Location((Unit *)&DAT_1101c050);
    uVar2 = DAT_1101c050;
    uVar1 = DAT_1101c04c;
    if (*piVar4 == 0xca) {
      uVar5 = MAP_RECT::MAP_RECT(local_24,0xc6,8,0xcc,0xc);
      MiningGroup::Setup((MiningGroup *)&DAT_1101c0c4,uVar1,uVar2,uVar5,puVar6,puVar7);
      return;
    }
  }
  FUN_11007770('\x01','\x01',500,FUN_1100369e,0);
  return;
}


// ---- 1100378f FUN_1100378f  (called by: InitProc@11005597)

void FUN_1100378f(void)

{
  code *pcVar1;
  FightGroup *pFVar2;
  MAP_RECT *pMVar3;
  int unaff_EBP;
  
  FUN_11008fa8();
  IUnit::IUnit((IUnit *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -0x4c) = 0x8b;
  *(undefined4 *)(unaff_EBP + -0x48) = 2;
  *(undefined4 *)(unaff_EBP + -0x40) = 0x21;
  *(undefined4 *)(unaff_EBP + -0x44) = 0x8d;
  *(undefined4 *)(unaff_EBP + -0x38) = 7;
  *(undefined4 *)(unaff_EBP + -0x3c) = 0x95;
  *(undefined4 *)(unaff_EBP + -0x28) = 0x3c;
  *(undefined4 *)(unaff_EBP + -0x34) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0xb8;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x14;
  *(undefined4 *)(unaff_EBP + -0x24) = 0xb5;
  *(undefined4 *)(unaff_EBP + -0x80) = 0x37;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x7c) = 0xc0;
  *(undefined4 *)(unaff_EBP + -0x84) = 200;
  *(undefined4 *)(unaff_EBP + -0x74) = 200;
  *(undefined4 *)(unaff_EBP + -0x70) = 10;
  *(undefined4 *)(unaff_EBP + -0x6c) = 0xd7;
  *(undefined4 *)(unaff_EBP + -100) = 0xc9;
  *(undefined4 *)(unaff_EBP + -0x68) = 0x11;
  *(undefined4 *)(unaff_EBP + -0x5c) = 0xd4;
  *(undefined4 *)(unaff_EBP + -0x60) = 0x28;
  *(undefined4 *)(unaff_EBP + -0x54) = 0xffffffff;
  pcVar1 = Player_exref;
  *(undefined4 *)(unaff_EBP + -0x78) = 0x1d;
  *(undefined4 *)(unaff_EBP + -0x30) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x18) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x58) = 0x31;
  *(undefined4 *)(unaff_EBP + -0x50) = 0xffffffff;
  pFVar2 = (FightGroup *)
           CreateFightGroup(unaff_EBP + -0x14,0x31,*(undefined4 *)(pcVar1 + 0xc),
                            *(undefined4 *)(pcVar1 + 0x10),*(undefined4 *)(pcVar1 + 0x14));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FightGroup::operator=((FightGroup *)&DAT_1101c054,pFVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(unaff_EBP + -0xac),0x8b,4,0x98,0x16);
  FightGroup::SetRect((FightGroup *)&DAT_1101c054,pMVar3);
  *(int *)(unaff_EBP + -0x90) = unaff_EBP + -0x4c;
  FightGroup::SetPatrolMode((FightGroup *)&DAT_1101c054,(PatrolRoute *)(unaff_EBP + -0x94));
  ScGroup::SetLights((ScGroup *)&DAT_1101c054,1);
  TethysGame::CreateUnit(unaff_EBP + -0x10,5,0x8d,0x10,1,0x3d,3);
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c054,*(undefined4 *)(unaff_EBP + -0x10));
  TethysGame::CreateUnit(unaff_EBP + -0x10,5,0x90,0x19,1,0x3d,2);
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c054,*(undefined4 *)(unaff_EBP + -0x10));
  TethysGame::CreateUnit(unaff_EBP + -0x10,5,0x8d,8,1,0x3d,1);
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c054,*(undefined4 *)(unaff_EBP + -0x10));
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c054,5,0x3d,DAT_1101c0f8 + 2);
  pFVar2 = (FightGroup *)CreateFightGroup(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FightGroup::operator=((FightGroup *)&DAT_1101c058,pFVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(unaff_EBP + -0xac),0xb3,0x14,0xbb,0x3c);
  FightGroup::SetRect((FightGroup *)&DAT_1101c058,pMVar3);
  *(int *)(unaff_EBP + -0x98) = unaff_EBP + -0x2c;
  FightGroup::SetPatrolMode((FightGroup *)&DAT_1101c058,(PatrolRoute *)(unaff_EBP + -0x9c));
  ScGroup::SetLights((ScGroup *)&DAT_1101c058,1);
  TethysGame::CreateUnit(unaff_EBP + -0x10,5,0xb5,0x16,1,0x3d,3);
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c058,*(undefined4 *)(unaff_EBP + -0x10));
  TethysGame::CreateUnit(unaff_EBP + -0x10,5,0xb7,0x28,1,0x3d,2);
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c058,*(undefined4 *)(unaff_EBP + -0x10));
  TethysGame::CreateUnit(unaff_EBP + -0x10,5,0xb8,0x39,1,0x3d,1);
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c058,*(undefined4 *)(unaff_EBP + -0x10));
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c058,5,0x3d,DAT_1101c0f8 + 2);
  pFVar2 = (FightGroup *)CreateFightGroup(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FightGroup::operator=((FightGroup *)&DAT_1101c05c,pFVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(unaff_EBP + -0xac),0xc0,10,0xd7,0x37);
  FightGroup::SetRect((FightGroup *)&DAT_1101c05c,pMVar3);
  *(int *)(unaff_EBP + -0x88) = unaff_EBP + -0x84;
  FightGroup::SetPatrolMode((FightGroup *)&DAT_1101c05c,(PatrolRoute *)(unaff_EBP + -0x8c));
  ScGroup::SetLights((ScGroup *)&DAT_1101c05c,1);
  TethysGame::CreateUnit(unaff_EBP + -0x10,5,0xaf,8,1,0x3d,3);
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c05c,*(undefined4 *)(unaff_EBP + -0x10));
  TethysGame::CreateUnit(unaff_EBP + -0x10,5,0xb1,2,1,0x3d,2);
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c05c,*(undefined4 *)(unaff_EBP + -0x10));
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c05c,5,0x3d,DAT_1101c0f8 + 2);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11003b2b FUN_11003b2b  (called by: FUN_11003bd0@11003bd0)

void FUN_11003b2b(void)

{
  int iVar1;
  
  iVar1 = ScGroup::TotalUnitCount((ScGroup *)&DAT_1101c084);
  if (0 < iVar1) {
    FUN_11007b70('\x01','\x01',1,0x40,0x1e,5,0x3e);
    DAT_1101c120 = 1;
  }
  return;
}


// ---- 11003b5f FUN_11003b5f  (called by: -)

void FUN_11003b5f(void)

{
  int iVar1;
  int *piVar2;
  undefined1 *puVar3;
  undefined1 local_14 [8];
  GroupEnumerator local_c [4];
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  GroupEnumerator::GroupEnumerator(local_c,(ScGroup *)&DAT_1101c084);
  while (iVar1 = GroupEnumerator::GetNext(local_c,(Unit *)&local_8), iVar1 != 0) {
    puVar3 = local_14;
    piVar2 = (int *)Unit::Location((Unit *)&local_8);
    if (*piVar2 < 0x46) {
      ScGroup::RemoveUnit((ScGroup *)&DAT_1101c084,local_8,puVar3);
      ScGroup::TakeUnit((ScGroup *)&DAT_1101c08c,local_8);
    }
  }
  DAT_1101c120 = 0;
  return;
}


// ---- 11003bd0 FUN_11003bd0  (called by: -)

void FUN_11003bd0(void)

{
  int iVar1;
  MAP_RECT *pMVar2;
  int iVar3;
  map_id mVar4;
  LOCATION *pLVar5;
  undefined1 *puVar6;
  InRectEnumerator local_58 [52];
  MAP_RECT local_24 [8];
  undefined1 local_1c [8];
  int local_14;
  int local_10;
  GroupEnumerator local_c [4];
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  local_14 = 0;
  local_10 = 0;
  iVar1 = TethysGame::Tick();
  if ((0x1964 < iVar1 % 0x4074) && (iVar1 % 0x4074 < 13000)) {
    GroupEnumerator::GroupEnumerator(local_c,(ScGroup *)&DAT_1101c07c);
    iVar1 = GroupEnumerator::GetNext(local_c,(Unit *)&local_8);
    while (iVar1 != 0) {
      puVar6 = local_1c;
      iVar1 = Unit::Location((Unit *)&local_8);
      if (0x22 < *(int *)(iVar1 + 4)) {
        ScGroup::RemoveUnit((ScGroup *)&DAT_1101c07c,local_8,puVar6);
        ScGroup::TakeUnit((ScGroup *)&DAT_1101c084,local_8);
      }
      iVar1 = GroupEnumerator::GetNext(local_c,(Unit *)&local_8);
    }
    iVar1 = TethysGame::Tick();
    if (iVar1 < 0x4e21) {
      pMVar2 = (MAP_RECT *)MAP_RECT::MAP_RECT(local_24,0x20,0x20,0x96,0x3e);
      InRectEnumerator::InRectEnumerator(local_58,pMVar2);
      do {
        iVar1 = InRectEnumerator::GetNext(local_58,(Unit *)&local_8);
        if (iVar1 == 0) goto LAB_11003d24;
        iVar3 = Unit::OwnerID((Unit *)&local_8);
      } while (((0 < iVar3) ||
               ((mVar4 = Unit::GetType((Unit *)&local_8), (int)mVar4 < 0x18 &&
                (mVar4 = Unit::GetType((Unit *)&local_8), mVar4 != 0x15)))) && (0 < iVar1));
      if (0 < iVar1) {
        pLVar5 = (LOCATION *)Unit::Location((Unit *)&local_8);
        LOCATION::operator=((LOCATION *)&local_14,pLVar5);
        FightGroup::ClearGuarderdRects((FightGroup *)&DAT_1101c084);
        pMVar2 = (MAP_RECT *)
                 MAP_RECT::MAP_RECT(local_24,local_14 + -3,local_10 + -3,local_14 + 3,local_10 + 3);
        FightGroup::SetRect((FightGroup *)&DAT_1101c084,pMVar2);
        return;
      }
    }
LAB_11003d24:
    FUN_11003b2b();
  }
  return;
}


// ---- 11003d2e FUN_11003d2e  (called by: FUN_11003dd3@11003dd3)

void FUN_11003d2e(void)

{
  int iVar1;
  
  iVar1 = ScGroup::TotalUnitCount((ScGroup *)&DAT_1101c088);
  if (0 < iVar1) {
    FUN_11007b70('\x01','\x01',1,0x40,0,5,0x20);
    DAT_1101c121 = 1;
  }
  return;
}


// ---- 11003d62 FUN_11003d62  (called by: -)

void FUN_11003d62(void)

{
  int iVar1;
  int *piVar2;
  undefined1 *puVar3;
  undefined1 local_14 [8];
  GroupEnumerator local_c [4];
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  GroupEnumerator::GroupEnumerator(local_c,(ScGroup *)&DAT_1101c088);
  while (iVar1 = GroupEnumerator::GetNext(local_c,(Unit *)&local_8), iVar1 != 0) {
    puVar3 = local_14;
    piVar2 = (int *)Unit::Location((Unit *)&local_8);
    if (*piVar2 < 0x46) {
      ScGroup::RemoveUnit((ScGroup *)&DAT_1101c088,local_8,puVar3);
      ScGroup::TakeUnit((ScGroup *)&DAT_1101c090,local_8);
    }
  }
  DAT_1101c121 = 0;
  return;
}


// ---- 11003dd3 FUN_11003dd3  (called by: -)

void FUN_11003dd3(void)

{
  int iVar1;
  int *piVar2;
  MAP_RECT *pMVar3;
  int iVar4;
  map_id mVar5;
  LOCATION *pLVar6;
  undefined1 *puVar7;
  InRectEnumerator local_58 [52];
  MAP_RECT local_24 [8];
  undefined1 local_1c [8];
  int local_14;
  int local_10;
  GroupEnumerator local_c [4];
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  local_14 = 0;
  local_10 = 0;
  iVar1 = TethysGame::Tick();
  if ((0x1964 < iVar1 % 0x4074) && (iVar1 % 0x4074 < 13000)) {
    GroupEnumerator::GroupEnumerator(local_c,(ScGroup *)&DAT_1101c080);
    iVar1 = GroupEnumerator::GetNext(local_c,(Unit *)&local_8);
    while (iVar1 != 0) {
      puVar7 = local_1c;
      piVar2 = (int *)Unit::Location((Unit *)&local_8);
      if (*piVar2 < 0x87) {
        ScGroup::RemoveUnit((ScGroup *)&DAT_1101c080,local_8,puVar7);
        ScGroup::TakeUnit((ScGroup *)&DAT_1101c088,local_8);
      }
      iVar1 = GroupEnumerator::GetNext(local_c,(Unit *)&local_8);
    }
    iVar1 = TethysGame::Tick();
    if (iVar1 < 0x4e21) {
      pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT(local_24,0x20,0,0x96,0xd);
      InRectEnumerator::InRectEnumerator(local_58,pMVar3);
      do {
        iVar1 = InRectEnumerator::GetNext(local_58,(Unit *)&local_8);
        if (iVar1 == 0) goto LAB_11003f29;
        iVar4 = Unit::OwnerID((Unit *)&local_8);
      } while (((0 < iVar4) ||
               ((mVar5 = Unit::GetType((Unit *)&local_8), (int)mVar5 < 0x18 &&
                (mVar5 = Unit::GetType((Unit *)&local_8), mVar5 != 0x15)))) && (0 < iVar1));
      if (0 < iVar1) {
        pLVar6 = (LOCATION *)Unit::Location((Unit *)&local_8);
        LOCATION::operator=((LOCATION *)&local_14,pLVar6);
        FightGroup::ClearGuarderdRects((FightGroup *)&DAT_1101c088);
        pMVar3 = (MAP_RECT *)
                 MAP_RECT::MAP_RECT(local_24,local_14 + -3,local_10 + -3,local_14 + 3,local_10 + 3);
        FightGroup::SetRect((FightGroup *)&DAT_1101c088,pMVar3);
        return;
      }
    }
LAB_11003f29:
    FUN_11003d2e();
  }
  return;
}


// ---- 11003f33 FUN_11003f33  (called by: InitProc@11005597)

void FUN_11003f33(void)

{
  DAT_1101c0ec = DAT_1101c0f8 + 2;
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c0b8,DAT_1101c024);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c0b8,(ScGroup *)&DAT_1101c070,0x50);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c070,5,0x3d,DAT_1101c0ec);
  FUN_11007770('\x01','\0',(6 - DAT_1101c0f4) * 1000,FUN_11003f9d,0);
  return;
}


// ---- 11003f9d FUN_11003f9d  (called by: -)

void FUN_11003f9d(void)

{
  int iVar1;
  int *piVar2;
  undefined1 *puVar3;
  undefined1 local_14 [8];
  GroupEnumerator local_c [4];
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  GroupEnumerator::GroupEnumerator(local_c,(ScGroup *)&DAT_1101c074);
  iVar1 = GroupEnumerator::GetNext(local_c,(Unit *)&local_8);
  while (iVar1 != 0) {
    puVar3 = local_14;
    piVar2 = (int *)Unit::Location((Unit *)&local_8);
    if (*piVar2 < 0x90) {
      ScGroup::RemoveUnit((ScGroup *)&DAT_1101c074,local_8,puVar3);
      ScGroup::TakeUnit((ScGroup *)&DAT_1101c078,local_8);
    }
    iVar1 = GroupEnumerator::GetNext(local_c,(Unit *)&local_8);
  }
  iVar1 = ScGroup::UnitCount((ScGroup *)&DAT_1101c070,0);
  if (iVar1 == DAT_1101c0ec) {
    ScGroup::TakeAllUnits((ScGroup *)&DAT_1101c074,(ScGroup *)&DAT_1101c070);
  }
  return;
}


// ---- 11004032 FUN_11004032  (called by: FUN_110040b2@110040b2)

void FUN_11004032(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  uVar1 = DAT_1101c0d0;
  iVar3 = DAT_1101c0cc + 6;
  iVar2 = (-(uint)(DAT_1101c0e8 != '\0') & 2) + 2;
  do {
    TethysGame::CreateUnit(&local_8,5,0x21,0x3c,0,0x3e,7);
    Unit::DoMove((Unit *)&local_8,iVar3,uVar1);
    Unit::DoSetLights((Unit *)&local_8,1);
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TethysGame::AddMessage(s_Reinforcements_have_arrived_11015228,0,local_8,0xa2);
  return;
}


// ---- 110040b2 FUN_110040b2  (called by: FUN_110021fa@110021fa)

void FUN_110040b2(void)

{
  int iVar1;
  
  iVar1 = FUN_11007280(0,5,0xffffffff);
  if (iVar1 < (int)((-(uint)(DAT_1101c0ea != '\0') & 0xfffffffe) + 9)) {
    FUN_11004032();
  }
  return;
}


// ---- 110040dd FUN_110040dd  (called by: -)

void FUN_110040dd(void)

{
  int iVar1;
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  ScGroup::TakeAllUnits((ScGroup *)&DAT_1101c09c,(ScGroup *)&DAT_1101c094);
  for (iVar1 = DAT_1101c0f4 + 1; -1 < iVar1; iVar1 = iVar1 + -1) {
    TethysGame::CreateUnit(&local_8,5,0x11d - iVar1 / 2,0x39 - iVar1 % 2,2,0x3e,4);
    ScGroup::TakeUnit((ScGroup *)&DAT_1101c094,local_8);
  }
  FightGroup::SetCombineFire((FightGroup *)&DAT_1101c09c);
  FUN_110075b0('\x01','\x01',(ScStub *)&DAT_1101c09c,3,FUN_110040dd,0);
  return;
}


// ---- 11004170 FUN_11004170  (called by: -)

void FUN_11004170(void)

{
  int iVar1;
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  for (iVar1 = DAT_1101c0f4 + 2; -1 < iVar1; iVar1 = iVar1 + -1) {
    TethysGame::CreateUnit(&local_8,5,iVar1 / 2 + 0x21,0x3d - iVar1 % 2,2,0x40,7);
    ScGroup::TakeUnit((ScGroup *)&DAT_1101c0a0,local_8);
  }
  FUN_110075b0('\x01','\x01',(ScStub *)&DAT_1101c0a0,3,FUN_11004170,0);
  return;
}


// ---- 110041e5 FUN_110041e5  (called by: -)

void FUN_110041e5(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  
  FUN_11008fa8();
  IUnit::IUnit((IUnit *)(unaff_EBP + -0x14));
  puVar2 = (undefined4 *)MAP_RECT::MAP_RECT((MAP_RECT *)(unaff_EBP + -0x34),0xdb,0x1e,0xe2,0x28);
  *(undefined4 *)(unaff_EBP + -0x24) = *puVar2;
  *(undefined4 *)(unaff_EBP + -0x20) = puVar2[1];
  *(undefined4 *)(unaff_EBP + -0x1c) = puVar2[2];
  *(undefined4 *)(unaff_EBP + -0x18) = puVar2[3];
  FightGroup::SetRect((FightGroup *)&DAT_1101c098,(MAP_RECT *)(unaff_EBP + -0x24));
  FightGroup::SetRect((FightGroup *)&DAT_1101c09c,(MAP_RECT *)(unaff_EBP + -0x24));
  FightGroup::SetCombineFire((FightGroup *)&DAT_1101c098);
  FightGroup::DoGuardGroup((FightGroup *)&DAT_1101c09c);
  uVar1 = DAT_1101c098;
  *(undefined4 *)(unaff_EBP + -0x10) = DAT_1101c098;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FightGroup::SetTargetGroup((FightGroup *)&DAT_1101c09c,uVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  FightGroup::SetFollowMode((FightGroup *)&DAT_1101c09c,1);
  ScGroup::ClearTargCount((ScGroup *)&DAT_1101c068);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c068,5,0x3d,DAT_1101c0f8 + 2);
  FUN_11007770('\x01','\x01',4000,FUN_110042c2,0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 110042c2 FUN_110042c2  (called by: -)

void FUN_110042c2(void)

{
  MAP_RECT *pMVar1;
  MAP_RECT local_10 [16];
  
  FightGroup::ClearGuarderdRects((FightGroup *)&DAT_1101c098);
  pMVar1 = (MAP_RECT *)MAP_RECT::MAP_RECT(local_10,0xb2,0x14,0xba,0x1e);
  FightGroup::SetRect((FightGroup *)&DAT_1101c098,pMVar1);
  FUN_11007770('\x01','\x01',0x9c4,FUN_11004311,0);
  return;
}


// ---- 11004311 FUN_11004311  (called by: -)

void FUN_11004311(void)

{
  MAP_RECT *pMVar1;
  MAP_RECT aMStack_10 [16];
  
  DAT_1101c0fc = 1;
  FightGroup::SetAttackType((FightGroup *)&DAT_1101c098,0x17);
  FightGroup::DoAttackEnemy((FightGroup *)&DAT_1101c098);
  FightGroup::ClearGuarderdRects((FightGroup *)&DAT_1101c098);
  pMVar1 = (MAP_RECT *)MAP_RECT::MAP_RECT(aMStack_10,0x1f,2,0xb0,0x28);
  FightGroup::SetRect((FightGroup *)&DAT_1101c098,pMVar1);
  FightGroup::DoAttackEnemy((FightGroup *)&DAT_1101c068);
  FUN_11007b70('\x01','\x01',2,0x8a,10,6,3);
  return;
}


// ---- 11004389 FUN_11004389  (called by: -)

void FUN_11004389(void)

{
  undefined4 *puVar1;
  int iVar2;
  MAP_RECT local_28 [16];
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  puVar1 = (undefined4 *)
           MAP_RECT::MAP_RECT(local_28,DAT_1101c0cc + -10,DAT_1101c0d0 + -6,DAT_1101c0cc + 10,
                              DAT_1101c0d0 + 6);
  local_18 = *puVar1;
  uStack_14 = puVar1[1];
  uStack_10 = puVar1[2];
  uStack_c = puVar1[3];
  iVar2 = 2;
  do {
    TethysGame::CreateUnit(&local_8,5,iVar2 + 0x20,0x3c,2,0x40,7);
    ScGroup::TakeUnit((ScGroup *)&DAT_1101c098,local_8);
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  FightGroup::ClearGuarderdRects((FightGroup *)&DAT_1101c098);
  FightGroup::SetRect((FightGroup *)&DAT_1101c098,(MAP_RECT *)&local_18);
  return;
}


// ---- 11004410 FUN_11004410  (called by: -)

void FUN_11004410(void)

{
  FightGroup::ClearGuarderdRects((FightGroup *)&DAT_1101c09c);
  FightGroup::SetFollowMode((FightGroup *)&DAT_1101c09c,0);
  FightGroup::DoAttackEnemy((FightGroup *)&DAT_1101c09c);
  FightGroup::SetCombineFire((FightGroup *)&DAT_1101c09c);
  return;
}


// ---- 1100443a FUN_1100443a  (called by: FUN_1100451e@1100451e)

void FUN_1100443a(void)

{
  map_id *pmVar1;
  int iVar2;
  PlayerBuildingEnum *pPVar3;
  int *piVar4;
  Unit *pUVar5;
  int local_40 [8];
  PlayerBuildingEnum local_20 [8];
  PlayerBuildingEnum local_18 [8];
  IUnit local_10 [4];
  undefined4 local_c;
  int local_8;
  
  IUnit::IUnit(local_10);
  IUnit::IUnit((IUnit *)&local_c);
  local_40[0] = 0x31;
  local_40[1] = 0x26;
  local_40[2] = 0x30;
  local_40[3] = 0x1c;
  local_40[4] = 0x2f;
  local_40[5] = 0x1e;
  local_40[6] = 0x27;
  local_40[7] = 0;
  PlayerBuildingEnum::PlayerBuildingEnum(local_18,0,0x31);
  local_8 = 0;
  iVar2 = PlayerBuildingEnum::GetNext(local_18,(Unit *)&local_c);
  if (iVar2 == 0) {
    piVar4 = local_40;
    do {
      pmVar1 = (map_id *)(piVar4 + 1);
      local_8 = local_8 + 1;
      piVar4 = piVar4 + 1;
      if (*pmVar1 == 0) break;
      pPVar3 = (PlayerBuildingEnum *)PlayerBuildingEnum::PlayerBuildingEnum(local_20,0,*pmVar1);
      PlayerBuildingEnum::operator=(local_18,pPVar3);
      iVar2 = PlayerBuildingEnum::GetNext(local_18,(Unit *)&local_c);
    } while (iVar2 == 0);
  }
  pUVar5 = (Unit *)&DAT_1101c144;
  if (local_40[local_8] == 0) {
    do {
      ScGroup::TakeUnit((ScGroup *)&DAT_1101c0a4,*(undefined4 *)pUVar5);
      pUVar5 = pUVar5 + 4;
    } while ((int)pUVar5 < 0x1101c15c);
  }
  else {
    do {
      Unit::DoAttack(pUVar5,local_c);
      pUVar5 = pUVar5 + 4;
    } while ((int)pUVar5 < 0x1101c15c);
  }
  return;
}


// ---- 1100451e FUN_1100451e  (called by: FUN_110047a6@110047a6)

void FUN_1100451e(void)

{
  FightGroup *pFVar1;
  MAP_RECT *pMVar2;
  int unaff_EBP;
  Unit *this;
  int iVar3;
  
  FUN_11008fa8();
  iVar3 = 0;
  this = (Unit *)&DAT_1101c144;
  do {
    TethysGame::CreateUnit(this,5,iVar3 / 2 + 0x20,iVar3 % 2 + 0x3c,2,0x40,7);
    Unit::DoSetLights(this,1);
    this = this + 4;
    iVar3 = iVar3 + 1;
  } while ((int)this < 0x1101c15c);
  pFVar1 = (FightGroup *)CreateFightGroup(unaff_EBP + -0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FightGroup::operator=((FightGroup *)&DAT_1101c0a4,pFVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  pMVar2 = (MAP_RECT *)
           MAP_RECT::MAP_RECT((MAP_RECT *)(unaff_EBP + -0x20),0x20,DAT_1101c0d0 + -3,0x22,
                              DAT_1101c0d0 + 3);
  FightGroup::SetRect((FightGroup *)&DAT_1101c0a4,pMVar2);
  FightGroup::DoExitMap((FightGroup *)&DAT_1101c0a4);
  FUN_11007770('\x01','\0',100,FUN_1100443a,0);
  FUN_1100443a();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11004600 FUN_11004600  (called by: -)

void FUN_11004600(void)

{
  bool bVar1;
  int iVar2;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  PlayerVehicleEnum local_c [4];
  IUnit local_8 [4];
  
  IUnit::IUnit(local_8);
  PlayerVehicleEnum::PlayerVehicleEnum(local_c,0);
  MAP_RECT::MAP_RECT((MAP_RECT *)&local_1c,DAT_11016240 + -0xc,DAT_11016244 + -0xc,
                     DAT_11016240 + 0xc,DAT_11016244 + 0xc);
  do {
    iVar2 = PlayerVehicleEnum::GetNext(local_c,(Unit *)local_8);
    if (iVar2 == 0) {
      Trigger::Enable((Trigger *)&DAT_1101c124);
      return;
    }
    bVar1 = IUnit::IsInRect(local_8,local_1c,uStack_18,uStack_14,uStack_10);
  } while (bVar1);
  return;
}


// ---- 11004684 FUN_11004684  (called by: FUN_110047a6@110047a6)

undefined4 __cdecl FUN_11004684(int param_1)

{
  int iVar1;
  int *piVar2;
  map_id mVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  PlayerVehicleEnum local_28 [4];
  Truck_Cargo local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  IUnit local_8 [4];
  
  IUnit::IUnit(local_8);
  iVar6 = 0;
  local_1c = 0;
  local_20 = 0;
  iVar5 = 0;
  local_10 = 0;
  local_c = 0;
  local_14 = 0;
  local_18 = 0;
  PlayerVehicleEnum::PlayerVehicleEnum(local_28,0);
  while (iVar1 = PlayerVehicleEnum::GetNext(local_28,(Unit *)local_8), iVar1 != 0) {
    piVar2 = (int *)Unit::Location((Unit *)local_8);
    if (param_1 < *piVar2) {
      mVar3 = Unit::GetType((Unit *)local_8);
      if (mVar3 == 1) {
        iVar1 = IUnit::GetTruckCargo(local_8,&local_24);
        if (local_24 == 1) {
          iVar6 = iVar6 + iVar1;
        }
        else if (local_24 == 4) {
          iVar5 = iVar5 + iVar1;
        }
      }
      else if (mVar3 == 2) {
        mVar3 = Unit::GetCargo((Unit *)local_8);
        if (mVar3 == 0x1c) {
          local_10 = local_10 + 1;
        }
        else if (mVar3 == 0x2f) {
          local_14 = local_14 + 1;
        }
        else if (mVar3 == 0x36) {
          local_18 = local_18 + 1;
        }
        else if (mVar3 == 0x3a) {
          local_c = local_c + 1;
        }
      }
      else if (mVar3 == 8) {
        local_20 = local_20 + 1;
      }
      else if (mVar3 == 9) {
        local_1c = local_1c + 1;
      }
    }
  }
  if ((iVar6 < DAT_1101c100 * 1000) || (iVar5 < DAT_1101c104 * 1000)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0;
    if ((((0 < local_c) && (0 < local_10)) && (0 < local_14)) &&
       (((0 < local_18 && (0 < local_1c)) && (0 < local_20)))) {
      uVar4 = 1;
    }
  }
  return uVar4;
}


// ---- 110047a6 FUN_110047a6  (called by: -)

void FUN_110047a6(void)

{
  undefined4 uVar1;
  MAP_RECT *pMVar2;
  MAP_RECT local_10 [16];
  
  if (DAT_1101c122 == '\0') {
    uVar1 = FUN_11004684(0x96);
    if ((char)uVar1 != '\0') {
      DAT_1101c122 = '\x01';
      FightGroup::ClearGuarderdRects((FightGroup *)&DAT_1101c06c);
      pMVar2 = (MAP_RECT *)MAP_RECT::MAP_RECT(local_10,0xb2,0x14,0xba,0x1e);
      FightGroup::SetRect((FightGroup *)&DAT_1101c06c,pMVar2);
      FightGroup::DoAttackEnemy((FightGroup *)&DAT_1101c06c);
    }
  }
  uVar1 = FUN_11004684(0xb8);
  if ((char)uVar1 != '\0') {
    FUN_1100451e();
  }
  return;
}


// ---- 11004818 FUN_11004818  (called by: -)

void FUN_11004818(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  iVar1 = TethysGame::GetRand(0x1e);
  iVar2 = TethysGame::GetRand(0x1e);
  TethysGame::SetEarthquake(iVar2 + 0x40,iVar1 + 8,iVar3);
  return;
}


// ---- 11004841 FUN_11004841  (called by: -)

void FUN_11004841(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  iVar1 = TethysGame::GetRand(0x3e);
  iVar2 = TethysGame::GetRand(0xff);
  TethysGame::SetEarthquake(iVar2 + 0x20,iVar1 + 1,iVar3);
  return;
}


// ---- 1100486a FUN_1100486a  (called by: -)

void FUN_1100486a(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  iVar1 = TethysGame::GetRand(0x3e);
  iVar2 = TethysGame::GetRand(0xff);
  TethysGame::SetMeteor(iVar2 + 0x20,iVar1 + 1,iVar3);
  return;
}


// ---- 11004893 FUN_11004893  (called by: -)

void FUN_11004893(void)

{
  GameMap::SetTile(0x450,9,0xfd,9);
  GameMap::SetTile(0x45b,9,0xfe,9);
  GameMap::SetTile(0x466,10,0xfd,10);
  GameMap::SetTile(0x471);
  TethysGame::SetEruption(0xfd,10,0x3c);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c0b4,(ScGroup *)&DAT_1101c0b0,5000);
  FUN_11007770('\x01','\x01',7000,FUN_110034b1,0);
  return;
}


// ---- 1100491a FUN_1100491a  (called by: InitMap@11004a36)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1100491a(int *param_1)

{
  int iVar1;
  PlayerBuildingEnum *this;
  LOCATION *pLVar2;
  MAP_RECT *pMVar3;
  int *piVar4;
  int iVar5;
  Unit *pUVar6;
  MAP_RECT local_14 [8];
  PlayerBuildingEnum local_c [8];
  
  pUVar6 = (Unit *)&DAT_1101c01c;
  this = (PlayerBuildingEnum *)PlayerBuildingEnum::PlayerBuildingEnum(local_c,0,0x1c);
  PlayerBuildingEnum::GetNext(this,pUVar6);
  _DAT_1101c108 = (DAT_1101c0ea == '\0') + 1;
  _DAT_1101c10c = 4 - (uint)(DAT_1101c0ea != '\0');
  _DAT_1101c110 = 3 - DAT_1101c0f4;
  _DAT_1101c114 = 1;
  pLVar2 = (LOCATION *)Unit::Location((Unit *)&DAT_1101c01c);
  LOCATION::operator=((LOCATION *)&DAT_1101c0cc,pLVar2);
  pMVar3 = (MAP_RECT *)
           MAP_RECT::MAP_RECT(local_14,DAT_1101c0cc + -6,DAT_1101c0d0 + -10,DAT_1101c0cc + 10,
                              DAT_1101c0d0 + 4);
  MAP_RECT::operator=((MAP_RECT *)&DAT_1101c0d4,pMVar3);
  iVar5 = 0;
  if (0 < *param_1) {
    do {
      piVar4 = (int *)FUN_11006bc4(param_1,iVar5);
      if (piVar4[5] == 0) {
        iVar1 = *piVar4;
        if (iVar1 == 1) {
          _DAT_1101c10c = _DAT_1101c10c + -1;
        }
        else if (iVar1 == 2) {
          _DAT_1101c108 = _DAT_1101c108 + -1;
        }
        else if (iVar1 == 8) {
          _DAT_1101c114 = _DAT_1101c114 + -1;
        }
        else if (iVar1 == 9) {
          _DAT_1101c110 = _DAT_1101c110 + -1;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *param_1);
  }
  iVar5 = FUN_11007160(0,0x15,0xffffffff);
  _DAT_1101c110 = _DAT_1101c110 - iVar5;
  return;
}


// ---- 11004a20 FUN_11004a20  (called by: InitMap@11004a36)

bool FUN_11004a20(void)

{
  int iVar1;
  
  iVar1 = _Player::Difficulty((_Player *)Player_exref);
  return DAT_11016248 != iVar1;
}


// ---- 11004a36 InitMap  (called by: InitProc@11005597)

char InitMap(void)

{
  code *pcVar1;
  bool bVar2;
  undefined4 uVar3;
  PlayerBuildingEnum *this;
  int iVar4;
  int *piVar5;
  ClosestEnumerator *pCVar6;
  int iVar7;
  map_id mVar8;
  int *piVar9;
  int iVar10;
  Unit *this_00;
  IUnit *pIVar11;
  char local_d4 [28];
  ClosestEnumerator local_b8 [52];
  ClosestEnumerator local_84 [52];
  undefined1 local_50 [8];
  undefined1 local_48 [8];
  undefined1 local_40 [8];
  PlayerBuildingEnum local_38 [8];
  char *local_30 [3];
  IUnit local_24 [4];
  int local_20;
  int local_1c;
  uint local_18;
  char local_11;
  int *local_10;
  IUnit local_c [7];
  char local_5;
  
                    /* 0x4a36  7  InitMap */
  local_10 = operator_new(8);
  if (local_10 == (int *)0x0) {
    local_10 = (int *)0x0;
  }
  else {
    FUN_11006b55(local_10);
  }
  local_20 = 0x3c;
  local_1c = 0x14;
  ClosestEnumerator::ClosestEnumerator(local_84,(LOCATION *)&local_20);
  IUnit::IUnit(local_c);
  IUnit::IUnit(local_24);
  local_5 = FUN_11006737();
  if (local_5 != '\0') {
    uVar3 = FUN_110064f3(0,s_Q01_mis_11015298,'\0');
    local_5 = (char)uVar3;
    if (local_5 != '\0') {
      uVar3 = FUN_110064f3(1,s_Q01_mis_11015298,'\0');
      local_5 = (char)uVar3;
      if (local_5 != '\0') {
        uVar3 = FUN_1100690b(s_Q01_mis_11015298,local_10);
        local_5 = (char)uVar3;
      }
    }
  }
  bVar2 = FUN_11004a20();
  if (bVar2) {
    local_30[0] = &DAT_11015290;
    DAT_1101c0e8 = DAT_11016248 == 0;
    local_30[1] = s_medium_11015288;
    DAT_1101c0f8 = DAT_11016248 * 2;
    local_30[2] = &DAT_11015280;
    DAT_1101c0e9 = DAT_11016248 == 1;
    DAT_1101c0f4 = DAT_11016248;
    DAT_1101c0ea = DAT_11016248 == 2;
    scr_snprintf(local_d4,0x50,&DAT_11015250,local_30[DAT_11016248]);
    (*DAT_11015464)(s_Renegades_11015244,0);
  }
  if (local_5 != '\0') {
    pIVar11 = local_24;
    this = (PlayerBuildingEnum *)
           PlayerBuildingEnum::PlayerBuildingEnum((PlayerBuildingEnum *)&local_20,0,0x36);
    iVar4 = PlayerBuildingEnum::GetNext(this,(Unit *)pIVar11);
    local_11 = iVar4 != 0;
    iVar4 = *local_10;
    pcVar1 = Location_exref;
joined_r0x11004b89:
    iVar4 = iVar4 + -1;
    if (-1 < iVar4) {
      piVar5 = (int *)FUN_11006bc4(local_10,iVar4);
      if (piVar5[5] == 0) {
        local_20 = piVar5[3];
        local_1c = piVar5[4];
        pCVar6 = (ClosestEnumerator *)
                 ClosestEnumerator::ClosestEnumerator(local_b8,(LOCATION *)&local_20);
        ClosestEnumerator::operator=(local_84,pCVar6);
        do {
          do {
            iVar7 = ClosestEnumerator::GetNext(local_84,(Unit *)local_c,&local_18);
            if (iVar7 == 0) goto joined_r0x11004b89;
            local_18 = local_18 >> 9;
            iVar7 = Unit::IsVehicle((Unit *)local_c);
          } while ((iVar7 != 0) || (iVar7 = Unit::OwnerID((Unit *)local_c), iVar7 == 1));
          if (*piVar5 != 1) goto LAB_11004c45;
        } while ((local_11 != '\0') && (mVar8 = Unit::GetType((Unit *)local_c), mVar8 != 0x36));
        if ((*piVar5 == 1) && (0x19 < local_18)) {
          piVar9 = (int *)(*pcVar1)(local_48);
          piVar5[3] = *piVar9;
          iVar7 = (*pcVar1)(local_40);
          piVar5[4] = *(int *)(iVar7 + 4);
        }
        else {
LAB_11004c45:
          if (0x50 < local_18) {
            piVar9 = (int *)(*pcVar1)(local_50);
            iVar7 = *piVar9;
            iVar10 = TethysGame::GetRand(0xb);
            piVar5[3] = iVar7 + -5 + iVar10;
            iVar7 = Unit::Location((Unit *)local_c);
            iVar7 = *(int *)(iVar7 + 4);
            iVar10 = TethysGame::GetRand(0xb);
            pcVar1 = Location_exref;
            piVar5[4] = iVar7 + -5 + iVar10;
          }
        }
      }
      goto joined_r0x11004b89;
    }
    FUN_110069dd(0,local_10,'\0','\x01');
    FUN_1100491a(local_10);
    PlayerBuildingEnum::PlayerBuildingEnum(local_38,1,0x30);
    iVar4 = PlayerBuildingEnum::GetNext(local_38,(Unit *)local_c);
    while (iVar4 != 0) {
      piVar5 = (int *)(*pcVar1)(local_30 + 1);
      this_00 = (Unit *)&DAT_1101c024;
      if (*piVar5 < 0xc9) {
        this_00 = (Unit *)&DAT_1101c020;
      }
      Unit::operator=(this_00,(Unit *)local_c);
      iVar4 = PlayerBuildingEnum::GetNext(local_38,(Unit *)local_c);
    }
    FUN_11006bd1(local_10);
  }
  if (local_10 != (int *)0x0) {
    thunk_FUN_11006ba7(local_10);
    FUN_11009086(local_10);
  }
  return local_5;
}


// ---- 11004d2a FUN_11004d2a  (called by: InitProc@11005597)

void FUN_11004d2a(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = &DAT_11014c30;
  do {
    iVar1 = piVar3[2];
    for (iVar2 = *piVar3; iVar2 < iVar1; iVar2 = iVar2 + 1) {
      GameMap::SetLavaPossible(1);
    }
    piVar3 = piVar3 + 3;
  } while (-1 < iVar2);
  GameMap::InitialSetTile(0x447,9,0xfd,9);
  GameMap::InitialSetTile(0x453,9,0xfe,9);
  GameMap::InitialSetTile(0x45e);
  GameMap::InitialSetTile(0x469);
  return;
}


// ---- 11004dac FUN_11004dac  (called by: InitProc@11005597)

void FUN_11004dac(void)

{
  MiningGroup *pMVar1;
  BuildingGroup *pBVar2;
  MAP_RECT *pMVar3;
  FightGroup *pFVar4;
  ScStub aSStackY_1c4 [128];
  int iVar5;
  int iVar6;
  void *pvVar7;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  ScStub aSStack_c6 [6];
  ScStub aSStack_a2 [6];
  ScStub aSStack_7e [6];
  ScStub aSStack_5a [6];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  ScStub aSStack_26 [2];
  undefined1 local_24 [8];
  undefined4 uStack_1c;
  undefined4 uStack_10;
  undefined4 uStack_4;
  
  uStack_4 = 0x11004db6;
  FUN_11008fa8();
  uStack_44 = *(undefined4 *)(Player_exref + 0xc);
  uStack_40 = *(undefined4 *)(Player_exref + 0x10);
  uStack_3c = *(undefined4 *)(Player_exref + 0x14);
  pMVar1 = (MiningGroup *)CreateMiningGroup(local_24);
  uStack_4 = 0;
  uStack_4c = 0x11004df6;
  MiningGroup::operator=((MiningGroup *)&DAT_1101c0c0,pMVar1);
  uStack_4 = 0xffffffff;
  ScStub::~ScStub(aSStack_26 + -10);
  uStack_4c = 0x11004e13;
  ScGroup::SetLights((ScGroup *)&DAT_1101c0c0,1);
  uStack_50 = *(undefined4 *)(Player_exref + 0xc);
  uStack_4c = *(undefined4 *)(Player_exref + 0x10);
  pMVar1 = (MiningGroup *)CreateMiningGroup(aSStack_26 + -10);
  uStack_10 = 1;
  MiningGroup::operator=((MiningGroup *)&DAT_1101c0c4,pMVar1);
  uStack_10 = 0xffffffff;
  ScStub::~ScStub((ScStub *)&uStack_3c);
  ScGroup::SetLights((ScGroup *)&DAT_1101c0c4,1);
  pBVar2 = (BuildingGroup *)CreateBuildingGroup(&uStack_3c);
  uStack_1c = 2;
  BuildingGroup::operator=((BuildingGroup *)&DAT_1101c0a8,pBVar2);
  uStack_1c = 0xffffffff;
  ScStub::~ScStub(aSStack_5a + 0x12);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)&uStack_44,0x94,6,0x9a,8);
  BuildingGroup::SetRect((BuildingGroup *)&DAT_1101c0a8,pMVar3);
  ScGroup::SetLights((ScGroup *)&DAT_1101c0a8,1);
  pBVar2 = (BuildingGroup *)CreateBuildingGroup(aSStack_5a + 0x12);
  BuildingGroup::operator=((BuildingGroup *)&DAT_1101c0ac,pBVar2);
  ScStub::~ScStub(aSStack_5a + 6);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)&uStack_50,0xa8,0x2f,0xac,0x31);
  BuildingGroup::SetRect((BuildingGroup *)&DAT_1101c0ac,pMVar3);
  ScGroup::SetLights((ScGroup *)&DAT_1101c0ac,1);
  pBVar2 = (BuildingGroup *)CreateBuildingGroup(aSStack_5a + 6);
  BuildingGroup::operator=((BuildingGroup *)&DAT_1101c0b0,pBVar2);
  ScStub::~ScStub(aSStack_5a + -6);
  ScGroup::SetLights((ScGroup *)&DAT_1101c0b0,1);
  pBVar2 = (BuildingGroup *)CreateBuildingGroup(aSStack_5a + -6);
  uStack_40 = 5;
  BuildingGroup::operator=((BuildingGroup *)&DAT_1101c0b4,pBVar2);
  uStack_40 = 0xffffffff;
  ScStub::~ScStub(aSStack_7e + 0x12);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_5a + -0xe),0xa4,2,0xb5,8);
  BuildingGroup::SetRect((BuildingGroup *)&DAT_1101c0b4,pMVar3);
  ScGroup::SetLights((ScGroup *)&DAT_1101c0b4,1);
  pBVar2 = (BuildingGroup *)CreateBuildingGroup(aSStack_7e + 0x12);
  uStack_4c = 6;
  BuildingGroup::operator=((BuildingGroup *)&DAT_1101c0b8,pBVar2);
  uStack_4c = 0xffffffff;
  ScStub::~ScStub(aSStack_7e + 6);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_7e + 10),0x10e,4,0x11a,0xc);
  BuildingGroup::SetRect((BuildingGroup *)&DAT_1101c0b8,pMVar3);
  ScGroup::SetLights((ScGroup *)&DAT_1101c0b8,1);
  pBVar2 = (BuildingGroup *)CreateBuildingGroup(aSStack_7e + 6);
  BuildingGroup::operator=((BuildingGroup *)&DAT_1101c0bc,pBVar2);
  ScStub::~ScStub(aSStack_7e + -6);
  ScGroup::SetLights((ScGroup *)&DAT_1101c0bc,1);
  pFVar4 = (FightGroup *)CreateFightGroup(aSStack_7e + -6);
  FightGroup::operator=((FightGroup *)&DAT_1101c074,pFVar4);
  ScStub::~ScStub(aSStack_a2 + 0x12);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_7e + -0xe),0x89,0xd,0x8f,0x11);
  FightGroup::SetRect((FightGroup *)&DAT_1101c074,pMVar3);
  ScGroup::SetLights((ScGroup *)&DAT_1101c074,1);
  pFVar4 = (FightGroup *)CreateFightGroup(aSStack_a2 + 0x12);
  FightGroup::operator=((FightGroup *)&DAT_1101c070,pFVar4);
  ScStub::~ScStub(aSStack_a2 + 6);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_a2 + 10),0x10e,4,0x11a,0xc);
  FightGroup::SetRect((FightGroup *)&DAT_1101c070,pMVar3);
  ScGroup::SetLights((ScGroup *)&DAT_1101c070,1);
  pFVar4 = (FightGroup *)CreateFightGroup(aSStack_a2 + 6);
  FightGroup::operator=((FightGroup *)&DAT_1101c078,pFVar4);
  ScStub::~ScStub(aSStack_a2 + -6);
  FightGroup::SetRect((FightGroup *)&DAT_1101c078,(MAP_RECT *)&DAT_1101c0d4);
  FightGroup::DoAttackEnemy((FightGroup *)&DAT_1101c078);
  ScGroup::SetLights((ScGroup *)&DAT_1101c078,1);
  pFVar4 = (FightGroup *)CreateFightGroup(aSStack_a2 + -6);
  FightGroup::operator=((FightGroup *)&DAT_1101c07c,pFVar4);
  ScStub::~ScStub(aSStack_c6 + 0x12);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_a2 + -0xe),0x8a,0x25,0x8e,0x2a);
  FightGroup::SetRect((FightGroup *)&DAT_1101c07c,pMVar3);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c07c,5,0x3d,DAT_1101c0f8 + 1);
  ScGroup::SetLights((ScGroup *)&DAT_1101c07c,1);
  pFVar4 = (FightGroup *)CreateFightGroup(aSStack_c6 + 0x12);
  FightGroup::operator=((FightGroup *)&DAT_1101c080,pFVar4);
  ScStub::~ScStub(aSStack_c6 + 6);
  uStack_e8 = 0x1100523e;
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_c6 + 10),0x81,6,0x85,10);
  FightGroup::SetRect((FightGroup *)&DAT_1101c080,pMVar3);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c080,5,0x3d,DAT_1101c0f8 + 1);
  ScGroup::SetLights((ScGroup *)&DAT_1101c080,1);
  pFVar4 = (FightGroup *)CreateFightGroup(aSStack_c6 + 6);
  uStack_e8 = 0x11005290;
  FightGroup::operator=((FightGroup *)&DAT_1101c084,pFVar4);
  ScStub::~ScStub(aSStack_c6 + -6);
  uStack_e8 = 0x110052a1;
  ScGroup::SetLights((ScGroup *)&DAT_1101c084,0);
  uStack_ec = *(undefined4 *)(Player_exref + 0xc);
  uStack_e8 = *(undefined4 *)(Player_exref + 0x10);
  pFVar4 = (FightGroup *)CreateFightGroup(aSStack_c6 + -6);
  uStack_f4 = 0x110052d1;
  FightGroup::operator=((FightGroup *)&DAT_1101c088,pFVar4);
  ScStub::~ScStub(aSStack_c6 + -0x12);
  uStack_f4 = 0x110052e2;
  ScGroup::SetLights((ScGroup *)&DAT_1101c088,0);
  uStack_f8 = *(undefined4 *)(Player_exref + 0xc);
  uStack_f4 = *(undefined4 *)(Player_exref + 0x10);
  pFVar4 = (FightGroup *)CreateFightGroup(aSStack_c6 + -0x12);
  FightGroup::operator=((FightGroup *)&DAT_1101c08c,pFVar4);
  ScStub::~ScStub(aSStack_c6 + -0x1e);
  pMVar3 = (MAP_RECT *)
           MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_c6 + -0x1a),DAT_1101c0cc + -3,DAT_1101c0d0 + -3,
                              DAT_1101c0cc + 2,DAT_1101c0d0 + 2);
  FightGroup::SetRect((FightGroup *)&DAT_1101c08c,pMVar3);
  ScGroup::SetLights((ScGroup *)&DAT_1101c08c,0);
  iVar5 = *(int *)(Player_exref + 0x10);
  pvVar7 = *(void **)(Player_exref + 0x14);
  pFVar4 = (FightGroup *)CreateFightGroup(aSStack_c6 + -0x1e);
  FightGroup::operator=((FightGroup *)&DAT_1101c090,pFVar4);
  ScStub::~ScStub(aSStack_c6 + -0x2a);
  pMVar3 = (MAP_RECT *)
           MAP_RECT::MAP_RECT((MAP_RECT *)&uStack_ec,DAT_1101c0cc + -3,DAT_1101c0d0 + -3,
                              DAT_1101c0cc + 2,DAT_1101c0d0 + 2);
  FightGroup::SetRect((FightGroup *)&DAT_1101c090,pMVar3);
  ScGroup::SetLights((ScGroup *)&DAT_1101c090,0);
  iVar6 = *(int *)(Player_exref + 0x10);
  pFVar4 = (FightGroup *)CreateFightGroup(aSStack_c6 + -0x2a);
  FightGroup::operator=((FightGroup *)&DAT_1101c060,pFVar4);
  ScStub::~ScStub(aSStack_c6 + -0x36);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)&uStack_f8,0x8b,2,0x95,8);
  FightGroup::SetRect((FightGroup *)&DAT_1101c060,pMVar3);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c060,5,0x3d,iVar5);
  ScGroup::SetLights((ScGroup *)&DAT_1101c060,1);
  iVar5 = *(int *)(Player_exref + 0x10);
  pFVar4 = (FightGroup *)CreateFightGroup(aSStack_c6 + -0x36);
  FightGroup::operator=((FightGroup *)&DAT_1101c064,pFVar4);
  ScStub::~ScStub(aSStackY_1c4 + 0xbc);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_c6 + -0x3e),0xa4,2,0xb1,9);
  FightGroup::SetRect((FightGroup *)&DAT_1101c064,pMVar3);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c064,5,0x3d,iVar6);
  ScGroup::SetLights((ScGroup *)&DAT_1101c064,1);
  pFVar4 = (FightGroup *)CreateFightGroup(aSStackY_1c4 + 0xbc);
  uStack_e8 = 0x13;
  FightGroup::operator=((FightGroup *)&DAT_1101c068,pFVar4);
  uStack_e8 = 0xffffffff;
  ScStub::~ScStub(aSStackY_1c4 + 0xb0);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStackY_1c4 + 0xb4),0x110,3,0x11d,0xe);
  FightGroup::SetRect((FightGroup *)&DAT_1101c068,pMVar3);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c068,5,0x3d,iVar5);
  ScGroup::SetLights((ScGroup *)&DAT_1101c068,1);
  pFVar4 = (FightGroup *)CreateFightGroup(aSStackY_1c4 + 0xb0);
  uStack_f4 = 0x14;
  FightGroup::operator=((FightGroup *)&DAT_1101c06c,pFVar4);
  uStack_f4 = 0xffffffff;
  ScStub::~ScStub(aSStackY_1c4 + 0xa4);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStackY_1c4 + 0xb8),0xa2,0x2d,0xaa,0x32);
  FightGroup::SetRect((FightGroup *)&DAT_1101c06c,pMVar3);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c06c,5,0x3d,2);
  ScGroup::SetLights((ScGroup *)&DAT_1101c06c,1);
  ExceptionList = pvVar7;
  return;
}


// ---- 11005597 InitProc  (called by: -)

undefined4 InitProc(void)

{
  bool bVar1;
  char cVar2;
  Trigger *pTVar3;
  ScStub aSStack_a7 [3];
  char *pcVar4;
  ScStub aSStack_e [10];
  IUnit local_4 [4];
  
                    /* 0x5597  8  InitProc */
  bVar1 = FUN_11006bf2();
  if (bVar1) {
    IUnit::IUnit(local_4);
    DAT_1101c0f4 = _Player::Difficulty((_Player *)Player_exref);
    DAT_1101c0f8 = DAT_1101c0f4 * 2;
    DAT_1101c0e8 = DAT_1101c0f4 == 0;
    DAT_1101c0e9 = DAT_1101c0f4 == 1;
    DAT_1101c0ea = DAT_1101c0f4 == 2;
    _Player::GoPlymouth((_Player *)Player_exref);
    _Player::GoHuman((_Player *)Player_exref);
    _Player::SetColorNumber((_Player *)Player_exref,1);
    _Player::SetKids((_Player *)Player_exref,0);
    _Player::SetTechLevel((_Player *)Player_exref,2);
    _Player::AllyWith((_Player *)Player_exref,2);
    _Player::MarkResearchComplete((_Player *)Player_exref,0x842);
    _Player::MarkResearchComplete((_Player *)Player_exref,0xc81);
    _Player::MarkResearchComplete((_Player *)Player_exref,0xd50);
    _Player::GoEden((_Player *)(Player_exref + 0xc));
    _Player::GoAI((_Player *)(Player_exref + 0xc));
    _Player::SetColorNumber((_Player *)(Player_exref + 0xc),0);
    _Player::SetFoodStored((_Player *)(Player_exref + 0xc),10000);
    _Player::SetOre((_Player *)(Player_exref + 0xc),10000);
    _Player::SetTechLevel((_Player *)(Player_exref + 0xc),0xc);
    _Player::GoPlymouth((_Player *)(Player_exref + 0x18));
    _Player::GoAI((_Player *)(Player_exref + 0x18));
    _Player::SetColorNumber((_Player *)(Player_exref + 0x18),6);
    _Player::AllyWith((_Player *)(Player_exref + 0x18),0);
    FUN_110012ee(1,0x1f,0,(int *)&DAT_11014bb0);
    FUN_110012ee(1,0x1f,0,(int *)&DAT_11014bd0);
    FUN_11001417(0xc,0x11014890);
    FUN_11004d2a();
    FUN_11007330();
    cVar2 = InitMap();
    if (cVar2 != '\0') {
      FUN_11004dac();
      FUN_1100378f();
      FUN_11002ecd();
      FUN_11006ce5(0);
      GameMap::SetCellType(6);
      TethysGame::FreeMoraleLevel(0);
      TethysGame::SetDaylightMoves(1);
      TethysGame::SetDaylightEverywhere(0);
      TethysGame::SetCheatFastUnits(0);
      TethysGame::SetCheatFastProduction(0);
      TethysGame::SetCheatUnlimitedResources(0);
      TethysGame::SetCheatProduceAll(0);
      Trigger::Trigger((Trigger *)(aSStack_e + -10));
      pTVar3 = (Trigger *)
               CreateEscapeTrigger((int)(aSStack_e + -6),1,0,0,DAT_11016240 + -6,DAT_11016244 + -6,
                                   0xc,0xc,1,2,0x36,(char *)0x0);
      Trigger::operator=((Trigger *)(aSStack_e + -0xe),pTVar3);
      ScStub::~ScStub(aSStack_e + -10);
      CreateVictoryCondition((int)(aSStack_e + -10),1,(Trigger *)0x0,(char *)(aSStack_e + -0xe));
      ScStub::~ScStub(aSStack_e + -0xe);
      pTVar3 = (Trigger *)
               CreateEscapeTrigger((int)(aSStack_e + -0xe),1,0,0,DAT_11016240 + -6,DAT_11016244 + -6
                                   ,0xc,0xc,1,2,0x2f,(char *)0x0);
      Trigger::operator=((Trigger *)(aSStack_e + -0x16),pTVar3);
      ScStub::~ScStub(aSStack_e + -0x12);
      CreateVictoryCondition((int)(aSStack_e + -0x12),1,(Trigger *)0x0,(char *)(aSStack_e + -0x16));
      ScStub::~ScStub(aSStack_e + -0x16);
      pTVar3 = (Trigger *)
               CreateEscapeTrigger((int)(aSStack_e + -0x16),1,0,0,DAT_11016240 + -6,
                                   DAT_11016244 + -6,0xc,0xc,1,2,0x1c,(char *)0x0);
      Trigger::operator=((Trigger *)(aSStack_e + -0x1e),pTVar3);
      ScStub::~ScStub(aSStack_e + -0x1a);
      CreateVictoryCondition((int)(aSStack_e + -0x1a),1,(Trigger *)0x0,(char *)(aSStack_e + -0x1e));
      ScStub::~ScStub(aSStack_e + -0x1e);
      pTVar3 = (Trigger *)
               CreateEscapeTrigger((int)(aSStack_e + -0x1e),1,0,0,DAT_11016240 + -6,
                                   DAT_11016244 + -6,0xc,0xc,1,2,0x3a,(char *)0x0);
      Trigger::operator=((Trigger *)(aSStack_e + -0x26),pTVar3);
      ScStub::~ScStub(aSStack_e + -0x22);
      CreateVictoryCondition((int)(aSStack_e + -0x22),1,(Trigger *)0x0,(char *)(aSStack_e + -0x26));
      ScStub::~ScStub(aSStack_e + -0x26);
      pTVar3 = (Trigger *)
               CreateEscapeTrigger((int)(aSStack_e + -0x26),1,0,0,DAT_11016240 + -6,
                                   DAT_11016244 + -6,0xc,0xc,1,9,-1,(char *)0x0);
      Trigger::operator=((Trigger *)(aSStack_e + -0x2e),pTVar3);
      ScStub::~ScStub(aSStack_e + -0x2a);
      CreateVictoryCondition((int)(aSStack_e + -0x2a),1,(Trigger *)0x0,(char *)(aSStack_e + -0x2e));
      ScStub::~ScStub(aSStack_e + -0x2e);
      pTVar3 = (Trigger *)
               CreateEscapeTrigger((int)(aSStack_e + -0x2e),1,0,0,DAT_11016240 + -6,
                                   DAT_11016244 + -6,0xc,0xc,1,8,-1,(char *)0x0);
      Trigger::operator=((Trigger *)(aSStack_e + -0x36),pTVar3);
      ScStub::~ScStub(aSStack_e + -0x32);
      CreateVictoryCondition((int)(aSStack_e + -0x32),1,(Trigger *)0x0,(char *)(aSStack_e + -0x36));
      ScStub::~ScStub(aSStack_e + -0x36);
      if (DAT_1101c0f4 == 0) {
        _Player::SetOre((_Player *)Player_exref,5000);
        _Player::SetFoodStored((_Player *)Player_exref,3000);
        _Player::SetWorkers((_Player *)Player_exref,0x1e);
        _Player::SetScientists((_Player *)Player_exref,8);
        FUN_11007700('\x01','\0',4000,8000,FUN_1100486a,0);
        FUN_11007700('\x01','\x01',20000,30000,NoResponseToTrigger,0);
        FUN_11007770('\x01','\x01',10000,FUN_11004032,0);
        FUN_11007770('\x01','\x01',0x9c4,FUN_11003f33,0);
        DAT_1101c100 = 2;
        DAT_1101c104 = 4;
        FUN_11007420('\x01','\x01',0,0x31,0,4,FUN_11001b31,0);
        pTVar3 = (Trigger *)
                 CreateOperationalTrigger((int)(aSStack_e + -0x36),1,0,0,0x31,0,(char *)0x4);
        Trigger::operator=((Trigger *)(aSStack_e + -0x3e),pTVar3);
        ScStub::~ScStub(aSStack_e + -0x3a);
        pTVar3 = (Trigger *)
                 CreateVictoryCondition
                           ((int)(aSStack_e + -0x36),1,(Trigger *)0x0,(char *)(aSStack_e + -0x3e));
        Trigger::operator=((Trigger *)&DAT_1101c134,pTVar3);
        ScStub::~ScStub(aSStack_e + -0x3a);
      }
      else if (DAT_1101c0f4 == 1) {
        _Player::SetOre((_Player *)Player_exref,5000);
        _Player::SetFoodStored((_Player *)Player_exref,3000);
        _Player::SetWorkers((_Player *)Player_exref,0x1a);
        _Player::SetScientists((_Player *)Player_exref,6);
        FUN_110012ee(1,0x1f,0,(int *)&DAT_11014bf0);
        FUN_11007700('\x01','\0',2000,4000,FUN_1100486a,0);
        FUN_11007700('\x01','\0',0x9c4,0xdac,FUN_11004818,0);
        FUN_11007700('\x01','\x01',15000,20000,NoResponseToTrigger,0);
        FUN_11003f33();
        DAT_1101c100 = 3;
        DAT_1101c104 = 5;
        FUN_11001b31();
      }
      else if (DAT_1101c0f4 == 2) {
        _Player::SetOre((_Player *)Player_exref,4000);
        _Player::SetFoodStored((_Player *)Player_exref,2000);
        _Player::SetWorkers((_Player *)Player_exref,0x18);
        _Player::SetScientists((_Player *)Player_exref,5);
        FUN_110012ee(1,0x1f,0,(int *)&DAT_11014bf0);
        FUN_110012ee(1,0x1f,0,(int *)&DAT_11014c10);
        FUN_11007700('\x01','\0',0x5dc,0x9c4,FUN_1100486a,0);
        FUN_11007700('\x01','\0',1000,0x5dc,FUN_11004818,0);
        FUN_11007700('\x01','\x01',10000,12000,NoResponseToTrigger,0);
        FUN_11003f33();
        DAT_1101c100 = 3;
        DAT_1101c104 = 6;
        Research3401Done();
        Research3304Done();
        Research3305Done();
      }
      pcVar4 = s_NoResponseToTrigger_1101487c;
      pTVar3 = (Trigger *)
               CreateEscapeTrigger((int)(aSStack_e + -0x3a),1,0,0,DAT_11016240 + -6,
                                   DAT_11016244 + -6,0xc,0xc,DAT_1101c100,1,1,(char *)0x3e8);
      Trigger::operator=((Trigger *)(aSStack_e + -0x46),pTVar3);
      ScStub::~ScStub(aSStack_e + -0x3e);
      scr_snprintf(&DAT_1101c168,0x50,s_Evacuate__d_units_of_food_110152c4,DAT_1101c100 * 1000,
                   pcVar4);
      CreateVictoryCondition((int)(aSStack_e + -0x3e),1,(Trigger *)0x0,(char *)(aSStack_e + -0x46));
      ScStub::~ScStub(aSStack_e + -0x42);
      pcVar4 = s_NoResponseToTrigger_1101487c;
      pTVar3 = (Trigger *)
               CreateEscapeTrigger((int)(aSStack_e + -0x42),1,0,0,DAT_11016240 + -6,
                                   DAT_11016244 + -6,0xc,0xc,DAT_1101c104,1,4,(char *)0x3e8);
      Trigger::operator=((Trigger *)(aSStack_a7 + 0x4b),pTVar3);
      ScStub::~ScStub(aSStack_e + -0x46);
      scr_snprintf(&DAT_1101c1b8,0x50,s_Evacuate__d_units_of_Commom_Meta_110152a0,
                   DAT_1101c104 * 1000,pcVar4);
      CreateVictoryCondition((int)(aSStack_e + -0x46),1,(Trigger *)0x0,(char *)(aSStack_a7 + 0x4b));
      ScStub::~ScStub(aSStack_e + -0x4a);
      FUN_110025af();
      FUN_11007770('\x01','\0',(-(uint)(DAT_1101c0ea != '\0') & 0x5dc) + 0x9c4,FUN_110040b2,0);
      FUN_11007770('\x01','\x01',0x9c4,FUN_1100289e,0);
      FUN_11007770('\x01','\x01',0x30d4,FUN_11004893,0);
      FUN_11007700('\x01','\0',2000,5000,FUN_11004841,0);
      FUN_11007770('\x01','\0',4000,FUN_11003bd0,0);
      FUN_11007770('\x01','\0',0xc80,FUN_11003dd3,0);
      ScStub::~ScStub(aSStack_a7 + 0x47);
      return 1;
    }
  }
  else {
    (*DAT_11015464)();
  }
  return 0;
}


// ---- 11005e31 FUN_11005e31  (called by: FUN_11005e63@11005e63)

void FUN_11005e31(void)

{
  int iVar1;
  SongIds local_8;
  
  iVar1 = FUN_11001050();
  local_8 = 3;
  UninstallMusicHook();
  TethysGame::SetMusicPlayList(0,0,&local_8);
  if (iVar1 != 0) {
    FUN_1100106e();
  }
  return;
}


// ---- 11005e63 FUN_11005e63  (called by: entry@11009a9e)

undefined4 FUN_11005e63(HMODULE param_1,int param_2)

{
  bool bVar1;
  undefined *puVar2;
  ushort uVar3;
  
  if (param_2 == 0) {
    bVar1 = FUN_11006bff();
    if (bVar1) {
      FUN_11006c74((uint *)&DAT_110153f8);
    }
    FUN_110010ef();
    FUN_11005e31();
  }
  else if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    FUN_11007c80(param_1);
    uVar3 = 0x10;
    puVar2 = FUN_11006c0c((uint *)s_q02_mo3_110153fc,PTR_DAT_11015404);
    FUN_1100837f(puVar2,uVar3);
    FUN_11008156(0x110083a5);
    FUN_1100107a();
  }
  return 1;
}


// ---- 11005edb FUN_11005edb  (called by: FUN_11005fa7@11005fa7)

undefined1 FUN_11005edb(void)

{
  PlayerBuildingEnum *pPVar1;
  PlayerVehicleEnum *pPVar2;
  int iVar3;
  PlayerBuildingEnum local_2c [8];
  PlayerBuildingEnum local_24 [8];
  PlayerVehicleEnum local_1c [4];
  PlayerVehicleEnum local_18 [4];
  IUnit local_14 [4];
  int local_10;
  int local_c;
  undefined1 local_5;
  
  local_5 = 0;
  local_10 = 0;
  local_c = TethysGame::NoPlayers();
  IUnit::IUnit(local_14);
  PlayerBuildingEnum::PlayerBuildingEnum(local_24,0,0);
  PlayerVehicleEnum::PlayerVehicleEnum(local_18,0);
  while (local_c = local_c + -1, -1 < local_c) {
    pPVar1 = (PlayerBuildingEnum *)PlayerBuildingEnum::PlayerBuildingEnum(local_2c,local_c,0);
    PlayerBuildingEnum::operator=(local_24,pPVar1);
    pPVar2 = (PlayerVehicleEnum *)PlayerVehicleEnum::PlayerVehicleEnum(local_1c,local_c);
    PlayerVehicleEnum::operator=(local_18,pPVar2);
    while (iVar3 = PlayerBuildingEnum::GetNext(local_24,(Unit *)local_14), iVar3 != 0) {
      local_10 = local_10 + 1;
    }
    if (local_10 != *(int *)(&DAT_11016268 + local_c * 4)) {
      local_5 = 1;
    }
    while (iVar3 = PlayerVehicleEnum::GetNext(local_18,(Unit *)local_14), iVar3 != 0) {
      local_10 = local_10 + 1;
    }
    if (local_10 != *(int *)(&DAT_11016288 + local_c * 4)) {
      local_5 = 1;
    }
  }
  return local_5;
}


// ---- 11005fa7 FUN_11005fa7  (called by: FUN_11006c74@11006c74)

uint __cdecl FUN_11005fa7(LPCSTR param_1,char param_2)

{
  char cVar1;
  uint uVar2;
  
  if (param_2 == '\0') {
    param_2 = FUN_11005edb();
  }
  uVar2 = FUN_1100631d(param_1,param_2);
  cVar1 = (char)uVar2;
  if (cVar1 != '\0') {
    FUN_11006491(param_1);
    uVar2 = FUN_11005fe6(param_1,'\x01');
  }
  return CONCAT31((int3)(uVar2 >> 8),cVar1);
}


// ---- 11005fe6 FUN_11005fe6  (called by: FUN_11005fa7@11005fa7)

uint __cdecl FUN_11005fe6(LPCSTR param_1,char param_2)

{
  int iVar1;
  PlayerBuildingEnum *pPVar2;
  PlayerVehicleEnum *pPVar3;
  int iVar4;
  FILE *pFVar5;
  undefined4 *puVar6;
  map_id mVar7;
  PlayerBuildingEnum local_7c [8];
  PlayerVehicleEnum local_74 [4];
  undefined4 local_70;
  undefined4 local_6c;
  map_id local_68;
  map_id local_64;
  map_id local_60;
  undefined4 local_5c;
  undefined4 local_58;
  map_id local_54;
  map_id local_50;
  undefined4 local_4c;
  undefined4 local_48;
  map_id local_44;
  map_id local_40;
  map_id local_3c;
  map_id local_38;
  map_id local_34;
  undefined4 local_30;
  undefined4 local_2c;
  map_id local_28;
  PlayerBuildingEnum local_24 [8];
  map_id local_1c;
  int local_18;
  PlayerVehicleEnum local_14 [4];
  map_id local_10;
  uint local_c;
  IUnit local_8 [4];
  
  local_c = 0;
  local_10 = 0;
  local_18 = 0;
  iVar1 = TethysGame::NoPlayers();
  IUnit::IUnit(local_8);
  PlayerBuildingEnum::PlayerBuildingEnum(local_24,0,0);
  PlayerVehicleEnum::PlayerVehicleEnum(local_14,0);
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    pPVar2 = (PlayerBuildingEnum *)
             PlayerBuildingEnum::PlayerBuildingEnum((PlayerBuildingEnum *)&local_4c,iVar1,0);
    PlayerBuildingEnum::operator=(local_24,pPVar2);
    pPVar3 = (PlayerVehicleEnum *)
             PlayerVehicleEnum::PlayerVehicleEnum((PlayerVehicleEnum *)&local_1c,iVar1);
    PlayerVehicleEnum::operator=(local_14,pPVar3);
    while (iVar4 = PlayerBuildingEnum::GetNext(local_24,(Unit *)local_8), iVar4 != 0) {
      local_c = local_c + 1;
    }
    if (local_c != *(int *)(&DAT_11016268 + iVar1 * 4)) {
      param_2 = '\x01';
    }
    while (iVar4 = PlayerVehicleEnum::GetNext(local_14,(Unit *)local_8), iVar4 != 0) {
      local_10 = local_10 + 1;
    }
    if (local_10 != *(map_id *)(&DAT_11016288 + iVar1 * 4)) {
      param_2 = '\x01';
    }
    local_18 = local_18 + local_10 + local_c;
  }
  local_c = TethysGame::NoPlayers();
  if (param_2 == '\0') {
    local_c = local_c & 0xffffff00;
  }
  else {
    pFVar5 = (FILE *)FUN_11008b89(param_1,&DAT_11015408);
    FUN_11008a1f((char *)&local_18,4,1,(int *)pFVar5);
    if (pFVar5 != (FILE *)0x0) {
      while (local_c = local_c - 1, -1 < (int)local_c) {
        pPVar2 = (PlayerBuildingEnum *)PlayerBuildingEnum::PlayerBuildingEnum(local_7c,local_c,0);
        PlayerBuildingEnum::operator=(local_24,pPVar2);
        pPVar3 = (PlayerVehicleEnum *)PlayerVehicleEnum::PlayerVehicleEnum(local_74,local_c);
        PlayerVehicleEnum::operator=(local_14,pPVar3);
        while (iVar1 = PlayerBuildingEnum::GetNext(local_24,(Unit *)local_8), iVar1 != 0) {
          local_10 = Unit::GetCargo((Unit *)local_8);
          local_1c = Unit::OwnerID((Unit *)local_8);
          puVar6 = (undefined4 *)Unit::Location((Unit *)local_8);
          local_70 = *puVar6;
          local_6c = puVar6[1];
          mVar7 = Unit::GetWeapon((Unit *)local_8);
          local_68 = Unit::GetType((Unit *)local_8);
          local_60 = local_10;
          local_5c = 0;
          local_58 = 0;
          local_64 = mVar7;
          LOCATION::operator=((LOCATION *)&local_5c,(LOCATION *)&local_70);
          local_54 = local_1c;
          if ((local_68 == 0x2f) || (local_68 == 0x37)) {
            FUN_11008a1f((char *)&local_68,0x18,1,(int *)pFVar5);
            param_1 = (LPCSTR)0x0;
            do {
              IUnit::GetFactoryCargo(local_8,(int)param_1,&local_50,&local_44);
              FUN_11008a1f((char *)&local_50,4,1,(int *)pFVar5);
              FUN_11008a1f((char *)&local_44,4,1,(int *)pFVar5);
              param_1 = param_1 + 1;
            } while ((int)param_1 < 6);
          }
          else {
            FUN_11008a1f((char *)&local_68,0x18,1,(int *)pFVar5);
          }
        }
        while (iVar1 = PlayerVehicleEnum::GetNext(local_14,(Unit *)local_8), iVar1 != 0) {
          local_1c = Unit::GetCargo((Unit *)local_8);
          local_10 = Unit::OwnerID((Unit *)local_8);
          puVar6 = (undefined4 *)Unit::Location((Unit *)local_8);
          local_4c = *puVar6;
          local_48 = puVar6[1];
          mVar7 = Unit::GetWeapon((Unit *)local_8);
          local_3c = Unit::GetType((Unit *)local_8);
          local_34 = local_1c;
          local_30 = 0;
          local_2c = 0;
          local_38 = mVar7;
          LOCATION::operator=((LOCATION *)&local_30,(LOCATION *)&local_4c);
          local_28 = local_10;
          if (local_3c == 1) {
            local_38 = IUnit::GetTruckCargo(local_8,&local_40);
            local_34 = local_40;
          }
          else if ((local_3c == 2) && (IUnit::GetCargo(local_8,&local_34,&local_38), local_34 == 0))
          {
            local_38 = 0;
          }
          FUN_11008a1f((char *)&local_3c,0x18,1,(int *)pFVar5);
        }
      }
    }
    FUN_11008600(pFVar5);
    *(int *)(&DAT_11016268 + local_c * 4) = local_18;
    local_c = (uint)(pFVar5 != (FILE *)0x0);
  }
  return local_c;
}


// ---- 1100631d FUN_1100631d  (called by: FUN_11005fa7@11005fa7)

uint __cdecl FUN_1100631d(LPCSTR param_1,char param_2)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  FILE *pFVar4;
  uint uVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 uVar6;
  MAP_RECT local_38 [16];
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  byte local_5;
  
  local_14 = 0;
  piVar2 = (int *)MAP_RECT::MAP_RECT(local_38,0,0,0x200,0x100);
  local_28 = *piVar2;
  local_24 = piVar2[1];
  local_20 = piVar2[2];
  local_1c = piVar2[3];
  MAP_RECT::ClipToMap((MAP_RECT *)&local_28);
  local_c = local_24;
  uVar6 = extraout_EDX;
  if ((short)local_24 <= local_1c) {
    do {
      local_10 = local_28;
      sVar1 = (short)local_28;
      while (sVar1 <= local_20) {
        iVar3 = GameMap::GetCellType((int)(short)local_c,uVar6,(int)sVar1,(int)(short)local_c);
        local_5 = (byte)iVar3;
        if (0xf < local_5) {
          local_14 = local_14 + 1;
        }
        local_10 = local_10 + 1;
        uVar6 = extraout_EDX_00;
        sVar1 = (short)local_10;
      }
      local_c = local_c + 1;
    } while ((short)local_c <= local_1c);
  }
  if ((param_2 != '\0') || (uVar5 = local_14, local_14 != DAT_110162a8)) {
    pFVar4 = (FILE *)FUN_11008b89(param_1,&DAT_11014878);
    uVar5 = 0;
    if (pFVar4 != (FILE *)0x0) {
      FUN_11008a1f((char *)&local_14,4,1,(int *)pFVar4);
      local_c = local_24;
      sVar1 = (short)local_24;
      uVar6 = extraout_EDX_01;
      while (sVar1 <= local_1c) {
        local_10 = local_28;
        sVar1 = (short)local_28;
        while (sVar1 <= local_20) {
          iVar3 = GameMap::GetCellType((int)(short)local_c,uVar6,(int)sVar1,(int)(short)local_c);
          local_5 = (byte)iVar3;
          uVar6 = extraout_EDX_02;
          if (0xf < local_5) {
            FUN_11008a1f((char *)&local_10,2,1,(int *)pFVar4);
            FUN_11008a1f((char *)&local_c,2,1,(int *)pFVar4);
            FUN_11008a1f((char *)&local_5,1,1,(int *)pFVar4);
            if ((local_5 == 0x15) || (uVar6 = extraout_EDX_03, local_5 == 0x16)) {
              local_18 = GameMap::GetTile((int)(short)local_c,extraout_EDX_03,(int)(short)local_10,
                                          (int)(short)local_c);
              FUN_11008a1f((char *)&local_18,2,1,(int *)pFVar4);
              uVar6 = extraout_EDX_04;
            }
          }
          local_10 = local_10 + 1;
          sVar1 = (short)local_10;
        }
        local_c = local_c + 1;
        sVar1 = (short)local_c;
      }
      FUN_11008600(pFVar4);
      DAT_110162a8 = local_14;
      return CONCAT31((int3)(local_14 >> 8),1);
    }
  }
  return uVar5 & 0xffffff00;
}


// ---- 11006491 FUN_11006491  (called by: FUN_11005fa7@11005fa7)

undefined4 __cdecl FUN_11006491(LPCSTR param_1)

{
  FILE *pFVar1;
  undefined4 uVar2;
  int local_24 [8];
  
  FUN_11006ae9(local_24,SUB41(*(undefined4 *)Player_exref,0));
  pFVar1 = (FILE *)FUN_11008b89(param_1,&DAT_11015408);
  FUN_11008a1f((char *)local_24,0x20,1,(int *)pFVar1);
  uVar2 = FUN_11008600(pFVar1);
  return CONCAT31((int3)((uint)uVar2 >> 8),1);
}


// ---- 110064db FUN_110064db  (called by: FUN_110064f3@110064f3, FUN_1100690b@1100690b)

undefined4 __cdecl FUN_110064db(int *param_1)

{
  uint uVar1;
  
  uVar1 = FUN_1100909f((char *)&DAT_11016248,0x20,1,param_1);
  return CONCAT31((int3)(uVar1 >> 8),1);
}


// ---- 110064f3 FUN_110064f3  (called by: InitMap@11004a36)

undefined4 __cdecl FUN_110064f3(int param_1,LPCSTR param_2,char param_3)

{
  bool bVar1;
  FILE *pFVar2;
  undefined4 uVar3;
  undefined4 extraout_ECX;
  int iVar4;
  int local_30;
  map_id local_2c;
  map_id local_28;
  int local_24;
  int local_20;
  int local_1c;
  map_id local_18;
  map_id local_14;
  FILE *local_10;
  int local_c;
  IUnit local_8 [4];
  
  IUnit::IUnit(local_8);
  local_24 = 0;
  local_20 = 0;
  pFVar2 = (FILE *)FUN_11006887((uint3)extraout_ECX,param_2);
  if (pFVar2 == (FILE *)0x0) {
    uVar3 = 0;
  }
  else {
    local_10 = pFVar2;
    FUN_110064db((int *)pFVar2);
    FUN_1100909f((char *)&local_c,4,1,(int *)pFVar2);
    pFVar2 = local_10;
    if (0 < local_c) {
      while ((local_c = local_c + -1, local_10 = pFVar2, 0 < local_c &&
             (FUN_1100909f((char *)&local_30,0x18,1,(int *)pFVar2), (pFVar2->_flag & 0x10) == 0))) {
        if ((local_1c == param_1) &&
           ((param_3 != '\0' || (uVar3 = FUN_11006ad6(&local_30), (char)uVar3 == '\0')))) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (local_30 == 1) {
          if (bVar1) {
            TethysGame::CreateUnit(local_8,1,local_24,local_20,local_1c,0,0);
            Unit::SetTruckCargo((Unit *)local_8,local_28,local_2c);
          }
        }
        else if (local_30 == 2) {
          if (bVar1) {
            TethysGame::CreateUnit(local_8,2,local_24,local_20,local_1c,0,0);
            Unit::SetCargo((Unit *)local_8,local_28,local_2c);
          }
        }
        else if (local_30 == 0x2f) {
          if (bVar1) {
            TethysGame::CreateUnit(local_8,0x2f,local_24,local_20,local_1c,0,0);
          }
          iVar4 = 0;
          do {
            FUN_1100909f((char *)&local_14,4,1,(int *)local_10);
            FUN_1100909f((char *)&local_18,4,1,(int *)local_10);
            if (bVar1) {
              Unit::SetFactoryCargo((Unit *)local_8,iVar4,local_14,local_18);
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < 6);
        }
        else if (local_30 == 0x37) {
          if (bVar1) {
            TethysGame::CreateUnit(local_8,0x37,local_24,local_20,local_1c,0,0);
          }
          iVar4 = 0;
          do {
            FUN_1100909f((char *)&local_14,4,1,(int *)local_10);
            FUN_1100909f((char *)&local_18,4,1,(int *)local_10);
            if (bVar1) {
              Unit::SetFactoryCargo((Unit *)local_8,iVar4,local_18,0);
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < 6);
          if ((bVar1) && (local_14 != 0)) {
            Unit::SetFactoryCargo((Unit *)local_8,iVar4,local_14,0);
          }
        }
        else if (bVar1) {
          TethysGame::CreateUnit(local_8,local_30,local_24,local_20,local_1c,local_2c,0);
        }
        pFVar2 = local_10;
        if ((local_1c == 0) && (local_30 == 0x1c)) {
          _Player::CenterViewOn((_Player *)Player_exref,local_24,local_20);
          pFVar2 = local_10;
        }
      }
    }
    uVar3 = FUN_11008600(local_10);
    uVar3 = CONCAT31((int3)((uint)uVar3 >> 8),1);
  }
  return uVar3;
}


// ---- 11006737 FUN_11006737  (called by: InitMap@11004a36)

undefined1 FUN_11006737(void)

{
  int *piVar1;
  byte bVar2;
  undefined1 uVar3;
  FILE *pFVar4;
  int iVar5;
  int unaff_EBP;
  int iVar6;
  map_id mVar7;
  undefined1 auStack_16 [22];
  
  FUN_11008fa8();
  *(undefined1 *)(unaff_EBP + -0x11) = 0;
  *(undefined1 **)(unaff_EBP + -0x10) = auStack_16 + -0xe;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  pFVar4 = (FILE *)FUN_11008b89(*(LPCSTR *)(unaff_EBP + 8),&DAT_11015444);
  *(FILE **)(unaff_EBP + -0x24) = pFVar4;
  if (pFVar4 == (FILE *)0x0) {
    uVar3 = 0;
  }
  else {
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_1100909f((char *)(unaff_EBP + -0x20),4,1,(int *)pFVar4);
LAB_1100678b:
    piVar1 = (int *)(unaff_EBP + -0x20);
    *piVar1 = *piVar1 + -1;
    if (-1 < *piVar1) {
      FUN_1100909f((char *)(unaff_EBP + -0x1c),2,1,(int *)pFVar4);
      FUN_1100909f((char *)(unaff_EBP + -0x18),2,1,(int *)pFVar4);
      FUN_1100909f((char *)(unaff_EBP + -0x11),1,1,(int *)pFVar4);
      bVar2 = *(byte *)(unaff_EBP + -0x11);
      if (0x14 < bVar2) {
        if (0x16 < bVar2) {
          if (bVar2 == 0x17) {
            mVar7 = 0x12;
          }
          else {
            if (bVar2 != 0x1a) goto LAB_1100678b;
            mVar7 = 0x11;
          }
          TethysGame::CreateWallOrTube
                    ((int)*(short *)(unaff_EBP + -0x1c),(int)*(short *)(unaff_EBP + -0x18),0,mVar7);
          goto LAB_1100678b;
        }
        iVar6 = (int)*(short *)(unaff_EBP + -0x18);
        iVar5 = (int)*(short *)(unaff_EBP + -0x1c);
        GameMap::SetCellType(bVar2);
        FUN_1100909f((char *)(unaff_EBP + 10),2,1,(int *)pFVar4);
        GameMap::SetTile((int)*(short *)(unaff_EBP + 10),(int)*(short *)(unaff_EBP + -0x18),
                         (int)*(short *)(unaff_EBP + -0x1c),(int)*(short *)(unaff_EBP + -0x18),iVar5
                         ,iVar6);
      }
      goto LAB_1100678b;
    }
    FUN_11008600(pFVar4);
    uVar3 = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}


// ---- 11006829 Catch@11006829  (called by: -)

undefined4 Catch_11006829(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = FUN_11008736(*(char **)(unaff_EBP + -0x24));
  FUN_110091b6(&DAT_11019ab0,(byte *)s_Error_reading_file_at__04X____04_11015414,iVar1);
  (*DAT_11015464)(s_DEBUG_1101540c,0);
  return 0x1100686c;
}


// ---- 11006887 FUN_11006887  (called by: FUN_110064f3@110064f3, FUN_1100690b@1100690b)

int * __thiscall FUN_11006887(uint3 param_1,LPCSTR param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int local_c;
  undefined4 uStack_8;
  
  local_c = 0;
  uStack_8 = (uint)param_1;
  piVar1 = (int *)FUN_11008b89(param_2,&DAT_11015444);
  if (piVar1 == (int *)0x0) {
    return (int *)0x0;
  }
  piVar2 = &local_c;
  uVar3 = 4;
  do {
    FUN_1100909f((char *)piVar2,uVar3,1,piVar1);
    do {
      local_c = local_c + -1;
      if (local_c < 0) {
        return piVar1;
      }
      FUN_1100909f((char *)((int)&param_2 + 2),2,1,piVar1);
      FUN_1100909f((char *)((int)&param_2 + 2),2,1,piVar1);
      FUN_1100909f((char *)((int)&uStack_8 + 3),1,1,piVar1);
    } while ((uStack_8._3_1_ < 0x15) || (0x16 < uStack_8._3_1_));
    uVar3 = 2;
    piVar2 = (int *)((int)&param_2 + 2);
  } while( true );
}


// ---- 1100690b FUN_1100690b  (called by: InitMap@11004a36)

undefined4 __cdecl FUN_1100690b(LPCSTR param_1,void *param_2)

{
  FILE *pFVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 extraout_ECX;
  int iVar4;
  char local_10 [4];
  IUnit local_c [4];
  int local_8;
  
  IUnit::IUnit(local_c);
  pFVar1 = (FILE *)FUN_11006887((uint3)extraout_ECX,param_1);
  if (pFVar1 == (FILE *)0x0) {
    uVar3 = 0;
  }
  else {
    FUN_110064db((int *)pFVar1);
    FUN_1100909f((char *)&local_8,4,1,(int *)pFVar1);
    if (0 < local_8) {
      while (local_8 = local_8 + -1, 0 < local_8) {
        piVar2 = operator_new(0x18);
        if (piVar2 == (int *)0x0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2[3] = 0;
          piVar2[4] = 0;
        }
        FUN_1100909f((char *)piVar2,0x18,1,(int *)pFVar1);
        if ((pFVar1->_flag & 0x10) != 0) {
          FUN_11009086(piVar2);
          break;
        }
        if ((*piVar2 == 0x2f) || (*piVar2 == 0x37)) {
          iVar4 = 0xc;
          do {
            FUN_1100909f(local_10,4,1,(int *)pFVar1);
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        uVar3 = FUN_11006ad6(piVar2);
        if ((char)uVar3 == '\0') {
          FUN_11009086(piVar2);
        }
        else {
          FUN_11006bb8(param_2,(int)piVar2);
        }
      }
    }
    uVar3 = FUN_11008600(pFVar1);
    uVar3 = CONCAT31((int3)((uint)uVar3 >> 8),1);
  }
  return uVar3;
}


// ---- 110069dd FUN_110069dd  (called by: InitMap@11004a36)

void __cdecl FUN_110069dd(int param_1,int *param_2,char param_3,char param_4)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_2;
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    piVar2 = (int *)FUN_11006bc4(param_2,iVar1);
    if (piVar2[5] == param_1) {
      FUN_11006a19(piVar2,param_1,piVar2[3],piVar2[4],param_3,param_4);
    }
  }
  return;
}


// ---- 11006a19 FUN_11006a19  (called by: FUN_110069dd@110069dd)

void __cdecl
FUN_11006a19(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,char param_5,
            char param_6)

{
  map_id mVar1;
  int iVar2;
  map_id mVar3;
  Truck_Cargo TVar4;
  IUnit local_8 [4];
  
  IUnit::IUnit(local_8);
  iVar2 = *param_1;
  if (iVar2 == 1) {
    TethysGame::CreateUnit(local_8,1,param_3,param_4,param_2,0,0);
    if (param_5 == '\0') {
      iVar2 = 0;
      TVar4 = 0;
    }
    else {
      iVar2 = param_1[1];
      TVar4 = param_1[2];
    }
    Unit::SetTruckCargo((Unit *)local_8,TVar4,iVar2);
  }
  else if (iVar2 == 2) {
    TethysGame::CreateUnit(local_8,2,param_3,param_4,param_2,0,0);
    if (param_6 == '\0') {
      mVar1 = 0;
      mVar3 = 0;
    }
    else {
      mVar1 = param_1[1];
      mVar3 = param_1[2];
    }
    Unit::SetCargo((Unit *)local_8,mVar3,mVar1);
  }
  else {
    TethysGame::CreateUnit(local_8,iVar2,param_3,param_4,param_2,param_1[1],0);
  }
  Unit::DoSetLights((Unit *)local_8,1);
  return;
}


// ---- 11006ad6 FUN_11006ad6  (called by: FUN_110064f3@110064f3, FUN_1100690b@1100690b)

undefined4 __fastcall FUN_11006ad6(int *param_1)

{
  if ((*param_1 < 0x11) || (0x6e < *param_1)) {
    return 1;
  }
  return 0;
}


// ---- 11006ae9 FUN_11006ae9  (called by: FUN_11006491@11006491)

int * __thiscall FUN_11006ae9(int *param_1,_Player param_2)

{
  int iVar1;
  
  iVar1 = _Player::Difficulty(&param_2);
  *param_1 = iVar1;
  iVar1 = _Player::FoodStored(&param_2);
  param_1[1] = iVar1;
  iVar1 = _Player::GetRLVCount(&param_2);
  param_1[2] = iVar1;
  iVar1 = _Player::Kids(&param_2);
  param_1[3] = iVar1;
  iVar1 = _Player::Ore(&param_2);
  param_1[4] = iVar1;
  iVar1 = _Player::RareOre(&param_2);
  param_1[5] = iVar1;
  iVar1 = _Player::Scientists(&param_2);
  param_1[6] = iVar1;
  iVar1 = _Player::Workers(&param_2);
  param_1[7] = iVar1;
  return param_1;
}


// ---- 11006b55 FUN_11006b55  (called by: InitMap@11004a36)

void __fastcall FUN_11006b55(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return;
}


// ---- 11006b64 FUN_11006b64  (called by: FUN_11006bb8@11006bb8)

uint __thiscall FUN_11006b64(void *this,int param_1)

{
  int iVar1;
  uint in_EAX;
  int *piVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    uVar3 = in_EAX & 0xffffff00;
  }
  else {
    *(int *)this = *(int *)this + 1;
    if (*(int *)this == 1) {
      piVar2 = _malloc(4);
    }
    else {
      piVar2 = FUN_11009208(*(int **)((int)this + 4),(uint *)(*(int *)this << 2));
    }
    *(int **)((int)this + 4) = piVar2;
    iVar1 = *(int *)this;
    *(int *)(*(int *)((int)this + 4) + -4 + iVar1 * 4) = param_1;
    uVar3 = CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  return uVar3;
}


// ---- 11006ba7 FUN_11006ba7  (called by: FUN_11006bd1@11006bd1)

void __fastcall FUN_11006ba7(undefined4 *param_1)

{
  FUN_110085b8((LPVOID)param_1[1]);
  *param_1 = 0;
  return;
}


// ---- 11006bb8 FUN_11006bb8  (called by: FUN_1100690b@1100690b)

void __thiscall FUN_11006bb8(void *this,int param_1)

{
  FUN_11006b64(this,param_1);
  return;
}


// ---- 11006bc4 FUN_11006bc4  (called by: FUN_1100491a@1100491a, FUN_110069dd@110069dd, InitMap@11004a36)

undefined4 __thiscall FUN_11006bc4(void *this,int param_1)

{
  return *(undefined4 *)(*(int *)((int)this + 4) + param_1 * 4);
}


// ---- 11006bd1 FUN_11006bd1  (called by: InitMap@11004a36)

void __fastcall FUN_11006bd1(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    FUN_11009086(*(LPVOID *)(param_1[1] + iVar1 * 4));
  }
  FUN_11006ba7(param_1);
  return;
}


// ---- 11006bf2 FUN_11006bf2  (called by: InitProc@11005597)

bool FUN_11006bf2(void)

{
  return DAT_004e971c == 'Q';
}


// ---- 11006bff FUN_11006bff  (called by: FUN_11005e63@11005e63)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_11006bff(void)

{
  return _DAT_0056eb34 == 3;
}


// ---- 11006c0c FUN_11006c0c  (called by: FUN_11005e63@11005e63, FUN_11006c74@11006c74)

undefined * __cdecl FUN_11006c0c(uint *param_1,byte *param_2)

{
  byte *pbVar1;
  byte local_208 [256];
  byte local_108 [256];
  byte local_8 [4];
  
  pbVar1 = (byte *)GetCurrentModDir();
  if (pbVar1 == (byte *)0x0) {
    FUN_11009340((uint *)&DAT_11019ab0,param_1);
  }
  else {
    FUN_110094c1(pbVar1,local_8,local_208,local_108,local_108);
    FUN_11009430(&DAT_11019ab0,local_8,local_208,(byte *)param_1,param_2);
  }
  return &DAT_11019ab0;
}


// ---- 11006c74 FUN_11006c74  (called by: FUN_11005e63@11005e63)

void __cdecl FUN_11006c74(uint *param_1)

{
  size_t sVar1;
  undefined *puVar2;
  uint *puVar3;
  uint local_54 [20];
  
  GetGameDir(local_54);
  sVar1 = _strlen((char *)local_54);
  FUN_11009350(local_54,param_1);
  FUN_11009350(local_54,(uint *)&DAT_1101545c);
  FUN_11005fa7((LPCSTR)local_54,'\0');
  FUN_11009340((uint *)((int)local_54 + sVar1),(uint *)s_music2_wav_11015450);
  puVar3 = local_54;
  puVar2 = FUN_11006c0c(param_1,&DAT_11015448);
  FUN_11001106(puVar2,(LPCSTR)puVar3);
  return;
}


// ---- 11006ce5 FUN_11006ce5  (called by: InitProc@11005597)

void __cdecl FUN_11006ce5(undefined1 param_1)

{
  DAT_11019aac = param_1;
  FUN_11007770('\x01','\0',500,FUN_11006fbb,0);
  return;
}


// ---- 11006d07 FUN_11006d07  (called by: FUN_11006d88@11006d88)

bool __cdecl FUN_11006d07(Unit param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  LocationEnumerator *this;
  int iVar4;
  map_id mVar5;
  Unit *pUVar6;
  LocationEnumerator local_44 [52];
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  piVar2 = (int *)Unit::Location(&param_1);
  iVar4 = *piVar2;
  iVar1 = piVar2[1];
  iVar3 = Unit::OwnerID(&param_1);
  iVar3 = _Player::IsEden((_Player *)(Player_exref + iVar3 * 0xc));
  local_10 = iVar4 - ((-(uint)(iVar3 != 0) & 3) - 2);
  pUVar6 = (Unit *)&local_8;
  local_c = iVar1 + -1;
  this = (LocationEnumerator *)
         LocationEnumerator::LocationEnumerator(local_44,(LOCATION *)&local_10);
  iVar4 = LocationEnumerator::GetNext(this,pUVar6);
  if (iVar4 == 0) {
    return false;
  }
  mVar5 = Unit::GetType((Unit *)&local_8);
  return (bool)('\x01' - (mVar5 != 0x2f));
}


// ---- 11006d88 FUN_11006d88  (called by: FUN_11006e37@11006e37)

undefined4 __cdecl FUN_11006d88(LOCATION param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  map_id mVar2;
  bool bVar3;
  ClosestEnumerator local_48 [52];
  map_id local_14;
  map_id local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  ClosestEnumerator::ClosestEnumerator(local_48,&param_1);
LAB_11006db5:
  do {
    do {
      iVar1 = ClosestEnumerator::GetNext(local_48,(Unit *)&local_8,&local_c);
      if ((iVar1 == 0) || ((local_c._2_2_ & 0xfff8) != 0)) {
        return 0;
      }
      iVar1 = Unit::OwnerID((Unit *)&local_8);
    } while (((iVar1 != param_3) || (iVar1 = Unit::IsLive((Unit *)&local_8), iVar1 == 0)) ||
            (iVar1 = Unit::IsBusy((Unit *)&local_8), iVar1 != 0));
    mVar2 = Unit::GetType((Unit *)&local_8);
    if (mVar2 == 2) {
      bVar3 = FUN_11006d07(SUB41(local_8,0));
      if (bVar3) goto LAB_11006db5;
      IUnit::GetCargo((IUnit *)&local_8,&local_10,&local_14);
      bVar3 = local_10 == 0;
    }
    else {
      bVar3 = mVar2 == 0xe;
    }
    if (bVar3) {
      return local_8;
    }
  } while( true );
}


// ---- 11006e37 FUN_11006e37  (called by: FUN_11006fbb@11006fbb)

void __cdecl FUN_11006e37(int param_1)

{
  int iVar1;
  command_type cVar2;
  map_id mVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined1 local_20 [8];
  PlayerBuildingEnum local_18 [8];
  map_id local_10;
  IUnit local_c [4];
  int local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  IUnit::IUnit(local_c);
  local_10 = 0x15;
  do {
    if ((DAT_11019aac != '\0') || (local_10 != 0x17)) {
      PlayerBuildingEnum::PlayerBuildingEnum(local_18,param_1,local_10);
LAB_11006e80:
      iVar1 = PlayerBuildingEnum::GetNext(local_18,(Unit *)&local_8);
      if (iVar1 != 0) {
        iVar1 = IUnit::GetDamage((IUnit *)&local_8);
        if (iVar1 < 0x65) {
          *(undefined4 *)(&DAT_110162ac + (local_8 * 7 + param_1) * 4) = 0;
        }
        else {
          Unit::GetType((Unit *)&local_8);
          Unit::OwnerID((Unit *)&local_8);
          iVar1 = Unit::IsVehicle((Unit *)&local_8);
          if (iVar1 == 0) {
            iVar1 = Unit::IsLive((Unit *)&local_8);
            if (iVar1 != 0) {
              cVar2 = IUnit::GetBusy((IUnit *)&local_8);
              if ((cVar2 != 0x1e) && (((int)cVar2 < 0x21 || (0x22 < (int)cVar2)))) {
                if (0 < *(int *)(&DAT_110162ac + (local_8 * 7 + param_1) * 4)) {
                  Unit::SetId((Unit *)local_c,*(int *)(&DAT_110162ac + (local_8 * 7 + param_1) * 4))
                  ;
                  cVar2 = IUnit::GetBusy(local_c);
                  if (cVar2 == 0x1c) {
                    iVar1 = Unit::IsLive((Unit *)local_c);
                    if (iVar1 != 0) {
                      mVar3 = Unit::GetType((Unit *)local_c);
                      if (mVar3 == 2) goto LAB_11006e80;
                    }
                  }
                  *(undefined4 *)(&DAT_110162ac + (local_8 * 7 + param_1) * 4) = 0;
                }
                puVar5 = local_20;
                puVar4 = (undefined4 *)Unit::Location((Unit *)&local_8);
                iVar1 = FUN_11006d88(SUB41(*puVar4,0),puVar4[1],(int)puVar5);
                if (0 < iVar1) {
                  Unit::SetId((Unit *)local_c,iVar1);
                  Unit::GetType((Unit *)local_c);
                  Unit::OwnerID((Unit *)local_c);
                  IUnit::Repair(local_c,local_8);
                  *(int *)(&DAT_110162ac + (local_8 * 7 + param_1) * 4) = iVar1;
                }
              }
            }
          }
        }
        goto LAB_11006e80;
      }
    }
    local_10 = local_10 + 1;
    if (0x3a < (int)local_10) {
      return;
    }
  } while( true );
}


// ---- 11006fbb FUN_11006fbb  (called by: -)

void FUN_11006fbb(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = TethysGame::NoPlayers();
  if (0 < iVar1) {
    iVar1 = 0;
    do {
      iVar2 = _Player::IsHuman((_Player *)(Player_exref + iVar1));
      if (iVar2 == 0) {
        FUN_11006e37(iVar3);
      }
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + 0xc;
      iVar2 = TethysGame::NoPlayers();
    } while (iVar3 < iVar2);
  }
  return;
}


// ---- 11006ff5 FUN_11006ff5  (called by: FUN_110070b6@110070b6)

undefined4 * __thiscall
FUN_11006ff5(undefined4 *param_1,char param_2,char param_3,undefined1 param_4,LOCATION param_5,
            undefined4 param_6,undefined4 param_7)

{
  FUN_11007cd0(param_1,param_2,param_3,param_7);
  param_1[5] = 0;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 4) = param_4;
  *param_1 = &PTR_FUN_110103c8;
  LOCATION::operator=((LOCATION *)(param_1 + 5),&param_5);
  param_1[2] = 0;
  return param_1;
}


// ---- 11007035 FUN_11007035  (called by: -)

void __fastcall FUN_11007035(int param_1)

{
  int iVar1;
  command_type cVar2;
  LocationEnumerator local_3c [52];
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  LocationEnumerator::LocationEnumerator(local_3c,(LOCATION *)(param_1 + 0x14));
  do {
    iVar1 = LocationEnumerator::GetNext(local_3c,(Unit *)&local_8);
    if (iVar1 == 0) {
      return;
    }
    iVar1 = Unit::OwnerID((Unit *)&local_8);
  } while ((iVar1 != *(char *)(param_1 + 0x10)) ||
          (iVar1 = Unit::IsBuilding((Unit *)&local_8), iVar1 == 0));
  cVar2 = IUnit::GetBusy((IUnit *)&local_8);
  if ((cVar2 != 0x1e) && (((int)cVar2 < 0x21 || (0x22 < (int)cVar2)))) {
    *(undefined4 *)(param_1 + 8) = local_8;
    FUN_11007d50(param_1);
  }
  return;
}


// ---- 110070b6 FUN_110070b6  (called by: FUN_11007104@11007104)

undefined4 * __cdecl
FUN_110070b6(char param_1,char param_2,undefined1 param_3,LOCATION param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 *puVar1;
  undefined4 local_20 [7];
  
  puVar1 = (undefined4 *)FUN_11007fd0(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_11006ff5(local_20,param_1,param_2,param_3,param_4,param_5,param_6);
    FUN_11009690(puVar1,local_20,0x1c);
    FUN_11007da0(&DAT_1101c300,(int)puVar1);
  }
  return puVar1;
}


// ---- 11007104 FUN_11007104  (called by: FUN_11002a76@11002a76, FUN_11002c1c@11002c1c)

void __cdecl
FUN_11007104(char param_1,char param_2,undefined1 param_3,LOCATION param_4,undefined4 param_5,
            undefined4 param_6)

{
  FUN_110070b6(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ---- 11007160 FUN_11007160  (called by: FUN_1100491a@1100491a, FUN_11007300@11007300)

int __cdecl FUN_11007160(int param_1,map_id param_2,map_id param_3)

{
  int iVar1;
  map_id mVar2;
  int iVar3;
  undefined4 local_c;
  PlayerBuildingEnum local_8 [8];
  
  iVar3 = 0;
  local_c = 0;
  PlayerBuildingEnum::PlayerBuildingEnum(local_8,param_1,param_2);
  iVar1 = PlayerBuildingEnum::GetNext(local_8,(Unit *)&local_c);
  if (iVar1 == 0) {
    return 0;
  }
  do {
    mVar2 = Unit::GetType((Unit *)&local_c);
    if ((mVar2 == param_2) &&
       ((param_3 == 0xffffffff || (mVar2 = Unit::GetWeapon((Unit *)&local_c), mVar2 == param_3)))) {
      iVar3 = iVar3 + 1;
    }
    iVar1 = PlayerBuildingEnum::GetNext(local_8,(Unit *)&local_c);
  } while (iVar1 != 0);
  return iVar3;
}


// ---- 110071f0 FUN_110071f0  (called by: FUN_11007210@11007210)

undefined4 __cdecl FUN_110071f0(IUnit param_1)

{
  command_type cVar1;
  uint3 uVar2;
  
  cVar1 = IUnit::GetBusy(&param_1);
  uVar2 = (uint3)(cVar1 >> 8);
  if ((cVar1 == 0x12) || ((0x20 < (int)cVar1 && ((int)cVar1 < 0x23)))) {
    return (uint)uVar2 << 8;
  }
  return CONCAT31(uVar2,1);
}


// ---- 11007210 FUN_11007210  (called by: FUN_110073d0@110073d0)

int __cdecl FUN_11007210(int param_1,map_id param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_c;
  PlayerBuildingEnum local_8 [8];
  
  iVar3 = 0;
  IUnit::IUnit((IUnit *)&local_c);
  PlayerBuildingEnum::PlayerBuildingEnum(local_8,param_1,param_2);
  iVar1 = PlayerBuildingEnum::GetNext(local_8,(Unit *)&local_c);
  while (iVar1 != 0) {
    uVar2 = FUN_110071f0(SUB41(local_c,0));
    if ((char)uVar2 != '\0') {
      iVar3 = iVar3 + 1;
    }
    iVar1 = PlayerBuildingEnum::GetNext(local_8,(Unit *)&local_c);
  }
  return iVar3;
}


// ---- 11007280 FUN_11007280  (called by: FUN_110040b2@110040b2, FUN_11007300@11007300)

int __cdecl FUN_11007280(int param_1,map_id param_2,map_id param_3)

{
  map_id mVar1;
  map_id mVar2;
  int iVar3;
  map_id mVar4;
  int iVar5;
  undefined4 local_4;
  
  iVar5 = 0;
  local_4 = 0;
  PlayerVehicleEnum::PlayerVehicleEnum((PlayerVehicleEnum *)&param_1,param_1);
  iVar3 = PlayerVehicleEnum::GetNext((PlayerVehicleEnum *)&param_1,(Unit *)&local_4);
  mVar2 = param_3;
  mVar1 = param_2;
  if (iVar3 == 0) {
    return 0;
  }
  do {
    mVar4 = Unit::GetType((Unit *)&local_4);
    if ((mVar4 == mVar1) &&
       ((mVar2 == 0xffffffff || (mVar4 = Unit::GetWeapon((Unit *)&local_4), mVar4 == mVar2)))) {
      iVar5 = iVar5 + 1;
    }
    iVar3 = PlayerVehicleEnum::GetNext((PlayerVehicleEnum *)&param_1,(Unit *)&local_4);
  } while (iVar3 != 0);
  return iVar5;
}


// ---- 11007300 FUN_11007300  (called by: FUN_110077f0@110077f0)

void __cdecl FUN_11007300(int param_1,map_id param_2,map_id param_3)

{
  if ((int)param_2 < 0x11) {
    FUN_11007280(param_1,param_2,param_3);
    return;
  }
  FUN_11007160(param_1,param_2,param_3);
  return;
}


// ---- 11007330 FUN_11007330  (called by: InitProc@11005597)

void FUN_11007330(void)

{
  int local_8;
  undefined4 local_4;
  
  local_8 = 0x400;
  local_4 = 0x400;
  LOCATION::Clip((LOCATION *)&local_8);
  while (local_8 = local_8 + -1, 0x1e < local_8) {
    GameMap::SetCellType(6,local_4,local_8,local_4);
  }
  return;
}


// ---- 11007380 FUN_11007380  (called by: FUN_11007420@11007420)

undefined4 * __thiscall
FUN_11007380(void *this,char param_1,char param_2,undefined1 param_3,undefined4 param_4,
            undefined1 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  FUN_11007cd0(this,param_1,param_2,param_7);
  *(undefined1 *)((int)this + 0x10) = param_3;
  *(undefined1 *)((int)this + 0x11) = param_5;
  *(undefined4 *)((int)this + 0x18) = param_6;
  *(undefined ***)this = &PTR_FUN_110103cc;
  *(undefined4 *)((int)this + 0x14) = param_4;
  *(undefined4 *)((int)this + 8) = param_8;
  return this;
}


// ---- 110073d0 FUN_110073d0  (called by: -)

void __fastcall FUN_110073d0(int param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  
  cVar1 = *(char *)(param_1 + 0x10);
  iVar3 = TethysGame::NoPlayers();
  if (cVar1 < iVar3) {
    iVar3 = FUN_11007210((int)cVar1,*(map_id *)(param_1 + 0x14));
    *(char *)(param_1 + 0x12) = (char)iVar3;
    bVar2 = FUN_110080b0((int)(char)iVar3,(int)*(char *)(param_1 + 0x11),
                         *(undefined4 *)(param_1 + 0x18));
    if (bVar2) {
      FUN_11007d50(param_1);
    }
  }
  return;
}


// ---- 11007420 FUN_11007420  (called by: InitProc@11005597, Research3304Done@11001d41, Research3305Done@11001dee, Research3401Done@11001c7f)

undefined4 * __cdecl
FUN_11007420(char param_1,char param_2,undefined1 param_3,undefined4 param_4,undefined1 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_1c [7];
  
  puVar1 = (undefined4 *)FUN_11007fd0(0x1c);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_11007380(local_1c,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  puVar3 = local_1c;
  puVar4 = puVar1;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_11007da0(&DAT_1101c300,(int)puVar1);
  return puVar1;
}


// ---- 11007490 FUN_11007490  (called by: FUN_110075b0@110075b0)

undefined4 * __thiscall
FUN_11007490(void *this,char param_1,char param_2,ScStub *param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  char cVar1;
  int iVar2;
  
  FUN_11007cd0(this,param_1,param_2,param_5);
  *(undefined ***)this = &PTR_FUN_110103d0;
  iVar2 = ScStub::Id(param_3);
  *(char *)((int)this + 0x10) = (char)iVar2;
  iVar2 = ScGroup::TotalUnitCount((ScGroup *)param_3);
  cVar1 = (char)iVar2;
  *(char *)((int)this + 0x11) = cVar1;
  if (param_4 == 2) {
    *(char *)((int)this + 0x12) = (char)((int)(cVar1 * 3 + (cVar1 * 3 >> 0x1f & 3U)) >> 2);
    *(undefined4 *)((int)this + 8) = param_6;
    return this;
  }
  if (param_4 == 3) {
    *(undefined4 *)((int)this + 8) = param_6;
    *(char *)((int)this + 0x12) = cVar1 / '\x02';
    return this;
  }
  *(undefined1 *)((int)this + 0x12) = 0;
  *(undefined4 *)((int)this + 8) = param_6;
  return this;
}


// ---- 11007530 FUN_11007530  (called by: -)

void __fastcall FUN_11007530(int param_1)

{
  int iVar1;
  int local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_1100f959;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_10 = param_1;
  ScGroup::ScGroup((ScGroup *)&local_10);
  local_4 = 0;
  ScStub::SetId((ScStub *)&local_10,(int)*(char *)(param_1 + 0x10));
  iVar1 = ScGroup::TotalUnitCount((ScGroup *)&local_10);
  if (iVar1 <= *(char *)(param_1 + 0x12)) {
    FUN_11007d50(param_1);
  }
  local_4 = 0xffffffff;
  ScStub::~ScStub((ScStub *)&local_10);
  ExceptionList = local_c;
  return;
}


// ---- 110075b0 FUN_110075b0  (called by: FUN_11001e9b@11001e9b, FUN_110040dd@110040dd, FUN_11004170@11004170)

undefined4 * __cdecl
FUN_110075b0(char param_1,char param_2,ScStub *param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_14 [5];
  
  puVar1 = (undefined4 *)FUN_11007fd0(0x14);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_11007490(local_14,param_1,param_2,param_3,param_4,param_5,param_6);
  puVar3 = local_14;
  puVar4 = puVar1;
  for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_11007da0(&DAT_1101c300,(int)puVar1);
  return puVar1;
}


// ---- 11007620 FUN_11007620  (called by: FUN_11007700@11007700)

undefined4 * __thiscall
FUN_11007620(void *this,char param_1,char param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  
  FUN_11007cd0(this,param_1,param_2,param_5);
  *(undefined ***)this = &PTR_FUN_110103d4;
  if (param_3 < param_4) {
    *(int *)((int)this + 0x10) = param_3;
    *(int *)((int)this + 0x14) = param_4;
  }
  else {
    *(int *)((int)this + 0x10) = param_4;
    *(int *)((int)this + 0x14) = param_3;
  }
  iVar1 = TethysGame::Tick();
  *(int *)((int)this + 0x18) = iVar1;
  FUN_11007680((int)this);
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 8) = param_6;
  return this;
}


// ---- 11007680 FUN_11007680  (called by: FUN_11007620@11007620, FUN_110076c0@110076c0)

void __fastcall FUN_11007680(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x10) == *(int *)(param_1 + 0x14)) {
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x10);
    return;
  }
  iVar1 = TethysGame::GetRand(*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10));
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x10) + iVar1;
  return;
}


// ---- 110076c0 FUN_110076c0  (called by: -)

void __fastcall FUN_110076c0(int param_1)

{
  int iVar1;
  
  iVar1 = TethysGame::Tick();
  if ((*(int *)(param_1 + 0x18) <= iVar1) && (*(int *)(param_1 + 0x1c) < *(int *)(param_1 + 0x18)))
  {
    FUN_11007d50(param_1);
    if ((*(byte *)(param_1 + 6) & 0x20) != 0) {
      return;
    }
    if ((*(byte *)(param_1 + 6) & 2) != 0) {
      FUN_11007680(param_1);
    }
  }
  *(int *)(param_1 + 0x1c) = iVar1;
  return;
}


// ---- 11007700 FUN_11007700  (called by: FUN_11007770@11007770, InitProc@11005597)

undefined4 * __cdecl
FUN_11007700(char param_1,char param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6
            )

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_20 [8];
  
  puVar1 = (undefined4 *)FUN_11007fd0(0x20);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_11007620(local_20,param_1,param_2,param_3,param_4,param_5,param_6);
  puVar3 = local_20;
  puVar4 = puVar1;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_11007da0(&DAT_1101c300,(int)puVar1);
  return puVar1;
}


// ---- 11007770 FUN_11007770  (called by: FUN_11001e9b@11001e9b, FUN_110021fa@110021fa, FUN_110034b1@110034b1, FUN_1100369e@1100369e, FUN_11003f33@11003f33, FUN_110041e5@110041e5, FUN_110042c2@110042c2, FUN_1100451e@1100451e, FUN_11004893@11004893, FUN_11006ce5@11006ce5, InitProc@11005597)

void __cdecl
FUN_11007770(char param_1,char param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  FUN_11007700(param_1,param_2,param_3,param_3,param_4,param_5);
  return;
}


// ---- 110077a0 FUN_110077a0  (called by: FUN_11007840@11007840)

undefined4 * __thiscall
FUN_110077a0(void *this,char param_1,char param_2,undefined1 param_3,undefined4 param_4,
            undefined4 param_5,undefined1 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  FUN_11007cd0(this,param_1,param_2,param_8);
  *(undefined1 *)((int)this + 0x10) = param_3;
  *(undefined1 *)((int)this + 0x11) = param_6;
  *(undefined4 *)((int)this + 0x14) = param_4;
  *(undefined4 *)((int)this + 0x18) = param_5;
  *(undefined ***)this = &PTR_FUN_110103d8;
  *(undefined4 *)((int)this + 0x1c) = param_7;
  *(undefined4 *)((int)this + 8) = param_9;
  return this;
}


// ---- 110077f0 FUN_110077f0  (called by: -)

void __fastcall FUN_110077f0(int param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  
  cVar1 = *(char *)(param_1 + 0x10);
  iVar3 = TethysGame::NoPlayers();
  if (cVar1 < iVar3) {
    cVar1 = FUN_11007300((int)cVar1,*(map_id *)(param_1 + 0x14),*(map_id *)(param_1 + 0x18));
    *(char *)(param_1 + 0x12) = cVar1;
    bVar2 = FUN_110080b0((int)cVar1,(int)*(char *)(param_1 + 0x11),*(undefined4 *)(param_1 + 0x1c));
    if (bVar2) {
      FUN_11007d50(param_1);
    }
  }
  return;
}


// ---- 11007840 FUN_11007840  (called by: FUN_11002435@11002435, FUN_110025af@110025af)

undefined4 * __cdecl
FUN_11007840(char param_1,char param_2,undefined1 param_3,undefined4 param_4,undefined4 param_5,
            undefined1 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_20 [8];
  
  puVar1 = (undefined4 *)FUN_11007fd0(0x20);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_110077a0(local_20,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  puVar3 = local_20;
  puVar4 = puVar1;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_11007da0(&DAT_1101c300,(int)puVar1);
  return puVar1;
}


// ---- 110078c0 FUN_110078c0  (called by: FUN_11007990@11007990)

undefined4 * __thiscall
FUN_110078c0(undefined4 *param_1,char param_2,char param_3,undefined1 param_4,LOCATION param_5,
            undefined4 param_6,undefined4 param_7)

{
  FUN_11007cd0(param_1,param_2,param_3,param_7);
  param_1[5] = 0;
  param_1[6] = 0;
  *param_1 = &PTR_LAB_110103dc;
  *(undefined1 *)(param_1 + 4) = param_4;
  LOCATION::operator=((LOCATION *)(param_1 + 5),&param_5);
  param_1[2] = 0;
  return param_1;
}


// ---- 11007990 FUN_11007990  (called by: FUN_11007a00@11007a00)

undefined4 * __cdecl
FUN_11007990(char param_1,char param_2,undefined1 param_3,LOCATION param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_1c [7];
  
  puVar1 = (undefined4 *)FUN_11007fd0(0x1c);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_110078c0(local_1c,param_1,param_2,param_3,param_4,param_5,param_6);
  puVar3 = local_1c;
  puVar4 = puVar1;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_11007da0(&DAT_1101c300,(int)puVar1);
  return puVar1;
}


// ---- 11007a00 FUN_11007a00  (called by: FUN_11002a76@11002a76)

void __cdecl
FUN_11007a00(char param_1,char param_2,undefined1 param_3,LOCATION param_4,undefined4 param_5,
            undefined4 param_6)

{
  FUN_11007990(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ---- 11007a30 FUN_11007a30  (called by: FUN_11007af0@11007af0)

undefined4 * __thiscall
FUN_11007a30(undefined4 *param_1,char param_2,char param_3,undefined1 param_4,MAP_RECT param_5)

{
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  
  FUN_11007cd0(param_1,param_2,param_3,in_stack_00000020);
  MAP_RECT::MAP_RECT((MAP_RECT *)(param_1 + 5));
  *param_1 = &PTR_LAB_110103e0;
  *(undefined1 *)(param_1 + 4) = param_4;
  MAP_RECT::operator=((MAP_RECT *)(param_1 + 5),&param_5);
  param_1[2] = in_stack_00000024;
  return param_1;
}


// ---- 11007af0 FUN_11007af0  (called by: FUN_11007b70@11007b70)

undefined4 * __cdecl FUN_11007af0(char param_1,char param_2,undefined1 param_3,MAP_RECT param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_24 [9];
  
  puVar1 = (undefined4 *)FUN_11007fd0(0x24);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_11007a30(local_24,param_1,param_2,param_3,param_4);
    puVar3 = local_24;
    puVar4 = puVar1;
    for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_11007da0(&DAT_1101c300,(int)puVar1);
  }
  return puVar1;
}


// ---- 11007b70 FUN_11007b70  (called by: FUN_11003b2b@11003b2b, FUN_11003d2e@11003d2e, FUN_11004311@11004311)

void __cdecl
FUN_11007b70(char param_1,char param_2,undefined1 param_3,int param_4,int param_5,int param_6,
            int param_7)

{
  undefined4 *puVar1;
  MAP_RECT local_10 [16];
  
  puVar1 = (undefined4 *)
           MAP_RECT::MAP_RECT(local_10,param_4,param_5,param_6 + param_4,param_5 + param_7);
  FUN_11007af0(param_1,param_2,param_3,SUB41(*puVar1,0));
  return;
}


// ---- 11007be0 GetSaveRegions  (called by: -)

void __cdecl GetSaveRegions(int *param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *_Str1;
  int iVar6;
  
                    /* 0x7be0  6  GetSaveRegions */
  iVar4 = ImageLoad(&DAT_1101c2a8,0);
  iVar6 = 0;
  iVar1 = *(int *)(iVar4 + 0x14);
  pcVar2 = *(char **)(iVar4 + 0x18);
  iVar3 = *(int *)(*(int *)(iVar4 + 0xc) + 0x34);
  DAT_11019b00 = *(undefined4 *)(*(int *)(iVar4 + 0xc) + 8);
  _Str1 = pcVar2;
  if (0 < iVar1) {
    while( true ) {
      iVar5 = _strncmp(_Str1,s__save_11015468,5);
      if (iVar5 == 0) break;
      iVar6 = iVar6 + 1;
      _Str1 = _Str1 + 0x28;
      if (iVar1 <= iVar6) {
        ImageUnload(iVar4);
        return;
      }
    }
    *param_1 = *(int *)(pcVar2 + iVar6 * 0x28 + 0xc) + iVar3;
    param_1[1] = *(int *)(pcVar2 + iVar6 * 0x28 + 8);
  }
  ImageUnload(iVar4);
  return;
}


// ---- 11007c80 FUN_11007c80  (called by: FUN_11005e63@11005e63)

void __cdecl FUN_11007c80(HMODULE param_1)

{
  GetModuleFileNameA(param_1,&DAT_1101c2a8,0x50);
  return;
}


// ---- 11007cc0 AIProc  (called by: -)

void AIProc(void)

{
                    /* 0x7cc0  4  AIProc */
  FUN_11007e90(&DAT_1101c300);
  return;
}


// ---- 11007cd0 FUN_11007cd0  (called by: FUN_11006ff5@11006ff5, FUN_11007380@11007380, FUN_11007490@11007490, FUN_11007620@11007620, FUN_110077a0@110077a0, FUN_110078c0@110078c0, FUN_11007a30@11007a30)

undefined4 * __thiscall FUN_11007cd0(void *this,char param_1,char param_2,undefined4 param_3)

{
  *(undefined ***)this = &PTR_LAB_110103ec;
  FUN_11007d10(this,param_1,param_2,param_3);
  return this;
}


// ---- 11007d00 FUN_11007d00  (called by: FUN_11007d50@11007d50)

void __fastcall FUN_11007d00(int param_1)

{
  *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) | 0x20;
  return;
}


// ---- 11007d10 FUN_11007d10  (called by: FUN_11007cd0@11007cd0)

void __thiscall FUN_11007d10(void *this,char param_1,char param_2,undefined4 param_3)

{
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined2 *)((int)this + 4) = 0;
  *(byte *)((int)this + 6) = param_1 != '\0' | (-(param_2 != '\0') & 2U) + 2 | 8;
  *(undefined4 *)((int)this + 0xc) = param_3;
  return;
}


// ---- 11007d50 FUN_11007d50  (called by: FUN_11007035@11007035, FUN_110073d0@110073d0, FUN_11007530@11007530, FUN_110076c0@110076c0, FUN_110077f0@110077f0)

void __fastcall FUN_11007d50(int param_1)

{
  byte bVar1;
  
  if (*(code **)(param_1 + 0xc) != (code *)0x0) {
    *(short *)(param_1 + 4) = *(short *)(param_1 + 4) + 1;
    (**(code **)(param_1 + 0xc))(param_1);
    bVar1 = *(byte *)(param_1 + 6);
    if (((bVar1 & 2) == 0) && (*(byte *)(param_1 + 6) = bVar1 & 0xfe, (bVar1 & 4) != 0)) {
      FUN_11007d00(param_1);
    }
  }
  return;
}


// ---- 11007da0 FUN_11007da0  (called by: FUN_110070b6@110070b6, FUN_11007420@11007420, FUN_110075b0@110075b0, FUN_11007700@11007700, FUN_11007840@11007840, FUN_11007990@11007990, FUN_11007af0@11007af0)

void __thiscall FUN_11007da0(void *this,int param_1)

{
  int iVar1;
  
  iVar1 = FUN_11007e30(this,param_1);
  if (iVar1 < 0) {
    if (*(int *)((int)this + 4) == 0x200) {
      (*DAT_110103e8)(s_ERROR_11015494,0x10);
      return;
    }
    *(int *)(*(int *)this + *(int *)((int)this + 4) * 4) = param_1;
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  }
  return;
}


// ---- 11007df0 FUN_11007df0  (called by: FUN_11007f70@11007f70)

void __thiscall FUN_11007df0(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = FUN_11007e30(this,param_1);
  if (-1 < iVar3) {
    iVar3 = iVar3 + 1;
    if (iVar3 < *(int *)((int)this + 4)) {
      do {
        iVar1 = iVar3 * 4;
        iVar2 = iVar3 * 4;
        iVar3 = iVar3 + 1;
        *(undefined4 *)(*(int *)this + iVar2 + -4) = *(undefined4 *)(*(int *)this + iVar1);
      } while (iVar3 < *(int *)((int)this + 4));
    }
    iVar3 = *(int *)((int)this + 4) + -1;
    *(int *)((int)this + 4) = iVar3;
    *(undefined4 *)(*(int *)this + iVar3 * 4) = 0;
  }
  return;
}


// ---- 11007e30 FUN_11007e30  (called by: FUN_11007da0@11007da0, FUN_11007df0@11007df0)

void __thiscall FUN_11007e30(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)((int)this + 4) + -1;
  if (-1 < iVar1) {
    piVar2 = (int *)(*(int *)this + iVar1 * 4);
    do {
      if (*piVar2 == param_1) {
        return;
      }
      iVar1 = iVar1 + -1;
      piVar2 = piVar2 + -1;
    } while (-1 < iVar1);
  }
  return;
}


// ---- 11007e50 FUN_11007e50  (called by: FUN_11007e90@11007e90)

void FUN_11007e50(void)

{
  if (DAT_11019b04 == '\0') {
    if (DAT_1101c2f8 != DAT_11019b00) {
      DAT_11019b04 = '\x01';
      if (DAT_1101c2f8 == 0) {
        DAT_1101c2f8 = DAT_11019b00;
        return;
      }
      (*DAT_110103e8)(s_WARNING_110154e4,0x30);
    }
  }
  return;
}


// ---- 11007e90 FUN_11007e90  (called by: AIProc@11007cc0)

void __fastcall FUN_11007e90(int *param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_1100f970;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_11007e50();
  iVar3 = param_1[1];
  while( true ) {
    iVar3 = iVar3 + -1;
    if (iVar3 < 0) break;
    local_8 = 0;
    puVar2 = *(undefined4 **)(*param_1 + iVar3 * 4);
    if ((puVar2 == (undefined4 *)0x0) || (bVar1 = *(byte *)((int)puVar2 + 6), (bVar1 & 0x20) != 0))
    {
      local_8 = 0xffffffff;
    }
    else {
      if (((bVar1 & 1) != 0) && ((bVar1 & 8) == 0)) {
        (**(code **)*puVar2)();
      }
      local_8 = 0xffffffff;
      *(byte *)((int)puVar2 + 6) = *(byte *)((int)puVar2 + 6) & 0xf7;
    }
  }
  FUN_11007f70(param_1);
  ExceptionList = local_10;
  return;
}


// ---- 11007f01 Catch@11007f01  (called by: -)

undefined * Catch_11007f01(void)

{
  int unaff_EBP;
  
  scr_snprintf((char *)(unaff_EBP + -0x6c),0x50,s_Error_executing_event__02X_ID__0_110154f8,
               *(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 8),
               *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0xc));
  (*DAT_110103e8)(s_EventError_110154ec,0x30);
  return FUN_11007f3c;
}


// ---- 11007f3c FUN_11007f3c  (called by: -)

void FUN_11007f3c(void)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int unaff_EBP;
  
  piVar4 = *(int **)(unaff_EBP + -0x1c);
  iVar5 = *(int *)(unaff_EBP + -0x14);
  do {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    while( true ) {
      iVar5 = iVar5 + -1;
      *(int *)(unaff_EBP + -0x14) = iVar5;
      if (iVar5 < 0) {
        FUN_11007f70(piVar4);
        ExceptionList = *(void **)(unaff_EBP + -0xc);
        return;
      }
      iVar2 = *piVar4;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      puVar3 = *(undefined4 **)(iVar2 + iVar5 * 4);
      *(undefined4 **)(unaff_EBP + -0x18) = puVar3;
      if ((puVar3 == (undefined4 *)0x0) || (bVar1 = *(byte *)((int)puVar3 + 6), (bVar1 & 0x20) != 0)
         ) break;
      if (((bVar1 & 1) != 0) && ((bVar1 & 8) == 0)) {
        (**(code **)*puVar3)();
      }
      bVar1 = *(byte *)((int)puVar3 + 6);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(byte *)((int)puVar3 + 6) = bVar1 & 0xf7;
    }
  } while( true );
}


// ---- 11007f70 FUN_11007f70  (called by: FUN_11007f3c@11007f3c)

void __fastcall FUN_11007f70(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[1];
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    iVar2 = *(int *)(*param_1 + iVar1 * 4);
    if ((iVar2 != 0) && ((*(byte *)(iVar2 + 6) & 0x20) != 0)) {
      FUN_11007df0(param_1,iVar2);
      FUN_11008060(iVar2);
    }
  }
  return;
}


// ---- 11007fb0 FUN_11007fb0  (called by: FUN_11007fd0@11007fd0, FUN_11008060@11008060)

undefined * FUN_11007fb0(LPCSTR param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_retaddr;
  
  MessageBoxA((HWND)0x0,param_1,s_ERROR_11015494,0x10);
  FUN_11009bd5(0xffffffff);
  iVar2 = (unaff_retaddr - 1U >> 4) + 1;
  iVar5 = 0;
  do {
    cVar1 = (&DAT_11024b08)[iVar5];
    iVar4 = 0;
    while (cVar1 == '\0') {
      iVar3 = iVar4 + 1;
      if (iVar3 == iVar2) {
        for (; 0 < iVar4; iVar4 = iVar4 + -1) {
          (&DAT_11024b08)[iVar4 + iVar5] = 0xff;
        }
        (&DAT_11024b08)[iVar5] = (char)iVar2;
        return &DAT_1101cb08 + iVar5 * 0x10;
      }
      if (0x7ff < iVar3 + iVar5) {
        FUN_11007fb0(s__new__Out_of_memory_1101552c);
      }
      iVar4 = iVar3;
      cVar1 = (&DAT_11024b08)[iVar3 + iVar5];
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x800);
  FUN_11007fb0(s__new__Out_of_memory_1101552c);
  return (undefined *)0x0;
}


// ---- 11007fd0 FUN_11007fd0  (called by: FUN_110070b6@110070b6, FUN_11007420@11007420, FUN_110075b0@110075b0, FUN_11007700@11007700, FUN_11007840@11007840, FUN_11007990@11007990, FUN_11007af0@11007af0)

undefined * __cdecl FUN_11007fd0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = (param_1 - 1U >> 4) + 1;
  iVar5 = 0;
  do {
    cVar1 = (&DAT_11024b08)[iVar5];
    iVar4 = 0;
    while (cVar1 == '\0') {
      iVar3 = iVar4 + 1;
      if (iVar3 == iVar2) {
        for (; 0 < iVar4; iVar4 = iVar4 + -1) {
          (&DAT_11024b08)[iVar4 + iVar5] = 0xff;
        }
        (&DAT_11024b08)[iVar5] = (char)iVar2;
        return &DAT_1101cb08 + iVar5 * 0x10;
      }
      if (0x7ff < iVar3 + iVar5) {
        FUN_11007fb0(s__new__Out_of_memory_1101552c);
      }
      iVar4 = iVar3;
      cVar1 = (&DAT_11024b08)[iVar3 + iVar5];
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x800);
  FUN_11007fb0(s__new__Out_of_memory_1101552c);
  return (undefined *)0x0;
}


// ---- 11008060 FUN_11008060  (called by: FUN_11007f70@11007f70)

void __cdecl FUN_11008060(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (int)(param_1 + -0x1101cb08 + (param_1 + -0x1101cb08 >> 0x1f & 0xfU)) >> 4;
  iVar2 = (int)(char)(&DAT_11024b08)[iVar1];
  if ((iVar2 < 1) || (0xfe < iVar2)) {
    FUN_11007fb0(s__delete__Invalid_pointer_supplie_11015540);
  }
  else {
    iVar2 = iVar2 + -1;
    if (-1 < iVar2) {
      do {
        (&DAT_11024b08)[iVar2 + iVar1] = 0;
        iVar2 = iVar2 + -1;
      } while (-1 < iVar2);
      return;
    }
  }
  return;
}


// ---- 110080b0 FUN_110080b0  (called by: FUN_110073d0@110073d0, FUN_110077f0@110077f0)

bool __cdecl FUN_110080b0(int param_1,int param_2,undefined4 param_3)

{
  switch(param_3) {
  case 0:
    return param_1 == param_2;
  case 1:
    return param_1 <= param_2;
  case 2:
    return param_2 <= param_1;
  case 3:
    return param_1 < param_2;
  case 4:
    return param_2 < param_1;
  default:
    return false;
  }
}


// ---- 11008156 FUN_11008156  (called by: FUN_11005e63@11005e63)

undefined4 __cdecl FUN_11008156(int param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 uVar3;
  DWORD local_8;
  
  iVar1 = _memcmp(DAT_1101556c,&DAT_110103f0,0x14);
  if (iVar1 == 0) {
    iVar1 = _memcmp(DAT_11015574,&DAT_11010430,6);
    if (iVar1 == 0) {
      iVar1 = _memcmp(DAT_11015578,&DAT_11010418,5);
      uVar3 = 3;
      if (iVar1 == 0) {
        iVar1 = _memcmp(DAT_1101557c,&DAT_11010428,3);
        if (iVar1 == 0) {
          BVar2 = VirtualProtect(DAT_1101556c,0x14,0x40,&local_8);
          if (BVar2 == 0) {
            uVar3 = 5;
          }
          else {
            BVar2 = VirtualProtect(DAT_11015574,6,0x40,&local_8);
            if (BVar2 == 0) {
              uVar3 = 6;
            }
            else {
              BVar2 = VirtualProtect(DAT_11015578,5,0x40,&local_8);
              if (BVar2 == 0) {
                uVar3 = 7;
              }
              else {
                BVar2 = VirtualProtect(DAT_1101557c,3,0x40,&local_8);
                if (BVar2 != 0) {
                  EnterCriticalSection(DAT_11015568);
                  FUN_11009690(DAT_1101556c,(undefined4 *)&DAT_11010404,0x14);
                  *(undefined4 *)((int)DAT_1101556c + 0xb) = DAT_11015570;
                  DAT_1101556c[4] = (param_1 - (int)DAT_1101556c) + -0x14;
                  FUN_11009690(DAT_11015574,(undefined4 *)&DAT_11010438,6);
                  FUN_11009690(DAT_11015578,(undefined4 *)&DAT_11010420,5);
                  FUN_11009690(DAT_1101557c,(undefined4 *)&DAT_1101042c,3);
                  LeaveCriticalSection(DAT_11015568);
                  return 0;
                }
                uVar3 = 8;
              }
            }
          }
        }
        else {
          uVar3 = 4;
        }
      }
    }
    else {
      uVar3 = 2;
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


// ---- 110082c1 UninstallMusicHook  (called by: FUN_11005e31@11005e31)

/* int __cdecl UninstallMusicHook(void) */

int __cdecl UninstallMusicHook(void)

{
                    /* 0x82c1  3  ?UninstallMusicHook@@YAHXZ */
  EnterCriticalSection(DAT_11015568);
  FUN_11009690(DAT_1101556c,(undefined4 *)&DAT_110103f0,0x14);
  FUN_11009690(DAT_11015574,(undefined4 *)&DAT_11010430,6);
  FUN_11009690(DAT_11015578,(undefined4 *)&DAT_11010418,5);
  FUN_11009690(DAT_1101557c,(undefined4 *)&DAT_11010428,3);
  LeaveCriticalSection(DAT_11015568);
  return 0;
}


// ---- 11008331 FUN_11008331  (called by: -)

void FUN_11008331(void)

{
  FUN_11008425((undefined4 *)&DAT_11019b08);
  return;
}


// ---- 1100833b FUN_1100833b  (called by: -)

void FUN_1100833b(void)

{
  FUN_11009045(0x11008347);
  return;
}


// ---- 11008347 FUN_11008347  (called by: -)

void FUN_11008347(void)

{
  FUN_11008472((undefined4 *)&DAT_11019b08);
  return;
}


// ---- 11008351 FUN_11008351  (called by: FUN_1100837f@1100837f)

void __cdecl FUN_11008351(undefined4 param_1)

{
  FUN_110084d0(0x11019b08);
  DAT_11019b14 = param_1;
  FUN_1100847d(&DAT_11019b08,param_1);
  FUN_110084c5(0x11019b08);
  DAT_11015580 = 0;
  return;
}


// ---- 1100837f FUN_1100837f  (called by: FUN_11005e63@11005e63)

void __cdecl FUN_1100837f(undefined4 param_1,ushort param_2)

{
  FUN_11008351(param_1);
  FUN_11008394(param_2);
  return;
}


// ---- 11008394 FUN_11008394  (called by: FUN_1100837f@1100837f)

void __cdecl FUN_11008394(ushort param_1)

{
  FUN_110084e5(&DAT_11019b08,param_1,0);
  return;
}


// ---- 110083a5 FUN_110083a5  (called by: -)

undefined4 FUN_110083a5(undefined4 *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 unaff_BP;
  undefined4 local_8004 [8182];
  undefined4 uStackY_2c;
  
  FUN_11008ba0(unaff_BP);
  uVar2 = 0;
  if (DAT_11019b14 != 0) {
    if (DAT_11015580 == '\x01') {
      FUN_1100847d(&DAT_11019b08,DAT_11019b14);
      FUN_110084c5(0x11019b08);
      DAT_11015580 = '\0';
    }
    iVar1 = FUN_110084ab(&DAT_11019b08,local_8004,0x8000);
    FUN_11009690(param_1,local_8004,param_2);
    uStackY_2c = 0x11008418;
    _memset((void *)(iVar1 + (int)param_1),0,param_2 - iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


// ---- 11008425 FUN_11008425  (called by: FUN_11008331@11008331)

undefined4 * __fastcall FUN_11008425(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  *param_1 = &PTR_FUN_11010440;
  iVar1 = BASS_Init(0,0x5622,2,0,0);
  if (iVar1 == 0) {
    uVar2 = BASS_ErrorGetCode();
    param_1[1] = uVar2;
  }
  else {
    param_1[1] = 0;
  }
  return param_1;
}


// ---- 11008456 FUN_11008456  (called by: -)

undefined4 * __thiscall FUN_11008456(void *this,byte param_1)

{
  FUN_11008472(this);
  if ((param_1 & 1) != 0) {
    FUN_11009086(this);
  }
  return this;
}


// ---- 11008472 FUN_11008472  (called by: FUN_11008347@11008347, FUN_11008456@11008456)

void __fastcall FUN_11008472(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_11010440;
  BASS_Free();
  return;
}


// ---- 1100847d FUN_1100847d  (called by: FUN_11008351@11008351, FUN_110083a5@110083a5)

bool __thiscall FUN_1100847d(void *this,undefined4 param_1)

{
  int iVar1;
  bool bVar2;
  
  if (*(int *)((int)this + 4) == 0) {
    iVar1 = BASS_MusicLoad(0,param_1,0,0,0x200200,0);
    bVar2 = iVar1 == 0;
    *(int *)((int)this + 8) = iVar1;
  }
  else {
    bVar2 = true;
  }
  return bVar2;
}


// ---- 110084ab FUN_110084ab  (called by: FUN_110083a5@110083a5)

undefined4 __thiscall FUN_110084ab(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = BASS_ChannelGetData(*(undefined4 *)((int)this + 8),param_1,param_2);
  return uVar1;
}


// ---- 110084c5 FUN_110084c5  (called by: FUN_11008351@11008351, FUN_110083a5@110083a5)

void __fastcall FUN_110084c5(int param_1)

{
  BASS_ChannelPlay(*(undefined4 *)(param_1 + 8),0);
  return;
}


// ---- 110084d0 FUN_110084d0  (called by: FUN_11008351@11008351)

void __fastcall FUN_110084d0(int param_1)

{
  BASS_ChannelStop(*(undefined4 *)(param_1 + 8));
  BASS_MusicFree(*(undefined4 *)(param_1 + 8));
  return;
}


// ---- 110084e5 FUN_110084e5  (called by: FUN_11008394@11008394)

void __thiscall FUN_110084e5(void *this,ushort param_1,ushort param_2)

{
  BASS_ChannelSetPosition
            (*(undefined4 *)((int)this + 8),(param_2 | 0xffff8000) << 0x10 | (uint)param_1,0);
  return;
}


// ---- 1100852c _malloc  (called by: FUN_1100107a@1100107a, FUN_11006b64@11006b64, FUN_11009208@11009208, FUN_11009f49@11009f49, FUN_1100aec6@1100aec6, FUN_1100b5e1@1100b5e1, FUN_1100d1b3@1100d1b3, FUN_1100d26c@1100d26c, FUN_1100d4b9@1100d4b9, FUN_1100dbc3@1100dbc3, FUN_1100dea4@1100dea4)

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_11019b70);
  return pvVar1;
}


// ---- 1100853e __nh_malloc  (called by: _malloc@1100852c, operator_new@11009091)

/* Library Function - Single Match
    __nh_malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl __nh_malloc(size_t _Size,int _NhFlag)

{
  int *piVar1;
  int iVar2;
  
  if (_Size < 0xffffffe1) {
    do {
      piVar1 = FUN_1100856a((uint *)_Size);
      if (piVar1 != (int *)0x0) {
        return piVar1;
      }
      if (_NhFlag == 0) {
        return (void *)0x0;
      }
      iVar2 = FUN_11009de8(_Size);
    } while (iVar2 != 0);
  }
  return (void *)0x0;
}


// ---- 1100856a FUN_1100856a  (called by: __nh_malloc@1100853e)

int * __cdecl FUN_1100856a(uint *param_1)

{
  int *piVar1;
  
  if (param_1 <= DAT_11015674) {
    FUN_11009f49(9);
    piVar1 = FUN_1100a353(param_1);
    FUN_11009faa(9);
    if (piVar1 != (int *)0x0) {
      return piVar1;
    }
  }
  if (param_1 == (uint *)0x0) {
    param_1 = (uint *)0x1;
  }
  piVar1 = HeapAlloc(DAT_1101b21c,0,(int)param_1 + 0xfU & 0xfffffff0);
  return piVar1;
}


// ---- 110085b8 FUN_110085b8  (called by: FUN_110010ef@110010ef, FUN_11006ba7@11006ba7, FUN_11009086@11009086, FUN_11009208@11009208, FUN_11009edd@11009edd, FUN_11009f49@11009f49, FUN_1100b082@1100b082, FUN_1100bff8@1100bff8, FUN_1100d1b3@1100d1b3, FUN_1100d4b9@1100d4b9, __fclose_lk@11008631, __freebuf@1100ad3e)

void __cdecl FUN_110085b8(LPVOID param_1)

{
  uint *puVar1;
  
  if (param_1 != (LPVOID)0x0) {
    FUN_11009f49(9);
    puVar1 = (uint *)FUN_11009ffd((int)param_1);
    if (puVar1 != (uint *)0x0) {
      FUN_1100a028(puVar1,(uint)param_1);
      FUN_11009faa(9);
      return;
    }
    FUN_11009faa(9);
    HeapFree(DAT_1101b21c,0,param_1);
  }
  return;
}


// ---- 11008600 FUN_11008600  (called by: FUN_11001106@11001106, FUN_11005fe6@11005fe6, FUN_1100631d@1100631d, FUN_11006491@11006491, FUN_110064f3@110064f3, FUN_11006737@11006737, FUN_1100690b@1100690b)

undefined4 __cdecl FUN_11008600(FILE *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1->_flag & 0x40) == 0) {
    FUN_1100abba((uint)param_1);
    uVar1 = __fclose_lk(param_1);
    FUN_1100ac0c((uint)param_1);
  }
  else {
    param_1->_flag = 0;
  }
  return uVar1;
}


// ---- 11008631 __fclose_lk  (called by: FUN_11008600@11008600)

/* Library Function - Single Match
    __fclose_lk
   
   Library: Visual Studio 2003 Release */

undefined4 __cdecl __fclose_lk(FILE *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1->_flag & 0x83) != 0) {
    uVar2 = FUN_11008916((int *)param_1);
    __freebuf(param_1);
    iVar1 = FUN_1100ac5e(param_1->_file);
    if (iVar1 < 0) {
      uVar2 = 0xffffffff;
    }
    else if (param_1->_tmpfname != (char *)0x0) {
      FUN_110085b8(param_1->_tmpfname);
      param_1->_tmpfname = (char *)0x0;
    }
  }
  param_1->_flag = 0;
  return uVar2;
}


// ---- 1100867d FUN_1100867d  (called by: FUN_11001106@11001106)

int __cdecl FUN_1100867d(int *param_1,int param_2,DWORD param_3)

{
  int iVar1;
  
  FUN_1100abba((uint)param_1);
  iVar1 = FUN_110086a9(param_1,param_2,param_3);
  FUN_1100ac0c((uint)param_1);
  return iVar1;
}


// ---- 110086a9 FUN_110086a9  (called by: FUN_1100867d@1100867d)

int __cdecl FUN_110086a9(int *param_1,int param_2,DWORD param_3)

{
  uint uVar1;
  int iVar2;
  DWORD DVar3;
  DWORD *pDVar4;
  
  if (((param_1[3] & 0x83U) == 0) || (((param_3 != 0 && (param_3 != 1)) && (param_3 != 2)))) {
    pDVar4 = FUN_1100addc();
    *pDVar4 = 0x16;
    iVar2 = -1;
  }
  else {
    param_1[3] = param_1[3] & 0xffffffef;
    if (param_3 == 1) {
      iVar2 = FUN_11008758((char *)param_1);
      param_2 = param_2 + iVar2;
      param_3 = 0;
    }
    FUN_11008916(param_1);
    uVar1 = param_1[3];
    if ((uVar1 & 0x80) == 0) {
      if ((((uVar1 & 1) != 0) && ((uVar1 & 8) != 0)) && ((uVar1 & 0x400) == 0)) {
        param_1[6] = 0x200;
      }
    }
    else {
      param_1[3] = uVar1 & 0xfffffffc;
    }
    DVar3 = FUN_1100adee(param_1[4],param_2,param_3);
    iVar2 = (DVar3 != 0xffffffff) - 1;
  }
  return iVar2;
}


// ---- 11008736 FUN_11008736  (called by: Catch@11006829@11006829, FUN_11001106@11001106)

int __cdecl FUN_11008736(char *param_1)

{
  int iVar1;
  
  FUN_1100abba((uint)param_1);
  iVar1 = FUN_11008758(param_1);
  FUN_1100ac0c((uint)param_1);
  return iVar1;
}


// ---- 11008758 FUN_11008758  (called by: FUN_110086a9@110086a9, FUN_11008736@11008736)

int __cdecl FUN_11008758(char *param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  DWORD *pDVar4;
  char *pcVar5;
  DWORD DVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  int local_c;
  DWORD local_8;
  
  pcVar8 = param_1;
  uVar1 = *(uint *)(param_1 + 0x10);
  if (*(int *)(param_1 + 4) < 0) {
    param_1[4] = '\0';
    param_1[5] = '\0';
    param_1[6] = '\0';
    param_1[7] = '\0';
  }
  local_8 = FUN_1100adee(uVar1,0,1);
  if ((int)local_8 < 0) {
LAB_110087e6:
    local_c = -1;
  }
  else {
    uVar2 = *(uint *)(param_1 + 0xc);
    if ((uVar2 & 0x108) == 0) {
      return local_8 - *(int *)(param_1 + 4);
    }
    pcVar5 = *(char **)param_1;
    pcVar7 = *(char **)(param_1 + 8);
    local_c = (int)pcVar5 - (int)pcVar7;
    if ((uVar2 & 3) == 0) {
      if ((uVar2 & 0x80) == 0) {
        pDVar4 = FUN_1100addc();
        *pDVar4 = 0x16;
        goto LAB_110087e6;
      }
    }
    else if ((*(byte *)((&DAT_1101a0e0)[(int)uVar1 >> 5] + 4 + (uVar1 & 0x1f) * 0x24) & 0x80) != 0)
    {
      for (pcVar9 = pcVar7; pcVar9 < pcVar5; pcVar9 = pcVar9 + 1) {
        if (*pcVar9 == '\n') {
          local_c = local_c + 1;
        }
      }
    }
    if (local_8 != 0) {
      if ((param_1[0xc] & 1U) != 0) {
        if (*(int *)(param_1 + 4) == 0) {
          local_c = 0;
        }
        else {
          pcVar5 = pcVar5 + (*(int *)(param_1 + 4) - (int)pcVar7);
          iVar10 = (uVar1 & 0x1f) * 0x24;
          if ((*(byte *)(iVar10 + 4 + (&DAT_1101a0e0)[(int)uVar1 >> 5]) & 0x80) != 0) {
            DVar6 = FUN_1100adee(uVar1,0,2);
            if (DVar6 == local_8) {
              pcVar7 = *(char **)(param_1 + 8);
              pcVar9 = pcVar5 + (int)pcVar7;
              param_1 = pcVar5;
              for (; pcVar7 < pcVar9; pcVar7 = pcVar7 + 1) {
                if (*pcVar7 == '\n') {
                  param_1 = param_1 + 1;
                }
              }
              bVar3 = pcVar8[0xd] & 0x20;
            }
            else {
              FUN_1100adee(uVar1,local_8,0);
              pcVar8 = (char *)0x200;
              if ((((char *)0x200 < pcVar5) || ((*(uint *)(param_1 + 0xc) & 8) == 0)) ||
                 ((*(uint *)(param_1 + 0xc) & 0x400) != 0)) {
                pcVar8 = *(char **)(param_1 + 0x18);
              }
              bVar3 = *(byte *)(iVar10 + 4 + (&DAT_1101a0e0)[(int)uVar1 >> 5]) & 4;
              param_1 = pcVar8;
            }
            pcVar5 = param_1;
            if (bVar3 != 0) {
              pcVar5 = param_1 + 1;
            }
          }
          param_1 = pcVar5;
          local_8 = local_8 - (int)param_1;
        }
      }
      local_c = local_c + local_8;
    }
  }
  return local_c;
}


// ---- 110088b9 FUN_110088b9  (called by: FUN_11001106@11001106)

int __cdecl FUN_110088b9(int *param_1)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    iVar1 = FUN_1100897b(0);
    return iVar1;
  }
  FUN_1100abba((uint)param_1);
  iVar1 = FUN_110088e8(param_1);
  FUN_1100ac0c((uint)param_1);
  return iVar1;
}


// ---- 110088e8 FUN_110088e8  (called by: FUN_110088b9@110088b9, FUN_1100897b@1100897b)

int __cdecl FUN_110088e8(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_11008916(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((*(byte *)((int)param_1 + 0xd) & 0x40) == 0) {
    return 0;
  }
  iVar1 = FUN_1100b0d6(param_1[4]);
  return -(uint)(iVar1 != 0);
}


// ---- 11008916 FUN_11008916  (called by: FUN_110086a9@110086a9, FUN_110088e8@110088e8, FUN_11008a4e@11008a4e, __fclose_lk@11008631)

undefined4 __cdecl FUN_11008916(int *param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  DWORD DVar3;
  
  uVar2 = 0;
  if ((((byte)param_1[3] & 3) == 2) && ((param_1[3] & 0x108U) != 0)) {
    DVar3 = *param_1 - param_1[2];
    if (0 < (int)DVar3) {
      DVar1 = FUN_1100b169(param_1[4],(char *)param_1[2],DVar3);
      if (DVar1 == DVar3) {
        if ((param_1[3] & 0x80U) != 0) {
          param_1[3] = param_1[3] & 0xfffffffd;
        }
      }
      else {
        param_1[3] = param_1[3] | 0x20;
        uVar2 = 0xffffffff;
      }
    }
  }
  param_1[1] = 0;
  *param_1 = param_1[2];
  return uVar2;
}


// ---- 1100897b FUN_1100897b  (called by: FUN_110088b9@110088b9)

int __cdecl FUN_1100897b(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar5 = 0;
  FUN_11009f49(2);
  iVar4 = 0;
  if (0 < DAT_1101b200) {
    do {
      iVar2 = *(int *)(DAT_1101a1e4 + iVar4 * 4);
      if ((iVar2 != 0) && ((*(byte *)(iVar2 + 0xc) & 0x83) != 0)) {
        FUN_1100abe9(iVar4,iVar2);
        piVar1 = *(int **)(DAT_1101a1e4 + iVar4 * 4);
        if ((piVar1[3] & 0x83U) != 0) {
          if (param_1 == 1) {
            iVar2 = FUN_110088e8(piVar1);
            if (iVar2 != -1) {
              iVar3 = iVar3 + 1;
            }
          }
          else if ((param_1 == 0) && ((piVar1[3] & 2U) != 0)) {
            iVar2 = FUN_110088e8(piVar1);
            if (iVar2 == -1) {
              iVar5 = -1;
            }
          }
        }
        FUN_1100ac3b(iVar4,*(int *)(DAT_1101a1e4 + iVar4 * 4));
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_1101b200);
  }
  FUN_11009faa(2);
  if (param_1 != 1) {
    iVar3 = iVar5;
  }
  return iVar3;
}


// ---- 11008a1f FUN_11008a1f  (called by: FUN_11001106@11001106, FUN_11005fe6@11005fe6, FUN_1100631d@1100631d, FUN_11006491@11006491)

uint __cdecl FUN_11008a1f(char *param_1,uint param_2,uint param_3,int *param_4)

{
  uint uVar1;
  
  FUN_1100abba((uint)param_4);
  uVar1 = FUN_11008a4e(param_1,param_2,param_3,param_4);
  FUN_1100ac0c((uint)param_4);
  return uVar1;
}


// ---- 11008a4e FUN_11008a4e  (called by: FUN_11008a1f@11008a1f)

uint __cdecl FUN_11008a4e(char *param_1,uint param_2,uint param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  piVar1 = param_4;
  piVar6 = (int *)(param_2 * param_3);
  if (piVar6 == (int *)0x0) {
    param_3 = 0;
  }
  else {
    piVar5 = piVar6;
    if ((*(ushort *)(param_4 + 3) & 0x10c) == 0) {
      param_4 = (int *)0x1000;
    }
    else {
      param_4 = (int *)param_4[6];
    }
    do {
      if (((piVar1[3] & 0x108U) == 0) || (piVar7 = (int *)piVar1[1], piVar7 == (int *)0x0)) {
        if (param_4 <= piVar5) {
          if (((piVar1[3] & 0x108U) != 0) && (iVar2 = FUN_11008916(piVar1), iVar2 != 0)) {
LAB_11008b4f:
            return (uint)((int)piVar6 - (int)piVar5) / param_2;
          }
          if (param_4 == (int *)0x0) {
            piVar7 = piVar5;
          }
          else {
            piVar7 = (int *)((int)piVar5 - (uint)piVar5 % (uint)param_4);
          }
          piVar3 = (int *)FUN_1100b169(piVar1[4],param_1,(DWORD)piVar7);
          if ((piVar3 == (int *)0xffffffff) ||
             (piVar5 = (int *)((int)piVar5 - (int)piVar3), piVar3 < piVar7)) {
            piVar1[3] = piVar1[3] | 0x20;
            goto LAB_11008b4f;
          }
          goto LAB_11008b06;
        }
        uVar4 = FUN_1100b359((int)*param_1,piVar1);
        if (uVar4 == 0xffffffff) goto LAB_11008b4f;
        param_1 = param_1 + 1;
        param_4 = (int *)piVar1[6];
        piVar5 = (int *)((int)piVar5 - 1);
        if ((int)param_4 < 1) {
          param_4 = (int *)0x1;
        }
      }
      else {
        piVar3 = piVar5;
        if (piVar7 <= piVar5) {
          piVar3 = piVar7;
        }
        FUN_11009690((undefined4 *)*piVar1,(undefined4 *)param_1,(uint)piVar3);
        piVar1[1] = piVar1[1] - (int)piVar3;
        *piVar1 = *piVar1 + (int)piVar3;
        piVar5 = (int *)((int)piVar5 - (int)piVar3);
LAB_11008b06:
        param_1 = param_1 + (int)piVar3;
      }
    } while (piVar5 != (int *)0x0);
  }
  return param_3;
}


// ---- 11008b58 FUN_11008b58  (called by: FUN_11008b89@11008b89)

undefined4 * __cdecl FUN_11008b58(LPCSTR param_1,char *param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = FUN_1100b5e1();
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2 = FUN_1100b471(param_1,param_2,param_3,puVar1);
  FUN_1100ac0c((uint)puVar1);
  return puVar2;
}


// ---- 11008b89 FUN_11008b89  (called by: FUN_11001106@11001106, FUN_11005fe6@11005fe6, FUN_1100631d@1100631d, FUN_11006491@11006491, FUN_11006737@11006737, FUN_11006887@11006887)

void __cdecl FUN_11008b89(LPCSTR param_1,char *param_2)

{
  FUN_11008b58(param_1,param_2,0x40);
  return;
}


// ---- 11008ba0 FUN_11008ba0  (called by: FUN_11001106@11001106, FUN_110083a5@110083a5, FUN_1100e5c5@1100e5c5, FUN_1100e814@1100e814, FUN_1100eae7@1100eae7)

/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_11008ba0(undefined1 param_1)

{
  uint in_EAX;
  undefined1 *puVar1;
  undefined4 unaff_retaddr;
  
  puVar1 = &param_1;
  for (; 0xfff < in_EAX; in_EAX = in_EAX - 0x1000) {
    puVar1 = puVar1 + -0x1000;
  }
  *(undefined4 *)(puVar1 + (-4 - in_EAX)) = unaff_retaddr;
  return;
}


// ---- 11008bcf FUN_11008bcf  (called by: FUN_1100bab2@1100bab2)

void FUN_11008bcf(undefined *UNRECOVERED_JUMPTABLE)

{
  ExceptionList = *(void **)ExceptionList;
                    /* WARNING: Could not recover jumptable at 0x11008bfa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


// ---- 11008c03 FUN_11008c03  (called by: FUN_1100bc72@1100bc72, FUN_1100be36@1100be36)

void FUN_11008c03(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x11008c08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


// ---- 11008c0a FUN_11008c0a  (called by: FUN_1100bc72@1100bc72)

void FUN_11008c0a(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x11008c0f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


// ---- 11008c11 FUN_11008c11  (called by: FUN_11008dc5@11008dc5, FUN_1100bab2@1100bab2)

void FUN_11008c11(PVOID param_1,PEXCEPTION_RECORD param_2)

{
  void *pvVar1;
  
  pvVar1 = ExceptionList;
  RtlUnwind(param_1,(PVOID)0x11008c39,param_2,(PVOID)0x0);
  param_2->ExceptionFlags = param_2->ExceptionFlags & 0xfffffffd;
  *(void **)pvVar1 = ExceptionList;
  ExceptionList = pvVar1;
  return;
}


// ---- 11008c60 FUN_11008c60  (called by: FUN_1100f349@1100f349, FUN_1100f552@1100f552, FUN_1100f769@1100f769, FUN_1100f7aa@1100f7aa, FUN_1100f7d8@1100f7d8, FUN_1100f7ed@1100f7ed, FUN_1100f80a@1100f80a, FUN_1100f81d@1100f81d, FUN_1100f843@1100f843, FUN_1100f859@1100f859, FUN_1100f86d@1100f86d, FUN_1100f935@1100f935, FUN_1100f940@1100f940, FUN_1100f959@1100f959, FUN_1100f970@1100f970)

undefined4 __cdecl
FUN_11008c60(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  int *in_EAX;
  undefined4 uVar1;
  
  uVar1 = FUN_1100b6a9(param_1,param_2,param_3,param_4,in_EAX,0,(PVOID)0x0,'\0');
  return uVar1;
}


// ---- 11008c96 FUN_11008c96  (called by: FUN_1100bb2d@1100bb2d)

undefined4 __cdecl
FUN_11008c96(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  void *local_18;
  code *local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  local_10 = param_2;
  local_14 = FUN_11008cea;
  local_8 = param_4 + 1;
  local_c = param_1;
  local_18 = ExceptionList;
  ExceptionList = &local_18;
  uVar1 = __CallSettingFrame_12(param_3,param_1,param_5);
  ExceptionList = local_18;
  return uVar1;
}


// ---- 11008cea FUN_11008cea  (called by: -)

void __cdecl FUN_11008cea(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3)

{
  FUN_1100b6a9(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),param_2,'\0');
  return;
}


// ---- 11008d0f FUN_11008d0f  (called by: FUN_1100b8f7@1100b8f7)

undefined4 __cdecl
FUN_11008d0f(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  DWORD *pDVar1;
  undefined1 auStackY_cc [128];
  undefined4 uVar2;
  undefined4 **ppuVar3;
  undefined4 *local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  code *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 *local_10;
  undefined1 *local_c;
  undefined4 local_8;
  
  local_c = auStackY_cc + 200;
  local_10 = auStackY_cc + 0x88;
  local_28 = FUN_11008dc5;
  local_24 = param_5;
  local_20 = param_2;
  local_1c = param_6;
  local_18 = param_7;
  local_8 = 0;
  local_14 = 0x11008d97;
  local_2c = ExceptionList;
  ExceptionList = &local_2c;
  local_34 = param_1;
  local_30 = param_3;
  ppuVar3 = &local_34;
  uVar2 = *param_1;
  pDVar1 = FUN_1100bf91();
  (*(code *)pDVar1[0x1a])(uVar2,ppuVar3);
  if (local_8 != 0) {
    *local_2c = *(undefined4 *)ExceptionList;
  }
  ExceptionList = local_2c;
  return 0;
}


// ---- 11008dc5 FUN_11008dc5  (called by: -)

undefined4 __cdecl FUN_11008dc5(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3)

{
  undefined4 uVar1;
  
  if ((param_1->ExceptionFlags & 0x66) != 0) {
    *(undefined4 *)((int)param_2 + 0x24) = 1;
    return 1;
  }
  FUN_1100b6a9(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),*(PVOID *)((int)param_2 + 0x14),'\x01');
  if (*(int *)((int)param_2 + 0x24) == 0) {
    FUN_11008c11(param_2,param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x11008e2f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)((int)param_2 + 0x18))();
  return uVar1;
}


// ---- 11008e3a FUN_11008e3a  (called by: FUN_1100b744@1100b744, FUN_1100b8f7@1100b8f7)

int __cdecl FUN_11008e3a(uint param_1,int param_2,int param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint local_8;
  
  uVar2 = param_1;
  local_8 = *(uint *)(param_1 + 0xc);
  iVar1 = *(int *)(param_1 + 0x10);
  uVar3 = local_8;
  param_1 = local_8;
  if (-1 < param_2) {
    do {
      if (uVar3 == 0xffffffff) {
        FUN_1100c0f9();
      }
      uVar3 = uVar3 - 1;
      if (((*(int *)(iVar1 + 4 + uVar3 * 0x14) < param_3) &&
          (param_3 <= *(int *)(iVar1 + uVar3 * 0x14 + 8))) || (uVar3 == 0xffffffff)) {
        param_2 = param_2 + -1;
        local_8 = param_1;
        param_1 = uVar3;
      }
    } while (-1 < param_2);
  }
  uVar3 = uVar3 + 1;
  *param_4 = uVar3;
  *param_5 = local_8;
  if ((*(uint *)(uVar2 + 0xc) < local_8) || (local_8 < uVar3)) {
    FUN_1100c0f9();
  }
  return iVar1 + uVar3 * 0x14;
}


// ---- 11008eb8 __global_unwind2  (called by: FUN_1100e32c@1100e32c)

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x11008ed0,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}


// ---- 11008ed8 FUN_11008ed8  (called by: -)

undefined4 FUN_11008ed8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((*(uint *)(param_1 + 4) & 6) != 0) {
    *param_4 = param_2;
    uVar1 = 3;
  }
  return uVar1;
}


// ---- 11008efa __local_unwind2  (called by: FUN_1100e32c@1100e32c, FUN_1100e3e9@1100e3e9)

/* Library Function - Single Match
    __local_unwind2
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
   Studio 2003 Release */

void __cdecl __local_unwind2(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  void *pvStack_1c;
  code *pcStack_18;
  undefined4 local_14;
  int iStack_10;
  
  iStack_10 = param_1;
  pcStack_18 = FUN_11008ed8;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_11008f8e();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  ExceptionList = pvStack_1c;
  return;
}


// ---- 11008f62 __abnormal_termination  (called by: FUN_1100bbfa@1100bbfa)

/* Library Function - Single Match
    __abnormal_termination
   
   Library: Visual Studio */

int __cdecl __abnormal_termination(void)

{
  int iVar1;
  
  iVar1 = 0;
  if ((*(code **)((int)ExceptionList + 4) == FUN_11008ed8) &&
     (*(int *)((int)ExceptionList + 8) == *(int *)(*(int *)((int)ExceptionList + 0xc) + 0xc))) {
    iVar1 = 1;
  }
  return iVar1;
}


// ---- 11008f85 __NLG_Notify1  (called by: __CallSettingFrame@12@1100bec0)

/* Library Function - Single Match
    __NLG_Notify1
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __fastcall __NLG_Notify1(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;
  
  DAT_11015598 = param_1;
  DAT_11015594 = in_EAX;
  DAT_1101559c = unaff_EBP;
  return;
}


// ---- 11008f8e FUN_11008f8e  (called by: FUN_1100e32c@1100e32c, __local_unwind2@11008efa)

void FUN_11008f8e(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_11015598 = *(undefined4 *)(unaff_EBP + 8);
  DAT_11015594 = in_EAX;
  DAT_1101559c = unaff_EBP;
  return;
}


// ---- 11008fa8 FUN_11008fa8  (called by: FUN_11001448@11001448, FUN_11001610@11001610, FUN_110017de@110017de, FUN_11001b31@11001b31, FUN_11001e9b@11001e9b, FUN_110021fa@110021fa, FUN_11002435@11002435, FUN_11002b0b@11002b0b, FUN_1100378f@1100378f, FUN_110041e5@110041e5, FUN_1100451e@1100451e, FUN_11004dac@11004dac, FUN_11006737@11006737)

void FUN_11008fa8(void)

{
  undefined1 auStack_c [12];
  
  ExceptionList = auStack_c;
  return;
}


// ---- 11008fc7 FUN_11008fc7  (called by: FUN_11009045@11009045)

int __cdecl FUN_11008fc7(int param_1)

{
  SIZE_T SVar1;
  int *piVar2;
  
  FUN_11009cab();
  SVar1 = FUN_1100c14f(DAT_1101b22c);
  if (SVar1 < (uint)((int)DAT_1101b228 + (4 - (int)DAT_1101b22c))) {
    SVar1 = FUN_1100c14f(DAT_1101b22c);
    piVar2 = FUN_11009208(DAT_1101b22c,(uint *)(SVar1 + 0x10));
    if (piVar2 == (int *)0x0) {
      param_1 = 0;
      goto LAB_1100903c;
    }
    DAT_1101b228 = piVar2 + ((int)DAT_1101b228 - (int)DAT_1101b22c >> 2);
    DAT_1101b22c = piVar2;
  }
  *DAT_1101b228 = param_1;
  DAT_1101b228 = DAT_1101b228 + 1;
LAB_1100903c:
  FUN_11009cb4();
  return param_1;
}


// ---- 11009045 FUN_11009045  (called by: FUN_11001604@11001604, FUN_1100833b@1100833b)

int __cdecl FUN_11009045(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_11008fc7(param_1);
  return (iVar1 != 0) - 1;
}


// ---- 11009086 FUN_11009086  (called by: FUN_1100690b@1100690b, FUN_11006bd1@11006bd1, FUN_11008456@11008456, InitMap@11004a36)

void __cdecl FUN_11009086(LPVOID param_1)

{
  FUN_110085b8(param_1);
  return;
}


// ---- 11009091 operator_new  (called by: FUN_1100690b@1100690b, InitMap@11004a36)

/* Library Function - Single Match
    void * __cdecl operator new(unsigned int)
   
   Library: Visual Studio 2003 Release */

void * __cdecl operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(param_1,1);
  return pvVar1;
}


// ---- 1100909f FUN_1100909f  (called by: FUN_110064db@110064db, FUN_110064f3@110064f3, FUN_11006737@11006737, FUN_11006887@11006887, FUN_1100690b@1100690b)

uint __cdecl FUN_1100909f(char *param_1,uint param_2,uint param_3,int *param_4)

{
  uint uVar1;
  
  FUN_1100abba((uint)param_4);
  uVar1 = FUN_110090ce(param_1,param_2,param_3,param_4);
  FUN_1100ac0c((uint)param_4);
  return uVar1;
}


// ---- 110090ce FUN_110090ce  (called by: FUN_1100909f@1100909f)

uint __cdecl FUN_110090ce(char *param_1,uint param_2,uint param_3,int *param_4)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  piVar1 = param_4;
  pcVar6 = (char *)(param_2 * param_3);
  if (pcVar6 == (char *)0x0) {
    return 0;
  }
  pcVar5 = param_1;
  param_1 = pcVar6;
  if ((*(ushort *)(param_4 + 3) & 0x10c) == 0) {
    param_4 = (int *)0x1000;
  }
  else {
    param_4 = (int *)param_4[6];
  }
  do {
    if (((*(ushort *)(piVar1 + 3) & 0x10c) == 0) ||
       (pcVar2 = (char *)piVar1[1], pcVar2 == (char *)0x0)) {
      if (param_1 < param_4) {
        uVar4 = FUN_1100c194(piVar1);
        if (uVar4 == 0xffffffff) goto LAB_110091aa;
        *pcVar5 = (char)uVar4;
        param_4 = (int *)piVar1[6];
        pcVar5 = pcVar5 + 1;
        param_1 = param_1 + -1;
      }
      else {
        pcVar2 = param_1;
        if (param_4 != (int *)0x0) {
          pcVar2 = param_1 + -((uint)param_1 % (uint)param_4);
        }
        iVar3 = FUN_1100c270(piVar1[4],pcVar5,pcVar2);
        if (iVar3 == 0) {
          piVar1[3] = piVar1[3] | 0x10;
LAB_110091aa:
          return (uint)((int)pcVar6 - (int)param_1) / param_2;
        }
        if (iVar3 == -1) {
          piVar1[3] = piVar1[3] | 0x20;
          goto LAB_110091aa;
        }
        param_1 = param_1 + -iVar3;
        pcVar5 = pcVar5 + iVar3;
      }
    }
    else {
      pcVar7 = param_1;
      if (pcVar2 <= param_1) {
        pcVar7 = pcVar2;
      }
      FUN_11009690((undefined4 *)pcVar5,(undefined4 *)*piVar1,(uint)pcVar7);
      param_1 = param_1 + -(int)pcVar7;
      piVar1[1] = piVar1[1] - (int)pcVar7;
      *piVar1 = (int)(pcVar7 + *piVar1);
      pcVar5 = pcVar5 + (int)pcVar7;
    }
    if (param_1 == (char *)0x0) {
      return param_3;
    }
  } while( true );
}


// ---- 110091b6 FUN_110091b6  (called by: Catch@11006829@11006829)

int __cdecl FUN_110091b6(undefined1 *param_1,byte *param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 *local_24;
  int local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  
  local_1c = param_1;
  local_24 = param_1;
  local_18 = 0x42;
  local_20 = 0x7fffffff;
  iVar1 = FUN_1100c4ae((int *)&local_24,param_2,&param_3);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    FUN_1100b359(0,(int *)&local_24);
  }
  else {
    *local_24 = 0;
  }
  return iVar1;
}


// ---- 11009208 FUN_11009208  (called by: FUN_11006b64@11006b64, FUN_11008fc7@11008fc7)

int * __cdecl FUN_11009208(int *param_1,uint *param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  
  if (param_1 == (int *)0x0) {
    piVar1 = _malloc((size_t)param_2);
  }
  else {
    if (param_2 == (uint *)0x0) {
      FUN_110085b8(param_1);
    }
    else {
      do {
        if (param_2 < (uint *)0xffffffe1) {
          FUN_11009f49(9);
          puVar2 = (uint *)FUN_11009ffd((int)param_1);
          if (puVar2 == (uint *)0x0) {
            FUN_11009faa(9);
            if (param_2 == (uint *)0x0) {
              param_2 = (uint *)0x1;
            }
            param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
            piVar1 = HeapReAlloc(DAT_1101b21c,0,param_1,(SIZE_T)param_2);
          }
          else {
            if (DAT_11015674 < param_2) {
LAB_110092a7:
              if (param_2 == (uint *)0x0) {
                param_2 = (uint *)0x1;
              }
              param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
              piVar1 = HeapAlloc(DAT_1101b21c,0,(SIZE_T)param_2);
              if (piVar1 != (int *)0x0) {
                puVar4 = (uint *)(param_1[-1] - 1U);
                if (param_2 <= (uint *)(param_1[-1] - 1U)) {
                  puVar4 = param_2;
                }
                FUN_11009690(piVar1,param_1,(uint)puVar4);
                FUN_1100a028(puVar2,(uint)param_1);
              }
            }
            else {
              iVar3 = FUN_1100a808(puVar2,(int)param_1,(int)param_2);
              if (iVar3 == 0) {
                piVar1 = FUN_1100a353(param_2);
                if (piVar1 == (int *)0x0) goto LAB_110092a7;
                puVar4 = (uint *)(param_1[-1] - 1U);
                if (param_2 <= (uint *)(param_1[-1] - 1U)) {
                  puVar4 = param_2;
                }
                FUN_11009690(piVar1,param_1,(uint)puVar4);
                FUN_1100a028(puVar2,(uint)param_1);
              }
              else {
                piVar1 = param_1;
              }
              if (piVar1 == (int *)0x0) goto LAB_110092a7;
            }
            FUN_11009faa(9);
          }
          if (piVar1 != (int *)0x0) {
            return piVar1;
          }
        }
        if (DAT_11019b70 == 0) {
          return (int *)0x0;
        }
        iVar3 = FUN_11009de8(param_2);
      } while (iVar3 != 0);
    }
    piVar1 = (int *)0x0;
  }
  return piVar1;
}


// ---- 11009340 FUN_11009340  (called by: FUN_11006c0c@11006c0c, FUN_11006c74@11006c74, FUN_1100d1b3@1100d1b3, FUN_1100d624@1100d624)

uint * __cdecl FUN_11009340(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = param_1;
  while (((uint)param_2 & 3) != 0) {
    bVar1 = (byte)*param_2;
    uVar3 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_11009428;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_11009428:
        *(byte *)puVar4 = (byte)uVar3;
        return param_1;
      }
      if ((char)(uVar3 >> 8) == '\0') {
        *(short *)puVar4 = (short)uVar3;
        return param_1;
      }
      if ((uVar3 & 0xff0000) == 0) {
        *(short *)puVar4 = (short)uVar3;
        *(byte *)((int)puVar4 + 2) = 0;
        return param_1;
      }
      if ((uVar3 & 0xff000000) == 0) {
        *puVar4 = uVar3;
        return param_1;
      }
    }
    *puVar4 = uVar3;
    puVar4 = puVar4 + 1;
  } while( true );
}


// ---- 11009350 FUN_11009350  (called by: FUN_11006c74@11006c74, FUN_1100d624@1100d624)

uint * __cdecl FUN_11009350(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_1100936c;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_1100939f;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x110093bb;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_1100936c:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x110093bb;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x110093bb;
    }
  }
LAB_1100939f:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x110093bb:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_11009428:
            *(byte *)puVar5 = (byte)uVar4;
            return param_1;
          }
          if ((char)(uVar4 >> 8) == '\0') {
            *(short *)puVar5 = (short)uVar4;
            return param_1;
          }
          if ((uVar4 & 0xff0000) == 0) {
            *(short *)puVar5 = (short)uVar4;
            *(byte *)((int)puVar5 + 2) = 0;
            return param_1;
          }
          if ((uVar4 & 0xff000000) == 0) {
            *puVar5 = uVar4;
            return param_1;
          }
        }
        *puVar5 = uVar4;
        puVar5 = puVar5 + 1;
      } while( true );
    }
    bVar1 = (byte)*param_2;
    uVar4 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_11009428;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}


// ---- 11009430 FUN_11009430  (called by: FUN_11006c0c@11006c0c)

void __cdecl FUN_11009430(byte *param_1,byte *param_2,byte *param_3,byte *param_4,byte *param_5)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  if ((param_2 != (byte *)0x0) && (*param_2 != 0)) {
    *param_1 = *param_2;
    param_1[1] = 0x3a;
    param_1 = param_1 + 2;
  }
  if (param_3 != (byte *)0x0) {
    bVar1 = *param_3;
    pbVar2 = param_3;
    if (bVar1 != 0) {
      do {
        pbVar3 = param_1;
        *pbVar3 = bVar1;
        bVar1 = pbVar2[1];
        param_1 = pbVar3 + 1;
        pbVar2 = pbVar2 + 1;
      } while (bVar1 != 0);
      pbVar2 = FUN_1100ccb8(param_3,pbVar2);
      if ((*pbVar2 != 0x2f) && (*pbVar2 != 0x5c)) {
        *param_1 = 0x5c;
        param_1 = pbVar3 + 2;
      }
    }
  }
  if (param_4 != (byte *)0x0) {
    bVar1 = *param_4;
    while (bVar1 != 0) {
      *param_1 = bVar1;
      pbVar2 = param_4 + 1;
      param_1 = param_1 + 1;
      param_4 = param_4 + 1;
      bVar1 = *pbVar2;
    }
  }
  if (param_5 == (byte *)0x0) {
    *param_1 = 0;
  }
  else {
    if ((*param_5 != 0) && (*param_5 != 0x2e)) {
      *param_1 = 0x2e;
      param_1 = param_1 + 1;
    }
    do {
      bVar1 = *param_5;
      *param_1 = bVar1;
      param_1 = param_1 + 1;
      param_5 = param_5 + 1;
    } while (bVar1 != 0);
  }
  return;
}


// ---- 110094c1 FUN_110094c1  (called by: FUN_11006c0c@11006c0c)

void __cdecl FUN_110094c1(byte *param_1,byte *param_2,byte *param_3,byte *param_4,byte *param_5)

{
  byte bVar1;
  size_t sVar2;
  byte *pbVar3;
  byte *local_8;
  
  local_8 = (byte *)0x0;
  sVar2 = _strlen((char *)param_1);
  if ((sVar2 == 0) || (param_1[1] != 0x3a)) {
    pbVar3 = param_1;
    if (param_2 != (byte *)0x0) {
      *param_2 = 0;
    }
  }
  else {
    if (param_2 != (byte *)0x0) {
      FUN_1100d119(param_2,param_1,2);
      param_2[2] = 0;
    }
    pbVar3 = param_1 + 2;
  }
  param_2 = (byte *)0x0;
  param_1 = pbVar3;
  if (*pbVar3 != 0) {
    do {
      bVar1 = *param_1;
      if ((*(byte *)((int)&DAT_11019fc0 + bVar1 + 1) & 4) == 0) {
        if ((bVar1 == 0x2f) || (bVar1 == 0x5c)) {
          param_2 = param_1 + 1;
        }
        else if (bVar1 == 0x2e) {
          local_8 = param_1;
        }
      }
      else {
        param_1 = param_1 + 1;
      }
      param_1 = param_1 + 1;
    } while (*param_1 != 0);
    if (param_2 != (byte *)0x0) {
      if (param_3 != (byte *)0x0) {
        sVar2 = (int)param_2 - (int)pbVar3;
        if (0xfe < sVar2) {
          sVar2 = 0xff;
        }
        FUN_1100d119(param_3,pbVar3,sVar2);
        param_3[sVar2] = 0;
      }
      pbVar3 = param_2;
      goto LAB_11009588;
    }
  }
  if (param_3 != (byte *)0x0) {
    *param_3 = 0;
  }
LAB_11009588:
  if ((local_8 == (byte *)0x0) || (local_8 < pbVar3)) {
    if (param_4 != (byte *)0x0) {
      sVar2 = 0xff;
      if ((uint)((int)param_1 - (int)pbVar3) < 0xff) {
        sVar2 = (int)param_1 - (int)pbVar3;
      }
      FUN_1100d119(param_4,pbVar3,sVar2);
      param_4[sVar2] = 0;
    }
    if (param_5 != (byte *)0x0) {
      *param_5 = 0;
    }
  }
  else {
    if (param_4 != (byte *)0x0) {
      sVar2 = (int)local_8 - (int)pbVar3;
      if (0xfe < sVar2) {
        sVar2 = 0xff;
      }
      FUN_1100d119(param_4,pbVar3,sVar2);
      param_4[sVar2] = 0;
    }
    if (param_5 != (byte *)0x0) {
      sVar2 = 0xff;
      if ((uint)((int)param_1 - (int)local_8) < 0xff) {
        sVar2 = (int)param_1 - (int)local_8;
      }
      FUN_1100d119(param_5,local_8,sVar2);
      param_5[sVar2] = 0;
    }
  }
  return;
}


// ---- 11009610 _strlen  (called by: FUN_11006c74@11006c74, FUN_110094c1@110094c1, FUN_1100c4ae@1100c4ae, FUN_1100d1b3@1100d1b3, FUN_1100d624@1100d624)

/* Library Function - Single Match
    _strlen
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

size_t __cdecl _strlen(char *_Str)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar2 = (uint *)_Str;
  do {
    if (((uint)puVar2 & 3) == 0) goto LAB_11009630;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_11009663:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_11009630:
  do {
    do {
      puVar3 = puVar2;
      puVar2 = puVar3 + 1;
    } while (((*puVar3 ^ 0xffffffff ^ *puVar3 + 0x7efefeff) & 0x81010100) == 0);
    uVar1 = *puVar3;
    if ((char)uVar1 == '\0') {
      return (int)puVar3 - (int)_Str;
    }
    if ((char)(uVar1 >> 8) == '\0') {
      return (size_t)((int)puVar3 + (1 - (int)_Str));
    }
    if ((uVar1 & 0xff0000) == 0) {
      return (size_t)((int)puVar3 + (2 - (int)_Str));
    }
  } while ((uVar1 & 0xff000000) != 0);
  goto LAB_11009663;
}


// ---- 11009690 FUN_11009690  (called by: FUN_110070b6@110070b6, FUN_11008156@11008156, FUN_110083a5@110083a5, FUN_11008a4e@11008a4e, FUN_110090ce@110090ce, FUN_11009208@11009208, FUN_1100d4b9@1100d4b9, UninstallMusicHook@110082c1)

undefined4 * __cdecl FUN_11009690(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {
    puVar3 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar4 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = param_3 >> 2;
      uVar2 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return param_1;
        case 2:
          goto switchD_11009847_caseD_2;
        case 3:
          goto switchD_11009847_caseD_3;
        }
        goto switchD_11009847_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_11009847_caseD_0;
      case 1:
        goto switchD_11009847_caseD_1;
      case 2:
        goto switchD_11009847_caseD_2;
      case 3:
        goto switchD_11009847_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_11009847_caseD_2;
            case 3:
              goto switchD_11009847_caseD_3;
            }
            goto switchD_11009847_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_11009847_caseD_2;
            case 3:
              goto switchD_11009847_caseD_3;
            }
            goto switchD_11009847_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_11009847_caseD_2;
            case 3:
              goto switchD_11009847_caseD_3;
            }
            goto switchD_11009847_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_11009847_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_11009847_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_11009847_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_11009847_caseD_0:
    return param_1;
  }
  puVar3 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    uVar2 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return param_1;
      case 2:
        goto switchD_110096c5_caseD_2;
      case 3:
        goto switchD_110096c5_caseD_3;
      }
      goto switchD_110096c5_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_110096c5_caseD_0;
    case 1:
      goto switchD_110096c5_caseD_1;
    case 2:
      goto switchD_110096c5_caseD_2;
    case 3:
      goto switchD_110096c5_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (undefined4 *)((int)param_2 + 3);
        puVar3 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_110096c5_caseD_2;
          case 3:
            goto switchD_110096c5_caseD_3;
          }
          goto switchD_110096c5_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (undefined4 *)((int)param_2 + 2);
        puVar3 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_110096c5_caseD_2;
          case 3:
            goto switchD_110096c5_caseD_3;
          }
          goto switchD_110096c5_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_110096c5_caseD_2;
          case 3:
            goto switchD_110096c5_caseD_3;
          }
          goto switchD_110096c5_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = param_2[uVar1 - 7];
  case 6:
    puVar3[uVar1 - 6] = param_2[uVar1 - 6];
  case 5:
    puVar3[uVar1 - 5] = param_2[uVar1 - 5];
  case 4:
    puVar3[uVar1 - 4] = param_2[uVar1 - 4];
  case 3:
    puVar3[uVar1 - 3] = param_2[uVar1 - 3];
  case 2:
    puVar3[uVar1 - 2] = param_2[uVar1 - 2];
  case 1:
    puVar3[uVar1 - 1] = param_2[uVar1 - 1];
    param_2 = param_2 + uVar1;
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_110096c5_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_110096c5_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_110096c5_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_110096c5_caseD_0:
  return param_1;
}


// ---- 110099c5 FUN_110099c5  (called by: entry@11009a9e)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_110099c5(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 1) {
    DAT_11019b30 = GetVersion();
    iVar1 = FUN_11009e03(1);
    if (iVar1 != 0) {
      _DAT_11019b3c = DAT_11019b30 >> 8 & 0xff;
      _DAT_11019b38 = DAT_11019b30 & 0xff;
      DAT_11019b30 = DAT_11019b30 >> 0x10;
      _DAT_11019b34 = _DAT_11019b38 * 0x100 + _DAT_11019b3c;
      iVar1 = FUN_1100bf0c();
      if (iVar1 != 0) {
        DAT_1101b234 = GetCommandLineA();
        DAT_11019b1c = FUN_1100d4b9();
        FUN_1100aec6();
        FUN_1100d26c();
        FUN_1100d1b3();
        FUN_11009ba8();
        DAT_11019b18 = DAT_11019b18 + 1;
        goto LAB_11009a98;
      }
      FUN_11009e3f();
    }
LAB_11009a25:
    uVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      if (DAT_11019b18 < 1) goto LAB_11009a25;
      DAT_11019b18 = DAT_11019b18 + -1;
      if (DAT_11019b68 == 0) {
        FUN_11009bf7();
      }
      FUN_1100b082();
      FUN_1100bf60();
      FUN_11009e3f();
    }
    else if (param_2 == 3) {
      FUN_1100bff8((LPVOID)0x0);
    }
LAB_11009a98:
    uVar2 = 1;
  }
  return uVar2;
}


// ---- 11009a9e entry  (called by: -)

int entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2;
  if (param_2 == 0) {
    iVar2 = DAT_11019b18;
  }
  else {
    if ((param_2 != 1) && (param_2 != 2)) goto LAB_11009ae6;
    if ((DAT_1101b238 != (code *)0x0) &&
       (iVar2 = (*DAT_1101b238)(param_1,param_2,param_3), iVar2 == 0)) {
      return 0;
    }
    iVar2 = FUN_110099c5(param_1,param_2);
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_11009ae6:
  iVar2 = FUN_11005e63(param_1,param_2);
  if (param_2 == 1) {
    if (iVar2 != 0) {
      return iVar2;
    }
    FUN_110099c5(param_1,0);
  }
  if ((param_2 == 0) || (param_2 == 3)) {
    iVar3 = FUN_110099c5(param_1,param_2);
    param_2 = iVar2;
    if (iVar3 == 0) {
      param_2 = 0;
    }
    iVar2 = param_2;
    if ((param_2 != 0) && (DAT_1101b238 != (code *)0x0)) {
      iVar2 = (*DAT_1101b238)(param_1,iVar1,param_3);
    }
  }
  param_2 = iVar2;
  return param_2;
}


// ---- 11009b3b __amsg_exit  (called by: FUN_11009f49@11009f49, FUN_1100aec6@1100aec6, FUN_1100bf91@1100bf91, FUN_1100d1b3@1100d1b3, FUN_1100d26c@1100d26c, __fptrap@1100edcb)

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __amsg_exit(int param_1)

{
  if ((DAT_11019b24 == 1) || ((DAT_11019b24 == 0 && (DAT_11019b28 == 1)))) {
    FUN_1100d5eb();
  }
  FUN_1100d624(param_1);
  (*(code *)PTR___exit_110155a0)(0xff);
  return;
}


// ---- 11009b70 _strncmp  (called by: GetSaveRegions@11007be0)

/* Library Function - Single Match
    _strncmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  char cVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar5 = 0;
  if (_MaxCount != 0) {
    sVar3 = _MaxCount;
    pcVar6 = _Str1;
    do {
      if (sVar3 == 0) break;
      sVar3 = sVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    iVar4 = _MaxCount - sVar3;
    do {
      pcVar6 = _Str2;
      pcVar7 = _Str1;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = _Str1 + 1;
      pcVar6 = _Str2 + 1;
      cVar2 = *_Str1;
      cVar1 = *_Str2;
      _Str2 = pcVar6;
      _Str1 = pcVar7;
    } while (cVar1 == cVar2);
    uVar5 = 0;
    if ((byte)pcVar6[-1] <= (byte)pcVar7[-1]) {
      if (pcVar6[-1] == pcVar7[-1]) {
        return 0;
      }
      uVar5 = 0xfffffffe;
    }
    uVar5 = ~uVar5;
  }
  return uVar5;
}


// ---- 11009ba8 FUN_11009ba8  (called by: FUN_110099c5@110099c5)

void FUN_11009ba8(void)

{
  if (DAT_1101b230 != (code *)0x0) {
    (*DAT_1101b230)();
  }
  FUN_11009cbd((undefined4 *)&DAT_1101401c,(undefined4 *)&DAT_11014030);
  FUN_11009cbd((undefined4 *)&DAT_11014000,(undefined4 *)&DAT_11014018);
  return;
}


// ---- 11009bd5 FUN_11009bd5  (called by: FUN_11007fb0@11007fb0)

void __cdecl FUN_11009bd5(UINT param_1)

{
  FUN_11009c06(param_1,0,0);
  return;
}


// ---- 11009be6 __exit  (called by: FUN_1100e404@1100e404, FUN_1100ec0c@1100ec0c, __amsg_exit@11009b3b)

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __exit(int _Code)

{
  FUN_11009c06(_Code,1,0);
  return;
}


// ---- 11009bf7 FUN_11009bf7  (called by: FUN_110099c5@110099c5)

void FUN_11009bf7(void)

{
  FUN_11009c06(0,0,1);
  return;
}


// ---- 11009c06 FUN_11009c06  (called by: FUN_11009bd5@11009bd5, FUN_11009bf7@11009bf7, __exit@11009be6)

void __cdecl FUN_11009c06(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  FUN_11009cab();
  if (DAT_11019b6c == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  DAT_11019b68 = 1;
  DAT_11019b64 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_1101b22c != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_1101b228 - 4), DAT_1101b22c <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_1101b22c <= puVar1);
    }
    FUN_11009cbd((undefined4 *)&DAT_11014034,(undefined4 *)&DAT_1101403c);
  }
  FUN_11009cbd((undefined4 *)&DAT_11014040,(undefined4 *)&DAT_11014048);
  if (param_3 == 0) {
    DAT_11019b6c = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  FUN_11009cb4();
  return;
}


// ---- 11009cab FUN_11009cab  (called by: FUN_11008fc7@11008fc7, FUN_11009c06@11009c06)

void FUN_11009cab(void)

{
  FUN_11009f49(0xd);
  return;
}


// ---- 11009cb4 FUN_11009cb4  (called by: FUN_11008fc7@11008fc7, FUN_11009c06@11009c06)

void FUN_11009cb4(void)

{
  FUN_11009faa(0xd);
  return;
}


// ---- 11009cbd FUN_11009cbd  (called by: FUN_11009ba8@11009ba8, FUN_11009c06@11009c06)

void __cdecl FUN_11009cbd(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}


// ---- 11009ce0 _memcmp  (called by: FUN_11008156@11008156)

/* Library Function - Single Match
    _memcmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  uint *puVar7;
  uint *puVar8;
  bool bVar9;
  
  if (_Size != 0) {
    if ((((uint)_Buf1 | (uint)_Buf2) & 3) == 0) {
      uVar2 = _Size & 3;
      uVar5 = _Size >> 2;
      bVar9 = false;
      puVar7 = _Buf1;
      puVar8 = _Buf2;
      if (uVar5 != 0) {
        do {
          _Buf1 = puVar7;
          _Buf2 = puVar8;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          _Buf2 = puVar8 + 1;
          _Buf1 = puVar7 + 1;
          bVar9 = *puVar7 == *puVar8;
          puVar7 = _Buf1;
          puVar8 = _Buf2;
        } while (bVar9);
        if (!bVar9) {
          uVar2 = *(uint *)((int)_Buf1 + -4);
          uVar5 = *(uint *)((int)_Buf2 + -4);
          bVar9 = (byte)uVar2 < (byte)uVar5;
          if ((((byte)uVar2 == (byte)uVar5) &&
              (bVar4 = (byte)(uVar2 >> 8), bVar6 = (byte)(uVar5 >> 8), bVar9 = bVar4 < bVar6,
              bVar4 == bVar6)) &&
             (bVar4 = (byte)(uVar2 >> 0x10), bVar6 = (byte)(uVar5 >> 0x10), bVar9 = bVar4 < bVar6,
             bVar4 == bVar6)) {
            bVar9 = (byte)(uVar2 >> 0x18) < (byte)(uVar5 >> 0x18);
          }
          goto LAB_11009d5a;
        }
      }
      if (uVar2 != 0) {
        uVar5 = *(uint *)_Buf1;
        uVar1 = *(uint *)_Buf2;
        bVar9 = (byte)uVar5 < (byte)uVar1;
        if ((byte)uVar5 != (byte)uVar1) {
LAB_11009d5a:
          return (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        }
        iVar3 = 0;
        if (uVar2 != 1) {
          bVar6 = (byte)(uVar5 >> 8);
          bVar4 = (byte)(uVar1 >> 8);
          bVar9 = bVar6 < bVar4;
          if (bVar6 != bVar4) goto LAB_11009d5a;
          iVar3 = 0;
          if (uVar2 != 2) {
            bVar9 = (uVar5 & 0xff0000) < (uVar1 & 0xff0000);
            if ((uVar5 & 0xff0000) != (uVar1 & 0xff0000)) goto LAB_11009d5a;
            iVar3 = uVar2 - 3;
          }
        }
        return iVar3;
      }
    }
    else {
      if ((_Size & 1) == 0) goto LAB_11009d0d;
      bVar9 = *(byte *)_Buf1 < *(byte *)_Buf2;
      if (*(byte *)_Buf1 != *(byte *)_Buf2) goto LAB_11009d5a;
      _Buf1 = (void *)((int)_Buf1 + 1);
      _Buf2 = (void *)((int)_Buf2 + 1);
      for (_Size = _Size - 1; _Size != 0; _Size = _Size - 2) {
LAB_11009d0d:
        bVar9 = *(byte *)_Buf1 < *(byte *)_Buf2;
        if ((*(byte *)_Buf1 != *(byte *)_Buf2) ||
           (bVar9 = *(byte *)((int)_Buf1 + 1) < *(byte *)((int)_Buf2 + 1),
           *(byte *)((int)_Buf1 + 1) != *(byte *)((int)_Buf2 + 1))) goto LAB_11009d5a;
        _Buf2 = (void *)((int)_Buf2 + 2);
        _Buf1 = (void *)((int)_Buf1 + 2);
      }
    }
  }
  return 0;
}


// ---- 11009d90 _memset  (called by: FUN_110083a5@110083a5, FUN_1100dab5@1100dab5, FUN_1100e814@1100e814, FUN_1100eae7@1100eae7)

/* Library Function - Single Match
    _memset
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl _memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  size_t sVar3;
  uint *puVar4;
  
  if (_Size == 0) {
    return _Dst;
  }
  uVar1 = _Val & 0xff;
  puVar4 = _Dst;
  if (3 < _Size) {
    uVar2 = -(int)_Dst & 3;
    sVar3 = _Size;
    if (uVar2 != 0) {
      sVar3 = _Size - uVar2;
      do {
        *(undefined1 *)puVar4 = (undefined1)_Val;
        puVar4 = (uint *)((int)puVar4 + 1);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    uVar1 = uVar1 * 0x1010101;
    _Size = sVar3 & 3;
    uVar2 = sVar3 >> 2;
    if (uVar2 != 0) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      }
      if (_Size == 0) {
        return _Dst;
      }
    }
  }
  do {
    *(char *)puVar4 = (char)uVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    _Size = _Size - 1;
  } while (_Size != 0);
  return _Dst;
}


// ---- 11009de8 FUN_11009de8  (called by: FUN_11009208@11009208, FUN_1100dab5@1100dab5, __nh_malloc@1100853e)

undefined4 __cdecl FUN_11009de8(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_11019b74 != (code *)0x0) {
    iVar1 = (*DAT_11019b74)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


// ---- 11009e03 FUN_11009e03  (called by: FUN_110099c5@110099c5)

undefined4 __cdecl FUN_11009e03(int param_1)

{
  int iVar1;
  
  DAT_1101b21c = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (DAT_1101b21c != (HANDLE)0x0) {
    iVar1 = FUN_11009fbf();
    if (iVar1 != 0) {
      return 1;
    }
    HeapDestroy(DAT_1101b21c);
  }
  return 0;
}


// ---- 11009e3f FUN_11009e3f  (called by: FUN_110099c5@110099c5)

void FUN_11009e3f(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  if (0 < DAT_1101b214) {
    puVar2 = (undefined4 *)((int)DAT_1101b218 + 0xc);
    do {
      VirtualFree((LPVOID)*puVar2,0x100000,0x4000);
      VirtualFree((LPVOID)*puVar2,0,0x8000);
      HeapFree(DAT_1101b21c,0,(LPVOID)puVar2[1]);
      puVar2 = puVar2 + 5;
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_1101b214);
  }
  HeapFree(DAT_1101b21c,0,DAT_1101b218);
  HeapDestroy(DAT_1101b21c);
  return;
}


// ---- 11009eb4 FUN_11009eb4  (called by: FUN_1100bf0c@1100bf0c)

void FUN_11009eb4(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_110155f8);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_110155e8);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_110155d8);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_110155b8);
  return;
}


// ---- 11009edd FUN_11009edd  (called by: FUN_1100bf60@1100bf60)

void FUN_11009edd(void)

{
  undefined **ppuVar1;
  
  ppuVar1 = (undefined **)&DAT_110155b4;
  do {
    if (((((LPCRITICAL_SECTION)*ppuVar1 != (LPCRITICAL_SECTION)0x0) &&
         (ppuVar1 != &PTR_DAT_110155f8)) && (ppuVar1 != &PTR_DAT_110155e8)) &&
       ((ppuVar1 != &PTR_DAT_110155d8 && (ppuVar1 != &PTR_DAT_110155b8)))) {
      DeleteCriticalSection((LPCRITICAL_SECTION)*ppuVar1);
      FUN_110085b8(*ppuVar1);
    }
    ppuVar1 = ppuVar1 + 1;
  } while ((int)ppuVar1 < 0x11015674);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_110155d8);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_110155e8);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_110155f8);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_110155b8);
  return;
}


// ---- 11009f49 FUN_11009f49  (called by: FUN_1100856a@1100856a, FUN_110085b8@110085b8, FUN_1100897b@1100897b, FUN_11009208@11009208, FUN_11009cab@11009cab, FUN_11009f49@11009f49, FUN_1100abba@1100abba, FUN_1100abe9@1100abe9, FUN_1100b5e1@1100b5e1, FUN_1100c14f@1100c14f, FUN_1100ccb8@1100ccb8, FUN_1100cd25@1100cd25, FUN_1100d119@1100d119, FUN_1100dab5@1100dab5, FUN_1100dbc3@1100dbc3, FUN_1100de23@1100de23, FUN_1100e41b@1100e41b, FUN_1100ec0c@1100ec0c, FUN_1100eec0@1100eec0, FUN_1100ef90@1100ef90)

void __cdecl FUN_11009f49(int param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  piVar1 = &DAT_110155b4 + param_1;
  if ((&DAT_110155b4)[param_1] == 0) {
    lpCriticalSection = _malloc(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    FUN_11009f49(0x11);
    if (*piVar1 == 0) {
      InitializeCriticalSection(lpCriticalSection);
      *piVar1 = (int)lpCriticalSection;
    }
    else {
      FUN_110085b8(lpCriticalSection);
    }
    FUN_11009faa(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)*piVar1);
  return;
}


// ---- 11009faa FUN_11009faa  (called by: FUN_1100856a@1100856a, FUN_110085b8@110085b8, FUN_1100897b@1100897b, FUN_11009208@11009208, FUN_11009cb4@11009cb4, FUN_11009f49@11009f49, FUN_1100ac0c@1100ac0c, FUN_1100ac3b@1100ac3b, FUN_1100b5e1@1100b5e1, FUN_1100c14f@1100c14f, FUN_1100ccb8@1100ccb8, FUN_1100cd25@1100cd25, FUN_1100d119@1100d119, FUN_1100dab5@1100dab5, FUN_1100dbc3@1100dbc3, FUN_1100de23@1100de23, FUN_1100e41b@1100e41b, FUN_1100ec0c@1100ec0c, FUN_1100eec0@1100eec0, FUN_1100ef90@1100ef90)

void __cdecl FUN_11009faa(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_110155b4)[param_1]);
  return;
}


// ---- 11009fbf FUN_11009fbf  (called by: FUN_11009e03@11009e03)

undefined4 FUN_11009fbf(void)

{
  DAT_1101b218 = HeapAlloc(DAT_1101b21c,0,0x140);
  if (DAT_1101b218 == (LPVOID)0x0) {
    return 0;
  }
  DAT_1101b210 = 0;
  DAT_1101b214 = 0;
  DAT_1101b20c = DAT_1101b218;
  DAT_1101b204 = 0x10;
  return 1;
}


// ---- 11009ffd FUN_11009ffd  (called by: FUN_110085b8@110085b8, FUN_11009208@11009208, FUN_1100c14f@1100c14f)

uint __cdecl FUN_11009ffd(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_1101b218;
  while( true ) {
    if (DAT_1101b218 + DAT_1101b214 * 0x14 <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}


// ---- 1100a028 FUN_1100a028  (called by: FUN_110085b8@110085b8, FUN_11009208@11009208)

void __cdecl FUN_1100a028(uint *param_1,uint param_2)

{
  char *pcVar1;
  uint *puVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int local_10;
  
  uVar5 = param_1[4];
  iVar6 = *(int *)(param_2 - 4);
  piVar9 = (int *)(param_2 - 4);
  uVar10 = param_2 - param_1[3] >> 0xf;
  uVar7 = *(uint *)(param_2 - 8);
  local_10 = iVar6 + -1;
  piVar3 = (int *)(uVar10 * 0x204 + 0x144 + uVar5);
  uVar12 = *(uint *)(local_10 + (int)piVar9);
  if ((uVar12 & 1) == 0) {
    param_2 = ((int)uVar12 >> 4) - 1;
    if (0x3f < param_2) {
      param_2 = 0x3f;
    }
    if (*(int *)(iVar6 + 3 + (int)piVar9) == *(int *)(iVar6 + 7 + (int)piVar9)) {
      if (param_2 < 0x20) {
        pcVar1 = (char *)(param_2 + 4 + uVar5);
        uVar11 = ~(0x80000000U >> ((byte)param_2 & 0x1f));
        puVar2 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
        *puVar2 = *puVar2 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *param_1 = *param_1 & uVar11;
        }
      }
      else {
        pcVar1 = (char *)(param_2 + 4 + uVar5);
        uVar11 = ~(0x80000000U >> ((byte)param_2 - 0x20 & 0x1f));
        puVar2 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
        *puVar2 = *puVar2 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          param_1[1] = param_1[1] & uVar11;
        }
      }
    }
    *(undefined4 *)(*(int *)(iVar6 + 7 + (int)piVar9) + 4) =
         *(undefined4 *)(iVar6 + 3 + (int)piVar9);
    local_10 = local_10 + uVar12;
    *(undefined4 *)(*(int *)(iVar6 + 3 + (int)piVar9) + 8) =
         *(undefined4 *)(iVar6 + 7 + (int)piVar9);
  }
  uVar12 = (local_10 >> 4) - 1;
  if (0x3f < uVar12) {
    uVar12 = 0x3f;
  }
  if ((uVar7 & 1) == 0) {
    piVar9 = (int *)((int)piVar9 - uVar7);
    param_2 = ((int)uVar7 >> 4) - 1;
    if (0x3f < param_2) {
      param_2 = 0x3f;
    }
    local_10 = local_10 + uVar7;
    uVar12 = (local_10 >> 4) - 1;
    if (0x3f < uVar12) {
      uVar12 = 0x3f;
    }
    if (param_2 != uVar12) {
      if (piVar9[1] == piVar9[2]) {
        if (param_2 < 0x20) {
          pcVar1 = (char *)(param_2 + 4 + uVar5);
          uVar11 = ~(0x80000000U >> ((byte)param_2 & 0x1f));
          puVar2 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar11;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *param_1 = *param_1 & uVar11;
          }
        }
        else {
          pcVar1 = (char *)(param_2 + 4 + uVar5);
          uVar11 = ~(0x80000000U >> ((byte)param_2 - 0x20 & 0x1f));
          puVar2 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar11;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            param_1[1] = param_1[1] & uVar11;
          }
        }
      }
      *(int *)(piVar9[2] + 4) = piVar9[1];
      *(int *)(piVar9[1] + 8) = piVar9[2];
    }
  }
  if (((uVar7 & 1) != 0) || (param_2 != uVar12)) {
    piVar9[1] = piVar3[uVar12 * 2 + 1];
    piVar9[2] = (int)(piVar3 + uVar12 * 2);
    (piVar3 + uVar12 * 2)[1] = (int)piVar9;
    *(int **)(piVar9[1] + 8) = piVar9;
    if (piVar9[1] == piVar9[2]) {
      cVar4 = *(char *)(uVar12 + 4 + uVar5);
      *(char *)(uVar12 + 4 + uVar5) = cVar4 + '\x01';
      bVar8 = (byte)uVar12;
      if (uVar12 < 0x20) {
        if (cVar4 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
        }
        puVar2 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
        *puVar2 = *puVar2 | 0x80000000U >> (bVar8 & 0x1f);
      }
      else {
        if (cVar4 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
        }
        puVar2 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
        *puVar2 = *puVar2 | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
      }
    }
  }
  *piVar9 = local_10;
  *(int *)(local_10 + -4 + (int)piVar9) = local_10;
  *piVar3 = *piVar3 + -1;
  if (*piVar3 != 0) {
    return;
  }
  if (DAT_1101b210 != (uint *)0x0) {
    VirtualFree((LPVOID)(DAT_1101b208 * 0x8000 + DAT_1101b210[3]),0x8000,0x4000);
    DAT_1101b210[2] = DAT_1101b210[2] | 0x80000000U >> ((byte)DAT_1101b208 & 0x1f);
    *(undefined4 *)(DAT_1101b210[4] + 0xc4 + DAT_1101b208 * 4) = 0;
    *(char *)(DAT_1101b210[4] + 0x43) = *(char *)(DAT_1101b210[4] + 0x43) + -1;
    if (*(char *)(DAT_1101b210[4] + 0x43) == '\0') {
      DAT_1101b210[1] = DAT_1101b210[1] & 0xfffffffe;
    }
    if (DAT_1101b210[2] == 0xffffffff) {
      VirtualFree((LPVOID)DAT_1101b210[3],0,0x8000);
      HeapFree(DAT_1101b21c,0,(LPVOID)DAT_1101b210[4]);
      FUN_1100d780(DAT_1101b210,DAT_1101b210 + 5,
                   (DAT_1101b214 * 0x14 - (int)DAT_1101b210) + -0x14 + DAT_1101b218);
      DAT_1101b214 = DAT_1101b214 + -1;
      if (DAT_1101b210 < param_1) {
        param_1 = param_1 + -5;
      }
      DAT_1101b208 = uVar10;
      DAT_1101b20c = DAT_1101b218;
      DAT_1101b210 = param_1;
      return;
    }
  }
  DAT_1101b210 = param_1;
  DAT_1101b208 = uVar10;
  return;
}


// ---- 1100a353 FUN_1100a353  (called by: FUN_1100856a@1100856a, FUN_11009208@11009208, FUN_1100dab5@1100dab5)

int * __cdecl FUN_1100a353(uint *param_1)

{
  uint *puVar1;
  char *pcVar2;
  int *piVar3;
  char cVar4;
  int *piVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  int *piVar12;
  uint uVar13;
  uint local_10;
  uint local_c;
  int local_8;
  
  puVar10 = DAT_1101b218 + DAT_1101b214 * 5;
  uVar7 = (int)param_1 + 0x17U & 0xfffffff0;
  iVar8 = (int)((int)param_1 + 0x17U) >> 4;
  iVar9 = iVar8 + -1;
  if (iVar9 < 0x20) {
    local_10 = 0xffffffff >> ((byte)iVar9 & 0x1f);
    local_c = 0xffffffff;
  }
  else {
    local_c = 0xffffffff >> ((char)iVar8 - 0x21U & 0x1f);
    local_10 = 0;
  }
  for (param_1 = DAT_1101b20c;
      (param_1 < puVar10 && ((param_1[1] & local_c) == 0 && (*param_1 & local_10) == 0));
      param_1 = param_1 + 5) {
  }
  if (param_1 == puVar10) {
    for (param_1 = DAT_1101b218;
        (param_1 < DAT_1101b20c && ((param_1[1] & local_c) == 0 && (*param_1 & local_10) == 0));
        param_1 = param_1 + 5) {
    }
    if (param_1 == DAT_1101b20c) {
      for (; (param_1 < puVar10 && (param_1[2] == 0)); param_1 = param_1 + 5) {
      }
      if (param_1 == puVar10) {
        for (param_1 = DAT_1101b218; (param_1 < DAT_1101b20c && (param_1[2] == 0));
            param_1 = param_1 + 5) {
        }
        if ((param_1 == DAT_1101b20c) && (param_1 = FUN_1100a65c(), param_1 == (uint *)0x0)) {
          return (int *)0x0;
        }
      }
      iVar8 = FUN_1100a70d((int)param_1);
      *(int *)param_1[4] = iVar8;
      if (*(int *)param_1[4] == -1) {
        return (int *)0x0;
      }
    }
  }
  piVar5 = (int *)param_1[4];
  local_8 = *piVar5;
  if ((local_8 == -1) ||
     ((piVar5[local_8 + 0x31] & local_c) == 0 && (piVar5[local_8 + 0x11] & local_10) == 0)) {
    local_8 = 0;
    puVar10 = (uint *)(piVar5 + 0x11);
    if ((piVar5[0x31] & local_c) == 0 && (piVar5[0x11] & local_10) == 0) {
      do {
        puVar1 = puVar10 + 0x21;
        local_8 = local_8 + 1;
        puVar10 = puVar10 + 1;
      } while ((*puVar1 & local_c) == 0 && (local_10 & *puVar10) == 0);
    }
  }
  iVar8 = 0;
  piVar3 = piVar5 + local_8 * 0x81 + 0x51;
  local_10 = piVar5[local_8 + 0x11] & local_10;
  if (local_10 == 0) {
    local_10 = piVar5[local_8 + 0x31] & local_c;
    iVar8 = 0x20;
  }
  for (; -1 < (int)local_10; local_10 = local_10 << 1) {
    iVar8 = iVar8 + 1;
  }
  piVar12 = (int *)piVar3[iVar8 * 2 + 1];
  iVar11 = *piVar12 - uVar7;
  iVar9 = (iVar11 >> 4) + -1;
  if (0x3f < iVar9) {
    iVar9 = 0x3f;
  }
  DAT_1101b20c = param_1;
  if (iVar9 != iVar8) {
    if (piVar12[1] == piVar12[2]) {
      if (iVar8 < 0x20) {
        pcVar2 = (char *)((int)piVar5 + iVar8 + 4);
        uVar13 = ~(0x80000000U >> ((byte)iVar8 & 0x1f));
        piVar5[local_8 + 0x11] = uVar13 & piVar5[local_8 + 0x11];
        *pcVar2 = *pcVar2 + -1;
        if (*pcVar2 == '\0') {
          *param_1 = *param_1 & uVar13;
        }
      }
      else {
        pcVar2 = (char *)((int)piVar5 + iVar8 + 4);
        uVar13 = ~(0x80000000U >> ((byte)iVar8 - 0x20 & 0x1f));
        piVar5[local_8 + 0x31] = piVar5[local_8 + 0x31] & uVar13;
        *pcVar2 = *pcVar2 + -1;
        if (*pcVar2 == '\0') {
          param_1[1] = param_1[1] & uVar13;
        }
      }
    }
    *(int *)(piVar12[2] + 4) = piVar12[1];
    *(int *)(piVar12[1] + 8) = piVar12[2];
    if (iVar11 == 0) goto LAB_1100a619;
    piVar12[1] = piVar3[iVar9 * 2 + 1];
    piVar12[2] = (int)(piVar3 + iVar9 * 2);
    (piVar3 + iVar9 * 2)[1] = (int)piVar12;
    *(int **)(piVar12[1] + 8) = piVar12;
    if (piVar12[1] == piVar12[2]) {
      cVar4 = *(char *)(iVar9 + 4 + (int)piVar5);
      bVar6 = (byte)iVar9;
      if (iVar9 < 0x20) {
        *(char *)(iVar9 + 4 + (int)piVar5) = cVar4 + '\x01';
        if (cVar4 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> (bVar6 & 0x1f);
        }
        piVar5[local_8 + 0x11] = piVar5[local_8 + 0x11] | 0x80000000U >> (bVar6 & 0x1f);
      }
      else {
        *(char *)(iVar9 + 4 + (int)piVar5) = cVar4 + '\x01';
        if (cVar4 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> (bVar6 - 0x20 & 0x1f);
        }
        piVar5[local_8 + 0x31] = piVar5[local_8 + 0x31] | 0x80000000U >> (bVar6 - 0x20 & 0x1f);
      }
    }
  }
  if (iVar11 != 0) {
    *piVar12 = iVar11;
    *(int *)(iVar11 + -4 + (int)piVar12) = iVar11;
  }
LAB_1100a619:
  piVar12 = (int *)((int)piVar12 + iVar11);
  *piVar12 = uVar7 + 1;
  *(uint *)((int)piVar12 + (uVar7 - 4)) = uVar7 + 1;
  iVar8 = *piVar3;
  *piVar3 = iVar8 + 1;
  if (((iVar8 == 0) && (param_1 == DAT_1101b210)) && (local_8 == DAT_1101b208)) {
    DAT_1101b210 = (uint *)0x0;
  }
  *piVar5 = local_8;
  return piVar12 + 1;
}


// ---- 1100a65c FUN_1100a65c  (called by: FUN_1100a353@1100a353)

undefined4 * FUN_1100a65c(void)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  
  if (DAT_1101b214 == DAT_1101b204) {
    pvVar2 = HeapReAlloc(DAT_1101b21c,0,DAT_1101b218,(DAT_1101b204 * 5 + 0x50) * 4);
    if (pvVar2 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_1101b204 = DAT_1101b204 + 0x10;
    DAT_1101b218 = pvVar2;
  }
  puVar1 = (undefined4 *)((int)DAT_1101b218 + DAT_1101b214 * 0x14);
  pvVar2 = HeapAlloc(DAT_1101b21c,8,0x41c4);
  puVar1[4] = pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar1[3] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      puVar1[2] = 0xffffffff;
      *puVar1 = 0;
      puVar1[1] = 0;
      DAT_1101b214 = DAT_1101b214 + 1;
      *(undefined4 *)puVar1[4] = 0xffffffff;
      return puVar1;
    }
    HeapFree(DAT_1101b21c,0,(LPVOID)puVar1[4]);
  }
  return (undefined4 *)0x0;
}


// ---- 1100a70d FUN_1100a70d  (called by: FUN_1100a353@1100a353)

int __cdecl FUN_1100a70d(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  LPVOID pvVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *lpAddress;
  
  iVar3 = *(int *)(param_1 + 0x10);
  iVar9 = 0;
  for (iVar4 = *(int *)(param_1 + 8); -1 < iVar4; iVar4 = iVar4 << 1) {
    iVar9 = iVar9 + 1;
  }
  iVar8 = 0x3f;
  iVar4 = iVar9 * 0x204 + 0x144 + iVar3;
  iVar5 = iVar4;
  do {
    *(int *)(iVar5 + 8) = iVar5;
    *(int *)(iVar5 + 4) = iVar5;
    iVar5 = iVar5 + 8;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  lpAddress = (int *)(iVar9 * 0x8000 + *(int *)(param_1 + 0xc));
  pvVar6 = VirtualAlloc(lpAddress,0x8000,0x1000,4);
  if (pvVar6 == (LPVOID)0x0) {
    iVar9 = -1;
  }
  else {
    if (lpAddress <= lpAddress + 0x1c00) {
      piVar7 = lpAddress + 4;
      do {
        piVar7[-2] = -1;
        piVar7[0x3fb] = -1;
        piVar7[-1] = 0xff0;
        *piVar7 = (int)(piVar7 + 0x3ff);
        piVar7[1] = (int)(piVar7 + -0x401);
        piVar7[0x3fa] = 0xff0;
        piVar1 = piVar7 + 0x3fc;
        piVar7 = piVar7 + 0x400;
      } while (piVar1 <= lpAddress + 0x1c00);
    }
    *(int **)(iVar4 + 0x1fc) = lpAddress + 3;
    lpAddress[5] = iVar4 + 0x1f8;
    *(int **)(iVar4 + 0x200) = lpAddress + 0x1c03;
    lpAddress[0x1c04] = iVar4 + 0x1f8;
    *(undefined4 *)(iVar3 + 0x44 + iVar9 * 4) = 0;
    *(undefined4 *)(iVar3 + 0xc4 + iVar9 * 4) = 1;
    cVar2 = *(char *)(iVar3 + 0x43);
    *(char *)(iVar3 + 0x43) = cVar2 + '\x01';
    if (cVar2 == '\0') {
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;
    }
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & ~(0x80000000U >> ((byte)iVar9 & 0x1f));
  }
  return iVar9;
}


// ---- 1100a808 FUN_1100a808  (called by: FUN_11009208@11009208)

undefined4 __cdecl FUN_1100a808(uint *param_1,int param_2,int param_3)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint local_c;
  
  uVar5 = param_1[4];
  uVar11 = param_3 + 0x17U & 0xfffffff0;
  uVar9 = param_2 - param_1[3] >> 0xf;
  iVar3 = uVar9 * 0x204 + 0x144 + uVar5;
  iVar6 = *(int *)(param_2 + -4);
  iVar8 = iVar6 + -1;
  uVar12 = *(uint *)(iVar6 + -5 + param_2);
  iVar6 = iVar6 + -5 + param_2;
  if (iVar8 < (int)uVar11) {
    if (((uVar12 & 1) != 0) || ((int)(uVar12 + iVar8) < (int)uVar11)) {
      return 0;
    }
    local_c = ((int)uVar12 >> 4) - 1;
    if (0x3f < local_c) {
      local_c = 0x3f;
    }
    if (*(int *)(iVar6 + 4) == *(int *)(iVar6 + 8)) {
      if (local_c < 0x20) {
        pcVar1 = (char *)(local_c + 4 + uVar5);
        uVar10 = ~(0x80000000U >> ((byte)local_c & 0x1f));
        puVar7 = (uint *)(uVar5 + 0x44 + uVar9 * 4);
        *puVar7 = *puVar7 & uVar10;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *param_1 = *param_1 & uVar10;
        }
      }
      else {
        pcVar1 = (char *)(local_c + 4 + uVar5);
        uVar10 = ~(0x80000000U >> ((byte)local_c - 0x20 & 0x1f));
        puVar7 = (uint *)(uVar5 + 0xc4 + uVar9 * 4);
        *puVar7 = *puVar7 & uVar10;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          param_1[1] = param_1[1] & uVar10;
        }
      }
    }
    *(undefined4 *)(*(int *)(iVar6 + 8) + 4) = *(undefined4 *)(iVar6 + 4);
    *(undefined4 *)(*(int *)(iVar6 + 4) + 8) = *(undefined4 *)(iVar6 + 8);
    iVar6 = uVar12 + (iVar8 - uVar11);
    if (0 < iVar6) {
      uVar12 = (iVar6 >> 4) - 1;
      iVar8 = param_2 + -4 + uVar11;
      if (0x3f < uVar12) {
        uVar12 = 0x3f;
      }
      iVar3 = iVar3 + uVar12 * 8;
      *(undefined4 *)(iVar8 + 4) = *(undefined4 *)(iVar3 + 4);
      *(int *)(iVar8 + 8) = iVar3;
      *(int *)(iVar3 + 4) = iVar8;
      *(int *)(*(int *)(iVar8 + 4) + 8) = iVar8;
      if (*(int *)(iVar8 + 4) == *(int *)(iVar8 + 8)) {
        cVar4 = *(char *)(uVar12 + 4 + uVar5);
        *(char *)(uVar12 + 4 + uVar5) = cVar4 + '\x01';
        if (uVar12 < 0x20) {
          if (cVar4 == '\0') {
            *param_1 = *param_1 | 0x80000000U >> ((byte)uVar12 & 0x1f);
          }
          puVar7 = (uint *)(uVar5 + 0x44 + uVar9 * 4);
        }
        else {
          if (cVar4 == '\0') {
            param_1[1] = param_1[1] | 0x80000000U >> ((byte)uVar12 - 0x20 & 0x1f);
          }
          puVar7 = (uint *)(uVar5 + 0xc4 + uVar9 * 4);
          uVar12 = uVar12 - 0x20;
        }
        *puVar7 = *puVar7 | 0x80000000U >> ((byte)uVar12 & 0x1f);
      }
      piVar2 = (int *)(param_2 + -4 + uVar11);
      *piVar2 = iVar6;
      *(int *)(iVar6 + -4 + (int)piVar2) = iVar6;
    }
    *(uint *)(param_2 + -4) = uVar11 + 1;
    *(uint *)(param_2 + -8 + uVar11) = uVar11 + 1;
  }
  else if ((int)uVar11 < iVar8) {
    param_3 = iVar8 - uVar11;
    *(uint *)(param_2 + -4) = uVar11 + 1;
    piVar2 = (int *)(param_2 + -4 + uVar11);
    uVar10 = (param_3 >> 4) - 1;
    piVar2[-1] = uVar11 + 1;
    if (0x3f < uVar10) {
      uVar10 = 0x3f;
    }
    if ((uVar12 & 1) == 0) {
      uVar11 = ((int)uVar12 >> 4) - 1;
      if (0x3f < uVar11) {
        uVar11 = 0x3f;
      }
      if (*(int *)(iVar6 + 4) == *(int *)(iVar6 + 8)) {
        if (uVar11 < 0x20) {
          pcVar1 = (char *)(uVar11 + 4 + uVar5);
          uVar11 = ~(0x80000000U >> ((byte)uVar11 & 0x1f));
          puVar7 = (uint *)(uVar5 + 0x44 + uVar9 * 4);
          *puVar7 = *puVar7 & uVar11;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *param_1 = *param_1 & uVar11;
          }
        }
        else {
          pcVar1 = (char *)(uVar11 + 4 + uVar5);
          uVar11 = ~(0x80000000U >> ((byte)uVar11 - 0x20 & 0x1f));
          puVar7 = (uint *)(uVar5 + 0xc4 + uVar9 * 4);
          *puVar7 = *puVar7 & uVar11;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            param_1[1] = param_1[1] & uVar11;
          }
        }
      }
      *(undefined4 *)(*(int *)(iVar6 + 8) + 4) = *(undefined4 *)(iVar6 + 4);
      *(undefined4 *)(*(int *)(iVar6 + 4) + 8) = *(undefined4 *)(iVar6 + 8);
      param_3 = param_3 + uVar12;
      uVar10 = (param_3 >> 4) - 1;
      if (0x3f < uVar10) {
        uVar10 = 0x3f;
      }
    }
    iVar6 = iVar3 + uVar10 * 8;
    piVar2[1] = *(int *)(iVar3 + 4 + uVar10 * 8);
    piVar2[2] = iVar6;
    *(int **)(iVar6 + 4) = piVar2;
    *(int **)(piVar2[1] + 8) = piVar2;
    if (piVar2[1] == piVar2[2]) {
      cVar4 = *(char *)(uVar10 + 4 + uVar5);
      *(char *)(uVar10 + 4 + uVar5) = cVar4 + '\x01';
      if (uVar10 < 0x20) {
        if (cVar4 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> ((byte)uVar10 & 0x1f);
        }
        puVar7 = (uint *)(uVar5 + 0x44 + uVar9 * 4);
      }
      else {
        if (cVar4 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> ((byte)uVar10 - 0x20 & 0x1f);
        }
        puVar7 = (uint *)(uVar5 + 0xc4 + uVar9 * 4);
        uVar10 = uVar10 - 0x20;
      }
      *puVar7 = *puVar7 | 0x80000000U >> ((byte)uVar10 & 0x1f);
    }
    *piVar2 = param_3;
    *(int *)(param_3 + -4 + (int)piVar2) = param_3;
  }
  return 1;
}


// ---- 1100abba FUN_1100abba  (called by: FUN_11008600@11008600, FUN_1100867d@1100867d, FUN_11008736@11008736, FUN_110088b9@110088b9, FUN_11008a1f@11008a1f, FUN_1100909f@1100909f)

void __cdecl FUN_1100abba(uint param_1)

{
  if ((param_1 < 0x11015678) || (0x110158d8 < param_1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
    return;
  }
  FUN_11009f49(((int)(param_1 + 0xeefea988) >> 5) + 0x1c);
  return;
}


// ---- 1100abe9 FUN_1100abe9  (called by: FUN_1100897b@1100897b, FUN_1100b5e1@1100b5e1)

void __cdecl FUN_1100abe9(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_11009f49(param_1 + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}


// ---- 1100ac0c FUN_1100ac0c  (called by: FUN_11008600@11008600, FUN_1100867d@1100867d, FUN_11008736@11008736, FUN_110088b9@110088b9, FUN_11008a1f@11008a1f, FUN_11008b58@11008b58, FUN_1100909f@1100909f)

void __cdecl FUN_1100ac0c(uint param_1)

{
  if ((param_1 < 0x11015678) || (0x110158d8 < param_1)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
    return;
  }
  FUN_11009faa(((int)(param_1 + 0xeefea988) >> 5) + 0x1c);
  return;
}


// ---- 1100ac3b FUN_1100ac3b  (called by: FUN_1100897b@1100897b, FUN_1100b5e1@1100b5e1)

void __cdecl FUN_1100ac3b(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_11009faa(param_1 + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}


// ---- 1100ac5e FUN_1100ac5e  (called by: FUN_1100df11@1100df11, __fclose_lk@11008631)

undefined4 __cdecl FUN_1100ac5e(uint param_1)

{
  undefined4 uVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_1101a1e0) &&
     ((*(byte *)((&DAT_1101a0e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_1100de23(param_1);
    uVar1 = FUN_1100acbb(param_1);
    FUN_1100de82(param_1);
    return uVar1;
  }
  pDVar2 = FUN_1100addc();
  *pDVar2 = 9;
  pDVar2 = FUN_1100ade5();
  *pDVar2 = 0;
  return 0xffffffff;
}


// ---- 1100acbb FUN_1100acbb  (called by: FUN_1100ac5e@1100ac5e)

undefined4 __cdecl FUN_1100acbb(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  undefined4 uVar5;
  
  iVar1 = FUN_1100dde1(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_1100dde1(2);
      iVar2 = FUN_1100dde1(1);
      if (iVar2 == iVar1) goto LAB_1100ad09;
    }
    hObject = (HANDLE)FUN_1100dde1(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_1100ad0b;
    }
  }
LAB_1100ad09:
  DVar4 = 0;
LAB_1100ad0b:
  FUN_1100dd62(param_1);
  *(undefined1 *)((&DAT_1101a0e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = 0;
  if (DVar4 == 0) {
    uVar5 = 0;
  }
  else {
    FUN_1100ad69(DVar4);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}


// ---- 1100ad3e __freebuf  (called by: __fclose_lk@11008631)

/* Library Function - Single Match
    __freebuf
   
   Library: Visual Studio 2003 Release */

void __cdecl __freebuf(FILE *_File)

{
  if (((_File->_flag & 0x83U) != 0) && ((_File->_flag & 8U) != 0)) {
    FUN_110085b8(_File->_base);
    *(ushort *)&_File->_flag = (ushort)_File->_flag & 0xfbf7;
    _File->_ptr = (char *)0x0;
    _File->_base = (char *)0x0;
    _File->_cnt = 0;
  }
  return;
}


// ---- 1100ad69 FUN_1100ad69  (called by: FUN_1100acbb@1100acbb, FUN_1100ae53@1100ae53, FUN_1100b1ce@1100b1ce, FUN_1100c2d5@1100c2d5, FUN_1100df11@1100df11)

void __cdecl FUN_1100ad69(uint param_1)

{
  DWORD *pDVar1;
  uint *puVar2;
  int iVar3;
  
  pDVar1 = FUN_1100ade5();
  iVar3 = 0;
  *pDVar1 = param_1;
  puVar2 = &DAT_110158f8;
  do {
    if (param_1 == *puVar2) {
      pDVar1 = FUN_1100addc();
      *pDVar1 = *(DWORD *)(iVar3 * 8 + 0x110158fc);
      return;
    }
    puVar2 = puVar2 + 2;
    iVar3 = iVar3 + 1;
  } while ((int)puVar2 < 0x11015a60);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    pDVar1 = FUN_1100addc();
    *pDVar1 = 0xd;
    return;
  }
  if ((param_1 < 0xbc) || (0xca < param_1)) {
    pDVar1 = FUN_1100addc();
    *pDVar1 = 0x16;
    return;
  }
  pDVar1 = FUN_1100addc();
  *pDVar1 = 8;
  return;
}


// ---- 1100addc FUN_1100addc  (called by: FUN_110086a9@110086a9, FUN_11008758@11008758, FUN_1100ac5e@1100ac5e, FUN_1100ad69@1100ad69, FUN_1100adee@1100adee, FUN_1100ae53@1100ae53, FUN_1100b0d6@1100b0d6, FUN_1100b169@1100b169, FUN_1100b1ce@1100b1ce, FUN_1100c270@1100c270, FUN_1100c2d5@1100c2d5, FUN_1100dce6@1100dce6, FUN_1100dd62@1100dd62, FUN_1100dde1@1100dde1, FUN_1100df11@1100df11, FUN_1100e474@1100e474, FUN_1100eae7@1100eae7, FUN_1100edd4@1100edd4)

DWORD * FUN_1100addc(void)

{
  DWORD *pDVar1;
  
  pDVar1 = FUN_1100bf91();
  return pDVar1 + 2;
}


// ---- 1100ade5 FUN_1100ade5  (called by: FUN_1100ac5e@1100ac5e, FUN_1100ad69@1100ad69, FUN_1100adee@1100adee, FUN_1100b0d6@1100b0d6, FUN_1100b169@1100b169, FUN_1100b1ce@1100b1ce, FUN_1100c270@1100c270, FUN_1100c2d5@1100c2d5, FUN_1100dce6@1100dce6, FUN_1100dd62@1100dd62, FUN_1100dde1@1100dde1, FUN_1100df11@1100df11, FUN_1100eae7@1100eae7)

DWORD * FUN_1100ade5(void)

{
  DWORD *pDVar1;
  
  pDVar1 = FUN_1100bf91();
  return pDVar1 + 3;
}


// ---- 1100adee FUN_1100adee  (called by: FUN_110086a9@110086a9, FUN_11008758@11008758, FUN_1100b359@1100b359)

DWORD __cdecl FUN_1100adee(uint param_1,LONG param_2,DWORD param_3)

{
  DWORD DVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_1101a1e0) &&
     ((*(byte *)((&DAT_1101a0e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_1100de23(param_1);
    DVar1 = FUN_1100ae53(param_1,param_2,param_3);
    FUN_1100de82(param_1);
    return DVar1;
  }
  pDVar2 = FUN_1100addc();
  *pDVar2 = 9;
  pDVar2 = FUN_1100ade5();
  *pDVar2 = 0;
  return 0xffffffff;
}


// ---- 1100ae53 FUN_1100ae53  (called by: FUN_1100adee@1100adee, FUN_1100b1ce@1100b1ce, FUN_1100c2d5@1100c2d5, FUN_1100df11@1100df11, FUN_1100eae7@1100eae7)

DWORD __cdecl FUN_1100ae53(uint param_1,LONG param_2,DWORD param_3)

{
  byte *pbVar1;
  HANDLE hFile;
  DWORD *pDVar2;
  DWORD DVar3;
  uint uVar4;
  
  hFile = (HANDLE)FUN_1100dde1(param_1);
  if (hFile == (HANDLE)0xffffffff) {
    pDVar2 = FUN_1100addc();
    *pDVar2 = 9;
  }
  else {
    DVar3 = SetFilePointer(hFile,param_2,(PLONG)0x0,param_3);
    if (DVar3 == 0xffffffff) {
      uVar4 = GetLastError();
    }
    else {
      uVar4 = 0;
    }
    if (uVar4 == 0) {
      pbVar1 = (byte *)((&DAT_1101a0e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
      *pbVar1 = *pbVar1 & 0xfd;
      return DVar3;
    }
    FUN_1100ad69(uVar4);
  }
  return 0xffffffff;
}


// ---- 1100aec6 FUN_1100aec6  (called by: FUN_110099c5@110099c5)

void FUN_1100aec6(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  DWORD DVar4;
  HANDLE hFile;
  UINT *pUVar5;
  int iVar6;
  uint uVar7;
  UINT UVar8;
  _STARTUPINFOA local_4c;
  byte *local_8;
  
  puVar2 = _malloc(0x480);
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_1101a1e0 = 0x20;
  DAT_1101a0e0 = puVar2;
  for (; puVar2 < DAT_1101a0e0 + 0x120; puVar2 = puVar2 + 9) {
    *(undefined1 *)(puVar2 + 1) = 0;
    *puVar2 = 0xffffffff;
    puVar2[2] = 0;
    *(undefined1 *)((int)puVar2 + 5) = 10;
  }
  GetStartupInfoA(&local_4c);
  if ((local_4c.cbReserved2 != 0) && ((UINT *)local_4c.lpReserved2 != (UINT *)0x0)) {
    UVar8 = *(UINT *)local_4c.lpReserved2;
    pUVar5 = (UINT *)((int)local_4c.lpReserved2 + 4);
    local_8 = (byte *)((int)pUVar5 + UVar8);
    if (0x7ff < (int)UVar8) {
      UVar8 = 0x800;
    }
    if ((int)DAT_1101a1e0 < (int)UVar8) {
      puVar2 = &DAT_1101a0e4;
      do {
        puVar3 = _malloc(0x480);
        if (puVar3 == (undefined4 *)0x0) {
          UVar8 = DAT_1101a1e0;
          break;
        }
        DAT_1101a1e0 = DAT_1101a1e0 + 0x20;
        *puVar2 = puVar3;
        puVar1 = puVar3;
        for (; puVar3 < puVar1 + 0x120; puVar3 = puVar3 + 9) {
          *(undefined1 *)(puVar3 + 1) = 0;
          *puVar3 = 0xffffffff;
          puVar3[2] = 0;
          *(undefined1 *)((int)puVar3 + 5) = 10;
          puVar1 = (undefined4 *)*puVar2;
        }
        puVar2 = puVar2 + 1;
      } while ((int)DAT_1101a1e0 < (int)UVar8);
    }
    uVar7 = 0;
    if (0 < (int)UVar8) {
      do {
        if (((*(HANDLE *)local_8 != (HANDLE)0xffffffff) && ((*pUVar5 & 1) != 0)) &&
           (((*pUVar5 & 8) != 0 || (DVar4 = GetFileType(*(HANDLE *)local_8), DVar4 != 0)))) {
          puVar2 = (undefined4 *)((int)(&DAT_1101a0e0)[(int)uVar7 >> 5] + (uVar7 & 0x1f) * 0x24);
          *puVar2 = *(undefined4 *)local_8;
          *(byte *)(puVar2 + 1) = (byte)*pUVar5;
        }
        local_8 = local_8 + 4;
        uVar7 = uVar7 + 1;
        pUVar5 = (UINT *)((int)pUVar5 + 1);
      } while ((int)uVar7 < (int)UVar8);
    }
  }
  iVar6 = 0;
  do {
    puVar2 = DAT_1101a0e0 + iVar6 * 9;
    if (DAT_1101a0e0[iVar6 * 9] == -1) {
      *(undefined1 *)(puVar2 + 1) = 0x81;
      if (iVar6 == 0) {
        DVar4 = 0xfffffff6;
      }
      else {
        DVar4 = 0xfffffff5 - (iVar6 != 1);
      }
      hFile = GetStdHandle(DVar4);
      if ((hFile != (HANDLE)0xffffffff) && (DVar4 = GetFileType(hFile), DVar4 != 0)) {
        *puVar2 = hFile;
        if ((DVar4 & 0xff) != 2) {
          if ((DVar4 & 0xff) == 3) {
            *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 8;
          }
          goto LAB_1100b06b;
        }
      }
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x40;
    }
    else {
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x80;
    }
LAB_1100b06b:
    iVar6 = iVar6 + 1;
    if (2 < iVar6) {
      SetHandleCount(DAT_1101a1e0);
      return;
    }
  } while( true );
}


// ---- 1100b082 FUN_1100b082  (called by: FUN_110099c5@110099c5)

void FUN_1100b082(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint *puVar1;
  uint uVar2;
  
  puVar1 = &DAT_1101a0e0;
  do {
    uVar2 = *puVar1;
    if (uVar2 != 0) {
      if (uVar2 < uVar2 + 0x480) {
        lpCriticalSection = (LPCRITICAL_SECTION)(uVar2 + 0xc);
        do {
          if (lpCriticalSection[-1].SpinCount != 0) {
            DeleteCriticalSection(lpCriticalSection);
          }
          uVar2 = uVar2 + 0x24;
          lpCriticalSection = (LPCRITICAL_SECTION)&lpCriticalSection[1].OwningThread;
        } while (uVar2 < *puVar1 + 0x480);
      }
      FUN_110085b8((LPVOID)*puVar1);
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x1101a1e0);
  return;
}


// ---- 1100b0d6 FUN_1100b0d6  (called by: FUN_110088e8@110088e8)

undefined4 __cdecl FUN_1100b0d6(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  DWORD *pDVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (DAT_1101a1e0 <= param_1) {
LAB_1100b157:
    pDVar3 = FUN_1100addc();
    *pDVar3 = 9;
    return 0xffffffff;
  }
  iVar4 = (param_1 & 0x1f) * 0x24;
  if ((*(byte *)((&DAT_1101a0e0)[(int)param_1 >> 5] + 4 + iVar4) & 1) == 0) goto LAB_1100b157;
  FUN_1100de23(param_1);
  if ((*(byte *)((&DAT_1101a0e0)[(int)param_1 >> 5] + 4 + iVar4) & 1) != 0) {
    hFile = (HANDLE)FUN_1100dde1(param_1);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = 0;
    }
    uVar5 = 0;
    if (DVar2 == 0) goto LAB_1100b14c;
    pDVar3 = FUN_1100ade5();
    *pDVar3 = DVar2;
  }
  pDVar3 = FUN_1100addc();
  *pDVar3 = 9;
  uVar5 = 0xffffffff;
LAB_1100b14c:
  FUN_1100de82(param_1);
  return uVar5;
}


// ---- 1100b169 FUN_1100b169  (called by: FUN_11008916@11008916, FUN_11008a4e@11008a4e, FUN_1100b359@1100b359)

int __cdecl FUN_1100b169(uint param_1,char *param_2,DWORD param_3)

{
  int iVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_1101a1e0) &&
     ((*(byte *)((&DAT_1101a0e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_1100de23(param_1);
    iVar1 = FUN_1100b1ce(param_1,param_2,param_3);
    FUN_1100de82(param_1);
    return iVar1;
  }
  pDVar2 = FUN_1100addc();
  *pDVar2 = 9;
  pDVar2 = FUN_1100ade5();
  *pDVar2 = 0;
  return -1;
}


// ---- 1100b1ce FUN_1100b1ce  (called by: FUN_1100b169@1100b169, FUN_1100eae7@1100eae7)

int __cdecl FUN_1100b1ce(DWORD param_1,char *param_2,DWORD param_3)

{
  int *piVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  BOOL BVar6;
  DWORD *pDVar7;
  char local_418 [1028];
  int local_14;
  DWORD local_10;
  DWORD local_c;
  char *local_8;
  
  local_c = 0;
  local_14 = 0;
  if (param_3 == 0) {
LAB_1100b1e7:
    iVar4 = 0;
  }
  else {
    piVar1 = &DAT_1101a0e0 + ((int)param_1 >> 5);
    iVar4 = (param_1 & 0x1f) * 0x24;
    if ((*(byte *)(*piVar1 + 4 + iVar4) & 0x20) != 0) {
      FUN_1100ae53(param_1,0,2);
    }
    if ((*(byte *)((undefined4 *)(*piVar1 + iVar4) + 1) & 0x80) == 0) {
      BVar6 = WriteFile(*(HANDLE *)(*piVar1 + iVar4),param_2,param_3,&local_10,(LPOVERLAPPED)0x0);
      if (BVar6 == 0) {
        param_1 = GetLastError();
      }
      else {
        param_1 = 0;
        local_c = local_10;
      }
LAB_1100b2b6:
      if (local_c != 0) {
        return local_c - local_14;
      }
      if (param_1 == 0) goto LAB_1100b328;
      if (param_1 == 5) {
        pDVar7 = FUN_1100addc();
        *pDVar7 = 9;
        pDVar7 = FUN_1100ade5();
        *pDVar7 = 5;
      }
      else {
        FUN_1100ad69(param_1);
      }
    }
    else {
      local_8 = param_2;
      param_1 = 0;
      if (param_3 != 0) {
        do {
          pcVar5 = local_418;
          do {
            if (param_3 <= (uint)((int)local_8 - (int)param_2)) break;
            pcVar2 = local_8 + 1;
            cVar3 = *local_8;
            local_8 = pcVar2;
            if (cVar3 == '\n') {
              local_14 = local_14 + 1;
              *pcVar5 = '\r';
              pcVar5 = pcVar5 + 1;
            }
            *pcVar5 = cVar3;
            pcVar5 = pcVar5 + 1;
          } while ((int)pcVar5 - (int)local_418 < 0x400);
          BVar6 = WriteFile(*(HANDLE *)(*piVar1 + iVar4),local_418,(int)pcVar5 - (int)local_418,
                            &local_10,(LPOVERLAPPED)0x0);
          if (BVar6 == 0) {
            param_1 = GetLastError();
            goto LAB_1100b2b6;
          }
          local_c = local_c + local_10;
          if (((int)local_10 < (int)pcVar5 - (int)local_418) ||
             (param_3 <= (uint)((int)local_8 - (int)param_2))) goto LAB_1100b2b6;
        } while( true );
      }
LAB_1100b328:
      if (((*(byte *)(*piVar1 + 4 + iVar4) & 0x40) != 0) && (*param_2 == '\x1a')) goto LAB_1100b1e7;
      pDVar7 = FUN_1100addc();
      *pDVar7 = 0x1c;
      pDVar7 = FUN_1100ade5();
      *pDVar7 = 0;
    }
    iVar4 = -1;
  }
  return iVar4;
}


// ---- 1100b359 FUN_1100b359  (called by: FUN_11008a4e@11008a4e, FUN_110091b6@110091b6, FUN_1100cbef@1100cbef, __putw@1100f2f0)

uint __cdecl FUN_1100b359(uint param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  byte bVar5;
  undefined3 extraout_var;
  undefined *puVar6;
  int *piVar7;
  
  piVar4 = param_2;
  uVar1 = param_2[3];
  uVar2 = param_2[4];
  if (((uVar1 & 0x82) == 0) || ((uVar1 & 0x40) != 0)) {
LAB_1100b465:
    param_2[3] = uVar1 | 0x20;
  }
  else {
    if ((uVar1 & 1) != 0) {
      param_2[1] = 0;
      if ((uVar1 & 0x10) == 0) goto LAB_1100b465;
      *param_2 = param_2[2];
      param_2[3] = uVar1 & 0xfffffffe;
    }
    uVar1 = param_2[3];
    param_2[1] = 0;
    param_2 = (int *)0x0;
    piVar4[3] = uVar1 & 0xffffffef | 2;
    if (((uVar1 & 0x10c) == 0) &&
       (((piVar4 != (int *)&DAT_11015698 && (piVar4 != (int *)&DAT_110156b8)) ||
        (bVar5 = FUN_1100dee8(uVar2), CONCAT31(extraout_var,bVar5) == 0)))) {
      FUN_1100dea4(piVar4);
    }
    if ((*(ushort *)(piVar4 + 3) & 0x108) == 0) {
      piVar7 = (int *)0x1;
      param_2 = (int *)FUN_1100b169(uVar2,(char *)&param_1,1);
    }
    else {
      pcVar3 = (char *)piVar4[2];
      piVar7 = (int *)(*piVar4 - (int)pcVar3);
      *piVar4 = (int)(pcVar3 + 1);
      piVar4[1] = piVar4[6] + -1;
      if ((int)piVar7 < 1) {
        if (uVar2 == 0xffffffff) {
          puVar6 = &DAT_11015a60;
        }
        else {
          puVar6 = (undefined *)((&DAT_1101a0e0)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
        }
        if ((puVar6[4] & 0x20) != 0) {
          FUN_1100adee(uVar2,0,2);
        }
      }
      else {
        param_2 = (int *)FUN_1100b169(uVar2,pcVar3,(DWORD)piVar7);
      }
      *(undefined1 *)piVar4[2] = (undefined1)param_1;
    }
    if (param_2 == piVar7) {
      return param_1 & 0xff;
    }
    piVar4[3] = piVar4[3] | 0x20;
  }
  return 0xffffffff;
}


// ---- 1100b471 FUN_1100b471  (called by: FUN_11008b58@11008b58)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __cdecl FUN_1100b471(LPCSTR param_1,char *param_2,uint param_3,undefined4 *param_4)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  
  bVar4 = false;
  bVar3 = false;
  cVar1 = *param_2;
  if (cVar1 == 'a') {
    uVar5 = 0x109;
  }
  else {
    if (cVar1 == 'r') {
      uVar5 = 0;
      uVar6 = DAT_11019cec | 1;
      goto LAB_1100b4b2;
    }
    if (cVar1 != 'w') {
      return (undefined4 *)0x0;
    }
    uVar5 = 0x301;
  }
  uVar6 = DAT_11019cec | 2;
LAB_1100b4b2:
  bVar2 = true;
LAB_1100b4b5:
  cVar1 = param_2[1];
  param_2 = param_2 + 1;
  if ((cVar1 == '\0') || (!bVar2)) {
    uVar5 = FUN_1100df11(param_1,uVar5,param_3,0x1a4);
    if ((int)uVar5 < 0) {
      return (undefined4 *)0x0;
    }
    _DAT_11019bd8 = _DAT_11019bd8 + 1;
    param_4[3] = uVar6;
    param_4[1] = 0;
    *param_4 = 0;
    param_4[2] = 0;
    param_4[7] = 0;
    param_4[4] = uVar5;
    return param_4;
  }
  if (cVar1 < 'U') {
    if (cVar1 == 'T') {
      if ((uVar5 & 0x1000) == 0) {
        uVar5 = uVar5 | 0x1000;
        goto LAB_1100b4b5;
      }
    }
    else if (cVar1 == '+') {
      if ((uVar5 & 2) == 0) {
        uVar5 = uVar5 & 0xfffffffe | 2;
        uVar6 = uVar6 & 0xfffffffc | 0x80;
        goto LAB_1100b4b5;
      }
    }
    else if (cVar1 == 'D') {
      if ((uVar5 & 0x40) == 0) {
        uVar5 = uVar5 | 0x40;
        goto LAB_1100b4b5;
      }
    }
    else if (cVar1 == 'R') {
      if (!bVar3) {
        bVar3 = true;
        uVar5 = uVar5 | 0x10;
        goto LAB_1100b4b5;
      }
    }
    else if ((cVar1 == 'S') && (!bVar3)) {
      bVar3 = true;
      uVar5 = uVar5 | 0x20;
      goto LAB_1100b4b5;
    }
  }
  else {
    if (cVar1 == 'b') {
      if ((uVar5 & 0xc000) != 0) goto LAB_1100b595;
      uVar5 = uVar5 | 0x8000;
      goto LAB_1100b4b5;
    }
    if (cVar1 == 'c') {
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 | 0x4000;
        goto LAB_1100b4b5;
      }
    }
    else {
      if (cVar1 != 'n') {
        if ((cVar1 != 't') || ((uVar5 & 0xc000) != 0)) goto LAB_1100b595;
        uVar5 = uVar5 | 0x4000;
        goto LAB_1100b4b5;
      }
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 & 0xffffbfff;
        goto LAB_1100b4b5;
      }
    }
  }
LAB_1100b595:
  bVar2 = false;
  goto LAB_1100b4b5;
}


// ---- 1100b5e1 FUN_1100b5e1  (called by: FUN_11008b58@11008b58)

undefined4 * FUN_1100b5e1(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)0x0;
  FUN_11009f49(2);
  iVar3 = 0;
  if (0 < DAT_1101b200) {
    do {
      iVar1 = *(int *)(DAT_1101a1e4 + iVar3 * 4);
      if (iVar1 == 0) {
        iVar3 = iVar3 * 4;
        pvVar2 = _malloc(0x38);
        *(void **)(iVar3 + DAT_1101a1e4) = pvVar2;
        if (*(int *)(iVar3 + DAT_1101a1e4) != 0) {
          InitializeCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_1101a1e4) + 0x20));
          EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_1101a1e4) + 0x20));
          puVar4 = *(undefined4 **)(iVar3 + DAT_1101a1e4);
LAB_1100b685:
          if (puVar4 != (undefined4 *)0x0) {
            puVar4[4] = 0xffffffff;
            puVar4[1] = 0;
            puVar4[3] = 0;
            puVar4[2] = 0;
            *puVar4 = 0;
            puVar4[7] = 0;
          }
        }
        break;
      }
      if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
        FUN_1100abe9(iVar3,iVar1);
        iVar1 = *(int *)(DAT_1101a1e4 + iVar3 * 4);
        if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
          puVar4 = *(undefined4 **)(DAT_1101a1e4 + iVar3 * 4);
          goto LAB_1100b685;
        }
        FUN_1100ac3b(iVar3,iVar1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_1101b200);
  }
  FUN_11009faa(2);
  return puVar4;
}


// ---- 1100b6a9 FUN_1100b6a9  (called by: FUN_11008c60@11008c60, FUN_11008cea@11008cea, FUN_11008dc5@11008dc5)

undefined4 __cdecl
FUN_1100b6a9(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int *param_5,
            int param_6,PVOID param_7,char param_8)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (*param_5 != 0x19930520) {
    FUN_1100c0f9();
  }
  if ((param_1->ExceptionFlags & 0x66) == 0) {
    if (param_5[3] != 0) {
      if (((param_1->ExceptionCode == 0xe06d7363) && (0x19930520 < param_1->ExceptionInformation[0])
          ) && (pcVar1 = *(code **)(param_1->ExceptionInformation[2] + 8), pcVar1 != (code *)0x0)) {
        uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
        return uVar2;
      }
      FUN_1100b744(param_1,param_2,param_3,param_4,(uint)param_5,param_8,param_6,param_7);
    }
  }
  else if ((param_5[1] != 0) && (param_6 == 0)) {
    FUN_1100b9fe((int)param_2,param_4,(int)param_5,-1);
  }
  return 1;
}


// ---- 1100b744 FUN_1100b744  (called by: FUN_1100b6a9@1100b6a9)

void __cdecl
FUN_1100b744(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,uint param_5,
            char param_6,int param_7,PVOID param_8)

{
  byte *pbVar1;
  bool bVar2;
  DWORD *pDVar3;
  undefined3 extraout_var;
  int *piVar4;
  int iVar5;
  int *piVar6;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_18 = local_18 & 0xffffff00;
  local_14 = *(int *)((int)param_2 + 8);
  if ((local_14 < -1) || (*(int *)(param_5 + 4) <= local_14)) {
    FUN_1100c0f9();
  }
  if (param_1->ExceptionCode == 0xe06d7363) {
    if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
       (param_1->ExceptionInformation[2] == 0)) {
      pDVar3 = FUN_1100bf91();
      if (pDVar3[0x1b] == 0) {
        return;
      }
      pDVar3 = FUN_1100bf91();
      param_1 = (PEXCEPTION_RECORD)pDVar3[0x1b];
      pDVar3 = FUN_1100bf91();
      param_3 = pDVar3[0x1c];
      local_18 = CONCAT31(local_18._1_3_,1);
      bVar2 = FUN_1100e244(param_1,1);
      if (CONCAT31(extraout_var,bVar2) == 0) {
        FUN_1100c0f9();
      }
      if (param_1->ExceptionCode != 0xe06d7363) goto LAB_1100b8cc;
      if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
         (param_1->ExceptionInformation[2] == 0)) {
        FUN_1100c0f9();
      }
    }
    iVar5 = local_14;
    if (((param_1->ExceptionCode == 0xe06d7363) && (param_1->NumberParameters == 3)) &&
       (param_1->ExceptionInformation[0] == 0x19930520)) {
      piVar4 = (int *)FUN_11008e3a(param_5,param_7,local_14,&local_8,&local_1c);
      do {
        if (local_1c <= local_8) {
          if (param_6 == '\0') {
            return;
          }
          FUN_1100be36((int)param_1);
          return;
        }
        if ((*piVar4 <= iVar5) && (iVar5 <= piVar4[1])) {
          pbVar1 = (byte *)piVar4[4];
          for (local_10 = piVar4[3]; 0 < local_10; local_10 = local_10 + -1) {
            piVar6 = *(int **)(param_1->ExceptionInformation[2] + 0xc);
            for (local_c = *piVar6; 0 < local_c; local_c = local_c + -1) {
              piVar6 = piVar6 + 1;
              iVar5 = FUN_1100b9a1(pbVar1,(byte *)*piVar6,(uint *)param_1->ExceptionInformation[2]);
              if (iVar5 != 0) {
                FUN_1100bab2(param_1,param_2,param_3,param_4,param_5,pbVar1,(byte *)*piVar6,piVar4,
                             param_7,param_8);
                goto LAB_1100b8a9;
              }
            }
            pbVar1 = pbVar1 + 0x10;
          }
LAB_1100b8a9:
          iVar5 = local_14;
        }
        local_8 = local_8 + 1;
        piVar4 = piVar4 + 5;
      } while( true );
    }
  }
LAB_1100b8cc:
  if (param_6 == '\0') {
    FUN_1100b8f7(param_1,param_2,param_3,param_4,param_5,local_14,param_7,param_8);
    return;
  }
  FUN_1100c098();
  return;
}


// ---- 1100b8f7 FUN_1100b8f7  (called by: FUN_1100b744@1100b744)

void __cdecl
FUN_1100b8f7(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,uint param_5,
            int param_6,int param_7,PVOID param_8)

{
  DWORD *pDVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint local_c;
  uint local_8;
  
  pDVar1 = FUN_1100bf91();
  if ((pDVar1[0x1a] != 0) &&
     (iVar2 = FUN_11008d0f(&param_1->ExceptionCode,param_2,param_3,param_4,param_5,param_7,param_8),
     iVar2 != 0)) {
    return;
  }
  piVar3 = (int *)FUN_11008e3a(param_5,param_7,param_6,&local_8,&local_c);
  for (; local_8 < local_c; local_8 = local_8 + 1) {
    if ((*piVar3 <= param_6) && (param_6 <= piVar3[1])) {
      iVar4 = piVar3[3] * 0x10 + piVar3[4];
      iVar2 = *(int *)(iVar4 + -0xc);
      if ((iVar2 == 0) || (*(char *)(iVar2 + 8) == '\0')) {
        FUN_1100bab2(param_1,param_2,param_3,param_4,param_5,(byte *)(iVar4 + -0x10),(byte *)0x0,
                     piVar3,param_7,param_8);
      }
    }
    piVar3 = piVar3 + 5;
  }
  return;
}


// ---- 1100b9a1 FUN_1100b9a1  (called by: FUN_1100b744@1100b744)

undefined4 __cdecl FUN_1100b9a1(byte *param_1,byte *param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || (*(char *)(iVar1 + 8) == '\0')) {
LAB_1100b9f8:
    uVar2 = 1;
  }
  else {
    if (iVar1 == *(int *)(param_2 + 4)) {
LAB_1100b9d2:
      if (((((*param_2 & 2) == 0) || ((*param_1 & 8) != 0)) &&
          (((*param_3 & 1) == 0 || ((*param_1 & 1) != 0)))) &&
         (((*param_3 & 2) == 0 || ((*param_1 & 2) != 0)))) goto LAB_1100b9f8;
    }
    else {
      iVar1 = _strcmp((char *)(iVar1 + 8),(char *)(*(int *)(param_2 + 4) + 8));
      if (iVar1 == 0) goto LAB_1100b9d2;
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ---- 1100b9fe FUN_1100b9fe  (called by: FUN_1100b6a9@1100b6a9, FUN_1100bab2@1100bab2)

void __cdecl FUN_1100b9fe(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_11010448;
  pcStack_10 = FUN_1100e32c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  for (iVar2 = *(int *)(param_1 + 8); local_8 = 0xffffffff, iVar2 != param_4;
      iVar2 = *(int *)(*(int *)(param_3 + 8) + iVar2 * 8)) {
    if ((iVar2 < 0) || (*(int *)(param_3 + 4) <= iVar2)) {
      FUN_1100c0f9();
    }
    local_8 = 0;
    iVar1 = *(int *)(*(int *)(param_3 + 8) + 4 + iVar2 * 8);
    if (iVar1 != 0) {
      __CallSettingFrame_12(iVar1,param_1,0x103);
    }
  }
  *(int *)(param_1 + 8) = iVar2;
  ExceptionList = local_14;
  return;
}


// ---- 1100bab2 FUN_1100bab2  (called by: FUN_1100b744@1100b744, FUN_1100b8f7@1100b8f7)

void __cdecl
FUN_1100bab2(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int param_5,
            byte *param_6,byte *param_7,int *param_8,int param_9,PVOID param_10)

{
  undefined *UNRECOVERED_JUMPTABLE;
  
  if (param_7 != (byte *)0x0) {
    FUN_1100bc72((int)param_1,(int)param_2,param_6,param_7);
  }
  if (param_10 == (PVOID)0x0) {
    param_10 = param_2;
  }
  else {
  }
  FUN_11008c11(param_10,param_1);
  FUN_1100b9fe((int)param_2,param_4,param_5,*param_8);
  *(int *)((int)param_2 + 8) = param_8[1] + 1;
  UNRECOVERED_JUMPTABLE =
       (undefined *)
       FUN_1100bb2d((DWORD)param_1,param_2,param_3,param_5,*(undefined4 *)(param_6 + 0xc),param_9,
                    0x100);
  if (UNRECOVERED_JUMPTABLE != (undefined *)0x0) {
    FUN_11008bcf(UNRECOVERED_JUMPTABLE);
  }
  return;
}


// ---- 1100bb2d FUN_1100bb2d  (called by: FUN_1100bab2@1100bab2)

undefined4 __cdecl
FUN_1100bb2d(DWORD param_1,undefined4 param_2,DWORD param_3,undefined4 param_4,undefined4 param_5,
            int param_6,int param_7)

{
  DWORD *pDVar1;
  undefined4 uVar2;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_11010458;
  pcStack_10 = FUN_1100e32c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_1100bf91();
  FUN_1100bf91();
  pDVar1 = FUN_1100bf91();
  pDVar1[0x1b] = param_1;
  pDVar1 = FUN_1100bf91();
  pDVar1[0x1c] = param_3;
  local_8 = 1;
  uVar2 = FUN_11008c96(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_1100bbfa();
  ExceptionList = local_14;
  return uVar2;
}


// ---- 1100bbfa FUN_1100bbfa  (called by: FUN_1100bb2d@1100bb2d)

void FUN_1100bbfa(void)

{
  DWORD *pDVar1;
  int unaff_EBP;
  int unaff_ESI;
  int *unaff_EDI;
  
  *(undefined4 *)(unaff_ESI + -4) = *(undefined4 *)(unaff_EBP + -0x28);
  pDVar1 = FUN_1100bf91();
  pDVar1[0x1b] = *(DWORD *)(unaff_EBP + -0x1c);
  pDVar1 = FUN_1100bf91();
  pDVar1[0x1c] = *(DWORD *)(unaff_EBP + -0x20);
  if ((((*unaff_EDI == -0x1f928c9d) && (unaff_EDI[4] == 3)) && (unaff_EDI[5] == 0x19930520)) &&
     ((*(int *)(unaff_EBP + -0x24) == 0 && (*(int *)(unaff_EBP + -0x2c) != 0)))) {
    __abnormal_termination();
    FUN_1100be36((int)unaff_EDI);
  }
  return;
}


// ---- 1100bc72 FUN_1100bc72  (called by: FUN_1100bab2@1100bab2)

void __cdecl FUN_1100bc72(int param_1,int param_2,byte *param_3,byte *param_4)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined4 *puVar4;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  uint uVar5;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_11010470;
  pcStack_10 = FUN_1100e32c;
  local_14 = ExceptionList;
  if (*(int *)(param_3 + 4) == 0) {
    return;
  }
  if (*(char *)(*(int *)(param_3 + 4) + 8) == '\0') {
    return;
  }
  if (*(int *)(param_3 + 8) == 0) {
    return;
  }
  piVar1 = (int *)(*(int *)(param_3 + 8) + 0xc + param_2);
  local_8 = 0;
  if ((*param_3 & 8) == 0) {
    if ((*param_4 & 1) == 0) {
      if (*(int *)(param_4 + 0x18) == 0) {
        ExceptionList = &local_14;
        bVar2 = FUN_1100e244(*(void **)(param_1 + 0x18),1);
        if ((CONCAT31(extraout_var_03,bVar2) != 0) &&
           (bVar2 = FUN_1100e260(piVar1,1), CONCAT31(extraout_var_04,bVar2) != 0)) {
          uVar5 = *(uint *)(param_4 + 0x14);
          puVar4 = (undefined4 *)FUN_1100be9d(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
          FUN_1100d780(piVar1,puVar4,uVar5);
          ExceptionList = local_14;
          return;
        }
      }
      else {
        ExceptionList = &local_14;
        bVar2 = FUN_1100e244(*(void **)(param_1 + 0x18),1);
        if (((CONCAT31(extraout_var_05,bVar2) != 0) &&
            (bVar2 = FUN_1100e260(piVar1,1), CONCAT31(extraout_var_06,bVar2) != 0)) &&
           (bVar2 = FUN_1100e27c(*(FARPROC *)(param_4 + 0x18)), CONCAT31(extraout_var_07,bVar2) != 0
           )) {
          if ((*param_4 & 4) == 0) {
            FUN_1100be9d(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
            FUN_11008c03(piVar1,*(undefined **)(param_4 + 0x18));
            ExceptionList = local_14;
            return;
          }
          FUN_1100be9d(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
          FUN_11008c0a(piVar1,*(undefined **)(param_4 + 0x18));
          ExceptionList = local_14;
          return;
        }
      }
    }
    else {
      ExceptionList = &local_14;
      bVar2 = FUN_1100e244(*(void **)(param_1 + 0x18),1);
      if ((CONCAT31(extraout_var_01,bVar2) != 0) &&
         (bVar2 = FUN_1100e260(piVar1,1), CONCAT31(extraout_var_02,bVar2) != 0)) {
        FUN_1100d780(piVar1,*(undefined4 **)(param_1 + 0x18),*(uint *)(param_4 + 0x14));
        if (*(int *)(param_4 + 0x14) != 4) {
          ExceptionList = local_14;
          return;
        }
        iVar3 = *piVar1;
        if (iVar3 == 0) {
          ExceptionList = local_14;
          return;
        }
        goto LAB_1100bd00;
      }
    }
  }
  else {
    ExceptionList = &local_14;
    bVar2 = FUN_1100e244(*(void **)(param_1 + 0x18),1);
    if ((CONCAT31(extraout_var,bVar2) != 0) &&
       (bVar2 = FUN_1100e260(piVar1,1), CONCAT31(extraout_var_00,bVar2) != 0)) {
      iVar3 = *(int *)(param_1 + 0x18);
      *piVar1 = iVar3;
LAB_1100bd00:
      iVar3 = FUN_1100be9d(iVar3,(int *)(param_4 + 8));
      *piVar1 = iVar3;
      ExceptionList = local_14;
      return;
    }
  }
  FUN_1100c0f9();
  ExceptionList = local_14;
  return;
}


// ---- 1100be36 FUN_1100be36  (called by: FUN_1100b744@1100b744, FUN_1100bbfa@1100bbfa)

void __cdecl FUN_1100be36(int param_1)

{
  undefined *UNRECOVERED_JUMPTABLE;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_11010480;
  pcStack_10 = FUN_1100e32c;
  local_14 = ExceptionList;
  if ((param_1 != 0) &&
     (UNRECOVERED_JUMPTABLE = *(undefined **)(*(int *)(param_1 + 0x1c) + 4),
     UNRECOVERED_JUMPTABLE != (undefined *)0x0)) {
    local_8 = 0;
    ExceptionList = &local_14;
    FUN_11008c03(*(undefined4 *)(param_1 + 0x18),UNRECOVERED_JUMPTABLE);
  }
  ExceptionList = local_14;
  return;
}


// ---- 1100be9d FUN_1100be9d  (called by: FUN_1100bc72@1100bc72)

int __cdecl FUN_1100be9d(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2[1];
  iVar2 = *param_2 + param_1;
  if (-1 < iVar1) {
    iVar2 = iVar2 + *(int *)(*(int *)(iVar1 + param_1) + param_2[2]) + iVar1;
  }
  return iVar2;
}


// ---- 1100bec0 __CallSettingFrame@12  (called by: FUN_11008c96@11008c96, FUN_1100b9fe@1100b9fe)

/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* Library Function - Single Match
    __CallSettingFrame@12
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __CallSettingFrame_12(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)__NLG_Notify1(param_3);
  (*pcVar1)();
  if (param_3 == 0x100) {
    param_3 = 2;
  }
  __NLG_Notify1(param_3);
  return;
}


// ---- 1100bf0c FUN_1100bf0c  (called by: FUN_110099c5@110099c5)

undefined4 FUN_1100bf0c(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  FUN_11009eb4();
  DAT_11015a90 = TlsAlloc();
  if (DAT_11015a90 != 0xffffffff) {
    lpTlsValue = (DWORD *)FUN_1100dab5(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_11015a90,lpTlsValue);
      if (BVar1 != 0) {
        FUN_1100bf7e((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        return 1;
      }
    }
  }
  return 0;
}


// ---- 1100bf60 FUN_1100bf60  (called by: FUN_110099c5@110099c5)

void FUN_1100bf60(void)

{
  FUN_11009edd();
  if (DAT_11015a90 != 0xffffffff) {
    TlsFree(DAT_11015a90);
    DAT_11015a90 = 0xffffffff;
  }
  return;
}


// ---- 1100bf7e FUN_1100bf7e  (called by: FUN_1100bf0c@1100bf0c, FUN_1100bf91@1100bf91)

void __cdecl FUN_1100bf7e(int param_1)

{
  *(undefined **)(param_1 + 0x50) = &DAT_11015c30;
  *(undefined4 *)(param_1 + 0x14) = 1;
  return;
}


// ---- 1100bf91 FUN_1100bf91  (called by: FUN_11008d0f@11008d0f, FUN_1100addc@1100addc, FUN_1100ade5@1100ade5, FUN_1100b744@1100b744, FUN_1100b8f7@1100b8f7, FUN_1100bb2d@1100bb2d, FUN_1100bbfa@1100bbfa, FUN_1100c098@1100c098, FUN_1100ec0c@1100ec0c)

DWORD * FUN_1100bf91(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(DAT_11015a90);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = (DWORD *)FUN_1100dab5(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_11015a90,lpTlsValue);
      if (BVar1 != 0) {
        FUN_1100bf7e((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        goto LAB_1100bfec;
      }
    }
    __amsg_exit(0x10);
  }
LAB_1100bfec:
  SetLastError(dwErrCode);
  return lpTlsValue;
}


// ---- 1100bff8 FUN_1100bff8  (called by: FUN_110099c5@110099c5)

void __cdecl FUN_1100bff8(LPVOID param_1)

{
  if (DAT_11015a90 == 0xffffffff) {
    return;
  }
  if ((param_1 != (LPVOID)0x0) || (param_1 = TlsGetValue(DAT_11015a90), param_1 != (LPVOID)0x0)) {
    if (*(LPVOID *)((int)param_1 + 0x24) != (LPVOID)0x0) {
      FUN_110085b8(*(LPVOID *)((int)param_1 + 0x24));
    }
    if (*(LPVOID *)((int)param_1 + 0x28) != (LPVOID)0x0) {
      FUN_110085b8(*(LPVOID *)((int)param_1 + 0x28));
    }
    if (*(LPVOID *)((int)param_1 + 0x30) != (LPVOID)0x0) {
      FUN_110085b8(*(LPVOID *)((int)param_1 + 0x30));
    }
    if (*(LPVOID *)((int)param_1 + 0x38) != (LPVOID)0x0) {
      FUN_110085b8(*(LPVOID *)((int)param_1 + 0x38));
    }
    if (*(LPVOID *)((int)param_1 + 0x40) != (LPVOID)0x0) {
      FUN_110085b8(*(LPVOID *)((int)param_1 + 0x40));
    }
    if (*(LPVOID *)((int)param_1 + 0x44) != (LPVOID)0x0) {
      FUN_110085b8(*(LPVOID *)((int)param_1 + 0x44));
    }
    if (*(undefined **)((int)param_1 + 0x50) != &DAT_11015c30) {
      FUN_110085b8(*(undefined **)((int)param_1 + 0x50));
    }
    FUN_110085b8(param_1);
  }
  TlsSetValue(DAT_11015a90,(LPVOID)0x0);
  return;
}


// ---- 1100c098 FUN_1100c098  (called by: FUN_1100b744@1100b744, FUN_1100c0f9@1100c0f9, FUN_1100e1e0@1100e1e0)

void FUN_1100c098(void)

{
  DWORD *pDVar1;
  void *pvStack_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_11010490;
  pcStack_10 = FUN_1100e32c;
  pvStack_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_14;
  pDVar1 = FUN_1100bf91();
  if (pDVar1[0x18] != 0) {
    local_8 = 1;
    pDVar1 = FUN_1100bf91();
    (*(code *)pDVar1[0x18])();
  }
  local_8 = 0xffffffff;
  FUN_1100e404();
  return;
}


// ---- 1100c0f9 FUN_1100c0f9  (called by: FUN_11008e3a@11008e3a, FUN_1100b6a9@1100b6a9, FUN_1100b744@1100b744, FUN_1100b9fe@1100b9fe, FUN_1100bc72@1100bc72)

void FUN_1100c0f9(void)

{
  void *pvStack_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_110104a8;
  pcStack_10 = FUN_1100e32c;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (PTR_FUN_11015a94 != (undefined *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*(code *)PTR_FUN_11015a94)();
  }
  local_8 = 0xffffffff;
  FUN_1100c098();
  return;
}


// ---- 1100c14f FUN_1100c14f  (called by: FUN_11008fc7@11008fc7)

SIZE_T __cdecl FUN_1100c14f(LPCVOID param_1)

{
  uint uVar1;
  SIZE_T SVar2;
  
  FUN_11009f49(9);
  uVar1 = FUN_11009ffd((int)param_1);
  if (uVar1 == 0) {
    FUN_11009faa(9);
    SVar2 = HeapSize(DAT_1101b21c,0,param_1);
  }
  else {
    SVar2 = *(int *)((int)param_1 + -4) - 9;
    FUN_11009faa(9);
  }
  return SVar2;
}


// ---- 1100c194 FUN_1100c194  (called by: FUN_110090ce@110090ce)

uint __cdecl FUN_1100c194(undefined4 *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  
  uVar2 = param_1[3];
  if (((uVar2 & 0x83) != 0) && ((uVar2 & 0x40) == 0)) {
    if ((uVar2 & 2) == 0) {
      param_1[3] = uVar2 | 1;
      if ((uVar2 & 0x10c) == 0) {
        FUN_1100dea4(param_1);
      }
      else {
        *param_1 = param_1[2];
      }
      iVar3 = FUN_1100c270(param_1[4],(char *)param_1[2],(char *)param_1[6]);
      param_1[1] = iVar3;
      if ((iVar3 != 0) && (iVar3 != -1)) {
        if ((param_1[3] & 0x82) == 0) {
          uVar2 = param_1[4];
          if (uVar2 == 0xffffffff) {
            puVar4 = &DAT_11015a60;
          }
          else {
            puVar4 = (undefined *)((&DAT_1101a0e0)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
          }
          if ((puVar4[4] & 0x82) == 0x82) {
            param_1[3] = param_1[3] | 0x2000;
          }
        }
        if (((param_1[6] == 0x200) && ((param_1[3] & 8) != 0)) && ((param_1[3] & 0x400) == 0)) {
          param_1[6] = 0x1000;
        }
        param_1[1] = iVar3 + -1;
        bVar1 = *(byte *)*param_1;
        *param_1 = (byte *)*param_1 + 1;
        return (uint)bVar1;
      }
      param_1[3] = param_1[3] | (-(uint)(iVar3 != 0) & 0x10) + 0x10;
      param_1[1] = 0;
    }
    else {
      param_1[3] = uVar2 | 0x20;
    }
  }
  return 0xffffffff;
}


// ---- 1100c270 FUN_1100c270  (called by: FUN_110090ce@110090ce, FUN_1100c194@1100c194)

int __cdecl FUN_1100c270(uint param_1,char *param_2,char *param_3)

{
  int iVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_1101a1e0) &&
     ((*(byte *)((&DAT_1101a0e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_1100de23(param_1);
    iVar1 = FUN_1100c2d5(param_1,param_2,param_3);
    FUN_1100de82(param_1);
    return iVar1;
  }
  pDVar2 = FUN_1100addc();
  *pDVar2 = 9;
  pDVar2 = FUN_1100ade5();
  *pDVar2 = 0;
  return -1;
}


// ---- 1100c2d5 FUN_1100c2d5  (called by: FUN_1100c270@1100c270, FUN_1100df11@1100df11)

int __cdecl FUN_1100c2d5(uint param_1,char *param_2,char *param_3)

{
  int *piVar1;
  byte *pbVar2;
  char cVar3;
  byte bVar4;
  BOOL BVar5;
  DWORD DVar6;
  DWORD *pDVar7;
  char *pcVar8;
  int iVar9;
  DWORD local_10;
  char *local_c;
  char local_5;
  
  local_c = (char *)0x0;
  if (param_3 != (char *)0x0) {
    piVar1 = &DAT_1101a0e0 + ((int)param_1 >> 5);
    iVar9 = (param_1 & 0x1f) * 0x24;
    bVar4 = *(byte *)((&DAT_1101a0e0)[(int)param_1 >> 5] + iVar9 + 4);
    if ((bVar4 & 2) == 0) {
      pcVar8 = param_2;
      if (((bVar4 & 0x48) != 0) &&
         (cVar3 = *(char *)((&DAT_1101a0e0)[(int)param_1 >> 5] + iVar9 + 5), cVar3 != '\n')) {
        param_3 = param_3 + -1;
        *param_2 = cVar3;
        pcVar8 = param_2 + 1;
        local_c = (char *)0x1;
        *(undefined1 *)(*piVar1 + 5 + iVar9) = 10;
      }
      BVar5 = ReadFile(*(HANDLE *)(*piVar1 + iVar9),pcVar8,(DWORD)param_3,&local_10,
                       (LPOVERLAPPED)0x0);
      if (BVar5 == 0) {
        DVar6 = GetLastError();
        if (DVar6 == 5) {
          pDVar7 = FUN_1100addc();
          *pDVar7 = 9;
          pDVar7 = FUN_1100ade5();
          *pDVar7 = 5;
        }
        else {
          if (DVar6 == 0x6d) {
            return 0;
          }
          FUN_1100ad69(DVar6);
        }
        return -1;
      }
      local_c = (char *)((int)local_c + local_10);
      bVar4 = *(byte *)(*piVar1 + 4 + iVar9);
      if ((bVar4 & 0x80) != 0) {
        if ((local_10 == 0) || (*param_2 != '\n')) {
          bVar4 = bVar4 & 0xfb;
        }
        else {
          bVar4 = bVar4 | 4;
        }
        *(byte *)(*piVar1 + 4 + iVar9) = bVar4;
        param_3 = param_2;
        local_c = param_2 + (int)local_c;
        pcVar8 = param_2;
        if (param_2 < local_c) {
          do {
            cVar3 = *param_3;
            if (cVar3 == '\x1a') {
              pbVar2 = (byte *)(*piVar1 + 4 + iVar9);
              bVar4 = *pbVar2;
              if ((bVar4 & 0x40) == 0) {
                *pbVar2 = bVar4 | 2;
              }
              break;
            }
            if (cVar3 == '\r') {
              if (param_3 < local_c + -1) {
                if (param_3[1] == '\n') {
                  param_3 = param_3 + 2;
                  goto LAB_1100c460;
                }
                *pcVar8 = '\r';
                pcVar8 = pcVar8 + 1;
                param_3 = param_3 + 1;
              }
              else {
                param_3 = param_3 + 1;
                BVar5 = ReadFile(*(HANDLE *)(*piVar1 + iVar9),&local_5,1,&local_10,(LPOVERLAPPED)0x0
                                );
                if (((BVar5 == 0) && (DVar6 = GetLastError(), DVar6 != 0)) || (local_10 == 0)) {
LAB_1100c47a:
                  *pcVar8 = '\r';
LAB_1100c47d:
                  pcVar8 = pcVar8 + 1;
                }
                else if ((*(byte *)(*piVar1 + 4 + iVar9) & 0x48) == 0) {
                  if ((pcVar8 == param_2) && (local_5 == '\n')) {
LAB_1100c460:
                    *pcVar8 = '\n';
                    goto LAB_1100c47d;
                  }
                  FUN_1100ae53(param_1,-1,1);
                  if (local_5 != '\n') goto LAB_1100c47a;
                }
                else {
                  if (local_5 == '\n') goto LAB_1100c460;
                  *pcVar8 = '\r';
                  pcVar8 = pcVar8 + 1;
                  *(char *)(*piVar1 + 5 + iVar9) = local_5;
                }
              }
            }
            else {
              *pcVar8 = cVar3;
              pcVar8 = pcVar8 + 1;
              param_3 = param_3 + 1;
            }
          } while (param_3 < local_c);
        }
        local_c = (char *)((int)pcVar8 - (int)param_2);
      }
      return (int)local_c;
    }
  }
  return 0;
}


// ---- 1100c4ae FUN_1100c4ae  (called by: FUN_110091b6@110091b6)

int __cdecl FUN_1100c4ae(int *param_1,byte *param_2,undefined4 *param_3)

{
  WCHAR WVar1;
  byte *pbVar2;
  uint uVar3;
  undefined4 uVar4;
  short *psVar5;
  undefined1 *puVar6;
  WCHAR *pWVar7;
  int *piVar8;
  int iVar9;
  byte bVar10;
  int iVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  longlong lVar14;
  undefined1 local_24c [511];
  undefined1 local_4d;
  undefined4 local_4c;
  undefined4 local_48;
  uint local_44;
  uint local_40;
  CHAR local_3c [4];
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  char local_1a;
  char local_19;
  int local_18;
  int local_14;
  undefined1 *local_10;
  WCHAR *local_c;
  uint local_8;
  
  local_34 = 0;
  bVar10 = *param_2;
  local_10 = (undefined1 *)0x0;
  local_18 = 0;
  if (bVar10 != 0) {
    pbVar2 = param_2;
    while (param_2 = pbVar2 + 1, -1 < local_18) {
      if (((char)bVar10 < ' ') || ('x' < (char)bVar10)) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(byte *)((int)&PTR_LAB_110104a0 + (int)(char)bVar10) & 0xf;
      }
      local_34 = (int)(char)(&DAT_110104c0)[uVar3 * 8 + local_34] >> 4;
      switch(local_34) {
      case 0:
switchD_1100c51c_caseD_0:
        local_28 = 0;
        if ((PTR_DAT_11015cd0[(uint)bVar10 * 2 + 1] & 0x80) != 0) {
          FUN_1100cbef((int)(char)bVar10,param_1,&local_18);
          bVar10 = *param_2;
          param_2 = pbVar2 + 2;
        }
        FUN_1100cbef((int)(char)bVar10,param_1,&local_18);
        break;
      case 1:
        local_14 = -1;
        local_38 = 0;
        local_2c = 0;
        local_24 = 0;
        local_20 = 0;
        local_8 = 0;
        local_28 = 0;
        break;
      case 2:
        if (bVar10 == 0x20) {
          local_8 = local_8 | 2;
        }
        else if (bVar10 == 0x23) {
          local_8 = local_8 | 0x80;
        }
        else if (bVar10 == 0x2b) {
          local_8 = local_8 | 1;
        }
        else if (bVar10 == 0x2d) {
          local_8 = local_8 | 4;
        }
        else if (bVar10 == 0x30) {
          local_8 = local_8 | 8;
        }
        break;
      case 3:
        if (bVar10 == 0x2a) {
          local_24 = FUN_1100cc8d((int *)&param_3);
          if (local_24 < 0) {
            local_8 = local_8 | 4;
            local_24 = -local_24;
          }
        }
        else {
          local_24 = (char)bVar10 + -0x30 + local_24 * 10;
        }
        break;
      case 4:
        local_14 = 0;
        break;
      case 5:
        if (bVar10 == 0x2a) {
          local_14 = FUN_1100cc8d((int *)&param_3);
          if (local_14 < 0) {
            local_14 = -1;
          }
        }
        else {
          local_14 = (char)bVar10 + -0x30 + local_14 * 10;
        }
        break;
      case 6:
        if (bVar10 == 0x49) {
          if ((*param_2 != 0x36) || (pbVar2[2] != 0x34)) {
            local_34 = 0;
            goto switchD_1100c51c_caseD_0;
          }
          param_2 = pbVar2 + 3;
          local_8 = local_8 | 0x8000;
        }
        else if (bVar10 == 0x68) {
          local_8 = local_8 | 0x20;
        }
        else if (bVar10 == 0x6c) {
          local_8 = local_8 | 0x10;
        }
        else if (bVar10 == 0x77) {
          local_8 = local_8 | 0x800;
        }
        break;
      case 7:
        pWVar7 = local_c;
        if ((char)bVar10 < 'h') {
          if ('d' < (char)bVar10) {
LAB_1100c73c:
            local_8 = local_8 | 0x40;
            pWVar7 = (WCHAR *)local_24c;
            if (local_14 < 0) {
              local_14 = 6;
            }
            else if ((local_14 == 0) && (bVar10 == 0x67)) {
              local_14 = 1;
            }
            local_4c = *param_3;
            local_48 = param_3[1];
            param_3 = param_3 + 2;
            local_c = pWVar7;
            (*(code *)PTR___fptrap_11015cb8)
                      (&local_4c,local_24c,(int)(char)bVar10,local_14,local_38);
            uVar3 = local_8 & 0x80;
            if ((uVar3 != 0) && (local_14 == 0)) {
              (*(code *)PTR___fptrap_11015cc4)(local_24c);
            }
            if ((bVar10 == 0x67) && (uVar3 == 0)) {
              (*(code *)PTR___fptrap_11015cbc)(local_24c);
            }
            if (local_24c[0] == '-') {
              local_8 = local_8 | 0x100;
              pWVar7 = (WCHAR *)(local_24c + 1);
              local_c = pWVar7;
            }
LAB_1100c8ae:
            puVar6 = (undefined1 *)_strlen((char *)pWVar7);
            goto LAB_1100cab5;
          }
          if ((char)bVar10 < 'Y') {
            if (bVar10 == 0x58) {
LAB_1100c92d:
              local_30 = 7;
LAB_1100c934:
              local_10 = (undefined1 *)0x10;
              if ((local_8 & 0x80) != 0) {
                local_1a = '0';
                local_19 = (char)local_30 + 'Q';
                local_20 = 2;
              }
              goto LAB_1100c99e;
            }
            if (bVar10 == 0x43) {
              if ((local_8 & 0x830) == 0) {
                local_8 = local_8 | 0x800;
              }
              goto LAB_1100c769;
            }
            if ((bVar10 != 0x45) && (bVar10 != 0x47)) {
              if (bVar10 == 0x53) {
                if ((local_8 & 0x830) == 0) {
                  local_8 = local_8 | 0x800;
                }
                goto LAB_1100c6db;
              }
              goto LAB_1100cab8;
            }
            local_38 = 1;
            bVar10 = bVar10 + 0x20;
            goto LAB_1100c73c;
          }
          if (bVar10 == 0x5a) {
            psVar5 = (short *)FUN_1100cc8d((int *)&param_3);
            if ((psVar5 != (short *)0x0) &&
               (local_c = *(WCHAR **)(psVar5 + 2), local_c != (WCHAR *)0x0)) {
              if ((local_8 & 0x800) == 0) {
                local_28 = 0;
                puVar6 = (undefined1 *)(int)*psVar5;
                goto LAB_1100cab5;
              }
              local_10 = (undefined1 *)((uint)(int)*psVar5 >> 1);
              local_28 = 1;
              pWVar7 = local_c;
              goto LAB_1100cab8;
            }
            local_c = (WCHAR *)PTR_DAT_11015a98;
            pWVar7 = (WCHAR *)PTR_DAT_11015a98;
            goto LAB_1100c8ae;
          }
          if (bVar10 == 99) {
LAB_1100c769:
            if ((local_8 & 0x810) == 0) {
              uVar4 = FUN_1100cc8d((int *)&param_3);
              local_24c[0] = (char)uVar4;
              local_10 = (undefined1 *)0x1;
            }
            else {
              uVar4 = FUN_1100ccaa((int *)&param_3);
              local_10 = (undefined1 *)FUN_1100e41b(local_24c,(WCHAR)uVar4);
              if ((int)local_10 < 0) {
                local_2c = 1;
              }
            }
            pWVar7 = (WCHAR *)local_24c;
          }
          else if (bVar10 == 100) goto LAB_1100c993;
        }
        else {
          if (bVar10 == 0x69) {
LAB_1100c993:
            local_8 = local_8 | 0x40;
LAB_1100c997:
            local_10 = (undefined1 *)0xa;
LAB_1100c99e:
            if ((local_8 & 0x8000) == 0) {
              if ((local_8 & 0x20) == 0) {
                if ((local_8 & 0x40) == 0) {
                  uVar3 = FUN_1100cc8d((int *)&param_3);
                  uVar12 = (ulonglong)uVar3;
                  goto LAB_1100c9f1;
                }
                uVar3 = FUN_1100cc8d((int *)&param_3);
              }
              else if ((local_8 & 0x40) == 0) {
                uVar3 = FUN_1100cc8d((int *)&param_3);
                uVar3 = uVar3 & 0xffff;
              }
              else {
                uVar4 = FUN_1100cc8d((int *)&param_3);
                uVar3 = (uint)(short)uVar4;
              }
              uVar12 = (ulonglong)(int)uVar3;
            }
            else {
              uVar12 = FUN_1100cc9a((int *)&param_3);
            }
LAB_1100c9f1:
            iVar11 = (int)(uVar12 >> 0x20);
            if ((((local_8 & 0x40) != 0) && (iVar11 == 0 || (longlong)uVar12 < 0)) &&
               ((longlong)uVar12 < 0)) {
              local_8 = local_8 | 0x100;
              uVar12 = CONCAT44(-(iVar11 + (uint)((int)uVar12 != 0)),-(int)uVar12);
            }
            iVar11 = (int)(uVar12 >> 0x20);
            if ((local_8 & 0x8000) == 0) {
              iVar11 = 0;
            }
            lVar14 = CONCAT44(iVar11,(int)uVar12);
            if (local_14 < 0) {
              local_14 = 1;
            }
            else {
              local_8 = local_8 & 0xfffffff7;
            }
            if ((int)uVar12 == 0 && iVar11 == 0) {
              local_20 = 0;
            }
            local_c = (WCHAR *)&local_4d;
            while ((iVar11 = local_14 + -1, 0 < local_14 || (lVar14 != 0))) {
              local_40 = (int)local_10 >> 0x1f;
              local_44 = (uint)local_10;
              uVar3 = (uint)((ulonglong)lVar14 >> 0x20);
              local_14 = iVar11;
              uVar13 = __aullrem((uint)lVar14,uVar3,(uint)local_10,local_40);
              iVar11 = (int)uVar13 + 0x30;
              lVar14 = __aulldiv((uint)lVar14,uVar3,local_44,local_40);
              if (0x39 < iVar11) {
                iVar11 = iVar11 + local_30;
              }
              pWVar7 = (WCHAR *)((int)local_c + -1);
              *(char *)local_c = (char)iVar11;
              local_c = pWVar7;
            }
            local_10 = local_24c + -(int)local_c + 0x1ff;
            pWVar7 = (WCHAR *)((int)local_c + 1);
            local_14 = iVar11;
            if ((local_8 & 0x200) == 0) goto LAB_1100cab8;
            if (*(char *)pWVar7 == '0') {
              if (local_10 != (undefined1 *)0x0) goto LAB_1100cab8;
            }
            puVar6 = local_24c + -(int)local_c + 0x200;
            *(char *)local_c = '0';
          }
          else {
            if (bVar10 == 0x6e) {
              piVar8 = (int *)FUN_1100cc8d((int *)&param_3);
              if ((local_8 & 0x20) == 0) {
                *piVar8 = local_18;
              }
              else {
                *(undefined2 *)piVar8 = (undefined2)local_18;
              }
              local_2c = 1;
              break;
            }
            if (bVar10 == 0x6f) {
              local_10 = (undefined1 *)0x8;
              if ((local_8 & 0x80) != 0) {
                local_8 = local_8 | 0x200;
              }
              goto LAB_1100c99e;
            }
            if (bVar10 == 0x70) {
              local_14 = 8;
              goto LAB_1100c92d;
            }
            if (bVar10 != 0x73) {
              if (bVar10 != 0x75) {
                if (bVar10 != 0x78) goto LAB_1100cab8;
                local_30 = 0x27;
                goto LAB_1100c934;
              }
              goto LAB_1100c997;
            }
LAB_1100c6db:
            iVar11 = local_14;
            if (local_14 == -1) {
              iVar11 = 0x7fffffff;
            }
            local_c = (WCHAR *)FUN_1100cc8d((int *)&param_3);
            if ((local_8 & 0x810) == 0) {
              if (local_c == (WCHAR *)0x0) {
                local_c = (WCHAR *)PTR_DAT_11015a98;
              }
              for (pWVar7 = local_c; (iVar11 != 0 && ((char)*pWVar7 != '\0'));
                  pWVar7 = (WCHAR *)((int)pWVar7 + 1)) {
                iVar11 = iVar11 + -1;
              }
              puVar6 = (undefined1 *)((int)pWVar7 - (int)local_c);
            }
            else {
              if (local_c == (WCHAR *)0x0) {
                local_c = (WCHAR *)PTR_DAT_11015a9c;
              }
              local_28 = 1;
              for (pWVar7 = local_c; (iVar11 != 0 && (*pWVar7 != L'\0')); pWVar7 = pWVar7 + 1) {
                iVar11 = iVar11 + -1;
              }
              puVar6 = (undefined1 *)((int)pWVar7 - (int)local_c >> 1);
            }
          }
LAB_1100cab5:
          local_10 = puVar6;
          pWVar7 = local_c;
        }
LAB_1100cab8:
        local_c = pWVar7;
        uVar3 = local_8;
        if (local_2c == 0) {
          if ((local_8 & 0x40) != 0) {
            if ((local_8 & 0x100) == 0) {
              if ((local_8 & 1) == 0) {
                if ((local_8 & 2) == 0) goto LAB_1100caf0;
                local_1a = ' ';
              }
              else {
                local_1a = '+';
              }
            }
            else {
              local_1a = '-';
            }
            local_20 = 1;
          }
LAB_1100caf0:
          iVar11 = (local_24 - local_20) - (int)local_10;
          if ((local_8 & 0xc) == 0) {
            FUN_1100cc24(0x20,iVar11,param_1,&local_18);
          }
          FUN_1100cc55(&local_1a,local_20,param_1,&local_18);
          if (((uVar3 & 8) != 0) && ((uVar3 & 4) == 0)) {
            FUN_1100cc24(0x30,iVar11,param_1,&local_18);
          }
          if ((local_28 == 0) || ((int)local_10 < 1)) {
            FUN_1100cc55((char *)local_c,(int)local_10,param_1,&local_18);
          }
          else {
            puVar6 = local_10;
            pWVar7 = local_c;
            do {
              puVar6 = puVar6 + -1;
              WVar1 = *pWVar7;
              pWVar7 = pWVar7 + 1;
              iVar9 = FUN_1100e41b(local_3c,WVar1);
              if (iVar9 < 1) break;
              FUN_1100cc55(local_3c,iVar9,param_1,&local_18);
            } while (puVar6 != (undefined1 *)0x0);
          }
          if ((local_8 & 4) != 0) {
            FUN_1100cc24(0x20,iVar11,param_1,&local_18);
          }
        }
      }
      bVar10 = *param_2;
      if (bVar10 == 0) {
        return local_18;
      }
      pbVar2 = param_2;
    }
  }
  return local_18;
}


// ---- 1100cbef FUN_1100cbef  (called by: FUN_1100c4ae@1100c4ae, FUN_1100cc24@1100cc24, FUN_1100cc55@1100cc55)

void __cdecl FUN_1100cbef(uint param_1,int *param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = param_2 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    uVar2 = FUN_1100b359(param_1,param_2);
  }
  else {
    *(undefined1 *)*param_2 = (undefined1)param_1;
    *param_2 = *param_2 + 1;
    uVar2 = param_1 & 0xff;
  }
  if (uVar2 == 0xffffffff) {
    *param_3 = -1;
    return;
  }
  *param_3 = *param_3 + 1;
  return;
}


// ---- 1100cc24 FUN_1100cc24  (called by: FUN_1100c4ae@1100c4ae)

void __cdecl FUN_1100cc24(uint param_1,int param_2,int *param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    FUN_1100cbef(param_1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}


// ---- 1100cc55 FUN_1100cc55  (called by: FUN_1100c4ae@1100c4ae)

void __cdecl FUN_1100cc55(char *param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;
  
  if (0 < param_2) {
    do {
      param_2 = param_2 + -1;
      cVar1 = *param_1;
      param_1 = param_1 + 1;
      FUN_1100cbef((int)cVar1,param_3,param_4);
      if (*param_4 == -1) {
        return;
      }
    } while (0 < param_2);
  }
  return;
}


// ---- 1100cc8d FUN_1100cc8d  (called by: FUN_1100c4ae@1100c4ae)

undefined4 __cdecl FUN_1100cc8d(int *param_1)

{
  *param_1 = *param_1 + 4;
  return *(undefined4 *)(*param_1 + -4);
}


// ---- 1100cc9a FUN_1100cc9a  (called by: FUN_1100c4ae@1100c4ae)

undefined8 __cdecl FUN_1100cc9a(int *param_1)

{
  *param_1 = *param_1 + 8;
  return *(undefined8 *)(*param_1 + -8);
}


// ---- 1100ccaa FUN_1100ccaa  (called by: FUN_1100c4ae@1100c4ae)

undefined4 __cdecl FUN_1100ccaa(int *param_1)

{
  *param_1 = *param_1 + 4;
  return CONCAT22((short)((uint)*param_1 >> 0x10),*(undefined2 *)(*param_1 + -4));
}


// ---- 1100ccb8 FUN_1100ccb8  (called by: FUN_11009430@11009430)

byte * __cdecl FUN_1100ccb8(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  
  if (param_1 < param_2) {
    if (DAT_11019eac == 0) {
      pbVar1 = param_2 + -1;
    }
    else {
      FUN_11009f49(0x19);
      pbVar1 = param_2 + -1;
      if ((*(byte *)((int)&DAT_11019fc0 + param_2[-1] + 1) & 4) == 0) {
        do {
          pbVar1 = pbVar1 + -1;
          if (pbVar1 < param_1) break;
        } while ((*(byte *)((int)&DAT_11019fc0 + *pbVar1 + 1) & 4) != 0);
        FUN_11009faa(0x19);
        pbVar1 = param_2 + (-1 - ((int)param_2 - (int)pbVar1 & 1U));
      }
      else {
        FUN_11009faa(0x19);
        pbVar1 = param_2 + -2;
      }
    }
  }
  else {
    pbVar1 = (byte *)0x0;
  }
  return pbVar1;
}


// ---- 1100cd25 FUN_1100cd25  (called by: FUN_1100d0fd@1100d0fd)

undefined4 __cdecl FUN_1100cd25(int param_1)

{
  BYTE *pBVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  UINT CodePage;
  UINT *pUVar5;
  BOOL BVar6;
  uint uVar7;
  uint uVar8;
  BYTE *pBVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  byte *pbVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  _cpinfo local_1c;
  uint local_8;
  
  FUN_11009f49(0x19);
  CodePage = FUN_1100ced2(param_1);
  if (CodePage != DAT_11019e90) {
    if (CodePage != 0) {
      iVar12 = 0;
      pUVar5 = &DAT_11015aa8;
LAB_1100cd62:
      if (*pUVar5 != CodePage) goto code_r0x1100cd66;
      local_8 = 0;
      puVar15 = &DAT_11019fc0;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      iVar12 = iVar12 * 0x30;
      *(undefined1 *)puVar15 = 0;
      pbVar13 = (byte *)(iVar12 + 0x11015ab8);
      do {
        bVar3 = *pbVar13;
        pbVar11 = pbVar13;
        while ((bVar3 != 0 && (bVar3 = pbVar11[1], bVar3 != 0))) {
          uVar8 = (uint)*pbVar11;
          if (uVar8 <= bVar3) {
            bVar4 = (&DAT_11015aa0)[local_8];
            do {
              pbVar2 = (byte *)((int)&DAT_11019fc0 + uVar8 + 1);
              *pbVar2 = *pbVar2 | bVar4;
              uVar8 = uVar8 + 1;
            } while (uVar8 <= bVar3);
          }
          pbVar11 = pbVar11 + 2;
          bVar3 = *pbVar11;
        }
        local_8 = local_8 + 1;
        pbVar13 = pbVar13 + 8;
      } while (local_8 < 4);
      DAT_11019eac = 1;
      DAT_11019e90 = CodePage;
      DAT_1101a0c4 = FUN_1100cf1c(CodePage);
      DAT_11019ea0 = *(undefined4 *)(iVar12 + 0x11015aac);
      DAT_11019ea4 = *(undefined4 *)(iVar12 + 0x11015ab0);
      DAT_11019ea8 = *(undefined4 *)(iVar12 + 0x11015ab4);
      goto LAB_1100ceb6;
    }
    goto LAB_1100ceb1;
  }
  goto LAB_1100cd4c;
code_r0x1100cd66:
  pUVar5 = pUVar5 + 0xc;
  iVar12 = iVar12 + 1;
  if (0x11015b97 < (int)pUVar5) goto code_r0x1100cd71;
  goto LAB_1100cd62;
code_r0x1100cd71:
  BVar6 = GetCPInfo(CodePage,&local_1c);
  uVar8 = 1;
  if (BVar6 == 1) {
    DAT_1101a0c4 = 0;
    puVar15 = &DAT_11019fc0;
    for (iVar12 = 0x40; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar15 = 0;
      puVar15 = puVar15 + 1;
    }
    *(undefined1 *)puVar15 = 0;
    if (local_1c.MaxCharSize < 2) {
      DAT_11019eac = 0;
      DAT_11019e90 = CodePage;
    }
    else {
      DAT_11019e90 = CodePage;
      if (local_1c.LeadByte[0] != '\0') {
        pBVar9 = local_1c.LeadByte + 1;
        do {
          bVar3 = *pBVar9;
          if (bVar3 == 0) break;
          for (uVar7 = (uint)pBVar9[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
            pbVar13 = (byte *)((int)&DAT_11019fc0 + uVar7 + 1);
            *pbVar13 = *pbVar13 | 4;
          }
          pBVar1 = pBVar9 + 1;
          pBVar9 = pBVar9 + 2;
        } while (*pBVar1 != 0);
      }
      do {
        pbVar13 = (byte *)((int)&DAT_11019fc0 + uVar8 + 1);
        *pbVar13 = *pbVar13 | 8;
        uVar8 = uVar8 + 1;
      } while (uVar8 < 0xff);
      DAT_1101a0c4 = FUN_1100cf1c(CodePage);
      DAT_11019eac = 1;
    }
    DAT_11019ea0 = 0;
    DAT_11019ea4 = 0;
    DAT_11019ea8 = 0;
  }
  else {
    if (DAT_11019bdc == 0) {
      uVar14 = 0xffffffff;
      goto LAB_1100cec3;
    }
LAB_1100ceb1:
    FUN_1100cf4f();
  }
LAB_1100ceb6:
  FUN_1100cf78();
LAB_1100cd4c:
  uVar14 = 0;
LAB_1100cec3:
  FUN_11009faa(0x19);
  return uVar14;
}


// ---- 1100ced2 FUN_1100ced2  (called by: FUN_1100cd25@1100cd25)

int __cdecl FUN_1100ced2(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_11019bdc = 1;
                    /* WARNING: Could not recover jumptable at 0x1100ceec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_11019bdc = 1;
                    /* WARNING: Could not recover jumptable at 0x1100cf01. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_11019d0c;
  }
  DAT_11019bdc = (uint)bVar2;
  return param_1;
}


// ---- 1100cf1c FUN_1100cf1c  (called by: FUN_1100cd25@1100cd25)

undefined4 __cdecl FUN_1100cf1c(int param_1)

{
  if (param_1 == 0x3a4) {
    return 0x411;
  }
  if (param_1 == 0x3a8) {
    return 0x804;
  }
  if (param_1 == 0x3b5) {
    return 0x412;
  }
  if (param_1 == 0x3b6) {
    return 0x404;
  }
  return 0;
}


// ---- 1100cf4f FUN_1100cf4f  (called by: FUN_1100cd25@1100cd25)

void FUN_1100cf4f(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_11019fc0;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_11019e90 = 0;
  DAT_11019eac = 0;
  DAT_1101a0c4 = 0;
  DAT_11019ea0 = 0;
  DAT_11019ea4 = 0;
  DAT_11019ea8 = 0;
  return;
}


// ---- 1100cf78 FUN_1100cf78  (called by: FUN_1100cd25@1100cd25)

void FUN_1100cf78(void)

{
  byte *pbVar1;
  BOOL BVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  undefined1 uVar8;
  BYTE *pBVar9;
  CHAR *pCVar10;
  WORD local_518 [256];
  WCHAR local_318 [128];
  WCHAR local_218 [128];
  CHAR local_118 [256];
  _cpinfo local_18;
  
  BVar2 = GetCPInfo(DAT_11019e90,&local_18);
  if (BVar2 == 1) {
    uVar3 = 0;
    do {
      local_118[uVar3] = (CHAR)uVar3;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
    local_118[0] = ' ';
    if (local_18.LeadByte[0] != 0) {
      pBVar9 = local_18.LeadByte + 1;
      do {
        uVar3 = (uint)local_18.LeadByte[0];
        if (uVar3 <= *pBVar9) {
          uVar5 = (*pBVar9 - uVar3) + 1;
          uVar6 = uVar5 >> 2;
          pCVar10 = local_118 + uVar3;
          while (uVar6 != 0) {
            uVar6 = uVar6 - 1;
            builtin_memcpy(pCVar10,"    ",4);
            pCVar10 = pCVar10 + 4;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *pCVar10 = ' ';
            pCVar10 = pCVar10 + 1;
          }
        }
        local_18.LeadByte[0] = pBVar9[1];
        pBVar9 = pBVar9 + 2;
      } while (local_18.LeadByte[0] != 0);
    }
    FUN_1100e814(1,local_118,0x100,local_518,DAT_11019e90,DAT_1101a0c4,0);
    FUN_1100e5c5(DAT_1101a0c4,0x100,local_118,0x100,local_218,0x100,DAT_11019e90,0);
    FUN_1100e5c5(DAT_1101a0c4,0x200,local_118,0x100,local_318,0x100,DAT_11019e90,0);
    uVar3 = 0;
    puVar7 = local_518;
    do {
      if ((*puVar7 & 1) == 0) {
        if ((*puVar7 & 2) != 0) {
          pbVar1 = (byte *)((int)&DAT_11019fc0 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          uVar8 = *(undefined1 *)((int)local_318 + uVar3);
          goto LAB_1100d084;
        }
        (&DAT_11019ec0)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_11019fc0 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        uVar8 = *(undefined1 *)((int)local_218 + uVar3);
LAB_1100d084:
        (&DAT_11019ec0)[uVar3] = uVar8;
      }
      uVar3 = uVar3 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar3 < 0x100);
  }
  else {
    uVar3 = 0;
    do {
      if ((uVar3 < 0x41) || (0x5a < uVar3)) {
        if ((0x60 < uVar3) && (uVar3 < 0x7b)) {
          pbVar1 = (byte *)((int)&DAT_11019fc0 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          cVar4 = (char)uVar3 + -0x20;
          goto LAB_1100d0ce;
        }
        (&DAT_11019ec0)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_11019fc0 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        cVar4 = (char)uVar3 + ' ';
LAB_1100d0ce:
        (&DAT_11019ec0)[uVar3] = cVar4;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
  }
  return;
}


// ---- 1100d0fd FUN_1100d0fd  (called by: FUN_1100d1b3@1100d1b3, FUN_1100d26c@1100d26c)

void FUN_1100d0fd(void)

{
  if (DAT_1101b224 == 0) {
    FUN_1100cd25(-3);
    DAT_1101b224 = 1;
  }
  return;
}


// ---- 1100d119 FUN_1100d119  (called by: FUN_110094c1@110094c1)

byte * __cdecl FUN_1100d119(byte *param_1,byte *param_2,size_t param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  if (DAT_11019eac == 0) {
    param_1 = (byte *)_strncpy((char *)param_1,(char *)param_2,param_3);
  }
  else {
    FUN_11009f49(0x19);
    uVar4 = 0;
    pbVar6 = param_1;
    if (param_3 != 0) {
      pbVar5 = param_1;
      do {
        bVar1 = *param_2;
        uVar4 = param_3 - 1;
        bVar2 = *(byte *)((int)&DAT_11019fc0 + bVar1 + 1);
        *pbVar5 = bVar1;
        if ((bVar2 & 4) == 0) {
          pbVar6 = pbVar5 + 1;
          param_2 = param_2 + 1;
          if (bVar1 == 0) goto LAB_1100d18a;
        }
        else {
          pbVar6 = pbVar5 + 1;
          if (uVar4 == 0) {
            *pbVar5 = 0;
            goto LAB_1100d18a;
          }
          bVar1 = param_2[1];
          uVar4 = param_3 - 2;
          *pbVar6 = bVar1;
          pbVar6 = pbVar5 + 2;
          param_2 = param_2 + 2;
          if (bVar1 == 0) {
            *pbVar5 = 0;
            goto LAB_1100d18a;
          }
        }
        param_3 = uVar4;
        pbVar5 = pbVar6;
      } while (uVar4 != 0);
      uVar4 = 0;
    }
LAB_1100d18a:
    if (uVar4 != 0) {
      for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        pbVar6[0] = 0;
        pbVar6[1] = 0;
        pbVar6[2] = 0;
        pbVar6[3] = 0;
        pbVar6 = pbVar6 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pbVar6 = 0;
        pbVar6 = pbVar6 + 1;
      }
    }
    FUN_11009faa(0x19);
  }
  return param_1;
}


// ---- 1100d1b3 FUN_1100d1b3  (called by: FUN_110099c5@110099c5)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1100d1b3(void)

{
  char cVar1;
  size_t sVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  uint *puVar6;
  
  if (DAT_1101b224 == 0) {
    FUN_1100d0fd();
  }
  iVar5 = 0;
  for (puVar6 = DAT_11019b1c; (char)*puVar6 != '\0'; puVar6 = (uint *)((int)puVar6 + sVar2 + 1)) {
    if ((char)*puVar6 != '=') {
      iVar5 = iVar5 + 1;
    }
    sVar2 = _strlen((char *)puVar6);
  }
  puVar3 = _malloc(iVar5 * 4 + 4);
  _DAT_11019b4c = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = (char)*DAT_11019b1c;
  puVar6 = DAT_11019b1c;
  while (cVar1 != '\0') {
    sVar2 = _strlen((char *)puVar6);
    if ((char)*puVar6 != '=') {
      pvVar4 = _malloc(sVar2 + 1);
      *puVar3 = pvVar4;
      if (pvVar4 == (void *)0x0) {
        __amsg_exit(9);
      }
      FUN_11009340((uint *)*puVar3,puVar6);
      puVar3 = puVar3 + 1;
    }
    puVar6 = (uint *)((int)puVar6 + sVar2 + 1);
    cVar1 = (char)*puVar6;
  }
  FUN_110085b8(DAT_11019b1c);
  DAT_11019b1c = (uint *)0x0;
  *puVar3 = 0;
  _DAT_1101b220 = 1;
  return;
}


// ---- 1100d26c FUN_1100d26c  (called by: FUN_110099c5@110099c5)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1100d26c(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_c;
  int local_8;
  
  if (DAT_1101b224 == 0) {
    FUN_1100d0fd();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_11019be0,0x104);
  _DAT_11019b5c = &DAT_11019be0;
  pbVar2 = &DAT_11019be0;
  if (*DAT_1101b234 != 0) {
    pbVar2 = DAT_1101b234;
  }
  FUN_1100d305(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_c);
  puVar1 = _malloc(local_c + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_1100d305(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_c);
  _DAT_11019b44 = puVar1;
  _DAT_11019b40 = local_8 + -1;
  return;
}


// ---- 1100d305 FUN_1100d305  (called by: FUN_1100d26c@1100d26c)

void __cdecl FUN_1100d305(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  byte *pbVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  *param_5 = 0;
  *param_4 = 1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_3;
    param_2 = param_2 + 1;
  }
  if (*param_1 == 0x22) {
    while( true ) {
      bVar1 = param_1[1];
      pbVar4 = param_1 + 1;
      if ((bVar1 == 0x22) || (bVar1 == 0)) break;
      if (((*(byte *)((int)&DAT_11019fc0 + bVar1 + 1) & 4) != 0) &&
         (*param_5 = *param_5 + 1, param_3 != (byte *)0x0)) {
        *param_3 = *pbVar4;
        param_3 = param_3 + 1;
        pbVar4 = param_1 + 2;
      }
      *param_5 = *param_5 + 1;
      param_1 = pbVar4;
      if (param_3 != (byte *)0x0) {
        *param_3 = *pbVar4;
        param_3 = param_3 + 1;
      }
    }
    *param_5 = *param_5 + 1;
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    if (*pbVar4 == 0x22) {
      pbVar4 = param_1 + 2;
    }
  }
  else {
    do {
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *param_1;
        param_3 = param_3 + 1;
      }
      bVar1 = *param_1;
      pbVar4 = param_1 + 1;
      if ((*(byte *)((int)&DAT_11019fc0 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar4;
          param_3 = param_3 + 1;
        }
        pbVar4 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_1100d3b0;
      param_1 = pbVar4;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_1100d3b0:
      pbVar4 = pbVar4 + -1;
    }
    else if (param_3 != (byte *)0x0) {
      param_3[-1] = 0;
    }
  }
  bVar2 = false;
  puVar6 = param_2;
  while (*pbVar4 != 0) {
    for (; (*pbVar4 == 0x20 || (*pbVar4 == 9)); pbVar4 = pbVar4 + 1) {
    }
    if (*pbVar4 == 0) break;
    if (puVar6 != (undefined4 *)0x0) {
      *puVar6 = param_3;
      puVar6 = puVar6 + 1;
      param_2 = puVar6;
    }
    *param_4 = *param_4 + 1;
    while( true ) {
      bVar3 = true;
      uVar5 = 0;
      for (; *pbVar4 == 0x5c; pbVar4 = pbVar4 + 1) {
        uVar5 = uVar5 + 1;
      }
      if (*pbVar4 == 0x22) {
        if ((uVar5 & 1) == 0) {
          if ((!bVar2) || (pbVar4[1] != 0x22)) {
            bVar3 = false;
          }
          else {
            pbVar4 = pbVar4 + 1;
          }
          bVar2 = !bVar2;
          puVar6 = param_2;
        }
        uVar5 = uVar5 >> 1;
      }
      if (uVar5 != 0) {
        do {
          if (param_3 != (byte *)0x0) {
            *param_3 = 0x5c;
            param_3 = param_3 + 1;
          }
          *param_5 = *param_5 + 1;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
      bVar1 = *pbVar4;
      if ((bVar1 == 0) || ((!bVar2 && ((bVar1 == 0x20 || (bVar1 == 9)))))) break;
      if (bVar3) {
        if (param_3 == (byte *)0x0) {
          if ((*(byte *)((int)&DAT_11019fc0 + bVar1 + 1) & 4) != 0) {
            pbVar4 = pbVar4 + 1;
            *param_5 = *param_5 + 1;
          }
        }
        else {
          if ((*(byte *)((int)&DAT_11019fc0 + bVar1 + 1) & 4) != 0) {
            *param_3 = bVar1;
            param_3 = param_3 + 1;
            pbVar4 = pbVar4 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_3 = *pbVar4;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      pbVar4 = pbVar4 + 1;
    }
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    *param_5 = *param_5 + 1;
  }
  if (puVar6 != (undefined4 *)0x0) {
    *puVar6 = 0;
  }
  *param_4 = *param_4 + 1;
  return;
}


// ---- 1100d4b9 FUN_1100d4b9  (called by: FUN_110099c5@110099c5)

LPSTR FUN_1100d4b9(void)

{
  char cVar1;
  WCHAR WVar2;
  WCHAR *pWVar3;
  WCHAR *pWVar4;
  int iVar5;
  size_t _Size;
  LPSTR pCVar6;
  char *pcVar8;
  char *pcVar7;
  LPWCH lpWideCharStr;
  LPCH pCVar9;
  LPSTR local_8;
  
  local_8 = (LPSTR)0x0;
  lpWideCharStr = (LPWCH)0x0;
  pCVar9 = (LPCH)0x0;
  if (DAT_11019ce4 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr != (LPWCH)0x0) {
      DAT_11019ce4 = 1;
      goto LAB_1100d510;
    }
    pCVar9 = GetEnvironmentStrings();
    if (pCVar9 == (LPCH)0x0) {
      return (LPSTR)0x0;
    }
    DAT_11019ce4 = 2;
  }
  else {
    if (DAT_11019ce4 == 1) {
LAB_1100d510:
      if ((lpWideCharStr == (LPWCH)0x0) &&
         (lpWideCharStr = GetEnvironmentStringsW(), lpWideCharStr == (LPWCH)0x0)) {
        return (LPSTR)0x0;
      }
      WVar2 = *lpWideCharStr;
      pWVar4 = lpWideCharStr;
      while (WVar2 != L'\0') {
        do {
          pWVar3 = pWVar4;
          pWVar4 = pWVar3 + 1;
        } while (*pWVar4 != L'\0');
        pWVar4 = pWVar3 + 2;
        WVar2 = *pWVar4;
      }
      iVar5 = ((int)pWVar4 - (int)lpWideCharStr >> 1) + 1;
      _Size = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
      if ((_Size != 0) && (pCVar6 = _malloc(_Size), pCVar6 != (LPSTR)0x0)) {
        iVar5 = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,pCVar6,_Size,(LPCSTR)0x0,(LPBOOL)0x0);
        local_8 = pCVar6;
        if (iVar5 == 0) {
          FUN_110085b8(pCVar6);
          local_8 = (LPSTR)0x0;
        }
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return local_8;
    }
    if (DAT_11019ce4 != 2) {
      return (LPSTR)0x0;
    }
  }
  if ((pCVar9 == (LPCH)0x0) && (pCVar9 = GetEnvironmentStrings(), pCVar9 == (LPCH)0x0)) {
    return (LPSTR)0x0;
  }
  cVar1 = *pCVar9;
  pcVar7 = pCVar9;
  while (cVar1 != '\0') {
    do {
      pcVar8 = pcVar7;
      pcVar7 = pcVar8 + 1;
    } while (*pcVar7 != '\0');
    pcVar7 = pcVar8 + 2;
    cVar1 = *pcVar7;
  }
  pCVar6 = _malloc((size_t)(pcVar7 + (1 - (int)pCVar9)));
  if (pCVar6 == (LPSTR)0x0) {
    pCVar6 = (LPSTR)0x0;
  }
  else {
    FUN_11009690((undefined4 *)pCVar6,(undefined4 *)pCVar9,(uint)(pcVar7 + (1 - (int)pCVar9)));
  }
  FreeEnvironmentStringsA(pCVar9);
  return pCVar6;
}


// ---- 1100d5eb FUN_1100d5eb  (called by: __amsg_exit@11009b3b)

void FUN_1100d5eb(void)

{
  if ((DAT_11019b24 == 1) || ((DAT_11019b24 == 0 && (DAT_11019b28 == 1)))) {
    FUN_1100d624(0xfc);
    if (DAT_11019ce8 != (code *)0x0) {
      (*DAT_11019ce8)();
    }
    FUN_1100d624(0xff);
  }
  return;
}


// ---- 1100d624 FUN_1100d624  (called by: FUN_1100d5eb@1100d5eb, FUN_1100e404@1100e404, __amsg_exit@11009b3b)

void __cdecl FUN_1100d624(DWORD param_1)

{
  undefined4 *puVar1;
  DWORD *pDVar2;
  DWORD DVar3;
  size_t sVar4;
  HANDLE hFile;
  int iVar5;
  uint *_Dest;
  undefined1 auStackY_1e3 [7];
  LPCVOID lpBuffer;
  LPOVERLAPPED lpOverlapped;
  uint local_1a8 [65];
  uint local_a4 [40];
  
  iVar5 = 0;
  pDVar2 = &DAT_11015b98;
  do {
    if (param_1 == *pDVar2) break;
    pDVar2 = pDVar2 + 2;
    iVar5 = iVar5 + 1;
  } while ((int)pDVar2 < 0x11015c28);
  if (param_1 == (&DAT_11015b98)[iVar5 * 2]) {
    if ((DAT_11019b24 == 1) || ((DAT_11019b24 == 0 && (DAT_11019b28 == 1)))) {
      pDVar2 = &param_1;
      puVar1 = (undefined4 *)(iVar5 * 8 + 0x11015b9c);
      lpOverlapped = (LPOVERLAPPED)0x0;
      sVar4 = _strlen((char *)*puVar1);
      lpBuffer = (LPCVOID)*puVar1;
      hFile = GetStdHandle(0xfffffff4);
      WriteFile(hFile,lpBuffer,sVar4,pDVar2,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_1a8,0x104);
      if (DVar3 == 0) {
        FUN_11009340(local_1a8,(uint *)"<program name unknown>");
      }
      _Dest = local_1a8;
      sVar4 = _strlen((char *)local_1a8);
      if (0x3c < sVar4 + 1) {
        sVar4 = _strlen((char *)local_1a8);
        _Dest = (uint *)(auStackY_1e3 + sVar4);
        _strncpy((char *)_Dest,"...",3);
      }
      FUN_11009340(local_a4,(uint *)"Runtime Error!\n\nProgram: ");
      FUN_11009350(local_a4,_Dest);
      FUN_11009350(local_a4,(uint *)&DAT_110107e8);
      FUN_11009350(local_a4,*(uint **)(iVar5 * 8 + 0x11015b9c));
      auStackY_1e3._3_4_ = 0x1100d748;
      FUN_1100ea5e(local_a4,"Microsoft Visual C++ Runtime Library",0x12010);
    }
  }
  return;
}


// ---- 1100d780 FUN_1100d780  (called by: FUN_1100a028@1100a028, FUN_1100bc72@1100bc72)

undefined4 * __cdecl FUN_1100d780(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {
    puVar3 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar4 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = param_3 >> 2;
      uVar2 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return param_1;
        case 2:
          goto switchD_1100d937_caseD_2;
        case 3:
          goto switchD_1100d937_caseD_3;
        }
        goto switchD_1100d937_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_1100d937_caseD_0;
      case 1:
        goto switchD_1100d937_caseD_1;
      case 2:
        goto switchD_1100d937_caseD_2;
      case 3:
        goto switchD_1100d937_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_1100d937_caseD_2;
            case 3:
              goto switchD_1100d937_caseD_3;
            }
            goto switchD_1100d937_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_1100d937_caseD_2;
            case 3:
              goto switchD_1100d937_caseD_3;
            }
            goto switchD_1100d937_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_1100d937_caseD_2;
            case 3:
              goto switchD_1100d937_caseD_3;
            }
            goto switchD_1100d937_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_1100d937_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_1100d937_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_1100d937_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_1100d937_caseD_0:
    return param_1;
  }
  puVar3 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    uVar2 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return param_1;
      case 2:
        goto switchD_1100d7b5_caseD_2;
      case 3:
        goto switchD_1100d7b5_caseD_3;
      }
      goto switchD_1100d7b5_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_1100d7b5_caseD_0;
    case 1:
      goto switchD_1100d7b5_caseD_1;
    case 2:
      goto switchD_1100d7b5_caseD_2;
    case 3:
      goto switchD_1100d7b5_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (undefined4 *)((int)param_2 + 3);
        puVar3 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_1100d7b5_caseD_2;
          case 3:
            goto switchD_1100d7b5_caseD_3;
          }
          goto switchD_1100d7b5_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (undefined4 *)((int)param_2 + 2);
        puVar3 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_1100d7b5_caseD_2;
          case 3:
            goto switchD_1100d7b5_caseD_3;
          }
          goto switchD_1100d7b5_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_1100d7b5_caseD_2;
          case 3:
            goto switchD_1100d7b5_caseD_3;
          }
          goto switchD_1100d7b5_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = param_2[uVar1 - 7];
  case 6:
    puVar3[uVar1 - 6] = param_2[uVar1 - 6];
  case 5:
    puVar3[uVar1 - 5] = param_2[uVar1 - 5];
  case 4:
    puVar3[uVar1 - 4] = param_2[uVar1 - 4];
  case 3:
    puVar3[uVar1 - 3] = param_2[uVar1 - 3];
  case 2:
    puVar3[uVar1 - 2] = param_2[uVar1 - 2];
  case 1:
    puVar3[uVar1 - 1] = param_2[uVar1 - 1];
    param_2 = param_2 + uVar1;
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_1100d7b5_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_1100d7b5_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_1100d7b5_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_1100d7b5_caseD_0:
  return param_1;
}


// ---- 1100dab5 FUN_1100dab5  (called by: FUN_1100bf0c@1100bf0c, FUN_1100bf91@1100bf91)

int * __cdecl FUN_1100dab5(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint *_Size;
  uint *puVar3;
  
  _Size = (uint *)(param_1 * param_2);
  puVar3 = _Size;
  if (_Size < (uint *)0xffffffe1) {
    if (_Size == (uint *)0x0) {
      puVar3 = (uint *)0x1;
    }
    puVar3 = (uint *)((int)puVar3 + 0xfU & 0xfffffff0);
  }
  do {
    if (puVar3 < (uint *)0xffffffe1) {
      if (_Size <= DAT_11015674) {
        FUN_11009f49(9);
        piVar1 = FUN_1100a353(_Size);
        FUN_11009faa(9);
        if (piVar1 != (int *)0x0) {
          _memset(piVar1,0,(size_t)_Size);
          return piVar1;
        }
      }
      piVar1 = HeapAlloc(DAT_1101b21c,8,(SIZE_T)puVar3);
      if (piVar1 != (int *)0x0) {
        return piVar1;
      }
    }
    if (DAT_11019b70 == 0) {
      return (int *)0x0;
    }
    iVar2 = FUN_11009de8(puVar3);
  } while (iVar2 != 0);
  return (int *)0x0;
}


// ---- 1100dbc3 FUN_1100dbc3  (called by: FUN_1100df11@1100df11)

uint FUN_1100dbc3(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  int local_8;
  int local_4;
  
  uVar4 = 0xffffffff;
  FUN_11009f49(0x12);
  local_8 = 0;
  local_4 = 0;
  piVar3 = &DAT_1101a0e0;
  while (puVar2 = (undefined4 *)*piVar3, puVar1 = puVar2, puVar2 != (undefined4 *)0x0) {
    for (; puVar2 < puVar1 + 0x120; puVar2 = puVar2 + 9) {
      if ((*(byte *)(puVar2 + 1) & 1) == 0) {
        if (puVar2[2] == 0) {
          FUN_11009f49(0x11);
          if (puVar2[2] == 0) {
            InitializeCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
            puVar2[2] = puVar2[2] + 1;
          }
          FUN_11009faa(0x11);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
        if ((*(byte *)(puVar2 + 1) & 1) == 0) {
          *puVar2 = 0xffffffff;
          uVar4 = ((int)puVar2 - *piVar3) / 0x24 + local_4;
          if (uVar4 != 0xffffffff) goto LAB_1100dcd5;
          break;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
      }
      puVar1 = (undefined4 *)*piVar3;
    }
    local_4 = local_4 + 0x20;
    piVar3 = piVar3 + 1;
    local_8 = local_8 + 1;
    if (0x1101a1df < (int)piVar3) goto LAB_1100dcd5;
  }
  puVar2 = _malloc(0x480);
  if (puVar2 != (undefined4 *)0x0) {
    DAT_1101a1e0 = DAT_1101a1e0 + 0x20;
    (&DAT_1101a0e0)[local_8] = puVar2;
    puVar1 = puVar2;
    for (; puVar2 < puVar1 + 0x120; puVar2 = puVar2 + 9) {
      *(undefined1 *)(puVar2 + 1) = 0;
      *puVar2 = 0xffffffff;
      puVar2[2] = 0;
      *(undefined1 *)((int)puVar2 + 5) = 10;
      puVar1 = (undefined4 *)(&DAT_1101a0e0)[local_8];
    }
    uVar4 = local_8 << 5;
    FUN_1100de23(uVar4);
  }
LAB_1100dcd5:
  FUN_11009faa(0x12);
  return uVar4;
}


// ---- 1100dce6 FUN_1100dce6  (called by: FUN_1100df11@1100df11)

undefined4 __cdecl FUN_1100dce6(uint param_1,HANDLE param_2)

{
  DWORD *pDVar1;
  int iVar2;
  DWORD nStdHandle;
  
  if (param_1 < DAT_1101a1e0) {
    iVar2 = (param_1 & 0x1f) * 0x24;
    if (*(int *)((&DAT_1101a0e0)[(int)param_1 >> 5] + iVar2) == -1) {
      if (DAT_11019b28 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_1100dd3f;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,param_2);
      }
LAB_1100dd3f:
      *(HANDLE *)((&DAT_1101a0e0)[(int)param_1 >> 5] + iVar2) = param_2;
      return 0;
    }
  }
  pDVar1 = FUN_1100addc();
  *pDVar1 = 9;
  pDVar1 = FUN_1100ade5();
  *pDVar1 = 0;
  return 0xffffffff;
}


// ---- 1100dd62 FUN_1100dd62  (called by: FUN_1100acbb@1100acbb)

undefined4 __cdecl FUN_1100dd62(uint param_1)

{
  int *piVar1;
  DWORD *pDVar2;
  int iVar3;
  DWORD nStdHandle;
  
  if (param_1 < DAT_1101a1e0) {
    iVar3 = (param_1 & 0x1f) * 0x24;
    piVar1 = (int *)((&DAT_1101a0e0)[(int)param_1 >> 5] + iVar3);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_11019b28 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_1100ddbe;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_1100ddbe:
      *(undefined4 *)((&DAT_1101a0e0)[(int)param_1 >> 5] + iVar3) = 0xffffffff;
      return 0;
    }
  }
  pDVar2 = FUN_1100addc();
  *pDVar2 = 9;
  pDVar2 = FUN_1100ade5();
  *pDVar2 = 0;
  return 0xffffffff;
}


// ---- 1100dde1 FUN_1100dde1  (called by: FUN_1100acbb@1100acbb, FUN_1100ae53@1100ae53, FUN_1100b0d6@1100b0d6, FUN_1100eae7@1100eae7)

undefined4 __cdecl FUN_1100dde1(uint param_1)

{
  DWORD *pDVar1;
  
  if ((param_1 < DAT_1101a1e0) &&
     ((*(byte *)((&DAT_1101a0e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    return *(undefined4 *)((&DAT_1101a0e0)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24);
  }
  pDVar1 = FUN_1100addc();
  *pDVar1 = 9;
  pDVar1 = FUN_1100ade5();
  *pDVar1 = 0;
  return 0xffffffff;
}


// ---- 1100de23 FUN_1100de23  (called by: FUN_1100ac5e@1100ac5e, FUN_1100adee@1100adee, FUN_1100b0d6@1100b0d6, FUN_1100b169@1100b169, FUN_1100c270@1100c270, FUN_1100dbc3@1100dbc3)

void __cdecl FUN_1100de23(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (param_1 & 0x1f) * 0x24;
  iVar1 = (&DAT_1101a0e0)[(int)param_1 >> 5] + iVar2;
  if (*(int *)(iVar1 + 8) == 0) {
    FUN_11009f49(0x11);
    if (*(int *)(iVar1 + 8) == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xc));
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    }
    FUN_11009faa(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((&DAT_1101a0e0)[(int)param_1 >> 5] + 0xc + iVar2));
  return;
}


// ---- 1100de82 FUN_1100de82  (called by: FUN_1100ac5e@1100ac5e, FUN_1100adee@1100adee, FUN_1100b0d6@1100b0d6, FUN_1100b169@1100b169, FUN_1100c270@1100c270, FUN_1100df11@1100df11)

void __cdecl FUN_1100de82(uint param_1)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_1101a0e0)[(int)param_1 >> 5] + 0xc + (param_1 & 0x1f) * 0x24));
  return;
}


// ---- 1100dea4 FUN_1100dea4  (called by: FUN_1100b359@1100b359, FUN_1100c194@1100c194)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1100dea4(undefined4 *param_1)

{
  void *pvVar1;
  
  _DAT_11019bd8 = _DAT_11019bd8 + 1;
  pvVar1 = _malloc(0x1000);
  param_1[2] = pvVar1;
  if (pvVar1 == (void *)0x0) {
    param_1[3] = param_1[3] | 4;
    param_1[2] = param_1 + 5;
    param_1[6] = 2;
  }
  else {
    param_1[3] = param_1[3] | 8;
    param_1[6] = 0x1000;
  }
  param_1[1] = 0;
  *param_1 = param_1[2];
  return;
}


// ---- 1100dee8 FUN_1100dee8  (called by: FUN_1100b359@1100b359)

byte __cdecl FUN_1100dee8(uint param_1)

{
  if (param_1 < DAT_1101a1e0) {
    return *(byte *)((&DAT_1101a0e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0x40;
  }
  return 0;
}


// ---- 1100df11 FUN_1100df11  (called by: FUN_1100b471@1100b471)

uint __cdecl FUN_1100df11(LPCSTR param_1,uint param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  DWORD *pDVar4;
  HANDLE hFile;
  DWORD DVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  _SECURITY_ATTRIBUTES local_20;
  DWORD local_14;
  DWORD local_10;
  DWORD local_c;
  byte local_5;
  
  bVar8 = (param_2 & 0x80) == 0;
  local_20.nLength = 0xc;
  local_20.lpSecurityDescriptor = (LPVOID)0x0;
  if (bVar8) {
    local_5 = 0;
  }
  else {
    local_5 = 0x10;
  }
  local_20.bInheritHandle = (BOOL)bVar8;
  if (((param_2 & 0x8000) == 0) && (((param_2 & 0x4000) != 0 || (DAT_11019d28 != 0x8000)))) {
    local_5 = local_5 | 0x80;
  }
  uVar2 = param_2 & 3;
  if (uVar2 == 0) {
    local_10 = 0x80000000;
  }
  else if (uVar2 == 1) {
    local_10 = 0x40000000;
  }
  else {
    if (uVar2 != 2) goto LAB_1100e015;
    local_10 = 0xc0000000;
  }
  if (param_3 == 0x10) {
    local_14 = 0;
  }
  else if (param_3 == 0x20) {
    local_14 = 1;
  }
  else if (param_3 == 0x30) {
    local_14 = 2;
  }
  else {
    if (param_3 != 0x40) goto LAB_1100e015;
    local_14 = 3;
  }
  uVar2 = param_2 & 0x700;
  if (uVar2 < 0x401) {
    if ((uVar2 == 0x400) || (uVar2 == 0)) {
      local_c = 3;
    }
    else if (uVar2 == 0x100) {
      local_c = 4;
    }
    else {
      if (uVar2 == 0x200) goto LAB_1100e02f;
      if (uVar2 != 0x300) goto LAB_1100e015;
      local_c = 2;
    }
  }
  else {
    if (uVar2 != 0x500) {
      if (uVar2 == 0x600) {
LAB_1100e02f:
        local_c = 5;
        goto LAB_1100e03f;
      }
      if (uVar2 != 0x700) {
LAB_1100e015:
        pDVar4 = FUN_1100addc();
        *pDVar4 = 0x16;
        pDVar4 = FUN_1100ade5();
        *pDVar4 = 0;
        return 0xffffffff;
      }
    }
    local_c = 1;
  }
LAB_1100e03f:
  uVar2 = 0x80;
  if (((param_2 & 0x100) != 0) && ((~DAT_11019b2c & param_4 & 0x80) == 0)) {
    uVar2 = 1;
  }
  if ((param_2 & 0x40) != 0) {
    uVar2 = uVar2 | 0x4000000;
    local_10 = CONCAT13(local_10._3_1_,0x10000);
  }
  if ((param_2 & 0x1000) != 0) {
    uVar2 = uVar2 | 0x100;
  }
  if ((param_2 & 0x20) == 0) {
    if ((param_2 & 0x10) != 0) {
      uVar2 = uVar2 | 0x10000000;
    }
  }
  else {
    uVar2 = uVar2 | 0x8000000;
  }
  uVar3 = FUN_1100dbc3();
  if (uVar3 == 0xffffffff) {
    pDVar4 = FUN_1100addc();
    *pDVar4 = 0x18;
    pDVar4 = FUN_1100ade5();
    *pDVar4 = 0;
    return 0xffffffff;
  }
  hFile = CreateFileA(param_1,local_10,local_14,&local_20,local_c,uVar2,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    DVar5 = GetFileType(hFile);
    if (DVar5 != 0) {
      if (DVar5 == 2) {
        local_5 = local_5 | 0x40;
      }
      else if (DVar5 == 3) {
        local_5 = local_5 | 8;
      }
      FUN_1100dce6(uVar3,hFile);
      iVar7 = (uVar3 & 0x1f) * 0x24;
      param_1._3_1_ = local_5 & 0x48;
      *(byte *)((&DAT_1101a0e0)[(int)uVar3 >> 5] + 4 + iVar7) = local_5 | 1;
      if ((((local_5 & 0x48) == 0) && ((local_5 & 0x80) != 0)) && ((param_2 & 2) != 0)) {
        local_14 = FUN_1100ae53(uVar3,-1,2);
        if (local_14 == 0xffffffff) {
          pDVar4 = FUN_1100ade5();
          if (*pDVar4 == 0x83) goto LAB_1100e1b9;
        }
        else {
          param_3 = param_3 & 0xffffff;
          iVar6 = FUN_1100c2d5(uVar3,(char *)((int)&param_3 + 3),(char *)0x1);
          if ((((iVar6 != 0) || (param_3._3_1_ != '\x1a')) ||
              (iVar6 = FUN_1100eae7(uVar3,local_14), iVar6 != -1)) &&
             (DVar5 = FUN_1100ae53(uVar3,0,0), DVar5 != 0xffffffff)) goto LAB_1100e1b9;
        }
        FUN_1100ac5e(uVar3);
        uVar2 = 0xffffffff;
      }
      else {
LAB_1100e1b9:
        if ((param_1._3_1_ == 0) && ((param_2 & 8) != 0)) {
          pbVar1 = (byte *)((&DAT_1101a0e0)[(int)uVar3 >> 5] + 4 + iVar7);
          *pbVar1 = *pbVar1 | 0x20;
        }
        uVar2 = uVar3;
      }
      goto LAB_1100e1d2;
    }
    CloseHandle(hFile);
  }
  DVar5 = GetLastError();
  FUN_1100ad69(DVar5);
  uVar2 = 0xffffffff;
LAB_1100e1d2:
  FUN_1100de82(uVar3);
  return uVar2;
}


// ---- 1100e1e0 FUN_1100e1e0  (called by: -)

int FUN_1100e1e0(int *param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    iVar3 = FUN_1100c098();
    return iVar3;
  }
  if ((DAT_11019cf0 == (FARPROC)0x0) ||
     (bVar2 = FUN_1100e27c(DAT_11019cf0), CONCAT31(extraout_var,bVar2) == 0)) {
    return 0;
  }
  iVar3 = (*DAT_11019cf0)(param_1);
  return iVar3;
}


// ---- 1100e244 FUN_1100e244  (called by: FUN_1100b744@1100b744, FUN_1100bc72@1100bc72)

bool __cdecl FUN_1100e244(void *param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadReadPtr(param_1,param_2);
  return BVar1 == 0;
}


// ---- 1100e260 FUN_1100e260  (called by: FUN_1100bc72@1100bc72)

bool __cdecl FUN_1100e260(LPVOID param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadWritePtr(param_1,param_2);
  return BVar1 == 0;
}


// ---- 1100e27c FUN_1100e27c  (called by: FUN_1100bc72@1100bc72, FUN_1100e1e0@1100e1e0)

bool __cdecl FUN_1100e27c(FARPROC param_1)

{
  BOOL BVar1;
  
  BVar1 = IsBadCodePtr(param_1);
  return BVar1 == 0;
}


// ---- 1100e2a0 _strcmp  (called by: FUN_1100b9a1@1100b9a1)

/* Library Function - Single Match
    _strcmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strcmp(char *_Str1,char *_Str2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  byte bVar3;
  bool bVar4;
  
  if (((uint)_Str1 & 3) != 0) {
    if (((uint)_Str1 & 1) != 0) {
      bVar3 = *_Str1;
      _Str1 = _Str1 + 1;
      bVar4 = bVar3 < (byte)*_Str2;
      if (bVar3 != *_Str2) goto LAB_1100e2e4;
      _Str2 = _Str2 + 1;
      if (bVar3 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_1100e2b0;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar3 = (byte)uVar1;
    bVar4 = bVar3 < (byte)*_Str2;
    if (bVar3 != *_Str2) goto LAB_1100e2e4;
    if (bVar3 == 0) {
      return 0;
    }
    bVar3 = (byte)((ushort)uVar1 >> 8);
    bVar4 = bVar3 < (byte)_Str2[1];
    if (bVar3 != _Str2[1]) goto LAB_1100e2e4;
    if (bVar3 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_1100e2b0:
  while( true ) {
    uVar2 = *(undefined4 *)_Str1;
    bVar3 = (byte)uVar2;
    bVar4 = bVar3 < (byte)*_Str2;
    if (bVar3 != *_Str2) break;
    if (bVar3 == 0) {
      return 0;
    }
    bVar3 = (byte)((uint)uVar2 >> 8);
    bVar4 = bVar3 < (byte)_Str2[1];
    if (bVar3 != _Str2[1]) break;
    if (bVar3 == 0) {
      return 0;
    }
    bVar3 = (byte)((uint)uVar2 >> 0x10);
    bVar4 = bVar3 < (byte)_Str2[2];
    if (bVar3 != _Str2[2]) break;
    if (bVar3 == 0) {
      return 0;
    }
    bVar3 = (byte)((uint)uVar2 >> 0x18);
    bVar4 = bVar3 < (byte)_Str2[3];
    if (bVar3 != _Str2[3]) break;
    _Str2 = _Str2 + 4;
    _Str1 = _Str1 + 4;
    if (bVar3 == 0) {
      return 0;
    }
  }
LAB_1100e2e4:
  return (uint)bVar4 * -2 + 1;
}


// ---- 1100e32c FUN_1100e32c  (called by: -)

undefined4 FUN_1100e32c(int param_1,PVOID param_2,undefined4 param_3)

{
  int iVar1;
  int extraout_ECX;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  int iStack_c;
  undefined4 uStack_8;
  
  puVar2 = (undefined1 *)((int)register0x00000010 + -4);
  puVar4 = (undefined1 *)((int)register0x00000010 + -4);
  if ((*(uint *)(param_1 + 4) & 6) == 0) {
    iStack_c = param_1;
    uStack_8 = param_3;
    *(int **)((int)param_2 + -4) = &iStack_c;
    iVar1 = *(int *)((int)param_2 + 8);
    for (iVar3 = *(int *)((int)param_2 + 0xc); iVar3 != -1; iVar3 = *(int *)(iVar1 + iVar3 * 0xc)) {
      if (*(int *)(iVar1 + 4 + iVar3 * 0xc) != 0) {
        iVar1 = (**(code **)(iVar1 + 4 + iVar3 * 0xc))(puVar2,iVar3,puVar4);
        param_2 = *(PVOID *)(puVar2 + 0xc);
        if (iVar1 != 0) {
          if (iVar1 < 0) {
            return 0;
          }
          iVar1 = *(int *)((int)param_2 + 8);
          __global_unwind2(param_2);
          puVar2 = (undefined1 *)((int)param_2 + 0x10);
          __local_unwind2((int)param_2,iVar3);
          FUN_11008f8e();
          *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(iVar1 + extraout_ECX * 4);
          (**(code **)(iVar1 + 8 + extraout_ECX * 4))();
        }
      }
      iVar1 = *(int *)((int)param_2 + 8);
    }
  }
  else {
    __local_unwind2((int)param_2,-1);
  }
  return 1;
}


// ---- 1100e3e9 FUN_1100e3e9  (called by: -)

void FUN_1100e3e9(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}


// ---- 1100e404 FUN_1100e404  (called by: FUN_1100c098@1100c098)

void FUN_1100e404(void)

{
  FUN_1100d624(10);
  FUN_1100ec0c((DWORD *)0x16);
                    /* WARNING: Subroutine does not return */
  __exit(3);
}


// ---- 1100e41b FUN_1100e41b  (called by: FUN_1100c4ae@1100c4ae)

int __cdecl FUN_1100e41b(LPSTR param_1,WCHAR param_2)

{
  int iVar1;
  bool bVar2;
  
  InterlockedIncrement((LONG *)&DAT_11019e8c);
  bVar2 = DAT_11019e88 != 0;
  if (bVar2) {
    InterlockedDecrement((LONG *)&DAT_11019e8c);
    FUN_11009f49(0x13);
  }
  iVar1 = FUN_1100e474(param_1,param_2);
  if (bVar2) {
    FUN_11009faa(0x13);
  }
  else {
    InterlockedDecrement((LONG *)&DAT_11019e8c);
  }
  return iVar1;
}


// ---- 1100e474 FUN_1100e474  (called by: FUN_1100e41b@1100e41b)

int __cdecl FUN_1100e474(LPSTR param_1,WCHAR param_2)

{
  LPSTR lpMultiByteStr;
  int iVar1;
  DWORD *pDVar2;
  
  lpMultiByteStr = param_1;
  if (param_1 == (LPSTR)0x0) {
    return 0;
  }
  if (DAT_11019cfc == 0) {
    if ((ushort)param_2 < 0x100) {
      *param_1 = (CHAR)param_2;
      return 1;
    }
  }
  else {
    param_1 = (LPSTR)0x0;
    iVar1 = WideCharToMultiByte(DAT_11019d0c,0x220,&param_2,1,lpMultiByteStr,DAT_11015fec,
                                (LPCSTR)0x0,(LPBOOL)&param_1);
    if ((iVar1 != 0) && (param_1 == (LPSTR)0x0)) {
      return iVar1;
    }
  }
  pDVar2 = FUN_1100addc();
  *pDVar2 = 0x2a;
  return -1;
}


// ---- 1100e4e0 __aulldiv  (called by: FUN_1100c4ae@1100c4ae)

/* Library Function - Single Match
    __aulldiv
   
   Library: Visual Studio */

undefined8 __aulldiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (param_4 == 0) {
    uVar4 = param_2 / param_3;
    iVar5 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    uVar8 = param_1;
    uVar6 = param_4;
    uVar7 = param_2;
    uVar4 = param_3;
    do {
      uVar3 = uVar6 & 1;
      uVar6 = uVar6 >> 1;
      uVar4 = (uint)(CONCAT14(uVar3 != 0,uVar4) >> 1);
      uVar3 = uVar7 & 1;
      uVar7 = uVar7 >> 1;
      uVar8 = (uint)(CONCAT14(uVar3 != 0,uVar8) >> 1);
    } while (uVar6 != 0);
    uVar1 = CONCAT44(uVar7,uVar8) / (ulonglong)uVar4;
    iVar5 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar4 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar8 = uVar4 + iVar5 * param_4;
    if (((CARRY4(uVar4,iVar5 * param_4)) || (param_2 < uVar8)) ||
       ((param_2 <= uVar8 && (param_1 < (uint)lVar2)))) {
      iVar5 = iVar5 + -1;
    }
    uVar4 = 0;
  }
  return CONCAT44(uVar4,iVar5);
}


// ---- 1100e550 __aullrem  (called by: FUN_1100c4ae@1100c4ae)

/* Library Function - Single Match
    __aullrem
   
   Library: Visual Studio */

undefined8 __aullrem(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  
  if (param_4 == 0) {
    iVar7 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) %
                 (ulonglong)param_3);
    iVar8 = 0;
  }
  else {
    uVar5 = param_1;
    uVar6 = param_4;
    uVar9 = param_2;
    uVar4 = param_3;
    do {
      uVar3 = uVar6 & 1;
      uVar6 = uVar6 >> 1;
      uVar4 = (uint)(CONCAT14(uVar3 != 0,uVar4) >> 1);
      uVar3 = uVar9 & 1;
      uVar9 = uVar9 >> 1;
      uVar5 = (uint)(CONCAT14(uVar3 != 0,uVar5) >> 1);
    } while (uVar6 != 0);
    uVar1 = CONCAT44(uVar9,uVar5) / (ulonglong)uVar4;
    uVar4 = (int)uVar1 * param_4;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;
    uVar6 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar5 = (uint)lVar2;
    uVar9 = uVar6 + uVar4;
    if (((CARRY4(uVar6,uVar4)) || (param_2 < uVar9)) || ((param_2 <= uVar9 && (param_1 < uVar5)))) {
      bVar10 = uVar5 < param_3;
      uVar5 = uVar5 - param_3;
      uVar9 = (uVar9 - param_4) - (uint)bVar10;
    }
    iVar7 = -(uVar5 - param_1);
    iVar8 = -(uint)(uVar5 - param_1 != 0) - ((uVar9 - param_2) - (uint)(uVar5 < param_1));
  }
  return CONCAT44(iVar8,iVar7);
}


// ---- 1100e5c5 FUN_1100e5c5  (called by: FUN_1100cf78@1100cf78, FUN_1100f106@1100f106)

int __cdecl
FUN_1100e5c5(LCID param_1,DWORD param_2,char *param_3,int param_4,LPWSTR param_5,int param_6,
            UINT param_7,int param_8)

{
  int iVar1;
  int iVar2;
  undefined1 unaff_DI;
  undefined1 uStack00000000;
  WCHAR aWStack_2e [13];
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_11010830;
  pcStack_10 = FUN_1100e32c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_11019d14 == 0) {
    ExceptionList = &local_14;
    iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_11019d14 = 2;
    }
    else {
      DAT_11019d14 = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_1100e7e9(param_3,param_4);
  }
  if (DAT_11019d14 == 2) {
    iVar1 = LCMapStringA(param_1,param_2,param_3,param_4,(LPSTR)param_5,param_6);
    ExceptionList = local_14;
    return iVar1;
  }
  if (DAT_11019d14 == 1) {
    if (param_7 == 0) {
      param_7 = DAT_11019d0c;
    }
    iVar1 = MultiByteToWideChar(param_7,(-(uint)(param_8 != 0) & 8) + 1,param_3,param_4,(LPWSTR)0x0,
                                0);
    if (iVar1 == 0) {
      ExceptionList = local_14;
      return 0;
    }
    local_8 = 0;
    FUN_11008ba0(unaff_DI);
    local_8 = 0xffffffff;
    if (&uStack00000000 == (undefined1 *)0x3c) {
      ExceptionList = local_14;
      return 0;
    }
    iVar2 = MultiByteToWideChar(param_7,1,param_3,param_4,aWStack_2e + -7,iVar1);
    if (iVar2 == 0) {
      ExceptionList = local_14;
      return 0;
    }
    iVar2 = LCMapStringW(param_1,param_2,aWStack_2e + -7,iVar1,(LPWSTR)0x0,0);
    if (iVar2 == 0) {
      ExceptionList = local_14;
      return 0;
    }
    if ((param_2 & 0x400) == 0) {
      local_8 = 1;
      FUN_11008ba0(unaff_DI);
      local_8 = 0xffffffff;
      if (&uStack00000000 == (undefined1 *)0x3c) {
        ExceptionList = local_14;
        return 0;
      }
      iVar1 = LCMapStringW(param_1,param_2,aWStack_2e + -7,iVar1,aWStack_2e + -7,iVar2);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      if (param_6 == 0) {
        param_6 = 0;
        param_5 = (LPWSTR)0x0;
      }
      iVar2 = WideCharToMultiByte(param_7,0x220,aWStack_2e + -7,iVar2,(LPSTR)param_5,param_6,
                                  (LPCSTR)0x0,(LPBOOL)0x0);
      iVar1 = iVar2;
    }
    else {
      if (param_6 == 0) {
        ExceptionList = local_14;
        return iVar2;
      }
      if (param_6 < iVar2) {
        ExceptionList = local_14;
        return 0;
      }
      iVar1 = LCMapStringW(param_1,param_2,aWStack_2e + -7,iVar1,param_5,param_6);
    }
    if (iVar1 != 0) {
      ExceptionList = local_14;
      return iVar2;
    }
  }
  ExceptionList = local_14;
  return 0;
}


// ---- 1100e7e9 FUN_1100e7e9  (called by: FUN_1100e5c5@1100e5c5)

int __cdecl FUN_1100e7e9(char *param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = param_2;
  for (pcVar1 = param_1; (iVar2 != 0 && (iVar2 = iVar2 + -1, *pcVar1 != '\0')); pcVar1 = pcVar1 + 1)
  {
  }
  if (*pcVar1 == '\0') {
    return (int)pcVar1 - (int)param_1;
  }
  return param_2;
}


// ---- 1100e814 FUN_1100e814  (called by: FUN_1100cf78@1100cf78, FUN_1100f091@1100f091)

BOOL __cdecl
FUN_1100e814(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6,
            int param_7)

{
  WCHAR *pWVar1;
  BOOL BVar2;
  int iVar3;
  undefined1 unaff_DI;
  undefined1 uStack00000000;
  WCHAR aWStack_2a [5];
  WORD local_20 [2];
  undefined1 *local_1c;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_11010848;
  pcStack_10 = FUN_1100e32c;
  local_14 = ExceptionList;
  local_1c = (undefined1 *)(aWStack_2a + -7);
  ExceptionList = &local_14;
  pWVar1 = aWStack_2a + -7;
  if (DAT_11019d18 == 0) {
    iVar3 = 1;
    ExceptionList = &local_14;
    BVar2 = GetStringTypeW(1,L"",1,local_20);
    if (BVar2 == 0) {
      BVar2 = GetStringTypeA(0,1,"",1,local_20);
      if (BVar2 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      iVar3 = 2;
    }
    DAT_11019d18 = iVar3;
    pWVar1 = (WCHAR *)local_1c;
  }
  local_1c = (undefined1 *)pWVar1;
  if (DAT_11019d18 == 2) {
    if (param_6 == 0) {
      param_6 = DAT_11019cfc;
    }
    BVar2 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
    ExceptionList = local_14;
    return BVar2;
  }
  if (DAT_11019d18 == 1) {
    if (param_5 == 0) {
      param_5 = DAT_11019d0c;
    }
    iVar3 = MultiByteToWideChar(param_5,(-(uint)(param_7 != 0) & 8) + 1,param_2,param_3,(LPWSTR)0x0,
                                0);
    if (iVar3 != 0) {
      local_8 = 0;
      FUN_11008ba0(unaff_DI);
      local_1c = (undefined1 *)(aWStack_2a + -7);
      _memset(aWStack_2a + -7,0,iVar3 * 2);
      local_8 = 0xffffffff;
      if ((&uStack00000000 != (undefined1 *)0x38) &&
         (iVar3 = MultiByteToWideChar(param_5,1,param_2,param_3,aWStack_2a + -7,iVar3), iVar3 != 0))
      {
        BVar2 = GetStringTypeW(param_1,aWStack_2a + -7,iVar3,param_4);
        ExceptionList = local_14;
        return BVar2;
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}


// ---- 1100e960 _strncpy  (called by: FUN_1100d119@1100d119, FUN_1100d624@1100d624)

/* Library Function - Single Match
    _strncpy
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strncpy(char *_Dest,char *_Source,size_t _Count)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  
  if (_Count == 0) {
    return _Dest;
  }
  puVar5 = (uint *)_Dest;
  if (((uint)_Source & 3) != 0) {
    while( true ) {
      uVar4 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 1);
      *(char *)puVar5 = (char)uVar4;
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
      if (_Count == 0) {
        return _Dest;
      }
      if ((char)uVar4 == '\0') break;
      if (((uint)_Source & 3) == 0) {
        uVar4 = _Count >> 2;
        goto joined_r0x1100e99e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_1100e9db;
        goto LAB_1100ea49;
      }
      *(char *)puVar5 = '\0';
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
    } while (_Count != 0);
    return _Dest;
  }
  uVar4 = _Count >> 2;
  if (uVar4 != 0) {
    do {
      uVar1 = *(uint *)_Source;
      uVar2 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 4);
      if (((uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uVar2 == '\0') {
          *puVar5 = 0;
joined_r0x1100ea45:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_1100ea49:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_1100e9db;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x1100ea45;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x1100ea45;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x1100ea45;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x1100e99e:
    } while (uVar4 != 0);
    _Count = _Count & 3;
    if (_Count == 0) {
      return _Dest;
    }
  }
  do {
    cVar3 = (char)*(uint *)_Source;
    _Source = (char *)((int)_Source + 1);
    *(char *)puVar5 = cVar3;
    puVar5 = (uint *)((int)puVar5 + 1);
    if (cVar3 == '\0') {
      while (_Count = _Count - 1, _Count != 0) {
LAB_1100e9db:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}


// ---- 1100ea5e FUN_1100ea5e  (called by: FUN_1100d624@1100d624)

int __cdecl FUN_1100ea5e(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_11019d1c == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_11019d1c = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_11019d1c != (FARPROC)0x0) {
        DAT_11019d20 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_11019d24 = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_1100eaad;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_1100eaad:
    if (DAT_11019d20 != (FARPROC)0x0) {
      iVar1 = (*DAT_11019d20)();
      if ((iVar1 != 0) && (DAT_11019d24 != (FARPROC)0x0)) {
        iVar1 = (*DAT_11019d24)(iVar1);
      }
    }
    iVar1 = (*DAT_11019d1c)(iVar1,param_1,param_2,param_3);
  }
  return iVar1;
}


// ---- 1100eae7 FUN_1100eae7  (called by: FUN_1100df11@1100df11)

int __cdecl FUN_1100eae7(uint param_1,int param_2)

{
  DWORD DVar1;
  DWORD DVar2;
  int iVar3;
  DWORD DVar4;
  int iVar5;
  DWORD *pDVar6;
  HANDLE hFile;
  BOOL BVar7;
  undefined1 unaff_BP;
  int iVar8;
  char local_1008 [4064];
  undefined4 uStackY_28;
  
  FUN_11008ba0(unaff_BP);
  iVar8 = 0;
  DVar1 = FUN_1100ae53(param_1,0,1);
  if ((DVar1 == 0xffffffff) || (DVar2 = FUN_1100ae53(param_1,0,2), DVar2 == 0xffffffff)) {
    iVar8 = -1;
  }
  else {
    DVar2 = param_2 - DVar2;
    if ((int)DVar2 < 1) {
      if ((int)DVar2 < 0) {
        FUN_1100ae53(param_1,param_2,0);
        hFile = (HANDLE)FUN_1100dde1(param_1);
        BVar7 = SetEndOfFile(hFile);
        iVar8 = (BVar7 != 0) - 1;
        if (iVar8 == -1) {
          pDVar6 = FUN_1100addc();
          *pDVar6 = 0xd;
          DVar2 = GetLastError();
          pDVar6 = FUN_1100ade5();
          *pDVar6 = DVar2;
        }
      }
    }
    else {
      _memset(local_1008,0,0x1000);
      uStackY_28 = 0x1100eb54;
      iVar3 = FUN_1100edd4(param_1,0x8000);
      do {
        DVar4 = 0x1000;
        if ((int)DVar2 < 0x1000) {
          DVar4 = DVar2;
        }
        iVar5 = FUN_1100b1ce(param_1,local_1008,DVar4);
        if (iVar5 == -1) {
          pDVar6 = FUN_1100ade5();
          if (*pDVar6 == 5) {
            pDVar6 = FUN_1100addc();
            *pDVar6 = 0xd;
          }
          iVar8 = -1;
          break;
        }
        DVar2 = DVar2 - iVar5;
      } while (0 < (int)DVar2);
      FUN_1100edd4(param_1,iVar3);
    }
    FUN_1100ae53(param_1,DVar1,0);
  }
  return iVar8;
}


// ---- 1100ec0c FUN_1100ec0c  (called by: FUN_1100e404@1100e404)

undefined4 __cdecl FUN_1100ec0c(DWORD *param_1)

{
  bool bVar1;
  DWORD *pDVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  undefined4 *puVar7;
  DWORD local_10;
  DWORD local_c;
  
  bVar1 = false;
  if (param_1 == (DWORD *)0x2) {
    puVar7 = &DAT_11019d2c;
    pcVar6 = DAT_11019d2c;
LAB_1100ec92:
    bVar1 = true;
    FUN_11009f49(1);
    pDVar2 = param_1;
  }
  else {
    if (((param_1 != (DWORD *)0x4) && (param_1 != (DWORD *)0x8)) && (param_1 != (DWORD *)0xb)) {
      if (param_1 == (DWORD *)0xf) {
        puVar7 = &DAT_11019d38;
        pcVar6 = DAT_11019d38;
      }
      else if (param_1 == (DWORD *)0x15) {
        puVar7 = &DAT_11019d30;
        pcVar6 = DAT_11019d30;
      }
      else {
        if (param_1 != (DWORD *)0x16) {
          return 0xffffffff;
        }
        puVar7 = &DAT_11019d34;
        pcVar6 = DAT_11019d34;
      }
      goto LAB_1100ec92;
    }
    pDVar2 = FUN_1100bf91();
    uVar3 = FUN_1100ed8e((int)param_1,pDVar2[0x14]);
    puVar7 = (undefined4 *)(uVar3 + 8);
    pcVar6 = (code *)*puVar7;
  }
  if (pcVar6 == (code *)0x1) {
    if (bVar1) {
      FUN_11009faa(1);
      return 0;
    }
    return 0;
  }
  if (pcVar6 == (code *)0x0) {
    if (bVar1) {
      FUN_11009faa(1);
    }
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  if (((param_1 == (DWORD *)0x8) || (param_1 == (DWORD *)0xb)) || (param_1 == (DWORD *)0x4)) {
    local_c = pDVar2[0x15];
    pDVar2[0x15] = 0;
    if (param_1 == (DWORD *)0x8) {
      local_10 = pDVar2[0x16];
      pDVar2[0x16] = 0x8c;
      goto LAB_1100ed06;
    }
  }
  else {
LAB_1100ed06:
    if (param_1 == (DWORD *)0x8) {
      if (DAT_11015ca8 < DAT_11015cac + DAT_11015ca8) {
        iVar4 = DAT_11015ca8 * 0xc;
        iVar5 = DAT_11015ca8;
        do {
          iVar4 = iVar4 + 0xc;
          *(undefined4 *)((pDVar2[0x14] - 4) + iVar4) = 0;
          iVar5 = iVar5 + 1;
        } while (iVar5 < DAT_11015cac + DAT_11015ca8);
      }
      goto LAB_1100ed44;
    }
  }
  *puVar7 = 0;
LAB_1100ed44:
  if (bVar1) {
    FUN_11009faa(1);
  }
  if (param_1 == (DWORD *)0x8) {
    (*pcVar6)(8,pDVar2[0x16]);
  }
  else {
    (*pcVar6)(param_1);
    if ((param_1 != (DWORD *)0xb) && (param_1 != (DWORD *)0x4)) {
      return 0;
    }
  }
  pDVar2[0x15] = local_c;
  if (param_1 == (DWORD *)0x8) {
    pDVar2[0x16] = local_10;
  }
  return 0;
}


// ---- 1100ed8e FUN_1100ed8e  (called by: FUN_1100ec0c@1100ec0c)

uint __cdecl FUN_1100ed8e(int param_1,uint param_2)

{
  int *piVar1;
  uint uVar3;
  uint uVar2;
  
  uVar2 = param_2;
  if (*(int *)(param_2 + 4) != param_1) {
    uVar3 = param_2;
    do {
      uVar2 = uVar3 + 0xc;
      if (param_2 + DAT_11015cb4 * 0xc <= uVar2) break;
      piVar1 = (int *)(uVar3 + 0x10);
      uVar3 = uVar2;
    } while (*piVar1 != param_1);
  }
  if ((param_2 + DAT_11015cb4 * 0xc <= uVar2) || (*(int *)(uVar2 + 4) != param_1)) {
    uVar2 = 0;
  }
  return uVar2;
}


// ---- 1100edcb __fptrap  (called by: FUN_1100c4ae@1100c4ae)

/* Library Function - Single Match
    __fptrap
   
   Library: Visual Studio 2003 Release */

void __cdecl __fptrap(void)

{
  __amsg_exit(2);
  return;
}


// ---- 1100edd4 FUN_1100edd4  (called by: FUN_1100eae7@1100eae7)

int __cdecl FUN_1100edd4(uint param_1,int param_2)

{
  byte bVar1;
  DWORD *pDVar2;
  byte bVar3;
  
  bVar1 = *(byte *)((&DAT_1101a0e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
  if (param_2 == 0x8000) {
    bVar3 = bVar1 & 0x7f;
  }
  else {
    if (param_2 != 0x4000) {
      pDVar2 = FUN_1100addc();
      *pDVar2 = 0x16;
      return -1;
    }
    bVar3 = bVar1 | 0x80;
  }
  *(byte *)((&DAT_1101a0e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = bVar3;
  return (-(uint)((bVar1 & 0x80) != 0) & 0xffffc000) + 0x8000;
}


// ---- 1100ee40 FUN_1100ee40  (called by: -)

int __cdecl FUN_1100ee40(byte *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    param_2 = param_2 + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  iVar2 = -1;
  do {
    iVar2 = iVar2 + 1;
    bVar1 = *param_1;
    if (bVar1 == 0) {
      return iVar2;
    }
    param_1 = param_1 + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return iVar2;
}


// ---- 1100ee80 FUN_1100ee80  (called by: -)

byte * __cdecl FUN_1100ee80(byte *param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    param_2 = param_2 + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  do {
    pbVar2 = param_1;
    bVar1 = *pbVar2;
    if (bVar1 == 0) {
      return (byte *)0x0;
    }
    param_1 = pbVar2 + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return pbVar2;
}


// ---- 1100eec0 FUN_1100eec0  (called by: -)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_1100eec0(void *this,byte *param_1,byte *param_2)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  void *extraout_ECX;
  void *this_00;
  void *extraout_ECX_00;
  uint uVar8;
  uint uVar9;
  
  iVar2 = _DAT_11019e8c;
  if (DAT_11019cfc == 0) {
    bVar5 = 0xff;
    do {
      do {
        cVar6 = '\0';
        if (bVar5 == 0) goto LAB_1100ef0e;
        bVar5 = *param_2;
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        param_1 = param_1 + 1;
      } while (bVar4 == bVar5);
      bVar3 = bVar5 + 0xbf + (-((byte)(bVar5 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      bVar4 = bVar4 + 0xbf;
      bVar5 = bVar4 + (-(bVar4 < 0x1a) & 0x20U) + 0x41;
    } while (bVar5 == bVar3);
    cVar6 = (bVar5 < bVar3) * -2 + '\x01';
LAB_1100ef0e:
    uVar7 = (uint)cVar6;
  }
  else {
    LOCK();
    _DAT_11019e8c = _DAT_11019e8c + 1;
    UNLOCK();
    bVar1 = 0 < DAT_11019e88;
    if (bVar1) {
      LOCK();
      UNLOCK();
      _DAT_11019e8c = iVar2;
      FUN_11009f49(0x13);
      this = extraout_ECX;
    }
    uVar9 = (uint)bVar1;
    uVar7 = 0xff;
    uVar8 = 0;
    do {
      do {
        if ((char)uVar7 == '\0') goto LAB_1100ef6f;
        bVar5 = *param_2;
        uVar7 = CONCAT31((int3)(uVar7 >> 8),bVar5);
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        uVar8 = CONCAT31((int3)(uVar8 >> 8),bVar4);
        param_1 = param_1 + 1;
      } while (bVar5 == bVar4);
      uVar8 = FUN_1100f106(this,uVar8);
      uVar7 = FUN_1100f106(this_00,uVar7);
      this = extraout_ECX_00;
    } while ((byte)uVar8 == (byte)uVar7);
    uVar8 = (uint)((byte)uVar8 < (byte)uVar7);
    uVar7 = (1 - uVar8) - (uint)(uVar8 != 0);
LAB_1100ef6f:
    if (uVar9 == 0) {
      LOCK();
      _DAT_11019e8c = _DAT_11019e8c + -1;
      UNLOCK();
    }
    else {
      FUN_11009faa(0x13);
    }
  }
  return uVar7;
}


// ---- 1100ef90 FUN_1100ef90  (called by: -)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1100ef90(byte *param_1,char *param_2,void *param_3)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  undefined4 uVar6;
  void *this;
  uint uVar7;
  bool bVar8;
  uint uVar9;
  
  iVar2 = _DAT_11019e8c;
  uVar6 = 0;
  if (param_3 != (void *)0x0) {
    if (DAT_11019cfc == 0) {
      do {
        bVar3 = *param_1;
        cVar1 = *param_2;
        uVar4 = CONCAT11(bVar3,cVar1);
        if (bVar3 == 0) break;
        uVar4 = CONCAT11(bVar3,cVar1);
        uVar7 = (uint)uVar4;
        if (cVar1 == '\0') break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        if ((0x40 < bVar3) && (bVar3 < 0x5b)) {
          uVar7 = (uint)CONCAT11(bVar3 + 0x20,cVar1);
        }
        uVar4 = (ushort)uVar7;
        bVar3 = (byte)uVar7;
        if ((0x40 < bVar3) && (bVar3 < 0x5b)) {
          uVar4 = (ushort)CONCAT31((int3)(uVar7 >> 8),bVar3 + 0x20);
        }
        bVar3 = (byte)(uVar4 >> 8);
        bVar8 = bVar3 < (byte)uVar4;
        if (bVar3 != (byte)uVar4) goto LAB_1100efef;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar6 = 0;
      bVar3 = (byte)(uVar4 >> 8);
      bVar8 = bVar3 < (byte)uVar4;
      if (bVar3 != (byte)uVar4) {
LAB_1100efef:
        uVar6 = 0xffffffff;
        if (!bVar8) {
          uVar6 = 1;
        }
      }
    }
    else {
      LOCK();
      _DAT_11019e8c = _DAT_11019e8c + 1;
      UNLOCK();
      bVar8 = 0 < DAT_11019e88;
      if (bVar8) {
        LOCK();
        UNLOCK();
        _DAT_11019e8c = iVar2;
        FUN_11009f49(0x13);
      }
      uVar9 = (uint)bVar8;
      uVar5 = 0;
      uVar7 = 0;
      do {
        uVar5 = CONCAT31((int3)(uVar5 >> 8),*param_1);
        uVar7 = CONCAT31((int3)(uVar7 >> 8),*param_2);
        if ((uVar5 == 0) || (uVar7 == 0)) break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        uVar7 = FUN_1100f106(param_3,uVar7);
        uVar5 = FUN_1100f106(this,uVar5);
        bVar8 = uVar5 < uVar7;
        if (uVar5 != uVar7) goto LAB_1100f065;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar6 = 0;
      bVar8 = uVar5 < uVar7;
      if (uVar5 != uVar7) {
LAB_1100f065:
        uVar6 = 0xffffffff;
        if (!bVar8) {
          uVar6 = 1;
        }
      }
      if (uVar9 == 0) {
        LOCK();
        _DAT_11019e8c = _DAT_11019e8c + -1;
        UNLOCK();
      }
      else {
        FUN_11009faa(0x13);
      }
    }
  }
  return uVar6;
}


// ---- 1100f091 FUN_1100f091  (called by: FUN_1100f106@1100f106)

uint __thiscall FUN_1100f091(void *this,int param_1,uint param_2)

{
  BOOL BVar1;
  int iVar2;
  undefined4 local_8;
  
  if (param_1 + 1U < 0x101) {
    param_1._2_2_ = *(ushort *)(PTR_DAT_11015cd0 + param_1 * 2);
  }
  else {
    if ((PTR_DAT_11015cd0[(param_1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      local_8 = CONCAT31((int3)((uint)this >> 8),(char)param_1) & 0xffff00ff;
      iVar2 = 1;
    }
    else {
      local_8._0_2_ = CONCAT11((char)param_1,(char)((uint)param_1 >> 8));
      local_8 = CONCAT22((short)((uint)this >> 0x10),(undefined2)local_8) & 0xff00ffff;
      iVar2 = 2;
    }
    BVar1 = FUN_1100e814(1,(LPCSTR)&local_8,iVar2,(LPWORD)((int)&param_1 + 2),0,0,1);
    if (BVar1 == 0) {
      return 0;
    }
  }
  return param_1._2_2_ & param_2;
}


// ---- 1100f106 FUN_1100f106  (called by: FUN_1100eec0@1100eec0, FUN_1100ef90@1100ef90)

uint __thiscall FUN_1100f106(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  void *local_8;
  
  uVar1 = param_1;
  if (DAT_11019cfc == 0) {
    if ((int)param_1 < 0x41) {
      return param_1;
    }
    if ((int)param_1 < 0x5b) {
      return param_1 + 0x20;
    }
    return param_1;
  }
  iVar3 = 1;
  local_8 = this;
  if ((int)param_1 < 0x100) {
    if (DAT_11015fec < 2) {
      uVar2 = (byte)PTR_DAT_11015cd0[param_1 * 2] & 1;
    }
    else {
      uVar2 = FUN_1100f091(this,param_1,1);
    }
    if (uVar2 == 0) {
      return uVar1;
    }
  }
  if ((PTR_DAT_11015cd0[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
    param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;
  }
  else {
    uVar2 = param_1 >> 0x10;
    param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));
    param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;
    iVar3 = 2;
  }
  iVar3 = FUN_1100e5c5(DAT_11019cfc,0x100,(char *)&param_1,iVar3,(LPWSTR)&local_8,3,0,1);
  if (iVar3 == 0) {
    return uVar1;
  }
  if (iVar3 == 1) {
    return (uint)local_8 & 0xff;
  }
  return (uint)local_8 & 0xffff;
}


// ---- 1100f2f0 __putw  (called by: FUN_11001106@11001106)

/* Library Function - Single Match
    __putw
   
   Library: Visual Studio 2003 Release */

int __cdecl __putw(int _Word,FILE *_File)

{
  int *piVar1;
  FILE *pFVar2;
  int iVar3;
  int *piVar4;
  
  pFVar2 = _File;
  piVar4 = &_Word;
  iVar3 = 4;
  do {
    piVar1 = &pFVar2->_cnt;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      FUN_1100b359((int)(char)*piVar4,(int *)pFVar2);
    }
    else {
      *pFVar2->_ptr = (char)*piVar4;
      pFVar2->_ptr = pFVar2->_ptr + 1;
    }
    piVar4 = (int *)((int)piVar4 + 1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if ((pFVar2->_flag & 0x20) == 0) {
    return _Word;
  }
  return -1;
}


// ---- 1100f340 Unwind@1100f340  (called by: -)

void Unwind_1100f340(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f343. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + 8));
  return;
}


// ---- 1100f349 FUN_1100f349  (called by: -)

void FUN_1100f349(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_11008c60(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f354 Unwind@1100f354  (called by: -)

void Unwind_1100f354(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f35a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x44));
  return;
}


// ---- 1100f360 Unwind@1100f360  (called by: -)

void Unwind_1100f360(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f366. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x48));
  return;
}


// ---- 1100f36c Unwind@1100f36c  (called by: -)

void Unwind_1100f36c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f372. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}


// ---- 1100f378 Unwind@1100f378  (called by: -)

void Unwind_1100f378(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f37e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x50));
  return;
}


// ---- 1100f384 Unwind@1100f384  (called by: -)

void Unwind_1100f384(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f38a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x54));
  return;
}


// ---- 1100f390 Unwind@1100f390  (called by: -)

void Unwind_1100f390(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f396. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x58));
  return;
}


// ---- 1100f39c Unwind@1100f39c  (called by: -)

void Unwind_1100f39c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f3a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x5c));
  return;
}


// ---- 1100f3a8 Unwind@1100f3a8  (called by: -)

void Unwind_1100f3a8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f3ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x60));
  return;
}


// ---- 1100f3b4 Unwind@1100f3b4  (called by: -)

void Unwind_1100f3b4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f3ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 100));
  return;
}


// ---- 1100f3c0 Unwind@1100f3c0  (called by: -)

void Unwind_1100f3c0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f3c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x68));
  return;
}


// ---- 1100f3cc Unwind@1100f3cc  (called by: -)

void Unwind_1100f3cc(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f3d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x6c));
  return;
}


// ---- 1100f3d8 Unwind@1100f3d8  (called by: -)

void Unwind_1100f3d8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f3de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x70));
  return;
}


// ---- 1100f3e4 Unwind@1100f3e4  (called by: -)

void Unwind_1100f3e4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f3ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x74));
  return;
}


// ---- 1100f3f0 Unwind@1100f3f0  (called by: -)

void Unwind_1100f3f0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f3f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x78));
  return;
}


// ---- 1100f3fc Unwind@1100f3fc  (called by: -)

void Unwind_1100f3fc(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f402. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x7c));
  return;
}


// ---- 1100f408 Unwind@1100f408  (called by: -)

void Unwind_1100f408(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f411. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x80));
  return;
}


// ---- 1100f417 Unwind@1100f417  (called by: -)

void Unwind_1100f417(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f420. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x84));
  return;
}


// ---- 1100f426 Unwind@1100f426  (called by: -)

void Unwind_1100f426(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f42f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x88));
  return;
}


// ---- 1100f435 Unwind@1100f435  (called by: -)

void Unwind_1100f435(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f43e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x8c));
  return;
}


// ---- 1100f444 Unwind@1100f444  (called by: -)

void Unwind_1100f444(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f44d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x90));
  return;
}


// ---- 1100f453 Unwind@1100f453  (called by: -)

void Unwind_1100f453(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f45c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x94));
  return;
}


// ---- 1100f462 Unwind@1100f462  (called by: -)

void Unwind_1100f462(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f46b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 0x98));
  return;
}


// ---- 1100f471 Unwind@1100f471  (called by: -)

void Unwind_1100f471(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f47a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 0x9c));
  return;
}


// ---- 1100f480 Unwind@1100f480  (called by: -)

void Unwind_1100f480(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f489. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 0xa0));
  return;
}


// ---- 1100f48f Unwind@1100f48f  (called by: -)

void Unwind_1100f48f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f498. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 0xa4));
  return;
}


// ---- 1100f49e Unwind@1100f49e  (called by: -)

void Unwind_1100f49e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f4a7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 0xa8));
  return;
}


// ---- 1100f4ad Unwind@1100f4ad  (called by: -)

void Unwind_1100f4ad(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f4b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 0xac));
  return;
}


// ---- 1100f4bc Unwind@1100f4bc  (called by: -)

void Unwind_1100f4bc(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f4c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x10) + 0xb0));
  return;
}


// ---- 1100f4cb Unwind@1100f4cb  (called by: -)

void Unwind_1100f4cb(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f4d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x10) + 0xb4));
  return;
}


// ---- 1100f4da Unwind@1100f4da  (called by: -)

void Unwind_1100f4da(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f4e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x10) + 0xb8));
  return;
}


// ---- 1100f4e9 Unwind@1100f4e9  (called by: -)

void Unwind_1100f4e9(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f4f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0x114));
  return;
}


// ---- 1100f4f8 Unwind@1100f4f8  (called by: -)

void Unwind_1100f4f8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f501. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0x118));
  return;
}


// ---- 1100f507 Unwind@1100f507  (called by: -)

void Unwind_1100f507(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f510. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0x11c));
  return;
}


// ---- 1100f516 Unwind@1100f516  (called by: -)

void Unwind_1100f516(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f51f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0x120));
  return;
}


// ---- 1100f525 Unwind@1100f525  (called by: -)

void Unwind_1100f525(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f52e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0x124));
  return;
}


// ---- 1100f534 Unwind@1100f534  (called by: -)

void Unwind_1100f534(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f53d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0x128));
  return;
}


// ---- 1100f543 Unwind@1100f543  (called by: -)

void Unwind_1100f543(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f54c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 300));
  return;
}


// ---- 1100f552 FUN_1100f552  (called by: -)

void FUN_1100f552(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_11008c60(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f55c Unwind@1100f55c  (called by: -)

void Unwind_1100f55c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f562. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x44));
  return;
}


// ---- 1100f568 Unwind@1100f568  (called by: -)

void Unwind_1100f568(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f56e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x48));
  return;
}


// ---- 1100f574 Unwind@1100f574  (called by: -)

void Unwind_1100f574(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f57a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x4c));
  return;
}


// ---- 1100f580 Unwind@1100f580  (called by: -)

void Unwind_1100f580(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f586. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x50));
  return;
}


// ---- 1100f58c Unwind@1100f58c  (called by: -)

void Unwind_1100f58c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f592. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x54));
  return;
}


// ---- 1100f598 Unwind@1100f598  (called by: -)

void Unwind_1100f598(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f59e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x58));
  return;
}


// ---- 1100f5a4 Unwind@1100f5a4  (called by: -)

void Unwind_1100f5a4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f5aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x5c));
  return;
}


// ---- 1100f5b0 Unwind@1100f5b0  (called by: -)

void Unwind_1100f5b0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f5b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x60));
  return;
}


// ---- 1100f5bc Unwind@1100f5bc  (called by: -)

void Unwind_1100f5bc(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f5c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 100));
  return;
}


// ---- 1100f5c8 Unwind@1100f5c8  (called by: -)

void Unwind_1100f5c8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f5ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x68));
  return;
}


// ---- 1100f5d4 Unwind@1100f5d4  (called by: -)

void Unwind_1100f5d4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f5da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x6c));
  return;
}


// ---- 1100f5e0 Unwind@1100f5e0  (called by: -)

void Unwind_1100f5e0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f5e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x70));
  return;
}


// ---- 1100f5ec Unwind@1100f5ec  (called by: -)

void Unwind_1100f5ec(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f5f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x74));
  return;
}


// ---- 1100f5f8 Unwind@1100f5f8  (called by: -)

void Unwind_1100f5f8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f5fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x78));
  return;
}


// ---- 1100f604 Unwind@1100f604  (called by: -)

void Unwind_1100f604(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f60a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x7c));
  return;
}


// ---- 1100f610 Unwind@1100f610  (called by: -)

void Unwind_1100f610(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f619. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x80));
  return;
}


// ---- 1100f61f Unwind@1100f61f  (called by: -)

void Unwind_1100f61f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f628. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x84));
  return;
}


// ---- 1100f62e Unwind@1100f62e  (called by: -)

void Unwind_1100f62e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f637. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x88));
  return;
}


// ---- 1100f63d Unwind@1100f63d  (called by: -)

void Unwind_1100f63d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f646. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x8c));
  return;
}


// ---- 1100f64c Unwind@1100f64c  (called by: -)

void Unwind_1100f64c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f655. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x90));
  return;
}


// ---- 1100f65b Unwind@1100f65b  (called by: -)

void Unwind_1100f65b(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f664. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x94));
  return;
}


// ---- 1100f66a Unwind@1100f66a  (called by: -)

void Unwind_1100f66a(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f673. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x14) + 0x98));
  return;
}


// ---- 1100f679 Unwind@1100f679  (called by: -)

void Unwind_1100f679(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f682. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x14) + 0x9c));
  return;
}


// ---- 1100f688 Unwind@1100f688  (called by: -)

void Unwind_1100f688(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f691. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x14) + 0xa0));
  return;
}


// ---- 1100f697 Unwind@1100f697  (called by: -)

void Unwind_1100f697(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f6a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x14) + 0xa4));
  return;
}


// ---- 1100f6a6 Unwind@1100f6a6  (called by: -)

void Unwind_1100f6a6(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f6af. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x14) + 0xa8));
  return;
}


// ---- 1100f6b5 Unwind@1100f6b5  (called by: -)

void Unwind_1100f6b5(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f6be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x14) + 0xac));
  return;
}


// ---- 1100f6c4 Unwind@1100f6c4  (called by: -)

void Unwind_1100f6c4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f6cd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x14) + 0xb0));
  return;
}


// ---- 1100f6d3 Unwind@1100f6d3  (called by: -)

void Unwind_1100f6d3(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f6dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x14) + 0xb4));
  return;
}


// ---- 1100f6e2 Unwind@1100f6e2  (called by: -)

void Unwind_1100f6e2(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f6eb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x14) + 0xb8));
  return;
}


// ---- 1100f6f1 Unwind@1100f6f1  (called by: -)

void Unwind_1100f6f1(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f6fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x14) + 0x114));
  return;
}


// ---- 1100f700 Unwind@1100f700  (called by: -)

void Unwind_1100f700(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f709. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x14) + 0x118));
  return;
}


// ---- 1100f70f Unwind@1100f70f  (called by: -)

void Unwind_1100f70f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f718. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x14) + 0x11c));
  return;
}


// ---- 1100f71e Unwind@1100f71e  (called by: -)

void Unwind_1100f71e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f727. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x14) + 0x120));
  return;
}


// ---- 1100f72d Unwind@1100f72d  (called by: -)

void Unwind_1100f72d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f736. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x14) + 0x124));
  return;
}


// ---- 1100f73c Unwind@1100f73c  (called by: -)

void Unwind_1100f73c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f745. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x14) + 0x128));
  return;
}


// ---- 1100f74b Unwind@1100f74b  (called by: -)

void Unwind_1100f74b(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f754. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x14) + 300));
  return;
}


// ---- 1100f75a Unwind@1100f75a  (called by: -)

void Unwind_1100f75a(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f763. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x14) + 0x130));
  return;
}


// ---- 1100f769 FUN_1100f769  (called by: -)

void FUN_1100f769(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_11008c60(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f774 Unwind@1100f774  (called by: -)

void Unwind_1100f774(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f777. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100f77d Unwind@1100f77d  (called by: -)

void Unwind_1100f77d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f780. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x14));
  return;
}


// ---- 1100f786 Unwind@1100f786  (called by: -)

void Unwind_1100f786(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f789. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x14));
  return;
}


// ---- 1100f78f Unwind@1100f78f  (called by: -)

void Unwind_1100f78f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f792. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x14));
  return;
}


// ---- 1100f798 Unwind@1100f798  (called by: -)

void Unwind_1100f798(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f79b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x14));
  return;
}


// ---- 1100f7a1 Unwind@1100f7a1  (called by: -)

void Unwind_1100f7a1(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f7a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x14));
  return;
}


// ---- 1100f7aa FUN_1100f7aa  (called by: -)

void FUN_1100f7aa(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_11008c60(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f7b4 Unwind@1100f7b4  (called by: -)

void Unwind_1100f7b4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f7b7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x34));
  return;
}


// ---- 1100f7bd Unwind@1100f7bd  (called by: -)

void Unwind_1100f7bd(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f7c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x34));
  return;
}


// ---- 1100f7c6 Unwind@1100f7c6  (called by: -)

void Unwind_1100f7c6(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f7c9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x34));
  return;
}


// ---- 1100f7cf Unwind@1100f7cf  (called by: -)

void Unwind_1100f7cf(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f7d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x34));
  return;
}


// ---- 1100f7d8 FUN_1100f7d8  (called by: -)

void FUN_1100f7d8(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_11008c60(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f7e4 Unwind@1100f7e4  (called by: -)

void Unwind_1100f7e4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f7e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x24));
  return;
}


// ---- 1100f7ed FUN_1100f7ed  (called by: -)

void FUN_1100f7ed(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_11008c60(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f7f8 Unwind@1100f7f8  (called by: -)

void Unwind_1100f7f8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f7fb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100f801 Unwind@1100f801  (called by: -)

void Unwind_1100f801(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f804. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x14));
  return;
}


// ---- 1100f80a FUN_1100f80a  (called by: -)

void FUN_1100f80a(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_11008c60(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f814 Unwind@1100f814  (called by: -)

void Unwind_1100f814(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f817. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(unaff_EBP + 8));
  return;
}


// ---- 1100f81d FUN_1100f81d  (called by: -)

void FUN_1100f81d(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_11008c60(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f828 Unwind@1100f828  (called by: -)

void Unwind_1100f828(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f82b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x14));
  return;
}


// ---- 1100f831 Unwind@1100f831  (called by: -)

void Unwind_1100f831(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f834. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x14));
  return;
}


// ---- 1100f83a Unwind@1100f83a  (called by: -)

void Unwind_1100f83a(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f83d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x14));
  return;
}


// ---- 1100f843 FUN_1100f843  (called by: -)

void FUN_1100f843(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_11008c60(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f850 Unwind@1100f850  (called by: -)

void Unwind_1100f850(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f853. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScGroup::~ScGroup((ScGroup *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100f859 FUN_1100f859  (called by: -)

void FUN_1100f859(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_11008c60(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f864 Unwind@1100f864  (called by: -)

void Unwind_1100f864(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f867. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100f86d FUN_1100f86d  (called by: -)

void FUN_1100f86d(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_11008c60(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f878 Unwind@1100f878  (called by: -)

void Unwind_1100f878(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f87b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f881 Unwind@1100f881  (called by: -)

void Unwind_1100f881(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f884. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f88a Unwind@1100f88a  (called by: -)

void Unwind_1100f88a(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f88d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f893 Unwind@1100f893  (called by: -)

void Unwind_1100f893(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f896. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f89c Unwind@1100f89c  (called by: -)

void Unwind_1100f89c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f89f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f8a5 Unwind@1100f8a5  (called by: -)

void Unwind_1100f8a5(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f8a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f8ae Unwind@1100f8ae  (called by: -)

void Unwind_1100f8ae(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f8b1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f8b7 Unwind@1100f8b7  (called by: -)

void Unwind_1100f8b7(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f8ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f8c0 Unwind@1100f8c0  (called by: -)

void Unwind_1100f8c0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f8c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f8c9 Unwind@1100f8c9  (called by: -)

void Unwind_1100f8c9(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f8cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f8d2 Unwind@1100f8d2  (called by: -)

void Unwind_1100f8d2(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f8d5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f8db Unwind@1100f8db  (called by: -)

void Unwind_1100f8db(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f8de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f8e4 Unwind@1100f8e4  (called by: -)

void Unwind_1100f8e4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f8e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f8ed Unwind@1100f8ed  (called by: -)

void Unwind_1100f8ed(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f8f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f8f6 Unwind@1100f8f6  (called by: -)

void Unwind_1100f8f6(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f8f9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f8ff Unwind@1100f8ff  (called by: -)

void Unwind_1100f8ff(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f902. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f908 Unwind@1100f908  (called by: -)

void Unwind_1100f908(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f90b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f911 Unwind@1100f911  (called by: -)

void Unwind_1100f911(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f914. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f91a Unwind@1100f91a  (called by: -)

void Unwind_1100f91a(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f91d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f923 Unwind@1100f923  (called by: -)

void Unwind_1100f923(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f926. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f92c Unwind@1100f92c  (called by: -)

void Unwind_1100f92c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f92f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f935 FUN_1100f935  (called by: -)

void FUN_1100f935(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_11008c60(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f940 FUN_1100f940  (called by: -)

void FUN_1100f940(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_11008c60(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f950 Unwind@1100f950  (called by: -)

void Unwind_1100f950(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f953. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScGroup::~ScGroup((ScGroup *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100f959 FUN_1100f959  (called by: -)

void FUN_1100f959(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_11008c60(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f970 FUN_1100f970  (called by: -)

void FUN_1100f970(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_11008c60(param_1,param_2,param_3,param_4);
  return;
}


