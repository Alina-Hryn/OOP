#-------------------------------------------------
#
# Project created by QtCreator 2019-06-17T09:29:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = exam_2sem
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    workwithfiles.cpp \
    slcircular.cpp \
    newperson.cpp \
    sorting.cpp \
    listofpersons.cpp

HEADERS += \
        mainwindow.h \
    workwithfiles.h \
    slcircular.h \
    newperson.h \
    sorting.h \
    singleton.h \
    listofpersons.h \
    sortFactory.h \
    splaytree.h \
    bptree.h

FORMS += \
        mainwindow.ui \
    newperson.ui \
    sorting.ui \
    listofpersons.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    officials.qrc
