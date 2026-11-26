// ---- 11001000 FUN_11001000  (called by: FUN_11001050@11001050, FUN_1100106e@1100106e)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_11001000(uint param_1,undefined4 param_2)

{
  if (param_1 < 0x16) {
    **(undefined4 **)(&DAT_11010064 + param_1 * 4) = param_2;
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
    return **(undefined4 **)(&DAT_11010064 + param_1 * 4);
  }
  return 0xffffffff;
}


// ---- 11001050 FUN_11001050  (called by: FUN_1100477a@1100477a)

int FUN_11001050(void)

{
  int iVar1;
  
  iVar1 = FUN_11001039(0xe);
  if (iVar1 != 0) {
    FUN_11001000(0xe,1);
  }
  return iVar1;
}


// ---- 1100106e FUN_1100106e  (called by: FUN_1100477a@1100477a)

void FUN_1100106e(void)

{
  FUN_11001000(0xe,0);
  return;
}


// ---- 1100107a GetCargo  (called by: -)

/* public: enum map_id __thiscall IUnit::GetCargo(void) */

map_id __thiscall IUnit::GetCargo(IUnit *this)

{
  map_id mVar1;
  
                    /* WARNING: Could not recover jumptable at 0x1100107a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x107a  2  ?GetCargo@IUnit@@QAE?AW4map_id@@XZ */
  mVar1 = Unit::GetCargo((Unit *)this);
  return mVar1;
}


// ---- 11001080 operator=  (called by: -)

/* public: class IUnit & __thiscall IUnit::operator=(class IUnit const &) */

IUnit * __thiscall IUnit::operator=(IUnit *this,IUnit *param_1)

{
                    /* 0x1080  1  ??4IUnit@@QAEAAV0@ABV0@@Z */
  Unit::operator=((Unit *)this,(Unit *)param_1);
  return this;
}


// ---- 11001093 FUN_11001093  (called by: FUN_11001112@11001112)

undefined4 * __thiscall
FUN_11001093(void *this,char param_1,char param_2,undefined1 param_3,undefined4 param_4,
            undefined4 param_5)

{
  FUN_11005560(this,param_1,param_2,param_4);
  *(undefined ***)this = &PTR_FUN_1100d378;
  *(undefined1 *)((int)this + 0x10) = param_3;
  *(undefined4 *)((int)this + 8) = param_5;
  return this;
}


// ---- 110010c0 FUN_110010c0  (called by: -)

void __fastcall FUN_110010c0(int param_1)

{
  bool bVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  local_c = param_1;
  local_8 = param_1;
  IUnit::IUnit((IUnit *)&local_8);
  PlayerVehicleEnum::PlayerVehicleEnum((PlayerVehicleEnum *)&local_c,(int)*(char *)(param_1 + 0x10))
  ;
  do {
    iVar2 = PlayerVehicleEnum::GetNext((PlayerVehicleEnum *)&local_c,(Unit *)&local_8);
    if (iVar2 == 0) {
      return;
    }
    bVar1 = IUnit::GetLights((IUnit *)&local_8);
  } while (!bVar1);
  FUN_110055e0(param_1);
  return;
}


// ---- 11001112 FUN_11001112  (called by: InitProc@11004475)

undefined4 * __cdecl
FUN_11001112(char param_1,char param_2,undefined1 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 local_18 [5];
  
  puVar1 = (undefined4 *)FUN_11005870(0x14);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_11001093(local_18,param_1,param_2,param_3,param_4,param_5);
    FUN_11006760(puVar1,local_18,0x14);
    FUN_11005630(&DAT_11017928,(int)puVar1);
  }
  return puVar1;
}


// ---- 1100115d FUN_1100115d  (called by: FUN_110047ac@110047ac)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1100115d(void)

{
  HANDLE hFile;
  DWORD _Size;
  DWORD local_4;
  
  DAT_11011780 = _DAT_004ff814;
  hFile = CreateFileA(s_renegmbl_raw_110100bc,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                      (HANDLE)0x0);
  _Size = GetFileSize(hFile,(LPDWORD)0x0);
  DAT_11011784 = _malloc(_Size);
  ReadFile(hFile,DAT_11011784,_Size,&local_4,(LPOVERLAPPED)0x0);
  CloseHandle(hFile);
  _DAT_004ff814 = (int)DAT_11011784 - *(int *)(_DAT_00546b98 + 0xec);
  return;
}


// ---- 110011d2 FUN_110011d2  (called by: FUN_110047ac@110047ac)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_110011d2(void)

{
  _DAT_004ff814 = DAT_11011780;
  FUN_11006b21(DAT_11011784);
  return;
}


// ---- 110011e9 FUN_110011e9  (called by: FUN_110051a2@110051a2)

undefined4 __cdecl FUN_110011e9(undefined4 param_1,LPCSTR param_2)

{
  int iVar1;
  FILE *_File;
  uint uVar2;
  undefined1 unaff_BP;
  char local_4e4c [19952];
  undefined4 uStackY_5c;
  undefined4 uVar3;
  
  FUN_11007110(unaff_BP);
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
        _File = (FILE *)FUN_110070f2(param_2,&DAT_110100f0);
        if (_File != (FILE *)0x0) {
          BASS_ChannelGetInfo();
          FUN_11006f88((char *)&WAVE_110100d8,0x14,1,(int *)_File);
          FUN_11006f88(local_4e4c + 0x4e34,0x10,1,(int *)_File);
          FUN_11006f88(&DAT_110100cc,8,1,(int *)_File);
          while (iVar1 = BASS_ChannelIsActive(), iVar1 != 0) {
            uVar2 = BASS_ChannelGetData();
            FUN_11006f88(local_4e4c,1,uVar2,(int *)_File);
            BASS_ChannelGetPosition();
          }
          FUN_11006e22((int *)_File);
          iVar1 = FUN_11006c9f((char *)_File);
          FUN_11006be6((int *)_File,4,0);
          __putw(iVar1 + -8,_File);
          FUN_11006e22((int *)_File);
          FUN_11006be6((int *)_File,0x28,0);
          __putw(iVar1 + -0x2c,_File);
          FUN_11006e22((int *)_File);
          uStackY_5c = 0x1100135f;
          FUN_11006b69(_File);
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


// ---- 11001369 FUN_11001369  (called by: FUN_110013d1@110013d1)

void __cdecl FUN_11001369(int param_1,int param_2,int param_3,int param_4,map_id param_5)

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


// ---- 110013d1 FUN_110013d1  (called by: InitProc@11004475)

void __cdecl FUN_110013d1(undefined4 param_1,int param_2,int param_3,int *param_4)

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
      FUN_11001369(*piVar2 + param_2,piVar2[1] + param_3,piVar2[2] + param_2,piVar2[3] + param_3,
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
      FUN_11001369(*piVar2 + param_2,piVar2[1] + param_3,piVar2[2] + param_2,piVar2[3] + param_3,
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


// ---- 110014fa FUN_110014fa  (called by: InitProc@11004475)

void __cdecl FUN_110014fa(int param_1,int param_2)

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


// ---- 1100152b FUN_1100152b  (called by: FUN_1100152b@1100152b, FUN_110016a0@110016a0)

void FUN_1100152b(void)

{
  int unaff_EBP;
  int iVar1;
  int iVar2;
  
  FUN_11007518();
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
      FUN_1100152b();
      FUN_1100152b();
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 110016a0 FUN_110016a0  (called by: FUN_11002b0d@11002b0d)

void FUN_110016a0(void)

{
  int *piVar1;
  int iVar2;
  map_id mVar3;
  int *piVar4;
  int iVar5;
  int unaff_EBP;
  int iVar6;
  
  FUN_11007518();
  piVar1 = *(int **)(unaff_EBP + 0x14);
  iVar5 = 0;
  iVar6 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (0 < *piVar1) {
    do {
      piVar4 = (int *)(iVar5 + piVar1[1]);
      iVar2 = piVar4[1];
      mVar3 = piVar4[2];
      *(int *)(unaff_EBP + -0x14) = *piVar4 + *(int *)(unaff_EBP + 0xc);
      *(int *)(unaff_EBP + -0x10) = iVar2 + *(int *)(unaff_EBP + 0x10);
      BuildingGroup::RecordBuilding
                ((BuildingGroup *)(unaff_EBP + 8),(LOCATION *)(unaff_EBP + -0x14),mVar3,0);
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 0xc;
    } while (iVar6 < *piVar1);
  }
  iVar5 = 0;
  if (0 < piVar1[2]) {
    *(undefined4 *)(unaff_EBP + 0x14) = 0;
    do {
      FUN_1100152b();
      *(int *)(unaff_EBP + 0x14) = *(int *)(unaff_EBP + 0x14) + 0x10;
      iVar5 = iVar5 + 1;
    } while (iVar5 < piVar1[2]);
  }
  iVar5 = 0;
  if (0 < piVar1[4]) {
    *(undefined4 *)(unaff_EBP + 0x14) = 0;
    do {
      FUN_1100152b();
      *(int *)(unaff_EBP + 0x14) = *(int *)(unaff_EBP + 0x14) + 0x10;
      iVar5 = iVar5 + 1;
    } while (iVar5 < piVar1[4]);
  }
  iVar5 = 0;
  iVar6 = 0;
  if (0 < piVar1[6]) {
    do {
      piVar4 = (int *)(piVar1[7] + iVar5);
      if (piVar4[2] == 0x17) {
        iVar2 = piVar4[1];
        mVar3 = piVar4[3];
        *(int *)(unaff_EBP + -0x14) = *piVar4 + *(int *)(unaff_EBP + 0xc);
        *(int *)(unaff_EBP + -0x10) = iVar2 + *(int *)(unaff_EBP + 0x10);
        BuildingGroup::RecordBuilding
                  ((BuildingGroup *)(unaff_EBP + 8),(LOCATION *)(unaff_EBP + -0x14),0x17,mVar3);
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 0x14;
    } while (iVar6 < piVar1[6]);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 110018e4 FUN_110018e4  (called by: -)

void FUN_110018e4(void)

{
  undefined4 *puVar1;
  MAP_RECT local_14 [16];
  
  puVar1 = (undefined4 *)MAP_RECT::MAP_RECT(local_14,0x48,0x53,0x49,0x5b);
  DAT_11011790 = *puVar1;
  DAT_11011794 = puVar1[1];
  DAT_11011798 = puVar1[2];
  DAT_1101179c = puVar1[3];
  puVar1 = (undefined4 *)MAP_RECT::MAP_RECT(local_14,0x48,0x53,0x49,0x5b);
  DAT_110117a0 = *puVar1;
  DAT_110117a4 = puVar1[1];
  DAT_110117a8 = puVar1[2];
  DAT_110117ac = puVar1[3];
  puVar1 = (undefined4 *)MAP_RECT::MAP_RECT(local_14,0x2e,0x2b,0x2f,0x2e);
  DAT_110117b0 = *puVar1;
  DAT_110117b4 = puVar1[1];
  DAT_110117b8 = puVar1[2];
  DAT_110117bc = puVar1[3];
  puVar1 = (undefined4 *)MAP_RECT::MAP_RECT(local_14,0x2e,0x2b,0x2f,0x2e);
  DAT_110117c0 = *puVar1;
  DAT_110117c4 = puVar1[1];
  DAT_110117c8 = puVar1[2];
  DAT_110117cc = puVar1[3];
  puVar1 = (undefined4 *)MAP_RECT::MAP_RECT(local_14,0x59,0x24,0x5c,0x26);
  DAT_110117d0 = *puVar1;
  DAT_110117d4 = puVar1[1];
  DAT_110117d8 = puVar1[2];
  DAT_110117dc = puVar1[3];
  puVar1 = (undefined4 *)MAP_RECT::MAP_RECT(local_14,0x59,0x24,0x5c,0x26);
  DAT_110117e0 = *puVar1;
  DAT_110117e4 = puVar1[1];
  DAT_110117e8 = puVar1[2];
  DAT_110117ec = puVar1[3];
  puVar1 = (undefined4 *)MAP_RECT::MAP_RECT(local_14,-1,-1,-1,-1);
  DAT_110117f0 = *puVar1;
  DAT_110117f4 = puVar1[1];
  DAT_110117f8 = puVar1[2];
  DAT_110117fc = puVar1[3];
  return;
}


// ---- 11001a7e FUN_11001a7e  (called by: -)

void FUN_11001a7e(void)

{
  FUN_11001b51();
  return;
}


// ---- 11001a88 FUN_11001a88  (called by: -)

void FUN_11001a88(void)

{
  FUN_110075b5(0x11001a94);
  return;
}


// ---- 11001a94 FUN_11001a94  (called by: -)

void FUN_11001a94(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_11007518();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0xc;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x8e8));
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x88));
  *(undefined1 *)(unaff_EBP + -4) = 10;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x84));
  *(undefined1 *)(unaff_EBP + -4) = 9;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x80));
  *(undefined1 *)(unaff_EBP + -4) = 8;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x7c));
  *(undefined1 *)(unaff_EBP + -4) = 7;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x78));
  *(undefined1 *)(unaff_EBP + -4) = 6;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x74));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x70));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x6c));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x68));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 100));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x60));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x5c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x58));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11001b51 FUN_11001b51  (called by: FUN_11001a7e@11001a7e)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_11001b51(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_11007518();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  IUnit::IUnit((IUnit *)(extraout_ECX + 0xc));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x10));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x14));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x18));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x1c));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x20));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x24));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x28));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x2c));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x30));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x34));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x38));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x3c));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x40));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x44));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x48));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x4c));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x50));
  IUnit::IUnit((IUnit *)(extraout_ECX + 0x54));
  MiningGroup::MiningGroup((MiningGroup *)(extraout_ECX + 0x58));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  MiningGroup::MiningGroup((MiningGroup *)(extraout_ECX + 0x5c));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  MiningGroup::MiningGroup((MiningGroup *)(extraout_ECX + 0x60));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  BuildingGroup::BuildingGroup((BuildingGroup *)(extraout_ECX + 100));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  BuildingGroup::BuildingGroup((BuildingGroup *)(extraout_ECX + 0x68));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  BuildingGroup::BuildingGroup((BuildingGroup *)(extraout_ECX + 0x6c));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  BuildingGroup::BuildingGroup((BuildingGroup *)(extraout_ECX + 0x70));
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x74));
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x78));
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x7c));
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x80));
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x84));
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x88));
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  *(undefined4 *)(extraout_ECX + 0x94) = 0;
  *(undefined4 *)(extraout_ECX + 0x98) = 0;
  Trigger::Trigger((Trigger *)(extraout_ECX + 0x8e8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 0x8cc) = 0;
  *(undefined1 *)(extraout_ECX + 0x8cd) = 0;
  *(undefined1 *)(extraout_ECX + 0x8ce) = 0;
  *(undefined1 *)(extraout_ECX + 0x8d0) = 0;
  *(undefined1 *)(extraout_ECX + 0x8cf) = 0;
  *(undefined1 *)(extraout_ECX + 0x8d1) = 0;
  *(undefined1 *)(extraout_ECX + 0x8d2) = 0;
  *(undefined1 *)(extraout_ECX + 0x8d3) = 0;
  *(undefined1 *)(extraout_ECX + 0x8d4) = 0;
  *(undefined4 *)(extraout_ECX + 0xc4) = 0;
  *(undefined4 *)(extraout_ECX + 200) = 0;
  *(undefined1 *)(extraout_ECX + 0x8d6) = 0;
  *(undefined1 *)(extraout_ECX + 0x8d7) = 0;
  *(undefined4 *)(extraout_ECX + 0xbc) = 0;
  *(undefined4 *)(extraout_ECX + 0xc0) = 1;
  _DAT_110178f4 = 0;
  _DAT_110178ec = 0xc;
  _DAT_110178f0 = 0xd;
  return extraout_ECX;
}


// ---- 11001d2d FUN_11001d2d  (called by: FUN_1100311d@1100311d)

void __cdecl FUN_11001d2d(ScStub *param_1)

{
  int iVar1;
  
  iVar1 = ScStub::IsInitialized(param_1);
  if (iVar1 != 0) {
    ScStub::Disable(param_1);
    ScStub::Destroy(param_1);
  }
  return;
}


// ---- 11001d50 FUN_11001d50  (called by: InitProc@11004475)

void FUN_11001d50(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  map_id mVar4;
  int *piVar5;
  ScGroup *pSVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  MAP_RECT local_4c [8];
  undefined1 local_44 [8];
  PlayerBuildingEnum local_3c [8];
  PlayerBuildingEnum local_34 [8];
  PlayerBuildingEnum local_2c [8];
  PlayerBuildingEnum local_24 [8];
  undefined1 local_1c [4];
  undefined4 local_18;
  int local_10;
  PlayerVehicleEnum local_c [4];
  undefined1 *local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  PlayerVehicleEnum::PlayerVehicleEnum(local_c,1);
  PlayerBuildingEnum::PlayerBuildingEnum(local_2c,1,0x36);
  PlayerBuildingEnum::PlayerBuildingEnum(local_24,1,0x15);
  PlayerBuildingEnum::PlayerBuildingEnum(local_3c,1,0x38);
  PlayerBuildingEnum::PlayerBuildingEnum(local_34,1,0x16);
  PlayerBuildingEnum::GetNext(local_24,(Unit *)&DAT_11017020);
  PlayerBuildingEnum::GetNext(local_24,(Unit *)&DAT_11017024);
  iVar1 = Unit::Location((Unit *)&DAT_11017024);
  iVar2 = Unit::Location((Unit *)&DAT_11017020);
  if (*(int *)(iVar1 + 4) < *(int *)(iVar2 + 4)) {
    local_10 = DAT_11017020;
    Unit::operator=((Unit *)&DAT_11017020,(Unit *)&DAT_11017024);
    Unit::operator=((Unit *)&DAT_11017024,(Unit *)&local_10);
  }
  PlayerBuildingEnum::GetNext(local_2c,(Unit *)&DAT_1101702c);
  PlayerBuildingEnum::GetNext(local_2c,(Unit *)&DAT_11017030);
  local_10 = Unit::Location((Unit *)&DAT_11017030);
  iVar1 = Unit::Location((Unit *)&DAT_1101702c);
  if (*(int *)(local_10 + 4) < *(int *)(iVar1 + 4)) {
    local_10 = DAT_1101702c;
    Unit::operator=((Unit *)&DAT_1101702c,(Unit *)&DAT_11017030);
    Unit::operator=((Unit *)&DAT_11017030,(Unit *)&local_10);
  }
  PlayerBuildingEnum::GetNext(local_34,(Unit *)&DAT_11017028);
  PlayerBuildingEnum::GetNext(local_3c,(Unit *)&DAT_11017034);
  iVar2 = DAT_1101702c;
  iVar1 = DAT_11017020;
  uVar3 = MAP_RECT::MAP_RECT(local_4c,0x47,0x50,0x4a,0x53);
  MiningGroup::Setup((MiningGroup *)&DAT_11017058,iVar1,iVar2,uVar3);
  ScGroup::SetTargCount((ScGroup *)&DAT_11017058,1,0,2);
  local_10 = DAT_11017030;
  local_18 = DAT_11017024;
  uVar3 = MAP_RECT::MAP_RECT(local_4c,0x5b,0x21,0x5e,0x24);
  MiningGroup::Setup((MiningGroup *)&DAT_1101705c,local_18,local_10,uVar3);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101705c,1,0,3);
  local_18 = DAT_11017034;
  local_10 = DAT_11017028;
  uVar3 = MAP_RECT::MAP_RECT(local_4c,0x30,0x2e,0x32,0x31);
  MiningGroup::Setup((MiningGroup *)&DAT_11017060,local_10,local_18,uVar3);
  puVar7 = (undefined1 *)0x1;
  ScGroup::SetTargCount((ScGroup *)&DAT_11017060,1,0,2);
  iVar1 = PlayerVehicleEnum::GetNext(local_c,(Unit *)&local_8);
  while (0 < iVar1) {
    mVar4 = Unit::GetType((Unit *)&local_8);
    if (mVar4 == 1) {
      puVar9 = local_44;
      iVar1 = Unit::Location((Unit *)&local_8);
      if (*(int *)(iVar1 + 4) < 0x51) {
        puVar8 = local_1c;
        piVar5 = (int *)Unit::Location((Unit *)&local_8);
        pSVar6 = (ScGroup *)&DAT_11017058;
        puVar7 = local_8;
        if (*piVar5 < 0x51) {
          pSVar6 = (ScGroup *)&DAT_11017060;
        }
      }
      else {
        pSVar6 = (ScGroup *)&DAT_1101705c;
        puVar8 = local_8;
      }
      ScGroup::TakeUnit(pSVar6,puVar7,puVar8,puVar9);
    }
    iVar1 = PlayerVehicleEnum::GetNext(local_c,(Unit *)&local_8);
  }
  return;
}


// ---- 11001f88 FUN_11001f88  (called by: InitProc@11004475)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_11001f88(void)

{
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  _DAT_11017090 = &DAT_11011898;
  FightGroup::SetPatrolMode((FightGroup *)&DAT_11017078,(PatrolRoute *)&DAT_1101708c);
  TethysGame::CreateUnit(&local_8,5,0x4b,0x1c,1,0x3e,0);
  ScGroup::TakeUnit((ScGroup *)&DAT_11017078,local_8);
  TethysGame::CreateUnit(&local_8,5,0x38,0x23,1,0x3e,0);
  ScGroup::TakeUnit((ScGroup *)&DAT_11017078,local_8);
  return;
}


// ---- 11001ffe FUN_11001ffe  (called by: -)

void FUN_11001ffe(void)

{
  int iVar1;
  map_id mVar2;
  PlayerVehicleEnum local_8 [4];
  
  PlayerVehicleEnum::PlayerVehicleEnum(local_8,1);
  iVar1 = PlayerVehicleEnum::GetNext(local_8,(Unit *)&DAT_11017048);
  while( true ) {
    if (iVar1 == 0) {
      return;
    }
    mVar2 = Unit::GetType((Unit *)&DAT_11017048);
    if (mVar2 == 0xc) break;
    iVar1 = PlayerVehicleEnum::GetNext(local_8,(Unit *)&DAT_11017048);
  }
  IUnit::Doze((IUnit *)&DAT_11017048,DAT_11011790,DAT_11011794,DAT_11011798,DAT_1101179c);
  DAT_110178d8 = FUN_11005aa0('\x01','\0',400,FUN_11002080,0);
  DAT_110170b8 = 0;
  return;
}


// ---- 11002080 FUN_11002080  (called by: -)

void FUN_11002080(void)

{
  command_type cVar1;
  
  cVar1 = IUnit::GetBusy((IUnit *)&DAT_11017048);
  if (cVar1 != 1) {
    DAT_110170b8 = DAT_110170b8 + 1;
    IUnit::Doze((IUnit *)&DAT_11017048,(&DAT_11011790)[DAT_110170b8 * 4],
                (&DAT_11011794)[DAT_110170b8 * 4],(&DAT_11011798)[DAT_110170b8 * 4],
                (&DAT_1101179c)[DAT_110170b8 * 4]);
    if (((&DAT_110117a0)[DAT_110170b8 * 4] == -1) && (DAT_110178d8 != 0)) {
      FUN_11005590(DAT_110178d8);
    }
  }
  return;
}


// ---- 110020dd FUN_110020dd  (called by: FUN_11002244@11002244, FUN_1100235b@1100235b)

void FUN_110020dd(void)

{
  TethysGame::AddMessage(-1,-1,s_We_might_be_able_to_help_each_ot_11010670,0,0);
  TethysGame::AddMessage(-1,-1,s_It_seems_those_Eden_units_are_he_11010638,0,0xb7);
  DAT_110178d4 = 1;
  _Player::AllyWith((_Player *)&DAT_11017918,0);
  DAT_110178d6 = 1;
  return;
}


// ---- 11002126 FUN_11002126  (called by: -)

void FUN_11002126(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = Unit::IsLive((Unit *)&DAT_1101704c);
  if (iVar1 == 0) {
    if (DAT_110178dc != 0) {
      FUN_11005590(DAT_110178dc);
    }
  }
  else {
    piVar2 = (int *)Unit::Location((Unit *)&DAT_1101704c);
    if (*piVar2 == *(int *)(&DAT_11011848 + DAT_110170bc * 8)) {
      iVar1 = Unit::Location((Unit *)&DAT_1101704c);
      if (*(int *)(iVar1 + 4) == *(int *)(&DAT_1101184c + DAT_110170bc * 8)) {
        if (DAT_110178dc != 0) {
          FUN_11005590(DAT_110178dc);
        }
        DAT_110178dc = FUN_11005aa0('\x01','\x01',0x32,FUN_11002244,0);
      }
    }
  }
  return;
}


// ---- 110021b5 FUN_110021b5  (called by: -)

void FUN_110021b5(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = Unit::IsLive((Unit *)&DAT_11017050);
  if (iVar1 == 0) {
    if (DAT_110178e0 != 0) {
      FUN_11005590(DAT_110178e0);
    }
  }
  else {
    piVar2 = (int *)Unit::Location((Unit *)&DAT_11017050);
    if (*piVar2 == *(int *)(&DAT_11011848 + DAT_110170c0 * 8)) {
      iVar1 = Unit::Location((Unit *)&DAT_11017050);
      if (*(int *)(iVar1 + 4) == *(int *)(&DAT_1101184c + DAT_110170c0 * 8)) {
        if (DAT_110178e0 != 0) {
          FUN_11005590(DAT_110178e0);
        }
        DAT_110178e0 = FUN_11005aa0('\x01','\x01',0x32,FUN_1100235b,0);
      }
    }
  }
  return;
}


// ---- 11002244 FUN_11002244  (called by: FUN_11002531@11002531)

void FUN_11002244(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  MAP_RECT local_2c [16];
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  int local_8;
  
  if (DAT_110178dc != 0) {
    FUN_11005590(DAT_110178dc);
  }
  iVar2 = Unit::IsLive((Unit *)&DAT_1101704c);
  if (iVar2 != 0) {
    DAT_110170bc = DAT_110170bc + 2;
    if (DAT_110170bc < 10) {
      iVar2 = *(int *)(&DAT_1101184c + DAT_110170bc * 8);
      iVar1 = *(int *)(&DAT_11011848 + DAT_110170bc * 8);
      local_8 = iVar2;
      Unit::DoMove((Unit *)&DAT_1101704c,iVar1,iVar2);
      puVar3 = (undefined4 *)MAP_RECT::MAP_RECT(local_2c,iVar1 + -2,iVar2 + -2,iVar1 + 2,iVar2 + 2);
      local_1c = *puVar3;
      uStack_18 = puVar3[1];
      uStack_14 = puVar3[2];
      uStack_10 = puVar3[3];
      FightGroup::SetRect((FightGroup *)&DAT_11017080,(MAP_RECT *)&local_1c);
      DAT_110178dc = FUN_11005c30('\x01','\0',2,SUB41(iVar1,0),local_8,FUN_11002126);
    }
    else {
      IUnit::Poof((IUnit *)&DAT_1101704c);
      FightGroup::DoExitMap((FightGroup *)&DAT_11017080);
      uVar4 = FUN_11002335();
      if ((char)uVar4 != '\0') {
        FightGroup::DoExitMap((FightGroup *)&DAT_1101707c);
      }
    }
    if ((3 < DAT_110170bc) && (DAT_110178d4 == '\0')) {
      FUN_110020dd();
    }
  }
  return;
}


// ---- 11002335 FUN_11002335  (called by: FUN_11002244@11002244, FUN_1100235b@1100235b, FUN_11002783@11002783, FUN_11003d6a@11003d6a)

undefined4 FUN_11002335(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((DAT_110178cc != '\0') && (DAT_110178cd != '\0')) && (DAT_110178ce != '\0')) &&
     (DAT_110178cf != '\0')) {
    uVar1 = 1;
  }
  return uVar1;
}


// ---- 1100235b FUN_1100235b  (called by: FUN_1100261f@1100261f)

void FUN_1100235b(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  MAP_RECT local_2c [16];
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  int local_8;
  
  if (DAT_110178e0 != 0) {
    FUN_11005590(DAT_110178e0);
  }
  iVar2 = Unit::IsLive((Unit *)&DAT_11017050);
  if (iVar2 != 0) {
    DAT_110170c0 = DAT_110170c0 + 2;
    if (DAT_110170c0 < 10) {
      iVar2 = *(int *)(&DAT_1101184c + DAT_110170c0 * 8);
      iVar1 = *(int *)(&DAT_11011848 + DAT_110170c0 * 8);
      local_8 = iVar2;
      Unit::DoMove((Unit *)&DAT_11017050,iVar1,iVar2);
      puVar3 = (undefined4 *)MAP_RECT::MAP_RECT(local_2c,iVar1 + -2,iVar2 + -2,iVar1 + 2,iVar2 + 2);
      local_1c = *puVar3;
      uStack_18 = puVar3[1];
      uStack_14 = puVar3[2];
      uStack_10 = puVar3[3];
      FightGroup::SetRect((FightGroup *)&DAT_11017084,(MAP_RECT *)&local_1c);
      DAT_110178e0 = FUN_11005c30('\x01','\0',2,SUB41(iVar1,0),local_8,FUN_110021b5);
    }
    else {
      IUnit::Poof((IUnit *)&DAT_11017050);
      FightGroup::DoExitMap((FightGroup *)&DAT_11017084);
      uVar4 = FUN_11002335();
      if ((char)uVar4 != '\0') {
        FightGroup::DoExitMap((FightGroup *)&DAT_1101707c);
      }
    }
    if ((3 < DAT_110170c0) && (DAT_110178d4 == '\0')) {
      FUN_110020dd();
    }
  }
  return;
}


// ---- 1100244c FUN_1100244c  (called by: -)

void FUN_1100244c(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  IUnit aIStack_4 [4];
  
  IUnit::IUnit(aIStack_4);
  iVar1 = FUN_11005df0(1,0x17,0xffffffff);
  iVar2 = FUN_11005df0(1,0x30,0xffffffff);
  iVar3 = DAT_110170c4 + 2 + DAT_11017004 * 2;
  if (iVar1 < 4) {
    iVar3 = iVar3 + -1;
  }
  if (iVar1 < 2) {
    iVar3 = iVar3 + -1;
  }
  if (iVar2 == 0) {
    iVar3 = iVar3 + -2;
  }
  if (-1 < iVar3 + -1) {
    iVar1 = iVar3 + 0x54 + iVar3 + -1;
    do {
      uVar4 = 2;
      TethysGame::CreateUnit(aIStack_4,5,iVar1,1,2,0x3f,2);
      ScGroup::TakeUnit((ScGroup *)&DAT_1101707c,uVar4);
      iVar1 = iVar1 + -2;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  FightGroup::DoAttackEnemy((FightGroup *)&DAT_1101707c);
  FightGroup::SetAttackType((FightGroup *)&DAT_1101707c,0x17);
  FightGroup::SetCombineFire((FightGroup *)&DAT_1101707c);
  if (DAT_110178e4 != 0) {
    FUN_11005590(DAT_110178e4);
  }
  FUN_11005aa0('\x01','\x01',400,FUN_1100270a,0);
  DAT_110178d5 = 0;
  FUN_11005d80('\x01','\x01',(ScStub *)&DAT_1101707c,2,FUN_11002783,0);
  return;
}


// ---- 11002531 FUN_11002531  (called by: FUN_1100270a@1100270a)

void FUN_11002531(void)

{
  int iVar1;
  int iVar2;
  MAP_RECT *pMVar3;
  undefined4 uVar4;
  IUnit local_18 [2];
  MAP_RECT aMStack_16 [2];
  int local_14;
  
  IUnit::IUnit(local_18);
  iVar1 = ScGroup::UnitCount((ScGroup *)&DAT_11017080,0);
  iVar2 = (DAT_11017004 - iVar1) + 1;
  if (-1 < iVar2) {
    iVar2 = (0x2f - iVar2) * 2;
    local_14 = (DAT_11017004 - iVar1) + 2;
    do {
      uVar4 = 2;
      TethysGame::CreateUnit(local_18,5,iVar2,1,2,0x3d,2);
      ScGroup::TakeUnit((ScGroup *)&DAT_11017080,uVar4);
      iVar2 = iVar2 + 2;
      local_14 = local_14 + -1;
    } while (local_14 != 0);
  }
  iVar1 = Unit::IsLive((Unit *)&DAT_1101704c);
  if (iVar1 == 0) {
    TethysGame::CreateUnit(&DAT_1101704c,0xb,0x60,1,2,0,2);
    FightGroup::DoGuardUnit((FightGroup *)&DAT_11017080);
    FightGroup::SetTargetUnit((FightGroup *)&DAT_11017080,DAT_1101704c);
    FightGroup::SetFollowMode((FightGroup *)&DAT_11017080,1);
    pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(local_18 + -0x10),0x4a,0x16,0x4f,0x19);
    FightGroup::SetRect((FightGroup *)&DAT_11017080,pMVar3);
    FightGroup::SetAttackType((FightGroup *)&DAT_11017080,5);
    FightGroup::SetAttackType((FightGroup *)&DAT_11017080,0x17);
    DAT_110170bc = DAT_110170bc + -2;
    FUN_11002244();
  }
  return;
}


// ---- 1100261f FUN_1100261f  (called by: FUN_1100270a@1100270a)

void FUN_1100261f(void)

{
  int iVar1;
  MAP_RECT *pMVar2;
  int iVar3;
  undefined4 uVar4;
  IUnit local_18 [2];
  MAP_RECT aMStack_16 [2];
  int local_14;
  
  IUnit::IUnit(local_18);
  iVar1 = ScGroup::UnitCount((ScGroup *)&DAT_11017084,0);
  iVar1 = DAT_11017004 - iVar1;
  if (-1 < iVar1 + 1) {
    iVar3 = iVar1 + 0x53 + iVar1 + 1;
    local_14 = iVar1 + 2;
    do {
      uVar4 = 2;
      TethysGame::CreateUnit(local_18,5,iVar3,1,2,0x3d,2);
      ScGroup::TakeUnit((ScGroup *)&DAT_11017084,uVar4);
      iVar3 = iVar3 + -2;
      local_14 = local_14 + -1;
    } while (local_14 != 0);
    local_14 = 0;
  }
  iVar1 = Unit::IsLive((Unit *)&DAT_11017050);
  if (iVar1 == 0) {
    TethysGame::CreateUnit(&DAT_11017050,0xb,0x50,1,2,0);
    FightGroup::DoGuardUnit((FightGroup *)&DAT_11017084);
    FightGroup::SetTargetUnit((FightGroup *)&DAT_11017084,DAT_11017050);
    FightGroup::SetFollowMode((FightGroup *)&DAT_11017084,1);
    pMVar2 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(local_18 + -0x10),0x4a,0x16,0x4f,0x19);
    FightGroup::SetRect((FightGroup *)&DAT_11017084,pMVar2);
    FightGroup::SetAttackType((FightGroup *)&DAT_11017084,5);
    FightGroup::SetAttackType((FightGroup *)&DAT_11017084,0x17);
    DAT_110170c0 = DAT_110170c0 + -2;
    FUN_1100235b();
  }
  return;
}


// ---- 1100270a FUN_1100270a  (called by: -)

void FUN_1100270a(void)

{
  bool bVar1;
  bool bVar2;
  
  if (DAT_110178d5 == '\0') {
    bVar1 = DAT_110170bc < 10;
    if (bVar1) {
      FUN_11002531();
    }
    bVar2 = DAT_110170c0 < 10;
    if (bVar2) {
      FUN_1100261f();
    }
    if ((bVar2 || bVar1) && (DAT_110170c8 = DAT_110170c8 + 1, DAT_110170c8 < 2)) {
      FUN_11006060('\x01','\x01',2,0xb,0xffffffff,0,0,FUN_11002765,0);
    }
  }
  return;
}


// ---- 11002765 FUN_11002765  (called by: -)

void FUN_11002765(void)

{
  DAT_110178e4 = FUN_11005aa0('\x01','\x01',0x898,FUN_1100270a,0);
  return;
}


