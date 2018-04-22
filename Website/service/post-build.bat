@echo off

setlocal

if [%1]==[] goto err_no_args
if [%2]==[] goto err_one_arg
if [%3]==[] goto err_two_args
if not "%~4"=="" goto :err_four_or_more_args

set config=%1
set outdir=%~2
set depdir=%~3

::release mode is "/r" , debug mode is "/d"
if "%config%" neq "/r" if "%config%" neq "/d" goto :err_bad_config
if not exist "%depdir%" goto :err_bad_dll_loc

if exist resource (
	echo Copying "%CD%\resource to "%outdir%\resource"
	xcopy  /s /e /y "resource" "%outdir%\resource" > nul
	if %errorlevel% neq 0 (
		echo Could not copy "%CD%\resource\". Aborting.
		goto :err_copy_failure 
	)
)

echo Copying DLLs from "%depdir%" to "%outdir%\bin\"
for %%f in ("%depdir%\*.dll") do (
	copy /y "%%f" "%outdir%\bin" > nul
	if not exist "%outdir%\bin\%%~nxf" (
		echo Could not copy "%%~nxf". Aborting.
		goto :err_copy_failure
	) 
	echo Copied "%%~nxf" 
)

if "%config%"=="/r" (
	echo Removing the extra output files ^(keeping only the DLLs and EXE^) from %outdir%\bin\
	::delete unneeded files from bin/ (Release Mode)
	for %%f in ("%outdir%\bin\*.*") do (
		if not %%~xf==.dll if not %%~xf==.exe (
			del "%%f"
			if exist "%%f" (
				echo Could not remove "%%~nxf"
			) else (
				echo Removed "%%~nxf" 
			)
		)
	)
)

set service_bat="WebService.bat"
if not exist %service_bat% (
	goto :err_no_service_bat
)
echo Copying %service_bat% into "%outdir%\bin"
copy /y %service_bat% "%outdir%\bin" > nul
if not exist "%outdir%\bin\%service_bat%" (
	echo Could not copy %service_bat%. Aborting.
	goto :err_copy_failure
)

exit /b

:err_no_args
	echo Error: No arguments provided. The usage is 
	echo 		post-build.bat /config-flag path-to-destination path-to-dlls
	exit /b 1
:err_one_arg
	echo Error: Only one argument provided. The usage is 
	echo 		post-build.bat /config-flag path-to-destination path-to-dlls
	exit /b 2
:err_two_args
	echo Error: Only 2 arguments provided. The usage is  
	echo 		post-build.bat /config-flag path-to-destination path-to-dlls
	exit /b 3
:err_four_or_more_args
	echo Error: 4 or more arguments provided. The usage is 
	echo 		post-build.bat /config-flag path-to-destination path-to-dlls
	exit /b 3
:err_bad_config
	echo Error: Bad config-flag provided. Expected /d (Debug) or /r (Release). Provided: %config%
	exit /b -1	
:err_bad_dll_loc
	echo Error: The Location of DLLs can't be found. The Provided location is %depdir%		
	exit /b -2
:err_copy_failure
	exit /b -3
:err_no_service_bat:
	echo Error: WebSerivce.bat was not found in %CD%
	exit /b -4