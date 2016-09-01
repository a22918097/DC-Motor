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
    dcmotor.cpp \
    mythread.cpp \
    myrobot.cpp

HEADERS  += mainwindow.h \
    dcmotor.h \
    mythread.h \
    myrobot.h

FORMS    += mainwindow.ui


OpenCV_Lib = $$quote(C:\opencv\build\x64\vc12\lib)

INCLUDEPATH +=  $$quote(C:\opencv\build\include)

    Release: LIBS +=    $$OpenCV_Lib/opencv_ts300.lib\
                        $$OpenCV_Lib/opencv_world300.lib \
                        #$$qdarkstyle/style.qrc

    Debug: LIBS +=      $$OpenCV_Lib/opencv_ts300d.lib\
                        $$OpenCV_Lib/opencv_world300d.lib \
                        #$$qdarkstyle/style.qrc
