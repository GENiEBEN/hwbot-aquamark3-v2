@setlocal enableextensions enabledelayedexpansion
@echo off
FOR /F "usebackq tokens=3*" %%A IN (`REG QUERY "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows NT\CurrentVersion" /v "CSDVersion"`) DO (set result=%%A %%B) & (ECHO !result!) >csdv.out