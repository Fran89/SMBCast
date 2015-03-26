#-------------------------------------------------
#
# Project created by QtCreator 2015-03-24T22:30:17
#
#-------------------------------------------------

QT       += core gui xml positioning

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SMBCast
TEMPLATE = app


SOURCES += main.cpp\
        smbcast.cpp \
    smclass.cpp \
    smbconf.cpp

HEADERS  += smbcast.h \
    smclass.h \
    smbconf.h

FORMS    += smbcast.ui \
    smbconf.ui

#CONFIG += static plugin

OTHER_FILES +=
