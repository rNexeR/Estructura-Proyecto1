#-------------------------------------------------
#
# Project created by QtCreator 2015-05-24T11:34:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Estructura-Proyecto1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tamagotchi.cpp \
    CrearTamagotchi.cpp \
    Cuidar.cpp

HEADERS  += mainwindow.h \
    Nodo.h \
    Pila.h \
    Cola.h \
    tamagotchi.h \
    constantes.h \
    CrearTamagotchi.h \
    Cuidar.h

FORMS    += mainwindow.ui \
    CrearTamagotchi.ui \
    Cuidar.ui

RESOURCES += \
    resources.qrc