// ---- 11002783 FUN_11002783  (called by: -)

void FUN_11002783(void)

{
  MAP_RECT *pMVar1;
  undefined4 uVar2;
  MAP_RECT aMStack_10 [16];
  
  FightGroup::DoGuardRect((FightGroup *)&DAT_1101707c);
  pMVar1 = (MAP_RECT *)MAP_RECT::MAP_RECT(aMStack_10,0x52,0xb,0x59,0xe);
  FightGroup::SetRect((FightGroup *)&DAT_1101707c,pMVar1);
  DAT_110170c4 = DAT_110170c4 + 1;
  DAT_110178d5 = 1;
  if (DAT_110170c4 < 3) {
    uVar2 = FUN_11002335();
    if ((char)uVar2 == '\0') {
      FUN_11005aa0('\x01','\x01',2000,FUN_1100244c,0);
    }
  }
  return;
}


// ---- 110027eb FUN_110027eb  (called by: FUN_1100294d@1100294d)

void __cdecl FUN_110027eb(map_id param_1,undefined4 param_2,int param_3,LOCATION param_4)

{
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  TethysGame::CreateUnit(&local_8,2,0x20,param_2,1,param_1,0);
  if (param_3 == 1) {
    ScGroup::TakeUnit((ScGroup *)&DAT_11017064,local_8);
    return;
  }
  ScGroup::TakeUnit((ScGroup *)&DAT_11017068,local_8);
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_11017068,&param_4,param_1,0);
  return;
}


// ---- 1100284d FUN_1100284d  (called by: -)

void FUN_1100284d(void)

{
  int iVar1;
  MAP_RECT *pMVar2;
  int iVar3;
  undefined4 uVar4;
  IUnit local_18 [2];
  IUnit aIStack_16 [2];
  int local_14;
  MAP_RECT aMStack_10 [16];
  
  IUnit::IUnit(local_18);
  iVar1 = DAT_11017004 * 2;
  if (-1 < iVar1 + 3) {
    iVar3 = iVar1 + 0x15;
    local_14 = iVar1 + 4;
    do {
      uVar4 = 0;
      TethysGame::CreateUnit(local_18,5,0x21,iVar3,1);
      ScGroup::TakeUnit((ScGroup *)&DAT_11017088,uVar4);
      uVar4 = 0;
      TethysGame::CreateUnit(local_18 + -0x18,5,0x20,iVar3,1,0x40,0);
      ScGroup::TakeUnit((ScGroup *)&DAT_11017088,uVar4);
      iVar3 = iVar3 + -1;
      local_14 = local_14 + -1;
    } while (local_14 != 0);
    local_14 = 0;
  }
  FightGroup::DoGuardRect((FightGroup *)&DAT_11017088);
  pMVar2 = (MAP_RECT *)MAP_RECT::MAP_RECT(aMStack_10,0x37,0x19,0x4c,0x29);
  FightGroup::SetRect((FightGroup *)&DAT_11017088,pMVar2);
  pMVar2 = (MAP_RECT *)MAP_RECT::MAP_RECT(aMStack_10,0x1f,0xc,0x5f,0x37);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_11017088,pMVar2);
  pMVar2 = (MAP_RECT *)MAP_RECT::MAP_RECT(aMStack_10,0x2a,0x37,0x54,0x62);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_11017088,pMVar2);
  FightGroup::SetAttackType((FightGroup *)&DAT_11017088,5);
  FightGroup::SetAttackType((FightGroup *)&DAT_11017088,6);
  FightGroup::SetCombineFire((FightGroup *)&DAT_11017088);
  FUN_11005aa0('\x01','\x01',300,FUN_1100294d,0);
  return;
}


// ---- 1100294d FUN_1100294d  (called by: -)

void FUN_1100294d(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  PlayerBuildingEnum *this;
  Unit *pUVar4;
  undefined4 uStack_28;
  int iStack_24;
  int iStack_20;
  int aiStack_1c [2];
  PlayerBuildingEnum aPStack_14 [4];
  PlayerBuildingEnum aPStack_10 [8];
  PlayerUnitEnum aPStack_8 [8];
  
  IUnit::IUnit((IUnit *)&uStack_28);
  iStack_24 = 0;
  PlayerUnitEnum::PlayerUnitEnum(aPStack_8,1);
  PlayerBuildingEnum::PlayerBuildingEnum(aPStack_10,1,0x1c);
  iVar1 = FUN_11005f10(1,2,0xffffffff);
  pUVar4 = (Unit *)&uStack_28;
  this = aPStack_10;
  do {
    iVar2 = PlayerBuildingEnum::GetNext(this,pUVar4);
    if (iVar2 == 0) {
LAB_110029c6:
      iStack_24 = FUN_11005df0(1,0x2f,0xffffffff);
      aiStack_1c[0] = FUN_11005df0(1,0x30,0xffffffff);
      iStack_20 = FUN_11005df0(1,0x3a,0xffffffff);
      iVar2 = FUN_11005df0(1,0x15,0xffffffff);
      if (iVar2 < 2) {
        TethysGame::CreateUnit(aiStack_1c + -4,9,0x21,0x10,1,0,0);
      }
      if (iVar2 < 1) {
        TethysGame::CreateUnit(aiStack_1c + -4,9,0x21,0xf,1,0,0);
      }
      if (uStack_28 == 0) {
        FUN_110027eb(0x1c,0xe,2,(LOCATION)0x3d);
        iVar1 = iVar1 + 1;
      }
      if (iStack_24 == 0) {
        FUN_110027eb(0x2f,0xf,(0 < iVar1) + 1,(LOCATION)0x42);
        iVar1 = iVar1 + 1;
      }
      if (iStack_20 == 0) {
        FUN_110027eb(0x3a,0x10,(1 < iVar1) + 1,(LOCATION)0x35);
        iVar1 = iVar1 + 1;
      }
      if (aiStack_1c[0] == 0) {
        if (iVar1 < 3) {
          FUN_110027eb(0x30,0x10,2,(LOCATION)0x39);
          iVar1 = iVar1 + 1;
        }
        else {
          aiStack_1c[0] = 0x39;
          aiStack_1c[1] = 0x1a;
          BuildingGroup::RecordBuilding
                    ((BuildingGroup *)&DAT_11017068,(LOCATION *)aiStack_1c,0x30,0);
        }
      }
      if (iVar1 < 3) {
        iVar1 = 4 - (iVar1 + 1);
        do {
          FUN_110027eb(0x30,0x10,2,(LOCATION)0x39);
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
      return;
    }
    piVar3 = (int *)Unit::Location((Unit *)&uStack_28);
    if (*piVar3 == 0x3d) {
      uStack_28 = 1;
      goto LAB_110029c6;
    }
    pUVar4 = (Unit *)(aiStack_1c + -4);
    this = aPStack_14;
  } while( true );
}


// ---- 11002b0d FUN_11002b0d  (called by: InitProc@11004475)

void FUN_11002b0d(void)

{
  PlayerBuildingEnum *this;
  MiningGroup *pMVar1;
  BuildingGroup *pBVar2;
  MAP_RECT *pMVar3;
  FightGroup *pFVar4;
  ScStub aSStack_eb [3];
  void *pvVar5;
  ScStub aSStack_82 [2];
  ScStub aSStack_6e [6];
  undefined4 uStack_60;
  undefined4 uStack_54;
  Unit *pUVar6;
  ScStub aSStack_3e [2];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  PlayerBuildingEnum aPStack_1c [4];
  undefined4 uStack_18;
  undefined4 uStack_4;
  
  uStack_4 = 0x11002b17;
  FUN_11007518();
  uStack_30 = 0;
  uStack_34 = 0;
  uStack_38 = 1;
  uStack_3c = 0x2e;
  TethysGame::CreateUnit(&DAT_11017044,2);
  pUVar6 = (Unit *)&DAT_11017040;
  this = (PlayerBuildingEnum *)
         PlayerBuildingEnum::PlayerBuildingEnum((PlayerBuildingEnum *)&uStack_30,1,0x2f);
  PlayerBuildingEnum::GetNext(this,pUVar6);
  PlayerBuildingEnum::PlayerBuildingEnum(aPStack_1c,1,0x30);
  PlayerBuildingEnum::GetNext(aPStack_1c,(Unit *)&DAT_11017038);
  Unit::SetFactoryCargo((Unit *)&DAT_11017040,0,0x30,0);
  pMVar1 = (MiningGroup *)CreateMiningGroup(&uStack_30);
  uStack_18 = 0;
  uStack_54 = 0x11002ba6;
  MiningGroup::operator=((MiningGroup *)&DAT_11017058,pMVar1);
  uStack_18 = 0xffffffff;
  ScStub::~ScStub((ScStub *)&uStack_3c);
  uStack_54 = DAT_110178fc;
  pMVar1 = (MiningGroup *)CreateMiningGroup(&uStack_3c);
  uStack_60 = 0x11002bdf;
  MiningGroup::operator=((MiningGroup *)&DAT_1101705c,pMVar1);
  ScStub::~ScStub(aSStack_3e + -10);
  uStack_60 = DAT_110178fc;
  pMVar1 = (MiningGroup *)CreateMiningGroup(aSStack_3e + -10);
  uStack_30 = 2;
  MiningGroup::operator=((MiningGroup *)&DAT_11017060,pMVar1);
  uStack_30 = 0xffffffff;
  ScStub::~ScStub((ScStub *)&uStack_54);
  pBVar2 = (BuildingGroup *)CreateBuildingGroup(&uStack_54);
  uStack_3c = 3;
  BuildingGroup::operator=((BuildingGroup *)&DAT_11017064,pBVar2);
  uStack_3c = 0xffffffff;
  ScStub::~ScStub((ScStub *)&uStack_60);
  ScGroup::SetTargCount((ScGroup *)&DAT_11017064,2,0,2);
  ScGroup::SetTargCount((ScGroup *)&DAT_11017064,0xf,0,1);
  ScGroup::SetTargCount((ScGroup *)&DAT_11017064,0xc,0,1);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)&uStack_60,0x3e,0x20,0x44,0x21);
  BuildingGroup::SetRect((BuildingGroup *)&DAT_11017064,pMVar3);
  ScGroup::TakeUnit((ScGroup *)&DAT_11017064);
  ScGroup::TakeUnit((ScGroup *)&DAT_11017064);
  FUN_110016a0();
  FUN_110016a0();
  pBVar2 = (BuildingGroup *)CreateBuildingGroup(aSStack_6e + 6);
  BuildingGroup::operator=((BuildingGroup *)&DAT_11017068,pBVar2);
  ScStub::~ScStub(aSStack_6e + -6);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_6e + -6),0x3e,0x20,0x44,0x21);
  BuildingGroup::SetRect((BuildingGroup *)&DAT_11017068,pMVar3);
  ScGroup::SetLights((ScGroup *)&DAT_11017068,1);
  pFVar4 = (FightGroup *)CreateFightGroup(aSStack_6e + -6);
  FightGroup::operator=((FightGroup *)&DAT_11017074,pFVar4);
  ScStub::~ScStub(aSStack_82 + 2);
  ScGroup::SetTargCount((ScGroup *)&DAT_11017074,5,0x3e,4);
  ScGroup::SetTargCount((ScGroup *)&DAT_11017074,5,0x40,2);
  ScGroup::SetTargCount((ScGroup *)&DAT_11017074,6,0x3e,3);
  ScGroup::SetTargCount((ScGroup *)&DAT_11017074,6,0x40,1);
  FightGroup::DoGuardRect((FightGroup *)&DAT_11017074);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_82 + 2),0x37,0x19,0x4c,0x29);
  FightGroup::SetRect((FightGroup *)&DAT_11017074,pMVar3);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_82 + 2),0x2e,0x2a,0x42,0x31);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_11017074,pMVar3);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_82 + 2),0x36,0x31,0x3c,0x3a);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_11017074,pMVar3);
  FightGroup::SetAttackType((FightGroup *)&DAT_11017074,5);
  pFVar4 = (FightGroup *)CreateFightGroup(aSStack_82 + 2);
  FightGroup::operator=((FightGroup *)&DAT_11017078,pFVar4);
  ScStub::~ScStub(aSStack_82 + -10);
  if (DAT_11017000 == '\0') {
    ScGroup::SetTargCount((ScGroup *)&DAT_11017078,5,0x3e,(-(uint)(DAT_11017002 != '\0') & 4) + 4);
    ScGroup::SetTargCount((ScGroup *)&DAT_11017078,5,0x40,(-(uint)(DAT_11017002 != '\0') & 2) + 1);
    if (DAT_11017002 != '\0') {
      ScGroup::SetTargCount((ScGroup *)&DAT_11017078,6,0x40,2);
      ScGroup::SetLights((ScGroup *)&DAT_11017078,0);
    }
  }
  pBVar2 = (BuildingGroup *)CreateBuildingGroup(aSStack_82 + -10);
  BuildingGroup::operator=((BuildingGroup *)&DAT_1101706c,pBVar2);
  ScStub::~ScStub(aSStack_82 + -0x16);
  ScGroup::TakeUnit((ScGroup *)&DAT_1101706c);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101706c,(ScGroup *)&DAT_11017074,2000);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101706c,(ScGroup *)&DAT_11017058,1000);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101706c,(ScGroup *)&DAT_1101705c,1000);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101706c,(ScGroup *)&DAT_11017060,500);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101706c,(ScGroup *)&DAT_11017064,4000);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101706c,(ScGroup *)&DAT_11017078,8000);
  if (DAT_11017002 != '\0') {
    pBVar2 = (BuildingGroup *)CreateBuildingGroup(aSStack_82 + -0x1a);
    BuildingGroup::operator=((BuildingGroup *)&DAT_11017070,pBVar2);
    ScStub::~ScStub(aSStack_82 + -0x1a);
    BuildingGroup::RecordVehReinforceGroup
              ((BuildingGroup *)&DAT_11017070,(ScGroup *)&DAT_11017078,8000);
    BuildingGroup::RecordBuilding
              ((BuildingGroup *)&DAT_11017064,(LOCATION *)(aSStack_82 + -0x1a),0x30,0,
               (ScGroup *)&DAT_11017070);
    FUN_11006180('\x01','\x01',1,0x30,2,0,FUN_1100311d,0);
  }
  pvVar5 = DAT_11017920;
  pFVar4 = (FightGroup *)CreateFightGroup(aSStack_82 + -0x1a);
  FightGroup::operator=((FightGroup *)&DAT_1101707c,pFVar4);
  ScStub::~ScStub(aSStack_82 + -0x26);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_82 + -0x26),0x52,0xb,0x59,0xe);
  FightGroup::SetRect((FightGroup *)&DAT_1101707c,pMVar3);
  pFVar4 = (FightGroup *)CreateFightGroup(aSStack_82 + -0x26);
  FightGroup::operator=((FightGroup *)&DAT_11017080,pFVar4);
  ScStub::~ScStub(aSStack_82 + -0x32);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_82 + -0x32),0x4a,0x16,0x4f,0x19);
  FightGroup::SetRect((FightGroup *)&DAT_11017080,pMVar3);
  ScGroup::SetLights((ScGroup *)&DAT_11017080,0);
  pFVar4 = (FightGroup *)CreateFightGroup(aSStack_82 + -0x32);
  FightGroup::operator=((FightGroup *)&DAT_11017084,pFVar4);
  ScStub::~ScStub(aSStack_eb + 0x2b);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_eb + 0x2b),0x4a,0x16,0x4f,0x19);
  FightGroup::SetRect((FightGroup *)&DAT_11017084,pMVar3);
  ScGroup::SetLights((ScGroup *)&DAT_11017084,0);
  pFVar4 = (FightGroup *)CreateFightGroup(aSStack_82 + -0x2e);
  FightGroup::operator=((FightGroup *)&DAT_11017088,pFVar4);
  ScStub::~ScStub(aSStack_eb + 0x2f);
  FUN_11006060('\x01','\x01',1,0xc,0xffffffff,1,0,FUN_11001ffe,0);
  ExceptionList = pvVar5;
  return;
}


// ---- 1100311d FUN_1100311d  (called by: -)

void FUN_1100311d(void)

{
  LocationEnumerator *this;
  int unaff_EBP;
  Unit *pUVar1;
  
  FUN_11007518();
  pUVar1 = (Unit *)&DAT_1101703c;
  *(undefined4 *)(unaff_EBP + -0x18) = 0x39;
  *(undefined4 *)(unaff_EBP + -0x14) = 0x1a;
  this = (LocationEnumerator *)
         LocationEnumerator::LocationEnumerator
                   ((LocationEnumerator *)(unaff_EBP + -0x50),(LOCATION *)(unaff_EBP + -0x18));
  LocationEnumerator::GetNext(this,pUVar1);
  BuildingGroup::UnRecordVehGroup((BuildingGroup *)&DAT_1101706c,(ScGroup *)&DAT_11017078);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_11017070,(ScGroup *)&DAT_11017078,8000);
  if (DAT_110170a8 == 1) {
    FUN_11001d2d((ScStub *)&DAT_110178e8);
    CreateSpecialTarget(unaff_EBP + -0x10,1,(Unit *)0x1,0x1101703c,(char *)0xb);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    CreateVictoryCondition(unaff_EBP + -0x14,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x10));
    ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  }
  else {
    CreateSpecialTarget(unaff_EBP + -0x1c,1,(Unit *)0x1,0x1101703c,(char *)0xb);
    ScStub::~ScStub((ScStub *)(unaff_EBP + -0x1c));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 110031fd FUN_110031fd  (called by: InitProc@11004475)

void FUN_110031fd(void)

{
  int iVar1;
  PlayerUnitEnum local_10 [8];
  IUnit local_8 [4];
  
  IUnit::IUnit(local_8);
  PlayerUnitEnum::PlayerUnitEnum(local_10,0);
  while( true ) {
    iVar1 = PlayerUnitEnum::GetNext(local_10,(Unit *)local_8);
    if (iVar1 == 0) break;
    Unit::DoSetLights((Unit *)local_8,0);
  }
  return;
}


// ---- 11003241 FUN_11003241  (called by: -)

void FUN_11003241(void)

{
                    /* WARNING: Could not recover jumptable at 0x11003246. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::DoAttackEnemy((FightGroup *)&DAT_11017078);
  return;
}


// ---- 1100324c StatusProc  (called by: -)

undefined4 StatusProc(void)

{
                    /* 0x324c  11  StatusProc */
  return 0;
}


// ---- 1100324f NoResponseToTrigger  (called by: -)

void NoResponseToTrigger(void)

{
                    /* 0x324f  10  NoResponseToTrigger */
  return;
}


// ---- 11003250 FUN_11003250  (called by: FUN_11003d79@11003d79, FUN_11003e72@11003e72, gotPanther@110032b7, gotScientists@110033c1)

void __cdecl FUN_11003250(char *param_1)

{
  TethysGame::AddMessage(-1,-1,param_1,0,0x7a);
  return;
}


// ---- 11003264 gotNothing  (called by: -)

void gotNothing(void)

{
                    /* 0x3264  14  gotNothing */
  TethysGame::AddMessage(-1,-1,s_Nothing_found__110106d4,0,0x59);
  return;
}


// ---- 11003279 gotRPG  (called by: -)

void gotRPG(void)

{
                    /* 0x3279  16  gotRPG */
  DAT_110178cc = 1;
  TethysGame::AddMessage(-1,-1,s_Retrieved_RPG_data__110106e4,0,0xb6);
  return;
}


// ---- 11003298 gotRareOre  (called by: -)

void gotRareOre(void)

{
                    /* 0x3298  17  gotRareOre */
  DAT_110178cd = 1;
  TethysGame::AddMessage(-1,-1,s_Retrieved_Rare_Ore_technologies_110106f8,0,0xb4);
  return;
}


// ---- 110032b7 gotPanther  (called by: -)

void gotPanther(void)

{
  Trigger *pTVar1;
  Trigger local_8 [2];
  Trigger aTStack_6 [2];
  undefined1 local_4 [4];
  
                    /* 0x32b7  15  gotPanther */
  DAT_110178ce = 1;
  TethysGame::AddMessage(-1,-1,s_Retrieved_Panther_design_plans_11010770,0,0xb6);
  Trigger::Trigger(local_8);
  pTVar1 = (Trigger *)CreateCountTrigger((int)local_4,1,0,1,0x29,-1,0,(char *)0x0);
  Trigger::operator=(local_8 + -4,pTVar1);
  ScStub::~ScStub((ScStub *)local_8);
  CreateVictoryCondition((int)local_8,1,(Trigger *)0x0,(char *)(local_8 + -4));
  ScStub::~ScStub((ScStub *)(local_8 + -4));
  FUN_11006060('\x01','\x01',1,0x29,0xffffffff,2,3,FUN_1100415c,0);
  FUN_11006060('\x01','\x01',1,0x29,0xffffffff,1,3,FUN_1100415c,0);
  pTVar1 = (Trigger *)CreateCountTrigger((int)(local_8 + -4),1,0,1,0x30,-1,0,(char *)0x0);
  Trigger::operator=(local_8 + -0xc,pTVar1);
  ScStub::~ScStub((ScStub *)(local_8 + -8));
  CreateVictoryCondition((int)(local_8 + -8),1,(Trigger *)0x0,(char *)(local_8 + -0xc));
  ScStub::~ScStub((ScStub *)(local_8 + -0xc));
  FUN_11003250(s_Destroy_all_vehicle_factories_an_11010718);
  ScStub::~ScStub((ScStub *)(local_8 + -0x10));
  return;
}


// ---- 110033c1 gotScientists  (called by: -)

void gotScientists(void)

{
  ScStub local_c [4];
  ScStub local_8 [4];
  
                    /* 0x33c1  18  gotScientists */
  DAT_110178d0 = 1;
  TethysGame::AddMessage(-1,-1,s_Scientists_captured_110107c4,0,0xb2);
  Unit::SetCargo((Unit *)&DAT_11017014,5,0);
  CreateEscapeTrigger((int)local_8,1,0,0,DAT_11011840 + -6,DAT_11011844 + -6,0xc,0xc,1,0xd,5,
                      (char *)0x0);
  CreateVictoryCondition((int)local_c,1,(Trigger *)0x0,(char *)local_8);
  ScStub::~ScStub(local_c);
  FUN_11003250(s_New_objective_11010790);
  ScStub::~ScStub(local_8);
  return;
}


// ---- 11003458 gotCodes  (called by: -)

void gotCodes(void)

{
                    /* 0x3458  13  gotCodes */
  DAT_110178cf = 1;
  TethysGame::AddMessage(-1,-1,s_Retrieved_security_codes__110107d8,0,0xa0);
  return;
}


// ---- 11003477 FUN_11003477  (called by: FUN_11003d6a@11003d6a, FUN_110040a2@110040a2, FUN_110040de@110040de, FUN_110041bf@110041bf, FUN_110041ce@110041ce, FUN_110041e6@110041e6, FUN_11004204@11004204, FUN_1100421c@1100421c, FUN_11004234@11004234)

void FUN_11003477(void)

{
  int unaff_EBP;
  
  FUN_11007518();
  CreateTimeTrigger(unaff_EBP + -0x10,1,1,(char *)0xa);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  CreateFailureCondition(unaff_EBP + -0x14,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x10));
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 110034d5 FUN_110034d5  (called by: InitProc@11004475)

void FUN_110034d5(void)

{
  Trigger *pTVar1;
  int unaff_EBP;
  code *pcVar2;
  undefined *puVar3;
  char *pcVar4;
  char *pcVar5;
  
  FUN_11007518();
  IUnit::IUnit((IUnit *)(unaff_EBP + -0x44));
  IUnit::IUnit((IUnit *)(unaff_EBP + -0x2c));
  IUnit::IUnit((IUnit *)(unaff_EBP + -0x30));
  IUnit::IUnit((IUnit *)(unaff_EBP + -0x38));
  IUnit::IUnit((IUnit *)(unaff_EBP + -0x28));
  IUnit::IUnit((IUnit *)(unaff_EBP + -0x34));
  IUnit::IUnit((IUnit *)(unaff_EBP + -0x1c));
  IUnit::IUnit((IUnit *)(unaff_EBP + -0x24));
  IUnit::IUnit((IUnit *)(unaff_EBP + -0x20));
  Trigger::Trigger((Trigger *)(unaff_EBP + -0x14));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  Trigger::Trigger((Trigger *)(unaff_EBP + -0x54));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  Trigger::Trigger((Trigger *)(unaff_EBP + -0x4c));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  PlayerBuildingEnum::PlayerBuildingEnum((PlayerBuildingEnum *)(unaff_EBP + -0x74),1,0x32);
  PlayerBuildingEnum::PlayerBuildingEnum((PlayerBuildingEnum *)(unaff_EBP + -0x94),1,0x38);
  PlayerBuildingEnum::PlayerBuildingEnum((PlayerBuildingEnum *)(unaff_EBP + -0x84),1,0x31);
  PlayerBuildingEnum::PlayerBuildingEnum((PlayerBuildingEnum *)(unaff_EBP + -0x8c),1,0x26);
  PlayerBuildingEnum::PlayerBuildingEnum((PlayerBuildingEnum *)(unaff_EBP + -0x9c),1,0x1f);
  PlayerBuildingEnum::PlayerBuildingEnum((PlayerBuildingEnum *)(unaff_EBP + -0x7c),1,0x1c);
  PlayerBuildingEnum::GetNext((PlayerBuildingEnum *)(unaff_EBP + -0x74),(Unit *)(unaff_EBP + -0x2c))
  ;
  PlayerBuildingEnum::GetNext((PlayerBuildingEnum *)(unaff_EBP + -0x74),(Unit *)(unaff_EBP + -0x30))
  ;
  PlayerBuildingEnum::GetNext((PlayerBuildingEnum *)(unaff_EBP + -0x94),(Unit *)(unaff_EBP + -0x38))
  ;
  PlayerBuildingEnum::GetNext((PlayerBuildingEnum *)(unaff_EBP + -0x84),(Unit *)(unaff_EBP + -0x28))
  ;
  PlayerBuildingEnum::GetNext((PlayerBuildingEnum *)(unaff_EBP + -0x8c),(Unit *)(unaff_EBP + -0x34))
  ;
  PlayerBuildingEnum::GetNext((PlayerBuildingEnum *)(unaff_EBP + -0x9c),(Unit *)(unaff_EBP + -0x20))
  ;
  PlayerBuildingEnum::GetNext((PlayerBuildingEnum *)(unaff_EBP + -0x7c),(Unit *)(unaff_EBP + -0x1c))
  ;
  PlayerBuildingEnum::GetNext((PlayerBuildingEnum *)(unaff_EBP + -0x7c),(Unit *)(unaff_EBP + -0x24))
  ;
  Unit::SetOppFiredUpon((Unit *)(unaff_EBP + -0x2c),0);
  Unit::SetOppFiredUpon((Unit *)(unaff_EBP + -0x30),0);
  Unit::SetOppFiredUpon((Unit *)(unaff_EBP + -0x28),0);
  Unit::SetOppFiredUpon((Unit *)(unaff_EBP + -0x34),0);
  Unit::SetOppFiredUpon((Unit *)(unaff_EBP + -0x20),0);
  Unit::SetOppFiredUpon((Unit *)(unaff_EBP + -0x1c),0);
  Unit::SetOppFiredUpon((Unit *)(unaff_EBP + -0x24),0);
  Unit::SetOppFiredUpon((Unit *)&DAT_11017038,0);
  if (DAT_11017002 != '\0') {
    Unit::SetOppFiredUpon((Unit *)&DAT_1101703c,0);
  }
  if (DAT_110170b4 == 1) {
    pTVar1 = (Trigger *)
             CreateSpecialTarget(unaff_EBP + -0x10,1,(Unit *)0x1,unaff_EBP - 0x28,(char *)0xd);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    Trigger::operator=((Trigger *)(unaff_EBP + -0x14),pTVar1);
    pcVar2 = ~ScStub_exref;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
    Unit::SetCargo((Unit *)(unaff_EBP + -0x28),5,0);
    pcVar5 = s_Capture_Plymouth_scientists_11010880;
    CreateVictoryCondition(unaff_EBP + -0x10,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x14));
    ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
    pcVar4 = s_gotNothing_1101069c;
    CreateSpecialTarget(unaff_EBP + -0x10,1,(Unit *)0x1,unaff_EBP - 0x34,(char *)0xd);
  }
  else {
    pTVar1 = (Trigger *)
             CreateSpecialTarget(unaff_EBP + -0x10,1,(Unit *)0x1,unaff_EBP - 0x34,(char *)0xd);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    Trigger::operator=((Trigger *)(unaff_EBP + -0x14),pTVar1);
    pcVar2 = ~ScStub_exref;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
    Unit::SetCargo((Unit *)(unaff_EBP + -0x34),5,0);
    pcVar5 = s_Capture_Plymouth_scientists_11010880;
    CreateVictoryCondition(unaff_EBP + -0x10,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x14));
    ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
    pcVar4 = s_gotNothing_1101069c;
    CreateSpecialTarget(unaff_EBP + -0x10,1,(Unit *)0x1,unaff_EBP - 0x28,(char *)0xd);
  }
  (*pcVar2)(pcVar4,pcVar5);
  pcVar4 = s_NoResponseToTrigger_110100f4;
  pTVar1 = (Trigger *)CreateCountTrigger(unaff_EBP + -0x10,1,0,0,0xd,-1,0,(char *)0x0);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  Trigger::operator=((Trigger *)(unaff_EBP + -0x14),pTVar1);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  (*pcVar2)(pcVar4);
  puVar3 = &DAT_11011788;
  CreateFailureCondition(unaff_EBP + -0x10,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x14));
  (*pcVar2)(puVar3);
  if (DAT_110170ac == 1) {
    Unit::operator=((Unit *)&DAT_1101701c,(Unit *)(unaff_EBP + -0x2c));
    pcVar4 = s_gotRPG_11010878;
    pTVar1 = (Trigger *)
             CreateSpecialTarget(unaff_EBP + -0x10,1,(Unit *)0x1,unaff_EBP - 0x2c,(char *)0xb);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    Trigger::operator=((Trigger *)(unaff_EBP + -0x14),pTVar1);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    (*pcVar2)(pcVar4);
    pcVar4 = s_Transmit_RPG_data_11010864;
    CreateVictoryCondition(unaff_EBP + -0x10,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x14));
    (*pcVar2)(pcVar4);
    pcVar4 = s_gotNothing_1101069c;
    CreateSpecialTarget(unaff_EBP + -0x10,1,(Unit *)0x1,unaff_EBP - 0x30,(char *)0xb);
  }
  else {
    Unit::operator=((Unit *)&DAT_1101701c,(Unit *)(unaff_EBP + -0x30));
    pcVar4 = s_gotRPG_11010878;
    pTVar1 = (Trigger *)
             CreateSpecialTarget(unaff_EBP + -0x10,1,(Unit *)0x1,unaff_EBP - 0x30,(char *)0xb);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    Trigger::operator=((Trigger *)(unaff_EBP + -0x14),pTVar1);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    (*pcVar2)(pcVar4);
    pcVar4 = s_Transmit_RPG_data_11010864;
    CreateVictoryCondition(unaff_EBP + -0x10,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x14));
    (*pcVar2)(pcVar4);
    pcVar4 = s_gotNothing_1101069c;
    CreateSpecialTarget(unaff_EBP + -0x10,1,(Unit *)0x1,unaff_EBP - 0x2c,(char *)0xb);
  }
  (*pcVar2)(pcVar4);
  pcVar4 = s_gotRareOre_11010858;
  pTVar1 = (Trigger *)
           CreateSpecialTarget(unaff_EBP + -0x10,1,(Unit *)0x1,unaff_EBP - 0x38,(char *)0xb);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  Trigger::operator=((Trigger *)(unaff_EBP + -0x14),pTVar1);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  (*pcVar2)(pcVar4);
  pcVar4 = s_Transmit_Rare_Ore_technologies_11010838;
  CreateVictoryCondition(unaff_EBP + -0x10,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x14));
  (*pcVar2)(pcVar4);
  if (DAT_110170a8 == 0) {
    pcVar4 = s_gotPanther_110106c8;
    pTVar1 = (Trigger *)CreateSpecialTarget(unaff_EBP + -0x10,1,(Unit *)0x1,0x11017038,(char *)0xb);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    Trigger::operator=((Trigger *)(unaff_EBP + -0x14),pTVar1);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    (*pcVar2)(pcVar4);
    pcVar4 = s_Transmit_Panther_design_plans_110106a8;
    pTVar1 = (Trigger *)
             CreateVictoryCondition(unaff_EBP + -0x10,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x14));
    *(undefined1 *)(unaff_EBP + -4) = 10;
    Trigger::operator=((Trigger *)&DAT_110178e8,pTVar1);
    *(undefined1 *)(unaff_EBP + -4) = 2;
  }
  else {
    pcVar4 = s_gotNothing_1101069c;
    CreateSpecialTarget(unaff_EBP + -0x10,1,(Unit *)0x1,0x11017038,(char *)0xb);
    (*pcVar2)(pcVar4);
    pcVar4 = s_NoResponseToTrigger_110100f4;
    pTVar1 = (Trigger *)CreateTimeTrigger(unaff_EBP + -0x10,1,1,(char *)0x98967f);
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    Trigger::operator=((Trigger *)(unaff_EBP + -0x14),pTVar1);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    (*pcVar2)(pcVar4);
    pcVar4 = s_Transmit_Panther_design_plans_110106a8;
    pTVar1 = (Trigger *)
             CreateVictoryCondition(unaff_EBP + -0x10,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x14));
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    Trigger::operator=((Trigger *)&DAT_110178e8,pTVar1);
    *(undefined1 *)(unaff_EBP + -4) = 2;
  }
  (*pcVar2)(pcVar4);
  if (DAT_110170b0 == 0) {
    Unit::operator=((Unit *)&DAT_11017018,(Unit *)(unaff_EBP + -0x20));
    pcVar4 = s_gotCodes_1101082c;
    pTVar1 = (Trigger *)
             CreateSpecialTarget(unaff_EBP + -0x58,1,(Unit *)0x1,unaff_EBP - 0x20,(char *)0xb);
    *(undefined1 *)(unaff_EBP + -4) = 0xd;
    Trigger::operator=((Trigger *)(unaff_EBP + -0x14),pTVar1);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    (*pcVar2)(pcVar4);
    pcVar4 = s_Transmit_security_codes_11010814;
    CreateVictoryCondition(unaff_EBP + -0x6c,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x14));
    (*pcVar2)(pcVar4);
    pcVar4 = s_gotNothing_1101069c;
    CreateSpecialTarget(unaff_EBP + -0x60,1,(Unit *)0x1,unaff_EBP - 0x1c,(char *)0xb);
    (*pcVar2)(pcVar4);
    pcVar4 = s_gotNothing_1101069c;
    CreateSpecialTarget(unaff_EBP + -0x18,1,(Unit *)0x1,unaff_EBP - 0x24,(char *)0xb);
  }
  else if (DAT_110170b0 == 1) {
    Unit::operator=((Unit *)&DAT_11017018,(Unit *)(unaff_EBP + -0x1c));
    pcVar4 = s_gotCodes_1101082c;
    pTVar1 = (Trigger *)
             CreateSpecialTarget(unaff_EBP + -0x48,1,(Unit *)0x1,unaff_EBP - 0x1c,(char *)0xb);
    *(undefined1 *)(unaff_EBP + -4) = 0xe;
    Trigger::operator=((Trigger *)(unaff_EBP + -0x14),pTVar1);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    (*pcVar2)(pcVar4);
    pcVar4 = s_Transmit_security_codes_11010814;
    CreateVictoryCondition(unaff_EBP + -0x3c,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x14));
    (*pcVar2)(pcVar4);
    pcVar4 = s_gotNothing_1101069c;
    CreateSpecialTarget(unaff_EBP + -0x50,1,(Unit *)0x1,unaff_EBP - 0x20,(char *)0xb);
    (*pcVar2)(pcVar4);
    pcVar4 = s_gotNothing_1101069c;
    CreateSpecialTarget(unaff_EBP + -100,1,(Unit *)0x1,unaff_EBP - 0x24,(char *)0xb);
  }
  else {
    if (DAT_110170b0 != 2) goto LAB_11003b1d;
    Unit::operator=((Unit *)&DAT_11017018,(Unit *)(unaff_EBP + -0x24));
    pcVar4 = s_gotCodes_1101082c;
    pTVar1 = (Trigger *)
             CreateSpecialTarget(unaff_EBP + -0x10,1,(Unit *)0x1,unaff_EBP - 0x24,(char *)0xb);
    *(undefined1 *)(unaff_EBP + -4) = 0xf;
    Trigger::operator=((Trigger *)(unaff_EBP + -0x14),pTVar1);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    (*pcVar2)(pcVar4);
    pcVar4 = s_Transmit_security_codes_11010814;
    CreateVictoryCondition(unaff_EBP + -0x5c,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x14));
    (*pcVar2)(pcVar4);
    pcVar4 = s_gotNothing_1101069c;
    CreateSpecialTarget(unaff_EBP + -0x40,1,(Unit *)0x1,unaff_EBP - 0x20,(char *)0xb);
    (*pcVar2)(pcVar4);
    pcVar4 = s_gotNothing_1101069c;
    CreateSpecialTarget(unaff_EBP + -0x68,1,(Unit *)0x1,unaff_EBP - 0x1c,(char *)0xb);
  }
  (*pcVar2)(pcVar4);
