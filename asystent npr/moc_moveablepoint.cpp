/****************************************************************************
** Meta object code from reading C++ file 'moveablepoint.h'
**
** Created: Tue Oct 27 10:27:14 2009
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
** License: GPL 
** Owner: Marcin Brysz
** Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
** Version: 1.3 Beta
*****************************************************************************/

#include "moveablepoint.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'moveablepoint.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MoveablePoint[] = {

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
      15,   14,   14,   14, 0x05,
      35,   14,   14,   14, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_MoveablePoint[] = {
    "MoveablePoint\0\0deletePointSignal()\0"
    "stateChange()\0"
};

const QMetaObject MoveablePoint::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MoveablePoint,
      qt_meta_data_MoveablePoint, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MoveablePoint::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MoveablePoint::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MoveablePoint::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MoveablePoint))
        return static_cast<void*>(const_cast< MoveablePoint*>(this));
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< MoveablePoint*>(this));
    return QObject::qt_metacast(_clname);
}

int MoveablePoint::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: deletePointSignal(); break;
        case 1: stateChange(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void MoveablePoint::deletePointSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MoveablePoint::stateChange()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
