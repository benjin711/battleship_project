/****************************************************************************
** Meta object code from reading C++ file 'board.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "board.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'board.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Board_t {
    QByteArrayData data[19];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Board_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Board_t qt_meta_stringdata_Board = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Board"
QT_MOC_LITERAL(1, 6, 10), // "possibleC2"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 36), // "std::vector<std::pair<qint8,q..."
QT_MOC_LITERAL(4, 55, 14), // "endCoordinates"
QT_MOC_LITERAL(5, 70, 22), // "std::pair<qint8,qint8>"
QT_MOC_LITERAL(6, 93, 2), // "c1"
QT_MOC_LITERAL(7, 96, 19), // "lengthOfCurrentShip"
QT_MOC_LITERAL(8, 116, 23), // "coordinatesOfPlacedShip"
QT_MOC_LITERAL(9, 140, 16), // "finalCoordinates"
QT_MOC_LITERAL(10, 157, 14), // "allShipsPlaced"
QT_MOC_LITERAL(11, 172, 6), // "signal"
QT_MOC_LITERAL(12, 179, 21), // "coordinatesOfAllShips"
QT_MOC_LITERAL(13, 201, 14), // "allCoordinates"
QT_MOC_LITERAL(14, 216, 19), // "randomShipPlacement"
QT_MOC_LITERAL(15, 236, 22), // "setLengthOfCurrentShip"
QT_MOC_LITERAL(16, 259, 17), // "coordinatesOfShip"
QT_MOC_LITERAL(17, 277, 18), // "std::pair<int,int>"
QT_MOC_LITERAL(18, 296, 1) // "c"

    },
    "Board\0possibleC2\0\0"
    "std::vector<std::pair<qint8,qint8> >\0"
    "endCoordinates\0std::pair<qint8,qint8>\0"
    "c1\0lengthOfCurrentShip\0coordinatesOfPlacedShip\0"
    "finalCoordinates\0allShipsPlaced\0signal\0"
    "coordinatesOfAllShips\0allCoordinates\0"
    "randomShipPlacement\0setLengthOfCurrentShip\0"
    "coordinatesOfShip\0std::pair<int,int>\0"
    "c"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Board[] = {

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
      10,    1,   59,    2, 0x06 /* Public */,
      12,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,   65,    2, 0x0a /* Public */,
      15,    1,   66,    2, 0x0a /* Public */,
      16,    1,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::SChar,    4,    6,    7,
    QMetaType::Void, 0x80000000 | 3,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, 0x80000000 | 3,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, 0x80000000 | 17,   18,

       0        // eod
};

void Board::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Board *_t = static_cast<Board *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->possibleC2((*reinterpret_cast< std::vector<std::pair<qint8,qint8> >(*)>(_a[1])),(*reinterpret_cast< std::pair<qint8,qint8>(*)>(_a[2])),(*reinterpret_cast< qint8(*)>(_a[3]))); break;
        case 1: _t->coordinatesOfPlacedShip((*reinterpret_cast< std::vector<std::pair<qint8,qint8> >(*)>(_a[1]))); break;
        case 2: _t->allShipsPlaced((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->coordinatesOfAllShips((*reinterpret_cast< std::vector<std::pair<qint8,qint8> >(*)>(_a[1]))); break;
        case 4: _t->randomShipPlacement(); break;
        case 5: _t->setLengthOfCurrentShip((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->coordinatesOfShip((*reinterpret_cast< std::pair<int,int>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Board::*_t)(std::vector<std::pair<qint8,qint8> > , std::pair<qint8,qint8> , qint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Board::possibleC2)) {
                *result = 0;
            }
        }
        {
            typedef void (Board::*_t)(std::vector<std::pair<qint8,qint8> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Board::coordinatesOfPlacedShip)) {
                *result = 1;
            }
        }
        {
            typedef void (Board::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Board::allShipsPlaced)) {
                *result = 2;
            }
        }
        {
            typedef void (Board::*_t)(std::vector<std::pair<qint8,qint8> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Board::coordinatesOfAllShips)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Board::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Board.data,
      qt_meta_data_Board,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Board::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Board::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Board.stringdata0))
        return static_cast<void*>(const_cast< Board*>(this));
    return QObject::qt_metacast(_clname);
}

int Board::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Board::possibleC2(std::vector<std::pair<qint8,qint8> > _t1, std::pair<qint8,qint8> _t2, qint8 _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Board::coordinatesOfPlacedShip(std::vector<std::pair<qint8,qint8> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Board::allShipsPlaced(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Board::coordinatesOfAllShips(std::vector<std::pair<qint8,qint8> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
