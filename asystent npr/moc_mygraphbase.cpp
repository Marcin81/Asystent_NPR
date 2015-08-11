/****************************************************************************
** Meta object code from reading C++ file 'mygraphbase.h'
**
** Created: Tue Nov 10 23:43:10 2009
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
** License: GPL 
** Owner: Marcin Brysz
** Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
** Version: 1.3 Beta
*****************************************************************************/

#include "mygraphbase.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygraphbase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyGraphBase[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      27,   12,   12,   12, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_MyGraphBase[] = {
    "MyGraphBase\0\0createPoint()\0graphChange()\0"
};

const QMetaObject MyGraphBase::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_MyGraphBase,
      qt_meta_data_MyGraphBase, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyGraphBase::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyGraphBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyGraphBase::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyGraphBase))
        return static_cast<void*>(const_cast< MyGraphBase*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int MyGraphBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: createPoint(); break;
        case 1: graphChange(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void MyGraphBase::createPoint()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MyGraphBase::graphChange()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
