#include <QApplication>
#include <QSplashScreen>
#include <QSettings>
#include <QDir>
#include <QStandardPaths>
#include <QStyleFactory>
#include "sysinfo.h"
#include "security.h"
#include "gui.h"
#include "windows.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    frmMain w;
    QString foo;
    QSettings ubw("GENiEBEN","UBW");
    QSettings sysinfo("GENiEBEN", "SystemInfo");
    QSettings ShellFolders("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders",QSettings::NativeFormat);

    // SPLASH SCREEN
    QPixmap pixmap(":/images/res/splash.png");
    QSplashScreen *splash = new QSplashScreen(pixmap);
    splash->show();

    if (ubw.value("SystemInfo").toString().toLower()=="enabled"){

        splash->showMessage("Processor");
        a.processEvents();
        sysinfo.setValue("CPU_Count", SYSINFO_CPU_COUNT() );
        sysinfo.setValue("CPU_Name", SYSINFO_CPU_NAME() );
        sysinfo.setValue("CPU_Threads", SYSINFO_CPU_THREADCOUNT() );
        sysinfo.setValue("CPU_Now", SYSINFO_CPU_SPEED_NOW() );
        sysinfo.setValue("CPU_ExtClk", SYSINFO_CPU_SPEED_EXTCLK() );
        sysinfo.setValue("CPU_Voltage", SYSINFO_CPU_VOLTAGE() );
        sysinfo.setValue("CPU_SkUpgrade", SYSINFO_CPU_SOCKET_UPGRADE() );
        sysinfo.setValue("CPU_SkName", SYSINFO_CPU_SOCKET_NAME() );
        sysinfo.setValue("CPU_FamilyName", SYSINFO_CPU_FAMILY_NAME() );

        splash->showMessage("Motherboard");
        a.processEvents();

        sysinfo.setValue("MOBO_SkCount", SYSINFO_MOBO_SOCKET_COUNT() );
        sysinfo.setValue("MOBO_Vendor", SYSINFO_MOBO_VENDOR() );
        sysinfo.setValue("MOBO_Name", SYSINFO_MOBO_NAME() );
        sysinfo.setValue("MOBO_Serial", SYSINFO_MOBO_SERIALNUMBER() );

        splash->showMessage("BIOS");
        a.processEvents();

        sysinfo.setValue("BIOS_IsUEFI", SYSINFO_BIOS_IS_UEFI() );
        sysinfo.setValue("BIOS_Version", SYSINFO_BIOS_VERSION() );
        sysinfo.setValue("BIOS_Date", SYSINFO_BIOS_DATE() );
        sysinfo.setValue("BIOS_Revision", SYSINFO_BIOS_REVISION() );
        sysinfo.setValue("BIOS_FwRev", SYSINFO_BIOS_FIRMWARE_REVISION() );

        splash->showMessage("Memory");
        a.processEvents();

        sysinfo.setValue("RAM_ModuleCount", SYSINFO_RAM_MODULECOUNT() );
        sysinfo.setValue("RAM_Vendor", SYSINFO_RAM_VENDOR() );
        sysinfo.setValue("RAM_PartNumber", SYSINFO_RAM_PARTNUMBER() );
        sysinfo.setValue("RAM_SpeedCfg", SYSINFO_RAM_CONFIGUREDSPEED() );
        sysinfo.setValue("RAM_SpeedRated", SYSINFO_RAM_RATEDSPEED() );
        sysinfo.setValue("RAM_SizeInstalled", SYSINFO_RAM_INSTALLEDSIZE() );
        sysinfo.setValue("RAM_Type", SYSINFO_RAM_TYPE() );
        sysinfo.setValue("RAM_FormFactor", SYSINFO_RAM_FORMFACTOR() );

        splash->showMessage("Graphics");
        a.processEvents();

        if (_rungpuz()==1){
            sysinfo.setValue("GFX_Count", SYSINFO_GFX_COUNT() );
            sysinfo.setValue("GFX_IntegratorName", SYSINFO_GFX_INTEGRATOR_NAME() );
            sysinfo.setValue("GFX_Name", SYSINFO_GFX_NAME() );
            sysinfo.setValue("GFX_SpeedShader", SYSINFO_GFX_SPEED_SHADER() );
            sysinfo.setValue("GFX_SpeedCore", SYSINFO_GFX_SPEED_CORE() );
            sysinfo.setValue("GFX_SpeedRam", SYSINFO_GFX_SPEED_RAM() );
            sysinfo.setValue("GFX_RamSize", SYSINFO_GFX_RAM_SIZE() );
            sysinfo.setValue("GFX_RamType", SYSINFO_GFX_RAM_TYPE() );
            sysinfo.setValue("GFX_RamBusWidth", SYSINFO_GFX_RAM_BUSWIDTH() );
            sysinfo.setValue("GFX_DriverName", SYSINFO_GFX_DRIVER_NAME() );
            sysinfo.setValue("GFX_DriverVersion", SYSINFO_GFX_DRIVER_VERSION() );
            sysinfo.setValue("GFX_DriverDate", SYSINFO_GFX_DRIVER_DATE() );
            _delgpuz();
        }

        if (_rundxdiag()==1){
            sysinfo.setValue("GFX_DxVersion", SYSINFO_GFX_DXVERSION() );
            sysinfo.setValue("GFX_OutputPorts", SYSINFO_GFX_OUTPUTPORTS() );
        }

        splash->showMessage("Operating System");
        a.processEvents();

        sysinfo.setValue("OS_ServicePack", SYSINFO_OS_SP() );
        sysinfo.setValue("OS_Name", SYSINFO_OS_NAME() );
        sysinfo.setValue("OS_Bits", SYSINFO_OS_BITS() );

        splash->showMessage("Benchmark Settings");
        a.processEvents();



        splash->showMessage("Paths");
        a.processEvents();

        sysinfo.setValue("Path_Desktop", ShellFolders.value("Desktop").toString());
        sysinfo.setValue("Path_MyDocuments", ShellFolders.value("Personal").toString());


        for (int i = 0; i<QCoreApplication::arguments().count();i++){
            foo = QCoreApplication::arguments().at(i);
            foo = foo.right(foo.length() - 1); //avoid including the argument delimiter "-"

            if (foo.contains("bench=")){
                if (foo.contains("aquamark3")){
                    QSettings settings("GENiEBEN", "UBW_Aquamark3");
                    settings.setValue("Path_MyDocuments", QString("%1\\Aquamark3").arg(sysinfo.value("Path_MyDocuments").toString()));
                    settings.setValue("Path_EXE",QString("%1\\%2").
                                      arg(settings.value("InstallLocation","C:\\Program Files (x86)\\HWBOT\\Aquamark3").toString()).
                                      arg("\\benchmark\\aquamark3\\aquamark3.exe"));
                    settings.setValue("Path_Pak0",QString("%1\\%2").
                                      arg(settings.value("InstallLocation","C:\\Program Files (x86)\\HWBOT\\Aquamark3").toString()).
                                      arg("\\benchmark\\aquamark3\\pak\\data0.pak"));
                    settings.setValue("Path_Pak1",QString("%1\\%2").
                                      arg(settings.value("InstallLocation","C:\\Program Files (x86)\\HWBOT\\Aquamark3").toString()).
                                      arg("\\benchmark\\aquamark3\\pak\\data1.pak"));
                }
            }
        }
    }


    //SHOW MAIN GUI
    w.setWindowFlags( Qt::Dialog );
    w.setFixedSize(w.size());
    w.setWindowTitle(QString("%1 v%2").arg(w.windowTitle()).arg(APP_VERSION));
    w.show();
    splash->finish(&w);

    //done
    return a.exec();

    //cleanup code

}
