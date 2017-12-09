TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /usr/local/include/fastdb
LIBS += -L/usr/local/lib -lfastdb

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

