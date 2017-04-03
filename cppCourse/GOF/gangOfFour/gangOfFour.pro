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
    builder.h \
    adapter1.h \
    decorator.h \
    facade.h \
    proxy.h \
    composite.h \
    ceocomposite.h \
    bridge.h \
    flyweight.h \
    templatemethod.h
