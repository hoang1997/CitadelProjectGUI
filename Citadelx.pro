#-------------------------------------------------
#
# Project created by QtCreator 2018-07-25T10:22:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CitadelX
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    add_layer.cpp \
    add_obstruction.cpp \
    add_attacker.cpp \
    layer.cpp \
    attacker.cpp \
    layeritem.cpp \
    savefile.cpp \
    algorithms.cpp \
    updatelayer.cpp \
    updateattacker.cpp

HEADERS += \
        mainwindow.h \
    add_layer.h \
    add_obstruction.h \
    add_attacker.h \
    layer.h \
    attacker.h \
    layeritem.h \
    savefile.h \
    algorithms.h \
    updatelayer.h \
    updateattacker.h

FORMS += \
        mainwindow.ui \
    add_layer.ui \
    add_obstruction.ui \
    add_attacker.ui \
    savefile.ui \
    updatelayer.ui \
    updateattacker.ui

RESOURCES +=
