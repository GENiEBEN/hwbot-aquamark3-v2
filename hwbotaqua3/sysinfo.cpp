//HARDWARE INFO LIBRARY FOR GENiEBEN's APPLICATIONS v1.10

#include <QApplication>
#include <QStringList>
#include <QSettings>
#include <QProcess>
#include <QFile>
#include <QTextStream>
#include <QThread>
#include "windows.h"
#include <QFileInfo>
#include <QDate>
#include <QTime>
#include <QDateTime>
//Q_OS_
        //DARWIN   - Darwin OS (synonym for Q_OS_MAC)
        //SYMBIAN  - Symbian
        //MSDOS    - MS-DOS and Windows
        //OS2      - OS/2
        //OS2EMX   - XFree86 on OS/2 (not PM)
        //WIN32    - Win32 (Windows 2000/XP/Vista/7 and Windows Server 2003/2008)
        //WINCE    - WinCE (Windows CE 5.0)
        //CYGWIN   - Cygwin
        //SOLARIS  - Sun Solaris
        //HPUX     - HP-UX
        //ULTRIX   - DEC Ultrix
        //LINUX    - Linux
        //FREEBSD  - FreeBSD
        //NETBSD   - NetBSD
        //OPENBSD  - OpenBSD
        //BSDI     - BSD/OS
        //IRIX     - SGI Irix
        //OSF      - HP Tru64 UNIX
        //SCO      - SCO OpenServer 5
        //UNIXWARE - UnixWare 7, Open UNIX 8
        //AIX      - AIX
        //HURD     - GNU Hurd
        //DGUX     - DG/UX
        //RELIANT  - Reliant UNIX
        //DYNIX    - DYNIX/ptx
        //QNX      - QNX
        //LYNX     - LynxOS
        //BSD4     - Any BSD 4.4 system
        //UNIX     - Any UNIX BSD/SYSV system

QString _dxdiagpath;



bool _rundxdiag() {
    //Start dxdiag and output to file
    QFile dxdiagOut("dxdiag.out");if (dxdiagOut.exists()){dxdiagOut.remove();}
    QProcess dxdiag;QStringList args;args << "/whql:off" << "/t" << "dxdiag.out";
    dxdiag.start("dxdiag.exe", args);
    dxdiag.waitForFinished();
    dxdiag.close();
    QFileInfo fileInfo(dxdiagOut.fileName());
    QString filename( fileInfo.absoluteFilePath() );
    _dxdiagpath = filename;
    return dxdiagOut.exists();
}


bool _rungpuz() {
    //Start GPU-Z and output to file
    QFile gpuzout("gpuz.out");if (gpuzout.exists()){gpuzout.remove();}
    QProcess gpuz;QStringList args;args << "-dump" << "gpuz.out";
    gpuz.start("gpuz.dll", args);gpuz.waitForFinished(-1);gpuz.close();
    return gpuzout.exists();
}

bool _rundmid(QStringList args) {
    //Start DMI Decode and output to file
    QFile dmidout("dmid.out");if (dmidout.exists()){dmidout.remove();}
    QProcess dmid;
    dmid.start("dmid.dll", args);dmid.waitForFinished(-1);dmid.close();
    return dmidout.exists();
}

bool _delgpuz() {
    //Remove output file of gpuz
    QFile gpuzout("gpuz.out");if (gpuzout.exists()){gpuzout.remove();}
    return !gpuzout.exists();
}

QString SYSINFO_GFX_GetLevelOfDetail_AMD(){
    QString result;
    QSettings sets("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Video", QSettings::NativeFormat);
    QStringList keys = sets.allKeys();
    QStringList foo_l; QStringList boo_l;QString foo;

    for (int i=0;i<keys.count();i++){//find all LOD keys (if multiple cards/drivers)
        if (keys.value(i).contains("LODAdj")){
            foo_l << "HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Video\\" + keys.at(i);
        }
    }
    for (int i=0;i<foo_l.count();i++){//create a list with all registry LOD paths found
        foo = foo_l.at(i);
        foo.replace("/","\\",Qt::CaseInsensitive);
        foo.replace("\\LODAdj","",Qt::CaseInsensitive);
        boo_l << foo;
    }

    for (int j=0; j<boo_l.count();j++){//get value from each registry LOD path; only last is visible in GUI
        QSettings lodadj(boo_l.at(j), QSettings::NativeFormat);
        result = lodadj.value("LODAdj").toString();
    }

    return result;
}

QString SYSINFO_CPU_THREADCOUNT(){
    QString result = QString::number(QThread::idealThreadCount());
    return result;
}

QString SYSINFO_CPU_COUNT() {
    QString result="1"; QString foo;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "4";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    int i=0; //default number of processors
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo=="Processor Information") {
                i += 1; //processor count increase
            }
            if (foo.contains("Status: Unpopulated")) {
                i -= 1; //processor count decrease since socket is available but empty.
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    result = QString::number(i);
    result = result.trimmed();
    return result;
}



QString SYSINFO_CPU_NAME() {
    //Retrieve generic name from registry
    QSettings registry("HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",QSettings::NativeFormat);
    QString result = registry.value( "ProcessorNameString", "-" ).toString();
    //Remove frequency from name
    result.simplified();
    result.trimmed();
    if (result.contains("@")){
    QStringList foolist = result.split("@",QString::SkipEmptyParts);
    result = foolist.at(0);
    }
    //Trim and rename
    result.replace("Eight-Core","",Qt::CaseSensitive);
    result.replace("Quad-Core","",Qt::CaseSensitive);
    result.replace("Six-Core","",Qt::CaseSensitive);
    result.replace("Dual-Core","",Qt::CaseSensitive);
    result.replace("AMD E","Fusion E",Qt::CaseSensitive);
    result.replace("AMD C","Fusion C",Qt::CaseSensitive);
    result.replace("Processor","",Qt::CaseInsensitive);
    result.replace("(ES)","",Qt::CaseInsensitive);
    result.replace("(R)","",Qt::CaseInsensitive);
    result.replace("(TM)","",Qt::CaseInsensitive);
    result.replace("Core2","Core 2",Qt::CaseSensitive);
    result.replace("CPU","",Qt::CaseInsensitive);
    result.replace("APU","",Qt::CaseInsensitive);
    result.replace("with Radeon HD Graphics","",Qt::CaseInsensitive);
    result.replace("  "," ",Qt::CaseInsensitive);
    result.replace("Genuine","",Qt::CaseInsensitive);
    result.replace("i7 X 990","i7 990X",Qt::CaseSensitive);
    result.replace("i7 X 980","i7 980X",Qt::CaseSensitive);
    result.replace("i7 X 995","i7 995X",Qt::CaseSensitive);
    result.replace("X9750","QX9750",Qt::CaseSensitive);
    result.replace("X9770","QX9770",Qt::CaseSensitive);
    result.replace("X9775","QX9775",Qt::CaseSensitive);
    result.replace("i3-","i3 ",Qt::CaseSensitive);
    result.replace("i5-","i5 ",Qt::CaseSensitive);
    result.replace("i7-","i7 ",Qt::CaseSensitive);

    if (result.contains("i5 M", Qt::CaseSensitive)==true){
        result.replace("i5 M","i5",Qt::CaseSensitive);
        result.append("M");
    }

    if (result.contains("i7 Q", Qt::CaseSensitive)==true){
        result.replace("i7 Q","i7",Qt::CaseSensitive);
        result.append("QM");
    }

    if (result.contains("Desktop_4740", Qt::CaseSensitive)==true){
        result = "AMD FX-9590 (ES)"; //http://i.imgur.com/dzNno6q.png
    }

    result = result.trimmed();
    return result;
}

QString SYSINFO_CPU_SPEED_NOW() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "4";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Current Speed")) {
                foolist = foo.split(":");
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
        result = result.trimmed();
    }
    return result;
}

QString SYSINFO_CPU_SPEED_MAX() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "4";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Max Speed")) {
                foolist = foo.split(":");
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
        result = result.trimmed();
    }
    return result;
}

QString SYSINFO_CPU_SPEED_EXTCLK() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "4";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("External Clock")) {
                foolist = foo.split(":");
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
        result = result.trimmed();
    }
    return result;
}

QString SYSINFO_CPU_SOCKET_NAME() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "4";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Socket Designation:")) {
                foolist = foo.split(":");
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        foo = foolist.at(1);
        result = foo;
        result.replace("<OUT OF SPEC>","Unknown", Qt::CaseSensitive);
        if (result=="Other"){        result = "Unknown Socket";}
        if (result.contains("Slot")){result = "Slot "; result.append(foo); }
        result = result.trimmed();
    }
    //

    return result;
}

QString SYSINFO_CPU_SOCKET_UPGRADE() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "4";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Upgrade:")) {
                foolist = foo.split(":");
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
        if (result=="Other"){
            result = SYSINFO_CPU_SOCKET_NAME();
        }
        result = result.trimmed();
    }
    result.replace("<OUT OF SPEC>","Unknown Socket", Qt::CaseSensitive);
    return result;
}

QString SYSINFO_CPU_VOLTAGE() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "4";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Voltage")) {
                foolist = foo.split(":");
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
        result = result.trimmed();
    }
    return result;
}

