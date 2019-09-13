#-------------------------------------------------
#
# Project created by QtCreator 2014-09-26T13:04:42
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = stockbuddy2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    register.cpp \
    welcome.cpp \
    prompt.cpp \
    buy.cpp \
    sell.cpp \
    summary.cpp \
    update.cpp \
    reciept.cpp

HEADERS  += mainwindow.h \
    register.h \
    welcome.h \
    prompt.h \
    buy.h \
    sell.h \
    summary.h \
    update.h \
    reciept.h

FORMS    += mainwindow.ui \
    register.ui \
    welcome.ui \
    prompt.ui \
    buy.ui \
    sell.ui \
    summary.ui \
    update.ui \
    reciept.ui
