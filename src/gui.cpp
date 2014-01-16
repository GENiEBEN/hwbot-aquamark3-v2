#include "gui.h"
#include "ui_gui.h"
#include "sysinfo.h"
#include "security.h"
#include "aquamark3.h"
#include "functions.h"
#include "hwbotapi.h"
#include "QPixmap"
#include <QWidget>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QDir>
#include <QDirIterator>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QDebug>
#include <iostream>
#include <QListView>
#include <QDesktopServices>
#include <QStandardPaths>
#include <QProcess>
#include <Windows.h>
#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <QFileDialog>
#include <QBuffer>
#include <QDesktopWidget>
#include <QScreen>
#include <QSettings>
#include <QUrl>
#include <QStyleFactory>
#include <QByteArray>
#include <QTreeWidget>


void SetTheme(QString name){
    if (name == "Fusion (Dark)"){
        qApp->setStyle(QStyleFactory::create("Fusion"));
        QPalette darkPalette;
        darkPalette.setColor(QPalette::Window, QColor(53,53,53));
        darkPalette.setColor(QPalette::WindowText, Qt::white);
        darkPalette.setColor(QPalette::Base, QColor(25,25,25));
        darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
        darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
        darkPalette.setColor(QPalette::ToolTipText, Qt::white);
        darkPalette.setColor(QPalette::Text, Qt::white);
        darkPalette.setColor(QPalette::Button, QColor(53,53,53));
        darkPalette.setColor(QPalette::ButtonText, Qt::white);
        darkPalette.setColor(QPalette::BrightText, Qt::red);
        darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
        darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        darkPalette.setColor(QPalette::HighlightedText, Qt::black);
        qApp->setPalette(darkPalette);
        qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
    } else {
        qApp->setPalette(qApp->style()->standardPalette());
        qApp->setStyleSheet(" ");
        qApp->setStyle(name);
    }
}

frmMain::frmMain(QWidget *parent) : QMainWindow(parent), ui(new Ui::frmMain)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);

    QString foo; QStringList foolist;

    //Read settings from registry
    QSettings settings("GENiEBEN", "Aquamark3 Wrapper");
    if (settings.value("Background").toString()!=""){
        QPalette* palette = new QPalette();
        palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap(settings.value("Background").toString())))));
        setPalette(*palette);
    }
    WriteLog("background set");
    ui->cbProcessPrio->setCurrentText(settings.value("ProcessPrio").toString());
    ui->lblLODVal->setText(settings.value("LOD").toString());
    ui->dial->setValue(settings.value("LOD").toInt() * 4);
    ui->cbHideError->setCurrentText(settings.value("HideError").toString());
    ui->cbHideLogo->setCurrentText(settings.value("HideLogo").toString());
    ui->cbOSD->setCurrentText(settings.value("OSDStats").toString());
    ui->cbRunMode->setCurrentText(settings.value("RunMode").toString().toUpper());
    ui->cbSIenabled->setCurrentText(settings.value("SystemInfo").toString());
    //ui->cbTheme->addItems(QStyleFactory::keys());//add all Themes
    //ui->cbTheme->addItem("Fusion (Dark)");
    ui->cbTheme->setCurrentText(settings.value("Theme").toString());
    ui->slider_SSQuality->setValue(settings.value("SS_Quality").toInt());
    ui->dial->setValue(SYSINFO_GFX_GetLevelOfDetail_AMD().toInt() * 4);

    //Find number of available cpu threads
    WriteLog("ideal thread count: " + SYSINFO_CPU_THREADCOUNT() );

    //Disable checkboxes that are not needed
    QList<QCheckBox *> lstCheckboxes = ui->frame->findChildren<QCheckBox *>();
    for (int i=0; i < lstCheckboxes.count(); i++){
        if ( i < SYSINFO_CPU_THREADCOUNT().toInt() ){
            lstCheckboxes[i]->setChecked(true);
            foo = settings.value(QString::number(i+1)).toString();//check which cores were used by user previously
            if (foo.toLower() == "false"){ lstCheckboxes[i]->setChecked(false);;}//select the ones user previously used
        } else {
            lstCheckboxes[i]->setEnabled(false);
        }
    }
    WriteLog("settings read and applied");

    //Detect hardware configuration (only if user enabled SYSTEM INFO in settings tab)
    if (ui->cbSIenabled->currentText().toLower()=="enabled"){
        WriteLog("systeminfo is enabled");
        WriteLog("dxdiag launched: " + QString::number(_rundxdiag()) );
        //CPU Info
        ui->lblCPU_Name->setText(QString("%1x %2")
                                 .arg( SYSINFO_CPU_COUNT() )
                                 .arg( SYSINFO_CPU_NAME() )
                                 );
        ui->lblCPU_Speed->setText(QString("%1T @ %2, Bus %3, %4")
                                  .arg( SYSINFO_CPU_THREADCOUNT() )
                                  .arg( SYSINFO_CPU_SPEED_NOW() )
                                  .arg( SYSINFO_CPU_SPEED_EXTCLK() )
                                  .arg( SYSINFO_CPU_VOLTAGE() )
                                  );
        foo = SYSINFO_CPU_SOCKET_NAME();
        if (!foo.contains("Socket") || !foo.contains("Slot")) { foo = SYSINFO_CPU_SOCKET_UPGRADE(); }
        ui->lblCPU_Socket->setText(QString("%1, %2 Family")
                                   .arg( foo )
                                   .arg( SYSINFO_CPU_FAMILY_NAME() )
                                   );
        //Motherboard Info
        ui->lblMB_Name->setText(QString("%1P %2 %3")
                                .arg( SYSINFO_MOBO_SOCKET_COUNT() )
                                .arg( SYSINFO_MOBO_VENDOR() )
                                .arg( SYSINFO_MOBO_NAME() )
                                );
        ui->lblMB_Bios->setText(QString("%1 BIOS %2, %3, Rev %4")
                                .arg( SYSINFO_BIOS_IS_UEFI() )
                                .arg( SYSINFO_BIOS_VERSION() )
                                .arg( SYSINFO_BIOS_DATE() )
                                .arg( SYSINFO_BIOS_REVISION() )
                                );
        ui->lblMB_SN->setText(QString("S/N %1, Fw %2")
                              .arg( SYSINFO_MOBO_SERIALNUMBER() )
                              .arg( SYSINFO_BIOS_FIRMWARE_REVISION() )
                              );
        //Memory Info
        ui->lblRAM_Name->setText(QString("%1x %2")
                                 .arg( SYSINFO_RAM_MODULECOUNT() )
                                 .arg( SYSINFO_RAM_VENDOR() )
                                 );
        ui->lblRAM_PN->setText(QString("%1")
                               .arg( SYSINFO_RAM_PARTNUMBER() )
                               );
        foolist.clear(); foolist << SYSINFO_RAM_CONFIGUREDSPEED() << SYSINFO_RAM_RATEDSPEED();
        if ( foolist.at(0)==" MHz" || foolist.at(0).toLower()=="unknown"){
            foo = QString("rated %1").arg( foolist.at(1) );
        } else {
            foo = QString("at %1").arg( foolist.at(0) );
        }
        ui->lblRAM_Size->setText(QString("%1 %2 %3 %4")
                                 .arg( SYSINFO_RAM_INSTALLEDSIZE() )
                                 .arg( SYSINFO_RAM_TYPE() )
                                 .arg( SYSINFO_RAM_FORMFACTOR() )
                                 .arg( foo )
                                 );
        //VideoCard Info
        if(_rungpuz()==true){
            WriteLog("gpuz dump result: 1");
            ui->lblGFX_Name->setText(QString("%1x %2 %3")
                                     .arg( SYSINFO_GFX_COUNT() )
                                     .arg( SYSINFO_GFX_INTEGRATOR_NAME() )
                                     .arg( SYSINFO_GFX_NAME() )
                                     );
            if (SYSINFO_GFX_SPEED_SHADER()==""){//if gpu has unified shaders
                foo = QString("%1/%2")
                        .arg(SYSINFO_GFX_SPEED_CORE())
                        .arg(SYSINFO_GFX_SPEED_RAM());//speed is CORE/RAM
            } else {
                foo = QString("%1/%2/%3")
                        .arg( SYSINFO_GFX_SPEED_CORE() )
                        .arg( SYSINFO_GFX_SPEED_SHADER() )
                        .arg( SYSINFO_GFX_SPEED_RAM() );//speed is CORE/SHADER/RAM
            }//TODO: Add support for cards with BOOST clocks
            ui->lblGFX_Speed->setText(QString("%1 %2 %3b %4")
                                      .arg( SYSINFO_GFX_RAM_SIZE() )
                                      .arg( SYSINFO_GFX_RAM_TYPE() )
                                      .arg( SYSINFO_GFX_RAM_BUSWIDTH() )
                                      .arg( foo )
                                      );
            ui->lblOS_ExtraInfo->setText(QString("%1 (%2,%3)")
                                         .arg( SYSINFO_GFX_DRIVER_NAME() )
                                         .arg( SYSINFO_GFX_DRIVER_VERSION() )
                                         .arg( SYSINFO_GFX_DRIVER_DATE() )
                                         );
        } else { WriteLog("gpuz dump result: 0");}
        //OS Info
        foo = SYSINFO_OS_SP();
        if (foo==""){
            ui->lblOS_Name->setText(QString("%1 %2-bits")
                                    .arg( SYSINFO_OS_NAME() )
                                    .arg( SYSINFO_OS_BITS() )
                                    );
        } else {
            ui->lblOS_Name->setText(QString("%1 %2 %3-bits")
                                    .arg( SYSINFO_OS_NAME() )
                                    .arg( foo )
                                    .arg( SYSINFO_OS_BITS() )
                                    );
        }
        ui->lblOS_DX->setText( SYSINFO_GFX_DXVERSION() );
        ui->lblGFX_Driver->setText( SYSINFO_GFX_OUTPUTPORTS() );
        WriteLog("systeminfo displayed in gui");
    } else {
        WriteLog("systeminfo is disabled");
        ui->stackedWidget->setCurrentIndex(1);
    }
}

