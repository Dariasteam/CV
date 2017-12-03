/****************************************************************************
** Meta object code from reading C++ file 'footer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "view/footer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'footer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_footer_t {
    QByteArrayData data[13];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_footer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_footer_t qt_meta_stringdata_footer = {
    {
QT_MOC_LITERAL(0, 0, 6), // "footer"
QT_MOC_LITERAL(1, 7, 10), // "get_rgb_at"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 27), // "on_update_coordenate_labels"
QT_MOC_LITERAL(4, 47, 5), // "point"
QT_MOC_LITERAL(5, 53, 19), // "on_update_meta_data"
QT_MOC_LITERAL(6, 73, 6), // "format"
QT_MOC_LITERAL(7, 80, 4), // "size"
QT_MOC_LITERAL(8, 85, 16), // "on_update_rgb_at"
QT_MOC_LITERAL(9, 102, 5), // "color"
QT_MOC_LITERAL(10, 108, 22), // "on_update_progress_bar"
QT_MOC_LITERAL(11, 131, 5), // "value"
QT_MOC_LITERAL(12, 137, 21) // "on_reset_progress_bar"

    },
    "footer\0get_rgb_at\0\0on_update_coordenate_labels\0"
    "point\0on_update_meta_data\0format\0size\0"
    "on_update_rgb_at\0color\0on_update_progress_bar\0"
    "value\0on_reset_progress_bar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_footer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   47,    2, 0x0a /* Public */,
       5,    2,   50,    2, 0x0a /* Public */,
       8,    1,   55,    2, 0x0a /* Public */,
      10,    1,   58,    2, 0x0a /* Public */,
      12,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QSize,    6,    7,
    QMetaType::Void, QMetaType::QColor,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,

       0        // eod
};

void footer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        footer *_t = static_cast<footer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->get_rgb_at((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->on_update_coordenate_labels((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->on_update_meta_data((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QSize(*)>(_a[2]))); break;
        case 3: _t->on_update_rgb_at((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 4: _t->on_update_progress_bar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_reset_progress_bar(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (footer::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&footer::get_rgb_at)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject footer::staticMetaObject = {
    { &QStatusBar::staticMetaObject, qt_meta_stringdata_footer.data,
      qt_meta_data_footer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *footer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *footer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_footer.stringdata0))
        return static_cast<void*>(this);
    return QStatusBar::qt_metacast(_clname);
}

int footer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStatusBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void footer::get_rgb_at(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
