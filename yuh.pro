QT       += core gui concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    cpu.cpp \
    disk.cpp \
    gpu.cpp \
    network.cpp \
    ram.cpp

HEADERS += \
    mainwindow.h \
    cpu.h \
    disk.h \
    gpu.h \
    network.h \
    ram.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    yuh_en_US.ts

CONFIG += lrelease
CONFIG += embed_translations

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
