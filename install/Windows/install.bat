@echo off

:: BatchGotAdmin
:-------------------------------------
REM  --> Check for permissions
    IF "%PROCESSOR_ARCHITECTURE%" EQU "amd64" (
>nul 2>&1 "%SYSTEMROOT%\SysWOW64\cacls.exe" "%SYSTEMROOT%\SysWOW64\config\system"
) ELSE (
>nul 2>&1 "%SYSTEMROOT%\system32\cacls.exe" "%SYSTEMROOT%\system32\config\system"
)

REM --> If error flag set, we do not have admin.
if '%errorlevel%' NEQ '0' (
    echo Requesting administrative privileges...
    goto UACPrompt
) else ( goto gotAdmin )

:UACPrompt
    echo Set UAC = CreateObject^("Shell.Application"^) > "%temp%\getadmin.vbs"
    set params = %*:"=""
    echo UAC.ShellExecute "cmd.exe", "/c ""%~s0"" %params%", "", "runas", 1 >> "%temp%\getadmin.vbs"

    "%temp%\getadmin.vbs"
    del "%temp%\getadmin.vbs"
    exit /B

:gotAdmin
    pushd "%CD%"
    CD /D "%~dp0"
:-------------------------------------- 

@echo on


@SET NSISPath64="%ProgramFiles(x86)%\NSIS\NSIS.exe"

@SET NSISPath32="%ProgramFiles%\NSIS\NSIS.exe"

@SET desktopPath=%systemdrive%\Documents and Settings\All Users\Desktop


@if exist %NSISPath64% (
@echo "NSIS found in x86"
)

@if not exist %NSISPath64% (

@echo "NSIS NOT found in x86"


@if exist %NSISPath32% (
 @echo "found in 32 bit"
)

@if not exist %NSISPath32% (
start /d nsis-3.01-setup.exe
@pause
)
)

@if not exist ..\..\build (
  @mkdir ..\..\build
)
@cd ..\..\build\
@cmake -G "Visual Studio 15 2017 Win64" ..
@cmake --build . --target PACKAGE --config Release
@start /d "./" AoL-setup-1.0.exe
@pause
@icacls "%ProgramFiles%\Age of Lazies" /grant %username%:(OI)(CI)F /T

@set SCRIPT="%TEMP%\%RANDOM%-%RANDOM%-%RANDOM%-%RANDOM%.vbs"

@echo Set oWS = WScript.CreateObject("WScript.Shell") >> %SCRIPT%
@echo sLinkFile = "%USERPROFILE%\Desktop\Age Of Lazies.lnk" >> %SCRIPT%
@echo Set oLink = oWS.CreateShortcut(sLinkFile) >> %SCRIPT%
@echo oLink.TargetPath = "%ProgramFiles%\Age Of Lazies\AgeOfLazies.exe" >> %SCRIPT%
@echo oLink.WorkingDirectory = "%ProgramFiles%\Age Of Lazies\" >> %SCRIPT%
@echo oLink.Save >> %SCRIPT%

@cscript /nologo %SCRIPT%
@del %SCRIPT%
@pause
