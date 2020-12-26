@echo off
set ARDUINO_PATH=D:\Programmi_Home\Arduino\Arduino-1.8.4
set ARDUINO_EXE=D:\Programmi_Home\Arduino\Arduino-1.8.4\arduino_debug.exe
set ARDUINO_MODE=%~1
if not "%ARDUINO_MODE%" == "" set ARDUINO_MODE=%~1 --verbose
set ARDUINO_BOARD=arduino:avr:mega:cpu=atmega2560
set ARDUINO_PORT=COM4
set SKETCH_PATH=D:\Programmi_Home\Git\WorkSpaceGit\Sandro730\Repetier-Firmware\src\ArduinoAVR\Repetier\..
set BUILD_PATH=D:\Programmi_Home\Git\WorkSpaceGit\Sandro730\Repetier-Firmware\src\ArduinoAVR\Repetier\..\build
set FULL_CURRENT_PATH=D:\Programmi_Home\Git\WorkSpaceGit\Sandro730\Repetier-Firmware\src\ArduinoAVR\Repetier\Repetier.ino
echo "%ARDUINO_EXE%" --save-prefs --board %ARDUINO_BOARD% --port %ARDUINO_PORT% --pref sketchbook.path=%SKETCH_PATH% --pref build.path=%BUILD_PATH%
"%ARDUINO_EXE%" --save-prefs --board %ARDUINO_BOARD% --port %ARDUINO_PORT% --pref sketchbook.path=%SKETCH_PATH% --pref build.path=%BUILD_PATH%
echo "%ARDUINO_EXE%" %ARDUINO_MODE% %FULL_CURRENT_PATH%
"%ARDUINO_EXE%" %ARDUINO_MODE% %FULL_CURRENT_PATH%
