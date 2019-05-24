@echo off

set PATH=D:\Java\jdk-12\bin
set CLASSPATH=..\JavaFX\GProject\bin
set CLASSPATH=C:\Users\gerard\Downloads\Gerard\openjfx-12.0.1_windows-x64_bin-sdk\javafx-sdk-12.0.1\lib\javafx.base.jar;%CLASSPATH%
set CLASSPATH=C:\Users\gerard\Downloads\Gerard\openjfx-12.0.1_windows-x64_bin-sdk\javafx-sdk-12.0.1\lib\javafx.javafx.controls.jar;%CLASSPATH%
set CLASSPATH=C:\Users\gerard\Downloads\Gerard\openjfx-12.0.1_windows-x64_bin-sdk\javafx-sdk-12.0.1\lib\javafx.fxml.jar;%CLASSPATH%
set CLASSPATH=C:\Users\gerard\Downloads\Gerard\openjfx-12.0.1_windows-x64_bin-sdk\javafx-sdk-12.0.1\lib\javafx.graphics.jar;%CLASSPATH%
set CLASSPATH=C:\Users\gerard\Downloads\Gerard\openjfx-12.0.1_windows-x64_bin-sdk\javafx-sdk-12.0.1\lib\javafx.media.jar;%CLASSPATH%
set CLASSPATH=C:\Users\gerard\Downloads\Gerard\openjfx-12.0.1_windows-x64_bin-sdk\javafx-sdk-12.0.1\lib\javafx.swing.jar;%CLASSPATH%
set CLASSPATH=C:\Users\gerard\Downloads\Gerard\openjfx-12.0.1_windows-x64_bin-sdk\javafx-sdk-12.0.1\lib\javafx.web.jar;%CLASSPATH%
set CLASSPATH=C:\Users\gerard\Downloads\Gerard\openjfx-12.0.1_windows-x64_bin-sdk\javafx-sdk-12.0.1\lib\javafx-swt.jar;%CLASSPATH%

echo.
java --module-path C:\Users\gerard\Downloads\Gerard\openjfx-12.0.1_windows-x64_bin-sdk\javafx-sdk-12.0.1\lib --add-modules=javafx.controls com.elephant.app.GWindow 
echo.

pause