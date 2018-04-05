/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "game.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Game_t {
    QByteArrayData data[17];
    char stringdata0[279];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Game_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Game_t qt_meta_stringdata_Game = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Game"
QT_MOC_LITERAL(1, 5, 18), // "attackP2Coordinate"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 19), // "std::vector<quint8>"
QT_MOC_LITERAL(4, 45, 14), // "ourSCtoNetwork"
QT_MOC_LITERAL(5, 60, 17), // "infoToGuiAttackP1"
QT_MOC_LITERAL(6, 78, 24), // "std::pair<quint8,quint8>"
QT_MOC_LITERAL(7, 103, 22), // "statusCodePlayer2ToGUI"
QT_MOC_LITERAL(8, 126, 38), // "std::vector<std::pair<quint8,..."
QT_MOC_LITERAL(9, 165, 13), // "attackPlayer2"
QT_MOC_LITERAL(10, 179, 1), // "c"
QT_MOC_LITERAL(11, 181, 20), // "setTurnOfBothPlayers"
QT_MOC_LITERAL(12, 202, 6), // "signal"
QT_MOC_LITERAL(13, 209, 15), // "attackOnPlayer1"
QT_MOC_LITERAL(14, 225, 20), // "processingSCOpponent"
QT_MOC_LITERAL(15, 246, 10), // "statusCode"
QT_MOC_LITERAL(16, 257, 21) // "coordinatesOfSunkShip"

    },
    "Game\0attackP2Coordinate\0\0std::vector<quint8>\0"
    "ourSCtoNetwork\0infoToGuiAttackP1\0"
    "std::pair<quint8,quint8>\0"
    "statusCodePlayer2ToGUI\0"
    "std::vector<std::pair<quint8,quint8> >\0"
    "attackPlayer2\0c\0setTurnOfBothPlayers\0"
    "signal\0attackOnPlayer1\0processingSCOpponent\0"
    "statusCode\0coordinatesOfSunkShip"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Game[] = {

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
    QMetaType::Void, 0x80000000 | 6,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, 0x80000000 | 6,   10,
    QMetaType::Void, QMetaType::UChar, 0x80000000 | 8,   15,   16,
    QMetaType::Void, QMetaType::UChar,   15,

       0        // eod
};

void Game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Game *_t = static_cast<Game *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->attackP2Coordinate((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< std::vector<quint8>(*)>(_a[3]))); break;
        case 1: _t->ourSCtoNetwork((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< std::vector<quint8>(*)>(_a[3]))); break;
        case 2: _t->infoToGuiAttackP1((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< std::pair<quint8,quint8>(*)>(_a[2]))); break;
        case 3: _t->statusCodePlayer2ToGUI((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< std::vector<std::pair<quint8,quint8> >(*)>(_a[2])),(*reinterpret_cast< std::pair<quint8,quint8>(*)>(_a[3]))); break;
        case 4: _t->attackPlayer2((*reinterpret_cast< std::pair<quint8,quint8>(*)>(_a[1]))); break;
        case 5: _t->setTurnOfBothPlayers((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->attackOnPlayer1((*reinterpret_cast< std::pair<quint8,quint8>(*)>(_a[1]))); break;
        case 7: _t->processingSCOpponent((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< std::vector<std::pair<quint8,quint8> >(*)>(_a[2]))); break;
        case 8: _t->processingSCOpponent((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Game::*_t)(quint8 , quint8 , std::vector<quint8> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game::attackP2Coordinate)) {
                *result = 0;
            }
        }
        {
            typedef void (Game::*_t)(quint8 , quint8 , std::vector<quint8> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game::ourSCtoNetwork)) {
                *result = 1;
            }
        }
        {
            typedef void (Game::*_t)(quint8 , std::pair<quint8,quint8> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game::infoToGuiAttackP1)) {
                *result = 2;
            }
        }
        {
            typedef void (Game::*_t)(quint8 , std::vector<std::pair<quint8,quint8> > , std::pair<quint8,quint8> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game::statusCodePlayer2ToGUI)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Game::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Game.data,
      qt_meta_data_Game,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Game::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Game.stringdata0))
        return static_cast<void*>(const_cast< Game*>(this));
    return QObject::qt_metacast(_clname);
}

int Game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Game::attackP2Coordinate(quint8 _t1, quint8 _t2, std::vector<quint8> _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Game::ourSCtoNetwork(quint8 _t1, quint8 _t2, std::vector<quint8> _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Game::infoToGuiAttackP1(quint8 _t1, std::pair<quint8,quint8> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Game::statusCodePlayer2ToGUI(quint8 _t1, std::vector<std::pair<quint8,quint8> > _t2, std::pair<quint8,quint8> _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
