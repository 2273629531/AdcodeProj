#-------------------------------------------------
#
# Project created by QtCreator 2018-11-28T16:21:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ReadAdcode
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    adcoderead.cpp \
    area.cpp

HEADERS  += mainwindow.h \
    adcoderead.h \
    area.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
