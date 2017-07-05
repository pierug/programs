QT += core
QT -= gui

CONFIG += c++11

TARGET = testqt
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    testsomething.cpp

HEADERS += \
    testsomething.h
