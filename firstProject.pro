TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../firstProject/firebase_cpp_sdk/include


LIBS += -L../firstProject/firebase_cpp_sdk/libs/linux/x86_64/legacy
LIBS += -ljsoncpp -lcurl

SOURCES += \
    apicontroller.cpp \
    locationmanager.cpp \
    main.cpp \
    uicontroller.cpp \
    usersettings.cpp \
    weatherdatamanager.cpp

HEADERS += \
    apicontroller.h \
    locationmanager.h \
    uicontroller.h \
    usersettings.h \
    weatherdatamanager.h
