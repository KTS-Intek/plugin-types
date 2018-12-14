QT       += core

linux-beagleboard-g++:{
   QT -= gui
}

INCLUDEPATH  += $$PWD

HEADERS += \
    $$PWD/shared/meterplugin.h \
    $$PWD/shared/meterplugintypes.h
