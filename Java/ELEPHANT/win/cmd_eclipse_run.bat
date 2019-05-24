@echo off

set PATH=D:\Java\jdk-12\bin
set CLASSPATH=..\JavaFX\GProject\bin
set GMOBULEPATH=C:\Users\gerard\Downloads\Gerard\openjfx-12.0.1_windows-x64_bin-sdk\javafx-sdk-12.0.1\lib
set GADDMODULES=javafx.controls

echo.
java --module-path %GMOBULEPATH% ^
--add-modules=%GADDMODULES% ^
com.elephant.app.GWindow 
echo.

pause