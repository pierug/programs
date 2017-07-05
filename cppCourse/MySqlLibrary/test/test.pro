#-------------------------------------------------
#
# Project created by QtCreator 2017-04-14T21:51:53
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_testtest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_testtest.cpp\
../database.cpp

HEADERS += ../database.h

DEFINES += SRCDIR=\\\"$$PWD/\\\"

