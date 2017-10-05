#-------------------------------------------------
#
# Project created by QtCreator 2017-09-25T10:49:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vision_computador
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        src/main.cpp \
        src/mainwindow.cpp \
    src/view.cpp \
    src/controller.cpp \
    src/model.cpp \    
    src/canvas_window.cpp \
    src/options_dock.cpp \
    src/picture.cpp \
    src/footer.cpp \
    src/canvas_image_label.cpp \
    src/ensure_close_dialog.cpp \
    src/image_operation.cpp \
    src/operation_color_to_black.cpp

HEADERS += \
        src/mainwindow.h \
    src/view.h \
    src/controller.h \
    src/model.h \    
    src/canvas_window.h \
    src/options_dock.h \
    src/picture.h \
    src/footer.h \
    src/canvas_image_label.h \
    src/ensure_close_dialog.h \
    src/image_operation.h \
    src/operation_color_to_black.h

FORMS += \
        src/mainwindow.ui
