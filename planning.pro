TEMPLATE = app
CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -std=c++11

LIBS += -ljson
LIBS += -lncurses++
LIBS += -lncurses
LIBS += -lpanel
LIBS += -lmenu

SOURCES += *.cpp \
    editor/planningeditor.cpp \
    editor/planningmenu.cpp \
    editor/planningitems.cpp
HEADERS += *.h \
    editor/planningeditor.h \
    editor/planningmenu.h \
    editor/planningitems.h

include(deployment.pri)


qtcAddDeployment()

OTHER_FILES += \
    README.md \
    LICENSE

