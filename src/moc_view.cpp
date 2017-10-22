/****************************************************************************
** Meta object code from reading C++ file 'view.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "view/view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_view_t {
    QByteArrayData data[8];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_view_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_view_t qt_meta_stringdata_view = {
    {
QT_MOC_LITERAL(0, 0, 4), // "view"
QT_MOC_LITERAL(1, 5, 12), // "delete_image"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 16), // "no_image_focused"
QT_MOC_LITERAL(4, 36, 13), // "image_focused"
QT_MOC_LITERAL(5, 50, 20), // "on_window_set_active"
QT_MOC_LITERAL(6, 71, 3), // "key"
QT_MOC_LITERAL(7, 75, 16) // "on_windows_close"

    },
    "view\0delete_image\0\0no_image_focused\0"
    "image_focused\0on_window_set_active\0"
    "key\0on_windows_close"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_view[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    1,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   44,    2, 0x0a /* Public */,
       7,    1,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,    6,
    QMetaType::Void, QMetaType::UInt,    6,

       0        // eod
};

void view::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        view *_t = static_cast<view *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->delete_image(); break;
        case 1: _t->no_image_focused(); break;
        case 2: _t->image_focused((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 3: _t->on_window_set_active((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 4: _t->on_windows_close((*reinterpret_cast< uint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (view::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&view::delete_image)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (view::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&view::no_image_focused)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (view::*_t)(unsigned  );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&view::image_focused)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject view::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_view.data,
      qt_meta_data_view,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *view::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *view::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_view.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int view::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void view::delete_image()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void view::no_image_focused()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void view::image_focused(unsigned  _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
