@echo off
setlocal

REM Definir el rango de archivos a crear
set inicio=1
set fin=2

REM Bucle para crear los archivos .cpp
for /L %%i in (%inicio%, 1, %fin%) do (
    echo. > DAIG_ACT7_0%%i.cpp
)

echo Archivos creados exitosamente.

endlocal
