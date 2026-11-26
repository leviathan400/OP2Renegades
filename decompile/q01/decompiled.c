// ---- 11001000 FUN_11001000  (called by: FUN_11001050@11001050, FUN_1100106e@1100106e)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_11001000(uint param_1,undefined4 param_2)

{
  if (param_1 < 0x16) {
    **(undefined4 **)(&DAT_1100f054 + param_1 * 4) = param_2;
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
    return **(undefined4 **)(&DAT_1100f054 + param_1 * 4);
  }
  return 0xffffffff;
}


// ---- 11001050 FUN_11001050  (called by: FUN_11003830@11003830)

int FUN_11001050(void)

{
  int iVar1;
  
  iVar1 = FUN_11001039(0xe);
  if (iVar1 != 0) {
    FUN_11001000(0xe,1);
  }
  return iVar1;
}


// ---- 1100106e FUN_1100106e  (called by: FUN_11003830@11003830)

void FUN_1100106e(void)

{
  FUN_11001000(0xe,0);
  return;
}


// ---- 1100107a FUN_1100107a  (called by: FUN_11003862@11003862)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1100107a(void)

{
  HANDLE hFile;
  DWORD _Size;
  DWORD local_4;
  
  DAT_11010350 = _DAT_004ff814;
  hFile = CreateFileA(s_renegmbl_raw_1100f0ac,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                      (HANDLE)0x0);
  _Size = GetFileSize(hFile,(LPDWORD)0x0);
  DAT_11010354 = _malloc(_Size);
  ReadFile(hFile,DAT_11010354,_Size,&local_4,(LPOVERLAPPED)0x0);
  CloseHandle(hFile);
  _DAT_004ff814 = (int)DAT_11010354 - *(int *)(_DAT_00546b98 + 0xec);
  return;
}


// ---- 110010ef FUN_110010ef  (called by: FUN_11003862@11003862)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_110010ef(void)

{
  _DAT_004ff814 = DAT_11010350;
  FUN_11005028(DAT_11010354);
  return;
}


// ---- 11001106 FUN_11001106  (called by: FUN_11003fc8@11003fc8)

undefined4 __cdecl FUN_11001106(undefined4 param_1,LPCSTR param_2)

{
  int iVar1;
  FILE *_File;
  uint uVar2;
  undefined1 unaff_BP;
  char local_4e4c [19952];
  undefined4 uStackY_5c;
  undefined4 uVar3;
  
  FUN_11005610(unaff_BP);
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
        _File = (FILE *)FUN_110055f9(param_2,&DAT_1100f0e0);
        if (_File != (FILE *)0x0) {
          BASS_ChannelGetInfo();
          FUN_1100548f((char *)&WAVE_1100f0c8,0x14,1,(int *)_File);
          FUN_1100548f(local_4e4c + 0x4e34,0x10,1,(int *)_File);
          FUN_1100548f(&DAT_1100f0bc,8,1,(int *)_File);
          while (iVar1 = BASS_ChannelIsActive(), iVar1 != 0) {
            uVar2 = BASS_ChannelGetData();
            FUN_1100548f(local_4e4c,1,uVar2,(int *)_File);
            BASS_ChannelGetPosition();
          }
          FUN_11005329((int *)_File);
          iVar1 = FUN_110051a6((char *)_File);
          FUN_110050ed((int *)_File,4,0);
          __putw(iVar1 + -8,_File);
          FUN_11005329((int *)_File);
          FUN_110050ed((int *)_File,0x28,0);
          __putw(iVar1 + -0x2c,_File);
          FUN_11005329((int *)_File);
          uStackY_5c = 0x1100127c;
          FUN_11005070(_File);
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


// ---- 11001286 GetCargo  (called by: -)

/* public: enum map_id __thiscall IUnit::GetCargo(void) */

map_id __thiscall IUnit::GetCargo(IUnit *this)

{
  map_id mVar1;
  
                    /* WARNING: Could not recover jumptable at 0x11001286. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x1286  2  ?GetCargo@IUnit@@QAE?AW4map_id@@XZ */
  mVar1 = Unit::GetCargo((Unit *)this);
  return mVar1;
}


// ---- 1100128c operator=  (called by: -)

/* public: class IUnit & __thiscall IUnit::operator=(class IUnit const &) */

IUnit * __thiscall IUnit::operator=(IUnit *this,IUnit *param_1)

{
                    /* 0x128c  1  ??4IUnit@@QAEAAV0@ABV0@@Z */
  Unit::operator=((Unit *)this,(Unit *)param_1);
  return this;
}


// ---- 1100129f FUN_1100129f  (called by: FUN_1100135c@1100135c)

int __cdecl FUN_1100129f(int param_1,map_id param_2,map_id param_3)

{
  int iVar1;
  map_id mVar2;
  int iVar3;
  PlayerBuildingEnum local_10 [8];
  undefined4 local_8;
  
  iVar3 = 0;
  local_8 = 0;
  PlayerBuildingEnum::PlayerBuildingEnum(local_10,param_1,param_2);
  while (iVar1 = PlayerBuildingEnum::GetNext(local_10,(Unit *)&local_8), iVar1 != 0) {
    mVar2 = Unit::GetType((Unit *)&local_8);
    if ((mVar2 == param_2) &&
       ((param_3 == 0xffffffff || (mVar2 = Unit::GetWeapon((Unit *)&local_8), mVar2 == param_3)))) {
      iVar3 = iVar3 + 1;
    }
  }
  return iVar3;
}


// ---- 11001300 FUN_11001300  (called by: FUN_1100135c@1100135c)

int __cdecl FUN_11001300(int param_1,map_id param_2,map_id param_3)

{
  int iVar1;
  map_id mVar2;
  int iVar3;
  undefined4 local_8;
  
  iVar3 = 0;
  local_8 = 0;
  PlayerVehicleEnum::PlayerVehicleEnum((PlayerVehicleEnum *)&param_1,param_1);
  while (iVar1 = PlayerVehicleEnum::GetNext((PlayerVehicleEnum *)&param_1,(Unit *)&local_8),
        iVar1 != 0) {
    mVar2 = Unit::GetType((Unit *)&local_8);
    if ((mVar2 == param_2) &&
       ((param_3 == 0xffffffff || (mVar2 = Unit::GetWeapon((Unit *)&local_8), mVar2 == param_3)))) {
      iVar3 = iVar3 + 1;
    }
  }
  return iVar3;
}


// ---- 1100135c FUN_1100135c  (called by: FUN_11004220@11004220)

void __cdecl FUN_1100135c(int param_1,map_id param_2,map_id param_3)

{
  if ((int)param_2 < 0x11) {
    FUN_11001300(param_1,param_2,param_3);
  }
  else {
    FUN_1100129f(param_1,param_2,param_3);
  }
  return;
}


// ---- 1100137f FUN_1100137f  (called by: InitProc@11002d9f)

void FUN_1100137f(void)

{
  undefined4 extraout_EDX;
  undefined4 uVar1;
  undefined4 extraout_EDX_00;
  int local_c;
  undefined4 local_8;
  
  local_c = 0x400;
  local_8 = 0x400;
  LOCATION::Clip((LOCATION *)&local_c);
  uVar1 = extraout_EDX;
  while (local_c = local_c + -1, 0x1e < local_c) {
    GameMap::SetCellType(6,uVar1,local_c,local_8);
    uVar1 = extraout_EDX_00;
  }
  return;
}


// ---- 110013b5 FUN_110013b5  (called by: FUN_1100298c@1100298c)

undefined4 __cdecl
FUN_110013b5(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_3;
  if (param_5 < param_3) {
    iVar3 = param_5;
    param_5 = param_3;
  }
  iVar2 = param_4;
  if (param_6 < param_4) {
    iVar2 = param_6;
    param_6 = param_4;
  }
  if ((((param_1 < iVar3) || (param_5 < param_1)) || (param_2 < iVar2)) || (param_6 < param_2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ---- 110013f9 FUN_110013f9  (called by: FUN_110014e4@110014e4)

void __cdecl FUN_110013f9(int param_1,int param_2,int param_3,int param_4,map_id param_5)

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


// ---- 11001461 FUN_11001461  (called by: InitProc@11002d9f)

void FUN_11001461(void)

{
  Trigger *pTVar1;
  int unaff_EBP;
  
  FUN_11005a18();
  Trigger::Trigger((Trigger *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  pTVar1 = (Trigger *)CreateOperationalTrigger(unaff_EBP + -0x14,1,1,0,0x1c,0,(char *)0x0);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  Trigger::operator=((Trigger *)(unaff_EBP + -0x10),pTVar1);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  CreateFailureCondition(unaff_EBP + -0x14,1,(Trigger *)0x1,(char *)(unaff_EBP + -0x10));
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 110014e4 FUN_110014e4  (called by: InitProc@11002d9f)

void __cdecl FUN_110014e4(undefined4 param_1,int param_2,int param_3,int *param_4)

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
      FUN_110013f9(*piVar2 + param_2,piVar2[1] + param_3,piVar2[2] + param_2,piVar2[3] + param_3,
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
      FUN_110013f9(*piVar2 + param_2,piVar2[1] + param_3,piVar2[2] + param_2,piVar2[3] + param_3,
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


// ---- 1100160d FUN_1100160d  (called by: InitProc@11002d9f)

void __cdecl FUN_1100160d(int param_1,int param_2)

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


// ---- 1100163e FUN_1100163e  (called by: FUN_1100163e@1100163e, FUN_11001f2a@11001f2a)

void FUN_1100163e(void)

{
  int unaff_EBP;
  int iVar1;
  int iVar2;
  
  FUN_11005a18();
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
      FUN_1100163e();
      FUN_1100163e();
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11001907 FUN_11001907  (called by: -)

void FUN_11001907(void)

{
  FUN_11001a01();
  return;
}


// ---- 11001911 FUN_11001911  (called by: -)

void FUN_11001911(void)

{
  FUN_11005ab5(0x1100191d);
  return;
}


// ---- 1100191d FUN_1100191d  (called by: -)

void FUN_1100191d(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_11005a18();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0xf;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x17c));
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x178));
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x174));
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x170));
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x16c));
  *(undefined1 *)(unaff_EBP + -4) = 10;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x168));
  *(undefined1 *)(unaff_EBP + -4) = 9;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x164));
  *(undefined1 *)(unaff_EBP + -4) = 8;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x160));
  *(undefined1 *)(unaff_EBP + -4) = 7;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x40));
  *(undefined1 *)(unaff_EBP + -4) = 6;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x3c));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x38));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x34));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x30));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x2c));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x28));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x24));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x20));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11001a01 FUN_11001a01  (called by: FUN_11001907@11001907)

int FUN_11001a01(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_11005a18();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  IUnit::IUnit((IUnit *)(extraout_ECX + 8));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0xc));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x10));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x14));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x18));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x1c));
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x20));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x24));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x28));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x2c));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x30));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x34));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x38));
  *(undefined1 *)(unaff_EBP + -4) = 6;
  BuildingGroup::BuildingGroup((BuildingGroup *)(extraout_ECX + 0x3c));
  *(undefined1 *)(unaff_EBP + -4) = 7;
  MiningGroup::MiningGroup((MiningGroup *)(extraout_ECX + 0x40));
  *(undefined1 *)(unaff_EBP + -4) = 8;
  Trigger::Trigger((Trigger *)(extraout_ECX + 0x160));
  *(undefined1 *)(unaff_EBP + -4) = 9;
  Trigger::Trigger((Trigger *)(extraout_ECX + 0x164));
  *(undefined1 *)(unaff_EBP + -4) = 10;
  Trigger::Trigger((Trigger *)(extraout_ECX + 0x168));
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  Trigger::Trigger((Trigger *)(extraout_ECX + 0x16c));
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  Trigger::Trigger((Trigger *)(extraout_ECX + 0x170));
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  Trigger::Trigger((Trigger *)(extraout_ECX + 0x174));
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  Trigger::Trigger((Trigger *)(extraout_ECX + 0x178));
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  Trigger::Trigger((Trigger *)(extraout_ECX + 0x17c));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  DAT_11012000 = 0x30;
  DAT_11012004 = 0x1b;
  *(undefined4 *)(extraout_ECX + 0x5c) = 1;
  *(undefined1 *)(extraout_ECX + 0x57) = 0;
  *(undefined1 *)(extraout_ECX + 0x58) = 0;
  *(undefined1 *)(extraout_ECX + 0x59) = 0;
  *(undefined1 *)(extraout_ECX + 0x5a) = 0;
  *(undefined4 *)(extraout_ECX + 0x180) = 0x10;
  *(undefined4 *)(extraout_ECX + 0x184) = 0x11;
  *(undefined4 *)(extraout_ECX + 0x188) = 0;
  return extraout_ECX;
}


// ---- 11001b58 StatusProc  (called by: -)

undefined4 StatusProc(void)

{
                    /* 0x1b58  11  StatusProc */
  return 0;
}


// ---- 11001b5b NoResponseToTrigger  (called by: -)

void NoResponseToTrigger(void)

{
                    /* 0x1b5b  10  NoResponseToTrigger */
  return;
}


// ---- 11001b5c FUN_11001b5c  (called by: -)

void FUN_11001b5c(void)

{
  FightGroup *pFVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  FUN_11005a18();
  FightGroup::FightGroup((FightGroup *)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FightGroup::FightGroup((FightGroup *)(unaff_EBP + -0x18));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FightGroup::FightGroup((FightGroup *)(unaff_EBP + -0x14));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  IUnit::IUnit((IUnit *)(unaff_EBP + -0x10));
  pFVar1 = (FightGroup *)
           CreateFightGroup(unaff_EBP + -0x20,extraout_EDX,*(undefined4 *)(Player_exref + 0xc),
                            *(undefined4 *)(Player_exref + 0x10),
                            *(undefined4 *)(Player_exref + 0x14));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FightGroup::operator=((FightGroup *)(unaff_EBP + -0x1c),pFVar1);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x20));
  *(undefined **)(unaff_EBP + -0x24) = &DAT_110103f0;
  FightGroup::SetPatrolMode((FightGroup *)(unaff_EBP + -0x1c),(PatrolRoute *)(unaff_EBP + -0x28));
  pFVar1 = (FightGroup *)CreateFightGroup(unaff_EBP + -0x20);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FightGroup::operator=((FightGroup *)(unaff_EBP + -0x18),pFVar1);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x20));
  *(undefined **)(unaff_EBP + -0x2c) = &DAT_11010420;
  FightGroup::SetPatrolMode((FightGroup *)(unaff_EBP + -0x18),(PatrolRoute *)(unaff_EBP + -0x30));
  uVar2 = *(undefined4 *)(Player_exref + 0xc);
  uVar3 = *(undefined4 *)(Player_exref + 0x10);
  uVar4 = *(undefined4 *)(Player_exref + 0x14);
  pFVar1 = (FightGroup *)CreateFightGroup(unaff_EBP + -0x20);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FightGroup::operator=((FightGroup *)(unaff_EBP + -0x14),pFVar1);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x20));
  *(undefined **)(unaff_EBP + -0x34) = &DAT_110103b0;
  FightGroup::SetPatrolMode((FightGroup *)(unaff_EBP + -0x14),(PatrolRoute *)(unaff_EBP + -0x38));
  TethysGame::CreateUnit(unaff_EBP + -0x10,0xb,0x9e,2,1,0,4,uVar2,uVar3,uVar4);
  ScGroup::TakeUnit((ScGroup *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x10));
  TethysGame::CreateUnit(unaff_EBP + -0x10,0xb,0x9e,4,1,0,3);
  ScGroup::TakeUnit((ScGroup *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x10));
  TethysGame::CreateUnit(unaff_EBP + -0x10,0xb,0x9e,6,1,0,3);
  ScGroup::TakeUnit((ScGroup *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x10));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x18));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x1c));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11001cfd FUN_11001cfd  (called by: -)

void FUN_11001cfd(void)

{
  int iVar1;
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  iVar1 = (DAT_11012054 != '\0') + 2;
  do {
    TethysGame::CreateUnit(&local_8,1,0x21,0x3c,0,0,0);
    Unit::DoMove((Unit *)&local_8,DAT_11012000 + -4,DAT_11012004 + 4);
    Unit::DoSetLights((Unit *)&local_8,1);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  scr_snprintf(&DAT_11010358,0x50,s__d_extra_cargo_trucks_have_arriv_1100f388,
               (DAT_11012054 != '\0') + 2);
  TethysGame::AddMessage(&DAT_11010358,0,local_8,0xa2);
  return;
}


// ---- 11001d9d FUN_11001d9d  (called by: -)

void FUN_11001d9d(void)

{
  FUN_11004190('\x01','\x01',DAT_11012048 * 1000 + 0x9c4,FUN_11001cfd,0);
  return;
}


// ---- 11001dc2 FUN_11001dc2  (called by: -)

void FUN_11001dc2(void)

{
  FUN_11004190('\x01','\x01',DAT_11012048 * 1000 + 500,FUN_11001cfd,0);
  return;
}


// ---- 11001de7 FUN_11001de7  (called by: FUN_11001f2a@11001f2a)

void FUN_11001de7(void)

{
  int iVar1;
  map_id mVar2;
  GroupEnumerator local_10 [4];
  undefined4 local_c;
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  IUnit::IUnit((IUnit *)&local_c);
  GroupEnumerator::GroupEnumerator(local_10,(ScGroup *)&DAT_1101203c);
  iVar1 = GroupEnumerator::GetNext(local_10,(Unit *)&local_8);
  while (iVar1 != 0) {
    iVar1 = Unit::IsVehicle((Unit *)&local_8);
    if ((iVar1 != 0) && (iVar1 = Unit::IsLive((Unit *)&local_8), iVar1 == 0)) {
      mVar2 = Unit::GetType((Unit *)&local_8);
      TethysGame::CreateUnit(&local_c,mVar2,0x9e,5,1,0,4);
      ScGroup::RemoveUnit((ScGroup *)&DAT_1101203c,local_8);
      ScGroup::TakeUnit((ScGroup *)&DAT_1101203c,local_c);
    }
    iVar1 = GroupEnumerator::GetNext(local_10,(Unit *)&local_8);
  }
  DAT_1101205a = 0;
  return;
}


// ---- 11001e91 FUN_11001e91  (called by: -)

void FUN_11001e91(void)

{
  int iVar1;
  
  iVar1 = IUnit::GetDamage((IUnit *)&DAT_1101201c);
  if (iVar1 < 0xc9) goto LAB_11001f02;
  if (DAT_11012018 == 0) {
LAB_11001ec9:
    TethysGame::CreateUnit(&DAT_11012018,2,0x9f,0x3a,1,0x40,4);
    ScGroup::TakeUnit((ScGroup *)&DAT_11012038,DAT_11012018);
  }
  else {
    iVar1 = Unit::IsLive((Unit *)&DAT_11012018);
    if (iVar1 == 0) goto LAB_11001ec9;
  }
  IUnit::Repair((IUnit *)&DAT_11012018,DAT_1101201c);
LAB_11001f02:
  iVar1 = IUnit::GetDamage((IUnit *)&DAT_1101201c);
  if ((iVar1 == 0) && (0 < DAT_11012018)) {
    iVar1 = Unit::IsLive((Unit *)&DAT_11012018);
    if (iVar1 != 0) {
      FightGroup::DoExitMap((FightGroup *)&DAT_11012038);
    }
  }
  return;
}


// ---- 11001f2a FUN_11001f2a  (called by: FUN_11002412@11002412)

void FUN_11001f2a(void)

{
  BuildingGroup *pBVar1;
  MAP_RECT *pMVar2;
  PlayerBuildingEnum *pPVar3;
  void *unaff_retaddr;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  Unit *pUVar4;
  PlayerBuildingEnum local_8 [4];
  undefined4 uStack_4;
  
  uStack_4 = 0x11001f34;
  FUN_11005a18();
  if (DAT_11012057 == '\0') {
    DAT_11012057 = '\x01';
    uStack_40 = 0x11001f7b;
    TethysGame::CreateUnit(&DAT_11012008,2);
    uStack_40 = 2;
    uStack_44 = 0;
    uStack_48 = 1;
    uStack_4c = 5;
    uStack_50 = 0x9e;
    uStack_54 = 0x11001f8e;
    TethysGame::CreateUnit(&DAT_1101200c,0xf);
    uStack_54 = 4;
    uStack_58 = 0;
    uStack_5c = 1;
    uStack_60 = 5;
    TethysGame::CreateUnit(&DAT_11012014,9,0x9e);
    pUVar4 = (Unit *)&DAT_11012010;
    pPVar3 = (PlayerBuildingEnum *)
             PlayerBuildingEnum::PlayerBuildingEnum((PlayerBuildingEnum *)&uStack_54,1,0x2f);
    PlayerBuildingEnum::GetNext(pPVar3,pUVar4);
    pBVar1 = (BuildingGroup *)CreateBuildingGroup(&uStack_54);
    uStack_40 = 0;
    BuildingGroup::operator=((BuildingGroup *)&DAT_1101203c,pBVar1);
    uStack_40 = 0xffffffff;
    ScStub::~ScStub((ScStub *)&uStack_60);
    pMVar2 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)&uStack_60,0x94,6,0x9a,8);
    BuildingGroup::SetRect((BuildingGroup *)&DAT_1101203c,pMVar2);
    uStack_60 = 0x91;
    uStack_5c = 0x1d;
    BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101203c,(LOCATION *)&uStack_60,0x15,0);
    uStack_60 = 0x89;
    uStack_5c = 6;
    BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101203c,(LOCATION *)&uStack_60,0x17,0x3d);
    uStack_60 = 0x8e;
    uStack_5c = 0x10;
    BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101203c,(LOCATION *)&uStack_60,0x17,0x3d);
    uStack_60 = 0x8f;
    uStack_5c = 0x19;
    BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101203c,(LOCATION *)&uStack_60,0x17,0x3d);
    uStack_60 = 0x9b;
    uStack_5c = 5;
    BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101203c,(LOCATION *)&uStack_60,0x19,0);
    uStack_60 = 0x8e;
    uStack_5c = 0x22;
    BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101203c,(LOCATION *)&uStack_60,0x17,0x3d);
    uStack_60 = 0x8a;
    uStack_5c = 0x10;
    BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101203c,(LOCATION *)&uStack_60,0x17,0x3d);
    uStack_60 = 0x93;
    uStack_5c = 6;
    BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101203c,(LOCATION *)&uStack_60,0x17,0x3d);
    uStack_60 = 0x8a;
    uStack_5c = 2;
    BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101203c,(LOCATION *)&uStack_60,0x3a,0);
    FUN_1100163e();
    FUN_1100163e();
    FUN_1100163e();
    FUN_1100163e();
    FUN_1100163e();
    FUN_1100163e();
    ScGroup::TakeUnit((ScGroup *)&DAT_1101203c,DAT_11012008);
    ScGroup::TakeUnit((ScGroup *)&DAT_1101203c,DAT_1101200c);
    ScGroup::TakeUnit((ScGroup *)&DAT_1101203c,DAT_11012014);
    ScGroup::TakeUnit((ScGroup *)&DAT_1101203c,DAT_11012010);
    uStack_40 = 0x1100220d;
    FUN_11004190('\x01','\0',0x4b0,FUN_11001de7,0);
  }
  else {
    FUN_11001de7();
  }
  pUVar4 = (Unit *)&DAT_1101201c;
  pPVar3 = (PlayerBuildingEnum *)PlayerBuildingEnum::PlayerBuildingEnum(local_8,1,0x3a);
  PlayerBuildingEnum::GetNext(pPVar3,pUVar4);
  uStack_40 = 0x11002240;
  FUN_11004190('\x01','\0',500,FUN_11001e91,0);
  ExceptionList = unaff_retaddr;
  return;
}


// ---- 11002254 FUN_11002254  (called by: -)

void FUN_11002254(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  GroupEnumerator local_10 [4];
  undefined4 local_c;
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  iVar3 = 0;
  puVar1 = (undefined4 *)GroupEnumerator::GroupEnumerator(local_10,(ScGroup *)&DAT_11012040);
  local_c = *puVar1;
  iVar2 = GroupEnumerator::GetNext((GroupEnumerator *)&local_c,(Unit *)&local_8);
  if (iVar2 != 0) {
    do {
      iVar2 = Unit::IsLive((Unit *)&local_8);
      if (iVar2 == 0) {
        ScGroup::RemoveUnit((ScGroup *)&DAT_11012040,local_8);
      }
      else {
        iVar3 = iVar3 + 1;
      }
      iVar2 = GroupEnumerator::GetNext((GroupEnumerator *)&local_c,(Unit *)&local_8);
    } while (iVar2 != 0);
    if (2 < iVar3) {
      return;
    }
  }
  TethysGame::CreateUnit(&local_8,1,0x9e,4,1,0,4);
  ScGroup::TakeUnit((ScGroup *)&DAT_11012040,local_8);
  return;
}


// ---- 110022e9 FUN_110022e9  (called by: InitProc@11002d9f)

void FUN_110022e9(void)

{
  undefined4 *puVar1;
  PlayerBuildingEnum *pPVar2;
  int iVar3;
  undefined4 uVar4;
  map_id mVar5;
  Unit *pUVar6;
  MAP_RECT local_24 [8];
  PlayerBuildingEnum local_1c [4];
  PlayerVehicleEnum local_18 [4];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_c);
  IUnit::IUnit((IUnit *)&local_8);
  IUnit::IUnit((IUnit *)&local_10);
  puVar1 = (undefined4 *)PlayerVehicleEnum::PlayerVehicleEnum(local_18,1);
  local_14 = *puVar1;
  pUVar6 = (Unit *)&local_10;
  pPVar2 = (PlayerBuildingEnum *)PlayerBuildingEnum::PlayerBuildingEnum(local_1c,1,0x15);
  iVar3 = PlayerBuildingEnum::GetNext(pPVar2,pUVar6);
  if (iVar3 != 0) {
    pUVar6 = (Unit *)&local_c;
    pPVar2 = (PlayerBuildingEnum *)PlayerBuildingEnum::PlayerBuildingEnum(local_1c,1,0x36);
    iVar3 = PlayerBuildingEnum::GetNext(pPVar2,pUVar6);
    if (iVar3 != 0) {
      uVar4 = MAP_RECT::MAP_RECT(local_24,0x8d,5,0x93,9);
      MiningGroup::Setup((MiningGroup *)&DAT_11012040,local_10,local_c,uVar4);
      while (iVar3 = PlayerVehicleEnum::GetNext((PlayerVehicleEnum *)&local_14,(Unit *)&local_8),
            iVar3 != 0) {
        mVar5 = Unit::GetType((Unit *)&local_8);
        if (mVar5 == 1) {
          ScGroup::TakeUnit((ScGroup *)&DAT_11012040,local_8);
        }
      }
      FUN_11004190('\x01','\0',500,FUN_11002254,0);
      FUN_11004270('\x01','\x01',1,0x15,0xffffffff,0,0,FUN_11002412,0);
      ScGroup::RemoveUnit((ScGroup *)&DAT_1101203c,DAT_11012014);
      return;
    }
  }
  FUN_11004190('\x01','\x01',500,FUN_110022e9,0);
  return;
}


// ---- 11002412 FUN_11002412  (called by: -)

void FUN_11002412(void)

{
  if (DAT_11012057 != '\0') {
    TethysGame::CreateUnit(&DAT_11012014,9,0x9e,5,1,0,4);
    ScGroup::TakeUnit((ScGroup *)&DAT_1101203c,DAT_11012014);
  }
  FUN_11004270('\x01','\x01',1,0x15,0xffffffff,1,0,FUN_110022e9,0);
  FUN_11001f2a();
  return;
}


// ---- 1100246e FUN_1100246e  (called by: -)

void FUN_1100246e(void)

