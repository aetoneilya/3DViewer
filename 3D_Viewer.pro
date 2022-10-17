QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl openglwidgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(QtGifImage/src/gifimage/qtgifimage.pri)

SOURCES += \
    ./main.cc \
    ./view/main_window.cc \
    ./view/opengl_widget.cc \
    ./model/model.cc \
    ./model/drawer/drawer.cc \
    ./model/settings/settings.cc \
    ./model/filereader/filereader.cc \
    ./controller/controller.cc

HEADERS += \
    ./model/model.h \
    ./model/drawer/drawer.h \
    ./model/filereader/filereader.h \
    ./model/filereader/basefilereader.h \
    ./model/drawer/figure/figure.h \
    ./model/settings/settings.h \
    ./controller/controller.h \
    ./view/main_window.h \
    ./view/opengl_widget.h

FORMS += \
    ./view/resources/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

ICON = ./view/icons/3dViewer.ico