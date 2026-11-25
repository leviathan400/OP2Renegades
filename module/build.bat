@echo off
REM Build Renegades.dll, a 32-bit op2ext module (Outpost 2 and op2ext are x86).
setlocal
cd /d "%~dp0"

set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
set "VSPATH="
if exist "%VSWHERE%" (
  for /f "usebackq tokens=*" %%i in (`"%VSWHERE%" -latest -products * -property installationPath`) do set "VSPATH=%%i"
)
if "%VSPATH%"=="" ( echo Could not locate Visual Studio via vswhere. & exit /b 1 )

call "%VSPATH%\VC\Auxiliary\Build\vcvarsall.bat" x86 >nul
if errorlevel 1 ( echo vcvarsall x86 failed & exit /b 1 )

rc /nologo /fo Renegades.res Renegades.rc
if errorlevel 1 ( echo rc FAILED & exit /b 1 )
cl /nologo /O2 /MT /EHsc /W3 /DWIN32 /D_WINDOWS Renegades.cpp /link /DLL /OUT:Renegades.dll gdi32.lib version.lib Renegades.res
if errorlevel 1 ( echo build FAILED & exit /b 1 )
del /q Renegades.obj Renegades.exp Renegades.lib Renegades.res 2>nul
echo Built Renegades.dll
endlocal