{
  char *pcVar1;
  int iVar2;
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  iVar2 = 3;
  do {
    TethysGame::CreateUnit(&local_8,5,0x21,0x3c,0,0x3e,0);
    Unit::DoMove((Unit *)&local_8,DAT_11012000 + -4,DAT_11012004 + 4);
    Unit::DoSetLights((Unit *)&local_8,1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (DAT_11012050 < 2) {
    pcVar1 = s_No_more_reinforcements_available_1100f3ac;
  }
  else {
    pcVar1 = s_Reinforcements_have_arrived_1100f3d0;
  }
  TethysGame::AddMessage(pcVar1,0,local_8,0xa2);
  return;
}


// ---- 110024f0 FUN_110024f0  (called by: FUN_110026c1@110026c1)

void FUN_110024f0(void)

{
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  TethysGame::CreateUnit(&local_8,5,0x9e,3,1,0x3d,0);
  ScGroup::TakeUnit((ScGroup *)&DAT_11012030,local_8);
  if (DAT_11012054 == '\0') {
    TethysGame::CreateUnit(&local_8,5,0x9e,3,1,0x3d,0);
    ScGroup::TakeUnit((ScGroup *)&DAT_11012030,local_8);
  }
  return;
}


// ---- 1100255c FUN_1100255c  (called by: FUN_1100257a@1100257a)

void FUN_1100255c(void)

{
  FUN_11004120('\x01','\x01',500,1000,FUN_110024f0,0);
  return;
}


// ---- 1100257a FUN_1100257a  (called by: -)

int FUN_1100257a(void)

{
  PlayerBuildingEnum *this;
  int iVar1;
  LOCATION *pLVar2;
  MAP_RECT *pMVar3;
  int iVar4;
  undefined1 *puVar5;
  Unit *pUVar6;
  MAP_RECT local_28 [8];
  undefined1 local_20 [8];
  int local_18;
  int local_14;
  PlayerBuildingEnum local_10 [4];
  GroupEnumerator local_c [4];
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  pUVar6 = (Unit *)&local_8;
  local_18 = 0;
  local_14 = 0;
  this = (PlayerBuildingEnum *)PlayerBuildingEnum::PlayerBuildingEnum(local_10,0,0x3a);
  iVar1 = PlayerBuildingEnum::GetNext(this,pUVar6);
  if (iVar1 == 0) {
    FightGroup::DoAttackEnemy((FightGroup *)&DAT_11012034);
  }
  else {
    pLVar2 = (LOCATION *)Unit::Location((Unit *)&local_8);
    LOCATION::operator=((LOCATION *)&local_18,pLVar2);
    FightGroup::ClearGuarderdRects((FightGroup *)&DAT_11012034);
    pMVar3 = (MAP_RECT *)
             MAP_RECT::MAP_RECT(local_28,local_18 + -3,local_14 + -3,local_18 + 3,local_14 + 3);
    FightGroup::SetRect((FightGroup *)&DAT_11012034,pMVar3);
  }
  iVar1 = TethysGame::Tick();
  iVar4 = iVar1 / 16000;
  if ((0x251c < iVar1 % 16000) && (iVar1 % 16000 < 0x34bc)) {
    GroupEnumerator::GroupEnumerator(local_c,(ScGroup *)&DAT_11012030);
    while ((iVar1 = GroupEnumerator::GetNext(local_c,(Unit *)&local_8), iVar1 != 0 &&
           (iVar1 = ScGroup::TotalUnitCount((ScGroup *)&DAT_11012034), iVar1 != 4))) {
      puVar5 = local_20;
      iVar1 = Unit::Location((Unit *)&local_8);
      if (0x22 < *(int *)(iVar1 + 4)) {
        ScGroup::RemoveUnit((ScGroup *)&DAT_11012030,local_8,puVar5);
        ScGroup::TakeUnit((ScGroup *)&DAT_11012034,local_8);
      }
    }
    if (DAT_11012056 != '\0') {
      FUN_11004410('\x01','\x01',(ScStub *)&DAT_11012034,2,FUN_1100255c,0);
    }
    iVar4 = FUN_1100255c();
  }
  return iVar4;
}


// ---- 110026c1 FUN_110026c1  (called by: -)

void FUN_110026c1(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  IUnit aIStack_4 [4];
  
  if (DAT_11012058 == '\0') {
    IUnit::IUnit(aIStack_4);
    iVar3 = DAT_11012048;
    iVar1 = DAT_11012048 + 2;
    if (0 < iVar1) {
      iVar2 = iVar1;
      do {
        uVar4 = 3;
        TethysGame::CreateUnit(aIStack_4,5,0x9e,2,1,0x3d,3);
        ScGroup::TakeUnit((ScGroup *)&DAT_11012020,uVar4);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    if ((DAT_11012054 == '\0') && (1 < iVar1)) {
      iVar3 = iVar3 + 1;
      do {
        uVar4 = 3;
        TethysGame::CreateUnit(aIStack_4,5,0x9e,5,1,0x3d,3);
        ScGroup::TakeUnit((ScGroup *)&DAT_11012028,uVar4);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    FUN_110024f0();
    DAT_11012058 = '\x01';
  }
  return;
}


// ---- 11002768 FUN_11002768  (called by: -)

void FUN_11002768(void)

{
  undefined4 uVar1;
  undefined1 auStack_42 [14];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  IUnit aIStack_4 [4];
  
  if (DAT_11012059 == '\0') {
    uStack_18 = 0x11002783;
    IUnit::IUnit(aIStack_4);
    uStack_18 = 3;
    uStack_1c = 0x3d;
    uStack_20 = 1;
    uStack_24 = 2;
    uStack_28 = 0x9e;
    uStack_2c = 0x110027a4;
    TethysGame::CreateUnit(aIStack_4,5);
    uStack_2c = uStack_18;
    uStack_30 = 0x110027b7;
    ScGroup::TakeUnit((ScGroup *)&DAT_11012024);
    uStack_30 = 3;
    uStack_34 = 0x3d;
    TethysGame::CreateUnit(&uStack_1c,5);
    ScGroup::TakeUnit((ScGroup *)&DAT_11012024);
    if (DAT_11012054 == '\0') {
      uVar1 = 4;
      TethysGame::CreateUnit(&uStack_34,5,0x9e,4,1);
      ScGroup::TakeUnit((ScGroup *)&DAT_1101202c,uVar1);
      uVar1 = 4;
      TethysGame::CreateUnit(auStack_42 + -10,5,0x9e,6,1,0x3d,4);
      ScGroup::TakeUnit((ScGroup *)&DAT_1101202c,uVar1);
    }
    FUN_11004410('\x01','\x01',(ScStub *)&DAT_1101202c,1,FUN_110028d5,0);
    DAT_11012059 = '\x01';
  }
  return;
}


// ---- 11002841 FUN_11002841  (called by: -)

void FUN_11002841(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  iVar2 = 0;
  if (0 < DAT_11012044) {
    do {
      iVar1 = TethysGame::GetRand(8);
      TethysGame::CreateUnit(&local_8,5,0x9c,4,1,0x3d,iVar1);
      ScGroup::TakeUnit((ScGroup *)&DAT_1101202c,local_8);
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_11012044);
  }
  if (DAT_1101205a != '\0') {
    FUN_11004190('\x01','\x01',200,FUN_11001f2a,0);
  }
  FUN_11004410('\x01','\x01',(ScStub *)&DAT_1101202c,2,FUN_110028d5,0);
  return;
}


// ---- 110028d5 FUN_110028d5  (called by: -)

void FUN_110028d5(void)

{
  int iVar1;
  
  iVar1 = DAT_1101204c + 5;
  FUN_11004120('\x01','\x01',2000,4000,FUN_11002841,0);
  DAT_11012050 = DAT_11012050 + -1;
  if (0 < DAT_11012050) {
    FUN_11004120('\x01','\x01',1000,2000,FUN_1100246e,0);
  }
  DAT_11012044 = DAT_11012044 + 1;
  if (iVar1 < DAT_11012044) {
    DAT_11012044 = iVar1;
  }
  return;
}


// ---- 1100293c FUN_1100293c  (called by: -)

void FUN_1100293c(void)

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


// ---- 11002965 FUN_11002965  (called by: -)

void FUN_11002965(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  iVar1 = TethysGame::GetRand(0x3e);
  iVar2 = TethysGame::GetRand(100);
  TethysGame::SetEarthquake(iVar2 + 0x20,iVar1 + 1,iVar3);
  return;
}


// ---- 1100298c FUN_1100298c  (called by: -)

void FUN_1100298c(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  MAP_RECT aMStack_10 [16];
  
  do {
    iVar1 = TethysGame::GetRand(0x6e);
    iVar2 = TethysGame::GetRand(0x40);
    piVar3 = (int *)MAP_RECT::MAP_RECT(aMStack_10,0xd,0x15,0x19,0x1e);
    uVar4 = FUN_110013b5(iVar1,iVar2,*piVar3,piVar3[1],piVar3[2],piVar3[3]);
  } while ((char)uVar4 != '\0');
  TethysGame::SetMeteor(iVar1 + 0x1f,iVar2 + -1,1);
  return;
}


// ---- 110029f1 FUN_110029f1  (called by: InitProc@11002d9f)

void FUN_110029f1(void)

{
  code *pcVar1;
  FightGroup *pFVar2;
  MAP_RECT *pMVar3;
  MiningGroup *pMVar4;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  int unaff_EBP;
  
  FUN_11005a18();
  *(undefined4 *)(unaff_EBP + -0x3c) = 2;
  *(undefined4 *)(unaff_EBP + -0x40) = 0x8b;
  *(undefined4 *)(unaff_EBP + -0x34) = 0x21;
  *(undefined4 *)(unaff_EBP + -0x38) = 0x8d;
  *(undefined4 *)(unaff_EBP + -0x2c) = 7;
  *(undefined4 *)(unaff_EBP + -0x30) = 0x95;
  *(undefined4 *)(unaff_EBP + -0x24) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x78) = 0x88;
  *(undefined4 *)(unaff_EBP + -0x74) = 0xe;
  *(undefined4 *)(unaff_EBP + -0x70) = 0x57;
  *(undefined4 *)(unaff_EBP + -0x6c) = 0x17;
  *(undefined4 *)(unaff_EBP + -0x68) = 0x30;
  *(undefined4 *)(unaff_EBP + -100) = 9;
  *(undefined4 *)(unaff_EBP + -0x60) = 0x28;
  *(undefined4 *)(unaff_EBP + -0x5c) = 0x30;
  *(undefined4 *)(unaff_EBP + -0x58) = 0x2e;
  *(undefined4 *)(unaff_EBP + -0x50) = 0x8a;
  *(undefined4 *)(unaff_EBP + -0x54) = 0x2c;
  *(undefined4 *)(unaff_EBP + -0x48) = 0xffffffff;
  pcVar1 = Player_exref;
  *(undefined4 *)(unaff_EBP + -0x4c) = 0x30;
  *(undefined4 *)(unaff_EBP + -0x44) = 0xffffffff;
  pFVar2 = (FightGroup *)
           CreateFightGroup(unaff_EBP + -0x10,extraout_EDX,*(undefined4 *)(pcVar1 + 0xc),
                            *(undefined4 *)(pcVar1 + 0x10),*(undefined4 *)(pcVar1 + 0x14));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FightGroup::operator=((FightGroup *)&DAT_11012020,pFVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(unaff_EBP + -0x20),0x8b,4,0x98,0x16);
  FightGroup::SetRect((FightGroup *)&DAT_11012020,pMVar3);
  *(int *)(unaff_EBP + -0x7c) = unaff_EBP + -0x40;
  FightGroup::SetPatrolMode((FightGroup *)&DAT_11012020,(PatrolRoute *)(unaff_EBP + -0x80));
  ScGroup::SetLights((ScGroup *)&DAT_11012020,1);
  pFVar2 = (FightGroup *)
           CreateFightGroup(unaff_EBP + -0x10,extraout_EDX_00,*(undefined4 *)(Player_exref + 0xc),
                            *(undefined4 *)(Player_exref + 0x10),
                            *(undefined4 *)(Player_exref + 0x14));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FightGroup::operator=((FightGroup *)&DAT_11012024,pFVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(unaff_EBP + -0x20),0x8b,4,0x98,0x16);
  FightGroup::SetRect((FightGroup *)&DAT_11012024,pMVar3);
  *(int *)(unaff_EBP + -0x84) = unaff_EBP + -0x78;
  FightGroup::SetPatrolMode((FightGroup *)&DAT_11012024,(PatrolRoute *)(unaff_EBP + -0x88));
  ScGroup::SetLights((ScGroup *)&DAT_11012024,1);
  pFVar2 = (FightGroup *)
           CreateFightGroup(unaff_EBP + -0x10,extraout_EDX_01,*(undefined4 *)(Player_exref + 0xc),
                            *(undefined4 *)(Player_exref + 0x10),
                            *(undefined4 *)(Player_exref + 0x14));
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FightGroup::operator=((FightGroup *)&DAT_11012028,pFVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(unaff_EBP + -0x20),0x8b,3,0x9c,10);
  FightGroup::SetRect((FightGroup *)&DAT_11012028,pMVar3);
  FightGroup::DoGuardRect((FightGroup *)&DAT_11012028);
  ScGroup::SetLights((ScGroup *)&DAT_11012028,1);
  pFVar2 = (FightGroup *)
           CreateFightGroup(unaff_EBP + -0x10,extraout_EDX_02,*(undefined4 *)(Player_exref + 0xc),
                            *(undefined4 *)(Player_exref + 0x10),
                            *(undefined4 *)(Player_exref + 0x14));
  *(undefined4 *)(unaff_EBP + -4) = 3;
  FightGroup::operator=((FightGroup *)&DAT_1101202c,pFVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(unaff_EBP + -0x20),0x2d,0x15,0x36,0x1c);
  FightGroup::SetRect((FightGroup *)&DAT_1101202c,pMVar3);
  FightGroup::DoAttackEnemy((FightGroup *)&DAT_1101202c);
  ScGroup::SetLights((ScGroup *)&DAT_1101202c,1);
  pFVar2 = (FightGroup *)
           CreateFightGroup(unaff_EBP + -0x10,extraout_EDX_03,*(undefined4 *)(Player_exref + 0xc),
                            *(undefined4 *)(Player_exref + 0x10),
                            *(undefined4 *)(Player_exref + 0x14));
  *(undefined4 *)(unaff_EBP + -4) = 4;
  FightGroup::operator=((FightGroup *)&DAT_11012030,pFVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(unaff_EBP + -0x20),0x88,0x26,0x8e,0x2a);
  FightGroup::SetRect((FightGroup *)&DAT_11012030,pMVar3);
  ScGroup::SetLights((ScGroup *)&DAT_11012030,1);
  pFVar2 = (FightGroup *)
           CreateFightGroup(unaff_EBP + -0x10,extraout_EDX_04,*(undefined4 *)(Player_exref + 0xc),
                            *(undefined4 *)(Player_exref + 0x10),
                            *(undefined4 *)(Player_exref + 0x14));
  *(undefined4 *)(unaff_EBP + -4) = 5;
  FightGroup::operator=((FightGroup *)&DAT_11012034,pFVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(unaff_EBP + -0x20),0x2b,0x2c,0x2d,0x2e);
  FightGroup::SetRect((FightGroup *)&DAT_11012034,pMVar3);
  ScGroup::SetLights((ScGroup *)&DAT_11012034,0);
  pMVar4 = (MiningGroup *)
           CreateMiningGroup(unaff_EBP + -0x10,extraout_EDX_05,*(undefined4 *)(Player_exref + 0xc),
                             *(undefined4 *)(Player_exref + 0x10),
                             *(undefined4 *)(Player_exref + 0x14));
  *(undefined4 *)(unaff_EBP + -4) = 6;
  MiningGroup::operator=((MiningGroup *)&DAT_11012040,pMVar4);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  pFVar2 = (FightGroup *)
           CreateFightGroup(unaff_EBP + -0x10,extraout_EDX_06,*(undefined4 *)(Player_exref + 0xc),
                            *(undefined4 *)(Player_exref + 0x10),
                            *(undefined4 *)(Player_exref + 0x14));
  *(undefined4 *)(unaff_EBP + -4) = 7;
  FightGroup::operator=((FightGroup *)&DAT_11012038,pFVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(unaff_EBP + -0x98),0x9b,0x32,0x9f,0x35);
  FightGroup::SetRect((FightGroup *)&DAT_11012038,pMVar3);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11002d9f InitProc  (called by: -)

undefined4 InitProc(void)

{
  bool bVar1;
  PlayerBuildingEnum *this;
  Trigger *pTVar2;
  ScStub aSStack_cb [3];
  int iVar3;
  int iVar4;
  IUnit *pIVar5;
  IUnit local_40 [2];
  ScStub aSStack_3e [42];
  PlayerBuildingEnum aPStack_14 [16];
  IUnit local_4 [4];
  
                    /* 0x2d9f  7  InitProc */
  bVar1 = FUN_11003f46();
  if (!bVar1) {
    (*DAT_1100f0e4)();
    return 0;
  }
  IUnit::IUnit(local_4);
  IUnit::IUnit(local_40);
  DAT_11012048 = _Player::Difficulty((_Player *)Player_exref);
  DAT_1101204c = DAT_11012048 * 2;
  DAT_11012054 = DAT_11012048 == 0;
  DAT_11012055 = DAT_11012048 == 1;
  DAT_11012056 = DAT_11012048 == 2;
  _Player::GoPlymouth((_Player *)Player_exref);
  _Player::SetColorNumber((_Player *)Player_exref,1);
  _Player::SetScientists((_Player *)Player_exref,5);
  _Player::SetKids((_Player *)Player_exref,0);
  _Player::CenterViewOn((_Player *)Player_exref,DAT_11012000,DAT_11012004);
  _Player::SetTechLevel((_Player *)Player_exref,3);
  _Player::MarkResearchComplete((_Player *)Player_exref,0x842);
  _Player::MarkResearchComplete((_Player *)Player_exref,0xc81);
  _Player::MarkResearchComplete((_Player *)Player_exref,0xd50);
  _Player::GoAI((_Player *)(Player_exref + 0xc));
  _Player::GoEden((_Player *)(Player_exref + 0xc));
  _Player::SetColorNumber((_Player *)(Player_exref + 0xc),0);
  _Player::SetTechLevel((_Player *)(Player_exref + 0xc),0xc);
  FUN_1100137f();
  GameMap::SetCellType(6);
  FUN_110014e4(0,DAT_11012000,DAT_11012004,(int *)&DAT_1100f300);
  FUN_110014e4(1,0x1f,0,(int *)&DAT_1100f320);
  FUN_1100160d(7,0x1100f100);
  TethysGame::FreeMoraleLevel(1);
  TethysGame::SetDaylightMoves(1);
  TethysGame::SetDaylightEverywhere(0);
  TethysGame::SetCheatFastUnits(0);
  TethysGame::SetCheatFastProduction(0);
  TethysGame::SetCheatUnlimitedResources(0);
  TethysGame::SetCheatProduceAll(0);
  pIVar5 = local_40 + -8;
  this = (PlayerBuildingEnum *)PlayerBuildingEnum::PlayerBuildingEnum(aPStack_14,0,0x2f);
  PlayerBuildingEnum::GetNext(this,(Unit *)pIVar5);
  FUN_110029f1();
  Trigger::Trigger((Trigger *)(local_40 + -4));
  pTVar2 = (Trigger *)CreateKitTrigger((int)local_40,1,0,0,0x36,(char *)0x1);
  Trigger::operator=((Trigger *)&DAT_11012160,pTVar2);
  ScStub::~ScStub((ScStub *)(local_40 + -4));
  CreateVictoryCondition((int)(local_40 + -4),1,(Trigger *)0x0,&DAT_11012160);
  ScStub::~ScStub((ScStub *)(local_40 + -8));
  pTVar2 = (Trigger *)CreateKitTrigger((int)(local_40 + -8),1,0,0,0x2f,(char *)0x1);
  Trigger::operator=((Trigger *)&DAT_11012164,pTVar2);
  ScStub::~ScStub((ScStub *)(local_40 + -0xc));
  CreateVictoryCondition((int)(local_40 + -0xc),1,(Trigger *)0x0,&DAT_11012164);
  ScStub::~ScStub((ScStub *)(local_40 + -0x10));
  pTVar2 = (Trigger *)CreateKitTrigger((int)(local_40 + -0x10),1,0,0,0x1c,(char *)0x1);
  Trigger::operator=((Trigger *)&DAT_11012168,pTVar2);
  ScStub::~ScStub((ScStub *)(local_40 + -0x14));
  CreateVictoryCondition((int)(local_40 + -0x14),1,(Trigger *)0x0,&DAT_11012168);
  ScStub::~ScStub((ScStub *)(local_40 + -0x18));
  pTVar2 = (Trigger *)CreateKitTrigger((int)(local_40 + -0x18),1,0,0,0x3a,(char *)0x1);
  Trigger::operator=((Trigger *)&DAT_1101216c,pTVar2);
  ScStub::~ScStub((ScStub *)(local_40 + -0x1c));
  CreateVictoryCondition((int)(local_40 + -0x1c),1,(Trigger *)0x0,&DAT_1101216c);
  ScStub::~ScStub((ScStub *)(local_40 + -0x20));
  if (DAT_11012048 == 0) {
    _Player::SetOre((_Player *)Player_exref,0x708);
    _Player::SetFoodStored((_Player *)Player_exref,0x9c4);
    _Player::SetWorkers((_Player *)Player_exref,0x1c);
    Unit::SetFactoryCargo((Unit *)(local_40 + -0x28),0,0x1e,0);
    Unit::SetFactoryCargo((Unit *)(local_40 + -0x28),1,0x27,0);
    Unit::SetFactoryCargo((Unit *)(local_40 + -0x28),2,0x17,0x3e);
    Unit::SetFactoryCargo((Unit *)(local_40 + -0x28),3,0x17,0x3e);
    Unit::SetFactoryCargo((Unit *)(local_40 + -0x28),4,0x17,0x3e);
    Unit::SetFactoryCargo((Unit *)(local_40 + -0x28),5,0x17,0x3e);
    DAT_11012060 = 2000;
    DAT_11012064 = 4000;
    DAT_11012068 = 0xf;
    DAT_1101206c = 2;
    pTVar2 = (Trigger *)CreateResourceTrigger((int)local_40,1,0,6,0xc,0,(char *)0x3);
    Trigger::operator=((Trigger *)(local_40 + -0x28),pTVar2);
    ScStub::~ScStub((ScStub *)(local_40 + -4));
    CreateFailureCondition((int)local_40,1,(Trigger *)0x0,(char *)(local_40 + -0x28));
    ScStub::~ScStub((ScStub *)(local_40 + -4));
    pTVar2 = (Trigger *)CreateResourceTrigger((int)local_40,1,0,5,2,0,(char *)0x3);
    Trigger::operator=((Trigger *)(local_40 + -0x30),pTVar2);
    ScStub::~ScStub((ScStub *)(local_40 + -4));
    CreateFailureCondition((int)local_40,1,(Trigger *)0x0,(char *)(local_40 + -0x30));
    ScStub::~ScStub((ScStub *)(local_40 + -4));
    FUN_11004120('\x01','\x01',4000,5000,FUN_11001b5c,0);
    FUN_11004190('\x01','\x01',5000,FUN_11001f2a,0);
    FUN_11004190('\x01','\x01',0x1d4c,FUN_1100246e,0);
    FUN_11004120('\x01','\x01',6000,8000,FUN_110026c1,0);
    FUN_11004120('\x01','\x01',10000,13000,FUN_11002768,0);
    FUN_11004190('\x01','\x01',10000,FUN_1100246e,0);
    FUN_11004120('\x01','\x01',4000,8000,FUN_1100298c,0);
    DAT_11012044 = 0;
  }
  else {
    if (DAT_11012048 == 1) {
      _Player::SetOre((_Player *)Player_exref,0x4b0);
      _Player::SetFoodStored((_Player *)Player_exref,2000);
      _Player::SetWorkers((_Player *)Player_exref,0x19);
      Unit::SetFactoryCargo((Unit *)(local_40 + -0x28),2,0x17,0x3e);
      Unit::SetFactoryCargo((Unit *)(local_40 + -0x28),3,0x17,0x3e);
      Unit::SetFactoryCargo((Unit *)(local_40 + -0x28),4,0x17,0x3e);
      Unit::SetFactoryCargo((Unit *)(local_40 + -0x28),5,0x17,0x3e);
      DAT_11012060 = 0x9c4;
      DAT_11012064 = 5000;
      DAT_11012068 = 0x10;
      DAT_1101206c = 2;
      pTVar2 = (Trigger *)CreateResourceTrigger((int)(local_40 + -0x10),1,0,6,0x10,0,(char *)0x3);
      Trigger::operator=((Trigger *)(local_40 + -0x28),pTVar2);
      ScStub::~ScStub((ScStub *)(local_40 + -0x14));
      CreateFailureCondition((int)(local_40 + -0x10),1,(Trigger *)0x0,(char *)(local_40 + -0x28));
      ScStub::~ScStub((ScStub *)(local_40 + -0x14));
      pTVar2 = (Trigger *)CreateResourceTrigger((int)(local_40 + -0x10),1,0,5,2,0,(char *)0x3);
      Trigger::operator=((Trigger *)(local_40 + -0x30),pTVar2);
      ScStub::~ScStub((ScStub *)(local_40 + -0x14));
      CreateFailureCondition((int)(local_40 + -0x10),1,(Trigger *)0x0,(char *)(local_40 + -0x30));
      ScStub::~ScStub((ScStub *)(local_40 + -0x14));
      FUN_11004120('\x01','\x01',3000,4000,FUN_11001b5c,0);
      FUN_11004190('\x01','\x01',5000,FUN_11001f2a,0);
      FUN_11004190('\x01','\x01',0x1d4c,FUN_1100246e,0);
      FUN_11004120('\x01','\x01',5000,7000,FUN_110026c1,0);
      iVar4 = 11000;
      iVar3 = 9000;
    }
    else {
      if (DAT_11012048 != 2) goto LAB_110035d4;
      _Player::SetOre((_Player *)Player_exref,600);
      _Player::SetFoodStored((_Player *)Player_exref,1000);
      _Player::SetWorkers((_Player *)Player_exref,0x14);
      Unit::SetFactoryCargo((Unit *)(local_40 + -0x28),4,0x17,0x3e);
      Unit::SetFactoryCargo((Unit *)(local_40 + -0x28),5,0x17,0x3e);
      DAT_11012060 = 3000;
      DAT_11012064 = 6000;
      DAT_11012068 = 0x12;
      DAT_1101206c = 3;
      pTVar2 = (Trigger *)CreateResourceTrigger((int)(local_40 + -0x20),1,0,6,0x12,0,(char *)0x3);
      Trigger::operator=((Trigger *)(local_40 + -0x28),pTVar2);
      ScStub::~ScStub((ScStub *)(local_40 + -0x24));
      CreateFailureCondition((int)(local_40 + -0x20),1,(Trigger *)0x0,(char *)(local_40 + -0x28));
      ScStub::~ScStub((ScStub *)(local_40 + -0x24));
      pTVar2 = (Trigger *)CreateResourceTrigger((int)(local_40 + -0x20),1,0,5,3,0,(char *)0x3);
      Trigger::operator=((Trigger *)(local_40 + -0x30),pTVar2);
      ScStub::~ScStub((ScStub *)(local_40 + -0x24));
      CreateFailureCondition((int)(local_40 + -0x20),1,(Trigger *)0x0,(char *)(local_40 + -0x30));
      ScStub::~ScStub((ScStub *)(local_40 + -0x24));
      FUN_11004120('\x01','\x01',2000,4000,FUN_11001b5c,0);
      FUN_11004190('\x01','\x01',4000,FUN_11001f2a,0);
      FUN_11004190('\x01','\x01',0x1d4c,FUN_1100246e,0);
      FUN_11004120('\x01','\x01',5000,7000,FUN_110026c1,0);
      iVar4 = 10000;
      iVar3 = 8000;
    }
    FUN_11004120('\x01','\x01',iVar3,iVar4,FUN_11002768,0);
    FUN_11004190('\x01','\x01',10000,FUN_1100246e,0);
    FUN_11004120('\x01','\0',4000,8000,FUN_1100298c,0);
    FUN_11004120('\x01','\0',0x9c4,0x157c,FUN_1100293c,0);
    DAT_11012044 = 1;
  }
  DAT_11012050 = 2;
LAB_110035d4:
  pTVar2 = (Trigger *)CreateResourceTrigger((int)(local_40 + -4),1,0,0,DAT_11012060,0,(char *)0x2);
  Trigger::operator=((Trigger *)&DAT_11012178,pTVar2);
  ScStub::~ScStub((ScStub *)(local_40 + -8));
  scr_snprintf(&DAT_11012070,0x3c,s_Store__d_units_of_food_1100f464);
  CreateVictoryCondition((int)(local_40 + -8),1,(Trigger *)0x0,&DAT_11012178);
  ScStub::~ScStub((ScStub *)(local_40 + -0xc));
  pTVar2 = (Trigger *)CreateResourceTrigger((int)(local_40 + -0xc),1,0,1,DAT_11012064,0,(char *)0x2)
  ;
  Trigger::operator=((Trigger *)&DAT_1101217c,pTVar2);
  ScStub::~ScStub((ScStub *)(local_40 + -0x10));
  scr_snprintf(&DAT_110120ac,0x3c,s_Collect__d_units_of_Commom_Metal_1100f440);
  CreateVictoryCondition((int)(local_40 + -0x10),1,(Trigger *)0x0,&DAT_1101217c);
  ScStub::~ScStub((ScStub *)(local_40 + -0x14));
  pTVar2 = (Trigger *)
           CreateResourceTrigger((int)(local_40 + -0x14),1,0,6,DAT_11012068,0,(char *)0x2);
  Trigger::operator=((Trigger *)&DAT_11012170,pTVar2);
  ScStub::~ScStub((ScStub *)(local_40 + -0x18));
  scr_snprintf(&DAT_110120e8,0x3c,s_Have_at_least__d_total_colonists_1100f414);
  CreateVictoryCondition((int)(local_40 + -0x18),1,(Trigger *)0x0,&DAT_11012170);
  ScStub::~ScStub((ScStub *)(local_40 + -0x1c));
  pTVar2 = (Trigger *)
           CreateResourceTrigger((int)(local_40 + -0x1c),1,0,5,DAT_1101206c,0,(char *)0x2);
  Trigger::operator=((Trigger *)&DAT_11012174,pTVar2);
  ScStub::~ScStub((ScStub *)(local_40 + -0x20));
  scr_snprintf(&DAT_11012124,0x3c,s_Have_at_least__d_scientists_surv_1100f3ec);
  CreateVictoryCondition((int)(local_40 + -0x20),1,(Trigger *)0x0,&DAT_11012174);
  ScStub::~ScStub((ScStub *)(local_40 + -0x24));
  FUN_110045c0('\x01','\x01',0,0x87,1,0x18,0x20);
  FUN_110045c0('\x01','\x01',0,0x8a,1,0x18,10);
  FUN_11001461();
  TethysGame::CreateUnit(local_40 + -0x1c,0x15,0x91,0x1d,1,0,0);
  FUN_11004270('\x01','\x01',1,0x15,0xffffffff,0,0,FUN_11001f2a,0);
  FUN_11004270('\x01','\x01',0,0x15,0xffffffff,1,0,FUN_11001d9d,0);
  FUN_11004270('\x01','\x01',0,1,0xffffffff,0,0,FUN_11001dc2,0);
  FUN_110022e9();
  FUN_11004120('\x01','\0',3000,7000,FUN_11002965,0);
  FUN_11004190('\x01','\0',0xc80,FUN_1100257a,0);
  ScStub::~ScStub(aSStack_cb + 0x23);
  return 1;
}


// ---- 11003830 FUN_11003830  (called by: FUN_11003862@11003862)

void FUN_11003830(void)

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


// ---- 11003862 FUN_11003862  (called by: entry@11006064)

undefined4 FUN_11003862(HMODULE param_1,int param_2)

{
  bool bVar1;
  undefined *puVar2;
  ushort uVar3;
  
  if (param_2 == 0) {
    bVar1 = FUN_11003f53();
    if (bVar1) {
      FUN_11003fc8((uint *)&DAT_1100f560);
    }
    FUN_110010ef();
    FUN_11003830();
  }
  else if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    FUN_110046d0(param_1);
    uVar3 = 0xf;
    puVar2 = FUN_11003f60((uint *)s_q01_mo3_1100f564,PTR_DAT_1100f56c);
    FUN_11004def(puVar2,uVar3);
    FUN_11004bc6(0x11004e15);
    FUN_1100107a();
  }
  return 1;
}


// ---- 110038da FUN_110038da  (called by: FUN_110039a6@110039a6)

undefined1 FUN_110038da(void)

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
    if (local_10 != *(int *)(&DAT_11010468 + local_c * 4)) {
      local_5 = 1;
    }
    while (iVar3 = PlayerVehicleEnum::GetNext(local_18,(Unit *)local_14), iVar3 != 0) {
      local_10 = local_10 + 1;
    }
    if (local_10 != *(int *)(&DAT_11010488 + local_c * 4)) {
      local_5 = 1;
    }
  }
  return local_5;
}


// ---- 110039a6 FUN_110039a6  (called by: FUN_11003fc8@11003fc8)

uint __cdecl FUN_110039a6(LPCSTR param_1,char param_2)

{
  char cVar1;
  uint uVar2;
  
  if (param_2 == '\0') {
    param_2 = FUN_110038da();
  }
  uVar2 = FUN_11003d1c(param_1,param_2);
  cVar1 = (char)uVar2;
  if (cVar1 != '\0') {
    FUN_11003e90(param_1);
    uVar2 = FUN_110039e5(param_1,'\x01');
  }
  return CONCAT31((int3)(uVar2 >> 8),cVar1);
}


// ---- 110039e5 FUN_110039e5  (called by: FUN_110039a6@110039a6)

uint __cdecl FUN_110039e5(LPCSTR param_1,char param_2)

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
    if (local_c != *(int *)(&DAT_11010468 + iVar1 * 4)) {
      param_2 = '\x01';
    }
    while (iVar4 = PlayerVehicleEnum::GetNext(local_14,(Unit *)local_8), iVar4 != 0) {
      local_10 = local_10 + 1;
    }
    if (local_10 != *(map_id *)(&DAT_11010488 + iVar1 * 4)) {
      param_2 = '\x01';
    }
    local_18 = local_18 + local_10 + local_c;
  }
  local_c = TethysGame::NoPlayers();
  if (param_2 == '\0') {
    local_c = local_c & 0xffffff00;
  }
  else {
    pFVar5 = (FILE *)FUN_110055f9(param_1,&DAT_1100f570);
    FUN_1100548f((char *)&local_18,4,1,(int *)pFVar5);
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
            FUN_1100548f((char *)&local_68,0x18,1,(int *)pFVar5);
            param_1 = (LPCSTR)0x0;
            do {
              IUnit::GetFactoryCargo(local_8,(int)param_1,&local_50,&local_44);
              FUN_1100548f((char *)&local_50,4,1,(int *)pFVar5);
              FUN_1100548f((char *)&local_44,4,1,(int *)pFVar5);
              param_1 = param_1 + 1;
            } while ((int)param_1 < 6);
          }
          else {
            FUN_1100548f((char *)&local_68,0x18,1,(int *)pFVar5);
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
          FUN_1100548f((char *)&local_3c,0x18,1,(int *)pFVar5);
        }
      }
    }
    FUN_11005070(pFVar5);
    *(int *)(&DAT_11010468 + local_c * 4) = local_18;
    local_c = (uint)(pFVar5 != (FILE *)0x0);
  }
  return local_c;
}


