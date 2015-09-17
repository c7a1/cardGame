TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp \
    card.cpp \
    deck.cpp

HEADERS += \
    card.h \
    deck.h

