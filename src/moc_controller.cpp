/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "controller/controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_controller_t {
    QByteArrayData data[27];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_controller_t qt_meta_stringdata_controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "controller"
QT_MOC_LITERAL(1, 11, 17), // "update_histograms"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 9), // "histogram"
QT_MOC_LITERAL(4, 40, 4), // "hist"
QT_MOC_LITERAL(5, 45, 23), // "update_operation_option"
QT_MOC_LITERAL(6, 69, 8), // "QWidget*"
QT_MOC_LITERAL(7, 78, 3), // "wid"
QT_MOC_LITERAL(8, 82, 13), // "on_load_image"
QT_MOC_LITERAL(9, 96, 9), // "file_name"
QT_MOC_LITERAL(10, 106, 14), // "on_store_image"
QT_MOC_LITERAL(11, 121, 2), // "id"
QT_MOC_LITERAL(12, 124, 14), // "on_close_image"
QT_MOC_LITERAL(13, 139, 19), // "on_set_active_image"
QT_MOC_LITERAL(14, 159, 5), // "image"
QT_MOC_LITERAL(15, 165, 15), // "on_create_image"
QT_MOC_LITERAL(16, 181, 8), // "picture*"
QT_MOC_LITERAL(17, 190, 3), // "pic"
QT_MOC_LITERAL(18, 194, 18), // "on_overwrite_image"
QT_MOC_LITERAL(19, 213, 16), // "load_all_plugins"
QT_MOC_LITERAL(20, 230, 4), // "path"
QT_MOC_LITERAL(21, 235, 11), // "load_plugin"
QT_MOC_LITERAL(22, 247, 11), // "plugin_name"
QT_MOC_LITERAL(23, 259, 4), // "QDir"
QT_MOC_LITERAL(24, 264, 3), // "dir"
QT_MOC_LITERAL(25, 268, 10), // "use_plugin"
QT_MOC_LITERAL(26, 279, 5) // "index"

    },
    "controller\0update_histograms\0\0histogram\0"
    "hist\0update_operation_option\0QWidget*\0"
    "wid\0on_load_image\0file_name\0on_store_image\0"
    "id\0on_close_image\0on_set_active_image\0"
    "image\0on_create_image\0picture*\0pic\0"
    "on_overwrite_image\0load_all_plugins\0"
    "path\0load_plugin\0plugin_name\0QDir\0dir\0"
    "use_plugin\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       5,    1,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   75,    2, 0x0a /* Public */,
      10,    2,   78,    2, 0x0a /* Public */,
      12,    0,   83,    2, 0x0a /* Public */,
      13,    1,   84,    2, 0x0a /* Public */,
      15,    1,   87,    2, 0x0a /* Public */,
      18,    1,   90,    2, 0x0a /* Public */,
      19,    1,   93,    2, 0x0a /* Public */,
      21,    2,   96,    2, 0x0a /* Public */,
      25,    1,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt,    9,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Bool, QMetaType::QString,   20,
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 23,   22,   24,
    QMetaType::Void, QMetaType::UInt,   26,

       0        // eod
};

void controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        controller *_t = static_cast<controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_histograms((*reinterpret_cast< histogram(*)>(_a[1]))); break;
        case 1: _t->update_operation_option((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 2: _t->on_load_image((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_store_image((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 4: _t->on_close_image(); break;
        case 5: _t->on_set_active_image((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 6: _t->on_create_image((*reinterpret_cast< picture*(*)>(_a[1]))); break;
        case 7: _t->on_overwrite_image((*reinterpret_cast< picture*(*)>(_a[1]))); break;
        case 8: { bool _r = _t->load_all_plugins((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->load_plugin((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDir(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->use_plugin((*reinterpret_cast< uint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (controller::*_t)(histogram );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&controller::update_histograms)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (controller::*_t)(QWidget * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&controller::update_operation_option)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_controller.data,
      qt_meta_data_controller,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_controller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void controller::update_histograms(histogram _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void controller::update_operation_option(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