// ---- 11003d1c FUN_11003d1c  (called by: FUN_110039a6@110039a6)

uint __cdecl FUN_11003d1c(LPCSTR param_1,char param_2)

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
  if ((param_2 != '\0') || (uVar5 = local_14, local_14 != DAT_110104a8)) {
    pFVar4 = (FILE *)FUN_110055f9(param_1,&DAT_1100f0e0);
    uVar5 = 0;
    if (pFVar4 != (FILE *)0x0) {
      FUN_1100548f((char *)&local_14,4,1,(int *)pFVar4);
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
            FUN_1100548f((char *)&local_10,2,1,(int *)pFVar4);
            FUN_1100548f((char *)&local_c,2,1,(int *)pFVar4);
            FUN_1100548f((char *)&local_5,1,1,(int *)pFVar4);
            if ((local_5 == 0x15) || (uVar6 = extraout_EDX_03, local_5 == 0x16)) {
              local_18 = GameMap::GetTile((int)(short)local_c,extraout_EDX_03,(int)(short)local_10,
                                          (int)(short)local_c);
              FUN_1100548f((char *)&local_18,2,1,(int *)pFVar4);
              uVar6 = extraout_EDX_04;
            }
          }
          local_10 = local_10 + 1;
          sVar1 = (short)local_10;
        }
        local_c = local_c + 1;
        sVar1 = (short)local_c;
      }
      FUN_11005070(pFVar4);
      DAT_110104a8 = local_14;
      return CONCAT31((int3)(local_14 >> 8),1);
    }
  }
  return uVar5 & 0xffffff00;
}


// ---- 11003e90 FUN_11003e90  (called by: FUN_110039a6@110039a6)

undefined4 __cdecl FUN_11003e90(LPCSTR param_1)

{
  FILE *pFVar1;
  undefined4 uVar2;
  int local_24 [8];
  
  FUN_11003eda(local_24,SUB41(*(undefined4 *)Player_exref,0));
  pFVar1 = (FILE *)FUN_110055f9(param_1,&DAT_1100f570);
  FUN_1100548f((char *)local_24,0x20,1,(int *)pFVar1);
  uVar2 = FUN_11005070(pFVar1);
  return CONCAT31((int3)((uint)uVar2 >> 8),1);
}


// ---- 11003eda FUN_11003eda  (called by: FUN_11003e90@11003e90)

int * __thiscall FUN_11003eda(int *param_1,_Player param_2)

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


// ---- 11003f46 FUN_11003f46  (called by: InitProc@11002d9f)

bool FUN_11003f46(void)

{
  return DAT_004e971c == 'Q';
}


// ---- 11003f53 FUN_11003f53  (called by: FUN_11003862@11003862)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_11003f53(void)

{
  return _DAT_0056eb34 == 3;
}


// ---- 11003f60 FUN_11003f60  (called by: FUN_11003862@11003862, FUN_11003fc8@11003fc8)

undefined * __cdecl FUN_11003f60(uint *param_1,byte *param_2)

{
  byte *pbVar1;
  byte local_208 [256];
  byte local_108 [256];
  byte local_8 [4];
  
  pbVar1 = (byte *)GetCurrentModDir();
  if (pbVar1 == (byte *)0x0) {
    FUN_11005c40((uint *)&DAT_11010358,param_1);
  }
  else {
    FUN_11005dc1(pbVar1,local_8,local_208,local_108,local_108);
    FUN_11005d30(&DAT_11010358,local_8,local_208,(byte *)param_1,param_2);
  }
  return &DAT_11010358;
}


// ---- 11003fc8 FUN_11003fc8  (called by: FUN_11003862@11003862)

void __cdecl FUN_11003fc8(uint *param_1)

{
  size_t sVar1;
  undefined *puVar2;
  uint *puVar3;
  uint local_54 [20];
  
  GetGameDir(local_54);
  sVar1 = _strlen((char *)local_54);
  FUN_11005c50(local_54,param_1);
  FUN_11005c50(local_54,(uint *)&DAT_1100f588);
  FUN_110039a6((LPCSTR)local_54,'\0');
  FUN_11005c40((uint *)((int)local_54 + sVar1),(uint *)s_music2_wav_1100f57c);
  puVar3 = local_54;
  puVar2 = FUN_11003f60(param_1,&DAT_1100f574);
  FUN_11001106(puVar2,(LPCSTR)puVar3);
  return;
}


// ---- 11004040 FUN_11004040  (called by: FUN_11004120@11004120)

undefined4 * __thiscall
FUN_11004040(void *this,char param_1,char param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  
  FUN_11004740(this,param_1,param_2,param_5);
  *(undefined ***)this = &PTR_FUN_1100c328;
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
  FUN_110040a0((int)this);
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 8) = param_6;
  return this;
}


// ---- 110040a0 FUN_110040a0  (called by: FUN_11004040@11004040, FUN_110040e0@110040e0)

void __fastcall FUN_110040a0(int param_1)

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


// ---- 110040e0 FUN_110040e0  (called by: -)

void __fastcall FUN_110040e0(int param_1)

{
  int iVar1;
  
  iVar1 = TethysGame::Tick();
  if ((*(int *)(param_1 + 0x18) <= iVar1) && (*(int *)(param_1 + 0x1c) < *(int *)(param_1 + 0x18)))
  {
    FUN_110047c0(param_1);
    if ((*(byte *)(param_1 + 6) & 0x20) != 0) {
      return;
    }
    if ((*(byte *)(param_1 + 6) & 2) != 0) {
      FUN_110040a0(param_1);
    }
  }
  *(int *)(param_1 + 0x1c) = iVar1;
  return;
}


// ---- 11004120 FUN_11004120  (called by: FUN_1100255c@1100255c, FUN_110028d5@110028d5, FUN_11004190@11004190, InitProc@11002d9f)

undefined4 * __cdecl
FUN_11004120(char param_1,char param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6
            )

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_20 [8];
  
  puVar1 = (undefined4 *)FUN_11004a40(0x20);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_11004040(local_20,param_1,param_2,param_3,param_4,param_5,param_6);
  puVar3 = local_20;
  puVar4 = puVar1;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_11004810(&DAT_110121e0,(int)puVar1);
  return puVar1;
}


// ---- 11004190 FUN_11004190  (called by: FUN_11001d9d@11001d9d, FUN_11001dc2@11001dc2, FUN_11001f2a@11001f2a, FUN_110022e9@110022e9, FUN_11002841@11002841, InitProc@11002d9f)

void __cdecl
FUN_11004190(char param_1,char param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  FUN_11004120(param_1,param_2,param_3,param_3,param_4,param_5);
  return;
}


// ---- 110041d0 FUN_110041d0  (called by: FUN_11004270@11004270)

undefined4 * __thiscall
FUN_110041d0(void *this,char param_1,char param_2,undefined1 param_3,undefined4 param_4,
            undefined4 param_5,undefined1 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  FUN_11004740(this,param_1,param_2,param_8);
  *(undefined1 *)((int)this + 0x10) = param_3;
  *(undefined1 *)((int)this + 0x11) = param_6;
  *(undefined4 *)((int)this + 0x14) = param_4;
  *(undefined4 *)((int)this + 0x18) = param_5;
  *(undefined ***)this = &PTR_FUN_1100c32c;
  *(undefined4 *)((int)this + 0x1c) = param_7;
  *(undefined4 *)((int)this + 8) = param_9;
  return this;
}


// ---- 11004220 FUN_11004220  (called by: -)

void __fastcall FUN_11004220(int param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  
  cVar1 = *(char *)(param_1 + 0x10);
  iVar3 = TethysGame::NoPlayers();
  if (cVar1 < iVar3) {
    cVar1 = FUN_1100135c((int)cVar1,*(map_id *)(param_1 + 0x14),*(map_id *)(param_1 + 0x18));
    *(char *)(param_1 + 0x12) = cVar1;
    bVar2 = FUN_11004b20((int)cVar1,(int)*(char *)(param_1 + 0x11),*(undefined4 *)(param_1 + 0x1c));
    if (bVar2) {
      FUN_110047c0(param_1);
    }
  }
  return;
}


// ---- 11004270 FUN_11004270  (called by: FUN_110022e9@110022e9, FUN_11002412@11002412, InitProc@11002d9f)

undefined4 * __cdecl
FUN_11004270(char param_1,char param_2,undefined1 param_3,undefined4 param_4,undefined4 param_5,
            undefined1 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_20 [8];
  
  puVar1 = (undefined4 *)FUN_11004a40(0x20);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_110041d0(local_20,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  puVar3 = local_20;
  puVar4 = puVar1;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_11004810(&DAT_110121e0,(int)puVar1);
  return puVar1;
}


// ---- 110042f0 FUN_110042f0  (called by: FUN_11004410@11004410)

undefined4 * __thiscall
FUN_110042f0(void *this,char param_1,char param_2,ScStub *param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  char cVar1;
  int iVar2;
  
  FUN_11004740(this,param_1,param_2,param_5);
  *(undefined ***)this = &PTR_FUN_1100c330;
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


// ---- 11004390 FUN_11004390  (called by: -)

void __fastcall FUN_11004390(int param_1)

{
  int iVar1;
  int local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_1100b4e9;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_10 = param_1;
  ScGroup::ScGroup((ScGroup *)&local_10);
  local_4 = 0;
  ScStub::SetId((ScStub *)&local_10,(int)*(char *)(param_1 + 0x10));
  iVar1 = ScGroup::TotalUnitCount((ScGroup *)&local_10);
  if (iVar1 <= *(char *)(param_1 + 0x12)) {
    FUN_110047c0(param_1);
  }
  local_4 = 0xffffffff;
  ScStub::~ScStub((ScStub *)&local_10);
  ExceptionList = local_c;
  return;
}


// ---- 11004410 FUN_11004410  (called by: FUN_1100257a@1100257a, FUN_11002768@11002768, FUN_11002841@11002841)

undefined4 * __cdecl
FUN_11004410(char param_1,char param_2,ScStub *param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_14 [5];
  
  puVar1 = (undefined4 *)FUN_11004a40(0x14);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_110042f0(local_14,param_1,param_2,param_3,param_4,param_5,param_6);
  puVar3 = local_14;
  puVar4 = puVar1;
  for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_11004810(&DAT_110121e0,(int)puVar1);
  return puVar1;
}


// ---- 11004480 FUN_11004480  (called by: FUN_11004540@11004540)

undefined4 * __thiscall
FUN_11004480(undefined4 *param_1,char param_2,char param_3,undefined1 param_4,MAP_RECT param_5)

{
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  
  FUN_11004740(param_1,param_2,param_3,in_stack_00000020);
  MAP_RECT::MAP_RECT((MAP_RECT *)(param_1 + 5));
  *param_1 = &PTR_LAB_1100c334;
  *(undefined1 *)(param_1 + 4) = param_4;
  MAP_RECT::operator=((MAP_RECT *)(param_1 + 5),&param_5);
  param_1[2] = in_stack_00000024;
  return param_1;
}


// ---- 11004540 FUN_11004540  (called by: FUN_110045c0@110045c0)

undefined4 * __cdecl FUN_11004540(char param_1,char param_2,undefined1 param_3,MAP_RECT param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_24 [9];
  
  puVar1 = (undefined4 *)FUN_11004a40(0x24);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_11004480(local_24,param_1,param_2,param_3,param_4);
    puVar3 = local_24;
    puVar4 = puVar1;
    for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_11004810(&DAT_110121e0,(int)puVar1);
  }
  return puVar1;
}


// ---- 110045c0 FUN_110045c0  (called by: InitProc@11002d9f)

void __cdecl
FUN_110045c0(char param_1,char param_2,undefined1 param_3,int param_4,int param_5,int param_6,
            int param_7)

{
  undefined4 *puVar1;
  MAP_RECT local_10 [16];
  
  puVar1 = (undefined4 *)
           MAP_RECT::MAP_RECT(local_10,param_4,param_5,param_6 + param_4,param_5 + param_7);
  FUN_11004540(param_1,param_2,param_3,SUB41(*puVar1,0));
  return;
}


// ---- 11004630 GetSaveRegions  (called by: -)

void __cdecl GetSaveRegions(int *param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *_Str1;
  int iVar6;
  
                    /* 0x4630  6  GetSaveRegions */
  iVar4 = ImageLoad(&DAT_1101218c,0);
  iVar6 = 0;
  iVar1 = *(int *)(iVar4 + 0x14);
  pcVar2 = *(char **)(iVar4 + 0x18);
  iVar3 = *(int *)(*(int *)(iVar4 + 0xc) + 0x34);
  DAT_110104ac = *(undefined4 *)(*(int *)(iVar4 + 0xc) + 8);
  _Str1 = pcVar2;
  if (0 < iVar1) {
    while( true ) {
      iVar5 = _strncmp(_Str1,s__save_1100f590,5);
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


// ---- 110046d0 FUN_110046d0  (called by: FUN_11003862@11003862)

void __cdecl FUN_110046d0(HMODULE param_1)

{
  GetModuleFileNameA(param_1,&DAT_1101218c,0x50);
  return;
}


// ---- 11004730 AIProc  (called by: -)

void AIProc(void)

{
                    /* 0x4730  4  AIProc */
  FUN_11004900(&DAT_110121e0);
  return;
}


// ---- 11004740 FUN_11004740  (called by: FUN_11004040@11004040, FUN_110041d0@110041d0, FUN_110042f0@110042f0, FUN_11004480@11004480)

undefined4 * __thiscall FUN_11004740(void *this,char param_1,char param_2,undefined4 param_3)

{
  *(undefined ***)this = &PTR_LAB_1100c340;
  FUN_11004780(this,param_1,param_2,param_3);
  return this;
}


// ---- 11004770 FUN_11004770  (called by: FUN_110047c0@110047c0)

void __fastcall FUN_11004770(int param_1)

{
  *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) | 0x20;
  return;
}


// ---- 11004780 FUN_11004780  (called by: FUN_11004740@11004740)

void __thiscall FUN_11004780(void *this,char param_1,char param_2,undefined4 param_3)

{
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined2 *)((int)this + 4) = 0;
  *(byte *)((int)this + 6) = param_1 != '\0' | (-(param_2 != '\0') & 2U) + 2 | 8;
  *(undefined4 *)((int)this + 0xc) = param_3;
  return;
}


// ---- 110047c0 FUN_110047c0  (called by: FUN_110040e0@110040e0, FUN_11004220@11004220, FUN_11004390@11004390)

void __fastcall FUN_110047c0(int param_1)

{
  byte bVar1;
  
  if (*(code **)(param_1 + 0xc) != (code *)0x0) {
    *(short *)(param_1 + 4) = *(short *)(param_1 + 4) + 1;
    (**(code **)(param_1 + 0xc))(param_1);
    bVar1 = *(byte *)(param_1 + 6);
    if (((bVar1 & 2) == 0) && (*(byte *)(param_1 + 6) = bVar1 & 0xfe, (bVar1 & 4) != 0)) {
      FUN_11004770(param_1);
    }
  }
  return;
}


// ---- 11004810 FUN_11004810  (called by: FUN_11004120@11004120, FUN_11004270@11004270, FUN_11004410@11004410, FUN_11004540@11004540)

void __thiscall FUN_11004810(void *this,int param_1)

{
  int iVar1;
  
  iVar1 = FUN_110048a0(this,param_1);
  if (iVar1 < 0) {
    if (*(int *)((int)this + 4) == 0x200) {
      (*DAT_1100c33c)(s_ERROR_1100f5bc,0x10);
      return;
    }
    *(int *)(*(int *)this + *(int *)((int)this + 4) * 4) = param_1;
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  }
  return;
}


// ---- 11004860 FUN_11004860  (called by: FUN_110049e0@110049e0)

void __thiscall FUN_11004860(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = FUN_110048a0(this,param_1);
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


// ---- 110048a0 FUN_110048a0  (called by: FUN_11004810@11004810, FUN_11004860@11004860)

void __thiscall FUN_110048a0(void *this,int param_1)

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


// ---- 110048c0 FUN_110048c0  (called by: FUN_11004900@11004900)

void FUN_110048c0(void)

{
  if (DAT_110104b0 == '\0') {
    if (DAT_110121dc != DAT_110104ac) {
      DAT_110104b0 = '\x01';
      if (DAT_110121dc == 0) {
        DAT_110121dc = DAT_110104ac;
        return;
      }
      (*DAT_1100c33c)(s_WARNING_1100f60c,0x30);
    }
  }
  return;
}


// ---- 11004900 FUN_11004900  (called by: AIProc@11004730)

void __fastcall FUN_11004900(int *param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_1100b500;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_110048c0();
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
  FUN_110049e0(param_1);
  ExceptionList = local_10;
  return;
}


// ---- 11004971 Catch@11004971  (called by: -)

undefined * Catch_11004971(void)

{
  int unaff_EBP;
  
  scr_snprintf((char *)(unaff_EBP + -0x6c),0x50,s_Error_executing_event__02X_ID__0_1100f620,
               *(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 8),
               *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0xc));
  (*DAT_1100c33c)(s_EventError_1100f614,0x30);
  return FUN_110049ac;
}


// ---- 110049ac FUN_110049ac  (called by: -)

void FUN_110049ac(void)

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
        FUN_110049e0(piVar4);
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


// ---- 110049e0 FUN_110049e0  (called by: FUN_110049ac@110049ac)

void __fastcall FUN_110049e0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[1];
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    iVar2 = *(int *)(*param_1 + iVar1 * 4);
    if ((iVar2 != 0) && ((*(byte *)(iVar2 + 6) & 0x20) != 0)) {
      FUN_11004860(param_1,iVar2);
      FUN_11004ad0(iVar2);
    }
  }
  return;
}


// ---- 11004a20 FUN_11004a20  (called by: FUN_11004a40@11004a40, FUN_11004ad0@11004ad0)

