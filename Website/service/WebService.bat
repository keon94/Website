@echo off
set service_config="..\resource\config\service-config.json"
if not exist %service_config% (
	call :err_no_config %service_config%
	pause
	exit /b 1
)

service.exe -c %service_config%

pause
exit /b

:err_no_config
echo Error: %~dpfn1 could not be found.
