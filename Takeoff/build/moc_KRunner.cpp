/****************************************************************************
** Meta object code from reading C++ file 'KRunner.h'
**
** Created: Thu Sep 29 19:28:58 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/takeoff/model/krunner/KRunner.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KRunner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KRunner[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,    9,    8,    8, 0x05,
      56,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      81,   75,    8,    8, 0x0a,
     112,  103,    8,    8, 0x0a,
     151,  143,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_KRunner[] = {
    "KRunner\0\0result\0queryFinished(QList<Takeoff::Launcher>)\0"
    "launcherExecuted()\0query\0executeQuery(QString)\0"
    "launcher\0runLauncher(Takeoff::Launcher)\0"
    "matches\0parseQuery(QList<Plasma::QueryMatch>)\0"
};

const QMetaObject KRunner::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KRunner,
      qt_meta_data_KRunner, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KRunner::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KRunner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KRunner::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KRunner))
        return static_cast<void*>(const_cast< KRunner*>(this));
    return QObject::qt_metacast(_clname);
}

int KRunner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: queryFinished((*reinterpret_cast< QList<Takeoff::Launcher>(*)>(_a[1]))); break;
        case 1: launcherExecuted(); break;
        case 2: executeQuery((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: runLauncher((*reinterpret_cast< const Takeoff::Launcher(*)>(_a[1]))); break;
        case 4: parseQuery((*reinterpret_cast< QList<Plasma::QueryMatch>(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void KRunner::queryFinished(QList<Takeoff::Launcher> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KRunner::launcherExecuted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