undefined * FUN_11004a20(LPCSTR param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_retaddr;
  
  MessageBoxA((HWND)0x0,param_1,s_ERROR_1100f5bc,0x10);
  FUN_110061a5(0xffffffff);
  iVar2 = (unaff_retaddr - 1U >> 4) + 1;
  iVar5 = 0;
  do {
    cVar1 = (&DAT_1101a9e8)[iVar5];
    iVar4 = 0;
    while (cVar1 == '\0') {
      iVar3 = iVar4 + 1;
      if (iVar3 == iVar2) {
        for (; 0 < iVar4; iVar4 = iVar4 + -1) {
          (&DAT_1101a9e8)[iVar4 + iVar5] = 0xff;
        }
        (&DAT_1101a9e8)[iVar5] = (char)iVar2;
        return &DAT_110129e8 + iVar5 * 0x10;
      }
      if (0x7ff < iVar3 + iVar5) {
        FUN_11004a20(s__new__Out_of_memory_1100f654);
      }
      iVar4 = iVar3;
      cVar1 = (&DAT_1101a9e8)[iVar3 + iVar5];
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x800);
  FUN_11004a20(s__new__Out_of_memory_1100f654);
  return (undefined *)0x0;
}


// ---- 11004a40 FUN_11004a40  (called by: FUN_11004120@11004120, FUN_11004270@11004270, FUN_11004410@11004410, FUN_11004540@11004540)

undefined * __cdecl FUN_11004a40(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = (param_1 - 1U >> 4) + 1;
  iVar5 = 0;
  do {
    cVar1 = (&DAT_1101a9e8)[iVar5];
    iVar4 = 0;
    while (cVar1 == '\0') {
      iVar3 = iVar4 + 1;
      if (iVar3 == iVar2) {
        for (; 0 < iVar4; iVar4 = iVar4 + -1) {
          (&DAT_1101a9e8)[iVar4 + iVar5] = 0xff;
        }
        (&DAT_1101a9e8)[iVar5] = (char)iVar2;
        return &DAT_110129e8 + iVar5 * 0x10;
      }
      if (0x7ff < iVar3 + iVar5) {
        FUN_11004a20(s__new__Out_of_memory_1100f654);
      }
      iVar4 = iVar3;
      cVar1 = (&DAT_1101a9e8)[iVar3 + iVar5];
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x800);
  FUN_11004a20(s__new__Out_of_memory_1100f654);
  return (undefined *)0x0;
}


// ---- 11004ad0 FUN_11004ad0  (called by: FUN_110049e0@110049e0)

void __cdecl FUN_11004ad0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (int)(param_1 + -0x110129e8 + (param_1 + -0x110129e8 >> 0x1f & 0xfU)) >> 4;
  iVar2 = (int)(char)(&DAT_1101a9e8)[iVar1];
  if ((iVar2 < 1) || (0xfe < iVar2)) {
    FUN_11004a20(s__delete__Invalid_pointer_supplie_1100f668);
  }
  else {
    iVar2 = iVar2 + -1;
    if (-1 < iVar2) {
      do {
        (&DAT_1101a9e8)[iVar2 + iVar1] = 0;
        iVar2 = iVar2 + -1;
      } while (-1 < iVar2);
      return;
    }
  }
  return;
}


// ---- 11004b20 FUN_11004b20  (called by: FUN_11004220@11004220)

bool __cdecl FUN_11004b20(int param_1,int param_2,undefined4 param_3)

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


// ---- 11004bc6 FUN_11004bc6  (called by: FUN_11003862@11003862)

undefined4 __cdecl FUN_11004bc6(int param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 uVar3;
  DWORD local_8;
  
  iVar1 = _memcmp(DAT_1100f694,&DAT_1100c344,0x14);
  if (iVar1 == 0) {
    iVar1 = _memcmp(DAT_1100f69c,&DAT_1100c384,6);
    if (iVar1 == 0) {
      iVar1 = _memcmp(DAT_1100f6a0,&DAT_1100c36c,5);
      uVar3 = 3;
      if (iVar1 == 0) {
        iVar1 = _memcmp(DAT_1100f6a4,&DAT_1100c37c,3);
        if (iVar1 == 0) {
          BVar2 = VirtualProtect(DAT_1100f694,0x14,0x40,&local_8);
          if (BVar2 == 0) {
            uVar3 = 5;
          }
          else {
            BVar2 = VirtualProtect(DAT_1100f69c,6,0x40,&local_8);
            if (BVar2 == 0) {
              uVar3 = 6;
            }
            else {
              BVar2 = VirtualProtect(DAT_1100f6a0,5,0x40,&local_8);
              if (BVar2 == 0) {
                uVar3 = 7;
              }
              else {
                BVar2 = VirtualProtect(DAT_1100f6a4,3,0x40,&local_8);
                if (BVar2 != 0) {
                  EnterCriticalSection(DAT_1100f690);
                  FUN_110062b0(DAT_1100f694,(undefined4 *)&DAT_1100c358,0x14);
                  *(undefined4 *)((int)DAT_1100f694 + 0xb) = DAT_1100f698;
                  DAT_1100f694[4] = (param_1 - (int)DAT_1100f694) + -0x14;
                  FUN_110062b0(DAT_1100f69c,(undefined4 *)&DAT_1100c38c,6);
                  FUN_110062b0(DAT_1100f6a0,(undefined4 *)&DAT_1100c374,5);
                  FUN_110062b0(DAT_1100f6a4,(undefined4 *)&DAT_1100c380,3);
                  LeaveCriticalSection(DAT_1100f690);
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


// ---- 11004d31 UninstallMusicHook  (called by: FUN_11003830@11003830)

/* int __cdecl UninstallMusicHook(void) */

int __cdecl UninstallMusicHook(void)

{
                    /* 0x4d31  3  ?UninstallMusicHook@@YAHXZ */
  EnterCriticalSection(DAT_1100f690);
  FUN_110062b0(DAT_1100f694,(undefined4 *)&DAT_1100c344,0x14);
  FUN_110062b0(DAT_1100f69c,(undefined4 *)&DAT_1100c384,6);
  FUN_110062b0(DAT_1100f6a0,(undefined4 *)&DAT_1100c36c,5);
  FUN_110062b0(DAT_1100f6a4,(undefined4 *)&DAT_1100c37c,3);
  LeaveCriticalSection(DAT_1100f690);
  return 0;
}


// ---- 11004da1 FUN_11004da1  (called by: -)

void FUN_11004da1(void)

{
  FUN_11004e95((undefined4 *)&DAT_110104b8);
  return;
}


// ---- 11004dab FUN_11004dab  (called by: -)

void FUN_11004dab(void)

{
  FUN_11005ab5(0x11004db7);
  return;
}


// ---- 11004db7 FUN_11004db7  (called by: -)

void FUN_11004db7(void)

{
  FUN_11004ee2((undefined4 *)&DAT_110104b8);
  return;
}


// ---- 11004dc1 FUN_11004dc1  (called by: FUN_11004def@11004def)

void __cdecl FUN_11004dc1(undefined4 param_1)

{
  FUN_11004f40(0x110104b8);
  DAT_110104c4 = param_1;
  FUN_11004eed(&DAT_110104b8,param_1);
  FUN_11004f35(0x110104b8);
  DAT_1100f6a8 = 0;
  return;
}


// ---- 11004def FUN_11004def  (called by: FUN_11003862@11003862)

void __cdecl FUN_11004def(undefined4 param_1,ushort param_2)

{
  FUN_11004dc1(param_1);
  FUN_11004e04(param_2);
  return;
}


// ---- 11004e04 FUN_11004e04  (called by: FUN_11004def@11004def)

void __cdecl FUN_11004e04(ushort param_1)

{
  FUN_11004f55(&DAT_110104b8,param_1,0);
  return;
}


// ---- 11004e15 FUN_11004e15  (called by: -)

undefined4 FUN_11004e15(undefined4 *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 unaff_BP;
  undefined4 local_8004 [8182];
  undefined4 uStackY_2c;
  
  FUN_11005610(unaff_BP);
  uVar2 = 0;
  if (DAT_110104c4 != 0) {
    if (DAT_1100f6a8 == '\x01') {
      FUN_11004eed(&DAT_110104b8,DAT_110104c4);
      FUN_11004f35(0x110104b8);
      DAT_1100f6a8 = '\0';
    }
    iVar1 = FUN_11004f1b(&DAT_110104b8,local_8004,0x8000);
    FUN_110062b0(param_1,local_8004,param_2);
    uStackY_2c = 0x11004e88;
    _memset((void *)(iVar1 + (int)param_1),0,param_2 - iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


// ---- 11004e95 FUN_11004e95  (called by: FUN_11004da1@11004da1)

undefined4 * __fastcall FUN_11004e95(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  *param_1 = &PTR_FUN_1100c394;
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


// ---- 11004ec6 FUN_11004ec6  (called by: -)

undefined4 * __thiscall FUN_11004ec6(void *this,byte param_1)

{
  FUN_11004ee2(this);
  if ((param_1 & 1) != 0) {
    FUN_11005af6(this);
  }
  return this;
}


// ---- 11004ee2 FUN_11004ee2  (called by: FUN_11004db7@11004db7, FUN_11004ec6@11004ec6)

void __fastcall FUN_11004ee2(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_1100c394;
  BASS_Free();
  return;
}


// ---- 11004eed FUN_11004eed  (called by: FUN_11004dc1@11004dc1, FUN_11004e15@11004e15)

bool __thiscall FUN_11004eed(void *this,undefined4 param_1)

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


// ---- 11004f1b FUN_11004f1b  (called by: FUN_11004e15@11004e15)

undefined4 __thiscall FUN_11004f1b(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = BASS_ChannelGetData(*(undefined4 *)((int)this + 8),param_1,param_2);
  return uVar1;
}


// ---- 11004f35 FUN_11004f35  (called by: FUN_11004dc1@11004dc1, FUN_11004e15@11004e15)

void __fastcall FUN_11004f35(int param_1)

{
  BASS_ChannelPlay(*(undefined4 *)(param_1 + 8),0);
  return;
}


// ---- 11004f40 FUN_11004f40  (called by: FUN_11004dc1@11004dc1)

void __fastcall FUN_11004f40(int param_1)

{
  BASS_ChannelStop(*(undefined4 *)(param_1 + 8));
  BASS_MusicFree(*(undefined4 *)(param_1 + 8));
  return;
}


// ---- 11004f55 FUN_11004f55  (called by: FUN_11004e04@11004e04)

void __thiscall FUN_11004f55(void *this,ushort param_1,ushort param_2)

{
  BASS_ChannelSetPosition
            (*(undefined4 *)((int)this + 8),(param_2 | 0xffff8000) << 0x10 | (uint)param_1,0);
  return;
}


// ---- 11004f9c _malloc  (called by: FUN_1100107a@1100107a, FUN_11005b01@11005b01, FUN_11006859@11006859, FUN_110077d6@110077d6, FUN_11007ef1@11007ef1, FUN_11009178@11009178, FUN_11009231@11009231, FUN_1100947e@1100947e, FUN_11009b83@11009b83, FUN_11009e64@11009e64)

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_11010520);
  return pvVar1;
}


// ---- 11004fae __nh_malloc  (called by: _malloc@11004f9c)

/* Library Function - Single Match
    __nh_malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl __nh_malloc(size_t _Size,int _NhFlag)

{
  int *piVar1;
  int iVar2;
  
  if (_Size < 0xffffffe1) {
    do {
      piVar1 = FUN_11004fda((uint *)_Size);
      if (piVar1 != (int *)0x0) {
        return piVar1;
      }
      if (_NhFlag == 0) {
        return (void *)0x0;
      }
      iVar2 = FUN_110066f8(_Size);
    } while (iVar2 != 0);
  }
  return (void *)0x0;
}


// ---- 11004fda FUN_11004fda  (called by: __nh_malloc@11004fae)

int * __cdecl FUN_11004fda(uint *param_1)

{
  int *piVar1;
  
  if (param_1 <= DAT_1100f794) {
    FUN_11006859(9);
    piVar1 = FUN_11006c63(param_1);
    FUN_110068ba(9);
    if (piVar1 != (int *)0x0) {
      return piVar1;
    }
  }
  if (param_1 == (uint *)0x0) {
    param_1 = (uint *)0x1;
  }
  piVar1 = HeapAlloc(DAT_11011bbc,0,(int)param_1 + 0xfU & 0xfffffff0);
  return piVar1;
}


// ---- 11005028 FUN_11005028  (called by: FUN_110010ef@110010ef, FUN_11005af6@11005af6, FUN_11005b01@11005b01, FUN_110067ed@110067ed, FUN_11006859@11006859, FUN_11007992@11007992, FUN_11008908@11008908, FUN_11009178@11009178, FUN_1100947e@1100947e, __fclose_lk@110050a1, __freebuf@1100764e)

void __cdecl FUN_11005028(LPVOID param_1)

{
  uint *puVar1;
  
  if (param_1 != (LPVOID)0x0) {
    FUN_11006859(9);
    puVar1 = (uint *)FUN_1100690d((int)param_1);
    if (puVar1 != (uint *)0x0) {
      FUN_11006938(puVar1,(uint)param_1);
      FUN_110068ba(9);
      return;
    }
    FUN_110068ba(9);
    HeapFree(DAT_11011bbc,0,param_1);
  }
  return;
}


// ---- 11005070 FUN_11005070  (called by: FUN_11001106@11001106, FUN_110039e5@110039e5, FUN_11003d1c@11003d1c, FUN_11003e90@11003e90)

undefined4 __cdecl FUN_11005070(FILE *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1->_flag & 0x40) == 0) {
    FUN_110074ca((uint)param_1);
    uVar1 = __fclose_lk(param_1);
    FUN_1100751c((uint)param_1);
  }
  else {
    param_1->_flag = 0;
  }
  return uVar1;
}


// ---- 110050a1 __fclose_lk  (called by: FUN_11005070@11005070)

/* Library Function - Single Match
    __fclose_lk
   
   Library: Visual Studio 2003 Release */

undefined4 __cdecl __fclose_lk(FILE *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1->_flag & 0x83) != 0) {
    uVar2 = FUN_11005386((int *)param_1);
    __freebuf(param_1);
    iVar1 = FUN_1100756e(param_1->_file);
    if (iVar1 < 0) {
      uVar2 = 0xffffffff;
    }
    else if (param_1->_tmpfname != (char *)0x0) {
      FUN_11005028(param_1->_tmpfname);
      param_1->_tmpfname = (char *)0x0;
    }
  }
  param_1->_flag = 0;
  return uVar2;
}


// ---- 110050ed FUN_110050ed  (called by: FUN_11001106@11001106)

int __cdecl FUN_110050ed(int *param_1,int param_2,DWORD param_3)

{
  int iVar1;
  
  FUN_110074ca((uint)param_1);
  iVar1 = FUN_11005119(param_1,param_2,param_3);
  FUN_1100751c((uint)param_1);
  return iVar1;
}


// ---- 11005119 FUN_11005119  (called by: FUN_110050ed@110050ed)

int __cdecl FUN_11005119(int *param_1,int param_2,DWORD param_3)

{
  uint uVar1;
  int iVar2;
  DWORD DVar3;
  DWORD *pDVar4;
  
  if (((param_1[3] & 0x83U) == 0) || (((param_3 != 0 && (param_3 != 1)) && (param_3 != 2)))) {
    pDVar4 = FUN_110076ec();
    *pDVar4 = 0x16;
    iVar2 = -1;
  }
  else {
    param_1[3] = param_1[3] & 0xffffffef;
    if (param_3 == 1) {
      iVar2 = FUN_110051c8((char *)param_1);
      param_2 = param_2 + iVar2;
      param_3 = 0;
    }
    FUN_11005386(param_1);
    uVar1 = param_1[3];
    if ((uVar1 & 0x80) == 0) {
      if ((((uVar1 & 1) != 0) && ((uVar1 & 8) != 0)) && ((uVar1 & 0x400) == 0)) {
        param_1[6] = 0x200;
      }
    }
    else {
      param_1[3] = uVar1 & 0xfffffffc;
    }
    DVar3 = FUN_110076fe(param_1[4],param_2,param_3);
    iVar2 = (DVar3 != 0xffffffff) - 1;
  }
  return iVar2;
}


// ---- 110051a6 FUN_110051a6  (called by: FUN_11001106@11001106)

int __cdecl FUN_110051a6(char *param_1)

{
  int iVar1;
  
  FUN_110074ca((uint)param_1);
  iVar1 = FUN_110051c8(param_1);
  FUN_1100751c((uint)param_1);
  return iVar1;
}


// ---- 110051c8 FUN_110051c8  (called by: FUN_11005119@11005119, FUN_110051a6@110051a6)

int __cdecl FUN_110051c8(char *param_1)

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
  local_8 = FUN_110076fe(uVar1,0,1);
  if ((int)local_8 < 0) {
LAB_11005256:
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
        pDVar4 = FUN_110076ec();
        *pDVar4 = 0x16;
        goto LAB_11005256;
      }
    }
    else if ((*(byte *)((&DAT_11010a80)[(int)uVar1 >> 5] + 4 + (uVar1 & 0x1f) * 0x24) & 0x80) != 0)
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
          if ((*(byte *)(iVar10 + 4 + (&DAT_11010a80)[(int)uVar1 >> 5]) & 0x80) != 0) {
            DVar6 = FUN_110076fe(uVar1,0,2);
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
              FUN_110076fe(uVar1,local_8,0);
              pcVar8 = (char *)0x200;
              if ((((char *)0x200 < pcVar5) || ((*(uint *)(param_1 + 0xc) & 8) == 0)) ||
                 ((*(uint *)(param_1 + 0xc) & 0x400) != 0)) {
                pcVar8 = *(char **)(param_1 + 0x18);
              }
              bVar3 = *(byte *)(iVar10 + 4 + (&DAT_11010a80)[(int)uVar1 >> 5]) & 4;
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


// ---- 11005329 FUN_11005329  (called by: FUN_11001106@11001106)

int __cdecl FUN_11005329(int *param_1)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    iVar1 = FUN_110053eb(0);
    return iVar1;
  }
  FUN_110074ca((uint)param_1);
  iVar1 = FUN_11005358(param_1);
  FUN_1100751c((uint)param_1);
  return iVar1;
}


// ---- 11005358 FUN_11005358  (called by: FUN_11005329@11005329, FUN_110053eb@110053eb)

int __cdecl FUN_11005358(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_11005386(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((*(byte *)((int)param_1 + 0xd) & 0x40) == 0) {
    return 0;
  }
  iVar1 = FUN_110079e6(param_1[4]);
  return -(uint)(iVar1 != 0);
}


// ---- 11005386 FUN_11005386  (called by: FUN_11005119@11005119, FUN_11005358@11005358, FUN_110054be@110054be, __fclose_lk@110050a1)

undefined4 __cdecl FUN_11005386(int *param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  DWORD DVar3;
  
  uVar2 = 0;
  if ((((byte)param_1[3] & 3) == 2) && ((param_1[3] & 0x108U) != 0)) {
    DVar3 = *param_1 - param_1[2];
    if (0 < (int)DVar3) {
      DVar1 = FUN_11007a79(param_1[4],(char *)param_1[2],DVar3);
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


// ---- 110053eb FUN_110053eb  (called by: FUN_11005329@11005329)

int __cdecl FUN_110053eb(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar5 = 0;
  FUN_11006859(2);
  iVar4 = 0;
  if (0 < DAT_11011ba0) {
    do {
      iVar2 = *(int *)(DAT_11010b84 + iVar4 * 4);
      if ((iVar2 != 0) && ((*(byte *)(iVar2 + 0xc) & 0x83) != 0)) {
        FUN_110074f9(iVar4,iVar2);
        piVar1 = *(int **)(DAT_11010b84 + iVar4 * 4);
        if ((piVar1[3] & 0x83U) != 0) {
          if (param_1 == 1) {
            iVar2 = FUN_11005358(piVar1);
            if (iVar2 != -1) {
              iVar3 = iVar3 + 1;
            }
          }
          else if ((param_1 == 0) && ((piVar1[3] & 2U) != 0)) {
            iVar2 = FUN_11005358(piVar1);
            if (iVar2 == -1) {
              iVar5 = -1;
            }
          }
        }
        FUN_1100754b(iVar4,*(int *)(DAT_11010b84 + iVar4 * 4));
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_11011ba0);
  }
  FUN_110068ba(2);
  if (param_1 != 1) {
    iVar3 = iVar5;
  }
  return iVar3;
}


// ---- 1100548f FUN_1100548f  (called by: FUN_11001106@11001106, FUN_110039e5@110039e5, FUN_11003d1c@11003d1c, FUN_11003e90@11003e90)

uint __cdecl FUN_1100548f(char *param_1,uint param_2,uint param_3,int *param_4)

{
  uint uVar1;
  
  FUN_110074ca((uint)param_4);
  uVar1 = FUN_110054be(param_1,param_2,param_3,param_4);
  FUN_1100751c((uint)param_4);
  return uVar1;
}


// ---- 110054be FUN_110054be  (called by: FUN_1100548f@1100548f)

uint __cdecl FUN_110054be(char *param_1,uint param_2,uint param_3,int *param_4)

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
          if (((piVar1[3] & 0x108U) != 0) && (iVar2 = FUN_11005386(piVar1), iVar2 != 0)) {
LAB_110055bf:
            return (uint)((int)piVar6 - (int)piVar5) / param_2;
          }
          if (param_4 == (int *)0x0) {
            piVar7 = piVar5;
          }
          else {
            piVar7 = (int *)((int)piVar5 - (uint)piVar5 % (uint)param_4);
          }
          piVar3 = (int *)FUN_11007a79(piVar1[4],param_1,(DWORD)piVar7);
          if ((piVar3 == (int *)0xffffffff) ||
             (piVar5 = (int *)((int)piVar5 - (int)piVar3), piVar3 < piVar7)) {
            piVar1[3] = piVar1[3] | 0x20;
            goto LAB_110055bf;
          }
          goto LAB_11005576;
        }
        uVar4 = FUN_11007c69((int)*param_1,piVar1);
        if (uVar4 == 0xffffffff) goto LAB_110055bf;
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
        FUN_110062b0((undefined4 *)*piVar1,(undefined4 *)param_1,(uint)piVar3);
        piVar1[1] = piVar1[1] - (int)piVar3;
        *piVar1 = *piVar1 + (int)piVar3;
        piVar5 = (int *)((int)piVar5 - (int)piVar3);
LAB_11005576:
        param_1 = param_1 + (int)piVar3;
      }
    } while (piVar5 != (int *)0x0);
  }
  return param_3;
}


// ---- 110055c8 FUN_110055c8  (called by: FUN_110055f9@110055f9)

undefined4 * __cdecl FUN_110055c8(LPCSTR param_1,char *param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = FUN_11007ef1();
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2 = FUN_11007d81(param_1,param_2,param_3,puVar1);
  FUN_1100751c((uint)puVar1);
  return puVar2;
}


// ---- 110055f9 FUN_110055f9  (called by: FUN_11001106@11001106, FUN_110039e5@110039e5, FUN_11003d1c@11003d1c, FUN_11003e90@11003e90)

void __cdecl FUN_110055f9(LPCSTR param_1,char *param_2)

{
  FUN_110055c8(param_1,param_2,0x40);
  return;
}


// ---- 11005610 FUN_11005610  (called by: FUN_11001106@11001106, FUN_11004e15@11004e15, FUN_1100a4c5@1100a4c5, FUN_1100a714@1100a714, FUN_1100a9e7@1100a9e7)

/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_11005610(undefined1 param_1)

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


// ---- 1100563f FUN_1100563f  (called by: FUN_110083c2@110083c2)

void FUN_1100563f(undefined *UNRECOVERED_JUMPTABLE)

{
  ExceptionList = *(void **)ExceptionList;
                    /* WARNING: Could not recover jumptable at 0x1100566a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


// ---- 11005673 FUN_11005673  (called by: FUN_11008582@11008582, FUN_11008746@11008746)

void FUN_11005673(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x11005678. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


// ---- 1100567a FUN_1100567a  (called by: FUN_11008582@11008582)

void FUN_1100567a(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x1100567f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


// ---- 11005681 FUN_11005681  (called by: FUN_11005835@11005835, FUN_110083c2@110083c2)

void FUN_11005681(PVOID param_1,PEXCEPTION_RECORD param_2)

{
  void *pvVar1;
  
  pvVar1 = ExceptionList;
  RtlUnwind(param_1,(PVOID)0x110056a9,param_2,(PVOID)0x0);
  param_2->ExceptionFlags = param_2->ExceptionFlags & 0xfffffffd;
  *(void **)pvVar1 = ExceptionList;
  ExceptionList = pvVar1;
  return;
}


// ---- 110056d0 FUN_110056d0  (called by: FUN_1100b252@1100b252, FUN_1100b265@1100b265, FUN_1100b345@1100b345, FUN_1100b425@1100b425, FUN_1100b466@1100b466, FUN_1100b479@1100b479, FUN_1100b4cc@1100b4cc, FUN_1100b4e9@1100b4e9, FUN_1100b500@1100b500)

undefined4 __cdecl
FUN_110056d0(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  int *in_EAX;
  undefined4 uVar1;
  
  uVar1 = FUN_11007fb9(param_1,param_2,param_3,param_4,in_EAX,0,(PVOID)0x0,'\0');
  return uVar1;
}


// ---- 11005706 FUN_11005706  (called by: FUN_1100843d@1100843d)

undefined4 __cdecl
FUN_11005706(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  void *local_18;
  code *local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  local_10 = param_2;
  local_14 = FUN_1100575a;
  local_8 = param_4 + 1;
  local_c = param_1;
  local_18 = ExceptionList;
  ExceptionList = &local_18;
  uVar1 = __CallSettingFrame_12(param_3,param_1,param_5);
  ExceptionList = local_18;
  return uVar1;
}


// ---- 1100575a FUN_1100575a  (called by: -)

void __cdecl FUN_1100575a(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3)

{
  FUN_11007fb9(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),param_2,'\0');
  return;
}


// ---- 1100577f FUN_1100577f  (called by: FUN_11008207@11008207)

undefined4 __cdecl
FUN_1100577f(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  local_28 = FUN_11005835;
  local_24 = param_5;
  local_20 = param_2;
  local_1c = param_6;
  local_18 = param_7;
  local_8 = 0;
  local_14 = 0x11005807;
  local_2c = ExceptionList;
  ExceptionList = &local_2c;
  local_34 = param_1;
  local_30 = param_3;
  ppuVar3 = &local_34;
  uVar2 = *param_1;
  pDVar1 = FUN_110088a1();
  (*(code *)pDVar1[0x1a])(uVar2,ppuVar3);
  if (local_8 != 0) {
    *local_2c = *(undefined4 *)ExceptionList;
  }
  ExceptionList = local_2c;
  return 0;
}


// ---- 11005835 FUN_11005835  (called by: -)

undefined4 __cdecl FUN_11005835(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3)

{
  undefined4 uVar1;
  
  if ((param_1->ExceptionFlags & 0x66) != 0) {
    *(undefined4 *)((int)param_2 + 0x24) = 1;
    return 1;
  }
  FUN_11007fb9(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),*(PVOID *)((int)param_2 + 0x14),'\x01');
  if (*(int *)((int)param_2 + 0x24) == 0) {
    FUN_11005681(param_2,param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x1100589f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)((int)param_2 + 0x18))();
  return uVar1;
}


// ---- 110058aa FUN_110058aa  (called by: FUN_11008054@11008054, FUN_11008207@11008207)

int __cdecl FUN_110058aa(uint param_1,int param_2,int param_3,uint *param_4,uint *param_5)

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
        FUN_11008a09();
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
    FUN_11008a09();
  }
  return iVar1 + uVar3 * 0x14;
}


// ---- 11005928 __global_unwind2  (called by: FUN_1100a2ec@1100a2ec)

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x11005940,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}


// ---- 11005948 FUN_11005948  (called by: -)

undefined4 FUN_11005948(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((*(uint *)(param_1 + 4) & 6) != 0) {
    *param_4 = param_2;
    uVar1 = 3;
  }
  return uVar1;
}


// ---- 1100596a __local_unwind2  (called by: FUN_1100a2ec@1100a2ec, FUN_1100a3a9@1100a3a9)

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
  pcStack_18 = FUN_11005948;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_110059fe();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  ExceptionList = pvStack_1c;
  return;
}


// ---- 110059d2 __abnormal_termination  (called by: FUN_1100850a@1100850a)

/* Library Function - Single Match
    __abnormal_termination
   
   Library: Visual Studio */

int __cdecl __abnormal_termination(void)

{
  int iVar1;
  
  iVar1 = 0;
  if ((*(code **)((int)ExceptionList + 4) == FUN_11005948) &&
     (*(int *)((int)ExceptionList + 8) == *(int *)(*(int *)((int)ExceptionList + 0xc) + 0xc))) {
    iVar1 = 1;
  }
  return iVar1;
}


// ---- 110059f5 __NLG_Notify1  (called by: __CallSettingFrame@12@110087d0)

/* Library Function - Single Match
    __NLG_Notify1
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __fastcall __NLG_Notify1(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;
  
  DAT_1100f6b8 = param_1;
  DAT_1100f6b4 = in_EAX;
  DAT_1100f6bc = unaff_EBP;
  return;
}


// ---- 110059fe FUN_110059fe  (called by: FUN_1100a2ec@1100a2ec, __local_unwind2@1100596a)

void FUN_110059fe(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_1100f6b8 = *(undefined4 *)(unaff_EBP + 8);
  DAT_1100f6b4 = in_EAX;
  DAT_1100f6bc = unaff_EBP;
  return;
}


// ---- 11005a18 FUN_11005a18  (called by: FUN_11001461@11001461, FUN_1100163e@1100163e, FUN_1100191d@1100191d, FUN_11001a01@11001a01, FUN_11001b5c@11001b5c, FUN_11001f2a@11001f2a, FUN_110029f1@110029f1)

void FUN_11005a18(void)

{
  undefined1 auStack_c [12];
  
  ExceptionList = auStack_c;
  return;
}


// ---- 11005a37 FUN_11005a37  (called by: FUN_11005ab5@11005ab5)

int __cdecl FUN_11005a37(int param_1)

{
  SIZE_T SVar1;
  int *piVar2;
  
  FUN_1100627b();
  SVar1 = FUN_11008a5f(DAT_11011bcc);
  if (SVar1 < (uint)((int)DAT_11011bc8 + (4 - (int)DAT_11011bcc))) {
    SVar1 = FUN_11008a5f(DAT_11011bcc);
    piVar2 = FUN_11005b01(DAT_11011bcc,(uint *)(SVar1 + 0x10));
    if (piVar2 == (int *)0x0) {
      param_1 = 0;
      goto LAB_11005aac;
    }
    DAT_11011bc8 = piVar2 + ((int)DAT_11011bc8 - (int)DAT_11011bcc >> 2);
    DAT_11011bcc = piVar2;
  }
  *DAT_11011bc8 = param_1;
  DAT_11011bc8 = DAT_11011bc8 + 1;
LAB_11005aac:
  FUN_11006284();
  return param_1;
}


// ---- 11005ab5 FUN_11005ab5  (called by: FUN_11001911@11001911, FUN_11004dab@11004dab)

int __cdecl FUN_11005ab5(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_11005a37(param_1);
  return (iVar1 != 0) - 1;
}


// ---- 11005af6 FUN_11005af6  (called by: FUN_11004ec6@11004ec6)

void __cdecl FUN_11005af6(LPVOID param_1)

{
  FUN_11005028(param_1);
  return;
}


// ---- 11005b01 FUN_11005b01  (called by: FUN_11005a37@11005a37)

int * __cdecl FUN_11005b01(int *param_1,uint *param_2)

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
      FUN_11005028(param_1);
    }
    else {
      do {
        if (param_2 < (uint *)0xffffffe1) {
          FUN_11006859(9);
          puVar2 = (uint *)FUN_1100690d((int)param_1);
          if (puVar2 == (uint *)0x0) {
            FUN_110068ba(9);
            if (param_2 == (uint *)0x0) {
              param_2 = (uint *)0x1;
            }
            param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
            piVar1 = HeapReAlloc(DAT_11011bbc,0,param_1,(SIZE_T)param_2);
          }
          else {
            if (DAT_1100f794 < param_2) {
LAB_11005ba0:
              if (param_2 == (uint *)0x0) {
                param_2 = (uint *)0x1;
              }
              param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
              piVar1 = HeapAlloc(DAT_11011bbc,0,(SIZE_T)param_2);
              if (piVar1 != (int *)0x0) {
                puVar4 = (uint *)(param_1[-1] - 1U);
                if (param_2 <= (uint *)(param_1[-1] - 1U)) {
                  puVar4 = param_2;
                }
                FUN_110062b0(piVar1,param_1,(uint)puVar4);
                FUN_11006938(puVar2,(uint)param_1);
              }
            }
            else {
              iVar3 = FUN_11007118(puVar2,(int)param_1,(int)param_2);
              if (iVar3 == 0) {
                piVar1 = FUN_11006c63(param_2);
                if (piVar1 == (int *)0x0) goto LAB_11005ba0;
                puVar4 = (uint *)(param_1[-1] - 1U);
                if (param_2 <= (uint *)(param_1[-1] - 1U)) {
                  puVar4 = param_2;
                }
                FUN_110062b0(piVar1,param_1,(uint)puVar4);
                FUN_11006938(puVar2,(uint)param_1);
              }
              else {
                piVar1 = param_1;
              }
              if (piVar1 == (int *)0x0) goto LAB_11005ba0;
            }
            FUN_110068ba(9);
          }
          if (piVar1 != (int *)0x0) {
            return piVar1;
          }
        }
        if (DAT_11010520 == 0) {
          return (int *)0x0;
        }
        iVar3 = FUN_110066f8(param_2);
      } while (iVar3 != 0);
    }
    piVar1 = (int *)0x0;
  }
  return piVar1;
}


// ---- 11005c40 FUN_11005c40  (called by: FUN_11003f60@11003f60, FUN_11003fc8@11003fc8, FUN_11009178@11009178, FUN_110095e9@110095e9)

uint * __cdecl FUN_11005c40(uint *param_1,uint *param_2)

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
    if (bVar1 == 0) goto LAB_11005d28;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_11005d28:
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


// ---- 11005c50 FUN_11005c50  (called by: FUN_11003fc8@11003fc8, FUN_110095e9@110095e9)

uint * __cdecl FUN_11005c50(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_11005c6c;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_11005c9f;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x11005cbb;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_11005c6c:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x11005cbb;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x11005cbb;
    }
  }
LAB_11005c9f:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x11005cbb:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_11005d28:
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
    if (bVar1 == 0) goto LAB_11005d28;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}


// ---- 11005d30 FUN_11005d30  (called by: FUN_11003f60@11003f60)

void __cdecl FUN_11005d30(byte *param_1,byte *param_2,byte *param_3,byte *param_4,byte *param_5)

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
      pbVar2 = FUN_11008c7d(param_3,pbVar2);
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


// ---- 11005dc1 FUN_11005dc1  (called by: FUN_11003f60@11003f60)

void __cdecl FUN_11005dc1(byte *param_1,byte *param_2,byte *param_3,byte *param_4,byte *param_5)

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
      FUN_110090de(param_2,param_1,2);
      param_2[2] = 0;
    }
    pbVar3 = param_1 + 2;
  }
  param_2 = (byte *)0x0;
  param_1 = pbVar3;
  if (*pbVar3 != 0) {
    do {
      bVar1 = *param_1;
      if ((*(byte *)((int)&DAT_11010960 + bVar1 + 1) & 4) == 0) {
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
        FUN_110090de(param_3,pbVar3,sVar2);
        param_3[sVar2] = 0;
      }
      pbVar3 = param_2;
      goto LAB_11005e88;
    }
  }
  if (param_3 != (byte *)0x0) {
    *param_3 = 0;
  }
LAB_11005e88:
  if ((local_8 == (byte *)0x0) || (local_8 < pbVar3)) {
    if (param_4 != (byte *)0x0) {
      sVar2 = 0xff;
      if ((uint)((int)param_1 - (int)pbVar3) < 0xff) {
        sVar2 = (int)param_1 - (int)pbVar3;
      }
      FUN_110090de(param_4,pbVar3,sVar2);
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
      FUN_110090de(param_4,pbVar3,sVar2);
      param_4[sVar2] = 0;
    }
    if (param_5 != (byte *)0x0) {
      sVar2 = 0xff;
      if ((uint)((int)param_1 - (int)local_8) < 0xff) {
        sVar2 = (int)param_1 - (int)local_8;
      }
      FUN_110090de(param_5,local_8,sVar2);
      param_5[sVar2] = 0;
    }
  }
  return;
}


// ---- 11005f10 _strlen  (called by: FUN_11003fc8@11003fc8, FUN_11005dc1@11005dc1, FUN_11009178@11009178, FUN_110095e9@110095e9)

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
    if (((uint)puVar2 & 3) == 0) goto LAB_11005f30;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_11005f63:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_11005f30:
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
  goto LAB_11005f63;
}


// ---- 11005f8b FUN_11005f8b  (called by: entry@11006064)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_11005f8b(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 1) {
    DAT_110104e0 = GetVersion();
    iVar1 = FUN_11006713(1);
    if (iVar1 != 0) {
      _DAT_110104ec = DAT_110104e0 >> 8 & 0xff;
      _DAT_110104e8 = DAT_110104e0 & 0xff;
      DAT_110104e0 = DAT_110104e0 >> 0x10;
      _DAT_110104e4 = _DAT_110104e8 * 0x100 + _DAT_110104ec;
      iVar1 = FUN_1100881c();
      if (iVar1 != 0) {
        DAT_11011bd4 = GetCommandLineA();
        DAT_110104cc = FUN_1100947e();
        FUN_110077d6();
        FUN_11009231();
        FUN_11009178();
        FUN_11006178();
        DAT_110104c8 = DAT_110104c8 + 1;
        goto LAB_1100605e;
      }
      FUN_1100674f();
    }
LAB_11005feb:
    uVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      if (DAT_110104c8 < 1) goto LAB_11005feb;
      DAT_110104c8 = DAT_110104c8 + -1;
      if (DAT_11010518 == 0) {
        FUN_110061c7();
      }
      FUN_11007992();
      FUN_11008870();
      FUN_1100674f();
    }
    else if (param_2 == 3) {
      FUN_11008908((LPVOID)0x0);
    }
LAB_1100605e:
    uVar2 = 1;
  }
  return uVar2;
}


// ---- 11006064 entry  (called by: -)

int entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2;
  if (param_2 == 0) {
    iVar2 = DAT_110104c8;
  }
  else {
    if ((param_2 != 1) && (param_2 != 2)) goto LAB_110060ac;
    if ((DAT_11011bd8 != (code *)0x0) &&
       (iVar2 = (*DAT_11011bd8)(param_1,param_2,param_3), iVar2 == 0)) {
      return 0;
    }
    iVar2 = FUN_11005f8b(param_1,param_2);
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_110060ac:
  iVar2 = FUN_11003862(param_1,param_2);
  if (param_2 == 1) {
    if (iVar2 != 0) {
      return iVar2;
    }
    FUN_11005f8b(param_1,0);
  }
  if ((param_2 == 0) || (param_2 == 3)) {
    iVar3 = FUN_11005f8b(param_1,param_2);
    param_2 = iVar2;
    if (iVar3 == 0) {
      param_2 = 0;
    }
    iVar2 = param_2;
    if ((param_2 != 0) && (DAT_11011bd8 != (code *)0x0)) {
      iVar2 = (*DAT_11011bd8)(param_1,iVar1,param_3);
    }
  }
  param_2 = iVar2;
  return param_2;
}


// ---- 11006101 __amsg_exit  (called by: FUN_11006859@11006859, FUN_110077d6@110077d6, FUN_110088a1@110088a1, FUN_11009178@11009178, FUN_11009231@11009231)

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __amsg_exit(int param_1)

{
  if ((DAT_110104d4 == 1) || ((DAT_110104d4 == 0 && (DAT_110104d8 == 1)))) {
    FUN_110095b0();
  }
  FUN_110095e9(param_1);
  (*(code *)PTR___exit_1100f6c0)(0xff);
  return;
}


// ---- 11006140 _strncmp  (called by: GetSaveRegions@11004630)

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


// ---- 11006178 FUN_11006178  (called by: FUN_11005f8b@11005f8b)

void FUN_11006178(void)

{
  if (DAT_11011bd0 != (code *)0x0) {
    (*DAT_11011bd0)();
  }
  FUN_1100628d((undefined4 *)&DAT_1100f01c,(undefined4 *)&DAT_1100f030);
  FUN_1100628d((undefined4 *)&DAT_1100f000,(undefined4 *)&DAT_1100f018);
  return;
}


// ---- 110061a5 FUN_110061a5  (called by: FUN_11004a20@11004a20)

void __cdecl FUN_110061a5(UINT param_1)

{
  FUN_110061d6(param_1,0,0);
  return;
}


// ---- 110061b6 __exit  (called by: FUN_1100a3c4@1100a3c4, FUN_1100ab0c@1100ab0c, __amsg_exit@11006101)

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __exit(int _Code)

{
  FUN_110061d6(_Code,1,0);
  return;
}


// ---- 110061c7 FUN_110061c7  (called by: FUN_11005f8b@11005f8b)

void FUN_110061c7(void)

{
  FUN_110061d6(0,0,1);
  return;
}


// ---- 110061d6 FUN_110061d6  (called by: FUN_110061a5@110061a5, FUN_110061c7@110061c7, __exit@110061b6)

void __cdecl FUN_110061d6(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  FUN_1100627b();
  if (DAT_1101051c == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  DAT_11010518 = 1;
  DAT_11010514 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_11011bcc != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_11011bc8 - 4), DAT_11011bcc <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_11011bcc <= puVar1);
    }
    FUN_1100628d((undefined4 *)&DAT_1100f034,(undefined4 *)&DAT_1100f03c);
  }
  FUN_1100628d((undefined4 *)&DAT_1100f040,(undefined4 *)&DAT_1100f048);
  if (param_3 == 0) {
    DAT_1101051c = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  FUN_11006284();
  return;
}


// ---- 1100627b FUN_1100627b  (called by: FUN_11005a37@11005a37, FUN_110061d6@110061d6)

void FUN_1100627b(void)

{
  FUN_11006859(0xd);
  return;
}


// ---- 11006284 FUN_11006284  (called by: FUN_11005a37@11005a37, FUN_110061d6@110061d6)

void FUN_11006284(void)

{
  FUN_110068ba(0xd);
  return;
}


// ---- 1100628d FUN_1100628d  (called by: FUN_11006178@11006178, FUN_110061d6@110061d6)

void __cdecl FUN_1100628d(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}


// ---- 110062b0 FUN_110062b0  (called by: FUN_11004bc6@11004bc6, FUN_11004e15@11004e15, FUN_110054be@110054be, FUN_11005b01@11005b01, FUN_1100947e@1100947e, UninstallMusicHook@11004d31)

undefined4 * __cdecl FUN_110062b0(undefined4 *param_1,undefined4 *param_2,uint param_3)

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
          goto switchD_11006467_caseD_2;
        case 3:
          goto switchD_11006467_caseD_3;
        }
        goto switchD_11006467_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_11006467_caseD_0;
      case 1:
        goto switchD_11006467_caseD_1;
      case 2:
        goto switchD_11006467_caseD_2;
      case 3:
        goto switchD_11006467_caseD_3;
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
              goto switchD_11006467_caseD_2;
            case 3:
              goto switchD_11006467_caseD_3;
            }
            goto switchD_11006467_caseD_1;
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
              goto switchD_11006467_caseD_2;
            case 3:
              goto switchD_11006467_caseD_3;
            }
            goto switchD_11006467_caseD_1;
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
              goto switchD_11006467_caseD_2;
            case 3:
              goto switchD_11006467_caseD_3;
            }
            goto switchD_11006467_caseD_1;
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
switchD_11006467_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_11006467_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_11006467_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_11006467_caseD_0:
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
        goto switchD_110062e5_caseD_2;
      case 3:
        goto switchD_110062e5_caseD_3;
      }
      goto switchD_110062e5_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_110062e5_caseD_0;
    case 1:
      goto switchD_110062e5_caseD_1;
    case 2:
      goto switchD_110062e5_caseD_2;
    case 3:
      goto switchD_110062e5_caseD_3;
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
            goto switchD_110062e5_caseD_2;
          case 3:
            goto switchD_110062e5_caseD_3;
          }
          goto switchD_110062e5_caseD_1;
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
            goto switchD_110062e5_caseD_2;
          case 3:
            goto switchD_110062e5_caseD_3;
          }
          goto switchD_110062e5_caseD_1;
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
            goto switchD_110062e5_caseD_2;
          case 3:
            goto switchD_110062e5_caseD_3;
          }
          goto switchD_110062e5_caseD_1;
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
switchD_110062e5_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_110062e5_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_110062e5_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_110062e5_caseD_0:
  return param_1;
}


// ---- 110065f0 _memcmp  (called by: FUN_11004bc6@11004bc6)

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
          goto LAB_1100666a;
        }
      }
      if (uVar2 != 0) {
        uVar5 = *(uint *)_Buf1;
        uVar1 = *(uint *)_Buf2;
        bVar9 = (byte)uVar5 < (byte)uVar1;
        if ((byte)uVar5 != (byte)uVar1) {
LAB_1100666a:
          return (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        }
        iVar3 = 0;
        if (uVar2 != 1) {
          bVar6 = (byte)(uVar5 >> 8);
          bVar4 = (byte)(uVar1 >> 8);
          bVar9 = bVar6 < bVar4;
          if (bVar6 != bVar4) goto LAB_1100666a;
          iVar3 = 0;
          if (uVar2 != 2) {
            bVar9 = (uVar5 & 0xff0000) < (uVar1 & 0xff0000);
            if ((uVar5 & 0xff0000) != (uVar1 & 0xff0000)) goto LAB_1100666a;
            iVar3 = uVar2 - 3;
          }
        }
        return iVar3;
      }
    }
    else {
      if ((_Size & 1) == 0) goto LAB_1100661d;
      bVar9 = *(byte *)_Buf1 < *(byte *)_Buf2;
      if (*(byte *)_Buf1 != *(byte *)_Buf2) goto LAB_1100666a;
      _Buf1 = (void *)((int)_Buf1 + 1);
      _Buf2 = (void *)((int)_Buf2 + 1);
      for (_Size = _Size - 1; _Size != 0; _Size = _Size - 2) {
LAB_1100661d:
        bVar9 = *(byte *)_Buf1 < *(byte *)_Buf2;
        if ((*(byte *)_Buf1 != *(byte *)_Buf2) ||
           (bVar9 = *(byte *)((int)_Buf1 + 1) < *(byte *)((int)_Buf2 + 1),
           *(byte *)((int)_Buf1 + 1) != *(byte *)((int)_Buf2 + 1))) goto LAB_1100666a;
        _Buf2 = (void *)((int)_Buf2 + 2);
        _Buf1 = (void *)((int)_Buf1 + 2);
      }
    }
  }
  return 0;
}


// ---- 110066a0 _memset  (called by: FUN_11004e15@11004e15, FUN_11009a75@11009a75, FUN_1100a714@1100a714, FUN_1100a9e7@1100a9e7)

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


// ---- 110066f8 FUN_110066f8  (called by: FUN_11005b01@11005b01, FUN_11009a75@11009a75, __nh_malloc@11004fae)

undefined4 __cdecl FUN_110066f8(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_11010524 != (code *)0x0) {
    iVar1 = (*DAT_11010524)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


// ---- 11006713 FUN_11006713  (called by: FUN_11005f8b@11005f8b)

undefined4 __cdecl FUN_11006713(int param_1)

{
  int iVar1;
  
  DAT_11011bbc = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (DAT_11011bbc != (HANDLE)0x0) {
    iVar1 = FUN_110068cf();
    if (iVar1 != 0) {
      return 1;
    }
    HeapDestroy(DAT_11011bbc);
  }
  return 0;
}


// ---- 1100674f FUN_1100674f  (called by: FUN_11005f8b@11005f8b)

void FUN_1100674f(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  if (0 < DAT_11011bb4) {
    puVar2 = (undefined4 *)((int)DAT_11011bb8 + 0xc);
    do {
      VirtualFree((LPVOID)*puVar2,0x100000,0x4000);
      VirtualFree((LPVOID)*puVar2,0,0x8000);
      HeapFree(DAT_11011bbc,0,(LPVOID)puVar2[1]);
      puVar2 = puVar2 + 5;
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_11011bb4);
  }
  HeapFree(DAT_11011bbc,0,DAT_11011bb8);
  HeapDestroy(DAT_11011bbc);
  return;
}


// ---- 110067c4 FUN_110067c4  (called by: FUN_1100881c@1100881c)

void FUN_110067c4(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1100f718);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1100f708);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1100f6f8);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1100f6d8);
  return;
}


// ---- 110067ed FUN_110067ed  (called by: FUN_11008870@11008870)

void FUN_110067ed(void)

{
  undefined **ppuVar1;
  
  ppuVar1 = (undefined **)&DAT_1100f6d4;
  do {
    if (((((LPCRITICAL_SECTION)*ppuVar1 != (LPCRITICAL_SECTION)0x0) &&
         (ppuVar1 != &PTR_DAT_1100f718)) && (ppuVar1 != &PTR_DAT_1100f708)) &&
       ((ppuVar1 != &PTR_DAT_1100f6f8 && (ppuVar1 != &PTR_DAT_1100f6d8)))) {
      DeleteCriticalSection((LPCRITICAL_SECTION)*ppuVar1);
      FUN_11005028(*ppuVar1);
    }
    ppuVar1 = ppuVar1 + 1;
  } while ((int)ppuVar1 < 0x1100f794);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1100f6f8);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1100f708);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1100f718);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1100f6d8);
  return;
}


// ---- 11006859 FUN_11006859  (called by: FUN_11004fda@11004fda, FUN_11005028@11005028, FUN_110053eb@110053eb, FUN_11005b01@11005b01, FUN_1100627b@1100627b, FUN_11006859@11006859, FUN_110074ca@110074ca, FUN_110074f9@110074f9, FUN_11007ef1@11007ef1, FUN_11008a5f@11008a5f, FUN_11008c7d@11008c7d, FUN_11008cea@11008cea, FUN_110090de@110090de, FUN_11009a75@11009a75, FUN_11009b83@11009b83, FUN_11009de3@11009de3, FUN_1100ab0c@1100ab0c, FUN_1100adc0@1100adc0, FUN_1100ae90@1100ae90)

void __cdecl FUN_11006859(int param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  piVar1 = &DAT_1100f6d4 + param_1;
  if ((&DAT_1100f6d4)[param_1] == 0) {
    lpCriticalSection = _malloc(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    FUN_11006859(0x11);
    if (*piVar1 == 0) {
      InitializeCriticalSection(lpCriticalSection);
      *piVar1 = (int)lpCriticalSection;
    }
    else {
      FUN_11005028(lpCriticalSection);
    }
    FUN_110068ba(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)*piVar1);
  return;
}


// ---- 110068ba FUN_110068ba  (called by: FUN_11004fda@11004fda, FUN_11005028@11005028, FUN_110053eb@110053eb, FUN_11005b01@11005b01, FUN_11006284@11006284, FUN_11006859@11006859, FUN_1100751c@1100751c, FUN_1100754b@1100754b, FUN_11007ef1@11007ef1, FUN_11008a5f@11008a5f, FUN_11008c7d@11008c7d, FUN_11008cea@11008cea, FUN_110090de@110090de, FUN_11009a75@11009a75, FUN_11009b83@11009b83, FUN_11009de3@11009de3, FUN_1100ab0c@1100ab0c, FUN_1100adc0@1100adc0, FUN_1100ae90@1100ae90)

void __cdecl FUN_110068ba(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_1100f6d4)[param_1]);
  return;
}


// ---- 110068cf FUN_110068cf  (called by: FUN_11006713@11006713)

undefined4 FUN_110068cf(void)

{
  DAT_11011bb8 = HeapAlloc(DAT_11011bbc,0,0x140);
  if (DAT_11011bb8 == (LPVOID)0x0) {
    return 0;
  }
  DAT_11011bb0 = 0;
  DAT_11011bb4 = 0;
  DAT_11011bac = DAT_11011bb8;
  DAT_11011ba4 = 0x10;
  return 1;
}


// ---- 1100690d FUN_1100690d  (called by: FUN_11005028@11005028, FUN_11005b01@11005b01, FUN_11008a5f@11008a5f)

uint __cdecl FUN_1100690d(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_11011bb8;
  while( true ) {
    if (DAT_11011bb8 + DAT_11011bb4 * 0x14 <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}


// ---- 11006938 FUN_11006938  (called by: FUN_11005028@11005028, FUN_11005b01@11005b01)

void __cdecl FUN_11006938(uint *param_1,uint param_2)

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
  if (DAT_11011bb0 != (uint *)0x0) {
    VirtualFree((LPVOID)(DAT_11011ba8 * 0x8000 + DAT_11011bb0[3]),0x8000,0x4000);
    DAT_11011bb0[2] = DAT_11011bb0[2] | 0x80000000U >> ((byte)DAT_11011ba8 & 0x1f);
    *(undefined4 *)(DAT_11011bb0[4] + 0xc4 + DAT_11011ba8 * 4) = 0;
    *(char *)(DAT_11011bb0[4] + 0x43) = *(char *)(DAT_11011bb0[4] + 0x43) + -1;
    if (*(char *)(DAT_11011bb0[4] + 0x43) == '\0') {
      DAT_11011bb0[1] = DAT_11011bb0[1] & 0xfffffffe;
    }
    if (DAT_11011bb0[2] == 0xffffffff) {
      VirtualFree((LPVOID)DAT_11011bb0[3],0,0x8000);
      HeapFree(DAT_11011bbc,0,(LPVOID)DAT_11011bb0[4]);
      FUN_11009740(DAT_11011bb0,DAT_11011bb0 + 5,
                   (DAT_11011bb4 * 0x14 - (int)DAT_11011bb0) + -0x14 + DAT_11011bb8);
      DAT_11011bb4 = DAT_11011bb4 + -1;
      if (DAT_11011bb0 < param_1) {
        param_1 = param_1 + -5;
      }
      DAT_11011ba8 = uVar10;
      DAT_11011bac = DAT_11011bb8;
      DAT_11011bb0 = param_1;
      return;
    }
  }
  DAT_11011bb0 = param_1;
  DAT_11011ba8 = uVar10;
  return;
}


// ---- 11006c63 FUN_11006c63  (called by: FUN_11004fda@11004fda, FUN_11005b01@11005b01, FUN_11009a75@11009a75)

int * __cdecl FUN_11006c63(uint *param_1)

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
  
  puVar10 = DAT_11011bb8 + DAT_11011bb4 * 5;
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
  for (param_1 = DAT_11011bac;
      (param_1 < puVar10 && ((param_1[1] & local_c) == 0 && (*param_1 & local_10) == 0));
      param_1 = param_1 + 5) {
  }
  if (param_1 == puVar10) {
    for (param_1 = DAT_11011bb8;
        (param_1 < DAT_11011bac && ((param_1[1] & local_c) == 0 && (*param_1 & local_10) == 0));
        param_1 = param_1 + 5) {
    }
    if (param_1 == DAT_11011bac) {
      for (; (param_1 < puVar10 && (param_1[2] == 0)); param_1 = param_1 + 5) {
      }
      if (param_1 == puVar10) {
        for (param_1 = DAT_11011bb8; (param_1 < DAT_11011bac && (param_1[2] == 0));
            param_1 = param_1 + 5) {
        }
        if ((param_1 == DAT_11011bac) && (param_1 = FUN_11006f6c(), param_1 == (uint *)0x0)) {
          return (int *)0x0;
        }
      }
      iVar8 = FUN_1100701d((int)param_1);
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
  DAT_11011bac = param_1;
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
    if (iVar11 == 0) goto LAB_11006f29;
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
LAB_11006f29:
  piVar12 = (int *)((int)piVar12 + iVar11);
  *piVar12 = uVar7 + 1;
  *(uint *)((int)piVar12 + (uVar7 - 4)) = uVar7 + 1;
  iVar8 = *piVar3;
  *piVar3 = iVar8 + 1;
  if (((iVar8 == 0) && (param_1 == DAT_11011bb0)) && (local_8 == DAT_11011ba8)) {
    DAT_11011bb0 = (uint *)0x0;
  }
  *piVar5 = local_8;
  return piVar12 + 1;
}


// ---- 11006f6c FUN_11006f6c  (called by: FUN_11006c63@11006c63)

undefined4 * FUN_11006f6c(void)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  
  if (DAT_11011bb4 == DAT_11011ba4) {
    pvVar2 = HeapReAlloc(DAT_11011bbc,0,DAT_11011bb8,(DAT_11011ba4 * 5 + 0x50) * 4);
    if (pvVar2 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_11011ba4 = DAT_11011ba4 + 0x10;
    DAT_11011bb8 = pvVar2;
  }
  puVar1 = (undefined4 *)((int)DAT_11011bb8 + DAT_11011bb4 * 0x14);
  pvVar2 = HeapAlloc(DAT_11011bbc,8,0x41c4);
  puVar1[4] = pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar1[3] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      puVar1[2] = 0xffffffff;
      *puVar1 = 0;
      puVar1[1] = 0;
      DAT_11011bb4 = DAT_11011bb4 + 1;
      *(undefined4 *)puVar1[4] = 0xffffffff;
      return puVar1;
    }
    HeapFree(DAT_11011bbc,0,(LPVOID)puVar1[4]);
  }
  return (undefined4 *)0x0;
}


// ---- 1100701d FUN_1100701d  (called by: FUN_11006c63@11006c63)

int __cdecl FUN_1100701d(int param_1)

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


// ---- 11007118 FUN_11007118  (called by: FUN_11005b01@11005b01)

undefined4 __cdecl FUN_11007118(uint *param_1,int param_2,int param_3)

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


// ---- 110074ca FUN_110074ca  (called by: FUN_11005070@11005070, FUN_110050ed@110050ed, FUN_110051a6@110051a6, FUN_11005329@11005329, FUN_1100548f@1100548f)

void __cdecl FUN_110074ca(uint param_1)

{
  if ((param_1 < 0x1100f798) || (0x1100f9f8 < param_1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
    return;
  }
  FUN_11006859(((int)(param_1 + 0xeeff0868) >> 5) + 0x1c);
  return;
}


// ---- 110074f9 FUN_110074f9  (called by: FUN_110053eb@110053eb, FUN_11007ef1@11007ef1)

void __cdecl FUN_110074f9(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_11006859(param_1 + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}


// ---- 1100751c FUN_1100751c  (called by: FUN_11005070@11005070, FUN_110050ed@110050ed, FUN_110051a6@110051a6, FUN_11005329@11005329, FUN_1100548f@1100548f, FUN_110055c8@110055c8)

void __cdecl FUN_1100751c(uint param_1)

{
  if ((param_1 < 0x1100f798) || (0x1100f9f8 < param_1)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
    return;
  }
  FUN_110068ba(((int)(param_1 + 0xeeff0868) >> 5) + 0x1c);
  return;
}


// ---- 1100754b FUN_1100754b  (called by: FUN_110053eb@110053eb, FUN_11007ef1@11007ef1)

void __cdecl FUN_1100754b(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_110068ba(param_1 + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}


// ---- 1100756e FUN_1100756e  (called by: FUN_11009ed1@11009ed1, __fclose_lk@110050a1)

undefined4 __cdecl FUN_1100756e(uint param_1)

{
  undefined4 uVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_11010b80) &&
     ((*(byte *)((&DAT_11010a80)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_11009de3(param_1);
    uVar1 = FUN_110075cb(param_1);
    FUN_11009e42(param_1);
    return uVar1;
  }
  pDVar2 = FUN_110076ec();
  *pDVar2 = 9;
  pDVar2 = FUN_110076f5();
  *pDVar2 = 0;
  return 0xffffffff;
}


// ---- 110075cb FUN_110075cb  (called by: FUN_1100756e@1100756e)

undefined4 __cdecl FUN_110075cb(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  undefined4 uVar5;
  
  iVar1 = FUN_11009da1(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_11009da1(2);
      iVar2 = FUN_11009da1(1);
      if (iVar2 == iVar1) goto LAB_11007619;
    }
    hObject = (HANDLE)FUN_11009da1(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_1100761b;
    }
  }
LAB_11007619:
  DVar4 = 0;
LAB_1100761b:
  FUN_11009d22(param_1);
  *(undefined1 *)((&DAT_11010a80)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = 0;
  if (DVar4 == 0) {
    uVar5 = 0;
  }
  else {
    FUN_11007679(DVar4);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}


// ---- 1100764e __freebuf  (called by: __fclose_lk@110050a1)

/* Library Function - Single Match
    __freebuf
   
   Library: Visual Studio 2003 Release */

void __cdecl __freebuf(FILE *_File)

{
  if (((_File->_flag & 0x83U) != 0) && ((_File->_flag & 8U) != 0)) {
    FUN_11005028(_File->_base);
    *(ushort *)&_File->_flag = (ushort)_File->_flag & 0xfbf7;
    _File->_ptr = (char *)0x0;
    _File->_base = (char *)0x0;
    _File->_cnt = 0;
  }
  return;
}


// ---- 11007679 FUN_11007679  (called by: FUN_110075cb@110075cb, FUN_11007763@11007763, FUN_11007ade@11007ade, FUN_11008aa4@11008aa4, FUN_11009ed1@11009ed1)

void __cdecl FUN_11007679(uint param_1)

{
  DWORD *pDVar1;
  uint *puVar2;
  int iVar3;
  
  pDVar1 = FUN_110076f5();
  iVar3 = 0;
  *pDVar1 = param_1;
  puVar2 = &DAT_1100fa18;
  do {
    if (param_1 == *puVar2) {
      pDVar1 = FUN_110076ec();
      *pDVar1 = *(DWORD *)(iVar3 * 8 + 0x1100fa1c);
      return;
    }
    puVar2 = puVar2 + 2;
    iVar3 = iVar3 + 1;
  } while ((int)puVar2 < 0x1100fb80);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    pDVar1 = FUN_110076ec();
    *pDVar1 = 0xd;
    return;
  }
  if ((param_1 < 0xbc) || (0xca < param_1)) {
    pDVar1 = FUN_110076ec();
    *pDVar1 = 0x16;
    return;
  }
  pDVar1 = FUN_110076ec();
  *pDVar1 = 8;
  return;
}


// ---- 110076ec FUN_110076ec  (called by: FUN_11005119@11005119, FUN_110051c8@110051c8, FUN_1100756e@1100756e, FUN_11007679@11007679, FUN_110076fe@110076fe, FUN_11007763@11007763, FUN_110079e6@110079e6, FUN_11007a79@11007a79, FUN_11007ade@11007ade, FUN_11008aa4@11008aa4, FUN_11009ca6@11009ca6, FUN_11009d22@11009d22, FUN_11009da1@11009da1, FUN_11009ed1@11009ed1, FUN_1100a9e7@1100a9e7, FUN_1100acd4@1100acd4)

DWORD * FUN_110076ec(void)

{
  DWORD *pDVar1;
  
  pDVar1 = FUN_110088a1();
  return pDVar1 + 2;
}


// ---- 110076f5 FUN_110076f5  (called by: FUN_1100756e@1100756e, FUN_11007679@11007679, FUN_110076fe@110076fe, FUN_110079e6@110079e6, FUN_11007a79@11007a79, FUN_11007ade@11007ade, FUN_11008aa4@11008aa4, FUN_11009ca6@11009ca6, FUN_11009d22@11009d22, FUN_11009da1@11009da1, FUN_11009ed1@11009ed1, FUN_1100a9e7@1100a9e7)

DWORD * FUN_110076f5(void)

{
  DWORD *pDVar1;
  
  pDVar1 = FUN_110088a1();
  return pDVar1 + 3;
}


// ---- 110076fe FUN_110076fe  (called by: FUN_11005119@11005119, FUN_110051c8@110051c8, FUN_11007c69@11007c69)

DWORD __cdecl FUN_110076fe(uint param_1,LONG param_2,DWORD param_3)

{
  DWORD DVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_11010b80) &&
     ((*(byte *)((&DAT_11010a80)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_11009de3(param_1);
    DVar1 = FUN_11007763(param_1,param_2,param_3);
    FUN_11009e42(param_1);
    return DVar1;
  }
  pDVar2 = FUN_110076ec();
  *pDVar2 = 9;
  pDVar2 = FUN_110076f5();
  *pDVar2 = 0;
  return 0xffffffff;
}


// ---- 11007763 FUN_11007763  (called by: FUN_110076fe@110076fe, FUN_11007ade@11007ade, FUN_11008aa4@11008aa4, FUN_11009ed1@11009ed1, FUN_1100a9e7@1100a9e7)

DWORD __cdecl FUN_11007763(uint param_1,LONG param_2,DWORD param_3)

{
  byte *pbVar1;
  HANDLE hFile;
  DWORD *pDVar2;
  DWORD DVar3;
  uint uVar4;
  
  hFile = (HANDLE)FUN_11009da1(param_1);
  if (hFile == (HANDLE)0xffffffff) {
    pDVar2 = FUN_110076ec();
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
      pbVar1 = (byte *)((&DAT_11010a80)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
      *pbVar1 = *pbVar1 & 0xfd;
      return DVar3;
    }
    FUN_11007679(uVar4);
  }
  return 0xffffffff;
}


// ---- 110077d6 FUN_110077d6  (called by: FUN_11005f8b@11005f8b)

void FUN_110077d6(void)

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
  DAT_11010b80 = 0x20;
  DAT_11010a80 = puVar2;
  for (; puVar2 < DAT_11010a80 + 0x120; puVar2 = puVar2 + 9) {
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
    if ((int)DAT_11010b80 < (int)UVar8) {
      puVar2 = &DAT_11010a84;
      do {
        puVar3 = _malloc(0x480);
        if (puVar3 == (undefined4 *)0x0) {
          UVar8 = DAT_11010b80;
          break;
        }
        DAT_11010b80 = DAT_11010b80 + 0x20;
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
      } while ((int)DAT_11010b80 < (int)UVar8);
    }
    uVar7 = 0;
    if (0 < (int)UVar8) {
      do {
        if (((*(HANDLE *)local_8 != (HANDLE)0xffffffff) && ((*pUVar5 & 1) != 0)) &&
           (((*pUVar5 & 8) != 0 || (DVar4 = GetFileType(*(HANDLE *)local_8), DVar4 != 0)))) {
          puVar2 = (undefined4 *)((int)(&DAT_11010a80)[(int)uVar7 >> 5] + (uVar7 & 0x1f) * 0x24);
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
    puVar2 = DAT_11010a80 + iVar6 * 9;
    if (DAT_11010a80[iVar6 * 9] == -1) {
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
          goto LAB_1100797b;
        }
      }
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x40;
    }
    else {
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x80;
    }
LAB_1100797b:
    iVar6 = iVar6 + 1;
    if (2 < iVar6) {
      SetHandleCount(DAT_11010b80);
      return;
    }
  } while( true );
}


// ---- 11007992 FUN_11007992  (called by: FUN_11005f8b@11005f8b)

void FUN_11007992(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint *puVar1;
  uint uVar2;
  
  puVar1 = &DAT_11010a80;
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
      FUN_11005028((LPVOID)*puVar1);
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x11010b80);
  return;
}


// ---- 110079e6 FUN_110079e6  (called by: FUN_11005358@11005358)

undefined4 __cdecl FUN_110079e6(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  DWORD *pDVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (DAT_11010b80 <= param_1) {
LAB_11007a67:
    pDVar3 = FUN_110076ec();
    *pDVar3 = 9;
    return 0xffffffff;
  }
  iVar4 = (param_1 & 0x1f) * 0x24;
  if ((*(byte *)((&DAT_11010a80)[(int)param_1 >> 5] + 4 + iVar4) & 1) == 0) goto LAB_11007a67;
  FUN_11009de3(param_1);
  if ((*(byte *)((&DAT_11010a80)[(int)param_1 >> 5] + 4 + iVar4) & 1) != 0) {
    hFile = (HANDLE)FUN_11009da1(param_1);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = 0;
    }
    uVar5 = 0;
    if (DVar2 == 0) goto LAB_11007a5c;
    pDVar3 = FUN_110076f5();
    *pDVar3 = DVar2;
  }
  pDVar3 = FUN_110076ec();
  *pDVar3 = 9;
  uVar5 = 0xffffffff;
LAB_11007a5c:
  FUN_11009e42(param_1);
  return uVar5;
}


// ---- 11007a79 FUN_11007a79  (called by: FUN_11005386@11005386, FUN_110054be@110054be, FUN_11007c69@11007c69)

int __cdecl FUN_11007a79(uint param_1,char *param_2,DWORD param_3)

{
  int iVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_11010b80) &&
     ((*(byte *)((&DAT_11010a80)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_11009de3(param_1);
    iVar1 = FUN_11007ade(param_1,param_2,param_3);
    FUN_11009e42(param_1);
    return iVar1;
  }
  pDVar2 = FUN_110076ec();
  *pDVar2 = 9;
  pDVar2 = FUN_110076f5();
  *pDVar2 = 0;
  return -1;
}


// ---- 11007ade FUN_11007ade  (called by: FUN_11007a79@11007a79, FUN_1100a9e7@1100a9e7)

int __cdecl FUN_11007ade(DWORD param_1,char *param_2,DWORD param_3)

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
LAB_11007af7:
    iVar4 = 0;
  }
  else {
    piVar1 = &DAT_11010a80 + ((int)param_1 >> 5);
    iVar4 = (param_1 & 0x1f) * 0x24;
    if ((*(byte *)(*piVar1 + 4 + iVar4) & 0x20) != 0) {
      FUN_11007763(param_1,0,2);
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
LAB_11007bc6:
      if (local_c != 0) {
        return local_c - local_14;
      }
      if (param_1 == 0) goto LAB_11007c38;
      if (param_1 == 5) {
        pDVar7 = FUN_110076ec();
        *pDVar7 = 9;
        pDVar7 = FUN_110076f5();
        *pDVar7 = 5;
      }
      else {
        FUN_11007679(param_1);
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
            goto LAB_11007bc6;
          }
          local_c = local_c + local_10;
          if (((int)local_10 < (int)pcVar5 - (int)local_418) ||
             (param_3 <= (uint)((int)local_8 - (int)param_2))) goto LAB_11007bc6;
        } while( true );
      }
LAB_11007c38:
      if (((*(byte *)(*piVar1 + 4 + iVar4) & 0x40) != 0) && (*param_2 == '\x1a')) goto LAB_11007af7;
      pDVar7 = FUN_110076ec();
      *pDVar7 = 0x1c;
      pDVar7 = FUN_110076f5();
      *pDVar7 = 0;
    }
    iVar4 = -1;
  }
  return iVar4;
}


// ---- 11007c69 FUN_11007c69  (called by: FUN_110054be@110054be, __putw@1100b1f0)

uint __cdecl FUN_11007c69(uint param_1,int *param_2)

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
LAB_11007d75:
    param_2[3] = uVar1 | 0x20;
  }
  else {
    if ((uVar1 & 1) != 0) {
      param_2[1] = 0;
      if ((uVar1 & 0x10) == 0) goto LAB_11007d75;
      *param_2 = param_2[2];
      param_2[3] = uVar1 & 0xfffffffe;
    }
    uVar1 = param_2[3];
    param_2[1] = 0;
    param_2 = (int *)0x0;
    piVar4[3] = uVar1 & 0xffffffef | 2;
    if (((uVar1 & 0x10c) == 0) &&
       (((piVar4 != (int *)&DAT_1100f7b8 && (piVar4 != (int *)&DAT_1100f7d8)) ||
        (bVar5 = FUN_11009ea8(uVar2), CONCAT31(extraout_var,bVar5) == 0)))) {
      FUN_11009e64(piVar4);
    }
    if ((*(ushort *)(piVar4 + 3) & 0x108) == 0) {
      piVar7 = (int *)0x1;
      param_2 = (int *)FUN_11007a79(uVar2,(char *)&param_1,1);
    }
    else {
      pcVar3 = (char *)piVar4[2];
      piVar7 = (int *)(*piVar4 - (int)pcVar3);
      *piVar4 = (int)(pcVar3 + 1);
      piVar4[1] = piVar4[6] + -1;
      if ((int)piVar7 < 1) {
        if (uVar2 == 0xffffffff) {
          puVar6 = &DAT_1100fb80;
        }
        else {
          puVar6 = (undefined *)((&DAT_11010a80)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
        }
        if ((puVar6[4] & 0x20) != 0) {
          FUN_110076fe(uVar2,0,2);
        }
      }
      else {
        param_2 = (int *)FUN_11007a79(uVar2,pcVar3,(DWORD)piVar7);
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


// ---- 11007d81 FUN_11007d81  (called by: FUN_110055c8@110055c8)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __cdecl FUN_11007d81(LPCSTR param_1,char *param_2,uint param_3,undefined4 *param_4)

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
      uVar6 = DAT_1101069c | 1;
      goto LAB_11007dc2;
    }
    if (cVar1 != 'w') {
      return (undefined4 *)0x0;
    }
    uVar5 = 0x301;
  }
  uVar6 = DAT_1101069c | 2;
LAB_11007dc2:
  bVar2 = true;
LAB_11007dc5:
  cVar1 = param_2[1];
  param_2 = param_2 + 1;
  if ((cVar1 == '\0') || (!bVar2)) {
    uVar5 = FUN_11009ed1(param_1,uVar5,param_3,0x1a4);
    if ((int)uVar5 < 0) {
      return (undefined4 *)0x0;
    }
    _DAT_11010588 = _DAT_11010588 + 1;
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
        goto LAB_11007dc5;
      }
    }
    else if (cVar1 == '+') {
      if ((uVar5 & 2) == 0) {
        uVar5 = uVar5 & 0xfffffffe | 2;
        uVar6 = uVar6 & 0xfffffffc | 0x80;
        goto LAB_11007dc5;
      }
    }
    else if (cVar1 == 'D') {
      if ((uVar5 & 0x40) == 0) {
        uVar5 = uVar5 | 0x40;
        goto LAB_11007dc5;
      }
    }
    else if (cVar1 == 'R') {
      if (!bVar3) {
        bVar3 = true;
        uVar5 = uVar5 | 0x10;
        goto LAB_11007dc5;
      }
    }
    else if ((cVar1 == 'S') && (!bVar3)) {
      bVar3 = true;
      uVar5 = uVar5 | 0x20;
      goto LAB_11007dc5;
    }
  }
  else {
    if (cVar1 == 'b') {
      if ((uVar5 & 0xc000) != 0) goto LAB_11007ea5;
      uVar5 = uVar5 | 0x8000;
      goto LAB_11007dc5;
    }
    if (cVar1 == 'c') {
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 | 0x4000;
        goto LAB_11007dc5;
      }
    }
    else {
      if (cVar1 != 'n') {
        if ((cVar1 != 't') || ((uVar5 & 0xc000) != 0)) goto LAB_11007ea5;
        uVar5 = uVar5 | 0x4000;
        goto LAB_11007dc5;
      }
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 & 0xffffbfff;
        goto LAB_11007dc5;
      }
    }
  }
LAB_11007ea5:
  bVar2 = false;
  goto LAB_11007dc5;
}


