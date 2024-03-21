TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../firstProject/firebase_cpp_sdk/include


LIBS += -L../firstProject/firebase_cpp_sdk/libs/linux/x86_64/legacy
LIBS += -ljsoncpp -lcurl

SOURCES += \
    airqualitydatamanager.cpp \
    apicontroller.cpp \
    datamanager.cpp \
    locationmanager.cpp \
    main.cpp \
    mainmenu.cpp \
    usersettings.cpp \
    weatherdatamanager.cpp

HEADERS += \
    airqualitydatamanager.h \
    apicontroller.h \
    datamanager.h \
    locationmanager.h \
    mainmenu.h \
    usersettings.h \
    weatherdatamanager.h