frmMain::~frmMain(){ delete ui; }

void frmMain::on_btnStart_clicked()
{
    QString foo; QStringList foolist;QMessageBox msgBox;
    QSettings settings("GENiEBEN", "Aquamark3 Wrapper");
    //Check integrity of benchmark executable
    bool valid_score = true;
    valid_score = _checkfile(qApp->property("Benchmark_Exe_Path").toString(),sauce1());
    WriteLog("sauce 1: " + QString::number(valid_score) );
    //Check integrity of data0.pak
    valid_score = _checkfile(qApp->property("Benchmark_Pak0_Path").toString(),sauce2());
    WriteLog("sauce 2: " + QString::number(valid_score) );
    //Check integrity of data1.pak
    valid_score = _checkfile(qApp->property("Benchmark_Pak1_Path").toString(),sauce3());
    WriteLog("sauce 3: " + QString::number(valid_score) );

    if (_clearmydocs()!=true){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Clearing Benchmark's Logs");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Benchmark's logs folder could not be deleted.\nPlease close all Explorer windows.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }

    //Check what settings user selected so we can start the benchmark with proper cmd arguments.
    QProcess benchmark; QStringList args;
    QString arg1; if(ui->cbHideLogo->currentText().toLower()=="true")   { arg1 = "-nologo"; WriteLog("-nologo"); }
    QString arg2; if(ui->cbOSD->currentText().toLower()=="true")        { arg2 = "-statistics"; WriteLog("-statistics"); }
    QString arg3; if(ui->cbHideError->currentText().toLower()=="true")  { arg3 = "-noreset"; WriteLog("-noreset"); }

    //Continue based on RunMode: AUTO/MANUAL
    QDir mydocs; mydocs.setPath(qApp->property("Benchmark_My_Docs_Folder").toString());

    if (ui->cbRunMode->currentText().toLower()=="auto"){
        //Set starting arguments for benchmark
        args << "-bench" << mydocs.absolutePath() + "\\Run.txt" << arg1 << arg2 << arg3;
        WriteLog("will run in auto mode");
        //Create license file
        if ( Aquamark3_WriteLicenseFile()==true){
            WriteLog("license file created");
        } else {
            WriteLog("failed writing license file");
        }
        //Create benchmark batch run file
        if ( Aquamark3_WriteConfigFile()==true){
            WriteLog("autosettings created");
        } else {
            WriteLog("failed writing autosettings");
        }
    } else {
        args << arg1 << arg2 << arg3;
        WriteLog("will run in manual mode");
    }
    //TODO: kill benchmark.exe if it already exists

    //Start benchmark
    benchmark.setWorkingDirectory(qApp->property("Benchmark_Install_Path").toString() + "\\benchmark");
    WriteLog("working dir set at: " + benchmark.workingDirectory() );

    WriteLog("process priority: " + ui->cbProcessPrio->currentText() );
    benchmark.start(qApp->property("Benchmark_Exe_Path").toString(), args);
    WriteLog("benchmark started: " + qApp->property("Benchmark_Exe_Path").toString() );

    //Set Affinity based on user selected settings.
    DWORD64 processAffinityMask;
    DWORD64 Core01 = 0;DWORD64 Core02 = 0;DWORD64 Core03 = 0;DWORD64 Core04 = 0;
    DWORD64 Core05 = 0;DWORD64 Core06 = 0;DWORD64 Core07 = 0;DWORD64 Core08 = 0;
    DWORD64 Core09 = 0;DWORD64 Core10 = 0;DWORD64 Core11 = 0;DWORD64 Core12 = 0;
    DWORD64 Core13 = 0;DWORD64 Core14 = 0;DWORD64 Core62 = 0;DWORD64 Core63 = 0;
    DWORD64 Core15 = 0;DWORD64 Core16 = 0;DWORD64 Core17 = 0;DWORD64 Core18 = 0;
    DWORD64 Core19 = 0;DWORD64 Core20 = 0;DWORD64 Core21 = 0;DWORD64 Core22 = 0;
    DWORD64 Core23 = 0;DWORD64 Core24 = 0;DWORD64 Core25 = 0;DWORD64 Core26 = 0;
    DWORD64 Core27 = 0;DWORD64 Core28 = 0;DWORD64 Core29 = 0;DWORD64 Core30 = 0;
    DWORD64 Core31 = 0;DWORD64 Core32 = 0;DWORD64 Core33 = 0;DWORD64 Core34 = 0;
    DWORD64 Core35 = 0;DWORD64 Core36 = 0;DWORD64 Core37 = 0;DWORD64 Core38 = 0;
    DWORD64 Core39 = 0;DWORD64 Core40 = 0;DWORD64 Core41 = 0;DWORD64 Core64 = 0;
    DWORD64 Core42 = 0;DWORD64 Core43 = 0;DWORD64 Core44 = 0;DWORD64 Core45 = 0;
    DWORD64 Core46 = 0;DWORD64 Core47 = 0;DWORD64 Core48 = 0;DWORD64 Core49 = 0;
    DWORD64 Core50 = 0;DWORD64 Core51 = 0;DWORD64 Core52 = 0;DWORD64 Core53 = 0;
    DWORD64 Core54 = 0;DWORD64 Core55 = 0;DWORD64 Core56 = 0;DWORD64 Core57 = 0;
    DWORD64 Core58 = 0;DWORD64 Core59 = 0;DWORD64 Core60 = 0;DWORD64 Core61 = 0;

    if (ui->ckbCore01->isChecked()==1) { Core01 = 1; WriteLog("affinity selected: core 1"); settings.setValue("1","true"); } else { settings.setValue("1","false"); }
    if (ui->ckbCore02->isChecked()==1) { Core02 = 2; WriteLog("affinity selected: core 2"); settings.setValue("2","true"); } else { settings.setValue("2","false"); }
    if (ui->ckbCore03->isChecked()==1) { Core03 = 4; WriteLog("affinity selected: core 3"); settings.setValue("3","true"); } else { settings.setValue("3","false"); }
    if (ui->ckbCore04->isChecked()==1) { Core04 = 8; WriteLog("affinity selected: core 4"); settings.setValue("4","true"); } else { settings.setValue("4","false"); }
    if (ui->ckbCore05->isChecked()==1) { Core05 = 16; WriteLog("affinity selected: core 5"); settings.setValue("5","true"); } else { settings.setValue("5","false"); }
    if (ui->ckbCore06->isChecked()==1) { Core06 = 32; WriteLog("affinity selected: core 6"); settings.setValue("6","true"); } else { settings.setValue("6","false"); }
    if (ui->ckbCore07->isChecked()==1) { Core07 = 64; WriteLog("affinity selected: core 7"); settings.setValue("7","true"); } else { settings.setValue("7","false"); }
    if (ui->ckbCore08->isChecked()==1) { Core08 = 128; WriteLog("affinity selected: core 8"); settings.setValue("8","true"); } else { settings.setValue("8","false"); }
    if (ui->ckbCore09->isChecked()==1) { Core09 = 256; WriteLog("affinity selected: core 9"); settings.setValue("9","true"); } else { settings.setValue("9","false"); }
    if (ui->ckbCore10->isChecked()==1) { Core10 = 512; WriteLog("affinity selected: core 10"); settings.setValue("10","true"); } else { settings.setValue("10","false"); }
    if (ui->ckbCore11->isChecked()==1) { Core11 = 1024; WriteLog("affinity selected: core 11"); settings.setValue("11","true"); } else { settings.setValue("11","false"); }
    if (ui->ckbCore12->isChecked()==1) { Core12 = 2048; WriteLog("affinity selected: core 12"); settings.setValue("12","true"); } else { settings.setValue("12","false"); }
    if (ui->ckbCore13->isChecked()==1) { Core13 = 4096; WriteLog("affinity selected: core 13"); settings.setValue("13","true"); } else { settings.setValue("13","false"); }
    if (ui->ckbCore14->isChecked()==1) { Core14 = 8092; WriteLog("affinity selected: core 14"); settings.setValue("14","true"); } else { settings.setValue("14","false"); }
    if (ui->ckbCore15->isChecked()==1) { Core15 = 16184; WriteLog("affinity selected: core 15"); settings.setValue("15","true"); } else { settings.setValue("15","false"); }
    if (ui->ckbCore16->isChecked()==1) { Core16 = 32368; WriteLog("affinity selected: core 16"); settings.setValue("16","true"); } else { settings.setValue("16","false"); }
    if (ui->ckbCore17->isChecked()==1) { Core17 = 64736; WriteLog("affinity selected: core 17"); settings.setValue("17","true"); } else { settings.setValue("17","false"); }
    if (ui->ckbCore18->isChecked()==1) { Core18 = 129472; WriteLog("affinity selected: core 18"); settings.setValue("18","true"); } else { settings.setValue("18","false"); }
    if (ui->ckbCore19->isChecked()==1) { Core19 = 258944; WriteLog("affinity selected: core 19"); settings.setValue("19","true"); } else { settings.setValue("19","false"); }
    if (ui->ckbCore20->isChecked()==1) { Core20 = 517888; WriteLog("affinity selected: core 20"); settings.setValue("20","true"); } else { settings.setValue("20","false"); }
    if (ui->ckbCore21->isChecked()==1) { Core21 = 1035776; WriteLog("affinity selected: core 21"); settings.setValue("21","true"); } else { settings.setValue("21","false"); }
    if (ui->ckbCore22->isChecked()==1) { Core22 = 2071552; WriteLog("affinity selected: core 22"); settings.setValue("22","true"); } else { settings.setValue("22","false"); }
    if (ui->ckbCore23->isChecked()==1) { Core23 = 4143104; WriteLog("affinity selected: core 23"); settings.setValue("23","true"); } else { settings.setValue("23","false"); }
    if (ui->ckbCore24->isChecked()==1) { Core24 = 8286208; WriteLog("affinity selected: core 24"); settings.setValue("24","true"); } else { settings.setValue("24","false"); }
    if (ui->ckbCore25->isChecked()==1) { Core25 = 16572416; WriteLog("affinity selected: core 25"); settings.setValue("25","true"); } else { settings.setValue("25","false"); }
    if (ui->ckbCore26->isChecked()==1) { Core26 = 33144832; WriteLog("affinity selected: core 26"); settings.setValue("26","true"); } else { settings.setValue("26","false"); }
    if (ui->ckbCore27->isChecked()==1) { Core27 = 66289664; WriteLog("affinity selected: core 27"); settings.setValue("27","true"); } else { settings.setValue("27","false"); }
    if (ui->ckbCore28->isChecked()==1) { Core28 = 132579328; WriteLog("affinity selected: core 28"); settings.setValue("28","true"); } else { settings.setValue("28","false"); }
    if (ui->ckbCore29->isChecked()==1) { Core29 = 265158656; WriteLog("affinity selected: core 29"); settings.setValue("29","true"); } else { settings.setValue("29","false"); }
    if (ui->ckbCore30->isChecked()==1) { Core30 = 530317312; WriteLog("affinity selected: core 30"); settings.setValue("30","true"); } else { settings.setValue("30","false"); }
    if (ui->ckbCore31->isChecked()==1) { Core31 = 1060634624; WriteLog("affinity selected: core 31"); settings.setValue("31","true"); } else { settings.setValue("31","false"); }
    if (ui->ckbCore32->isChecked()==1) { Core32 = 2121269248; WriteLog("affinity selected: core 32"); settings.setValue("32","true"); } else { settings.setValue("32","false"); }
    if (ui->ckbCore33->isChecked()==1) { Core33 = 4242538496; WriteLog("affinity selected: core 33"); settings.setValue("33","true"); } else { settings.setValue("33","false"); }
    if (ui->ckbCore34->isChecked()==1) { Core34 = 8485076992; WriteLog("affinity selected: core 34"); settings.setValue("34","true"); } else { settings.setValue("34","false"); }
    if (ui->ckbCore35->isChecked()==1) { Core35 = 16970153984; WriteLog("affinity selected: core 35"); settings.setValue("35","true"); } else { settings.setValue("35","false"); }
    if (ui->ckbCore36->isChecked()==1) { Core36 = 33940307968; WriteLog("affinity selected: core 36"); settings.setValue("36","true"); } else { settings.setValue("36","false"); }
    if (ui->ckbCore37->isChecked()==1) { Core37 = 67880615936; WriteLog("affinity selected: core 37"); settings.setValue("37","true"); } else { settings.setValue("37","false"); }
    if (ui->ckbCore38->isChecked()==1) { Core38 = 135761231872; WriteLog("affinity selected: core 38"); settings.setValue("38","true"); } else { settings.setValue("38","false"); }
    if (ui->ckbCore39->isChecked()==1) { Core39 = 271522463744; WriteLog("affinity selected: core 39"); settings.setValue("39","true"); } else { settings.setValue("39","false"); }
    if (ui->ckbCore40->isChecked()==1) { Core40 = 543044927488; WriteLog("affinity selected: core 40"); settings.setValue("40","true"); } else { settings.setValue("40","false"); }
    if (ui->ckbCore41->isChecked()==1) { Core41 = 1086089854976; WriteLog("affinity selected: core 41"); settings.setValue("41","true"); } else { settings.setValue("41","false"); }
    if (ui->ckbCore42->isChecked()==1) { Core42 = 2172179709952; WriteLog("affinity selected: core 42"); settings.setValue("42","true"); } else { settings.setValue("42","false"); }
    if (ui->ckbCore43->isChecked()==1) { Core43 = 4344359419904; WriteLog("affinity selected: core 43"); settings.setValue("43","true"); } else { settings.setValue("43","false"); }
    if (ui->ckbCore44->isChecked()==1) { Core44 = 8688718839808; WriteLog("affinity selected: core 44"); settings.setValue("44","true"); } else { settings.setValue("44","false"); }
    if (ui->ckbCore45->isChecked()==1) { Core45 = 17377437679616; WriteLog("affinity selected: core 45"); settings.setValue("45","true"); } else { settings.setValue("45","false"); }
    if (ui->ckbCore46->isChecked()==1) { Core46 = 34754875359232; WriteLog("affinity selected: core 46"); settings.setValue("46","true"); } else { settings.setValue("46","false"); }
    if (ui->ckbCore47->isChecked()==1) { Core47 = 69509750718464; WriteLog("affinity selected: core 47"); settings.setValue("47","true"); } else { settings.setValue("47","false"); }
    if (ui->ckbCore48->isChecked()==1) { Core48 = 139019501436928; WriteLog("affinity selected: core 48"); settings.setValue("48","true"); } else { settings.setValue("48","false"); }
    if (ui->ckbCore49->isChecked()==1) { Core49 = 278039002873856; WriteLog("affinity selected: core 49"); settings.setValue("49","true"); } else { settings.setValue("49","false"); }
    if (ui->ckbCore50->isChecked()==1) { Core50 = 556078005747712; WriteLog("affinity selected: core 50"); settings.setValue("50","true"); } else { settings.setValue("50","false"); }
    if (ui->ckbCore51->isChecked()==1) { Core51 = 1112156011495424; WriteLog("affinity selected: core 51"); settings.setValue("51","true"); } else { settings.setValue("51","false"); }
    if (ui->ckbCore52->isChecked()==1) { Core52 = 2224312022990848; WriteLog("affinity selected: core 52"); settings.setValue("52","true"); } else { settings.setValue("52","false"); }
    if (ui->ckbCore53->isChecked()==1) { Core53 = 4448624045981696; WriteLog("affinity selected: core 53"); settings.setValue("53","true"); } else { settings.setValue("53","false"); }
    if (ui->ckbCore54->isChecked()==1) { Core54 = 8897248091963392; WriteLog("affinity selected: core 54"); settings.setValue("54","true"); } else { settings.setValue("54","false"); }
    if (ui->ckbCore55->isChecked()==1) { Core55 = 17794496183926784; WriteLog("affinity selected: core 55"); settings.setValue("55","true"); } else { settings.setValue("55","false"); }
    if (ui->ckbCore56->isChecked()==1) { Core56 = 35588992367853568; WriteLog("affinity selected: core 56"); settings.setValue("56","true"); } else { settings.setValue("56","false"); }
    if (ui->ckbCore57->isChecked()==1) { Core57 = 71177984735707136; WriteLog("affinity selected: core 57"); settings.setValue("57","true"); } else { settings.setValue("57","false"); }
    if (ui->ckbCore58->isChecked()==1) { Core58 = 142355969471414272; WriteLog("affinity selected: core 58"); settings.setValue("58","true"); } else { settings.setValue("58","false"); }
    if (ui->ckbCore59->isChecked()==1) { Core59 = 284711938942828544; WriteLog("affinity selected: core 59"); settings.setValue("59","true"); } else { settings.setValue("59","false"); }
    if (ui->ckbCore60->isChecked()==1) { Core60 = 569423877885657088; WriteLog("affinity selected: core 60"); settings.setValue("60","true"); } else { settings.setValue("60","false"); }
    if (ui->ckbCore61->isChecked()==1) { Core61 = 1138847755771314176; WriteLog("affinity selected: core 61"); settings.setValue("61","true"); } else { settings.setValue("62","false"); }
    if (ui->ckbCore62->isChecked()==1) { Core62 = 2277695511542628352; WriteLog("affinity selected: core 62"); settings.setValue("62","true"); } else { settings.setValue("62","false"); }
    if (ui->ckbCore63->isChecked()==1) { Core63 = 4555391023085256704; WriteLog("affinity selected: core 63"); settings.setValue("63","true"); } else { settings.setValue("63","false"); }
    if (ui->ckbCore64->isChecked()==1) { Core64 = 9110782046170513408; WriteLog("affinity selected: core 64"); settings.setValue("64","true"); } else { settings.setValue("64","false"); }

    processAffinityMask = Core01+Core02+Core03+Core04+Core05+Core06+Core07+Core08+Core09+Core10+Core11+Core12+Core13+Core14+Core15+Core16+Core17+Core18+Core18+Core19+Core20+Core21+Core22+Core23+Core24+Core25+Core26+Core27+Core28+Core29+Core30+Core31+Core32+Core33+Core34+Core35+Core36+Core37+Core38+Core39+Core40+Core41+Core42+Core43+Core44+Core45+Core46+Core47+Core48+Core49+Core50+Core51+Core52+Core53+Core54+Core55+Core56+Core57+Core58+Core59+Core60+Core61+Core62+Core63+Core64;
    bool affinityApplied = SetProcessAffinityMask(benchmark.pid()->hProcess, processAffinityMask);
    WriteLog("affinity applied: " +  QString::number(affinityApplied) );

    //Set process priority
    DWORD PriorityType;
    switch (ui->cbProcessPrio->currentIndex()) {
    case 0:
        PriorityType = IDLE_PRIORITY_CLASS;
        break;
    case 1:
        PriorityType = BELOW_NORMAL_PRIORITY_CLASS;
        break;
    case 2:
        PriorityType = NORMAL_PRIORITY_CLASS;
        break;
    case 3:
        PriorityType = ABOVE_NORMAL_PRIORITY_CLASS;
        break;
    case 4:
        PriorityType = HIGH_PRIORITY_CLASS;
        break;
    case 5:
        PriorityType = REALTIME_PRIORITY_CLASS;
        break;
    default:
        PriorityType = HIGH_PRIORITY_CLASS;
        break;
    }
    WriteLog("priority selected: " +  ui->cbProcessPrio->currentText().toLower() );
    WriteLog("priority applied: " + QString::number( SetPriorityClass(benchmark.pid()->hProcess, PriorityType) ) );

    //Wait for it to finish
    benchmark.waitForFinished(-1);
    benchmark.close();
    WriteLog("benchmark closed");

    //Find the application output
    QString Benchmark_Summary_Path;
    QString Benchmark_Details_Path;
    QDirIterator search(mydocs.absolutePath(),QDirIterator::Subdirectories);

    WriteLog("browsing benchmark logs:");
    while (search.hasNext()) {
        search.next();
        WriteLog(search.filePath());
        if (QFileInfo(search.filePath()).isFile())
            if (search.filePath().contains("Summary")){
                Benchmark_Summary_Path=search.filePath();
                WriteLog("summary file found");
            }
            if (search.filePath().contains("Details Pass 01")){
                Benchmark_Details_Path=search.filePath();
                WriteLog("details file found");
            }
    }
    //Check if it was ran at default settings
    if ( Aquamark3_RanAtDefaultSettings(Benchmark_Details_Path)==true ){
        //Read Total/CPU/GFX scores
        foolist = Aquamark3_ReadScore(Benchmark_Summary_Path);
        if (foolist.at(0) !="0"){
            ui->lcdTriscore->display("0");ui->lcdTriscore->display(foolist.at(0));
            WriteLog("triscore: " + foolist.at(0) );
            ui->lcdGFX->display("0"); ui->lcdGFX->display(foolist.at(1));
            WriteLog("graphics: " + foolist.at(1) );
            ui->lcdCPU->display("0"); ui->lcdCPU->display(foolist.at(2));
            WriteLog("processor: " + foolist.at(2) );
        } else {
            WriteLog("summary file not found");
        }
        //Read Chapter Scores
        foolist = Aquamark3_ReadChapters(Benchmark_Details_Path);
        if (foolist.at(0) != "0"){
            ui->lblScore_C1->setText(foolist.at(0));
            ui->lblScore_C2->setText(foolist.at(1));
            ui->lblScore_C3->setText(foolist.at(2));
            ui->lblScore_C4->setText(foolist.at(3));
            ui->lblScore_C5->setText(foolist.at(4));
            ui->lblScore_C6->setText(foolist.at(5));
            ui->lblScore_C7->setText(foolist.at(6));
            ui->lblScore_C8->setText(foolist.at(7));
            ui->lblScore_C9->setText(foolist.at(8));
            WriteLog("chapter1: " +  foolist.at(0));
            WriteLog("chapter2: " +  foolist.at(1));
            WriteLog("chapter3: " +  foolist.at(2));
            WriteLog("chapter4: " +  foolist.at(3));
            WriteLog("chapter5: " +  foolist.at(4));
            WriteLog("chapter6: " +  foolist.at(5));
            WriteLog("chapter7: " +  foolist.at(6));
            WriteLog("chapter8: " +  foolist.at(7));
            WriteLog("chapter9: " +  foolist.at(8));
        } else {
            WriteLog("details file not found");
        }

        WriteLog("printed scores to gui");
        ui->tabWidget->setCurrentIndex(0);
        //Generate Hash
        foo = "";
        foo.append(QString::number(ui->lcdTriscore->value()));
        foo.append("dont");
        foo.append(QString::number(ui->lcdGFX->value()));
        foo.append("crack");
        foo.append(QString::number(ui->lcdCPU->value()));
        foo.append("me");
        QString HashResult = _getshorthash(foo);
        ui->lblHash->setText(HashResult);
        WriteLog("generated score hash: " + HashResult);
    } else {
        ui->lblHash->setText("NON-DEFAULT SETTINGS");
    }
    //was the hashing ok?
    if (valid_score == false){
        ui->lblHash->setText("FILE INTEGRITY CHECK FAILED");
    }
}


