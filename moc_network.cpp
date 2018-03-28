/****************************************************************************
** Meta object code from reading C++ file 'network.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "network.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'network.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_network_t {
    QByteArrayData data[25];
    char stringdata0[331];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_network_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_network_t qt_meta_stringdata_network = {
    {
QT_MOC_LITERAL(0, 0, 7), // "network"
QT_MOC_LITERAL(1, 8, 10), // "GameParams"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 19), // "std::vector<quint8>"
QT_MOC_LITERAL(4, 40, 4), // "data"
QT_MOC_LITERAL(5, 45, 4), // "Shot"
QT_MOC_LITERAL(6, 50, 24), // "std::pair<quint8,quint8>"
QT_MOC_LITERAL(7, 75, 4), // "shot"
QT_MOC_LITERAL(8, 80, 9), // "GameState"
QT_MOC_LITERAL(9, 90, 10), // "ShotAnswer"
QT_MOC_LITERAL(10, 101, 10), // "statuscode"
QT_MOC_LITERAL(11, 112, 38), // "std::vector<std::pair<quint8,..."
QT_MOC_LITERAL(12, 151, 17), // "koordinatenvector"
QT_MOC_LITERAL(13, 169, 8), // "NoAnswer"
QT_MOC_LITERAL(14, 178, 12), // "NetworkToGui"
QT_MOC_LITERAL(15, 191, 9), // "GameStart"
QT_MOC_LITERAL(16, 201, 20), // "startToWaitForAnswer"
QT_MOC_LITERAL(17, 222, 18), // "sendTimeoutToEnemy"
QT_MOC_LITERAL(18, 241, 4), // "send"
QT_MOC_LITERAL(19, 246, 3), // "cmd"
QT_MOC_LITERAL(20, 250, 6), // "length"
QT_MOC_LITERAL(21, 257, 18), // "StartButtonPressed"
QT_MOC_LITERAL(22, 276, 11), // "receiveData"
QT_MOC_LITERAL(23, 288, 13), // "onSocketError"
QT_MOC_LITERAL(24, 302, 28) // "QAbstractSocket::SocketError"

    },
    "network\0GameParams\0\0std::vector<quint8>\0"
    "data\0Shot\0std::pair<quint8,quint8>\0"
    "shot\0GameState\0ShotAnswer\0statuscode\0"
    "std::vector<std::pair<quint8,quint8> >\0"
    "koordinatenvector\0NoAnswer\0NetworkToGui\0"
    "GameStart\0startToWaitForAnswer\0"
    "sendTimeoutToEnemy\0send\0cmd\0length\0"
    "StartButtonPressed\0receiveData\0"
    "onSocketError\0QAbstractSocket::SocketError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_network[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       5,    1,   82,    2, 0x06 /* Public */,
       8,    1,   85,    2, 0x06 /* Public */,
       9,    2,   88,    2, 0x06 /* Public */,
      13,    0,   93,    2, 0x06 /* Public */,
      14,    1,   94,    2, 0x06 /* Public */,
      15,    1,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    0,  100,    2, 0x0a /* Public */,
      17,    0,  101,    2, 0x0a /* Public */,
      18,    3,  102,    2, 0x0a /* Public */,
      21,    0,  109,    2, 0x0a /* Public */,
      22,    0,  110,    2, 0x0a /* Public */,
      23,    1,  111,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::UChar, 0x80000000 | 11,   10,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, 0x80000000 | 3,   19,   20,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 24,    2,

       0        // eod
};

void network::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        network *_t = static_cast<network *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GameParams((*reinterpret_cast< std::vector<quint8>(*)>(_a[1]))); break;
        case 1: _t->Shot((*reinterpret_cast< std::pair<quint8,quint8>(*)>(_a[1]))); break;
        case 2: _t->GameState((*reinterpret_cast< std::vector<quint8>(*)>(_a[1]))); break;
        case 3: _t->ShotAnswer((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< std::vector<std::pair<quint8,quint8> >(*)>(_a[2]))); break;
        case 4: _t->NoAnswer(); break;
        case 5: _t->NetworkToGui((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->GameStart((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->startToWaitForAnswer(); break;
        case 8: _t->sendTimeoutToEnemy(); break;
        case 9: _t->send((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< std::vector<quint8>(*)>(_a[3]))); break;
        case 10: _t->StartButtonPressed(); break;
        case 11: _t->receiveData(); break;
        case 12: _t->onSocketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (network::*_t)(std::vector<quint8> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&network::GameParams)) {
                *result = 0;
            }
        }
        {
            typedef void (network::*_t)(std::pair<quint8,quint8> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&network::Shot)) {
                *result = 1;
            }
        }
        {
            typedef void (network::*_t)(std::vector<quint8> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&network::GameState)) {
                *result = 2;
            }
        }
        {
            typedef void (network::*_t)(quint8 , std::vector<std::pair<quint8,quint8>> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&network::ShotAnswer)) {
                *result = 3;
            }
        }
        {
            typedef void (network::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&network::NoAnswer)) {
                *result = 4;
            }
        }
        {
            typedef void (network::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&network::NetworkToGui)) {
                *result = 5;
            }
        }
        {
            typedef void (network::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&network::GameStart)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject network::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_network.data,
      qt_meta_data_network,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *network::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *network::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_network.stringdata0))
        return static_cast<void*>(const_cast< network*>(this));
    return QObject::qt_metacast(_clname);
}

int network::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void network::GameParams(std::vector<quint8> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void network::Shot(std::pair<quint8,quint8> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void network::GameState(std::vector<quint8> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void network::ShotAnswer(quint8 _t1, std::vector<std::pair<quint8,quint8>> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void network::NoAnswer()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void network::NetworkToGui(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void network::GameStart(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
