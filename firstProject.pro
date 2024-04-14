TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


LIBS += -ljsoncpp -lcurl


SOURCES += \
    airqualitydatamanager.cpp \
    apicontroller.cpp \
    dataexporter.cpp \
    datamanager.cpp \
    historicalweatherdatamanager.cpp \
    locationmanager.cpp \
    main.cpp \
    mainmenu.cpp \
    userpreferences.cpp \
    utility.cpp \
    weatherdatamanager.cpp

HEADERS += \
    airqualitydatamanager.h \
    apicontroller.h \
    dataexporter.h \
    datamanager.h \
    historicalweatherdatamanager.h \
    locationmanager.h \
    mainmenu.h \
    userpreferences.h \
    utility.h \
    weatherdatamanager.h
