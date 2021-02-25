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
    QByteArrayData data[17];
    char stringdata0[335];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "drawchart"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "cv::Mat"
QT_MOC_LITERAL(4, 30, 10), // "drawchart2"
QT_MOC_LITERAL(5, 41, 25), // "on_pb_show_origin_clicked"
QT_MOC_LITERAL(6, 67, 26), // "on_pb_equalization_clicked"
QT_MOC_LITERAL(7, 94, 25), // "on_pb_grayscaleAB_clicked"
QT_MOC_LITERAL(8, 120, 21), // "on_pb_diff_AB_clicked"
QT_MOC_LITERAL(9, 142, 20), // "on_pb_binary_clicked"
QT_MOC_LITERAL(10, 163, 32), // "on_slider_brightness_sliderMoved"
QT_MOC_LITERAL(11, 196, 8), // "position"
QT_MOC_LITERAL(12, 205, 30), // "on_slider_contrast_sliderMoved"
QT_MOC_LITERAL(13, 236, 29), // "on_doubleSpinBox_valueChanged"
QT_MOC_LITERAL(14, 266, 4), // "arg1"
QT_MOC_LITERAL(15, 271, 31), // "on_doubleSpinBox_2_valueChanged"
QT_MOC_LITERAL(16, 303, 31) // "on_doubleSpinBox_3_valueChanged"

    },
    "MainWindow\0drawchart\0\0cv::Mat\0drawchart2\0"
    "on_pb_show_origin_clicked\0"
    "on_pb_equalization_clicked\0"
    "on_pb_grayscaleAB_clicked\0"
    "on_pb_diff_AB_clicked\0on_pb_binary_clicked\0"
    "on_slider_brightness_sliderMoved\0"
    "position\0on_slider_contrast_sliderMoved\0"
    "on_doubleSpinBox_valueChanged\0arg1\0"
    "on_doubleSpinBox_2_valueChanged\0"
    "on_doubleSpinBox_3_valueChanged"
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
       1,    1,   74,    2, 0x08 /* Private */,
       4,    1,   77,    2, 0x08 /* Private */,
       5,    0,   80,    2, 0x08 /* Private */,
       6,    0,   81,    2, 0x08 /* Private */,
       7,    0,   82,    2, 0x08 /* Private */,
       8,    0,   83,    2, 0x08 /* Private */,
       9,    0,   84,    2, 0x08 /* Private */,
      10,    1,   85,    2, 0x08 /* Private */,
      12,    1,   88,    2, 0x08 /* Private */,
      13,    1,   91,    2, 0x08 /* Private */,
      15,    1,   94,    2, 0x08 /* Private */,
      16,    1,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Double,   14,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->drawchart((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 1: _t->drawchart2((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 2: _t->on_pb_show_origin_clicked(); break;
        case 3: _t->on_pb_equalization_clicked(); break;
        case 4: _t->on_pb_grayscaleAB_clicked(); break;
        case 5: _t->on_pb_diff_AB_clicked(); break;
        case 6: _t->on_pb_binary_clicked(); break;
        case 7: _t->on_slider_brightness_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_slider_contrast_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_doubleSpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->on_doubleSpinBox_2_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->on_doubleSpinBox_3_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
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