void frmMain::on_btnSave_clicked()
{
    QString foo = qApp->property("Benchmark_Install_Path").toString();
    bool valid_score = true;
    //Check integrity of encryption tool
    valid_score = _checkfile(foo + "/benchmark/fmod.dll",sauce4());
    WriteLog("sauce 4: " + QString::number(valid_score) );
    valid_score = _checkfile(foo + "/libeay32.dll",sauce5());
    WriteLog("sauce 5: " + QString::number(valid_score) );
    valid_score = _checkfile(foo + "/ssleay32.dll",sauce6());
    WriteLog("sauce 6: " + QString::number(valid_score) );
    valid_score = _checkfile(foo + "/osl.dll",sauce7());
    WriteLog("sauce 7: " + QString::number(valid_score) );

    //was the hashing ok?
    if (valid_score == false){
        ui->lblHash->setText("FILE INTEGRITY CHECK FAILED");
    }

    //generate scorefile
    QStringList x;
    WriteLog("started creating scorefile");
    x << "<?xml version=\"1.0\"?>";
    x << "<submission xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns=\"http://hwbot.org/submit/api\">";
    x << "<application>";
    x << "<name>Aquamark</name>";
        x << "<version>" << APP_VERSION << "</version>";
    x << "</application>";
    x << "<score>";
        x << "<points>";
        x << QString::number(ui->lcdTriscore->value());
        x << "</points>";
        x << "<subscores>";
            x << "<subscore name=\"GFX\">";
            x << QString::number(ui->lcdGFX->value());
            x << "</subscore>";
            x << "<subscore name=\"CPU\">";
            x << QString::number(ui->lcdCPU->value());
            x << "</subscore>";
            x << "<subscore name=\"Chapter 1\">";
            if (ui->lblHash->text()!="-"){ x << ui->lblScore_C1->text(); } else { x << "0";  }
            x << "</subscore>";
            x << "<subscore name=\"Chapter 2\">";
            if (ui->lblHash->text()!="-"){ x << ui->lblScore_C2->text(); } else { x << "0";  }
            x << "</subscore>";
            x << "<subscore name=\"Chapter 3\">";
            if (ui->lblHash->text()!="-"){ x << ui->lblScore_C3->text(); } else { x << "0";  }
            x << "</subscore>";
            x << "<subscore name=\"Chapter 4\">";
            if (ui->lblHash->text()!="-"){ x << ui->lblScore_C4->text(); } else { x << "0";  }
            x << "</subscore>";
            x << "<subscore name=\"Chapter 5\">";
            if (ui->lblHash->text()!="-"){ x << ui->lblScore_C5->text(); } else { x << "0";  }
            x << "</subscore>";
            x << "<subscore name=\"Chapter 6\">";
            if (ui->lblHash->text()!="-"){ x << ui->lblScore_C6->text(); } else { x << "0";  }
            x << "</subscore>";
            x << "<subscore name=\"Chapter 7\">";
            if (ui->lblHash->text()!="-"){ x << ui->lblScore_C7->text(); } else { x << "0";  }
            x << "</subscore>";
            x << "<subscore name=\"Chapter 8\">";
            if (ui->lblHash->text()!="-"){ x << ui->lblScore_C8->text(); } else { x << "0";  }
            x << "</subscore>";
            x << "<subscore name=\"Chapter 9\">";
            if (ui->lblHash->text()!="-"){ x << ui->lblScore_C9->text(); } else { x << "0";  }
            x << "</subscore>";
        x << "</subscores>";
        x << "</score>";
    x << "<timestamp>";
    x << SYSINFO_OS_TIMESTAMP();
    x << "</timestamp>";
    x << "<verificationUrl>";
    x << "</verificationUrl>";
    x << "<applicationChecksum>";
    x << ui->lblHash->text();
    x << "</applicationChecksum>";
    foo = ui->cbScreenshotFormat->currentText();
    if (foo=="PNG"){ x << "<screenshot contentType=\"image/png\">"; }
    if (foo=="JPG"){ x << "<screenshot contentType=\"image/jpeg\">"; }
    qApp->beep();
    QPixmap pixmap;QScreen *screen = QGuiApplication::primaryScreen();
    if (screen){pixmap = screen->grabWindow(0);}//Qt4.8: pixmap = QPixmap::grabWindow(QApplication::desktop()->winId());
    QByteArray byteArray;QBuffer buffer(&byteArray);
    if (foo=="PNG"){ pixmap.save( &buffer,"PNG",ui->slider_SSQuality->value() ); }
    if (foo=="JPG"){ pixmap.save( &buffer,"JPG",ui->slider_SSQuality->value() ); }

    QFile screenshot(QString("screenshot.%1").arg(foo.toLower()));
    screenshot.open(QIODevice::WriteOnly);
    screenshot.write(byteArray);
    screenshot.close();

    WriteLog(QString("screenshot took: %1, quality %2").arg(foo).arg(QString::number(ui->slider_SSQuality->value())));
    x << byteArray.toBase64();
    x << "</screenshot>";
    x << "<hardware>";
        x << "<processor>";
            x << "<name>";
            if (ui->cbSIenabled->currentIndex()==0){
                QString cpu_name = SYSINFO_CPU_NAME();
                cpu_name.replace(cpu_name.split(" ").at(0),"",Qt::CaseInsensitive);//remove Vendor from product name
            x << cpu_name;
            }
            x << "</name>";
            x << "<amount>";
            if (ui->cbSIenabled->currentIndex()==0){
            x << SYSINFO_CPU_COUNT();
            }
            x << "</amount>";
            x << "<idleTemp>";
            x << "</idleTemp>";
            x << "<loadTemp>";
            x << "</loadTemp>";
            x << "<coreClock>";
            if (ui->cbSIenabled->currentIndex()==0){
                QString cpu_speed = SYSINFO_CPU_SPEED_NOW();
                cpu_speed.replace(" MHz","",Qt::CaseInsensitive);
                x << cpu_speed;
            }
            x << "</coreClock>";
            x << "<referenceClock>";
            if (ui->cbSIenabled->currentIndex()==0){
                QString cpu_bus = SYSINFO_CPU_SPEED_EXTCLK();
                cpu_bus.replace(" MHz","",Qt::CaseInsensitive);
                x << cpu_bus;
            }
            x << "</referenceClock>";
        x << "</processor>";
        x << "<videocard>";
            x << "<name>";
            if (ui->cbSIenabled->currentIndex()==0){
                QString gpu_name=SYSINFO_GFX_NAME();
                if (gpu_name.contains("|")){
                    QStringList gpu_name_l = gpu_name.split("|");
                    gpu_name = gpu_name_l.at(0);
                }
            x << gpu_name;
            }
            x << "</name>";
            x << "<vendor>";
            if (ui->cbSIenabled->currentIndex()==0){
                QString gpu_vendor=SYSINFO_GFX_INTEGRATOR_NAME();
                if (gpu_vendor.contains("|")){
                    QStringList gpu_vendor_l = gpu_vendor.split("|");
                    gpu_vendor = gpu_vendor_l.at(0);
                }
            x << gpu_vendor;
            }
            x << "</vendor>";
            x << "<amount>";
            if (ui->cbSIenabled->currentIndex()==0){
            x << SYSINFO_GFX_COUNT();
            }
            x << "</amount>";
            x << "<idleTemp>";
            x << "</idleTemp>";
            x << "<loadTemp>";
            x << "</loadTemp>";
            x << "<coreClock>";
            if (ui->cbSIenabled->currentIndex()==0){
                QString gpu_corespeed=SYSINFO_GFX_SPEED_CORE();
                if (gpu_corespeed.contains("|")){
                    QStringList gpu_corespeed_l = gpu_corespeed.split("|");
                    gpu_corespeed = gpu_corespeed_l.at(0);
                }
            x << gpu_corespeed;
            }
            x << "</coreClock>";
            x << "<gpuMemClock>";
            if (ui->cbSIenabled->currentIndex()==0){
                QString gpu_ramspeed=SYSINFO_GFX_SPEED_RAM();
                if (gpu_ramspeed.contains("|")){
                    QStringList gpu_ramspeed_l = gpu_ramspeed.split("|");
                    gpu_ramspeed = gpu_ramspeed_l.at(0);
                }
            x << gpu_ramspeed;
            }
            x << "</gpuMemClock>";
            _delgpuz();//delete gpuz's dump file
        x << "</videocard>";
        x << "<motherboard>";
            x << "<name>";
            if (ui->cbSIenabled->currentIndex()==0){
                QString moboname = SYSINFO_MOBO_NAME();
                if (moboname.contains(" ()")){ moboname.replace(" ()","", Qt::CaseInsensitive); }
                moboname.replace("HP","Hewlett-Packard",Qt::CaseInsensitive);
            x << moboname;
            }
            x << "</name>";
            x << "<vendor>";
            if (ui->cbSIenabled->currentIndex()==0){
            x << SYSINFO_MOBO_VENDOR();
            }
            x << "</vendor>";
            x << "<idleTemp>";
            x << "</idleTemp>";
            x << "<loadTemp>";
            x << "</loadTemp>";
            x << "<chipset>";
            x << "</chipset>";
        x << "</motherboard>";
        x << "<memory>";
            x << "<vendor>";
            if (ui->cbSIenabled->currentIndex()==0){
                QString ram_vendor=SYSINFO_RAM_VENDOR();
                if (ram_vendor.contains("|")){
                    QStringList ram_vendor_l = ram_vendor.split("|");
                    ram_vendor = ram_vendor_l.at(0);
                }
                ram_vendor.replace("Kingston", "Kingston Technology", Qt::CaseInsensitive);
            x << ram_vendor;
            }
            x << "</vendor>";
            x << "<idleTemp>";
            x << "</idleTemp>";
            x << "<loadTemp>";
            x << "</loadTemp>";
            x << "<type>";
            if (ui->cbSIenabled->currentIndex()==0){
                QString ram_type=SYSINFO_RAM_TYPE();
                if (ram_type.contains("|")){
                    QStringList ram_type_l = ram_type.split("|");
                    ram_type = ram_type_l.at(0);
                }
                if (ram_type=="DDR") { ram_type = "DDR SDRAM"; }
                if (ram_type=="DDR2"){ ram_type = "DDR2 SDRAM"; }
                if (ram_type=="DDR3"){ ram_type = "DDR3 SDRAM"; }

            x << ram_type;
            }
            x << "</type>";
            x << "<memoryClock>";
            x << "</memoryClock>";
            x << "<rating>";
            if (ui->cbSIenabled->currentIndex()==0){
                QString ram_speed=SYSINFO_RAM_RATEDSPEED();
                if (ram_speed.contains("|")){
                    QStringList ram_speed_l = ram_speed.split("|");
                    ram_speed = ram_speed_l.at(0);
                }
            x << ram_speed;
            }
            x << "</rating>";
            x << "<totalSize>";
            if (ui->cbSIenabled->currentIndex()==0){
                QString ram_size = SYSINFO_RAM_INSTALLEDSIZE();
                if (ram_size.contains("GB")){
                    ram_size.replace(" GB","",Qt::CaseInsensitive);//remove measuring unit
                    ram_size = QString::number(ram_size.toInt() * 1024);//Convert GB to MB
                } else {
                    ram_size.replace(" MB","",Qt::CaseInsensitive);//remove measuring unit
                }
                x << ram_size;
            }
            x << "</totalSize>";
            x << "<tCas>";
            x << "</tCas>";
            x << "<tRCD>";
            x << "</tRCD>";
            x << "<tRP>";
            x << "</tRP>";
            x << "<tRas>";
            x << "</tRas>";
            x << "<commandRate>";
            x << "</commandRate>";
        x << "</memory>";
        x << "<disk>";
            x << "<vendor>";
            x << "</vendor>";
            x << "<amount>";
            x << "</amount>";
            x << "<diskCapInGB>";
            x << "</diskCapInGB>";
            x << "<series>";
            x << "</series>";
            x << "<configuration>";
            x << "</configuration>";
        x << "</disk>";
    x << "</hardware>";
    x << "<software>";
        x << "<os>";
            x << "<family>";
                #ifdef Q_OS_WIN32
                x << "Windows";
                #else
                x << "X11";
                #endif
            x << "</family>";
            x << "<fullName>";
                if (ui->cbSIenabled->currentIndex()==0){
                    x <<  QString("%1 %2 %3-bits").arg(SYSINFO_OS_NAME()).arg(SYSINFO_OS_SP()).arg(SYSINFO_OS_BITS());
                }
            x << "</fullName>";
        x << "</os>";
    x << "</software>";
    x << "<metadata name=\"bench_log\">";
    WriteLog("adding benchmark log");
    WriteLog("unenecrypted scorefile generated");
    for (int i=0; i< applog.count();i++){
        x << applog.at(i) << "\n";
    }
    x << "</metadata>";
    x << "</submission>";

    //save scorefile to disk (unencrypted)
    QFile fOut(QString::number(ui->lcdTriscore->value()));
    if(fOut.exists()){fOut.remove();}
    if (fOut.open(QFile::WriteOnly | QFile::Text)) {
      QTextStream s(&fOut);
      for (int i = 0; i < x.size(); ++i)
          s << x.at(i);
    } else {
      WriteLog("error opening output file");
      QMessageBox msgBox;
      msgBox.setWindowTitle("Error");
      msgBox.setIcon(QMessageBox::Warning);
      msgBox.setText("Error opening output file.");
      msgBox.setStandardButtons(QMessageBox::Ok);
      msgBox.exec();
    }
    fOut.close();

    //encrypt
    QProcess openssl;QStringList args;
    QString outname = QString("%1/%2.hwbot").arg(qApp->property("Benchmark_Desktop_Folder").toString()).arg(QString::number(ui->lcdTriscore->value()));
    args << "aes-128-cbc"
         << "-K" << aeskey()
         << "-iv" << aesiv()
         << "-in" << QString::number(ui->lcdTriscore->value())
         << "-out" << outname;
    openssl.start("osl.dll", args);
    openssl.waitForFinished();
    openssl.close();
    fOut.remove();//delete unencrypted version
    //inform the user
    QMessageBox msgBox;
    msgBox.setWindowTitle("HWBOT Aquamark3");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText(QString("File successfully saved at\n%1").arg(outname.replace("/","\\",Qt::CaseInsensitive)));
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}


