@echo off
setlocal enabledelayedexpansion

echo generating...

gen.exe 6 3 0 10 102 > PrimeChoice_1.in
gen.exe 10 10 0 100 223 > PrimeChoice_2.in
gen.exe 100 200 0 5000 723 > PrimeChoice_3.in
gen.exe 100 200 3000 5000 239 > PrimeChoice_4.in
gen.exe 1000 2000 0 50000 119 > PrimeChoice_5.in
gen.exe 1000 2000 10200 50000 155 > PrimeChoice_6.in
gen.exe 5000 10000 0 60000 179 > PrimeChoice_7.in
gen.exe 5000 10000 11451 60000 107 > PrimeChoice_8.in
gen.exe 10000 30000 0 300000 771 > PrimeChoice_9.in
gen.exe 10000 30000 18400 300000 828 > PrimeChoice_10.in
gen.exe 100000 100000 0 1000000 111 > PrimeChoice_11.in
gen.exe 100000 100000 200000 1000000 392 > PrimeChoice_12.in
gen.exe 100000 1000000 0 1000000 892 > PrimeChoice_13.in
gen.exe 100000 1000000 500000 1000000 123 > PrimeChoice_14.in
gen.exe 1000 1000000 0 1000000 991 > PrimeChoice_15.in
gen.exe 100000 100 0 0 331 > PrimeChoice_16.in
gen-hand.exe 0 1000000 200 > PrimeChoice_17.in
gen-hand.exe 300000 1000000 251 > PrimeChoice_18.in
gen-hand2.exe 0 1000000 122 > PrimeChoice_19.in
gen-hand2.exe 300000 1000000 412 > PrimeChoice_20.in


REM last two handed.

echo generation done.

for %%i in (*.in) do (
	set in=%%i
	set ans=!in:in=ans!
	echo !in! !ans!
	PrimeChoice.exe < !in! > !ans!
)
pause