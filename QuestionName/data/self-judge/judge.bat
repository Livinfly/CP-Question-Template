@echo off
setlocal enabledelayedexpansion

set cnt=0
set tot=0
for %%i in (*.in) do (
	set in=%%i
	set out=!in:in=out!
	set ans=!in:in=ans!

	echo !in! !out! !ans!

	set tt=!TIME!
	set /a TIMESTAMP1=!tt:~0,2!*3600*1000 + !tt:~3,2!*60*1000 + !tt:~6,2!*1000 + !tt:~9,2!*10

	my.exe < !in! > !out!

	set tt=!TIME!
	set /a TIMESTAMP2=!tt:~0,2!*3600*1000 + !tt:~3,2!*60*1000 + !tt:~6,2!*1000 + !tt:~9,2!*10

	set /a delta=!TIMESTAMP2!-!TIMESTAMP1!
	
	echo !delta!

	fc /n !out! !ans!
	if not errorlevel 1 (
		if !delta! lss 1000 (
			set /a cnt=!cnt!+1
		)
	)
	set /a tot=!tot!+1
)
echo AC/TOT: %cnt%/%tot%
pause