LAB_11003b1d:
  TethysGame::CreateUnit(&DAT_1101700c,0x29,0x42,0x24,1,0,0);
  TethysGame::CreateUnit(&DAT_11017010,0x29,0x42,0x27,1,0,0);
  Unit::SetOppFiredUpon((Unit *)&DAT_1101700c,0);
  Unit::SetOppFiredUpon((Unit *)&DAT_11017010,0);
  FUN_11006060('\x01','\x01',1,0x38,0xffffffff,1,3,FUN_110041bf,0);
  FUN_11006060('\x01','\x01',1,0x1f,0xffffffff,1,3,FUN_110041ce,0);
  FUN_11006060('\x01','\x01',1,0x1c,0xffffffff,2,3,FUN_110041e6,0);
  FUN_11006060('\x01','\x01',1,0x1c,0xffffffff,1,3,FUN_110041e6,0);
  FUN_11006060('\x01','\x01',1,0x31,0xffffffff,1,3,FUN_11004204,0);
  FUN_11006060('\x01','\x01',1,0x26,0xffffffff,1,3,FUN_1100421c,0);
  FUN_11006060('\x01','\x01',1,0x32,0xffffffff,2,3,FUN_11004234,0);
  FUN_11006060('\x01','\x01',1,0x32,0xffffffff,1,3,FUN_11004234,0);
  FUN_11006060('\x01','\x01',1,0x30,0xffffffff,1,3,FUN_110040a2,0);
  if (DAT_11017002 != '\0') {
    FUN_11006060('\x01','\x01',1,0x30,0xffffffff,2,3,FUN_110040de,0);
  }
  FUN_11006060('\x01','\x01',0,0xb,0xffffffff,1,3,FUN_11003d6a,0);
  pcVar4 = s_NoResponseToTrigger_110100f4;
  pTVar1 = (Trigger *)CreateCountTrigger(unaff_EBP + -0x18,1,0,0,3,-1,1,(char *)0x0);
  *(undefined1 *)(unaff_EBP + -4) = 0x10;
  Trigger::operator=((Trigger *)(unaff_EBP + -0x14),pTVar1);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  (*pcVar2)(pcVar4);
  pcVar4 = s_Spider_prototype_must_survive_110107f4;
  CreateVictoryCondition(unaff_EBP + -0x18,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x14));
  (*pcVar2)(pcVar4);
  pcVar4 = s_NoResponseToTrigger_110100f4;
  pTVar1 = (Trigger *)CreateCountTrigger(unaff_EBP + -0x18,1,0,0,3,-1,0,(char *)0x0);
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  Trigger::operator=((Trigger *)(unaff_EBP + -0x14),pTVar1);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  (*pcVar2)(pcVar4);
  puVar3 = &DAT_11011788;
  CreateFailureCondition(unaff_EBP + -0x18,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x14));
  (*pcVar2)(puVar3);
  TethysGame::PlaceMarker((Unit *)(unaff_EBP + -0x44),DAT_11011840,DAT_11011844,0);
  TethysGame::CreateUnit(&DAT_11017014,0xd,0x47,0x7d,0,0,6);
  Unit::DoSetLights((Unit *)&DAT_11017014,1);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  (*pcVar2)();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  (*pcVar2)();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (*pcVar2)();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11003d6a FUN_11003d6a  (called by: -)

void FUN_11003d6a(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_11002335();
  if ((char)uVar1 == '\0') {
    FUN_11003477();
    return;
  }
  return;
}


// ---- 11003d79 FUN_11003d79  (called by: -)

void FUN_11003d79(void)

{
  Trigger *pTVar1;
  int unaff_EBP;
  
  FUN_11007518();
  Trigger::Trigger((Trigger *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  IUnit::SetOffensive((IUnit *)&DAT_11017054,false);
  pTVar1 = (Trigger *)
           CreateEscapeTrigger(unaff_EBP + -0x14,1,0,0,DAT_11011840 + -6,DAT_11011844 + -6,0xc,0xc,1
                               ,6,-1,(char *)0x0);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  Trigger::operator=((Trigger *)(unaff_EBP + -0x10),pTVar1);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  CreateVictoryCondition(unaff_EBP + -0x14,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x10));
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  pTVar1 = (Trigger *)CreateCountTrigger(unaff_EBP + -0x14,1,0,0,6,0x3e,0,(char *)0x0);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  Trigger::operator=((Trigger *)(unaff_EBP + -0x10),pTVar1);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  CreateFailureCondition(unaff_EBP + -0x14,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x10));
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  FUN_11003250(s_New_objective_11010790);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11003e72 FUN_11003e72  (called by: FUN_110040a2@110040a2, FUN_110040de@110040de, FUN_1100415c@1100415c)

void FUN_11003e72(void)

{
  Trigger *pTVar1;
  int unaff_EBP;
  
  FUN_11007518();
  if (DAT_110178d1 == '\0') {
    IUnit::IUnit((IUnit *)(unaff_EBP + -0x18));
    TethysGame::CreateWreck(DAT_11017094,DAT_11017098,0,1);
    GameMap::SetTile(0x66f);
    GameMap::SetCellType(4);
    CreateEscapeTrigger(unaff_EBP + -0x10,1,0,0,DAT_11011840 + -6,DAT_11011844 + -6,0xc,0xc,1,1,9,
                        (char *)0x1);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    CreateVictoryCondition(unaff_EBP + -0x14,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x10));
    ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
    FUN_11006060('\x01','\x01',0,1,9,1,0,FUN_11004027,0);
    pTVar1 = (Trigger *)CreateCountTrigger(unaff_EBP + -0x14,1,0,0,1,-1,0,(char *)0x0);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    Trigger::operator=((Trigger *)(unaff_EBP + -0x10),pTVar1);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
    CreateFailureCondition(unaff_EBP + -0x14,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x10));
    ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
    FUN_11003250(s_New_objective_11010790);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    DAT_110178d1 = '\x01';
    ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11003fb2 FUN_11003fb2  (called by: FUN_110040a2@110040a2, FUN_110040de@110040de, FUN_1100415c@1100415c)

void __cdecl FUN_11003fb2(undefined4 param_1,undefined4 param_2)

{
  IUnit local_8 [4];
  
  if (DAT_110178d2 == '\0') {
    IUnit::IUnit(local_8);
    TethysGame::CreateUnit(local_8,6,param_1,param_2,3,0x3e,0);
    Unit::SetDamage((Unit *)local_8,0xfa);
    IUnit::SetEMPticks(local_8,-1);
    IUnit::SetOffensive(local_8,false);
    FUN_11006060('\x01','\x01',0,6,0x3e,0,4,FUN_11003d79,0);
    DAT_110178d2 = '\x01';
  }
  return;
}


// ---- 11004027 FUN_11004027  (called by: -)

void FUN_11004027(void)

{
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  FUN_11007518();
  GameMap::SetTile(DAT_1101709c,extraout_EDX,DAT_11017094,DAT_11017098);
  CreateCountTrigger(unaff_EBP + -0x10,1,1,0,1,9,0,(char *)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  CreateFailureCondition(unaff_EBP + -0x14,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x10));
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 110040a2 FUN_110040a2  (called by: -)

void FUN_110040a2(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (DAT_110178ce == '\0') {
    FUN_11003477();
  }
  if (DAT_110170a0 == 0) {
    FUN_11003e72();
  }
  if (DAT_110170a4 == 0) {
    uVar2 = 0x2e;
    uVar1 = 0x40;
  }
  else {
    if (DAT_110170a4 != 3) {
      return;
    }
    uVar2 = 0x1a;
    uVar1 = 0x3a;
  }
  FUN_11003fb2(uVar1,uVar2);
  return;
}


// ---- 110040de FUN_110040de  (called by: -)

void FUN_110040de(void)

{
  int iVar1;
  
  iVar1 = Unit::IsLive((Unit *)&DAT_11017038);
  if (iVar1 == 0) {
    if (DAT_110170a0 == 0) {
      FUN_11003e72();
    }
    if (DAT_110170a4 == 0) {
      FUN_11003fb2(0x40,0x2e);
      if (DAT_110178ce == '\0') {
        FUN_11003477();
      }
    }
  }
  iVar1 = Unit::IsLive((Unit *)&DAT_1101703c);
  if (iVar1 == 0) {
    if (DAT_110170a0 == 3) {
      FUN_11003e72();
    }
    if (DAT_110170a4 == 3) {
      FUN_11003fb2(0x3a,0x1a);
      if (DAT_110178ce == '\0') {
        FUN_11003477();
        return;
      }
    }
  }
  return;
}


// ---- 1100415c FUN_1100415c  (called by: -)

void FUN_1100415c(void)

{
  int iVar1;
  
  iVar1 = Unit::IsLive((Unit *)&DAT_1101700c);
  if (iVar1 == 0) {
    if (DAT_110170a0 == 1) {
      FUN_11003e72();
    }
    if (DAT_110170a4 == 1) {
      FUN_11003fb2(0x42,0x24);
    }
  }
  iVar1 = Unit::IsLive((Unit *)&DAT_11017010);
  if (iVar1 == 0) {
    if (DAT_110170a0 == 2) {
      FUN_11003e72();
    }
    if (DAT_110170a4 == 2) {
      FUN_11003fb2(0x42,0x27);
    }
  }
  return;
}


// ---- 110041bf FUN_110041bf  (called by: -)

void FUN_110041bf(void)

{
  if (DAT_110178cd == '\0') {
    FUN_11003477();
    return;
  }
  return;
}


// ---- 110041ce FUN_110041ce  (called by: -)

void FUN_110041ce(void)

{
  if ((DAT_110178cf == '\0') && (DAT_110170b0 == 0)) {
    FUN_11003477();
    return;
  }
  return;
}


// ---- 110041e6 FUN_110041e6  (called by: -)

void FUN_110041e6(void)

{
  int iVar1;
  
  if (DAT_110178cf == '\0') {
    iVar1 = Unit::IsLive((Unit *)&DAT_11017018);
    if (iVar1 == 0) {
      FUN_11003477();
      return;
    }
  }
  return;
}


// ---- 11004204 FUN_11004204  (called by: -)

void FUN_11004204(void)

{
  if ((DAT_110178d0 == '\0') && (DAT_110170b4 == 0)) {
    FUN_11003477();
    return;
  }
  return;
}


// ---- 1100421c FUN_1100421c  (called by: -)

void FUN_1100421c(void)

{
  if ((DAT_110178d0 == '\0') && (DAT_110170b4 == 1)) {
    FUN_11003477();
    return;
  }
  return;
}


// ---- 11004234 FUN_11004234  (called by: -)

void FUN_11004234(void)

{
  int iVar1;
  
  if (DAT_110178cc == '\0') {
    iVar1 = Unit::IsLive((Unit *)&DAT_1101701c);
    if (iVar1 == 0) {
      FUN_11003477();
      return;
    }
  }
  return;
}


// ---- 11004252 FUN_11004252  (called by: FUN_11004267@11004267)

bool FUN_11004252(void)

{
  int iVar1;
  
  iVar1 = _Player::Difficulty((_Player *)&DAT_11017908);
  return DAT_110118d0 != iVar1;
}


// ---- 11004267 FUN_11004267  (called by: InitProc@11004475)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_11004267(void)

{
  bool bVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_11007518();
  puVar3 = operator_new(8);
  *(undefined4 **)(unaff_EBP + -0x20) = puVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar3 == (undefined4 *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
  }
  else {
    FUN_11005083(puVar3);
    *(undefined4 **)(unaff_EBP + -0x14) = puVar3;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  IUnit::IUnit((IUnit *)(unaff_EBP + -0x1c));
  FUN_11004e3c((uint3)extraout_ECX,s_Q03_mis_11010940);
  bVar1 = FUN_11004252();
  iVar5 = DAT_110118d0;
  if (bVar1) {
    *(undefined **)(unaff_EBP + -0x2c) = &DAT_11010938;
    DAT_11017000 = iVar5 == 0;
    *(char **)(unaff_EBP + -0x28) = s_medium_11010930;
    _DAT_11017008 = iVar5 * 2;
    *(undefined **)(unaff_EBP + -0x24) = &DAT_11010928;
    DAT_11017001 = iVar5 == 1;
    DAT_11017002 = iVar5 == 2;
    DAT_11017004 = iVar5;
    scr_snprintf(&DAT_1101513c,0x50,&DAT_110108f8,*(undefined4 *)(unaff_EBP + -0x2c + iVar5 * 4));
    (*DAT_11010aac)(s_Renegades_110108ec,0);
  }
  uVar4 = FUN_11004ee9(s_Q03_mis_11010940,*(void **)(unaff_EBP + -0x14));
  *(char *)(unaff_EBP + -0xd) = (char)uVar4;
  if ((char)uVar4 != '\0') {
    iVar5 = FUN_11004fbb(0,*(int **)(unaff_EBP + -0x14),5,0x3e);
    iVar6 = FUN_11004fbb(0,*(int **)(unaff_EBP + -0x14),5,0x47);
    iVar7 = ((iVar6 + iVar5) * 5) / 4;
    *(int *)(unaff_EBP + -0x18) = iVar7;
    if (iVar7 == 0) {
      uVar2 = 0;
      goto LAB_11004466;
    }
    iVar7 = ((iVar5 * 5 + 5) * 2) / *(int *)(unaff_EBP + -0x18);
    iVar6 = ((iVar6 * 5 + 5) * 2) / *(int *)(unaff_EBP + -0x18);
    *(int *)(unaff_EBP + -0x18) = iVar6;
    for (iVar5 = iVar5 - iVar7; (4 < iVar6 && (iVar5 != 0)); iVar5 = iVar5 + -1) {
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + -1;
      *(int *)(unaff_EBP + -0x18) = iVar6;
    }
    if (iVar6 + iVar7 < 8) {
      do {
        if (iVar5 < 1) {
          iVar6 = iVar6 + 1;
        }
        else {
          iVar5 = iVar5 + -1;
          iVar7 = iVar7 + 1;
        }
      } while (iVar6 + iVar7 < 8);
      *(int *)(unaff_EBP + -0x18) = iVar6;
    }
    if (8 < iVar6 + iVar7) {
      do {
        if (iVar5 < 1) {
          iVar6 = iVar6 + -1;
        }
        else {
          iVar7 = iVar7 + -1;
          iVar5 = iVar5 + 1;
        }
      } while (8 < iVar6 + iVar7);
      *(int *)(unaff_EBP + -0x18) = iVar6;
    }
    iVar5 = 0;
    if (0 < iVar7) {
      puVar3 = &DAT_11011800;
      *(int *)(unaff_EBP + -0x20) = iVar7;
      do {
        TethysGame::CreateUnit(unaff_EBP + -0x1c,5,*puVar3,puVar3[1],0,0x3e,6);
        puVar3 = puVar3 + 2;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      iVar5 = *(int *)(unaff_EBP + -0x20);
      iVar6 = *(int *)(unaff_EBP + -0x18);
    }
    if (0 < iVar6) {
      puVar3 = &DAT_11011800 + iVar5 * 2;
      do {
        TethysGame::CreateUnit(unaff_EBP + -0x1c,5,*puVar3,puVar3[1],0,0x47,6);
        puVar3 = puVar3 + 2;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    FUN_110050ff(*(int **)(unaff_EBP + -0x14));
  }
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    thunk_FUN_110050d5(*(undefined4 **)(unaff_EBP + -0x14));
    FUN_110075f6(*(LPVOID *)(unaff_EBP + -0x14));
  }
  uVar2 = *(undefined1 *)(unaff_EBP + -0xd);
LAB_11004466:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}


// ---- 11004475 InitProc  (called by: -)

undefined4 InitProc(void)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  LOCATION *pLVar4;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
                    /* 0x4475  7  InitProc */
  bVar1 = FUN_11005120();
  if (!bVar1) {
    (*DAT_11010aac)(s_Renegades_110108ec,0);
    return 0;
  }
  DAT_11017004 = _Player::Difficulty((_Player *)&DAT_11017908);
  _Player::GoPlymouth((_Player *)&DAT_11017908);
  _Player::GoHuman((_Player *)&DAT_11017908);
  _Player::SetColorNumber((_Player *)&DAT_11017908,3);
  _Player::SetTechLevel((_Player *)&DAT_11017908,0);
  _Player::SetOre((_Player *)&DAT_11017908,10000);
  _Player::SetRareOre((_Player *)&DAT_11017908,10000);
  _Player::AllyWith((_Player *)&DAT_11017908,3);
  _Player::MarkResearchComplete((_Player *)&DAT_11017908,0x3262);
  _Player::GoPlymouth((_Player *)&DAT_110178f8);
  _Player::GoAI((_Player *)&DAT_110178f8);
  _Player::SetColorNumber((_Player *)&DAT_110178f8,1);
  _Player::SetTechLevel((_Player *)&DAT_110178f8,0xc);
  _Player::SetOre((_Player *)&DAT_110178f8,2000);
  _Player::GoEden((_Player *)&DAT_11017918);
  _Player::GoAI((_Player *)&DAT_11017918);
  _Player::SetColorNumber((_Player *)&DAT_11017918,0);
  _Player::SetTechLevel((_Player *)&DAT_11017918,0xc);
  _Player::MarkResearchComplete((_Player *)&DAT_11017918,0x3263);
  _Player::GoPlymouth((_Player *)(Player_exref + 0x24));
  _Player::SetColorNumber((_Player *)(Player_exref + 0x24),1);
  FUN_110014fa(5,0x11010108);
  FUN_110013d1(1,0x1f,-1,(int *)&DAT_11010598);
  if (DAT_11017002 != '\0') {
    FUN_110013d1(1,0x1f,-1,(int *)&DAT_110105d8);
  }
  FUN_110013d1(0,0x1f,-1,(int *)&DAT_110105b8);
  cVar2 = FUN_11004267();
  if (cVar2 == '\0') {
    return 0;
  }
  _Player::CenterViewOn((_Player *)&DAT_11017908,0x46,0x78);
  TethysGame::SetDaylightMoves(0);
  TethysGame::SetDaylightEverywhere(0);
  DAT_110170a0 = TethysGame::GetRand((DAT_11017002 != '\0') + 3);
  DAT_110170a4 = TethysGame::GetRand((DAT_11017002 != '\0') + 3);
  if (DAT_11017002 == '\0') {
    DAT_110170a8 = 0;
  }
  else {
    DAT_110170a8 = TethysGame::GetRand(2);
  }
  DAT_110170ac = TethysGame::GetRand(2);
  DAT_110170b4 = TethysGame::GetRand(2);
  DAT_110170b0 = TethysGame::GetRand(3);
  if (DAT_110170a0 == 0) {
    iVar3 = TethysGame::GetRand(3);
    local_8 = TethysGame::GetRand(3);
    local_8 = local_8 + 0x3f;
    pLVar4 = (LOCATION *)&local_8;
    local_4 = iVar3 + 0x2d;
  }
  else if (DAT_110170a0 == 1) {
    iVar3 = TethysGame::GetRand(2);
    local_10 = TethysGame::GetRand(3);
    local_10 = local_10 + 0x41;
    pLVar4 = (LOCATION *)&local_10;
    local_c = iVar3 + 0x23;
  }
  else if (DAT_110170a0 == 2) {
    iVar3 = TethysGame::GetRand(2);
    local_18 = TethysGame::GetRand(3);
    local_18 = local_18 + 0x41;
    pLVar4 = (LOCATION *)&local_18;
    local_14 = iVar3 + 0x26;
  }
  else {
    if (DAT_110170a0 != 3) goto LAB_110046f9;
    iVar3 = TethysGame::GetRand(3);
    local_20 = TethysGame::GetRand(3);
    local_20 = local_20 + 0x38;
    pLVar4 = (LOCATION *)&local_20;
    local_1c = iVar3 + 0x19;
  }
  LOCATION::operator=((LOCATION *)&DAT_11017094,pLVar4);
LAB_110046f9:
  DAT_1101709c = GameMap::GetTile();
  FUN_11002b0d();
  FUN_110034d5();
  FUN_11001d50();
  FUN_11001f88();
  FUN_110031fd();
  FUN_11005213(0);
  FUN_11005a30('\x01','\x01',0x1068,0x12c0,FUN_1100244c,0);
  FUN_11005a30('\x01','\x01',18000,20000,FUN_1100284d,0);
  FUN_11001112('\x01','\x01',0,FUN_11003241,0);
  return 1;
}


// ---- 1100477a FUN_1100477a  (called by: FUN_110047ac@110047ac)

void FUN_1100477a(void)

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


// ---- 110047ac FUN_110047ac  (called by: entry@11007c84)

undefined4 FUN_110047ac(HMODULE param_1,int param_2)

{
  bool bVar1;
  undefined *puVar2;
  ushort uVar3;
  
  if (param_2 == 0) {
    bVar1 = FUN_1100512d();
    if (bVar1) {
      FUN_110051a2((uint *)&DAT_11010984);
    }
    FUN_110011d2();
    FUN_1100477a();
  }
  else if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    FUN_110062a0(param_1);
    uVar3 = 0x1a;
    puVar2 = FUN_1100513a((uint *)s_q04_mo3_11010988,PTR_DAT_11010990);
    FUN_110065af(puVar2,uVar3);
    FUN_11006386(0x110065d5);
    FUN_1100115d();
  }
  return 1;
}


// ---- 11004824 FUN_11004824  (called by: FUN_110048f0@110048f0)

undefined1 FUN_11004824(void)

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
    if (local_10 != *(int *)(&DAT_110118f0 + local_c * 4)) {
      local_5 = 1;
    }
    while (iVar3 = PlayerVehicleEnum::GetNext(local_18,(Unit *)local_14), iVar3 != 0) {
      local_10 = local_10 + 1;
    }
    if (local_10 != *(int *)(&DAT_11011910 + local_c * 4)) {
      local_5 = 1;
    }
  }
  return local_5;
}


// ---- 110048f0 FUN_110048f0  (called by: FUN_110051a2@110051a2)

uint __cdecl FUN_110048f0(LPCSTR param_1,char param_2)

{
  char cVar1;
  uint uVar2;
  
  if (param_2 == '\0') {
    param_2 = FUN_11004824();
  }
  uVar2 = FUN_11004c66(param_1,param_2);
  cVar1 = (char)uVar2;
  if (cVar1 != '\0') {
    FUN_11004dda(param_1);
    uVar2 = FUN_1100492f(param_1,'\x01');
  }
  return CONCAT31((int3)(uVar2 >> 8),cVar1);
}


// ---- 1100492f FUN_1100492f  (called by: FUN_110048f0@110048f0)

uint __cdecl FUN_1100492f(LPCSTR param_1,char param_2)

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
    if (local_c != *(int *)(&DAT_110118f0 + iVar1 * 4)) {
      param_2 = '\x01';
    }
    while (iVar4 = PlayerVehicleEnum::GetNext(local_14,(Unit *)local_8), iVar4 != 0) {
      local_10 = local_10 + 1;
    }
    if (local_10 != *(map_id *)(&DAT_11011910 + iVar1 * 4)) {
      param_2 = '\x01';
    }
    local_18 = local_18 + local_10 + local_c;
  }
  local_c = TethysGame::NoPlayers();
  if (param_2 == '\0') {
    local_c = local_c & 0xffffff00;
  }
  else {
    pFVar5 = (FILE *)FUN_110070f2(param_1,&DAT_11010994);
    FUN_11006f88((char *)&local_18,4,1,(int *)pFVar5);
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
            FUN_11006f88((char *)&local_68,0x18,1,(int *)pFVar5);
            param_1 = (LPCSTR)0x0;
            do {
              IUnit::GetFactoryCargo(local_8,(int)param_1,&local_50,&local_44);
              FUN_11006f88((char *)&local_50,4,1,(int *)pFVar5);
              FUN_11006f88((char *)&local_44,4,1,(int *)pFVar5);
              param_1 = param_1 + 1;
            } while ((int)param_1 < 6);
          }
          else {
            FUN_11006f88((char *)&local_68,0x18,1,(int *)pFVar5);
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
          FUN_11006f88((char *)&local_3c,0x18,1,(int *)pFVar5);
        }
      }
    }
    FUN_11006b69(pFVar5);
    *(int *)(&DAT_110118f0 + local_c * 4) = local_18;
    local_c = (uint)(pFVar5 != (FILE *)0x0);
  }
  return local_c;
}


// ---- 11004c66 FUN_11004c66  (called by: FUN_110048f0@110048f0)

uint __cdecl FUN_11004c66(LPCSTR param_1,char param_2)

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
  if ((param_2 != '\0') || (uVar5 = local_14, local_14 != DAT_11011930)) {
    pFVar4 = (FILE *)FUN_110070f2(param_1,&DAT_110100f0);
    uVar5 = 0;
    if (pFVar4 != (FILE *)0x0) {
      FUN_11006f88((char *)&local_14,4,1,(int *)pFVar4);
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
            FUN_11006f88((char *)&local_10,2,1,(int *)pFVar4);
            FUN_11006f88((char *)&local_c,2,1,(int *)pFVar4);
            FUN_11006f88((char *)&local_5,1,1,(int *)pFVar4);
            if ((local_5 == 0x15) || (uVar6 = extraout_EDX_03, local_5 == 0x16)) {
              local_18 = GameMap::GetTile((int)(short)local_c,extraout_EDX_03,(int)(short)local_10,
                                          (int)(short)local_c);
              FUN_11006f88((char *)&local_18,2,1,(int *)pFVar4);
              uVar6 = extraout_EDX_04;
            }
          }
          local_10 = local_10 + 1;
          sVar1 = (short)local_10;
        }
        local_c = local_c + 1;
        sVar1 = (short)local_c;
      }
      FUN_11006b69(pFVar4);
      DAT_11011930 = local_14;
      return CONCAT31((int3)(local_14 >> 8),1);
    }
  }
  return uVar5 & 0xffffff00;
}


// ---- 11004dda FUN_11004dda  (called by: FUN_110048f0@110048f0)

undefined4 __cdecl FUN_11004dda(LPCSTR param_1)

{
  FILE *pFVar1;
  undefined4 uVar2;
  int local_24 [8];
  
  FUN_11005017(local_24,SUB41(*(undefined4 *)Player_exref,0));
  pFVar1 = (FILE *)FUN_110070f2(param_1,&DAT_11010994);
  FUN_11006f88((char *)local_24,0x20,1,(int *)pFVar1);
  uVar2 = FUN_11006b69(pFVar1);
  return CONCAT31((int3)((uint)uVar2 >> 8),1);
}


// ---- 11004e24 FUN_11004e24  (called by: FUN_11004e3c@11004e3c, FUN_11004ee9@11004ee9)

undefined4 __cdecl FUN_11004e24(int *param_1)

{
  uint uVar1;
  
  uVar1 = FUN_1100760f((char *)&DAT_110118d0,0x20,1,param_1);
  return CONCAT31((int3)(uVar1 >> 8),1);
}


// ---- 11004e3c FUN_11004e3c  (called by: FUN_11004267@11004267)

undefined1 __thiscall FUN_11004e3c(uint3 param_1,LPCSTR param_2)

{
  FILE *pFVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  
  uVar3 = 0;
  pFVar1 = (FILE *)FUN_11004e65(param_1,param_2);
  if (pFVar1 != (FILE *)0x0) {
    uVar2 = FUN_11004e24((int *)pFVar1);
    uVar3 = (undefined1)uVar2;
    FUN_11006b69(pFVar1);
  }
  return uVar3;
}


// ---- 11004e65 FUN_11004e65  (called by: FUN_11004e3c@11004e3c, FUN_11004ee9@11004ee9)

int * __thiscall FUN_11004e65(uint3 param_1,LPCSTR param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int local_c;
  undefined4 uStack_8;
  
  local_c = 0;
  uStack_8 = (uint)param_1;
  piVar1 = (int *)FUN_110070f2(param_2,&DAT_11010998);
  if (piVar1 == (int *)0x0) {
    return (int *)0x0;
  }
  piVar2 = &local_c;
  uVar3 = 4;
  do {
    FUN_1100760f((char *)piVar2,uVar3,1,piVar1);
    do {
      local_c = local_c + -1;
      if (local_c < 0) {
        return piVar1;
      }
      FUN_1100760f((char *)((int)&param_2 + 2),2,1,piVar1);
      FUN_1100760f((char *)((int)&param_2 + 2),2,1,piVar1);
      FUN_1100760f((char *)((int)&uStack_8 + 3),1,1,piVar1);
    } while ((uStack_8._3_1_ < 0x15) || (0x16 < uStack_8._3_1_));
    uVar3 = 2;
    piVar2 = (int *)((int)&param_2 + 2);
  } while( true );
}


// ---- 11004ee9 FUN_11004ee9  (called by: FUN_11004267@11004267)

undefined4 __cdecl FUN_11004ee9(LPCSTR param_1,void *param_2)

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
  pFVar1 = (FILE *)FUN_11004e65((uint3)extraout_ECX,param_1);
  if (pFVar1 == (FILE *)0x0) {
    uVar3 = 0;
  }
  else {
    FUN_11004e24((int *)pFVar1);
    FUN_1100760f((char *)&local_8,4,1,(int *)pFVar1);
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
        FUN_1100760f((char *)piVar2,0x18,1,(int *)pFVar1);
        if ((pFVar1->_flag & 0x10) != 0) {
          FUN_110075f6(piVar2);
          break;
        }
        if ((*piVar2 == 0x2f) || (*piVar2 == 0x37)) {
          iVar4 = 0xc;
          do {
            FUN_1100760f(local_10,4,1,(int *)pFVar1);
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        uVar3 = FUN_11005004(piVar2);
        if ((char)uVar3 == '\0') {
          FUN_110075f6(piVar2);
        }
        else {
          FUN_110050e6(param_2,(int)piVar2);
        }
      }
    }
    uVar3 = FUN_11006b69(pFVar1);
    uVar3 = CONCAT31((int3)((uint)uVar3 >> 8),1);
  }
  return uVar3;
}


// ---- 11004fbb FUN_11004fbb  (called by: FUN_11004267@11004267)

int __cdecl FUN_11004fbb(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int local_8;
  
  local_8 = 0;
  iVar1 = *param_2;
  while (iVar1 = iVar1 + -1, 0 < iVar1) {
    piVar2 = (int *)FUN_110050f2(param_2,iVar1);
    if (((piVar2[5] == param_1) && (*piVar2 == param_3)) &&
       ((piVar2[1] == param_4 || (param_4 == -1)))) {
      local_8 = local_8 + 1;
    }
  }
  return local_8;
}


// ---- 11005004 FUN_11005004  (called by: FUN_11004ee9@11004ee9)

undefined4 __fastcall FUN_11005004(int *param_1)

{
  if ((*param_1 < 0x11) || (0x6e < *param_1)) {
    return 1;
  }
  return 0;
}


// ---- 11005017 FUN_11005017  (called by: FUN_11004dda@11004dda)

int * __thiscall FUN_11005017(int *param_1,_Player param_2)

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


// ---- 11005083 FUN_11005083  (called by: FUN_11004267@11004267)

void __fastcall FUN_11005083(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return;
}


// ---- 11005092 FUN_11005092  (called by: FUN_110050e6@110050e6)

uint __thiscall FUN_11005092(void *this,int param_1)

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
      piVar2 = FUN_11007726(*(int **)((int)this + 4),(uint *)(*(int *)this << 2));
    }
    *(int **)((int)this + 4) = piVar2;
    iVar1 = *(int *)this;
    *(int *)(*(int *)((int)this + 4) + -4 + iVar1 * 4) = param_1;
    uVar3 = CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  return uVar3;
}


// ---- 110050d5 FUN_110050d5  (called by: FUN_110050ff@110050ff)

void __fastcall FUN_110050d5(undefined4 *param_1)

{
  FUN_11006b21((LPVOID)param_1[1]);
  *param_1 = 0;
  return;
}


// ---- 110050e6 FUN_110050e6  (called by: FUN_11004ee9@11004ee9)

void __thiscall FUN_110050e6(void *this,int param_1)

{
  FUN_11005092(this,param_1);
  return;
}


// ---- 110050f2 FUN_110050f2  (called by: FUN_11004fbb@11004fbb)

undefined4 __thiscall FUN_110050f2(void *this,int param_1)

{
  return *(undefined4 *)(*(int *)((int)this + 4) + param_1 * 4);
}


// ---- 110050ff FUN_110050ff  (called by: FUN_11004267@11004267)

void __fastcall FUN_110050ff(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    FUN_110075f6(*(LPVOID *)(param_1[1] + iVar1 * 4));
  }
  FUN_110050d5(param_1);
  return;
}


// ---- 11005120 FUN_11005120  (called by: InitProc@11004475)

bool FUN_11005120(void)

{
  return DAT_004e971c == 'Q';
}


// ---- 1100512d FUN_1100512d  (called by: FUN_110047ac@110047ac)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_1100512d(void)

{
  return _DAT_0056eb34 == 3;
}


// ---- 1100513a FUN_1100513a  (called by: FUN_110047ac@110047ac, FUN_110051a2@110051a2)

undefined * __cdecl FUN_1100513a(uint *param_1,byte *param_2)

{
  byte *pbVar1;
  byte local_208 [256];
  byte local_108 [256];
  byte local_8 [4];
  
  pbVar1 = (byte *)GetCurrentModDir();
  if (pbVar1 == (byte *)0x0) {
    FUN_11007860((uint *)&DAT_1101513c,param_1);
  }
  else {
    FUN_110079e1(pbVar1,local_8,local_208,local_108,local_108);
    FUN_11007950(&DAT_1101513c,local_8,local_208,(byte *)param_1,param_2);
  }
  return &DAT_1101513c;
}


// ---- 110051a2 FUN_110051a2  (called by: FUN_110047ac@110047ac)

void __cdecl FUN_110051a2(uint *param_1)

{
  size_t sVar1;
  undefined *puVar2;
  uint *puVar3;
  uint local_54 [20];
  
  GetGameDir(local_54);
  sVar1 = _strlen((char *)local_54);
  FUN_11007870(local_54,param_1);
  FUN_11007870(local_54,(uint *)&DAT_110109b0);
  FUN_110048f0((LPCSTR)local_54,'\0');
  FUN_11007860((uint *)((int)local_54 + sVar1),(uint *)s_music2_wav_110109a4);
  puVar3 = local_54;
  puVar2 = FUN_1100513a(param_1,&DAT_1101099c);
  FUN_110011e9(puVar2,(LPCSTR)puVar3);
  return;
}


