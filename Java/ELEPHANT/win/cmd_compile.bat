@echo off

set PATH=D:\Java\jdk-12\bin

set GSRC=..\code\GProject\src\com\elephant\app
set GBUILD=build
set GSRCPATH=..\code\GProject\src

javac %GSRC%\GMain.java ^
-d %GBUILD% ^
-sourcepath %GSRCPATH%