// ---- 11007ef1 FUN_11007ef1  (called by: FUN_110055c8@110055c8)

undefined4 * FUN_11007ef1(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)0x0;
  FUN_11006859(2);
  iVar3 = 0;
  if (0 < DAT_11011ba0) {
    do {
      iVar1 = *(int *)(DAT_11010b84 + iVar3 * 4);
      if (iVar1 == 0) {
        iVar3 = iVar3 * 4;
        pvVar2 = _malloc(0x38);
        *(void **)(iVar3 + DAT_11010b84) = pvVar2;
        if (*(int *)(iVar3 + DAT_11010b84) != 0) {
          InitializeCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_11010b84) + 0x20));
          EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_11010b84) + 0x20));
          puVar4 = *(undefined4 **)(iVar3 + DAT_11010b84);
LAB_11007f95:
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
        FUN_110074f9(iVar3,iVar1);
        iVar1 = *(int *)(DAT_11010b84 + iVar3 * 4);
        if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
          puVar4 = *(undefined4 **)(DAT_11010b84 + iVar3 * 4);
          goto LAB_11007f95;
        }
        FUN_1100754b(iVar3,iVar1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_11011ba0);
  }
  FUN_110068ba(2);
  return puVar4;
}


// ---- 11007fb9 FUN_11007fb9  (called by: FUN_110056d0@110056d0, FUN_1100575a@1100575a, FUN_11005835@11005835)