// ---- 11005213 FUN_11005213  (called by: InitProc@11004475)

void __cdecl FUN_11005213(undefined1 param_1)

{
  DAT_11015134 = param_1;
  FUN_11005aa0('\x01','\0',500,FUN_110054e9,0);
  return;
}


// ---- 11005235 FUN_11005235  (called by: FUN_110052b6@110052b6)

bool __cdecl FUN_11005235(Unit param_1)

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


// ---- 110052b6 FUN_110052b6  (called by: FUN_11005365@11005365)

undefined4 __cdecl FUN_110052b6(LOCATION param_1,undefined4 param_2,int param_3)

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
LAB_110052e3:
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
      bVar3 = FUN_11005235(SUB41(local_8,0));
      if (bVar3) goto LAB_110052e3;
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


// ---- 11005365 FUN_11005365  (called by: FUN_110054e9@110054e9)

void __cdecl FUN_11005365(int param_1)

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
    if ((DAT_11015134 != '\0') || (local_10 != 0x17)) {
      PlayerBuildingEnum::PlayerBuildingEnum(local_18,param_1,local_10);
LAB_110053ae:
      iVar1 = PlayerBuildingEnum::GetNext(local_18,(Unit *)&local_8);
      if (iVar1 != 0) {
        iVar1 = IUnit::GetDamage((IUnit *)&local_8);
        if (iVar1 < 0x65) {
          *(undefined4 *)(&DAT_11011934 + (local_8 * 7 + param_1) * 4) = 0;
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
                if (0 < *(int *)(&DAT_11011934 + (local_8 * 7 + param_1) * 4)) {
                  Unit::SetId((Unit *)local_c,*(int *)(&DAT_11011934 + (local_8 * 7 + param_1) * 4))
                  ;
                  cVar2 = IUnit::GetBusy(local_c);
                  if (cVar2 == 0x1c) {
                    iVar1 = Unit::IsLive((Unit *)local_c);
                    if (iVar1 != 0) {
                      mVar3 = Unit::GetType((Unit *)local_c);
                      if (mVar3 == 2) goto LAB_110053ae;
                    }
                  }
                  *(undefined4 *)(&DAT_11011934 + (local_8 * 7 + param_1) * 4) = 0;
                }
                puVar5 = local_20;
                puVar4 = (undefined4 *)Unit::Location((Unit *)&local_8);
                iVar1 = FUN_110052b6(SUB41(*puVar4,0),puVar4[1],(int)puVar5);
                if (0 < iVar1) {
                  Unit::SetId((Unit *)local_c,iVar1);
                  Unit::GetType((Unit *)local_c);
                  Unit::OwnerID((Unit *)local_c);
                  IUnit::Repair(local_c,local_8);
                  *(int *)(&DAT_11011934 + (local_8 * 7 + param_1) * 4) = iVar1;
                }
              }
            }
          }
        }
        goto LAB_110053ae;
      }
    }
    local_10 = local_10 + 1;
    if (0x3a < (int)local_10) {
      return;
    }
  } while( true );
}


// ---- 110054e9 FUN_110054e9  (called by: -)

void FUN_110054e9(void)

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
        FUN_11005365(iVar3);
      }
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + 0xc;
      iVar2 = TethysGame::NoPlayers();
    } while (iVar3 < iVar2);
  }
  return;
}


// ---- 11005550 AIProc  (called by: -)

void AIProc(void)

{
                    /* 0x5550  4  AIProc */
  FUN_11005720(&DAT_11017928);
  return;
}


// ---- 11005560 FUN_11005560  (called by: FUN_11001093@11001093, FUN_11005950@11005950, FUN_11005af0@11005af0, FUN_11005c60@11005c60, FUN_11005fc0@11005fc0, FUN_110060e0@110060e0)

undefined4 * __thiscall FUN_11005560(void *this,char param_1,char param_2,undefined4 param_3)

{
  *(undefined ***)this = &PTR_LAB_1100d380;
  FUN_110055a0(this,param_1,param_2,param_3);
  return this;
}


// ---- 11005590 FUN_11005590  (called by: FUN_11002080@11002080, FUN_11002126@11002126, FUN_110021b5@110021b5, FUN_11002244@11002244, FUN_1100235b@1100235b, FUN_1100244c@1100244c, FUN_110055e0@110055e0)

void __fastcall FUN_11005590(int param_1)

{
  *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) | 0x20;
  return;
}


// ---- 110055a0 FUN_110055a0  (called by: FUN_11005560@11005560)

void __thiscall FUN_110055a0(void *this,char param_1,char param_2,undefined4 param_3)

{
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined2 *)((int)this + 4) = 0;
  *(byte *)((int)this + 6) = param_1 != '\0' | (-(param_2 != '\0') & 2U) + 2 | 8;
  *(undefined4 *)((int)this + 0xc) = param_3;
  return;
}


// ---- 110055e0 FUN_110055e0  (called by: FUN_110010c0@110010c0, FUN_110059f0@110059f0, FUN_11005d00@11005d00, FUN_11006010@11006010, FUN_11006130@11006130)

void __fastcall FUN_110055e0(int param_1)

{
  byte bVar1;
  
  if (*(code **)(param_1 + 0xc) != (code *)0x0) {
    *(short *)(param_1 + 4) = *(short *)(param_1 + 4) + 1;
    (**(code **)(param_1 + 0xc))(param_1);
    bVar1 = *(byte *)(param_1 + 6);
    if (((bVar1 & 2) == 0) && (*(byte *)(param_1 + 6) = bVar1 & 0xfe, (bVar1 & 4) != 0)) {
      FUN_11005590(param_1);
    }
  }
  return;
}


// ---- 11005630 FUN_11005630  (called by: FUN_11001112@11001112, FUN_11005a30@11005a30, FUN_11005bc0@11005bc0, FUN_11005d80@11005d80, FUN_11006060@11006060, FUN_11006180@11006180)

void __thiscall FUN_11005630(void *this,int param_1)

{
  int iVar1;
  
  iVar1 = FUN_110056c0(this,param_1);
  if (iVar1 < 0) {
    if (*(int *)((int)this + 4) == 0x200) {
      (*DAT_1100d37c)(s_ERROR_110109dc,0x10);
      return;
    }
    *(int *)(*(int *)this + *(int *)((int)this + 4) * 4) = param_1;
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  }
  return;
}


// ---- 11005680 FUN_11005680  (called by: FUN_11005800@11005800)

void __thiscall FUN_11005680(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = FUN_110056c0(this,param_1);
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


// ---- 110056c0 FUN_110056c0  (called by: FUN_11005630@11005630, FUN_11005680@11005680)

void __thiscall FUN_110056c0(void *this,int param_1)

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


// ---- 110056e0 FUN_110056e0  (called by: FUN_11005720@11005720)

void FUN_110056e0(void)

{
  if (DAT_11015138 == '\0') {
    if (DAT_11020980 != DAT_1101518c) {
      DAT_11015138 = '\x01';
      if (DAT_11020980 == 0) {
        DAT_11020980 = DAT_1101518c;
        return;
      }
      (*DAT_1100d37c)(s_WARNING_11010a2c,0x30);
    }
  }
  return;
}


// ---- 11005720 FUN_11005720  (called by: AIProc@11005550)

void __fastcall FUN_11005720(int *param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_1100cfb0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_110056e0();
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
  FUN_11005800(param_1);
  ExceptionList = local_10;
  return;
}


// ---- 11005791 Catch@11005791  (called by: -)

undefined * Catch_11005791(void)

{
  int unaff_EBP;
  
  scr_snprintf((char *)(unaff_EBP + -0x6c),0x50,s_Error_executing_event__02X_ID__0_11010a40,
               *(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 8),
               *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0xc));
  (*DAT_1100d37c)(s_EventError_11010a34,0x30);
  return FUN_110057cc;
}


// ---- 110057cc FUN_110057cc  (called by: -)

void FUN_110057cc(void)

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
        FUN_11005800(piVar4);
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


// ---- 11005800 FUN_11005800  (called by: FUN_110057cc@110057cc)

void __fastcall FUN_11005800(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[1];
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    iVar2 = *(int *)(*param_1 + iVar1 * 4);
    if ((iVar2 != 0) && ((*(byte *)(iVar2 + 6) & 0x20) != 0)) {
      FUN_11005680(param_1,iVar2);
      FUN_11005900(iVar2);
    }
  }
  return;
}


// ---- 11005850 FUN_11005850  (called by: FUN_11005870@11005870, FUN_11005900@11005900)

undefined * FUN_11005850(LPCSTR param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_retaddr;
  
  MessageBoxA((HWND)0x0,param_1,s_ERROR_110109dc,0x10);
  FUN_11007d81(0xffffffff);
  iVar2 = (unaff_retaddr - 1U >> 4) + 1;
  iVar5 = 0;
  do {
    cVar1 = (&DAT_11020130)[iVar5];
    iVar4 = 0;
    while (cVar1 == '\0') {
      iVar3 = iVar4 + 1;
      if (iVar3 == iVar2) {
        for (; 0 < iVar4; iVar4 = iVar4 + -1) {
          (&DAT_11020130)[iVar4 + iVar5] = 0xff;
        }
        (&DAT_11020130)[iVar5] = (char)iVar2;
        return &DAT_11018130 + iVar5 * 0x10;
      }
      if (0x7ff < iVar3 + iVar5) {
        FUN_11005850(s__new__Out_of_memory_11010a74);
      }
      iVar4 = iVar3;
      cVar1 = (&DAT_11020130)[iVar3 + iVar5];
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x800);
  FUN_11005850(s__new__Out_of_memory_11010a74);
  return (undefined *)0x0;
}


// ---- 11005870 FUN_11005870  (called by: FUN_11001112@11001112, FUN_11005a30@11005a30, FUN_11005bc0@11005bc0, FUN_11005d80@11005d80, FUN_11006060@11006060, FUN_11006180@11006180)

undefined * __cdecl FUN_11005870(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = (param_1 - 1U >> 4) + 1;
  iVar5 = 0;
  do {
    cVar1 = (&DAT_11020130)[iVar5];
    iVar4 = 0;
    while (cVar1 == '\0') {
      iVar3 = iVar4 + 1;
      if (iVar3 == iVar2) {
        for (; 0 < iVar4; iVar4 = iVar4 + -1) {
          (&DAT_11020130)[iVar4 + iVar5] = 0xff;
        }
        (&DAT_11020130)[iVar5] = (char)iVar2;
        return &DAT_11018130 + iVar5 * 0x10;
      }
      if (0x7ff < iVar3 + iVar5) {
        FUN_11005850(s__new__Out_of_memory_11010a74);
      }
      iVar4 = iVar3;
      cVar1 = (&DAT_11020130)[iVar3 + iVar5];
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x800);
  FUN_11005850(s__new__Out_of_memory_11010a74);
  return (undefined *)0x0;
}


// ---- 11005900 FUN_11005900  (called by: FUN_11005800@11005800)

void __cdecl FUN_11005900(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (int)(param_1 + -0x11018130 + (param_1 + -0x11018130 >> 0x1f & 0xfU)) >> 4;
  iVar2 = (int)(char)(&DAT_11020130)[iVar1];
  if ((iVar2 < 1) || (0xfe < iVar2)) {
    FUN_11005850(s__delete__Invalid_pointer_supplie_11010a88);
  }
  else {
    iVar2 = iVar2 + -1;
    if (-1 < iVar2) {
      do {
        (&DAT_11020130)[iVar2 + iVar1] = 0;
        iVar2 = iVar2 + -1;
      } while (-1 < iVar2);
      return;
    }
  }
  return;
}


// ---- 11005950 FUN_11005950  (called by: FUN_11005a30@11005a30)

undefined4 * __thiscall
FUN_11005950(void *this,char param_1,char param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  
  FUN_11005560(this,param_1,param_2,param_5);
  *(undefined ***)this = &PTR_FUN_1100d384;
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
  FUN_110059b0((int)this);
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 8) = param_6;
  return this;
}


// ---- 110059b0 FUN_110059b0  (called by: FUN_11005950@11005950, FUN_110059f0@110059f0)

void __fastcall FUN_110059b0(int param_1)

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


// ---- 110059f0 FUN_110059f0  (called by: -)

void __fastcall FUN_110059f0(int param_1)

{
  int iVar1;
  
  iVar1 = TethysGame::Tick();
  if ((*(int *)(param_1 + 0x18) <= iVar1) && (*(int *)(param_1 + 0x1c) < *(int *)(param_1 + 0x18)))
  {
    FUN_110055e0(param_1);
    if ((*(byte *)(param_1 + 6) & 0x20) != 0) {
      return;
    }
    if ((*(byte *)(param_1 + 6) & 2) != 0) {
      FUN_110059b0(param_1);
    }
  }
  *(int *)(param_1 + 0x1c) = iVar1;
  return;
}


// ---- 11005a30 FUN_11005a30  (called by: FUN_11005aa0@11005aa0, InitProc@11004475)

undefined4 * __cdecl
FUN_11005a30(char param_1,char param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6
            )

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_20 [8];
  
  puVar1 = (undefined4 *)FUN_11005870(0x20);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_11005950(local_20,param_1,param_2,param_3,param_4,param_5,param_6);
  puVar3 = local_20;
  puVar4 = puVar1;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_11005630(&DAT_11017928,(int)puVar1);
  return puVar1;
}


// ---- 11005aa0 FUN_11005aa0  (called by: FUN_11001ffe@11001ffe, FUN_11002126@11002126, FUN_110021b5@110021b5, FUN_1100244c@1100244c, FUN_11002765@11002765, FUN_11002783@11002783, FUN_1100284d@1100284d, FUN_11005213@11005213)

void __cdecl
FUN_11005aa0(char param_1,char param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  FUN_11005a30(param_1,param_2,param_3,param_3,param_4,param_5);
  return;
}


// ---- 11005af0 FUN_11005af0  (called by: FUN_11005bc0@11005bc0)

undefined4 * __thiscall
FUN_11005af0(undefined4 *param_1,char param_2,char param_3,undefined1 param_4,LOCATION param_5,
            undefined4 param_6,undefined4 param_7)

{
  FUN_11005560(param_1,param_2,param_3,param_7);
  param_1[5] = 0;
  param_1[6] = 0;
  *param_1 = &PTR_LAB_1100d388;
  *(undefined1 *)(param_1 + 4) = param_4;
  LOCATION::operator=((LOCATION *)(param_1 + 5),&param_5);
  param_1[2] = 0;
  return param_1;
}


// ---- 11005bc0 FUN_11005bc0  (called by: FUN_11005c30@11005c30)

undefined4 * __cdecl
FUN_11005bc0(char param_1,char param_2,undefined1 param_3,LOCATION param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_1c [7];
  
  puVar1 = (undefined4 *)FUN_11005870(0x1c);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_11005af0(local_1c,param_1,param_2,param_3,param_4,param_5,param_6);
  puVar3 = local_1c;
  puVar4 = puVar1;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_11005630(&DAT_11017928,(int)puVar1);
  return puVar1;
}


// ---- 11005c30 FUN_11005c30  (called by: FUN_11002244@11002244, FUN_1100235b@1100235b)

void __cdecl
FUN_11005c30(char param_1,char param_2,undefined1 param_3,LOCATION param_4,undefined4 param_5,
            undefined4 param_6)

