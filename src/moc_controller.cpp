/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "controller/controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_controller_t {
    QByteArrayData data[37];
    char stringdata0[414];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_controller_t qt_meta_stringdata_controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "controller"
QT_MOC_LITERAL(1, 11, 18), // "send_current_image"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "picture*"
QT_MOC_LITERAL(4, 40, 3), // "pic"
QT_MOC_LITERAL(5, 44, 17), // "update_histograms"
QT_MOC_LITERAL(6, 62, 9), // "histogram"
QT_MOC_LITERAL(7, 72, 4), // "hist"
QT_MOC_LITERAL(8, 77, 17), // "update_basic_info"
QT_MOC_LITERAL(9, 95, 18), // "picture_basic_info"
QT_MOC_LITERAL(10, 114, 10), // "basic_info"
QT_MOC_LITERAL(11, 125, 23), // "update_operation_option"
QT_MOC_LITERAL(12, 149, 8), // "QWidget*"
QT_MOC_LITERAL(13, 158, 3), // "wid"
QT_MOC_LITERAL(14, 162, 15), // "update_metadata"
QT_MOC_LITERAL(15, 178, 6), // "format"
QT_MOC_LITERAL(16, 185, 4), // "size"
QT_MOC_LITERAL(17, 190, 13), // "update_rgb_at"
QT_MOC_LITERAL(18, 204, 5), // "color"
QT_MOC_LITERAL(19, 210, 13), // "on_load_image"
QT_MOC_LITERAL(20, 224, 9), // "file_name"
QT_MOC_LITERAL(21, 234, 14), // "on_store_image"
QT_MOC_LITERAL(22, 249, 2), // "id"
QT_MOC_LITERAL(23, 252, 14), // "on_close_image"
QT_MOC_LITERAL(24, 267, 19), // "on_set_active_image"
QT_MOC_LITERAL(25, 287, 3), // "key"
QT_MOC_LITERAL(26, 291, 15), // "on_create_image"
QT_MOC_LITERAL(27, 307, 16), // "load_all_plugins"
QT_MOC_LITERAL(28, 324, 4), // "path"
QT_MOC_LITERAL(29, 329, 11), // "load_plugin"
QT_MOC_LITERAL(30, 341, 11), // "plugin_name"
QT_MOC_LITERAL(31, 353, 4), // "QDir"
QT_MOC_LITERAL(32, 358, 3), // "dir"
QT_MOC_LITERAL(33, 362, 13), // "on_get_rgb_at"
QT_MOC_LITERAL(34, 376, 20), // "on_get_current_image"
QT_MOC_LITERAL(35, 397, 10), // "use_plugin"
QT_MOC_LITERAL(36, 408, 5) // "index"

    },
    "controller\0send_current_image\0\0picture*\0"
    "pic\0update_histograms\0histogram\0hist\0"
    "update_basic_info\0picture_basic_info\0"
    "basic_info\0update_operation_option\0"
    "QWidget*\0wid\0update_metadata\0format\0"
    "size\0update_rgb_at\0color\0on_load_image\0"
    "file_name\0on_store_image\0id\0on_close_image\0"
    "on_set_active_image\0key\0on_create_image\0"
    "load_all_plugins\0path\0load_plugin\0"
    "plugin_name\0QDir\0dir\0on_get_rgb_at\0"
    "on_get_current_image\0use_plugin\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       5,    1,   97,    2, 0x06 /* Public */,
       8,    1,  100,    2, 0x06 /* Public */,
      11,    1,  103,    2, 0x06 /* Public */,
      14,    2,  106,    2, 0x06 /* Public */,
      17,    1,  111,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    1,  114,    2, 0x0a /* Public */,
      21,    2,  117,    2, 0x0a /* Public */,
      23,    0,  122,    2, 0x0a /* Public */,
      24,    1,  123,    2, 0x0a /* Public */,
      26,    1,  126,    2, 0x0a /* Public */,
      27,    1,  129,    2, 0x0a /* Public */,
      29,    2,  132,    2, 0x0a /* Public */,
      33,    1,  137,    2, 0x0a /* Public */,
      34,    0,  140,    2, 0x0a /* Public */,
      35,    1,  141,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QSize,   15,   16,
    QMetaType::Void, QMetaType::QColor,   18,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt,   20,   22,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,   25,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Bool, QMetaType::QString,   28,
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 31,   30,   32,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,   36,

       0        // eod
};

void controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        controller *_t = static_cast<controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_current_image((*reinterpret_cast< picture*(*)>(_a[1]))); break;
        case 1: _t->update_histograms((*reinterpret_cast< histogram(*)>(_a[1]))); break;
        case 2: _t->update_basic_info((*reinterpret_cast< picture_basic_info(*)>(_a[1]))); break;
        case 3: _t->update_operation_option((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 4: _t->update_metadata((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QSize(*)>(_a[2]))); break;
        case 5: _t->update_rgb_at((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 6: _t->on_load_image((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_store_image((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 8: _t->on_close_image(); break;
        case 9: _t->on_set_active_image((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 10: _t->on_create_image((*reinterpret_cast< picture*(*)>(_a[1]))); break;
        case 11: { bool _r = _t->load_all_plugins((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->load_plugin((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDir(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->on_get_rgb_at((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 14: _t->on_get_current_image(); break;
        case 15: _t->use_plugin((*reinterpret_cast< uint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< picture* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< picture* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (controller::*_t)(picture * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controller::send_current_image)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (controller::*_t)(histogram );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controller::update_histograms)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (controller::*_t)(picture_basic_info );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controller::update_basic_info)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (controller::*_t)(QWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controller::update_operation_option)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (controller::*_t)(QString , QSize );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controller::update_metadata)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (controller::*_t)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controller::update_rgb_at)) {
                *result = 5;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void controller::send_current_image(picture * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void controller::update_histograms(histogram _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void controller::update_basic_info(picture_basic_info _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void controller::update_operation_option(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void controller::update_metadata(QString _t1, QSize _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void controller::update_rgb_at(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
