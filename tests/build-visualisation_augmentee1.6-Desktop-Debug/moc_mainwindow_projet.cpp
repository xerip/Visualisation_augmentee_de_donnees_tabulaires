/****************************************************************************
** Meta object code from reading C++ file 'mainwindow_projet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../visualisation_augmentee1.6/mainwindow_projet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow_projet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_projet_t {
    QByteArrayData data[12];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_projet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_projet_t qt_meta_stringdata_MainWindow_projet = {
    {
QT_MOC_LITERAL(0, 0, 17), // "MainWindow_projet"
QT_MOC_LITERAL(1, 18, 10), // "signalTest"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 3), // "col"
QT_MOC_LITERAL(4, 34, 11), // "on_importer"
QT_MOC_LITERAL(5, 46, 10), // "on_generer"
QT_MOC_LITERAL(6, 57, 8), // "on_trier"
QT_MOC_LITERAL(7, 66, 11), // "on_colorier"
QT_MOC_LITERAL(8, 78, 10), // "on_valider"
QT_MOC_LITERAL(9, 89, 7), // "on_help"
QT_MOC_LITERAL(10, 97, 13), // "on_clicked_TB"
QT_MOC_LITERAL(11, 111, 5) // "index"

    },
    "MainWindow_projet\0signalTest\0\0col\0"
    "on_importer\0on_generer\0on_trier\0"
    "on_colorier\0on_valider\0on_help\0"
    "on_clicked_TB\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow_projet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   57,    2, 0x09 /* Protected */,
       5,    0,   58,    2, 0x09 /* Protected */,
       6,    0,   59,    2, 0x09 /* Protected */,
       7,    0,   60,    2, 0x09 /* Protected */,
       8,    0,   61,    2, 0x09 /* Protected */,
       9,    0,   62,    2, 0x09 /* Protected */,
      10,    1,   63,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   11,

       0        // eod
};

void MainWindow_projet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow_projet *_t = static_cast<MainWindow_projet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalTest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_importer(); break;
        case 2: _t->on_generer(); break;
        case 3: _t->on_trier(); break;
        case 4: _t->on_colorier(); break;
        case 5: _t->on_valider(); break;
        case 6: _t->on_help(); break;
        case 7: _t->on_clicked_TB((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainWindow_projet::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow_projet::signalTest)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow_projet::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow_projet.data,
      qt_meta_data_MainWindow_projet,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow_projet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow_projet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow_projet.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow_projet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MainWindow_projet::signalTest(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
