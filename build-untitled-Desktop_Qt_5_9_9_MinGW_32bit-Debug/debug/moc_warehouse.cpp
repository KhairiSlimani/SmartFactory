/****************************************************************************
** Meta object code from reading C++ file 'warehouse.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../untitled/warehouse.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'warehouse.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_warehouse_t {
    QByteArrayData data[20];
    char stringdata0[429];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_warehouse_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_warehouse_t qt_meta_stringdata_warehouse = {
    {
QT_MOC_LITERAL(0, 0, 9), // "warehouse"
QT_MOC_LITERAL(1, 10, 11), // "HomeClicked"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 37), // "on_pushButton_AddNewWarehouse..."
QT_MOC_LITERAL(4, 61, 8), // "showTime"
QT_MOC_LITERAL(5, 70, 15), // "showContextMenu"
QT_MOC_LITERAL(6, 86, 3), // "pos"
QT_MOC_LITERAL(7, 90, 15), // "deleteWarehouse"
QT_MOC_LITERAL(8, 106, 13), // "viewWarehouse"
QT_MOC_LITERAL(9, 120, 13), // "editWarehouse"
QT_MOC_LITERAL(10, 134, 38), // "on_pushButton_SaveAddWarehous..."
QT_MOC_LITERAL(11, 173, 40), // "on_pushButton_CancelAddWareho..."
QT_MOC_LITERAL(12, 214, 39), // "on_pushButton_SaveEditWarehou..."
QT_MOC_LITERAL(13, 254, 41), // "on_pushButton_CancelEditWareh..."
QT_MOC_LITERAL(14, 296, 28), // "on_pushButton_Return_clicked"
QT_MOC_LITERAL(15, 325, 20), // "on_signOut_8_clicked"
QT_MOC_LITERAL(16, 346, 20), // "on_signOut_5_clicked"
QT_MOC_LITERAL(17, 367, 20), // "on_signOut_6_clicked"
QT_MOC_LITERAL(18, 388, 20), // "on_signOut_7_clicked"
QT_MOC_LITERAL(19, 409, 19) // "on_LoadData_clicked"

    },
    "warehouse\0HomeClicked\0\0"
    "on_pushButton_AddNewWarehouse_clicked\0"
    "showTime\0showContextMenu\0pos\0"
    "deleteWarehouse\0viewWarehouse\0"
    "editWarehouse\0on_pushButton_SaveAddWarehouse_clicked\0"
    "on_pushButton_CancelAddWarehouse_clicked\0"
    "on_pushButton_SaveEditWarehouse_clicked\0"
    "on_pushButton_CancelEditWarehouse_clicked\0"
    "on_pushButton_Return_clicked\0"
    "on_signOut_8_clicked\0on_signOut_5_clicked\0"
    "on_signOut_6_clicked\0on_signOut_7_clicked\0"
    "on_LoadData_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_warehouse[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    1,  102,    2, 0x08 /* Private */,
       7,    0,  105,    2, 0x08 /* Private */,
       8,    0,  106,    2, 0x08 /* Private */,
       9,    0,  107,    2, 0x08 /* Private */,
      10,    0,  108,    2, 0x08 /* Private */,
      11,    0,  109,    2, 0x08 /* Private */,
      12,    0,  110,    2, 0x08 /* Private */,
      13,    0,  111,    2, 0x08 /* Private */,
      14,    0,  112,    2, 0x08 /* Private */,
      15,    0,  113,    2, 0x08 /* Private */,
      16,    0,  114,    2, 0x08 /* Private */,
      17,    0,  115,    2, 0x08 /* Private */,
      18,    0,  116,    2, 0x08 /* Private */,
      19,    0,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    6,
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

void warehouse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        warehouse *_t = static_cast<warehouse *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->HomeClicked(); break;
        case 1: _t->on_pushButton_AddNewWarehouse_clicked(); break;
        case 2: _t->showTime(); break;
        case 3: _t->showContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 4: _t->deleteWarehouse(); break;
        case 5: _t->viewWarehouse(); break;
        case 6: _t->editWarehouse(); break;
        case 7: _t->on_pushButton_SaveAddWarehouse_clicked(); break;
        case 8: _t->on_pushButton_CancelAddWarehouse_clicked(); break;
        case 9: _t->on_pushButton_SaveEditWarehouse_clicked(); break;
        case 10: _t->on_pushButton_CancelEditWarehouse_clicked(); break;
        case 11: _t->on_pushButton_Return_clicked(); break;
        case 12: _t->on_signOut_8_clicked(); break;
        case 13: _t->on_signOut_5_clicked(); break;
        case 14: _t->on_signOut_6_clicked(); break;
        case 15: _t->on_signOut_7_clicked(); break;
        case 16: _t->on_LoadData_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (warehouse::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&warehouse::HomeClicked)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject warehouse::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_warehouse.data,
      qt_meta_data_warehouse,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *warehouse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *warehouse::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_warehouse.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int warehouse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void warehouse::HomeClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