QString SYSINFO_CPU_FAMILY_NAME() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "4";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Family:")) {
                foolist = foo.split(":");
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
        result = result.trimmed();
    }
    return result;
}

QString SYSINFO_MOBO_VENDOR() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "2";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Manufacturer:")) {
                foolist = foo.split(":");
                break;
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
    }
    //Trim unnecesary info
    result.simplified();
    result.replace("Intel Corporation","Intel",Qt::CaseSensitive);
    result.replace("ECS","Ecs Elitegroup",Qt::CaseSensitive);//only for HWBOT compliance
    result.replace("ASUSTeK COMPUTER INC.","ASUS",Qt::CaseInsensitive);
    result.replace("Gigabyte Technology Co., Ltd.","GIGABYTE",Qt::CaseSensitive);
    result.replace("Hewlett-Packard","HP",Qt::CaseSensitive);
    result.replace("Sony Corporation","SONY",Qt::CaseInsensitive);
    result.replace("Microsoft Corporation","Microsoft",Qt::CaseInsensitive);
    result.replace("Dell Inc.","DELL",Qt::CaseInsensitive);
    result = result.trimmed();
    return result;
}

QString SYSINFO_SYSTEM_SKU() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "1";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("SKU Number:")) {
                foolist = foo.split(":");
                break;
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
    }
    //Trim unnecesary info
    result.replace("To Be Filled By O.E.M.","",Qt::CaseInsensitive);
    result.replace("SKU","",Qt::CaseInsensitive);
    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(QString sku){
    QString result = "-";
    if (sku.contains("#ABA")){result.append("USA");}
    if (sku.contains("#ABC")){result.append("Canada FR");}
    if (sku.contains("#ABM")){result.append("Latin America");}
    if (sku.contains("#AC4")){result.append("Brazil");}
    if (sku.contains("#ABB")){result.append("Euro");}
    if (sku.contains("#ABF")){result.append("France");}
    if (sku.contains("#ABD")){result.append("Germany");}
    if (sku.contains("#ABZ")){result.append("Italy");}
    if (sku.contains("#ABH")){result.append("Netherland");}
    if (sku.contains("#ABE")){result.append("Spain");}
    if (sku.contains("#ABU")){result.append("UK");}
    if (sku.contains("#ABN")){result.append("Norway");}
    if (sku.contains("#AB9")){result.append("Portugal");}
    if (sku.contains("#AK8")){result.append("Sweden/Finland");}
    if (sku.contains("#AKC")){result.append("Hungary");}
    if (sku.contains("#A2M")){result.append("Iceland");}
    if (sku.contains("#ABT")){result.append("Israel");}
    if (sku.contains("#AB8")){result.append("Turkey");}
    if (sku.contains("#ACQ")){result.append("South Africa");}
    if (sku.contains("#UUF")){result.append("Asia Pacific");}
    if (sku.contains("#ABG")){result.append("Australia");}
    if (sku.contains("#ACJ")){result.append("India");}
    if (sku.contains("#AB0")){result.append("Taiwan");}
    if (sku.contains("#ABJ")){result.append("Japan JP");}
    if (sku.contains("#ACF")){result.append("Japan EN KYRD");}
    if (sku.contains("#UUZ")){result.append("Switzerland");}
    if (sku.contains("#UUG")){result.append("Belgium");}
    if (sku.contains("#ABD")){result.append("Germany");}
    if (sku.contains("#ABF")){result.append("France");}
    if (sku.contains("#ABM")){result.append("Latin America SP");}
    if (sku.contains("#ACH")){result.append("Latin America EN");}
    if (sku.contains("#AB2")){result.append("China CN");}
    if (sku.contains("#AKB")){result.append("Czech");}
    if (sku.contains("#B1A")){result.append("Greece");}
    if (sku.contains("#AB1")){result.append("Korea");}
    if (sku.contains("#AKD")){result.append("Poland");}
    if (sku.contains("#ABB")){result.append("Euro");}
    if (sku.contains("#ACB")){result.append("Russia");}
    if (sku.contains("#AKR")){result.append("Slovakia");}
    if (sku.contains("#B1L")){result.append("China CN/EN");}
    if (sku.contains("#UUW")){result.append("Nordic");}
    if (sku.contains("#ABY")){result.append("Denmark");}
    if (sku.contains("#AB6")){result.append("Sweden");}
    if (sku.contains("#ABX")){result.append("Finland");}
    if (sku.contains("#AC8")){result.append("Argentina");}
    if (sku.contains("#AB6")){result.append("NW Africa");}
    if (sku.contains("#AR2")){result.append("Pan Euro");}
    if (sku.contains("#A1Y")){result.append("Brazil EN");}
    if (sku.contains("#AB5")){result.append("Hong Kong");}
    if (sku.contains("#AKN")){result.append("Slovenia");}
    if (sku.contains("#BED")){result.append("Adriatic Region");}
    if (sku.contains("#AKL")){result.append("Thailand");}
    if (sku.contains("#AKS")){result.append("Bulgaria");}
    if (sku.contains("#AB4")){result.append("Singapore");}
    if (sku.contains("#ARL")){result.append("Czech/Slovakia");}
    if (sku.contains("#BCM")){result.append("Czech/Slovakia");}
    if (sku.contains("#B1R")){result.append("Baltics");}
    if (sku.contains("#B1T")){result.append("Bulgaria/Romania");}
    if (sku.contains("#AKQ")){result.append("Serbia");}
    if (sku.contains("#B10")){result.append("Euro-A5");}
    if (sku.contains("#AK9")){result.append("Euro-A2");}
    if (sku.contains("#B1S")){result.append("French Arabic");}
    if (sku.contains("#AKH")){result.append("Chile");}
    if (sku.contains("#A2N")){result.append("Saudi Arabia");}
    if (sku.contains("#AR6")){result.append("Indonesia");}
    if (sku.contains("#ABV")){result.append("Arabia");}
    if (sku.contains("#BH4")){result.append("Africa FR");}
    if (sku.contains("#BH5")){result.append("Africa EN");}
    if (sku.contains("#BH6")){result.append("Africa EN/FR");}
    result = result.trimmed();
    return result;
}

QString SYSINFO_SYSTEM_PRODUCTNAME() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "1";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Product Name:")) {
                foolist = foo.split(":");
                break;
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
    }
    //Trim unnecesary info
    result.simplified();
    result.replace("System Product Name","",Qt::CaseInsensitive);//some dumb bioses actually report this
    result.replace("Notebook","",Qt::CaseInsensitive);
    result.replace("PC","",Qt::CaseInsensitive);
    result.replace("HP","",Qt::CaseSensitive);
    result.replace("VMware Virtual Platform","VMWare",Qt::CaseInsensitive);
    result.replace("To Be Filled By O.E.M.","",Qt::CaseInsensitive);

    //Special cases
    QString sku = SYSINFO_SYSTEM_SKU();
    if (sku.contains("A7S55EA")){
        result = "Folio 13-1050ez ";
        result.append(SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(sku));
    }
    if (sku.contains("H6E31EA")){
        result = "ProBook 430 G1 ";
        result.append(SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(sku));
    }
    if (sku.contains("H0V07EA")){
        result = "ProBook 470 G0 "; //ati8 + i5
        result.append(SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(sku));
    }
    if (sku.contains("H4R48EA")){
        result = "ProBook 4340s ";
        result.append(SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(sku));
    }
    if (sku.contains("B6N72EA")){
        result = "ProBook 4740s "; //ati7 + i5
        result.append(SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(sku));
    }
    if (sku.contains("C4Z61EA")){
        result = "ProBook 4740s "; //ati7 + i5
        result.append(SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(sku));
    }
    if (sku.contains("H5K30EA")){
        result = "ProBook 4740s "; //ati7 + i5
        result.append(SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(sku));
    }
    if (sku.contains("H5K41EA")){
        result = "ProBook 4740s "; //ati7 + i5
        result.append(SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(sku));
    }
    if (sku.contains("B8W13AA")){
        result = "Spectre XT Pro "; //i5
        result.append(SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(sku));
    }
    if (sku.contains("H6D55EA")){
        result = "Spectre XT Pro "; //i7
        result.append(SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(sku));
    }
    if (sku.contains("LW871AW")){
        result = "Elitebook 8760w ";
        result.append(SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(sku));
    }
    if (sku.contains("B9C91AW")){
        result = "Elitebook 8770w "; //firepro + i7
        result.append(SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(sku));
    }
    if (sku.contains("LY582EA")){
        result = "Elitebook 8770w "; //quadro + i7
        result.append(SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(sku));
    }
    if (sku.contains("LY584EA")){
        result = "Elitebook 8770w "; //quadro + i7++
        result.append(SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(sku));
    }
    if (sku.contains("LY588EA")){
        result = "Elitebook 8770w "; //firepro + i5
        result.append(SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(sku));
    }
    if (sku.contains("E1U34EA")){
        result = "Envy 17-j070ez "; //geforce + i7
        result.append(SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(sku));
    }
    if (sku.contains("E4Q54EA")){
        result = "Envy 17-j077ez "; //geforce + i7
        result.append(SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(sku));
    }
    if (sku.contains("E1U35EA")){
        result = "Envy 17-j090ez "; //geforce + i7
        result.append(SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(sku));
    }
    if (sku.contains("C4V19EA")){
        result = "Envy d7-7286ez "; //geforce + i7
        result.append(SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(sku));
    }
    if (sku.contains("B6H29EA")){
        result = "Envy 6-1076ez ";
        result.append(SYSINFO_VENDORSPECIFIC_HP_PORTABLES_COUNTRIFICATION(sku));
    }
    if (sku.contains("PSAY3E-04300TS4")){
        result = "Satellite P755-11T"; //geforce + i7, probably swiss?
    }

    //
    result = result.trimmed();
    return result;
}

