/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "view/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "load_image"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 9), // "file_name"
QT_MOC_LITERAL(4, 33, 10), // "save_image"
QT_MOC_LITERAL(5, 44, 1), // "i"
QT_MOC_LITERAL(6, 46, 12), // "on_bttn_load"
QT_MOC_LITERAL(7, 59, 12), // "on_bttn_save"
QT_MOC_LITERAL(8, 72, 16), // "on_image_focused"
QT_MOC_LITERAL(9, 89, 19), // "on_no_focused_image"
QT_MOC_LITERAL(10, 109, 13), // "on_add_plugin"
QT_MOC_LITERAL(11, 123, 15), // "indexed_action*"
QT_MOC_LITERAL(12, 139, 8), // "category"
QT_MOC_LITERAL(13, 148, 4), // "name"
QT_MOC_LITERAL(14, 153, 5) // "index"

    },
    "MainWindow\0load_image\0\0file_name\0"
    "save_image\0i\0on_bttn_load\0on_bttn_save\0"
    "on_image_focused\0on_no_focused_image\0"
    "on_add_plugin\0indexed_action*\0category\0"
    "name\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    2,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   57,    2, 0x08 /* Private */,
       7,    1,   60,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x08 /* Private */,
      10,    3,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt,    3,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 11, QMetaType::QString, QMetaType::QString, QMetaType::UInt,   12,   13,   14,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->load_image((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->save_image((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 2: _t->on_bttn_load((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_bttn_save((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_image_focused(); break;
        case 5: _t->on_no_focused_image(); break;
        case 6: { indexed_action* _r = _t->on_add_plugin((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< indexed_action**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::load_image)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString , unsigned  );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::save_image)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::load_image(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::save_image(QString _t1, unsigned  _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