undefined4 __cdecl
FUN_11007fb9(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int *param_5,
            int param_6,PVOID param_7,char param_8)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (*param_5 != 0x19930520) {
    FUN_11008a09();
  }
  if ((param_1->ExceptionFlags & 0x66) == 0) {
    if (param_5[3] != 0) {
      if (((param_1->ExceptionCode == 0xe06d7363) && (0x19930520 < param_1->ExceptionInformation[0])
          ) && (pcVar1 = *(code **)(param_1->ExceptionInformation[2] + 8), pcVar1 != (code *)0x0)) {
        uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
        return uVar2;
      }
      FUN_11008054(param_1,param_2,param_3,param_4,(uint)param_5,param_8,param_6,param_7);
    }
  }
  else if ((param_5[1] != 0) && (param_6 == 0)) {
    FUN_1100830e((int)param_2,param_4,(int)param_5,-1);
  }
  return 1;
}


// ---- 11008054 FUN_11008054  (called by: FUN_11007fb9@11007fb9)

void __cdecl
FUN_11008054(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,uint param_5,
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
    FUN_11008a09();
  }
  if (param_1->ExceptionCode == 0xe06d7363) {
    if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
       (param_1->ExceptionInformation[2] == 0)) {
      pDVar3 = FUN_110088a1();
      if (pDVar3[0x1b] == 0) {
        return;
      }
      pDVar3 = FUN_110088a1();
      param_1 = (PEXCEPTION_RECORD)pDVar3[0x1b];
      pDVar3 = FUN_110088a1();
      param_3 = pDVar3[0x1c];
      local_18 = CONCAT31(local_18._1_3_,1);
      bVar2 = FUN_1100a204(param_1,1);
      if (CONCAT31(extraout_var,bVar2) == 0) {
        FUN_11008a09();
      }
      if (param_1->ExceptionCode != 0xe06d7363) goto LAB_110081dc;
      if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
         (param_1->ExceptionInformation[2] == 0)) {
        FUN_11008a09();
      }
    }
    iVar5 = local_14;
    if (((param_1->ExceptionCode == 0xe06d7363) && (param_1->NumberParameters == 3)) &&
       (param_1->ExceptionInformation[0] == 0x19930520)) {
      piVar4 = (int *)FUN_110058aa(param_5,param_7,local_14,&local_8,&local_1c);
      do {
        if (local_1c <= local_8) {
          if (param_6 == '\0') {
            return;
          }
          FUN_11008746((int)param_1);
          return;
        }
        if ((*piVar4 <= iVar5) && (iVar5 <= piVar4[1])) {
          pbVar1 = (byte *)piVar4[4];
          for (local_10 = piVar4[3]; 0 < local_10; local_10 = local_10 + -1) {
            piVar6 = *(int **)(param_1->ExceptionInformation[2] + 0xc);
            for (local_c = *piVar6; 0 < local_c; local_c = local_c + -1) {
              piVar6 = piVar6 + 1;
              iVar5 = FUN_110082b1(pbVar1,(byte *)*piVar6,(uint *)param_1->ExceptionInformation[2]);
              if (iVar5 != 0) {
                FUN_110083c2(param_1,param_2,param_3,param_4,param_5,pbVar1,(byte *)*piVar6,piVar4,
                             param_7,param_8);
                goto LAB_110081b9;
              }
            }
            pbVar1 = pbVar1 + 0x10;
          }
LAB_110081b9:
          iVar5 = local_14;
        }
        local_8 = local_8 + 1;
        piVar4 = piVar4 + 5;
      } while( true );
    }
  }
LAB_110081dc:
  if (param_6 == '\0') {
    FUN_11008207(param_1,param_2,param_3,param_4,param_5,local_14,param_7,param_8);
    return;
  }
  FUN_110089a8();
  return;
}


// ---- 11008207 FUN_11008207  (called by: FUN_11008054@11008054)

void __cdecl
FUN_11008207(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,uint param_5,
            int param_6,int param_7,PVOID param_8)

{
  DWORD *pDVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint local_c;
  uint local_8;
  
  pDVar1 = FUN_110088a1();
  if ((pDVar1[0x1a] != 0) &&
     (iVar2 = FUN_1100577f(&param_1->ExceptionCode,param_2,param_3,param_4,param_5,param_7,param_8),
     iVar2 != 0)) {
    return;
  }
  piVar3 = (int *)FUN_110058aa(param_5,param_7,param_6,&local_8,&local_c);
  for (; local_8 < local_c; local_8 = local_8 + 1) {
    if ((*piVar3 <= param_6) && (param_6 <= piVar3[1])) {
      iVar4 = piVar3[3] * 0x10 + piVar3[4];
      iVar2 = *(int *)(iVar4 + -0xc);
      if ((iVar2 == 0) || (*(char *)(iVar2 + 8) == '\0')) {
        FUN_110083c2(param_1,param_2,param_3,param_4,param_5,(byte *)(iVar4 + -0x10),(byte *)0x0,
                     piVar3,param_7,param_8);
      }
    }
    piVar3 = piVar3 + 5;
  }
  return;
}


// ---- 110082b1 FUN_110082b1  (called by: FUN_11008054@11008054)

