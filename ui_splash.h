/********************************************************************************
** Form generated from reading UI file 'splash.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPLASH_H
#define UI_SPLASH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_splash
{
public:
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *splash)
    {
        if (splash->objectName().isEmpty())
            splash->setObjectName(QStringLiteral("splash"));
        splash->resize(320, 240);
        centralwidget = new QWidget(splash);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        splash->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(splash);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        splash->setStatusBar(statusbar);

        retranslateUi(splash);

        QMetaObject::connectSlotsByName(splash);
    } // setupUi

    void retranslateUi(QMainWindow *splash)
    {
        splash->setWindowTitle(QApplication::translate("splash", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class splash: public Ui_splash {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPLASH_H
