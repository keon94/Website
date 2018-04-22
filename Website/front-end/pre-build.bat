@echo off

set tmplDir=resource/tmpl/
set tmplMaker=python %tmplDir%cppcms_tmpl_cc.py

%tmplMaker% %tmplDir%Home.tmpl -o src/Home.cpp

if %ERRORLEVEL% == 0 (
	echo Generated Home.cpp in %CD%\src
	exit \b
)

echo Failed to generate Home.cpp in %CD%\src
exit \b -1