REM Run the following script at a similar location to add cl.exe and such to your path:
REM C:\Program Files (x86)\Microsoft Visual Studio\2017\VC\Auxiliary\Build\vcvars64.bat
@echo off
cl.exe /D_USRDLL /D_WINDLL half.c print_message.c sum.c /link /DLL /OUT:libexample.dll
cl.exe dynaload.c /link /OUT:dynaload.exe
