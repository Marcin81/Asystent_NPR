/****************************************************************************
** Meta object code from reading C++ file 'mygraph.h'
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

#include "mygraph.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygraph.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Mygraph[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x09,
      27,    8,    8,    8, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_Mygraph[] = {
    "Mygraph\0\0deletePointSlot()\0graphChangeSlot()\0"
};

const QMetaObject Mygraph::staticMetaObject = {
    { &MyGraphBase::staticMetaObject, qt_meta_stringdata_Mygraph,
      qt_meta_data_Mygraph, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Mygraph::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Mygraph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Mygraph::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Mygraph))
        return static_cast<void*>(const_cast< Mygraph*>(this));
    return MyGraphBase::qt_metacast(_clname);
}

int Mygraph::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyGraphBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: deletePointSlot(); break;
        case 1: graphChangeSlot(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
