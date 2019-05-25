@echo off

set PATH=C:\Program Files\Java\jdk-11.0.1\bin

set GSRC=..\code\GProject\src\com\elephant\app
set GBUILD=build
set GSRCPATH=..\code\GProject\src

javac %GSRC%\GMain.java ^
-d %GBUILD% ^
-sourcepath %GSRCPATH%
