QT += core
QT -= gui

CONFIG += c++11

TARGET = GoogleTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../googletest-master/googletest/msvc/gtest-md/release/ -lgtestd
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../googletest-master/googletest/msvc/gtest-md/debug/ -lgtestd
else:unix: LIBS += -L$$PWD/../../googletest-master/googletest/msvc/gtest-md/ -lgtestd

INCLUDEPATH += $$PWD/../../googletest-master/googletest/msvc/gtest-md/Debug
DEPENDPATH += $$PWD/../../googletest-master/googletest/msvc/gtest-md/Debug
