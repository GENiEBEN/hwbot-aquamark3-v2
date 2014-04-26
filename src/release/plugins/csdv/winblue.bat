@setlocal enableextensions enabledelayedexpansion
@echo off
FOR /F "usebackq tokens=3*" %%A IN (`REG QUERY "HKEY_LOCAL_MACHINE\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion" /v "BuildLab"`) DO (set result=%%A %%B) & (ECHO !result!)