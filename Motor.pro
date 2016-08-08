#-------------------------------------------------
#
# Project created by QtCreator 2016-07-24T21:38:36
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Motor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dcmotor.cpp

HEADERS  += mainwindow.h \
    dcmotor.h

FORMS    += mainwindow.ui