undefined4 __cdecl FUN_110082b1(byte *param_1,byte *param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || (*(char *)(iVar1 + 8) == '\0')) {
LAB_11008308:
    uVar2 = 1;
  }
  else {
    if (iVar1 == *(int *)(param_2 + 4)) {
LAB_110082e2:
      if (((((*param_2 & 2) == 0) || ((*param_1 & 8) != 0)) &&
          (((*param_3 & 1) == 0 || ((*param_1 & 1) != 0)))) &&
         (((*param_3 & 2) == 0 || ((*param_1 & 2) != 0)))) goto LAB_11008308;
    }
    else {
      iVar1 = _strcmp((char *)(iVar1 + 8),(char *)(*(int *)(param_2 + 4) + 8));
      if (iVar1 == 0) goto LAB_110082e2;
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ---- 1100830e FUN_1100830e  (called by: FUN_11007fb9@11007fb9, FUN_110083c2@110083c2)

void __cdecl FUN_1100830e(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_1100c398;
  pcStack_10 = FUN_1100a2ec;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  for (iVar2 = *(int *)(param_1 + 8); local_8 = 0xffffffff, iVar2 != param_4;
      iVar2 = *(int *)(*(int *)(param_3 + 8) + iVar2 * 8)) {
    if ((iVar2 < 0) || (*(int *)(param_3 + 4) <= iVar2)) {
      FUN_11008a09();
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


// ---- 110083ac FUN_110083ac  (called by: -)

undefined4 __cdecl FUN_110083ac(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (*(int *)*param_1 == -0x1f928c9d) {
    uVar1 = FUN_110089a8();
    return uVar1;
  }
  return 0;
}


// ---- 110083c2 FUN_110083c2  (called by: FUN_11008054@11008054, FUN_11008207@11008207)

void __cdecl
FUN_110083c2(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int param_5,
            byte *param_6,byte *param_7,int *param_8,int param_9,PVOID param_10)

{
  undefined *UNRECOVERED_JUMPTABLE;
  
  if (param_7 != (byte *)0x0) {
    FUN_11008582((int)param_1,(int)param_2,param_6,param_7);
  }
  if (param_10 == (PVOID)0x0) {
    param_10 = param_2;
  }
  else {
  }
  FUN_11005681(param_10,param_1);
  FUN_1100830e((int)param_2,param_4,param_5,*param_8);
  *(int *)((int)param_2 + 8) = param_8[1] + 1;
  UNRECOVERED_JUMPTABLE =
       (undefined *)
       FUN_1100843d((DWORD)param_1,param_2,param_3,param_5,*(undefined4 *)(param_6 + 0xc),param_9,
                    0x100);
  if (UNRECOVERED_JUMPTABLE != (undefined *)0x0) {
    FUN_1100563f(UNRECOVERED_JUMPTABLE);
  }
  return;
}


// ---- 1100843d FUN_1100843d  (called by: FUN_110083c2@110083c2)

undefined4 __cdecl
FUN_1100843d(DWORD param_1,undefined4 param_2,DWORD param_3,undefined4 param_4,undefined4 param_5,
            int param_6,int param_7)

{
  DWORD *pDVar1;
  undefined4 uVar2;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_1100c3a8;
  pcStack_10 = FUN_1100a2ec;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_110088a1();
  FUN_110088a1();
  pDVar1 = FUN_110088a1();
  pDVar1[0x1b] = param_1;
  pDVar1 = FUN_110088a1();
  pDVar1[0x1c] = param_3;
  local_8 = 1;
  uVar2 = FUN_11005706(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_1100850a();
  ExceptionList = local_14;
  return uVar2;
}


// ---- 1100850a FUN_1100850a  (called by: FUN_1100843d@1100843d)

void FUN_1100850a(void)

{
  DWORD *pDVar1;
  int unaff_EBP;
  int unaff_ESI;
  int *unaff_EDI;
  
  *(undefined4 *)(unaff_ESI + -4) = *(undefined4 *)(unaff_EBP + -0x28);
  pDVar1 = FUN_110088a1();
  pDVar1[0x1b] = *(DWORD *)(unaff_EBP + -0x1c);
  pDVar1 = FUN_110088a1();
  pDVar1[0x1c] = *(DWORD *)(unaff_EBP + -0x20);
  if ((((*unaff_EDI == -0x1f928c9d) && (unaff_EDI[4] == 3)) && (unaff_EDI[5] == 0x19930520)) &&
     ((*(int *)(unaff_EBP + -0x24) == 0 && (*(int *)(unaff_EBP + -0x2c) != 0)))) {
    __abnormal_termination();
    FUN_11008746((int)unaff_EDI);
  }
  return;
}


// ---- 11008558 FUN_11008558  (called by: -)

undefined4 __cdecl FUN_11008558(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if ((((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) &&
     (piVar1[7] == 0)) {
    return 1;
  }
  return 0;
}


// ---- 11008582 FUN_11008582  (called by: FUN_110083c2@110083c2)

void __cdecl FUN_11008582(int param_1,int param_2,byte *param_3,byte *param_4)

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
  
  puStack_c = &DAT_1100c3c0;
  pcStack_10 = FUN_1100a2ec;
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
        bVar2 = FUN_1100a204(*(void **)(param_1 + 0x18),1);
        if ((CONCAT31(extraout_var_03,bVar2) != 0) &&
           (bVar2 = FUN_1100a220(piVar1,1), CONCAT31(extraout_var_04,bVar2) != 0)) {
          uVar5 = *(uint *)(param_4 + 0x14);
          puVar4 = (undefined4 *)FUN_110087ad(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
          FUN_11009740(piVar1,puVar4,uVar5);
          ExceptionList = local_14;
          return;
        }
      }
      else {
        ExceptionList = &local_14;
        bVar2 = FUN_1100a204(*(void **)(param_1 + 0x18),1);
        if (((CONCAT31(extraout_var_05,bVar2) != 0) &&
            (bVar2 = FUN_1100a220(piVar1,1), CONCAT31(extraout_var_06,bVar2) != 0)) &&
           (bVar2 = FUN_1100a23c(*(FARPROC *)(param_4 + 0x18)), CONCAT31(extraout_var_07,bVar2) != 0
           )) {
          if ((*param_4 & 4) == 0) {
            FUN_110087ad(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
            FUN_11005673(piVar1,*(undefined **)(param_4 + 0x18));
            ExceptionList = local_14;
            return;
          }
          FUN_110087ad(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
          FUN_1100567a(piVar1,*(undefined **)(param_4 + 0x18));
          ExceptionList = local_14;
          return;
        }
      }
    }
    else {
      ExceptionList = &local_14;
      bVar2 = FUN_1100a204(*(void **)(param_1 + 0x18),1);
      if ((CONCAT31(extraout_var_01,bVar2) != 0) &&
         (bVar2 = FUN_1100a220(piVar1,1), CONCAT31(extraout_var_02,bVar2) != 0)) {
        FUN_11009740(piVar1,*(undefined4 **)(param_1 + 0x18),*(uint *)(param_4 + 0x14));
        if (*(int *)(param_4 + 0x14) != 4) {
          ExceptionList = local_14;
          return;
        }
        iVar3 = *piVar1;
        if (iVar3 == 0) {
          ExceptionList = local_14;
          return;
        }
        goto LAB_11008610;
      }
    }
  }
  else {
    ExceptionList = &local_14;
    bVar2 = FUN_1100a204(*(void **)(param_1 + 0x18),1);
    if ((CONCAT31(extraout_var,bVar2) != 0) &&
       (bVar2 = FUN_1100a220(piVar1,1), CONCAT31(extraout_var_00,bVar2) != 0)) {
      iVar3 = *(int *)(param_1 + 0x18);
      *piVar1 = iVar3;
LAB_11008610:
      iVar3 = FUN_110087ad(iVar3,(int *)(param_4 + 8));
      *piVar1 = iVar3;
      ExceptionList = local_14;
      return;
    }
  }
  FUN_11008a09();
  ExceptionList = local_14;
  return;
}


// ---- 11008746 FUN_11008746  (called by: FUN_11008054@11008054, FUN_1100850a@1100850a)

void __cdecl FUN_11008746(int param_1)

{
  undefined *UNRECOVERED_JUMPTABLE;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_1100c3d0;
  pcStack_10 = FUN_1100a2ec;
  local_14 = ExceptionList;
  if ((param_1 != 0) &&
     (UNRECOVERED_JUMPTABLE = *(undefined **)(*(int *)(param_1 + 0x1c) + 4),
     UNRECOVERED_JUMPTABLE != (undefined *)0x0)) {
    local_8 = 0;
    ExceptionList = &local_14;
    FUN_11005673(*(undefined4 *)(param_1 + 0x18),UNRECOVERED_JUMPTABLE);
  }
  ExceptionList = local_14;
  return;
}


// ---- 110087ad FUN_110087ad  (called by: FUN_11008582@11008582)

int __cdecl FUN_110087ad(int param_1,int *param_2)

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


// ---- 110087d0 __CallSettingFrame@12  (called by: FUN_11005706@11005706, FUN_1100830e@1100830e)

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


// ---- 1100881c FUN_1100881c  (called by: FUN_11005f8b@11005f8b)

undefined4 FUN_1100881c(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  FUN_110067c4();
  DAT_1100fbb0 = TlsAlloc();
  if (DAT_1100fbb0 != 0xffffffff) {
    lpTlsValue = (DWORD *)FUN_11009a75(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_1100fbb0,lpTlsValue);
      if (BVar1 != 0) {
        FUN_1100888e((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        return 1;
      }
    }
  }
  return 0;
}


// ---- 11008870 FUN_11008870  (called by: FUN_11005f8b@11005f8b)

void FUN_11008870(void)

{
  FUN_110067ed();
  if (DAT_1100fbb0 != 0xffffffff) {
    TlsFree(DAT_1100fbb0);
    DAT_1100fbb0 = 0xffffffff;
  }
  return;
}


// ---- 1100888e FUN_1100888e  (called by: FUN_1100881c@1100881c, FUN_110088a1@110088a1)

void __cdecl FUN_1100888e(int param_1)

{
  *(undefined **)(param_1 + 0x50) = &DAT_1100fd50;
  *(undefined4 *)(param_1 + 0x14) = 1;
  return;
}


// ---- 110088a1 FUN_110088a1  (called by: FUN_1100577f@1100577f, FUN_110076ec@110076ec, FUN_110076f5@110076f5, FUN_11008054@11008054, FUN_11008207@11008207, FUN_1100843d@1100843d, FUN_1100850a@1100850a, FUN_110089a8@110089a8, FUN_1100ab0c@1100ab0c)

DWORD * FUN_110088a1(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(DAT_1100fbb0);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = (DWORD *)FUN_11009a75(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_1100fbb0,lpTlsValue);
      if (BVar1 != 0) {
        FUN_1100888e((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        goto LAB_110088fc;
      }
    }
    __amsg_exit(0x10);
  }
LAB_110088fc:
  SetLastError(dwErrCode);
  return lpTlsValue;
}


// ---- 11008908 FUN_11008908  (called by: FUN_11005f8b@11005f8b)

void __cdecl FUN_11008908(LPVOID param_1)

{
  if (DAT_1100fbb0 == 0xffffffff) {
    return;
  }
  if ((param_1 != (LPVOID)0x0) || (param_1 = TlsGetValue(DAT_1100fbb0), param_1 != (LPVOID)0x0)) {
    if (*(LPVOID *)((int)param_1 + 0x24) != (LPVOID)0x0) {
      FUN_11005028(*(LPVOID *)((int)param_1 + 0x24));
    }
    if (*(LPVOID *)((int)param_1 + 0x28) != (LPVOID)0x0) {
      FUN_11005028(*(LPVOID *)((int)param_1 + 0x28));
    }
    if (*(LPVOID *)((int)param_1 + 0x30) != (LPVOID)0x0) {
      FUN_11005028(*(LPVOID *)((int)param_1 + 0x30));
    }
    if (*(LPVOID *)((int)param_1 + 0x38) != (LPVOID)0x0) {
      FUN_11005028(*(LPVOID *)((int)param_1 + 0x38));
    }
    if (*(LPVOID *)((int)param_1 + 0x40) != (LPVOID)0x0) {
      FUN_11005028(*(LPVOID *)((int)param_1 + 0x40));
    }
    if (*(LPVOID *)((int)param_1 + 0x44) != (LPVOID)0x0) {
      FUN_11005028(*(LPVOID *)((int)param_1 + 0x44));
    }
    if (*(undefined **)((int)param_1 + 0x50) != &DAT_1100fd50) {
      FUN_11005028(*(undefined **)((int)param_1 + 0x50));
    }
    FUN_11005028(param_1);
  }
  TlsSetValue(DAT_1100fbb0,(LPVOID)0x0);
  return;
}


// ---- 110089a8 FUN_110089a8  (called by: FUN_11008054@11008054, FUN_110083ac@110083ac, FUN_11008a09@11008a09, FUN_1100a1a0@1100a1a0)

void FUN_110089a8(void)

{
  DWORD *pDVar1;
  void *pvStack_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_1100c3e0;
  pcStack_10 = FUN_1100a2ec;
  pvStack_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_14;
  pDVar1 = FUN_110088a1();
  if (pDVar1[0x18] != 0) {
    local_8 = 1;
    pDVar1 = FUN_110088a1();
    (*(code *)pDVar1[0x18])();
  }
  local_8 = 0xffffffff;
  FUN_1100a3c4();
  return;
}


// ---- 11008a09 FUN_11008a09  (called by: FUN_110058aa@110058aa, FUN_11007fb9@11007fb9, FUN_11008054@11008054, FUN_1100830e@1100830e, FUN_11008582@11008582)

void FUN_11008a09(void)

{
  void *pvStack_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_1100c3f8;
  pcStack_10 = FUN_1100a2ec;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (PTR_FUN_1100fbb4 != (undefined *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*(code *)PTR_FUN_1100fbb4)();
  }
  local_8 = 0xffffffff;
  FUN_110089a8();
  return;
}


// ---- 11008a5f FUN_11008a5f  (called by: FUN_11005a37@11005a37)

SIZE_T __cdecl FUN_11008a5f(LPCVOID param_1)

{
  uint uVar1;
  SIZE_T SVar2;
  
  FUN_11006859(9);
  uVar1 = FUN_1100690d((int)param_1);
  if (uVar1 == 0) {
    FUN_110068ba(9);
    SVar2 = HeapSize(DAT_11011bbc,0,param_1);
  }
  else {
    SVar2 = *(int *)((int)param_1 + -4) - 9;
    FUN_110068ba(9);
  }
  return SVar2;
}


// ---- 11008aa4 FUN_11008aa4  (called by: FUN_11009ed1@11009ed1)

int __cdecl FUN_11008aa4(uint param_1,char *param_2,char *param_3)

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
    piVar1 = &DAT_11010a80 + ((int)param_1 >> 5);
    iVar9 = (param_1 & 0x1f) * 0x24;
    bVar4 = *(byte *)((&DAT_11010a80)[(int)param_1 >> 5] + iVar9 + 4);
    if ((bVar4 & 2) == 0) {
      pcVar8 = param_2;
      if (((bVar4 & 0x48) != 0) &&
         (cVar3 = *(char *)((&DAT_11010a80)[(int)param_1 >> 5] + iVar9 + 5), cVar3 != '\n')) {
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
          pDVar7 = FUN_110076ec();
          *pDVar7 = 9;
          pDVar7 = FUN_110076f5();
          *pDVar7 = 5;
        }
        else {
          if (DVar6 == 0x6d) {
            return 0;
          }
          FUN_11007679(DVar6);
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
                  goto LAB_11008c2f;
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
LAB_11008c49:
                  *pcVar8 = '\r';
LAB_11008c4c:
                  pcVar8 = pcVar8 + 1;
                }
                else if ((*(byte *)(*piVar1 + 4 + iVar9) & 0x48) == 0) {
                  if ((pcVar8 == param_2) && (local_5 == '\n')) {
LAB_11008c2f:
                    *pcVar8 = '\n';
                    goto LAB_11008c4c;
                  }
                  FUN_11007763(param_1,-1,1);
                  if (local_5 != '\n') goto LAB_11008c49;
                }
                else {
                  if (local_5 == '\n') goto LAB_11008c2f;
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


// ---- 11008c7d FUN_11008c7d  (called by: FUN_11005d30@11005d30)

byte * __cdecl FUN_11008c7d(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  
  if (param_1 < param_2) {
    if (DAT_1101085c == 0) {
      pbVar1 = param_2 + -1;
    }
    else {
      FUN_11006859(0x19);
      pbVar1 = param_2 + -1;
      if ((*(byte *)((int)&DAT_11010960 + param_2[-1] + 1) & 4) == 0) {
        do {
          pbVar1 = pbVar1 + -1;
          if (pbVar1 < param_1) break;
        } while ((*(byte *)((int)&DAT_11010960 + *pbVar1 + 1) & 4) != 0);
        FUN_110068ba(0x19);
        pbVar1 = param_2 + (-1 - ((int)param_2 - (int)pbVar1 & 1U));
      }
      else {
        FUN_110068ba(0x19);
        pbVar1 = param_2 + -2;
      }
    }
  }
  else {
    pbVar1 = (byte *)0x0;
  }
  return pbVar1;
}


// ---- 11008cea FUN_11008cea  (called by: FUN_110090c2@110090c2)

undefined4 __cdecl FUN_11008cea(int param_1)

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
  
  FUN_11006859(0x19);
  CodePage = FUN_11008e97(param_1);
  if (CodePage != DAT_11010840) {
    if (CodePage != 0) {
      iVar12 = 0;
      pUVar5 = &DAT_1100fbc8;
LAB_11008d27:
      if (*pUVar5 != CodePage) goto code_r0x11008d2b;
      local_8 = 0;
      puVar15 = &DAT_11010960;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      iVar12 = iVar12 * 0x30;
      *(undefined1 *)puVar15 = 0;
      pbVar13 = (byte *)(iVar12 + 0x1100fbd8);
      do {
        bVar3 = *pbVar13;
        pbVar11 = pbVar13;
        while ((bVar3 != 0 && (bVar3 = pbVar11[1], bVar3 != 0))) {
          uVar8 = (uint)*pbVar11;
          if (uVar8 <= bVar3) {
            bVar4 = (&DAT_1100fbc0)[local_8];
            do {
              pbVar2 = (byte *)((int)&DAT_11010960 + uVar8 + 1);
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
      DAT_1101085c = 1;
      DAT_11010840 = CodePage;
      DAT_11010a64 = FUN_11008ee1(CodePage);
      DAT_11010850 = *(undefined4 *)(iVar12 + 0x1100fbcc);
      DAT_11010854 = *(undefined4 *)(iVar12 + 0x1100fbd0);
      DAT_11010858 = *(undefined4 *)(iVar12 + 0x1100fbd4);
      goto LAB_11008e7b;
    }
    goto LAB_11008e76;
  }
  goto LAB_11008d11;
code_r0x11008d2b:
  pUVar5 = pUVar5 + 0xc;
  iVar12 = iVar12 + 1;
  if (0x1100fcb7 < (int)pUVar5) goto code_r0x11008d36;
  goto LAB_11008d27;
code_r0x11008d36:
  BVar6 = GetCPInfo(CodePage,&local_1c);
  uVar8 = 1;
  if (BVar6 == 1) {
    DAT_11010a64 = 0;
    puVar15 = &DAT_11010960;
    for (iVar12 = 0x40; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar15 = 0;
      puVar15 = puVar15 + 1;
    }
    *(undefined1 *)puVar15 = 0;
    if (local_1c.MaxCharSize < 2) {
      DAT_1101085c = 0;
      DAT_11010840 = CodePage;
    }
    else {
      DAT_11010840 = CodePage;
      if (local_1c.LeadByte[0] != '\0') {
        pBVar9 = local_1c.LeadByte + 1;
        do {
          bVar3 = *pBVar9;
          if (bVar3 == 0) break;
          for (uVar7 = (uint)pBVar9[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
            pbVar13 = (byte *)((int)&DAT_11010960 + uVar7 + 1);
            *pbVar13 = *pbVar13 | 4;
          }
          pBVar1 = pBVar9 + 1;
          pBVar9 = pBVar9 + 2;
        } while (*pBVar1 != 0);
      }
      do {
        pbVar13 = (byte *)((int)&DAT_11010960 + uVar8 + 1);
        *pbVar13 = *pbVar13 | 8;
        uVar8 = uVar8 + 1;
      } while (uVar8 < 0xff);
      DAT_11010a64 = FUN_11008ee1(CodePage);
      DAT_1101085c = 1;
    }
    DAT_11010850 = 0;
    DAT_11010854 = 0;
    DAT_11010858 = 0;
  }
  else {
    if (DAT_1101058c == 0) {
      uVar14 = 0xffffffff;
      goto LAB_11008e88;
    }
LAB_11008e76:
    FUN_11008f14();
  }
LAB_11008e7b:
  FUN_11008f3d();
LAB_11008d11:
  uVar14 = 0;
LAB_11008e88:
  FUN_110068ba(0x19);
  return uVar14;
}


// ---- 11008e97 FUN_11008e97  (called by: FUN_11008cea@11008cea)

int __cdecl FUN_11008e97(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_1101058c = 1;
                    /* WARNING: Could not recover jumptable at 0x11008eb1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_1101058c = 1;
                    /* WARNING: Could not recover jumptable at 0x11008ec6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_110106bc;
  }
  DAT_1101058c = (uint)bVar2;
  return param_1;
}


// ---- 11008ee1 FUN_11008ee1  (called by: FUN_11008cea@11008cea)

undefined4 __cdecl FUN_11008ee1(int param_1)

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


// ---- 11008f14 FUN_11008f14  (called by: FUN_11008cea@11008cea)

void FUN_11008f14(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_11010960;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_11010840 = 0;
  DAT_1101085c = 0;
  DAT_11010a64 = 0;
  DAT_11010850 = 0;
  DAT_11010854 = 0;
  DAT_11010858 = 0;
  return;
}


// ---- 11008f3d FUN_11008f3d  (called by: FUN_11008cea@11008cea)

void FUN_11008f3d(void)

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
  
  BVar2 = GetCPInfo(DAT_11010840,&local_18);
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
    FUN_1100a714(1,local_118,0x100,local_518,DAT_11010840,DAT_11010a64,0);
    FUN_1100a4c5(DAT_11010a64,0x100,local_118,0x100,local_218,0x100,DAT_11010840,0);
    FUN_1100a4c5(DAT_11010a64,0x200,local_118,0x100,local_318,0x100,DAT_11010840,0);
    uVar3 = 0;
    puVar7 = local_518;
    do {
      if ((*puVar7 & 1) == 0) {
        if ((*puVar7 & 2) != 0) {
          pbVar1 = (byte *)((int)&DAT_11010960 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          uVar8 = *(undefined1 *)((int)local_318 + uVar3);
          goto LAB_11009049;
        }
        (&DAT_11010860)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_11010960 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        uVar8 = *(undefined1 *)((int)local_218 + uVar3);
LAB_11009049:
        (&DAT_11010860)[uVar3] = uVar8;
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
          pbVar1 = (byte *)((int)&DAT_11010960 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          cVar4 = (char)uVar3 + -0x20;
          goto LAB_11009093;
        }
        (&DAT_11010860)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_11010960 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        cVar4 = (char)uVar3 + ' ';
LAB_11009093:
        (&DAT_11010860)[uVar3] = cVar4;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
  }
  return;
}


// ---- 110090c2 FUN_110090c2  (called by: FUN_11009178@11009178, FUN_11009231@11009231)

void FUN_110090c2(void)

{
  if (DAT_11011bc4 == 0) {
    FUN_11008cea(-3);
    DAT_11011bc4 = 1;
  }
  return;
}


// ---- 110090de FUN_110090de  (called by: FUN_11005dc1@11005dc1)

byte * __cdecl FUN_110090de(byte *param_1,byte *param_2,size_t param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  if (DAT_1101085c == 0) {
    param_1 = (byte *)_strncpy((char *)param_1,(char *)param_2,param_3);
  }
  else {
    FUN_11006859(0x19);
    uVar4 = 0;
    pbVar6 = param_1;
    if (param_3 != 0) {
      pbVar5 = param_1;
      do {
        bVar1 = *param_2;
        uVar4 = param_3 - 1;
        bVar2 = *(byte *)((int)&DAT_11010960 + bVar1 + 1);
        *pbVar5 = bVar1;
        if ((bVar2 & 4) == 0) {
          pbVar6 = pbVar5 + 1;
          param_2 = param_2 + 1;
          if (bVar1 == 0) goto LAB_1100914f;
        }
        else {
          pbVar6 = pbVar5 + 1;
          if (uVar4 == 0) {
            *pbVar5 = 0;
            goto LAB_1100914f;
          }
          bVar1 = param_2[1];
          uVar4 = param_3 - 2;
          *pbVar6 = bVar1;
          pbVar6 = pbVar5 + 2;
          param_2 = param_2 + 2;
          if (bVar1 == 0) {
            *pbVar5 = 0;
            goto LAB_1100914f;
          }
        }
        param_3 = uVar4;
        pbVar5 = pbVar6;
      } while (uVar4 != 0);
      uVar4 = 0;
    }
LAB_1100914f:
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
    FUN_110068ba(0x19);
  }
  return param_1;
}


// ---- 11009178 FUN_11009178  (called by: FUN_11005f8b@11005f8b)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_11009178(void)

{
  char cVar1;
  size_t sVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  uint *puVar6;
  
  if (DAT_11011bc4 == 0) {
    FUN_110090c2();
  }
  iVar5 = 0;
  for (puVar6 = DAT_110104cc; (char)*puVar6 != '\0'; puVar6 = (uint *)((int)puVar6 + sVar2 + 1)) {
    if ((char)*puVar6 != '=') {
      iVar5 = iVar5 + 1;
    }
    sVar2 = _strlen((char *)puVar6);
  }
  puVar3 = _malloc(iVar5 * 4 + 4);
  _DAT_110104fc = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = (char)*DAT_110104cc;
  puVar6 = DAT_110104cc;
  while (cVar1 != '\0') {
    sVar2 = _strlen((char *)puVar6);
    if ((char)*puVar6 != '=') {
      pvVar4 = _malloc(sVar2 + 1);
      *puVar3 = pvVar4;
      if (pvVar4 == (void *)0x0) {
        __amsg_exit(9);
      }
      FUN_11005c40((uint *)*puVar3,puVar6);
      puVar3 = puVar3 + 1;
    }
    puVar6 = (uint *)((int)puVar6 + sVar2 + 1);
    cVar1 = (char)*puVar6;
  }
  FUN_11005028(DAT_110104cc);
  DAT_110104cc = (uint *)0x0;
  *puVar3 = 0;
  _DAT_11011bc0 = 1;
  return;
}


// ---- 11009231 FUN_11009231  (called by: FUN_11005f8b@11005f8b)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_11009231(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_c;
  int local_8;
  
  if (DAT_11011bc4 == 0) {
    FUN_110090c2();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_11010590,0x104);
  _DAT_1101050c = &DAT_11010590;
  pbVar2 = &DAT_11010590;
  if (*DAT_11011bd4 != 0) {
    pbVar2 = DAT_11011bd4;
  }
  FUN_110092ca(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_c);
  puVar1 = _malloc(local_c + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_110092ca(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_c);
  _DAT_110104f4 = puVar1;
  _DAT_110104f0 = local_8 + -1;
  return;
}


// ---- 110092ca FUN_110092ca  (called by: FUN_11009231@11009231)

void __cdecl FUN_110092ca(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

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
      if (((*(byte *)((int)&DAT_11010960 + bVar1 + 1) & 4) != 0) &&
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
      if ((*(byte *)((int)&DAT_11010960 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar4;
          param_3 = param_3 + 1;
        }
        pbVar4 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_11009375;
      param_1 = pbVar4;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_11009375:
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
          if ((*(byte *)((int)&DAT_11010960 + bVar1 + 1) & 4) != 0) {
            pbVar4 = pbVar4 + 1;
            *param_5 = *param_5 + 1;
          }
        }
        else {
          if ((*(byte *)((int)&DAT_11010960 + bVar1 + 1) & 4) != 0) {
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


// ---- 1100947e FUN_1100947e  (called by: FUN_11005f8b@11005f8b)

LPSTR FUN_1100947e(void)

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
  if (DAT_11010694 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr != (LPWCH)0x0) {
      DAT_11010694 = 1;
      goto LAB_110094d5;
    }
    pCVar9 = GetEnvironmentStrings();
    if (pCVar9 == (LPCH)0x0) {
      return (LPSTR)0x0;
    }
    DAT_11010694 = 2;
  }
  else {
    if (DAT_11010694 == 1) {
LAB_110094d5:
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
          FUN_11005028(pCVar6);
          local_8 = (LPSTR)0x0;
        }
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return local_8;
    }
    if (DAT_11010694 != 2) {
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
    FUN_110062b0((undefined4 *)pCVar6,(undefined4 *)pCVar9,(uint)(pcVar7 + (1 - (int)pCVar9)));
  }
  FreeEnvironmentStringsA(pCVar9);
  return pCVar6;
}


// ---- 110095b0 FUN_110095b0  (called by: __amsg_exit@11006101)

void FUN_110095b0(void)

{
  if ((DAT_110104d4 == 1) || ((DAT_110104d4 == 0 && (DAT_110104d8 == 1)))) {
    FUN_110095e9(0xfc);
    if (DAT_11010698 != (code *)0x0) {
      (*DAT_11010698)();
    }
    FUN_110095e9(0xff);
  }
  return;
}


// ---- 110095e9 FUN_110095e9  (called by: FUN_110095b0@110095b0, FUN_1100a3c4@1100a3c4, __amsg_exit@11006101)

void __cdecl FUN_110095e9(DWORD param_1)

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
  pDVar2 = &DAT_1100fcb8;
  do {
    if (param_1 == *pDVar2) break;
    pDVar2 = pDVar2 + 2;
    iVar5 = iVar5 + 1;
  } while ((int)pDVar2 < 0x1100fd48);
  if (param_1 == (&DAT_1100fcb8)[iVar5 * 2]) {
    if ((DAT_110104d4 == 1) || ((DAT_110104d4 == 0 && (DAT_110104d8 == 1)))) {
      pDVar2 = &param_1;
      puVar1 = (undefined4 *)(iVar5 * 8 + 0x1100fcbc);
      lpOverlapped = (LPOVERLAPPED)0x0;
      sVar4 = _strlen((char *)*puVar1);
      lpBuffer = (LPCVOID)*puVar1;
      hFile = GetStdHandle(0xfffffff4);
      WriteFile(hFile,lpBuffer,sVar4,pDVar2,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_1a8,0x104);
      if (DVar3 == 0) {
        FUN_11005c40(local_1a8,(uint *)"<program name unknown>");
      }
      _Dest = local_1a8;
      sVar4 = _strlen((char *)local_1a8);
      if (0x3c < sVar4 + 1) {
        sVar4 = _strlen((char *)local_1a8);
        _Dest = (uint *)(auStackY_1e3 + sVar4);
        _strncpy((char *)_Dest,"...",3);
      }
      FUN_11005c40(local_a4,(uint *)"Runtime Error!\n\nProgram: ");
      FUN_11005c50(local_a4,_Dest);
      FUN_11005c50(local_a4,(uint *)&DAT_1100c738);
      FUN_11005c50(local_a4,*(uint **)(iVar5 * 8 + 0x1100fcbc));
      auStackY_1e3._3_4_ = 0x1100970d;
      FUN_1100a95e(local_a4,"Microsoft Visual C++ Runtime Library",0x12010);
    }
  }
  return;
}


// ---- 11009740 FUN_11009740  (called by: FUN_11006938@11006938, FUN_11008582@11008582)

undefined4 * __cdecl FUN_11009740(undefined4 *param_1,undefined4 *param_2,uint param_3)

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
          goto switchD_110098f7_caseD_2;
        case 3:
          goto switchD_110098f7_caseD_3;
        }
        goto switchD_110098f7_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_110098f7_caseD_0;
      case 1:
        goto switchD_110098f7_caseD_1;
      case 2:
        goto switchD_110098f7_caseD_2;
      case 3:
        goto switchD_110098f7_caseD_3;
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
              goto switchD_110098f7_caseD_2;
            case 3:
              goto switchD_110098f7_caseD_3;
            }
            goto switchD_110098f7_caseD_1;
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
              goto switchD_110098f7_caseD_2;
            case 3:
              goto switchD_110098f7_caseD_3;
            }
            goto switchD_110098f7_caseD_1;
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
              goto switchD_110098f7_caseD_2;
            case 3:
              goto switchD_110098f7_caseD_3;
            }
            goto switchD_110098f7_caseD_1;
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
switchD_110098f7_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_110098f7_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_110098f7_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_110098f7_caseD_0:
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
        goto switchD_11009775_caseD_2;
      case 3:
        goto switchD_11009775_caseD_3;
      }
      goto switchD_11009775_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_11009775_caseD_0;
    case 1:
      goto switchD_11009775_caseD_1;
    case 2:
      goto switchD_11009775_caseD_2;
    case 3:
      goto switchD_11009775_caseD_3;
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
            goto switchD_11009775_caseD_2;
          case 3:
            goto switchD_11009775_caseD_3;
          }
          goto switchD_11009775_caseD_1;
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
            goto switchD_11009775_caseD_2;
          case 3:
            goto switchD_11009775_caseD_3;
          }
          goto switchD_11009775_caseD_1;
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
            goto switchD_11009775_caseD_2;
          case 3:
            goto switchD_11009775_caseD_3;
          }
          goto switchD_11009775_caseD_1;
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
switchD_11009775_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_11009775_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_11009775_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_11009775_caseD_0:
  return param_1;
}


// ---- 11009a75 FUN_11009a75  (called by: FUN_1100881c@1100881c, FUN_110088a1@110088a1)

int * __cdecl FUN_11009a75(int param_1,int param_2)

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
      if (_Size <= DAT_1100f794) {
        FUN_11006859(9);
        piVar1 = FUN_11006c63(_Size);
        FUN_110068ba(9);
        if (piVar1 != (int *)0x0) {
          _memset(piVar1,0,(size_t)_Size);
          return piVar1;
        }
      }
      piVar1 = HeapAlloc(DAT_11011bbc,8,(SIZE_T)puVar3);
      if (piVar1 != (int *)0x0) {
        return piVar1;
      }
    }
    if (DAT_11010520 == 0) {
      return (int *)0x0;
    }
    iVar2 = FUN_110066f8(puVar3);
  } while (iVar2 != 0);
  return (int *)0x0;
}


// ---- 11009b83 FUN_11009b83  (called by: FUN_11009ed1@11009ed1)

uint FUN_11009b83(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  int local_8;
  int local_4;
  
  uVar4 = 0xffffffff;
  FUN_11006859(0x12);
  local_8 = 0;
  local_4 = 0;
  piVar3 = &DAT_11010a80;
  while (puVar2 = (undefined4 *)*piVar3, puVar1 = puVar2, puVar2 != (undefined4 *)0x0) {
    for (; puVar2 < puVar1 + 0x120; puVar2 = puVar2 + 9) {
      if ((*(byte *)(puVar2 + 1) & 1) == 0) {
        if (puVar2[2] == 0) {
          FUN_11006859(0x11);
          if (puVar2[2] == 0) {
            InitializeCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
            puVar2[2] = puVar2[2] + 1;
          }
          FUN_110068ba(0x11);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
        if ((*(byte *)(puVar2 + 1) & 1) == 0) {
          *puVar2 = 0xffffffff;
          uVar4 = ((int)puVar2 - *piVar3) / 0x24 + local_4;
          if (uVar4 != 0xffffffff) goto LAB_11009c95;
          break;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
      }
      puVar1 = (undefined4 *)*piVar3;
    }
    local_4 = local_4 + 0x20;
    piVar3 = piVar3 + 1;
    local_8 = local_8 + 1;
    if (0x11010b7f < (int)piVar3) goto LAB_11009c95;
  }
  puVar2 = _malloc(0x480);
  if (puVar2 != (undefined4 *)0x0) {
    DAT_11010b80 = DAT_11010b80 + 0x20;
    (&DAT_11010a80)[local_8] = puVar2;
    puVar1 = puVar2;
    for (; puVar2 < puVar1 + 0x120; puVar2 = puVar2 + 9) {
      *(undefined1 *)(puVar2 + 1) = 0;
      *puVar2 = 0xffffffff;
      puVar2[2] = 0;
      *(undefined1 *)((int)puVar2 + 5) = 10;
      puVar1 = (undefined4 *)(&DAT_11010a80)[local_8];
    }
    uVar4 = local_8 << 5;
    FUN_11009de3(uVar4);
  }
LAB_11009c95:
  FUN_110068ba(0x12);
  return uVar4;
}


// ---- 11009ca6 FUN_11009ca6  (called by: FUN_11009ed1@11009ed1)

undefined4 __cdecl FUN_11009ca6(uint param_1,HANDLE param_2)

{
  DWORD *pDVar1;
  int iVar2;
  DWORD nStdHandle;
  
  if (param_1 < DAT_11010b80) {
    iVar2 = (param_1 & 0x1f) * 0x24;
    if (*(int *)((&DAT_11010a80)[(int)param_1 >> 5] + iVar2) == -1) {
      if (DAT_110104d8 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_11009cff;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,param_2);
      }
LAB_11009cff:
      *(HANDLE *)((&DAT_11010a80)[(int)param_1 >> 5] + iVar2) = param_2;
      return 0;
    }
  }
  pDVar1 = FUN_110076ec();
  *pDVar1 = 9;
  pDVar1 = FUN_110076f5();
  *pDVar1 = 0;
  return 0xffffffff;
}


// ---- 11009d22 FUN_11009d22  (called by: FUN_110075cb@110075cb)

undefined4 __cdecl FUN_11009d22(uint param_1)

{
  int *piVar1;
  DWORD *pDVar2;
  int iVar3;
  DWORD nStdHandle;
  
  if (param_1 < DAT_11010b80) {
    iVar3 = (param_1 & 0x1f) * 0x24;
    piVar1 = (int *)((&DAT_11010a80)[(int)param_1 >> 5] + iVar3);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_110104d8 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_11009d7e;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_11009d7e:
      *(undefined4 *)((&DAT_11010a80)[(int)param_1 >> 5] + iVar3) = 0xffffffff;
      return 0;
    }
  }
  pDVar2 = FUN_110076ec();
  *pDVar2 = 9;
  pDVar2 = FUN_110076f5();
  *pDVar2 = 0;
  return 0xffffffff;
}


// ---- 11009da1 FUN_11009da1  (called by: FUN_110075cb@110075cb, FUN_11007763@11007763, FUN_110079e6@110079e6, FUN_1100a9e7@1100a9e7)

undefined4 __cdecl FUN_11009da1(uint param_1)

{
  DWORD *pDVar1;
  
  if ((param_1 < DAT_11010b80) &&
     ((*(byte *)((&DAT_11010a80)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    return *(undefined4 *)((&DAT_11010a80)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24);
  }
  pDVar1 = FUN_110076ec();
  *pDVar1 = 9;
  pDVar1 = FUN_110076f5();
  *pDVar1 = 0;
  return 0xffffffff;
}


// ---- 11009de3 FUN_11009de3  (called by: FUN_1100756e@1100756e, FUN_110076fe@110076fe, FUN_110079e6@110079e6, FUN_11007a79@11007a79, FUN_11009b83@11009b83)

void __cdecl FUN_11009de3(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (param_1 & 0x1f) * 0x24;
  iVar1 = (&DAT_11010a80)[(int)param_1 >> 5] + iVar2;
  if (*(int *)(iVar1 + 8) == 0) {
    FUN_11006859(0x11);
    if (*(int *)(iVar1 + 8) == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xc));
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    }
    FUN_110068ba(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((&DAT_11010a80)[(int)param_1 >> 5] + 0xc + iVar2));
  return;
}


// ---- 11009e42 FUN_11009e42  (called by: FUN_1100756e@1100756e, FUN_110076fe@110076fe, FUN_110079e6@110079e6, FUN_11007a79@11007a79, FUN_11009ed1@11009ed1)

void __cdecl FUN_11009e42(uint param_1)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_11010a80)[(int)param_1 >> 5] + 0xc + (param_1 & 0x1f) * 0x24));
  return;
}


// ---- 11009e64 FUN_11009e64  (called by: FUN_11007c69@11007c69)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_11009e64(undefined4 *param_1)

{
  void *pvVar1;
  
  _DAT_11010588 = _DAT_11010588 + 1;
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


// ---- 11009ea8 FUN_11009ea8  (called by: FUN_11007c69@11007c69)

byte __cdecl FUN_11009ea8(uint param_1)

{
  if (param_1 < DAT_11010b80) {
    return *(byte *)((&DAT_11010a80)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0x40;
  }
  return 0;
}


// ---- 11009ed1 FUN_11009ed1  (called by: FUN_11007d81@11007d81)

uint __cdecl FUN_11009ed1(LPCSTR param_1,uint param_2,uint param_3,uint param_4)

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
  if (((param_2 & 0x8000) == 0) && (((param_2 & 0x4000) != 0 || (DAT_110106d8 != 0x8000)))) {
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
    if (uVar2 != 2) goto LAB_11009fd5;
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
    if (param_3 != 0x40) goto LAB_11009fd5;
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
      if (uVar2 == 0x200) goto LAB_11009fef;
      if (uVar2 != 0x300) goto LAB_11009fd5;
      local_c = 2;
    }
  }
  else {
    if (uVar2 != 0x500) {
      if (uVar2 == 0x600) {
LAB_11009fef:
        local_c = 5;
        goto LAB_11009fff;
      }
      if (uVar2 != 0x700) {
LAB_11009fd5:
        pDVar4 = FUN_110076ec();
        *pDVar4 = 0x16;
        pDVar4 = FUN_110076f5();
        *pDVar4 = 0;
        return 0xffffffff;
      }
    }
    local_c = 1;
  }
LAB_11009fff:
  uVar2 = 0x80;
  if (((param_2 & 0x100) != 0) && ((~DAT_110104dc & param_4 & 0x80) == 0)) {
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
  uVar3 = FUN_11009b83();
  if (uVar3 == 0xffffffff) {
    pDVar4 = FUN_110076ec();
    *pDVar4 = 0x18;
    pDVar4 = FUN_110076f5();
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
      FUN_11009ca6(uVar3,hFile);
      iVar7 = (uVar3 & 0x1f) * 0x24;
      param_1._3_1_ = local_5 & 0x48;
      *(byte *)((&DAT_11010a80)[(int)uVar3 >> 5] + 4 + iVar7) = local_5 | 1;
      if ((((local_5 & 0x48) == 0) && ((local_5 & 0x80) != 0)) && ((param_2 & 2) != 0)) {
        local_14 = FUN_11007763(uVar3,-1,2);
        if (local_14 == 0xffffffff) {
          pDVar4 = FUN_110076f5();
          if (*pDVar4 == 0x83) goto LAB_1100a179;
        }
        else {
          param_3 = param_3 & 0xffffff;
          iVar6 = FUN_11008aa4(uVar3,(char *)((int)&param_3 + 3),(char *)0x1);
          if ((((iVar6 != 0) || (param_3._3_1_ != '\x1a')) ||
              (iVar6 = FUN_1100a9e7(uVar3,local_14), iVar6 != -1)) &&
             (DVar5 = FUN_11007763(uVar3,0,0), DVar5 != 0xffffffff)) goto LAB_1100a179;
        }
        FUN_1100756e(uVar3);
        uVar2 = 0xffffffff;
      }
      else {
LAB_1100a179:
        if ((param_1._3_1_ == 0) && ((param_2 & 8) != 0)) {
          pbVar1 = (byte *)((&DAT_11010a80)[(int)uVar3 >> 5] + 4 + iVar7);
          *pbVar1 = *pbVar1 | 0x20;
        }
        uVar2 = uVar3;
      }
      goto LAB_1100a192;
    }
    CloseHandle(hFile);
  }
  DVar5 = GetLastError();
  FUN_11007679(DVar5);
  uVar2 = 0xffffffff;
LAB_1100a192:
  FUN_11009e42(uVar3);
  return uVar2;
}


// ---- 1100a1a0 FUN_1100a1a0  (called by: -)

int FUN_1100a1a0(int *param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    iVar3 = FUN_110089a8();
    return iVar3;
  }
  if ((DAT_110106a0 == (FARPROC)0x0) ||
     (bVar2 = FUN_1100a23c(DAT_110106a0), CONCAT31(extraout_var,bVar2) == 0)) {
    return 0;
  }
  iVar3 = (*DAT_110106a0)(param_1);
  return iVar3;
}


// ---- 1100a204 FUN_1100a204  (called by: FUN_11008054@11008054, FUN_11008582@11008582)

bool __cdecl FUN_1100a204(void *param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadReadPtr(param_1,param_2);
  return BVar1 == 0;
}


// ---- 1100a220 FUN_1100a220  (called by: FUN_11008582@11008582)

bool __cdecl FUN_1100a220(LPVOID param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadWritePtr(param_1,param_2);
  return BVar1 == 0;
}


// ---- 1100a23c FUN_1100a23c  (called by: FUN_11008582@11008582, FUN_1100a1a0@1100a1a0)

bool __cdecl FUN_1100a23c(FARPROC param_1)

{
  BOOL BVar1;
  
  BVar1 = IsBadCodePtr(param_1);
  return BVar1 == 0;
}


// ---- 1100a260 _strcmp  (called by: FUN_110082b1@110082b1)

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
      if (bVar3 != *_Str2) goto LAB_1100a2a4;
      _Str2 = _Str2 + 1;
      if (bVar3 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_1100a270;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar3 = (byte)uVar1;
    bVar4 = bVar3 < (byte)*_Str2;
    if (bVar3 != *_Str2) goto LAB_1100a2a4;
    if (bVar3 == 0) {
      return 0;
    }
    bVar3 = (byte)((ushort)uVar1 >> 8);
    bVar4 = bVar3 < (byte)_Str2[1];
    if (bVar3 != _Str2[1]) goto LAB_1100a2a4;
    if (bVar3 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_1100a270:
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
LAB_1100a2a4:
  return (uint)bVar4 * -2 + 1;
}


// ---- 1100a2ec FUN_1100a2ec  (called by: -)

undefined4 FUN_1100a2ec(int param_1,PVOID param_2,undefined4 param_3)

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
          FUN_110059fe();
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


// ---- 1100a3a9 FUN_1100a3a9  (called by: -)

void FUN_1100a3a9(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}


// ---- 1100a3c4 FUN_1100a3c4  (called by: FUN_110089a8@110089a8)

void FUN_1100a3c4(void)

{
  FUN_110095e9(10);
  FUN_1100ab0c((DWORD *)0x16);
                    /* WARNING: Subroutine does not return */
  __exit(3);
}


// ---- 1100a4c5 FUN_1100a4c5  (called by: FUN_11008f3d@11008f3d, FUN_1100b006@1100b006)

int __cdecl
FUN_1100a4c5(LCID param_1,DWORD param_2,char *param_3,int param_4,LPWSTR param_5,int param_6,
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
  puStack_c = &DAT_1100c780;
  pcStack_10 = FUN_1100a2ec;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_110106c4 == 0) {
    ExceptionList = &local_14;
    iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_110106c4 = 2;
    }
    else {
      DAT_110106c4 = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_1100a6e9(param_3,param_4);
  }
  if (DAT_110106c4 == 2) {
    iVar1 = LCMapStringA(param_1,param_2,param_3,param_4,(LPSTR)param_5,param_6);
    ExceptionList = local_14;
    return iVar1;
  }
  if (DAT_110106c4 == 1) {
    if (param_7 == 0) {
      param_7 = DAT_110106bc;
    }
    iVar1 = MultiByteToWideChar(param_7,(-(uint)(param_8 != 0) & 8) + 1,param_3,param_4,(LPWSTR)0x0,
                                0);
    if (iVar1 == 0) {
      ExceptionList = local_14;
      return 0;
    }
    local_8 = 0;
    FUN_11005610(unaff_DI);
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
      FUN_11005610(unaff_DI);
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


// ---- 1100a6e9 FUN_1100a6e9  (called by: FUN_1100a4c5@1100a4c5)

int __cdecl FUN_1100a6e9(char *param_1,int param_2)

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


// ---- 1100a714 FUN_1100a714  (called by: FUN_11008f3d@11008f3d, FUN_1100af91@1100af91)

BOOL __cdecl
FUN_1100a714(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6,
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
  puStack_c = &DAT_1100c798;
  pcStack_10 = FUN_1100a2ec;
  local_14 = ExceptionList;
  local_1c = (undefined1 *)(aWStack_2a + -7);
  ExceptionList = &local_14;
  pWVar1 = aWStack_2a + -7;
  if (DAT_110106c8 == 0) {
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
    DAT_110106c8 = iVar3;
    pWVar1 = (WCHAR *)local_1c;
  }
  local_1c = (undefined1 *)pWVar1;
  if (DAT_110106c8 == 2) {
    if (param_6 == 0) {
      param_6 = DAT_110106ac;
    }
    BVar2 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
    ExceptionList = local_14;
    return BVar2;
  }
  if (DAT_110106c8 == 1) {
    if (param_5 == 0) {
      param_5 = DAT_110106bc;
    }
    iVar3 = MultiByteToWideChar(param_5,(-(uint)(param_7 != 0) & 8) + 1,param_2,param_3,(LPWSTR)0x0,
                                0);
    if (iVar3 != 0) {
      local_8 = 0;
      FUN_11005610(unaff_DI);
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


// ---- 1100a860 _strncpy  (called by: FUN_110090de@110090de, FUN_110095e9@110095e9)

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
        goto joined_r0x1100a89e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_1100a8db;
        goto LAB_1100a949;
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
joined_r0x1100a945:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_1100a949:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_1100a8db;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x1100a945;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x1100a945;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x1100a945;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x1100a89e:
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
LAB_1100a8db:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}


// ---- 1100a95e FUN_1100a95e  (called by: FUN_110095e9@110095e9)

int __cdecl FUN_1100a95e(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_110106cc == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_110106cc = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_110106cc != (FARPROC)0x0) {
        DAT_110106d0 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_110106d4 = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_1100a9ad;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_1100a9ad:
    if (DAT_110106d0 != (FARPROC)0x0) {
      iVar1 = (*DAT_110106d0)();
      if ((iVar1 != 0) && (DAT_110106d4 != (FARPROC)0x0)) {
        iVar1 = (*DAT_110106d4)(iVar1);
      }
    }
    iVar1 = (*DAT_110106cc)(iVar1,param_1,param_2,param_3);
  }
  return iVar1;
}


// ---- 1100a9e7 FUN_1100a9e7  (called by: FUN_11009ed1@11009ed1)

int __cdecl FUN_1100a9e7(uint param_1,int param_2)

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
  
  FUN_11005610(unaff_BP);
  iVar8 = 0;
  DVar1 = FUN_11007763(param_1,0,1);
  if ((DVar1 == 0xffffffff) || (DVar2 = FUN_11007763(param_1,0,2), DVar2 == 0xffffffff)) {
    iVar8 = -1;
  }
  else {
    DVar2 = param_2 - DVar2;
    if ((int)DVar2 < 1) {
      if ((int)DVar2 < 0) {
        FUN_11007763(param_1,param_2,0);
        hFile = (HANDLE)FUN_11009da1(param_1);
        BVar7 = SetEndOfFile(hFile);
        iVar8 = (BVar7 != 0) - 1;
        if (iVar8 == -1) {
          pDVar6 = FUN_110076ec();
          *pDVar6 = 0xd;
          DVar2 = GetLastError();
          pDVar6 = FUN_110076f5();
          *pDVar6 = DVar2;
        }
      }
    }
    else {
      _memset(local_1008,0,0x1000);
      uStackY_28 = 0x1100aa54;
      iVar3 = FUN_1100acd4(param_1,0x8000);
      do {
        DVar4 = 0x1000;
        if ((int)DVar2 < 0x1000) {
          DVar4 = DVar2;
        }
        iVar5 = FUN_11007ade(param_1,local_1008,DVar4);
        if (iVar5 == -1) {
          pDVar6 = FUN_110076f5();
          if (*pDVar6 == 5) {
            pDVar6 = FUN_110076ec();
            *pDVar6 = 0xd;
          }
          iVar8 = -1;
          break;
        }
        DVar2 = DVar2 - iVar5;
      } while (0 < (int)DVar2);
      FUN_1100acd4(param_1,iVar3);
    }
    FUN_11007763(param_1,DVar1,0);
  }
  return iVar8;
}


// ---- 1100ab0c FUN_1100ab0c  (called by: FUN_1100a3c4@1100a3c4)

undefined4 __cdecl FUN_1100ab0c(DWORD *param_1)

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
    puVar7 = &DAT_110106dc;
    pcVar6 = DAT_110106dc;
LAB_1100ab92:
    bVar1 = true;
    FUN_11006859(1);
    pDVar2 = param_1;
  }
  else {
    if (((param_1 != (DWORD *)0x4) && (param_1 != (DWORD *)0x8)) && (param_1 != (DWORD *)0xb)) {
      if (param_1 == (DWORD *)0xf) {
        puVar7 = &DAT_110106e8;
        pcVar6 = DAT_110106e8;
      }
      else if (param_1 == (DWORD *)0x15) {
        puVar7 = &DAT_110106e0;
        pcVar6 = DAT_110106e0;
      }
      else {
        if (param_1 != (DWORD *)0x16) {
          return 0xffffffff;
        }
        puVar7 = &DAT_110106e4;
        pcVar6 = DAT_110106e4;
      }
      goto LAB_1100ab92;
    }
    pDVar2 = FUN_110088a1();
    uVar3 = FUN_1100ac8e((int)param_1,pDVar2[0x14]);
    puVar7 = (undefined4 *)(uVar3 + 8);
    pcVar6 = (code *)*puVar7;
  }
  if (pcVar6 == (code *)0x1) {
    if (bVar1) {
      FUN_110068ba(1);
      return 0;
    }
    return 0;
  }
  if (pcVar6 == (code *)0x0) {
    if (bVar1) {
      FUN_110068ba(1);
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
      goto LAB_1100ac06;
    }
  }
  else {
LAB_1100ac06:
    if (param_1 == (DWORD *)0x8) {
      if (DAT_1100fdc8 < DAT_1100fdcc + DAT_1100fdc8) {
        iVar4 = DAT_1100fdc8 * 0xc;
        iVar5 = DAT_1100fdc8;
        do {
          iVar4 = iVar4 + 0xc;
          *(undefined4 *)((pDVar2[0x14] - 4) + iVar4) = 0;
          iVar5 = iVar5 + 1;
        } while (iVar5 < DAT_1100fdcc + DAT_1100fdc8);
      }
      goto LAB_1100ac44;
    }
  }
  *puVar7 = 0;
LAB_1100ac44:
  if (bVar1) {
    FUN_110068ba(1);
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


// ---- 1100ac8e FUN_1100ac8e  (called by: FUN_1100ab0c@1100ab0c)

uint __cdecl FUN_1100ac8e(int param_1,uint param_2)

{
  int *piVar1;
  uint uVar3;
  uint uVar2;
  
  uVar2 = param_2;
  if (*(int *)(param_2 + 4) != param_1) {
    uVar3 = param_2;
    do {
      uVar2 = uVar3 + 0xc;
      if (param_2 + DAT_1100fdd4 * 0xc <= uVar2) break;
      piVar1 = (int *)(uVar3 + 0x10);
      uVar3 = uVar2;
    } while (*piVar1 != param_1);
  }
  if ((param_2 + DAT_1100fdd4 * 0xc <= uVar2) || (*(int *)(uVar2 + 4) != param_1)) {
    uVar2 = 0;
  }
  return uVar2;
}


// ---- 1100acd4 FUN_1100acd4  (called by: FUN_1100a9e7@1100a9e7)

int __cdecl FUN_1100acd4(uint param_1,int param_2)

{
  byte bVar1;
  DWORD *pDVar2;
  byte bVar3;
  
  bVar1 = *(byte *)((&DAT_11010a80)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
  if (param_2 == 0x8000) {
    bVar3 = bVar1 & 0x7f;
  }
  else {
    if (param_2 != 0x4000) {
      pDVar2 = FUN_110076ec();
      *pDVar2 = 0x16;
      return -1;
    }
    bVar3 = bVar1 | 0x80;
  }
  *(byte *)((&DAT_11010a80)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = bVar3;
  return (-(uint)((bVar1 & 0x80) != 0) & 0xffffc000) + 0x8000;
}


// ---- 1100ad40 FUN_1100ad40  (called by: -)

int __cdecl FUN_1100ad40(byte *param_1,byte *param_2)

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


// ---- 1100ad80 FUN_1100ad80  (called by: -)

byte * __cdecl FUN_1100ad80(byte *param_1,byte *param_2)

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


// ---- 1100adc0 FUN_1100adc0  (called by: -)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_1100adc0(void *this,byte *param_1,byte *param_2)

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
  
  iVar2 = _DAT_1101083c;
  if (DAT_110106ac == 0) {
    bVar5 = 0xff;
    do {
      do {
        cVar6 = '\0';
        if (bVar5 == 0) goto LAB_1100ae0e;
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
LAB_1100ae0e:
    uVar7 = (uint)cVar6;
  }
  else {
    LOCK();
    _DAT_1101083c = _DAT_1101083c + 1;
    UNLOCK();
    bVar1 = 0 < DAT_11010838;
    if (bVar1) {
      LOCK();
      UNLOCK();
      _DAT_1101083c = iVar2;
      FUN_11006859(0x13);
      this = extraout_ECX;
    }
    uVar9 = (uint)bVar1;
    uVar7 = 0xff;
    uVar8 = 0;
    do {
      do {
        if ((char)uVar7 == '\0') goto LAB_1100ae6f;
        bVar5 = *param_2;
        uVar7 = CONCAT31((int3)(uVar7 >> 8),bVar5);
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        uVar8 = CONCAT31((int3)(uVar8 >> 8),bVar4);
        param_1 = param_1 + 1;
      } while (bVar5 == bVar4);
      uVar8 = FUN_1100b006(this,uVar8);
      uVar7 = FUN_1100b006(this_00,uVar7);
      this = extraout_ECX_00;
    } while ((byte)uVar8 == (byte)uVar7);
    uVar8 = (uint)((byte)uVar8 < (byte)uVar7);
    uVar7 = (1 - uVar8) - (uint)(uVar8 != 0);
LAB_1100ae6f:
    if (uVar9 == 0) {
      LOCK();
      _DAT_1101083c = _DAT_1101083c + -1;
      UNLOCK();
    }
    else {
      FUN_110068ba(0x13);
    }
  }
  return uVar7;
}


// ---- 1100ae90 FUN_1100ae90  (called by: -)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1100ae90(byte *param_1,char *param_2,void *param_3)

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
  
  iVar2 = _DAT_1101083c;
  uVar6 = 0;
  if (param_3 != (void *)0x0) {
    if (DAT_110106ac == 0) {
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
        if (bVar3 != (byte)uVar4) goto LAB_1100aeef;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar6 = 0;
      bVar3 = (byte)(uVar4 >> 8);
      bVar8 = bVar3 < (byte)uVar4;
      if (bVar3 != (byte)uVar4) {
LAB_1100aeef:
        uVar6 = 0xffffffff;
        if (!bVar8) {
          uVar6 = 1;
        }
      }
    }
    else {
      LOCK();
      _DAT_1101083c = _DAT_1101083c + 1;
      UNLOCK();
      bVar8 = 0 < DAT_11010838;
      if (bVar8) {
        LOCK();
        UNLOCK();
        _DAT_1101083c = iVar2;
        FUN_11006859(0x13);
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
        uVar7 = FUN_1100b006(param_3,uVar7);
        uVar5 = FUN_1100b006(this,uVar5);
        bVar8 = uVar5 < uVar7;
        if (uVar5 != uVar7) goto LAB_1100af65;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar6 = 0;
      bVar8 = uVar5 < uVar7;
      if (uVar5 != uVar7) {
LAB_1100af65:
        uVar6 = 0xffffffff;
        if (!bVar8) {
          uVar6 = 1;
        }
      }
      if (uVar9 == 0) {
        LOCK();
        _DAT_1101083c = _DAT_1101083c + -1;
        UNLOCK();
      }
      else {
        FUN_110068ba(0x13);
      }
    }
  }
  return uVar6;
}


// ---- 1100af91 FUN_1100af91  (called by: FUN_1100b006@1100b006)

uint __thiscall FUN_1100af91(void *this,int param_1,uint param_2)

{
  BOOL BVar1;
  int iVar2;
  undefined4 local_8;
  
  if (param_1 + 1U < 0x101) {
    param_1._2_2_ = *(ushort *)(PTR_DAT_1100fdf0 + param_1 * 2);
  }
  else {
    if ((PTR_DAT_1100fdf0[(param_1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      local_8 = CONCAT31((int3)((uint)this >> 8),(char)param_1) & 0xffff00ff;
      iVar2 = 1;
    }
    else {
      local_8._0_2_ = CONCAT11((char)param_1,(char)((uint)param_1 >> 8));
      local_8 = CONCAT22((short)((uint)this >> 0x10),(undefined2)local_8) & 0xff00ffff;
      iVar2 = 2;
    }
    BVar1 = FUN_1100a714(1,(LPCSTR)&local_8,iVar2,(LPWORD)((int)&param_1 + 2),0,0,1);
    if (BVar1 == 0) {
      return 0;
    }
  }
  return param_1._2_2_ & param_2;
}


// ---- 1100b006 FUN_1100b006  (called by: FUN_1100adc0@1100adc0, FUN_1100ae90@1100ae90)

uint __thiscall FUN_1100b006(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  void *local_8;
  
  uVar1 = param_1;
  if (DAT_110106ac == 0) {
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
    if (DAT_1101010c < 2) {
      uVar2 = (byte)PTR_DAT_1100fdf0[param_1 * 2] & 1;
    }
    else {
      uVar2 = FUN_1100af91(this,param_1,1);
    }
    if (uVar2 == 0) {
      return uVar1;
    }
  }
  if ((PTR_DAT_1100fdf0[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
    param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;
  }
  else {
    uVar2 = param_1 >> 0x10;
    param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));
    param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;
    iVar3 = 2;
  }
  iVar3 = FUN_1100a4c5(DAT_110106ac,0x100,(char *)&param_1,iVar3,(LPWSTR)&local_8,3,0,1);
  if (iVar3 == 0) {
    return uVar1;
  }
  if (iVar3 == 1) {
    return (uint)local_8 & 0xff;
  }
  return (uint)local_8 & 0xffff;
}


// ---- 1100b1f0 __putw  (called by: FUN_11001106@11001106)

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
      FUN_11007c69((int)(char)*piVar4,(int *)pFVar2);
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


// ---- 1100b240 Unwind@1100b240  (called by: -)

void Unwind_1100b240(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b243. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100b249 Unwind@1100b249  (called by: -)

void Unwind_1100b249(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b24c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x14));
  return;
}


// ---- 1100b252 FUN_1100b252  (called by: -)

void FUN_1100b252(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110056d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100b25c Unwind@1100b25c  (called by: -)

void Unwind_1100b25c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b25f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + 8));
  return;
}


// ---- 1100b265 FUN_1100b265  (called by: -)

void FUN_1100b265(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110056d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100b270 Unwind@1100b270  (called by: -)

void Unwind_1100b270(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b276. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x20));
  return;
}


// ---- 1100b27c Unwind@1100b27c  (called by: -)

void Unwind_1100b27c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b282. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x24));
  return;
}


// ---- 1100b288 Unwind@1100b288  (called by: -)

void Unwind_1100b288(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b28e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}


// ---- 1100b294 Unwind@1100b294  (called by: -)

void Unwind_1100b294(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b29a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}


// ---- 1100b2a0 Unwind@1100b2a0  (called by: -)

void Unwind_1100b2a0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b2a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}


// ---- 1100b2ac Unwind@1100b2ac  (called by: -)

void Unwind_1100b2ac(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b2b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x34));
  return;
}


// ---- 1100b2b8 Unwind@1100b2b8  (called by: -)

void Unwind_1100b2b8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b2be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}


// ---- 1100b2c4 Unwind@1100b2c4  (called by: -)

void Unwind_1100b2c4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b2ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}


// ---- 1100b2d0 Unwind@1100b2d0  (called by: -)

void Unwind_1100b2d0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b2d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x10) + 0x40));
  return;
}


// ---- 1100b2dc Unwind@1100b2dc  (called by: -)

void Unwind_1100b2dc(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b2e5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0x160));
  return;
}


// ---- 1100b2eb Unwind@1100b2eb  (called by: -)

void Unwind_1100b2eb(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b2f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0x164));
  return;
}


// ---- 1100b2fa Unwind@1100b2fa  (called by: -)

void Unwind_1100b2fa(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b303. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0x168));
  return;
}


