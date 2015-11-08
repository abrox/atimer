TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    atimer.cpp \
    ../mqttsn/lib/utils.cpp

HEADERS += \
    callback.h \
    atimer.h \
    ../mqttsn/lib/utils.h

INCLUDEPATH +=../mqttsn/lib/

QMAKE_CXXFLAGS += -DLINUX
QMAKE_CXXFLAGS += -DMQTT_DEBUG
