/****************************************************************************
** Meta object code from reading C++ file 'manage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Source Codes/manage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Manage_t {
    QByteArrayData data[18];
    char stringdata0[346];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Manage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Manage_t qt_meta_stringdata_Manage = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Manage"
QT_MOC_LITERAL(1, 7, 21), // "on_btn_logout_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 14), // "currentsession"
QT_MOC_LITERAL(4, 45, 22), // "on_btn_newbook_clicked"
QT_MOC_LITERAL(5, 68, 23), // "on_btn_viewbook_clicked"
QT_MOC_LITERAL(6, 92, 21), // "on_btn_return_clicked"
QT_MOC_LITERAL(7, 114, 19), // "on_btn_back_clicked"
QT_MOC_LITERAL(8, 134, 24), // "on_btn_returnall_clicked"
QT_MOC_LITERAL(9, 159, 21), // "on_listView_activated"
QT_MOC_LITERAL(10, 181, 11), // "QModelIndex"
QT_MOC_LITERAL(11, 193, 5), // "index"
QT_MOC_LITERAL(12, 199, 22), // "on_btn_viewava_clicked"
QT_MOC_LITERAL(13, 222, 25), // "on_btn_viewbooked_clicked"
QT_MOC_LITERAL(14, 248, 27), // "on_btn_updatestatus_clicked"
QT_MOC_LITERAL(15, 276, 25), // "on_listViewstatus_clicked"
QT_MOC_LITERAL(16, 302, 21), // "on_btn_update_clicked"
QT_MOC_LITERAL(17, 324, 21) // "on_btn_back_2_clicked"

    },
    "Manage\0on_btn_logout_clicked\0\0"
    "currentsession\0on_btn_newbook_clicked\0"
    "on_btn_viewbook_clicked\0on_btn_return_clicked\0"
    "on_btn_back_clicked\0on_btn_returnall_clicked\0"
    "on_listView_activated\0QModelIndex\0"
    "index\0on_btn_viewava_clicked\0"
    "on_btn_viewbooked_clicked\0"
    "on_btn_updatestatus_clicked\0"
    "on_listViewstatus_clicked\0"
    "on_btn_update_clicked\0on_btn_back_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Manage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    1,   91,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    1,   97,    2, 0x08 /* Private */,
      16,    0,  100,    2, 0x08 /* Private */,
      17,    0,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Manage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Manage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_logout_clicked(); break;
        case 1: _t->currentsession(); break;
        case 2: _t->on_btn_newbook_clicked(); break;
        case 3: _t->on_btn_viewbook_clicked(); break;
        case 4: _t->on_btn_return_clicked(); break;
        case 5: _t->on_btn_back_clicked(); break;
        case 6: _t->on_btn_returnall_clicked(); break;
        case 7: _t->on_listView_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_btn_viewava_clicked(); break;
        case 9: _t->on_btn_viewbooked_clicked(); break;
        case 10: _t->on_btn_updatestatus_clicked(); break;
        case 11: _t->on_listViewstatus_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 12: _t->on_btn_update_clicked(); break;
        case 13: _t->on_btn_back_2_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Manage::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Manage.data,
    qt_meta_data_Manage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Manage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Manage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Manage.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Manage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
