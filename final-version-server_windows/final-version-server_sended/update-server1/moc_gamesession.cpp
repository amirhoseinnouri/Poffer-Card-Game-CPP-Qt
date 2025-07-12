/****************************************************************************
** Meta object code from reading C++ file 'gamesession.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
**
** create by amirhoseinnouri
*****************************************************************************/

#include <memory>
#include "gamesession.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamesession.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameSession_t {
    QByteArrayData data[9];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameSession_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameSession_t qt_meta_stringdata_GameSession = {
    {
QT_MOC_LITERAL(0, 0, 11), 
QT_MOC_LITERAL(1, 12, 12), 
QT_MOC_LITERAL(2, 25, 0), 
QT_MOC_LITERAL(3, 26, 15), 
QT_MOC_LITERAL(4, 42, 11), 
QT_MOC_LITERAL(5, 54, 12), 
QT_MOC_LITERAL(6, 67, 15), 
QT_MOC_LITERAL(7, 83, 12), 
QT_MOC_LITERAL(8, 96, 13) 

    },
    "GameSession\0gameFinished\0\0player1Username\0"
    "GameHistory\0historyForP1\0player2Username\0"
    "historyForP2\0playerMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameSession[] = {

 // content:
       8,       
       0,       
       0,    0, 
       2,   14, 
       0,    0, 
       0,    0, 
       0,    0, 
       0,       
       1,       

 // signals: name, argc, parameters, tag, flags
       1,    4,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, QMetaType::QString, 0x80000000 | 4,    3,    5,    6,    7,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void GameSession::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameSession *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->gameFinished((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const GameHistory(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const GameHistory(*)>(_a[4]))); break;
        case 1: _t->playerMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameSession::*)(const QString & , const GameHistory & , const QString & , const GameHistory & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameSession::gameFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GameSession::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_GameSession.data,
    qt_meta_data_GameSession,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GameSession::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameSession::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameSession.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GameSession::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void GameSession::gameFinished(const QString & _t1, const GameHistory & _t2, const QString & _t3, const GameHistory & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