// ---- 1100b309 Unwind@1100b309  (called by: -)

void Unwind_1100b309(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b312. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0x16c));
  return;
}


// ---- 1100b318 Unwind@1100b318  (called by: -)

void Unwind_1100b318(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b321. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0x170));
  return;
}


// ---- 1100b327 Unwind@1100b327  (called by: -)

void Unwind_1100b327(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b330. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0x174));
  return;
}


// ---- 1100b336 Unwind@1100b336  (called by: -)

void Unwind_1100b336(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b33f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0x178));
  return;
}


// ---- 1100b345 FUN_1100b345  (called by: -)

void FUN_1100b345(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110056d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100b350 Unwind@1100b350  (called by: -)

void Unwind_1100b350(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b356. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x20));
  return;
}


// ---- 1100b35c Unwind@1100b35c  (called by: -)

void Unwind_1100b35c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b362. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x24));
  return;
}


// ---- 1100b368 Unwind@1100b368  (called by: -)

void Unwind_1100b368(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b36e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}


// ---- 1100b374 Unwind@1100b374  (called by: -)

void Unwind_1100b374(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b37a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}


// ---- 1100b380 Unwind@1100b380  (called by: -)

void Unwind_1100b380(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b386. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}


// ---- 1100b38c Unwind@1100b38c  (called by: -)

void Unwind_1100b38c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b392. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x34));
  return;
}


// ---- 1100b398 Unwind@1100b398  (called by: -)

void Unwind_1100b398(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b39e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}


// ---- 1100b3a4 Unwind@1100b3a4  (called by: -)

void Unwind_1100b3a4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b3aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}


// ---- 1100b3b0 Unwind@1100b3b0  (called by: -)

void Unwind_1100b3b0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b3b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x10) + 0x40));
  return;
}


// ---- 1100b3bc Unwind@1100b3bc  (called by: -)

void Unwind_1100b3bc(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b3c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0x160));
  return;
}


// ---- 1100b3cb Unwind@1100b3cb  (called by: -)

void Unwind_1100b3cb(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b3d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0x164));
  return;
}


// ---- 1100b3da Unwind@1100b3da  (called by: -)

void Unwind_1100b3da(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b3e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0x168));
  return;
}


// ---- 1100b3e9 Unwind@1100b3e9  (called by: -)

void Unwind_1100b3e9(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b3f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0x16c));
  return;
}


// ---- 1100b3f8 Unwind@1100b3f8  (called by: -)

void Unwind_1100b3f8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b401. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0x170));
  return;
}


// ---- 1100b407 Unwind@1100b407  (called by: -)

void Unwind_1100b407(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b410. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0x174));
  return;
}


// ---- 1100b416 Unwind@1100b416  (called by: -)

void Unwind_1100b416(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b41f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0x178));
  return;
}


// ---- 1100b425 FUN_1100b425  (called by: -)

void FUN_1100b425(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110056d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100b430 Unwind@1100b430  (called by: -)

void Unwind_1100b430(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b433. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x1c));
  return;
}


// ---- 1100b439 Unwind@1100b439  (called by: -)

void Unwind_1100b439(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b43c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x18));
  return;
}


// ---- 1100b442 Unwind@1100b442  (called by: -)

void Unwind_1100b442(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b445. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x14));
  return;
}


// ---- 1100b44b Unwind@1100b44b  (called by: -)

void Unwind_1100b44b(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b44e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x20));
  return;
}


// ---- 1100b454 Unwind@1100b454  (called by: -)

void Unwind_1100b454(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b457. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x20));
  return;
}


// ---- 1100b45d Unwind@1100b45d  (called by: -)

void Unwind_1100b45d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b460. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x20));
  return;
}


// ---- 1100b466 FUN_1100b466  (called by: -)

void FUN_1100b466(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110056d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100b470 Unwind@1100b470  (called by: -)

void Unwind_1100b470(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b473. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + -0x24));
  return;
}


// ---- 1100b479 FUN_1100b479  (called by: -)

void FUN_1100b479(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110056d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100b484 Unwind@1100b484  (called by: -)

void Unwind_1100b484(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b487. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100b48d Unwind@1100b48d  (called by: -)

void Unwind_1100b48d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100b496 Unwind@1100b496  (called by: -)

void Unwind_1100b496(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b499. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100b49f Unwind@1100b49f  (called by: -)

void Unwind_1100b49f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b4a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100b4a8 Unwind@1100b4a8  (called by: -)

void Unwind_1100b4a8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b4ab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100b4b1 Unwind@1100b4b1  (called by: -)

void Unwind_1100b4b1(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b4b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100b4ba Unwind@1100b4ba  (called by: -)

void Unwind_1100b4ba(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b4bd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100b4c3 Unwind@1100b4c3  (called by: -)

void Unwind_1100b4c3(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b4c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100b4cc FUN_1100b4cc  (called by: -)

void FUN_1100b4cc(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110056d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100b4e0 Unwind@1100b4e0  (called by: -)

void Unwind_1100b4e0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100b4e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScGroup::~ScGroup((ScGroup *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100b4e9 FUN_1100b4e9  (called by: -)

void FUN_1100b4e9(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110056d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100b500 FUN_1100b500  (called by: -)

void FUN_1100b500(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110056d0(param_1,param_2,param_3,param_4);
  return;
}


