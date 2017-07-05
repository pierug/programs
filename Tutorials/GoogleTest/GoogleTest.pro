#-------------------------------------------------
#
# Project created by QtCreator 2017-03-10T15:32:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GoogleTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    include/gtest/internal/custom/gtest-port.h \
    include/gtest/internal/custom/gtest-printers.h \
    include/gtest/internal/custom/gtest.h \
    include/gtest/internal/gtest-death-test-internal.h \
    include/gtest/internal/gtest-filepath.h \
    include/gtest/internal/gtest-internal.h \
    include/gtest/internal/gtest-linked_ptr.h \
    include/gtest/internal/gtest-param-util-generated.h \
    include/gtest/internal/gtest-param-util.h \
    include/gtest/internal/gtest-port-arch.h \
    include/gtest/internal/gtest-port.h \
    include/gtest/internal/gtest-string.h \
    include/gtest/internal/gtest-tuple.h \
    include/gtest/internal/gtest-tuple.h.pump \
    include/gtest/internal/gtest-type-util.h \
    include/gtest/gtest-death-test.h \
    include/gtest/gtest-message.h \
    include/gtest/gtest-param-test.h \
    include/gtest/gtest-param-test.h.pump \
    include/gtest/gtest-printers.h \
    include/gtest/gtest-spi.h \
    include/gtest/gtest-test-part.h \
    include/gtest/gtest-typed-test.h \
    include/gtest/gtest.h \
    include/gtest/gtest_pred_impl.h \
    include/gtest/gtest_prod.h \
    include/gtest/gtest/internal/custom/gtest-port.h \
    include/gtest/gtest/internal/custom/gtest-printers.h \
    include/gtest/gtest/internal/custom/gtest.h \
    include/gtest/gtest/internal/gtest-death-test-internal.h \
    include/gtest/gtest/internal/gtest-filepath.h \
    include/gtest/gtest/internal/gtest-internal.h \
    include/gtest/gtest/internal/gtest-linked_ptr.h \
    include/gtest/gtest/internal/gtest-param-util-generated.h \
    include/gtest/gtest/internal/gtest-param-util.h \
    include/gtest/gtest/internal/gtest-port-arch.h \
    include/gtest/gtest/internal/gtest-port.h \
    include/gtest/gtest/internal/gtest-string.h \
    include/gtest/gtest/internal/gtest-tuple.h \
    include/gtest/gtest/internal/gtest-tuple.h.pump \
    include/gtest/gtest/internal/gtest-type-util.h \
    include/gtest/internal/custom/gtest-port.h \
    include/gtest/internal/custom/gtest-printers.h \
    include/gtest/internal/custom/gtest.h \
    include/gtest/internal/gtest-death-test-internal.h \
    include/gtest/internal/gtest-filepath.h \
    include/gtest/internal/gtest-internal.h \
    include/gtest/internal/gtest-linked_ptr.h \
    include/gtest/internal/gtest-param-util-generated.h \
    include/gtest/internal/gtest-param-util.h \
    include/gtest/internal/gtest-port-arch.h \
    include/gtest/internal/gtest-port.h \
    include/gtest/internal/gtest-string.h \
    include/gtest/internal/gtest-tuple.h \
    include/gtest/internal/gtest-tuple.h.pump \
    include/gtest/internal/gtest-type-util.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../googletest-master/googletest/msvc/gtest-md/release/ -lgtestd
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../googletest-master/googletest/msvc/gtest-md/debug/ -lgtestd
else:unix: LIBS += -L$$PWD/../../googletest-master/googletest/msvc/gtest-md/ -lgtestd

INCLUDEPATH += $$PWD/../../googletest-master/googletest/msvc/gtest-md/Debug
DEPENDPATH += $$PWD/../../googletest-master/googletest/msvc/gtest-md/Debug

DISTFILES += \
    include/gtest/internal/gtest-param-util-generated.h.pump \
    include/gtest/internal/gtest-type-util.h.pump \
    include/gtest/gtest/internal/gtest-param-util-generated.h.pump \
    include/gtest/gtest/internal/gtest-type-util.h.pump \
    include/gtest/internal/gtest-param-util-generated.h.pump \
    include/gtest/internal/gtest-type-util.h.pump
