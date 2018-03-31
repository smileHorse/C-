/****************************************************************************
** Meta object code from reading C++ file 'settingstree.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../tools/settingseditor/settingstree.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingstree.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SettingsTree_t {
    QByteArrayData data[11];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingsTree_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingsTree_t qt_meta_stringdata_SettingsTree = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SettingsTree"
QT_MOC_LITERAL(1, 13, 14), // "setAutoRefresh"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "autoRefresh"
QT_MOC_LITERAL(4, 41, 19), // "setFallbacksEnabled"
QT_MOC_LITERAL(5, 61, 7), // "enabled"
QT_MOC_LITERAL(6, 69, 12), // "maybeRefresh"
QT_MOC_LITERAL(7, 82, 7), // "refresh"
QT_MOC_LITERAL(8, 90, 13), // "updateSetting"
QT_MOC_LITERAL(9, 104, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(10, 121, 4) // "item"

    },
    "SettingsTree\0setAutoRefresh\0\0autoRefresh\0"
    "setFallbacksEnabled\0enabled\0maybeRefresh\0"
    "refresh\0updateSetting\0QTreeWidgetItem*\0"
    "item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingsTree[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x0a /* Public */,
       7,    0,   46,    2, 0x0a /* Public */,
       8,    1,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void SettingsTree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SettingsTree *_t = static_cast<SettingsTree *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setAutoRefresh((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->setFallbacksEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->maybeRefresh(); break;
        case 3: _t->refresh(); break;
        case 4: _t->updateSetting((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SettingsTree::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_SettingsTree.data,
      qt_meta_data_SettingsTree,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SettingsTree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingsTree::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsTree.stringdata0))
        return static_cast<void*>(const_cast< SettingsTree*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int SettingsTree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
