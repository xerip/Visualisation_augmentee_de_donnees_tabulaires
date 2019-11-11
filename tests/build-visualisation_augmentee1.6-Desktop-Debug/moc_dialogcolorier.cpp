/****************************************************************************
** Meta object code from reading C++ file 'dialogcolorier.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../visualisation_augmentee1.6/dialogcolorier.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogcolorier.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogColorier_t {
    QByteArrayData data[13];
    char stringdata0[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogColorier_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogColorier_t qt_meta_stringdata_DialogColorier = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DialogColorier"
QT_MOC_LITERAL(1, 15, 11), // "change_text"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "value"
QT_MOC_LITERAL(4, 34, 15), // "on_colorChanged"
QT_MOC_LITERAL(5, 50, 17), // "on_appliquerColor"
QT_MOC_LITERAL(6, 68, 17), // "on_message_erreur"
QT_MOC_LITERAL(7, 86, 14), // "on_reinitColor"
QT_MOC_LITERAL(8, 101, 17), // "on_colorAleatoire"
QT_MOC_LITERAL(9, 119, 17), // "on_tout_aleatoire"
QT_MOC_LITERAL(10, 137, 21), // "on_tout_reinitialiser"
QT_MOC_LITERAL(11, 159, 19), // "on_afficher_caseTab"
QT_MOC_LITERAL(12, 179, 8) // "_myIndex"

    },
    "DialogColorier\0change_text\0\0value\0"
    "on_colorChanged\0on_appliquerColor\0"
    "on_message_erreur\0on_reinitColor\0"
    "on_colorAleatoire\0on_tout_aleatoire\0"
    "on_tout_reinitialiser\0on_afficher_caseTab\0"
    "_myIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogColorier[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   62,    2, 0x09 /* Protected */,
       5,    0,   63,    2, 0x09 /* Protected */,
       6,    1,   64,    2, 0x09 /* Protected */,
       7,    0,   67,    2, 0x09 /* Protected */,
       8,    0,   68,    2, 0x09 /* Protected */,
       9,    0,   69,    2, 0x09 /* Protected */,
      10,    0,   70,    2, 0x09 /* Protected */,
      11,    1,   71,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   12,

       0        // eod
};

void DialogColorier::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogColorier *_t = static_cast<DialogColorier *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->change_text((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_colorChanged(); break;
        case 2: _t->on_appliquerColor(); break;
        case 3: _t->on_message_erreur((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->on_reinitColor(); break;
        case 5: _t->on_colorAleatoire(); break;
        case 6: _t->on_tout_aleatoire(); break;
        case 7: _t->on_tout_reinitialiser(); break;
        case 8: _t->on_afficher_caseTab((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DialogColorier::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogColorier::change_text)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DialogColorier::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogColorier.data,
      qt_meta_data_DialogColorier,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DialogColorier::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogColorier::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogColorier.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogColorier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void DialogColorier::change_text(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
