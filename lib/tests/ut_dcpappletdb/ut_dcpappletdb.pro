include(../common_top.pri)

INCLUDEPATH += $$system(find $$SRCDIR -type d)

TARGET = ut_dcpappletdb

TEST_SOURCES = \
    $$SRCDIR/appletdb/dcpappletdb.cpp \
    $$SRCDIR/appletdb/dcpappletmetadata.cpp

# unit test and unit
SOURCES += \
    ut_dcpappletdb.cpp \
    $$TEST_SOURCES \ 

# base classes
SOURCES += \


# unit test and unit
HEADERS += \
    ut_dcpappletdb.h \
    $$SRCDIR/appletdb/dcpappletdb.h \

# base classes
HEADERS += \


# service classes
HEADERS += \

DATADIR = $${DCP_PREFIX}/share/libduicontrolpanel-tests/ut_dcpappletdb
DEFINES += DATADIR=\\\"$${DATADIR}\\\"
desktops1.files += desktops/*.desktop
desktops1.path = $${DATADIR}/desktops
desktops2.files += desktops2/*.desktop
desktops2.path = $${DATADIR}/desktops2
desktops3.files += desktops3/*.desktop
desktops3.path = $${DATADIR}/desktops3

INSTALLS += desktops1 desktops2 desktops3
