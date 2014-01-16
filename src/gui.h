#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QMainWindow>
#include <QtGui>
#include <QTreeWidgetItem>

extern QStringList applog;
extern QString _printlog();
extern void SetTheme(QString name);

namespace Ui {
class frmMain;
}

class frmMain : public QMainWindow
{
    Q_OBJECT

public:

    explicit frmMain(QWidget *parent = 0);

    ~frmMain();


private slots:

    void on_btnStart_clicked();

    void on_btnSave_clicked();

    void on_dial_valueChanged(int value);

    void on_menu_DumpLog_triggered();

    void on_menu_Update_triggered();

    void on_menu_wwwHWBOT_triggered();

    void on_menu_wwwGenieben_triggered();

    void on_menu_ReportBug_triggered();

    void on_menu_DumpGPUZ_triggered();

    void on_menu_DumpDMI_triggered();

    void on_menu_DumpDXDIAG_triggered();

    void on_menu_Exit_triggered();

    void on_menu_wwwForums_triggered();

    void on_menu_ClearBenchLogs_triggered();

    void on_cbSIenabled_currentIndexChanged(int index);

    void on_cbTheme_currentIndexChanged(const QString &arg1);

    void on_tabWidget_currentChanged(int index);

    void on_cbRunMode_currentIndexChanged(const QString &arg1);

    void on_cbHideLogo_currentIndexChanged(const QString &arg1);

    void on_cbHideError_currentIndexChanged(const QString &arg1);

    void on_cbOSD_currentIndexChanged(const QString &arg1);

    void on_cbSIenabled_currentIndexChanged(const QString &arg1);

    void on_cbProcessPrio_currentIndexChanged(const QString &arg1);

    void on_slider_SSQuality_valueChanged(int value);

    void on_cbScreenshotFormat_currentIndexChanged(const QString &arg1);
    
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::frmMain *ui;


};

#endif // FRMMAIN_H
