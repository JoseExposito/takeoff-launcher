/****************************************************************************
** Meta object code from reading C++ file 'SearchWidget.h'
**
** Created: Thu Sep 29 17:29:59 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/takeoff/view/takeoff_widget/search/SearchWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SearchWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TakeoffPrivate__SearchWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      30,   29,   29,   29, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   29,   29,   29, 0x08,
      60,   52,   29,   29, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TakeoffPrivate__SearchWidget[] = {
    "TakeoffPrivate::SearchWidget\0\0"
    "exitSearch()\0search()\0matches\0"
    "showQuery(QList<Takeoff::Launcher>)\0"
};

const QMetaObject TakeoffPrivate::SearchWidget::staticMetaObject = {
    { &QGraphicsWidget::staticMetaObject, qt_meta_stringdata_TakeoffPrivate__SearchWidget,
      qt_meta_data_TakeoffPrivate__SearchWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TakeoffPrivate::SearchWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TakeoffPrivate::SearchWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TakeoffPrivate::SearchWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TakeoffPrivate__SearchWidget))
        return static_cast<void*>(const_cast< SearchWidget*>(this));
    return QGraphicsWidget::qt_metacast(_clname);
}

int TakeoffPrivate::SearchWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: exitSearch(); break;
        case 1: search(); break;
        case 2: showQuery((*reinterpret_cast< QList<Takeoff::Launcher>(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void TakeoffPrivate::SearchWidget::exitSearch()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
