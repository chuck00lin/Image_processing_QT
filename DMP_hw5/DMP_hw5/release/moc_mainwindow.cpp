/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[14];
    char stringdata0[255];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 26), // "on_action_import_triggered"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 17), // "on_pb_RGB_clicked"
QT_MOC_LITERAL(4, 57, 17), // "on_pb_CMY_clicked"
QT_MOC_LITERAL(5, 75, 17), // "on_pb_HSI_clicked"
QT_MOC_LITERAL(6, 93, 17), // "on_pb_XYZ_clicked"
QT_MOC_LITERAL(7, 111, 17), // "on_pb_Lab_clicked"
QT_MOC_LITERAL(8, 129, 17), // "on_pb_YUV_clicked"
QT_MOC_LITERAL(9, 147, 21), // "on_pb_Rainbow_clicked"
QT_MOC_LITERAL(10, 169, 17), // "on_pb_Hot_clicked"
QT_MOC_LITERAL(11, 187, 20), // "on_pb_Winter_clicked"
QT_MOC_LITERAL(12, 208, 20), // "on_pb_Autumn_clicked"
QT_MOC_LITERAL(13, 229, 25) // "on_pb_applykmeans_clicked"

    },
    "MainWindow\0on_action_import_triggered\0"
    "\0on_pb_RGB_clicked\0on_pb_CMY_clicked\0"
    "on_pb_HSI_clicked\0on_pb_XYZ_clicked\0"
    "on_pb_Lab_clicked\0on_pb_YUV_clicked\0"
    "on_pb_Rainbow_clicked\0on_pb_Hot_clicked\0"
    "on_pb_Winter_clicked\0on_pb_Autumn_clicked\0"
    "on_pb_applykmeans_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

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

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_action_import_triggered(); break;
        case 1: _t->on_pb_RGB_clicked(); break;
        case 2: _t->on_pb_CMY_clicked(); break;
        case 3: _t->on_pb_HSI_clicked(); break;
        case 4: _t->on_pb_XYZ_clicked(); break;
        case 5: _t->on_pb_Lab_clicked(); break;
        case 6: _t->on_pb_YUV_clicked(); break;
        case 7: _t->on_pb_Rainbow_clicked(); break;
        case 8: _t->on_pb_Hot_clicked(); break;
        case 9: _t->on_pb_Winter_clicked(); break;
        case 10: _t->on_pb_Autumn_clicked(); break;
        case 11: _t->on_pb_applykmeans_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
