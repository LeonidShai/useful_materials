QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Data2Send.cpp \
    TaskExecutor.cpp \
    TcpConfig.cpp \
    TcpServer.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    Data2Send.h \
    MainWindow.h \
    TaskExecutor.h \
    TcpConfig.h \
    TcpServer.h

FORMS += \
    MainWindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
