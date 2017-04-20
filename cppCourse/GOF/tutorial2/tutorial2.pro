QT += widgets testlib

SOURCES = testqstring.cpp \
    testqstring.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/tutorial2
INSTALLS += target
