/****************************************************************************
** Meta object code from reading C++ file 'imagepoint.h'
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

#include "imagepoint.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagepoint.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImagePoint[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      32,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ImagePoint[] = {
    "ImagePoint\0\0deletePointSignal()\0"
    "stateChange()\0updateTranslation()\0"
};

const QMetaObject ImagePoint::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ImagePoint,
      qt_meta_data_ImagePoint, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImagePoint::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImagePoint::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImagePoint::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImagePoint))
        return static_cast<void*>(const_cast< ImagePoint*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< ImagePoint*>(this));
    return QObject::qt_metacast(_clname);
}

int ImagePoint::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: deletePointSignal(); break;
        case 1: stateChange(); break;
        case 2: updateTranslation(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ImagePoint::deletePointSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ImagePoint::stateChange()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
