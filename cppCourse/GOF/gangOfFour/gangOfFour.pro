TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    singleton.cpp

HEADERS += \
    singleton.h \
    abstractfactory.h \
    prototype.h \
    factorymethod.h \
    builder.h
