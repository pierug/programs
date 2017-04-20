QT += core
QT -= gui

CONFIG += c++11

TARGET = Test_1_Praca
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    singleton.cpp

HEADERS += \
    singleton.h
