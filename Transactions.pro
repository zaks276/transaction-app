#-------------------------------------------------
#
# Project created by QtCreator 2021-07-27T14:29:07
#
#-------------------------------------------------

QT       += core gui
QT       += xml
CONFIG   += console


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Transactions
TEMPLATE = app


SOURCES += main.cpp\
        bankingtransactions.cpp \
    transaction.cpp \
    transactionlist.cpp \
    transactioncontroller.cpp \
    xmlfilewriter.cpp \
    sort.cpp \
    selectionsort.cpp \
    insertionsort.cpp \
    sortfactory.cpp

HEADERS  += bankingtransactions.h \
    transaction.h \
    transactionlist.h \
    transactioncontroller.h \
    xmlfilewriter.h \
    sort.h \
    selectionsort.h \
    insertionsort.h \
    sortfactory.h

FORMS    += bankingtransactions.ui