{
  FUN_11005bc0(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ---- 11005c60 FUN_11005c60  (called by: FUN_11005d80@11005d80)

undefined4 * __thiscall
FUN_11005c60(void *this,char param_1,char param_2,ScStub *param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  char cVar1;
  int iVar2;
  
  FUN_11005560(this,param_1,param_2,param_5);
  *(undefined ***)this = &PTR_FUN_1100d38c;
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


// ---- 11005d00 FUN_11005d00  (called by: -)

void __fastcall FUN_11005d00(int param_1)

{
  int iVar1;
  int local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_1100cfc9;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_10 = param_1;
  ScGroup::ScGroup((ScGroup *)&local_10);
  local_4 = 0;
  ScStub::SetId((ScStub *)&local_10,(int)*(char *)(param_1 + 0x10));
  iVar1 = ScGroup::TotalUnitCount((ScGroup *)&local_10);
  if (iVar1 <= *(char *)(param_1 + 0x12)) {
    FUN_110055e0(param_1);
  }
  local_4 = 0xffffffff;
  ScStub::~ScStub((ScStub *)&local_10);
  ExceptionList = local_c;
  return;
}


// ---- 11005d80 FUN_11005d80  (called by: FUN_1100244c@1100244c)

undefined4 * __cdecl
FUN_11005d80(char param_1,char param_2,ScStub *param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_14 [5];
  
  puVar1 = (undefined4 *)FUN_11005870(0x14);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_11005c60(local_14,param_1,param_2,param_3,param_4,param_5,param_6);
  puVar3 = local_14;
  puVar4 = puVar1;
  for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_11005630(&DAT_11017928,(int)puVar1);
  return puVar1;
}


// ---- 11005df0 FUN_11005df0  (called by: FUN_1100244c@1100244c, FUN_1100294d@1100294d, FUN_11005f90@11005f90)

int __cdecl FUN_11005df0(int param_1,map_id param_2,map_id param_3)

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


// ---- 11005e80 FUN_11005e80  (called by: FUN_11005ea0@11005ea0)

undefined4 __cdecl FUN_11005e80(IUnit param_1)

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


// ---- 11005ea0 FUN_11005ea0  (called by: FUN_11006130@11006130)

int __cdecl FUN_11005ea0(int param_1,map_id param_2)

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
    uVar2 = FUN_11005e80(SUB41(local_c,0));
    if ((char)uVar2 != '\0') {
      iVar3 = iVar3 + 1;
    }
    iVar1 = PlayerBuildingEnum::GetNext(local_8,(Unit *)&local_c);
  }
  return iVar3;
}


// ---- 11005f10 FUN_11005f10  (called by: FUN_1100294d@1100294d, FUN_11005f90@11005f90)

int __cdecl FUN_11005f10(int param_1,map_id param_2,map_id param_3)

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


// ---- 11005f90 FUN_11005f90  (called by: FUN_11006010@11006010)

void __cdecl FUN_11005f90(int param_1,map_id param_2,map_id param_3)

{
  if ((int)param_2 < 0x11) {
    FUN_11005f10(param_1,param_2,param_3);
    return;
  }
  FUN_11005df0(param_1,param_2,param_3);
  return;
}


// ---- 11005fc0 FUN_11005fc0  (called by: FUN_11006060@11006060)

undefined4 * __thiscall
FUN_11005fc0(void *this,char param_1,char param_2,undefined1 param_3,undefined4 param_4,
            undefined4 param_5,undefined1 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  FUN_11005560(this,param_1,param_2,param_8);
  *(undefined1 *)((int)this + 0x10) = param_3;
  *(undefined1 *)((int)this + 0x11) = param_6;
  *(undefined4 *)((int)this + 0x14) = param_4;
  *(undefined4 *)((int)this + 0x18) = param_5;
  *(undefined ***)this = &PTR_FUN_1100d390;
  *(undefined4 *)((int)this + 0x1c) = param_7;
  *(undefined4 *)((int)this + 8) = param_9;
  return this;
}


// ---- 11006010 FUN_11006010  (called by: -)

void __fastcall FUN_11006010(int param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  
  cVar1 = *(char *)(param_1 + 0x10);
  iVar3 = TethysGame::NoPlayers();
  if (cVar1 < iVar3) {
    cVar1 = FUN_11005f90((int)cVar1,*(map_id *)(param_1 + 0x14),*(map_id *)(param_1 + 0x18));
    *(char *)(param_1 + 0x12) = cVar1;
    bVar2 = FUN_110062e0((int)cVar1,(int)*(char *)(param_1 + 0x11),*(undefined4 *)(param_1 + 0x1c));
    if (bVar2) {
      FUN_110055e0(param_1);
    }
  }
  return;
}


// ---- 11006060 FUN_11006060  (called by: FUN_1100270a@1100270a, FUN_11002b0d@11002b0d, FUN_110034d5@110034d5, FUN_11003e72@11003e72, FUN_11003fb2@11003fb2, gotPanther@110032b7)

undefined4 * __cdecl
FUN_11006060(char param_1,char param_2,undefined1 param_3,undefined4 param_4,undefined4 param_5,
            undefined1 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_20 [8];
  
  puVar1 = (undefined4 *)FUN_11005870(0x20);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_11005fc0(local_20,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  puVar3 = local_20;
  puVar4 = puVar1;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_11005630(&DAT_11017928,(int)puVar1);
  return puVar1;
}


// ---- 110060e0 FUN_110060e0  (called by: FUN_11006180@11006180)

undefined4 * __thiscall
FUN_110060e0(void *this,char param_1,char param_2,undefined1 param_3,undefined4 param_4,
            undefined1 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  FUN_11005560(this,param_1,param_2,param_7);
  *(undefined1 *)((int)this + 0x10) = param_3;
  *(undefined1 *)((int)this + 0x11) = param_5;
  *(undefined4 *)((int)this + 0x18) = param_6;
  *(undefined ***)this = &PTR_FUN_1100d394;
  *(undefined4 *)((int)this + 0x14) = param_4;
  *(undefined4 *)((int)this + 8) = param_8;
  return this;
}


// ---- 11006130 FUN_11006130  (called by: -)

void __fastcall FUN_11006130(int param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  
  cVar1 = *(char *)(param_1 + 0x10);
  iVar3 = TethysGame::NoPlayers();
  if (cVar1 < iVar3) {
    iVar3 = FUN_11005ea0((int)cVar1,*(map_id *)(param_1 + 0x14));
    *(char *)(param_1 + 0x12) = (char)iVar3;
    bVar2 = FUN_110062e0((int)(char)iVar3,(int)*(char *)(param_1 + 0x11),
                         *(undefined4 *)(param_1 + 0x18));
    if (bVar2) {
      FUN_110055e0(param_1);
    }
  }
  return;
}


// ---- 11006180 FUN_11006180  (called by: FUN_11002b0d@11002b0d)

undefined4 * __cdecl
FUN_11006180(char param_1,char param_2,undefined1 param_3,undefined4 param_4,undefined1 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_1c [7];
  
  puVar1 = (undefined4 *)FUN_11005870(0x1c);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_110060e0(local_1c,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  puVar3 = local_1c;
  puVar4 = puVar1;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_11005630(&DAT_11017928,(int)puVar1);
  return puVar1;
}


// ---- 11006200 GetSaveRegions  (called by: -)

void __cdecl GetSaveRegions(int *param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *_Str1;
  int iVar6;
  
                    /* 0x6200  6  GetSaveRegions */
  iVar4 = ImageLoad(&DAT_11020930,0);
  iVar6 = 0;
  iVar1 = *(int *)(iVar4 + 0x14);
  pcVar2 = *(char **)(iVar4 + 0x18);
  iVar3 = *(int *)(*(int *)(iVar4 + 0xc) + 0x34);
  DAT_1101518c = *(undefined4 *)(*(int *)(iVar4 + 0xc) + 8);
  _Str1 = pcVar2;
  if (0 < iVar1) {
    while( true ) {
      iVar5 = _strncmp(_Str1,s__save_11010ab0,5);
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


// ---- 110062a0 FUN_110062a0  (called by: FUN_110047ac@110047ac)

void __cdecl FUN_110062a0(HMODULE param_1)

{
  GetModuleFileNameA(param_1,&DAT_11020930,0x50);
  return;
}


// ---- 110062e0 FUN_110062e0  (called by: FUN_11006010@11006010, FUN_11006130@11006130)

bool __cdecl FUN_110062e0(int param_1,int param_2,undefined4 param_3)

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


// ---- 11006386 FUN_11006386  (called by: FUN_110047ac@110047ac)

undefined4 __cdecl FUN_11006386(int param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 uVar3;
  DWORD local_8;
  
  iVar1 = _memcmp(DAT_11010ac0,&DAT_1100d39c,0x14);
  if (iVar1 == 0) {
    iVar1 = _memcmp(DAT_11010ac8,&DAT_1100d3dc,6);
    if (iVar1 == 0) {
      iVar1 = _memcmp(DAT_11010acc,&DAT_1100d3c4,5);
      uVar3 = 3;
      if (iVar1 == 0) {
        iVar1 = _memcmp(DAT_11010ad0,&DAT_1100d3d4,3);
        if (iVar1 == 0) {
          BVar2 = VirtualProtect(DAT_11010ac0,0x14,0x40,&local_8);
          if (BVar2 == 0) {
            uVar3 = 5;
          }
          else {
            BVar2 = VirtualProtect(DAT_11010ac8,6,0x40,&local_8);
            if (BVar2 == 0) {
              uVar3 = 6;
            }
            else {
              BVar2 = VirtualProtect(DAT_11010acc,5,0x40,&local_8);
              if (BVar2 == 0) {
                uVar3 = 7;
              }
              else {
                BVar2 = VirtualProtect(DAT_11010ad0,3,0x40,&local_8);
                if (BVar2 != 0) {
                  EnterCriticalSection(DAT_11010abc);
                  FUN_11006760(DAT_11010ac0,(undefined4 *)&DAT_1100d3b0,0x14);
                  *(undefined4 *)((int)DAT_11010ac0 + 0xb) = DAT_11010ac4;
                  DAT_11010ac0[4] = (param_1 - (int)DAT_11010ac0) + -0x14;
                  FUN_11006760(DAT_11010ac8,(undefined4 *)&DAT_1100d3e4,6);
                  FUN_11006760(DAT_11010acc,(undefined4 *)&DAT_1100d3cc,5);
                  FUN_11006760(DAT_11010ad0,(undefined4 *)&DAT_1100d3d8,3);
                  LeaveCriticalSection(DAT_11010abc);
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


// ---- 110064f1 UninstallMusicHook  (called by: FUN_1100477a@1100477a)

/* int __cdecl UninstallMusicHook(void) */

int __cdecl UninstallMusicHook(void)

{
                    /* 0x64f1  3  ?UninstallMusicHook@@YAHXZ */
  EnterCriticalSection(DAT_11010abc);
  FUN_11006760(DAT_11010ac0,(undefined4 *)&DAT_1100d39c,0x14);
  FUN_11006760(DAT_11010ac8,(undefined4 *)&DAT_1100d3dc,6);
  FUN_11006760(DAT_11010acc,(undefined4 *)&DAT_1100d3c4,5);
  FUN_11006760(DAT_11010ad0,(undefined4 *)&DAT_1100d3d4,3);
  LeaveCriticalSection(DAT_11010abc);
  return 0;
}


// ---- 11006561 FUN_11006561  (called by: -)

void FUN_11006561(void)

{
  FUN_11006655((undefined4 *)&DAT_11015190);
  return;
}


// ---- 1100656b FUN_1100656b  (called by: -)

void FUN_1100656b(void)

{
  FUN_110075b5(0x11006577);
  return;
}


// ---- 11006577 FUN_11006577  (called by: -)

void FUN_11006577(void)

{
  FUN_110066a2((undefined4 *)&DAT_11015190);
  return;
}


// ---- 11006581 FUN_11006581  (called by: FUN_110065af@110065af)

void __cdecl FUN_11006581(undefined4 param_1)

{
  FUN_11006700(0x11015190);
  DAT_1101519c = param_1;
  FUN_110066ad(&DAT_11015190,param_1);
  FUN_110066f5(0x11015190);
  DAT_11010ad4 = 0;
  return;
}


// ---- 110065af FUN_110065af  (called by: FUN_110047ac@110047ac)

void __cdecl FUN_110065af(undefined4 param_1,ushort param_2)

{
  FUN_11006581(param_1);
  FUN_110065c4(param_2);
  return;
}


// ---- 110065c4 FUN_110065c4  (called by: FUN_110065af@110065af)

void __cdecl FUN_110065c4(ushort param_1)

{
  FUN_11006715(&DAT_11015190,param_1,0);
  return;
}


// ---- 110065d5 FUN_110065d5  (called by: -)

undefined4 FUN_110065d5(undefined4 *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 unaff_BP;
  undefined4 local_8004 [8182];
  undefined4 uStackY_2c;
  
  FUN_11007110(unaff_BP);
  uVar2 = 0;
  if (DAT_1101519c != 0) {
    if (DAT_11010ad4 == '\x01') {
      FUN_110066ad(&DAT_11015190,DAT_1101519c);
      FUN_110066f5(0x11015190);
      DAT_11010ad4 = '\0';
    }
    iVar1 = FUN_110066db(&DAT_11015190,local_8004,0x8000);
    FUN_11006760(param_1,local_8004,param_2);
    uStackY_2c = 0x11006648;
    _memset((void *)(iVar1 + (int)param_1),0,param_2 - iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


// ---- 11006655 FUN_11006655  (called by: FUN_11006561@11006561)

undefined4 * __fastcall FUN_11006655(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  *param_1 = &PTR_FUN_1100d3ec;
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


// ---- 11006686 FUN_11006686  (called by: -)

undefined4 * __thiscall FUN_11006686(void *this,byte param_1)

{
  FUN_110066a2(this);
  if ((param_1 & 1) != 0) {
    FUN_110075f6(this);
  }
  return this;
}


// ---- 110066a2 FUN_110066a2  (called by: FUN_11006577@11006577, FUN_11006686@11006686)

void __fastcall FUN_110066a2(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_1100d3ec;
  BASS_Free();
  return;
}


// ---- 110066ad FUN_110066ad  (called by: FUN_11006581@11006581, FUN_110065d5@110065d5)

bool __thiscall FUN_110066ad(void *this,undefined4 param_1)

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


// ---- 110066db FUN_110066db  (called by: FUN_110065d5@110065d5)

undefined4 __thiscall FUN_110066db(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = BASS_ChannelGetData(*(undefined4 *)((int)this + 8),param_1,param_2);
  return uVar1;
}


// ---- 110066f5 FUN_110066f5  (called by: FUN_11006581@11006581, FUN_110065d5@110065d5)

void __fastcall FUN_110066f5(int param_1)

{
  BASS_ChannelPlay(*(undefined4 *)(param_1 + 8),0);
  return;
}


// ---- 11006700 FUN_11006700  (called by: FUN_11006581@11006581)

void __fastcall FUN_11006700(int param_1)

{
  BASS_ChannelStop(*(undefined4 *)(param_1 + 8));
  BASS_MusicFree(*(undefined4 *)(param_1 + 8));
  return;
}


// ---- 11006715 FUN_11006715  (called by: FUN_110065c4@110065c4)

void __thiscall FUN_11006715(void *this,ushort param_1,ushort param_2)

{
  BASS_ChannelSetPosition
            (*(undefined4 *)((int)this + 8),(param_2 | 0xffff8000) << 0x10 | (uint)param_1,0);
  return;
}


// ---- 11006760 FUN_11006760  (called by: FUN_11001112@11001112, FUN_11006386@11006386, FUN_110065d5@110065d5, FUN_11006fb7@11006fb7, FUN_1100763e@1100763e, FUN_11007726@11007726, FUN_1100ae9f@1100ae9f, UninstallMusicHook@110064f1)

undefined4 * __cdecl FUN_11006760(undefined4 *param_1,undefined4 *param_2,uint param_3)

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
          goto switchD_11006917_caseD_2;
        case 3:
          goto switchD_11006917_caseD_3;
        }
        goto switchD_11006917_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_11006917_caseD_0;
      case 1:
        goto switchD_11006917_caseD_1;
      case 2:
        goto switchD_11006917_caseD_2;
      case 3:
        goto switchD_11006917_caseD_3;
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
              goto switchD_11006917_caseD_2;
            case 3:
              goto switchD_11006917_caseD_3;
            }
            goto switchD_11006917_caseD_1;
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
              goto switchD_11006917_caseD_2;
            case 3:
              goto switchD_11006917_caseD_3;
            }
            goto switchD_11006917_caseD_1;
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
              goto switchD_11006917_caseD_2;
            case 3:
              goto switchD_11006917_caseD_3;
            }
            goto switchD_11006917_caseD_1;
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
switchD_11006917_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_11006917_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_11006917_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_11006917_caseD_0:
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
        goto switchD_11006795_caseD_2;
      case 3:
        goto switchD_11006795_caseD_3;
      }
      goto switchD_11006795_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_11006795_caseD_0;
    case 1:
      goto switchD_11006795_caseD_1;
    case 2:
      goto switchD_11006795_caseD_2;
    case 3:
      goto switchD_11006795_caseD_3;
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
            goto switchD_11006795_caseD_2;
          case 3:
            goto switchD_11006795_caseD_3;
          }
          goto switchD_11006795_caseD_1;
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
            goto switchD_11006795_caseD_2;
          case 3:
            goto switchD_11006795_caseD_3;
          }
          goto switchD_11006795_caseD_1;
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
            goto switchD_11006795_caseD_2;
          case 3:
            goto switchD_11006795_caseD_3;
          }
          goto switchD_11006795_caseD_1;
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
switchD_11006795_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_11006795_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_11006795_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_11006795_caseD_0:
  return param_1;
}


// ---- 11006a95 _malloc  (called by: FUN_1100115d@1100115d, FUN_11005092@11005092, FUN_11007726@11007726, FUN_11008139@11008139, FUN_110090b6@110090b6, FUN_110097d1@110097d1, FUN_1100ab99@1100ab99, FUN_1100ac52@1100ac52, FUN_1100ae9f@1100ae9f, FUN_1100b5a3@1100b5a3, FUN_1100b884@1100b884)

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_110151f8);
  return pvVar1;
}


// ---- 11006aa7 __nh_malloc  (called by: _malloc@11006a95, operator_new@11007601)

/* Library Function - Single Match
    __nh_malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl __nh_malloc(size_t _Size,int _NhFlag)

{
  int *piVar1;
  int iVar2;
  
  if (_Size < 0xffffffe1) {
    do {
      piVar1 = FUN_11006ad3((uint *)_Size);
      if (piVar1 != (int *)0x0) {
        return piVar1;
      }
      if (_NhFlag == 0) {
        return (void *)0x0;
      }
      iVar2 = FUN_11007fd8(_Size);
    } while (iVar2 != 0);
  }
  return (void *)0x0;
}


// ---- 11006ad3 FUN_11006ad3  (called by: __nh_malloc@11006aa7)

int * __cdecl FUN_11006ad3(uint *param_1)

{
  int *piVar1;
  
  if (param_1 <= DAT_11010bc4) {
    FUN_11008139(9);
    piVar1 = FUN_11008543(param_1);
    FUN_1100819a(9);
    if (piVar1 != (int *)0x0) {
      return piVar1;
    }
  }
  if (param_1 == (uint *)0x0) {
    param_1 = (uint *)0x1;
  }
  piVar1 = HeapAlloc(DAT_1101689c,0,(int)param_1 + 0xfU & 0xfffffff0);
  return piVar1;
}


// ---- 11006b21 FUN_11006b21  (called by: FUN_110011d2@110011d2, FUN_110050d5@110050d5, FUN_110075f6@110075f6, FUN_11007726@11007726, FUN_110080cd@110080cd, FUN_11008139@11008139, FUN_11009272@11009272, FUN_1100a1e8@1100a1e8, FUN_1100ab99@1100ab99, FUN_1100ae9f@1100ae9f, __fclose_lk@11006b9a, __freebuf@11008f2e)

void __cdecl FUN_11006b21(LPVOID param_1)

{
  uint *puVar1;
  
  if (param_1 != (LPVOID)0x0) {
    FUN_11008139(9);
    puVar1 = (uint *)FUN_110081ed((int)param_1);
    if (puVar1 != (uint *)0x0) {
      FUN_11008218(puVar1,(uint)param_1);
      FUN_1100819a(9);
      return;
    }
    FUN_1100819a(9);
    HeapFree(DAT_1101689c,0,param_1);
  }
  return;
}


// ---- 11006b69 FUN_11006b69  (called by: FUN_110011e9@110011e9, FUN_1100492f@1100492f, FUN_11004c66@11004c66, FUN_11004dda@11004dda, FUN_11004e3c@11004e3c, FUN_11004ee9@11004ee9)

undefined4 __cdecl FUN_11006b69(FILE *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1->_flag & 0x40) == 0) {
    FUN_11008daa((uint)param_1);
    uVar1 = __fclose_lk(param_1);
    FUN_11008dfc((uint)param_1);
  }
  else {
    param_1->_flag = 0;
  }
  return uVar1;
}


// ---- 11006b9a __fclose_lk  (called by: FUN_11006b69@11006b69)

/* Library Function - Single Match
    __fclose_lk
   
   Library: Visual Studio 2003 Release */

undefined4 __cdecl __fclose_lk(FILE *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1->_flag & 0x83) != 0) {
    uVar2 = FUN_11006e7f((int *)param_1);
    __freebuf(param_1);
    iVar1 = FUN_11008e4e(param_1->_file);
    if (iVar1 < 0) {
      uVar2 = 0xffffffff;
    }
    else if (param_1->_tmpfname != (char *)0x0) {
      FUN_11006b21(param_1->_tmpfname);
      param_1->_tmpfname = (char *)0x0;
    }
  }
  param_1->_flag = 0;
  return uVar2;
}


// ---- 11006be6 FUN_11006be6  (called by: FUN_110011e9@110011e9)

int __cdecl FUN_11006be6(int *param_1,int param_2,DWORD param_3)

{
  int iVar1;
  
  FUN_11008daa((uint)param_1);
  iVar1 = FUN_11006c12(param_1,param_2,param_3);
  FUN_11008dfc((uint)param_1);
  return iVar1;
}


// ---- 11006c12 FUN_11006c12  (called by: FUN_11006be6@11006be6)

int __cdecl FUN_11006c12(int *param_1,int param_2,DWORD param_3)

{
  uint uVar1;
  int iVar2;
  DWORD DVar3;
  DWORD *pDVar4;
  
  if (((param_1[3] & 0x83U) == 0) || (((param_3 != 0 && (param_3 != 1)) && (param_3 != 2)))) {
    pDVar4 = FUN_11008fcc();
    *pDVar4 = 0x16;
    iVar2 = -1;
  }
  else {
    param_1[3] = param_1[3] & 0xffffffef;
    if (param_3 == 1) {
      iVar2 = FUN_11006cc1((char *)param_1);
      param_2 = param_2 + iVar2;
      param_3 = 0;
    }
    FUN_11006e7f(param_1);
    uVar1 = param_1[3];
    if ((uVar1 & 0x80) == 0) {
      if ((((uVar1 & 1) != 0) && ((uVar1 & 8) != 0)) && ((uVar1 & 0x400) == 0)) {
        param_1[6] = 0x200;
      }
    }
    else {
      param_1[3] = uVar1 & 0xfffffffc;
    }
    DVar3 = FUN_11008fde(param_1[4],param_2,param_3);
    iVar2 = (DVar3 != 0xffffffff) - 1;
  }
  return iVar2;
}


// ---- 11006c9f FUN_11006c9f  (called by: FUN_110011e9@110011e9)

int __cdecl FUN_11006c9f(char *param_1)

{
  int iVar1;
  
  FUN_11008daa((uint)param_1);
  iVar1 = FUN_11006cc1(param_1);
  FUN_11008dfc((uint)param_1);
  return iVar1;
}


// ---- 11006cc1 FUN_11006cc1  (called by: FUN_11006c12@11006c12, FUN_11006c9f@11006c9f)

int __cdecl FUN_11006cc1(char *param_1)

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
  local_8 = FUN_11008fde(uVar1,0,1);
  if ((int)local_8 < 0) {
LAB_11006d4f:
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
        pDVar4 = FUN_11008fcc();
        *pDVar4 = 0x16;
        goto LAB_11006d4f;
      }
    }
    else if ((*(byte *)((&DAT_11015760)[(int)uVar1 >> 5] + 4 + (uVar1 & 0x1f) * 0x24) & 0x80) != 0)
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
          if ((*(byte *)(iVar10 + 4 + (&DAT_11015760)[(int)uVar1 >> 5]) & 0x80) != 0) {
            DVar6 = FUN_11008fde(uVar1,0,2);
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
              FUN_11008fde(uVar1,local_8,0);
              pcVar8 = (char *)0x200;
              if ((((char *)0x200 < pcVar5) || ((*(uint *)(param_1 + 0xc) & 8) == 0)) ||
                 ((*(uint *)(param_1 + 0xc) & 0x400) != 0)) {
                pcVar8 = *(char **)(param_1 + 0x18);
              }
              bVar3 = *(byte *)(iVar10 + 4 + (&DAT_11015760)[(int)uVar1 >> 5]) & 4;
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


// ---- 11006e22 FUN_11006e22  (called by: FUN_110011e9@110011e9)

int __cdecl FUN_11006e22(int *param_1)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    iVar1 = FUN_11006ee4(0);
    return iVar1;
  }
  FUN_11008daa((uint)param_1);
  iVar1 = FUN_11006e51(param_1);
  FUN_11008dfc((uint)param_1);
  return iVar1;
}


// ---- 11006e51 FUN_11006e51  (called by: FUN_11006e22@11006e22, FUN_11006ee4@11006ee4)

int __cdecl FUN_11006e51(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_11006e7f(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((*(byte *)((int)param_1 + 0xd) & 0x40) == 0) {
    return 0;
  }
  iVar1 = FUN_110092c6(param_1[4]);
  return -(uint)(iVar1 != 0);
}


// ---- 11006e7f FUN_11006e7f  (called by: FUN_11006c12@11006c12, FUN_11006e51@11006e51, FUN_11006fb7@11006fb7, __fclose_lk@11006b9a)

undefined4 __cdecl FUN_11006e7f(int *param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  DWORD DVar3;
  
  uVar2 = 0;
  if ((((byte)param_1[3] & 3) == 2) && ((param_1[3] & 0x108U) != 0)) {
    DVar3 = *param_1 - param_1[2];
    if (0 < (int)DVar3) {
      DVar1 = FUN_11009359(param_1[4],(char *)param_1[2],DVar3);
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


// ---- 11006ee4 FUN_11006ee4  (called by: FUN_11006e22@11006e22)

int __cdecl FUN_11006ee4(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar5 = 0;
  FUN_11008139(2);
  iVar4 = 0;
  if (0 < DAT_11016880) {
    do {
      iVar2 = *(int *)(DAT_11015864 + iVar4 * 4);
      if ((iVar2 != 0) && ((*(byte *)(iVar2 + 0xc) & 0x83) != 0)) {
        FUN_11008dd9(iVar4,iVar2);
        piVar1 = *(int **)(DAT_11015864 + iVar4 * 4);
        if ((piVar1[3] & 0x83U) != 0) {
          if (param_1 == 1) {
            iVar2 = FUN_11006e51(piVar1);
            if (iVar2 != -1) {
              iVar3 = iVar3 + 1;
            }
          }
          else if ((param_1 == 0) && ((piVar1[3] & 2U) != 0)) {
            iVar2 = FUN_11006e51(piVar1);
            if (iVar2 == -1) {
              iVar5 = -1;
            }
          }
        }
        FUN_11008e2b(iVar4,*(int *)(DAT_11015864 + iVar4 * 4));
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_11016880);
  }
  FUN_1100819a(2);
  if (param_1 != 1) {
    iVar3 = iVar5;
  }
  return iVar3;
}


// ---- 11006f88 FUN_11006f88  (called by: FUN_110011e9@110011e9, FUN_1100492f@1100492f, FUN_11004c66@11004c66, FUN_11004dda@11004dda)

uint __cdecl FUN_11006f88(char *param_1,uint param_2,uint param_3,int *param_4)

{
  uint uVar1;
  
  FUN_11008daa((uint)param_4);
  uVar1 = FUN_11006fb7(param_1,param_2,param_3,param_4);
  FUN_11008dfc((uint)param_4);
  return uVar1;
}


// ---- 11006fb7 FUN_11006fb7  (called by: FUN_11006f88@11006f88)

uint __cdecl FUN_11006fb7(char *param_1,uint param_2,uint param_3,int *param_4)

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
          if (((piVar1[3] & 0x108U) != 0) && (iVar2 = FUN_11006e7f(piVar1), iVar2 != 0)) {
LAB_110070b8:
            return (uint)((int)piVar6 - (int)piVar5) / param_2;
          }
          if (param_4 == (int *)0x0) {
            piVar7 = piVar5;
          }
          else {
            piVar7 = (int *)((int)piVar5 - (uint)piVar5 % (uint)param_4);
          }
          piVar3 = (int *)FUN_11009359(piVar1[4],param_1,(DWORD)piVar7);
          if ((piVar3 == (int *)0xffffffff) ||
             (piVar5 = (int *)((int)piVar5 - (int)piVar3), piVar3 < piVar7)) {
            piVar1[3] = piVar1[3] | 0x20;
            goto LAB_110070b8;
          }
          goto LAB_1100706f;
        }
        uVar4 = FUN_11009549((int)*param_1,piVar1);
        if (uVar4 == 0xffffffff) goto LAB_110070b8;
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
        FUN_11006760((undefined4 *)*piVar1,(undefined4 *)param_1,(uint)piVar3);
        piVar1[1] = piVar1[1] - (int)piVar3;
        *piVar1 = *piVar1 + (int)piVar3;
        piVar5 = (int *)((int)piVar5 - (int)piVar3);
LAB_1100706f:
        param_1 = param_1 + (int)piVar3;
      }
    } while (piVar5 != (int *)0x0);
  }
  return param_3;
}


// ---- 110070c1 FUN_110070c1  (called by: FUN_110070f2@110070f2)

undefined4 * __cdecl FUN_110070c1(LPCSTR param_1,char *param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = FUN_110097d1();
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2 = FUN_11009661(param_1,param_2,param_3,puVar1);
  FUN_11008dfc((uint)puVar1);
  return puVar2;
}


// ---- 110070f2 FUN_110070f2  (called by: FUN_110011e9@110011e9, FUN_1100492f@1100492f, FUN_11004c66@11004c66, FUN_11004dda@11004dda, FUN_11004e65@11004e65)

void __cdecl FUN_110070f2(LPCSTR param_1,char *param_2)

{
  FUN_110070c1(param_1,param_2,0x40);
  return;
}


// ---- 11007110 FUN_11007110  (called by: FUN_110011e9@110011e9, FUN_110065d5@110065d5, FUN_1100bee5@1100bee5, FUN_1100c134@1100c134, FUN_1100c407@1100c407)

/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_11007110(undefined1 param_1)

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


// ---- 1100713f FUN_1100713f  (called by: FUN_11009ca2@11009ca2)

void FUN_1100713f(undefined *UNRECOVERED_JUMPTABLE)

{
  ExceptionList = *(void **)ExceptionList;
                    /* WARNING: Could not recover jumptable at 0x1100716a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


// ---- 11007173 FUN_11007173  (called by: FUN_11009e62@11009e62, FUN_1100a026@1100a026)

void FUN_11007173(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x11007178. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


// ---- 1100717a FUN_1100717a  (called by: FUN_11009e62@11009e62)

void FUN_1100717a(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x1100717f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


// ---- 11007181 FUN_11007181  (called by: FUN_11007335@11007335, FUN_11009ca2@11009ca2)

void FUN_11007181(PVOID param_1,PEXCEPTION_RECORD param_2)

{
  void *pvVar1;
  
  pvVar1 = ExceptionList;
  RtlUnwind(param_1,(PVOID)0x110071a9,param_2,(PVOID)0x0);
  param_2->ExceptionFlags = param_2->ExceptionFlags & 0xfffffffd;
  *(void **)pvVar1 = ExceptionList;
  ExceptionList = pvVar1;
  return;
}


// ---- 110071d0 FUN_110071d0  (called by: FUN_1100cc69@1100cc69, FUN_1100cc7d@1100cc7d, FUN_1100cd2d@1100cd2d, FUN_1100cddd@1100cddd, FUN_1100ce5d@1100ce5d, FUN_1100ce71@1100ce71, FUN_1100ce85@1100ce85, FUN_1100cf32@1100cf32, FUN_1100cf57@1100cf57, FUN_1100cf76@1100cf76, FUN_1100cf89@1100cf89, FUN_1100cf9e@1100cf9e, FUN_1100cfb0@1100cfb0, FUN_1100cfc9@1100cfc9)

undefined4 __cdecl
FUN_110071d0(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  int *in_EAX;
  undefined4 uVar1;
  
  uVar1 = FUN_11009899(param_1,param_2,param_3,param_4,in_EAX,0,(PVOID)0x0,'\0');
  return uVar1;
}


// ---- 11007206 FUN_11007206  (called by: FUN_11009d1d@11009d1d)

undefined4 __cdecl
FUN_11007206(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  void *local_18;
  code *local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  local_10 = param_2;
  local_14 = FUN_1100725a;
  local_8 = param_4 + 1;
  local_c = param_1;
  local_18 = ExceptionList;
  ExceptionList = &local_18;
  uVar1 = __CallSettingFrame_12(param_3,param_1,param_5);
  ExceptionList = local_18;
  return uVar1;
}


// ---- 1100725a FUN_1100725a  (called by: -)

void __cdecl FUN_1100725a(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3)

{
  FUN_11009899(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),param_2,'\0');
  return;
}


// ---- 1100727f FUN_1100727f  (called by: FUN_11009ae7@11009ae7)

undefined4 __cdecl
FUN_1100727f(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  local_28 = FUN_11007335;
  local_24 = param_5;
  local_20 = param_2;
  local_1c = param_6;
  local_18 = param_7;
  local_8 = 0;
  local_14 = 0x11007307;
  local_2c = ExceptionList;
  ExceptionList = &local_2c;
  local_34 = param_1;
  local_30 = param_3;
  ppuVar3 = &local_34;
  uVar2 = *param_1;
  pDVar1 = FUN_1100a181();
  (*(code *)pDVar1[0x1a])(uVar2,ppuVar3);
  if (local_8 != 0) {
    *local_2c = *(undefined4 *)ExceptionList;
  }
  ExceptionList = local_2c;
  return 0;
}


// ---- 11007335 FUN_11007335  (called by: -)

undefined4 __cdecl FUN_11007335(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3)

{
  undefined4 uVar1;
  
  if ((param_1->ExceptionFlags & 0x66) != 0) {
    *(undefined4 *)((int)param_2 + 0x24) = 1;
    return 1;
  }
  FUN_11009899(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),*(PVOID *)((int)param_2 + 0x14),'\x01');
  if (*(int *)((int)param_2 + 0x24) == 0) {
    FUN_11007181(param_2,param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x1100739f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)((int)param_2 + 0x18))();
  return uVar1;
}


// ---- 110073aa FUN_110073aa  (called by: FUN_11009934@11009934, FUN_11009ae7@11009ae7)

int __cdecl FUN_110073aa(uint param_1,int param_2,int param_3,uint *param_4,uint *param_5)

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
        FUN_1100a2e9();
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
    FUN_1100a2e9();
  }
  return iVar1 + uVar3 * 0x14;
}


// ---- 11007428 __global_unwind2  (called by: FUN_1100bd0c@1100bd0c)

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x11007440,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}


// ---- 11007448 FUN_11007448  (called by: -)

undefined4 FUN_11007448(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((*(uint *)(param_1 + 4) & 6) != 0) {
    *param_4 = param_2;
    uVar1 = 3;
  }
  return uVar1;
}


// ---- 1100746a __local_unwind2  (called by: FUN_1100bd0c@1100bd0c, FUN_1100bdc9@1100bdc9)

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
  pcStack_18 = FUN_11007448;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_110074fe();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  ExceptionList = pvStack_1c;
  return;
}


// ---- 110074d2 __abnormal_termination  (called by: FUN_11009dea@11009dea)

/* Library Function - Single Match
    __abnormal_termination
   
   Library: Visual Studio */

int __cdecl __abnormal_termination(void)

{
  int iVar1;
  
  iVar1 = 0;
  if ((*(code **)((int)ExceptionList + 4) == FUN_11007448) &&
     (*(int *)((int)ExceptionList + 8) == *(int *)(*(int *)((int)ExceptionList + 0xc) + 0xc))) {
    iVar1 = 1;
  }
  return iVar1;
}


// ---- 110074f5 __NLG_Notify1  (called by: __CallSettingFrame@12@1100a0b0)

/* Library Function - Single Match
    __NLG_Notify1
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __fastcall __NLG_Notify1(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;
  
  DAT_11010ae8 = param_1;
  DAT_11010ae4 = in_EAX;
  DAT_11010aec = unaff_EBP;
  return;
}


// ---- 110074fe FUN_110074fe  (called by: FUN_1100bd0c@1100bd0c, __local_unwind2@1100746a)

void FUN_110074fe(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_11010ae8 = *(undefined4 *)(unaff_EBP + 8);
  DAT_11010ae4 = in_EAX;
  DAT_11010aec = unaff_EBP;
  return;
}


// ---- 11007518 FUN_11007518  (called by: FUN_1100152b@1100152b, FUN_110016a0@110016a0, FUN_11001a94@11001a94, FUN_11001b51@11001b51, FUN_11002b0d@11002b0d, FUN_1100311d@1100311d, FUN_11003477@11003477, FUN_110034d5@110034d5, FUN_11003d79@11003d79, FUN_11003e72@11003e72, FUN_11004027@11004027, FUN_11004267@11004267)

void FUN_11007518(void)

{
  undefined1 auStack_c [12];
  
  ExceptionList = auStack_c;
  return;
}


// ---- 11007537 FUN_11007537  (called by: FUN_110075b5@110075b5)

int __cdecl FUN_11007537(int param_1)

{
  SIZE_T SVar1;
  int *piVar2;
  
  FUN_11007e57();
  SVar1 = FUN_1100a33f(DAT_110168ac);
  if (SVar1 < (uint)((int)DAT_110168a8 + (4 - (int)DAT_110168ac))) {
    SVar1 = FUN_1100a33f(DAT_110168ac);
    piVar2 = FUN_11007726(DAT_110168ac,(uint *)(SVar1 + 0x10));
    if (piVar2 == (int *)0x0) {
      param_1 = 0;
      goto LAB_110075ac;
    }
    DAT_110168a8 = piVar2 + ((int)DAT_110168a8 - (int)DAT_110168ac >> 2);
    DAT_110168ac = piVar2;
  }
  *DAT_110168a8 = param_1;
  DAT_110168a8 = DAT_110168a8 + 1;
LAB_110075ac:
  FUN_11007e60();
  return param_1;
}


// ---- 110075b5 FUN_110075b5  (called by: FUN_11001a88@11001a88, FUN_1100656b@1100656b)

int __cdecl FUN_110075b5(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_11007537(param_1);
  return (iVar1 != 0) - 1;
}


// ---- 110075f6 FUN_110075f6  (called by: FUN_11004267@11004267, FUN_11004ee9@11004ee9, FUN_110050ff@110050ff, FUN_11006686@11006686, Unwind@1100cf94@1100cf94)

void __cdecl FUN_110075f6(LPVOID param_1)

{
  FUN_11006b21(param_1);
  return;
}


// ---- 11007601 operator_new  (called by: FUN_11004267@11004267, FUN_11004ee9@11004ee9)

/* Library Function - Single Match
    void * __cdecl operator new(unsigned int)
   
   Library: Visual Studio 2003 Release */

void * __cdecl operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(param_1,1);
  return pvVar1;
}


// ---- 1100760f FUN_1100760f  (called by: FUN_11004e24@11004e24, FUN_11004e65@11004e65, FUN_11004ee9@11004ee9)

uint __cdecl FUN_1100760f(char *param_1,uint param_2,uint param_3,int *param_4)

{
  uint uVar1;
  
  FUN_11008daa((uint)param_4);
  uVar1 = FUN_1100763e(param_1,param_2,param_3,param_4);
  FUN_11008dfc((uint)param_4);
  return uVar1;
}


// ---- 1100763e FUN_1100763e  (called by: FUN_1100760f@1100760f)

uint __cdecl FUN_1100763e(char *param_1,uint param_2,uint param_3,int *param_4)

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
        uVar4 = FUN_1100a384(piVar1);
        if (uVar4 == 0xffffffff) goto LAB_1100771a;
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
        iVar3 = FUN_1100a460(piVar1[4],pcVar5,pcVar2);
        if (iVar3 == 0) {
          piVar1[3] = piVar1[3] | 0x10;
LAB_1100771a:
          return (uint)((int)pcVar6 - (int)param_1) / param_2;
        }
        if (iVar3 == -1) {
          piVar1[3] = piVar1[3] | 0x20;
          goto LAB_1100771a;
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
      FUN_11006760((undefined4 *)pcVar5,(undefined4 *)*piVar1,(uint)pcVar7);
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


// ---- 11007726 FUN_11007726  (called by: FUN_11005092@11005092, FUN_11007537@11007537)

int * __cdecl FUN_11007726(int *param_1,uint *param_2)

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
      FUN_11006b21(param_1);
    }
    else {
      do {
        if (param_2 < (uint *)0xffffffe1) {
          FUN_11008139(9);
          puVar2 = (uint *)FUN_110081ed((int)param_1);
          if (puVar2 == (uint *)0x0) {
            FUN_1100819a(9);
            if (param_2 == (uint *)0x0) {
              param_2 = (uint *)0x1;
            }
            param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
            piVar1 = HeapReAlloc(DAT_1101689c,0,param_1,(SIZE_T)param_2);
          }
          else {
            if (DAT_11010bc4 < param_2) {
LAB_110077c5:
              if (param_2 == (uint *)0x0) {
                param_2 = (uint *)0x1;
              }
              param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
              piVar1 = HeapAlloc(DAT_1101689c,0,(SIZE_T)param_2);
              if (piVar1 != (int *)0x0) {
                puVar4 = (uint *)(param_1[-1] - 1U);
                if (param_2 <= (uint *)(param_1[-1] - 1U)) {
                  puVar4 = param_2;
                }
                FUN_11006760(piVar1,param_1,(uint)puVar4);
                FUN_11008218(puVar2,(uint)param_1);
              }
            }
            else {
              iVar3 = FUN_110089f8(puVar2,(int)param_1,(int)param_2);
              if (iVar3 == 0) {
                piVar1 = FUN_11008543(param_2);
                if (piVar1 == (int *)0x0) goto LAB_110077c5;
                puVar4 = (uint *)(param_1[-1] - 1U);
                if (param_2 <= (uint *)(param_1[-1] - 1U)) {
                  puVar4 = param_2;
                }
                FUN_11006760(piVar1,param_1,(uint)puVar4);
                FUN_11008218(puVar2,(uint)param_1);
              }
              else {
                piVar1 = param_1;
              }
              if (piVar1 == (int *)0x0) goto LAB_110077c5;
            }
            FUN_1100819a(9);
          }
          if (piVar1 != (int *)0x0) {
            return piVar1;
          }
        }
        if (DAT_110151f8 == 0) {
          return (int *)0x0;
        }
        iVar3 = FUN_11007fd8(param_2);
      } while (iVar3 != 0);
    }
    piVar1 = (int *)0x0;
  }
  return piVar1;
}


// ---- 11007860 FUN_11007860  (called by: FUN_1100513a@1100513a, FUN_110051a2@110051a2, FUN_1100ab99@1100ab99, FUN_1100b00a@1100b00a)

uint * __cdecl FUN_11007860(uint *param_1,uint *param_2)

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
    if (bVar1 == 0) goto LAB_11007948;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_11007948:
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


// ---- 11007870 FUN_11007870  (called by: FUN_110051a2@110051a2, FUN_1100b00a@1100b00a)

uint * __cdecl FUN_11007870(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_1100788c;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_110078bf;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x110078db;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_1100788c:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x110078db;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x110078db;
    }
  }
LAB_110078bf:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x110078db:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_11007948:
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
    if (bVar1 == 0) goto LAB_11007948;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}


// ---- 11007950 FUN_11007950  (called by: FUN_1100513a@1100513a)

void __cdecl FUN_11007950(byte *param_1,byte *param_2,byte *param_3,byte *param_4,byte *param_5)

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
      pbVar2 = FUN_1100a69e(param_3,pbVar2);
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


// ---- 110079e1 FUN_110079e1  (called by: FUN_1100513a@1100513a)

void __cdecl FUN_110079e1(byte *param_1,byte *param_2,byte *param_3,byte *param_4,byte *param_5)

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
      FUN_1100aaff(param_2,param_1,2);
      param_2[2] = 0;
    }
    pbVar3 = param_1 + 2;
  }
  param_2 = (byte *)0x0;
  param_1 = pbVar3;
  if (*pbVar3 != 0) {
    do {
      bVar1 = *param_1;
      if ((*(byte *)((int)&DAT_11015640 + bVar1 + 1) & 4) == 0) {
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
        FUN_1100aaff(param_3,pbVar3,sVar2);
        param_3[sVar2] = 0;
      }
      pbVar3 = param_2;
      goto LAB_11007aa8;
    }
  }
  if (param_3 != (byte *)0x0) {
    *param_3 = 0;
  }
LAB_11007aa8:
  if ((local_8 == (byte *)0x0) || (local_8 < pbVar3)) {
    if (param_4 != (byte *)0x0) {
      sVar2 = 0xff;
      if ((uint)((int)param_1 - (int)pbVar3) < 0xff) {
        sVar2 = (int)param_1 - (int)pbVar3;
      }
      FUN_1100aaff(param_4,pbVar3,sVar2);
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
      FUN_1100aaff(param_4,pbVar3,sVar2);
      param_4[sVar2] = 0;
    }
    if (param_5 != (byte *)0x0) {
      sVar2 = 0xff;
      if ((uint)((int)param_1 - (int)local_8) < 0xff) {
        sVar2 = (int)param_1 - (int)local_8;
      }
      FUN_1100aaff(param_5,local_8,sVar2);
      param_5[sVar2] = 0;
    }
  }
  return;
}


// ---- 11007b30 _strlen  (called by: FUN_110051a2@110051a2, FUN_110079e1@110079e1, FUN_1100ab99@1100ab99, FUN_1100b00a@1100b00a)

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
    if (((uint)puVar2 & 3) == 0) goto LAB_11007b50;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_11007b83:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_11007b50:
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
  goto LAB_11007b83;
}


// ---- 11007bab FUN_11007bab  (called by: entry@11007c84)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_11007bab(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 1) {
    DAT_110151b8 = GetVersion();
    iVar1 = FUN_11007ff3(1);
    if (iVar1 != 0) {
      _DAT_110151c4 = DAT_110151b8 >> 8 & 0xff;
      _DAT_110151c0 = DAT_110151b8 & 0xff;
      DAT_110151b8 = DAT_110151b8 >> 0x10;
      _DAT_110151bc = _DAT_110151c0 * 0x100 + _DAT_110151c4;
      iVar1 = FUN_1100a0fc();
      if (iVar1 != 0) {
        DAT_110168b4 = GetCommandLineA();
        DAT_110151a4 = FUN_1100ae9f();
        FUN_110090b6();
        FUN_1100ac52();
        FUN_1100ab99();
        FUN_11007d54();
        DAT_110151a0 = DAT_110151a0 + 1;
        goto LAB_11007c7e;
      }
      FUN_1100802f();
    }
LAB_11007c0b:
    uVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      if (DAT_110151a0 < 1) goto LAB_11007c0b;
      DAT_110151a0 = DAT_110151a0 + -1;
      if (DAT_110151f0 == 0) {
        FUN_11007da3();
      }
      FUN_11009272();
      FUN_1100a150();
      FUN_1100802f();
    }
    else if (param_2 == 3) {
      FUN_1100a1e8((LPVOID)0x0);
    }
LAB_11007c7e:
    uVar2 = 1;
  }
  return uVar2;
}


// ---- 11007c84 entry  (called by: -)

int entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2;
  if (param_2 == 0) {
    iVar2 = DAT_110151a0;
  }
  else {
    if ((param_2 != 1) && (param_2 != 2)) goto LAB_11007ccc;
    if ((DAT_110168b8 != (code *)0x0) &&
       (iVar2 = (*DAT_110168b8)(param_1,param_2,param_3), iVar2 == 0)) {
      return 0;
    }
    iVar2 = FUN_11007bab(param_1,param_2);
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_11007ccc:
  iVar2 = FUN_110047ac(param_1,param_2);
  if (param_2 == 1) {
    if (iVar2 != 0) {
      return iVar2;
    }
    FUN_11007bab(param_1,0);
  }
  if ((param_2 == 0) || (param_2 == 3)) {
    iVar3 = FUN_11007bab(param_1,param_2);
    param_2 = iVar2;
    if (iVar3 == 0) {
      param_2 = 0;
    }
    iVar2 = param_2;
    if ((param_2 != 0) && (DAT_110168b8 != (code *)0x0)) {
      iVar2 = (*DAT_110168b8)(param_1,iVar1,param_3);
    }
  }
  param_2 = iVar2;
  return param_2;
}


// ---- 11007d21 __amsg_exit  (called by: FUN_11008139@11008139, FUN_110090b6@110090b6, FUN_1100a181@1100a181, FUN_1100ab99@1100ab99, FUN_1100ac52@1100ac52)

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __amsg_exit(int param_1)

{
  if ((DAT_110151ac == 1) || ((DAT_110151ac == 0 && (DAT_110151b0 == 1)))) {
    FUN_1100afd1();
  }
  FUN_1100b00a(param_1);
  (*(code *)PTR___exit_11010af0)(0xff);
  return;
}


// ---- 11007d54 FUN_11007d54  (called by: FUN_11007bab@11007bab)

void FUN_11007d54(void)

{
  if (DAT_110168b0 != (code *)0x0) {
    (*DAT_110168b0)();
  }
  FUN_11007e69((undefined4 *)&DAT_11010030,(undefined4 *)&DAT_11010044);
  FUN_11007e69((undefined4 *)&DAT_11010000,(undefined4 *)&DAT_1101002c);
  return;
}


// ---- 11007d81 FUN_11007d81  (called by: FUN_11005850@11005850)

void __cdecl FUN_11007d81(UINT param_1)

{
  FUN_11007db2(param_1,0,0);
  return;
}


// ---- 11007d92 __exit  (called by: FUN_1100bde4@1100bde4, FUN_1100c52c@1100c52c, __amsg_exit@11007d21)

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __exit(int _Code)

{
  FUN_11007db2(_Code,1,0);
  return;
}


// ---- 11007da3 FUN_11007da3  (called by: FUN_11007bab@11007bab)

void FUN_11007da3(void)

{
  FUN_11007db2(0,0,1);
  return;
}


// ---- 11007db2 FUN_11007db2  (called by: FUN_11007d81@11007d81, FUN_11007da3@11007da3, __exit@11007d92)

void __cdecl FUN_11007db2(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  FUN_11007e57();
  if (DAT_110151f4 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  DAT_110151f0 = 1;
  DAT_110151ec = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_110168ac != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_110168a8 - 4), DAT_110168ac <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_110168ac <= puVar1);
    }
    FUN_11007e69((undefined4 *)&DAT_11010048,(undefined4 *)&DAT_11010050);
  }
  FUN_11007e69((undefined4 *)&DAT_11010054,(undefined4 *)&DAT_1101005c);
  if (param_3 == 0) {
    DAT_110151f4 = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  FUN_11007e60();
  return;
}


// ---- 11007e57 FUN_11007e57  (called by: FUN_11007537@11007537, FUN_11007db2@11007db2)

void FUN_11007e57(void)

{
  FUN_11008139(0xd);
  return;
}


// ---- 11007e60 FUN_11007e60  (called by: FUN_11007537@11007537, FUN_11007db2@11007db2)

void FUN_11007e60(void)

{
  FUN_1100819a(0xd);
  return;
}


// ---- 11007e69 FUN_11007e69  (called by: FUN_11007d54@11007d54, FUN_11007db2@11007db2)

void __cdecl FUN_11007e69(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}


// ---- 11007e90 _strncmp  (called by: GetSaveRegions@11006200)

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


// ---- 11007ed0 _memcmp  (called by: FUN_11006386@11006386)

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
          goto LAB_11007f4a;
        }
      }
      if (uVar2 != 0) {
        uVar5 = *(uint *)_Buf1;
        uVar1 = *(uint *)_Buf2;
        bVar9 = (byte)uVar5 < (byte)uVar1;
        if ((byte)uVar5 != (byte)uVar1) {
LAB_11007f4a:
          return (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        }
        iVar3 = 0;
        if (uVar2 != 1) {
          bVar6 = (byte)(uVar5 >> 8);
          bVar4 = (byte)(uVar1 >> 8);
          bVar9 = bVar6 < bVar4;
          if (bVar6 != bVar4) goto LAB_11007f4a;
          iVar3 = 0;
          if (uVar2 != 2) {
            bVar9 = (uVar5 & 0xff0000) < (uVar1 & 0xff0000);
            if ((uVar5 & 0xff0000) != (uVar1 & 0xff0000)) goto LAB_11007f4a;
            iVar3 = uVar2 - 3;
          }
        }
        return iVar3;
      }
    }
    else {
      if ((_Size & 1) == 0) goto LAB_11007efd;
      bVar9 = *(byte *)_Buf1 < *(byte *)_Buf2;
      if (*(byte *)_Buf1 != *(byte *)_Buf2) goto LAB_11007f4a;
      _Buf1 = (void *)((int)_Buf1 + 1);
      _Buf2 = (void *)((int)_Buf2 + 1);
      for (_Size = _Size - 1; _Size != 0; _Size = _Size - 2) {
LAB_11007efd:
        bVar9 = *(byte *)_Buf1 < *(byte *)_Buf2;
        if ((*(byte *)_Buf1 != *(byte *)_Buf2) ||
           (bVar9 = *(byte *)((int)_Buf1 + 1) < *(byte *)((int)_Buf2 + 1),
           *(byte *)((int)_Buf1 + 1) != *(byte *)((int)_Buf2 + 1))) goto LAB_11007f4a;
        _Buf2 = (void *)((int)_Buf2 + 2);
        _Buf1 = (void *)((int)_Buf1 + 2);
      }
    }
  }
  return 0;
}


// ---- 11007f80 _memset  (called by: FUN_110065d5@110065d5, FUN_1100b495@1100b495, FUN_1100c134@1100c134, FUN_1100c407@1100c407)

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


// ---- 11007fd8 FUN_11007fd8  (called by: FUN_11007726@11007726, FUN_1100b495@1100b495, __nh_malloc@11006aa7)

undefined4 __cdecl FUN_11007fd8(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_110151fc != (code *)0x0) {
    iVar1 = (*DAT_110151fc)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


// ---- 11007ff3 FUN_11007ff3  (called by: FUN_11007bab@11007bab)

undefined4 __cdecl FUN_11007ff3(int param_1)

{
  int iVar1;
  
  DAT_1101689c = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (DAT_1101689c != (HANDLE)0x0) {
    iVar1 = FUN_110081af();
    if (iVar1 != 0) {
      return 1;
    }
    HeapDestroy(DAT_1101689c);
  }
  return 0;
}


// ---- 1100802f FUN_1100802f  (called by: FUN_11007bab@11007bab)

void FUN_1100802f(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  if (0 < DAT_11016894) {
    puVar2 = (undefined4 *)((int)DAT_11016898 + 0xc);
    do {
      VirtualFree((LPVOID)*puVar2,0x100000,0x4000);
      VirtualFree((LPVOID)*puVar2,0,0x8000);
      HeapFree(DAT_1101689c,0,(LPVOID)puVar2[1]);
      puVar2 = puVar2 + 5;
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_11016894);
  }
  HeapFree(DAT_1101689c,0,DAT_11016898);
  HeapDestroy(DAT_1101689c);
  return;
}


// ---- 110080a4 FUN_110080a4  (called by: FUN_1100a0fc@1100a0fc)

void FUN_110080a4(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_11010b48);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_11010b38);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_11010b28);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_11010b08);
  return;
}


// ---- 110080cd FUN_110080cd  (called by: FUN_1100a150@1100a150)

void FUN_110080cd(void)