void frmMain::on_dial_valueChanged(int value){
  ui->lblLODVal->setText(QString::number(value*0.25));
      QString regpath = "HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Video";
      QSettings sets(regpath, QSettings::NativeFormat);
      QStringList keys = sets.allKeys();
      QStringList foo_l; QStringList boo_l;QString foo;

      for (int i=0;i<keys.count();i++){
          if (keys.value(i).contains("LODAdj")){
              foo_l << regpath + "\\" + keys.at(i); WriteLog("LODAdj was found: " + keys.at(i) );
          }
      }
      for (int i=0;i<foo_l.count();i++){foo = foo_l.at(i);foo.replace("/","\\",Qt::CaseInsensitive);foo.replace("\\LODAdj","",Qt::CaseInsensitive);boo_l << foo;}
      for (int i=0;i<boo_l.count();i++){QSettings boo_s(boo_l.at(i),QSettings::NativeFormat);boo_s.setValue("LODAdj",ui->lblLODVal->text());}

}

void frmMain::on_menu_DumpLog_triggered()
{
    WriteLog("Dumg log menu was used.");
    QMessageBox msgBox;
    msgBox.setWindowTitle("Dump log");
    msgBox.setText("File log.txt was successfully created.");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}

void frmMain::on_menu_Update_triggered()
{
    QFile wgetOut("hwbot_aqua_3.txt");QString foo;QString current= APP_VERSION;
    if(wgetOut.exists()){wgetOut.remove();}

    QProcess wget;QStringList args;args << "--no-check-certificate" << "http://tiny.cc/aqua3update";
    wget.start("wget/wget.dll", args);
    wget.waitForFinished();
    wget.close();

    if (wgetOut.open(QIODevice::ReadOnly)){QTextStream in(&wgetOut);while ( !in.atEnd() ){foo = in.readLine();}}wgetOut.close();

    current.replace(".","",Qt::CaseInsensitive);
    foo.replace(".","",Qt::CaseInsensitive);

    if (foo.toInt() == current.toInt()){//already newest version
        QMessageBox msgBox;
        msgBox.setWindowTitle("Check for updates");
        msgBox.setText("You are already using the latest version.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        wgetOut.remove();
    }
    if (foo.toInt() > current.toInt()){//newer version available
        QMessageBox msgBox;
        msgBox.setWindowTitle("Check for updates");
        msgBox.setText("There is a newer version available.\nDonwload it from http://tiny.cc/hwbotaqua");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        wgetOut.remove();
    }
    if (foo.toInt() < current.toInt()){//using a version newer than the one reported on server
        QMessageBox msgBox;
        msgBox.setWindowTitle("Check for updates");
        msgBox.setText("Take it easy T-1000, you are already using a\nversion newer than everyone else has.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        wgetOut.remove();
    }
}


void frmMain::on_menu_wwwHWBOT_triggered()
{
    QDesktopServices::openUrl(QUrl("http://www.hwbot.org"));
}

void frmMain::on_menu_wwwGenieben_triggered()
{
    QDesktopServices::openUrl(QUrl("http://www.elgenieben.blogspot.com"));
}

void frmMain::on_menu_ReportBug_triggered()
{
    QDesktopServices::openUrl(QUrl("http://forum.hwbot.org/showthread.php?t=67401"));
}

void frmMain::on_menu_DumpGPUZ_triggered()
{
    if (_rungpuz()==true){
        QMessageBox msgBox;
        msgBox.setWindowTitle("GPU-Z Dump");
        msgBox.setText("A file named 'gpuz.out' was created in application's path.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    } else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("GPU-Z Dump");
        msgBox.setText("There seems to have been a problem creating a dump from application GPU-Z.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}

void frmMain::on_menu_DumpDMI_triggered()
{
    QStringList args; args << ">>dmid.out";
    if (_rundmid(args)==true){
        QMessageBox msgBox;
        msgBox.setWindowTitle("DMI Decode Dump");
        msgBox.setText("A file named 'dmid.out' was created in application's path.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    } else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("DMI Decode Dump");
        msgBox.setText("There seems to have been a problem creating a dump from application DMI Decode.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}

void frmMain::on_menu_DumpDXDIAG_triggered()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("DirectX Diag Dump");

    if (_rundxdiag()==true){
        msgBox.setText("A file named 'dxdiag.out' was created in the logs folder");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStandardButtons(QMessageBox::Ok|QMessageBox::Open);
    } else {
        msgBox.setText("There seems to have been a problem creating a dump from application DirectX Diag.");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStandardButtons(QMessageBox::Ok);
    }
    if (msgBox.exec()==QMessageBox::Open ){
        QString file = qApp->property("Benchmark_Install_Folder").toString() + "/dxdiag.out";
        QStringList args; args << file;
        QProcess notepad; notepad.start("notepad.exe",args);
    }
}

void frmMain::on_menu_Exit_triggered()
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setWindowTitle("Exit application?");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("Are you sure you want to close this application?");
    msgBox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    if (msgBox.exec()==QMessageBox::Yes){ qApp->quit(); }
}


void frmMain::on_menu_wwwForums_triggered()
{
    QDesktopServices::openUrl(QUrl("http://forum.hwbot.org"));
}

void frmMain::on_menu_ClearBenchLogs_triggered()
{
    if (_clearmydocs()!=true){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Clearing Benchmark's Logs");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Benchmark's logs folder could not be deleted.\nPlease close all Explorer windows.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}

void frmMain::on_cbSIenabled_currentIndexChanged(int index){
    ui->stackedWidget->setCurrentIndex(index);
}

void frmMain::on_cbTheme_currentIndexChanged(const QString &arg1)
{
    SetTheme(arg1);
    QSettings settings("GENiEBEN", "Aquamark3 Wrapper");
    settings.setValue("Theme",arg1);
}

void frmMain::on_tabWidget_currentChanged(int index){
    QString foo;QString boo;
    switch (index){

        case 2: {//COMPARE ONLINE page
            //hide Browse tab until version 2.55
            ui->tab_CompareOnline->removeTab(1);
            //
            QStringList TopTwentyList = Query_World_Records("aquamark",20);

            if (TopTwentyList.at(0).contains("Error")){
                ui->stacked_CompareOnline->setCurrentIndex(0);//hide table and show NOT CONNECTED TO INTERNET warning.
            } else {
                ui->stacked_CompareOnline->setCurrentIndex(1);//show table
                for (int i=0;i<ui->table_WR->rowCount();i++){ ui->table_WR->removeRow(i); }
                for (int i=0; i< TopTwentyList.count();i++){
                    foo = TopTwentyList.at(i);
                    ui->table_WR->insertRow(ui->table_WR->rowCount());
                    boo = foo.split(";").at(0);
                    QTableWidgetItem *newItem0 = new QTableWidgetItem(QString::number(i+1));
                    QTableWidgetItem *newItem1 = new QTableWidgetItem(boo.replace("marks",""));
                    QTableWidgetItem *newItem2 = new QTableWidgetItem(foo.split(";").at(1));
                    boo = foo.split(";").at(2);
                    boo.replace("Mhz"," MHz");
                    QTableWidgetItem *newItem3 = new QTableWidgetItem(boo.replace("at null MHz",""));
                    ui->table_WR->setItem(i, 0, newItem0);
                    ui->table_WR->setItem(i, 1, newItem1);
                    ui->table_WR->setItem(i, 2, newItem2);
                    ui->table_WR->setItem(i, 3, newItem3);
                }
                ui->table_WR->setColumnWidth(0,40);
                ui->table_WR->setColumnWidth(1,70);
                ui->table_WR->setColumnWidth(2,140);
                ui->table_WR->horizontalHeader()->setStretchLastSection(1);
                break;
            }
        }
        case 3: {//ABOUT page
            ui->table_AboutModules->setColumnWidth(1,70);
            ui->table_AboutModules->horizontalHeader()->setStretchLastSection(1);
            break;
        }
    }
}

void frmMain::on_cbRunMode_currentIndexChanged(const QString &arg1)
{
    QSettings settings("GENiEBEN", "Aquamark3 Wrapper");
    settings.setValue("RunMode",arg1);
}

void frmMain::on_cbHideLogo_currentIndexChanged(const QString &arg1)
{
    QSettings settings("GENiEBEN", "Aquamark3 Wrapper");
    settings.setValue("HideLogo",arg1);
}

void frmMain::on_cbHideError_currentIndexChanged(const QString &arg1)
{
    QSettings settings("GENiEBEN", "Aquamark3 Wrapper");
    settings.setValue("HideError",arg1);
}

void frmMain::on_cbOSD_currentIndexChanged(const QString &arg1)
{
    QSettings settings("GENiEBEN", "Aquamark3 Wrapper");
    settings.setValue("OSDStats",arg1);
}

void frmMain::on_cbSIenabled_currentIndexChanged(const QString &arg1)
{
    QSettings settings("GENiEBEN", "Aquamark3 Wrapper");
    settings.setValue("SystemInfo",arg1);
}

void frmMain::on_cbProcessPrio_currentIndexChanged(const QString &arg1)
{
    QSettings settings("GENiEBEN", "Aquamark3 Wrapper");
    settings.setValue("ProcessPrio",arg1);
}

void frmMain::on_cbScreenshotFormat_currentIndexChanged(const QString &arg1)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Screenshot Format");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("Please be aware that JPG option does\nnot work under Windows XP / 2003.");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
    if (SYSINFO_OS_NAME().contains("XP") || SYSINFO_OS_NAME().contains("2003")){
        ui->cbScreenshotFormat->setCurrentText("PNG");
    }
    QSettings settings("GENiEBEN", "Aquamark3 Wrapper");
    settings.setValue("Screenshot",arg1);
}

void frmMain::on_slider_SSQuality_valueChanged(int value)
{
    QSettings settings("GENiEBEN", "Aquamark3 Wrapper");
    settings.setValue("SS_Quality",value);
}

void frmMain::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column){
    ui->stack_settings->setCurrentIndex(0);

    if (item->text(column)=="Tweaks" || item->text(column)=="Processor"){
        ui->stack_settings->setCurrentIndex(1);
    }
    if (item->text(column)=="Video Card" || item->text(column)=="ATi / AMD"){
        ui->stack_settings->setCurrentIndex(2);
    }
    if (item->text(column)=="Benchmark"){
        ui->stack_settings->setCurrentIndex(3);
    }
    if (item->text(column)=="Interface"){
        ui->stack_settings->setCurrentIndex(4);
    }
    if (item->text(column)=="System Info"){
        ui->stack_settings->setCurrentIndex(5);
    }

}