QString SYSINFO_CHASSIS_TYPE() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "3";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Type:")) {
                foolist = foo.split(":");
                break;
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
        result = result.trimmed();
    }
    return result;
}

QString SYSINFO_MOBO_NAME() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "2";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Product Name:")) {
                foolist = foo.split(":");
                break;
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
    }
    //Trim unnecesary info
    result.simplified();
    result.replace("EVGA","",Qt::CaseInsensitive);
    result.replace("To be filled by O.E.M.","",Qt::CaseInsensitive);
    result.replace("440BX Desktop Reference Platform","440BX",Qt::CaseInsensitive);
    result.replace("Virtual Machine","VM",Qt::CaseInsensitive);
    //Specific cases
    QString chassistype = SYSINFO_CHASSIS_TYPE();
    QString productname = SYSINFO_SYSTEM_PRODUCTNAME();
    if (chassistype.contains("Notebook") ){
        result = QString("%1 (%2)").arg(result).arg(productname);
    }

    result = result.trimmed();
    return result;
}

QString SYSINFO_MOBO_SERIALNUMBER() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "2";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Serial Number:")) {
                foolist = foo.split(":");
                break;
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
        result = result.trimmed();
    }
    result.replace("To Be Filled By O.E.M.","-",Qt::CaseInsensitive);
    result.replace("None","-",Qt::CaseInsensitive);
    if (result == ""){ result = "Unknown";}
    return result;
}

QString SYSINFO_BIOS_VENDOR() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "0";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Vendor:")) {
                foolist = foo.split(":");
                break;
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
        result = result.trimmed();
    }
    //Trim

    if (result.contains("Phoenix",Qt::CaseInsensitive)){ result = "Phoenix"; }
    if (result.contains("Insyde",Qt::CaseInsensitive)) { result = "InsydeH2O";}
    if (result.contains("Award",Qt::CaseInsensitive)) { result = "Award";}
    if (result.contains("Megatrends",Qt::CaseInsensitive)) { result = "AMI";}

    return result;
}

QString SYSINFO_BIOS_VERSION() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "0";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Version:")) {
                foolist = foo.split(":");
                break;
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
        result = result.trimmed();
    }
    //Trim
    result.replace("Rev. ","",Qt::CaseInsensitive);
    //Special cases
    if (SYSINFO_BIOS_VENDOR().contains("Intel")){
        QStringList versionlist;
        versionlist = result.split(".");
        result = versionlist.at(1);
    }

    return result;
}

QString SYSINFO_BIOS_REVISION() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "0";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("BIOS Revision:")) {
                foolist = foo.split(":");
                break;
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
        result = result.trimmed();
    }
    if (result == ""){ result = "-";}
    return result;
}

QString SYSINFO_BIOS_FIRMWARE_REVISION() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "0";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Firmware Revision:")) {
                foolist = foo.split(":");
                break;
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
        result = result.trimmed();
    }
    if (result == ""){ result = "-";}
    return result;
}


QString SYSINFO_BIOS_ROM_SIZE() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "0";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("ROM Size:")) {
                foolist = foo.split(":");
                break;
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
        result = result.trimmed();
    }
    return result;
}

QString SYSINFO_BIOS_DATE() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "0";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Release Date:")) {
                foolist = foo.split(":");
                break;
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
        result = result.trimmed();
    }
    return result;
}

QString SYSINFO_BIOS_IS_UEFI() {
    QString result="Non-UEFI"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "0";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("UEFI is supported")) {
                result = "UEFI";
                break;
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    result = result.trimmed();
    return result;
}

QString SYSINFO_MOBO_SOCKET_COUNT() {
    QString result="-"; QString foo;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "4";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    int i=0; //default number of processors
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo=="Processor Information") {
                i += 1; //processor count increase
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    result = QString::number(i);
    result = result.trimmed();
    return result;
}

QString SYSINFO_RAM_MODULECOUNT() {
    QString result="-"; QString foo; int i=0;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--type" << "memory";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Memory Device")) {
                i += 1;//each occurence means a slot of ram exists on motherboard
            }
            if (foo.contains("Size: No Module Installed")) {
                i -= 1;//if size is not available it means slot is empty
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    result = QString::number(i);
    result = result.trimmed();
    return result;
}


QString SYSINFO_RAM_SLOTCOUNT() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--type" << "memory";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Number Of Devices:")) {
                foolist = foo.split(":");
                break;
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
        result = result.trimmed();
    }
    return result;
}


QString SYSINFO_RAM_INSTALLEDSIZE() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--t" << "19";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Range Size:")) {
                foolist = foo.split(":");
                break;
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
        result = result.trimmed();
    }
    return result;
}

QString SYSINFO_RAM_MAXCAPACITY() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--type" << "memory";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Maximum Capacity:")) {
                foolist = foo.split(":");
                break;
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
        result = result.trimmed();
    }
    return result;
}

QString SYSINFO_RAM_FORMFACTOR() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--type" << "memory";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Form Factor:")) {
                foolist = foo.split(":");
                break;//stop after first result since motherboards can't mix ram anyway
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    if (foolist.size()>0){
        result = foolist.at(1);
        result = result.trimmed();
    }
    return result;
}

QString SYSINFO_RAM_TYPE() {
    QString result="-"; QString foo; QStringList foolist;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--type" << "memory";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Type:")) {
                if (foo.contains("Error Correction")){
                    //skip "Error Correction Type:" since we are looking for "Type:"
                } else {
                    foolist = foo.split(":");
                    break;//stop after first result since motherboards can't mix ram anyway
                }

            }
        }
    }
    dmiout.close();
    dmiout.remove();
    //Trim unnecesary info
    result = foolist.at(1);
    result.replace("FB-DIMM","",Qt::CaseInsensitive);//this is because we use FORMFACTOR separately
    result.replace("DIMM","",Qt::CaseInsensitive);//this is because we use FORMFACTOR separately
    //
    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_RAM_RATEDSPEED() {
    QString result=""; QString foo; QStringList foolist; QStringList resultlist;int i=0;bool skip=false;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--type" << "memory";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("No Module Installed")){
                skip = true;
            }
            if (foo.contains("Speed:")) {
                if (!foo.contains("Configured")){
                    if (skip==false){
                        foolist = foo.split(":");
                        resultlist << foolist.at(1);
                        result="";
                    } else {skip = false;}

                }
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    for(i=0; i<resultlist.count();i++){
        result.append(resultlist.at(i));
        if (i > -1 && i < resultlist.count()-1){
            result.append("|");
        }
    }
    //
    result.replace("MHz","",Qt::CaseInsensitive);
    result.replace("|||","-",Qt::CaseInsensitive);
    result.replace("||","-",Qt::CaseInsensitive);
    result.replace(" |","|",Qt::CaseInsensitive);
    result.replace("| ","|",Qt::CaseInsensitive);
    //
    result.simplified();
    result = result.trimmed();
    result.append(" MHz");
    return result;
}

QString SYSINFO_RAM_CONFIGUREDSPEED() {
    QString result=""; QString foo; QStringList foolist; QStringList resultlist;int i=0;bool skip=false;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--type" << "memory";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("No Module Installed")){
                skip = true;
            }
            if (foo.contains("Configured Clock Speed:")) {
                if (skip==false){
                    foolist = foo.split(":");
                    resultlist << foolist.at(1);
                    result="";
                } else {skip = false;}
            }
        }
    }
    dmiout.close();
    dmiout.remove();
    for(i=0; i<resultlist.count();i++){
        result.append(resultlist.at(i));
        if (i > -1 && i < resultlist.count()-1){
            result.append("|");
        }
    }
    //
    result.replace("MHz","",Qt::CaseInsensitive);
    result.replace("|||","-",Qt::CaseInsensitive);
    result.replace("||","-",Qt::CaseInsensitive);
    result.replace(" |","|",Qt::CaseInsensitive);
    result.replace("| ","|",Qt::CaseInsensitive);
    //
    result.simplified();
    result = result.trimmed();
    result.append(" MHz");
    return result;
}

