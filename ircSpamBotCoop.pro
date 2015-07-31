#-------------------------------------------------
#
# Project created by QtCreator 2015-07-03T01:31:39
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ircSpamBotCoop
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    loginwindow.cpp \
    partyservice.cpp \
    jsonparser.cpp \
    spamsystem.cpp \
    loginpassinputdialog.cpp \
    tinylogger.cpp

HEADERS  += mainwindow.h \
    loginwindow.h \
    partyservice.h \
    jsonparser.h \
    spamsystem.h \
    loginpassinputdialog.h \
    tinylogger.h

FORMS    += mainwindow.ui \
    loginwindow.ui \
    loginpassinputdialog.ui

RESOURCES += \
    res.qrc
