// ---- 11001000 FUN_11001000  (called by: FUN_11001050@11001050, FUN_1100106e@1100106e)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_11001000(uint param_1,undefined4 param_2)

{
  if (param_1 < 0x16) {
    **(undefined4 **)(&DAT_110143b4 + param_1 * 4) = param_2;
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
    return **(undefined4 **)(&DAT_110143b4 + param_1 * 4);
  }
  return 0xffffffff;
}


// ---- 11001050 FUN_11001050  (called by: FUN_11005f4d@11005f4d)

int FUN_11001050(void)

{
  int iVar1;
  
  iVar1 = FUN_11001039(0xe);
  if (iVar1 != 0) {
    FUN_11001000(0xe,1);
  }
  return iVar1;
}


// ---- 1100106e FUN_1100106e  (called by: FUN_11005f4d@11005f4d)

void FUN_1100106e(void)

{
  FUN_11001000(0xe,0);
  return;
}


// ---- 1100107a FUN_1100107a  (called by: FUN_11001121@11001121)

undefined4 * __thiscall
FUN_1100107a(void *this,char param_1,char param_2,ScStub *param_3,undefined1 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  FUN_11006eb0(this,param_1,param_2,param_6);
  *(undefined ***)this = &PTR_FUN_110103f8;
  iVar1 = ScStub::Id(param_3);
  *(char *)((int)this + 0x11) = (char)iVar1;
  *(undefined1 *)((int)this + 0x10) = param_4;
  *(undefined4 *)((int)this + 0x14) = param_5;
  *(undefined4 *)((int)this + 8) = param_7;
  return this;
}


// ---- 110010b9 FUN_110010b9  (called by: -)

void FUN_110010b9(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_110089b4();
  ScGroup::ScGroup((ScGroup *)(unaff_EBP + -0x10));
  cVar1 = *(char *)(extraout_ECX + 0x11);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  ScStub::SetId((ScStub *)(unaff_EBP + -0x10),(int)cVar1);
  iVar3 = ScGroup::TotalUnitCount((ScGroup *)(unaff_EBP + -0x10));
  bVar2 = FUN_11007190(iVar3,(uint)*(byte *)(extraout_ECX + 0x10),
                       *(undefined4 *)(extraout_ECX + 0x14));
  if (bVar2) {
    FUN_11006f30(extraout_ECX);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11001121 FUN_11001121  (called by: FUN_11003e3c@11003e3c, FUN_1100440c@1100440c)

undefined4 * __cdecl
FUN_11001121(char param_1,char param_2,ScStub *param_3,undefined1 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  undefined4 *puVar1;
  undefined4 local_1c [6];
  
  puVar1 = (undefined4 *)FUN_11007220(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_1100107a(local_1c,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    FUN_110089e0(puVar1,local_1c,0x18);
    FUN_11006f80(&DAT_11020178,(int)puVar1);
  }
  return puVar1;
}


// ---- 11001172 FUN_11001172  (called by: FUN_11005f7f@11005f7f)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_11001172(void)

{
  HANDLE hFile;
  DWORD _Size;
  DWORD local_4;
  
  DAT_11015ff0 = _DAT_004ff814;
  hFile = CreateFileA(s_renegmbl_raw_1101440c,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                      (HANDLE)0x0);
  _Size = GetFileSize(hFile,(LPDWORD)0x0);
  DAT_11015ff4 = _malloc(_Size);
  ReadFile(hFile,DAT_11015ff4,_Size,&local_4,(LPOVERLAPPED)0x0);
  CloseHandle(hFile);
  _DAT_004ff814 = (int)DAT_11015ff4 - *(int *)(_DAT_00546b98 + 0xec);
  return;
}


// ---- 110011e7 FUN_110011e7  (called by: FUN_11005f7f@11005f7f)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_110011e7(void)

{
  _DAT_004ff814 = DAT_11015ff0;
  FUN_11008da1(DAT_11015ff4);
  return;
}


// ---- 110011fe FUN_110011fe  (called by: FUN_11006aa8@11006aa8)

undefined4 __cdecl FUN_110011fe(undefined4 param_1,LPCSTR param_2)

{
  int iVar1;
  FILE *_File;
  uint uVar2;
  undefined1 unaff_BP;
  char local_4e4c [19952];
  undefined4 uStackY_5c;
  undefined4 uVar3;
  
  FUN_11009390(unaff_BP);
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
        _File = (FILE *)FUN_11009372(param_2,&DAT_11014440);
        if (_File != (FILE *)0x0) {
          BASS_ChannelGetInfo();
          FUN_11009208((char *)&WAVE_11014428,0x14,1,(int *)_File);
          FUN_11009208(local_4e4c + 0x4e34,0x10,1,(int *)_File);
          FUN_11009208(&DAT_1101441c,8,1,(int *)_File);
          while (iVar1 = BASS_ChannelIsActive(), iVar1 != 0) {
            uVar2 = BASS_ChannelGetData();
            FUN_11009208(local_4e4c,1,uVar2,(int *)_File);
            BASS_ChannelGetPosition();
          }
          FUN_110090a2((int *)_File);
          iVar1 = FUN_11008f1f((char *)_File);
          FUN_11008e66((int *)_File,4,0);
          __putw(iVar1 + -8,_File);
          FUN_110090a2((int *)_File);
          FUN_11008e66((int *)_File,0x28,0);
          __putw(iVar1 + -0x2c,_File);
          FUN_110090a2((int *)_File);
          uStackY_5c = 0x11001374;
          FUN_11008de9(_File);
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


// ---- 1100137e FUN_1100137e  (called by: FUN_11001417@11001417)

undefined4 * __thiscall
FUN_1100137e(undefined4 *param_1,char param_2,char param_3,undefined1 param_4,MAP_RECT param_5)

{
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  
  FUN_11006eb0(param_1,param_2,param_3,in_stack_00000020);
  MAP_RECT::MAP_RECT((MAP_RECT *)(param_1 + 4));
  *param_1 = &PTR_FUN_110103fc;
  MAP_RECT::operator=((MAP_RECT *)(param_1 + 4),&param_5);
  *(undefined1 *)(param_1 + 8) = param_4;
  param_1[2] = in_stack_00000024;
  return param_1;
}


// ---- 110013c4 FUN_110013c4  (called by: -)

void __fastcall FUN_110013c4(int param_1)

{
  int iVar1;
  InRectEnumerator local_3c [52];
  undefined4 local_8;
  
  local_8 = 0;
  InRectEnumerator::InRectEnumerator(local_3c,(MAP_RECT *)(param_1 + 0x10));
  do {
    iVar1 = InRectEnumerator::GetNext(local_3c,(Unit *)&local_8);
    if (iVar1 == 0) {
      FUN_11006f30(param_1);
      return;
    }
    iVar1 = Unit::OwnerID((Unit *)&local_8);
  } while (iVar1 != *(char *)(param_1 + 0x20));
  return;
}


// ---- 11001417 FUN_11001417  (called by: FUN_110025b8@110025b8, FUN_11002cfe@11002cfe)

undefined4 * __cdecl FUN_11001417(char param_1,char param_2,undefined1 param_3,MAP_RECT param_4)

{
  undefined4 *puVar1;
  undefined4 local_28 [9];
  
  puVar1 = (undefined4 *)FUN_11007220(0x24);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_1100137e(local_28,param_1,param_2,param_3,param_4);
    FUN_110089e0(puVar1,local_28,0x24);
    FUN_11006f80(&DAT_11020178,(int)puVar1);
  }
  return puVar1;
}


// ---- 11001472 FUN_11001472  (called by: FUN_110014da@110014da)

void __cdecl FUN_11001472(int param_1,int param_2,int param_3,int param_4,map_id param_5)

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


// ---- 110014da FUN_110014da  (called by: FUN_110022f0@110022f0, InitProc@11005892)

void __cdecl FUN_110014da(undefined4 param_1,int param_2,int param_3,int *param_4)

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
      FUN_11001472(*piVar2 + param_2,piVar2[1] + param_3,piVar2[2] + param_2,piVar2[3] + param_3,
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
      FUN_11001472(*piVar2 + param_2,piVar2[1] + param_3,piVar2[2] + param_2,piVar2[3] + param_3,
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


// ---- 11001603 FUN_11001603  (called by: InitProc@11005892)

void __cdecl FUN_11001603(int param_1,int param_2)

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


// ---- 11001634 FUN_11001634  (called by: FUN_11001634@11001634, FUN_110017a9@110017a9, FUN_110022f0@110022f0, FUN_11002cfe@11002cfe, FUN_11003880@11003880, FUN_11003c21@11003c21)

void FUN_11001634(void)

{
  int unaff_EBP;
  int iVar1;
  int iVar2;
  
  FUN_110089b4();
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
      FUN_11001634();
      FUN_11001634();
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 110017a9 FUN_110017a9  (called by: FUN_110021c8@110021c8, FUN_110022f0@110022f0, FUN_11002cfe@11002cfe, FUN_11003880@11003880, FUN_11004240@11004240)

void FUN_110017a9(void)

{
  int *piVar1;
  int iVar2;
  map_id mVar3;
  int *piVar4;
  int iVar5;
  int unaff_EBP;
  int iVar6;
  
  FUN_110089b4();
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
      FUN_11001634();
      *(int *)(unaff_EBP + 0x14) = *(int *)(unaff_EBP + 0x14) + 0x10;
      iVar5 = iVar5 + 1;
    } while (iVar5 < piVar1[2]);
  }
  iVar5 = 0;
  if (0 < piVar1[4]) {
    *(undefined4 *)(unaff_EBP + 0x14) = 0;
    do {
      FUN_11001634();
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


// ---- 110018d6 FUN_110018d6  (called by: FUN_110021c8@110021c8, FUN_110022ab@110022ab, FUN_11003880@11003880, FUN_11003cd5@11003cd5)

void FUN_110018d6(void)

{
  map_id mVar1;
  map_id mVar2;
  map_id mVar3;
  int unaff_EBP;
  map_id *pmVar4;
  int iVar5;
  
  FUN_110089b4();
  iVar5 = *(int *)(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (0 < iVar5) {
    pmVar4 = (map_id *)(*(int *)(unaff_EBP + 0x18) + 0xc);
    do {
      mVar1 = pmVar4[-2];
      mVar2 = *pmVar4;
      mVar3 = pmVar4[-1];
      *(map_id *)(unaff_EBP + -0x14) = pmVar4[-3] + *(int *)(unaff_EBP + 0xc);
      *(map_id *)(unaff_EBP + -0x10) = mVar1 + *(int *)(unaff_EBP + 0x10);
      BuildingGroup::RecordBuilding
                ((BuildingGroup *)(unaff_EBP + 8),(LOCATION *)(unaff_EBP + -0x14),mVar3,mVar2);
      pmVar4 = pmVar4 + 5;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11001972 GetCargo  (called by: -)

/* public: enum map_id __thiscall IUnit::GetCargo(void) */

map_id __thiscall IUnit::GetCargo(IUnit *this)

{
  map_id mVar1;
  
                    /* WARNING: Could not recover jumptable at 0x11001972. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x1972  2  ?GetCargo@IUnit@@QAE?AW4map_id@@XZ */
  mVar1 = Unit::GetCargo((Unit *)this);
  return mVar1;
}


// ---- 11001978 operator=  (called by: -)

/* public: class IUnit & __thiscall IUnit::operator=(class IUnit const &) */

IUnit * __thiscall IUnit::operator=(IUnit *this,IUnit *param_1)

{
                    /* 0x1978  1  ??4IUnit@@QAEAAV0@ABV0@@Z */
  Unit::operator=((Unit *)this,(Unit *)param_1);
  return this;
}


// ---- 11001a97 FUN_11001a97  (called by: -)

void FUN_11001a97(void)

{
  FUN_11001c63();
  return;
}


// ---- 11001aa1 FUN_11001aa1  (called by: -)

void FUN_11001aa1(void)

{
  FUN_1100943d(0x11001aad);
  return;
}


// ---- 11001aad FUN_11001aad  (called by: -)

void FUN_11001aad(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_110089b4();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0x21;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xe4));
  *(undefined1 *)(unaff_EBP + -4) = 0x20;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xe0));
  *(undefined1 *)(unaff_EBP + -4) = 0x1f;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xdc));
  *(undefined1 *)(unaff_EBP + -4) = 0x1e;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xd8));
  *(undefined1 *)(unaff_EBP + -4) = 0x1d;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xcc));
  *(undefined1 *)(unaff_EBP + -4) = 0x1c;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 200));
  *(undefined1 *)(unaff_EBP + -4) = 0x1b;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xc4));
  *(undefined1 *)(unaff_EBP + -4) = 0x1a;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xc0));
  *(undefined1 *)(unaff_EBP + -4) = 0x19;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xbc));
  *(undefined1 *)(unaff_EBP + -4) = 0x18;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xb8));
  *(undefined1 *)(unaff_EBP + -4) = 0x17;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xb4));
  *(undefined1 *)(unaff_EBP + -4) = 0x16;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xb0));
  *(undefined1 *)(unaff_EBP + -4) = 0x15;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xac));
  *(undefined1 *)(unaff_EBP + -4) = 0x14;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xa8));
  *(undefined1 *)(unaff_EBP + -4) = 0x13;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xa4));
  *(undefined1 *)(unaff_EBP + -4) = 0x12;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0xa0));
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x9c));
  *(undefined1 *)(unaff_EBP + -4) = 0x10;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x98));
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x94));
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x90));
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x8c));
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x88));
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x84));
  *(undefined1 *)(unaff_EBP + -4) = 10;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x80));
  *(undefined1 *)(unaff_EBP + -4) = 9;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x7c));
  *(undefined1 *)(unaff_EBP + -4) = 8;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x78));
  *(undefined1 *)(unaff_EBP + -4) = 7;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x74));
  *(undefined1 *)(unaff_EBP + -4) = 6;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x70));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x6c));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x68));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 100));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x60));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x5c));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x58));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(extraout_ECX + 0x54));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11001c63 FUN_11001c63  (called by: FUN_11001a97@11001a97)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_11001c63(void)

{
  int *piVar1;
  int extraout_ECX;
  int unaff_EBP;
  LOCATION *this;
  
  FUN_110089b4();
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
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
  MiningGroup::MiningGroup((MiningGroup *)(extraout_ECX + 0x54));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  MiningGroup::MiningGroup((MiningGroup *)(extraout_ECX + 0x58));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  MiningGroup::MiningGroup((MiningGroup *)(extraout_ECX + 0x5c));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  MiningGroup::MiningGroup((MiningGroup *)(extraout_ECX + 0x60));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  BuildingGroup::BuildingGroup((BuildingGroup *)(extraout_ECX + 100));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  BuildingGroup::BuildingGroup((BuildingGroup *)(extraout_ECX + 0x68));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  BuildingGroup::BuildingGroup((BuildingGroup *)(extraout_ECX + 0x6c));
  *(undefined1 *)(unaff_EBP + -4) = 6;
  BuildingGroup::BuildingGroup((BuildingGroup *)(extraout_ECX + 0x70));
  *(undefined1 *)(unaff_EBP + -4) = 7;
  BuildingGroup::BuildingGroup((BuildingGroup *)(extraout_ECX + 0x74));
  *(undefined1 *)(unaff_EBP + -4) = 8;
  BuildingGroup::BuildingGroup((BuildingGroup *)(extraout_ECX + 0x78));
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x7c));
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x80));
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x84));
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x88));
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x8c));
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x90));
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x94));
  *(undefined1 *)(unaff_EBP + -4) = 0x10;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x98));
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0x9c));
  *(undefined1 *)(unaff_EBP + -4) = 0x12;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0xa0));
  *(undefined1 *)(unaff_EBP + -4) = 0x13;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0xa4));
  *(undefined1 *)(unaff_EBP + -4) = 0x14;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0xa8));
  *(undefined1 *)(unaff_EBP + -4) = 0x15;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0xac));
  *(undefined1 *)(unaff_EBP + -4) = 0x16;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0xb0));
  *(undefined1 *)(unaff_EBP + -4) = 0x17;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0xb4));
  *(undefined1 *)(unaff_EBP + -4) = 0x18;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0xb8));
  *(undefined1 *)(unaff_EBP + -4) = 0x19;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0xbc));
  *(undefined1 *)(unaff_EBP + -4) = 0x1a;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0xc0));
  *(undefined1 *)(unaff_EBP + -4) = 0x1b;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0xc4));
  *(undefined1 *)(unaff_EBP + -4) = 0x1c;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 200));
  *(undefined1 *)(unaff_EBP + -4) = 0x1d;
  FightGroup::FightGroup((FightGroup *)(extraout_ECX + 0xcc));
  *(undefined1 *)(unaff_EBP + -4) = 0x1e;
  Trigger::Trigger((Trigger *)(extraout_ECX + 0xd8));
  *(undefined1 *)(unaff_EBP + -4) = 0x1f;
  Trigger::Trigger((Trigger *)(extraout_ECX + 0xdc));
  *(undefined1 *)(unaff_EBP + -4) = 0x20;
  Trigger::Trigger((Trigger *)(extraout_ECX + 0xe0));
  *(undefined1 *)(unaff_EBP + -4) = 0x21;
  Trigger::Trigger((Trigger *)(extraout_ECX + 0xe4));
  *(undefined1 *)(unaff_EBP + -4) = 0x22;
  this = (LOCATION *)(extraout_ECX + 0xf0);
  *(undefined4 *)(unaff_EBP + -0x10) = 0x800;
  do {
    LOCATION::LOCATION(this);
    this = this + 8;
    piVar1 = (int *)(unaff_EBP + -0x10);
    *piVar1 = *piVar1 + -1;
  } while (*piVar1 != 0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  _DAT_11020100 = 0x15;
  _DAT_11020104 = 0;
  _DAT_11020108 = 0;
  _DAT_1102010c = 1;
  _DAT_11020110 = 0;
  *(undefined4 *)(extraout_ECX + 0x40f0) = 0;
  *(undefined4 *)(extraout_ECX + 0x40f4) = 0;
  *(undefined4 *)(extraout_ECX + 0x40f8) = 0;
  *(undefined4 *)(extraout_ECX + 0x40fc) = 5;
  *(undefined1 *)(extraout_ECX + 0xe8) = 0;
  *(undefined1 *)(extraout_ECX + 0xe9) = 0;
  *(undefined1 *)(extraout_ECX + 0xea) = 1;
  *(undefined1 *)(extraout_ECX + 0xeb) = 0;
  *(undefined1 *)(extraout_ECX + 0xec) = 0;
  return extraout_ECX;
}


// ---- 11001f32 FUN_11001f32  (called by: FUN_110025b8@110025b8, FUN_110027b8@110027b8, FUN_11002cfe@11002cfe, FUN_1100301d@1100301d)

void __cdecl FUN_11001f32(ScStub *param_1)

{
  int iVar1;
  
  iVar1 = ScStub::IsInitialized(param_1);
  if (iVar1 != 0) {
    ScStub::Disable(param_1);
    ScStub::Destroy(param_1);
  }
  return;
}


// ---- 11001f55 FUN_11001f55  (called by: FUN_110025b8@110025b8, FUN_11002a51@11002a51, FUN_1100301d@1100301d, FUN_11003503@11003503, FUN_11003880@11003880, FUN_110040e2@110040e2)

void FUN_11001f55(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  FUN_110089b4();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar1 = FUN_11007720(*(int *)(unaff_EBP + 0xc),SUB41(*(undefined4 *)(unaff_EBP + 8),0));
  if ((char)uVar1 != '\0') {
    ScGroup::RemoveUnit((ScGroup *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11001f99 FUN_11001f99  (called by: FUN_110025b8@110025b8, FUN_11005670@11005670, FUN_110056dc@110056dc, FUN_11005748@11005748, FUN_110057b4@110057b4, FUN_11005823@11005823)

void __cdecl FUN_11001f99(undefined4 param_1)

{
  PlayerBuildingEnum *this;
  Unit *pUVar1;
  PlayerBuildingEnum local_10 [8];
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  scr_snprintf(&DAT_110198d4,0x50,s_New_mission_objective_s_11014e48,param_1);
  pUVar1 = (Unit *)&local_8;
  this = (PlayerBuildingEnum *)PlayerBuildingEnum::PlayerBuildingEnum(local_10,0,0x31);
  PlayerBuildingEnum::GetNext(this,pUVar1);
  TethysGame::AddMessage(&DAT_110198d4,0,local_8,0x7a);
  return;
}


// ---- 11001fec FUN_11001fec  (called by: FUN_11004a66@11004a66)

void FUN_11001fec(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  map_id mVar4;
  ScGroup *pSVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  MAP_RECT local_3c [16];
  PlayerBuildingEnum local_2c [8];
  PlayerBuildingEnum local_24 [8];
  undefined1 local_1c [4];
  int local_18;
  undefined1 local_14 [4];
  int local_10;
  PlayerVehicleEnum local_c [4];
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  PlayerVehicleEnum::PlayerVehicleEnum(local_c,1);
  PlayerBuildingEnum::PlayerBuildingEnum(local_2c,1,0x36);
  PlayerBuildingEnum::PlayerBuildingEnum(local_24,1,0x15);
  PlayerBuildingEnum::GetNext(local_24,(Unit *)&DAT_1101c00c);
  PlayerBuildingEnum::GetNext(local_24,(Unit *)&DAT_1101c010);
  iVar1 = Unit::Location((Unit *)&DAT_1101c010);
  iVar2 = Unit::Location((Unit *)&DAT_1101c00c);
  if (*(int *)(iVar1 + 4) < *(int *)(iVar2 + 4)) {
    local_10 = DAT_1101c00c;
    Unit::operator=((Unit *)&DAT_1101c00c,(Unit *)&DAT_1101c010);
    Unit::operator=((Unit *)&DAT_1101c010,(Unit *)&local_10);
  }
  PlayerBuildingEnum::GetNext(local_2c,(Unit *)&DAT_1101c018);
  PlayerBuildingEnum::GetNext(local_2c,(Unit *)&DAT_1101c01c);
  puVar6 = local_1c;
  iVar1 = Unit::Location((Unit *)&DAT_1101c01c);
  puVar7 = local_14;
  iVar2 = Unit::Location((Unit *)&DAT_1101c018);
  if (*(int *)(iVar1 + 4) < *(int *)(iVar2 + 4)) {
    local_10 = DAT_1101c018;
    Unit::operator=((Unit *)&DAT_1101c018,(Unit *)&DAT_1101c01c);
    Unit::operator=((Unit *)&DAT_1101c01c,(Unit *)&local_10);
  }
  if ((0 < DAT_1101c00c) && (0 < DAT_1101c018)) {
    local_10 = DAT_1101c018;
    local_18 = DAT_1101c00c;
    uVar3 = MAP_RECT::MAP_RECT(local_3c,0x31,0x16,0x36,0x18);
    MiningGroup::Setup((MiningGroup *)&DAT_1101c054,local_18,local_10,uVar3,puVar7,puVar6);
    ScGroup::SetTargCount((ScGroup *)&DAT_1101c054,1,0,4);
  }
  if ((0 < DAT_1101c010) && (0 < DAT_1101c01c)) {
    local_18 = DAT_1101c01c;
    local_10 = DAT_1101c010;
    uVar3 = MAP_RECT::MAP_RECT(local_3c,0x23,0x52,0x27,0x56);
    MiningGroup::Setup((MiningGroup *)&DAT_1101c058,local_10,local_18,uVar3,puVar7);
    ScGroup::SetTargCount((ScGroup *)&DAT_1101c058,1,0,2);
  }
  iVar1 = PlayerVehicleEnum::GetNext(local_c,(Unit *)&local_8);
  while (0 < iVar1) {
    mVar4 = Unit::GetType((Unit *)&local_8);
    if (mVar4 == 1) {
      puVar6 = local_1c;
      iVar1 = Unit::Location((Unit *)&local_8);
      pSVar5 = (ScGroup *)&DAT_1101c058;
      if (*(int *)(iVar1 + 4) < 0x51) {
        pSVar5 = (ScGroup *)&DAT_1101c054;
      }
      ScGroup::TakeUnit(pSVar5,local_8,puVar6);
    }
    iVar1 = PlayerVehicleEnum::GetNext(local_c,(Unit *)&local_8);
  }
  return;
}


// ---- 110021c8 FUN_110021c8  (called by: FUN_110022f0@110022f0, FUN_11002cfe@11002cfe)

void FUN_110021c8(void)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0x31;
  local_8 = 0x12;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c064,(LOCATION *)&local_c,0x23,0);
  local_c = 0x2a;
  local_8 = 0xe;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c064,(LOCATION *)&local_c,0x26,0);
  local_c = 0x32;
  local_8 = 0x1a;
  BuildingGroup::RecordBuilding
            ((BuildingGroup *)&DAT_1101c064,(LOCATION *)&local_c,0x30,0,(ScGroup *)&DAT_1101c06c);
  local_c = 0x2d;
  local_8 = 0xd;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c064,(LOCATION *)&local_c,0x19,0);
  FUN_110018d6();
  FUN_110017a9();
  FUN_11007870('\x01','\x01',1,0x32,0,4,FUN_11002292,0);
  return;
}


// ---- 11002292 FUN_11002292  (called by: -)

void FUN_11002292(void)

{
  FUN_11007a30('\x01','\x01',0x898,FUN_110022ab,0);
  return;
}


// ---- 110022ab FUN_110022ab  (called by: -)

void FUN_110022ab(void)

{
  ScGroup::ClearTargCount((ScGroup *)&DAT_1101c090);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c090,5,0x3d,7);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c090,5,0x3f,4);
  FUN_110018d6();
  return;
}


// ---- 110022f0 FUN_110022f0  (called by: InitProc@11005892)

void FUN_110022f0(void)

{
  int iVar1;
  map_id mVar2;
  PlayerBuildingEnum local_20 [8];
  undefined4 local_18;
  undefined4 local_14;
  IUnit local_10 [4];
  PlayerVehicleEnum local_c [4];
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  IUnit::IUnit(local_10);
  PlayerVehicleEnum::PlayerVehicleEnum(local_c,1);
  PlayerBuildingEnum::PlayerBuildingEnum(local_20,1,0x2f);
  iVar1 = PlayerVehicleEnum::GetNext(local_c,(Unit *)&local_8);
  while (0 < iVar1) {
    mVar2 = Unit::GetType((Unit *)&local_8);
    if (mVar2 == 2) {
      ScGroup::TakeUnit((ScGroup *)&DAT_1101c064,local_8);
    }
    iVar1 = PlayerVehicleEnum::GetNext(local_c,(Unit *)&local_8);
  }
  PlayerBuildingEnum::GetNext(local_20,(Unit *)&DAT_1101c044);
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c064,DAT_1101c044);
  FUN_110017a9();
  local_18 = 0x30;
  local_14 = 0xb;
  BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c064,(LOCATION *)&local_18,0x31,0);
  if (DAT_1101c000 == '\0') {
    FUN_11007870('\x01','\x01',1,0x31,0,4,FUN_110021c8,0);
  }
  else {
    FUN_110014da(1,0x1f,-1,(int *)&DAT_11014d60);
    TethysGame::CreateUnit(local_10,0x31,0x30,0xb,1,0,0);
    FUN_110021c8();
  }
  FUN_11001634();
  return;
}


// ---- 11002425 FUN_11002425  (called by: -)

void FUN_11002425(void)

{
  if (DAT_1102016c != 0) {
    FUN_11006ee0(DAT_1102016c);
  }
  DAT_1102016c = 0;
  if ((DAT_1101c0ec == '\0') && (DAT_1101c050 == 0)) {
    TethysGame::CreateUnit(&DAT_1101c050,0xd,0x22,0x5a,2,6,0);
    ScGroup::TakeUnit((ScGroup *)&DAT_1101c0cc,DAT_1101c050);
  }
  return;
}


// ---- 1100247b FUN_1100247b  (called by: FUN_11003c21@11003c21)

void FUN_1100247b(void)

{
  if (DAT_11020154 != 0) {
    FUN_11006ee0(DAT_11020154);
  }
  DAT_11020154 = 0;
  if (DAT_1101c0ec == '\0') {
    BuildingGroup::RecordVehReinforceGroup
              ((BuildingGroup *)&DAT_1101c078,(ScGroup *)&DAT_1101c0cc,200);
    FUN_11007b00('\x01','\x01',2,0xd,0xffffffff,1,0,FUN_110024f3,0);
    if (DAT_1102016c == (undefined4 *)0x0) {
      DAT_1102016c = FUN_11007870('\x01','\x01',2,0x30,1,3,FUN_11002425,0);
    }
  }
  return;
}


// ---- 110024f3 FUN_110024f3  (called by: -)

void FUN_110024f3(void)

{
  if (DAT_1101c0ec == '\0') {
    ScGroup::GetFirstOfType((ScGroup *)&DAT_1101c0cc,(Unit *)&DAT_1101c050,9);
    if (0 < DAT_1101c050) {
      Unit::SetCargo((Unit *)&DAT_1101c050,6,0);
      FUN_11007a30('\x01','\x01',500,FUN_1100256d,0);
      if (DAT_11020154 != (undefined4 *)0x0) {
        FUN_11006ee0((int)DAT_11020154);
      }
      DAT_11020154 = FUN_11007b00('\x01','\x01',2,0xd,0xffffffff,0,0,FUN_1100247b,0);
    }
  }
  return;
}


// ---- 1100256d FUN_1100256d  (called by: -)

void FUN_1100256d(void)

{
  MAP_RECT *pMVar1;
  MAP_RECT aMStack_10 [16];
  
  if (DAT_1101c0ec == '\0') {
    pMVar1 = (MAP_RECT *)MAP_RECT::MAP_RECT(aMStack_10,0x38,0x4b,0x3b,0x4e);
    FightGroup::SetRect((FightGroup *)&DAT_1101c0cc,pMVar1);
    FUN_11007cc0('\x01','\x01',2,0x38,0x4b,3,3);
  }
  return;
}


// ---- 110025b8 FUN_110025b8  (called by: -)

void FUN_110025b8(void)

{
  int iVar1;
  Trigger *pTVar2;
  undefined4 *puVar3;
  int unaff_EBP;
  char *pcVar4;
  
  FUN_110089b4();
  if (DAT_1101c0ec == '\0') {
    iVar1 = ScStub::IsInitialized((ScStub *)&DAT_1101c0cc);
    if (iVar1 != 0) {
      BuildingGroup::UnRecordVehGroup((BuildingGroup *)&DAT_1101c078,(ScGroup *)&DAT_1101c0cc);
      *(undefined4 *)(unaff_EBP + -0x10) = DAT_1101c0cc;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_11001f55();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
    }
    Unit::DoTransfer((Unit *)&DAT_1101c050,0);
    DAT_1101c0ec = '\x01';
    TethysGame::AddMessage(s_A_group_of_colonists_wants_to_de_11014ed8,0,DAT_1101c050,0xa2);
    FUN_11001f32((ScStub *)&DAT_1101c0d8);
    pTVar2 = (Trigger *)CreateSpecialTarget(unaff_EBP + -0x10,0,(Unit *)0x1,0x1101c050,(char *)0x1e)
    ;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    Trigger::operator=((Trigger *)&DAT_1101c0d8,pTVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
    DAT_1101c0e8 = 1;
    FUN_11001f32((ScStub *)&DAT_1101c0dc);
    pTVar2 = (Trigger *)CreateTimeTrigger(unaff_EBP + -0x10,0,1,(char *)0xa);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    Trigger::operator=((Trigger *)&DAT_1101c0dc,pTVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
    FUN_11001f32((ScStub *)&DAT_1101c0e0);
    pTVar2 = (Trigger *)CreateTimeTrigger(unaff_EBP + -0x10,0,1,(char *)0xa);
    *(undefined4 *)(unaff_EBP + -4) = 3;
    Trigger::operator=((Trigger *)&DAT_1101c0e0,pTVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
    pTVar2 = (Trigger *)CreateFailureCondition(unaff_EBP + -0x10,1,(Trigger *)0x0,&DAT_1101c0e0);
    *(undefined4 *)(unaff_EBP + -4) = 4;
    Trigger::operator=((Trigger *)&DAT_1101c0e4,pTVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
    pcVar4 = s_Escort_defectors_to_safety_11014ebc;
    CreateVictoryCondition(unaff_EBP + -0x10,1,(Trigger *)0x0,&DAT_1101c0dc);
    ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
    FUN_11001f99(s___Escort_defectors_to_safety_11014e9c);
    TethysGame::AddMessage(s_To_transfer_colonists__put_the_e_11014e60,0,DAT_1101c050,0,pcVar4);
    puVar3 = (undefined4 *)MAP_RECT::MAP_RECT((MAP_RECT *)(unaff_EBP + -0x20),0x20,0x43,0x3e,0x5a);
    FUN_11001417('\x01','\x01',0,SUB41(*puVar3,0));
    if (DAT_11020154 != 0) {
      FUN_11006ee0(DAT_11020154);
    }
    DAT_11020154 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 110027b8 FUN_110027b8  (called by: FUN_11002867@11002867)

void __cdecl FUN_110027b8(undefined4 param_1)

{
  map_id mVar1;
  int iVar2;
  
  mVar1 = Unit::GetCargo((Unit *)&DAT_1101c050);
  if (mVar1 == 6) {
    TethysGame::AddMessage(s_Colonists_transferred_safely__11014f00,0,param_1,0xb2);
    iVar2 = _Player::Scientists((_Player *)&DAT_11020128);
    _Player::SetScientists((_Player *)&DAT_11020128,iVar2 + 5);
    iVar2 = _Player::Workers((_Player *)&DAT_11020128);
    _Player::SetWorkers((_Player *)&DAT_11020128,iVar2 + 10);
    iVar2 = _Player::Kids((_Player *)&DAT_11020128);
    _Player::SetKids((_Player *)&DAT_11020128,iVar2 + 10);
    Unit::SetCargo((Unit *)&DAT_1101c050,0,0);
    Unit::ClearSpecialTarget((Unit *)&DAT_1101c050);
    FUN_11001f32((ScStub *)&DAT_1101c0d8);
    FUN_11001f32((ScStub *)&DAT_1101c0e4);
    DAT_1101c0e8 = 0;
    Trigger::Enable((Trigger *)&DAT_1101c0dc);
  }
  return;
}


// ---- 11002867 FUN_11002867  (called by: FUN_110055fe@110055fe)

void FUN_11002867(void)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  map_id mVar4;
  InRectEnumerator local_54 [52];
  MAP_RECT local_20 [24];
  undefined4 local_8;
  
  iVar2 = Unit::IsLive((Unit *)&DAT_1101c050);
  if (iVar2 == 0) {
    Trigger::Enable((Trigger *)&DAT_1101c0e0);
  }
  else {
    IUnit::IUnit((IUnit *)&local_8);
    piVar3 = (int *)Unit::Location((Unit *)&DAT_1101c050);
    MAP_RECT::MAP_RECT(local_20,*piVar3 + -1,piVar3[1] + -1,*piVar3 + 2,piVar3[1] + 2);
    InRectEnumerator::InRectEnumerator(local_54,local_20);
    do {
      iVar2 = InRectEnumerator::GetNext(local_54,(Unit *)&local_8);
      if (iVar2 == 0) {
        return;
      }
      mVar4 = Unit::GetType((Unit *)&local_8);
    } while ((mVar4 != 0x1e) || (iVar2 = Unit::OwnerID((Unit *)&local_8), iVar2 != 0));
    iVar2 = Unit::IsLive((Unit *)&local_8);
    if ((iVar2 != 0) && (bVar1 = IUnit::IsIdled((IUnit *)&local_8), !bVar1)) {
      FUN_110027b8(local_8);
    }
  }
  return;
}


// ---- 11002929 FUN_11002929  (called by: FUN_11002a51@11002a51)

void FUN_11002929(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  map_id mVar4;
  InRectEnumerator local_5c [52];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  MAP_RECT local_18 [12];
  GroupEnumerator local_c [4];
  IUnit local_8 [4];
  
  piVar1 = (int *)Unit::Location((Unit *)&DAT_1101c050);
  puVar2 = (undefined4 *)
           MAP_RECT::MAP_RECT(local_18,*piVar1 + -2,piVar1[1] + -2,*piVar1 + 3,piVar1[1] + 3);
  local_28 = *puVar2;
  uStack_24 = puVar2[1];
  uStack_20 = puVar2[2];
  uStack_1c = puVar2[3];
  IUnit::IUnit(local_8);
  iVar3 = ScGroup::TotalUnitCount((ScGroup *)&DAT_1101c0c0);
  if (iVar3 != 0) {
    FightGroup::ClearGuarderdRects((FightGroup *)&DAT_1101c0c0);
    FightGroup::DoPatrolOnly((FightGroup *)&DAT_1101c0c0);
    FightGroup::SetRect((FightGroup *)&DAT_1101c0c0,(MAP_RECT *)&local_28);
    if (DAT_1101c0eb == '\0') {
      MAP_RECT::Inflate((MAP_RECT *)&local_28,4,4);
      InRectEnumerator::InRectEnumerator(local_5c,(MAP_RECT *)&local_28);
      do {
        iVar3 = InRectEnumerator::GetNext(local_5c,(Unit *)local_8);
        if (iVar3 == 0) {
          return;
        }
        iVar3 = Unit::OwnerID((Unit *)local_8);
      } while ((iVar3 != 0) || (mVar4 = Unit::GetType((Unit *)local_8), mVar4 != 5));
      GroupEnumerator::GroupEnumerator(local_c,(ScGroup *)&DAT_1101c0c0);
      while (iVar3 = GroupEnumerator::GetNext(local_c,(Unit *)local_8), iVar3 != 0) {
        IUnit::SetOffensive(local_8,true);
      }
      FightGroup::DoAttackEnemy((FightGroup *)&DAT_1101c0c0);
      FightGroup::SetAttackType((FightGroup *)&DAT_1101c0c0,5);
      DAT_1101c0eb = '\x01';
    }
  }
  return;
}


// ---- 11002a51 FUN_11002a51  (called by: -)

void FUN_11002a51(void)

{
  int iVar1;
  map_id mVar2;
  int unaff_EBP;
  int iVar3;
  
  FUN_110089b4();
  GroupEnumerator::GroupEnumerator((GroupEnumerator *)(unaff_EBP + -0x14),(ScGroup *)&DAT_1101c0b0);
  IUnit::IUnit((IUnit *)(unaff_EBP + -0x10));
  iVar3 = 0;
  do {
    do {
      iVar1 = GroupEnumerator::GetNext
                        ((GroupEnumerator *)(unaff_EBP + -0x14),(Unit *)(unaff_EBP + -0x10));
      if (iVar1 == 0) goto LAB_11002ae5;
      mVar2 = Unit::GetWeapon((Unit *)(unaff_EBP + -0x10));
    } while (mVar2 != 0x3e);
    *(undefined4 *)(unaff_EBP + -0x18) = DAT_1101c0b0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_11001f55();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    ScStub::~ScStub((ScStub *)(unaff_EBP + -0x18));
    IUnit::SetOffensive((IUnit *)(unaff_EBP + -0x10),false);
    ScGroup::TakeUnit((ScGroup *)&DAT_1101c0c0,*(undefined4 *)(unaff_EBP + -0x10));
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
LAB_11002ae5:
  FUN_11002929();
  FUN_11007a30('\x01','\0',0x32,FUN_11002929,0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11002b0d FUN_11002b0d  (called by: -)

void FUN_11002b0d(void)

{
  int iVar1;
  LocationEnumerator *pLVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  LocationEnumerator local_48 [52];
  MAP_RECT local_14 [8];
  undefined4 local_c;
  undefined4 local_8;
  
  piVar5 = &DAT_1101c014;
  local_c = 0x65;
  local_8 = 6;
  pLVar2 = (LocationEnumerator *)
           LocationEnumerator::LocationEnumerator(local_48,(LOCATION *)&local_c);
  LocationEnumerator::GetNext(pLVar2,(Unit *)piVar5);
  piVar5 = &DAT_1101c020;
  local_c = 0x37;
  local_8 = 10;
  pLVar2 = (LocationEnumerator *)
           LocationEnumerator::LocationEnumerator(local_48,(LOCATION *)&local_c);
  LocationEnumerator::GetNext(pLVar2,(Unit *)piVar5);
  iVar1 = DAT_1101c020;
  iVar4 = DAT_1101c014;
  if ((0 < DAT_1101c014) && (0 < DAT_1101c020)) {
    uVar3 = MAP_RECT::MAP_RECT(local_14,0x37,8,0x3b,0xc);
    MiningGroup::Setup((MiningGroup *)&DAT_1101c05c,iVar4,iVar1,uVar3);
    ScGroup::SetTargCount((ScGroup *)&DAT_1101c05c,1,0,4);
    BuildingGroup::RecordVehReinforceGroup
              ((BuildingGroup *)&DAT_1101c06c,(ScGroup *)&DAT_1101c05c,0x4b0);
    iVar4 = ScGroup::UnitCount((ScGroup *)&DAT_1101c05c,7);
    if (iVar4 < 3) {
      FUN_11007520((ScGroup *)&DAT_1101c0c8,&DAT_1101c05c,0xffffffff);
    }
  }
  return;
}


// ---- 11002be0 FUN_11002be0  (called by: FUN_11003503@11003503)

void FUN_11002be0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  MAP_RECT local_28 [16];
  PlayerBuildingEnum local_18 [8];
  PlayerBuildingEnum local_10 [8];
  IUnit local_8 [4];
  
  IUnit::IUnit(local_8);
  PlayerBuildingEnum::PlayerBuildingEnum(local_18,2,0x36);
  PlayerBuildingEnum::PlayerBuildingEnum(local_10,2,0x15);
  iVar3 = PlayerBuildingEnum::GetNext(local_10,(Unit *)&DAT_1101c024);
  if (iVar3 != 0) {
    iVar3 = PlayerBuildingEnum::GetNext(local_18,(Unit *)&DAT_1101c028);
    uVar2 = DAT_1101c028;
    uVar1 = DAT_1101c024;
    if (iVar3 != 0) {
      uVar4 = MAP_RECT::MAP_RECT(local_28,0x23,0x52,0x27,0x56);
      MiningGroup::Setup((MiningGroup *)&DAT_1101c060,uVar1,uVar2,uVar4);
      ScGroup::SetTargCount((ScGroup *)&DAT_1101c060,1,0,2);
    }
  }
  return;
}


// ---- 11002c69 FUN_11002c69  (called by: FUN_110042e0@110042e0)

void FUN_11002c69(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EBP;
  
  FUN_110089b4();
  IUnit::IUnit((IUnit *)(unaff_EBP + -0x10));
  InRectEnumerator::InRectEnumerator
            ((InRectEnumerator *)(unaff_EBP + -0x48),(MAP_RECT *)(unaff_EBP + 8));
  uVar1 = DAT_1101c0c4;
  *(undefined4 *)(unaff_EBP + -0x14) = DAT_1101c0c4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_11007670(SUB41(uVar1,0));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  while (iVar2 = InRectEnumerator::GetNext
                           ((InRectEnumerator *)(unaff_EBP + -0x48),(Unit *)(unaff_EBP + -0x10)),
        iVar2 != 0) {
    iVar2 = Unit::OwnerID((Unit *)(unaff_EBP + -0x10));
    if ((iVar2 == *(int *)(unaff_EBP + 0x18)) &&
       (iVar2 = Unit::IsBuilding((Unit *)(unaff_EBP + -0x10)), iVar2 != 0)) {
      ScGroup::TakeUnit((ScGroup *)&DAT_1101c0c4,*(undefined4 *)(unaff_EBP + -0x10));
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11002cfe FUN_11002cfe  (called by: -)

void FUN_11002cfe(void)

{
  int iVar1;
  undefined4 *puVar2;
  MAP_RECT *pMVar3;
  int iVar4;
  undefined4 unaff_EDI;
  void *unaff_retaddr;
  undefined4 uStack00000008;
  ScGroup aSStack_18 [2];
  ScGroup aSStack_16 [2];
  IUnit local_14 [4];
  MAP_RECT aMStack_10 [12];
  undefined4 uStack_4;
  
  uStack_4 = 0x11002d08;
  FUN_110089b4();
  if (DAT_11020158 != 0) {
    FUN_11006ee0(DAT_11020158);
    DAT_11020158 = 0;
  }
  DAT_110200f4 = DAT_110200f4 + 1;
  iVar1 = DAT_110200f4 * -2;
  IUnit::IUnit(local_14);
  iVar1 = iVar1 + 1;
  if (iVar1 < 5) {
    iVar4 = 5 - iVar1;
    iVar1 = iVar1 + iVar4;
    do {
      TethysGame::CreateUnit(local_14,5,0x1f,0x61,2,0x3e,7);
      ScGroup::TakeUnit((ScGroup *)&DAT_1101c098,unaff_EDI);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  if (iVar1 + 1 < 8) {
    iVar1 = 8 - (iVar1 + 1);
    do {
      TethysGame::CreateUnit(local_14,5,0x1f,99,2,0x40,6);
      ScGroup::TakeUnit((ScGroup *)&DAT_1101c098,unaff_EDI);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  puVar2 = (undefined4 *)MAP_RECT::MAP_RECT(aMStack_10,0x1f,0x47,0x2e,100);
  DAT_11020160 = FUN_11001417('\x01','\0',1,SUB41(*puVar2,0));
  if (DAT_110200f4 == 1) {
    BuildingGroup::UnRecordVehGroup((BuildingGroup *)&DAT_1101c06c,(ScGroup *)&DAT_1101c058);
    ScGroup::SetTargCount((ScGroup *)&DAT_1101c058,1,0,0);
    FUN_11007520((ScGroup *)&DAT_1101c058,&DAT_1101c0c8,0xffffffff);
  }
  DAT_11020150 = FUN_11007e50('\x01','\x01',(ScStub *)&DAT_1101c098,3,FUN_11002f76,0);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c06c,(ScGroup *)&DAT_1101c090,8000);
  iVar1 = TethysGame::GetRand(3);
  if (iVar1 == 0) {
    FUN_11007a30('\x01','\x01',400,FUN_11003fa7,0);
  }
  if (1 < DAT_110200f4) {
    ScGroup::ClearTargCount((ScGroup *)&DAT_1101c064);
    BuildingGroup::UnRecordVehGroup((BuildingGroup *)&DAT_1101c06c,(ScGroup *)&DAT_1101c064);
    CreateBuildingGroup(aSStack_18);
    uStack_4 = 0;
    FUN_11007520((ScGroup *)&DAT_1101c064,aSStack_18 + -0xc,0xffffffff);
    FUN_11001f32((ScStub *)&DAT_1101c064);
    ScGroup::SetTargCount(aSStack_18,2,0,2);
    ScGroup::SetTargCount(aSStack_18,0xf,0,1);
    pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT(aMStack_10,0x25,0x18,0x2a,0x1c);
    BuildingGroup::SetRect((BuildingGroup *)aSStack_18,pMVar3);
    BuildingGroup::operator=((BuildingGroup *)&DAT_1101c064,(BuildingGroup *)aSStack_18);
    FUN_110017a9();
    FUN_110021c8();
    FUN_11001634();
    BuildingGroup::RecordVehReinforceGroup
              ((BuildingGroup *)&DAT_1101c06c,(ScGroup *)&DAT_1101c064,400);
    uStack00000008 = 0xffffffff;
    ScStub::~ScStub((ScStub *)aSStack_18);
  }
  ExceptionList = unaff_retaddr;
  return;
}


// ---- 11002f76 FUN_11002f76  (called by: -)

void FUN_11002f76(void)

{
  int iVar1;
  undefined4 uVar2;
  IUnit aIStack_4 [4];
  
  iVar1 = DAT_110200f4;
  IUnit::IUnit(aIStack_4);
  if (2 - iVar1 < 3) {
    iVar1 = 3 - (2 - iVar1);
    do {
      uVar2 = 7;
      TethysGame::CreateUnit(aIStack_4,5,0x1f,0x61,2,0x3e,7);
      ScGroup::TakeUnit((ScGroup *)&DAT_1101c098,uVar2);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  uVar2 = 6;
  TethysGame::CreateUnit(aIStack_4,5,0x1f,99,2,0x40,6);
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c098,uVar2);
  if (DAT_11020150 != (undefined4 *)0x0) {
    FUN_11006ee0((int)DAT_11020150);
  }
  DAT_11020150 = FUN_11007e50('\x01','\x01',(ScStub *)&DAT_1101c098,3,FUN_11002f76,0);
  return;
}


// ---- 1100301d FUN_1100301d  (called by: -)

void FUN_1100301d(void)

{
  MAP_RECT *pMVar1;
  BuildingGroup *pBVar2;
  undefined4 *puVar3;
  PlayerBuildingEnum *this;
  int iVar4;
  undefined1 uStack00000008;
  uint3 uStack00000009;
  undefined4 uStack00000010;
  Unit *pUVar5;
  BuildingGroup local_40 [4];
  IUnit local_3c [4];
  int local_38;
  IUnit local_34 [4];
  int iStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int local_20;
  int local_1c;
  int local_14;
  int iStack_10;
  undefined4 local_c;
  int local_8;
  undefined4 local_4;
  
  local_4 = 0x11003027;
  FUN_110089b4();
  local_20 = FUN_11007420(2,9,0xffffffff);
  local_38 = FUN_11007300(2,0x15,0xffffffff);
  local_14 = FUN_11007300(2,0x1c,0xffffffff);
  local_1c = FUN_11007300(2,0x36,0xffffffff);
  IUnit::IUnit((IUnit *)&local_c);
  IUnit::IUnit(local_34);
  IUnit::IUnit((IUnit *)&local_8);
  IUnit::IUnit((IUnit *)&local_4);
  IUnit::IUnit(local_3c);
  BuildingGroup::BuildingGroup(local_40);
  _uStack00000008 = (void *)0x0;
  if (DAT_11020150 != 0) {
    FUN_11006ee0(DAT_11020150);
    DAT_11020150 = 0;
  }
  if (DAT_11020160 != 0) {
    FUN_11006ee0(DAT_11020160);
    DAT_11020160 = 0;
  }
  FUN_11007520((ScGroup *)&DAT_1101c098,&DAT_1101c0b0,0xffffffff);
  FightGroup::DoGuardRect((FightGroup *)&DAT_1101c0b0);
  pMVar1 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)&uStack_24,0x30,0x51,0x33,0x58);
  FightGroup::SetRect((FightGroup *)&DAT_1101c0b0,pMVar1);
  pMVar1 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)&uStack_24,0x33,0x4b,0x38,0x57);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_1101c0b0,pMVar1);
  pMVar1 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)&uStack_24,0x1f,0x43,0x33,0x53);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_1101c0b0,pMVar1);
  BuildingGroup::UnRecordVehGroup((BuildingGroup *)&DAT_1101c078,(ScGroup *)&DAT_1101c074);
  pBVar2 = (BuildingGroup *)CreateBuildingGroup(&uStack_24);
  uStack00000008 = 1;
  BuildingGroup::operator=(local_40,pBVar2);
  _uStack00000008 = (void *)((uint)uStack00000009 << 8);
  ScStub::~ScStub((ScStub *)&iStack_30);
  ScGroup::SetTargCount((ScGroup *)local_40,2,0,1);
  ScGroup::SetTargCount((ScGroup *)local_40,0xf,0,1);
  pMVar1 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)&iStack_30,0x26,0x4d,0x2a,0x53);
  BuildingGroup::SetRect(local_40,pMVar1);
  FUN_11007520((ScGroup *)&DAT_1101c074,local_40,0xffffffff);
  FUN_11001f32((ScStub *)&DAT_1101c074);
  BuildingGroup::operator=((BuildingGroup *)&DAT_1101c074,(BuildingGroup *)local_34);
  puVar3 = (undefined4 *)MAP_RECT::MAP_RECT((MAP_RECT *)&uStack_24,0x20,0,0x50,0x7f);
  FUN_110075d0(SUB41(*puVar3,0));
  pUVar5 = (Unit *)&iStack_30;
  this = (PlayerBuildingEnum *)
         PlayerBuildingEnum::PlayerBuildingEnum((PlayerBuildingEnum *)&uStack_24,2,0x15);
  PlayerBuildingEnum::GetNext(this,pUVar5);
  if (((0 < iStack_2c) && (0 < iStack_30)) &&
     (iVar4 = IUnit::GetDamage((IUnit *)&iStack_30), 800 < iVar4)) {
    Unit::DoDeath((Unit *)&iStack_30);
    iStack_2c = 0;
  }
  if ((local_14 == 0) && (iStack_2c == 0)) {
    TethysGame::CreateUnit(&uStack_28,9,0x1f,0x5e,2,0,0);
    Unit::DoSetLights((Unit *)local_3c,1);
    IUnit::Build(local_3c,0x27,0x57);
  }
  if (iStack_10 == 0) {
    if ((0 < DAT_1101c038) && (iVar4 = Unit::IsLive((Unit *)&DAT_1101c038), iVar4 != 0)) {
      ScGroup::TakeUnit((ScGroup *)&DAT_1101c08c,DAT_1101c038);
    }
    TethysGame::CreateUnit(&DAT_1101c038,2,0x20,0x5c,2,0x36,0);
    uStack_24 = 0x24;
    local_20 = 0x50;
    BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c074,(LOCATION *)&uStack_24,0x36,0);
    ScGroup::TakeUnit((ScGroup *)&DAT_1101c074,DAT_1101c038);
  }
  if (local_8 == 0) {
    if ((0 < DAT_1101c034) && (iVar4 = Unit::IsLive((Unit *)&DAT_1101c034), iVar4 != 0)) {
      local_8 = DAT_1101c074;
      FUN_11001f55();
      ScStub::~ScStub((ScStub *)&local_8);
      ScGroup::TakeUnit((ScGroup *)&DAT_1101c08c,DAT_1101c034);
    }
    TethysGame::CreateUnit(&DAT_1101c034,2,0x20,0x60,2,0x1c,0);
    local_8 = 0x24;
    local_4 = 0x4d;
    BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c074,(LOCATION *)&local_8,0x1c,0);
  }
  if ((DAT_1101c034 == 0) || (iVar4 = Unit::IsLive((Unit *)&DAT_1101c034), iVar4 == 0)) {
    TethysGame::CreateUnit(&DAT_1101c034,2,0x20,0x60,2,0,0);
  }
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c074,DAT_1101c034);
  FUN_11007b00('\x01','\x01',2,0x36,0xffffffff,0,4,FUN_11003503,0);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c068,9,0,1);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c06c,(ScGroup *)&DAT_1101c068,0x7fff);
  iVar4 = FUN_11007300(1,0x15,0xffffffff);
  if ((iVar4 < 2) || (iVar4 = FUN_11007300(1,0x36,0xffffffff), iVar4 < 2)) {
    local_c = 0x65;
    local_8 = 6;
    BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c068,(LOCATION *)&local_c,0x15,0);
    local_c = 0x37;
    local_8 = 10;
    BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c064,(LOCATION *)&local_c,0x36,0);
    local_c = 0x65;
    local_8 = 3;
    BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c064,(LOCATION *)&local_c,0x17,0x3d);
    local_c = 0x65;
    local_8 = 9;
    BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c064,(LOCATION *)&local_c,0x17,0x3d);
    uStack_28 = 0x22;
    uStack_24 = 0x1a;
    BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c064,(LOCATION *)&uStack_28,0x3a,0);
    FUN_11008000('\x01','\0',1,(LOCATION)0x65,6,FUN_11002b0d);
  }
  uStack00000010 = 0xffffffff;
  ScStub::~ScStub((ScStub *)&local_38);
  ExceptionList = _uStack00000008;
  return;
}


// ---- 11003503 FUN_11003503  (called by: -)

void FUN_11003503(void)

{
  int iVar1;
  MAP_RECT *pMVar2;
  int iVar3;
  IUnit *this;
  PlayerBuildingEnum *pPVar4;
  int in_stack_00000014;
  undefined4 uVar5;
  undefined4 local_74;
  int local_70;
  undefined4 local_6c;
  int local_68;
  int local_64;
  PlayerBuildingEnum aPStack_58 [4];
  PlayerBuildingEnum local_54 [4];
  PlayerBuildingEnum aPStack_50 [4];
  IUnit local_4c [4];
  MAP_RECT aMStack_48 [20];
  LocationEnumerator local_34 [48];
  void *pvStack_4;
  
  pvStack_4 = (void *)0x1100350d;
  FUN_110089b4();
  if (*(int *)(in_stack_00000014 + 8) == 1) {
    ScGroup::TakeUnit((ScGroup *)&DAT_1101c074);
  }
  else {
    iVar3 = 2;
    local_64 = FUN_11007420(2,1,0xffffffff);
    local_70 = FUN_11007300(2,0x3a,0xffffffff);
    iVar1 = FUN_11007300(2,0x2f,0xffffffff);
    IUnit::IUnit((IUnit *)&local_74);
    this = local_4c;
    do {
      IUnit::IUnit(this);
      this = this + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    PlayerBuildingEnum::PlayerBuildingEnum(local_54,2,0x3a);
    local_6c = 0x24;
    local_68 = 0x5f;
    LocationEnumerator::LocationEnumerator(local_34,(LOCATION *)&local_6c);
    if (iVar1 == 0) {
      if ((0 < DAT_1101c03c) && (iVar3 = Unit::IsLive((Unit *)&DAT_1101c03c), iVar3 != 0)) {
        local_6c = DAT_1101c074;
        FUN_11001f55();
        ScStub::~ScStub((ScStub *)&local_6c);
        ScGroup::TakeUnit((ScGroup *)&DAT_1101c08c);
      }
      TethysGame::CreateUnit(&DAT_1101c03c,2,0x20,0x5f,2);
      local_6c = 0x29;
      local_68 = 0x4c;
      BuildingGroup::RecordBuilding((BuildingGroup *)&DAT_1101c074,(LOCATION *)&local_6c,0x2f,0);
    }
    if ((DAT_1101c03c == 0) || (iVar3 = Unit::IsLive((Unit *)&DAT_1101c03c), iVar3 == 0)) {
      TethysGame::CreateUnit(&DAT_1101c03c,2,0x20,0x5f,2);
    }
    ScGroup::TakeUnit((ScGroup *)&DAT_1101c074);
    if (0 < local_74) {
      while (iVar3 = PlayerBuildingEnum::GetNext(aPStack_58,(Unit *)(aPStack_58 + -0x20)),
            iVar3 != 0) {
        iVar3 = IUnit::GetDamage((IUnit *)(aPStack_58 + -0x20));
        if (800 < iVar3) {
          local_74 = local_74 + -1;
        }
      }
    }
    if (local_74 == 0) {
      if ((0 < DAT_1101c040) && (iVar3 = Unit::IsLive((Unit *)&DAT_1101c040), iVar3 != 0)) {
        ScGroup::TakeUnit((ScGroup *)&DAT_1101c08c);
      }
      uVar5 = 0;
      TethysGame::CreateUnit(&DAT_1101c040,2,0x20,0x60,2,0x3a);
      BuildingGroup::RecordBuilding
                ((BuildingGroup *)&DAT_1101c074,(LOCATION *)(aPStack_58 + -0x2c),0x3a,0);
      iVar3 = LocationEnumerator::GetNext
                        ((LocationEnumerator *)local_4c,(Unit *)(aPStack_58 + -0x34));
      if (iVar3 == 0) {
        IUnit::Build((IUnit *)&DAT_1101c040,0x24,0x5f);
        ScGroup::TakeUnit((ScGroup *)&DAT_1101c074,DAT_1101c040);
      }
      else {
        IUnit::Dismantle((IUnit *)&DAT_1101c040,uVar5);
        FUN_11007b00('\x01','\x01',2,0x3a,0xffffffff,0,0,FUN_11003503,1);
      }
    }
    iVar3 = local_68;
    if (local_68 < 2) {
      local_74 = local_68 + 0x5c;
      local_68 = 0x20;
      pPVar4 = local_54 + iVar3 * 4 + 4;
      do {
        TethysGame::CreateUnit(pPVar4,1,local_68,local_74,2,0);
        ScGroup::TakeUnit((ScGroup *)&DAT_1101c060,*(undefined4 *)pPVar4);
        local_74 = local_74 + 1;
        pPVar4 = pPVar4 + 4;
      } while (local_74 < 0x5e);
    }
    FUN_11002be0();
    ScGroup::SetTargCount((ScGroup *)&DAT_1101c060,1,0,3);
    local_74 = 2;
    do {
      uVar5 = 7;
      TethysGame::CreateUnit(aPStack_58 + -0x20,5,0x1f,0x5c,2,0x3e);
      ScGroup::TakeUnit((ScGroup *)&DAT_1101c0b4,uVar5);
      local_74 = local_74 + -1;
    } while (local_74 != 0);
    FightGroup::DoGuardRect((FightGroup *)&DAT_1101c0b4);
    pMVar2 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)&local_68,0x2b,0x4c,0x2f,0x4e);
    FightGroup::SetRect((FightGroup *)&DAT_1101c0b4,pMVar2);
    pMVar2 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)&local_68,0x22,0x46,0x2f,0x4c);
    FightGroup::AddGuardedRect((FightGroup *)&DAT_1101c0b4,pMVar2);
    pMVar2 = (MAP_RECT *)MAP_RECT::MAP_RECT(aMStack_48,0x33,0x42,0x35,0x44);
    FightGroup::AddGuardedRect((FightGroup *)&DAT_1101c0b4,pMVar2);
    FUN_11007870('\x01','\x01',2,0x2f,0,4,FUN_11003880,0);
  }
  ExceptionList = pvStack_4;
  return;
}


// ---- 11003880 FUN_11003880  (called by: -)

void FUN_11003880(void)

{
  PlayerBuildingEnum *this;
  MAP_RECT *pMVar1;
  int iVar2;
  Unit *pUVar3;
  undefined4 local_18;
  void *local_14;
  PlayerBuildingEnum local_10 [8];
  void *pvStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1100388a;
  FUN_110089b4();
  IUnit::IUnit((IUnit *)&local_18);
  IUnit::IUnit((IUnit *)&local_14);
  pUVar3 = (Unit *)&local_18;
  this = (PlayerBuildingEnum *)PlayerBuildingEnum::PlayerBuildingEnum(local_10,2,0x2f);
  PlayerBuildingEnum::GetNext(this,pUVar3);
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c074,local_18);
  FUN_110018d6();
  FUN_11001634();
  FUN_110017a9();
  FightGroup::ClearGuarderdRects((FightGroup *)&DAT_1101c0b0);
  FightGroup::DoGuardRect((FightGroup *)&DAT_1101c0b0);
  pMVar1 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)&local_14,0x22,0x4b,0x2c,0x53);
  FightGroup::SetRect((FightGroup *)&DAT_1101c0b0,pMVar1);
  pMVar1 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)&local_14,0x20,0x46,0x2e,0x58);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_1101c0b0,pMVar1);
  pMVar1 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)&local_14,0x2a,0x41,0x31,0x46);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_1101c0b0,pMVar1);
  pMVar1 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)&local_14,0x20,0x59,0x27,100);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_1101c0b0,pMVar1);
  FightGroup::ClearGuarderdRects((FightGroup *)&DAT_1101c0b4);
  FightGroup::DoGuardRect((FightGroup *)&DAT_1101c0b4);
  pMVar1 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)&local_14,0x2d,0x44,0x32,0x48);
  FightGroup::SetRect((FightGroup *)&DAT_1101c0b4,pMVar1);
  pMVar1 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)&local_14,0x22,0x46,0x2f,0x54);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_1101c0b4,pMVar1);
  FightGroup::ClearGuarderdRects((FightGroup *)&DAT_1101c0b8);
  FightGroup::DoGuardRect((FightGroup *)&DAT_1101c0b8);
  pMVar1 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)&local_14,0x20,0x44,0x23,0x4a);
  FightGroup::SetRect((FightGroup *)&DAT_1101c0b8,pMVar1);
  pMVar1 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)&local_14,0x20,0x44,0x2e,0x53);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_1101c0b8,pMVar1);
  iVar2 = Unit::IsLive((Unit *)&DAT_1101c038);
  if (iVar2 != 0) {
    local_14 = DAT_1101c074;
    FUN_11001f55();
    ScStub::~ScStub((ScStub *)&local_14);
    ScGroup::TakeUnit((ScGroup *)&DAT_1101c08c,DAT_1101c038);
  }
  iVar2 = Unit::IsLive((Unit *)&DAT_1101c040);
  if (iVar2 != 0) {
    local_14 = DAT_1101c074;
    FUN_11001f55();
    ScStub::~ScStub((ScStub *)&local_14);
    ScGroup::TakeUnit((ScGroup *)&DAT_1101c08c,DAT_1101c040);
  }
  iVar2 = TethysGame::Tick();
  if (50000 < iVar2) {
    iVar2 = FUN_11007420(2,2,0);
    if (iVar2 < 2) {
      TethysGame::CreateUnit(&local_18,2,0x20,0x5e,2,0,0);
    }
  }
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c074,local_18);
  if (DAT_11020164 != (undefined4 *)0x0) {
    FUN_11006ee0((int)DAT_11020164);
  }
  DAT_11020164 = FUN_11007870('\x01','\x01',2,0x30,0,4,FUN_11003b26,0);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c054,1,0,5);
  ExceptionList = pvStack_8;
  return;
}


// ---- 11003b26 FUN_11003b26  (called by: -)

void FUN_11003b26(void)

{
  PlayerBuildingEnum *this;
  Unit *pUVar1;
  PlayerBuildingEnum local_10 [8];
  undefined4 local_8;
  
  IUnit::IUnit((IUnit *)&local_8);
  if (DAT_11020164 != 0) {
    FUN_11006ee0(DAT_11020164);
  }
  DAT_11020164 = 0;
  pUVar1 = (Unit *)&local_8;
  this = (PlayerBuildingEnum *)PlayerBuildingEnum::PlayerBuildingEnum(local_10,2,0x30);
  PlayerBuildingEnum::GetNext(this,pUVar1);
  ScGroup::TakeUnit((ScGroup *)&DAT_1101c078,local_8);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c078,(ScGroup *)&DAT_1101c074,200);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c078,(ScGroup *)&DAT_1101c0b0,500);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c078,(ScGroup *)&DAT_1101c0b4,0x4b0);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c078,(ScGroup *)&DAT_1101c0b8,800);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c078,(ScGroup *)&DAT_1101c060,300);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0b0,5,0x3e,2);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0b4,5,0x3e,4);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0b8,5,0x3e,2);
  if (DAT_11020168 != (undefined4 *)0x0) {
    FUN_11006ee0((int)DAT_11020168);
  }
  DAT_11020168 = FUN_11007870('\x01','\x01',2,0x32,0,4,FUN_11003c21,0);
  return;
}


// ---- 11003c21 FUN_11003c21  (called by: -)

void FUN_11003c21(void)

{
  if (DAT_11020168 != 0) {
    FUN_11006ee0(DAT_11020168);
  }
  DAT_11020168 = 0;
  FUN_11001634();
  FUN_11001634();
  FUN_11001634();
  BuildingGroup::UnRecordVehGroup((BuildingGroup *)&DAT_1101c06c,(ScGroup *)&DAT_1101c0a8);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c06c,(ScGroup *)&DAT_1101c0a8,500);
  FUN_11007a30('\x01','\x01',0x1068,FUN_11003cd5,0);
  FUN_1100247b();
  return;
}


// ---- 11003cd5 FUN_11003cd5  (called by: -)

void FUN_11003cd5(void)

{
  MAP_RECT *pMVar1;
  MAP_RECT aMStack_10 [16];
  
  _Player::MarkResearchComplete((_Player *)&DAT_11020118,0x15e2);
  ScGroup::ClearTargCount((ScGroup *)&DAT_1101c0b0);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0b0,5,0x3e,2);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0b0,5,0x40,1);
  ScGroup::ClearTargCount((ScGroup *)&DAT_1101c0b4);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0b4,5,0x3e,3);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0b4,5,0x40,2);
  ScGroup::ClearTargCount((ScGroup *)&DAT_1101c0b8);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0b8,5,0x3e,2);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0b8,5,0x40,1);
  FightGroup::DoGuardRect((FightGroup *)&DAT_1101c0bc);
  pMVar1 = (MAP_RECT *)MAP_RECT::MAP_RECT(aMStack_10,0x2a,0x54,0x2f,0x58);
  FightGroup::SetRect((FightGroup *)&DAT_1101c0bc,pMVar1);
  pMVar1 = (MAP_RECT *)MAP_RECT::MAP_RECT(aMStack_10,0x23,0x4a,0x38,0x57);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_1101c0bc,pMVar1);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0bc,5,0x3e,2);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0bc,5,0x40,1);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c078,(ScGroup *)&DAT_1101c074,200);
  FUN_110018d6();
  return;
}


// ---- 11003dd5 FUN_11003dd5  (called by: -)

void FUN_11003dd5(void)

{
  int iVar1;
  GroupEnumerator local_c [4];
  IUnit local_8 [4];
  
  IUnit::IUnit(local_8);
  GroupEnumerator::GroupEnumerator(local_c,(ScGroup *)&DAT_1101c08c);
  while (iVar1 = GroupEnumerator::GetNext(local_c,(Unit *)local_8), iVar1 != 0) {
    iVar1 = Unit::Location((Unit *)local_8);
    if ((99 < *(int *)(iVar1 + 4)) && (*(int *)(iVar1 + 4) < 0x67)) {
      IUnit::Poof(local_8);
      Unit::DoDeath((Unit *)local_8);
    }
  }
  return;
}


// ---- 11003e3c FUN_11003e3c  (called by: FUN_110055fe@110055fe)

void __cdecl FUN_11003e3c(PlayerBuildingEnum param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  PlayerBuildingEnum *this;
  
  iVar1 = ScStub::IsInitialized((ScStub *)&DAT_1101c090);
  if (iVar1 != 0) {
    iVar1 = ScGroup::TotalUnitCount((ScGroup *)&DAT_1101c090);
    iVar2 = FUN_11007300(2,0x17,0xffffffff);
    iVar3 = FUN_11007420(2,5,0xffffffff);
    if (iVar2 + iVar3 < iVar1) {
      DAT_110200fc = iVar1;
    }
    else {
      if (iVar1 <= DAT_110200fc) {
        return;
      }
      DAT_110200fc = DAT_110200fc + 1;
    }
    if (DAT_110200fc < 5) {
      DAT_110200fc = 5;
    }
    DAT_110200f8 = DAT_110200f8 + 1;
    if (DAT_110200f8 < 2) {
      FUN_11007a30('\x01','\x01',900,FUN_11003fa7,0);
    }
    FUN_11007520((ScGroup *)&DAT_1101c090,&DAT_1101c094,0xffffffff);
    this = (PlayerBuildingEnum *)PlayerBuildingEnum::PlayerBuildingEnum(&param_1,2,0x15);
    iVar1 = PlayerBuildingEnum::GetNext(this,(Unit *)register0x00000010);
    if (iVar1 != 0) {
      FUN_11007b00('\x01','\x01',2,0x15,0xffffffff,0,0,FUN_110043c0,0);
    }
    FUN_11007b00('\x01','\x01',2,5,0xffffffff,0,0,FUN_11004240,0);
    iVar1 = TethysGame::Tick();
    if ((50000 < iVar1) || (9 < DAT_110200fc)) {
      DAT_1101c0ea = 0;
      FUN_11007a30('\x01','\x01',2000,FUN_1100301d,0);
      ScGroup::ClearTargCount((ScGroup *)&DAT_1101c090);
      ScGroup::SetTargCount((ScGroup *)&DAT_1101c090,0xb,0,2);
      FUN_11001121('\x01','\x01',(ScStub *)&DAT_1101c090,2,0,FUN_11004564,0);
    }
  }
  return;
}


// ---- 11003fa7 FUN_11003fa7  (called by: -)

void FUN_11003fa7(void)

{
  undefined4 *puVar1;
  MAP_RECT aMStack_10 [16];
  
  puVar1 = (undefined4 *)MAP_RECT::MAP_RECT(aMStack_10,0x20,0x3d,0x42,0x59);
  FUN_110075d0(SUB41(*puVar1,0));
  return;
}


// ---- 11003fe2 FUN_11003fe2  (called by: FUN_110040e2@110040e2)

void FUN_11003fe2(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  code *pcVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  MAP_RECT local_18 [8];
  undefined1 local_10 [8];
  Truck_Cargo local_8;
  
  if ((DAT_11016000 & 1) == 0) {
    DAT_11016000 = DAT_11016000 | 1;
    DAT_11020148 = 0;
    DAT_1102014c = 0;
    FUN_1100943d(0x110040e1);
  }
  if (0 < DAT_1101c048) {
    iVar1 = Unit::IsLive((Unit *)&DAT_1101c048);
    if ((iVar1 != 0) && (0 < DAT_1101c04c)) {
      iVar1 = Unit::IsLive((Unit *)&DAT_1101c04c);
      if (iVar1 != 0) {
        IUnit::GetTruckCargo((IUnit *)&DAT_1101c048,&local_8);
        pcVar4 = Location_exref;
        puVar6 = local_10;
        piVar2 = (int *)Unit::Location((Unit *)&DAT_1101c048);
        if (DAT_11020148 == *piVar2) {
          puVar5 = local_10;
          iVar1 = Unit::Location((Unit *)&DAT_1101c048);
          if ((DAT_1102014c == *(int *)(iVar1 + 4)) && (local_8 != 6)) {
            iVar1 = DAT_1101c04c;
            puVar3 = (undefined4 *)MAP_RECT::MAP_RECT(local_18,0x20,0x40,0x36,0x60);
            IUnit::Salvage((IUnit *)&DAT_1101c048,*puVar3,puVar3[1],puVar3[2],puVar3[3],iVar1,puVar5
                           ,puVar6);
            pcVar4 = Location_exref;
          }
        }
        piVar2 = (int *)(*pcVar4)(local_10);
        DAT_11020148 = *piVar2;
        iVar1 = (*pcVar4)(local_10);
        DAT_1102014c = *(int *)(iVar1 + 4);
      }
    }
  }
  return;
}


// ---- 110040e1 FUN_110040e1  (called by: -)

void FUN_110040e1(void)

{
  return;
}


// ---- 110040e2 FUN_110040e2  (called by: -)

void FUN_110040e2(void)

{
  PlayerBuildingEnum *this;
  int iVar1;
  map_id mVar2;
  int unaff_EBP;
  int *piVar3;
  
  FUN_110089b4();
  piVar3 = &DAT_1101c04c;
  this = (PlayerBuildingEnum *)
         PlayerBuildingEnum::PlayerBuildingEnum((PlayerBuildingEnum *)(unaff_EBP + -0x24),1,0x39);
  PlayerBuildingEnum::GetNext(this,(Unit *)piVar3);
  if ((0 < DAT_1101c04c) && (iVar1 = Unit::IsLive((Unit *)&DAT_1101c04c), iVar1 != 0)) {
    if (0 < DAT_1101c048) {
LAB_11004206:
      *(byte *)(DAT_1102015c + 6) = *(byte *)(DAT_1102015c + 6) | 1;
      FUN_11003fe2();
      goto LAB_11004231;
    }
    IUnit::IUnit((IUnit *)(unaff_EBP + -0x10));
    GroupEnumerator::GroupEnumerator
              ((GroupEnumerator *)(unaff_EBP + -0x14),(ScGroup *)&DAT_1101c054);
    iVar1 = GroupEnumerator::GetNext
                      ((GroupEnumerator *)(unaff_EBP + -0x14),(Unit *)(unaff_EBP + -0x10));
    while (iVar1 != 0) {
      mVar2 = Unit::GetType((Unit *)(unaff_EBP + -0x10));
      if ((((mVar2 == 1) &&
           (iVar1 = IUnit::GetTruckCargo
                              ((IUnit *)(unaff_EBP + -0x10),(Truck_Cargo *)(unaff_EBP + -0x1c)),
           iVar1 == 0)) && (iVar1 = Unit::IsLive((Unit *)(unaff_EBP + -0x10)), iVar1 != 0)) &&
         ((piVar3 = (int *)Unit::Location((Unit *)(unaff_EBP + -0x10)), *piVar3 != 0x4f ||
          (iVar1 = Unit::Location((Unit *)(unaff_EBP + -0x10)), *(int *)(iVar1 + 4) != 0x1a)))) {
        *(undefined4 *)(unaff_EBP + -0x18) = DAT_1101c054;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        FUN_11001f55();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        ScStub::~ScStub((ScStub *)(unaff_EBP + -0x18));
        Unit::operator=((Unit *)&DAT_1101c048,(Unit *)(unaff_EBP + -0x10));
        Unit::DoStop((Unit *)&DAT_1101c048);
        goto LAB_11004206;
      }
      iVar1 = GroupEnumerator::GetNext
                        ((GroupEnumerator *)(unaff_EBP + -0x14),(Unit *)(unaff_EBP + -0x10));
    }
  }
  FUN_11007a30('\x01','\x01',500,FUN_110040e2,0);
LAB_11004231:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11004240 FUN_11004240  (called by: -)

void FUN_11004240(void)

{
  PlayerBuildingEnum *this;
  int iVar1;
  Unit aUStack_24 [4];
  Unit *pUVar2;
  
  pUVar2 = aUStack_24 + 0x1c;
  this = (PlayerBuildingEnum *)
         PlayerBuildingEnum::PlayerBuildingEnum((PlayerBuildingEnum *)(aUStack_24 + 0x14),2,0x17);
  iVar1 = PlayerBuildingEnum::GetNext(this,pUVar2);
  if (iVar1 == 0) {
    BuildingGroup::UnRecordVehGroup((BuildingGroup *)&DAT_1101c06c,(ScGroup *)&DAT_1101c090);
    FUN_11007520((ScGroup *)&DAT_1101c090,&DAT_1101c094,0xffffffff);
    FUN_110017a9();
    FUN_11007a30('\x01','\x01',500,FUN_110040e2,0);
  }
  if (DAT_11020158 == (undefined4 *)0x0) {
    DAT_11020158 = FUN_110079c0('\x01','\x01',3000,5000,FUN_11002cfe,0);
  }
  return;
}


// ---- 110042e0 FUN_110042e0  (called by: FUN_110055fe@110055fe)

void FUN_110042e0(void)

{
  int iVar1;
  MAP_RECT *pMVar2;
  InRectEnumerator local_54 [52];
  MAP_RECT local_20 [16];
  GroupEnumerator local_10 [4];
  IUnit local_c [4];
  undefined4 local_8;
  
  iVar1 = ScGroup::TotalUnitCount((ScGroup *)&DAT_1101c0c4);
  if (iVar1 == 0) {
    MAP_RECT::MAP_RECT(local_20,0x20,0x3c,0x37,100);
    FUN_11002c69();
  }
  IUnit::IUnit((IUnit *)&local_8);
  IUnit::IUnit(local_c);
  GroupEnumerator::GroupEnumerator(local_10,(ScGroup *)&DAT_1101c0c4);
  pMVar2 = (MAP_RECT *)MAP_RECT::MAP_RECT(local_20,0x20,0x3c,0x37,100);
  InRectEnumerator::InRectEnumerator(local_54,pMVar2);
  do {
    iVar1 = GroupEnumerator::GetNext(local_10,(Unit *)&local_8);
    if (iVar1 == 0) {
      DAT_1101c0e9 = 0;
      return;
    }
    iVar1 = Unit::IsLive((Unit *)&local_8);
  } while (iVar1 == 0);
  while (iVar1 = InRectEnumerator::GetNext(local_54,(Unit *)local_c), iVar1 != 0) {
    iVar1 = Unit::OwnerID((Unit *)local_c);
    if (iVar1 == 1) {
      Unit::DoAttack((Unit *)local_c,local_8);
    }
  }
  return;
}


// ---- 110043c0 FUN_110043c0  (called by: -)

void FUN_110043c0(void)

{
  int iVar1;
  
  iVar1 = FUN_11007420(2,5,0xffffffff);
  if (iVar1 < 1) {
    FUN_11007520((ScGroup *)&DAT_1101c090,&DAT_1101c094,0xffffffff);
    BuildingGroup::UnRecordVehGroup((BuildingGroup *)&DAT_1101c06c,(ScGroup *)&DAT_1101c090);
    return;
  }
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c06c,(ScGroup *)&DAT_1101c090,8000);
  return;
}


// ---- 1100440c FUN_1100440c  (called by: -)

void FUN_1100440c(void)

{
  int iVar1;
  MAP_RECT *pMVar2;
  IUnit aIStack_8 [4];
  MAP_RECT aMStack_4 [4];
  
  FUN_11007520((ScGroup *)&DAT_1101c090,&DAT_1101c0ac,0xb);
  if ((DAT_1101c002 == '\0') &&
     (iVar1 = _Player::HasTechnology((_Player *)&DAT_11020128,0xd50), iVar1 == 0)) {
    FUN_11001121('\x01','\x01',(ScStub *)&DAT_1101c090,2,2,FUN_11004564,0);
    return;
  }
  IUnit::IUnit(aIStack_8);
  DAT_11020170 = DAT_11020170 + 1;
  if (3 < DAT_11020170) {
    FightGroup::ClearPatrolMode((FightGroup *)&DAT_1101c0ac);
    FightGroup::SetAttackType((FightGroup *)&DAT_1101c0ac,0x17);
    pMVar2 = (MAP_RECT *)MAP_RECT::MAP_RECT(aMStack_4,0x6e,0x28,0x8c,0x50);
    FightGroup::SetRect((FightGroup *)&DAT_1101c0ac,pMVar2);
  }
  if (5 < DAT_11020170) {
    DAT_11020170 = 5;
  }
  ScGroup::ClearTargCount((ScGroup *)&DAT_1101c090);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c090,5,0x3f,0);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c090,5,0x3d,0);
  iVar1 = DAT_11020170;
  if (3 < DAT_11020170) {
    iVar1 = _Player::HasTechnology((_Player *)&DAT_11020128,0xf0b);
    if (iVar1 == 0) {
      DAT_11020170 = 3;
    }
    else {
      ScGroup::SetTargCount((ScGroup *)&DAT_1101c090,5,0x3f,DAT_11020170 + -3);
    }
    iVar1 = DAT_11020170;
    if (3 < DAT_11020170) {
      iVar1 = 3;
    }
  }
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c090,5,0x3d,iVar1);
  FUN_11007520((ScGroup *)&DAT_1101c090,&DAT_1101c0ac,0xffffffff);
  FUN_11001121('\x01','\x01',(ScStub *)&DAT_1101c090,(char)DAT_11020170,2,FUN_11004564,0);
  return;
}


// ---- 11004564 FUN_11004564  (called by: -)

void FUN_11004564(void)

{
  FUN_110079c0('\x01','\x01',(3 - DAT_1101c004) * 1000,(3 - DAT_1101c004) * 2000,FUN_1100440c,0);
  return;
}


// ---- 1100458c StatusProc  (called by: -)

undefined4 StatusProc(void)

{
                    /* 0x458c  12  StatusProc */
  return 0;
}


// ---- 1100458f NoResponseToTrigger  (called by: -)

void NoResponseToTrigger(void)

{
                    /* 0x458f  11  NoResponseToTrigger */
  return;
}


// ---- 11004590 FUN_11004590  (called by: -)

void FUN_11004590(void)

{
  FUN_11008273(0x1b);
  return;
}


// ---- 11004599 FUN_11004599  (called by: -)

void FUN_11004599(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  iVar1 = TethysGame::GetRand(100);
  iVar2 = TethysGame::GetRand(0x5a);
  TethysGame::SetEarthquake(iVar2 + 0x39,iVar1 + 1,iVar3);
  return;
}


// ---- 110045c0 FUN_110045c0  (called by: -)

void FUN_110045c0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  iVar1 = TethysGame::GetRand(0x50);
  iVar2 = TethysGame::GetRand(0x3c);
  TethysGame::SetMeteor(iVar2 + 0x60,iVar1 + 0x28,iVar3);
  return;
}


// ---- 110045e9 FUN_110045e9  (called by: -)

void FUN_110045e9(void)

{
  GameMap::SetTile(0x450,0x5c,0x61,0x5c);
  GameMap::SetTile(0x45b,0x5c,0x62,0x5c);
  GameMap::SetTile(0x466,0x5d,0x61,0x5d);
  GameMap::SetTile(0x471,0x5d,0x62,0x5d);
  TethysGame::SetEruption(0x61,0x5d,0x50);
  FUN_11007a30('\x01','\x01',(9 - DAT_1101c004) * 2000,FUN_110046ff,0);
  FUN_11007a30('\x01','\x01',0x3b6,FUN_11004590,0);
  return;
}


// ---- 11004673 FUN_11004673  (called by: FUN_110049e2@110049e2)

void __fastcall FUN_11004673(int param_1)

{
  int iVar1;
  undefined4 extraout_EDX;
  int iVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  iVar3 = 1;
  local_c = param_1;
  local_8 = param_1;
  do {
    iVar2 = 0x1f;
    do {
      iVar1 = GameMap::GetTile();
      if (((0x22e < iVar1) && (iVar1 < 0x25f)) || ((0x1d6 < iVar1 && (iVar1 < 0x1f9)))) {
        GameMap::SetLavaPossible(1,extraout_EDX,iVar2,iVar3);
      }
      if ((0x1c6 < iVar1) && (iVar1 < 0x1d7)) {
        DAT_110200f0 = DAT_110200f0 + 1;
        local_c = iVar2;
        local_8 = iVar3;
        LOCATION::operator=((LOCATION *)(&DAT_1101c0f0 + DAT_110200f0 * 2),(LOCATION *)&local_c);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0xa0);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x81);
  return;
}


// ---- 110046ff FUN_110046ff  (called by: -)

void __fastcall FUN_110046ff(undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_EDX;
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  if (-1 < DAT_110200f0) {
    puVar1 = &DAT_1101c0f0;
    do {
      GameMap::SetLavaPossible(1,param_2,*puVar1,puVar1[1]);
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 2;
      param_2 = extraout_EDX;
    } while (iVar2 <= DAT_110200f0);
  }
  return;
}


// ---- 1100472d FUN_1100472d  (called by: InitMap@1100487d)

void __cdecl FUN_1100472d(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar3 = 0;
  local_18 = 0;
  local_30 = 0;
  local_2c = 0;
  local_8 = 0;
  local_10 = 0;
  local_c = 0;
  local_14 = 0;
  local_24 = 0;
  local_1c = 0;
  local_28 = 0;
  local_20 = 0;
  if (0 < *param_1) {
    do {
      piVar1 = (int *)FUN_110069cf(param_1,iVar3);
      if (piVar1[5] < 1) {
        iVar2 = *piVar1;
        if (iVar2 == 1) {
          if (piVar1[2] == 1) {
            local_30 = local_30 + 1;
            if (local_30 <= (int)((DAT_1101c002 == '\0') + 1)) {
              piVar1[1] = 200;
              goto LAB_1100483d;
            }
          }
          else if (piVar1[2] == 4) {
            local_2c = local_2c + 1;
            iVar2 = 4 - DAT_1101c004;
            bVar6 = SBORROW4(local_2c,iVar2);
            bVar5 = local_2c - iVar2 < 0;
            bVar4 = local_2c == iVar2;
            goto LAB_11004830;
          }
        }
        else {
          if (iVar2 == 2) {
            iVar2 = piVar1[2];
            if (iVar2 == 0x1c) {
              iVar2 = local_28 + 1;
              bVar6 = SBORROW4(iVar2,1);
              bVar5 = local_28 < 0;
              bVar4 = iVar2 == 1;
              local_28 = iVar2;
            }
            else if (iVar2 == 0x2f) {
              iVar2 = local_24 + 1;
              bVar6 = SBORROW4(iVar2,1);
              bVar5 = local_24 < 0;
              bVar4 = iVar2 == 1;
              local_24 = iVar2;
            }
            else if (iVar2 == 0x36) {
              iVar2 = local_20 + 1;
              bVar6 = SBORROW4(iVar2,1);
              bVar5 = local_20 < 0;
              bVar4 = iVar2 == 1;
              local_20 = iVar2;
            }
            else {
              if (iVar2 != 0x3a) goto LAB_11004832;
              iVar2 = local_1c + 1;
              bVar6 = SBORROW4(iVar2,1);
              bVar5 = local_1c < 0;
              bVar4 = iVar2 == 1;
              local_1c = iVar2;
            }
          }
          else if (iVar2 == 5) {
            local_18 = local_18 + 1;
            iVar2 = 4 - DAT_1101c008;
            bVar6 = SBORROW4(local_18,iVar2);
            bVar5 = local_18 - iVar2 < 0;
            bVar4 = local_18 == iVar2;
          }
          else if (iVar2 == 8) {
            iVar2 = local_14 + 1;
            bVar6 = SBORROW4(iVar2,1);
            bVar5 = local_14 < 0;
            bVar4 = iVar2 == 1;
            local_14 = iVar2;
          }
          else if (iVar2 == 9) {
            local_10 = local_10 + 1;
            iVar2 = (DAT_1101c002 == '\0') + 1;
            bVar6 = SBORROW4(local_10,iVar2);
            bVar5 = local_10 - iVar2 < 0;
            bVar4 = local_10 == iVar2;
          }
          else if (iVar2 == 0xc) {
            iVar2 = local_c + 1;
            bVar6 = SBORROW4(iVar2,1);
            bVar5 = local_c < 0;
            bVar4 = iVar2 == 1;
            local_c = iVar2;
          }
          else {
            if (iVar2 != 0xf) goto LAB_1100483d;
            iVar2 = local_8 + 1;
            bVar6 = SBORROW4(iVar2,1);
            bVar5 = local_8 < 0;
            bVar4 = iVar2 == 1;
            local_8 = iVar2;
          }
LAB_11004830:
          if (bVar4 || bVar6 != bVar5) goto LAB_1100483d;
        }
LAB_11004832:
        FUN_110069dc(param_1,iVar3);
        iVar3 = iVar3 + -1;
      }
LAB_1100483d:
      iVar3 = iVar3 + 1;
    } while (iVar3 < *param_1);
  }
  return;
}


// ---- 11004868 FUN_11004868  (called by: InitMap@1100487d)

bool FUN_11004868(void)

{
  int iVar1;
  
  iVar1 = _Player::Difficulty((_Player *)&DAT_11020128);
  return DAT_11016068 != iVar1;
}


// ---- 1100487d InitMap  (called by: InitProc@11005892)

char InitMap(void)

{
  bool bVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 extraout_ECX;
  char *local_24 [3];
  IUnit local_18 [4];
  int local_14;
  int local_10;
  int *local_c;
  char local_5;
  
                    /* 0x487d  7  InitMap */
  local_c = operator_new(8);
  if (local_c == (int *)0x0) {
    local_c = (int *)0x0;
  }
  else {
    FUN_11006917(local_c);
  }
  local_10 = 0;
  local_14 = 0;
  IUnit::IUnit(local_18);
  FUN_1100660f((uint3)extraout_ECX,s_Q02_mis_11014f74);
  bVar1 = FUN_11004868();
  if (bVar1) {
    local_24[0] = &DAT_11014f6c;
    DAT_1101c000 = DAT_11016068 == 0;
    local_24[1] = s_medium_11014f64;
    DAT_1101c008 = DAT_11016068 * 2;
    local_24[2] = &DAT_11014f5c;
    DAT_1101c001 = DAT_11016068 == 1;
    DAT_1101c002 = DAT_11016068 == 2;
    DAT_1101c004 = DAT_11016068;
    scr_snprintf(&DAT_110198d4,0x50,&DAT_11014f2c,local_24[DAT_11016068]);
    (*DAT_1101531c)(s_Renegades_11014f20,0);
  }
  uVar2 = FUN_110066bc(s_Q02_mis_11014f74,local_c);
  local_5 = (char)uVar2;
  if (local_5 != '\0') {
    FUN_1100472d(local_c);
    piVar3 = FUN_1100684b(0,local_c,-1,&local_14,-1);
    while (piVar3 != (int *)0x0) {
      if (piVar3[5] == 0) {
        iVar4 = local_10 / 2;
        local_10 = local_10 + 1;
        FUN_1100678e(piVar3,0,0x9d - iVar4,0x7d - local_10 % 2,'\x01','\x01');
      }
      piVar3 = FUN_1100684b(0,local_c,-1,&local_14,-1);
    }
    FUN_11006a05(local_c);
  }
  if (local_c != (int *)0x0) {
    thunk_FUN_110069b2(local_c);
    FUN_1100947e(local_c);
  }
  return local_5;
}


// ---- 110049e2 FUN_110049e2  (called by: InitProc@11005892)

void __fastcall FUN_110049e2(int param_1)

{
  FUN_11004673(param_1);
  GameMap::InitialSetTile(0x447,0x5c,0x61,0x5c);
  GameMap::InitialSetTile(0x453,0x5c,0x62,0x5c);
  GameMap::InitialSetTile(0x45e,0x5d,0x61,0x5d);
  GameMap::InitialSetTile(0x469,0x5d,0x62,0x5d);
  GameMap::SetLavaPossible(1,0x5d,0x61,0x5d);
  GameMap::SetLavaPossible(1,0x5d,0x60,0x5d);
  GameMap::SetLavaPossible(1,0x5e,0x61,0x5e);
  GameMap::SetLavaPossible(1,0x5e,0x60,0x5e);
  return;
}


// ---- 11004a66 FUN_11004a66  (called by: InitProc@11005892)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_11004a66(void)

{
  MiningGroup *pMVar1;
  FightGroup *pFVar2;
  MAP_RECT *pMVar3;
  BuildingGroup *pBVar4;
  undefined4 *puVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uStack_184;
  void *pvStack_180;
  undefined4 uStack_174;
  void *pvStack_168;
  void *pvStack_15c;
  undefined4 uStack_150;
  ScStub aSStack_6e [2];
  undefined4 uStack_6c;
  undefined4 uStack_60;
  undefined4 uStack_54;
  undefined4 uStack_48;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined1 local_24 [8];
  undefined4 uStack_1c;
  undefined4 uStack_10;
  undefined4 uStack_4;
  
  uStack_4 = 0x11004a70;
  FUN_110089b4();
  uStack_3c = DAT_1102013c;
  uStack_38 = DAT_11020140;
  pMVar1 = (MiningGroup *)CreateMiningGroup(local_24);
  uStack_4 = 0;
  uStack_48 = 0x11004aa1;
  MiningGroup::operator=((MiningGroup *)&DAT_1101c054,pMVar1);
  uStack_4 = 0xffffffff;
  ScStub::~ScStub((ScStub *)(local_24 + -0xc));
  uStack_48 = DAT_1102013c;
  pMVar1 = (MiningGroup *)CreateMiningGroup(local_24 + -0xc);
  uStack_10 = 1;
  uStack_54 = 0x11004ad9;
  MiningGroup::operator=((MiningGroup *)&DAT_1101c058,pMVar1);
  uStack_10 = 0xffffffff;
  ScStub::~ScStub((ScStub *)&uStack_3c);
  uStack_54 = DAT_1102013c;
  pMVar1 = (MiningGroup *)CreateMiningGroup(&uStack_3c);
  uStack_1c = 2;
  uStack_60 = (void *)0x11004b0b;
  MiningGroup::operator=((MiningGroup *)&DAT_1101c05c,pMVar1);
  uStack_1c = 0xffffffff;
  ScStub::~ScStub((ScStub *)&uStack_48);
  uStack_60 = DAT_1102011c;
  pMVar1 = (MiningGroup *)CreateMiningGroup(&uStack_48);
  uStack_6c = 0x11004b3d;
  MiningGroup::operator=((MiningGroup *)&DAT_1101c060,pMVar1);
  ScStub::~ScStub((ScStub *)&uStack_54);
  uStack_6c = DAT_1102013c;
  pFVar2 = (FightGroup *)CreateFightGroup(&uStack_54);
  FightGroup::operator=((FightGroup *)&DAT_1101c0c8,pFVar2);
  ScStub::~ScStub((ScStub *)&uStack_60);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_6e + 0x12),0x2e,7,0x32,9);
  FightGroup::SetRect((FightGroup *)&DAT_1101c0c8,pMVar3);
  pBVar4 = (BuildingGroup *)CreateBuildingGroup(&uStack_60);
  BuildingGroup::operator=((BuildingGroup *)&DAT_1101c064,pBVar4);
  ScStub::~ScStub((ScStub *)&uStack_6c);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c064,2,0,2);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c064,0xf,0,1);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_6e + 6),0x25,0x18,0x2a,0x1c);
  BuildingGroup::SetRect((BuildingGroup *)&DAT_1101c064,pMVar3);
  pBVar4 = (BuildingGroup *)CreateBuildingGroup(&uStack_6c);
  BuildingGroup::operator=((BuildingGroup *)&DAT_1101c068,pBVar4);
  ScStub::~ScStub(aSStack_6e + -10);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c068,2,0,1);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_6e + -6),0x25,0x18,0x2a,0x1c);
  BuildingGroup::SetRect((BuildingGroup *)&DAT_1101c068,pMVar3);
  pBVar4 = (BuildingGroup *)CreateBuildingGroup(aSStack_6e + -10);
  BuildingGroup::operator=((BuildingGroup *)&DAT_1101c074,pBVar4);
  ScStub::~ScStub(aSStack_6e + -0x16);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c074,2,0,1);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c074,0xf,0,1);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_6e + -0x12),0x26,0x4d,0x2a,0x50);
  BuildingGroup::SetRect((BuildingGroup *)&DAT_1101c074,pMVar3);
  pBVar4 = (BuildingGroup *)CreateBuildingGroup(aSStack_6e + -0x16);
  BuildingGroup::operator=((BuildingGroup *)&DAT_1101c070,pBVar4);
  ScStub::~ScStub(aSStack_6e + -0x22);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c070,2,0,2);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_6e + -0x1e),0x26,0x4d,0x2a,0x50);
  BuildingGroup::SetRect((BuildingGroup *)&DAT_1101c070,pMVar3);
  pFVar2 = (FightGroup *)CreateFightGroup(aSStack_6e + -0x22);
  FightGroup::operator=((FightGroup *)&DAT_1101c08c,pFVar2);
  ScStub::~ScStub(aSStack_6e + -0x2e);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_6e + -0x2a),0x20,100,0x22,0x66);
  FightGroup::SetRect((FightGroup *)&DAT_1101c08c,pMVar3);
  pFVar2 = (FightGroup *)CreateFightGroup(aSStack_6e + -0x2e);
  FightGroup::operator=((FightGroup *)&DAT_1101c07c,pFVar2);
  ScStub::~ScStub(aSStack_6e + -0x3a);
  puVar5 = (undefined4 *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_6e + -0x36),0x22,8,0x36,0x18);
  FUN_110075d0(SUB41(*puVar5,0));
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c07c,5,0x3d,DAT_1101c008 + 4);
  FightGroup::DoGuardRect((FightGroup *)&DAT_1101c07c);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_6e + -0x36),0x22,8,0x36,0x18);
  FightGroup::SetRect((FightGroup *)&DAT_1101c07c,pMVar3);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_6e + -0x36),0x20,0,0x38,0x1e);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_1101c07c,pMVar3);
  pFVar2 = (FightGroup *)CreateFightGroup(aSStack_6e + -0x3a);
  FightGroup::operator=((FightGroup *)&DAT_1101c080,pFVar2);
  ScStub::~ScStub(aSStack_6e + -0x46);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c080,5,0x3d,4);
  FightGroup::DoGuardRect((FightGroup *)&DAT_1101c080);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_6e + -0x42),0x24,0x22,0x33,0x23);
  FightGroup::SetRect((FightGroup *)&DAT_1101c080,pMVar3);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_6e + -0x42),0x20,0x23,0x34,0x26);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_1101c080,pMVar3);
  pFVar2 = (FightGroup *)CreateFightGroup(aSStack_6e + -0x46);
  FightGroup::operator=((FightGroup *)&DAT_1101c084,pFVar2);
  ScStub::~ScStub(aSStack_6e + -0x52);
  puVar5 = (undefined4 *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_6e + -0x4e),0x6e,1,0x73,0xf);
  FUN_110075d0(SUB41(*puVar5,0));
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c084,5,0x3d,DAT_1101c004 + 3);
  FightGroup::DoGuardRect((FightGroup *)&DAT_1101c084);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_6e + -0x4e),0x6e,0,0x71,0xe);
  FightGroup::SetRect((FightGroup *)&DAT_1101c084,pMVar3);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_6e + -0x4e),0x72,0,0x76,0xe);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_1101c084,pMVar3);
  pFVar2 = (FightGroup *)CreateFightGroup(aSStack_6e + -0x52);
  FightGroup::operator=((FightGroup *)&DAT_1101c088,pFVar2);
  ScStub::~ScStub(aSStack_6e + -0x5e);
  FightGroup::DoGuardRect((FightGroup *)&DAT_1101c088);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_6e + -0x5a),0x22,0x4b,0x27,0x58);
  FightGroup::SetRect((FightGroup *)&DAT_1101c088,pMVar3);
  FightGroup::SetAttackType((FightGroup *)&DAT_1101c088,2);
  pFVar2 = (FightGroup *)CreateFightGroup(aSStack_6e + -0x5e);
  FightGroup::operator=((FightGroup *)&DAT_1101c090,pFVar2);
  ScStub::~ScStub(aSStack_6e + -0x6a);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c090,5,0x3d,10);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_6e + -0x66),0x2f,0x1d,0x34,0x20);
  FightGroup::SetRect((FightGroup *)&DAT_1101c090,pMVar3);
  pFVar2 = (FightGroup *)CreateFightGroup(aSStack_6e + -0x6a);
  FightGroup::operator=((FightGroup *)&DAT_1101c094,pFVar2);
  ScStub::~ScStub(aSStack_6e + -0x76);
  FightGroup::SetCombineFire((FightGroup *)&DAT_1101c094);
  FightGroup::SetAttackType((FightGroup *)&DAT_1101c094,5);
  FightGroup::DoGuardRect((FightGroup *)&DAT_1101c094);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_6e + -0x72),0x22,0x48,0x2b,0x56);
  FightGroup::SetRect((FightGroup *)&DAT_1101c094,pMVar3);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_6e + -0x72),0x20,0x44,0x32,0x61);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_1101c094,pMVar3);
  pFVar2 = (FightGroup *)CreateFightGroup(aSStack_6e + -0x76);
  FightGroup::operator=((FightGroup *)&DAT_1101c0a0,pFVar2);
  ScStub::~ScStub((ScStub *)((int)register0x00000010 + -0xf0));
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)(aSStack_6e + -0x7e),0x2a,0x51,0x2f,0x57);
  FightGroup::SetRect((FightGroup *)&DAT_1101c0a0,pMVar3);
  pFVar2 = (FightGroup *)CreateFightGroup((int)register0x00000010 + -0xf0);
  FightGroup::operator=((FightGroup *)&DAT_1101c0a4,pFVar2);
  ScStub::~ScStub((ScStub *)((int)register0x00000010 + -0xfc));
  pMVar3 = (MAP_RECT *)
           MAP_RECT::MAP_RECT((MAP_RECT *)((int)register0x00000010 + -0xf8),0x21,0x46,0x2f,0x4a);
  FightGroup::SetRect((FightGroup *)&DAT_1101c0a4,pMVar3);
  pFVar2 = (FightGroup *)CreateFightGroup((int)register0x00000010 + -0xfc);
  FightGroup::operator=((FightGroup *)&DAT_1101c0a8,pFVar2);
  ScStub::~ScStub((ScStub *)((int)register0x00000010 + -0x108));
  puVar5 = (undefined4 *)
           MAP_RECT::MAP_RECT((MAP_RECT *)((int)register0x00000010 + -0x104),0x50,0x26,0x54,0x29);
  FUN_110075d0(SUB41(*puVar5,0));
  pMVar3 = (MAP_RECT *)
           MAP_RECT::MAP_RECT((MAP_RECT *)((int)register0x00000010 + -0x104),0x50,0x26,0x54,0x2a);
  FightGroup::SetRect((FightGroup *)&DAT_1101c0a8,pMVar3);
  pMVar3 = (MAP_RECT *)
           MAP_RECT::MAP_RECT((MAP_RECT *)((int)register0x00000010 + -0x104),0x52,0x2b,0x5a,0x31);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_1101c0a8,pMVar3);
  pMVar3 = (MAP_RECT *)
           MAP_RECT::MAP_RECT((MAP_RECT *)((int)register0x00000010 + -0x104),0x55,0x30,0x59,0x33);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_1101c0a8,pMVar3);
  pMVar3 = (MAP_RECT *)
           MAP_RECT::MAP_RECT((MAP_RECT *)((int)register0x00000010 + -0x104),0x49,0x22,0x50,0x2c);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_1101c0a8,pMVar3);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0a8,5,0x3d,DAT_1101c004 + 2);
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0a8,5,0x3f,DAT_1101c004);
  _DAT_1101c0d4 = &DAT_11016008;
  pFVar2 = (FightGroup *)CreateFightGroup((int)register0x00000010 + -0x108);
  FightGroup::operator=((FightGroup *)&DAT_1101c0ac,pFVar2);
  ScStub::~ScStub((ScStub *)((int)register0x00000010 + -0x114));
  FightGroup::SetPatrolMode((FightGroup *)&DAT_1101c0ac,(PatrolRoute *)&DAT_1101c0d0);
  pFVar2 = (FightGroup *)CreateFightGroup((int)register0x00000010 + -0x114);
  FightGroup::operator=((FightGroup *)&DAT_1101c0c4,pFVar2);
  ScStub::~ScStub((ScStub *)((int)register0x00000010 + -0x120));
  pMVar3 = (MAP_RECT *)
           MAP_RECT::MAP_RECT((MAP_RECT *)((int)register0x00000010 + -0x11c),0x20,0x47,0x29,0x5a);
  FightGroup::SetRect((FightGroup *)&DAT_1101c0c4,pMVar3);
  pFVar2 = (FightGroup *)CreateFightGroup((int)register0x00000010 + -0x120);
  FightGroup::operator=((FightGroup *)&DAT_1101c098,pFVar2);
  ScStub::~ScStub((ScStub *)((int)register0x00000010 + -300));
  FightGroup::DoGuardRect((FightGroup *)&DAT_1101c098);
  uStack_150 = (void *)0x11005302;
  pMVar3 = (MAP_RECT *)
           MAP_RECT::MAP_RECT((MAP_RECT *)((int)register0x00000010 + -0x128),0x22,0x4c,0x25,0x55);
  FightGroup::SetRect((FightGroup *)&DAT_1101c098,pMVar3);
  uStack_150 = (void *)0x11005319;
  pMVar3 = (MAP_RECT *)
           MAP_RECT::MAP_RECT((MAP_RECT *)((int)register0x00000010 + -0x128),0x20,0x47,0x29,0x5a);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_1101c098,pMVar3);
  FightGroup::SetCombineFire((FightGroup *)&DAT_1101c098);
  FightGroup::SetAttackType((FightGroup *)&DAT_1101c098,0x17);
  pFVar2 = (FightGroup *)CreateFightGroup((int)register0x00000010 + -300);
  uStack_150 = (void *)0x1100535f;
  FightGroup::operator=((FightGroup *)&DAT_1101c0b0,pFVar2);
  ScStub::~ScStub((ScStub *)((int)register0x00000010 + -0x138));
  uStack_150 = DAT_1102011c;
  pFVar2 = (FightGroup *)CreateFightGroup((int)register0x00000010 + -0x138);
  pvStack_15c = (void *)0x11005395;
  FightGroup::operator=((FightGroup *)&DAT_1101c0b4,pFVar2);
  ScStub::~ScStub((ScStub *)((int)register0x00000010 + -0x144));
  pvStack_15c = DAT_1102011c;
  pFVar2 = (FightGroup *)CreateFightGroup((int)register0x00000010 + -0x144);
  pvStack_168 = (void *)0x110053cb;
  FightGroup::operator=((FightGroup *)&DAT_1101c0b8,pFVar2);
  ScStub::~ScStub((ScStub *)&uStack_150);
  pvStack_168 = DAT_1102011c;
  pFVar2 = (FightGroup *)CreateFightGroup(&uStack_150);
  uStack_174 = (void *)0x11005401;
  FightGroup::operator=((FightGroup *)&DAT_1101c0bc,pFVar2);
  ScStub::~ScStub((ScStub *)&pvStack_15c);
  uStack_174 = DAT_1102011c;
  pFVar2 = (FightGroup *)CreateFightGroup(&pvStack_15c);
  pvStack_180 = (void *)0x11005437;
  FightGroup::operator=((FightGroup *)&DAT_1101c0c0,pFVar2);
  ScStub::~ScStub((ScStub *)&pvStack_168);
  uStack_184 = DAT_11020118;
  pvStack_180 = DAT_1102011c;
  pFVar2 = (FightGroup *)CreateFightGroup(&pvStack_168);
  FightGroup::operator=((FightGroup *)&DAT_1101c09c,pFVar2);
  ScStub::~ScStub((ScStub *)&uStack_174);
  FightGroup::DoGuardRect((FightGroup *)&DAT_1101c09c);
  pMVar3 = (MAP_RECT *)
           MAP_RECT::MAP_RECT((MAP_RECT *)((int)register0x00000010 + -0x170),0x2a,0x14,0x36,0x1c);
  FightGroup::SetRect((FightGroup *)&DAT_1101c09c,pMVar3);
  pMVar3 = (MAP_RECT *)
           MAP_RECT::MAP_RECT((MAP_RECT *)((int)register0x00000010 + -0x170),0x25,9,0x2b,0x14);
  FightGroup::AddGuardedRect((FightGroup *)&DAT_1101c09c,pMVar3);
  FightGroup::SetCombineFire((FightGroup *)&DAT_1101c09c);
  pBVar4 = (BuildingGroup *)CreateBuildingGroup(&uStack_174);
  BuildingGroup::operator=((BuildingGroup *)&DAT_1101c06c,pBVar4);
  ScStub::~ScStub((ScStub *)&pvStack_180);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c06c,(ScGroup *)&DAT_1101c054,600);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c06c,(ScGroup *)&DAT_1101c058,900);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c06c,(ScGroup *)&DAT_1101c07c,800);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c06c,(ScGroup *)&DAT_1101c080,500);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c06c,(ScGroup *)&DAT_1101c084,200);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c06c,(ScGroup *)&DAT_1101c064,400);
  BuildingGroup::RecordVehReinforceGroup
            ((BuildingGroup *)&DAT_1101c06c,(ScGroup *)&DAT_1101c0a8,0x32);
  pBVar4 = (BuildingGroup *)CreateBuildingGroup(&pvStack_180,extraout_EDX,DAT_11020118);
  BuildingGroup::operator=((BuildingGroup *)&DAT_1101c078,pBVar4);
  ScStub::~ScStub((ScStub *)((int)register0x00000010 + -0x18c));
  pFVar2 = (FightGroup *)
           CreateFightGroup((int)register0x00000010 + -0x18c,extraout_EDX_00,DAT_11020118,
                            DAT_1102011c,DAT_11020120);
  FightGroup::operator=((FightGroup *)&DAT_1101c0cc,pFVar2);
  ScStub::~ScStub((ScStub *)((int)register0x00000010 + -0x198));
  ScGroup::SetTargCount((ScGroup *)&DAT_1101c0cc,0xd,0,1);
  pMVar3 = (MAP_RECT *)MAP_RECT::MAP_RECT((MAP_RECT *)&uStack_184,0x27,0x51,0x2b,0x53);
  FightGroup::SetRect((FightGroup *)&DAT_1101c0cc,pMVar3);
  FUN_11001fec();
  ExceptionList = uStack_174;
  return;
}


// ---- 110055fe FUN_110055fe  (called by: -)

void FUN_110055fe(void)

{
  PlayerBuildingEnum unaff_retaddr;
  
  if (DAT_1101c0ea != '\0') {
    FUN_11003e3c(unaff_retaddr);
  }
  if (DAT_1101c0e9 != '\0') {
    FUN_110042e0();
  }
  if (DAT_1101c0e8 == '\0') {
    return;
  }
  FUN_11002867();
  return;
}


// ---- 11005629 FUN_11005629  (called by: InitProc@11005892)

void FUN_11005629(void)

{
  FUN_11007cc0('\x01','\0',2,0x20,100,0x21,0x66);
  FUN_11007a30('\x01','\0',100,FUN_110055fe,0);
  DAT_1102015c = FUN_11007a30('\0','\0',200,FUN_11003fe2,0);
  return;
}


// ---- 11005670 FUN_11005670  (called by: -)

void FUN_11005670(void)

{
  int unaff_EBP;
  
  FUN_110089b4();
  CreateOperationalTrigger(unaff_EBP + -0x10,1,0,0,0x22,0,(char *)0x4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  CreateVictoryCondition(unaff_EBP + -0x14,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x10));
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  FUN_11001f99(s___Construct_a_Medical_Center_11014f7c);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 110056dc FUN_110056dc  (called by: -)

void FUN_110056dc(void)

{
  int unaff_EBP;
  
  FUN_110089b4();
  CreateOperationalTrigger(unaff_EBP + -0x10,1,0,0,0x28,0,(char *)0x4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  CreateVictoryCondition(unaff_EBP + -0x14,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x10));
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  FUN_11001f99(s___Construct_a_DIRT_11014fc8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11005748 FUN_11005748  (called by: -)

void FUN_11005748(void)

{
  int unaff_EBP;
  
  FUN_110089b4();
  CreateOperationalTrigger(unaff_EBP + -0x10,1,0,0,0x29,0,(char *)0x4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  CreateVictoryCondition(unaff_EBP + -0x14,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x10));
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  FUN_11001f99(s___Construct_a_Garage_11015000);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 110057b4 FUN_110057b4  (called by: -)

void FUN_110057b4(void)

{
  int unaff_EBP;
  
  FUN_110089b4();
  CreateCountTrigger(unaff_EBP + -0x10,1,0,0,0xb,-1,2,(char *)0x2);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  CreateVictoryCondition(unaff_EBP + -0x14,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x10));
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  FUN_11001f99(s___Build_2_Scouts_1101503c);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11005823 FUN_11005823  (called by: -)

void FUN_11005823(void)

{
  int unaff_EBP;
  
  FUN_110089b4();
  CreateCountTrigger(unaff_EBP + -0x10,1,0,0,5,-1,10,(char *)0x2);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  CreateVictoryCondition(unaff_EBP + -0x14,1,(Trigger *)0x0,(char *)(unaff_EBP + -0x10));
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x14));
  FUN_11001f99(s___Build_10_Lynx_11015068);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11005892 InitProc  (called by: -)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 InitProc(void)

{
  bool bVar1;
  char cVar2;
  Trigger *pTVar3;
  int extraout_ECX;
  undefined4 uVar4;
  int iVar5;
  Trigger aTStack_7f [3];
  Trigger local_18 [2];
  Trigger aTStack_16 [2];
  Trigger local_14 [4];
  Trigger local_10 [4];
  undefined1 local_c [8];
  IUnit local_4 [4];
  
                    /* 0x5892  8  InitProc */
  bVar1 = FUN_11006a26();
  if (!bVar1) {
    (*DAT_1101531c)();
    return 0;
  }
  IUnit::IUnit(local_4);
  Trigger::Trigger(local_18);
  Trigger::Trigger(local_10);
  Trigger::Trigger(local_14);
  DAT_1101c004 = _Player::Difficulty((_Player *)&DAT_11020128);
  uVar4 = 0;
  DAT_1101c008 = DAT_1101c004 * 2;
  DAT_1101c000 = DAT_1101c004 == 0;
  DAT_1101c001 = DAT_1101c004 == 1;
  DAT_1101c002 = DAT_1101c004 == 2;
  _Player::GoPlymouth((_Player *)&DAT_11020128);
  _Player::GoHuman((_Player *)&DAT_11020128);
  _Player::SetColorNumber((_Player *)&DAT_11020128,3);
  _Player::SetKids((_Player *)&DAT_11020128,0);
  _Player::SetTechLevel((_Player *)&DAT_11020128,2);
  _Player::MarkResearchComplete((_Player *)&DAT_11020128,0x83a);
  _Player::GoEden((_Player *)&DAT_11020138);
  _Player::GoAI((_Player *)&DAT_11020138);
  _Player::SetColorNumber((_Player *)&DAT_11020138,0);
  _Player::SetTechLevel((_Player *)&DAT_11020138,3);
  _Player::SetOre((_Player *)&DAT_11020138,10000);
  _Player::GoPlymouth((_Player *)&DAT_11020118);
  _Player::GoAI((_Player *)&DAT_11020118);
  _Player::SetColorNumber((_Player *)&DAT_11020118,1);
  _Player::SetTechLevel((_Player *)&DAT_11020118,3);
  if (DAT_1101c000 != '\0') {
    _DAT_1101446c = 0;
    _DAT_11014484 = 1;
  }
  FUN_11001603(0xb,0x11014458);
  FUN_110014da(1,0x1f,-1,(int *)&DAT_11014d40);
  FUN_110014da(1,0x1f,-1,(int *)&DAT_11014d80);
  FUN_110049e2(extraout_ECX);
  FUN_110074d0();
  cVar2 = InitMap();
  if (cVar2 == '\0') goto LAB_11005f31;
  FUN_11004a66();
  FUN_11005629();
  FUN_110022f0();
  FUN_11006b19(0);
  TethysGame::SetCheatFastUnits(0);
  TethysGame::SetCheatFastProduction(0);
  TethysGame::SetCheatUnlimitedResources(0);
  TethysGame::SetCheatProduceAll(0);
  TethysGame::SetDaylightMoves(1);
  TethysGame::SetDaylightEverywhere(0);
  GameMap::SetInitialLightLevel(0x8f);
  FUN_110080a0('\x01','\x01',0x13bc,0,FUN_11005748,0);
  pTVar3 = (Trigger *)CreateResearchTrigger((int)local_c,1,0,0x13bc,(char *)0x0);
  Trigger::operator=(local_18 + -4,pTVar3);
  ScStub::~ScStub((ScStub *)local_10);
  CreateVictoryCondition((int)local_10,1,(Trigger *)0x0,(char *)(local_18 + -4));
  ScStub::~ScStub((ScStub *)local_14);
  FUN_110080a0('\x01','\x01',0xce7,0,FUN_11005670,0);
  if (DAT_1101c000 == '\0') {
    pTVar3 = (Trigger *)CreateResearchTrigger((int)local_14,1,0,0xce7,(char *)0x0);
    Trigger::operator=(local_18 + -0xc,pTVar3);
    ScStub::~ScStub((ScStub *)local_18);
    CreateVictoryCondition((int)local_18,1,(Trigger *)0x0,(char *)(local_18 + -0xc));
    ScStub::~ScStub((ScStub *)(local_18 + -4));
  }
  FUN_110080a0('\x01','\x01',0xce5,0,FUN_110056dc,0);
  if (DAT_1101c000 == '\0') {
    pTVar3 = (Trigger *)CreateResearchTrigger((int)(local_18 + -4),1,0,0xce5,(char *)0x0);
    Trigger::operator=(local_18 + -0x14,pTVar3);
    ScStub::~ScStub((ScStub *)(local_18 + -8));
    CreateVictoryCondition((int)(local_18 + -8),1,(Trigger *)0x0,(char *)(local_18 + -0x14));
    ScStub::~ScStub((ScStub *)(local_18 + -0xc));
  }
  FUN_110080a0('\x01','\x01',0xf0b,0,FUN_11005823,0);
  pTVar3 = (Trigger *)CreateResearchTrigger((int)(local_18 + -4),1,0,0xf0b,(char *)0x0);
  Trigger::operator=(local_18 + -0x14,pTVar3);
  ScStub::~ScStub((ScStub *)(local_18 + -8));
  CreateVictoryCondition((int)(local_18 + -8),1,(Trigger *)0x0,(char *)(local_18 + -0x14));
  ScStub::~ScStub((ScStub *)(local_18 + -0xc));
  pTVar3 = (Trigger *)CreateResearchTrigger((int)(local_18 + -0xc),1,0,0xc82,(char *)0x0);
  Trigger::operator=(local_18 + -0x1c,pTVar3);
  ScStub::~ScStub((ScStub *)(local_18 + -0x10));
  CreateVictoryCondition((int)(local_18 + -0x10),1,(Trigger *)0x0,(char *)(local_18 + -0x1c));
  ScStub::~ScStub((ScStub *)(local_18 + -0x14));
  FUN_110080a0('\x01','\x01',0xd49,0,FUN_110057b4,0);
  pTVar3 = (Trigger *)CreateResearchTrigger((int)(local_18 + -0x14),1,0,0xd49,(char *)0x0);
  Trigger::operator=(local_18 + -0x1c,pTVar3);
  ScStub::~ScStub((ScStub *)(local_18 + -0x18));
  pTVar3 = (Trigger *)CreateResearchTrigger((int)(local_18 + -0x14),1,0,0xc81,(char *)0x0);
  Trigger::operator=(local_18 + -0x24,pTVar3);
  pTVar3 = (Trigger *)CreateSetTrigger((int)(local_18 + -0x1c),1,0,2,(char *)0x2);
  Trigger::operator=(local_18 + -0x28,pTVar3);
  ScStub::~ScStub((ScStub *)(local_18 + -0x1c));
  ScStub::~ScStub((ScStub *)(local_18 + -0x18));
  CreateVictoryCondition((int)(local_18 + -0x18),1,(Trigger *)0x0,(char *)(local_18 + -0x28));
  ScStub::~ScStub((ScStub *)(local_18 + -0x1c));
  pTVar3 = (Trigger *)CreateKitTrigger((int)(local_18 + -0x1c),1,0,1,0x37,(char *)0x1);
  Trigger::operator=(local_18 + -0x30,pTVar3);
  ScStub::~ScStub((ScStub *)(local_18 + -0x20));
  pTVar3 = (Trigger *)
           CreateVictoryCondition
                     ((int)(local_18 + -0x20),1,(Trigger *)0x0,(char *)(local_18 + -0x30));
  Trigger::operator=((Trigger *)&DAT_1101c0dc,pTVar3);
  ScStub::~ScStub((ScStub *)(local_18 + -0x24));
  pTVar3 = (Trigger *)CreateResourceTrigger((int)(local_18 + -0x24),1,0,6,10,0,(char *)0x3);
  Trigger::operator=(aTStack_7f + 0x2f,pTVar3);
  ScStub::~ScStub((ScStub *)(local_18 + -0x28));
  CreateFailureCondition((int)(local_18 + -0x28),1,(Trigger *)0x0,(char *)(aTStack_7f + 0x2f));
  ScStub::~ScStub((ScStub *)(local_18 + -0x2c));
  pTVar3 = (Trigger *)CreateEvacTrigger((int)(local_18 + -0x2c),1,0,(char *)0x0);
  Trigger::operator=(aTStack_7f + 0x27,pTVar3);
  ScStub::~ScStub((ScStub *)(local_18 + -0x30));
  CreateVictoryCondition((int)(local_18 + -0x30),1,(Trigger *)0x0,(char *)(aTStack_7f + 0x27));
  ScStub::~ScStub((ScStub *)(aTStack_7f + 0x33));
  _Player::MarkResearchComplete((_Player *)&DAT_11020128,0xe17);
  _Player::SetOre((_Player *)&DAT_11020128,0);
  _Player::SetFoodStored
            ((_Player *)&DAT_11020128,
             *(int *)(&DAT_11010400 + DAT_1101c004 * 4) + ((DAT_1101c002 == '\0') + 1) * -200);
  _Player::MarkResearchComplete((_Player *)&DAT_11020118,0x3262);
  if (DAT_1101c004 == 0) {
    _Player::SetWorkers((_Player *)&DAT_11020128,0x28);
    _Player::SetScientists((_Player *)&DAT_11020128,0xf);
    FUN_110079c0('\x01','\0',4000,6000,FUN_11004599,0);
    FUN_110079c0('\x01','\0',4000,8000,FUN_110045c0,0);
    FUN_11007a30('\x01','\x01',21000,FUN_110045e9,0);
    TethysGame::ForceMoraleGood(0);
  }
  else {
    if (DAT_1101c004 == 1) {
      _Player::SetWorkers((_Player *)&DAT_11020128,0x23);
      _Player::SetScientists((_Player *)&DAT_11020128,0xc);
      FUN_110079c0('\x01','\0',4000,6000,FUN_11004599,0);
      FUN_110079c0('\x01','\0',4000,8000,FUN_110045c0,0);
      iVar5 = 18000;
    }
    else {
      if (DAT_1101c004 != 2) goto LAB_11005ef6;
      _Player::SetWorkers((_Player *)&DAT_11020128,0x1e);
      _Player::SetScientists((_Player *)&DAT_11020128,10);
      FUN_110079c0('\x01','\0',4000,6000,FUN_11004599,0);
      FUN_110079c0('\x01','\0',4000,8000,FUN_110045c0,0);
      iVar5 = 16000;
    }
    FUN_11007a30('\x01','\x01',iVar5,FUN_110045e9,0);
    TethysGame::FreeMoraleLevel(0);
  }
LAB_11005ef6:
  uVar4 = 1;
  FUN_11007a30('\x01','\x01',12000,FUN_11002cfe,0);
  FUN_11007a30('\x01','\x01',80000,FUN_1100247b,0);
  _Player::CenterViewOn((_Player *)&DAT_11020128,0x9c,0x7c);
LAB_11005f31:
  ScStub::~ScStub((ScStub *)(aTStack_7f + 0x27));
  ScStub::~ScStub((ScStub *)(aTStack_7f + 0x2b));
  ScStub::~ScStub((ScStub *)(aTStack_7f + 0x23));
  return uVar4;
}


// ---- 11005f4d FUN_11005f4d  (called by: FUN_11005f7f@11005f7f)

void FUN_11005f4d(void)

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


// ---- 11005f7f FUN_11005f7f  (called by: entry@11009b14)

undefined4 FUN_11005f7f(HMODULE param_1,int param_2)

{
  bool bVar1;
  undefined *puVar2;
  ushort uVar3;
  
  if (param_2 == 0) {
    bVar1 = FUN_11006a33();
    if (!bVar1) {
      FUN_11006aa8((uint *)&DAT_110151f4);
    }
    FUN_110011e7();
    FUN_11005f4d();
  }
  else if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    FUN_110081b0(param_1);
    uVar3 = 1;
    puVar2 = FUN_11006a40((uint *)s_q03_mo3_110151f8,PTR_DAT_11015200);
    FUN_1100825e(puVar2,uVar3);
    FUN_11008304(0x11008284);
    FUN_11001172();
  }
  return 1;
}


// ---- 11005ff7 FUN_11005ff7  (called by: FUN_110060c3@110060c3)

undefined1 FUN_11005ff7(void)

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
    if (local_10 != *(int *)(&DAT_11016088 + local_c * 4)) {
      local_5 = 1;
    }
    while (iVar3 = PlayerVehicleEnum::GetNext(local_18,(Unit *)local_14), iVar3 != 0) {
      local_10 = local_10 + 1;
    }
    if (local_10 != *(int *)(&DAT_110160a8 + local_c * 4)) {
      local_5 = 1;
    }
  }
  return local_5;
}


// ---- 110060c3 FUN_110060c3  (called by: FUN_11006aa8@11006aa8)

uint __cdecl FUN_110060c3(LPCSTR param_1,char param_2)

{
  char cVar1;
  uint uVar2;
  
  if (param_2 == '\0') {
    param_2 = FUN_11005ff7();
  }
  uVar2 = FUN_11006439(param_1,param_2);
  cVar1 = (char)uVar2;
  if (cVar1 != '\0') {
    FUN_110065ad(param_1);
    uVar2 = FUN_11006102(param_1,'\x01');
  }
  return CONCAT31((int3)(uVar2 >> 8),cVar1);
}


// ---- 11006102 FUN_11006102  (called by: FUN_110060c3@110060c3)

uint __cdecl FUN_11006102(LPCSTR param_1,char param_2)

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
    if (local_c != *(int *)(&DAT_11016088 + iVar1 * 4)) {
      param_2 = '\x01';
    }
    while (iVar4 = PlayerVehicleEnum::GetNext(local_14,(Unit *)local_8), iVar4 != 0) {
      local_10 = local_10 + 1;
    }
    if (local_10 != *(map_id *)(&DAT_110160a8 + iVar1 * 4)) {
      param_2 = '\x01';
    }
    local_18 = local_18 + local_10 + local_c;
  }
  local_c = TethysGame::NoPlayers();
  if (param_2 == '\0') {
    local_c = local_c & 0xffffff00;
  }
  else {
    pFVar5 = (FILE *)FUN_11009372(param_1,&DAT_11015204);
    FUN_11009208((char *)&local_18,4,1,(int *)pFVar5);
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
            FUN_11009208((char *)&local_68,0x18,1,(int *)pFVar5);
            param_1 = (LPCSTR)0x0;
            do {
              IUnit::GetFactoryCargo(local_8,(int)param_1,&local_50,&local_44);
              FUN_11009208((char *)&local_50,4,1,(int *)pFVar5);
              FUN_11009208((char *)&local_44,4,1,(int *)pFVar5);
              param_1 = param_1 + 1;
            } while ((int)param_1 < 6);
          }
          else {
            FUN_11009208((char *)&local_68,0x18,1,(int *)pFVar5);
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
          FUN_11009208((char *)&local_3c,0x18,1,(int *)pFVar5);
        }
      }
    }
    FUN_11008de9(pFVar5);
    *(int *)(&DAT_11016088 + local_c * 4) = local_18;
    local_c = (uint)(pFVar5 != (FILE *)0x0);
  }
  return local_c;
}


// ---- 11006439 FUN_11006439  (called by: FUN_110060c3@110060c3)

uint __cdecl FUN_11006439(LPCSTR param_1,char param_2)

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
  if ((param_2 != '\0') || (uVar5 = local_14, local_14 != DAT_110160c8)) {
    pFVar4 = (FILE *)FUN_11009372(param_1,&DAT_11014440);
    uVar5 = 0;
    if (pFVar4 != (FILE *)0x0) {
      FUN_11009208((char *)&local_14,4,1,(int *)pFVar4);
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
            FUN_11009208((char *)&local_10,2,1,(int *)pFVar4);
            FUN_11009208((char *)&local_c,2,1,(int *)pFVar4);
            FUN_11009208((char *)&local_5,1,1,(int *)pFVar4);
            if ((local_5 == 0x15) || (uVar6 = extraout_EDX_03, local_5 == 0x16)) {
              local_18 = GameMap::GetTile((int)(short)local_c,extraout_EDX_03,(int)(short)local_10,
                                          (int)(short)local_c);
              FUN_11009208((char *)&local_18,2,1,(int *)pFVar4);
              uVar6 = extraout_EDX_04;
            }
          }
          local_10 = local_10 + 1;
          sVar1 = (short)local_10;
        }
        local_c = local_c + 1;
        sVar1 = (short)local_c;
      }
      FUN_11008de9(pFVar4);
      DAT_110160c8 = local_14;
      return CONCAT31((int3)(local_14 >> 8),1);
    }
  }
  return uVar5 & 0xffffff00;
}


// ---- 110065ad FUN_110065ad  (called by: FUN_110060c3@110060c3)

undefined4 __cdecl FUN_110065ad(LPCSTR param_1)

{
  FILE *pFVar1;
  undefined4 uVar2;
  int local_24 [8];
  
  FUN_110068ab(local_24,SUB41(*(undefined4 *)Player_exref,0));
  pFVar1 = (FILE *)FUN_11009372(param_1,&DAT_11015204);
  FUN_11009208((char *)local_24,0x20,1,(int *)pFVar1);
  uVar2 = FUN_11008de9(pFVar1);
  return CONCAT31((int3)((uint)uVar2 >> 8),1);
}


// ---- 110065f7 FUN_110065f7  (called by: FUN_1100660f@1100660f, FUN_110066bc@110066bc)

undefined4 __cdecl FUN_110065f7(int *param_1)

{
  uint uVar1;
  
  uVar1 = FUN_11009497((char *)&DAT_11016068,0x20,1,param_1);
  return CONCAT31((int3)(uVar1 >> 8),1);
}


// ---- 1100660f FUN_1100660f  (called by: InitMap@1100487d)

undefined1 __thiscall FUN_1100660f(uint3 param_1,LPCSTR param_2)

{
  FILE *pFVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  
  uVar3 = 0;
  pFVar1 = (FILE *)FUN_11006638(param_1,param_2);
  if (pFVar1 != (FILE *)0x0) {
    uVar2 = FUN_110065f7((int *)pFVar1);
    uVar3 = (undefined1)uVar2;
    FUN_11008de9(pFVar1);
  }
  return uVar3;
}


// ---- 11006638 FUN_11006638  (called by: FUN_1100660f@1100660f, FUN_110066bc@110066bc)

int * __thiscall FUN_11006638(uint3 param_1,LPCSTR param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int local_c;
  undefined4 uStack_8;
  
  local_c = 0;
  uStack_8 = (uint)param_1;
  piVar1 = (int *)FUN_11009372(param_2,&DAT_11015208);
  if (piVar1 == (int *)0x0) {
    return (int *)0x0;
  }
  piVar2 = &local_c;
  uVar3 = 4;
  do {
    FUN_11009497((char *)piVar2,uVar3,1,piVar1);
    do {
      local_c = local_c + -1;
      if (local_c < 0) {
        return piVar1;
      }
      FUN_11009497((char *)((int)&param_2 + 2),2,1,piVar1);
      FUN_11009497((char *)((int)&param_2 + 2),2,1,piVar1);
      FUN_11009497((char *)((int)&uStack_8 + 3),1,1,piVar1);
    } while ((uStack_8._3_1_ < 0x15) || (0x16 < uStack_8._3_1_));
    uVar3 = 2;
    piVar2 = (int *)((int)&param_2 + 2);
  } while( true );
}


// ---- 110066bc FUN_110066bc  (called by: InitMap@1100487d)

undefined4 __cdecl FUN_110066bc(LPCSTR param_1,void *param_2)

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
  pFVar1 = (FILE *)FUN_11006638((uint3)extraout_ECX,param_1);
  if (pFVar1 == (FILE *)0x0) {
    uVar3 = 0;
  }
  else {
    FUN_110065f7((int *)pFVar1);
    FUN_11009497((char *)&local_8,4,1,(int *)pFVar1);
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
        FUN_11009497((char *)piVar2,0x18,1,(int *)pFVar1);
        if ((pFVar1->_flag & 0x10) != 0) {
          FUN_1100947e(piVar2);
          break;
        }
        if ((*piVar2 == 0x2f) || (*piVar2 == 0x37)) {
          iVar4 = 0xc;
          do {
            FUN_11009497(local_10,4,1,(int *)pFVar1);
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        uVar3 = FUN_11006898(piVar2);
        if ((char)uVar3 == '\0') {
          FUN_1100947e(piVar2);
        }
        else {
          FUN_110069c3(param_2,(int)piVar2);
        }
      }
    }
    uVar3 = FUN_11008de9(pFVar1);
    uVar3 = CONCAT31((int3)((uint)uVar3 >> 8),1);
  }
  return uVar3;
}


// ---- 1100678e FUN_1100678e  (called by: InitMap@1100487d)

void __cdecl
FUN_1100678e(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,char param_5,
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


// ---- 1100684b FUN_1100684b  (called by: InitMap@1100487d)

int * __cdecl FUN_1100684b(undefined4 param_1,int *param_2,int param_3,int *param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  IUnit local_8 [4];
  
  IUnit::IUnit(local_8);
  *param_4 = *param_4 + 1;
  iVar1 = *param_4;
  if (iVar1 < *param_2) {
    do {
      piVar2 = (int *)FUN_110069cf(param_2,iVar1);
      if ((*piVar2 == param_3) || (param_3 == -1)) {
        if (piVar2[1] == param_5) {
          return piVar2;
        }
        if (param_5 == -1) {
          return piVar2;
        }
      }
      *param_4 = *param_4 + 1;
      iVar1 = *param_4;
    } while (iVar1 < *param_2);
  }
  return (int *)0x0;
}


// ---- 11006898 FUN_11006898  (called by: FUN_110066bc@110066bc)

undefined4 __fastcall FUN_11006898(int *param_1)

{
  if ((*param_1 < 0x11) || (0x6e < *param_1)) {
    return 1;
  }
  return 0;
}


// ---- 110068ab FUN_110068ab  (called by: FUN_110065ad@110065ad)

int * __thiscall FUN_110068ab(int *param_1,_Player param_2)

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


// ---- 11006917 FUN_11006917  (called by: InitMap@1100487d)

void __fastcall FUN_11006917(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return;
}


// ---- 11006926 FUN_11006926  (called by: FUN_110069c3@110069c3)

uint __thiscall FUN_11006926(void *this,int param_1)

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
      piVar2 = FUN_110095ae(*(int **)((int)this + 4),(uint *)(*(int *)this << 2));
    }
    *(int **)((int)this + 4) = piVar2;
    iVar1 = *(int *)this;
    *(int *)(*(int *)((int)this + 4) + -4 + iVar1 * 4) = param_1;
    uVar3 = CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  return uVar3;
}


// ---- 11006969 FUN_11006969  (called by: FUN_110069dc@110069dc)

uint __thiscall FUN_11006969(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  if (param_1 < *(int *)this) {
    iVar3 = param_1 + 1;
    if (iVar3 < *(int *)this) {
      do {
        iVar1 = iVar3 * 4;
        iVar2 = iVar3 * 4;
        iVar3 = iVar3 + 1;
        *(undefined4 *)(*(int *)((int)this + 4) + iVar2 + -4) =
             *(undefined4 *)(*(int *)((int)this + 4) + iVar1);
      } while (iVar3 < *(int *)this);
    }
    iVar3 = *(int *)this;
    piVar4 = (int *)0x0;
    if (iVar3 != 0) {
      *(int *)this = iVar3 + -1;
      piVar4 = FUN_110095ae(*(int **)((int)this + 4),(uint *)(iVar3 << 2));
      *(int **)((int)this + 4) = piVar4;
    }
    uVar5 = CONCAT31((int3)((uint)piVar4 >> 8),1);
  }
  else {
    uVar5 = param_1 & 0xffffff00;
  }
  return uVar5;
}


// ---- 110069b2 FUN_110069b2  (called by: FUN_11006a05@11006a05)

void __fastcall FUN_110069b2(undefined4 *param_1)

{
  FUN_11008da1((LPVOID)param_1[1]);
  *param_1 = 0;
  return;
}


// ---- 110069c3 FUN_110069c3  (called by: FUN_110066bc@110066bc)

void __thiscall FUN_110069c3(void *this,int param_1)

{
  FUN_11006926(this,param_1);
  return;
}


// ---- 110069cf FUN_110069cf  (called by: FUN_1100472d@1100472d, FUN_1100684b@1100684b)

undefined4 __thiscall FUN_110069cf(void *this,int param_1)

{
  return *(undefined4 *)(*(int *)((int)this + 4) + param_1 * 4);
}


// ---- 110069dc FUN_110069dc  (called by: FUN_1100472d@1100472d)

uint __thiscall FUN_110069dc(void *this,int param_1)

{
  uint in_EAX;
  uint uVar1;
  
  if (param_1 < *(int *)this) {
    FUN_1100947e(*(LPVOID *)(*(int *)((int)this + 4) + param_1 * 4));
    uVar1 = FUN_11006969(this,param_1);
  }
  else {
    uVar1 = in_EAX & 0xffffff00;
  }
  return uVar1;
}


// ---- 11006a05 FUN_11006a05  (called by: InitMap@1100487d)

void __fastcall FUN_11006a05(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    FUN_1100947e(*(LPVOID *)(param_1[1] + iVar1 * 4));
  }
  FUN_110069b2(param_1);
  return;
}


// ---- 11006a26 FUN_11006a26  (called by: InitProc@11005892)

bool FUN_11006a26(void)

{
  return DAT_004e971c == 'Q';
}


// ---- 11006a33 FUN_11006a33  (called by: FUN_11005f7f@11005f7f)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_11006a33(void)

{
  return _DAT_0056eb34 == 3;
}


// ---- 11006a40 FUN_11006a40  (called by: FUN_11005f7f@11005f7f, FUN_11006aa8@11006aa8)

undefined * __cdecl FUN_11006a40(uint *param_1,byte *param_2)

{
  byte *pbVar1;
  byte local_208 [256];
  byte local_108 [256];
  byte local_8 [4];
  
  pbVar1 = (byte *)GetCurrentModDir();
  if (pbVar1 == (byte *)0x0) {
    FUN_110096f0((uint *)&DAT_110198d4,param_1);
  }
  else {
    FUN_11009871(pbVar1,local_8,local_208,local_108,local_108);
    FUN_110097e0(&DAT_110198d4,local_8,local_208,(byte *)param_1,param_2);
  }
  return &DAT_110198d4;
}


// ---- 11006aa8 FUN_11006aa8  (called by: FUN_11005f7f@11005f7f)

void __cdecl FUN_11006aa8(uint *param_1)

{
  size_t sVar1;
  undefined *puVar2;
  uint *puVar3;
  uint local_54 [20];
  
  GetGameDir(local_54);
  sVar1 = _strlen((char *)local_54);
  FUN_11009700(local_54,param_1);
  FUN_11009700(local_54,(uint *)&DAT_11015220);
  FUN_110060c3((LPCSTR)local_54,'\0');
  FUN_110096f0((uint *)((int)local_54 + sVar1),(uint *)s_music2_wav_11015214);
  puVar3 = local_54;
  puVar2 = FUN_11006a40(param_1,&DAT_1101520c);
  FUN_110011fe(puVar2,(LPCSTR)puVar3);
  return;
}


// ---- 11006b19 FUN_11006b19  (called by: InitProc@11005892)

void __cdecl FUN_11006b19(undefined1 param_1)

{
  DAT_110198cc = param_1;
  FUN_11007a30('\x01','\0',500,FUN_11006def,0);
  return;
}


// ---- 11006b3b FUN_11006b3b  (called by: FUN_11006bbc@11006bbc)

bool __cdecl FUN_11006b3b(Unit param_1)

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


// ---- 11006bbc FUN_11006bbc  (called by: FUN_11006c6b@11006c6b)

undefined4 __cdecl FUN_11006bbc(LOCATION param_1,undefined4 param_2,int param_3)

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
LAB_11006be9:
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
      bVar3 = FUN_11006b3b(SUB41(local_8,0));
      if (bVar3) goto LAB_11006be9;
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


// ---- 11006c6b FUN_11006c6b  (called by: FUN_11006def@11006def)

void __cdecl FUN_11006c6b(int param_1)

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
    if ((DAT_110198cc != '\0') || (local_10 != 0x17)) {
      PlayerBuildingEnum::PlayerBuildingEnum(local_18,param_1,local_10);
LAB_11006cb4:
      iVar1 = PlayerBuildingEnum::GetNext(local_18,(Unit *)&local_8);
      if (iVar1 != 0) {
        iVar1 = IUnit::GetDamage((IUnit *)&local_8);
        if (iVar1 < 0x65) {
          *(undefined4 *)(&DAT_110160cc + (local_8 * 7 + param_1) * 4) = 0;
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
                if (0 < *(int *)(&DAT_110160cc + (local_8 * 7 + param_1) * 4)) {
                  Unit::SetId((Unit *)local_c,*(int *)(&DAT_110160cc + (local_8 * 7 + param_1) * 4))
                  ;
                  cVar2 = IUnit::GetBusy(local_c);
                  if (cVar2 == 0x1c) {
                    iVar1 = Unit::IsLive((Unit *)local_c);
                    if (iVar1 != 0) {
                      mVar3 = Unit::GetType((Unit *)local_c);
                      if (mVar3 == 2) goto LAB_11006cb4;
                    }
                  }
                  *(undefined4 *)(&DAT_110160cc + (local_8 * 7 + param_1) * 4) = 0;
                }
                puVar5 = local_20;
                puVar4 = (undefined4 *)Unit::Location((Unit *)&local_8);
                iVar1 = FUN_11006bbc(SUB41(*puVar4,0),puVar4[1],(int)puVar5);
                if (0 < iVar1) {
                  Unit::SetId((Unit *)local_c,iVar1);
                  Unit::GetType((Unit *)local_c);
                  Unit::OwnerID((Unit *)local_c);
                  IUnit::Repair(local_c,local_8);
                  *(int *)(&DAT_110160cc + (local_8 * 7 + param_1) * 4) = iVar1;
                }
              }
            }
          }
        }
        goto LAB_11006cb4;
      }
    }
    local_10 = local_10 + 1;
    if (0x3a < (int)local_10) {
      return;
    }
  } while( true );
}


// ---- 11006def FUN_11006def  (called by: -)

void FUN_11006def(void)

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
        FUN_11006c6b(iVar3);
      }
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + 0xc;
      iVar2 = TethysGame::NoPlayers();
    } while (iVar3 < iVar2);
  }
  return;
}


// ---- 11006ea0 AIProc  (called by: -)

void AIProc(void)

{
                    /* 0x6ea0  4  AIProc */
  FUN_11007070(&DAT_11020178);
  return;
}


// ---- 11006eb0 FUN_11006eb0  (called by: FUN_1100107a@1100107a, FUN_1100137e@1100137e, FUN_110077d0@110077d0, FUN_110078e0@110078e0, FUN_11007a60@11007a60, FUN_11007b80@11007b80, FUN_11007d30@11007d30, FUN_11007ec0@11007ec0, FUN_11008030@11008030)

undefined4 * __thiscall FUN_11006eb0(void *this,char param_1,char param_2,undefined4 param_3)

{
  *(undefined ***)this = &PTR_LAB_11010410;
  FUN_11006ef0(this,param_1,param_2,param_3);
  return this;
}


// ---- 11006ee0 FUN_11006ee0  (called by: FUN_11002425@11002425, FUN_1100247b@1100247b, FUN_110024f3@110024f3, FUN_110025b8@110025b8, FUN_11002cfe@11002cfe, FUN_11002f76@11002f76, FUN_1100301d@1100301d, FUN_11003880@11003880, FUN_11003b26@11003b26, FUN_11003c21@11003c21, FUN_11006f30@11006f30)

void __fastcall FUN_11006ee0(int param_1)

{
  *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) | 0x20;
  return;
}


// ---- 11006ef0 FUN_11006ef0  (called by: FUN_11006eb0@11006eb0)

void __thiscall FUN_11006ef0(void *this,char param_1,char param_2,undefined4 param_3)

{
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined2 *)((int)this + 4) = 0;
  *(byte *)((int)this + 6) = param_1 != '\0' | (-(param_2 != '\0') & 2U) + 2 | 8;
  *(undefined4 *)((int)this + 0xc) = param_3;
  return;
}


// ---- 11006f30 FUN_11006f30  (called by: FUN_110010b9@110010b9, FUN_110013c4@110013c4, FUN_11007820@11007820, FUN_11007980@11007980, FUN_11007ab0@11007ab0, FUN_11007dd0@11007dd0, FUN_11008070@11008070)

void __fastcall FUN_11006f30(int param_1)

{
  byte bVar1;
  
  if (*(code **)(param_1 + 0xc) != (code *)0x0) {
    *(short *)(param_1 + 4) = *(short *)(param_1 + 4) + 1;
    (**(code **)(param_1 + 0xc))(param_1);
    bVar1 = *(byte *)(param_1 + 6);
    if (((bVar1 & 2) == 0) && (*(byte *)(param_1 + 6) = bVar1 & 0xfe, (bVar1 & 4) != 0)) {
      FUN_11006ee0(param_1);
    }
  }
  return;
}


// ---- 11006f80 FUN_11006f80  (called by: FUN_11001121@11001121, FUN_11001417@11001417, FUN_11007870@11007870, FUN_110079c0@110079c0, FUN_11007b00@11007b00, FUN_11007c40@11007c40, FUN_11007e50@11007e50, FUN_11007f90@11007f90, FUN_110080a0@110080a0)

void __thiscall FUN_11006f80(void *this,int param_1)

{
  int iVar1;
  
  iVar1 = FUN_11007010(this,param_1);
  if (iVar1 < 0) {
    if (*(int *)((int)this + 4) == 0x200) {
      (*DAT_1101040c)(s_ERROR_1101524c,0x10);
      return;
    }
    *(int *)(*(int *)this + *(int *)((int)this + 4) * 4) = param_1;
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  }
  return;
}


// ---- 11006fd0 FUN_11006fd0  (called by: FUN_11007150@11007150)

void __thiscall FUN_11006fd0(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = FUN_11007010(this,param_1);
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


// ---- 11007010 FUN_11007010  (called by: FUN_11006f80@11006f80, FUN_11006fd0@11006fd0)

void __thiscall FUN_11007010(void *this,int param_1)

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


// ---- 11007030 FUN_11007030  (called by: FUN_11007070@11007070)

void FUN_11007030(void)

{
  if (DAT_110198d0 == '\0') {
    if (DAT_110291d0 != DAT_11019924) {
      DAT_110198d0 = '\x01';
      if (DAT_110291d0 == 0) {
        DAT_110291d0 = DAT_11019924;
        return;
      }
      (*DAT_1101040c)(s_WARNING_1101529c,0x30);
    }
  }
  return;
}


// ---- 11007070 FUN_11007070  (called by: AIProc@11006ea0)

void __fastcall FUN_11007070(int *param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_1100f1c0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_11007030();
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
  FUN_11007150(param_1);
  ExceptionList = local_10;
  return;
}


// ---- 110070e1 Catch@110070e1  (called by: -)

undefined * Catch_110070e1(void)

{
  int unaff_EBP;
  
  scr_snprintf((char *)(unaff_EBP + -0x6c),0x50,s_Error_executing_event__02X_ID__0_110152b0,
               *(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 8),
               *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0xc));
  (*DAT_1101040c)(s_EventError_110152a4,0x30);
  return FUN_1100711c;
}


// ---- 1100711c FUN_1100711c  (called by: -)

void FUN_1100711c(void)

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
        FUN_11007150(piVar4);
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


// ---- 11007150 FUN_11007150  (called by: FUN_1100711c@1100711c)

void __fastcall FUN_11007150(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[1];
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    iVar2 = *(int *)(*param_1 + iVar1 * 4);
    if ((iVar2 != 0) && ((*(byte *)(iVar2 + 6) & 0x20) != 0)) {
      FUN_11006fd0(param_1,iVar2);
      FUN_110072b0(iVar2);
    }
  }
  return;
}


// ---- 11007190 FUN_11007190  (called by: FUN_110010b9@110010b9, FUN_11007820@11007820, FUN_11007ab0@11007ab0)

bool __cdecl FUN_11007190(int param_1,int param_2,undefined4 param_3)

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


// ---- 11007200 FUN_11007200  (called by: FUN_11007220@11007220, FUN_110072b0@110072b0)

undefined * FUN_11007200(LPCSTR param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_retaddr;
  
  MessageBoxA((HWND)0x0,param_1,s_ERROR_1101524c,0x10);
  FUN_11009c11(0xffffffff);
  iVar2 = (unaff_retaddr - 1U >> 4) + 1;
  iVar5 = 0;
  do {
    cVar1 = (&DAT_11028980)[iVar5];
    iVar4 = 0;
    while (cVar1 == '\0') {
      iVar3 = iVar4 + 1;
      if (iVar3 == iVar2) {
        for (; 0 < iVar4; iVar4 = iVar4 + -1) {
          (&DAT_11028980)[iVar4 + iVar5] = 0xff;
        }
        (&DAT_11028980)[iVar5] = (char)iVar2;
        return &DAT_11020980 + iVar5 * 0x10;
      }
      if (0x7ff < iVar3 + iVar5) {
        FUN_11007200(s__new__Out_of_memory_110152e4);
      }
      iVar4 = iVar3;
      cVar1 = (&DAT_11028980)[iVar3 + iVar5];
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x800);
  FUN_11007200(s__new__Out_of_memory_110152e4);
  return (undefined *)0x0;
}


// ---- 11007220 FUN_11007220  (called by: FUN_11001121@11001121, FUN_11001417@11001417, FUN_11007870@11007870, FUN_110079c0@110079c0, FUN_11007b00@11007b00, FUN_11007c40@11007c40, FUN_11007e50@11007e50, FUN_11007f90@11007f90, FUN_110080a0@110080a0)

undefined * __cdecl FUN_11007220(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = (param_1 - 1U >> 4) + 1;
  iVar5 = 0;
  do {
    cVar1 = (&DAT_11028980)[iVar5];
    iVar4 = 0;
    while (cVar1 == '\0') {
      iVar3 = iVar4 + 1;
      if (iVar3 == iVar2) {
        for (; 0 < iVar4; iVar4 = iVar4 + -1) {
          (&DAT_11028980)[iVar4 + iVar5] = 0xff;
        }
        (&DAT_11028980)[iVar5] = (char)iVar2;
        return &DAT_11020980 + iVar5 * 0x10;
      }
      if (0x7ff < iVar3 + iVar5) {
        FUN_11007200(s__new__Out_of_memory_110152e4);
      }
      iVar4 = iVar3;
      cVar1 = (&DAT_11028980)[iVar3 + iVar5];
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x800);
  FUN_11007200(s__new__Out_of_memory_110152e4);
  return (undefined *)0x0;
}


// ---- 110072b0 FUN_110072b0  (called by: FUN_11007150@11007150)

void __cdecl FUN_110072b0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (int)(param_1 + -0x11020980 + (param_1 + -0x11020980 >> 0x1f & 0xfU)) >> 4;
  iVar2 = (int)(char)(&DAT_11028980)[iVar1];
  if ((iVar2 < 1) || (0xfe < iVar2)) {
    FUN_11007200(s__delete__Invalid_pointer_supplie_110152f8);
  }
  else {
    iVar2 = iVar2 + -1;
    if (-1 < iVar2) {
      do {
        (&DAT_11028980)[iVar2 + iVar1] = 0;
        iVar2 = iVar2 + -1;
      } while (-1 < iVar2);
      return;
    }
  }
  return;
}


// ---- 11007300 FUN_11007300  (called by: FUN_1100301d@1100301d, FUN_11003503@11003503, FUN_11003e3c@11003e3c, FUN_110074a0@110074a0)

int __cdecl FUN_11007300(int param_1,map_id param_2,map_id param_3)

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


// ---- 11007390 FUN_11007390  (called by: FUN_110073b0@110073b0)

undefined4 __cdecl FUN_11007390(IUnit param_1)

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


// ---- 110073b0 FUN_110073b0  (called by: FUN_11007820@11007820)

int __cdecl FUN_110073b0(int param_1,map_id param_2)

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
    uVar2 = FUN_11007390(SUB41(local_c,0));
    if ((char)uVar2 != '\0') {
      iVar3 = iVar3 + 1;
    }
    iVar1 = PlayerBuildingEnum::GetNext(local_8,(Unit *)&local_c);
  }
  return iVar3;
}


// ---- 11007420 FUN_11007420  (called by: FUN_1100301d@1100301d, FUN_11003503@11003503, FUN_11003880@11003880, FUN_11003e3c@11003e3c, FUN_110043c0@110043c0, FUN_110074a0@110074a0)

int __cdecl FUN_11007420(int param_1,map_id param_2,map_id param_3)

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


// ---- 110074a0 FUN_110074a0  (called by: FUN_11007ab0@11007ab0)

void __cdecl FUN_110074a0(int param_1,map_id param_2,map_id param_3)

{
  if ((int)param_2 < 0x11) {
    FUN_11007420(param_1,param_2,param_3);
    return;
  }
  FUN_11007300(param_1,param_2,param_3);
  return;
}


// ---- 110074d0 FUN_110074d0  (called by: InitProc@11005892)

void FUN_110074d0(void)

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


// ---- 11007520 FUN_11007520  (called by: FUN_11002b0d@11002b0d, FUN_11002cfe@11002cfe, FUN_1100301d@1100301d, FUN_11003e3c@11003e3c, FUN_11004240@11004240, FUN_110043c0@110043c0, FUN_1100440c@1100440c)

void FUN_11007520(ScGroup *param_1,undefined4 param_2,map_id param_3)

{
  int iVar1;
  map_id mVar2;
  undefined1 auStackY_ac [128];
  GroupEnumerator local_1c [4];
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_1100f1d0;
  pvStack_10 = ExceptionList;
  local_14 = auStackY_ac + 0x84;
  local_18 = 0;
  ExceptionList = &pvStack_10;
  GroupEnumerator::GroupEnumerator(local_1c,param_1);
  do {
    iVar1 = GroupEnumerator::GetNext(local_1c,(Unit *)&local_18);
    if (iVar1 == 0) {
      ExceptionList = pvStack_10;
      return;
    }
    if (param_3 == 0xffffffff) break;
    mVar2 = Unit::GetType((Unit *)&local_18);
  } while (mVar2 != param_3);
  local_8 = 0;
  ScGroup::RemoveUnit(param_1,local_18);
  FUN_1100759a();
  return;
}


// ---- 11007591 Catch@11007591  (called by: -)

undefined * Catch_11007591(void)

{
  return FUN_11007597;
}


// ---- 11007597 FUN_11007597  (called by: -)

void FUN_11007597(void)

{
  map_id mVar1;
  int iVar2;
  map_id mVar3;
  int unaff_EBP;
  
  mVar1 = *(map_id *)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScGroup::TakeUnit(*(ScGroup **)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + -0x14));
  do {
    iVar2 = GroupEnumerator::GetNext
                      ((GroupEnumerator *)(unaff_EBP + -0x18),(Unit *)(unaff_EBP + -0x14));
    if (iVar2 == 0) {
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return;
    }
    if (mVar1 == 0xffffffff) break;
    mVar3 = Unit::GetType((Unit *)(unaff_EBP + -0x14));
  } while (mVar3 != mVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  ScGroup::RemoveUnit(*(ScGroup **)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x14));
  FUN_1100759a();
  return;
}


// ---- 1100759a FUN_1100759a  (called by: FUN_11007520@11007520)

void FUN_1100759a(void)

{
  int iVar1;
  map_id mVar2;
  int unaff_EBP;
  map_id unaff_ESI;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScGroup::TakeUnit(*(ScGroup **)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + -0x14));
  do {
    iVar1 = GroupEnumerator::GetNext
                      ((GroupEnumerator *)(unaff_EBP + -0x18),(Unit *)(unaff_EBP + -0x14));
    if (iVar1 == 0) {
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return;
    }
    if (unaff_ESI == 0xffffffff) break;
    mVar2 = Unit::GetType((Unit *)(unaff_EBP + -0x14));
  } while (mVar2 != unaff_ESI);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  ScGroup::RemoveUnit(*(ScGroup **)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x14));
  FUN_1100759a();
  return;
}


// ---- 110075d0 FUN_110075d0  (called by: FUN_1100301d@1100301d, FUN_11003fa7@11003fa7, FUN_11004a66@11004a66)

void __cdecl FUN_110075d0(MAP_RECT param_1)

{
  int iVar1;
  map_id mVar2;
  map_id in_stack_00000014;
  map_id in_stack_00000018;
  int in_stack_0000001c;
  ScGroup *in_stack_00000020;
  undefined4 local_38;
  InRectEnumerator local_34 [52];
  
  local_38 = 0;
  InRectEnumerator::InRectEnumerator(local_34,&param_1);
  iVar1 = InRectEnumerator::GetNext(local_34,(Unit *)&local_38);
  while (iVar1 != 0) {
    iVar1 = Unit::OwnerID((Unit *)&local_38);
    if (((iVar1 == in_stack_0000001c) &&
        ((in_stack_00000014 == 0xffffffff ||
         (mVar2 = Unit::GetType((Unit *)&local_38), mVar2 == in_stack_00000014)))) &&
       ((in_stack_00000018 == 0xffffffff ||
        (mVar2 = Unit::GetWeapon((Unit *)&local_38), mVar2 == in_stack_00000018)))) {
      ScGroup::TakeUnit(in_stack_00000020,local_38);
    }
    iVar1 = InRectEnumerator::GetNext(local_34,(Unit *)&local_38);
  }
  return;
}


// ---- 11007670 FUN_11007670  (called by: FUN_11002c69@11002c69)

void __cdecl FUN_11007670(ScStub param_1)

{
  Unit *this;
  int iVar1;
  undefined1 auStackY_12c [128];
  Unit local_9c [128];
  GroupEnumerator local_1c [4];
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  pcStack_c = FUN_1100f1e9;
  local_10 = ExceptionList;
  local_14 = auStackY_12c + 0x84;
  this = local_9c;
  local_8 = 0;
  local_18 = 0;
  iVar1 = 0x20;
  ExceptionList = &local_10;
  do {
    Unit::Unit(this);
    this = this + 4;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  GroupEnumerator::GroupEnumerator(local_1c,(ScGroup *)&param_1);
  while( true ) {
    iVar1 = GroupEnumerator::GetNext(local_1c,(Unit *)&local_18);
    if (iVar1 == 0) break;
    local_8 = CONCAT31(local_8._1_3_,1);
    ScGroup::RemoveUnit((ScGroup *)&param_1,local_18);
    local_8 = 0;
  }
  local_8 = 0xffffffff;
  ScStub::~ScStub(&param_1);
  ExceptionList = local_10;
  return;
}


// ---- 110076e9 Catch@110076e9  (called by: -)

undefined * Catch_110076e9(void)

{
  return FUN_110076ef;
}


// ---- 110076ef FUN_110076ef  (called by: -)

void FUN_110076ef(void)

{
  int iVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  while( true ) {
    iVar1 = GroupEnumerator::GetNext
                      ((GroupEnumerator *)(unaff_EBP + -0x18),(Unit *)(unaff_EBP + -0x14));
    if (iVar1 == 0) break;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    ScGroup::RemoveUnit((ScGroup *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x14));
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ScStub::~ScStub((ScStub *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


// ---- 11007720 FUN_11007720  (called by: FUN_11001f55@11001f55)

uint __cdecl FUN_11007720(int param_1,ScStub param_2)

{
  int iVar1;
  uint extraout_EAX;
  undefined4 extraout_EAX_00;
  int local_14;
  GroupEnumerator local_10 [4];
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_1100f209;
  local_c = ExceptionList;
  local_4 = 0;
  local_14 = 0;
  ExceptionList = &local_c;
  GroupEnumerator::GroupEnumerator(local_10,(ScGroup *)&param_2);
  iVar1 = GroupEnumerator::GetNext(local_10,(Unit *)&local_14);
  while( true ) {
    if (iVar1 == 0) {
      local_4 = 0xffffffff;
      ScStub::~ScStub(&param_2);
      ExceptionList = local_c;
      return extraout_EAX & 0xffffff00;
    }
    if (local_14 == param_1) break;
    iVar1 = GroupEnumerator::GetNext(local_10,(Unit *)&local_14);
  }
  local_4 = 0xffffffff;
  ScStub::~ScStub(&param_2);
  ExceptionList = local_c;
  return CONCAT31((int3)((uint)extraout_EAX_00 >> 8),1);
}


// ---- 110077d0 FUN_110077d0  (called by: FUN_11007870@11007870)

undefined4 * __thiscall
FUN_110077d0(void *this,char param_1,char param_2,undefined1 param_3,undefined4 param_4,
            undefined1 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  FUN_11006eb0(this,param_1,param_2,param_7);
  *(undefined1 *)((int)this + 0x10) = param_3;
  *(undefined1 *)((int)this + 0x11) = param_5;
  *(undefined4 *)((int)this + 0x18) = param_6;
  *(undefined ***)this = &PTR_FUN_11010414;
  *(undefined4 *)((int)this + 0x14) = param_4;
  *(undefined4 *)((int)this + 8) = param_8;
  return this;
}


// ---- 11007820 FUN_11007820  (called by: -)

void __fastcall FUN_11007820(int param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  
  cVar1 = *(char *)(param_1 + 0x10);
  iVar3 = TethysGame::NoPlayers();
  if (cVar1 < iVar3) {
    iVar3 = FUN_110073b0((int)cVar1,*(map_id *)(param_1 + 0x14));
    *(char *)(param_1 + 0x12) = (char)iVar3;
    bVar2 = FUN_11007190((int)(char)iVar3,(int)*(char *)(param_1 + 0x11),
                         *(undefined4 *)(param_1 + 0x18));
    if (bVar2) {
      FUN_11006f30(param_1);
    }
  }
  return;
}


// ---- 11007870 FUN_11007870  (called by: FUN_110021c8@110021c8, FUN_110022f0@110022f0, FUN_1100247b@1100247b, FUN_11003503@11003503, FUN_11003880@11003880, FUN_11003b26@11003b26)

undefined4 * __cdecl
FUN_11007870(char param_1,char param_2,undefined1 param_3,undefined4 param_4,undefined1 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_1c [7];
  
  puVar1 = (undefined4 *)FUN_11007220(0x1c);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_110077d0(local_1c,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  puVar3 = local_1c;
  puVar4 = puVar1;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_11006f80(&DAT_11020178,(int)puVar1);
  return puVar1;
}


// ---- 110078e0 FUN_110078e0  (called by: FUN_110079c0@110079c0)

undefined4 * __thiscall
FUN_110078e0(void *this,char param_1,char param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  
  FUN_11006eb0(this,param_1,param_2,param_5);
  *(undefined ***)this = &PTR_FUN_11010418;
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
  FUN_11007940((int)this);
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 8) = param_6;
  return this;
}


// ---- 11007940 FUN_11007940  (called by: FUN_110078e0@110078e0, FUN_11007980@11007980)

void __fastcall FUN_11007940(int param_1)

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


// ---- 11007980 FUN_11007980  (called by: -)

void __fastcall FUN_11007980(int param_1)

{
  int iVar1;
  
  iVar1 = TethysGame::Tick();
  if ((*(int *)(param_1 + 0x18) <= iVar1) && (*(int *)(param_1 + 0x1c) < *(int *)(param_1 + 0x18)))
  {
    FUN_11006f30(param_1);
    if ((*(byte *)(param_1 + 6) & 0x20) != 0) {
      return;
    }
    if ((*(byte *)(param_1 + 6) & 2) != 0) {
      FUN_11007940(param_1);
    }
  }
  *(int *)(param_1 + 0x1c) = iVar1;
  return;
}


// ---- 110079c0 FUN_110079c0  (called by: FUN_11004240@11004240, FUN_11004564@11004564, FUN_11007a30@11007a30, InitProc@11005892)

undefined4 * __cdecl
FUN_110079c0(char param_1,char param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6
            )

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_20 [8];
  
  puVar1 = (undefined4 *)FUN_11007220(0x20);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_110078e0(local_20,param_1,param_2,param_3,param_4,param_5,param_6);
  puVar3 = local_20;
  puVar4 = puVar1;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_11006f80(&DAT_11020178,(int)puVar1);
  return puVar1;
}


// ---- 11007a30 FUN_11007a30  (called by: FUN_11002292@11002292, FUN_110024f3@110024f3, FUN_11002a51@11002a51, FUN_11002cfe@11002cfe, FUN_11003c21@11003c21, FUN_11003e3c@11003e3c, FUN_110040e2@110040e2, FUN_11004240@11004240, FUN_110045e9@110045e9, FUN_11005629@11005629, FUN_11006b19@11006b19, InitProc@11005892)

void __cdecl
FUN_11007a30(char param_1,char param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  FUN_110079c0(param_1,param_2,param_3,param_3,param_4,param_5);
  return;
}


// ---- 11007a60 FUN_11007a60  (called by: FUN_11007b00@11007b00)

undefined4 * __thiscall
FUN_11007a60(void *this,char param_1,char param_2,undefined1 param_3,undefined4 param_4,
            undefined4 param_5,undefined1 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  FUN_11006eb0(this,param_1,param_2,param_8);
  *(undefined1 *)((int)this + 0x10) = param_3;
  *(undefined1 *)((int)this + 0x11) = param_6;
  *(undefined4 *)((int)this + 0x14) = param_4;
  *(undefined4 *)((int)this + 0x18) = param_5;
  *(undefined ***)this = &PTR_FUN_1101041c;
  *(undefined4 *)((int)this + 0x1c) = param_7;
  *(undefined4 *)((int)this + 8) = param_9;
  return this;
}


// ---- 11007ab0 FUN_11007ab0  (called by: -)

void __fastcall FUN_11007ab0(int param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  
  cVar1 = *(char *)(param_1 + 0x10);
  iVar3 = TethysGame::NoPlayers();
  if (cVar1 < iVar3) {
    cVar1 = FUN_110074a0((int)cVar1,*(map_id *)(param_1 + 0x14),*(map_id *)(param_1 + 0x18));
    *(char *)(param_1 + 0x12) = cVar1;
    bVar2 = FUN_11007190((int)cVar1,(int)*(char *)(param_1 + 0x11),*(undefined4 *)(param_1 + 0x1c));
    if (bVar2) {
      FUN_11006f30(param_1);
    }
  }
  return;
}


// ---- 11007b00 FUN_11007b00  (called by: FUN_1100247b@1100247b, FUN_110024f3@110024f3, FUN_1100301d@1100301d, FUN_11003503@11003503, FUN_11003e3c@11003e3c)

undefined4 * __cdecl
FUN_11007b00(char param_1,char param_2,undefined1 param_3,undefined4 param_4,undefined4 param_5,
            undefined1 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_20 [8];
  
  puVar1 = (undefined4 *)FUN_11007220(0x20);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_11007a60(local_20,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  puVar3 = local_20;
  puVar4 = puVar1;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_11006f80(&DAT_11020178,(int)puVar1);
  return puVar1;
}


// ---- 11007b80 FUN_11007b80  (called by: FUN_11007c40@11007c40)

undefined4 * __thiscall
FUN_11007b80(undefined4 *param_1,char param_2,char param_3,undefined1 param_4,MAP_RECT param_5)

{
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  
  FUN_11006eb0(param_1,param_2,param_3,in_stack_00000020);
  MAP_RECT::MAP_RECT((MAP_RECT *)(param_1 + 5));
  *param_1 = &PTR_LAB_11010420;
  *(undefined1 *)(param_1 + 4) = param_4;
  MAP_RECT::operator=((MAP_RECT *)(param_1 + 5),&param_5);
  param_1[2] = in_stack_00000024;
  return param_1;
}


// ---- 11007c40 FUN_11007c40  (called by: FUN_11007cc0@11007cc0)

undefined4 * __cdecl FUN_11007c40(char param_1,char param_2,undefined1 param_3,MAP_RECT param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_24 [9];
  
  puVar1 = (undefined4 *)FUN_11007220(0x24);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_11007b80(local_24,param_1,param_2,param_3,param_4);
    puVar3 = local_24;
    puVar4 = puVar1;
    for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_11006f80(&DAT_11020178,(int)puVar1);
  }
  return puVar1;
}


// ---- 11007cc0 FUN_11007cc0  (called by: FUN_1100256d@1100256d, FUN_11005629@11005629)

void __cdecl
FUN_11007cc0(char param_1,char param_2,undefined1 param_3,int param_4,int param_5,int param_6,
            int param_7)

{
  undefined4 *puVar1;
  MAP_RECT local_10 [16];
  
  puVar1 = (undefined4 *)
           MAP_RECT::MAP_RECT(local_10,param_4,param_5,param_6 + param_4,param_5 + param_7);
  FUN_11007c40(param_1,param_2,param_3,SUB41(*puVar1,0));
  return;
}


// ---- 11007d30 FUN_11007d30  (called by: FUN_11007e50@11007e50)

undefined4 * __thiscall
FUN_11007d30(void *this,char param_1,char param_2,ScStub *param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  char cVar1;
  int iVar2;
  
  FUN_11006eb0(this,param_1,param_2,param_5);
  *(undefined ***)this = &PTR_FUN_11010424;
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


// ---- 11007dd0 FUN_11007dd0  (called by: -)

void __fastcall FUN_11007dd0(int param_1)

{
  int iVar1;
  int local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_1100f229;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_10 = param_1;
  ScGroup::ScGroup((ScGroup *)&local_10);
  local_4 = 0;
  ScStub::SetId((ScStub *)&local_10,(int)*(char *)(param_1 + 0x10));
  iVar1 = ScGroup::TotalUnitCount((ScGroup *)&local_10);
  if (iVar1 <= *(char *)(param_1 + 0x12)) {
    FUN_11006f30(param_1);
  }
  local_4 = 0xffffffff;
  ScStub::~ScStub((ScStub *)&local_10);
  ExceptionList = local_c;
  return;
}


// ---- 11007e50 FUN_11007e50  (called by: FUN_11002cfe@11002cfe, FUN_11002f76@11002f76)

undefined4 * __cdecl
FUN_11007e50(char param_1,char param_2,ScStub *param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_14 [5];
  
  puVar1 = (undefined4 *)FUN_11007220(0x14);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_11007d30(local_14,param_1,param_2,param_3,param_4,param_5,param_6);
  puVar3 = local_14;
  puVar4 = puVar1;
  for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_11006f80(&DAT_11020178,(int)puVar1);
  return puVar1;
}


// ---- 11007ec0 FUN_11007ec0  (called by: FUN_11007f90@11007f90)

undefined4 * __thiscall
FUN_11007ec0(undefined4 *param_1,char param_2,char param_3,undefined1 param_4,LOCATION param_5,
            undefined4 param_6,undefined4 param_7)

{
  FUN_11006eb0(param_1,param_2,param_3,param_7);
  param_1[5] = 0;
  param_1[6] = 0;
  *param_1 = &PTR_LAB_11010428;
  *(undefined1 *)(param_1 + 4) = param_4;
  LOCATION::operator=((LOCATION *)(param_1 + 5),&param_5);
  param_1[2] = 0;
  return param_1;
}


// ---- 11007f90 FUN_11007f90  (called by: FUN_11008000@11008000)

undefined4 * __cdecl
FUN_11007f90(char param_1,char param_2,undefined1 param_3,LOCATION param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_1c [7];
  
  puVar1 = (undefined4 *)FUN_11007220(0x1c);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_11007ec0(local_1c,param_1,param_2,param_3,param_4,param_5,param_6);
  puVar3 = local_1c;
  puVar4 = puVar1;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_11006f80(&DAT_11020178,(int)puVar1);
  return puVar1;
}


// ---- 11008000 FUN_11008000  (called by: FUN_1100301d@1100301d)

void __cdecl
FUN_11008000(char param_1,char param_2,undefined1 param_3,LOCATION param_4,undefined4 param_5,
            undefined4 param_6)

{
  FUN_11007f90(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ---- 11008030 FUN_11008030  (called by: FUN_110080a0@110080a0)

undefined4 * __thiscall
FUN_11008030(void *this,char param_1,char param_2,undefined4 param_3,undefined1 param_4,
            undefined4 param_5,undefined4 param_6)

{
  FUN_11006eb0(this,param_1,param_2,param_5);
  *(undefined4 *)((int)this + 8) = param_6;
  *(undefined ***)this = &PTR_FUN_1101042c;
  *(undefined1 *)((int)this + 0x10) = param_4;
  *(undefined4 *)((int)this + 0x14) = param_3;
  return this;
}


// ---- 11008070 FUN_11008070  (called by: -)

void __fastcall FUN_11008070(int param_1)

{
  int iVar1;
  
  iVar1 = _Player::HasTechnology
                    ((_Player *)(Player_exref + *(char *)(param_1 + 0x10) * 0xc),
                     *(int *)(param_1 + 0x14));
  if (iVar1 != 0) {
    FUN_11006f30(param_1);
  }
  return;
}


// ---- 110080a0 FUN_110080a0  (called by: InitProc@11005892)

undefined4 * __cdecl
FUN_110080a0(char param_1,char param_2,undefined4 param_3,undefined1 param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_18 [6];
  
  puVar1 = (undefined4 *)FUN_11007220(0x18);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_11008030(local_18,param_1,param_2,param_3,param_4,param_5,param_6);
  puVar3 = local_18;
  puVar4 = puVar1;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_11006f80(&DAT_11020178,(int)puVar1);
  return puVar1;
}


// ---- 11008110 GetSaveRegions  (called by: -)

void __cdecl GetSaveRegions(int *param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *_Str1;
  int iVar6;
  
                    /* 0x8110  6  GetSaveRegions */
  iVar4 = ImageLoad(&DAT_11029180,0);
  iVar6 = 0;
  iVar1 = *(int *)(iVar4 + 0x14);
  pcVar2 = *(char **)(iVar4 + 0x18);
  iVar3 = *(int *)(*(int *)(iVar4 + 0xc) + 0x34);
  DAT_11019924 = *(undefined4 *)(*(int *)(iVar4 + 0xc) + 8);
  _Str1 = pcVar2;
  if (0 < iVar1) {
    while( true ) {
      iVar5 = _strncmp(_Str1,s__save_11015320,5);
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


// ---- 110081b0 FUN_110081b0  (called by: FUN_11005f7f@11005f7f)

void __cdecl FUN_110081b0(HMODULE param_1)

{
  GetModuleFileNameA(param_1,&DAT_11029180,0x50);
  return;
}


// ---- 11008210 FUN_11008210  (called by: -)

void FUN_11008210(void)

{
  FUN_110084d5((undefined4 *)&DAT_11019928);
  return;
}


// ---- 1100821a FUN_1100821a  (called by: -)

void FUN_1100821a(void)

{
  FUN_1100943d(0x11008226);
  return;
}


// ---- 11008226 FUN_11008226  (called by: -)

void FUN_11008226(void)

{
  FUN_11008522((undefined4 *)&DAT_11019928);
  return;
}


// ---- 11008230 FUN_11008230  (called by: FUN_1100825e@1100825e)

void __cdecl FUN_11008230(undefined4 param_1)

{
  FUN_11008580(0x11019928);
  DAT_11019934 = param_1;
  FUN_1100852d(&DAT_11019928,param_1);
  FUN_11008575(0x11019928);
  DAT_11015328 = 0;
  return;
}


// ---- 1100825e FUN_1100825e  (called by: FUN_11005f7f@11005f7f)

void __cdecl FUN_1100825e(undefined4 param_1,ushort param_2)

{
  FUN_11008230(param_1);
  FUN_11008273(param_2);
  return;
}


// ---- 11008273 FUN_11008273  (called by: FUN_11004590@11004590, FUN_1100825e@1100825e)

void __cdecl FUN_11008273(ushort param_1)

{
  FUN_11008595(&DAT_11019928,param_1,0);
  return;
}


// ---- 11008284 FUN_11008284  (called by: -)

undefined4 FUN_11008284(undefined4 *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 unaff_BP;
  undefined4 local_8004 [8182];
  undefined4 uStackY_2c;
  
  FUN_11009390(unaff_BP);
  uVar2 = 0;
  if (DAT_11019934 != 0) {
    if (DAT_11015328 == '\x01') {
      FUN_1100852d(&DAT_11019928,DAT_11019934);
      FUN_11008575(0x11019928);
      DAT_11015328 = '\0';
    }
    iVar1 = FUN_1100855b(&DAT_11019928,local_8004,0x8000);
    FUN_110089e0(param_1,local_8004,param_2);
    uStackY_2c = 0x110082f7;
    _memset((void *)(iVar1 + (int)param_1),0,param_2 - iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


// ---- 11008304 FUN_11008304  (called by: FUN_11005f7f@11005f7f)

undefined4 __cdecl FUN_11008304(int param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 uVar3;
  DWORD local_8;
  
  iVar1 = _memcmp(DAT_11015334,&DAT_11010434,0x14);
  if (iVar1 == 0) {
    iVar1 = _memcmp(DAT_1101533c,&DAT_11010474,6);
    if (iVar1 == 0) {
      iVar1 = _memcmp(DAT_11015340,&DAT_1101045c,5);
      uVar3 = 3;
      if (iVar1 == 0) {
        iVar1 = _memcmp(DAT_11015344,&DAT_1101046c,3);
        if (iVar1 == 0) {
          BVar2 = VirtualProtect(DAT_11015334,0x14,0x40,&local_8);
          if (BVar2 == 0) {
            uVar3 = 5;
          }
          else {
            BVar2 = VirtualProtect(DAT_1101533c,6,0x40,&local_8);
            if (BVar2 == 0) {
              uVar3 = 6;
            }
            else {
              BVar2 = VirtualProtect(DAT_11015340,5,0x40,&local_8);
              if (BVar2 == 0) {
                uVar3 = 7;
              }
              else {
                BVar2 = VirtualProtect(DAT_11015344,3,0x40,&local_8);
                if (BVar2 != 0) {
                  EnterCriticalSection(DAT_11015330);
                  FUN_110089e0(DAT_11015334,(undefined4 *)&DAT_11010448,0x14);
                  *(undefined4 *)((int)DAT_11015334 + 0xb) = DAT_11015338;
                  DAT_11015334[4] = (param_1 - (int)DAT_11015334) + -0x14;
                  FUN_110089e0(DAT_1101533c,(undefined4 *)&DAT_1101047c,6);
                  FUN_110089e0(DAT_11015340,(undefined4 *)&DAT_11010464,5);
                  FUN_110089e0(DAT_11015344,(undefined4 *)&DAT_11010470,3);
                  LeaveCriticalSection(DAT_11015330);
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


// ---- 1100846f UninstallMusicHook  (called by: FUN_11005f4d@11005f4d)

/* int __cdecl UninstallMusicHook(void) */

int __cdecl UninstallMusicHook(void)

{
                    /* 0x846f  3  ?UninstallMusicHook@@YAHXZ */
  EnterCriticalSection(DAT_11015330);
  FUN_110089e0(DAT_11015334,(undefined4 *)&DAT_11010434,0x14);
  FUN_110089e0(DAT_1101533c,(undefined4 *)&DAT_11010474,6);
  FUN_110089e0(DAT_11015340,(undefined4 *)&DAT_1101045c,5);
  FUN_110089e0(DAT_11015344,(undefined4 *)&DAT_1101046c,3);
  LeaveCriticalSection(DAT_11015330);
  return 0;
}


// ---- 110084d5 FUN_110084d5  (called by: FUN_11008210@11008210)

undefined4 * __fastcall FUN_110084d5(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  *param_1 = &PTR_FUN_11010484;
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


// ---- 11008506 FUN_11008506  (called by: -)

undefined4 * __thiscall FUN_11008506(void *this,byte param_1)

{
  FUN_11008522(this);
  if ((param_1 & 1) != 0) {
    FUN_1100947e(this);
  }
  return this;
}


// ---- 11008522 FUN_11008522  (called by: FUN_11008226@11008226, FUN_11008506@11008506)

void __fastcall FUN_11008522(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_11010484;
  BASS_Free();
  return;
}


// ---- 1100852d FUN_1100852d  (called by: FUN_11008230@11008230, FUN_11008284@11008284)

bool __thiscall FUN_1100852d(void *this,undefined4 param_1)

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


// ---- 1100855b FUN_1100855b  (called by: FUN_11008284@11008284)

undefined4 __thiscall FUN_1100855b(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = BASS_ChannelGetData(*(undefined4 *)((int)this + 8),param_1,param_2);
  return uVar1;
}


// ---- 11008575 FUN_11008575  (called by: FUN_11008230@11008230, FUN_11008284@11008284)

void __fastcall FUN_11008575(int param_1)

{
  BASS_ChannelPlay(*(undefined4 *)(param_1 + 8),0);
  return;
}


// ---- 11008580 FUN_11008580  (called by: FUN_11008230@11008230)

void __fastcall FUN_11008580(int param_1)

{
  BASS_ChannelStop(*(undefined4 *)(param_1 + 8));
  BASS_MusicFree(*(undefined4 *)(param_1 + 8));
  return;
}


// ---- 11008595 FUN_11008595  (called by: FUN_11008273@11008273)

void __thiscall FUN_11008595(void *this,ushort param_1,ushort param_2)

{
  BASS_ChannelSetPosition
            (*(undefined4 *)((int)this + 8),(param_2 | 0xffff8000) << 0x10 | (uint)param_1,0);
  return;
}


// ---- 110085dc FUN_110085dc  (called by: FUN_1100a275@1100a275)

void FUN_110085dc(undefined *UNRECOVERED_JUMPTABLE)

{
  ExceptionList = *(void **)ExceptionList;
                    /* WARNING: Could not recover jumptable at 0x11008607. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


// ---- 11008610 FUN_11008610  (called by: FUN_1100a435@1100a435, FUN_1100a5f9@1100a5f9)

void FUN_11008610(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x11008615. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


// ---- 11008617 FUN_11008617  (called by: FUN_1100a435@1100a435)

void FUN_11008617(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x1100861c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


// ---- 1100861e FUN_1100861e  (called by: FUN_110087d2@110087d2, FUN_1100a275@1100a275)

void FUN_1100861e(PVOID param_1,PEXCEPTION_RECORD param_2)

{
  void *pvVar1;
  
  pvVar1 = ExceptionList;
  RtlUnwind(param_1,(PVOID)0x11008646,param_2,(PVOID)0x0);
  param_2->ExceptionFlags = param_2->ExceptionFlags & 0xfffffffd;
  *(void **)pvVar1 = ExceptionList;
  ExceptionList = pvVar1;
  return;
}


// ---- 1100866d FUN_1100866d  (called by: FUN_1100eb19@1100eb19, FUN_1100eb2d@1100eb2d, FUN_1100eb41@1100eb41, FUN_1100eb55@1100eb55, FUN_1100ed3d@1100ed3d, FUN_1100ef34@1100ef34, FUN_1100ef49@1100ef49, FUN_1100ef81@1100ef81, FUN_1100ef95@1100ef95, FUN_1100efa9@1100efa9, FUN_1100efbd@1100efbd, FUN_1100efe3@1100efe3, FUN_1100eff9@1100eff9, FUN_1100f016@1100f016, FUN_1100f029@1100f029, FUN_1100f14b@1100f14b, FUN_1100f161@1100f161, FUN_1100f175@1100f175, FUN_1100f189@1100f189, FUN_1100f19d@1100f19d, FUN_1100f1b1@1100f1b1, FUN_1100f1c0@1100f1c0, FUN_1100f1d0@1100f1d0, FUN_1100f1e9@1100f1e9, FUN_1100f209@1100f209, FUN_1100f229@1100f229)

undefined4 __cdecl
FUN_1100866d(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  int *in_EAX;
  undefined4 uVar1;
  
  uVar1 = FUN_11009e6c(param_1,param_2,param_3,param_4,in_EAX,0,(PVOID)0x0,'\0');
  return uVar1;
}


// ---- 110086a3 FUN_110086a3  (called by: FUN_1100a2f0@1100a2f0)

undefined4 __cdecl
FUN_110086a3(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  void *local_18;
  code *local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  local_10 = param_2;
  local_14 = FUN_110086f7;
  local_8 = param_4 + 1;
  local_c = param_1;
  local_18 = ExceptionList;
  ExceptionList = &local_18;
  uVar1 = __CallSettingFrame_12(param_3,param_1,param_5);
  ExceptionList = local_18;
  return uVar1;
}


// ---- 110086f7 FUN_110086f7  (called by: -)

void __cdecl FUN_110086f7(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3)

{
  FUN_11009e6c(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),param_2,'\0');
  return;
}


// ---- 1100871c FUN_1100871c  (called by: FUN_1100a0ba@1100a0ba)

undefined4 __cdecl
FUN_1100871c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  local_28 = FUN_110087d2;
  local_24 = param_5;
  local_20 = param_2;
  local_1c = param_6;
  local_18 = param_7;
  local_8 = 0;
  local_14 = 0x110087a4;
  local_2c = ExceptionList;
  ExceptionList = &local_2c;
  local_34 = param_1;
  local_30 = param_3;
  ppuVar3 = &local_34;
  uVar2 = *param_1;
  pDVar1 = FUN_1100a761();
  (*(code *)pDVar1[0x1a])(uVar2,ppuVar3);
  if (local_8 != 0) {
    *local_2c = *(undefined4 *)ExceptionList;
  }
  ExceptionList = local_2c;
  return 0;
}


// ---- 110087d2 FUN_110087d2  (called by: -)

undefined4 __cdecl FUN_110087d2(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3)

{
  undefined4 uVar1;
  
  if ((param_1->ExceptionFlags & 0x66) != 0) {
    *(undefined4 *)((int)param_2 + 0x24) = 1;
    return 1;
  }
  FUN_11009e6c(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),*(PVOID *)((int)param_2 + 0x14),'\x01');
  if (*(int *)((int)param_2 + 0x24) == 0) {
    FUN_1100861e(param_2,param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x1100883c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)((int)param_2 + 0x18))();
  return uVar1;
}


// ---- 11008847 FUN_11008847  (called by: FUN_11009f07@11009f07, FUN_1100a0ba@1100a0ba)

int __cdecl FUN_11008847(uint param_1,int param_2,int param_3,uint *param_4,uint *param_5)

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
        FUN_1100a8c9();
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
    FUN_1100a8c9();
  }
  return iVar1 + uVar3 * 0x14;
}


// ---- 110088c4 __global_unwind2  (called by: FUN_1100d14c@1100d14c)

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x110088dc,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}


// ---- 110088e4 FUN_110088e4  (called by: -)

undefined4 FUN_110088e4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((*(uint *)(param_1 + 4) & 6) != 0) {
    *param_4 = param_2;
    uVar1 = 3;
  }
  return uVar1;
}


// ---- 11008906 __local_unwind2  (called by: FUN_1100d14c@1100d14c, FUN_1100d209@1100d209)

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
  pcStack_18 = FUN_110088e4;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_1100899a();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  ExceptionList = pvStack_1c;
  return;
}


// ---- 1100896e __abnormal_termination  (called by: FUN_1100a3bd@1100a3bd)

/* Library Function - Single Match
    __abnormal_termination
   
   Library: Visual Studio */

int __cdecl __abnormal_termination(void)

{
  int iVar1;
  
  iVar1 = 0;
  if ((*(code **)((int)ExceptionList + 4) == FUN_110088e4) &&
     (*(int *)((int)ExceptionList + 8) == *(int *)(*(int *)((int)ExceptionList + 0xc) + 0xc))) {
    iVar1 = 1;
  }
  return iVar1;
}


// ---- 11008991 __NLG_Notify1  (called by: __CallSettingFrame@12@1100a690)

/* Library Function - Single Match
    __NLG_Notify1
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __fastcall __NLG_Notify1(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;
  
  DAT_11015350 = param_1;
  DAT_1101534c = in_EAX;
  DAT_11015354 = unaff_EBP;
  return;
}


// ---- 1100899a FUN_1100899a  (called by: FUN_1100d14c@1100d14c, __local_unwind2@11008906)

void FUN_1100899a(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_11015350 = *(undefined4 *)(unaff_EBP + 8);
  DAT_1101534c = in_EAX;
  DAT_11015354 = unaff_EBP;
  return;
}


// ---- 110089b4 FUN_110089b4  (called by: FUN_110010b9@110010b9, FUN_11001634@11001634, FUN_110017a9@110017a9, FUN_110018d6@110018d6, FUN_11001aad@11001aad, FUN_11001c63@11001c63, FUN_11001f55@11001f55, FUN_110025b8@110025b8, FUN_11002a51@11002a51, FUN_11002c69@11002c69, FUN_11002cfe@11002cfe, FUN_1100301d@1100301d, FUN_11003503@11003503, FUN_11003880@11003880, FUN_110040e2@110040e2, FUN_11004a66@11004a66, FUN_11005670@11005670, FUN_110056dc@110056dc, FUN_11005748@11005748, FUN_110057b4@110057b4, FUN_11005823@11005823)

void FUN_110089b4(void)

{
  undefined1 auStack_c [12];
  
  ExceptionList = auStack_c;
  return;
}


// ---- 110089e0 FUN_110089e0  (called by: FUN_11001121@11001121, FUN_11001417@11001417, FUN_11008284@11008284, FUN_11008304@11008304, FUN_11009237@11009237, FUN_110094c6@110094c6, FUN_110095ae@110095ae, FUN_1100cd40@1100cd40, UninstallMusicHook@1100846f)

undefined4 * __cdecl FUN_110089e0(undefined4 *param_1,undefined4 *param_2,uint param_3)

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
          goto switchD_11008b97_caseD_2;
        case 3:
          goto switchD_11008b97_caseD_3;
        }
        goto switchD_11008b97_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_11008b97_caseD_0;
      case 1:
        goto switchD_11008b97_caseD_1;
      case 2:
        goto switchD_11008b97_caseD_2;
      case 3:
        goto switchD_11008b97_caseD_3;
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
              goto switchD_11008b97_caseD_2;
            case 3:
              goto switchD_11008b97_caseD_3;
            }
            goto switchD_11008b97_caseD_1;
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
              goto switchD_11008b97_caseD_2;
            case 3:
              goto switchD_11008b97_caseD_3;
            }
            goto switchD_11008b97_caseD_1;
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
              goto switchD_11008b97_caseD_2;
            case 3:
              goto switchD_11008b97_caseD_3;
            }
            goto switchD_11008b97_caseD_1;
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
switchD_11008b97_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_11008b97_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_11008b97_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_11008b97_caseD_0:
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
        goto switchD_11008a15_caseD_2;
      case 3:
        goto switchD_11008a15_caseD_3;
      }
      goto switchD_11008a15_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_11008a15_caseD_0;
    case 1:
      goto switchD_11008a15_caseD_1;
    case 2:
      goto switchD_11008a15_caseD_2;
    case 3:
      goto switchD_11008a15_caseD_3;
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
            goto switchD_11008a15_caseD_2;
          case 3:
            goto switchD_11008a15_caseD_3;
          }
          goto switchD_11008a15_caseD_1;
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
            goto switchD_11008a15_caseD_2;
          case 3:
            goto switchD_11008a15_caseD_3;
          }
          goto switchD_11008a15_caseD_1;
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
            goto switchD_11008a15_caseD_2;
          case 3:
            goto switchD_11008a15_caseD_3;
          }
          goto switchD_11008a15_caseD_1;
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
switchD_11008a15_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_11008a15_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_11008a15_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_11008a15_caseD_0:
  return param_1;
}


// ---- 11008d15 _malloc  (called by: FUN_11001172@11001172, FUN_11006926@11006926, FUN_110095ae@110095ae, FUN_1100aa80@1100aa80, FUN_1100b9fd@1100b9fd, FUN_1100c118@1100c118, FUN_1100ca3a@1100ca3a, FUN_1100caf3@1100caf3, FUN_1100cd40@1100cd40, FUN_1100d68a@1100d68a, FUN_1100d96b@1100d96b)

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_11019990);
  return pvVar1;
}


// ---- 11008d27 __nh_malloc  (called by: _malloc@11008d15, operator_new@11009489)

/* Library Function - Single Match
    __nh_malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl __nh_malloc(size_t _Size,int _NhFlag)

{
  int *piVar1;
  int iVar2;
  
  if (_Size < 0xffffffe1) {
    do {
      piVar1 = FUN_11008d53((uint *)_Size);
      if (piVar1 != (int *)0x0) {
        return piVar1;
      }
      if (_NhFlag == 0) {
        return (void *)0x0;
      }
      iVar2 = FUN_1100a91f(_Size);
    } while (iVar2 != 0);
  }
  return (void *)0x0;
}


// ---- 11008d53 FUN_11008d53  (called by: __nh_malloc@11008d27)

int * __cdecl FUN_11008d53(uint *param_1)

{
  int *piVar1;
  
  if (param_1 <= DAT_1101544c) {
    FUN_1100aa80(9);
    piVar1 = FUN_1100ae8a(param_1);
    FUN_1100aae1(9);
    if (piVar1 != (int *)0x0) {
      return piVar1;
    }
  }
  if (param_1 == (uint *)0x0) {
    param_1 = (uint *)0x1;
  }
  piVar1 = HeapAlloc(DAT_1101b03c,0,(int)param_1 + 0xfU & 0xfffffff0);
  return piVar1;
}


// ---- 11008da1 FUN_11008da1  (called by: FUN_110011e7@110011e7, FUN_110069b2@110069b2, FUN_1100947e@1100947e, FUN_110095ae@110095ae, FUN_1100a7c8@1100a7c8, FUN_1100aa14@1100aa14, FUN_1100aa80@1100aa80, FUN_1100bbb9@1100bbb9, FUN_1100ca3a@1100ca3a, FUN_1100cd40@1100cd40, __fclose_lk@11008e1a, __freebuf@1100b875)

void __cdecl FUN_11008da1(LPVOID param_1)

{
  uint *puVar1;
  
  if (param_1 != (LPVOID)0x0) {
    FUN_1100aa80(9);
    puVar1 = (uint *)FUN_1100ab34((int)param_1);
    if (puVar1 != (uint *)0x0) {
      FUN_1100ab5f(puVar1,(uint)param_1);
      FUN_1100aae1(9);
      return;
    }
    FUN_1100aae1(9);
    HeapFree(DAT_1101b03c,0,param_1);
  }
  return;
}


// ---- 11008de9 FUN_11008de9  (called by: FUN_110011fe@110011fe, FUN_11006102@11006102, FUN_11006439@11006439, FUN_110065ad@110065ad, FUN_1100660f@1100660f, FUN_110066bc@110066bc)

undefined4 __cdecl FUN_11008de9(FILE *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1->_flag & 0x40) == 0) {
    FUN_1100b6f1((uint)param_1);
    uVar1 = __fclose_lk(param_1);
    FUN_1100b743((uint)param_1);
  }
  else {
    param_1->_flag = 0;
  }
  return uVar1;
}


// ---- 11008e1a __fclose_lk  (called by: FUN_11008de9@11008de9)

/* Library Function - Single Match
    __fclose_lk
   
   Library: Visual Studio 2003 Release */

undefined4 __cdecl __fclose_lk(FILE *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1->_flag & 0x83) != 0) {
    uVar2 = FUN_110090ff((int *)param_1);
    __freebuf(param_1);
    iVar1 = FUN_1100b795(param_1->_file);
    if (iVar1 < 0) {
      uVar2 = 0xffffffff;
    }
    else if (param_1->_tmpfname != (char *)0x0) {
      FUN_11008da1(param_1->_tmpfname);
      param_1->_tmpfname = (char *)0x0;
    }
  }
  param_1->_flag = 0;
  return uVar2;
}


// ---- 11008e66 FUN_11008e66  (called by: FUN_110011fe@110011fe)

int __cdecl FUN_11008e66(int *param_1,int param_2,DWORD param_3)

{
  int iVar1;
  
  FUN_1100b6f1((uint)param_1);
  iVar1 = FUN_11008e92(param_1,param_2,param_3);
  FUN_1100b743((uint)param_1);
  return iVar1;
}


// ---- 11008e92 FUN_11008e92  (called by: FUN_11008e66@11008e66)

int __cdecl FUN_11008e92(int *param_1,int param_2,DWORD param_3)

{
  uint uVar1;
  int iVar2;
  DWORD DVar3;
  DWORD *pDVar4;
  
  if (((param_1[3] & 0x83U) == 0) || (((param_3 != 0 && (param_3 != 1)) && (param_3 != 2)))) {
    pDVar4 = FUN_1100b913();
    *pDVar4 = 0x16;
    iVar2 = -1;
  }
  else {
    param_1[3] = param_1[3] & 0xffffffef;
    if (param_3 == 1) {
      iVar2 = FUN_11008f41((char *)param_1);
      param_2 = param_2 + iVar2;
      param_3 = 0;
    }
    FUN_110090ff(param_1);
    uVar1 = param_1[3];
    if ((uVar1 & 0x80) == 0) {
      if ((((uVar1 & 1) != 0) && ((uVar1 & 8) != 0)) && ((uVar1 & 0x400) == 0)) {
        param_1[6] = 0x200;
      }
    }
    else {
      param_1[3] = uVar1 & 0xfffffffc;
    }
    DVar3 = FUN_1100b925(param_1[4],param_2,param_3);
    iVar2 = (DVar3 != 0xffffffff) - 1;
  }
  return iVar2;
}


// ---- 11008f1f FUN_11008f1f  (called by: FUN_110011fe@110011fe)

int __cdecl FUN_11008f1f(char *param_1)

{
  int iVar1;
  
  FUN_1100b6f1((uint)param_1);
  iVar1 = FUN_11008f41(param_1);
  FUN_1100b743((uint)param_1);
  return iVar1;
}


// ---- 11008f41 FUN_11008f41  (called by: FUN_11008e92@11008e92, FUN_11008f1f@11008f1f)

int __cdecl FUN_11008f41(char *param_1)

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
  local_8 = FUN_1100b925(uVar1,0,1);
  if ((int)local_8 < 0) {
LAB_11008fcf:
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
        pDVar4 = FUN_1100b913();
        *pDVar4 = 0x16;
        goto LAB_11008fcf;
      }
    }
    else if ((*(byte *)((&DAT_11019f00)[(int)uVar1 >> 5] + 4 + (uVar1 & 0x1f) * 0x24) & 0x80) != 0)
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
          if ((*(byte *)(iVar10 + 4 + (&DAT_11019f00)[(int)uVar1 >> 5]) & 0x80) != 0) {
            DVar6 = FUN_1100b925(uVar1,0,2);
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
              FUN_1100b925(uVar1,local_8,0);
              pcVar8 = (char *)0x200;
              if ((((char *)0x200 < pcVar5) || ((*(uint *)(param_1 + 0xc) & 8) == 0)) ||
                 ((*(uint *)(param_1 + 0xc) & 0x400) != 0)) {
                pcVar8 = *(char **)(param_1 + 0x18);
              }
              bVar3 = *(byte *)(iVar10 + 4 + (&DAT_11019f00)[(int)uVar1 >> 5]) & 4;
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


// ---- 110090a2 FUN_110090a2  (called by: FUN_110011fe@110011fe)

int __cdecl FUN_110090a2(int *param_1)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    iVar1 = FUN_11009164(0);
    return iVar1;
  }
  FUN_1100b6f1((uint)param_1);
  iVar1 = FUN_110090d1(param_1);
  FUN_1100b743((uint)param_1);
  return iVar1;
}


// ---- 110090d1 FUN_110090d1  (called by: FUN_110090a2@110090a2, FUN_11009164@11009164)

int __cdecl FUN_110090d1(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_110090ff(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((*(byte *)((int)param_1 + 0xd) & 0x40) == 0) {
    return 0;
  }
  iVar1 = FUN_1100bc0d(param_1[4]);
  return -(uint)(iVar1 != 0);
}


// ---- 110090ff FUN_110090ff  (called by: FUN_11008e92@11008e92, FUN_110090d1@110090d1, FUN_11009237@11009237, __fclose_lk@11008e1a)

undefined4 __cdecl FUN_110090ff(int *param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  DWORD DVar3;
  
  uVar2 = 0;
  if ((((byte)param_1[3] & 3) == 2) && ((param_1[3] & 0x108U) != 0)) {
    DVar3 = *param_1 - param_1[2];
    if (0 < (int)DVar3) {
      DVar1 = FUN_1100bca0(param_1[4],(char *)param_1[2],DVar3);
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


// ---- 11009164 FUN_11009164  (called by: FUN_110090a2@110090a2)

int __cdecl FUN_11009164(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar5 = 0;
  FUN_1100aa80(2);
  iVar4 = 0;
  if (0 < DAT_1101b020) {
    do {
      iVar2 = *(int *)(DAT_1101a004 + iVar4 * 4);
      if ((iVar2 != 0) && ((*(byte *)(iVar2 + 0xc) & 0x83) != 0)) {
        FUN_1100b720(iVar4,iVar2);
        piVar1 = *(int **)(DAT_1101a004 + iVar4 * 4);
        if ((piVar1[3] & 0x83U) != 0) {
          if (param_1 == 1) {
            iVar2 = FUN_110090d1(piVar1);
            if (iVar2 != -1) {
              iVar3 = iVar3 + 1;
            }
          }
          else if ((param_1 == 0) && ((piVar1[3] & 2U) != 0)) {
            iVar2 = FUN_110090d1(piVar1);
            if (iVar2 == -1) {
              iVar5 = -1;
            }
          }
        }
        FUN_1100b772(iVar4,*(int *)(DAT_1101a004 + iVar4 * 4));
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_1101b020);
  }
  FUN_1100aae1(2);
  if (param_1 != 1) {
    iVar3 = iVar5;
  }
  return iVar3;
}


// ---- 11009208 FUN_11009208  (called by: FUN_110011fe@110011fe, FUN_11006102@11006102, FUN_11006439@11006439, FUN_110065ad@110065ad)

uint __cdecl FUN_11009208(char *param_1,uint param_2,uint param_3,int *param_4)

{
  uint uVar1;
  
  FUN_1100b6f1((uint)param_4);
  uVar1 = FUN_11009237(param_1,param_2,param_3,param_4);
  FUN_1100b743((uint)param_4);
  return uVar1;
}


// ---- 11009237 FUN_11009237  (called by: FUN_11009208@11009208)

uint __cdecl FUN_11009237(char *param_1,uint param_2,uint param_3,int *param_4)

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
          if (((piVar1[3] & 0x108U) != 0) && (iVar2 = FUN_110090ff(piVar1), iVar2 != 0)) {
LAB_11009338:
            return (uint)((int)piVar6 - (int)piVar5) / param_2;
          }
          if (param_4 == (int *)0x0) {
            piVar7 = piVar5;
          }
          else {
            piVar7 = (int *)((int)piVar5 - (uint)piVar5 % (uint)param_4);
          }
          piVar3 = (int *)FUN_1100bca0(piVar1[4],param_1,(DWORD)piVar7);
          if ((piVar3 == (int *)0xffffffff) ||
             (piVar5 = (int *)((int)piVar5 - (int)piVar3), piVar3 < piVar7)) {
            piVar1[3] = piVar1[3] | 0x20;
            goto LAB_11009338;
          }
          goto LAB_110092ef;
        }
        uVar4 = FUN_1100be90((int)*param_1,piVar1);
        if (uVar4 == 0xffffffff) goto LAB_11009338;
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
        FUN_110089e0((undefined4 *)*piVar1,(undefined4 *)param_1,(uint)piVar3);
        piVar1[1] = piVar1[1] - (int)piVar3;
        *piVar1 = *piVar1 + (int)piVar3;
        piVar5 = (int *)((int)piVar5 - (int)piVar3);
LAB_110092ef:
        param_1 = param_1 + (int)piVar3;
      }
    } while (piVar5 != (int *)0x0);
  }
  return param_3;
}


// ---- 11009341 FUN_11009341  (called by: FUN_11009372@11009372)

undefined4 * __cdecl FUN_11009341(LPCSTR param_1,char *param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = FUN_1100c118();
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2 = FUN_1100bfa8(param_1,param_2,param_3,puVar1);
  FUN_1100b743((uint)puVar1);
  return puVar2;
}


// ---- 11009372 FUN_11009372  (called by: FUN_110011fe@110011fe, FUN_11006102@11006102, FUN_11006439@11006439, FUN_110065ad@110065ad, FUN_11006638@11006638)

void __cdecl FUN_11009372(LPCSTR param_1,char *param_2)

{
  FUN_11009341(param_1,param_2,0x40);
  return;
}


// ---- 11009390 FUN_11009390  (called by: FUN_110011fe@110011fe, FUN_11008284@11008284, FUN_1100dd95@1100dd95, FUN_1100dfe4@1100dfe4, FUN_1100e476@1100e476)

/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_11009390(undefined1 param_1)

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


// ---- 110093bf FUN_110093bf  (called by: FUN_1100943d@1100943d)

int __cdecl FUN_110093bf(int param_1)

{
  SIZE_T SVar1;
  int *piVar2;
  
  FUN_11009ce7();
  SVar1 = FUN_1100c1e0(DAT_1101b04c);
  if (SVar1 < (uint)((int)DAT_1101b048 + (4 - (int)DAT_1101b04c))) {
    SVar1 = FUN_1100c1e0(DAT_1101b04c);
    piVar2 = FUN_110095ae(DAT_1101b04c,(uint *)(SVar1 + 0x10));
    if (piVar2 == (int *)0x0) {
      param_1 = 0;
      goto LAB_11009434;
    }
    DAT_1101b048 = piVar2 + ((int)DAT_1101b048 - (int)DAT_1101b04c >> 2);
    DAT_1101b04c = piVar2;
  }
  *DAT_1101b048 = param_1;
  DAT_1101b048 = DAT_1101b048 + 1;
LAB_11009434:
  FUN_11009cf0();
  return param_1;
}


// ---- 1100943d FUN_1100943d  (called by: FUN_11001aa1@11001aa1, FUN_11003fe2@11003fe2, FUN_1100821a@1100821a)

int __cdecl FUN_1100943d(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_110093bf(param_1);
  return (iVar1 != 0) - 1;
}


// ---- 1100947e FUN_1100947e  (called by: FUN_110066bc@110066bc, FUN_110069dc@110069dc, FUN_11006a05@11006a05, FUN_11008506@11008506, InitMap@1100487d)

void __cdecl FUN_1100947e(LPVOID param_1)

{
  FUN_11008da1(param_1);
  return;
}


// ---- 11009489 operator_new  (called by: FUN_110066bc@110066bc, InitMap@1100487d)

/* Library Function - Single Match
    void * __cdecl operator new(unsigned int)
   
   Library: Visual Studio 2003 Release */

void * __cdecl operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(param_1,1);
  return pvVar1;
}


// ---- 11009497 FUN_11009497  (called by: FUN_110065f7@110065f7, FUN_11006638@11006638, FUN_110066bc@110066bc)

uint __cdecl FUN_11009497(char *param_1,uint param_2,uint param_3,int *param_4)

{
  uint uVar1;
  
  FUN_1100b6f1((uint)param_4);
  uVar1 = FUN_110094c6(param_1,param_2,param_3,param_4);
  FUN_1100b743((uint)param_4);
  return uVar1;
}


// ---- 110094c6 FUN_110094c6  (called by: FUN_11009497@11009497)

uint __cdecl FUN_110094c6(char *param_1,uint param_2,uint param_3,int *param_4)

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
        uVar4 = FUN_1100c225(piVar1);
        if (uVar4 == 0xffffffff) goto LAB_110095a2;
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
        iVar3 = FUN_1100c301(piVar1[4],pcVar5,pcVar2);
        if (iVar3 == 0) {
          piVar1[3] = piVar1[3] | 0x10;
LAB_110095a2:
          return (uint)((int)pcVar6 - (int)param_1) / param_2;
        }
        if (iVar3 == -1) {
          piVar1[3] = piVar1[3] | 0x20;
          goto LAB_110095a2;
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
      FUN_110089e0((undefined4 *)pcVar5,(undefined4 *)*piVar1,(uint)pcVar7);
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


// ---- 110095ae FUN_110095ae  (called by: FUN_11006926@11006926, FUN_11006969@11006969, FUN_110093bf@110093bf)

int * __cdecl FUN_110095ae(int *param_1,uint *param_2)

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
      FUN_11008da1(param_1);
    }
    else {
      do {
        if (param_2 < (uint *)0xffffffe1) {
          FUN_1100aa80(9);
          puVar2 = (uint *)FUN_1100ab34((int)param_1);
          if (puVar2 == (uint *)0x0) {
            FUN_1100aae1(9);
            if (param_2 == (uint *)0x0) {
              param_2 = (uint *)0x1;
            }
            param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
            piVar1 = HeapReAlloc(DAT_1101b03c,0,param_1,(SIZE_T)param_2);
          }
          else {
            if (DAT_1101544c < param_2) {
LAB_1100964d:
              if (param_2 == (uint *)0x0) {
                param_2 = (uint *)0x1;
              }
              param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
              piVar1 = HeapAlloc(DAT_1101b03c,0,(SIZE_T)param_2);
              if (piVar1 != (int *)0x0) {
                puVar4 = (uint *)(param_1[-1] - 1U);
                if (param_2 <= (uint *)(param_1[-1] - 1U)) {
                  puVar4 = param_2;
                }
                FUN_110089e0(piVar1,param_1,(uint)puVar4);
                FUN_1100ab5f(puVar2,(uint)param_1);
              }
            }
            else {
              iVar3 = FUN_1100b33f(puVar2,(int)param_1,(int)param_2);
              if (iVar3 == 0) {
                piVar1 = FUN_1100ae8a(param_2);
                if (piVar1 == (int *)0x0) goto LAB_1100964d;
                puVar4 = (uint *)(param_1[-1] - 1U);
                if (param_2 <= (uint *)(param_1[-1] - 1U)) {
                  puVar4 = param_2;
                }
                FUN_110089e0(piVar1,param_1,(uint)puVar4);
                FUN_1100ab5f(puVar2,(uint)param_1);
              }
              else {
                piVar1 = param_1;
              }
              if (piVar1 == (int *)0x0) goto LAB_1100964d;
            }
            FUN_1100aae1(9);
          }
          if (piVar1 != (int *)0x0) {
            return piVar1;
          }
        }
        if (DAT_11019990 == 0) {
          return (int *)0x0;
        }
        iVar3 = FUN_1100a91f(param_2);
      } while (iVar3 != 0);
    }
    piVar1 = (int *)0x0;
  }
  return piVar1;
}


// ---- 110096f0 FUN_110096f0  (called by: FUN_11006a40@11006a40, FUN_11006aa8@11006aa8, FUN_1100ca3a@1100ca3a, FUN_1100ceab@1100ceab)

uint * __cdecl FUN_110096f0(uint *param_1,uint *param_2)

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
    if (bVar1 == 0) goto LAB_110097d8;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_110097d8:
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


// ---- 11009700 FUN_11009700  (called by: FUN_11006aa8@11006aa8, FUN_1100ceab@1100ceab)

uint * __cdecl FUN_11009700(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_1100971c;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_1100974f;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x1100976b;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_1100971c:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x1100976b;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x1100976b;
    }
  }
LAB_1100974f:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x1100976b:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_110097d8:
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
    if (bVar1 == 0) goto LAB_110097d8;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}


// ---- 110097e0 FUN_110097e0  (called by: FUN_11006a40@11006a40)

void __cdecl FUN_110097e0(byte *param_1,byte *param_2,byte *param_3,byte *param_4,byte *param_5)

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
      pbVar2 = FUN_1100c53f(param_3,pbVar2);
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


// ---- 11009871 FUN_11009871  (called by: FUN_11006a40@11006a40)

void __cdecl FUN_11009871(byte *param_1,byte *param_2,byte *param_3,byte *param_4,byte *param_5)

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
      FUN_1100c9a0(param_2,param_1,2);
      param_2[2] = 0;
    }
    pbVar3 = param_1 + 2;
  }
  param_2 = (byte *)0x0;
  param_1 = pbVar3;
  if (*pbVar3 != 0) {
    do {
      bVar1 = *param_1;
      if ((*(byte *)((int)&DAT_11019de0 + bVar1 + 1) & 4) == 0) {
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
        FUN_1100c9a0(param_3,pbVar3,sVar2);
        param_3[sVar2] = 0;
      }
      pbVar3 = param_2;
      goto LAB_11009938;
    }
  }
  if (param_3 != (byte *)0x0) {
    *param_3 = 0;
  }
LAB_11009938:
  if ((local_8 == (byte *)0x0) || (local_8 < pbVar3)) {
    if (param_4 != (byte *)0x0) {
      sVar2 = 0xff;
      if ((uint)((int)param_1 - (int)pbVar3) < 0xff) {
        sVar2 = (int)param_1 - (int)pbVar3;
      }
      FUN_1100c9a0(param_4,pbVar3,sVar2);
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
      FUN_1100c9a0(param_4,pbVar3,sVar2);
      param_4[sVar2] = 0;
    }
    if (param_5 != (byte *)0x0) {
      sVar2 = 0xff;
      if ((uint)((int)param_1 - (int)local_8) < 0xff) {
        sVar2 = (int)param_1 - (int)local_8;
      }
      FUN_1100c9a0(param_5,local_8,sVar2);
      param_5[sVar2] = 0;
    }
  }
  return;
}


// ---- 110099c0 _strlen  (called by: FUN_11006aa8@11006aa8, FUN_11009871@11009871, FUN_1100ca3a@1100ca3a, FUN_1100ceab@1100ceab)

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
    if (((uint)puVar2 & 3) == 0) goto LAB_110099e0;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_11009a13:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_110099e0:
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
  goto LAB_11009a13;
}


// ---- 11009a3b FUN_11009a3b  (called by: entry@11009b14)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_11009a3b(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 1) {
    DAT_11019950 = GetVersion();
    iVar1 = FUN_1100a93a(1);
    if (iVar1 != 0) {
      _DAT_1101995c = DAT_11019950 >> 8 & 0xff;
      _DAT_11019958 = DAT_11019950 & 0xff;
      DAT_11019950 = DAT_11019950 >> 0x10;
      _DAT_11019954 = _DAT_11019958 * 0x100 + _DAT_1101995c;
      iVar1 = FUN_1100a6dc();
      if (iVar1 != 0) {
        DAT_1101b054 = GetCommandLineA();
        DAT_1101993c = FUN_1100cd40();
        FUN_1100b9fd();
        FUN_1100caf3();
        FUN_1100ca3a();
        FUN_11009be4();
        DAT_11019938 = DAT_11019938 + 1;
        goto LAB_11009b0e;
      }
      FUN_1100a976();
    }
LAB_11009a9b:
    uVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      if (DAT_11019938 < 1) goto LAB_11009a9b;
      DAT_11019938 = DAT_11019938 + -1;
      if (DAT_11019988 == 0) {
        FUN_11009c33();
      }
      FUN_1100bbb9();
      FUN_1100a730();
      FUN_1100a976();
    }
    else if (param_2 == 3) {
      FUN_1100a7c8((LPVOID)0x0);
    }
LAB_11009b0e:
    uVar2 = 1;
  }
  return uVar2;
}


// ---- 11009b14 entry  (called by: -)

int entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2;
  if (param_2 == 0) {
    iVar2 = DAT_11019938;
  }
  else {
    if ((param_2 != 1) && (param_2 != 2)) goto LAB_11009b5c;
    if ((DAT_1101b058 != (code *)0x0) &&
       (iVar2 = (*DAT_1101b058)(param_1,param_2,param_3), iVar2 == 0)) {
      return 0;
    }
    iVar2 = FUN_11009a3b(param_1,param_2);
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_11009b5c:
  iVar2 = FUN_11005f7f(param_1,param_2);
  if (param_2 == 1) {
    if (iVar2 != 0) {
      return iVar2;
    }
    FUN_11009a3b(param_1,0);
  }
  if ((param_2 == 0) || (param_2 == 3)) {
    iVar3 = FUN_11009a3b(param_1,param_2);
    param_2 = iVar2;
    if (iVar3 == 0) {
      param_2 = 0;
    }
    iVar2 = param_2;
    if ((param_2 != 0) && (DAT_1101b058 != (code *)0x0)) {
      iVar2 = (*DAT_1101b058)(param_1,iVar1,param_3);
    }
  }
  param_2 = iVar2;
  return param_2;
}


// ---- 11009bb1 __amsg_exit  (called by: FUN_1100a761@1100a761, FUN_1100aa80@1100aa80, FUN_1100b9fd@1100b9fd, FUN_1100ca3a@1100ca3a, FUN_1100caf3@1100caf3)

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __amsg_exit(int param_1)

{
  if ((DAT_11019944 == 1) || ((DAT_11019944 == 0 && (DAT_11019948 == 1)))) {
    FUN_1100ce72();
  }
  FUN_1100ceab(param_1);
  (*(code *)PTR___exit_11015360)(0xff);
  return;
}


// ---- 11009be4 FUN_11009be4  (called by: FUN_11009a3b@11009a3b)

void FUN_11009be4(void)

{
  if (DAT_1101b050 != (code *)0x0) {
    (*DAT_1101b050)();
  }
  FUN_11009cf9((undefined4 *)&DAT_11014024,(undefined4 *)&DAT_11014038);
  FUN_11009cf9((undefined4 *)&DAT_11014000,(undefined4 *)&DAT_11014020);
  return;
}


// ---- 11009c11 FUN_11009c11  (called by: FUN_11007200@11007200)

void __cdecl FUN_11009c11(UINT param_1)

{
  FUN_11009c42(param_1,0,0);
  return;
}


// ---- 11009c22 __exit  (called by: FUN_1100d5f2@1100d5f2, FUN_1100e2b7@1100e2b7, __amsg_exit@11009bb1)

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __exit(int _Code)

{
  FUN_11009c42(_Code,1,0);
  return;
}


// ---- 11009c33 FUN_11009c33  (called by: FUN_11009a3b@11009a3b)

void FUN_11009c33(void)

{
  FUN_11009c42(0,0,1);
  return;
}


// ---- 11009c42 FUN_11009c42  (called by: FUN_11009c11@11009c11, FUN_11009c33@11009c33, __exit@11009c22)

void __cdecl FUN_11009c42(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  FUN_11009ce7();
  if (DAT_1101998c == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  DAT_11019988 = 1;
  DAT_11019984 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_1101b04c != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_1101b048 - 4), DAT_1101b04c <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_1101b04c <= puVar1);
    }
    FUN_11009cf9((undefined4 *)&DAT_1101403c,(undefined4 *)&DAT_11014044);
  }
  FUN_11009cf9((undefined4 *)&DAT_11014048,(undefined4 *)&DAT_11014050);
  if (param_3 == 0) {
    DAT_1101998c = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  FUN_11009cf0();
  return;
}


// ---- 11009ce7 FUN_11009ce7  (called by: FUN_110093bf@110093bf, FUN_11009c42@11009c42)

void FUN_11009ce7(void)

{
  FUN_1100aa80(0xd);
  return;
}


// ---- 11009cf0 FUN_11009cf0  (called by: FUN_110093bf@110093bf, FUN_11009c42@11009c42)

void FUN_11009cf0(void)

{
  FUN_1100aae1(0xd);
  return;
}


// ---- 11009cf9 FUN_11009cf9  (called by: FUN_11009be4@11009be4, FUN_11009c42@11009c42)

void __cdecl FUN_11009cf9(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}


// ---- 11009d20 _strncmp  (called by: GetSaveRegions@11008110)

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


// ---- 11009d60 _memset  (called by: FUN_11008284@11008284, FUN_1100d565@1100d565, FUN_1100dfe4@1100dfe4, FUN_1100e476@1100e476)

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


// ---- 11009dc0 _memcmp  (called by: FUN_11008304@11008304)

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
          goto LAB_11009e3a;
        }
      }
      if (uVar2 != 0) {
        uVar5 = *(uint *)_Buf1;
        uVar1 = *(uint *)_Buf2;
        bVar9 = (byte)uVar5 < (byte)uVar1;
        if ((byte)uVar5 != (byte)uVar1) {
LAB_11009e3a:
          return (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        }
        iVar3 = 0;
        if (uVar2 != 1) {
          bVar6 = (byte)(uVar5 >> 8);
          bVar4 = (byte)(uVar1 >> 8);
          bVar9 = bVar6 < bVar4;
          if (bVar6 != bVar4) goto LAB_11009e3a;
          iVar3 = 0;
          if (uVar2 != 2) {
            bVar9 = (uVar5 & 0xff0000) < (uVar1 & 0xff0000);
            if ((uVar5 & 0xff0000) != (uVar1 & 0xff0000)) goto LAB_11009e3a;
            iVar3 = uVar2 - 3;
          }
        }
        return iVar3;
      }
    }
    else {
      if ((_Size & 1) == 0) goto LAB_11009ded;
      bVar9 = *(byte *)_Buf1 < *(byte *)_Buf2;
      if (*(byte *)_Buf1 != *(byte *)_Buf2) goto LAB_11009e3a;
      _Buf1 = (void *)((int)_Buf1 + 1);
      _Buf2 = (void *)((int)_Buf2 + 1);
      for (_Size = _Size - 1; _Size != 0; _Size = _Size - 2) {
LAB_11009ded:
        bVar9 = *(byte *)_Buf1 < *(byte *)_Buf2;
        if ((*(byte *)_Buf1 != *(byte *)_Buf2) ||
           (bVar9 = *(byte *)((int)_Buf1 + 1) < *(byte *)((int)_Buf2 + 1),
           *(byte *)((int)_Buf1 + 1) != *(byte *)((int)_Buf2 + 1))) goto LAB_11009e3a;
        _Buf2 = (void *)((int)_Buf2 + 2);
        _Buf1 = (void *)((int)_Buf1 + 2);
      }
    }
  }
  return 0;
}


// ---- 11009e6c FUN_11009e6c  (called by: FUN_1100866d@1100866d, FUN_110086f7@110086f7, FUN_110087d2@110087d2)

undefined4 __cdecl
FUN_11009e6c(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int *param_5,
            int param_6,PVOID param_7,char param_8)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (*param_5 != 0x19930520) {
    FUN_1100a8c9();
  }
  if ((param_1->ExceptionFlags & 0x66) == 0) {
    if (param_5[3] != 0) {
      if (((param_1->ExceptionCode == 0xe06d7363) && (0x19930520 < param_1->ExceptionInformation[0])
          ) && (pcVar1 = *(code **)(param_1->ExceptionInformation[2] + 8), pcVar1 != (code *)0x0)) {
        uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
        return uVar2;
      }
      FUN_11009f07(param_1,param_2,param_3,param_4,(uint)param_5,param_8,param_6,param_7);
    }
  }
  else if ((param_5[1] != 0) && (param_6 == 0)) {
    FUN_1100a1c1((int)param_2,param_4,(int)param_5,-1);
  }
  return 1;
}


// ---- 11009f07 FUN_11009f07  (called by: FUN_11009e6c@11009e6c)

void __cdecl
FUN_11009f07(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,uint param_5,
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
    FUN_1100a8c9();
  }
  if (param_1->ExceptionCode == 0xe06d7363) {
    if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
       (param_1->ExceptionInformation[2] == 0)) {
      pDVar3 = FUN_1100a761();
      if (pDVar3[0x1b] == 0) {
        return;
      }
      pDVar3 = FUN_1100a761();
      param_1 = (PEXCEPTION_RECORD)pDVar3[0x1b];
      pDVar3 = FUN_1100a761();
      param_3 = pDVar3[0x1c];
      local_18 = CONCAT31(local_18._1_3_,1);
      bVar2 = FUN_1100d062(param_1,1);
      if (CONCAT31(extraout_var,bVar2) == 0) {
        FUN_1100a8c9();
      }
      if (param_1->ExceptionCode != 0xe06d7363) goto LAB_1100a08f;
      if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
         (param_1->ExceptionInformation[2] == 0)) {
        FUN_1100a8c9();
      }
    }
    iVar5 = local_14;
    if (((param_1->ExceptionCode == 0xe06d7363) && (param_1->NumberParameters == 3)) &&
       (param_1->ExceptionInformation[0] == 0x19930520)) {
      piVar4 = (int *)FUN_11008847(param_5,param_7,local_14,&local_8,&local_1c);
      do {
        if (local_1c <= local_8) {
          if (param_6 == '\0') {
            return;
          }
          FUN_1100a5f9((int)param_1);
          return;
        }
        if ((*piVar4 <= iVar5) && (iVar5 <= piVar4[1])) {
          pbVar1 = (byte *)piVar4[4];
          for (local_10 = piVar4[3]; 0 < local_10; local_10 = local_10 + -1) {
            piVar6 = *(int **)(param_1->ExceptionInformation[2] + 0xc);
            for (local_c = *piVar6; 0 < local_c; local_c = local_c + -1) {
              piVar6 = piVar6 + 1;
              iVar5 = FUN_1100a164(pbVar1,(byte *)*piVar6,(uint *)param_1->ExceptionInformation[2]);
              if (iVar5 != 0) {
                FUN_1100a275(param_1,param_2,param_3,param_4,param_5,pbVar1,(byte *)*piVar6,piVar4,
                             param_7,param_8);
                goto LAB_1100a06c;
              }
            }
            pbVar1 = pbVar1 + 0x10;
          }
LAB_1100a06c:
          iVar5 = local_14;
        }
        local_8 = local_8 + 1;
        piVar4 = piVar4 + 5;
      } while( true );
    }
  }
LAB_1100a08f:
  if (param_6 == '\0') {
    FUN_1100a0ba(param_1,param_2,param_3,param_4,param_5,local_14,param_7,param_8);
    return;
  }
  FUN_1100a868();
  return;
}


// ---- 1100a0ba FUN_1100a0ba  (called by: FUN_11009f07@11009f07)

void __cdecl
FUN_1100a0ba(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,uint param_5,
            int param_6,int param_7,PVOID param_8)

{
  DWORD *pDVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint local_c;
  uint local_8;
  
  pDVar1 = FUN_1100a761();
  if ((pDVar1[0x1a] != 0) &&
     (iVar2 = FUN_1100871c(&param_1->ExceptionCode,param_2,param_3,param_4,param_5,param_7,param_8),
     iVar2 != 0)) {
    return;
  }
  piVar3 = (int *)FUN_11008847(param_5,param_7,param_6,&local_8,&local_c);
  for (; local_8 < local_c; local_8 = local_8 + 1) {
    if ((*piVar3 <= param_6) && (param_6 <= piVar3[1])) {
      iVar4 = piVar3[3] * 0x10 + piVar3[4];
      iVar2 = *(int *)(iVar4 + -0xc);
      if ((iVar2 == 0) || (*(char *)(iVar2 + 8) == '\0')) {
        FUN_1100a275(param_1,param_2,param_3,param_4,param_5,(byte *)(iVar4 + -0x10),(byte *)0x0,
                     piVar3,param_7,param_8);
      }
    }
    piVar3 = piVar3 + 5;
  }
  return;
}


// ---- 1100a164 FUN_1100a164  (called by: FUN_11009f07@11009f07)

undefined4 __cdecl FUN_1100a164(byte *param_1,byte *param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || (*(char *)(iVar1 + 8) == '\0')) {
LAB_1100a1bb:
    uVar2 = 1;
  }
  else {
    if (iVar1 == *(int *)(param_2 + 4)) {
LAB_1100a195:
      if (((((*param_2 & 2) == 0) || ((*param_1 & 8) != 0)) &&
          (((*param_3 & 1) == 0 || ((*param_1 & 1) != 0)))) &&
         (((*param_3 & 2) == 0 || ((*param_1 & 2) != 0)))) goto LAB_1100a1bb;
    }
    else {
      iVar1 = _strcmp((char *)(iVar1 + 8),(char *)(*(int *)(param_2 + 4) + 8));
      if (iVar1 == 0) goto LAB_1100a195;
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ---- 1100a1c1 FUN_1100a1c1  (called by: FUN_11009e6c@11009e6c, FUN_1100a275@1100a275)

void __cdecl FUN_1100a1c1(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_11010488;
  pcStack_10 = FUN_1100d14c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  for (iVar2 = *(int *)(param_1 + 8); local_8 = 0xffffffff, iVar2 != param_4;
      iVar2 = *(int *)(*(int *)(param_3 + 8) + iVar2 * 8)) {
    if ((iVar2 < 0) || (*(int *)(param_3 + 4) <= iVar2)) {
      FUN_1100a8c9();
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


// ---- 1100a275 FUN_1100a275  (called by: FUN_11009f07@11009f07, FUN_1100a0ba@1100a0ba)

void __cdecl
FUN_1100a275(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int param_5,
            byte *param_6,byte *param_7,int *param_8,int param_9,PVOID param_10)

{
  undefined *UNRECOVERED_JUMPTABLE;
  
  if (param_7 != (byte *)0x0) {
    FUN_1100a435((int)param_1,(int)param_2,param_6,param_7);
  }
  if (param_10 == (PVOID)0x0) {
    param_10 = param_2;
  }
  else {
  }
  FUN_1100861e(param_10,param_1);
  FUN_1100a1c1((int)param_2,param_4,param_5,*param_8);
  *(int *)((int)param_2 + 8) = param_8[1] + 1;
  UNRECOVERED_JUMPTABLE =
       (undefined *)
       FUN_1100a2f0((DWORD)param_1,param_2,param_3,param_5,*(undefined4 *)(param_6 + 0xc),param_9,
                    0x100);
  if (UNRECOVERED_JUMPTABLE != (undefined *)0x0) {
    FUN_110085dc(UNRECOVERED_JUMPTABLE);
  }
  return;
}


// ---- 1100a2f0 FUN_1100a2f0  (called by: FUN_1100a275@1100a275)

undefined4 __cdecl
FUN_1100a2f0(DWORD param_1,undefined4 param_2,DWORD param_3,undefined4 param_4,undefined4 param_5,
            int param_6,int param_7)

{
  DWORD *pDVar1;
  undefined4 uVar2;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_11010498;
  pcStack_10 = FUN_1100d14c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_1100a761();
  FUN_1100a761();
  pDVar1 = FUN_1100a761();
  pDVar1[0x1b] = param_1;
  pDVar1 = FUN_1100a761();
  pDVar1[0x1c] = param_3;
  local_8 = 1;
  uVar2 = FUN_110086a3(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_1100a3bd();
  ExceptionList = local_14;
  return uVar2;
}


// ---- 1100a3bd FUN_1100a3bd  (called by: FUN_1100a2f0@1100a2f0)

void FUN_1100a3bd(void)

{
  DWORD *pDVar1;
  int unaff_EBP;
  int unaff_ESI;
  int *unaff_EDI;
  
  *(undefined4 *)(unaff_ESI + -4) = *(undefined4 *)(unaff_EBP + -0x28);
  pDVar1 = FUN_1100a761();
  pDVar1[0x1b] = *(DWORD *)(unaff_EBP + -0x1c);
  pDVar1 = FUN_1100a761();
  pDVar1[0x1c] = *(DWORD *)(unaff_EBP + -0x20);
  if ((((*unaff_EDI == -0x1f928c9d) && (unaff_EDI[4] == 3)) && (unaff_EDI[5] == 0x19930520)) &&
     ((*(int *)(unaff_EBP + -0x24) == 0 && (*(int *)(unaff_EBP + -0x2c) != 0)))) {
    __abnormal_termination();
    FUN_1100a5f9((int)unaff_EDI);
  }
  return;
}


// ---- 1100a435 FUN_1100a435  (called by: FUN_1100a275@1100a275)

void __cdecl FUN_1100a435(int param_1,int param_2,byte *param_3,byte *param_4)

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
  
  puStack_c = &DAT_110104b0;
  pcStack_10 = FUN_1100d14c;
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
        bVar2 = FUN_1100d062(*(void **)(param_1 + 0x18),1);
        if ((CONCAT31(extraout_var_03,bVar2) != 0) &&
           (bVar2 = FUN_1100d07e(piVar1,1), CONCAT31(extraout_var_04,bVar2) != 0)) {
          uVar5 = *(uint *)(param_4 + 0x14);
          puVar4 = (undefined4 *)FUN_1100a660(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
          FUN_1100d230(piVar1,puVar4,uVar5);
          ExceptionList = local_14;
          return;
        }
      }
      else {
        ExceptionList = &local_14;
        bVar2 = FUN_1100d062(*(void **)(param_1 + 0x18),1);
        if (((CONCAT31(extraout_var_05,bVar2) != 0) &&
            (bVar2 = FUN_1100d07e(piVar1,1), CONCAT31(extraout_var_06,bVar2) != 0)) &&
           (bVar2 = FUN_1100d09a(*(FARPROC *)(param_4 + 0x18)), CONCAT31(extraout_var_07,bVar2) != 0
           )) {
          if ((*param_4 & 4) == 0) {
            FUN_1100a660(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
            FUN_11008610(piVar1,*(undefined **)(param_4 + 0x18));
            ExceptionList = local_14;
            return;
          }
          FUN_1100a660(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
          FUN_11008617(piVar1,*(undefined **)(param_4 + 0x18));
          ExceptionList = local_14;
          return;
        }
      }
    }
    else {
      ExceptionList = &local_14;
      bVar2 = FUN_1100d062(*(void **)(param_1 + 0x18),1);
      if ((CONCAT31(extraout_var_01,bVar2) != 0) &&
         (bVar2 = FUN_1100d07e(piVar1,1), CONCAT31(extraout_var_02,bVar2) != 0)) {
        FUN_1100d230(piVar1,*(undefined4 **)(param_1 + 0x18),*(uint *)(param_4 + 0x14));
        if (*(int *)(param_4 + 0x14) != 4) {
          ExceptionList = local_14;
          return;
        }
        iVar3 = *piVar1;
        if (iVar3 == 0) {
          ExceptionList = local_14;
          return;
        }
        goto LAB_1100a4c3;
      }
    }
  }
  else {
    ExceptionList = &local_14;
    bVar2 = FUN_1100d062(*(void **)(param_1 + 0x18),1);
    if ((CONCAT31(extraout_var,bVar2) != 0) &&
       (bVar2 = FUN_1100d07e(piVar1,1), CONCAT31(extraout_var_00,bVar2) != 0)) {
      iVar3 = *(int *)(param_1 + 0x18);
      *piVar1 = iVar3;
LAB_1100a4c3:
      iVar3 = FUN_1100a660(iVar3,(int *)(param_4 + 8));
      *piVar1 = iVar3;
      ExceptionList = local_14;
      return;
    }
  }
  FUN_1100a8c9();
  ExceptionList = local_14;
  return;
}


// ---- 1100a5f9 FUN_1100a5f9  (called by: FUN_11009f07@11009f07, FUN_1100a3bd@1100a3bd)

void __cdecl FUN_1100a5f9(int param_1)

{
  undefined *UNRECOVERED_JUMPTABLE;
  void *local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_110104c0;
  pcStack_10 = FUN_1100d14c;
  local_14 = ExceptionList;
  if ((param_1 != 0) &&
     (UNRECOVERED_JUMPTABLE = *(undefined **)(*(int *)(param_1 + 0x1c) + 4),
     UNRECOVERED_JUMPTABLE != (undefined *)0x0)) {
    local_8 = 0;
    ExceptionList = &local_14;
    FUN_11008610(*(undefined4 *)(param_1 + 0x18),UNRECOVERED_JUMPTABLE);
  }
  ExceptionList = local_14;
  return;
}


// ---- 1100a660 FUN_1100a660  (called by: FUN_1100a435@1100a435)

int __cdecl FUN_1100a660(int param_1,int *param_2)

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


// ---- 1100a690 __CallSettingFrame@12  (called by: FUN_110086a3@110086a3, FUN_1100a1c1@1100a1c1)

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


// ---- 1100a6dc FUN_1100a6dc  (called by: FUN_11009a3b@11009a3b)

undefined4 FUN_1100a6dc(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  FUN_1100a9eb();
  DAT_11015380 = TlsAlloc();
  if (DAT_11015380 != 0xffffffff) {
    lpTlsValue = (DWORD *)FUN_1100d565(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_11015380,lpTlsValue);
      if (BVar1 != 0) {
        FUN_1100a74e((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        return 1;
      }
    }
  }
  return 0;
}


// ---- 1100a730 FUN_1100a730  (called by: FUN_11009a3b@11009a3b)

void FUN_1100a730(void)

{
  FUN_1100aa14();
  if (DAT_11015380 != 0xffffffff) {
    TlsFree(DAT_11015380);
    DAT_11015380 = 0xffffffff;
  }
  return;
}


// ---- 1100a74e FUN_1100a74e  (called by: FUN_1100a6dc@1100a6dc, FUN_1100a761@1100a761)

void __cdecl FUN_1100a74e(int param_1)

{
  *(undefined **)(param_1 + 0x50) = &DAT_110159f0;
  *(undefined4 *)(param_1 + 0x14) = 1;
  return;
}


// ---- 1100a761 FUN_1100a761  (called by: FUN_1100871c@1100871c, FUN_11009f07@11009f07, FUN_1100a0ba@1100a0ba, FUN_1100a2f0@1100a2f0, FUN_1100a3bd@1100a3bd, FUN_1100a868@1100a868, FUN_1100b913@1100b913, FUN_1100b91c@1100b91c, FUN_1100e2b7@1100e2b7)

DWORD * FUN_1100a761(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(DAT_11015380);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = (DWORD *)FUN_1100d565(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_11015380,lpTlsValue);
      if (BVar1 != 0) {
        FUN_1100a74e((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        goto LAB_1100a7bc;
      }
    }
    __amsg_exit(0x10);
  }
LAB_1100a7bc:
  SetLastError(dwErrCode);
  return lpTlsValue;
}


// ---- 1100a7c8 FUN_1100a7c8  (called by: FUN_11009a3b@11009a3b)

void __cdecl FUN_1100a7c8(LPVOID param_1)

{
  if (DAT_11015380 == 0xffffffff) {
    return;
  }
  if ((param_1 != (LPVOID)0x0) || (param_1 = TlsGetValue(DAT_11015380), param_1 != (LPVOID)0x0)) {
    if (*(LPVOID *)((int)param_1 + 0x24) != (LPVOID)0x0) {
      FUN_11008da1(*(LPVOID *)((int)param_1 + 0x24));
    }
    if (*(LPVOID *)((int)param_1 + 0x28) != (LPVOID)0x0) {
      FUN_11008da1(*(LPVOID *)((int)param_1 + 0x28));
    }
    if (*(LPVOID *)((int)param_1 + 0x30) != (LPVOID)0x0) {
      FUN_11008da1(*(LPVOID *)((int)param_1 + 0x30));
    }
    if (*(LPVOID *)((int)param_1 + 0x38) != (LPVOID)0x0) {
      FUN_11008da1(*(LPVOID *)((int)param_1 + 0x38));
    }
    if (*(LPVOID *)((int)param_1 + 0x40) != (LPVOID)0x0) {
      FUN_11008da1(*(LPVOID *)((int)param_1 + 0x40));
    }
    if (*(LPVOID *)((int)param_1 + 0x44) != (LPVOID)0x0) {
      FUN_11008da1(*(LPVOID *)((int)param_1 + 0x44));
    }
    if (*(undefined **)((int)param_1 + 0x50) != &DAT_110159f0) {
      FUN_11008da1(*(undefined **)((int)param_1 + 0x50));
    }
    FUN_11008da1(param_1);
  }
  TlsSetValue(DAT_11015380,(LPVOID)0x0);
  return;
}


// ---- 1100a868 FUN_1100a868  (called by: FUN_11009f07@11009f07, FUN_1100a8c9@1100a8c9, FUN_1100cffe@1100cffe)

void FUN_1100a868(void)

{
  DWORD *pDVar1;
  void *pvStack_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_110104d0;
  pcStack_10 = FUN_1100d14c;
  pvStack_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_14;
  pDVar1 = FUN_1100a761();
  if (pDVar1[0x18] != 0) {
    local_8 = 1;
    pDVar1 = FUN_1100a761();
    (*(code *)pDVar1[0x18])();
  }
  local_8 = 0xffffffff;
  FUN_1100d5f2();
  return;
}


// ---- 1100a8c9 FUN_1100a8c9  (called by: FUN_11008847@11008847, FUN_11009e6c@11009e6c, FUN_11009f07@11009f07, FUN_1100a1c1@1100a1c1, FUN_1100a435@1100a435)

void FUN_1100a8c9(void)

{
  void *pvStack_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_110104e8;
  pcStack_10 = FUN_1100d14c;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (PTR_FUN_11015384 != (undefined *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*(code *)PTR_FUN_11015384)();
  }
  local_8 = 0xffffffff;
  FUN_1100a868();
  return;
}


// ---- 1100a91f FUN_1100a91f  (called by: FUN_110095ae@110095ae, FUN_1100d565@1100d565, __nh_malloc@11008d27)

undefined4 __cdecl FUN_1100a91f(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_11019994 != (code *)0x0) {
    iVar1 = (*DAT_11019994)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


// ---- 1100a93a FUN_1100a93a  (called by: FUN_11009a3b@11009a3b)

undefined4 __cdecl FUN_1100a93a(int param_1)

{
  int iVar1;
  
  DAT_1101b03c = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (DAT_1101b03c != (HANDLE)0x0) {
    iVar1 = FUN_1100aaf6();
    if (iVar1 != 0) {
      return 1;
    }
    HeapDestroy(DAT_1101b03c);
  }
  return 0;
}


// ---- 1100a976 FUN_1100a976  (called by: FUN_11009a3b@11009a3b)

void FUN_1100a976(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  if (0 < DAT_1101b034) {
    puVar2 = (undefined4 *)((int)DAT_1101b038 + 0xc);
    do {
      VirtualFree((LPVOID)*puVar2,0x100000,0x4000);
      VirtualFree((LPVOID)*puVar2,0,0x8000);
      HeapFree(DAT_1101b03c,0,(LPVOID)puVar2[1]);
      puVar2 = puVar2 + 5;
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_1101b034);
  }
  HeapFree(DAT_1101b03c,0,DAT_1101b038);
  HeapDestroy(DAT_1101b03c);
  return;
}


// ---- 1100a9eb FUN_1100a9eb  (called by: FUN_1100a6dc@1100a6dc)

void FUN_1100a9eb(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_110153d0);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_110153c0);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_110153b0);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_11015390);
  return;
}


// ---- 1100aa14 FUN_1100aa14  (called by: FUN_1100a730@1100a730)

void FUN_1100aa14(void)

{
  undefined **ppuVar1;
  
  ppuVar1 = (undefined **)&DAT_1101538c;
  do {
    if (((((LPCRITICAL_SECTION)*ppuVar1 != (LPCRITICAL_SECTION)0x0) &&
         (ppuVar1 != &PTR_DAT_110153d0)) && (ppuVar1 != &PTR_DAT_110153c0)) &&
       ((ppuVar1 != &PTR_DAT_110153b0 && (ppuVar1 != &PTR_DAT_11015390)))) {
      DeleteCriticalSection((LPCRITICAL_SECTION)*ppuVar1);
      FUN_11008da1(*ppuVar1);
    }
    ppuVar1 = ppuVar1 + 1;
  } while ((int)ppuVar1 < 0x1101544c);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_110153b0);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_110153c0);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_110153d0);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_11015390);
  return;
}


// ---- 1100aa80 FUN_1100aa80  (called by: FUN_11008d53@11008d53, FUN_11008da1@11008da1, FUN_11009164@11009164, FUN_110095ae@110095ae, FUN_11009ce7@11009ce7, FUN_1100aa80@1100aa80, FUN_1100b6f1@1100b6f1, FUN_1100b720@1100b720, FUN_1100c118@1100c118, FUN_1100c1e0@1100c1e0, FUN_1100c53f@1100c53f, FUN_1100c5ac@1100c5ac, FUN_1100c9a0@1100c9a0, FUN_1100d565@1100d565, FUN_1100d68a@1100d68a, FUN_1100d8ea@1100d8ea, FUN_1100e2b7@1100e2b7, FUN_1100e690@1100e690, FUN_1100e760@1100e760)

void __cdecl FUN_1100aa80(int param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  piVar1 = &DAT_1101538c + param_1;
  if ((&DAT_1101538c)[param_1] == 0) {
    lpCriticalSection = _malloc(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    FUN_1100aa80(0x11);
    if (*piVar1 == 0) {
      InitializeCriticalSection(lpCriticalSection);
      *piVar1 = (int)lpCriticalSection;
    }
    else {
      FUN_11008da1(lpCriticalSection);
    }
    FUN_1100aae1(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)*piVar1);
  return;
}


// ---- 1100aae1 FUN_1100aae1  (called by: FUN_11008d53@11008d53, FUN_11008da1@11008da1, FUN_11009164@11009164, FUN_110095ae@110095ae, FUN_11009cf0@11009cf0, FUN_1100aa80@1100aa80, FUN_1100b743@1100b743, FUN_1100b772@1100b772, FUN_1100c118@1100c118, FUN_1100c1e0@1100c1e0, FUN_1100c53f@1100c53f, FUN_1100c5ac@1100c5ac, FUN_1100c9a0@1100c9a0, FUN_1100d565@1100d565, FUN_1100d68a@1100d68a, FUN_1100d8ea@1100d8ea, FUN_1100e2b7@1100e2b7, FUN_1100e690@1100e690, FUN_1100e760@1100e760)

void __cdecl FUN_1100aae1(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_1101538c)[param_1]);
  return;
}


// ---- 1100aaf6 FUN_1100aaf6  (called by: FUN_1100a93a@1100a93a)

undefined4 FUN_1100aaf6(void)

{
  DAT_1101b038 = HeapAlloc(DAT_1101b03c,0,0x140);
  if (DAT_1101b038 == (LPVOID)0x0) {
    return 0;
  }
  DAT_1101b030 = 0;
  DAT_1101b034 = 0;
  DAT_1101b02c = DAT_1101b038;
  DAT_1101b024 = 0x10;
  return 1;
}


// ---- 1100ab34 FUN_1100ab34  (called by: FUN_11008da1@11008da1, FUN_110095ae@110095ae, FUN_1100c1e0@1100c1e0)

uint __cdecl FUN_1100ab34(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_1101b038;
  while( true ) {
    if (DAT_1101b038 + DAT_1101b034 * 0x14 <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}


// ---- 1100ab5f FUN_1100ab5f  (called by: FUN_11008da1@11008da1, FUN_110095ae@110095ae)

void __cdecl FUN_1100ab5f(uint *param_1,uint param_2)

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
  if (DAT_1101b030 != (uint *)0x0) {
    VirtualFree((LPVOID)(DAT_1101b028 * 0x8000 + DAT_1101b030[3]),0x8000,0x4000);
    DAT_1101b030[2] = DAT_1101b030[2] | 0x80000000U >> ((byte)DAT_1101b028 & 0x1f);
    *(undefined4 *)(DAT_1101b030[4] + 0xc4 + DAT_1101b028 * 4) = 0;
    *(char *)(DAT_1101b030[4] + 0x43) = *(char *)(DAT_1101b030[4] + 0x43) + -1;
    if (*(char *)(DAT_1101b030[4] + 0x43) == '\0') {
      DAT_1101b030[1] = DAT_1101b030[1] & 0xfffffffe;
    }
    if (DAT_1101b030[2] == 0xffffffff) {
      VirtualFree((LPVOID)DAT_1101b030[3],0,0x8000);
      HeapFree(DAT_1101b03c,0,(LPVOID)DAT_1101b030[4]);
      FUN_1100d230(DAT_1101b030,DAT_1101b030 + 5,
                   (DAT_1101b034 * 0x14 - (int)DAT_1101b030) + -0x14 + DAT_1101b038);
      DAT_1101b034 = DAT_1101b034 + -1;
      if (DAT_1101b030 < param_1) {
        param_1 = param_1 + -5;
      }
      DAT_1101b028 = uVar10;
      DAT_1101b02c = DAT_1101b038;
      DAT_1101b030 = param_1;
      return;
    }
  }
  DAT_1101b030 = param_1;
  DAT_1101b028 = uVar10;
  return;
}


// ---- 1100ae8a FUN_1100ae8a  (called by: FUN_11008d53@11008d53, FUN_110095ae@110095ae, FUN_1100d565@1100d565)

int * __cdecl FUN_1100ae8a(uint *param_1)

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
  
  puVar10 = DAT_1101b038 + DAT_1101b034 * 5;
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
  for (param_1 = DAT_1101b02c;
      (param_1 < puVar10 && ((param_1[1] & local_c) == 0 && (*param_1 & local_10) == 0));
      param_1 = param_1 + 5) {
  }
  if (param_1 == puVar10) {
    for (param_1 = DAT_1101b038;
        (param_1 < DAT_1101b02c && ((param_1[1] & local_c) == 0 && (*param_1 & local_10) == 0));
        param_1 = param_1 + 5) {
    }
    if (param_1 == DAT_1101b02c) {
      for (; (param_1 < puVar10 && (param_1[2] == 0)); param_1 = param_1 + 5) {
      }
      if (param_1 == puVar10) {
        for (param_1 = DAT_1101b038; (param_1 < DAT_1101b02c && (param_1[2] == 0));
            param_1 = param_1 + 5) {
        }
        if ((param_1 == DAT_1101b02c) && (param_1 = FUN_1100b193(), param_1 == (uint *)0x0)) {
          return (int *)0x0;
        }
      }
      iVar8 = FUN_1100b244((int)param_1);
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
  DAT_1101b02c = param_1;
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
    if (iVar11 == 0) goto LAB_1100b150;
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
LAB_1100b150:
  piVar12 = (int *)((int)piVar12 + iVar11);
  *piVar12 = uVar7 + 1;
  *(uint *)((int)piVar12 + (uVar7 - 4)) = uVar7 + 1;
  iVar8 = *piVar3;
  *piVar3 = iVar8 + 1;
  if (((iVar8 == 0) && (param_1 == DAT_1101b030)) && (local_8 == DAT_1101b028)) {
    DAT_1101b030 = (uint *)0x0;
  }
  *piVar5 = local_8;
  return piVar12 + 1;
}


// ---- 1100b193 FUN_1100b193  (called by: FUN_1100ae8a@1100ae8a)

undefined4 * FUN_1100b193(void)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  
  if (DAT_1101b034 == DAT_1101b024) {
    pvVar2 = HeapReAlloc(DAT_1101b03c,0,DAT_1101b038,(DAT_1101b024 * 5 + 0x50) * 4);
    if (pvVar2 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_1101b024 = DAT_1101b024 + 0x10;
    DAT_1101b038 = pvVar2;
  }
  puVar1 = (undefined4 *)((int)DAT_1101b038 + DAT_1101b034 * 0x14);
  pvVar2 = HeapAlloc(DAT_1101b03c,8,0x41c4);
  puVar1[4] = pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar1[3] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      puVar1[2] = 0xffffffff;
      *puVar1 = 0;
      puVar1[1] = 0;
      DAT_1101b034 = DAT_1101b034 + 1;
      *(undefined4 *)puVar1[4] = 0xffffffff;
      return puVar1;
    }
    HeapFree(DAT_1101b03c,0,(LPVOID)puVar1[4]);
  }
  return (undefined4 *)0x0;
}


// ---- 1100b244 FUN_1100b244  (called by: FUN_1100ae8a@1100ae8a)

int __cdecl FUN_1100b244(int param_1)

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


// ---- 1100b33f FUN_1100b33f  (called by: FUN_110095ae@110095ae)

undefined4 __cdecl FUN_1100b33f(uint *param_1,int param_2,int param_3)

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


// ---- 1100b6f1 FUN_1100b6f1  (called by: FUN_11008de9@11008de9, FUN_11008e66@11008e66, FUN_11008f1f@11008f1f, FUN_110090a2@110090a2, FUN_11009208@11009208, FUN_11009497@11009497)

void __cdecl FUN_1100b6f1(uint param_1)

{
  if ((param_1 < 0x11015450) || (0x110156b0 < param_1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
    return;
  }
  FUN_1100aa80(((int)(param_1 + 0xeefeabb0) >> 5) + 0x1c);
  return;
}


// ---- 1100b720 FUN_1100b720  (called by: FUN_11009164@11009164, FUN_1100c118@1100c118)

void __cdecl FUN_1100b720(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_1100aa80(param_1 + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}


// ---- 1100b743 FUN_1100b743  (called by: FUN_11008de9@11008de9, FUN_11008e66@11008e66, FUN_11008f1f@11008f1f, FUN_110090a2@110090a2, FUN_11009208@11009208, FUN_11009341@11009341, FUN_11009497@11009497)

void __cdecl FUN_1100b743(uint param_1)

{
  if ((param_1 < 0x11015450) || (0x110156b0 < param_1)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
    return;
  }
  FUN_1100aae1(((int)(param_1 + 0xeefeabb0) >> 5) + 0x1c);
  return;
}


// ---- 1100b772 FUN_1100b772  (called by: FUN_11009164@11009164, FUN_1100c118@1100c118)

void __cdecl FUN_1100b772(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_1100aae1(param_1 + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}


// ---- 1100b795 FUN_1100b795  (called by: FUN_1100d9d8@1100d9d8, __fclose_lk@11008e1a)

undefined4 __cdecl FUN_1100b795(uint param_1)

{
  undefined4 uVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_1101a000) &&
     ((*(byte *)((&DAT_11019f00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_1100d8ea(param_1);
    uVar1 = FUN_1100b7f2(param_1);
    FUN_1100d949(param_1);
    return uVar1;
  }
  pDVar2 = FUN_1100b913();
  *pDVar2 = 9;
  pDVar2 = FUN_1100b91c();
  *pDVar2 = 0;
  return 0xffffffff;
}


// ---- 1100b7f2 FUN_1100b7f2  (called by: FUN_1100b795@1100b795)

undefined4 __cdecl FUN_1100b7f2(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  undefined4 uVar5;
  
  iVar1 = FUN_1100d8a8(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_1100d8a8(2);
      iVar2 = FUN_1100d8a8(1);
      if (iVar2 == iVar1) goto LAB_1100b840;
    }
    hObject = (HANDLE)FUN_1100d8a8(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_1100b842;
    }
  }
LAB_1100b840:
  DVar4 = 0;
LAB_1100b842:
  FUN_1100d829(param_1);
  *(undefined1 *)((&DAT_11019f00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = 0;
  if (DVar4 == 0) {
    uVar5 = 0;
  }
  else {
    FUN_1100b8a0(DVar4);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}


// ---- 1100b875 __freebuf  (called by: __fclose_lk@11008e1a)

/* Library Function - Single Match
    __freebuf
   
   Library: Visual Studio 2003 Release */

void __cdecl __freebuf(FILE *_File)

{
  if (((_File->_flag & 0x83U) != 0) && ((_File->_flag & 8U) != 0)) {
    FUN_11008da1(_File->_base);
    *(ushort *)&_File->_flag = (ushort)_File->_flag & 0xfbf7;
    _File->_ptr = (char *)0x0;
    _File->_base = (char *)0x0;
    _File->_cnt = 0;
  }
  return;
}


// ---- 1100b8a0 FUN_1100b8a0  (called by: FUN_1100b7f2@1100b7f2, FUN_1100b98a@1100b98a, FUN_1100bd05@1100bd05, FUN_1100c366@1100c366, FUN_1100d9d8@1100d9d8)

void __cdecl FUN_1100b8a0(uint param_1)

{
  DWORD *pDVar1;
  uint *puVar2;
  int iVar3;
  
  pDVar1 = FUN_1100b91c();
  iVar3 = 0;
  *pDVar1 = param_1;
  puVar2 = &DAT_110156d0;
  do {
    if (param_1 == *puVar2) {
      pDVar1 = FUN_1100b913();
      *pDVar1 = *(DWORD *)(iVar3 * 8 + 0x110156d4);
      return;
    }
    puVar2 = puVar2 + 2;
    iVar3 = iVar3 + 1;
  } while ((int)puVar2 < 0x11015838);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    pDVar1 = FUN_1100b913();
    *pDVar1 = 0xd;
    return;
  }
  if ((param_1 < 0xbc) || (0xca < param_1)) {
    pDVar1 = FUN_1100b913();
    *pDVar1 = 0x16;
    return;
  }
  pDVar1 = FUN_1100b913();
  *pDVar1 = 8;
  return;
}


// ---- 1100b913 FUN_1100b913  (called by: FUN_11008e92@11008e92, FUN_11008f41@11008f41, FUN_1100b795@1100b795, FUN_1100b8a0@1100b8a0, FUN_1100b925@1100b925, FUN_1100b98a@1100b98a, FUN_1100bc0d@1100bc0d, FUN_1100bca0@1100bca0, FUN_1100bd05@1100bd05, FUN_1100c301@1100c301, FUN_1100c366@1100c366, FUN_1100d7ad@1100d7ad, FUN_1100d829@1100d829, FUN_1100d8a8@1100d8a8, FUN_1100d9d8@1100d9d8, FUN_1100e476@1100e476, FUN_1100e5a4@1100e5a4)

DWORD * FUN_1100b913(void)

{
  DWORD *pDVar1;
  
  pDVar1 = FUN_1100a761();
  return pDVar1 + 2;
}


// ---- 1100b91c FUN_1100b91c  (called by: FUN_1100b795@1100b795, FUN_1100b8a0@1100b8a0, FUN_1100b925@1100b925, FUN_1100bc0d@1100bc0d, FUN_1100bca0@1100bca0, FUN_1100bd05@1100bd05, FUN_1100c301@1100c301, FUN_1100c366@1100c366, FUN_1100d7ad@1100d7ad, FUN_1100d829@1100d829, FUN_1100d8a8@1100d8a8, FUN_1100d9d8@1100d9d8, FUN_1100e476@1100e476)

DWORD * FUN_1100b91c(void)

{
  DWORD *pDVar1;
  
  pDVar1 = FUN_1100a761();
  return pDVar1 + 3;
}


// ---- 1100b925 FUN_1100b925  (called by: FUN_11008e92@11008e92, FUN_11008f41@11008f41, FUN_1100be90@1100be90)

DWORD __cdecl FUN_1100b925(uint param_1,LONG param_2,DWORD param_3)

{
  DWORD DVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_1101a000) &&
     ((*(byte *)((&DAT_11019f00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_1100d8ea(param_1);
    DVar1 = FUN_1100b98a(param_1,param_2,param_3);
    FUN_1100d949(param_1);
    return DVar1;
  }
  pDVar2 = FUN_1100b913();
  *pDVar2 = 9;
  pDVar2 = FUN_1100b91c();
  *pDVar2 = 0;
  return 0xffffffff;
}


// ---- 1100b98a FUN_1100b98a  (called by: FUN_1100b925@1100b925, FUN_1100bd05@1100bd05, FUN_1100c366@1100c366, FUN_1100d9d8@1100d9d8, FUN_1100e476@1100e476)

DWORD __cdecl FUN_1100b98a(uint param_1,LONG param_2,DWORD param_3)

{
  byte *pbVar1;
  HANDLE hFile;
  DWORD *pDVar2;
  DWORD DVar3;
  uint uVar4;
  
  hFile = (HANDLE)FUN_1100d8a8(param_1);
  if (hFile == (HANDLE)0xffffffff) {
    pDVar2 = FUN_1100b913();
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
      pbVar1 = (byte *)((&DAT_11019f00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
      *pbVar1 = *pbVar1 & 0xfd;
      return DVar3;
    }
    FUN_1100b8a0(uVar4);
  }
  return 0xffffffff;
}


// ---- 1100b9fd FUN_1100b9fd  (called by: FUN_11009a3b@11009a3b)

void FUN_1100b9fd(void)

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
  DAT_1101a000 = 0x20;
  DAT_11019f00 = puVar2;
  for (; puVar2 < DAT_11019f00 + 0x120; puVar2 = puVar2 + 9) {
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
    if ((int)DAT_1101a000 < (int)UVar8) {
      puVar2 = &DAT_11019f04;
      do {
        puVar3 = _malloc(0x480);
        if (puVar3 == (undefined4 *)0x0) {
          UVar8 = DAT_1101a000;
          break;
        }
        DAT_1101a000 = DAT_1101a000 + 0x20;
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
      } while ((int)DAT_1101a000 < (int)UVar8);
    }
    uVar7 = 0;
    if (0 < (int)UVar8) {
      do {
        if (((*(HANDLE *)local_8 != (HANDLE)0xffffffff) && ((*pUVar5 & 1) != 0)) &&
           (((*pUVar5 & 8) != 0 || (DVar4 = GetFileType(*(HANDLE *)local_8), DVar4 != 0)))) {
          puVar2 = (undefined4 *)((int)(&DAT_11019f00)[(int)uVar7 >> 5] + (uVar7 & 0x1f) * 0x24);
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
    puVar2 = DAT_11019f00 + iVar6 * 9;
    if (DAT_11019f00[iVar6 * 9] == -1) {
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
          goto LAB_1100bba2;
        }
      }
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x40;
    }
    else {
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x80;
    }
LAB_1100bba2:
    iVar6 = iVar6 + 1;
    if (2 < iVar6) {
      SetHandleCount(DAT_1101a000);
      return;
    }
  } while( true );
}


// ---- 1100bbb9 FUN_1100bbb9  (called by: FUN_11009a3b@11009a3b)

void FUN_1100bbb9(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint *puVar1;
  uint uVar2;
  
  puVar1 = &DAT_11019f00;
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
      FUN_11008da1((LPVOID)*puVar1);
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x1101a000);
  return;
}


// ---- 1100bc0d FUN_1100bc0d  (called by: FUN_110090d1@110090d1)

undefined4 __cdecl FUN_1100bc0d(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  DWORD *pDVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (DAT_1101a000 <= param_1) {
LAB_1100bc8e:
    pDVar3 = FUN_1100b913();
    *pDVar3 = 9;
    return 0xffffffff;
  }
  iVar4 = (param_1 & 0x1f) * 0x24;
  if ((*(byte *)((&DAT_11019f00)[(int)param_1 >> 5] + 4 + iVar4) & 1) == 0) goto LAB_1100bc8e;
  FUN_1100d8ea(param_1);
  if ((*(byte *)((&DAT_11019f00)[(int)param_1 >> 5] + 4 + iVar4) & 1) != 0) {
    hFile = (HANDLE)FUN_1100d8a8(param_1);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = 0;
    }
    uVar5 = 0;
    if (DVar2 == 0) goto LAB_1100bc83;
    pDVar3 = FUN_1100b91c();
    *pDVar3 = DVar2;
  }
  pDVar3 = FUN_1100b913();
  *pDVar3 = 9;
  uVar5 = 0xffffffff;
LAB_1100bc83:
  FUN_1100d949(param_1);
  return uVar5;
}


// ---- 1100bca0 FUN_1100bca0  (called by: FUN_110090ff@110090ff, FUN_11009237@11009237, FUN_1100be90@1100be90)

int __cdecl FUN_1100bca0(uint param_1,char *param_2,DWORD param_3)

{
  int iVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_1101a000) &&
     ((*(byte *)((&DAT_11019f00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_1100d8ea(param_1);
    iVar1 = FUN_1100bd05(param_1,param_2,param_3);
    FUN_1100d949(param_1);
    return iVar1;
  }
  pDVar2 = FUN_1100b913();
  *pDVar2 = 9;
  pDVar2 = FUN_1100b91c();
  *pDVar2 = 0;
  return -1;
}


// ---- 1100bd05 FUN_1100bd05  (called by: FUN_1100bca0@1100bca0, FUN_1100e476@1100e476)

int __cdecl FUN_1100bd05(DWORD param_1,char *param_2,DWORD param_3)

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
LAB_1100bd1e:
    iVar4 = 0;
  }
  else {
    piVar1 = &DAT_11019f00 + ((int)param_1 >> 5);
    iVar4 = (param_1 & 0x1f) * 0x24;
    if ((*(byte *)(*piVar1 + 4 + iVar4) & 0x20) != 0) {
      FUN_1100b98a(param_1,0,2);
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
LAB_1100bded:
      if (local_c != 0) {
        return local_c - local_14;
      }
      if (param_1 == 0) goto LAB_1100be5f;
      if (param_1 == 5) {
        pDVar7 = FUN_1100b913();
        *pDVar7 = 9;
        pDVar7 = FUN_1100b91c();
        *pDVar7 = 5;
      }
      else {
        FUN_1100b8a0(param_1);
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
            goto LAB_1100bded;
          }
          local_c = local_c + local_10;
          if (((int)local_10 < (int)pcVar5 - (int)local_418) ||
             (param_3 <= (uint)((int)local_8 - (int)param_2))) goto LAB_1100bded;
        } while( true );
      }
LAB_1100be5f:
      if (((*(byte *)(*piVar1 + 4 + iVar4) & 0x40) != 0) && (*param_2 == '\x1a')) goto LAB_1100bd1e;
      pDVar7 = FUN_1100b913();
      *pDVar7 = 0x1c;
      pDVar7 = FUN_1100b91c();
      *pDVar7 = 0;
    }
    iVar4 = -1;
  }
  return iVar4;
}


// ---- 1100be90 FUN_1100be90  (called by: FUN_11009237@11009237, __putw@1100eac0)

uint __cdecl FUN_1100be90(uint param_1,int *param_2)

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
LAB_1100bf9c:
    param_2[3] = uVar1 | 0x20;
  }
  else {
    if ((uVar1 & 1) != 0) {
      param_2[1] = 0;
      if ((uVar1 & 0x10) == 0) goto LAB_1100bf9c;
      *param_2 = param_2[2];
      param_2[3] = uVar1 & 0xfffffffe;
    }
    uVar1 = param_2[3];
    param_2[1] = 0;
    param_2 = (int *)0x0;
    piVar4[3] = uVar1 & 0xffffffef | 2;
    if (((uVar1 & 0x10c) == 0) &&
       (((piVar4 != (int *)&DAT_11015470 && (piVar4 != (int *)&DAT_11015490)) ||
        (bVar5 = FUN_1100d9af(uVar2), CONCAT31(extraout_var,bVar5) == 0)))) {
      FUN_1100d96b(piVar4);
    }
    if ((*(ushort *)(piVar4 + 3) & 0x108) == 0) {
      piVar7 = (int *)0x1;
      param_2 = (int *)FUN_1100bca0(uVar2,(char *)&param_1,1);
    }
    else {
      pcVar3 = (char *)piVar4[2];
      piVar7 = (int *)(*piVar4 - (int)pcVar3);
      *piVar4 = (int)(pcVar3 + 1);
      piVar4[1] = piVar4[6] + -1;
      if ((int)piVar7 < 1) {
        if (uVar2 == 0xffffffff) {
          puVar6 = &DAT_11015838;
        }
        else {
          puVar6 = (undefined *)((&DAT_11019f00)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
        }
        if ((puVar6[4] & 0x20) != 0) {
          FUN_1100b925(uVar2,0,2);
        }
      }
      else {
        param_2 = (int *)FUN_1100bca0(uVar2,pcVar3,(DWORD)piVar7);
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


// ---- 1100bfa8 FUN_1100bfa8  (called by: FUN_11009341@11009341)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __cdecl FUN_1100bfa8(LPCSTR param_1,char *param_2,uint param_3,undefined4 *param_4)

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
      uVar6 = DAT_11019b10 | 1;
      goto LAB_1100bfe9;
    }
    if (cVar1 != 'w') {
      return (undefined4 *)0x0;
    }
    uVar5 = 0x301;
  }
  uVar6 = DAT_11019b10 | 2;
LAB_1100bfe9:
  bVar2 = true;
LAB_1100bfec:
  cVar1 = param_2[1];
  param_2 = param_2 + 1;
  if ((cVar1 == '\0') || (!bVar2)) {
    uVar5 = FUN_1100d9d8(param_1,uVar5,param_3,0x1a4);
    if ((int)uVar5 < 0) {
      return (undefined4 *)0x0;
    }
    _DAT_110199f8 = _DAT_110199f8 + 1;
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
        goto LAB_1100bfec;
      }
    }
    else if (cVar1 == '+') {
      if ((uVar5 & 2) == 0) {
        uVar5 = uVar5 & 0xfffffffe | 2;
        uVar6 = uVar6 & 0xfffffffc | 0x80;
        goto LAB_1100bfec;
      }
    }
    else if (cVar1 == 'D') {
      if ((uVar5 & 0x40) == 0) {
        uVar5 = uVar5 | 0x40;
        goto LAB_1100bfec;
      }
    }
    else if (cVar1 == 'R') {
      if (!bVar3) {
        bVar3 = true;
        uVar5 = uVar5 | 0x10;
        goto LAB_1100bfec;
      }
    }
    else if ((cVar1 == 'S') && (!bVar3)) {
      bVar3 = true;
      uVar5 = uVar5 | 0x20;
      goto LAB_1100bfec;
    }
  }
  else {
    if (cVar1 == 'b') {
      if ((uVar5 & 0xc000) != 0) goto LAB_1100c0cc;
      uVar5 = uVar5 | 0x8000;
      goto LAB_1100bfec;
    }
    if (cVar1 == 'c') {
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 | 0x4000;
        goto LAB_1100bfec;
      }
    }
    else {
      if (cVar1 != 'n') {
        if ((cVar1 != 't') || ((uVar5 & 0xc000) != 0)) goto LAB_1100c0cc;
        uVar5 = uVar5 | 0x4000;
        goto LAB_1100bfec;
      }
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 & 0xffffbfff;
        goto LAB_1100bfec;
      }
    }
  }
LAB_1100c0cc:
  bVar2 = false;
  goto LAB_1100bfec;
}


// ---- 1100c118 FUN_1100c118  (called by: FUN_11009341@11009341)

undefined4 * FUN_1100c118(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)0x0;
  FUN_1100aa80(2);
  iVar3 = 0;
  if (0 < DAT_1101b020) {
    do {
      iVar1 = *(int *)(DAT_1101a004 + iVar3 * 4);
      if (iVar1 == 0) {
        iVar3 = iVar3 * 4;
        pvVar2 = _malloc(0x38);
        *(void **)(iVar3 + DAT_1101a004) = pvVar2;
        if (*(int *)(iVar3 + DAT_1101a004) != 0) {
          InitializeCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_1101a004) + 0x20));
          EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_1101a004) + 0x20));
          puVar4 = *(undefined4 **)(iVar3 + DAT_1101a004);
LAB_1100c1bc:
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
        FUN_1100b720(iVar3,iVar1);
        iVar1 = *(int *)(DAT_1101a004 + iVar3 * 4);
        if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
          puVar4 = *(undefined4 **)(DAT_1101a004 + iVar3 * 4);
          goto LAB_1100c1bc;
        }
        FUN_1100b772(iVar3,iVar1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_1101b020);
  }
  FUN_1100aae1(2);
  return puVar4;
}


// ---- 1100c1e0 FUN_1100c1e0  (called by: FUN_110093bf@110093bf)

SIZE_T __cdecl FUN_1100c1e0(LPCVOID param_1)

{
  uint uVar1;
  SIZE_T SVar2;
  
  FUN_1100aa80(9);
  uVar1 = FUN_1100ab34((int)param_1);
  if (uVar1 == 0) {
    FUN_1100aae1(9);
    SVar2 = HeapSize(DAT_1101b03c,0,param_1);
  }
  else {
    SVar2 = *(int *)((int)param_1 + -4) - 9;
    FUN_1100aae1(9);
  }
  return SVar2;
}


// ---- 1100c225 FUN_1100c225  (called by: FUN_110094c6@110094c6)

uint __cdecl FUN_1100c225(undefined4 *param_1)

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
        FUN_1100d96b(param_1);
      }
      else {
        *param_1 = param_1[2];
      }
      iVar3 = FUN_1100c301(param_1[4],(char *)param_1[2],(char *)param_1[6]);
      param_1[1] = iVar3;
      if ((iVar3 != 0) && (iVar3 != -1)) {
        if ((param_1[3] & 0x82) == 0) {
          uVar2 = param_1[4];
          if (uVar2 == 0xffffffff) {
            puVar4 = &DAT_11015838;
          }
          else {
            puVar4 = (undefined *)((&DAT_11019f00)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
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


// ---- 1100c301 FUN_1100c301  (called by: FUN_110094c6@110094c6, FUN_1100c225@1100c225)

int __cdecl FUN_1100c301(uint param_1,char *param_2,char *param_3)

{
  int iVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_1101a000) &&
     ((*(byte *)((&DAT_11019f00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_1100d8ea(param_1);
    iVar1 = FUN_1100c366(param_1,param_2,param_3);
    FUN_1100d949(param_1);
    return iVar1;
  }
  pDVar2 = FUN_1100b913();
  *pDVar2 = 9;
  pDVar2 = FUN_1100b91c();
  *pDVar2 = 0;
  return -1;
}


// ---- 1100c366 FUN_1100c366  (called by: FUN_1100c301@1100c301, FUN_1100d9d8@1100d9d8)

int __cdecl FUN_1100c366(uint param_1,char *param_2,char *param_3)

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
    piVar1 = &DAT_11019f00 + ((int)param_1 >> 5);
    iVar9 = (param_1 & 0x1f) * 0x24;
    bVar4 = *(byte *)((&DAT_11019f00)[(int)param_1 >> 5] + iVar9 + 4);
    if ((bVar4 & 2) == 0) {
      pcVar8 = param_2;
      if (((bVar4 & 0x48) != 0) &&
         (cVar3 = *(char *)((&DAT_11019f00)[(int)param_1 >> 5] + iVar9 + 5), cVar3 != '\n')) {
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
          pDVar7 = FUN_1100b913();
          *pDVar7 = 9;
          pDVar7 = FUN_1100b91c();
          *pDVar7 = 5;
        }
        else {
          if (DVar6 == 0x6d) {
            return 0;
          }
          FUN_1100b8a0(DVar6);
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
                  goto LAB_1100c4f1;
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
LAB_1100c50b:
                  *pcVar8 = '\r';
LAB_1100c50e:
                  pcVar8 = pcVar8 + 1;
                }
                else if ((*(byte *)(*piVar1 + 4 + iVar9) & 0x48) == 0) {
                  if ((pcVar8 == param_2) && (local_5 == '\n')) {
LAB_1100c4f1:
                    *pcVar8 = '\n';
                    goto LAB_1100c50e;
                  }
                  FUN_1100b98a(param_1,-1,1);
                  if (local_5 != '\n') goto LAB_1100c50b;
                }
                else {
                  if (local_5 == '\n') goto LAB_1100c4f1;
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


// ---- 1100c53f FUN_1100c53f  (called by: FUN_110097e0@110097e0)

byte * __cdecl FUN_1100c53f(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  
  if (param_1 < param_2) {
    if (DAT_11019ccc == 0) {
      pbVar1 = param_2 + -1;
    }
    else {
      FUN_1100aa80(0x19);
      pbVar1 = param_2 + -1;
      if ((*(byte *)((int)&DAT_11019de0 + param_2[-1] + 1) & 4) == 0) {
        do {
          pbVar1 = pbVar1 + -1;
          if (pbVar1 < param_1) break;
        } while ((*(byte *)((int)&DAT_11019de0 + *pbVar1 + 1) & 4) != 0);
        FUN_1100aae1(0x19);
        pbVar1 = param_2 + (-1 - ((int)param_2 - (int)pbVar1 & 1U));
      }
      else {
        FUN_1100aae1(0x19);
        pbVar1 = param_2 + -2;
      }
    }
  }
  else {
    pbVar1 = (byte *)0x0;
  }
  return pbVar1;
}


// ---- 1100c5ac FUN_1100c5ac  (called by: FUN_1100c984@1100c984)

undefined4 __cdecl FUN_1100c5ac(int param_1)

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
  
  FUN_1100aa80(0x19);
  CodePage = FUN_1100c759(param_1);
  if (CodePage != DAT_11019cb0) {
    if (CodePage != 0) {
      iVar12 = 0;
      pUVar5 = &DAT_11015870;
LAB_1100c5e9:
      if (*pUVar5 != CodePage) goto code_r0x1100c5ed;
      local_8 = 0;
      puVar15 = &DAT_11019de0;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      iVar12 = iVar12 * 0x30;
      *(undefined1 *)puVar15 = 0;
      pbVar13 = (byte *)(iVar12 + 0x11015880);
      do {
        bVar3 = *pbVar13;
        pbVar11 = pbVar13;
        while ((bVar3 != 0 && (bVar3 = pbVar11[1], bVar3 != 0))) {
          uVar8 = (uint)*pbVar11;
          if (uVar8 <= bVar3) {
            bVar4 = (&DAT_11015868)[local_8];
            do {
              pbVar2 = (byte *)((int)&DAT_11019de0 + uVar8 + 1);
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
      DAT_11019ccc = 1;
      DAT_11019cb0 = CodePage;
      DAT_11019ee4 = FUN_1100c7a3(CodePage);
      DAT_11019cc0 = *(undefined4 *)(iVar12 + 0x11015874);
      DAT_11019cc4 = *(undefined4 *)(iVar12 + 0x11015878);
      DAT_11019cc8 = *(undefined4 *)(iVar12 + 0x1101587c);
      goto LAB_1100c73d;
    }
    goto LAB_1100c738;
  }
  goto LAB_1100c5d3;
code_r0x1100c5ed:
  pUVar5 = pUVar5 + 0xc;
  iVar12 = iVar12 + 1;
  if (0x1101595f < (int)pUVar5) goto code_r0x1100c5f8;
  goto LAB_1100c5e9;
code_r0x1100c5f8:
  BVar6 = GetCPInfo(CodePage,&local_1c);
  uVar8 = 1;
  if (BVar6 == 1) {
    DAT_11019ee4 = 0;
    puVar15 = &DAT_11019de0;
    for (iVar12 = 0x40; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar15 = 0;
      puVar15 = puVar15 + 1;
    }
    *(undefined1 *)puVar15 = 0;
    if (local_1c.MaxCharSize < 2) {
      DAT_11019ccc = 0;
      DAT_11019cb0 = CodePage;
    }
    else {
      DAT_11019cb0 = CodePage;
      if (local_1c.LeadByte[0] != '\0') {
        pBVar9 = local_1c.LeadByte + 1;
        do {
          bVar3 = *pBVar9;
          if (bVar3 == 0) break;
          for (uVar7 = (uint)pBVar9[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
            pbVar13 = (byte *)((int)&DAT_11019de0 + uVar7 + 1);
            *pbVar13 = *pbVar13 | 4;
          }
          pBVar1 = pBVar9 + 1;
          pBVar9 = pBVar9 + 2;
        } while (*pBVar1 != 0);
      }
      do {
        pbVar13 = (byte *)((int)&DAT_11019de0 + uVar8 + 1);
        *pbVar13 = *pbVar13 | 8;
        uVar8 = uVar8 + 1;
      } while (uVar8 < 0xff);
      DAT_11019ee4 = FUN_1100c7a3(CodePage);
      DAT_11019ccc = 1;
    }
    DAT_11019cc0 = 0;
    DAT_11019cc4 = 0;
    DAT_11019cc8 = 0;
  }
  else {
    if (DAT_110199fc == 0) {
      uVar14 = 0xffffffff;
      goto LAB_1100c74a;
    }
LAB_1100c738:
    FUN_1100c7d6();
  }
LAB_1100c73d:
  FUN_1100c7ff();
LAB_1100c5d3:
  uVar14 = 0;
LAB_1100c74a:
  FUN_1100aae1(0x19);
  return uVar14;
}


// ---- 1100c759 FUN_1100c759  (called by: FUN_1100c5ac@1100c5ac)

int __cdecl FUN_1100c759(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_110199fc = 1;
                    /* WARNING: Could not recover jumptable at 0x1100c773. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_110199fc = 1;
                    /* WARNING: Could not recover jumptable at 0x1100c788. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_11019b2c;
  }
  DAT_110199fc = (uint)bVar2;
  return param_1;
}


// ---- 1100c7a3 FUN_1100c7a3  (called by: FUN_1100c5ac@1100c5ac)

undefined4 __cdecl FUN_1100c7a3(int param_1)

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


// ---- 1100c7d6 FUN_1100c7d6  (called by: FUN_1100c5ac@1100c5ac)

void FUN_1100c7d6(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_11019de0;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_11019cb0 = 0;
  DAT_11019ccc = 0;
  DAT_11019ee4 = 0;
  DAT_11019cc0 = 0;
  DAT_11019cc4 = 0;
  DAT_11019cc8 = 0;
  return;
}


// ---- 1100c7ff FUN_1100c7ff  (called by: FUN_1100c5ac@1100c5ac)

void FUN_1100c7ff(void)

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
  
  BVar2 = GetCPInfo(DAT_11019cb0,&local_18);
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
    FUN_1100dfe4(1,local_118,0x100,local_518,DAT_11019cb0,DAT_11019ee4,0);
    FUN_1100dd95(DAT_11019ee4,0x100,local_118,0x100,local_218,0x100,DAT_11019cb0,0);
    FUN_1100dd95(DAT_11019ee4,0x200,local_118,0x100,local_318,0x100,DAT_11019cb0,0);
    uVar3 = 0;
    puVar7 = local_518;
    do {
      if ((*puVar7 & 1) == 0) {
        if ((*puVar7 & 2) != 0) {
          pbVar1 = (byte *)((int)&DAT_11019de0 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          uVar8 = *(undefined1 *)((int)local_318 + uVar3);
          goto LAB_1100c90b;
        }
        (&DAT_11019ce0)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_11019de0 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        uVar8 = *(undefined1 *)((int)local_218 + uVar3);
LAB_1100c90b:
        (&DAT_11019ce0)[uVar3] = uVar8;
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
          pbVar1 = (byte *)((int)&DAT_11019de0 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          cVar4 = (char)uVar3 + -0x20;
          goto LAB_1100c955;
        }
        (&DAT_11019ce0)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_11019de0 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        cVar4 = (char)uVar3 + ' ';
LAB_1100c955:
        (&DAT_11019ce0)[uVar3] = cVar4;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
  }
  return;
}


// ---- 1100c984 FUN_1100c984  (called by: FUN_1100ca3a@1100ca3a, FUN_1100caf3@1100caf3)

void FUN_1100c984(void)

{
  if (DAT_1101b044 == 0) {
    FUN_1100c5ac(-3);
    DAT_1101b044 = 1;
  }
  return;
}


// ---- 1100c9a0 FUN_1100c9a0  (called by: FUN_11009871@11009871)

byte * __cdecl FUN_1100c9a0(byte *param_1,byte *param_2,size_t param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  if (DAT_11019ccc == 0) {
    param_1 = (byte *)_strncpy((char *)param_1,(char *)param_2,param_3);
  }
  else {
    FUN_1100aa80(0x19);
    uVar4 = 0;
    pbVar6 = param_1;
    if (param_3 != 0) {
      pbVar5 = param_1;
      do {
        bVar1 = *param_2;
        uVar4 = param_3 - 1;
        bVar2 = *(byte *)((int)&DAT_11019de0 + bVar1 + 1);
        *pbVar5 = bVar1;
        if ((bVar2 & 4) == 0) {
          pbVar6 = pbVar5 + 1;
          param_2 = param_2 + 1;
          if (bVar1 == 0) goto LAB_1100ca11;
        }
        else {
          pbVar6 = pbVar5 + 1;
          if (uVar4 == 0) {
            *pbVar5 = 0;
            goto LAB_1100ca11;
          }
          bVar1 = param_2[1];
          uVar4 = param_3 - 2;
          *pbVar6 = bVar1;
          pbVar6 = pbVar5 + 2;
          param_2 = param_2 + 2;
          if (bVar1 == 0) {
            *pbVar5 = 0;
            goto LAB_1100ca11;
          }
        }
        param_3 = uVar4;
        pbVar5 = pbVar6;
      } while (uVar4 != 0);
      uVar4 = 0;
    }
LAB_1100ca11:
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
    FUN_1100aae1(0x19);
  }
  return param_1;
}


// ---- 1100ca3a FUN_1100ca3a  (called by: FUN_11009a3b@11009a3b)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1100ca3a(void)

{
  char cVar1;
  size_t sVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  uint *puVar6;
  
  if (DAT_1101b044 == 0) {
    FUN_1100c984();
  }
  iVar5 = 0;
  for (puVar6 = DAT_1101993c; (char)*puVar6 != '\0'; puVar6 = (uint *)((int)puVar6 + sVar2 + 1)) {
    if ((char)*puVar6 != '=') {
      iVar5 = iVar5 + 1;
    }
    sVar2 = _strlen((char *)puVar6);
  }
  puVar3 = _malloc(iVar5 * 4 + 4);
  _DAT_1101996c = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = (char)*DAT_1101993c;
  puVar6 = DAT_1101993c;
  while (cVar1 != '\0') {
    sVar2 = _strlen((char *)puVar6);
    if ((char)*puVar6 != '=') {
      pvVar4 = _malloc(sVar2 + 1);
      *puVar3 = pvVar4;
      if (pvVar4 == (void *)0x0) {
        __amsg_exit(9);
      }
      FUN_110096f0((uint *)*puVar3,puVar6);
      puVar3 = puVar3 + 1;
    }
    puVar6 = (uint *)((int)puVar6 + sVar2 + 1);
    cVar1 = (char)*puVar6;
  }
  FUN_11008da1(DAT_1101993c);
  DAT_1101993c = (uint *)0x0;
  *puVar3 = 0;
  _DAT_1101b040 = 1;
  return;
}


// ---- 1100caf3 FUN_1100caf3  (called by: FUN_11009a3b@11009a3b)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1100caf3(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_c;
  int local_8;
  
  if (DAT_1101b044 == 0) {
    FUN_1100c984();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_11019a00,0x104);
  _DAT_1101997c = &DAT_11019a00;
  pbVar2 = &DAT_11019a00;
  if (*DAT_1101b054 != 0) {
    pbVar2 = DAT_1101b054;
  }
  FUN_1100cb8c(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_c);
  puVar1 = _malloc(local_c + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_1100cb8c(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_c);
  _DAT_11019964 = puVar1;
  _DAT_11019960 = local_8 + -1;
  return;
}


// ---- 1100cb8c FUN_1100cb8c  (called by: FUN_1100caf3@1100caf3)

void __cdecl FUN_1100cb8c(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

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
      if (((*(byte *)((int)&DAT_11019de0 + bVar1 + 1) & 4) != 0) &&
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
      if ((*(byte *)((int)&DAT_11019de0 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar4;
          param_3 = param_3 + 1;
        }
        pbVar4 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_1100cc37;
      param_1 = pbVar4;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_1100cc37:
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
          if ((*(byte *)((int)&DAT_11019de0 + bVar1 + 1) & 4) != 0) {
            pbVar4 = pbVar4 + 1;
            *param_5 = *param_5 + 1;
          }
        }
        else {
          if ((*(byte *)((int)&DAT_11019de0 + bVar1 + 1) & 4) != 0) {
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


// ---- 1100cd40 FUN_1100cd40  (called by: FUN_11009a3b@11009a3b)

LPSTR FUN_1100cd40(void)

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
  if (DAT_11019b04 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr != (LPWCH)0x0) {
      DAT_11019b04 = 1;
      goto LAB_1100cd97;
    }
    pCVar9 = GetEnvironmentStrings();
    if (pCVar9 == (LPCH)0x0) {
      return (LPSTR)0x0;
    }
    DAT_11019b04 = 2;
  }
  else {
    if (DAT_11019b04 == 1) {
LAB_1100cd97:
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
          FUN_11008da1(pCVar6);
          local_8 = (LPSTR)0x0;
        }
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return local_8;
    }
    if (DAT_11019b04 != 2) {
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
    FUN_110089e0((undefined4 *)pCVar6,(undefined4 *)pCVar9,(uint)(pcVar7 + (1 - (int)pCVar9)));
  }
  FreeEnvironmentStringsA(pCVar9);
  return pCVar6;
}


// ---- 1100ce72 FUN_1100ce72  (called by: __amsg_exit@11009bb1)

void FUN_1100ce72(void)

{
  if ((DAT_11019944 == 1) || ((DAT_11019944 == 0 && (DAT_11019948 == 1)))) {
    FUN_1100ceab(0xfc);
    if (DAT_11019b08 != (code *)0x0) {
      (*DAT_11019b08)();
    }
    FUN_1100ceab(0xff);
  }
  return;
}


// ---- 1100ceab FUN_1100ceab  (called by: FUN_1100ce72@1100ce72, FUN_1100d5f2@1100d5f2, __amsg_exit@11009bb1)

void __cdecl FUN_1100ceab(DWORD param_1)

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
  pDVar2 = &DAT_11015960;
  do {
    if (param_1 == *pDVar2) break;
    pDVar2 = pDVar2 + 2;
    iVar5 = iVar5 + 1;
  } while ((int)pDVar2 < 0x110159f0);
  if (param_1 == (&DAT_11015960)[iVar5 * 2]) {
    if ((DAT_11019944 == 1) || ((DAT_11019944 == 0 && (DAT_11019948 == 1)))) {
      pDVar2 = &param_1;
      puVar1 = (undefined4 *)(iVar5 * 8 + 0x11015964);
      lpOverlapped = (LPOVERLAPPED)0x0;
      sVar4 = _strlen((char *)*puVar1);
      lpBuffer = (LPCVOID)*puVar1;
      hFile = GetStdHandle(0xfffffff4);
      WriteFile(hFile,lpBuffer,sVar4,pDVar2,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_1a8,0x104);
      if (DVar3 == 0) {
        FUN_110096f0(local_1a8,(uint *)"<program name unknown>");
      }
      _Dest = local_1a8;
      sVar4 = _strlen((char *)local_1a8);
      if (0x3c < sVar4 + 1) {
        sVar4 = _strlen((char *)local_1a8);
        _Dest = (uint *)(auStackY_1e3 + sVar4);
        _strncpy((char *)_Dest,"...",3);
      }
      FUN_110096f0(local_a4,(uint *)"Runtime Error!\n\nProgram: ");
      FUN_11009700(local_a4,_Dest);
      FUN_11009700(local_a4,(uint *)&DAT_11010828);
      FUN_11009700(local_a4,*(uint **)(iVar5 * 8 + 0x11015964));
      auStackY_1e3._3_4_ = 0x1100cfcf;
      FUN_1100e22e(local_a4,"Microsoft Visual C++ Runtime Library",0x12010);
    }
  }
  return;
}


// ---- 1100cffe FUN_1100cffe  (called by: -)

int FUN_1100cffe(int *param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    iVar3 = FUN_1100a868();
    return iVar3;
  }
  if ((DAT_11019b0c == (FARPROC)0x0) ||
     (bVar2 = FUN_1100d09a(DAT_11019b0c), CONCAT31(extraout_var,bVar2) == 0)) {
    return 0;
  }
  iVar3 = (*DAT_11019b0c)(param_1);
  return iVar3;
}


// ---- 1100d062 FUN_1100d062  (called by: FUN_11009f07@11009f07, FUN_1100a435@1100a435)

bool __cdecl FUN_1100d062(void *param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadReadPtr(param_1,param_2);
  return BVar1 == 0;
}


// ---- 1100d07e FUN_1100d07e  (called by: FUN_1100a435@1100a435)

bool __cdecl FUN_1100d07e(LPVOID param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadWritePtr(param_1,param_2);
  return BVar1 == 0;
}


// ---- 1100d09a FUN_1100d09a  (called by: FUN_1100a435@1100a435, FUN_1100cffe@1100cffe)

bool __cdecl FUN_1100d09a(FARPROC param_1)

{
  BOOL BVar1;
  
  BVar1 = IsBadCodePtr(param_1);
  return BVar1 == 0;
}


// ---- 1100d0c0 _strcmp  (called by: FUN_1100a164@1100a164)

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
      if (bVar3 != *_Str2) goto LAB_1100d104;
      _Str2 = _Str2 + 1;
      if (bVar3 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_1100d0d0;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar3 = (byte)uVar1;
    bVar4 = bVar3 < (byte)*_Str2;
    if (bVar3 != *_Str2) goto LAB_1100d104;
    if (bVar3 == 0) {
      return 0;
    }
    bVar3 = (byte)((ushort)uVar1 >> 8);
    bVar4 = bVar3 < (byte)_Str2[1];
    if (bVar3 != _Str2[1]) goto LAB_1100d104;
    if (bVar3 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_1100d0d0:
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
LAB_1100d104:
  return (uint)bVar4 * -2 + 1;
}


// ---- 1100d14c FUN_1100d14c  (called by: -)

undefined4 FUN_1100d14c(int param_1,PVOID param_2,undefined4 param_3)

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
          FUN_1100899a();
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


// ---- 1100d209 FUN_1100d209  (called by: -)

void FUN_1100d209(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}


// ---- 1100d230 FUN_1100d230  (called by: FUN_1100a435@1100a435, FUN_1100ab5f@1100ab5f)

undefined4 * __cdecl FUN_1100d230(undefined4 *param_1,undefined4 *param_2,uint param_3)

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
          goto switchD_1100d3e7_caseD_2;
        case 3:
          goto switchD_1100d3e7_caseD_3;
        }
        goto switchD_1100d3e7_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_1100d3e7_caseD_0;
      case 1:
        goto switchD_1100d3e7_caseD_1;
      case 2:
        goto switchD_1100d3e7_caseD_2;
      case 3:
        goto switchD_1100d3e7_caseD_3;
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
              goto switchD_1100d3e7_caseD_2;
            case 3:
              goto switchD_1100d3e7_caseD_3;
            }
            goto switchD_1100d3e7_caseD_1;
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
              goto switchD_1100d3e7_caseD_2;
            case 3:
              goto switchD_1100d3e7_caseD_3;
            }
            goto switchD_1100d3e7_caseD_1;
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
              goto switchD_1100d3e7_caseD_2;
            case 3:
              goto switchD_1100d3e7_caseD_3;
            }
            goto switchD_1100d3e7_caseD_1;
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
switchD_1100d3e7_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_1100d3e7_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_1100d3e7_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_1100d3e7_caseD_0:
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
        goto switchD_1100d265_caseD_2;
      case 3:
        goto switchD_1100d265_caseD_3;
      }
      goto switchD_1100d265_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_1100d265_caseD_0;
    case 1:
      goto switchD_1100d265_caseD_1;
    case 2:
      goto switchD_1100d265_caseD_2;
    case 3:
      goto switchD_1100d265_caseD_3;
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
            goto switchD_1100d265_caseD_2;
          case 3:
            goto switchD_1100d265_caseD_3;
          }
          goto switchD_1100d265_caseD_1;
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
            goto switchD_1100d265_caseD_2;
          case 3:
            goto switchD_1100d265_caseD_3;
          }
          goto switchD_1100d265_caseD_1;
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
            goto switchD_1100d265_caseD_2;
          case 3:
            goto switchD_1100d265_caseD_3;
          }
          goto switchD_1100d265_caseD_1;
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
switchD_1100d265_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_1100d265_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_1100d265_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_1100d265_caseD_0:
  return param_1;
}


// ---- 1100d565 FUN_1100d565  (called by: FUN_1100a6dc@1100a6dc, FUN_1100a761@1100a761)

int * __cdecl FUN_1100d565(int param_1,int param_2)

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
      if (_Size <= DAT_1101544c) {
        FUN_1100aa80(9);
        piVar1 = FUN_1100ae8a(_Size);
        FUN_1100aae1(9);
        if (piVar1 != (int *)0x0) {
          _memset(piVar1,0,(size_t)_Size);
          return piVar1;
        }
      }
      piVar1 = HeapAlloc(DAT_1101b03c,8,(SIZE_T)puVar3);
      if (piVar1 != (int *)0x0) {
        return piVar1;
      }
    }
    if (DAT_11019990 == 0) {
      return (int *)0x0;
    }
    iVar2 = FUN_1100a91f(puVar3);
  } while (iVar2 != 0);
  return (int *)0x0;
}


// ---- 1100d5f2 FUN_1100d5f2  (called by: FUN_1100a868@1100a868)

void FUN_1100d5f2(void)

{
  FUN_1100ceab(10);
  FUN_1100e2b7((DWORD *)0x16);
                    /* WARNING: Subroutine does not return */
  __exit(3);
}


// ---- 1100d68a FUN_1100d68a  (called by: FUN_1100d9d8@1100d9d8)

uint FUN_1100d68a(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  int local_8;
  int local_4;
  
  uVar4 = 0xffffffff;
  FUN_1100aa80(0x12);
  local_8 = 0;
  local_4 = 0;
  piVar3 = &DAT_11019f00;
  while (puVar2 = (undefined4 *)*piVar3, puVar1 = puVar2, puVar2 != (undefined4 *)0x0) {
    for (; puVar2 < puVar1 + 0x120; puVar2 = puVar2 + 9) {
      if ((*(byte *)(puVar2 + 1) & 1) == 0) {
        if (puVar2[2] == 0) {
          FUN_1100aa80(0x11);
          if (puVar2[2] == 0) {
            InitializeCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
            puVar2[2] = puVar2[2] + 1;
          }
          FUN_1100aae1(0x11);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
        if ((*(byte *)(puVar2 + 1) & 1) == 0) {
          *puVar2 = 0xffffffff;
          uVar4 = ((int)puVar2 - *piVar3) / 0x24 + local_4;
          if (uVar4 != 0xffffffff) goto LAB_1100d79c;
          break;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
      }
      puVar1 = (undefined4 *)*piVar3;
    }
    local_4 = local_4 + 0x20;
    piVar3 = piVar3 + 1;
    local_8 = local_8 + 1;
    if (0x11019fff < (int)piVar3) goto LAB_1100d79c;
  }
  puVar2 = _malloc(0x480);
  if (puVar2 != (undefined4 *)0x0) {
    DAT_1101a000 = DAT_1101a000 + 0x20;
    (&DAT_11019f00)[local_8] = puVar2;
    puVar1 = puVar2;
    for (; puVar2 < puVar1 + 0x120; puVar2 = puVar2 + 9) {
      *(undefined1 *)(puVar2 + 1) = 0;
      *puVar2 = 0xffffffff;
      puVar2[2] = 0;
      *(undefined1 *)((int)puVar2 + 5) = 10;
      puVar1 = (undefined4 *)(&DAT_11019f00)[local_8];
    }
    uVar4 = local_8 << 5;
    FUN_1100d8ea(uVar4);
  }
LAB_1100d79c:
  FUN_1100aae1(0x12);
  return uVar4;
}


// ---- 1100d7ad FUN_1100d7ad  (called by: FUN_1100d9d8@1100d9d8)

undefined4 __cdecl FUN_1100d7ad(uint param_1,HANDLE param_2)

{
  DWORD *pDVar1;
  int iVar2;
  DWORD nStdHandle;
  
  if (param_1 < DAT_1101a000) {
    iVar2 = (param_1 & 0x1f) * 0x24;
    if (*(int *)((&DAT_11019f00)[(int)param_1 >> 5] + iVar2) == -1) {
      if (DAT_11019948 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_1100d806;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,param_2);
      }
LAB_1100d806:
      *(HANDLE *)((&DAT_11019f00)[(int)param_1 >> 5] + iVar2) = param_2;
      return 0;
    }
  }
  pDVar1 = FUN_1100b913();
  *pDVar1 = 9;
  pDVar1 = FUN_1100b91c();
  *pDVar1 = 0;
  return 0xffffffff;
}


// ---- 1100d829 FUN_1100d829  (called by: FUN_1100b7f2@1100b7f2)

undefined4 __cdecl FUN_1100d829(uint param_1)

{
  int *piVar1;
  DWORD *pDVar2;
  int iVar3;
  DWORD nStdHandle;
  
  if (param_1 < DAT_1101a000) {
    iVar3 = (param_1 & 0x1f) * 0x24;
    piVar1 = (int *)((&DAT_11019f00)[(int)param_1 >> 5] + iVar3);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_11019948 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_1100d885;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_1100d885:
      *(undefined4 *)((&DAT_11019f00)[(int)param_1 >> 5] + iVar3) = 0xffffffff;
      return 0;
    }
  }
  pDVar2 = FUN_1100b913();
  *pDVar2 = 9;
  pDVar2 = FUN_1100b91c();
  *pDVar2 = 0;
  return 0xffffffff;
}


// ---- 1100d8a8 FUN_1100d8a8  (called by: FUN_1100b7f2@1100b7f2, FUN_1100b98a@1100b98a, FUN_1100bc0d@1100bc0d, FUN_1100e476@1100e476)

undefined4 __cdecl FUN_1100d8a8(uint param_1)

{
  DWORD *pDVar1;
  
  if ((param_1 < DAT_1101a000) &&
     ((*(byte *)((&DAT_11019f00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    return *(undefined4 *)((&DAT_11019f00)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24);
  }
  pDVar1 = FUN_1100b913();
  *pDVar1 = 9;
  pDVar1 = FUN_1100b91c();
  *pDVar1 = 0;
  return 0xffffffff;
}


// ---- 1100d8ea FUN_1100d8ea  (called by: FUN_1100b795@1100b795, FUN_1100b925@1100b925, FUN_1100bc0d@1100bc0d, FUN_1100bca0@1100bca0, FUN_1100c301@1100c301, FUN_1100d68a@1100d68a)

void __cdecl FUN_1100d8ea(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (param_1 & 0x1f) * 0x24;
  iVar1 = (&DAT_11019f00)[(int)param_1 >> 5] + iVar2;
  if (*(int *)(iVar1 + 8) == 0) {
    FUN_1100aa80(0x11);
    if (*(int *)(iVar1 + 8) == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xc));
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    }
    FUN_1100aae1(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((&DAT_11019f00)[(int)param_1 >> 5] + 0xc + iVar2));
  return;
}


// ---- 1100d949 FUN_1100d949  (called by: FUN_1100b795@1100b795, FUN_1100b925@1100b925, FUN_1100bc0d@1100bc0d, FUN_1100bca0@1100bca0, FUN_1100c301@1100c301, FUN_1100d9d8@1100d9d8)

void __cdecl FUN_1100d949(uint param_1)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_11019f00)[(int)param_1 >> 5] + 0xc + (param_1 & 0x1f) * 0x24));
  return;
}


// ---- 1100d96b FUN_1100d96b  (called by: FUN_1100be90@1100be90, FUN_1100c225@1100c225)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1100d96b(undefined4 *param_1)

{
  void *pvVar1;
  
  _DAT_110199f8 = _DAT_110199f8 + 1;
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


// ---- 1100d9af FUN_1100d9af  (called by: FUN_1100be90@1100be90)

byte __cdecl FUN_1100d9af(uint param_1)

{
  if (param_1 < DAT_1101a000) {
    return *(byte *)((&DAT_11019f00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0x40;
  }
  return 0;
}


// ---- 1100d9d8 FUN_1100d9d8  (called by: FUN_1100bfa8@1100bfa8)

uint __cdecl FUN_1100d9d8(LPCSTR param_1,uint param_2,uint param_3,uint param_4)

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
  if (((param_2 & 0x8000) == 0) && (((param_2 & 0x4000) != 0 || (DAT_11019b5c != 0x8000)))) {
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
    if (uVar2 != 2) goto LAB_1100dadc;
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
    if (param_3 != 0x40) goto LAB_1100dadc;
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
      if (uVar2 == 0x200) goto LAB_1100daf6;
      if (uVar2 != 0x300) goto LAB_1100dadc;
      local_c = 2;
    }
  }
  else {
    if (uVar2 != 0x500) {
      if (uVar2 == 0x600) {
LAB_1100daf6:
        local_c = 5;
        goto LAB_1100db06;
      }
      if (uVar2 != 0x700) {
LAB_1100dadc:
        pDVar4 = FUN_1100b913();
        *pDVar4 = 0x16;
        pDVar4 = FUN_1100b91c();
        *pDVar4 = 0;
        return 0xffffffff;
      }
    }
    local_c = 1;
  }
LAB_1100db06:
  uVar2 = 0x80;
  if (((param_2 & 0x100) != 0) && ((~DAT_1101994c & param_4 & 0x80) == 0)) {
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
  uVar3 = FUN_1100d68a();
  if (uVar3 == 0xffffffff) {
    pDVar4 = FUN_1100b913();
    *pDVar4 = 0x18;
    pDVar4 = FUN_1100b91c();
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
      FUN_1100d7ad(uVar3,hFile);
      iVar7 = (uVar3 & 0x1f) * 0x24;
      param_1._3_1_ = local_5 & 0x48;
      *(byte *)((&DAT_11019f00)[(int)uVar3 >> 5] + 4 + iVar7) = local_5 | 1;
      if ((((local_5 & 0x48) == 0) && ((local_5 & 0x80) != 0)) && ((param_2 & 2) != 0)) {
        local_14 = FUN_1100b98a(uVar3,-1,2);
        if (local_14 == 0xffffffff) {
          pDVar4 = FUN_1100b91c();
          if (*pDVar4 == 0x83) goto LAB_1100dc80;
        }
        else {
          param_3 = param_3 & 0xffffff;
          iVar6 = FUN_1100c366(uVar3,(char *)((int)&param_3 + 3),(char *)0x1);
          if ((((iVar6 != 0) || (param_3._3_1_ != '\x1a')) ||
              (iVar6 = FUN_1100e476(uVar3,local_14), iVar6 != -1)) &&
             (DVar5 = FUN_1100b98a(uVar3,0,0), DVar5 != 0xffffffff)) goto LAB_1100dc80;
        }
        FUN_1100b795(uVar3);
        uVar2 = 0xffffffff;
      }
      else {
LAB_1100dc80:
        if ((param_1._3_1_ == 0) && ((param_2 & 8) != 0)) {
          pbVar1 = (byte *)((&DAT_11019f00)[(int)uVar3 >> 5] + 4 + iVar7);
          *pbVar1 = *pbVar1 | 0x20;
        }
        uVar2 = uVar3;
      }
      goto LAB_1100dc99;
    }
    CloseHandle(hFile);
  }
  DVar5 = GetLastError();
  FUN_1100b8a0(DVar5);
  uVar2 = 0xffffffff;
LAB_1100dc99:
  FUN_1100d949(uVar3);
  return uVar2;
}


// ---- 1100dd95 FUN_1100dd95  (called by: FUN_1100c7ff@1100c7ff, FUN_1100e8d6@1100e8d6)

int __cdecl
FUN_1100dd95(LCID param_1,DWORD param_2,char *param_3,int param_4,LPWSTR param_5,int param_6,
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
  puStack_c = &DAT_11010870;
  pcStack_10 = FUN_1100d14c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_11019b34 == 0) {
    ExceptionList = &local_14;
    iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_11019b34 = 2;
    }
    else {
      DAT_11019b34 = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_1100dfb9(param_3,param_4);
  }
  if (DAT_11019b34 == 2) {
    iVar1 = LCMapStringA(param_1,param_2,param_3,param_4,(LPSTR)param_5,param_6);
    ExceptionList = local_14;
    return iVar1;
  }
  if (DAT_11019b34 == 1) {
    if (param_7 == 0) {
      param_7 = DAT_11019b2c;
    }
    iVar1 = MultiByteToWideChar(param_7,(-(uint)(param_8 != 0) & 8) + 1,param_3,param_4,(LPWSTR)0x0,
                                0);
    if (iVar1 == 0) {
      ExceptionList = local_14;
      return 0;
    }
    local_8 = 0;
    FUN_11009390(unaff_DI);
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
      FUN_11009390(unaff_DI);
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


// ---- 1100dfb9 FUN_1100dfb9  (called by: FUN_1100dd95@1100dd95)

int __cdecl FUN_1100dfb9(char *param_1,int param_2)

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


// ---- 1100dfe4 FUN_1100dfe4  (called by: FUN_1100c7ff@1100c7ff, FUN_1100e861@1100e861)

BOOL __cdecl
FUN_1100dfe4(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6,
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
  puStack_c = &DAT_11010888;
  pcStack_10 = FUN_1100d14c;
  local_14 = ExceptionList;
  local_1c = (undefined1 *)(aWStack_2a + -7);
  ExceptionList = &local_14;
  pWVar1 = aWStack_2a + -7;
  if (DAT_11019b38 == 0) {
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
    DAT_11019b38 = iVar3;
    pWVar1 = (WCHAR *)local_1c;
  }
  local_1c = (undefined1 *)pWVar1;
  if (DAT_11019b38 == 2) {
    if (param_6 == 0) {
      param_6 = DAT_11019b1c;
    }
    BVar2 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
    ExceptionList = local_14;
    return BVar2;
  }
  if (DAT_11019b38 == 1) {
    if (param_5 == 0) {
      param_5 = DAT_11019b2c;
    }
    iVar3 = MultiByteToWideChar(param_5,(-(uint)(param_7 != 0) & 8) + 1,param_2,param_3,(LPWSTR)0x0,
                                0);
    if (iVar3 != 0) {
      local_8 = 0;
      FUN_11009390(unaff_DI);
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


// ---- 1100e130 _strncpy  (called by: FUN_1100c9a0@1100c9a0, FUN_1100ceab@1100ceab)

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
        goto joined_r0x1100e16e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_1100e1ab;
        goto LAB_1100e219;
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
joined_r0x1100e215:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_1100e219:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_1100e1ab;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x1100e215;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x1100e215;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x1100e215;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x1100e16e:
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
LAB_1100e1ab:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}


// ---- 1100e22e FUN_1100e22e  (called by: FUN_1100ceab@1100ceab)

int __cdecl FUN_1100e22e(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_11019b3c == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_11019b3c = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_11019b3c != (FARPROC)0x0) {
        DAT_11019b40 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_11019b44 = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_1100e27d;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_1100e27d:
    if (DAT_11019b40 != (FARPROC)0x0) {
      iVar1 = (*DAT_11019b40)();
      if ((iVar1 != 0) && (DAT_11019b44 != (FARPROC)0x0)) {
        iVar1 = (*DAT_11019b44)(iVar1);
      }
    }
    iVar1 = (*DAT_11019b3c)(iVar1,param_1,param_2,param_3);
  }
  return iVar1;
}


// ---- 1100e2b7 FUN_1100e2b7  (called by: FUN_1100d5f2@1100d5f2)

undefined4 __cdecl FUN_1100e2b7(DWORD *param_1)

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
    puVar7 = &DAT_11019b48;
    pcVar6 = DAT_11019b48;
LAB_1100e33d:
    bVar1 = true;
    FUN_1100aa80(1);
    pDVar2 = param_1;
  }
  else {
    if (((param_1 != (DWORD *)0x4) && (param_1 != (DWORD *)0x8)) && (param_1 != (DWORD *)0xb)) {
      if (param_1 == (DWORD *)0xf) {
        puVar7 = &DAT_11019b54;
        pcVar6 = DAT_11019b54;
      }
      else if (param_1 == (DWORD *)0x15) {
        puVar7 = &DAT_11019b4c;
        pcVar6 = DAT_11019b4c;
      }
      else {
        if (param_1 != (DWORD *)0x16) {
          return 0xffffffff;
        }
        puVar7 = &DAT_11019b50;
        pcVar6 = DAT_11019b50;
      }
      goto LAB_1100e33d;
    }
    pDVar2 = FUN_1100a761();
    uVar3 = FUN_1100e439((int)param_1,pDVar2[0x14]);
    puVar7 = (undefined4 *)(uVar3 + 8);
    pcVar6 = (code *)*puVar7;
  }
  if (pcVar6 == (code *)0x1) {
    if (bVar1) {
      FUN_1100aae1(1);
      return 0;
    }
    return 0;
  }
  if (pcVar6 == (code *)0x0) {
    if (bVar1) {
      FUN_1100aae1(1);
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
      goto LAB_1100e3b1;
    }
  }
  else {
LAB_1100e3b1:
    if (param_1 == (DWORD *)0x8) {
      if (DAT_11015a68 < DAT_11015a6c + DAT_11015a68) {
        iVar4 = DAT_11015a68 * 0xc;
        iVar5 = DAT_11015a68;
        do {
          iVar4 = iVar4 + 0xc;
          *(undefined4 *)((pDVar2[0x14] - 4) + iVar4) = 0;
          iVar5 = iVar5 + 1;
        } while (iVar5 < DAT_11015a6c + DAT_11015a68);
      }
      goto LAB_1100e3ef;
    }
  }
  *puVar7 = 0;
LAB_1100e3ef:
  if (bVar1) {
    FUN_1100aae1(1);
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


// ---- 1100e439 FUN_1100e439  (called by: FUN_1100e2b7@1100e2b7)

uint __cdecl FUN_1100e439(int param_1,uint param_2)

{
  int *piVar1;
  uint uVar3;
  uint uVar2;
  
  uVar2 = param_2;
  if (*(int *)(param_2 + 4) != param_1) {
    uVar3 = param_2;
    do {
      uVar2 = uVar3 + 0xc;
      if (param_2 + DAT_11015a74 * 0xc <= uVar2) break;
      piVar1 = (int *)(uVar3 + 0x10);
      uVar3 = uVar2;
    } while (*piVar1 != param_1);
  }
  if ((param_2 + DAT_11015a74 * 0xc <= uVar2) || (*(int *)(uVar2 + 4) != param_1)) {
    uVar2 = 0;
  }
  return uVar2;
}


// ---- 1100e476 FUN_1100e476  (called by: FUN_1100d9d8@1100d9d8)

int __cdecl FUN_1100e476(uint param_1,int param_2)

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
  
  FUN_11009390(unaff_BP);
  iVar8 = 0;
  DVar1 = FUN_1100b98a(param_1,0,1);
  if ((DVar1 == 0xffffffff) || (DVar2 = FUN_1100b98a(param_1,0,2), DVar2 == 0xffffffff)) {
    iVar8 = -1;
  }
  else {
    DVar2 = param_2 - DVar2;
    if ((int)DVar2 < 1) {
      if ((int)DVar2 < 0) {
        FUN_1100b98a(param_1,param_2,0);
        hFile = (HANDLE)FUN_1100d8a8(param_1);
        BVar7 = SetEndOfFile(hFile);
        iVar8 = (BVar7 != 0) - 1;
        if (iVar8 == -1) {
          pDVar6 = FUN_1100b913();
          *pDVar6 = 0xd;
          DVar2 = GetLastError();
          pDVar6 = FUN_1100b91c();
          *pDVar6 = DVar2;
        }
      }
    }
    else {
      _memset(local_1008,0,0x1000);
      uStackY_28 = 0x1100e4e3;
      iVar3 = FUN_1100e5a4(param_1,0x8000);
      do {
        DVar4 = 0x1000;
        if ((int)DVar2 < 0x1000) {
          DVar4 = DVar2;
        }
        iVar5 = FUN_1100bd05(param_1,local_1008,DVar4);
        if (iVar5 == -1) {
          pDVar6 = FUN_1100b91c();
          if (*pDVar6 == 5) {
            pDVar6 = FUN_1100b913();
            *pDVar6 = 0xd;
          }
          iVar8 = -1;
          break;
        }
        DVar2 = DVar2 - iVar5;
      } while (0 < (int)DVar2);
      FUN_1100e5a4(param_1,iVar3);
    }
    FUN_1100b98a(param_1,DVar1,0);
  }
  return iVar8;
}


// ---- 1100e5a4 FUN_1100e5a4  (called by: FUN_1100e476@1100e476)

int __cdecl FUN_1100e5a4(uint param_1,int param_2)

{
  byte bVar1;
  DWORD *pDVar2;
  byte bVar3;
  
  bVar1 = *(byte *)((&DAT_11019f00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
  if (param_2 == 0x8000) {
    bVar3 = bVar1 & 0x7f;
  }
  else {
    if (param_2 != 0x4000) {
      pDVar2 = FUN_1100b913();
      *pDVar2 = 0x16;
      return -1;
    }
    bVar3 = bVar1 | 0x80;
  }
  *(byte *)((&DAT_11019f00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = bVar3;
  return (-(uint)((bVar1 & 0x80) != 0) & 0xffffc000) + 0x8000;
}


// ---- 1100e610 FUN_1100e610  (called by: -)

int __cdecl FUN_1100e610(byte *param_1,byte *param_2)

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


// ---- 1100e650 FUN_1100e650  (called by: -)

byte * __cdecl FUN_1100e650(byte *param_1,byte *param_2)

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


// ---- 1100e690 FUN_1100e690  (called by: -)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_1100e690(void *this,byte *param_1,byte *param_2)

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
  
  iVar2 = _DAT_11019cac;
  if (DAT_11019b1c == 0) {
    bVar5 = 0xff;
    do {
      do {
        cVar6 = '\0';
        if (bVar5 == 0) goto LAB_1100e6de;
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
LAB_1100e6de:
    uVar7 = (uint)cVar6;
  }
  else {
    LOCK();
    _DAT_11019cac = _DAT_11019cac + 1;
    UNLOCK();
    bVar1 = 0 < DAT_11019ca8;
    if (bVar1) {
      LOCK();
      UNLOCK();
      _DAT_11019cac = iVar2;
      FUN_1100aa80(0x13);
      this = extraout_ECX;
    }
    uVar9 = (uint)bVar1;
    uVar7 = 0xff;
    uVar8 = 0;
    do {
      do {
        if ((char)uVar7 == '\0') goto LAB_1100e73f;
        bVar5 = *param_2;
        uVar7 = CONCAT31((int3)(uVar7 >> 8),bVar5);
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        uVar8 = CONCAT31((int3)(uVar8 >> 8),bVar4);
        param_1 = param_1 + 1;
      } while (bVar5 == bVar4);
      uVar8 = FUN_1100e8d6(this,uVar8);
      uVar7 = FUN_1100e8d6(this_00,uVar7);
      this = extraout_ECX_00;
    } while ((byte)uVar8 == (byte)uVar7);
    uVar8 = (uint)((byte)uVar8 < (byte)uVar7);
    uVar7 = (1 - uVar8) - (uint)(uVar8 != 0);
LAB_1100e73f:
    if (uVar9 == 0) {
      LOCK();
      _DAT_11019cac = _DAT_11019cac + -1;
      UNLOCK();
    }
    else {
      FUN_1100aae1(0x13);
    }
  }
  return uVar7;
}


// ---- 1100e760 FUN_1100e760  (called by: -)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1100e760(byte *param_1,char *param_2,void *param_3)

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
  
  iVar2 = _DAT_11019cac;
  uVar6 = 0;
  if (param_3 != (void *)0x0) {
    if (DAT_11019b1c == 0) {
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
        if (bVar3 != (byte)uVar4) goto LAB_1100e7bf;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar6 = 0;
      bVar3 = (byte)(uVar4 >> 8);
      bVar8 = bVar3 < (byte)uVar4;
      if (bVar3 != (byte)uVar4) {
LAB_1100e7bf:
        uVar6 = 0xffffffff;
        if (!bVar8) {
          uVar6 = 1;
        }
      }
    }
    else {
      LOCK();
      _DAT_11019cac = _DAT_11019cac + 1;
      UNLOCK();
      bVar8 = 0 < DAT_11019ca8;
      if (bVar8) {
        LOCK();
        UNLOCK();
        _DAT_11019cac = iVar2;
        FUN_1100aa80(0x13);
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
        uVar7 = FUN_1100e8d6(param_3,uVar7);
        uVar5 = FUN_1100e8d6(this,uVar5);
        bVar8 = uVar5 < uVar7;
        if (uVar5 != uVar7) goto LAB_1100e835;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar6 = 0;
      bVar8 = uVar5 < uVar7;
      if (uVar5 != uVar7) {
LAB_1100e835:
        uVar6 = 0xffffffff;
        if (!bVar8) {
          uVar6 = 1;
        }
      }
      if (uVar9 == 0) {
        LOCK();
        _DAT_11019cac = _DAT_11019cac + -1;
        UNLOCK();
      }
      else {
        FUN_1100aae1(0x13);
      }
    }
  }
  return uVar6;
}


// ---- 1100e861 FUN_1100e861  (called by: FUN_1100e8d6@1100e8d6)

uint __thiscall FUN_1100e861(void *this,int param_1,uint param_2)

{
  BOOL BVar1;
  int iVar2;
  undefined4 local_8;
  
  if (param_1 + 1U < 0x101) {
    param_1._2_2_ = *(ushort *)(PTR_DAT_11015a90 + param_1 * 2);
  }
  else {
    if ((PTR_DAT_11015a90[(param_1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      local_8 = CONCAT31((int3)((uint)this >> 8),(char)param_1) & 0xffff00ff;
      iVar2 = 1;
    }
    else {
      local_8._0_2_ = CONCAT11((char)param_1,(char)((uint)param_1 >> 8));
      local_8 = CONCAT22((short)((uint)this >> 0x10),(undefined2)local_8) & 0xff00ffff;
      iVar2 = 2;
    }
    BVar1 = FUN_1100dfe4(1,(LPCSTR)&local_8,iVar2,(LPWORD)((int)&param_1 + 2),0,0,1);
    if (BVar1 == 0) {
      return 0;
    }
  }
  return param_1._2_2_ & param_2;
}


// ---- 1100e8d6 FUN_1100e8d6  (called by: FUN_1100e690@1100e690, FUN_1100e760@1100e760)

uint __thiscall FUN_1100e8d6(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  void *local_8;
  
  uVar1 = param_1;
  if (DAT_11019b1c == 0) {
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
    if (DAT_11015dac < 2) {
      uVar2 = (byte)PTR_DAT_11015a90[param_1 * 2] & 1;
    }
    else {
      uVar2 = FUN_1100e861(this,param_1,1);
    }
    if (uVar2 == 0) {
      return uVar1;
    }
  }
  if ((PTR_DAT_11015a90[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
    param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;
  }
  else {
    uVar2 = param_1 >> 0x10;
    param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));
    param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;
    iVar3 = 2;
  }
  iVar3 = FUN_1100dd95(DAT_11019b1c,0x100,(char *)&param_1,iVar3,(LPWSTR)&local_8,3,0,1);
  if (iVar3 == 0) {
    return uVar1;
  }
  if (iVar3 == 1) {
    return (uint)local_8 & 0xff;
  }
  return (uint)local_8 & 0xffff;
}


// ---- 1100eac0 __putw  (called by: FUN_110011fe@110011fe)

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
      FUN_1100be90((int)(char)*piVar4,(int *)pFVar2);
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


// ---- 1100eb10 Unwind@1100eb10  (called by: -)

void Unwind_1100eb10(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100eb13. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScGroup::~ScGroup((ScGroup *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100eb19 FUN_1100eb19  (called by: -)

void FUN_1100eb19(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100eb24 Unwind@1100eb24  (called by: -)

void Unwind_1100eb24(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100eb27. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + 8));
  return;
}


// ---- 1100eb2d FUN_1100eb2d  (called by: -)

void FUN_1100eb2d(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100eb38 Unwind@1100eb38  (called by: -)

void Unwind_1100eb38(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100eb3b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + 8));
  return;
}


// ---- 1100eb41 FUN_1100eb41  (called by: -)

void FUN_1100eb41(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100eb4c Unwind@1100eb4c  (called by: -)

void Unwind_1100eb4c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100eb4f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + 8));
  return;
}


// ---- 1100eb55 FUN_1100eb55  (called by: -)

void FUN_1100eb55(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100eb60 Unwind@1100eb60  (called by: -)

void Unwind_1100eb60(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100eb66. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x10) + 0x54));
  return;
}


// ---- 1100eb6c Unwind@1100eb6c  (called by: -)

void Unwind_1100eb6c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100eb72. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x10) + 0x58));
  return;
}


// ---- 1100eb78 Unwind@1100eb78  (called by: -)

void Unwind_1100eb78(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100eb7e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x10) + 0x5c));
  return;
}


// ---- 1100eb84 Unwind@1100eb84  (called by: -)

void Unwind_1100eb84(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100eb8a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x10) + 0x60));
  return;
}


// ---- 1100eb90 Unwind@1100eb90  (called by: -)

void Unwind_1100eb90(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100eb96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 100));
  return;
}


// ---- 1100eb9c Unwind@1100eb9c  (called by: -)

void Unwind_1100eb9c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100eba2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 0x68));
  return;
}


// ---- 1100eba8 Unwind@1100eba8  (called by: -)

void Unwind_1100eba8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ebae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 0x6c));
  return;
}


// ---- 1100ebb4 Unwind@1100ebb4  (called by: -)

void Unwind_1100ebb4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ebba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 0x70));
  return;
}


// ---- 1100ebc0 Unwind@1100ebc0  (called by: -)

void Unwind_1100ebc0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ebc6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 0x74));
  return;
}


// ---- 1100ebcc Unwind@1100ebcc  (called by: -)

void Unwind_1100ebcc(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ebd2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x10) + 0x78));
  return;
}


// ---- 1100ebd8 Unwind@1100ebd8  (called by: -)

void Unwind_1100ebd8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ebde. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x7c));
  return;
}


// ---- 1100ebe4 Unwind@1100ebe4  (called by: -)

void Unwind_1100ebe4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ebed. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x80));
  return;
}


// ---- 1100ebf3 Unwind@1100ebf3  (called by: -)

void Unwind_1100ebf3(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ebfc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x84));
  return;
}


// ---- 1100ec02 Unwind@1100ec02  (called by: -)

void Unwind_1100ec02(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ec0b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x88));
  return;
}


// ---- 1100ec11 Unwind@1100ec11  (called by: -)

void Unwind_1100ec11(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ec1a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x8c));
  return;
}


// ---- 1100ec20 Unwind@1100ec20  (called by: -)

void Unwind_1100ec20(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ec29. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x90));
  return;
}


// ---- 1100ec2f Unwind@1100ec2f  (called by: -)

void Unwind_1100ec2f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ec38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x94));
  return;
}


// ---- 1100ec3e Unwind@1100ec3e  (called by: -)

void Unwind_1100ec3e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ec47. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x98));
  return;
}


// ---- 1100ec4d Unwind@1100ec4d  (called by: -)

void Unwind_1100ec4d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ec56. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0x9c));
  return;
}


// ---- 1100ec5c Unwind@1100ec5c  (called by: -)

void Unwind_1100ec5c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ec65. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0xa0));
  return;
}


// ---- 1100ec6b Unwind@1100ec6b  (called by: -)

void Unwind_1100ec6b(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ec74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0xa4));
  return;
}


// ---- 1100ec7a Unwind@1100ec7a  (called by: -)

void Unwind_1100ec7a(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ec83. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0xa8));
  return;
}


// ---- 1100ec89 Unwind@1100ec89  (called by: -)

void Unwind_1100ec89(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ec92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0xac));
  return;
}


// ---- 1100ec98 Unwind@1100ec98  (called by: -)

void Unwind_1100ec98(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100eca1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0xb0));
  return;
}


// ---- 1100eca7 Unwind@1100eca7  (called by: -)

void Unwind_1100eca7(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ecb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0xb4));
  return;
}


// ---- 1100ecb6 Unwind@1100ecb6  (called by: -)

void Unwind_1100ecb6(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ecbf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0xb8));
  return;
}


// ---- 1100ecc5 Unwind@1100ecc5  (called by: -)

void Unwind_1100ecc5(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ecce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0xbc));
  return;
}


// ---- 1100ecd4 Unwind@1100ecd4  (called by: -)

void Unwind_1100ecd4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ecdd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0xc0));
  return;
}


// ---- 1100ece3 Unwind@1100ece3  (called by: -)

void Unwind_1100ece3(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ecec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0xc4));
  return;
}


// ---- 1100ecf2 Unwind@1100ecf2  (called by: -)

void Unwind_1100ecf2(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ecfb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 200));
  return;
}


// ---- 1100ed01 Unwind@1100ed01  (called by: -)

void Unwind_1100ed01(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ed0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x10) + 0xcc));
  return;
}


// ---- 1100ed10 Unwind@1100ed10  (called by: -)

void Unwind_1100ed10(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ed19. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0xd8));
  return;
}


// ---- 1100ed1f Unwind@1100ed1f  (called by: -)

void Unwind_1100ed1f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ed28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0xdc));
  return;
}


// ---- 1100ed2e Unwind@1100ed2e  (called by: -)

void Unwind_1100ed2e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ed37. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x10) + 0xe0));
  return;
}


// ---- 1100ed3d FUN_1100ed3d  (called by: -)

void FUN_1100ed3d(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100ed48 Unwind@1100ed48  (called by: -)

void Unwind_1100ed48(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ed4e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x14) + 0x54));
  return;
}


// ---- 1100ed54 Unwind@1100ed54  (called by: -)

void Unwind_1100ed54(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ed5a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x14) + 0x58));
  return;
}


// ---- 1100ed60 Unwind@1100ed60  (called by: -)

void Unwind_1100ed60(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ed66. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x14) + 0x5c));
  return;
}


// ---- 1100ed6c Unwind@1100ed6c  (called by: -)

void Unwind_1100ed6c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ed72. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(*(int *)(unaff_EBP + -0x14) + 0x60));
  return;
}


// ---- 1100ed78 Unwind@1100ed78  (called by: -)

void Unwind_1100ed78(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ed7e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x14) + 100));
  return;
}


// ---- 1100ed84 Unwind@1100ed84  (called by: -)

void Unwind_1100ed84(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ed8a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x14) + 0x68));
  return;
}


// ---- 1100ed90 Unwind@1100ed90  (called by: -)

void Unwind_1100ed90(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ed96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x14) + 0x6c));
  return;
}


// ---- 1100ed9c Unwind@1100ed9c  (called by: -)

void Unwind_1100ed9c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100eda2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x14) + 0x70));
  return;
}


// ---- 1100eda8 Unwind@1100eda8  (called by: -)

void Unwind_1100eda8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100edae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x14) + 0x74));
  return;
}


// ---- 1100edb4 Unwind@1100edb4  (called by: -)

void Unwind_1100edb4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100edba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(*(int *)(unaff_EBP + -0x14) + 0x78));
  return;
}


// ---- 1100edc0 Unwind@1100edc0  (called by: -)

void Unwind_1100edc0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100edc6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x7c));
  return;
}


// ---- 1100edcc Unwind@1100edcc  (called by: -)

void Unwind_1100edcc(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100edd5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x80));
  return;
}


// ---- 1100eddb Unwind@1100eddb  (called by: -)

void Unwind_1100eddb(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ede4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x84));
  return;
}


// ---- 1100edea Unwind@1100edea  (called by: -)

void Unwind_1100edea(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100edf3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x88));
  return;
}


// ---- 1100edf9 Unwind@1100edf9  (called by: -)

void Unwind_1100edf9(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ee02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x8c));
  return;
}


// ---- 1100ee08 Unwind@1100ee08  (called by: -)

void Unwind_1100ee08(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ee11. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x90));
  return;
}


// ---- 1100ee17 Unwind@1100ee17  (called by: -)

void Unwind_1100ee17(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ee20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x94));
  return;
}


// ---- 1100ee26 Unwind@1100ee26  (called by: -)

void Unwind_1100ee26(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ee2f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x98));
  return;
}


// ---- 1100ee35 Unwind@1100ee35  (called by: -)

void Unwind_1100ee35(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ee3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0x9c));
  return;
}


// ---- 1100ee44 Unwind@1100ee44  (called by: -)

void Unwind_1100ee44(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ee4d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0xa0));
  return;
}


// ---- 1100ee53 Unwind@1100ee53  (called by: -)

void Unwind_1100ee53(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ee5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0xa4));
  return;
}


// ---- 1100ee62 Unwind@1100ee62  (called by: -)

void Unwind_1100ee62(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ee6b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0xa8));
  return;
}


// ---- 1100ee71 Unwind@1100ee71  (called by: -)

void Unwind_1100ee71(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ee7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0xac));
  return;
}


// ---- 1100ee80 Unwind@1100ee80  (called by: -)

void Unwind_1100ee80(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ee89. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0xb0));
  return;
}


// ---- 1100ee8f Unwind@1100ee8f  (called by: -)

void Unwind_1100ee8f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ee98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0xb4));
  return;
}


// ---- 1100ee9e Unwind@1100ee9e  (called by: -)

void Unwind_1100ee9e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100eea7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0xb8));
  return;
}


// ---- 1100eead Unwind@1100eead  (called by: -)

void Unwind_1100eead(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100eeb6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0xbc));
  return;
}


// ---- 1100eebc Unwind@1100eebc  (called by: -)

void Unwind_1100eebc(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100eec5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0xc0));
  return;
}


// ---- 1100eecb Unwind@1100eecb  (called by: -)

void Unwind_1100eecb(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100eed4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0xc4));
  return;
}


// ---- 1100eeda Unwind@1100eeda  (called by: -)

void Unwind_1100eeda(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100eee3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 200));
  return;
}


// ---- 1100eee9 Unwind@1100eee9  (called by: -)

void Unwind_1100eee9(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100eef2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(*(int *)(unaff_EBP + -0x14) + 0xcc));
  return;
}


// ---- 1100eef8 Unwind@1100eef8  (called by: -)

void Unwind_1100eef8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ef01. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x14) + 0xd8));
  return;
}


// ---- 1100ef07 Unwind@1100ef07  (called by: -)

void Unwind_1100ef07(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ef10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x14) + 0xdc));
  return;
}


// ---- 1100ef16 Unwind@1100ef16  (called by: -)

void Unwind_1100ef16(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ef1f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x14) + 0xe0));
  return;
}


// ---- 1100ef25 Unwind@1100ef25  (called by: -)

void Unwind_1100ef25(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ef2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(*(int *)(unaff_EBP + -0x14) + 0xe4));
  return;
}


// ---- 1100ef34 FUN_1100ef34  (called by: -)

void FUN_1100ef34(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100ef40 Unwind@1100ef40  (called by: -)

void Unwind_1100ef40(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ef43. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScGroup::~ScGroup((ScGroup *)(unaff_EBP + 8));
  return;
}


// ---- 1100ef49 FUN_1100ef49  (called by: -)

void FUN_1100ef49(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100ef54 Unwind@1100ef54  (called by: -)

void Unwind_1100ef54(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ef57. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScGroup::~ScGroup((ScGroup *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100ef5d Unwind@1100ef5d  (called by: -)

void Unwind_1100ef5d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ef60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100ef66 Unwind@1100ef66  (called by: -)

void Unwind_1100ef66(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ef69. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100ef6f Unwind@1100ef6f  (called by: -)

void Unwind_1100ef6f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ef72. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100ef78 Unwind@1100ef78  (called by: -)

void Unwind_1100ef78(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ef7b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100ef81 FUN_1100ef81  (called by: -)

void FUN_1100ef81(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100ef8c Unwind@1100ef8c  (called by: -)

void Unwind_1100ef8c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100ef8f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScGroup::~ScGroup((ScGroup *)(unaff_EBP + -0x18));
  return;
}


// ---- 1100ef95 FUN_1100ef95  (called by: -)

void FUN_1100ef95(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100efa0 Unwind@1100efa0  (called by: -)

void Unwind_1100efa0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100efa3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScGroup::~ScGroup((ScGroup *)(unaff_EBP + -0x14));
  return;
}


// ---- 1100efa9 FUN_1100efa9  (called by: -)

void FUN_1100efa9(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100efb4 Unwind@1100efb4  (called by: -)

void Unwind_1100efb4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100efb7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + -0x24));
  return;
}


// ---- 1100efbd FUN_1100efbd  (called by: -)

void FUN_1100efbd(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100efc8 Unwind@1100efc8  (called by: -)

void Unwind_1100efc8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100efcb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + -0x4c));
  return;
}


// ---- 1100efd1 Unwind@1100efd1  (called by: -)

void Unwind_1100efd1(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100efd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + -0x3c));
  return;
}


// ---- 1100efda Unwind@1100efda  (called by: -)

void Unwind_1100efda(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100efdd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScGroup::~ScGroup((ScGroup *)(unaff_EBP + -0x20));
  return;
}


// ---- 1100efe3 FUN_1100efe3  (called by: -)

void FUN_1100efe3(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100eff0 Unwind@1100eff0  (called by: -)

void Unwind_1100eff0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100eff3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScGroup::~ScGroup((ScGroup *)(unaff_EBP + -0x78));
  return;
}


// ---- 1100eff9 FUN_1100eff9  (called by: -)

void FUN_1100eff9(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f004 Unwind@1100f004  (called by: -)

void Unwind_1100f004(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f007. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScGroup::~ScGroup((ScGroup *)(unaff_EBP + -0x1c));
  return;
}


// ---- 1100f00d Unwind@1100f00d  (called by: -)

void Unwind_1100f00d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f010. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScGroup::~ScGroup((ScGroup *)(unaff_EBP + -0x1c));
  return;
}


// ---- 1100f016 FUN_1100f016  (called by: -)

void FUN_1100f016(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f020 Unwind@1100f020  (called by: -)

void Unwind_1100f020(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f023. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScGroup::~ScGroup((ScGroup *)(unaff_EBP + -0x18));
  return;
}


// ---- 1100f029 FUN_1100f029  (called by: -)

void FUN_1100f029(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f034 Unwind@1100f034  (called by: -)

void Unwind_1100f034(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f037. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f03d Unwind@1100f03d  (called by: -)

void Unwind_1100f03d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f040. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f046 Unwind@1100f046  (called by: -)

void Unwind_1100f046(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f049. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f04f Unwind@1100f04f  (called by: -)

void Unwind_1100f04f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f052. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MiningGroup::~MiningGroup((MiningGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f058 Unwind@1100f058  (called by: -)

void Unwind_1100f058(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f05b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f061 Unwind@1100f061  (called by: -)

void Unwind_1100f061(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f064. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f06a Unwind@1100f06a  (called by: -)

void Unwind_1100f06a(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f06d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f073 Unwind@1100f073  (called by: -)

void Unwind_1100f073(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f076. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f07c Unwind@1100f07c  (called by: -)

void Unwind_1100f07c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f07f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f085 Unwind@1100f085  (called by: -)

void Unwind_1100f085(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f088. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f08e Unwind@1100f08e  (called by: -)

void Unwind_1100f08e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f091. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f097 Unwind@1100f097  (called by: -)

void Unwind_1100f097(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f09a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f0a0 Unwind@1100f0a0  (called by: -)

void Unwind_1100f0a0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f0a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f0a9 Unwind@1100f0a9  (called by: -)

void Unwind_1100f0a9(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f0ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f0b2 Unwind@1100f0b2  (called by: -)

void Unwind_1100f0b2(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f0b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f0bb Unwind@1100f0bb  (called by: -)

void Unwind_1100f0bb(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f0be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f0c4 Unwind@1100f0c4  (called by: -)

void Unwind_1100f0c4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f0c7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f0cd Unwind@1100f0cd  (called by: -)

void Unwind_1100f0cd(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f0d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f0d6 Unwind@1100f0d6  (called by: -)

void Unwind_1100f0d6(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f0d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f0df Unwind@1100f0df  (called by: -)

void Unwind_1100f0df(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f0e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f0e8 Unwind@1100f0e8  (called by: -)

void Unwind_1100f0e8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f0eb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f0f1 Unwind@1100f0f1  (called by: -)

void Unwind_1100f0f1(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f0f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f0fa Unwind@1100f0fa  (called by: -)

void Unwind_1100f0fa(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f0fd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f103 Unwind@1100f103  (called by: -)

void Unwind_1100f103(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f106. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f10c Unwind@1100f10c  (called by: -)

void Unwind_1100f10c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f10f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f115 Unwind@1100f115  (called by: -)

void Unwind_1100f115(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f118. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f11e Unwind@1100f11e  (called by: -)

void Unwind_1100f11e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f121. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f127 Unwind@1100f127  (called by: -)

void Unwind_1100f127(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f12a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f130 Unwind@1100f130  (called by: -)

void Unwind_1100f130(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f133. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f139 Unwind@1100f139  (called by: -)

void Unwind_1100f139(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f13c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BuildingGroup::~BuildingGroup((BuildingGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f142 Unwind@1100f142  (called by: -)

void Unwind_1100f142(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f145. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FightGroup::~FightGroup((FightGroup *)(unaff_EBP + -0x30));
  return;
}


// ---- 1100f14b FUN_1100f14b  (called by: -)

void FUN_1100f14b(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f158 Unwind@1100f158  (called by: -)

void Unwind_1100f158(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f15b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100f161 FUN_1100f161  (called by: -)

void FUN_1100f161(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f16c Unwind@1100f16c  (called by: -)

void Unwind_1100f16c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f16f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100f175 FUN_1100f175  (called by: -)

void FUN_1100f175(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f180 Unwind@1100f180  (called by: -)

void Unwind_1100f180(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f183. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100f189 FUN_1100f189  (called by: -)

void FUN_1100f189(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f194 Unwind@1100f194  (called by: -)

void Unwind_1100f194(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f197. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100f19d FUN_1100f19d  (called by: -)

void FUN_1100f19d(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f1a8 Unwind@1100f1a8  (called by: -)

void Unwind_1100f1a8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f1ab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Trigger::~Trigger((Trigger *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100f1b1 FUN_1100f1b1  (called by: -)

void FUN_1100f1b1(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f1c0 FUN_1100f1c0  (called by: -)

void FUN_1100f1c0(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f1d0 FUN_1100f1d0  (called by: -)

void FUN_1100f1d0(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f1e0 Unwind@1100f1e0  (called by: -)

void Unwind_1100f1e0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f1e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScGroup::~ScGroup((ScGroup *)(unaff_EBP + 8));
  return;
}


// ---- 1100f1e9 FUN_1100f1e9  (called by: -)

void FUN_1100f1e9(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f200 Unwind@1100f200  (called by: -)

void Unwind_1100f200(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f203. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScGroup::~ScGroup((ScGroup *)(unaff_EBP + 8));
  return;
}


// ---- 1100f209 FUN_1100f209  (called by: -)

void FUN_1100f209(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


// ---- 1100f220 Unwind@1100f220  (called by: -)

void Unwind_1100f220(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1100f223. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScGroup::~ScGroup((ScGroup *)(unaff_EBP + -0x10));
  return;
}


// ---- 1100f229 FUN_1100f229  (called by: -)

void FUN_1100f229(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  FUN_1100866d(param_1,param_2,param_3,param_4);
  return;
}


