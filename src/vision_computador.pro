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
        main.cpp \
        view/mainwindow.cpp \
        view/view.cpp \
        controller/controller.cpp \
        model/model.cpp \
        view/canvas_window.cpp \
        view/options_dock.cpp \
        model/picture.cpp \
        view/footer.cpp \
        ensure_close_dialog.cpp \
        image_operation.cpp \
        operation_color_to_black.cpp \
        model/histogram.cpp \
        view/histogram_widget.cpp \
        view/chart_representation.cpp \
        view/canvas_image_label.cpp \
    controller/indexed_action.cpp \
    view/operation_options_widget.cpp \
    controller/plugin_contoller.cpp \
    view/image_info_widget.cpp

HEADERS += \
        view/mainwindow.h \
        view/view.h \
        controller/controller.h \
        model/model.h \
        view/canvas_window.h \
        view/options_dock.h \
        model/picture.h \
        view/footer.h \
        ensure_close_dialog.h \
        image_operation.h \
        operation_color_to_black.h \
        model/histogram.h \
        view/histogram_widget.h \
        view/chart_representation.h \
        view/canvas_image_label.h \
    controller/plugin_interface.h \
    controller/indexed_action.h \
    view/operation_options_widget.h \
    controller/plugin_contoller.h \
    controller/view_interface.h \
    view/image_info_widget.h

FORMS += \
        view/mainwindow.ui
        
#COMMAND = "mv vision_computador ../build/"
              
QMAKE_POST_LINK += $$COMMAND
