@echo off

if [%1]==[] goto err_no_args
if not "%~2"=="" goto :err_over_one_arg

set outdir=%1
if exist resource (
	echo Copying from %CD%\resource\ to %outdir%\resource\
	xcopy  /s /e /q /y resource %outdir%\resource > nul
	if %errorlevel% neq 0 (
		echo Could not copy %CD%\resource\. Aborting.
		goto :err_copy_failure 
	)
)
exit /b

:err_no_args
	echo Error: No arguments provided. The usage is
	echo 		post-build.bat path-to-destination
	exit /b 1
:err_over_one_arg
	echo Error: 2 or more args provided. The usage is 
	echo 		post-build.bat path-to-destination
	exit /b 2
:err_copy_failure 
	exit /b -3