#include <QApplication>
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
    w.setWindowFlags( Qt::Dialog );
    w.setFixedSize(w.size());
    w.setWindowTitle(QString("%1 v%2").arg(w.windowTitle()).arg(APP_VERSION));
    w.show();

    //Get some global paths
    QSettings settings("GENiEBEN", "Aquamark3 Wrapper");
    QString Benchmark_Install_Path = settings.value( "InstallLocation", "C:\\Program Files (x86)\\HWBOT\\Aquamark3" ).toString();
    a.setProperty("Benchmark_Install_Path", Benchmark_Install_Path);
    a.setProperty("Benchmark_Exe_Path", Benchmark_Install_Path + "\\benchmark\\aquamark3.exe");
    a.setProperty("Benchmark_Pak0_Path", Benchmark_Install_Path + "\\benchmark\\pak\\data0.pak");
    a.setProperty("Benchmark_Pak1_Path", Benchmark_Install_Path + "\\benchmark\\pak\\data1.pak");

    QSettings ShellFolders("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders",QSettings::NativeFormat);
    QString Benchmark_My_Docs_Folder = ShellFolders.value("Personal").toString() + "\\Aquamark3";
    QString Benchmark_Desktop_Folder = ShellFolders.value("Desktop").toString();
    //TODO: Implement ShGetFolder CSIDL_PERSONAL or something similar instead of reading fromr registry.
    a.setProperty("Benchmark_My_Docs_Folder", Benchmark_My_Docs_Folder);
    a.setProperty("Benchmark_Desktop_Folder", Benchmark_Desktop_Folder);
    //done
    return a.exec();

    //cleanup code

}
