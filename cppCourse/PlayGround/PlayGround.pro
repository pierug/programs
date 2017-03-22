QT += core
QT -= gui

CONFIG += c++11

TARGET = PlayGround
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    effort.cpp

HEADERS += \
    effort.h
