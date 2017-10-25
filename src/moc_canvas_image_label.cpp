/****************************************************************************
** Meta object code from reading C++ file 'canvas_image_label.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "view/canvas_image_label.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canvas_image_label.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_image_canvas_t {
    QByteArrayData data[1];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_image_canvas_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_image_canvas_t qt_meta_stringdata_image_canvas = {
    {
QT_MOC_LITERAL(0, 0, 12) // "image_canvas"

    },
    "image_canvas"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_image_canvas[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void image_canvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject image_canvas::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_image_canvas.data,
      qt_meta_data_image_canvas,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *image_canvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *image_canvas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_image_canvas.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int image_canvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_canvas_image_label_t {
    QByteArrayData data[3];
    char stringdata0[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_canvas_image_label_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_canvas_image_label_t qt_meta_stringdata_canvas_image_label = {
    {
QT_MOC_LITERAL(0, 0, 18), // "canvas_image_label"
QT_MOC_LITERAL(1, 19, 18), // "update_coordenates"
QT_MOC_LITERAL(2, 38, 0) // ""

    },
    "canvas_image_label\0update_coordenates\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_canvas_image_label[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    2,

       0        // eod
};

void canvas_image_label::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        canvas_image_label *_t = static_cast<canvas_image_label *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_coordenates((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (canvas_image_label::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&canvas_image_label::update_coordenates)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject canvas_image_label::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_canvas_image_label.data,
      qt_meta_data_canvas_image_label,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *canvas_image_label::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *canvas_image_label::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_canvas_image_label.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int canvas_image_label::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void canvas_image_label::update_coordenates(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
