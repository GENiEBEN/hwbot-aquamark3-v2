/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmMain
{
public:
    QAction *menu_Update;
    QAction *menu_Exit;
    QAction *menu_DumpLog;
    QAction *menu_DumpGPUZ;
    QAction *menu_DumpDMI;
    QAction *menu_DumpDXDIAG;
    QAction *menu_ClearBenchLogs;
    QAction *menu_wwwHWBOT;
    QAction *menu_wwwGenieben;
    QAction *menu_ReportBug;
    QAction *menu_wwwForums;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLCDNumber *lcdTriscore;
    QLCDNumber *lcdGFX;
    QLCDNumber *lcdCPU;
    QLabel *lblGfxScore;
    QLabel *lblCpuScore;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QLabel *iconVGA;
    QLabel *iconRAM;
    QLabel *lblCPU_Speed;
    QLabel *lblCPU_Socket;
    QLabel *lblMB_SN;
    QLabel *iconOS;
    QLabel *lblCPU_Name;
    QLabel *lblOS_DX;
    QLabel *lblMB_Name;
    QLabel *lblOS_ExtraInfo;
    QLabel *lblRAM_Name;
    QLabel *iconCPU;
    QLabel *lblGFX_Speed;
    QLabel *lblRAM_Size;
    QLabel *lblMB_Bios;
    QLabel *lblRAM_PN;
    QLabel *lblOS_Name;
    QLabel *iconMOBO;
    QLabel *lblGFX_Name;
    QLabel *lblGFX_Driver;
    QWidget *page_4;
    QLabel *lblGfxScore_2;
    QLabel *lblCPU_Name_2;
    QLabel *lblCPU_Name_3;
    QLabel *lblCPU_Name_4;
    QLabel *lblCPU_Name_5;
    QLabel *lblCPU_Name_6;
    QLabel *lblCPU_Name_7;
    QLabel *lblCPU_Name_8;
    QLabel *lblCPU_Name_9;
    QLabel *lblCPU_Name_10;
    QLabel *lblScore_C1;
    QLabel *lblScore_C2;
    QLabel *lblScore_C3;
    QLabel *lblScore_C6;
    QLabel *lblScore_C5;
    QLabel *lblScore_C4;
    QLabel *lblScore_C9;
    QLabel *lblScore_C8;
    QLabel *lblScore_C7;
    QWidget *tab_2;
    QTreeWidget *treeWidget;
    QStackedWidget *stack_settings;
    QWidget *Page_Settings_blank;
    QWidget *Page_Settings_CPU;
    QGroupBox *gbCores;
    QFrame *frame;
    QCheckBox *ckbCore01;
    QCheckBox *ckbCore02;
    QCheckBox *ckbCore03;
    QCheckBox *ckbCore04;
    QCheckBox *ckbCore05;
    QCheckBox *ckbCore06;
    QCheckBox *ckbCore07;
    QCheckBox *ckbCore08;
    QCheckBox *ckbCore09;
    QCheckBox *ckbCore10;
    QCheckBox *ckbCore11;
    QCheckBox *ckbCore12;
    QCheckBox *ckbCore13;
    QCheckBox *ckbCore14;
    QCheckBox *ckbCore15;
    QCheckBox *ckbCore16;
    QCheckBox *ckbCore17;
    QCheckBox *ckbCore18;
    QCheckBox *ckbCore19;
    QCheckBox *ckbCore20;
    QCheckBox *ckbCore21;
    QCheckBox *ckbCore22;
    QCheckBox *ckbCore23;
    QCheckBox *ckbCore24;
    QCheckBox *ckbCore25;
    QCheckBox *ckbCore26;
    QCheckBox *ckbCore27;
    QCheckBox *ckbCore28;
    QCheckBox *ckbCore29;
    QCheckBox *ckbCore30;
    QCheckBox *ckbCore31;
    QCheckBox *ckbCore32;
    QCheckBox *ckbCore33;
    QCheckBox *ckbCore34;
    QCheckBox *ckbCore35;
    QCheckBox *ckbCore36;
    QCheckBox *ckbCore37;
    QCheckBox *ckbCore38;
    QCheckBox *ckbCore39;
    QCheckBox *ckbCore40;
    QCheckBox *ckbCore41;
    QCheckBox *ckbCore42;
    QCheckBox *ckbCore43;
    QCheckBox *ckbCore44;
    QCheckBox *ckbCore45;
    QCheckBox *ckbCore46;
    QCheckBox *ckbCore47;
    QCheckBox *ckbCore48;
    QCheckBox *ckbCore49;
    QCheckBox *ckbCore50;
    QCheckBox *ckbCore51;
    QCheckBox *ckbCore52;
    QCheckBox *ckbCore53;
    QCheckBox *ckbCore54;
    QCheckBox *ckbCore55;
    QCheckBox *ckbCore56;
    QCheckBox *ckbCore57;
    QCheckBox *ckbCore58;
    QCheckBox *ckbCore59;
    QCheckBox *ckbCore60;
    QCheckBox *ckbCore61;
    QCheckBox *ckbCore62;
    QCheckBox *ckbCore63;
    QCheckBox *ckbCore64;
    QComboBox *cbProcessPrio;
    QLabel *lblProcessPrio;
    QWidget *Page_Settings_TweaksATI;
    QDial *dial;
    QLabel *lblLOD;
    QLabel *lblLODVal;
    QWidget *Page_Settings_Benchmark;
    QComboBox *cbHideError;
    QLabel *lblOSD_2;
    QLabel *lblHideLogo;
    QComboBox *cbRunMode;
    QLabel *lblOSD;
    QLabel *lblRunMode;
    QComboBox *cbOSD;
    QComboBox *cbHideLogo;
    QWidget *Page_Settings_Interface;
    QSlider *slider_SSQuality;
    QLabel *lblSysInfo_2;
    QComboBox *cbTheme;
    QLabel *lblSysInfo_3;
    QComboBox *cbScreenshotFormat;
    QLabel *lblSysInfo_4;
    QWidget *Page_Settings_Plugins_SI;
    QComboBox *cbSIenabled;
    QLabel *lblSysInfo;
    QWidget *tab_3;
    QStackedWidget *stacked_CompareOnline;
    QWidget *page_5;
    QLabel *lblGfxScore_3;
    QWidget *page_6;
    QTabWidget *tab_CompareOnline;
    QWidget *tab_5;
    QTableWidget *table_WR;
    QWidget *tab_6;
    QTableWidget *table_WR_2;
    QComboBox *comboBox;
    QLabel *lblHideLogo_2;
    QLabel *lblHideLogo_3;
    QComboBox *comboBox_2;
    QLabel *lblHideLogo_4;
    QSpinBox *spinBox;
    QWidget *tab_4;
    QToolBox *toolBox;
    QWidget *page;
    QTableWidget *table_AboutModules;
    QWidget *page_2;
    QTextEdit *textEdit_2;
    QPushButton *btnStart;
    QPushButton *btnSave;
    QLabel *lblHash;
    QMenuBar *menuBar;
    QMenu *menuApplication;
    QMenu *menuDebug;
    QMenu *menuHelp;

    void setupUi(QMainWindow *frmMain)
    {
        if (frmMain->objectName().isEmpty())
            frmMain->setObjectName(QStringLiteral("frmMain"));
        frmMain->resize(640, 542);
        QFont font;
        font.setFamily(QStringLiteral("Meiryo UI"));
        frmMain->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/hwbot.ico"), QSize(), QIcon::Normal, QIcon::Off);
        frmMain->setWindowIcon(icon);
        menu_Update = new QAction(frmMain);
        menu_Update->setObjectName(QStringLiteral("menu_Update"));
        menu_Exit = new QAction(frmMain);
        menu_Exit->setObjectName(QStringLiteral("menu_Exit"));
        menu_DumpLog = new QAction(frmMain);
        menu_DumpLog->setObjectName(QStringLiteral("menu_DumpLog"));
        menu_DumpGPUZ = new QAction(frmMain);
        menu_DumpGPUZ->setObjectName(QStringLiteral("menu_DumpGPUZ"));
        menu_DumpDMI = new QAction(frmMain);
        menu_DumpDMI->setObjectName(QStringLiteral("menu_DumpDMI"));
        menu_DumpDXDIAG = new QAction(frmMain);
        menu_DumpDXDIAG->setObjectName(QStringLiteral("menu_DumpDXDIAG"));
        menu_ClearBenchLogs = new QAction(frmMain);
        menu_ClearBenchLogs->setObjectName(QStringLiteral("menu_ClearBenchLogs"));
        menu_wwwHWBOT = new QAction(frmMain);
        menu_wwwHWBOT->setObjectName(QStringLiteral("menu_wwwHWBOT"));
        menu_wwwGenieben = new QAction(frmMain);
        menu_wwwGenieben->setObjectName(QStringLiteral("menu_wwwGenieben"));
        menu_ReportBug = new QAction(frmMain);
        menu_ReportBug->setObjectName(QStringLiteral("menu_ReportBug"));
        menu_wwwForums = new QAction(frmMain);
        menu_wwwForums->setObjectName(QStringLiteral("menu_wwwForums"));
        centralwidget = new QWidget(frmMain);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 621, 461));
        tabWidget->setFont(font);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        lcdTriscore = new QLCDNumber(tab);
        lcdTriscore->setObjectName(QStringLiteral("lcdTriscore"));
        lcdTriscore->setGeometry(QRect(440, 10, 171, 49));
        lcdTriscore->setLayoutDirection(Qt::RightToLeft);
        lcdTriscore->setFrameShape(QFrame::NoFrame);
        lcdTriscore->setDigitCount(6);
        lcdTriscore->setSegmentStyle(QLCDNumber::Flat);
        lcdTriscore->setProperty("value", QVariant(0));
        lcdTriscore->setProperty("intValue", QVariant(0));
        lcdGFX = new QLCDNumber(tab);
        lcdGFX->setObjectName(QStringLiteral("lcdGFX"));
        lcdGFX->setGeometry(QRect(260, 20, 81, 41));
        lcdGFX->setLayoutDirection(Qt::RightToLeft);
        lcdGFX->setFrameShape(QFrame::NoFrame);
        lcdGFX->setDigitCount(6);
        lcdGFX->setSegmentStyle(QLCDNumber::Flat);
        lcdGFX->setProperty("value", QVariant(0));
        lcdGFX->setProperty("intValue", QVariant(0));
        lcdCPU = new QLCDNumber(tab);
        lcdCPU->setObjectName(QStringLiteral("lcdCPU"));
        lcdCPU->setGeometry(QRect(340, 20, 81, 41));
        lcdCPU->setLayoutDirection(Qt::RightToLeft);
        lcdCPU->setFrameShape(QFrame::NoFrame);
        lcdCPU->setDigitCount(6);
        lcdCPU->setSegmentStyle(QLCDNumber::Flat);
        lcdCPU->setProperty("value", QVariant(0));
        lcdCPU->setProperty("intValue", QVariant(0));
        lblGfxScore = new QLabel(tab);
        lblGfxScore->setObjectName(QStringLiteral("lblGfxScore"));
        lblGfxScore->setGeometry(QRect(280, 10, 51, 16));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        lblGfxScore->setFont(font1);
        lblGfxScore->setScaledContents(true);
        lblCpuScore = new QLabel(tab);
        lblCpuScore->setObjectName(QStringLiteral("lblCpuScore"));
        lblCpuScore->setGeometry(QRect(350, 10, 61, 16));
        lblCpuScore->setFont(font1);
        lblCpuScore->setScaledContents(true);
        stackedWidget = new QStackedWidget(tab);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 80, 591, 341));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        iconVGA = new QLabel(page_3);
        iconVGA->setObjectName(QStringLiteral("iconVGA"));
        iconVGA->setGeometry(QRect(10, 210, 64, 64));
        iconVGA->setFrameShape(QFrame::NoFrame);
        iconVGA->setPixmap(QPixmap(QString::fromUtf8(":/images/res/gfx.png")));
        iconVGA->setScaledContents(true);
        iconRAM = new QLabel(page_3);
        iconRAM->setObjectName(QStringLiteral("iconRAM"));
        iconRAM->setGeometry(QRect(10, 140, 64, 64));
        iconRAM->setFrameShape(QFrame::NoFrame);
        iconRAM->setPixmap(QPixmap(QString::fromUtf8(":/images/res/ram.png")));
        iconRAM->setScaledContents(true);
        lblCPU_Speed = new QLabel(page_3);
        lblCPU_Speed->setObjectName(QStringLiteral("lblCPU_Speed"));
        lblCPU_Speed->setGeometry(QRect(80, 20, 501, 20));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        lblCPU_Speed->setFont(font2);
        lblCPU_Socket = new QLabel(page_3);
        lblCPU_Socket->setObjectName(QStringLiteral("lblCPU_Socket"));
        lblCPU_Socket->setGeometry(QRect(80, 40, 501, 16));
        lblCPU_Socket->setFont(font2);
        lblMB_SN = new QLabel(page_3);
        lblMB_SN->setObjectName(QStringLiteral("lblMB_SN"));
        lblMB_SN->setGeometry(QRect(80, 110, 501, 16));
        lblMB_SN->setFont(font2);
        iconOS = new QLabel(page_3);
        iconOS->setObjectName(QStringLiteral("iconOS"));
        iconOS->setGeometry(QRect(10, 280, 64, 64));
        iconOS->setFrameShape(QFrame::NoFrame);
        iconOS->setPixmap(QPixmap(QString::fromUtf8(":/images/res/windows.png")));
        iconOS->setScaledContents(true);
        lblCPU_Name = new QLabel(page_3);
        lblCPU_Name->setObjectName(QStringLiteral("lblCPU_Name"));
        lblCPU_Name->setGeometry(QRect(80, 0, 501, 16));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        lblCPU_Name->setFont(font3);
        lblOS_DX = new QLabel(page_3);
        lblOS_DX->setObjectName(QStringLiteral("lblOS_DX"));
        lblOS_DX->setGeometry(QRect(80, 300, 501, 16));
        lblOS_DX->setFont(font2);
        lblMB_Name = new QLabel(page_3);
        lblMB_Name->setObjectName(QStringLiteral("lblMB_Name"));
        lblMB_Name->setGeometry(QRect(80, 70, 501, 16));
        lblMB_Name->setFont(font3);
        lblMB_Name->setScaledContents(true);
        lblMB_Name->setWordWrap(false);
        lblOS_ExtraInfo = new QLabel(page_3);
        lblOS_ExtraInfo->setObjectName(QStringLiteral("lblOS_ExtraInfo"));
        lblOS_ExtraInfo->setGeometry(QRect(80, 320, 501, 16));
        lblOS_ExtraInfo->setFont(font2);
        lblRAM_Name = new QLabel(page_3);
        lblRAM_Name->setObjectName(QStringLiteral("lblRAM_Name"));
        lblRAM_Name->setGeometry(QRect(80, 140, 501, 16));
        lblRAM_Name->setFont(font3);
        iconCPU = new QLabel(page_3);
        iconCPU->setObjectName(QStringLiteral("iconCPU"));
        iconCPU->setGeometry(QRect(10, 0, 64, 64));
        iconCPU->setFrameShape(QFrame::NoFrame);
        iconCPU->setPixmap(QPixmap(QString::fromUtf8(":/images/res/cpu.png")));
        iconCPU->setScaledContents(true);
        lblGFX_Speed = new QLabel(page_3);
        lblGFX_Speed->setObjectName(QStringLiteral("lblGFX_Speed"));
        lblGFX_Speed->setGeometry(QRect(80, 230, 501, 16));
        lblGFX_Speed->setFont(font2);
        lblRAM_Size = new QLabel(page_3);
        lblRAM_Size->setObjectName(QStringLiteral("lblRAM_Size"));
        lblRAM_Size->setGeometry(QRect(80, 180, 501, 16));
        lblRAM_Size->setFont(font2);
        lblMB_Bios = new QLabel(page_3);
        lblMB_Bios->setObjectName(QStringLiteral("lblMB_Bios"));
        lblMB_Bios->setGeometry(QRect(80, 90, 501, 16));
        lblMB_Bios->setFont(font2);
        lblRAM_PN = new QLabel(page_3);
        lblRAM_PN->setObjectName(QStringLiteral("lblRAM_PN"));
        lblRAM_PN->setGeometry(QRect(80, 160, 501, 16));
        lblRAM_PN->setFont(font2);
        lblOS_Name = new QLabel(page_3);
        lblOS_Name->setObjectName(QStringLiteral("lblOS_Name"));
        lblOS_Name->setGeometry(QRect(80, 280, 501, 16));
        lblOS_Name->setFont(font3);
        iconMOBO = new QLabel(page_3);
        iconMOBO->setObjectName(QStringLiteral("iconMOBO"));
        iconMOBO->setGeometry(QRect(10, 70, 64, 64));
        iconMOBO->setFrameShape(QFrame::NoFrame);
        iconMOBO->setPixmap(QPixmap(QString::fromUtf8(":/images/res/motherboard.png")));
        iconMOBO->setScaledContents(true);
        lblGFX_Name = new QLabel(page_3);
        lblGFX_Name->setObjectName(QStringLiteral("lblGFX_Name"));
        lblGFX_Name->setGeometry(QRect(80, 210, 501, 16));
        lblGFX_Name->setFont(font3);
        lblGFX_Driver = new QLabel(page_3);
        lblGFX_Driver->setObjectName(QStringLiteral("lblGFX_Driver"));
        lblGFX_Driver->setGeometry(QRect(80, 250, 501, 16));
        lblGFX_Driver->setFont(font2);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        lblGfxScore_2 = new QLabel(page_4);
        lblGfxScore_2->setObjectName(QStringLiteral("lblGfxScore_2"));
        lblGfxScore_2->setGeometry(QRect(10, 130, 581, 20));
        lblGfxScore_2->setFont(font1);
        lblGfxScore_2->setScaledContents(false);
        lblGfxScore_2->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_4);
        lblCPU_Name_2 = new QLabel(tab);
        lblCPU_Name_2->setObjectName(QStringLiteral("lblCPU_Name_2"));
        lblCPU_Name_2->setGeometry(QRect(10, 10, 21, 16));
        lblCPU_Name_2->setFont(font3);
        lblCPU_Name_3 = new QLabel(tab);
        lblCPU_Name_3->setObjectName(QStringLiteral("lblCPU_Name_3"));
        lblCPU_Name_3->setGeometry(QRect(10, 30, 21, 16));
        lblCPU_Name_3->setFont(font3);
        lblCPU_Name_4 = new QLabel(tab);
        lblCPU_Name_4->setObjectName(QStringLiteral("lblCPU_Name_4"));
        lblCPU_Name_4->setGeometry(QRect(10, 50, 21, 16));
        lblCPU_Name_4->setFont(font3);
        lblCPU_Name_5 = new QLabel(tab);
        lblCPU_Name_5->setObjectName(QStringLiteral("lblCPU_Name_5"));
        lblCPU_Name_5->setGeometry(QRect(90, 50, 21, 16));
        lblCPU_Name_5->setFont(font3);
        lblCPU_Name_6 = new QLabel(tab);
        lblCPU_Name_6->setObjectName(QStringLiteral("lblCPU_Name_6"));
        lblCPU_Name_6->setGeometry(QRect(90, 30, 21, 16));
        lblCPU_Name_6->setFont(font3);
        lblCPU_Name_7 = new QLabel(tab);
        lblCPU_Name_7->setObjectName(QStringLiteral("lblCPU_Name_7"));
        lblCPU_Name_7->setGeometry(QRect(90, 10, 21, 16));
        lblCPU_Name_7->setFont(font3);
        lblCPU_Name_8 = new QLabel(tab);
        lblCPU_Name_8->setObjectName(QStringLiteral("lblCPU_Name_8"));
        lblCPU_Name_8->setGeometry(QRect(170, 50, 21, 16));
        lblCPU_Name_8->setFont(font3);
        lblCPU_Name_9 = new QLabel(tab);
        lblCPU_Name_9->setObjectName(QStringLiteral("lblCPU_Name_9"));
        lblCPU_Name_9->setGeometry(QRect(170, 30, 21, 16));
        lblCPU_Name_9->setFont(font3);
        lblCPU_Name_10 = new QLabel(tab);
        lblCPU_Name_10->setObjectName(QStringLiteral("lblCPU_Name_10"));
        lblCPU_Name_10->setGeometry(QRect(170, 10, 21, 16));
        lblCPU_Name_10->setFont(font3);
        lblScore_C1 = new QLabel(tab);
        lblScore_C1->setObjectName(QStringLiteral("lblScore_C1"));
        lblScore_C1->setGeometry(QRect(30, 10, 51, 20));
        lblScore_C1->setFont(font2);
        lblScore_C1->setScaledContents(true);
        lblScore_C2 = new QLabel(tab);
        lblScore_C2->setObjectName(QStringLiteral("lblScore_C2"));
        lblScore_C2->setGeometry(QRect(30, 30, 51, 20));
        lblScore_C2->setFont(font2);
        lblScore_C2->setScaledContents(true);
        lblScore_C3 = new QLabel(tab);
        lblScore_C3->setObjectName(QStringLiteral("lblScore_C3"));
        lblScore_C3->setGeometry(QRect(30, 50, 51, 20));
        lblScore_C3->setFont(font2);
        lblScore_C3->setScaledContents(true);
        lblScore_C6 = new QLabel(tab);
        lblScore_C6->setObjectName(QStringLiteral("lblScore_C6"));
        lblScore_C6->setGeometry(QRect(110, 50, 51, 20));
        lblScore_C6->setFont(font2);
        lblScore_C6->setScaledContents(true);
        lblScore_C5 = new QLabel(tab);
        lblScore_C5->setObjectName(QStringLiteral("lblScore_C5"));
        lblScore_C5->setGeometry(QRect(110, 30, 51, 20));
        lblScore_C5->setFont(font2);
        lblScore_C5->setScaledContents(true);
        lblScore_C4 = new QLabel(tab);
        lblScore_C4->setObjectName(QStringLiteral("lblScore_C4"));
        lblScore_C4->setGeometry(QRect(110, 10, 51, 20));
        lblScore_C4->setFont(font2);
        lblScore_C4->setScaledContents(true);
        lblScore_C9 = new QLabel(tab);
        lblScore_C9->setObjectName(QStringLiteral("lblScore_C9"));
        lblScore_C9->setGeometry(QRect(190, 50, 51, 20));
        lblScore_C9->setFont(font2);
        lblScore_C9->setScaledContents(true);
        lblScore_C8 = new QLabel(tab);
        lblScore_C8->setObjectName(QStringLiteral("lblScore_C8"));
        lblScore_C8->setGeometry(QRect(190, 30, 51, 20));
        lblScore_C8->setFont(font2);
        lblScore_C8->setScaledContents(true);
        lblScore_C7 = new QLabel(tab);
        lblScore_C7->setObjectName(QStringLiteral("lblScore_C7"));
        lblScore_C7->setGeometry(QRect(190, 10, 51, 20));
        lblScore_C7->setFont(font2);
        lblScore_C7->setScaledContents(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        treeWidget = new QTreeWidget(tab_2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem2);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(0, 0, 161, 431));
        treeWidget->setFrameShape(QFrame::NoFrame);
        treeWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeWidget->setProperty("showDropIndicator", QVariant(false));
        treeWidget->setUniformRowHeights(true);
        treeWidget->setHeaderHidden(true);
        treeWidget->setExpandsOnDoubleClick(false);
        treeWidget->header()->setVisible(false);
        stack_settings = new QStackedWidget(tab_2);
        stack_settings->setObjectName(QStringLiteral("stack_settings"));
        stack_settings->setGeometry(QRect(170, 0, 451, 431));
        Page_Settings_blank = new QWidget();
        Page_Settings_blank->setObjectName(QStringLiteral("Page_Settings_blank"));
        stack_settings->addWidget(Page_Settings_blank);
        Page_Settings_CPU = new QWidget();
        Page_Settings_CPU->setObjectName(QStringLiteral("Page_Settings_CPU"));
        gbCores = new QGroupBox(Page_Settings_CPU);
        gbCores->setObjectName(QStringLiteral("gbCores"));
        gbCores->setGeometry(QRect(0, 10, 431, 201));
        frame = new QFrame(gbCores);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 20, 411, 171));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        ckbCore01 = new QCheckBox(frame);
        ckbCore01->setObjectName(QStringLiteral("ckbCore01"));
        ckbCore01->setGeometry(QRect(10, 10, 41, 17));
        ckbCore02 = new QCheckBox(frame);
        ckbCore02->setObjectName(QStringLiteral("ckbCore02"));
        ckbCore02->setGeometry(QRect(60, 10, 41, 17));
        ckbCore03 = new QCheckBox(frame);
        ckbCore03->setObjectName(QStringLiteral("ckbCore03"));
        ckbCore03->setGeometry(QRect(110, 10, 41, 17));
        ckbCore04 = new QCheckBox(frame);
        ckbCore04->setObjectName(QStringLiteral("ckbCore04"));
        ckbCore04->setGeometry(QRect(160, 10, 41, 17));
        ckbCore05 = new QCheckBox(frame);
        ckbCore05->setObjectName(QStringLiteral("ckbCore05"));
        ckbCore05->setGeometry(QRect(210, 10, 41, 17));
        ckbCore06 = new QCheckBox(frame);
        ckbCore06->setObjectName(QStringLiteral("ckbCore06"));
        ckbCore06->setGeometry(QRect(260, 10, 41, 17));
        ckbCore07 = new QCheckBox(frame);
        ckbCore07->setObjectName(QStringLiteral("ckbCore07"));
        ckbCore07->setGeometry(QRect(310, 10, 41, 17));
        ckbCore08 = new QCheckBox(frame);
        ckbCore08->setObjectName(QStringLiteral("ckbCore08"));
        ckbCore08->setGeometry(QRect(360, 10, 41, 17));
        ckbCore09 = new QCheckBox(frame);
        ckbCore09->setObjectName(QStringLiteral("ckbCore09"));
        ckbCore09->setGeometry(QRect(10, 30, 41, 17));
        ckbCore10 = new QCheckBox(frame);
        ckbCore10->setObjectName(QStringLiteral("ckbCore10"));
        ckbCore10->setGeometry(QRect(60, 30, 41, 17));
        ckbCore11 = new QCheckBox(frame);
        ckbCore11->setObjectName(QStringLiteral("ckbCore11"));
        ckbCore11->setGeometry(QRect(110, 30, 41, 17));
        ckbCore12 = new QCheckBox(frame);
        ckbCore12->setObjectName(QStringLiteral("ckbCore12"));
        ckbCore12->setGeometry(QRect(160, 30, 41, 17));
        ckbCore13 = new QCheckBox(frame);
        ckbCore13->setObjectName(QStringLiteral("ckbCore13"));
        ckbCore13->setGeometry(QRect(210, 30, 41, 17));
        ckbCore14 = new QCheckBox(frame);
        ckbCore14->setObjectName(QStringLiteral("ckbCore14"));
        ckbCore14->setGeometry(QRect(260, 30, 41, 17));
        ckbCore15 = new QCheckBox(frame);
        ckbCore15->setObjectName(QStringLiteral("ckbCore15"));
        ckbCore15->setGeometry(QRect(310, 30, 41, 17));
        ckbCore16 = new QCheckBox(frame);
        ckbCore16->setObjectName(QStringLiteral("ckbCore16"));
        ckbCore16->setGeometry(QRect(360, 30, 41, 17));
        ckbCore17 = new QCheckBox(frame);
        ckbCore17->setObjectName(QStringLiteral("ckbCore17"));
        ckbCore17->setGeometry(QRect(10, 50, 41, 17));
        ckbCore18 = new QCheckBox(frame);
        ckbCore18->setObjectName(QStringLiteral("ckbCore18"));
        ckbCore18->setGeometry(QRect(60, 50, 41, 17));
        ckbCore19 = new QCheckBox(frame);
        ckbCore19->setObjectName(QStringLiteral("ckbCore19"));
        ckbCore19->setGeometry(QRect(110, 50, 41, 17));
        ckbCore20 = new QCheckBox(frame);
        ckbCore20->setObjectName(QStringLiteral("ckbCore20"));
        ckbCore20->setGeometry(QRect(160, 50, 41, 17));
        ckbCore21 = new QCheckBox(frame);
        ckbCore21->setObjectName(QStringLiteral("ckbCore21"));
        ckbCore21->setGeometry(QRect(210, 50, 41, 17));
        ckbCore22 = new QCheckBox(frame);
        ckbCore22->setObjectName(QStringLiteral("ckbCore22"));
        ckbCore22->setGeometry(QRect(260, 50, 41, 17));
        ckbCore23 = new QCheckBox(frame);
        ckbCore23->setObjectName(QStringLiteral("ckbCore23"));
        ckbCore23->setGeometry(QRect(310, 50, 41, 17));
        ckbCore24 = new QCheckBox(frame);
        ckbCore24->setObjectName(QStringLiteral("ckbCore24"));
        ckbCore24->setGeometry(QRect(360, 50, 41, 17));
        ckbCore25 = new QCheckBox(frame);
        ckbCore25->setObjectName(QStringLiteral("ckbCore25"));
        ckbCore25->setGeometry(QRect(10, 70, 41, 17));
        ckbCore26 = new QCheckBox(frame);
        ckbCore26->setObjectName(QStringLiteral("ckbCore26"));
        ckbCore26->setGeometry(QRect(60, 70, 41, 17));
        ckbCore27 = new QCheckBox(frame);
        ckbCore27->setObjectName(QStringLiteral("ckbCore27"));
        ckbCore27->setGeometry(QRect(110, 70, 41, 17));
        ckbCore28 = new QCheckBox(frame);
        ckbCore28->setObjectName(QStringLiteral("ckbCore28"));
        ckbCore28->setGeometry(QRect(160, 70, 41, 17));
        ckbCore29 = new QCheckBox(frame);
        ckbCore29->setObjectName(QStringLiteral("ckbCore29"));
        ckbCore29->setGeometry(QRect(210, 70, 41, 17));
        ckbCore30 = new QCheckBox(frame);
        ckbCore30->setObjectName(QStringLiteral("ckbCore30"));
        ckbCore30->setGeometry(QRect(260, 70, 41, 17));
        ckbCore31 = new QCheckBox(frame);
        ckbCore31->setObjectName(QStringLiteral("ckbCore31"));
        ckbCore31->setGeometry(QRect(310, 70, 41, 17));
        ckbCore32 = new QCheckBox(frame);
        ckbCore32->setObjectName(QStringLiteral("ckbCore32"));
        ckbCore32->setGeometry(QRect(360, 70, 41, 17));
        ckbCore33 = new QCheckBox(frame);
        ckbCore33->setObjectName(QStringLiteral("ckbCore33"));
        ckbCore33->setGeometry(QRect(10, 90, 41, 17));
        ckbCore34 = new QCheckBox(frame);
        ckbCore34->setObjectName(QStringLiteral("ckbCore34"));
        ckbCore34->setGeometry(QRect(60, 90, 41, 17));
        ckbCore35 = new QCheckBox(frame);
        ckbCore35->setObjectName(QStringLiteral("ckbCore35"));
        ckbCore35->setGeometry(QRect(110, 90, 41, 17));
        ckbCore36 = new QCheckBox(frame);
        ckbCore36->setObjectName(QStringLiteral("ckbCore36"));
        ckbCore36->setGeometry(QRect(160, 90, 41, 17));
        ckbCore37 = new QCheckBox(frame);
        ckbCore37->setObjectName(QStringLiteral("ckbCore37"));
        ckbCore37->setGeometry(QRect(210, 90, 41, 17));
        ckbCore38 = new QCheckBox(frame);
        ckbCore38->setObjectName(QStringLiteral("ckbCore38"));
        ckbCore38->setGeometry(QRect(260, 90, 41, 17));
        ckbCore39 = new QCheckBox(frame);
        ckbCore39->setObjectName(QStringLiteral("ckbCore39"));
        ckbCore39->setGeometry(QRect(310, 90, 41, 17));
        ckbCore40 = new QCheckBox(frame);
        ckbCore40->setObjectName(QStringLiteral("ckbCore40"));
        ckbCore40->setGeometry(QRect(360, 90, 41, 17));
        ckbCore41 = new QCheckBox(frame);
        ckbCore41->setObjectName(QStringLiteral("ckbCore41"));
        ckbCore41->setGeometry(QRect(10, 110, 41, 17));
        ckbCore42 = new QCheckBox(frame);
        ckbCore42->setObjectName(QStringLiteral("ckbCore42"));
        ckbCore42->setGeometry(QRect(60, 110, 41, 17));
        ckbCore43 = new QCheckBox(frame);
        ckbCore43->setObjectName(QStringLiteral("ckbCore43"));
        ckbCore43->setGeometry(QRect(110, 110, 41, 17));
        ckbCore44 = new QCheckBox(frame);
        ckbCore44->setObjectName(QStringLiteral("ckbCore44"));
        ckbCore44->setGeometry(QRect(160, 110, 41, 17));
        ckbCore45 = new QCheckBox(frame);
        ckbCore45->setObjectName(QStringLiteral("ckbCore45"));
        ckbCore45->setGeometry(QRect(210, 110, 41, 17));
        ckbCore46 = new QCheckBox(frame);
        ckbCore46->setObjectName(QStringLiteral("ckbCore46"));
        ckbCore46->setGeometry(QRect(260, 110, 41, 17));
        ckbCore47 = new QCheckBox(frame);
        ckbCore47->setObjectName(QStringLiteral("ckbCore47"));
        ckbCore47->setGeometry(QRect(310, 110, 41, 17));
        ckbCore48 = new QCheckBox(frame);
        ckbCore48->setObjectName(QStringLiteral("ckbCore48"));
        ckbCore48->setGeometry(QRect(360, 110, 41, 17));
        ckbCore49 = new QCheckBox(frame);
        ckbCore49->setObjectName(QStringLiteral("ckbCore49"));
        ckbCore49->setGeometry(QRect(10, 130, 41, 17));
        ckbCore50 = new QCheckBox(frame);
        ckbCore50->setObjectName(QStringLiteral("ckbCore50"));
        ckbCore50->setGeometry(QRect(60, 130, 41, 17));
        ckbCore51 = new QCheckBox(frame);
        ckbCore51->setObjectName(QStringLiteral("ckbCore51"));
        ckbCore51->setGeometry(QRect(110, 130, 41, 17));
        ckbCore52 = new QCheckBox(frame);
        ckbCore52->setObjectName(QStringLiteral("ckbCore52"));
        ckbCore52->setGeometry(QRect(160, 130, 41, 17));
        ckbCore53 = new QCheckBox(frame);
        ckbCore53->setObjectName(QStringLiteral("ckbCore53"));
        ckbCore53->setGeometry(QRect(210, 130, 41, 17));
        ckbCore54 = new QCheckBox(frame);
        ckbCore54->setObjectName(QStringLiteral("ckbCore54"));
        ckbCore54->setGeometry(QRect(260, 130, 41, 17));
        ckbCore55 = new QCheckBox(frame);
        ckbCore55->setObjectName(QStringLiteral("ckbCore55"));
        ckbCore55->setGeometry(QRect(310, 130, 41, 17));
        ckbCore56 = new QCheckBox(frame);
        ckbCore56->setObjectName(QStringLiteral("ckbCore56"));
        ckbCore56->setGeometry(QRect(360, 130, 41, 17));
        ckbCore57 = new QCheckBox(frame);
        ckbCore57->setObjectName(QStringLiteral("ckbCore57"));
        ckbCore57->setGeometry(QRect(10, 150, 41, 17));
        ckbCore58 = new QCheckBox(frame);
        ckbCore58->setObjectName(QStringLiteral("ckbCore58"));
        ckbCore58->setGeometry(QRect(60, 150, 41, 17));
        ckbCore59 = new QCheckBox(frame);
        ckbCore59->setObjectName(QStringLiteral("ckbCore59"));
        ckbCore59->setGeometry(QRect(110, 150, 41, 17));
        ckbCore60 = new QCheckBox(frame);
        ckbCore60->setObjectName(QStringLiteral("ckbCore60"));
        ckbCore60->setGeometry(QRect(160, 150, 41, 17));
        ckbCore61 = new QCheckBox(frame);
        ckbCore61->setObjectName(QStringLiteral("ckbCore61"));
        ckbCore61->setGeometry(QRect(210, 150, 41, 17));
        ckbCore62 = new QCheckBox(frame);
        ckbCore62->setObjectName(QStringLiteral("ckbCore62"));
        ckbCore62->setGeometry(QRect(260, 150, 41, 17));
        ckbCore63 = new QCheckBox(frame);
        ckbCore63->setObjectName(QStringLiteral("ckbCore63"));
        ckbCore63->setGeometry(QRect(310, 150, 41, 17));
        ckbCore64 = new QCheckBox(frame);
        ckbCore64->setObjectName(QStringLiteral("ckbCore64"));
        ckbCore64->setGeometry(QRect(360, 150, 41, 17));
        cbProcessPrio = new QComboBox(Page_Settings_CPU);
        cbProcessPrio->setObjectName(QStringLiteral("cbProcessPrio"));
        cbProcessPrio->setGeometry(QRect(180, 220, 251, 22));
        lblProcessPrio = new QLabel(Page_Settings_CPU);
        lblProcessPrio->setObjectName(QStringLiteral("lblProcessPrio"));
        lblProcessPrio->setGeometry(QRect(0, 220, 151, 16));
        QFont font4;
        font4.setPointSize(9);
        font4.setBold(false);
        font4.setWeight(50);
        lblProcessPrio->setFont(font4);
        stack_settings->addWidget(Page_Settings_CPU);
        Page_Settings_TweaksATI = new QWidget();
        Page_Settings_TweaksATI->setObjectName(QStringLiteral("Page_Settings_TweaksATI"));
        dial = new QDial(Page_Settings_TweaksATI);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(150, 10, 141, 111));
        dial->setMinimum(-108);
        dial->setMaximum(108);
        dial->setSingleStep(1);
        dial->setPageStep(13);
        dial->setNotchesVisible(true);
        lblLOD = new QLabel(Page_Settings_TweaksATI);
        lblLOD->setObjectName(QStringLiteral("lblLOD"));
        lblLOD->setGeometry(QRect(10, 130, 431, 20));
        lblLOD->setFont(font4);
        lblLOD->setAlignment(Qt::AlignCenter);
        lblLODVal = new QLabel(Page_Settings_TweaksATI);
        lblLODVal->setObjectName(QStringLiteral("lblLODVal"));
        lblLODVal->setGeometry(QRect(10, 150, 431, 20));
        lblLODVal->setFont(font4);
        lblLODVal->setAlignment(Qt::AlignCenter);
        stack_settings->addWidget(Page_Settings_TweaksATI);
        Page_Settings_Benchmark = new QWidget();
        Page_Settings_Benchmark->setObjectName(QStringLiteral("Page_Settings_Benchmark"));
        cbHideError = new QComboBox(Page_Settings_Benchmark);
        cbHideError->setObjectName(QStringLiteral("cbHideError"));
        cbHideError->setGeometry(QRect(240, 100, 191, 22));
        lblOSD_2 = new QLabel(Page_Settings_Benchmark);
        lblOSD_2->setObjectName(QStringLiteral("lblOSD_2"));
        lblOSD_2->setGeometry(QRect(10, 100, 151, 16));
        lblOSD_2->setFont(font4);
        lblHideLogo = new QLabel(Page_Settings_Benchmark);
        lblHideLogo->setObjectName(QStringLiteral("lblHideLogo"));
        lblHideLogo->setGeometry(QRect(10, 40, 161, 16));
        lblHideLogo->setFont(font4);
        cbRunMode = new QComboBox(Page_Settings_Benchmark);
        cbRunMode->setObjectName(QStringLiteral("cbRunMode"));
        cbRunMode->setGeometry(QRect(240, 10, 191, 22));
        lblOSD = new QLabel(Page_Settings_Benchmark);
        lblOSD->setObjectName(QStringLiteral("lblOSD"));
        lblOSD->setGeometry(QRect(10, 70, 161, 16));
        lblOSD->setFont(font4);
        lblRunMode = new QLabel(Page_Settings_Benchmark);
        lblRunMode->setObjectName(QStringLiteral("lblRunMode"));
        lblRunMode->setGeometry(QRect(10, 10, 161, 16));
        lblRunMode->setFont(font1);
        cbOSD = new QComboBox(Page_Settings_Benchmark);
        cbOSD->setObjectName(QStringLiteral("cbOSD"));
        cbOSD->setGeometry(QRect(240, 70, 191, 22));
        cbHideLogo = new QComboBox(Page_Settings_Benchmark);
        cbHideLogo->setObjectName(QStringLiteral("cbHideLogo"));
        cbHideLogo->setGeometry(QRect(240, 40, 191, 22));
        stack_settings->addWidget(Page_Settings_Benchmark);
        Page_Settings_Interface = new QWidget();
        Page_Settings_Interface->setObjectName(QStringLiteral("Page_Settings_Interface"));
        slider_SSQuality = new QSlider(Page_Settings_Interface);
        slider_SSQuality->setObjectName(QStringLiteral("slider_SSQuality"));
        slider_SSQuality->setGeometry(QRect(240, 70, 191, 22));
        slider_SSQuality->setMinimum(0);
        slider_SSQuality->setMaximum(100);
        slider_SSQuality->setValue(50);
        slider_SSQuality->setSliderPosition(50);
        slider_SSQuality->setOrientation(Qt::Horizontal);
        slider_SSQuality->setTickPosition(QSlider::TicksBelow);
        lblSysInfo_2 = new QLabel(Page_Settings_Interface);
        lblSysInfo_2->setObjectName(QStringLiteral("lblSysInfo_2"));
        lblSysInfo_2->setGeometry(QRect(10, 10, 201, 16));
        lblSysInfo_2->setFont(font4);
        cbTheme = new QComboBox(Page_Settings_Interface);
        cbTheme->setObjectName(QStringLiteral("cbTheme"));
        cbTheme->setGeometry(QRect(240, 10, 191, 22));
        lblSysInfo_3 = new QLabel(Page_Settings_Interface);
        lblSysInfo_3->setObjectName(QStringLiteral("lblSysInfo_3"));
        lblSysInfo_3->setGeometry(QRect(10, 40, 211, 16));
        lblSysInfo_3->setFont(font4);
        cbScreenshotFormat = new QComboBox(Page_Settings_Interface);
        cbScreenshotFormat->setObjectName(QStringLiteral("cbScreenshotFormat"));
        cbScreenshotFormat->setGeometry(QRect(240, 40, 191, 22));
        lblSysInfo_4 = new QLabel(Page_Settings_Interface);
        lblSysInfo_4->setObjectName(QStringLiteral("lblSysInfo_4"));
        lblSysInfo_4->setGeometry(QRect(10, 70, 201, 16));
        lblSysInfo_4->setFont(font4);
        stack_settings->addWidget(Page_Settings_Interface);
        Page_Settings_Plugins_SI = new QWidget();
        Page_Settings_Plugins_SI->setObjectName(QStringLiteral("Page_Settings_Plugins_SI"));
        cbSIenabled = new QComboBox(Page_Settings_Plugins_SI);
        cbSIenabled->setObjectName(QStringLiteral("cbSIenabled"));
        cbSIenabled->setGeometry(QRect(240, 10, 191, 22));
        lblSysInfo = new QLabel(Page_Settings_Plugins_SI);
        lblSysInfo->setObjectName(QStringLiteral("lblSysInfo"));
        lblSysInfo->setGeometry(QRect(10, 10, 111, 16));
        lblSysInfo->setFont(font4);
        stack_settings->addWidget(Page_Settings_Plugins_SI);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        stacked_CompareOnline = new QStackedWidget(tab_3);
        stacked_CompareOnline->setObjectName(QStringLiteral("stacked_CompareOnline"));
        stacked_CompareOnline->setGeometry(QRect(0, 0, 611, 431));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        lblGfxScore_3 = new QLabel(page_5);
        lblGfxScore_3->setObjectName(QStringLiteral("lblGfxScore_3"));
        lblGfxScore_3->setGeometry(QRect(10, 199, 601, 51));
        lblGfxScore_3->setFont(font1);
        lblGfxScore_3->setScaledContents(true);
        lblGfxScore_3->setAlignment(Qt::AlignCenter);
        stacked_CompareOnline->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        tab_CompareOnline = new QTabWidget(page_6);
        tab_CompareOnline->setObjectName(QStringLiteral("tab_CompareOnline"));
        tab_CompareOnline->setGeometry(QRect(10, 10, 591, 411));
        tab_CompareOnline->setTabPosition(QTabWidget::West);
        tab_CompareOnline->setTabShape(QTabWidget::Rounded);
        tab_CompareOnline->setElideMode(Qt::ElideNone);
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        table_WR = new QTableWidget(tab_5);
        if (table_WR->columnCount() < 4)
            table_WR->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_WR->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_WR->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_WR->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_WR->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        table_WR->setObjectName(QStringLiteral("table_WR"));
        table_WR->setGeometry(QRect(0, 0, 561, 411));
        table_WR->setAutoFillBackground(false);
        table_WR->setFrameShape(QFrame::NoFrame);
        table_WR->setProperty("showDropIndicator", QVariant(false));
        table_WR->setDragDropOverwriteMode(false);
        table_WR->setAlternatingRowColors(true);
        table_WR->setSelectionMode(QAbstractItemView::NoSelection);
        table_WR->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_WR->setSortingEnabled(true);
        table_WR->horizontalHeader()->setDefaultSectionSize(150);
        table_WR->horizontalHeader()->setStretchLastSection(true);
        table_WR->verticalHeader()->setVisible(false);
        table_WR->verticalHeader()->setStretchLastSection(false);
        tab_CompareOnline->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        table_WR_2 = new QTableWidget(tab_6);
        if (table_WR_2->columnCount() < 4)
            table_WR_2->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_WR_2->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_WR_2->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_WR_2->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_WR_2->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        table_WR_2->setObjectName(QStringLiteral("table_WR_2"));
        table_WR_2->setGeometry(QRect(0, 70, 561, 341));
        table_WR_2->setAutoFillBackground(false);
        table_WR_2->setFrameShape(QFrame::NoFrame);
        table_WR_2->setProperty("showDropIndicator", QVariant(false));
        table_WR_2->setDragDropOverwriteMode(false);
        table_WR_2->setAlternatingRowColors(true);
        table_WR_2->setSelectionMode(QAbstractItemView::NoSelection);
        table_WR_2->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_WR_2->setSortingEnabled(true);
        table_WR_2->horizontalHeader()->setDefaultSectionSize(150);
        table_WR_2->horizontalHeader()->setStretchLastSection(true);
        table_WR_2->verticalHeader()->setVisible(false);
        table_WR_2->verticalHeader()->setStretchLastSection(false);
        comboBox = new QComboBox(tab_6);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 30, 221, 21));
        comboBox->setEditable(true);
        lblHideLogo_2 = new QLabel(tab_6);
        lblHideLogo_2->setObjectName(QStringLiteral("lblHideLogo_2"));
        lblHideLogo_2->setGeometry(QRect(10, 10, 151, 16));
        lblHideLogo_2->setFont(font4);
        lblHideLogo_3 = new QLabel(tab_6);
        lblHideLogo_3->setObjectName(QStringLiteral("lblHideLogo_3"));
        lblHideLogo_3->setGeometry(QRect(240, 10, 151, 16));
        lblHideLogo_3->setFont(font4);
        comboBox_2 = new QComboBox(tab_6);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(240, 30, 221, 21));
        comboBox_2->setEditable(true);
        lblHideLogo_4 = new QLabel(tab_6);
        lblHideLogo_4->setObjectName(QStringLiteral("lblHideLogo_4"));
        lblHideLogo_4->setGeometry(QRect(470, 10, 61, 16));
        lblHideLogo_4->setFont(font4);
        spinBox = new QSpinBox(tab_6);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(470, 30, 81, 22));
        tab_CompareOnline->addTab(tab_6, QString());
        stacked_CompareOnline->addWidget(page_6);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        toolBox = new QToolBox(tab_4);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(10, 10, 591, 421));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 100, 30));
        table_AboutModules = new QTableWidget(page);
        if (table_AboutModules->columnCount() < 3)
            table_AboutModules->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table_AboutModules->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table_AboutModules->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        table_AboutModules->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        if (table_AboutModules->rowCount() < 8)
            table_AboutModules->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        table_AboutModules->setVerticalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        table_AboutModules->setVerticalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        table_AboutModules->setVerticalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        table_AboutModules->setVerticalHeaderItem(3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        table_AboutModules->setVerticalHeaderItem(4, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        table_AboutModules->setVerticalHeaderItem(5, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        table_AboutModules->setVerticalHeaderItem(6, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        table_AboutModules->setVerticalHeaderItem(7, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        table_AboutModules->setItem(0, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        table_AboutModules->setItem(0, 1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        table_AboutModules->setItem(0, 2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        table_AboutModules->setItem(1, 0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        table_AboutModules->setItem(1, 1, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        table_AboutModules->setItem(1, 2, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        table_AboutModules->setItem(2, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        table_AboutModules->setItem(2, 1, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        table_AboutModules->setItem(2, 2, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        table_AboutModules->setItem(3, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        table_AboutModules->setItem(3, 1, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        table_AboutModules->setItem(3, 2, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        table_AboutModules->setItem(4, 0, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        table_AboutModules->setItem(4, 1, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        table_AboutModules->setItem(4, 2, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        table_AboutModules->setItem(5, 0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        table_AboutModules->setItem(5, 1, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        table_AboutModules->setItem(5, 2, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        table_AboutModules->setItem(6, 0, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        table_AboutModules->setItem(6, 1, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        table_AboutModules->setItem(6, 2, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        table_AboutModules->setItem(7, 0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        table_AboutModules->setItem(7, 1, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        table_AboutModules->setItem(7, 2, __qtablewidgetitem42);
        table_AboutModules->setObjectName(QStringLiteral("table_AboutModules"));
        table_AboutModules->setGeometry(QRect(0, 0, 591, 351));
        table_AboutModules->setAutoFillBackground(false);
        table_AboutModules->setProperty("showDropIndicator", QVariant(false));
        table_AboutModules->setDragDropOverwriteMode(false);
        table_AboutModules->setAlternatingRowColors(true);
        table_AboutModules->setSelectionMode(QAbstractItemView::NoSelection);
        table_AboutModules->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_AboutModules->setSortingEnabled(true);
        table_AboutModules->horizontalHeader()->setDefaultSectionSize(150);
        table_AboutModules->horizontalHeader()->setStretchLastSection(true);
        table_AboutModules->verticalHeader()->setVisible(false);
        table_AboutModules->verticalHeader()->setStretchLastSection(false);
        toolBox->addItem(page, QStringLiteral("About"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 591, 365));
        textEdit_2 = new QTextEdit(page_2);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(0, 0, 591, 351));
        QFont font5;
        font5.setFamily(QStringLiteral("Courier New"));
        font5.setBold(false);
        font5.setWeight(50);
        textEdit_2->setFont(font5);
        textEdit_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textEdit_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_2->setLineWrapMode(QTextEdit::NoWrap);
        textEdit_2->setReadOnly(true);
        toolBox->addItem(page_2, QStringLiteral("Changelog"));
        tabWidget->addTab(tab_4, QString());
        btnStart = new QPushButton(centralwidget);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setGeometry(QRect(510, 480, 121, 31));
        QFont font6;
        font6.setBold(true);
        font6.setWeight(75);
        btnStart->setFont(font6);
        btnStart->setDefault(true);
        btnSave = new QPushButton(centralwidget);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setEnabled(true);
        btnSave->setGeometry(QRect(360, 480, 141, 31));
        QFont font7;
        font7.setBold(false);
        font7.setWeight(50);
        btnSave->setFont(font7);
        lblHash = new QLabel(centralwidget);
        lblHash->setObjectName(QStringLiteral("lblHash"));
        lblHash->setGeometry(QRect(20, 480, 151, 16));
        QFont font8;
        font8.setPointSize(10);
        font8.setBold(false);
        font8.setItalic(true);
        font8.setWeight(50);
        lblHash->setFont(font8);
        frmMain->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(frmMain);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 21));
        menuApplication = new QMenu(menuBar);
        menuApplication->setObjectName(QStringLiteral("menuApplication"));
        menuDebug = new QMenu(menuBar);
        menuDebug->setObjectName(QStringLiteral("menuDebug"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        frmMain->setMenuBar(menuBar);

        menuBar->addAction(menuApplication->menuAction());
        menuBar->addAction(menuDebug->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuApplication->addAction(menu_Update);
        menuApplication->addSeparator();
        menuApplication->addAction(menu_Exit);
        menuDebug->addAction(menu_DumpLog);
        menuDebug->addSeparator();
        menuDebug->addAction(menu_DumpGPUZ);
        menuDebug->addAction(menu_DumpDMI);
        menuDebug->addAction(menu_DumpDXDIAG);
        menuDebug->addSeparator();
        menuDebug->addAction(menu_ClearBenchLogs);
        menuHelp->addAction(menu_wwwForums);
        menuHelp->addAction(menu_ReportBug);
        menuHelp->addSeparator();
        menuHelp->addAction(menu_wwwHWBOT);
        menuHelp->addAction(menu_wwwGenieben);

        retranslateUi(frmMain);

        tabWidget->setCurrentIndex(1);
        stackedWidget->setCurrentIndex(0);
        stack_settings->setCurrentIndex(5);
        stacked_CompareOnline->setCurrentIndex(1);
        tab_CompareOnline->setCurrentIndex(0);
        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(frmMain);
    } // setupUi

    void retranslateUi(QMainWindow *frmMain)
    {
        frmMain->setWindowTitle(QApplication::translate("frmMain", "HWBOT Aquamark\302\263", 0));
        menu_Update->setText(QApplication::translate("frmMain", "Check for Updates", 0));
        menu_Exit->setText(QApplication::translate("frmMain", "Exit", 0));
        menu_DumpLog->setText(QApplication::translate("frmMain", "Dump log file", 0));
        menu_DumpGPUZ->setText(QApplication::translate("frmMain", "Dump GPU-Z", 0));
        menu_DumpDMI->setText(QApplication::translate("frmMain", "Dump DMI", 0));
        menu_DumpDXDIAG->setText(QApplication::translate("frmMain", "Dump dxdiag", 0));
        menu_ClearBenchLogs->setText(QApplication::translate("frmMain", "Clear Benchmark logs", 0));
        menu_wwwHWBOT->setText(QApplication::translate("frmMain", "Visit HWBOT", 0));
        menu_wwwGenieben->setText(QApplication::translate("frmMain", "Visit my weblog", 0));
        menu_ReportBug->setText(QApplication::translate("frmMain", "Report bug", 0));
        menu_wwwForums->setText(QApplication::translate("frmMain", "Forums", 0));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        lblGfxScore->setText(QApplication::translate("frmMain", "GFX", 0));
        lblCpuScore->setText(QApplication::translate("frmMain", "CPU", 0));
        iconVGA->setText(QString());
        iconRAM->setText(QString());
        lblCPU_Speed->setText(QApplication::translate("frmMain", "-", 0));
        lblCPU_Socket->setText(QApplication::translate("frmMain", "-", 0));
        lblMB_SN->setText(QApplication::translate("frmMain", "-", 0));
        iconOS->setText(QString());
        lblCPU_Name->setText(QApplication::translate("frmMain", "-", 0));
        lblOS_DX->setText(QApplication::translate("frmMain", "-", 0));
        lblMB_Name->setText(QApplication::translate("frmMain", "-", 0));
        lblOS_ExtraInfo->setText(QApplication::translate("frmMain", "-", 0));
        lblRAM_Name->setText(QApplication::translate("frmMain", "-", 0));
        iconCPU->setText(QString());
        lblGFX_Speed->setText(QApplication::translate("frmMain", "-", 0));
        lblRAM_Size->setText(QApplication::translate("frmMain", "-", 0));
        lblMB_Bios->setText(QApplication::translate("frmMain", "-", 0));
        lblRAM_PN->setText(QApplication::translate("frmMain", "-", 0));
        lblOS_Name->setText(QApplication::translate("frmMain", "-", 0));
        iconMOBO->setText(QString());
        lblGFX_Name->setText(QApplication::translate("frmMain", "-", 0));
        lblGFX_Driver->setText(QApplication::translate("frmMain", "-", 0));
        lblGfxScore_2->setText(QApplication::translate("frmMain", "System Info is disabled.", 0));
        lblCPU_Name_2->setText(QApplication::translate("frmMain", "C1", 0));
        lblCPU_Name_3->setText(QApplication::translate("frmMain", "C2", 0));
        lblCPU_Name_4->setText(QApplication::translate("frmMain", "C3", 0));
        lblCPU_Name_5->setText(QApplication::translate("frmMain", "C6", 0));
        lblCPU_Name_6->setText(QApplication::translate("frmMain", "C5", 0));
        lblCPU_Name_7->setText(QApplication::translate("frmMain", "C4", 0));
        lblCPU_Name_8->setText(QApplication::translate("frmMain", "C9", 0));
        lblCPU_Name_9->setText(QApplication::translate("frmMain", "C8", 0));
        lblCPU_Name_10->setText(QApplication::translate("frmMain", "C7", 0));
        lblScore_C1->setText(QApplication::translate("frmMain", "-", 0));
        lblScore_C2->setText(QApplication::translate("frmMain", "-", 0));
        lblScore_C3->setText(QApplication::translate("frmMain", "-", 0));
        lblScore_C6->setText(QApplication::translate("frmMain", "-", 0));
        lblScore_C5->setText(QApplication::translate("frmMain", "-", 0));
        lblScore_C4->setText(QApplication::translate("frmMain", "-", 0));
        lblScore_C9->setText(QApplication::translate("frmMain", "-", 0));
        lblScore_C8->setText(QApplication::translate("frmMain", "-", 0));
        lblScore_C7->setText(QApplication::translate("frmMain", "-", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("frmMain", "Score", 0));
        tabWidget->setTabToolTip(tabWidget->indexOf(tab), QApplication::translate("frmMain", "Your results will be displayed here.", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("frmMain", "Settings", 0));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("frmMain", "Tweaks", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("frmMain", "Processor", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("frmMain", "Video Card", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem3->child(0);
        ___qtreewidgetitem4->setText(0, QApplication::translate("frmMain", "ATi / AMD", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem3->child(1);
        ___qtreewidgetitem5->setText(0, QApplication::translate("frmMain", "NVIDIA", 0));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem3->child(2);
        ___qtreewidgetitem6->setText(0, QApplication::translate("frmMain", "Intel", 0));
        QTreeWidgetItem *___qtreewidgetitem7 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem7->setText(0, QApplication::translate("frmMain", "Score", 0));
        QTreeWidgetItem *___qtreewidgetitem8 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem8->setText(0, QApplication::translate("frmMain", "Benchmark", 0));
        QTreeWidgetItem *___qtreewidgetitem9 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem9->setText(0, QApplication::translate("frmMain", "Interface", 0));
        QTreeWidgetItem *___qtreewidgetitem10 = treeWidget->topLevelItem(4);
        ___qtreewidgetitem10->setText(0, QApplication::translate("frmMain", "Plugins", 0));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem10->child(0);
        ___qtreewidgetitem11->setText(0, QApplication::translate("frmMain", "System Info", 0));
        treeWidget->setSortingEnabled(__sortingEnabled);

        gbCores->setTitle(QApplication::translate("frmMain", "Core Affinity", 0));
        ckbCore01->setText(QApplication::translate("frmMain", "1", 0));
        ckbCore02->setText(QApplication::translate("frmMain", "2", 0));
        ckbCore03->setText(QApplication::translate("frmMain", "3", 0));
        ckbCore04->setText(QApplication::translate("frmMain", "4", 0));
        ckbCore05->setText(QApplication::translate("frmMain", "5", 0));
        ckbCore06->setText(QApplication::translate("frmMain", "6", 0));
        ckbCore07->setText(QApplication::translate("frmMain", "7", 0));
        ckbCore08->setText(QApplication::translate("frmMain", "8", 0));
        ckbCore09->setText(QApplication::translate("frmMain", "9", 0));
        ckbCore10->setText(QApplication::translate("frmMain", "10", 0));
        ckbCore11->setText(QApplication::translate("frmMain", "11", 0));
        ckbCore12->setText(QApplication::translate("frmMain", "12", 0));
        ckbCore13->setText(QApplication::translate("frmMain", "13", 0));
        ckbCore14->setText(QApplication::translate("frmMain", "14", 0));
        ckbCore15->setText(QApplication::translate("frmMain", "15", 0));
        ckbCore16->setText(QApplication::translate("frmMain", "16", 0));
        ckbCore17->setText(QApplication::translate("frmMain", "17", 0));
        ckbCore18->setText(QApplication::translate("frmMain", "18", 0));
        ckbCore19->setText(QApplication::translate("frmMain", "19", 0));
        ckbCore20->setText(QApplication::translate("frmMain", "20", 0));
        ckbCore21->setText(QApplication::translate("frmMain", "21", 0));
        ckbCore22->setText(QApplication::translate("frmMain", "22", 0));
        ckbCore23->setText(QApplication::translate("frmMain", "23", 0));
        ckbCore24->setText(QApplication::translate("frmMain", "24", 0));
        ckbCore25->setText(QApplication::translate("frmMain", "25", 0));
        ckbCore26->setText(QApplication::translate("frmMain", "26", 0));
        ckbCore27->setText(QApplication::translate("frmMain", "27", 0));
        ckbCore28->setText(QApplication::translate("frmMain", "28", 0));
        ckbCore29->setText(QApplication::translate("frmMain", "29", 0));
        ckbCore30->setText(QApplication::translate("frmMain", "30", 0));
        ckbCore31->setText(QApplication::translate("frmMain", "31", 0));
        ckbCore32->setText(QApplication::translate("frmMain", "32", 0));
        ckbCore33->setText(QApplication::translate("frmMain", "33", 0));
        ckbCore34->setText(QApplication::translate("frmMain", "34", 0));
        ckbCore35->setText(QApplication::translate("frmMain", "35", 0));
        ckbCore36->setText(QApplication::translate("frmMain", "36", 0));
        ckbCore37->setText(QApplication::translate("frmMain", "37", 0));
        ckbCore38->setText(QApplication::translate("frmMain", "38", 0));
        ckbCore39->setText(QApplication::translate("frmMain", "39", 0));
        ckbCore40->setText(QApplication::translate("frmMain", "40", 0));
        ckbCore41->setText(QApplication::translate("frmMain", "41", 0));
        ckbCore42->setText(QApplication::translate("frmMain", "42", 0));
        ckbCore43->setText(QApplication::translate("frmMain", "43", 0));
        ckbCore44->setText(QApplication::translate("frmMain", "44", 0));
        ckbCore45->setText(QApplication::translate("frmMain", "45", 0));
        ckbCore46->setText(QApplication::translate("frmMain", "46", 0));
        ckbCore47->setText(QApplication::translate("frmMain", "47", 0));
        ckbCore48->setText(QApplication::translate("frmMain", "48", 0));
        ckbCore49->setText(QApplication::translate("frmMain", "49", 0));
        ckbCore50->setText(QApplication::translate("frmMain", "50", 0));
        ckbCore51->setText(QApplication::translate("frmMain", "51", 0));
        ckbCore52->setText(QApplication::translate("frmMain", "52", 0));
        ckbCore53->setText(QApplication::translate("frmMain", "53", 0));
        ckbCore54->setText(QApplication::translate("frmMain", "54", 0));
        ckbCore55->setText(QApplication::translate("frmMain", "55", 0));
        ckbCore56->setText(QApplication::translate("frmMain", "56", 0));
        ckbCore57->setText(QApplication::translate("frmMain", "57", 0));
        ckbCore58->setText(QApplication::translate("frmMain", "58", 0));
        ckbCore59->setText(QApplication::translate("frmMain", "59", 0));
        ckbCore60->setText(QApplication::translate("frmMain", "60", 0));
        ckbCore61->setText(QApplication::translate("frmMain", "61", 0));
        ckbCore62->setText(QApplication::translate("frmMain", "62", 0));
        ckbCore63->setText(QApplication::translate("frmMain", "63", 0));
        ckbCore64->setText(QApplication::translate("frmMain", "64", 0));
        cbProcessPrio->clear();
        cbProcessPrio->insertItems(0, QStringList()
         << QApplication::translate("frmMain", "Idle", 0)
         << QApplication::translate("frmMain", "Below Normal", 0)
         << QApplication::translate("frmMain", "Normal", 0)
         << QApplication::translate("frmMain", "Above Normal", 0)
         << QApplication::translate("frmMain", "High", 0)
         << QApplication::translate("frmMain", "Realtime", 0)
        );
#ifndef QT_NO_TOOLTIP
        cbProcessPrio->setToolTip(QApplication::translate("frmMain", "Use 'High' for a higher score.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        cbProcessPrio->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        cbProcessPrio->setCurrentText(QApplication::translate("frmMain", "Idle", 0));
#ifndef QT_NO_WHATSTHIS
        lblProcessPrio->setWhatsThis(QApplication::translate("frmMain", "How many resources the OS will allocate for the application.", 0));
#endif // QT_NO_WHATSTHIS
        lblProcessPrio->setText(QApplication::translate("frmMain", "Process Priority", 0));
#ifndef QT_NO_WHATSTHIS
        lblLOD->setWhatsThis(QApplication::translate("frmMain", "Use Manual if you experience problems with old cards or IGP.", 0));
#endif // QT_NO_WHATSTHIS
        lblLOD->setText(QApplication::translate("frmMain", "Level of Detail", 0));
#ifndef QT_NO_WHATSTHIS
        lblLODVal->setWhatsThis(QApplication::translate("frmMain", "Use Manual if you experience problems with old cards or IGP.", 0));
#endif // QT_NO_WHATSTHIS
        lblLODVal->setText(QApplication::translate("frmMain", "------", 0));
        cbHideError->clear();
        cbHideError->insertItems(0, QStringList()
         << QApplication::translate("frmMain", "True", 0)
         << QApplication::translate("frmMain", "False", 0)
        );
#ifndef QT_NO_TOOLTIP
        cbHideError->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        cbHideError->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lblOSD_2->setToolTip(QApplication::translate("frmMain", "If set to TRUE it will no longer ask the user if he wants to reset settings after a session that was closed prematurely.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lblOSD_2->setWhatsThis(QApplication::translate("frmMain", "Use Manual if you experience problems with old cards or IGP.", 0));
#endif // QT_NO_WHATSTHIS
        lblOSD_2->setText(QApplication::translate("frmMain", "Hide Reset Error", 0));
#ifndef QT_NO_WHATSTHIS
        lblHideLogo->setWhatsThis(QApplication::translate("frmMain", "Use Manual if you experience problems with old cards or IGP.", 0));
#endif // QT_NO_WHATSTHIS
        lblHideLogo->setText(QApplication::translate("frmMain", "Hide Logo", 0));
        cbRunMode->clear();
        cbRunMode->insertItems(0, QStringList()
         << QApplication::translate("frmMain", "AUTO", 0)
         << QApplication::translate("frmMain", "MANUAL", 0)
        );
#ifndef QT_NO_TOOLTIP
        cbRunMode->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        cbRunMode->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        lblOSD->setWhatsThis(QApplication::translate("frmMain", "Use Manual if you experience problems with old cards or IGP.", 0));
#endif // QT_NO_WHATSTHIS
        lblOSD->setText(QApplication::translate("frmMain", "OSD Statistics", 0));
#ifndef QT_NO_WHATSTHIS
        lblRunMode->setWhatsThis(QApplication::translate("frmMain", "Use Manual if you experience problems with old cards or IGP.", 0));
#endif // QT_NO_WHATSTHIS
        lblRunMode->setText(QApplication::translate("frmMain", "Run Mode", 0));
        cbOSD->clear();
        cbOSD->insertItems(0, QStringList()
         << QApplication::translate("frmMain", "True", 0)
         << QApplication::translate("frmMain", "False", 0)
        );
#ifndef QT_NO_TOOLTIP
        cbOSD->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        cbOSD->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        cbHideLogo->clear();
        cbHideLogo->insertItems(0, QStringList()
         << QApplication::translate("frmMain", "True", 0)
         << QApplication::translate("frmMain", "False", 0)
        );
#ifndef QT_NO_TOOLTIP
        cbHideLogo->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        cbHideLogo->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lblSysInfo_2->setToolTip(QApplication::translate("frmMain", "If set to TRUE it will no longer ask the user if he wants to reset settings after a session that was closed prematurely.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lblSysInfo_2->setWhatsThis(QApplication::translate("frmMain", "Use Manual if you experience problems with old cards or IGP.", 0));
#endif // QT_NO_WHATSTHIS
        lblSysInfo_2->setText(QApplication::translate("frmMain", "Theme", 0));
        cbTheme->clear();
        cbTheme->insertItems(0, QStringList()
         << QApplication::translate("frmMain", "Windows", 0)
         << QApplication::translate("frmMain", "WindowsXP", 0)
         << QApplication::translate("frmMain", "WindowsVista", 0)
         << QApplication::translate("frmMain", "Fusion", 0)
         << QApplication::translate("frmMain", "Fusion (Dark)", 0)
        );
#ifndef QT_NO_TOOLTIP
        cbTheme->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        cbTheme->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lblSysInfo_3->setToolTip(QApplication::translate("frmMain", "If set to TRUE it will no longer ask the user if he wants to reset settings after a session that was closed prematurely.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lblSysInfo_3->setWhatsThis(QApplication::translate("frmMain", "Use Manual if you experience problems with old cards or IGP.", 0));
#endif // QT_NO_WHATSTHIS
        lblSysInfo_3->setText(QApplication::translate("frmMain", "Screenshot Format", 0));
        cbScreenshotFormat->clear();
        cbScreenshotFormat->insertItems(0, QStringList()
         << QApplication::translate("frmMain", "PNG", 0)
         << QApplication::translate("frmMain", "JPG", 0)
        );
#ifndef QT_NO_TOOLTIP
        cbScreenshotFormat->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        cbScreenshotFormat->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lblSysInfo_4->setToolTip(QApplication::translate("frmMain", "If set to TRUE it will no longer ask the user if he wants to reset settings after a session that was closed prematurely.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lblSysInfo_4->setWhatsThis(QApplication::translate("frmMain", "Use Manual if you experience problems with old cards or IGP.", 0));
#endif // QT_NO_WHATSTHIS
        lblSysInfo_4->setText(QApplication::translate("frmMain", "Screenshot Quality", 0));
        cbSIenabled->clear();
        cbSIenabled->insertItems(0, QStringList()
         << QApplication::translate("frmMain", "Enabled", 0)
         << QApplication::translate("frmMain", "Disabled", 0)
        );
#ifndef QT_NO_TOOLTIP
        cbSIenabled->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        cbSIenabled->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lblSysInfo->setToolTip(QApplication::translate("frmMain", "If set to TRUE it will no longer ask the user if he wants to reset settings after a session that was closed prematurely.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lblSysInfo->setWhatsThis(QApplication::translate("frmMain", "Use Manual if you experience problems with old cards or IGP.", 0));
#endif // QT_NO_WHATSTHIS
        lblSysInfo->setText(QApplication::translate("frmMain", "System Info", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("frmMain", "Settings", 0));
        tabWidget->setTabToolTip(tabWidget->indexOf(tab_2), QApplication::translate("frmMain", "Faaasterr!", 0));
        lblGfxScore_3->setText(QApplication::translate("frmMain", "You are not connected to the Internet or\n"
"the query could not be performed.", 0));
        QTableWidgetItem *___qtablewidgetitem = table_WR->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("frmMain", "#", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_WR->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("frmMain", "Score", 0));
        QTableWidgetItem *___qtablewidgetitem2 = table_WR->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("frmMain", "Overclocker", 0));
        QTableWidgetItem *___qtablewidgetitem3 = table_WR->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("frmMain", "Video Card", 0));
        tab_CompareOnline->setTabText(tab_CompareOnline->indexOf(tab_5), QApplication::translate("frmMain", "World Records", 0));
        QTableWidgetItem *___qtablewidgetitem4 = table_WR_2->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("frmMain", "#", 0));
        QTableWidgetItem *___qtablewidgetitem5 = table_WR_2->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("frmMain", "Score", 0));
        QTableWidgetItem *___qtablewidgetitem6 = table_WR_2->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("frmMain", "Overclocker", 0));
        QTableWidgetItem *___qtablewidgetitem7 = table_WR_2->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("frmMain", "Video Card", 0));
#ifndef QT_NO_WHATSTHIS
        lblHideLogo_2->setWhatsThis(QApplication::translate("frmMain", "Use Manual if you experience problems with old cards or IGP.", 0));
#endif // QT_NO_WHATSTHIS
        lblHideLogo_2->setText(QApplication::translate("frmMain", "Processor", 0));
#ifndef QT_NO_WHATSTHIS
        lblHideLogo_3->setWhatsThis(QApplication::translate("frmMain", "Use Manual if you experience problems with old cards or IGP.", 0));
#endif // QT_NO_WHATSTHIS
        lblHideLogo_3->setText(QApplication::translate("frmMain", "Video Card", 0));
#ifndef QT_NO_WHATSTHIS
        lblHideLogo_4->setWhatsThis(QApplication::translate("frmMain", "Use Manual if you experience problems with old cards or IGP.", 0));
#endif // QT_NO_WHATSTHIS
        lblHideLogo_4->setText(QApplication::translate("frmMain", "Limit", 0));
        tab_CompareOnline->setTabText(tab_CompareOnline->indexOf(tab_6), QApplication::translate("frmMain", "Browse", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("frmMain", "Compare Online", 0));
        tabWidget->setTabToolTip(tabWidget->indexOf(tab_3), QApplication::translate("frmMain", "Browse through  Aqumark scores submitted on HWBOT", 0));
        QTableWidgetItem *___qtablewidgetitem8 = table_AboutModules->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("frmMain", "Module", 0));
        QTableWidgetItem *___qtablewidgetitem9 = table_AboutModules->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("frmMain", "Version", 0));
        QTableWidgetItem *___qtablewidgetitem10 = table_AboutModules->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("frmMain", "Author", 0));
        QTableWidgetItem *___qtablewidgetitem11 = table_AboutModules->verticalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("frmMain", "1", 0));
        QTableWidgetItem *___qtablewidgetitem12 = table_AboutModules->verticalHeaderItem(1);
        ___qtablewidgetitem12->setText(QApplication::translate("frmMain", "2", 0));
        QTableWidgetItem *___qtablewidgetitem13 = table_AboutModules->verticalHeaderItem(2);
        ___qtablewidgetitem13->setText(QApplication::translate("frmMain", "3", 0));
        QTableWidgetItem *___qtablewidgetitem14 = table_AboutModules->verticalHeaderItem(3);
        ___qtablewidgetitem14->setText(QApplication::translate("frmMain", "4", 0));
        QTableWidgetItem *___qtablewidgetitem15 = table_AboutModules->verticalHeaderItem(4);
        ___qtablewidgetitem15->setText(QApplication::translate("frmMain", "5", 0));
        QTableWidgetItem *___qtablewidgetitem16 = table_AboutModules->verticalHeaderItem(5);
        ___qtablewidgetitem16->setText(QApplication::translate("frmMain", "6", 0));
        QTableWidgetItem *___qtablewidgetitem17 = table_AboutModules->verticalHeaderItem(6);
        ___qtablewidgetitem17->setText(QApplication::translate("frmMain", "7", 0));
        QTableWidgetItem *___qtablewidgetitem18 = table_AboutModules->verticalHeaderItem(7);
        ___qtablewidgetitem18->setText(QApplication::translate("frmMain", "8", 0));

        const bool __sortingEnabled1 = table_AboutModules->isSortingEnabled();
        table_AboutModules->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem19 = table_AboutModules->item(0, 0);
        ___qtablewidgetitem19->setText(QApplication::translate("frmMain", "Wrapper", 0));
        QTableWidgetItem *___qtablewidgetitem20 = table_AboutModules->item(0, 1);
        ___qtablewidgetitem20->setText(QApplication::translate("frmMain", "2.55", 0));
        QTableWidgetItem *___qtablewidgetitem21 = table_AboutModules->item(0, 2);
        ___qtablewidgetitem21->setText(QApplication::translate("frmMain", "GENiEBEN", 0));
        QTableWidgetItem *___qtablewidgetitem22 = table_AboutModules->item(1, 0);
        ___qtablewidgetitem22->setText(QApplication::translate("frmMain", "Aquamark 3", 0));
        QTableWidgetItem *___qtablewidgetitem23 = table_AboutModules->item(1, 1);
        ___qtablewidgetitem23->setText(QApplication::translate("frmMain", "3.00", 0));
        QTableWidgetItem *___qtablewidgetitem24 = table_AboutModules->item(1, 2);
        ___qtablewidgetitem24->setText(QApplication::translate("frmMain", "JoWood Productions Software AG / Massive Development GmbH", 0));
        QTableWidgetItem *___qtablewidgetitem25 = table_AboutModules->item(2, 0);
        ___qtablewidgetitem25->setText(QApplication::translate("frmMain", "Qt Framework", 0));
        QTableWidgetItem *___qtablewidgetitem26 = table_AboutModules->item(2, 1);
        ___qtablewidgetitem26->setText(QApplication::translate("frmMain", "5.2.0", 0));
        QTableWidgetItem *___qtablewidgetitem27 = table_AboutModules->item(2, 2);
        ___qtablewidgetitem27->setText(QApplication::translate("frmMain", "Digia Plc and its subsidiaries", 0));
        QTableWidgetItem *___qtablewidgetitem28 = table_AboutModules->item(3, 0);
        ___qtablewidgetitem28->setText(QApplication::translate("frmMain", "dmidecode", 0));
        QTableWidgetItem *___qtablewidgetitem29 = table_AboutModules->item(3, 1);
        ___qtablewidgetitem29->setText(QApplication::translate("frmMain", "2.12", 0));
        QTableWidgetItem *___qtablewidgetitem30 = table_AboutModules->item(3, 2);
        ___qtablewidgetitem30->setText(QApplication::translate("frmMain", "Anton Arapov / GENiEBEN", 0));
        QTableWidgetItem *___qtablewidgetitem31 = table_AboutModules->item(4, 0);
        ___qtablewidgetitem31->setText(QApplication::translate("frmMain", "GPU-Z", 0));
        QTableWidgetItem *___qtablewidgetitem32 = table_AboutModules->item(4, 1);
        ___qtablewidgetitem32->setText(QApplication::translate("frmMain", "0.7.5", 0));
        QTableWidgetItem *___qtablewidgetitem33 = table_AboutModules->item(4, 2);
        ___qtablewidgetitem33->setText(QApplication::translate("frmMain", "TechPowerUp", 0));
        QTableWidgetItem *___qtablewidgetitem34 = table_AboutModules->item(5, 0);
        ___qtablewidgetitem34->setText(QApplication::translate("frmMain", "wget", 0));
        QTableWidgetItem *___qtablewidgetitem35 = table_AboutModules->item(5, 1);
        ___qtablewidgetitem35->setText(QApplication::translate("frmMain", "1.11.4", 0));
        QTableWidgetItem *___qtablewidgetitem36 = table_AboutModules->item(5, 2);
        ___qtablewidgetitem36->setText(QApplication::translate("frmMain", "Hrvoje Nik\305\241i\304\207, Giuseppe Scrivano.", 0));
        QTableWidgetItem *___qtablewidgetitem37 = table_AboutModules->item(6, 0);
        ___qtablewidgetitem37->setText(QApplication::translate("frmMain", "OpenSSL", 0));
        QTableWidgetItem *___qtablewidgetitem38 = table_AboutModules->item(6, 1);
        ___qtablewidgetitem38->setText(QApplication::translate("frmMain", "1.0.1.3", 0));
        QTableWidgetItem *___qtablewidgetitem39 = table_AboutModules->item(6, 2);
        ___qtablewidgetitem39->setText(QApplication::translate("frmMain", "openssl.org/about", 0));
        QTableWidgetItem *___qtablewidgetitem40 = table_AboutModules->item(7, 0);
        ___qtablewidgetitem40->setText(QApplication::translate("frmMain", "Theme - Dark Fusion", 0));
        QTableWidgetItem *___qtablewidgetitem41 = table_AboutModules->item(7, 1);
        ___qtablewidgetitem41->setText(QApplication::translate("frmMain", "-", 0));
        QTableWidgetItem *___qtablewidgetitem42 = table_AboutModules->item(7, 2);
        ___qtablewidgetitem42->setText(QApplication::translate("frmMain", "QuantumCD", 0));
        table_AboutModules->setSortingEnabled(__sortingEnabled1);

        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("frmMain", "About", 0));
        textEdit_2->setHtml(QApplication::translate("frmMain", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Courier New'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.56.111</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] System Info Library updated to v1.11, with the following changes:</span></p>\n"
"<p style=\" ma"
                        "rgin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--HD5750 is no longer detected as HD6750</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--New Drivers:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.55.110</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell"
                        " Dlg 2'; font-size:8pt;\">[NEW] A copy of the screenshot integrated into scorefile is stored in installation folder.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Crash when opening 'Compare Online' without Internet connection.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Default screenshot format is PNG 50% as JPG is not working under Windows XP.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Increased range of screenshot quality from 30-100 to 0-100.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0p"
                        "x; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] System Info Library updated to v1.10, with the following changes:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--New Drivers: Cat 13.12 WHQL/WU</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.54.109</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-si"
                        "ze:8pt;\">[FIX] Log files were not written to disk.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[NEW] Added support for Window Themes.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[NEW] Added 'Compare Online' feature.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[NEW] Added settings for Screenshot format (PNG/JPG) and quality (30 to 100), to prevent huge scorefiles.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\""
                        ">[UPD] GUI adjusments for 125% DPI.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Qt Framework updated from 5.1.1 to 5.2.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Settings are saved each time they are changed rather than waiting to press START.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] System Info Library updated to v1.09, with the following changes:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-siz"
                        "e:8pt;\">--Added detection for AVEXIR Core 2400, Team Xtreme Vulcan 1600</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--New GPUs: GMA X4500, GMA 4500MHD, GMA 4500, GMA 500 Mobile, GMA 900 Mobile, GMA 900, MARS II</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Updated GPU-Z to v0.7.5</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.53.108</span"
                        "></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Menus 'Forums' and 'Clear Aq3 Logs' now work.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Minor GUI changes and fixes.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Separated benchmark specific code from GUI code and further optimized for speed and memory usage.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Certains brands are renamed when saving t"
                        "he scorefile to match with HWBOT's database.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] System Info Library updated to v1.08, with the following changes:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Improved detection of RAM Vendor &amp; P/N</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--New Drivers: Cat13.11 WHQ/Beta9.4/Beta9.5</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--New GPUs: MSI 7970 Refere"
                        "nce / TwinFrozrIII / Lightning</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Improved CPU Socket detection</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--New SKUs: Toshiba Satellite P755-11T, HP Envy 6-1076ez</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Renamed </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic; color:#000000;\">CardExpert Technology</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; color:#000000;\"> to</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic; colo"
                        "r:#000000;\"> Gainward</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; color:#000000;\">, </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic; color:#000000;\">BFT Tech </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; color:#000000;\">to </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic; color:#000000;\">BFG</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; color:#000000;\">, </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic; color:#000000;\">Palit Microsystems </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; color:#000000;\">to </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic; color:#000000;\">Palit</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt; font"
                        "-style:italic;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.52.107</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] LOD did not work on all systems.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Video Card icon did not display properly..</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Windows XP '0 score' and AUTO mode.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px"
                        "; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[NEW] Changed the installar from AHK to NSIS in order to avoid false positives from AV software.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[NEW] Added menus.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[NEW] Added shortcuts: F7 (Save to Desktop) and Ctrl+S (Start Benchmark).</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Additional security checks (Thanks </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:"
                        "8pt; font-style:italic;\">BarboNet</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Code cleanup and optimizing.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] System Info Library updated to v1.07, with the following changes:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic;\">Sony Corporation</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\"> is renamed to </span><span style=\" font-fa"
                        "mily:'MS Shell Dlg 2'; font-size:8pt; font-style:italic;\">SONY</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic;\">--</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">Empty RAM slots are skipped when reading RAM P/N, Cfg Speed, Rated Speed</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Improved RAM Vendor codes list</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic;\">EDO DIMM </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">was"
                        " renamed to </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic;\">EDO</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic;\">--</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">OS ServicePack detection routine disabled on W8/8.1</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic;\">--</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">Some strings will be trimmed under VMWare Player and VirtualPC/XPMode</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--New video cards: HD5970"
                        "</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">KNOWN ISSUES</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">*Startup is slowed down by dxdiag.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">*WinXP: benchmark doesn't go full screen and is </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic;\">Not Responding </span><span style=\" fon"
                        "t-family:'MS Shell Dlg 2'; font-size:8pt;\">if a Windows Explorer window is opened.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">*WinXP: GFX driver detection fails</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.51.106</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Missing dll libraries missing from installer package.</span></p>\n"
"<p st"
                        "yle=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Some icons were not displayed on NVIDIA systems.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Registry setting</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic;\"> background</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\"> did not work properly.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[REM] Default background 'circuits' was removed to keep a cleaner look and smaller exe size.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-rig"
                        "ht:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] If </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic;\">LODAdj </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\"> is not found, it will assume it is not an ATI/AMD card.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] System Info Library updated to v1.06, with the following changes:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Code cleanup and fixing that prevented the application from running on some systems where expected information was missing.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:"
                        "0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Empty RAM slots are skipped when reading Vendor name.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Detection mechanism of NVIDIA Display INF file changed</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--New BIOS Vendors: Phoenix, Award, InsydeH2O</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Detection of DirectX version</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\""
                        "><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Detection of GFX used output ports (VGA/DVI/HDMI etc.)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--New Drivers: Cat13.11 B9.2</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Completed Radeon R9 series.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">KNOWN ISSUES</span></p>\n"
"<p style=\" margin"
                        "-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">*Startup is slowed down by dxdiag.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.50.105</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[NEW] Complete rewrite in Qt5/C++</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:"
                        "'MS Shell Dlg 2'; font-size:8pt;\">[NEW] 'About' page with proper credits and a changelog.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Settings now include a couple more features that were previously unavailable or not user changeable.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] System Info Library updated to v1.05, with the following changes:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Got rid of WMI dependency</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"
                        "\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Ram Information: vendor, module count, rated/configured speeds, p/n, total capacity, maximum capacity</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Processor Information: vendor, name, family, freq, bus, count, active threads, socket/package, max freq</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Bios Information: version, revision, build date, firmware revision, vendor</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Motherboard Informaion: vendor, name (based on sku for notebooks), revision, "
                        "s/n, socket count</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Hewlett-Packard Portable SKUs countrification</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--New SKUs: HP Folio 13-1050ez, HP ProBook 430 G1, HP Spectre XP Pro (various), HP ProBook 4340s, HP ProBook 4740s (various), HP Envy d7 (various), HP Envy 17 (various), HP EliteBook 8770 (various)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--New CPUs: QX9770, i7 995X, i7 ###QM, FX-9590 ES</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; "
                        "text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--New RAM vendors: Walton Chaintech, Ramaxel, G.Skill, KINGMAX, Princeton, GeIL, Nanya, Crucial, Patriot, Qimonda, Swissbit, Corsair, Elpida, TeamGroup, OCZ, A-DATA, Kingston, Itec Memory, WINTEC, Super PC Memory, GoldenRAM, DATARAM, Smart Modular, Transcend, Micron, Mosel Vitelic, Samsung, Infineon, NEC, AMD, Xerox, Apple, HP, SK Hynix, Mushkin, ASint, Winbond.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--New GPUs: Radeon R7 Series, Radeon R9 Series</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--New Drivers: Cat13.2/13.3 BETA detection fix, Cat13.9 WHQL, Cat13.10 B2, Cat13.11 B1/3/6/7, All NVIDIA drivers (generic), couple Intel"
                        " GMA/HD/Iris from branches 6/8/9.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.27.104</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Main GUI will no longer display CPU speed.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] System Info Library updated to v1.04, with the following changes:</span></p>\n"
"<p style=\" margin-top:0px; m"
                        "argin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Code cleanup</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Detection for Catalyst 13.10 BETA</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.27.103</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8"
                        "pt;\">[FIX] Temporarly removed detected CPU frequency from scorefile to avoid website parsing error.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.26.102</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Application versioning will include smaller increments for SI library updates.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] System "
                        "Info Library updated to v1.02, with the following changes:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Extensive Subvendor list for VGA</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Can read VRAM quantity</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Added couple more ATI/AMD cards (mostly HD7/8 series)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Intel BIOS versions are shortened to display only releva"
                        "nt info</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Fixed code errors that prevented race conditions to work</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">--Can display ATI/AMD driver friendly name and differentiate BETA versions </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">   (GPU-Z can't tell if it's beta or WHQL) from 11.11 up to 13.8B2</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
""
                        "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.26.000</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Improved security.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Logo's alpha channel didn't work on older cards displaying a black background.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Save and Open CPUZ/GPUZ buttons will not be shown if benchmark was aborted.</span></p>\n"
"<p style=\" mar"
                        "gin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[ADD] Basic system info displayed into main window. (WMI service must be ON).</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[ADD] User can select benchmark settings between Manual and Auto. Use manual for old cards/IGP.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[ADD] Multiple cores affinity (artificially limited up to 8 threads for now).</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[ADD] Norwe"
                        "gian translation (Thanks </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic;\">Maximous</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] GUI Redesigned to allow more information and future skins.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Installer will let you install on 98/ME but there is no guarantee it will work.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Improved translations in RO/IT/FR (Thanks </span><span style=\" font-family:'MS Sh"
                        "ell Dlg 2'; font-size:8pt; font-style:italic;\">Christian Ney</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[REM] VC Redis will no longer be installed on 6.x systems as it's not needed.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[REM] Removed 'Submit online' button until it works better.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" fo"
                        "nt-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.25.000</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Score was not saved on some stripped Windows XP systems.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Error Exception if WMI is not enabled on your system.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Installer contains the VC++ 2008 v9.0 x86/x64 redis.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS She"
                        "ll Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.24.000</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[ADD] You can now select 'All Cores' for process affinity.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[ADD] F1 hotkey for a quick Debug Message.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[ADD] F7 hotkey for a quicksave on desktop. It will not check for CPUZ/GPUZ!<"
                        "/span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Changed icon to original Aquamark green icon.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Updated RO translation.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[REM] Results are saved directly on desktop instead of 'Aquamark Results' folder.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px;"
                        " margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.23.000</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Datafile was not saved if the videocard name contained illegal character (Thanks </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic;\">mtech</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Completed Persian/Farsi translation (Thanks </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic;\">Olesius</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">)"
                        "</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.22.000</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Memory Tab was not opened in CPU-Z OC version. (Thanks </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic;\">topdog</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS She"
                        "ll Dlg 2'; font-size:8pt;\">[ADD] Partial Persian/Farsi translation. (Thanks </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic;\">Olesius</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[ADD] Hover mouse icon for HWBOT logo.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] TRISCORE is displayed using a bigger font size.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-r"
                        "ight:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.21.000</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Button 'STEP1' is not shown if benchmark was aborted using ESC key.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Main GUI did not load after benchmark closed.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[REM] Removed the 'Check for updates' button because feature is not implemented yet.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0"
                        "px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.20.000</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Stuck in a loop when trying to detect CPUZ.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Uninstaller deletes registry keys left in Wow6432Node.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shel"
                        "l Dlg 2'; font-size:8pt;\">[ADD] Pressing ESC during benchmark will quit instead of abort.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.19.000</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] STEP1 button no longer worked if there was an error in CPUZ detection.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] When manually browsing fo"
                        "r GPUZ the filter is *.exe instead of gpuz.exe</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[ADD] Spanish Translation (Thanks</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic;\"> Sweet</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Improved startup dialog.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Can detect custom CPUZ versions (ROG/G1/OC)</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; m"
                        "argin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.18.000</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] On Windows 7 with Classic Theme applied the screen couldn't be captured for SS.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Duplicate score files are renamed instead of being overwritten.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style="
                        "\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] The main GUI no longer starts with its titlebar underneath Windows taskbar.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Smarter window arrangement.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Minor GUI changes to improve i18n for both Wrapper and installer.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Wrapper will check if aquamark executable exists before trying to open it.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-inden"
                        "t:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Exception Catch for the 'Submit' button and Logo click.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Romanian translation updated.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[ADD] Dutch translation (Thanks </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic;\">Massman</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[ADD] Will check for local CPU-Z/GPU-Z.</span></p"
                        ">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[REM] CPU-Z and GPU-Z are no longer bundled with the wrapper installer.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[REM] CPU-Z is no longer used to read CPU/RAM/Motherboard info due licensing issues.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[REM] Keyboard/Mouse input is no longer blocked during STEP1.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
""
                        "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.17.000</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Score swap fixed.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Installer is a little more compact.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[ADD] Italian Translation (Thanks </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic;\">Christian Ney</span><span style=\""
                        " font-family:'MS Shell Dlg 2'; font-size:8pt;\">).</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[ADD] German Translation (Thanks </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic;\">der8auer</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">).</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] New logo and minor GUI changes.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] aquamark.exe renamed to aquamark3.exe to avoid graphic driver app specific tweaks.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; "
                        "margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.16.000</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Added a new HWBOT logo as </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-style:italic;\">Massman</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\"> suggested.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Save/Submit buttons only appear after"
                        " pressing the previous button(s) to avoid empty scores.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] i18n support based on Windows language. User can't manually change it.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600;\">2.08.000</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Fixed the archiving process.</span></p>\n"
"<p style=\" marg"
                        "in-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Improved Win 8 support.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[FIX] Minor GUI fixes</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Supresses GPU-Z &quot;Install&quot; option automatically</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Uninstaller selfdeletes</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; te"
                        "xt-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Removed the HASH check of the 2 dll's</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">[UPD] Inputbox sets default affinity to last core</span></p></body></html>", 0));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("frmMain", "Changelog", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("frmMain", "About", 0));
        tabWidget->setTabToolTip(tabWidget->indexOf(tab_4), QApplication::translate("frmMain", "Keep up with the changes.", 0));
        btnStart->setText(QApplication::translate("frmMain", "START", 0));
        btnStart->setShortcut(QApplication::translate("frmMain", "Ctrl+S", 0));
        btnSave->setText(QApplication::translate("frmMain", "Save to desktop", 0));
        btnSave->setShortcut(QApplication::translate("frmMain", "F7", 0));
        lblHash->setText(QApplication::translate("frmMain", "-", 0));
        menuApplication->setTitle(QApplication::translate("frmMain", "Application", 0));
        menuDebug->setTitle(QApplication::translate("frmMain", "Debug", 0));
        menuHelp->setTitle(QApplication::translate("frmMain", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class frmMain: public Ui_frmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
