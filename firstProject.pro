TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -ljsoncpp -lcurl

SOURCES += \
        apicontroller.cpp \
        debugaid.cpp \
        locationmanager.cpp \
        main.cpp \
        uicontroller.cpp

HEADERS += \
    apicontroller.h \
    debugaid.h \
    locationmanager.h \
    uicontroller.h

