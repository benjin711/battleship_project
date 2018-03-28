/****************************************************************************
** Meta object code from reading C++ file 'spiel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "spiel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spiel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Spiel_t {
    QByteArrayData data[17];
    char stringdata0[270];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Spiel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Spiel_t qt_meta_stringdata_Spiel = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Spiel"
QT_MOC_LITERAL(1, 6, 19), // "koordWeitergabeAnNW"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 19), // "std::vector<quint8>"
QT_MOC_LITERAL(4, 47, 13), // "rueckgabeAnNW"
QT_MOC_LITERAL(5, 61, 15), // "weitergabeAnGUI"
QT_MOC_LITERAL(6, 77, 24), // "std::pair<quint8,quint8>"
QT_MOC_LITERAL(7, 102, 19), // "statusCodeVonGegner"
QT_MOC_LITERAL(8, 122, 38), // "std::vector<std::pair<quint8,..."
QT_MOC_LITERAL(9, 161, 18), // "angriffAufSpieler2"
QT_MOC_LITERAL(10, 180, 1), // "k"
QT_MOC_LITERAL(11, 182, 20), // "setAmZugBeideSpieler"
QT_MOC_LITERAL(12, 203, 7), // "tmpBool"
QT_MOC_LITERAL(13, 211, 18), // "angriffAufSpieler1"
QT_MOC_LITERAL(14, 230, 18), // "verarbeiteSCGegner"
QT_MOC_LITERAL(15, 249, 10), // "statusCode"
QT_MOC_LITERAL(16, 260, 9) // "tmpVector"

    },
    "Spiel\0koordWeitergabeAnNW\0\0"
    "std::vector<quint8>\0rueckgabeAnNW\0"
    "weitergabeAnGUI\0std::pair<quint8,quint8>\0"
    "statusCodeVonGegner\0"
    "std::vector<std::pair<quint8,quint8> >\0"
    "angriffAufSpieler2\0k\0setAmZugBeideSpieler\0"
    "tmpBool\0angriffAufSpieler1\0"
    "verarbeiteSCGegner\0statusCode\0tmpVector"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Spiel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x06 /* Public */,
       4,    3,   66,    2, 0x06 /* Public */,
       5,    2,   73,    2, 0x06 /* Public */,
       7,    3,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   85,    2, 0x0a /* Public */,
      11,    1,   88,    2, 0x0a /* Public */,
      13,    1,   91,    2, 0x0a /* Public */,
      14,    2,   94,    2, 0x0a /* Public */,
      14,    1,   99,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, 0x80000000 | 3,    2,    2,    2,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, 0x80000000 | 3,    2,    2,    2,
    QMetaType::Void, QMetaType::UChar, 0x80000000 | 6,    2,    2,
    QMetaType::Void, QMetaType::UChar, 0x80000000 | 8, 0x80000000 | 6,    2,    2,    2,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 6,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, 0x80000000 | 6,   10,
    QMetaType::Void, QMetaType::UChar, 0x80000000 | 8,   15,   16,
    QMetaType::Void, QMetaType::UChar,   15,

       0        // eod
};

void Spiel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Spiel *_t = static_cast<Spiel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->koordWeitergabeAnNW((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< std::vector<quint8>(*)>(_a[3]))); break;
        case 1: _t->rueckgabeAnNW((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< std::vector<quint8>(*)>(_a[3]))); break;
        case 2: _t->weitergabeAnGUI((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< std::pair<quint8,quint8>(*)>(_a[2]))); break;
        case 3: _t->statusCodeVonGegner((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< std::vector<std::pair<quint8,quint8> >(*)>(_a[2])),(*reinterpret_cast< std::pair<quint8,quint8>(*)>(_a[3]))); break;
        case 4: { bool _r = _t->angriffAufSpieler2((*reinterpret_cast< std::pair<quint8,quint8>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->setAmZugBeideSpieler((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->angriffAufSpieler1((*reinterpret_cast< std::pair<quint8,quint8>(*)>(_a[1]))); break;
        case 7: _t->verarbeiteSCGegner((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< std::vector<std::pair<quint8,quint8> >(*)>(_a[2]))); break;
        case 8: _t->verarbeiteSCGegner((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Spiel::*_t)(quint8 , quint8 , std::vector<quint8> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spiel::koordWeitergabeAnNW)) {
                *result = 0;
            }
        }
        {
            typedef void (Spiel::*_t)(quint8 , quint8 , std::vector<quint8> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spiel::rueckgabeAnNW)) {
                *result = 1;
            }
        }
        {
            typedef void (Spiel::*_t)(quint8 , std::pair<quint8,quint8> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spiel::weitergabeAnGUI)) {
                *result = 2;
            }
        }
        {
            typedef void (Spiel::*_t)(quint8 , std::vector<std::pair<quint8,quint8> > , std::pair<quint8,quint8> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spiel::statusCodeVonGegner)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Spiel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Spiel.data,
      qt_meta_data_Spiel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Spiel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Spiel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Spiel.stringdata0))
        return static_cast<void*>(const_cast< Spiel*>(this));
    return QObject::qt_metacast(_clname);
}

int Spiel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Spiel::koordWeitergabeAnNW(quint8 _t1, quint8 _t2, std::vector<quint8> _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Spiel::rueckgabeAnNW(quint8 _t1, quint8 _t2, std::vector<quint8> _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Spiel::weitergabeAnGUI(quint8 _t1, std::pair<quint8,quint8> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Spiel::statusCodeVonGegner(quint8 _t1, std::vector<std::pair<quint8,quint8> > _t2, std::pair<quint8,quint8> _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
