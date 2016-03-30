QT += core
QT -= gui

TARGET = IntroductionToAlgorithms
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    ../C_Source/main.cpp

HEADERS += \
    ../C_Source/quicksort.hpp \
    ../C_Source/heapsort.hpp \
    ../C_Source/maxheap.hpp

