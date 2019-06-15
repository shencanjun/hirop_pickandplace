TEMPLATE = lib
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
TARGET = hsr_generator

DEFINES += __LINUX__

SOURCES +=  \
    src/generator.cpp

HEADERS += \
    include/generator.h \
    ../3rd/include/hlibload.h \
    ../3rd/include/hplugin_define.h \
    ../3rd/include/hplugin.h \
    ../3rd/include/hpluginloader.h \
    ../hirop_PickPlace/include/igenerator.h \
    ../hirop_PickPlace/include/pickandplac.h \
    ../hirop_PickPlace/include/c_base_generator.h
    /opt/ros/indigo/include

INCLUDEPATH += /opt/ros/indigo/include/ \
                              ../hirop_PickPlace/include/


LIBS += -Wl,-rpath=/home/fshs/hirop_pickandplace/3rd/libs  -L/home/fshs/hirop_pickandplace/3rd/libs -ldl -lHPlugin
