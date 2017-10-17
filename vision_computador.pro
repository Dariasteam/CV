#-------------------------------------------------
#
# Project created by QtCreator 2017-09-25T10:49:06
#
#-------------------------------------------------

QT       += core gui charts

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
        src/view/mainwindow.cpp \
        src/view/view.cpp \
        src/controller/controller.cpp \
        src/model/model.cpp \
        src/view/canvas_window.cpp \
        src/view/options_dock.cpp \
        src/model/picture.cpp \
        src/view/footer.cpp \
        src/ensure_close_dialog.cpp \
        src/image_operation.cpp \
        src/operation_color_to_black.cpp \
        src/model/histogram.cpp \
        src/view/histogram_widget.cpp \
        src/view/chart_representation.cpp \
        src/view/canvas_image_label.cpp

HEADERS += \
        src/view/mainwindow.h \
        src/view/view.h \
        src/controller/controller.h \
        src/model/model.h \
        src/view/canvas_window.h \
        src/view/options_dock.h \
        src/model/picture.h \
        src/view/footer.h \
        src/ensure_close_dialog.h \
        src/image_operation.h \
        src/operation_color_to_black.h \
        src/model/histogram.h \
        src/view/histogram_widget.h \
        src/view/chart_representation.h \
        src/view/canvas_image_label.h \
        src/controller/plugin_connector.h

FORMS += \
        src/view/mainwindow.ui
