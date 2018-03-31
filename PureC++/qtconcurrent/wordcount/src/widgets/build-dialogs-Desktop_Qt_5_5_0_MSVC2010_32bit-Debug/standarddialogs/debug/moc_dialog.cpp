/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../dialogs/standarddialogs/dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Dialog_t {
    QByteArrayData data[18];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_t qt_meta_stringdata_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Dialog"
QT_MOC_LITERAL(1, 7, 10), // "setInteger"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 9), // "setDouble"
QT_MOC_LITERAL(4, 29, 7), // "setItem"
QT_MOC_LITERAL(5, 37, 7), // "setText"
QT_MOC_LITERAL(6, 45, 16), // "setMultiLineText"
QT_MOC_LITERAL(7, 62, 8), // "setColor"
QT_MOC_LITERAL(8, 71, 7), // "setFont"
QT_MOC_LITERAL(9, 79, 20), // "setExistingDirectory"
QT_MOC_LITERAL(10, 100, 15), // "setOpenFileName"
QT_MOC_LITERAL(11, 116, 16), // "setOpenFileNames"
QT_MOC_LITERAL(12, 133, 15), // "setSaveFileName"
QT_MOC_LITERAL(13, 149, 15), // "criticalMessage"
QT_MOC_LITERAL(14, 165, 18), // "informationMessage"
QT_MOC_LITERAL(15, 184, 15), // "questionMessage"
QT_MOC_LITERAL(16, 200, 14), // "warningMessage"
QT_MOC_LITERAL(17, 215, 12) // "errorMessage"

    },
    "Dialog\0setInteger\0\0setDouble\0setItem\0"
    "setText\0setMultiLineText\0setColor\0"
    "setFont\0setExistingDirectory\0"
    "setOpenFileName\0setOpenFileNames\0"
    "setSaveFileName\0criticalMessage\0"
    "informationMessage\0questionMessage\0"
    "warningMessage\0errorMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    0,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dialog *_t = static_cast<Dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setInteger(); break;
        case 1: _t->setDouble(); break;
        case 2: _t->setItem(); break;
        case 3: _t->setText(); break;
        case 4: _t->setMultiLineText(); break;
        case 5: _t->setColor(); break;
        case 6: _t->setFont(); break;
        case 7: _t->setExistingDirectory(); break;
        case 8: _t->setOpenFileName(); break;
        case 9: _t->setOpenFileNames(); break;
        case 10: _t->setSaveFileName(); break;
        case 11: _t->criticalMessage(); break;
        case 12: _t->informationMessage(); break;
        case 13: _t->questionMessage(); break;
        case 14: _t->warningMessage(); break;
        case 15: _t->errorMessage(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Dialog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Dialog.data,
      qt_meta_data_Dialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog.stringdata0))
        return static_cast<void*>(const_cast< Dialog*>(this));
    return QWidget::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
