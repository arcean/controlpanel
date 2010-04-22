include(../common_top.pri)

CONFIG += meegotouch
 
INCLUDEPATH += $$system(find $$SRCDIR -type d)
INCLUDEPATH += $$LIBDCPINCLUDE 
TARGET = ut_dcpcomponent

TEST_SOURCES = \
    $$SRCDIR/component/dcpcomponent.cpp 

# unit test and unit
SOURCES += \
    ut_dcpcomponent.cpp \
    $$TEST_SOURCES 

# base classes
SOURCES += $$SRCDIR/page/pages.cpp


# unit test and unit
HEADERS += \
    ut_dcpcomponent.h \
    $$SRCDIR/include/* \
    $$SRCDIR/component/dcpcomponent.h 

# base classes
#HEADERS += 


# service classes
#HEADERS += 