QString SYSINFO_RAM_PARTNUMBER() {
    QString result=""; QString foo; QStringList foolist; QStringList resultlist;int i=0;bool skip=false;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--type" << "memory";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("No Module Installed")){
                skip = true;
            }
            if (foo.contains("Part Number:")) {
                if (skip==false){
                    foolist = foo.split(":");
                    resultlist << foolist.at(1);
                    result="";
                } else {skip = false;}

            }
        }
    }
    dmiout.close();
    dmiout.remove();
    for(i=0; i<resultlist.count();i++){
        result.append(resultlist.at(i));
        if (i > -1 && i < resultlist.count()-1){
            result.append("|");
        }
    }
    //Trim
    result.replace("0x0000000000000000000000000000000000","Unknown",Qt::CaseInsensitive);
    result.replace("ModulePartNumber01","Unknown",Qt::CaseInsensitive);
    result.replace("ModulePartNumber02","Unknown",Qt::CaseInsensitive);
    result.replace("ModulePartNumber03","Unknown",Qt::CaseInsensitive);
    result.replace("ModulePartNumber04","Unknown",Qt::CaseInsensitive);
    result.replace("ModulePartNumber05","Unknown",Qt::CaseInsensitive);
    result.replace("ModulePartNumber06","Unknown",Qt::CaseInsensitive);
    result.replace("ModulePartNumber07","Unknown",Qt::CaseInsensitive);
    result.replace("ModulePartNumber08","Unknown",Qt::CaseInsensitive);
    result.replace("ModulePartNumber09","Unknown",Qt::CaseInsensitive);
    result.replace("ModulePartNumber10","Unknown",Qt::CaseInsensitive);
    result.replace("ModulePartNumber11","Unknown",Qt::CaseInsensitive);
    result.replace("ModulePartNumber12","Unknown",Qt::CaseInsensitive);
    result.replace("PartNum0","Unknown",Qt::CaseInsensitive);
    result.replace("PartNum1","Unknown",Qt::CaseInsensitive);
    result.replace("PartNum2","Unknown",Qt::CaseInsensitive);
    result.replace("PartNum3","Unknown",Qt::CaseInsensitive);
    result.replace("PartNum4","Unknown",Qt::CaseInsensitive);
    result.replace("Dimm0_PartNum","Unknown",Qt::CaseInsensitive);
    result.replace("Dimm1_PartNum","Unknown",Qt::CaseInsensitive);
    result.replace("Dimm2_PartNum","Unknown",Qt::CaseInsensitive);
    result.replace("Dimm3_PartNum","Unknown",Qt::CaseInsensitive);
    result.replace("[Empty]","Unknown",Qt::CaseInsensitive);
    result.replace("Undefined","Unknown",Qt::CaseInsensitive);
    result.replace("Not Specified","Unknown",Qt::CaseInsensitive);
    result.replace("ChannelA_Dimm1_PartNum","Unknown",Qt::CaseInsensitive);
    result.replace("ChannelA_Dimm2_PartNum","Unknown",Qt::CaseInsensitive);
    result.replace("ChannelB_Dimm1_PartNum","Unknown",Qt::CaseInsensitive);
    result.replace("ChannelB_Dimm2_PartNum","Unknown",Qt::CaseInsensitive);
    result.replace("ChannelC_Dimm1_PartNum","Unknown",Qt::CaseInsensitive);
    result.replace("ChannelC_Dimm2_PartNum","Unknown",Qt::CaseInsensitive);
    result.replace("ChannelD_Dimm1_PartNum","Unknown",Qt::CaseInsensitive);
    result.replace("ChannelD_Dimm2_PartNum","Unknown",Qt::CaseInsensitive);
    result.replace("Array1_PartNumber0","Unknown",Qt::CaseInsensitive);
    result.replace("Array1_PartNumber1","Unknown",Qt::CaseInsensitive);
    result.replace("Array1_PartNumber2","Unknown",Qt::CaseInsensitive);
    result.replace("Array1_PartNumber3","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer0","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer1","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer2","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer3","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer4","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer5","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer6","Unknown",Qt::CaseInsensitive);
    //
    result.replace("|||","-",Qt::CaseInsensitive);
    result.replace("||","-",Qt::CaseInsensitive);
    result.replace("| ","|", Qt::CaseInsensitive);
    result.replace(" |","|", Qt::CaseInsensitive);
    //
    result.simplified();
    result.trimmed();
    return result;
}

QString SYSINFO_RAM_VENDOR() {
    QString result=""; QString foo; QStringList foolist; QStringList resultlist;int i=0;bool skip=false;
    //Start dmidecode and output to file
    QProcess dmidecode;QStringList args;args << "--type" << "memory";
    dmidecode.setStandardOutputFile("dmid.out");
    dmidecode.start("dmid.dll", args);
    dmidecode.waitForFinished();
    dmidecode.close();
    //Open output file of dmidecode and parse
    QFile dmiout("dmid.out");
    if (dmiout.open(QIODevice::ReadOnly)){
        QTextStream in(&dmiout);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("No Module Installed")){
                skip = true;
            }
            if (foo.contains("Manufacturer:")) {
                if (skip==false){
                    foolist = foo.split(":");
                    resultlist << foolist.at(1);
                    result="";
                } else {skip = false;}

            }
        }
    }
    dmiout.close();
    dmiout.remove();
    for(i=0; i<resultlist.count();i++){
        result.append(resultlist.at(i));
        if (i > -1 && i < resultlist.count()-1){
            result.append("|");
        }
    }
    result.replace("| ","|", Qt::CaseInsensitive);
    //Special cases. See more details at http://aspia.org/doxygen/0.3.0/d2/d0c/infolists_8c_source.php
    //JEDEC list: http://www.jedec.org/standards-documents/docs/jep-106ab
    result.replace("0x","",Qt::CaseInsensitive);
    result.replace("06C1","ASint", Qt::CaseInsensitive);
    result.replace("05D6","Walton Chaintech", Qt::CaseInsensitive);
    result.replace("0443","Ramaxel", Qt::CaseInsensitive);
    result.replace("04CD","G.Skill", Qt::CaseInsensitive);
    result.replace("0420","G.Skill", Qt::CaseInsensitive);
    result.replace("0325","KINGMAX", Qt::CaseInsensitive);
    result.replace("038A","Princeton", Qt::CaseInsensitive);
    result.replace("0313","GeIL", Qt::CaseInsensitive);//not sure if 0313 is GeIL
    result.replace("8313","GeIL", Qt::CaseInsensitive);///8313 is confirmed to be GeIL
    result.replace("030B","Nanya", Qt::CaseInsensitive);
    result.replace("059B","Crucial", Qt::CaseInsensitive);
    result.replace("0502","Patriot", Qt::CaseInsensitive);
    result.replace("0551","Qimonda", Qt::CaseInsensitive);
    result.replace("03DA","Swissbit", Qt::CaseInsensitive);
    result.replace("029E","Corsair", Qt::CaseInsensitive);
    result.replace("0215","Corsair", Qt::CaseInsensitive);
    result.replace("02FE","Elpida", Qt::CaseInsensitive);
    result.replace("04EF","Team Group", Qt::CaseInsensitive);
    result.replace("0423","Team Group", Qt::CaseInsensitive);
    result.replace("04B0","OCZ", Qt::CaseInsensitive);
    result.replace("04CB","A-DATA", Qt::CaseInsensitive);
    result.replace("0198","Kingston", Qt::CaseInsensitive);
    result.replace("015E","Itec Memory", Qt::CaseInsensitive);
    result.replace("0161","WINTEC", Qt::CaseInsensitive);
    result.replace("7F61","WINTEC", Qt::CaseInsensitive);
    result.replace("0162","Super PC", Qt::CaseInsensitive);
    result.replace("016B","GoldenRAM", Qt::CaseInsensitive);
    result.replace("0191","DATARAM", Qt::CaseInsensitive);
    result.replace("0194","Smart Modular", Qt::CaseInsensitive);
    result.replace("014F","Transcend", Qt::CaseInsensitive);
    result.replace("0132","Mushkin", Qt::CaseInsensitive);
    result.replace("859B","Crucial", Qt::CaseInsensitive);
    result.replace("2C","Micron", Qt::CaseInsensitive);
    result.replace("40","Mosel Vitelic", Qt::CaseInsensitive);
    result.replace("CE","Samsung", Qt::CaseSensitive);
    result.replace("C1","Infineon", Qt::CaseInsensitive);
    result.replace("10","NEC", Qt::CaseInsensitive);
    result.replace("01","AMD", Qt::CaseInsensitive);
    result.replace("43","Xerox", Qt::CaseInsensitive);
    result.replace("C8","Apple", Qt::CaseInsensitive);
    result.replace("54","Hewlett-Packard", Qt::CaseInsensitive);
    result.replace("DA","Winbond", Qt::CaseSensitive);
    result.replace("AD","SK Hynix", Qt::CaseSensitive);//older models might be Hyundai.
    //
    result.replace("Manufacturer01","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer1","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer02","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer2","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer03","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer3","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer04","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer4","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer05","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer06","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer07","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer08","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer09","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer10","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer11","Unknown",Qt::CaseInsensitive);
    result.replace("Manufacturer12","Unknown",Qt::CaseInsensitive);
    result.replace("[Empty]","Unknown",Qt::CaseInsensitive);
    result.replace("Undefined","Unknown",Qt::CaseInsensitive);
    result.replace("Not Specified","Unknown",Qt::CaseInsensitive);
    result.replace("ChannelA_Dimm1_Manufacturer","Unknown",Qt::CaseInsensitive);
    result.replace("ChannelA_Dimm2_Manufacturer","Unknown",Qt::CaseInsensitive);
    result.replace("ChannelB_Dimm1_Manufacturer","Unknown",Qt::CaseInsensitive);
    result.replace("ChannelB_Dimm2_Manufacturer","Unknown",Qt::CaseInsensitive);
    result.replace("ChannelC_Dimm1_Manufacturer","Unknown",Qt::CaseInsensitive);
    result.replace("ChannelC_Dimm2_Manufacturer","Unknown",Qt::CaseInsensitive);
    result.replace("ChannelD_Dimm1_Manufacturer","Unknown",Qt::CaseInsensitive);
    result.replace("ChannelD_Dimm2_Manufacturer","Unknown",Qt::CaseInsensitive);
    //Try to determine vendor by PartNumber
    if (result == ""){ result = "Unknown";}
    if (result.contains("Unknown")){
        QString pn = SYSINFO_RAM_PARTNUMBER();
        if(pn.startsWith("CT") || pn.startsWith("BLT")){result="Crucial";}
        if(pn.contains("SUPERTALENT")){result="Super Talent";}
        if(pn=="DDR3-2400 CL10 8G"){result="AVEXIR";}
        if(pn.contains("Vulcan")){result="Team Xtreme";}//Vulcan-1600
    }
    //

    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_OS_TIMESTAMP(){
    QDateTime ct; ct = QDateTime::currentDateTime();
    return ct.toString("yyyy-MM-ddTHH:mm:ss");
}