{
  undefined **ppuVar1;
  
  ppuVar1 = (undefined **)&DAT_11010b04;
  do {
    if (((((LPCRITICAL_SECTION)*ppuVar1 != (LPCRITICAL_SECTION)0x0) &&
         (ppuVar1 != &PTR_DAT_11010b48)) && (ppuVar1 != &PTR_DAT_11010b38)) &&
       ((ppuVar1 != &PTR_DAT_11010b28 && (ppuVar1 != &PTR_DAT_11010b08)))) {
      DeleteCriticalSection((LPCRITICAL_SECTION)*ppuVar1);
      FUN_11006b21(*ppuVar1);
    }
    ppuVar1 = ppuVar1 + 1;
  } while ((int)ppuVar1 < 0x11010bc4);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_11010b28);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_11010b38);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_11010b48);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_11010b08);
  return;
}


// ---- 11008139 FUN_11008139  (called by: FUN_11006ad3@11006ad3, FUN_11006b21@11006b21, FUN_11006ee4@11006ee4, FUN_11007726@11007726, FUN_11007e57@11007e57, FUN_11008139@11008139, FUN_11008daa@11008daa, FUN_11008dd9@11008dd9, FUN_110097d1@110097d1, FUN_1100a33f@1100a33f, FUN_1100a69e@1100a69e, FUN_1100a70b@1100a70b, FUN_1100aaff@1100aaff, FUN_1100b495@1100b495, FUN_1100b5a3@1100b5a3, FUN_1100b803@1100b803, FUN_1100c52c@1100c52c, FUN_1100c7e0@1100c7e0, FUN_1100c8b0@1100c8b0)

void __cdecl FUN_11008139(int param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  piVar1 = &DAT_11010b04 + param_1;
  if ((&DAT_11010b04)[param_1] == 0) {
    lpCriticalSection = _malloc(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    FUN_11008139(0x11);
    if (*piVar1 == 0) {
      InitializeCriticalSection(lpCriticalSection);
      *piVar1 = (int)lpCriticalSection;
    }
    else {
      FUN_11006b21(lpCriticalSection);
    }
    FUN_1100819a(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)*piVar1);
  return;
}


// ---- 1100819a FUN_1100819a  (called by: FUN_11006ad3@11006ad3, FUN_11006b21@11006b21, FUN_11006ee4@11006ee4, FUN_11007726@11007726, FUN_11007e60@11007e60, FUN_11008139@11008139, FUN_11008dfc@11008dfc, FUN_11008e2b@11008e2b, FUN_110097d1@110097d1, FUN_1100a33f@1100a33f, FUN_1100a69e@1100a69e, FUN_1100a70b@1100a70b, FUN_1100aaff@1100aaff, FUN_1100b495@1100b495, FUN_1100b5a3@1100b5a3, FUN_1100b803@1100b803, FUN_1100c52c@1100c52c, FUN_1100c7e0@1100c7e0, FUN_1100c8b0@1100c8b0)

void __cdecl FUN_1100819a(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_11010b04)[param_1]);
  return;
}


// ---- 110081af FUN_110081af  (called by: FUN_11007ff3@11007ff3)

undefined4 FUN_110081af(void)

{
  DAT_11016898 = HeapAlloc(DAT_1101689c,0,0x140);
  if (DAT_11016898 == (LPVOID)0x0) {
    return 0;
  }
  DAT_11016890 = 0;
  DAT_11016894 = 0;
  DAT_1101688c = DAT_11016898;
  DAT_11016884 = 0x10;
  return 1;
}


// ---- 110081ed FUN_110081ed  (called by: FUN_11006b21@11006b21, FUN_11007726@11007726, FUN_1100a33f@1100a33f)

uint __cdecl FUN_110081ed(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_11016898;
  while( true ) {
    if (DAT_11016898 + DAT_11016894 * 0x14 <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}


// ---- 11008218 FUN_11008218  (called by: FUN_11006b21@11006b21, FUN_11007726@11007726)

void __cdecl FUN_11008218(uint *param_1,uint param_2)

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
  if (DAT_11016890 != (uint *)0x0) {
    VirtualFree((LPVOID)(DAT_11016888 * 0x8000 + DAT_11016890[3]),0x8000,0x4000);
    DAT_11016890[2] = DAT_11016890[2] | 0x80000000U >> ((byte)DAT_11016888 & 0x1f);
    *(undefined4 *)(DAT_11016890[4] + 0xc4 + DAT_11016888 * 4) = 0;
    *(char *)(DAT_11016890[4] + 0x43) = *(char *)(DAT_11016890[4] + 0x43) + -1;
    if (*(char *)(DAT_11016890[4] + 0x43) == '\0') {
      DAT_11016890[1] = DAT_11016890[1] & 0xfffffffe;
    }
    if (DAT_11016890[2] == 0xffffffff) {
      VirtualFree((LPVOID)DAT_11016890[3],0,0x8000);
      HeapFree(DAT_1101689c,0,(LPVOID)DAT_11016890[4]);
      FUN_1100b160(DAT_11016890,DAT_11016890 + 5,
                   (DAT_11016894 * 0x14 - (int)DAT_11016890) + -0x14 + DAT_11016898);
      DAT_11016894 = DAT_11016894 + -1;
      if (DAT_11016890 < param_1) {
        param_1 = param_1 + -5;
      }
      DAT_11016888 = uVar10;
      DAT_1101688c = DAT_11016898;
      DAT_11016890 = param_1;
      return;
    }
  }
  DAT_11016890 = param_1;
  DAT_11016888 = uVar10;
  return;
}


// ---- 11008543 FUN_11008543  (called by: FUN_11006ad3@11006ad3, FUN_11007726@11007726, FUN_1100b495@1100b495)

int * __cdecl FUN_11008543(uint *param_1)

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
  
  puVar10 = DAT_11016898 + DAT_11016894 * 5;
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
  for (param_1 = DAT_1101688c;
      (param_1 < puVar10 && ((param_1[1] & local_c) == 0 && (*param_1 & local_10) == 0));
      param_1 = param_1 + 5) {
  }
  if (param_1 == puVar10) {
    for (param_1 = DAT_11016898;
        (param_1 < DAT_1101688c && ((param_1[1] & local_c) == 0 && (*param_1 & local_10) == 0));
        param_1 = param_1 + 5) {
    }
    if (param_1 == DAT_1101688c) {
      for (; (param_1 < puVar10 && (param_1[2] == 0)); param_1 = param_1 + 5) {
      }
      if (param_1 == puVar10) {
        for (param_1 = DAT_11016898; (param_1 < DAT_1101688c && (param_1[2] == 0));
            param_1 = param_1 + 5) {
        }
        if ((param_1 == DAT_1101688c) && (param_1 = FUN_1100884c(), param_1 == (uint *)0x0)) {
          return (int *)0x0;
        }
      }
      iVar8 = FUN_110088fd((int)param_1);
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
  DAT_1101688c = param_1;
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
    if (iVar11 == 0) goto LAB_11008809;
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
LAB_11008809:
  piVar12 = (int *)((int)piVar12 + iVar11);
  *piVar12 = uVar7 + 1;
  *(uint *)((int)piVar12 + (uVar7 - 4)) = uVar7 + 1;
  iVar8 = *piVar3;
  *piVar3 = iVar8 + 1;
  if (((iVar8 == 0) && (param_1 == DAT_11016890)) && (local_8 == DAT_11016888)) {
    DAT_11016890 = (uint *)0x0;
  }
  *piVar5 = local_8;
  return piVar12 + 1;
}


// ---- 1100884c FUN_1100884c  (called by: FUN_11008543@11008543)

undefined4 * FUN_1100884c(void)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  
  if (DAT_11016894 == DAT_11016884) {
    pvVar2 = HeapReAlloc(DAT_1101689c,0,DAT_11016898,(DAT_11016884 * 5 + 0x50) * 4);
    if (pvVar2 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_11016884 = DAT_11016884 + 0x10;
    DAT_11016898 = pvVar2;
  }
  puVar1 = (undefined4 *)((int)DAT_11016898 + DAT_11016894 * 0x14);
  pvVar2 = HeapAlloc(DAT_1101689c,8,0x41c4);
  puVar1[4] = pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar1[3] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      puVar1[2] = 0xffffffff;
      *puVar1 = 0;
      puVar1[1] = 0;
      DAT_11016894 = DAT_11016894 + 1;
      *(undefined4 *)puVar1[4] = 0xffffffff;
      return puVar1;
    }
    HeapFree(DAT_1101689c,0,(LPVOID)puVar1[4]);
  }
  return (undefined4 *)0x0;
}


// ---- 110088fd FUN_110088fd  (called by: FUN_11008543@11008543)

int __cdecl FUN_110088fd(int param_1)

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


// ---- 110089f8 FUN_110089f8  (called by: FUN_11007726@11007726)

undefined4 __cdecl FUN_110089f8(uint *param_1,int param_2,int param_3)

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


// ---- 11008daa FUN_11008daa  (called by: FUN_11006b69@11006b69, FUN_11006be6@11006be6, FUN_11006c9f@11006c9f, FUN_11006e22@11006e22, FUN_11006f88@11006f88, FUN_1100760f@1100760f)

void __cdecl FUN_11008daa(uint param_1)

{
  if ((param_1 < 0x11010bc8) || (0x11010e28 < param_1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
    return;
  }
  FUN_11008139(((int)(param_1 + 0xeefef438) >> 5) + 0x1c);
  return;
}


// ---- 11008dd9 FUN_11008dd9  (called by: FUN_11006ee4@11006ee4, FUN_110097d1@110097d1)

void __cdecl FUN_11008dd9(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_11008139(param_1 + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}


// ---- 11008dfc FUN_11008dfc  (called by: FUN_11006b69@11006b69, FUN_11006be6@11006be6, FUN_11006c9f@11006c9f, FUN_11006e22@11006e22, FUN_11006f88@11006f88, FUN_110070c1@110070c1, FUN_1100760f@1100760f)

void __cdecl FUN_11008dfc(uint param_1)

{
  if ((param_1 < 0x11010bc8) || (0x11010e28 < param_1)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
    return;
  }
  FUN_1100819a(((int)(param_1 + 0xeefef438) >> 5) + 0x1c);
  return;
}


// ---- 11008e2b FUN_11008e2b  (called by: FUN_11006ee4@11006ee4, FUN_110097d1@110097d1)

void __cdecl FUN_11008e2b(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_1100819a(param_1 + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}


// ---- 11008e4e FUN_11008e4e  (called by: FUN_1100b8f1@1100b8f1, __fclose_lk@11006b9a)

undefined4 __cdecl FUN_11008e4e(uint param_1)

{
  undefined4 uVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_11015860) &&
     ((*(byte *)((&DAT_11015760)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_1100b803(param_1);
    uVar1 = FUN_11008eab(param_1);
    FUN_1100b862(param_1);
    return uVar1;
  }
  pDVar2 = FUN_11008fcc();
  *pDVar2 = 9;
  pDVar2 = FUN_11008fd5();
  *pDVar2 = 0;
  return 0xffffffff;
}


// ---- 11008eab FUN_11008eab  (called by: FUN_11008e4e@11008e4e)

undefined4 __cdecl FUN_11008eab(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  undefined4 uVar5;
  
  iVar1 = FUN_1100b7c1(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_1100b7c1(2);
      iVar2 = FUN_1100b7c1(1);
      if (iVar2 == iVar1) goto LAB_11008ef9;
    }
    hObject = (HANDLE)FUN_1100b7c1(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_11008efb;
    }
  }
LAB_11008ef9:
  DVar4 = 0;
LAB_11008efb:
  FUN_1100b742(param_1);
  *(undefined1 *)((&DAT_11015760)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = 0;
  if (DVar4 == 0) {
    uVar5 = 0;
  }
  else {
    FUN_11008f59(DVar4);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}


// ---- 11008f2e __freebuf  (called by: __fclose_lk@11006b9a)

/* Library Function - Single Match
    __freebuf
   
   Library: Visual Studio 2003 Release */

void __cdecl __freebuf(FILE *_File)

{
  if (((_File->_flag & 0x83U) != 0) && ((_File->_flag & 8U) != 0)) {
    FUN_11006b21(_File->_base);
    *(ushort *)&_File->_flag = (ushort)_File->_flag & 0xfbf7;
    _File->_ptr = (char *)0x0;
    _File->_base = (char *)0x0;
    _File->_cnt = 0;
  }
  return;
}


// ---- 11008f59 FUN_11008f59  (called by: FUN_11008eab@11008eab, FUN_11009043@11009043, FUN_110093be@110093be, FUN_1100a4c5@1100a4c5, FUN_1100b8f1@1100b8f1)

void __cdecl FUN_11008f59(uint param_1)

{
  DWORD *pDVar1;
  uint *puVar2;
  int iVar3;
  
  pDVar1 = FUN_11008fd5();
  iVar3 = 0;
  *pDVar1 = param_1;
  puVar2 = &DAT_11010e48;
  do {
    if (param_1 == *puVar2) {
      pDVar1 = FUN_11008fcc();
      *pDVar1 = *(DWORD *)(iVar3 * 8 + 0x11010e4c);
      return;
    }
    puVar2 = puVar2 + 2;
    iVar3 = iVar3 + 1;
  } while ((int)puVar2 < 0x11010fb0);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    pDVar1 = FUN_11008fcc();
    *pDVar1 = 0xd;
    return;
  }
  if ((param_1 < 0xbc) || (0xca < param_1)) {
    pDVar1 = FUN_11008fcc();
    *pDVar1 = 0x16;
    return;
  }
  pDVar1 = FUN_11008fcc();
  *pDVar1 = 8;
  return;
}


// ---- 11008fcc FUN_11008fcc  (called by: FUN_11006c12@11006c12, FUN_11006cc1@11006cc1, FUN_11008e4e@11008e4e, FUN_11008f59@11008f59, FUN_11008fde@11008fde, FUN_11009043@11009043, FUN_110092c6@110092c6, FUN_11009359@11009359, FUN_110093be@110093be, FUN_1100a460@1100a460, FUN_1100a4c5@1100a4c5, FUN_1100b6c6@1100b6c6, FUN_1100b742@1100b742, FUN_1100b7c1@1100b7c1, FUN_1100b8f1@1100b8f1, FUN_1100c407@1100c407, FUN_1100c6f4@1100c6f4)

DWORD * FUN_11008fcc(void)

{
  DWORD *pDVar1;
  
  pDVar1 = FUN_1100a181();
  return pDVar1 + 2;
}


// ---- 11008fd5 FUN_11008fd5  (called by: FUN_11008e4e@11008e4e, FUN_11008f59@11008f59, FUN_11008fde@11008fde, FUN_110092c6@110092c6, FUN_11009359@11009359, FUN_110093be@110093be, FUN_1100a460@1100a460, FUN_1100a4c5@1100a4c5, FUN_1100b6c6@1100b6c6, FUN_1100b742@1100b742, FUN_1100b7c1@1100b7c1, FUN_1100b8f1@1100b8f1, FUN_1100c407@1100c407)

DWORD * FUN_11008fd5(void)

{
  DWORD *pDVar1;
  
  pDVar1 = FUN_1100a181();
  return pDVar1 + 3;
}


// ---- 11008fde FUN_11008fde  (called by: FUN_11006c12@11006c12, FUN_11006cc1@11006cc1, FUN_11009549@11009549)

DWORD __cdecl FUN_11008fde(uint param_1,LONG param_2,DWORD param_3)

{
  DWORD DVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_11015860) &&
     ((*(byte *)((&DAT_11015760)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_1100b803(param_1);
    DVar1 = FUN_11009043(param_1,param_2,param_3);
    FUN_1100b862(param_1);
    return DVar1;
  }
  pDVar2 = FUN_11008fcc();
  *pDVar2 = 9;
  pDVar2 = FUN_11008fd5();
  *pDVar2 = 0;
  return 0xffffffff;
}


// ---- 11009043 FUN_11009043  (called by: FUN_11008fde@11008fde, FUN_110093be@110093be, FUN_1100a4c5@1100a4c5, FUN_1100b8f1@1100b8f1, FUN_1100c407@1100c407)

DWORD __cdecl FUN_11009043(uint param_1,LONG param_2,DWORD param_3)

{
  byte *pbVar1;
  HANDLE hFile;
  DWORD *pDVar2;
  DWORD DVar3;
  uint uVar4;
  
  hFile = (HANDLE)FUN_1100b7c1(param_1);
  if (hFile == (HANDLE)0xffffffff) {
    pDVar2 = FUN_11008fcc();
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
      pbVar1 = (byte *)((&DAT_11015760)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
      *pbVar1 = *pbVar1 & 0xfd;
      return DVar3;
    }
    FUN_11008f59(uVar4);
  }
  return 0xffffffff;
}


// ---- 110090b6 FUN_110090b6  (called by: FUN_11007bab@11007bab)

void FUN_110090b6(void)

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
  DAT_11015860 = 0x20;
  DAT_11015760 = puVar2;
  for (; puVar2 < DAT_11015760 + 0x120; puVar2 = puVar2 + 9) {
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
    if ((int)DAT_11015860 < (int)UVar8) {
      puVar2 = &DAT_11015764;
      do {
        puVar3 = _malloc(0x480);
        if (puVar3 == (undefined4 *)0x0) {
          UVar8 = DAT_11015860;
          break;
        }
        DAT_11015860 = DAT_11015860 + 0x20;
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
      } while ((int)DAT_11015860 < (int)UVar8);
    }
    uVar7 = 0;
    if (0 < (int)UVar8) {
      do {
        if (((*(HANDLE *)local_8 != (HANDLE)0xffffffff) && ((*pUVar5 & 1) != 0)) &&
           (((*pUVar5 & 8) != 0 || (DVar4 = GetFileType(*(HANDLE *)local_8), DVar4 != 0)))) {
          puVar2 = (undefined4 *)((int)(&DAT_11015760)[(int)uVar7 >> 5] + (uVar7 & 0x1f) * 0x24);
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
    puVar2 = DAT_11015760 + iVar6 * 9;
    if (DAT_11015760[iVar6 * 9] == -1) {
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
          goto LAB_1100925b;
        }
      }
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x40;
    }
    else {
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x80;
    }
LAB_1100925b:
    iVar6 = iVar6 + 1;
    if (2 < iVar6) {
      SetHandleCount(DAT_11015860);
      return;
    }
  } while( true );
}


// ---- 11009272 FUN_11009272  (called by: FUN_11007bab@11007bab)

void FUN_11009272(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint *puVar1;
  uint uVar2;
  
  puVar1 = &DAT_11015760;
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
      FUN_11006b21((LPVOID)*puVar1);
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x11015860);
  return;
}


// ---- 110092c6 FUN_110092c6  (called by: FUN_11006e51@11006e51)

undefined4 __cdecl FUN_110092c6(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  DWORD *pDVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (DAT_11015860 <= param_1) {
LAB_11009347:
    pDVar3 = FUN_11008fcc();
    *pDVar3 = 9;
    return 0xffffffff;
  }
  iVar4 = (param_1 & 0x1f) * 0x24;
  if ((*(byte *)((&DAT_11015760)[(int)param_1 >> 5] + 4 + iVar4) & 1) == 0) goto LAB_11009347;
  FUN_1100b803(param_1);
  if ((*(byte *)((&DAT_11015760)[(int)param_1 >> 5] + 4 + iVar4) & 1) != 0) {
    hFile = (HANDLE)FUN_1100b7c1(param_1);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = 0;
    }
    uVar5 = 0;
    if (DVar2 == 0) goto LAB_1100933c;
    pDVar3 = FUN_11008fd5();
    *pDVar3 = DVar2;
  }
  pDVar3 = FUN_11008fcc();
  *pDVar3 = 9;
  uVar5 = 0xffffffff;
LAB_1100933c:
  FUN_1100b862(param_1);
  return uVar5;
}


// ---- 11009359 FUN_11009359  (called by: FUN_11006e7f@11006e7f, FUN_11006fb7@11006fb7, FUN_11009549@11009549)

int __cdecl FUN_11009359(uint param_1,char *param_2,DWORD param_3)

{
  int iVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_11015860) &&
     ((*(byte *)((&DAT_11015760)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_1100b803(param_1);
    iVar1 = FUN_110093be(param_1,param_2,param_3);
    FUN_1100b862(param_1);
    return iVar1;
  }
  pDVar2 = FUN_11008fcc();
  *pDVar2 = 9;
  pDVar2 = FUN_11008fd5();
  *pDVar2 = 0;
  return -1;
}


// ---- 110093be FUN_110093be  (called by: FUN_11009359@11009359, FUN_1100c407@1100c407)

int __cdecl FUN_110093be(DWORD param_1,char *param_2,DWORD param_3)

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
LAB_110093d7:
    iVar4 = 0;
  }
  else {
    piVar1 = &DAT_11015760 + ((int)param_1 >> 5);
    iVar4 = (param_1 & 0x1f) * 0x24;
    if ((*(byte *)(*piVar1 + 4 + iVar4) & 0x20) != 0) {
      FUN_11009043(param_1,0,2);
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
LAB_110094a6:
      if (local_c != 0) {
        return local_c - local_14;
      }
      if (param_1 == 0) goto LAB_11009518;
      if (param_1 == 5) {
        pDVar7 = FUN_11008fcc();
        *pDVar7 = 9;
        pDVar7 = FUN_11008fd5();
        *pDVar7 = 5;
      }
      else {
        FUN_11008f59(param_1);
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
            goto LAB_110094a6;
          }
          local_c = local_c + local_10;
          if (((int)local_10 < (int)pcVar5 - (int)local_418) ||
             (param_3 <= (uint)((int)local_8 - (int)param_2))) goto LAB_110094a6;
        } while( true );
      }
LAB_11009518:
      if (((*(byte *)(*piVar1 + 4 + iVar4) & 0x40) != 0) && (*param_2 == '\x1a')) goto LAB_110093d7;
      pDVar7 = FUN_11008fcc();
      *pDVar7 = 0x1c;
      pDVar7 = FUN_11008fd5();
      *pDVar7 = 0;
    }
    iVar4 = -1;
  }
  return iVar4;
}


// ---- 11009549 FUN_11009549  (called by: FUN_11006fb7@11006fb7, __putw@1100cc10)

uint __cdecl FUN_11009549(uint param_1,int *param_2)

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
LAB_11009655:
    param_2[3] = uVar1 | 0x20;
  }
  else {
    if ((uVar1 & 1) != 0) {
      param_2[1] = 0;
      if ((uVar1 & 0x10) == 0) goto LAB_11009655;
      *param_2 = param_2[2];
      param_2[3] = uVar1 & 0xfffffffe;
    }
    uVar1 = param_2[3];
    param_2[1] = 0;
    param_2 = (int *)0x0;
    piVar4[3] = uVar1 & 0xffffffef | 2;
    if (((uVar1 & 0x10c) == 0) &&
       (((piVar4 != (int *)&DAT_11010be8 && (piVar4 != (int *)&DAT_11010c08)) ||
        (bVar5 = FUN_1100b8c8(uVar2), CONCAT31(extraout_var,bVar5) == 0)))) {
      FUN_1100b884(piVar4);
    }
    if ((*(ushort *)(piVar4 + 3) & 0x108) == 0) {
      piVar7 = (int *)0x1;
      param_2 = (int *)FUN_11009359(uVar2,(char *)&param_1,1);
    }
    else {
      pcVar3 = (char *)piVar4[2];
      piVar7 = (int *)(*piVar4 - (int)pcVar3);
      *piVar4 = (int)(pcVar3 + 1);
      piVar4[1] = piVar4[6] + -1;
      if ((int)piVar7 < 1) {
        if (uVar2 == 0xffffffff) {
          puVar6 = &DAT_11010fb0;
        }
        else {
          puVar6 = (undefined *)((&DAT_11015760)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
        }
        if ((puVar6[4] & 0x20) != 0) {
          FUN_11008fde(uVar2,0,2);
        }
      }
      else {
        param_2 = (int *)FUN_11009359(uVar2,pcVar3,(DWORD)piVar7);
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


// ---- 11009661 FUN_11009661  (called by: FUN_110070c1@110070c1)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __cdecl FUN_11009661(LPCSTR param_1,char *param_2,uint param_3,undefined4 *param_4)

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
      uVar6 = DAT_11015374 | 1;
      goto LAB_110096a2;
    }
    if (cVar1 != 'w') {
      return (undefined4 *)0x0;
    }
    uVar5 = 0x301;
  }
  uVar6 = DAT_11015374 | 2;
LAB_110096a2:
  bVar2 = true;
LAB_110096a5:
  cVar1 = param_2[1];
  param_2 = param_2 + 1;
  if ((cVar1 == '\0') || (!bVar2)) {
    uVar5 = FUN_1100b8f1(param_1,uVar5,param_3,0x1a4);
    if ((int)uVar5 < 0) {
      return (undefined4 *)0x0;
    }
    _DAT_11015260 = _DAT_11015260 + 1;
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
        goto LAB_110096a5;
      }
    }
    else if (cVar1 == '+') {
      if ((uVar5 & 2) == 0) {
        uVar5 = uVar5 & 0xfffffffe | 2;
        uVar6 = uVar6 & 0xfffffffc | 0x80;
        goto LAB_110096a5;
      }
    }
    else if (cVar1 == 'D') {
      if ((uVar5 & 0x40) == 0) {
        uVar5 = uVar5 | 0x40;
        goto LAB_110096a5;
      }
    }
    else if (cVar1 == 'R') {
      if (!bVar3) {
        bVar3 = true;
        uVar5 = uVar5 | 0x10;
        goto LAB_110096a5;
      }
    }
    else if ((cVar1 == 'S') && (!bVar3)) {
      bVar3 = true;
      uVar5 = uVar5 | 0x20;
      goto LAB_110096a5;
    }
  }
  else {
    if (cVar1 == 'b') {
      if ((uVar5 & 0xc000) != 0) goto LAB_11009785;
      uVar5 = uVar5 | 0x8000;
      goto LAB_110096a5;
    }
    if (cVar1 == 'c') {
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 | 0x4000;
        goto LAB_110096a5;
      }
    }
    else {
      if (cVar1 != 'n') {
        if ((cVar1 != 't') || ((uVar5 & 0xc000) != 0)) goto LAB_11009785;
        uVar5 = uVar5 | 0x4000;
        goto LAB_110096a5;
      }
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 & 0xffffbfff;
        goto LAB_110096a5;
      }
    }
  }
LAB_11009785:
  bVar2 = false;
  goto LAB_110096a5;
}


// ---- 110097d1 FUN_110097d1  (called by: FUN_110070c1@110070c1)

undefined4 * FUN_110097d1(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)0x0;
  FUN_11008139(2);
  iVar3 = 0;
  if (0 < DAT_11016880) {
    do {
      iVar1 = *(int *)(DAT_11015864 + iVar3 * 4);
      if (iVar1 == 0) {
        iVar3 = iVar3 * 4;
        pvVar2 = _malloc(0x38);
        *(void **)(iVar3 + DAT_11015864) = pvVar2;
        if (*(int *)(iVar3 + DAT_11015864) != 0) {
          InitializeCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_11015864) + 0x20));
          EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_11015864) + 0x20));
          puVar4 = *(undefined4 **)(iVar3 + DAT_11015864);
LAB_11009875:
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
        FUN_11008dd9(iVar3,iVar1);
        iVar1 = *(int *)(DAT_11015864 + iVar3 * 4);
        if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
          puVar4 = *(undefined4 **)(DAT_11015864 + iVar3 * 4);
          goto LAB_11009875;
        }
        FUN_11008e2b(iVar3,iVar1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_11016880);
  }
  FUN_1100819a(2);
  return puVar4;
}


// ---- 11009899 FUN_11009899  (called by: FUN_110071d0@110071d0, FUN_1100725a@1100725a, FUN_11007335@11007335)

undefined4 __cdecl
FUN_11009899(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int *param_5,
            int param_6,PVOID param_7,char param_8)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (*param_5 != 0x19930520) {
    FUN_1100a2e9();
  }
  if ((param_1->ExceptionFlags & 0x66) == 0) {
    if (param_5[3] != 0) {
      if (((param_1->ExceptionCode == 0xe06d7363) && (0x19930520 < param_1->ExceptionInformation[0])
          ) && (pcVar1 = *(code **)(param_1->ExceptionInformation[2] + 8), pcVar1 != (code *)0x0)) {
        uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
        return uVar2;
      }
      FUN_11009934(param_1,param_2,param_3,param_4,(uint)param_5,param_8,param_6,param_7);
    }
  }
  else if ((param_5[1] != 0) && (param_6 == 0)) {
    FUN_11009bee((int)param_2,param_4,(int)param_5,-1);
  }
  return 1;
}


// ---- 11009934 FUN_11009934  (called by: FUN_11009899@11009899)

void __cdecl
FUN_11009934(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,uint param_5,
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
    FUN_1100a2e9();
  }
  if (param_1->ExceptionCode == 0xe06d7363) {
    if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
       (param_1->ExceptionInformation[2] == 0)) {
      pDVar3 = FUN_1100a181();
      if (pDVar3[0x1b] == 0) {
        return;
      }
      pDVar3 = FUN_1100a181();
      param_1 = (PEXCEPTION_RECORD)pDVar3[0x1b];
      pDVar3 = FUN_1100a181();
      param_3 = pDVar3[0x1c];
      local_18 = CONCAT31(local_18._1_3_,1);
      bVar2 = FUN_1100bc24(param_1,1);
      if (CONCAT31(extraout_var,bVar2) == 0) {
        FUN_1100a2e9();
      }
      if (param_1->ExceptionCode != 0xe06d7363) goto LAB_11009abc;
      if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
         (param_1->ExceptionInformation[2] == 0)) {
        FUN_1100a2e9();
      }
    }
    iVar5 = local_14;
    if (((param_1->ExceptionCode == 0xe06d7363) && (param_1->NumberParameters == 3)) &&
       (param_1->ExceptionInformation[0] == 0x19930520)) {
      piVar4 = (int *)FUN_110073aa(param_5,param_7,local_14,&local_8,&local_1c);
      do {
        if (local_1c <= local_8) {
          if (param_6 == '\0') {
            return;
          }
          FUN_1100a026((int)param_1);
          return;
        }
        if ((*piVar4 <= iVar5) && (iVar5 <= piVar4[1])) {
          pbVar1 = (byte *)piVar4[4];
          for (local_10 = piVar4[3]; 0 < local_10; local_10 = local_10 + -1) {
            piVar6 = *(int **)(param_1->ExceptionInformation[2] + 0xc);
            for (local_c = *piVar6; 0 < local_c; local_c = local_c + -1) {
              piVar6 = piVar6 + 1;
              iVar5 = FUN_11009b91(pbVar1,(byte *)*piVar6,(uint *)param_1->ExceptionInformation[2]);
              if (iVar5 != 0) {
                FUN_11009ca2(param_1,param_2,param_3,param_4,param_5,pbVar1,(byte *)*piVar6,piVar4,
                             param_7,param_8);
                goto LAB_11009a99;
              }
            }
            pbVar1 = pbVar1 + 0x10;
          }
LAB_11009a99:
          iVar5 = local_14;
        }
        local_8 = local_8 + 1;
        piVar4 = piVar4 + 5;
      } while( true );
    }
  }
LAB_11009abc:
  if (param_6 == '\0') {
    FUN_11009ae7(param_1,param_2,param_3,param_4,param_5,local_14,param_7,param_8);
    return;
  }
  FUN_1100a288();
  return;
}


// ---- 11009ae7 FUN_11009ae7  (called by: FUN_11009934@11009934)

void __cdecl
FUN_11009ae7(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,uint param_5,
            int param_6,int param_7,PVOID param_8)

{
  DWORD *pDVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint local_c;
  uint local_8;
  
  pDVar1 = FUN_1100a181();
  if ((pDVar1[0x1a] != 0) &&
     (iVar2 = FUN_1100727f(&param_1->ExceptionCode,param_2,param_3,param_4,param_5,param_7,param_8),
     iVar2 != 0)) {
    return;
  }
  piVar3 = (int *)FUN_110073aa(param_5,param_7,param_6,&local_8,&local_c);
  for (; local_8 < local_c; local_8 = local_8 + 1) {
    if ((*piVar3 <= param_6) && (param_6 <= piVar3[1])) {
      iVar4 = piVar3[3] * 0x10 + piVar3[4];
      iVar2 = *(int *)(iVar4 + -0xc);
      if ((iVar2 == 0) || (*(char *)(iVar2 + 8) == '\0')) {
        FUN_11009ca2(param_1,param_2,param_3,param_4,param_5,(byte *)(iVar4 + -0x10),(byte *)0x0,
                     piVar3,param_7,param_8);
      }
    }
    piVar3 = piVar3 + 5;
  }
  return;
}


// ---- 11009b91 FUN_11009b91  (called by: FUN_11009934@11009934)

