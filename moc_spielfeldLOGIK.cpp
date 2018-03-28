/****************************************************************************
** Meta object code from reading C++ file 'spielfeldLOGIK.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "spielfeldLOGIK.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spielfeldLOGIK.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SpielfeldLOGIK_t {
    QByteArrayData data[19];
    char stringdata0[231];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SpielfeldLOGIK_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SpielfeldLOGIK_t qt_meta_stringdata_SpielfeldLOGIK = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SpielfeldLOGIK"
QT_MOC_LITERAL(1, 15, 14), // "sigMoeglicheK2"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 32), // "std::vector<std::pair<int,int> >"
QT_MOC_LITERAL(4, 64, 9), // "tmpVector"
QT_MOC_LITERAL(5, 74, 18), // "std::pair<int,int>"
QT_MOC_LITERAL(6, 93, 2), // "k1"
QT_MOC_LITERAL(7, 96, 3), // "bla"
QT_MOC_LITERAL(8, 100, 11), // "koordSchiff"
QT_MOC_LITERAL(9, 112, 21), // "sigAlleSchiffeGesetzt"
QT_MOC_LITERAL(10, 134, 4), // "Buul"
QT_MOC_LITERAL(11, 139, 23), // "koordinatenAllerSchiffe"
QT_MOC_LITERAL(12, 163, 4), // "blub"
QT_MOC_LITERAL(13, 168, 18), // "setAktLaengeSchiff"
QT_MOC_LITERAL(14, 187, 16), // "NAktLaengeSchiff"
QT_MOC_LITERAL(15, 204, 11), // "moeglicheK2"
QT_MOC_LITERAL(16, 216, 1), // "k"
QT_MOC_LITERAL(17, 218, 9), // "setSchiff"
QT_MOC_LITERAL(18, 228, 2) // "k2"

    },
    "SpielfeldLOGIK\0sigMoeglicheK2\0\0"
    "std::vector<std::pair<int,int> >\0"
    "tmpVector\0std::pair<int,int>\0k1\0bla\0"
    "koordSchiff\0sigAlleSchiffeGesetzt\0"
    "Buul\0koordinatenAllerSchiffe\0blub\0"
    "setAktLaengeSchiff\0NAktLaengeSchiff\0"
    "moeglicheK2\0k\0setSchiff\0k2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpielfeldLOGIK[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   49,    2, 0x06 /* Public */,
       8,    1,   56,    2, 0x06 /* Public */,
       9,    1,   59,    2, 0x06 /* Public */,
      11,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,   65,    2, 0x0a /* Public */,
      15,    1,   68,    2, 0x0a /* Public */,
      17,    2,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::Int,    4,    6,    7,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, 0x80000000 | 3,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, 0x80000000 | 5,   16,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    6,   18,

       0        // eod
};

void SpielfeldLOGIK::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SpielfeldLOGIK *_t = static_cast<SpielfeldLOGIK *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigMoeglicheK2((*reinterpret_cast< std::vector<std::pair<int,int> >(*)>(_a[1])),(*reinterpret_cast< std::pair<int,int>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->koordSchiff((*reinterpret_cast< std::vector<std::pair<int,int> >(*)>(_a[1]))); break;
        case 2: _t->sigAlleSchiffeGesetzt((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->koordinatenAllerSchiffe((*reinterpret_cast< std::vector<std::pair<int,int> >(*)>(_a[1]))); break;
        case 4: _t->setAktLaengeSchiff((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->moeglicheK2((*reinterpret_cast< std::pair<int,int>(*)>(_a[1]))); break;
        case 6: _t->setSchiff((*reinterpret_cast< std::pair<int,int>(*)>(_a[1])),(*reinterpret_cast< std::pair<int,int>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SpielfeldLOGIK::*_t)(std::vector<std::pair<int,int> > , std::pair<int,int> , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SpielfeldLOGIK::sigMoeglicheK2)) {
                *result = 0;
            }
        }
        {
            typedef void (SpielfeldLOGIK::*_t)(std::vector<std::pair<int,int> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SpielfeldLOGIK::koordSchiff)) {
                *result = 1;
            }
        }
        {
            typedef void (SpielfeldLOGIK::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SpielfeldLOGIK::sigAlleSchiffeGesetzt)) {
                *result = 2;
            }
        }
        {
            typedef void (SpielfeldLOGIK::*_t)(std::vector<std::pair<int,int> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SpielfeldLOGIK::koordinatenAllerSchiffe)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject SpielfeldLOGIK::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SpielfeldLOGIK.data,
      qt_meta_data_SpielfeldLOGIK,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SpielfeldLOGIK::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpielfeldLOGIK::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SpielfeldLOGIK.stringdata0))
        return static_cast<void*>(const_cast< SpielfeldLOGIK*>(this));
    return QObject::qt_metacast(_clname);
}

int SpielfeldLOGIK::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void SpielfeldLOGIK::sigMoeglicheK2(std::vector<std::pair<int,int> > _t1, std::pair<int,int> _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SpielfeldLOGIK::koordSchiff(std::vector<std::pair<int,int> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SpielfeldLOGIK::sigAlleSchiffeGesetzt(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SpielfeldLOGIK::koordinatenAllerSchiffe(std::vector<std::pair<int,int> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
