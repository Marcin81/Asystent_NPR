/****************************************************************************
** Meta object code from reading C++ file 'mygraph.h'
**
** Created: Tue Nov 10 23:44:23 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mygraph.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygraph.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Mygraph[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

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

const QMetaObject *Mygraph::metaObject() const
{
    return &staticMetaObject;
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
