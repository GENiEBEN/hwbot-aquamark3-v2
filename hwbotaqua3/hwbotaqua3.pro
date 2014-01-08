#-------------------------------------------------
#
# Project created by QtCreator 2013-09-05T15:41:30
#
#-------------------------------------------------

QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml

TARGET = hwbotaqua3
TEMPLATE = app

# The application version
VERSION_APP = 2.55.110
# Define the preprocessor macro to get the application version in our application.
DEFINES += APP_VERSION=\\\"$$VERSION_APP\\\"

SOURCES += main.cpp sysinfo.cpp security.cpp \
    gui.cpp \
    aquamark3.cpp \
    functions.cpp \
    hwbotapi.cpp

HEADERS  += sysinfo.h security.h \
    gui.h \
    aquamark3.h \
    functions.h \
    hwbotapi.h

FORMS    += \
    gui.ui

RESOURCES += \
    res.qrc

QMAKE_CXXFLAGS_RELEASE += -O3 -ffast-math -ftracer

RC_ICONS = icon.ico

