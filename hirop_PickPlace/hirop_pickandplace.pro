TEMPLATE = lib
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11
QMAKE_LFLAGS += -std=c++11 -Wl,--export-dynamic

DEFINES += __LINUX__

SOURCES += \
    src/c_base_generator.cpp \
    src/c_base_pickPlace.cpp \
    src/cpp_loader.cpp \
    src/pickPlace_execute.cpp \
    src/configuer.cpp

INCLUDEPATH += ./include/ \
                               /opt/ros/indigo/include/ \
                               /home/fshs/yaml-cpp/include/

HEADERS += \
    ../3rd/include/hlibload.h \
    ../3rd/include/hplugin_define.h \
    ../3rd/include/hplugin.h \
    include/igrab_operation.h \
    ../3rd/include/hpluginloader.h \
    include/c_base_generator.h \
    include/c_base_pickPlace.h \
    include/cpp_loader.h \
    include/igenerator.h \
    include/ipickPlace.h \
    include/pickandplac.h \
    include/pickPlace_execute.h \
    include/configuer.h

LIBS += -Wl,-rpath=$$PWD/../3rd/libs  -L$$PWD/../3rd/libs -ldl -lHPlugin
LIBS += -L$$HOME/yaml-cpp/build/libyaml-cpp