undefined4 __cdecl FUN_11009b91(byte *param_1,byte *param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || (*(char *)(iVar1 + 8) == '\0')) {
LAB_11009be8:
    uVar2 = 1;
  }
  else {
    if (iVar1 == *(int *)(param_2 + 4)) {
LAB_11009bc2:
      if (((((*param_2 & 2) == 0) || ((*param_1 & 8) != 0)) &&
          (((*param_3 & 1) == 0 || ((*param_1 & 1) != 0)))) &&
         (((*param_3 & 2) == 0 || ((*param_1 & 2) != 0)))) goto LAB_11009be8;
    }
    else {
      iVar1 = _strcmp((char *)(iVar1 + 8),(char *)(*(int *)(param_2 + 4) + 8));
      if (iVar1 == 0) goto LAB_11009bc2;
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ---- 11009bee FUN_11009bee  (called by: FUN_11009899@11009899, FUN_11009ca2@11009ca2)

void __cdecl FUN_11009bee(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_1100d3f0;
  pcStack_10 = FUN_1100bd0c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  for (iVar2 = *(int *)(param_1 + 8); local_8 = 0xffffffff, iVar2 != param_4;
      iVar2 = *(int *)(*(int *)(param_3 + 8) + iVar2 * 8)) {
    if ((iVar2 < 0) || (*(int *)(param_3 + 4) <= iVar2)) {
      FUN_1100a2e9();
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


// ---- 11009ca2 FUN_11009ca2  (called by: FUN_11009934@11009934, FUN_11009ae7@11009ae7)

void __cdecl
FUN_11009ca2(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int param_5,
            byte *param_6,byte *param_7,int *param_8,int param_9,PVOID param_10)

{
  undefined *UNRECOVERED_JUMPTABLE;
  
  if (param_7 != (byte *)0x0) {
    FUN_11009e62((int)param_1,(int)param_2,param_6,param_7);
  }
  if (param_10 == (PVOID)0x0) {
    param_10 = param_2;
  }
  else {
  }
  FUN_11007181(param_10,param_1);
  FUN_11009bee((int)param_2,param_4,param_5,*param_8);
  *(int *)((int)param_2 + 8) = param_8[1] + 1;
  UNRECOVERED_JUMPTABLE =
       (undefined *)
       FUN_11009d1d((DWORD)param_1,param_2,param_3,param_5,*(undefined4 *)(param_6 + 0xc),param_9,
                    0x100);
  if (UNRECOVERED_JUMPTABLE != (undefined *)0x0) {
    FUN_1100713f(UNRECOVERED_JUMPTABLE);
  }
  return;
}


// ---- 11009d1d FUN_11009d1d  (called by: FUN_11009ca2@11009ca2)

undefined4 __cdecl
FUN_11009d1d(DWORD param_1,undefined4 param_2,DWORD param_3,undefined4 param_4,undefined4 param_5,
            int param_6,int param_7)

{
  DWORD *pDVar1;
  undefined4 uVar2;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_1100d400;
  pcStack_10 = FUN_1100bd0c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_1100a181();
  FUN_1100a181();
  pDVar1 = FUN_1100a181();
  pDVar1[0x1b] = param_1;
  pDVar1 = FUN_1100a181();
  pDVar1[0x1c] = param_3;
  local_8 = 1;
  uVar2 = FUN_11007206(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_11009dea();
  ExceptionList = local_14;
  return uVar2;
}


// ---- 11009dea FUN_11009dea  (called by: FUN_11009d1d@11009d1d)

void FUN_11009dea(void)

{
  DWORD *pDVar1;
  int unaff_EBP;
  int unaff_ESI;
  int *unaff_EDI;
  
  *(undefined4 *)(unaff_ESI + -4) = *(undefined4 *)(unaff_EBP + -0x28);
  pDVar1 = FUN_1100a181();
  pDVar1[0x1b] = *(DWORD *)(unaff_EBP + -0x1c);
  pDVar1 = FUN_1100a181();
  pDVar1[0x1c] = *(DWORD *)(unaff_EBP + -0x20);
  if ((((*unaff_EDI == -0x1f928c9d) && (unaff_EDI[4] == 3)) && (unaff_EDI[5] == 0x19930520)) &&
     ((*(int *)(unaff_EBP + -0x24) == 0 && (*(int *)(unaff_EBP + -0x2c) != 0)))) {
    __abnormal_termination();
    FUN_1100a026((int)unaff_EDI);
  }
  return;
}


// ---- 11009e62 FUN_11009e62  (called by: FUN_11009ca2@11009ca2)

void __cdecl FUN_11009e62(int param_1,int param_2,byte *param_3,byte *param_4)

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
  
  puStack_c = &DAT_1100d418;
  pcStack_10 = FUN_1100bd0c;
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
        bVar2 = FUN_1100bc24(*(void **)(param_1 + 0x18),1);
        if ((CONCAT31(extraout_var_03,bVar2) != 0) &&
           (bVar2 = FUN_1100bc40(piVar1,1), CONCAT31(extraout_var_04,bVar2) != 0)) {
          uVar5 = *(uint *)(param_4 + 0x14);
          puVar4 = (undefined4 *)FUN_1100a08d(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
          FUN_1100b160(piVar1,puVar4,uVar5);
          ExceptionList = local_14;
          return;
        }
      }
      else {
        ExceptionList = &local_14;
        bVar2 = FUN_1100bc24(*(void **)(param_1 + 0x18),1);
        if (((CONCAT31(extraout_var_05,bVar2) != 0) &&
            (bVar2 = FUN_1100bc40(piVar1,1), CONCAT31(extraout_var_06,bVar2) != 0)) &&
           (bVar2 = FUN_1100bc5c(*(FARPROC *)(param_4 + 0x18)), CONCAT31(extraout_var_07,bVar2) != 0
           )) {
          if ((*param_4 & 4) == 0) {
            FUN_1100a08d(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
            FUN_11007173(piVar1,*(undefined **)(param_4 + 0x18));
            ExceptionList = local_14;
            return;
          }
          FUN_1100a08d(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
          FUN_1100717a(piVar1,*(undefined **)(param_4 + 0x18));
          ExceptionList = local_14;
          return;
        }
      }
    }
    else {
      ExceptionList = &local_14;
      bVar2 = FUN_1100bc24(*(void **)(param_1 + 0x18),1);
      if ((CONCAT31(extraout_var_01,bVar2) != 0) &&
         (bVar2 = FUN_1100bc40(piVar1,1), CONCAT31(extraout_var_02,bVar2) != 0)) {
        FUN_1100b160(piVar1,*(undefined4 **)(param_1 + 0x18),*(uint *)(param_4 + 0x14));
        if (*(int *)(param_4 + 0x14) != 4) {
          ExceptionList = local_14;
          return;
        }
        iVar3 = *piVar1;
        if (iVar3 == 0) {
          ExceptionList = local_14;
          return;
        }
        goto LAB_11009ef0;
      }
    }
  }
  else {
    ExceptionList = &local_14;
    bVar2 = FUN_1100bc24(*(void **)(param_1 + 0x18),1);
    if ((CONCAT31(extraout_var,bVar2) != 0) &&
       (bVar2 = FUN_1100bc40(piVar1,1), CONCAT31(extraout_var_00,bVar2) != 0)) {
      iVar3 = *(int *)(param_1 + 0x18);
      *piVar1 = iVar3;
LAB_11009ef0:
      iVar3 = FUN_1100a08d(iVar3,(int *)(param_4 + 8));
      *piVar1 = iVar3;
      ExceptionList = local_14;
      return;
    }
  }
  FUN_1100a2e9();
  ExceptionList = local_14;
  return;
}


// ---- 1100a026 FUN_1100a026  (called by: FUN_11009934@11009934, FUN_11009dea@11009dea)

void __cdecl FUN_1100a026(int param_1)

{
  undefined *UNRECOVERED_JUMPTABLE;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_1100d428;
  pcStack_10 = FUN_1100bd0c;
  local_14 = ExceptionList;
  if ((param_1 != 0) &&
     (UNRECOVERED_JUMPTABLE = *(undefined **)(*(int *)(param_1 + 0x1c) + 4),
     UNRECOVERED_JUMPTABLE != (undefined *)0x0)) {
    local_8 = 0;
    ExceptionList = &local_14;
    FUN_11007173(*(undefined4 *)(param_1 + 0x18),UNRECOVERED_JUMPTABLE);
  }
  ExceptionList = local_14;
  return;
}


// ---- 1100a08d FUN_1100a08d  (called by: FUN_11009e62@11009e62)

int __cdecl FUN_1100a08d(int param_1,int *param_2)

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


// ---- 1100a0b0 __CallSettingFrame@12  (called by: FUN_11007206@11007206, FUN_11009bee@11009bee)

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


// ---- 1100a0fc FUN_1100a0fc  (called by: FUN_11007bab@11007bab)

undefined4 FUN_1100a0fc(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  FUN_110080a4();
  DAT_11010fe0 = TlsAlloc();
  if (DAT_11010fe0 != 0xffffffff) {
    lpTlsValue = (DWORD *)FUN_1100b495(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_11010fe0,lpTlsValue);
      if (BVar1 != 0) {
        FUN_1100a16e((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        return 1;
      }
    }
  }
  return 0;
}


// ---- 1100a150 FUN_1100a150  (called by: FUN_11007bab@11007bab)

void FUN_1100a150(void)

{
  FUN_110080cd();
  if (DAT_11010fe0 != 0xffffffff) {
    TlsFree(DAT_11010fe0);
    DAT_11010fe0 = 0xffffffff;
  }
  return;
}


// ---- 1100a16e FUN_1100a16e  (called by: FUN_1100a0fc@1100a0fc, FUN_1100a181@1100a181)

void __cdecl FUN_1100a16e(int param_1)

{
  *(undefined **)(param_1 + 0x50) = &DAT_11011180;
  *(undefined4 *)(param_1 + 0x14) = 1;
  return;
}


// ---- 1100a181 FUN_1100a181  (called by: FUN_1100727f@1100727f, FUN_11008fcc@11008fcc, FUN_11008fd5@11008fd5, FUN_11009934@11009934, FUN_11009ae7@11009ae7, FUN_11009d1d@11009d1d, FUN_11009dea@11009dea, FUN_1100a288@1100a288, FUN_1100c52c@1100c52c)

DWORD * FUN_1100a181(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(DAT_11010fe0);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = (DWORD *)FUN_1100b495(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_11010fe0,lpTlsValue);
      if (BVar1 != 0) {
        FUN_1100a16e((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        goto LAB_1100a1dc;
      }
    }
    __amsg_exit(0x10);
  }
LAB_1100a1dc:
  SetLastError(dwErrCode);
  return lpTlsValue;
}


// ---- 1100a1e8 FUN_1100a1e8  (called by: FUN_11007bab@11007bab)

void __cdecl FUN_1100a1e8(LPVOID param_1)

{
  if (DAT_11010fe0 == 0xffffffff) {
    return;
  }
  if ((param_1 != (LPVOID)0x0) || (param_1 = TlsGetValue(DAT_11010fe0), param_1 != (LPVOID)0x0)) {
    if (*(LPVOID *)((int)param_1 + 0x24) != (LPVOID)0x0) {
      FUN_11006b21(*(LPVOID *)((int)param_1 + 0x24));
    }
    if (*(LPVOID *)((int)param_1 + 0x28) != (LPVOID)0x0) {
      FUN_11006b21(*(LPVOID *)((int)param_1 + 0x28));
    }
    if (*(LPVOID *)((int)param_1 + 0x30) != (LPVOID)0x0) {
      FUN_11006b21(*(LPVOID *)((int)param_1 + 0x30));
    }
    if (*(LPVOID *)((int)param_1 + 0x38) != (LPVOID)0x0) {
      FUN_11006b21(*(LPVOID *)((int)param_1 + 0x38));
    }
    if (*(LPVOID *)((int)param_1 + 0x40) != (LPVOID)0x0) {
      FUN_11006b21(*(LPVOID *)((int)param_1 + 0x40));
    }
    if (*(LPVOID *)((int)param_1 + 0x44) != (LPVOID)0x0) {
      FUN_11006b21(*(LPVOID *)((int)param_1 + 0x44));
    }
    if (*(undefined **)((int)param_1 + 0x50) != &DAT_11011180) {
      FUN_11006b21(*(undefined **)((int)param_1 + 0x50));
    }
    FUN_11006b21(param_1);
  }
  TlsSetValue(DAT_11010fe0,(LPVOID)0x0);
  return;
}


// ---- 1100a288 FUN_1100a288  (called by: FUN_11009934@11009934, FUN_1100a2e9@1100a2e9, FUN_1100bbc0@1100bbc0)

void FUN_1100a288(void)

{
  DWORD *pDVar1;
  void *pvStack_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_1100d438;
  pcStack_10 = FUN_1100bd0c;
  pvStack_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_14;
  pDVar1 = FUN_1100a181();
  if (pDVar1[0x18] != 0) {
    local_8 = 1;
    pDVar1 = FUN_1100a181();
    (*(code *)pDVar1[0x18])();
  }
  local_8 = 0xffffffff;
  FUN_1100bde4();
  return;
}


// ---- 1100a2e9 FUN_1100a2e9  (called by: FUN_110073aa@110073aa, FUN_11009899@11009899, FUN_11009934@11009934, FUN_11009bee@11009bee, FUN_11009e62@11009e62)

void FUN_1100a2e9(void)

{
  void *pvStack_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_1100d450;
  pcStack_10 = FUN_1100bd0c;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (PTR_FUN_11010fe4 != (undefined *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*(code *)PTR_FUN_11010fe4)();
  }
  local_8 = 0xffffffff;
  FUN_1100a288();
  return;
}


// ---- 1100a33f FUN_1100a33f  (called by: FUN_11007537@11007537)

SIZE_T __cdecl FUN_1100a33f(LPCVOID param_1)

{
  uint uVar1;
  SIZE_T SVar2;
  
  FUN_11008139(9);
  uVar1 = FUN_110081ed((int)param_1);
  if (uVar1 == 0) {
    FUN_1100819a(9);
    SVar2 = HeapSize(DAT_1101689c,0,param_1);
  }
  else {
    SVar2 = *(int *)((int)param_1 + -4) - 9;
    FUN_1100819a(9);
  }
  return SVar2;
}


// ---- 1100a384 FUN_1100a384  (called by: FUN_1100763e@1100763e)

uint __cdecl FUN_1100a384(undefined4 *param_1)

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
        FUN_1100b884(param_1);
      }
      else {
        *param_1 = param_1[2];
      }
      iVar3 = FUN_1100a460(param_1[4],(char *)param_1[2],(char *)param_1[6]);
      param_1[1] = iVar3;
      if ((iVar3 != 0) && (iVar3 != -1)) {
        if ((param_1[3] & 0x82) == 0) {
          uVar2 = param_1[4];
          if (uVar2 == 0xffffffff) {
            puVar4 = &DAT_11010fb0;
          }
          else {
            puVar4 = (undefined *)((&DAT_11015760)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
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


// ---- 1100a460 FUN_1100a460  (called by: FUN_1100763e@1100763e, FUN_1100a384@1100a384)

int __cdecl FUN_1100a460(uint param_1,char *param_2,char *param_3)

{
  int iVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_11015860) &&
     ((*(byte *)((&DAT_11015760)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_1100b803(param_1);
    iVar1 = FUN_1100a4c5(param_1,param_2,param_3);
    FUN_1100b862(param_1);
    return iVar1;
  }
  pDVar2 = FUN_11008fcc();
  *pDVar2 = 9;
  pDVar2 = FUN_11008fd5();
  *pDVar2 = 0;
  return -1;
}


// ---- 1100a4c5 FUN_1100a4c5  (called by: FUN_1100a460@1100a460, FUN_1100b8f1@1100b8f1)

int __cdecl FUN_1100a4c5(uint param_1,char *param_2,char *param_3)

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
    piVar1 = &DAT_11015760 + ((int)param_1 >> 5);
    iVar9 = (param_1 & 0x1f) * 0x24;
    bVar4 = *(byte *)((&DAT_11015760)[(int)param_1 >> 5] + iVar9 + 4);
    if ((bVar4 & 2) == 0) {
      pcVar8 = param_2;
      if (((bVar4 & 0x48) != 0) &&
         (cVar3 = *(char *)((&DAT_11015760)[(int)param_1 >> 5] + iVar9 + 5), cVar3 != '\n')) {
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
          pDVar7 = FUN_11008fcc();
          *pDVar7 = 9;
          pDVar7 = FUN_11008fd5();
          *pDVar7 = 5;
        }
        else {
          if (DVar6 == 0x6d) {
            return 0;
          }
          FUN_11008f59(DVar6);
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
                  goto LAB_1100a650;
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
LAB_1100a66a:
                  *pcVar8 = '\r';
LAB_1100a66d:
                  pcVar8 = pcVar8 + 1;
                }
                else if ((*(byte *)(*piVar1 + 4 + iVar9) & 0x48) == 0) {
                  if ((pcVar8 == param_2) && (local_5 == '\n')) {
LAB_1100a650:
                    *pcVar8 = '\n';
                    goto LAB_1100a66d;
                  }
                  FUN_11009043(param_1,-1,1);
                  if (local_5 != '\n') goto LAB_1100a66a;
                }
                else {
                  if (local_5 == '\n') goto LAB_1100a650;
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


// ---- 1100a69e FUN_1100a69e  (called by: FUN_11007950@11007950)

byte * __cdecl FUN_1100a69e(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  
  if (param_1 < param_2) {
    if (DAT_1101552c == 0) {
      pbVar1 = param_2 + -1;
    }
    else {
      FUN_11008139(0x19);
      pbVar1 = param_2 + -1;
      if ((*(byte *)((int)&DAT_11015640 + param_2[-1] + 1) & 4) == 0) {
        do {
          pbVar1 = pbVar1 + -1;
          if (pbVar1 < param_1) break;
        } while ((*(byte *)((int)&DAT_11015640 + *pbVar1 + 1) & 4) != 0);
        FUN_1100819a(0x19);
        pbVar1 = param_2 + (-1 - ((int)param_2 - (int)pbVar1 & 1U));
      }
      else {
        FUN_1100819a(0x19);
        pbVar1 = param_2 + -2;
      }
    }
  }
  else {
    pbVar1 = (byte *)0x0;
  }
  return pbVar1;
}


// ---- 1100a70b FUN_1100a70b  (called by: FUN_1100aae3@1100aae3)

undefined4 __cdecl FUN_1100a70b(int param_1)

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
  
  FUN_11008139(0x19);
  CodePage = FUN_1100a8b8(param_1);
  if (CodePage != DAT_11015518) {
    if (CodePage != 0) {
      iVar12 = 0;
      pUVar5 = &DAT_11010ff8;
LAB_1100a748:
      if (*pUVar5 != CodePage) goto code_r0x1100a74c;
      local_8 = 0;
      puVar15 = &DAT_11015640;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      iVar12 = iVar12 * 0x30;
      *(undefined1 *)puVar15 = 0;
      pbVar13 = (byte *)(iVar12 + 0x11011008);
      do {
        bVar3 = *pbVar13;
        pbVar11 = pbVar13;
        while ((bVar3 != 0 && (bVar3 = pbVar11[1], bVar3 != 0))) {
          uVar8 = (uint)*pbVar11;
          if (uVar8 <= bVar3) {
            bVar4 = (&DAT_11010ff0)[local_8];
            do {
              pbVar2 = (byte *)((int)&DAT_11015640 + uVar8 + 1);
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
      DAT_1101552c = 1;
      DAT_11015518 = CodePage;
      DAT_11015744 = FUN_1100a902(CodePage);
      DAT_11015520 = *(undefined4 *)(iVar12 + 0x11010ffc);
      DAT_11015524 = *(undefined4 *)(iVar12 + 0x11011000);
      DAT_11015528 = *(undefined4 *)(iVar12 + 0x11011004);
      goto LAB_1100a89c;
    }
    goto LAB_1100a897;
  }
  goto LAB_1100a732;
code_r0x1100a74c:
  pUVar5 = pUVar5 + 0xc;
  iVar12 = iVar12 + 1;
  if (0x110110e7 < (int)pUVar5) goto code_r0x1100a757;
  goto LAB_1100a748;
code_r0x1100a757:
  BVar6 = GetCPInfo(CodePage,&local_1c);
  uVar8 = 1;
  if (BVar6 == 1) {
    DAT_11015744 = 0;
    puVar15 = &DAT_11015640;
    for (iVar12 = 0x40; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar15 = 0;
      puVar15 = puVar15 + 1;
    }
    *(undefined1 *)puVar15 = 0;
    if (local_1c.MaxCharSize < 2) {
      DAT_1101552c = 0;
      DAT_11015518 = CodePage;
    }
    else {
      DAT_11015518 = CodePage;
      if (local_1c.LeadByte[0] != '\0') {
        pBVar9 = local_1c.LeadByte + 1;
        do {
          bVar3 = *pBVar9;
          if (bVar3 == 0) break;
          for (uVar7 = (uint)pBVar9[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
            pbVar13 = (byte *)((int)&DAT_11015640 + uVar7 + 1);
            *pbVar13 = *pbVar13 | 4;
          }
          pBVar1 = pBVar9 + 1;
          pBVar9 = pBVar9 + 2;
        } while (*pBVar1 != 0);
      }
      do {
        pbVar13 = (byte *)((int)&DAT_11015640 + uVar8 + 1);
        *pbVar13 = *pbVar13 | 8;
        uVar8 = uVar8 + 1;
      } while (uVar8 < 0xff);
      DAT_11015744 = FUN_1100a902(CodePage);
      DAT_1101552c = 1;
    }
    DAT_11015520 = 0;
    DAT_11015524 = 0;
    DAT_11015528 = 0;
  }
  else {
    if (DAT_11015264 == 0) {
      uVar14 = 0xffffffff;
      goto LAB_1100a8a9;
    }
LAB_1100a897:
    FUN_1100a935();
  }
LAB_1100a89c:
  FUN_1100a95e();
LAB_1100a732:
  uVar14 = 0;
LAB_1100a8a9:
  FUN_1100819a(0x19);
  return uVar14;
}


// ---- 1100a8b8 FUN_1100a8b8  (called by: FUN_1100a70b@1100a70b)

int __cdecl FUN_1100a8b8(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_11015264 = 1;
                    /* WARNING: Could not recover jumptable at 0x1100a8d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_11015264 = 1;
                    /* WARNING: Could not recover jumptable at 0x1100a8e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_11015394;
  }
  DAT_11015264 = (uint)bVar2;
  return param_1;
}


// ---- 1100a902 FUN_1100a902  (called by: FUN_1100a70b@1100a70b)

undefined4 __cdecl FUN_1100a902(int param_1)

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


// ---- 1100a935 FUN_1100a935  (called by: FUN_1100a70b@1100a70b)

void FUN_1100a935(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_11015640;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_11015518 = 0;
  DAT_1101552c = 0;
  DAT_11015744 = 0;
  DAT_11015520 = 0;
  DAT_11015524 = 0;
  DAT_11015528 = 0;
  return;
}


// ---- 1100a95e FUN_1100a95e  (called by: FUN_1100a70b@1100a70b)

void FUN_1100a95e(void)

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
  
  BVar2 = GetCPInfo(DAT_11015518,&local_18);
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
    FUN_1100c134(1,local_118,0x100,local_518,DAT_11015518,DAT_11015744,0);
    FUN_1100bee5(DAT_11015744,0x100,local_118,0x100,local_218,0x100,DAT_11015518,0);
    FUN_1100bee5(DAT_11015744,0x200,local_118,0x100,local_318,0x100,DAT_11015518,0);
    uVar3 = 0;
    puVar7 = local_518;
    do {
      if ((*puVar7 & 1) == 0) {
        if ((*puVar7 & 2) != 0) {
          pbVar1 = (byte *)((int)&DAT_11015640 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          uVar8 = *(undefined1 *)((int)local_318 + uVar3);
          goto LAB_1100aa6a;
        }
        (&DAT_11015540)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_11015640 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        uVar8 = *(undefined1 *)((int)local_218 + uVar3);
LAB_1100aa6a:
        (&DAT_11015540)[uVar3] = uVar8;
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
          pbVar1 = (byte *)((int)&DAT_11015640 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          cVar4 = (char)uVar3 + -0x20;
          goto LAB_1100aab4;
        }
        (&DAT_11015540)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_11015640 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        cVar4 = (char)uVar3 + ' ';
LAB_1100aab4:
        (&DAT_11015540)[uVar3] = cVar4;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
  }
  return;
}


// ---- 1100aae3 FUN_1100aae3  (called by: FUN_1100ab99@1100ab99, FUN_1100ac52@1100ac52)

void FUN_1100aae3(void)

{
  if (DAT_110168a4 == 0) {
    FUN_1100a70b(-3);
    DAT_110168a4 = 1;
  }
  return;
}


// ---- 1100aaff FUN_1100aaff  (called by: FUN_110079e1@110079e1)

byte * __cdecl FUN_1100aaff(byte *param_1,byte *param_2,size_t param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  if (DAT_1101552c == 0) {
    param_1 = (byte *)_strncpy((char *)param_1,(char *)param_2,param_3);
  }
  else {
    FUN_11008139(0x19);
    uVar4 = 0;
    pbVar6 = param_1;
    if (param_3 != 0) {
      pbVar5 = param_1;
      do {
        bVar1 = *param_2;
        uVar4 = param_3 - 1;
        bVar2 = *(byte *)((int)&DAT_11015640 + bVar1 + 1);
        *pbVar5 = bVar1;
        if ((bVar2 & 4) == 0) {
          pbVar6 = pbVar5 + 1;
          param_2 = param_2 + 1;
          if (bVar1 == 0) goto LAB_1100ab70;
        }
        else {
          pbVar6 = pbVar5 + 1;
          if (uVar4 == 0) {
            *pbVar5 = 0;
            goto LAB_1100ab70;
          }
          bVar1 = param_2[1];
          uVar4 = param_3 - 2;
          *pbVar6 = bVar1;
          pbVar6 = pbVar5 + 2;
          param_2 = param_2 + 2;
          if (bVar1 == 0) {
            *pbVar5 = 0;
            goto LAB_1100ab70;
          }
        }
        param_3 = uVar4;
        pbVar5 = pbVar6;
      } while (uVar4 != 0);
      uVar4 = 0;
    }
LAB_1100ab70:
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
    FUN_1100819a(0x19);
  }
  return param_1;
}


// ---- 1100ab99 FUN_1100ab99  (called by: FUN_11007bab@11007bab)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1100ab99(void)

{
  char cVar1;
  size_t sVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  uint *puVar6;
  
  if (DAT_110168a4 == 0) {
    FUN_1100aae3();
  }
  iVar5 = 0;
  for (puVar6 = DAT_110151a4; (char)*puVar6 != '\0'; puVar6 = (uint *)((int)puVar6 + sVar2 + 1)) {
    if ((char)*puVar6 != '=') {
      iVar5 = iVar5 + 1;
    }
    sVar2 = _strlen((char *)puVar6);
  }
  puVar3 = _malloc(iVar5 * 4 + 4);
  _DAT_110151d4 = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = (char)*DAT_110151a4;
  puVar6 = DAT_110151a4;
  while (cVar1 != '\0') {
    sVar2 = _strlen((char *)puVar6);
    if ((char)*puVar6 != '=') {
      pvVar4 = _malloc(sVar2 + 1);
      *puVar3 = pvVar4;
      if (pvVar4 == (void *)0x0) {
        __amsg_exit(9);
      }
      FUN_11007860((uint *)*puVar3,puVar6);
      puVar3 = puVar3 + 1;
    }
    puVar6 = (uint *)((int)puVar6 + sVar2 + 1);
    cVar1 = (char)*puVar6;
  }
  FUN_11006b21(DAT_110151a4);
  DAT_110151a4 = (uint *)0x0;
  *puVar3 = 0;
  _DAT_110168a0 = 1;
  return;
}


// ---- 1100ac52 FUN_1100ac52  (called by: FUN_11007bab@11007bab)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1100ac52(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_c;
  int local_8;
  
  if (DAT_110168a4 == 0) {
    FUN_1100aae3();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_11015268,0x104);
  _DAT_110151e4 = &DAT_11015268;
  pbVar2 = &DAT_11015268;
  if (*DAT_110168b4 != 0) {
    pbVar2 = DAT_110168b4;
  }
  FUN_1100aceb(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_c);
  puVar1 = _malloc(local_c + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_1100aceb(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_c);
  _DAT_110151cc = puVar1;
  _DAT_110151c8 = local_8 + -1;
  return;
}


// ---- 1100aceb FUN_1100aceb  (called by: FUN_1100ac52@1100ac52)

void __cdecl FUN_1100aceb(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

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
      if (((*(byte *)((int)&DAT_11015640 + bVar1 + 1) & 4) != 0) &&
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
      if ((*(byte *)((int)&DAT_11015640 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar4;
          param_3 = param_3 + 1;
        }
        pbVar4 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_1100ad96;
      param_1 = pbVar4;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_1100ad96:
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
          if ((*(byte *)((int)&DAT_11015640 + bVar1 + 1) & 4) != 0) {
            pbVar4 = pbVar4 + 1;
            *param_5 = *param_5 + 1;
          }
        }
        else {
          if ((*(byte *)((int)&DAT_11015640 + bVar1 + 1) & 4) != 0) {
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


// ---- 1100ae9f FUN_1100ae9f  (called by: FUN_11007bab@11007bab)

LPSTR FUN_1100ae9f(void)

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
  if (DAT_1101536c == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr != (LPWCH)0x0) {
      DAT_1101536c = 1;
      goto LAB_1100aef6;
    }
    pCVar9 = GetEnvironmentStrings();
    if (pCVar9 == (LPCH)0x0) {
      return (LPSTR)0x0;
    }
    DAT_1101536c = 2;
  }
  else {
    if (DAT_1101536c == 1) {
LAB_1100aef6:
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
          FUN_11006b21(pCVar6);
          local_8 = (LPSTR)0x0;
        }
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return local_8;
    }
    if (DAT_1101536c != 2) {
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
    FUN_11006760((undefined4 *)pCVar6,(undefined4 *)pCVar9,(uint)(pcVar7 + (1 - (int)pCVar9)));
  }
  FreeEnvironmentStringsA(pCVar9);
  return pCVar6;
}


// ---- 1100afd1 FUN_1100afd1  (called by: __amsg_exit@11007d21)

void FUN_1100afd1(void)

{
  if ((DAT_110151ac == 1) || ((DAT_110151ac == 0 && (DAT_110151b0 == 1)))) {
    FUN_1100b00a(0xfc);
    if (DAT_11015370 != (code *)0x0) {
      (*DAT_11015370)();
    }
    FUN_1100b00a(0xff);
  }
  return;
}


// ---- 1100b00a FUN_1100b00a  (called by: FUN_1100afd1@1100afd1, FUN_1100bde4@1100bde4, __amsg_exit@11007d21)

void __cdecl FUN_1100b00a(DWORD param_1)

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
  pDVar2 = &DAT_110110e8;
  do {
    if (param_1 == *pDVar2) break;
    pDVar2 = pDVar2 + 2;
    iVar5 = iVar5 + 1;
  } while ((int)pDVar2 < 0x11011178);
  if (param_1 == (&DAT_110110e8)[iVar5 * 2]) {
    if ((DAT_110151ac == 1) || ((DAT_110151ac == 0 && (DAT_110151b0 == 1)))) {
      pDVar2 = &param_1;
      puVar1 = (undefined4 *)(iVar5 * 8 + 0x110110ec);
      lpOverlapped = (LPOVERLAPPED)0x0;
      sVar4 = _strlen((char *)*puVar1);
      lpBuffer = (LPCVOID)*puVar1;
      hFile = GetStdHandle(0xfffffff4);
      WriteFile(hFile,lpBuffer,sVar4,pDVar2,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_1a8,0x104);
      if (DVar3 == 0) {
        FUN_11007860(local_1a8,(uint *)"<program name unknown>");
      }
      _Dest = local_1a8;
      sVar4 = _strlen((char *)local_1a8);
      if (0x3c < sVar4 + 1) {
        sVar4 = _strlen((char *)local_1a8);
        _Dest = (uint *)(auStackY_1e3 + sVar4);
        _strncpy((char *)_Dest,"...",3);
      }
      FUN_11007860(local_a4,(uint *)"Runtime Error!\n\nProgram: ");
      FUN_11007870(local_a4,_Dest);
      FUN_11007870(local_a4,(uint *)&DAT_1100d790);
      FUN_11007870(local_a4,*(uint **)(iVar5 * 8 + 0x110110ec));
      auStackY_1e3._3_4_ = 0x1100b12e;
      FUN_1100c37e(local_a4,"Microsoft Visual C++ Runtime Library",0x12010);
    }
  }
  return;
}


// ---- 1100b160 FUN_1100b160  (called by: FUN_11008218@11008218, FUN_11009e62@11009e62)

undefined4 * __cdecl FUN_1100b160(undefined4 *param_1,undefined4 *param_2,uint param_3)

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
          goto switchD_1100b317_caseD_2;
        case 3:
          goto switchD_1100b317_caseD_3;
        }
        goto switchD_1100b317_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_1100b317_caseD_0;
      case 1:
        goto switchD_1100b317_caseD_1;
      case 2:
        goto switchD_1100b317_caseD_2;
      case 3:
        goto switchD_1100b317_caseD_3;
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
              goto switchD_1100b317_caseD_2;
            case 3:
              goto switchD_1100b317_caseD_3;
            }
            goto switchD_1100b317_caseD_1;
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
              goto switchD_1100b317_caseD_2;
            case 3:
              goto switchD_1100b317_caseD_3;
            }
            goto switchD_1100b317_caseD_1;
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
              goto switchD_1100b317_caseD_2;
            case 3:
              goto switchD_1100b317_caseD_3;
            }
            goto switchD_1100b317_caseD_1;
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
switchD_1100b317_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_1100b317_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_1100b317_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_1100b317_caseD_0:
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
        goto switchD_1100b195_caseD_2;
      case 3:
        goto switchD_1100b195_caseD_3;
      }
      goto switchD_1100b195_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_1100b195_caseD_0;
    case 1:
      goto switchD_1100b195_caseD_1;
    case 2:
      goto switchD_1100b195_caseD_2;
    case 3:
      goto switchD_1100b195_caseD_3;
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
            goto switchD_1100b195_caseD_2;
          case 3:
            goto switchD_1100b195_caseD_3;
          }
          goto switchD_1100b195_caseD_1;
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
            goto switchD_1100b195_caseD_2;
          case 3:
            goto switchD_1100b195_caseD_3;
          }
          goto switchD_1100b195_caseD_1;
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
            goto switchD_1100b195_caseD_2;
          case 3:
            goto switchD_1100b195_caseD_3;
          }
          goto switchD_1100b195_caseD_1;
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
switchD_1100b195_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_1100b195_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_1100b195_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_1100b195_caseD_0:
  return param_1;
}


// ---- 1100b495 FUN_1100b495  (called by: FUN_1100a0fc@1100a0fc, FUN_1100a181@1100a181)

int * __cdecl FUN_1100b495(int param_1,int param_2)

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
      if (_Size <= DAT_11010bc4) {
        FUN_11008139(9);
        piVar1 = FUN_11008543(_Size);
        FUN_1100819a(9);
        if (piVar1 != (int *)0x0) {
          _memset(piVar1,0,(size_t)_Size);
          return piVar1;
        }
      }
      piVar1 = HeapAlloc(DAT_1101689c,8,(SIZE_T)puVar3);
      if (piVar1 != (int *)0x0) {
        return piVar1;
      }
    }
    if (DAT_110151f8 == 0) {
      return (int *)0x0;
    }
    iVar2 = FUN_11007fd8(puVar3);
  } while (iVar2 != 0);
  return (int *)0x0;
}


// ---- 1100b5a3 FUN_1100b5a3  (called by: FUN_1100b8f1@1100b8f1)

uint FUN_1100b5a3(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  int local_8;
  int local_4;
  
  uVar4 = 0xffffffff;
  FUN_11008139(0x12);
  local_8 = 0;
  local_4 = 0;
  piVar3 = &DAT_11015760;
  while (puVar2 = (undefined4 *)*piVar3, puVar1 = puVar2, puVar2 != (undefined4 *)0x0) {
    for (; puVar2 < puVar1 + 0x120; puVar2 = puVar2 + 9) {
      if ((*(byte *)(puVar2 + 1) & 1) == 0) {
        if (puVar2[2] == 0) {
          FUN_11008139(0x11);
          if (puVar2[2] == 0) {
            InitializeCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
            puVar2[2] = puVar2[2] + 1;
          }
          FUN_1100819a(0x11);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
        if ((*(byte *)(puVar2 + 1) & 1) == 0) {
          *puVar2 = 0xffffffff;
          uVar4 = ((int)puVar2 - *piVar3) / 0x24 + local_4;
          if (uVar4 != 0xffffffff) goto LAB_1100b6b5;
          break;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
      }
      puVar1 = (undefined4 *)*piVar3;
    }
    local_4 = local_4 + 0x20;
    piVar3 = piVar3 + 1;
    local_8 = local_8 + 1;
    if (0x1101585f < (int)piVar3) goto LAB_1100b6b5;
  }
  puVar2 = _malloc(0x480);
  if (puVar2 != (undefined4 *)0x0) {
    DAT_11015860 = DAT_11015860 + 0x20;
    (&DAT_11015760)[local_8] = puVar2;
    puVar1 = puVar2;
    for (; puVar2 < puVar1 + 0x120; puVar2 = puVar2 + 9) {
      *(undefined1 *)(puVar2 + 1) = 0;
      *puVar2 = 0xffffffff;
      puVar2[2] = 0;
      *(undefined1 *)((int)puVar2 + 5) = 10;
      puVar1 = (undefined4 *)(&DAT_11015760)[local_8];
    }
    uVar4 = local_8 << 5;
    FUN_1100b803(uVar4);
  }
LAB_1100b6b5:
  FUN_1100819a(0x12);
  return uVar4;
}


// ---- 1100b6c6 FUN_1100b6c6  (called by: FUN_1100b8f1@1100b8f1)

undefined4 __cdecl FUN_1100b6c6(uint param_1,HANDLE param_2)

{
  DWORD *pDVar1;
  int iVar2;
  DWORD nStdHandle;
  
  if (param_1 < DAT_11015860) {
    iVar2 = (param_1 & 0x1f) * 0x24;
    if (*(int *)((&DAT_11015760)[(int)param_1 >> 5] + iVar2) == -1) {
      if (DAT_110151b0 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_1100b71f;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,param_2);
      }
LAB_1100b71f:
      *(HANDLE *)((&DAT_11015760)[(int)param_1 >> 5] + iVar2) = param_2;
      return 0;
    }
  }
  pDVar1 = FUN_11008fcc();
  *pDVar1 = 9;
  pDVar1 = FUN_11008fd5();
  *pDVar1 = 0;
  return 0xffffffff;
}


// ---- 1100b742 FUN_1100b742  (called by: FUN_11008eab@11008eab)

undefined4 __cdecl FUN_1100b742(uint param_1)

{
  int *piVar1;
  DWORD *pDVar2;
  int iVar3;
  DWORD nStdHandle;
  
  if (param_1 < DAT_11015860) {
    iVar3 = (param_1 & 0x1f) * 0x24;
    piVar1 = (int *)((&DAT_11015760)[(int)param_1 >> 5] + iVar3);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_110151b0 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_1100b79e;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_1100b79e:
      *(undefined4 *)((&DAT_11015760)[(int)param_1 >> 5] + iVar3) = 0xffffffff;
      return 0;
    }
  }
  pDVar2 = FUN_11008fcc();
  *pDVar2 = 9;
  pDVar2 = FUN_11008fd5();
  *pDVar2 = 0;
  return 0xffffffff;
}


// ---- 1100b7c1 FUN_1100b7c1  (called by: FUN_11008eab@11008eab, FUN_11009043@11009043, FUN_110092c6@110092c6, FUN_1100c407@1100c407)

undefined4 __cdecl FUN_1100b7c1(uint param_1)

{
  DWORD *pDVar1;
  
  if ((param_1 < DAT_11015860) &&
     ((*(byte *)((&DAT_11015760)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    return *(undefined4 *)((&DAT_11015760)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24);
  }
  pDVar1 = FUN_11008fcc();
  *pDVar1 = 9;
  pDVar1 = FUN_11008fd5();
  *pDVar1 = 0;
  return 0xffffffff;
}


// ---- 1100b803 FUN_1100b803  (called by: FUN_11008e4e@11008e4e, FUN_11008fde@11008fde, FUN_110092c6@110092c6, FUN_11009359@11009359, FUN_1100a460@1100a460, FUN_1100b5a3@1100b5a3)

void __cdecl FUN_1100b803(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (param_1 & 0x1f) * 0x24;
  iVar1 = (&DAT_11015760)[(int)param_1 >> 5] + iVar2;
  if (*(int *)(iVar1 + 8) == 0) {
    FUN_11008139(0x11);
    if (*(int *)(iVar1 + 8) == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xc));
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    }
    FUN_1100819a(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((&DAT_11015760)[(int)param_1 >> 5] + 0xc + iVar2));
  return;
}


// ---- 1100b862 FUN_1100b862  (called by: FUN_11008e4e@11008e4e, FUN_11008fde@11008fde, FUN_110092c6@110092c6, FUN_11009359@11009359, FUN_1100a460@1100a460, FUN_1100b8f1@1100b8f1)

void __cdecl FUN_1100b862(uint param_1)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_11015760)[(int)param_1 >> 5] + 0xc + (param_1 & 0x1f) * 0x24));
  return;
}


// ---- 1100b884 FUN_1100b884  (called by: FUN_11009549@11009549, FUN_1100a384@1100a384)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1100b884(undefined4 *param_1)

{
  void *pvVar1;
  
  _DAT_11015260 = _DAT_11015260 + 1;
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


// ---- 1100b8c8 FUN_1100b8c8  (called by: FUN_11009549@11009549)

byte __cdecl FUN_1100b8c8(uint param_1)

{
  if (param_1 < DAT_11015860) {
    return *(byte *)((&DAT_11015760)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0x40;
  }
  return 0;
}


// ---- 1100b8f1 FUN_1100b8f1  (called by: FUN_11009661@11009661)

uint __cdecl FUN_1100b8f1(LPCSTR param_1,uint param_2,uint param_3,uint param_4)

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
  if (((param_2 & 0x8000) == 0) && (((param_2 & 0x4000) != 0 || (DAT_110153b0 != 0x8000)))) {
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
    if (uVar2 != 2) goto LAB_1100b9f5;
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
    if (param_3 != 0x40) goto LAB_1100b9f5;
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
      if (uVar2 == 0x200) goto LAB_1100ba0f;
      if (uVar2 != 0x300) goto LAB_1100b9f5;
      local_c = 2;
    }
  }
  else {
    if (uVar2 != 0x500) {
      if (uVar2 == 0x600) {
LAB_1100ba0f:
        local_c = 5;
        goto LAB_1100ba1f;
      }
      if (uVar2 != 0x700) {
LAB_1100b9f5:
        pDVar4 = FUN_11008fcc();
        *pDVar4 = 0x16;
        pDVar4 = FUN_11008fd5();
        *pDVar4 = 0;
        return 0xffffffff;
      }
    }
    local_c = 1;
  }
LAB_1100ba1f:
  uVar2 = 0x80;
  if (((param_2 & 0x100) != 0) && ((~DAT_110151b4 & param_4 & 0x80) == 0)) {
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
  uVar3 = FUN_1100b5a3();
  if (uVar3 == 0xffffffff) {
    pDVar4 = FUN_11008fcc();
    *pDVar4 = 0x18;
    pDVar4 = FUN_11008fd5();
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
      FUN_1100b6c6(uVar3,hFile);
      iVar7 = (uVar3 & 0x1f) * 0x24;
      param_1._3_1_ = local_5 & 0x48;
      *(byte *)((&DAT_11015760)[(int)uVar3 >> 5] + 4 + iVar7) = local_5 | 1;
      if ((((local_5 & 0x48) == 0) && ((local_5 & 0x80) != 0)) && ((param_2 & 2) != 0)) {
        local_14 = FUN_11009043(uVar3,-1,2);
        if (local_14 == 0xffffffff) {
          pDVar4 = FUN_11008fd5();
          if (*pDVar4 == 0x83) goto LAB_1100bb99;
        }
        else {
          param_3 = param_3 & 0xffffff;
          iVar6 = FUN_1100a4c5(uVar3,(char *)((int)&param_3 + 3),(char *)0x1);
          if ((((iVar6 != 0) || (param_3._3_1_ != '\x1a')) ||
              (iVar6 = FUN_1100c407(uVar3,local_14), iVar6 != -1)) &&
             (DVar5 = FUN_11009043(uVar3,0,0), DVar5 != 0xffffffff)) goto LAB_1100bb99;
        }
        FUN_11008e4e(uVar3);
        uVar2 = 0xffffffff;
      }
      else {
LAB_1100bb99:
        if ((param_1._3_1_ == 0) && ((param_2 & 8) != 0)) {
          pbVar1 = (byte *)((&DAT_11015760)[(int)uVar3 >> 5] + 4 + iVar7);
          *pbVar1 = *pbVar1 | 0x20;
        }
        uVar2 = uVar3;
      }
      goto LAB_1100bbb2;
    }
    CloseHandle(hFile);
  }
  DVar5 = GetLastError();
  FUN_11008f59(DVar5);
  uVar2 = 0xffffffff;
LAB_1100bbb2:
  FUN_1100b862(uVar3);
  return uVar2;
}


// ---- 1100bbc0 FUN_1100bbc0  (called by: -)

int FUN_1100bbc0(int *param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    iVar3 = FUN_1100a288();
    return iVar3;
  }
  if ((DAT_11015378 == (FARPROC)0x0) ||
     (bVar2 = FUN_1100bc5c(DAT_11015378), CONCAT31(extraout_var,bVar2) == 0)) {
    return 0;
  }
  iVar3 = (*DAT_11015378)(param_1);
  return iVar3;
}


// ---- 1100bc24 FUN_1100bc24  (called by: FUN_11009934@11009934, FUN_11009e62@11009e62)

bool __cdecl FUN_1100bc24(void *param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadReadPtr(param_1,param_2);
  return BVar1 == 0;
}


// ---- 1100bc40 FUN_1100bc40  (called by: FUN_11009e62@11009e62)

bool __cdecl FUN_1100bc40(LPVOID param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadWritePtr(param_1,param_2);
  return BVar1 == 0;
}


// ---- 1100bc5c FUN_1100bc5c  (called by: FUN_11009e62@11009e62, FUN_1100bbc0@1100bbc0)

bool __cdecl FUN_1100bc5c(FARPROC param_1)

{
  BOOL BVar1;
  
  BVar1 = IsBadCodePtr(param_1);
  return BVar1 == 0;
}


// ---- 1100bc80 _strcmp  (called by: FUN_11009b91@11009b91)

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
      if (bVar3 != *_Str2) goto LAB_1100bcc4;
      _Str2 = _Str2 + 1;
      if (bVar3 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_1100bc90;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar3 = (byte)uVar1;
    bVar4 = bVar3 < (byte)*_Str2;
    if (bVar3 != *_Str2) goto LAB_1100bcc4;
    if (bVar3 == 0) {
      return 0;
    }
    bVar3 = (byte)((ushort)uVar1 >> 8);
    bVar4 = bVar3 < (byte)_Str2[1];
    if (bVar3 != _Str2[1]) goto LAB_1100bcc4;
    if (bVar3 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_1100bc90:
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
LAB_1100bcc4:
  return (uint)bVar4 * -2 + 1;
}


// ---- 1100bd0c FUN_1100bd0c  (called by: -)

undefined4 FUN_1100bd0c(int param_1,PVOID param_2,undefined4 param_3)

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
          FUN_110074fe();
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


// ---- 1100bdc9 FUN_1100bdc9  (called by: -)

void FUN_1100bdc9(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}


// ---- 1100bde4 FUN_1100bde4  (called by: FUN_1100a288@1100a288)

void FUN_1100bde4(void)

{
  FUN_1100b00a(10);
  FUN_1100c52c((DWORD *)0x16);
                    /* WARNING: Subroutine does not return */
  __exit(3);
}


// ---- 1100bee5 FUN_1100bee5  (called by: FUN_1100a95e@1100a95e, FUN_1100ca26@1100ca26)

int __cdecl
FUN_1100bee5(LCID param_1,DWORD param_2,char *param_3,int param_4,LPWSTR param_5,int param_6,
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
  puStack_c = &DAT_1100d7d8;
  pcStack_10 = FUN_1100bd0c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_1101539c == 0) {
    ExceptionList = &local_14;
    iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_1101539c = 2;
    }
    else {
      DAT_1101539c = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_1100c109(param_3,param_4);
  }
  if (DAT_1101539c == 2) {
    iVar1 = LCMapStringA(param_1,param_2,param_3,param_4,(LPSTR)param_5,param_6);
    ExceptionList = local_14;
    return iVar1;
  }
  if (DAT_1101539c == 1) {
    if (param_7 == 0) {
      param_7 = DAT_11015394;
    }
    iVar1 = MultiByteToWideChar(param_7,(-(uint)(param_8 != 0) & 8) + 1,param_3,param_4,(LPWSTR)0x0,
                                0);
    if (iVar1 == 0) {
      ExceptionList = local_14;
      return 0;
    }
    local_8 = 0;
    FUN_11007110(unaff_DI);
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
      FUN_11007110(unaff_DI);
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


// ---- 1100c109 FUN_1100c109  (called by: FUN_1100bee5@1100bee5)

int __cdecl FUN_1100c109(char *param_1,int param_2)

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


// ---- 1100c134 FUN_1100c134  (called by: FUN_1100a95e@1100a95e, FUN_1100c9b1@1100c9b1)

BOOL __cdecl
FUN_1100c134(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6,
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
  puStack_c = &DAT_1100d7f0;
  pcStack_10 = FUN_1100bd0c;
  local_14 = ExceptionList;
  local_1c = (undefined1 *)(aWStack_2a + -7);
  ExceptionList = &local_14;
  pWVar1 = aWStack_2a + -7;
  if (DAT_110153a0 == 0) {
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
    DAT_110153a0 = iVar3;
    pWVar1 = (WCHAR *)local_1c;
  }
  local_1c = (undefined1 *)pWVar1;
  if (DAT_110153a0 == 2) {
    if (param_6 == 0) {
      param_6 = DAT_11015384;
    }
    BVar2 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
    ExceptionList = local_14;
    return BVar2;
  }
  if (DAT_110153a0 == 1) {
    if (param_5 == 0) {
      param_5 = DAT_11015394;
    }
    iVar3 = MultiByteToWideChar(param_5,(-(uint)(param_7 != 0) & 8) + 1,param_2,param_3,(LPWSTR)0x0,
                                0);
    if (iVar3 != 0) {
      local_8 = 0;
      FUN_11007110(unaff_DI);
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


// ---- 1100c280 _strncpy  (called by: FUN_1100aaff@1100aaff, FUN_1100b00a@1100b00a)

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
        goto joined_r0x1100c2be;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_1100c2fb;
        goto LAB_1100c369;
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
joined_r0x1100c365:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_1100c369:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_1100c2fb;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x1100c365;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x1100c365;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x1100c365;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x1100c2be:
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
LAB_1100c2fb:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}


// ---- 1100c37e FUN_1100c37e  (called by: FUN_1100b00a@1100b00a)

int __cdecl FUN_1100c37e(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_110153a4 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_110153a4 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_110153a4 != (FARPROC)0x0) {
        DAT_110153a8 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_110153ac = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_1100c3cd;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_1100c3cd:
    if (DAT_110153a8 != (FARPROC)0x0) {
      iVar1 = (*DAT_110153a8)();
      if ((iVar1 != 0) && (DAT_110153ac != (FARPROC)0x0)) {
        iVar1 = (*DAT_110153ac)(iVar1);
      }
    }
    iVar1 = (*DAT_110153a4)(iVar1,param_1,param_2,param_3);
  }
  return iVar1;
}


// ---- 1100c407 FUN_1100c407  (called by: FUN_1100b8f1@1100b8f1)

int __cdecl FUN_1100c407(uint param_1,int param_2)

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
  
  FUN_11007110(unaff_BP);
  iVar8 = 0;
  DVar1 = FUN_11009043(param_1,0,1);
  if ((DVar1 == 0xffffffff) || (DVar2 = FUN_11009043(param_1,0,2), DVar2 == 0xffffffff)) {
    iVar8 = -1;
  }
  else {
    DVar2 = param_2 - DVar2;
    if ((int)DVar2 < 1) {
      if ((int)DVar2 < 0) {
        FUN_11009043(param_1,param_2,0);
        hFile = (HANDLE)FUN_1100b7c1(param_1);
        BVar7 = SetEndOfFile(hFile);
        iVar8 = (BVar7 != 0) - 1;
        if (iVar8 == -1) {
          pDVar6 = FUN_11008fcc();
          *pDVar6 = 0xd;
          DVar2 = GetLastError();
          pDVar6 = FUN_11008fd5();
          *pDVar6 = DVar2;
        }
      }
    }
    else {
      _memset(local_1008,0,0x1000);
      uStackY_28 = 0x1100c474;
      iVar3 = FUN_1100c6f4(param_1,0x8000);
      do {
        DVar4 = 0x1000;
        if ((int)DVar2 < 0x1000) {
          DVar4 = DVar2;
        }
        iVar5 = FUN_110093be(param_1,local_1008,DVar4);
        if (iVar5 == -1) {
          pDVar6 = FUN_11008fd5();
          if (*pDVar6 == 5) {
            pDVar6 = FUN_11008fcc();
            *pDVar6 = 0xd;
          }
          iVar8 = -1;
          break;
        }
        DVar2 = DVar2 - iVar5;
      } while (0 < (int)DVar2);
      FUN_1100c6f4(param_1,iVar3);
    }
    FUN_11009043(param_1,DVar1,0);
  }
  return iVar8;
}


// ---- 1100c52c FUN_1100c52c  (called by: FUN_1100bde4@1100bde4)

undefined4 __cdecl FUN_1100c52c(DWORD *param_1)

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
    puVar7 = &DAT_110153b4;
    pcVar6 = DAT_110153b4;
LAB_1100c5b2:
    bVar1 = true;
    FUN_11008139(1);
    pDVar2 = param_1;
  }
  else {
    if (((param_1 != (DWORD *)0x4) && (param_1 != (DWORD *)0x8)) && (param_1 != (DWORD *)0xb)) {
      if (param_1 == (DWORD *)0xf) {
        puVar7 = &DAT_110153c0;
        pcVar6 = DAT_110153c0;
      }
      else if (param_1 == (DWORD *)0x15) {
        puVar7 = &DAT_110153b8;
        pcVar6 = DAT_110153b8;
      }
      else {
        if (param_1 != (DWORD *)0x16) {
          return 0xffffffff;
        }
        puVar7 = &DAT_110153bc;
        pcVar6 = DAT_110153bc;
      }
      goto LAB_1100c5b2;
    }
    pDVar2 = FUN_1100a181();
    uVar3 = FUN_1100c6ae((int)param_1,pDVar2[0x14]);
    puVar7 = (undefined4 *)(uVar3 + 8);
    pcVar6 = (code *)*puVar7;
  }
  if (pcVar6 == (code *)0x1) {
    if (bVar1) {
      FUN_1100819a(1);
      return 0;
    }
    return 0;
  }
  if (pcVar6 == (code *)0x0) {
    if (bVar1) {
      FUN_1100819a(1);
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
      goto LAB_1100c626;
    }
  }
  else {
LAB_1100c626:
    if (param_1 == (DWORD *)0x8) {
      if (DAT_110111f8 < DAT_110111fc + DAT_110111f8) {
        iVar4 = DAT_110111f8 * 0xc;
        iVar5 = DAT_110111f8;
        do {
          iVar4 = iVar4 + 0xc;
          *(undefined4 *)((pDVar2[0x14] - 4) + iVar4) = 0;
          iVar5 = iVar5 + 1;
        } while (iVar5 < DAT_110111fc + DAT_110111f8);
      }
      goto LAB_1100c664;
    }
  }
  *puVar7 = 0;
LAB_1100c664:
  if (bVar1) {
    FUN_1100819a(1);
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


// ---- 1100c6ae FUN_1100c6ae  (called by: FUN_1100c52c@1100c52c)

uint __cdecl FUN_1100c6ae(int param_1,uint param_2)

{
  int *piVar1;
  uint uVar3;
  uint uVar2;
  
  uVar2 = param_2;
  if (*(int *)(param_2 + 4) != param_1) {
    uVar3 = param_2;
    do {
      uVar2 = uVar3 + 0xc;
      if (param_2 + DAT_11011204 * 0xc <= uVar2) break;
      piVar1 = (int *)(uVar3 + 0x10);
      uVar3 = uVar2;
    } while (*piVar1 != param_1);
  }
  if ((param_2 + DAT_11011204 * 0xc <= uVar2) || (*(int *)(uVar2 + 4) != param_1)) {
    uVar2 = 0;
  }
  return uVar2;
}


// ---- 1100c6f4 FUN_1100c6f4  (called by: FUN_1100c407@1100c407)

int __cdecl FUN_1100c6f4(uint param_1,int param_2)

{
  byte bVar1;
  DWORD *pDVar2;
  byte bVar3;
  
  bVar1 = *(byte *)((&DAT_11015760)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
  if (param_2 == 0x8000) {
    bVar3 = bVar1 & 0x7f;
  }
  else {
    if (param_2 != 0x4000) {
      pDVar2 = FUN_11008fcc();
      *pDVar2 = 0x16;
      return -1;
    }
    bVar3 = bVar1 | 0x80;
  }
  *(byte *)((&DAT_11015760)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = bVar3;
  return (-(uint)((bVar1 & 0x80) != 0) & 0xffffc000) + 0x8000;
}


// ---- 1100c760 FUN_1100c760  (called by: -)

int __cdecl FUN_1100c760(byte *param_1,byte *param_2)

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


// ---- 1100c7a0 FUN_1100c7a0  (called by: -)

byte * __cdecl FUN_1100c7a0(byte *param_1,byte *param_2)

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


// ---- 1100c7e0 FUN_1100c7e0  (called by: -)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_1100c7e0(void *this,byte *param_1,byte *param_2)

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
  
  iVar2 = _DAT_11015514;
  if (DAT_11015384 == 0) {
    bVar5 = 0xff;
    do {
      do {
        cVar6 = '\0';
        if (bVar5 == 0) goto LAB_1100c82e;
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
LAB_1100c82e:
    uVar7 = (uint)cVar6;
  }
  else {
    LOCK();
    _DAT_11015514 = _DAT_11015514 + 1;
    UNLOCK();
    bVar1 = 0 < DAT_11015510;
    if (bVar1) {
      LOCK();
      UNLOCK();
      _DAT_11015514 = iVar2;
      FUN_11008139(0x13);
      this = extraout_ECX;
    }
    uVar9 = (uint)bVar1;
    uVar7 = 0xff;
    uVar8 = 0;
    do {
      do {
        if ((char)uVar7 == '\0') goto LAB_1100c88f;
        bVar5 = *param_2;
        uVar7 = CONCAT31((int3)(uVar7 >> 8),bVar5);
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        uVar8 = CONCAT31((int3)(uVar8 >> 8),bVar4);
        param_1 = param_1 + 1;
      } while (bVar5 == bVar4);
      uVar8 = FUN_1100ca26(this,uVar8);
      uVar7 = FUN_1100ca26(this_00,uVar7);
      this = extraout_ECX_00;
    } while ((byte)uVar8 == (byte)uVar7);
    uVar8 = (uint)((byte)uVar8 < (byte)uVar7);
    uVar7 = (1 - uVar8) - (uint)(uVar8 != 0);
LAB_1100c88f:
    if (uVar9 == 0) {
      LOCK();
      _DAT_11015514 = _DAT_11015514 + -1;
      UNLOCK();
    }
    else {
      FUN_1100819a(0x13);
    }
  }
  return uVar7;
}


// ---- 1100c8b0 FUN_1100c8b0  (called by: -)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1100c8b0(byte *param_1,char *param_2,void *param_3)

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
  
  iVar2 = _DAT_11015514;
  uVar6 = 0;
  if (param_3 != (void *)0x0) {
    if (DAT_11015384 == 0) {
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
        if (bVar3 != (byte)uVar4) goto LAB_1100c90f;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar6 = 0;
      bVar3 = (byte)(uVar4 >> 8);
      bVar8 = bVar3 < (byte)uVar4;
      if (bVar3 != (byte)uVar4) {
LAB_1100c90f:
        uVar6 = 0xffffffff;
        if (!bVar8) {
          uVar6 = 1;
        }
      }
    }
    else {
      LOCK();
      _DAT_11015514 = _DAT_11015514 + 1;
      UNLOCK();
      bVar8 = 0 < DAT_11015510;
      if (bVar8) {
        LOCK();
        UNLOCK();
        _DAT_11015514 = iVar2;
        FUN_11008139(0x13);
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
        uVar7 = FUN_1100ca26(param_3,uVar7);
        uVar5 = FUN_1100ca26(this,uVar5);
        bVar8 = uVar5 < uVar7;
        if (uVar5 != uVar7) goto LAB_1100c985;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar6 = 0;
      bVar8 = uVar5 < uVar7;
      if (uVar5 != uVar7) {
LAB_1100c985:
        uVar6 = 0xffffffff;
        if (!bVar8) {
          uVar6 = 1;
        }
      }
      if (uVar9 == 0) {
        LOCK();
        _DAT_11015514 = _DAT_11015514 + -1;
        UNLOCK();
      }
      else {
        FUN_1100819a(0x13);
      }
    }
  }
  return uVar6;
}


// ---- 1100c9b1 FUN_1100c9b1  (called by: FUN_1100ca26@1100ca26)

uint __thiscall FUN_1100c9b1(void *this,int param_1,uint param_2)

{
  BOOL BVar1;
  int iVar2;
  undefined4 local_8;
  
  if (param_1 + 1U < 0x101) {
    param_1._2_2_ = *(ushort *)(PTR_DAT_11011220 + param_1 * 2);
  }
  else {
    if ((PTR_DAT_11011220[(param_1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      local_8 = CONCAT31((int3)((uint)this >> 8),(char)param_1) & 0xffff00ff;
      iVar2 = 1;
    }
    else {
      local_8._0_2_ = CONCAT11((char)param_1,(char)((uint)param_1 >> 8));
      local_8 = CONCAT22((short)((uint)this >> 0x10),(undefined2)local_8) & 0xff00ffff;
      iVar2 = 2;
    }
    BVar1 = FUN_1100c134(1,(LPCSTR)&local_8,iVar2,(LPWORD)((int)&param_1 + 2),0,0,1);
    if (BVar1 == 0) {
      return 0;
    }
  }
  return param_1._2_2_ & param_2;
}


// ---- 1100ca26 FUN_1100ca26  (called by: FUN_1100c7e0@1100c7e0, FUN_1100c8b0@1100c8b0)

uint __thiscall FUN_1100ca26(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  void *local_8;
  
  uVar1 = param_1;
  if (DAT_11015384 == 0) {
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
    if (DAT_1101153c < 2) {
      uVar2 = (byte)PTR_DAT_11011220[param_1 * 2] & 1;
    }
    else {
      uVar2 = FUN_1100c9b1(this,param_1,1);
    }
    if (uVar2 == 0) {
      return uVar1;
    }
  }
  if ((PTR_DAT_11011220[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
    param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;
  }
  else {
    uVar2 = param_1 >> 0x10;
    param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));
    param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;
    iVar3 = 2;
  }
  iVar3 = FUN_1100bee5(DAT_11015384,0x100,(char *)&param_1,iVar3,(LPWSTR)&local_8,3,0,1);
  if (iVar3 == 0) {
    return uVar1;
  }
  if (iVar3 == 1) {
    return (uint)local_8 & 0xff;
  }
  return (uint)local_8 & 0xffff;
}


// ---- 1100cc10 __putw  (called by: FUN_110011e9@110011e9)

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
      FUN_11009549((int)(char)*piVar4,(int *)pFVar2);
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


// ---- 1100cc60 Unwind@1100cc60  (called by: -)

void Unwind_1100cc60(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cc63. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + 8));
  return;
}


// ---- 1100cc69 FUN_1100cc69  (called by: -)

void FUN_1100cc69(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110071d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100cc74 Unwind@1100cc74  (called by: -)

void Unwind_1100cc74(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cc77. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + 8));
  return;
}


// ---- 1100cc7d FUN_1100cc7d  (called by: -)

void FUN_1100cc7d(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110071d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100cc88 Unwind@1100cc88  (called by: -)

void Unwind_1100cc88(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cc8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x10) + 0x58));
  return;
}


// ---- 1100cc94 Unwind@1100cc94  (called by: -)

void Unwind_1100cc94(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cc9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x10) + 0x5c));
  return;
}


// ---- 1100cca0 Unwind@1100cca0  (called by: -)

void Unwind_1100cca0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cca6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x10) + 0x60));
  return;
}


// ---- 1100ccac Unwind@1100ccac  (called by: -)

void Unwind_1100ccac(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ccb2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 100));
  return;
}


// ---- 1100ccb8 Unwind@1100ccb8  (called by: -)

void Unwind_1100ccb8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ccbe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 0x68));
  return;
}


// ---- 1100ccc4 Unwind@1100ccc4  (called by: -)

void Unwind_1100ccc4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ccca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 0x6c));
  return;
}


// ---- 1100ccd0 Unwind@1100ccd0  (called by: -)

void Unwind_1100ccd0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ccd6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 0x70));
  return;
}


