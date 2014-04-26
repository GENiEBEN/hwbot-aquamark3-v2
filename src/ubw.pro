#-------------------------------------------------
#
# Project created by QtCreator 2013-09-05T15:41:30
#
#-------------------------------------------------

QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml

TARGET = ubw
TEMPLATE = app

# The application version
VERSION_APP = 2.56.111
# Define the preprocessor macro to get the application version in our application.
DEFINES += APP_VERSION=\\\"$$VERSION_APP\\\"

SOURCES += main.cpp security.cpp \
    gui.cpp \
    aquamark3.cpp \
    functions.cpp \
    hwbotapi.cpp \
    sysinfo.cpp

HEADERS  += security.h \
    gui.h \
    aquamark3.h \
    functions.h \
    hwbotapi.h \
    sysinfo.h

FORMS    += \
    gui.ui

RESOURCES += \
    res.qrc

QMAKE_CXXFLAGS_RELEASE += -O3 -ffast-math -ftracer

RC_ICONS = res\icon.ico
