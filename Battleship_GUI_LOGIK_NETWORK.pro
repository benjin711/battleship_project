#-------------------------------------------------
#
# Project created by QtCreator 2018-03-16T16:59:54
#
#-------------------------------------------------

QT       += core gui network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Batlleship_GUI_LOGIK_NETWORK
TEMPLATE = app


SOURCES += \
    button.cpp \
    client.cpp \
    controls.cpp \
    main.cpp \
    network.cpp \
    server.cpp \
    spielfeld.cpp \
    startfenster.cpp \
    board.cpp \
    ship.cpp \
    player.cpp \
    game.cpp

HEADERS  += \
    button.h \
    client.h \
    controls.h \
    network.h \
    server.h \
    spielfeld.h \
    startfenster.h \
    ship.h \
    board.h \
    player.h \
    game.h

FORMS    += \
    mainwindow.ui \
    spielfeld.ui \
    startfenster.ui

CONFIG += c++14

SUBDIRS += \
    Battleship_GUI_LOGIK.pro \
    Battleship_GUI_LOGIK.pro

DISTFILES +=

RESOURCES += \
    bilder.qrc
