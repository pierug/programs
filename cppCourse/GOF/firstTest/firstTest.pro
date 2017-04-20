#-------------------------------------------------
#
# Project created by QtCreator 2017-04-13T15:02:02
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_firsttesttest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_firsttesttest.cpp \
    ../gangOfFour/abstractfactory.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../gangOfFour/abstractfactory.h
