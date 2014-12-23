TEMPLATE = app
CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -std=c++11

LIBS += -ljson
LIBS += -lncurses

SOURCES += *.cpp
HEADERS += *.h

include(deployment.pri)


qtcAddDeployment()

OTHER_FILES += \
    README.md \
    LICENSE