QString SYSINFO_OS_BITS() {
  QString result="";
  //Is 64bit OS?
  LPTSTR OsType = NULL;
  if (GetSystemWow64Directory(OsType, 1) > 0){
      result = "64";
  } else {
       result = "32";
  }
  return result;
}

QString SYSINFO_OS_NAME() {
    //Retrieve generic name from registry
    QSettings registry("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion",QSettings::NativeFormat);
    QString result = registry.value( "ProductName", "-" ).toString();
    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_OS_SP() {
    QString result="";
    if (!SYSINFO_OS_NAME().contains("Windows 8")){
        //Because of a stupid WOW64 redirection, you can't retrieve CSDVersion from registry,
        //so we will run an external compiled Batch Script
        QProcess csdv;
        csdv.start("csdv.dll");
        csdv.waitForFinished();
        csdv.close();
        //Open output file and parse
        QFile csdvout("csdv.out");
        if (csdvout.open(QIODevice::ReadOnly)){
            QTextStream in(&csdvout);
            while ( !in.atEnd() ){ result = in.readLine(); }
        }
        csdvout.close();
        csdvout.remove();
        //Trim
        result.replace("Service Pack ","SP",Qt::CaseInsensitive);
        result.replace("0x0 ","",Qt::CaseInsensitive);//no service pack
        result.simplified();result.trimmed();
    }
    return result;
}

QString SYSINFO_GFX_VENDORGPU_NAME() {
    QString result=""; QString foo; QStringList foolist; QStringList resultlist;int i=0;
    //Open output file of gpuz and parse
    QFile gpuzout("gpuz.out");
    if (gpuzout.open(QIODevice::ReadOnly)){QTextStream in(&gpuzout);
        while ( !in.atEnd() ){
            foo = in.readLine();
            if (foo.contains("<vendor>")) {
                foolist = foo.split(">");
                resultlist << foolist.at(1);
            }
        }
    }
    gpuzout.close();
    result.simplified();result.trimmed();
    for(i=0; i<resultlist.count();i++){
        result.append(resultlist.at(i));
        if (i > -1 && i < resultlist.count()-1){
            result.append("|");
        }
    }
    //Trim
    result.replace("| ","|", Qt::CaseInsensitive);
    result.replace("</vendor","",Qt::CaseInsensitive);
    //
    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_GFX_VENDORGPU_ID() {
    QString result=""; QString foo; QStringList foolist; QStringList resultlist;int i=0;
    //Open output file of gpuz and parse
    QFile gpuzout("gpuz.out");
    if (gpuzout.open(QIODevice::ReadOnly)){QTextStream in(&gpuzout);
        while ( !in.atEnd() ){
            foo = in.readLine();
            if (foo.contains("<vendorid>")) {
                foolist = foo.split(">");
                resultlist << foolist.at(1);
            }
        }
    }
    gpuzout.close();
    result.simplified();result.trimmed();
    for(i=0; i<resultlist.count();i++){
        result.append(resultlist.at(i));
        if (i > -1 && i < resultlist.count()-1){
            result.append("|");
        }
    }
    //Trim
    result.replace("| ","|", Qt::CaseInsensitive);
    result.replace("</vendorid","",Qt::CaseInsensitive);
    //
    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_GFX_DEVICE_ID() {
    QString result=""; QString foo; QStringList foolist; QStringList resultlist;int i=0;
    //Open output file of gpuz and parse
    QFile gpuzout("gpuz.out");
    if (gpuzout.open(QIODevice::ReadOnly)){QTextStream in(&gpuzout);
        while ( !in.atEnd() ){
            foo = in.readLine();
            if (foo.contains("<deviceid>")) {
                foolist = foo.split(">");
                resultlist << foolist.at(1);
            }
        }
    }
    gpuzout.close();
    result.simplified();result.trimmed();
    for(i=0; i<resultlist.count();i++){
        result.append(resultlist.at(i));
        if (i > -1 && i < resultlist.count()-1){
            result.append("|");
        }
    }
    //Trim
    result.replace("| ","|", Qt::CaseInsensitive);
    result.replace("</deviceid","",Qt::CaseInsensitive);
    //
    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_GFX_SUBSYS_ID() {
    QString result=""; QString foo; QStringList foolist; QStringList resultlist;int i=0;
    //Open output file of gpuz and parse
    QFile gpuzout("gpuz.out");
    if (gpuzout.open(QIODevice::ReadOnly)){QTextStream in(&gpuzout);
        while ( !in.atEnd() ){
            foo = in.readLine();
            if (foo.contains("<subsysid>")) {
                foolist = foo.split(">");
                resultlist << foolist.at(1);
            }
        }
    }
    gpuzout.close();

    result.simplified();result.trimmed();
    for(i=0; i<resultlist.count();i++){
        result.append(resultlist.at(i));
        if (i > -1 && i < resultlist.count()-1){
            result.append("|");
        }
    }
    //Trim
    result.replace("| ","|", Qt::CaseInsensitive);
    result.replace("</subsysid","",Qt::CaseInsensitive);
    //
    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_GFX_COUNT() {
    QString result=""; QString foo;int i=0;
    //Open output file of gpuz and parse
    QFile gpuzout("gpuz.out");
    if (gpuzout.open(QIODevice::ReadOnly)){QTextStream in(&gpuzout);
        while ( !in.atEnd() ){
            foo = in.readLine();
            if (foo.contains("<cardname>")) {
                i += 1;
            }
        }
    }
    gpuzout.close();
    result = QString::number(i);
    return result;
}


QString SYSINFO_GFX_INTEGRATOR_NAME() {
    QString result=""; QString foo; QStringList foolist; QStringList resultlist;int i=0;
    //Open output file of gpuz and parse
    QFile gpuzout("gpuz.out");
    if (gpuzout.open(QIODevice::ReadOnly)){QTextStream in(&gpuzout);
        while ( !in.atEnd() ){
            foo = in.readLine();
            if (foo.contains("<subvendor>")) {
                foolist = foo.split(">");
                resultlist << foolist.at(1);
            }
        }
    }
    gpuzout.close();

    result.simplified();result.trimmed();
    for(i=0; i<resultlist.count();i++){
        result.append(resultlist.at(i));
        if (i > -1 && i < resultlist.count()-1){
            result.append("|");
        }
    }
    //Trim
    result.replace("| ","|", Qt::CaseInsensitive);
    result.replace("</subvendor","",Qt::CaseInsensitive);
    result.replace("Sapphire/PCPartner","Sapphire",Qt::CaseInsensitive);
    result.replace("XFX Pine Group","XFX",Qt::CaseInsensitive);
    result.replace("CardExpert Technology","Gainward",Qt::CaseInsensitive);
    result.replace("BFG Tech","BFG",Qt::CaseInsensitive);
    result.replace("Palit Microsystems","Palit",Qt::CaseInsensitive);
    //
    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_GFX_INTEGRATOR_ID() {
    QString result=""; QString foo; QStringList foolist; QStringList resultlist;int i=0;
    //Open output file of gpuz and parse
    QFile gpuzout("gpuz.out");
    if (gpuzout.open(QIODevice::ReadOnly)){QTextStream in(&gpuzout);
        while ( !in.atEnd() ){
            foo = in.readLine();
            if (foo.contains("<subvendorid>")) {
                foolist = foo.split(">");
                resultlist << foolist.at(1);
            }
        }
    }
    gpuzout.close();

    result.simplified();result.trimmed();
    for(i=0; i<resultlist.count();i++){
        result.append(resultlist.at(i));
        if (i > -1 && i < resultlist.count()-1){
            result.append("|");
        }
    }
    //Trim
    result.replace("| ","|", Qt::CaseInsensitive);
    result.replace("</subvendorid","",Qt::CaseInsensitive);
    //
    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_GFX_RAM_SIZE() {
    QString result=""; QString foo; QStringList foolist; QStringList resultlist;int i=0;
    //Open output file of gpuz and parse
    QFile gpuzout("gpuz.out");
    if (gpuzout.open(QIODevice::ReadOnly)){QTextStream in(&gpuzout);
        while ( !in.atEnd() ){
            foo = in.readLine();
            if (foo.contains("<memsize>")) {
                foolist = foo.split(">");
                resultlist << foolist.at(1);
            }
        }
    }
    gpuzout.close();

    result.simplified();result.trimmed();
    for(i=0; i<resultlist.count();i++){
        result.append(resultlist.at(i));
        if (i > -1 && i < resultlist.count()-1){
            result.append("|");
        }
    }
    //Trim
    result.replace("| ","|", Qt::CaseInsensitive);
    result.replace("</memsize","",Qt::CaseInsensitive);
    //
    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_GFX_RAM_TYPE() {
    QString result=""; QString foo; QStringList foolist; QStringList resultlist;int i=0;
    //Open output file of gpuz and parse
    QFile gpuzout("gpuz.out");
    if (gpuzout.open(QIODevice::ReadOnly)){QTextStream in(&gpuzout);
        while ( !in.atEnd() ){
            foo = in.readLine();
            if (foo.contains("<memtype>")) {
                foolist = foo.split(">");
                resultlist << foolist.at(1);
            }
        }
    }
    gpuzout.close();

    result.simplified();result.trimmed();
    for(i=0; i<resultlist.count();i++){
        result.append(resultlist.at(i));
        if (i > -1 && i < resultlist.count()-1){
            result.append("|");
        }
    }
    //Trim
    result.replace("| ","|", Qt::CaseInsensitive);
    result.replace("</memtype","",Qt::CaseInsensitive);
    //
    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_GFX_RAM_BUSWIDTH() {
    QString result=""; QString foo; QStringList foolist; QStringList resultlist;int i=0;
    //Open output file of gpuz and parse
    QFile gpuzout("gpuz.out");
    if (gpuzout.open(QIODevice::ReadOnly)){QTextStream in(&gpuzout);
        while ( !in.atEnd() ){
            foo = in.readLine();
            if (foo.contains("<membuswidth>")) {
                foolist = foo.split(">");
                resultlist << foolist.at(1);
            }
        }
    }
    gpuzout.close();

    result.simplified();result.trimmed();
    for(i=0; i<resultlist.count();i++){
        result.append(resultlist.at(i));
        if (i > -1 && i < resultlist.count()-1){
            result.append("|");
        }
    }
    //Trim
    result.replace("| ","|", Qt::CaseInsensitive);
    result.replace("</membuswidth","",Qt::CaseInsensitive);
    //
    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_GFX_SPEED_CORE() {
    QString result=""; QString foo; QStringList foolist; QStringList resultlist;int i=0;
    //Open output file of gpuz and parse
    QFile gpuzout("gpuz.out");
    if (gpuzout.open(QIODevice::ReadOnly)){QTextStream in(&gpuzout);
        while ( !in.atEnd() ){
            foo = in.readLine();
            if (foo.contains("<clockgpu>")) {
                foolist = foo.split(">");
                resultlist << foolist.at(1);
            }
        }
    }
    gpuzout.close();

    result.simplified();result.trimmed();
    for(i=0; i<resultlist.count();i++){
        result.append(resultlist.at(i));
        if (i > -1 && i < resultlist.count()-1){
            result.append("|");
        }
    }
    //Trim
    result.replace("| ","|", Qt::CaseInsensitive);
    result.replace("</clockgpu","",Qt::CaseInsensitive);
    //
    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_GFX_SPEED_RAM() {
    QString result=""; QString foo; QStringList foolist; QStringList resultlist;int i=0;
    //Open output file of gpuz and parse
    QFile gpuzout("gpuz.out");
    if (gpuzout.open(QIODevice::ReadOnly)){QTextStream in(&gpuzout);
        while ( !in.atEnd() ){
            foo = in.readLine();
            if (foo.contains("<clockmem>")) {
                foolist = foo.split(">");
                resultlist << foolist.at(1);
            }
        }
    }
    gpuzout.close();

    result.simplified();result.trimmed();
    for(i=0; i<resultlist.count();i++){
        result.append(resultlist.at(i));
        if (i > -1 && i < resultlist.count()-1){
            result.append("|");
        }
    }
    //Trim
    result.replace("| ","|", Qt::CaseInsensitive);
    result.replace("</clockmem","",Qt::CaseInsensitive);
    //
    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_GFX_SPEED_SHADER() {
    QString result=""; QString foo; QStringList foolist; QStringList resultlist;int i=0;
    //Open output file of gpuz and parse
    QFile gpuzout("gpuz.out");
    if (gpuzout.open(QIODevice::ReadOnly)){QTextStream in(&gpuzout);
        while ( !in.atEnd() ){
            foo = in.readLine();
            if (foo.contains("<clockshader>")) {
                foolist = foo.split(">");
                resultlist << foolist.at(1);
            }
        }
    }
    gpuzout.close();

    result.simplified();result.trimmed();
    for(i=0; i<resultlist.count();i++){
        result.append(resultlist.at(i));
        if (i > -1 && i < resultlist.count()-1){
            result.append("|");
        }
    }
    //Trim
    result.replace("| ","|", Qt::CaseInsensitive);
    result.replace("</clockshader","",Qt::CaseInsensitive);
    //
    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_GFX_DRIVER_INFFILE() {
    QString result=""; QString foo; int i=0;
    if (!SYSINFO_OS_NAME().contains("XP")){
        for (i=0;i<100;i++){
            QFile inf("C:\\Windows\\inf\\oem" + QString::number(i) + ".inf");
            if (inf.exists()==1){
                if (inf.open(QIODevice::ReadOnly)){QTextStream in(&inf);
                    while ( !in.atEnd() ){
                        foo = in.readLine();
                        //TODO: check old drivers
                        if (foo.contains("AMD display information file")) {//AMD driver
                            result = inf.fileName();
                            break;
                        }
                        if (foo.contains("Display INF file")){//NVIDIA driver
                            result = inf.fileName();
                            break;
                        }
                        if (foo.contains("Intel Corporation graphics")){//Intel driver
                            result = inf.fileName();
                            break;
                        }
                    }
                }
                inf.close();
            }
        }
    }

    result.replace("/","\\",Qt::CaseInsensitive);
    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_GFX_DRIVER_VERSION_RELEASE() {
    QString result="-"; QString foo;int i=1;
    //Open driver inf file
    QFile inf(SYSINFO_GFX_DRIVER_INFFILE().replace("\\","\\\\",Qt::CaseInsensitive));
    if (inf.open(QIODevice::ReadOnly)){QTextStream in(&inf);
        while ( !in.atEnd() ){
            foo = in.readLine();
            if (i==2){
                result = foo;
                break;
            }
            i += 1;
        }
    }
    inf.close();
    //Trim
    result.replace("--","", Qt::CaseInsensitive);
    result.replace(";","",Qt::CaseInsensitive);
    //
    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_GFX_DRIVER_DATE() {
    QString result="-"; QString foo;
    //Open driver inf file
    QFile inf(SYSINFO_GFX_DRIVER_INFFILE().replace("\\","\\\\",Qt::CaseInsensitive));
    if (inf.open(QIODevice::ReadOnly)){QTextStream in(&inf);
        while ( !in.atEnd() ){
            foo = in.readLine();
            if (foo.contains("DriverVer")){
                result = foo.split(",").at(0);
                result.replace("DriverVer","",Qt::CaseInsensitive);
                result.replace("=","",Qt::CaseInsensitive);
                break;
            }
        }
    }
    inf.close();
    //
    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_GFX_DRIVER_VERSION() {
    QString result="-"; QString foo;
    //Open driver inf file
    QFile inf(SYSINFO_GFX_DRIVER_INFFILE().replace("\\","\\\\",Qt::CaseInsensitive));
    if (inf.open(QIODevice::ReadOnly)){QTextStream in(&inf);
        while ( !in.atEnd() ){
            foo = in.readLine();
            if (foo.contains("DriverVer")){
                result = foo.split(",").at(1);
                result.replace("DriverVer","",Qt::CaseInsensitive);
                result.replace("=","",Qt::CaseInsensitive);
                break;
            }
        }
    }
    inf.close();
    //
    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_GFX_DXVERSION() {
    QString result="-"; QString foo; QStringList foolist;
    //Open output file of dxdiag and parse
    QFile dxdiagOut(_dxdiagpath);
    if (dxdiagOut.open(QIODevice::ReadOnly)){
        QTextStream in(&dxdiagOut);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("DirectX Version:")) {
                foolist = foo.split(":");
            }
        }
    }
    dxdiagOut.close();
    if (foolist.size()>0){
        result = foolist.at(1);
        result = result.trimmed();
    }
    return result;
}

QString SYSINFO_GFX_OUTPUTPORTS() {
    QString result="Used ports:"; QString foo; QStringList foolist; QStringList resultlist;int i=0;
    QString outputpath = qApp->property("Benchmark_Install_Path").toString();
    outputpath.append(_dxdiagpath);
    //Open output file of dmidecode and parse
    QFile dxdiagOut(outputpath);
    if (dxdiagOut.open(QIODevice::ReadOnly)){
        QTextStream in(&dxdiagOut);
        while ( !in.atEnd() )
        {
            foo = in.readLine();
            if (foo.contains("Output Type:")) {
                foolist = foo.split(":");
                resultlist << foolist.at(1);
            }
        }
    }
    dxdiagOut.close();
    for(i=0; i<resultlist.count();i++){
        result.append(resultlist.at(i));
        if (i > -1 && i < resultlist.count()-1){
            result.append("|");
        }
    }
    result.replace("| ","|", Qt::CaseInsensitive);
    result.replace("HD15","VGA",Qt::CaseInsensitive);
    result.simplified();
    result = result.trimmed();
    if (result == ""){ result = "Unknown";}
    return result;
}


QString SYSINFO_GFX_DRIVER_NAME() {
    QString result="-";
    QString version = SYSINFO_GFX_DRIVER_VERSION();
    QString build = SYSINFO_GFX_DRIVER_VERSION_RELEASE();
    QString deviceid = SYSINFO_GFX_VENDORGPU_ID().split("|").at(0);
    //SPECIAL CASES
    //ATI-AMD
    if (deviceid=="1002"){
        result = "Catalyst";//default name in case we don't have it in the database
        if (version=="8.921.5.0000"){
            if (    build.contains("111229a-131232C")){result="Catalyst 11.12 WHQL";}}
        if (version=="8.921.2.0000"){
            if (    build.contains("111205a-132104C")){result="Catalyst 12.1 RC11 HD7900";}}
        if (version=="8.930.0.0000"){
            if (    build.contains("111205a-132104C")){result="Catalyst 12.1 WHQL";}}
        if (version=="8.930.7.0000"){
            if (    build.contains("120224a-134185E")){result="Catalyst 12.1 RC10 Win8 CP";}}
        if (version=="8.930.10.0000"){
            if (    build.contains("120102a-131070E")){result="Catalyst 12.1a Preview";}}
        if (version=="8.940.0.0000"){
            if (    build.contains("120120a-132259E")){result="Catalyst 12.2 Preview";}}
        if (version=="8.950.0.0000"){
            if (    build.contains("120117a-131901E")){result="Catalyst 12.2 BETA";}//01/17
            if (    build.contains("120124a-132309E")){result="Catalyst 12.2 BETA";}//01/24
            if (    build.contains("120131a-132694E")){result="Catalyst 12.2 RC HD7000";}//01/31 Not sure if 12.2 or 12.3
            if (    build.contains("120214a-133575E")){result="Catalyst 12.3 RC";}//02/14
            if (    build.contains("120214a-133662E")){result="Catalyst 12.2 Pre-WHQL";}
            if (    build.contains("120214a-134393C")){result="Catalyst 12.2 WHQL";}}
        if (version=="8.950.5.0000"){
            if (    build.contains("120224a-134185E")){result="Catalyst 12.3 BETA";}}//02/24
        if (version=="8.951.0.0000"){
            if (    build.contains("120308a-135951E")){result="Catalyst 12.3 AGP Hotfix";}
            if (    build.contains("120308a-135594C")){result="Catalyst 12.3 WHQL";}}
        if (version=="8.951.1.0000"){
            if (    build.contains("120305m-134662E")){result="Catalyst 12.3 BETA";}}//03/05
        if (version=="8.960.0.0000"){
            if (    build.contains("120214a-133521E")){result="Catalyst 12.3 BETA";}//02/14
            if (    build.contains("120228m-134331E")){result="Catalyst 12.3 BETA";}//02/28
            if (    build.contains("120315a-135399E")){result="Catalyst 12.4 BETA";}}//03/15
        if (version=="8.961.0.0000"){
            if (    build.contains("120405a-137224C")){result="Catalyst 12.4 WHQL";}}
        if (version=="8.961.3.0000"){
            if (    build.contains("120524a-139456E")){result="Catalyst 12.4b Hotfix";}}
        if (version=="8.970.0.0000"){
            if (    build.contains("120418a-137336E")){result="Catalyst 12.5 BETA";}}//04/18
        if (version=="8.970.100.0000"){                result="Catalyst 13.4 Legacy";}
        if (version=="8.970.100.3000"){
            if (    build.contains("120703a-142008E")){result="Catalyst 12.6 Legacy";}}
        if (version=="8.970.100.7000"){                result="Catalyst 13.1 Legacy";}
        if (version=="8.972.4.0000"){                  result="Catalyst 12.6 BETA Win8 RP";}
        if (version=="8.980.0.0000"){
            if (    build.contains("120611a-141402C")){result="Catalyst 12.6 WHQL";}
            if (    build.contains("120522a-139735E")){result="Catalyst 12.6 BETA";}//05/31
            if (    build.contains("120604a-140027E")){result="Catalyst 12.4 BETA";}}//06/04
        if (version=="8.981.0.0000"){                  result="Catalyst 8.981 Embedded";}//120704a-137604C
        if (version=="8.981.2.0000"){
            if (    build.contains("120612a-140817E")){result="Catalyst 12.7 BETA";}//06/12
            if (    build.contains("120626a-141571E")){result="Catalyst 12.7 BETA";}}//06/26
        if (version=="8.981.2.1000"){                  result="Catalyst 12.7 BETA";}//06/25
        if (version=="8.982.0.0000"){                  result="Catalyst 12.8 WHQL";
            if (    build.contains("120719a-143310E")){result="Catalyst 12.7 HD7970M";}}
        if (version=="8.982.7.0000"){
            if (    build.contains("120808a-14870C")){result="Catalyst 12.8 BETA";}}//08/08 leaked driver
        if (version=="9.000.0.0000"){                  result="Catalyst 12.9";
            if (    build.contains("120612a-140545E")){result="Catalyst 12.6 BETA";}//06/12
            if (    build.contains("120809a-145085E")){result="Catalyst 12.X BETA";}}//08/09
        if (version=="9.001.0.0000"){
            if (    build.contains("120913a-146933E")){result="Catalyst 12.9 BETA";}
            if (    build.contains("120904a-146497E")){result="Catalyst 12.X BETA";}}//09/04
        if (version=="9.002.0.0000"){                  result="Catalyst 12.10 WHQL";}
        if (version=="9.010.8.0000"){//they skipped some versions, this list of betas is complete
            if (    build.contains("121012a-147510E")){result="Catalyst 12.11 BETA";}
            if (    build.contains("121021a-147510E")){result="Catalyst 12.11 BETA3";}
            if (    build.contains("121022a-147510E")){result="Catalyst 12.11 BETA4";}
            if (    build.contains("121105a-147510E")){result="Catalyst 12.11 BETA6";}
            if (    build.contains("121112a-149575E")){result="Catalyst 12.11 BETA7";}
            if (    build.contains("121115a-149712E")){result="Catalyst 12.11 BETA8";}
            if (    build.contains("121202a-150272E")){result="Catalyst 12.11 BETA11";}}
        if (version=="9.012.0.0000"){                  result="Catalyst 13.1 WHQL";}
        if (version=="12.100.0.0000"){                 result="Catalyst 13.2 BETA1";}
        if (version=="12.100.17.0000"){                result="Catalyst 13.2 BETA2";
            if (    build.contains("130128a-152570E")){result="Catalyst 13.2 BETA3";}
            if (    build.contains("130129a-152690E")){result="Catalyst 13.2 BETA4";}
            if (    build.contains("130202a-152920E")){result="Catalyst 13.2 BETA5";}
            if (    build.contains("130215a-153345E")){result="Catalyst 13.2 BETA6";}
            if (    build.contains("130226a-153761E")){result="Catalyst 13.2 BETA7";}
            if (    build.contains("130314a-154593E")){result="Catalyst 13.3 BETA1";}
            if (    build.contains("130320a-154717E")){result="Catalyst 13.3 BETA3";}}
        if (version=="12.101.2.0000"){                 result="Catalyst 13.3 BETA2";}
        if (version=="12.101.2.1000"){                 result="Catalyst 13.X HD7790";}
        if (version=="12.102.3.1000"){                 result="Catalyst 13.5 BETA2";}
        if (version=="12.104.0.0000"){                 result="Catalyst 13.4 WHQL";}
        if (version=="13.101.0.0000"){
            if (    build.contains("130523a")){        result="Catalyst 13.6 BETA";}
            if (    build.contains("130604a")){        result="Catalyst 13.6 BETA2";}}
        if (version=="13.150.1.0000"){                 result="Catalyst 13.X BETA Win8.1 P";}
        if (version=="13.150.100.1000"){               result="Catalyst 13.X BETA OGL43";}
        if (version=="13.152.1.8000"){                 result="Catalyst 13.9 WHQL";}
        if (version=="13.200.0.0000"){                 result="Catalyst 13.8 BETA1";}
        if (version=="13.200.11.0000"){
            if (    build.contains("130814a")){        result="Catalyst 13.8 BETA2";}
            if (    build.contains("130904a")){        result="Catalyst 13.10 BETA";}
            if (    build.contains("130920a-162870E")){result="Catalyst 13.10 BETA2";}}
        if (version=="13.250.16.0000"){
            if (    build.contains("130926a-163066E")){result="Catalyst 13.11 BETA1";}}
        if (version=="13.250.18.0000"){
            if (    build.contains("131007a-163510E")){result="Catalyst 13.11 BETA3";}//10/7
            if (    build.contains("131024a-164159E")){result="Catalyst 13.11 BETA6";}//10/24
            if (    build.contains("131025a-164159E")){result="Catalyst 13.11 BETA7";}//10/25
            if (    build.contains("131029a-164333E")){result="Catalyst 13.11 BETA8";}
            if (    build.contains("131107a-164684E")){result="Catalyst 13.11 BETA9.2";}
            if (    build.contains("131122a-165306E")){result="Catalyst 13.11 BETA9.4";}
            if (    build.contains("131129a-165578E")){result="Catalyst 13.11 BETA9.5";}}
        if (version=="13.250.22.0000"){                result="Catalyst 13.11 WHQL";}
        if (version=="13.251.11.0000"){
            if (    build.contains("131206a-165817C")){result="Catalyst 13.12 WHQL";}
            if (    build.contains("131206a-166151E")){result="Catalyst 13.12 WinUpdates";}}

    }
    //NVIDIA
    if (deviceid=="10DE"){
        QString forceware = version.replace(".","",Qt::CaseInsensitive);
        forceware = forceware.right(5);
        result= QString("ForceWare %1.%2").arg(forceware.left(3)).arg(forceware.right(2));

    }
    //INTEL
    if (deviceid=="8086"){
        result = "Intel Graphics";

        if (version=="6.14.10.5390"){                  result="HD 14.42.13.5390";}
        if (version=="6.14.10.5402"){                  result="HD 14.42.13.5402";}
        if (version=="6.14.10.5420"){                  result="HD 14.42.15.5420";}
        if (version=="6.14.10.5436"){                  result="HD 14.51.10.5436";}
        if (version=="6.14.10.5437"){                  result="HD 14.51.10.5437";}
        if (version=="8.15.10.2555"){                  result="GMA 15.17.18.2555";}
        if (version=="8.15.10.2622"){                  result="HD 15.22.54.2622";}
        if (version=="8.15.10.2869"){                  result="GMA 15.17.19.2869";}
        if (version=="9.17.10.3062"){                  result="HD 15.28.15.3062";}
        if (version=="9.17.10.3223"){                  result="HD 15.28.18.3223";}
        if (version=="9.18.10.3165"){                  result="HD 15.31.9.3165";}


//
    }
    //
    result.simplified();
    result = result.trimmed();
    return result;
}

QString SYSINFO_GFX_NAME() {
    QString result=""; QString foo; QStringList foolist; QStringList resultlist;int i=0;QString boo="";
    QStringList GPU_VendorID = SYSINFO_GFX_VENDORGPU_ID().split("|");
    QStringList GPU_DeviceID = SYSINFO_GFX_DEVICE_ID().split("|");
    QStringList GPU_SubsysID = SYSINFO_GFX_SUBSYS_ID().split("|");

    //Open output file of gpuz and parse
    QFile gpuzout("gpuz.out");
    if (gpuzout.open(QIODevice::ReadOnly)){QTextStream in(&gpuzout);while ( !in.atEnd() ){foo = in.readLine();if (foo.contains("<cardname>")) {foolist = foo.split(">");boo = foolist.at(1);boo.replace("</cardname","",Qt::CaseInsensitive);
    //SPECIAL CASES
    //ATI-AMD
    if (GPU_VendorID.at(i)=="1002"){
        if (GPU_DeviceID.at(i)=="4E4A"){      boo = "Radeon 9800 XXL";}
        if (GPU_DeviceID.at(i)=="6658"){      boo = "Radeon R9 260X";}
        if (GPU_DeviceID.at(i)=="665C"){      boo = "Radeon HD 7790";
            if (GPU_SubsysID.at(i)=="2932"){boo = "Radeon HD 8770";}
            if (GPU_SubsysID.at(i)=="8770"){boo = "Radeon HD 8770";}}
        if (GPU_DeviceID.at(i)=="6718"){      boo = "Radeon HD 6970";}
        if (GPU_DeviceID.at(i)=="6740"){      boo = "Radeon HD 6730M";}
        if (GPU_DeviceID.at(i)=="6741"){      boo = "Radeon HD 6750M";}
        if (GPU_DeviceID.at(i)=="67B1"){      boo = "Radeon R9 290";}
        if (GPU_DeviceID.at(i)=="6798"){      boo = "Radeon HD 7990";//not sure!
            if (GPU_SubsysID.at(i)=="0B00"){boo = "Radeon HD 7970";}//MSI
            if (GPU_SubsysID.at(i)=="2770"){boo = "Radeon HD 7970";}//MSI
            if (GPU_SubsysID.at(i)=="2774"){boo = "Radeon HD 7970 Twin Frozr III";}//MSI
            if (GPU_SubsysID.at(i)=="2780"){boo = "Radeon HD 7970 Lightning";}//MSI
            if (GPU_SubsysID.at(i)=="3000"){boo = "Radeon HD 7970";}//also used by MSI Lightning BE
            if (GPU_SubsysID.at(i)=="3001"){boo = "Radeon R9 280X";}
            if (GPU_SubsysID.at(i)=="4000"){boo = "Radeon HD 8970";}
            if (GPU_SubsysID.at(i)=="9999"){boo = "ARES II";}}
        if (GPU_DeviceID.at(i)=="679A"){
            if (GPU_SubsysID.at(i)=="0B01"){boo = "Radeon HD 8950M OEM";}
            if (GPU_SubsysID.at(i)=="3000"){boo = "Radeon HD 8950";}
            if (GPU_SubsysID.at(i)=="0428"){boo = "Radeon HD 7950";}}
        if (GPU_DeviceID.at(i)=="679B"){
            if (GPU_SubsysID.at(i)=="0B28"){boo = "Radeon HD 8990";}//not sure why there are 2 ids for same card
            if (GPU_SubsysID.at(i)=="8036"){boo = "Radeon HD 8990";}}
        if (GPU_DeviceID.at(i)=="67B0"){      boo = "Radeon R9 290X";}
        if (GPU_DeviceID.at(i)=="6800"){      boo = "Radeon HD 7970M";}
        if (GPU_DeviceID.at(i)=="6810"){      boo = "Radeon R9 270X";}
        if (GPU_DeviceID.at(i)=="6899"){
            if (GPU_SubsysID.at(i)=="174B"){boo = "Radeon HD 5850";}}
        if (GPU_DeviceID.at(i)=="689C"){      boo = "Radeon HD 5970";
            if (GPU_SubsysID.at(i)=="0352"){boo = "ARES";}
            if (GPU_SubsysID.at(i)=="039E"){boo = "Radeon HD 5870";}}
        if (GPU_DeviceID.at(i)=="68BA"){
            if (GPU_SubsysID.at(i)=="E144"){boo = "Radeon HD 6770";}}
        if (GPU_DeviceID.at(i)=="68BE"){      boo = "Radeon HD 6750";}
        if (GPU_DeviceID.at(i)=="68BF"){      boo = "Radeon HD 6770 Green";}

        boo.replace("ATI","",Qt::CaseSensitive);
        boo.replace("AMD","",Qt::CaseInsensitive);

    }
    //NVIDIA
    if (GPU_VendorID.at(i)=="10DE"){
        boo.replace("NVIDIA","",Qt::CaseInsensitive);
        if (GPU_DeviceID.at(i)=="1080"){      boo = "GeForce GTX 580";}
        if (GPU_DeviceID.at(i)=="108B"){      boo = "MARS II";}

    }
    //Intel
    if (GPU_VendorID.at(i)=="8086"){
        boo.replace("Intel(R) HD","HD",Qt::CaseInsensitive);
        boo.replace("Mobile Intel(R) 4 Series Express Chipset Family","GMA 4500MHD (GM45, GS45)",Qt::CaseInsensitive);
        boo.replace("Intel(R) G45/G43 Express Chipset","GMA 4500 (B43, Q43, Q45)",Qt::CaseInsensitive);
        boo.replace("Intel(R) G41 Express Chipset","GMA X4500 (G43, G41)",Qt::CaseInsensitive);
        boo.replace("Mobile Intel® 915GM/GMS, 910GML Express Chipset Family","GMA 900 Mobile (915GM)",Qt::CaseInsensitive);
        boo.replace("Intel(R) 82915G/GV/910GL Express Chipset Family","GMA 900 (915G)",Qt::CaseInsensitive);
        boo.replace("Intel(R) Graphics Media Accelerator 500","GMA 500 (UL11L, US15L, US15W)",Qt::CaseInsensitive);

    }
    resultlist << boo;
    i += 1;
    }}}

    gpuzout.close();
    result.simplified();result.trimmed();
    for(i=0; i<resultlist.count();i++){result.append(resultlist.at(i));if (i > -1 && i < resultlist.count()-1){result.append("|");}}
    //Trim
    result.replace("| ","|", Qt::CaseInsensitive);
    result.replace(" | ","|", Qt::CaseInsensitive);
    result.replace("  ","", Qt::CaseInsensitive);
    result.replace("Graphics Adapter","",Qt::CaseInsensitive);//firegl cards
    result.replace("Graphics","",Qt::CaseInsensitive);//HD6-8 cards
    result.replace("Virtual PC Integration Components","",Qt::CaseInsensitive);//HD6-8 cards
    result.replace("EAH","",Qt::CaseSensitive);//ASUS

    //
    result.simplified();
    result = result.trimmed();
    return result;
}

