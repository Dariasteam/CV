/****************************************************************************
** Meta object code from reading C++ file 'canvas_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "view/canvas_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canvas_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_canvas_window_t {
    QByteArrayData data[7];
    char stringdata0[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_canvas_window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_canvas_window_t qt_meta_stringdata_canvas_window = {
    {
QT_MOC_LITERAL(0, 0, 13), // "canvas_window"
QT_MOC_LITERAL(1, 14, 10), // "set_active"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 2), // "id"
QT_MOC_LITERAL(4, 29, 5), // "close"
QT_MOC_LITERAL(5, 35, 12), // "focusInEvent"
QT_MOC_LITERAL(6, 48, 12) // "QFocusEvent*"

    },
    "canvas_window\0set_active\0\0id\0close\0"
    "focusInEvent\0QFocusEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_canvas_window[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::UInt,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    5,

       0        // eod
};

void canvas_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        canvas_window *_t = static_cast<canvas_window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->set_active((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: _t->close((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 2: _t->focusInEvent((*reinterpret_cast< QFocusEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (canvas_window::*_t)(unsigned  );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&canvas_window::set_active)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (canvas_window::*_t)(unsigned  );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&canvas_window::close)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject canvas_window::staticMetaObject = {
    { &QMdiSubWindow::staticMetaObject, qt_meta_stringdata_canvas_window.data,
      qt_meta_data_canvas_window,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *canvas_window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *canvas_window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_canvas_window.stringdata0))
        return static_cast<void*>(this);
    return QMdiSubWindow::qt_metacast(_clname);
}

int canvas_window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMdiSubWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void canvas_window::set_active(unsigned  _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void canvas_window::close(unsigned  _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
