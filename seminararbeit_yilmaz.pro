#-------------------------------------------------
#
# Project created by QtCreator 2018-07-30T17:41:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = Tutorial
TEMPLATE = app


SOURCES += main.cpp \
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    health.cpp \
    player.cpp \
    score.cpp \
    zeichenfeld.cpp \

HEADERS  += \
    bullet.h \
    enemy.h \
    game.h \
    health.h \
    player.h \
    score.h \
    zeichenfeld.h \

RESOURCES += \
    img.qrc