// ---- 1100ccdc Unwind@1100ccdc  (called by: -)

void Unwind_1100ccdc(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cce2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x74));
  return;
}


// ---- 1100cce8 Unwind@1100cce8  (called by: -)

void Unwind_1100cce8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ccee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x78));
  return;
}


// ---- 1100ccf4 Unwind@1100ccf4  (called by: -)

void Unwind_1100ccf4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ccfa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x7c));
  return;
}


// ---- 1100cd00 Unwind@1100cd00  (called by: -)

void Unwind_1100cd00(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cd09. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x80));
  return;
}


// ---- 1100cd0f Unwind@1100cd0f  (called by: -)

void Unwind_1100cd0f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cd18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x84));
  return;
}


// ---- 1100cd1e Unwind@1100cd1e  (called by: -)

void Unwind_1100cd1e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cd27. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x88));
  return;
}


// ---- 1100cd2d FUN_1100cd2d  (called by: -)

void FUN_1100cd2d(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110071d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100cd38 Unwind@1100cd38  (called by: -)

void Unwind_1100cd38(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cd3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x10) + 0x58));
  return;
}


// ---- 1100cd44 Unwind@1100cd44  (called by: -)

void Unwind_1100cd44(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cd4a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x10) + 0x5c));
  return;
}


// ---- 1100cd50 Unwind@1100cd50  (called by: -)

void Unwind_1100cd50(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cd56. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x10) + 0x60));
  return;
}


// ---- 1100cd5c Unwind@1100cd5c  (called by: -)

void Unwind_1100cd5c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cd62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 100));
  return;
}


// ---- 1100cd68 Unwind@1100cd68  (called by: -)

void Unwind_1100cd68(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cd6e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 0x68));
  return;
}


// ---- 1100cd74 Unwind@1100cd74  (called by: -)

void Unwind_1100cd74(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cd7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 0x6c));
  return;
}


// ---- 1100cd80 Unwind@1100cd80  (called by: -)

void Unwind_1100cd80(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cd86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 0x70));
  return;
}


// ---- 1100cd8c Unwind@1100cd8c  (called by: -)

void Unwind_1100cd8c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cd92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x74));
  return;
}


// ---- 1100cd98 Unwind@1100cd98  (called by: -)

void Unwind_1100cd98(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cd9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x78));
  return;
}


// ---- 1100cda4 Unwind@1100cda4  (called by: -)

void Unwind_1100cda4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cdaa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x7c));
  return;
}


// ---- 1100cdb0 Unwind@1100cdb0  (called by: -)

void Unwind_1100cdb0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cdb9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x80));
  return;
}


// ---- 1100cdbf Unwind@1100cdbf  (called by: -)

void Unwind_1100cdbf(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cdc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x84));
  return;
}


// ---- 1100cdce Unwind@1100cdce  (called by: -)

void Unwind_1100cdce(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cdd7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x88));
  return;
}


// ---- 1100cddd FUN_1100cddd  (called by: -)

void FUN_1100cddd(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110071d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100cde8 Unwind@1100cde8  (called by: -)

void Unwind_1100cde8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cdeb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(unaff_EBP + -0x28));
  return;
}


// ---- 1100cdf1 Unwind@1100cdf1  (called by: -)

void Unwind_1100cdf1(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cdf4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(unaff_EBP + -0x28));
  return;
}


// ---- 1100cdfa Unwind@1100cdfa  (called by: -)

void Unwind_1100cdfa(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cdfd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(unaff_EBP + -0x28));
  return;
}


// ---- 1100ce03 Unwind@1100ce03  (called by: -)

void Unwind_1100ce03(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ce06. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + -0x28));
  return;
}


// ---- 1100ce0c Unwind@1100ce0c  (called by: -)

void Unwind_1100ce0c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ce0f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + -0x28));
  return;
}


// ---- 1100ce15 Unwind@1100ce15  (called by: -)

void Unwind_1100ce15(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ce18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x28));
  return;
}


// ---- 1100ce1e Unwind@1100ce1e  (called by: -)

void Unwind_1100ce1e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ce21. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x28));
  return;
}


// ---- 1100ce27 Unwind@1100ce27  (called by: -)

void Unwind_1100ce27(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ce2a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + -0x28));
  return;
}


// ---- 1100ce30 Unwind@1100ce30  (called by: -)

void Unwind_1100ce30(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ce33. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + -0x28));
  return;
}


// ---- 1100ce39 Unwind@1100ce39  (called by: -)

void Unwind_1100ce39(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ce3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x28));
  return;
}


// ---- 1100ce42 Unwind@1100ce42  (called by: -)

void Unwind_1100ce42(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ce45. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x28));
  return;
}


// ---- 1100ce4b Unwind@1100ce4b  (called by: -)

void Unwind_1100ce4b(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ce4e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x28));
  return;
}


// ---- 1100ce54 Unwind@1100ce54  (called by: -)

void Unwind_1100ce54(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ce57. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x18));
  return;
}


// ---- 1100ce5d FUN_1100ce5d  (called by: -)

void FUN_1100ce5d(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110071d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100ce68 Unwind@1100ce68  (called by: -)

void Unwind_1100ce68(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ce6b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100ce71 FUN_1100ce71  (called by: -)

void FUN_1100ce71(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110071d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100ce7c Unwind@1100ce7c  (called by: -)

void Unwind_1100ce7c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ce7f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100ce85 FUN_1100ce85  (called by: -)

void FUN_1100ce85(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110071d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100ce90 Unwind@1100ce90  (called by: -)

void Unwind_1100ce90(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ce93. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x14));
  return;
}


// ---- 1100ce99 Unwind@1100ce99  (called by: -)

void Unwind_1100ce99(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ce9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x54));
  return;
}


// ---- 1100cea2 Unwind@1100cea2  (called by: -)

void Unwind_1100cea2(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cea5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x4c));
  return;
}


// ---- 1100ceab Unwind@1100ceab  (called by: -)

void Unwind_1100ceab(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ceae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100ceb4 Unwind@1100ceb4  (called by: -)

void Unwind_1100ceb4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ceb7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100cebd Unwind@1100cebd  (called by: -)

void Unwind_1100cebd(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cec0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100cec6 Unwind@1100cec6  (called by: -)

void Unwind_1100cec6(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cec9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100cecf Unwind@1100cecf  (called by: -)

void Unwind_1100cecf(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ced2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100ced8 Unwind@1100ced8  (called by: -)

void Unwind_1100ced8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cedb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100cee1 Unwind@1100cee1  (called by: -)

void Unwind_1100cee1(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cee4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100ceea Unwind@1100ceea  (called by: -)

void Unwind_1100ceea(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ceed. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100cef3 Unwind@1100cef3  (called by: -)

void Unwind_1100cef3(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cef6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100cefc Unwind@1100cefc  (called by: -)

void Unwind_1100cefc(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ceff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100cf05 Unwind@1100cf05  (called by: -)

void Unwind_1100cf05(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cf08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100cf0e Unwind@1100cf0e  (called by: -)

void Unwind_1100cf0e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cf11. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x48));
  return;
}


// ---- 1100cf17 Unwind@1100cf17  (called by: -)

void Unwind_1100cf17(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cf1a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x58));
  return;
}


// ---- 1100cf20 Unwind@1100cf20  (called by: -)

void Unwind_1100cf20(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cf23. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x18));
  return;
}


// ---- 1100cf29 Unwind@1100cf29  (called by: -)

void Unwind_1100cf29(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cf2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x18));
  return;
}


// ---- 1100cf32 FUN_1100cf32  (called by: -)

void FUN_1100cf32(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110071d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100cf3c Unwind@1100cf3c  (called by: -)

void Unwind_1100cf3c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cf3f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100cf45 Unwind@1100cf45  (called by: -)

void Unwind_1100cf45(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cf48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x14));
  return;
}


// ---- 1100cf4e Unwind@1100cf4e  (called by: -)

void Unwind_1100cf4e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cf51. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x14));
  return;
}


// ---- 1100cf57 FUN_1100cf57  (called by: -)

void FUN_1100cf57(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110071d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100cf64 Unwind@1100cf64  (called by: -)

void Unwind_1100cf64(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cf67. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100cf6d Unwind@1100cf6d  (called by: -)

void Unwind_1100cf6d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cf70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x14));
  return;
}


// ---- 1100cf76 FUN_1100cf76  (called by: -)

void FUN_1100cf76(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110071d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100cf80 Unwind@1100cf80  (called by: -)

void Unwind_1100cf80(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cf83. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100cf89 FUN_1100cf89  (called by: -)

void FUN_1100cf89(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110071d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100cf94 Unwind@1100cf94  (called by: -)

void Unwind_1100cf94(void)

{
  int unaff_EBP;
  
  FUN_110075f6(*(LPVOID *)(unaff_EBP + -0x20));
  return;
}


// ---- 1100cf9e FUN_1100cf9e  (called by: -)

void FUN_1100cf9e(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110071d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100cfb0 FUN_1100cfb0  (called by: -)

void FUN_1100cfb0(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110071d0(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100cfc0 Unwind@1100cfc0  (called by: -)

void Unwind_1100cfc0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100cfc3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScGroup::~ScGroup((ScGroup *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100cfc9 FUN_1100cfc9  (called by: -)

void FUN_1100cfc9(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_110071d0(param_1,param_2,param_3,param_4);
  return;
}


