/****************************************************************************
** Meta object code from reading C++ file 'imagescaling.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../qtconcurrent/imagescaling/imagescaling.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagescaling.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Images_t {
    QByteArrayData data[6];
    char stringdata0[36];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Images_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Images_t qt_meta_stringdata_Images = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Images"
QT_MOC_LITERAL(1, 7, 4), // "open"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 9), // "showImage"
QT_MOC_LITERAL(4, 23, 3), // "num"
QT_MOC_LITERAL(5, 27, 8) // "finished"

    },
    "Images\0open\0\0showImage\0num\0finished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Images[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    1,   30,    2, 0x0a /* Public */,
       5,    0,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,

       0        // eod
};

void Images::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Images *_t = static_cast<Images *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->open(); break;
        case 1: _t->showImage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->finished(); break;
        default: ;
        }
    }
}

const QMetaObject Images::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Images.data,
      qt_meta_data_Images,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Images::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Images::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Images.stringdata0))
        return static_cast<void*>(const_cast< Images*>(this));
    return QWidget::qt_metacast(_clname);
}

int Images::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
