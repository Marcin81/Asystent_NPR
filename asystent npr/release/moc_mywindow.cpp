/****************************************************************************
** Meta object code from reading C++ file 'mywindow.h'
**
** Created: Tue Nov 10 23:44:36 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mywindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mywindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      27,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   41,    9,    9, 0x09,
      72,    9,    9,    9, 0x09,
      90,    9,    9,    9, 0x09,
     110,    9,    9,    9, 0x09,
     127,    9,    9,    9, 0x09,
     153,    9,    9,    9, 0x09,
     168,    9,    9,    9, 0x09,
     188,    9,    9,    9, 0x09,
     208,    9,    9,    9, 0x09,
     222,    9,    9,    9, 0x09,
     241,    9,    9,    9, 0x09,
     258,    9,    9,    9, 0x0a,
     267,    9,    9,    9, 0x0a,
     286,  277,    9,    9, 0x0a,
     297,    9,    9,    9, 0x2a,
     304,    9,    9,    9, 0x0a,
     313,    9,    9,    9, 0x0a,
     320,    9,    9,    9, 0x0a,
     332,    9,    9,    9, 0x0a,
     347,    9,    9,    9, 0x0a,
     371,  363,    9,    9, 0x0a,
     395,  363,    9,    9, 0x0a,
     420,    9,    9,    9, 0x0a,
     453,  443,    9,    9, 0x0a,
     470,    9,    9,    9, 0x2a,
     483,    9,    9,    9, 0x0a,
     515,  499,    9,    9, 0x0a,
     539,  533,    9,    9, 0x2a,
     552,    9,    9,    9, 0x2a,
     560,    9,    9,    9, 0x0a,
     573,    9,    9,    9, 0x0a,
     589,   41,    9,    9, 0x0a,
     608,    9,    9,    9, 0x0a,
     633,  630,    9,    9, 0x0a,
     664,    9,    9,    9, 0x0a,
     672,    9,    9,    9, 0x0a,
     684,    9,    9,    9, 0x0a,
     704,    9,  696,    9, 0x0a,
     716,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyWindow[] = {
    "MyWindow\0\0languageChange()\0beforeClose()\0"
    "pageIndex\0configMenuScale(int)\0"
    "showAboutAction()\0updateTranslation()\0"
    "showHelpAction()\0showHelpDecompressError()\0"
    "deleteThread()\0deleteHelpArchive()\0"
    "showHelpAssistant()\0changeStyle()\0"
    "showLanguageMenu()\0updateTabTitle()\0"
    "zoomIn()\0zoomOut()\0isSaveUs\0save(bool)\0"
    "save()\0saveAs()\0load()\0pageSetup()\0"
    "printPreview()\0printPreviews()\0preview\0"
    "printPreview(QPrinter*)\0"
    "printPreviews(QPrinter*)\0"
    "printerConfiguration()\0isForEach\0"
    "printToPDF(bool)\0printToPDF()\0"
    "printAllToPDF()\0scale,isForEach\0"
    "print(qreal,bool)\0scale\0print(qreal)\0"
    "print()\0addPageTab()\0removePageTab()\0"
    "removePageTab(int)\0interpretationGraph()\0"
    "on\0autointerpretationGraphs(bool)\0"
    "clean()\0clearView()\0showAbout()\0QLocale\0"
    "getLocale()\0help()\0"
};

const QMetaObject MyWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MyWindow,
      qt_meta_data_MyWindow, 0 }
};

const QMetaObject *MyWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MyWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyWindow))
        return static_cast<void*>(const_cast< MyWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MyWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: languageChange(); break;
        case 1: beforeClose(); break;
        case 2: configMenuScale((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: showAboutAction(); break;
        case 4: updateTranslation(); break;
        case 5: showHelpAction(); break;
        case 6: showHelpDecompressError(); break;
        case 7: deleteThread(); break;
        case 8: deleteHelpArchive(); break;
        case 9: showHelpAssistant(); break;
        case 10: changeStyle(); break;
        case 11: showLanguageMenu(); break;
        case 12: updateTabTitle(); break;
        case 13: zoomIn(); break;
        case 14: zoomOut(); break;
        case 15: save((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 16: save(); break;
        case 17: saveAs(); break;
        case 18: load(); break;
        case 19: pageSetup(); break;
        case 20: printPreview(); break;
        case 21: printPreviews(); break;
        case 22: printPreview((*reinterpret_cast< QPrinter*(*)>(_a[1]))); break;
        case 23: printPreviews((*reinterpret_cast< QPrinter*(*)>(_a[1]))); break;
        case 24: printerConfiguration(); break;
        case 25: printToPDF((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 26: printToPDF(); break;
        case 27: printAllToPDF(); break;
        case 28: print((*reinterpret_cast< const qreal(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 29: print((*reinterpret_cast< const qreal(*)>(_a[1]))); break;
        case 30: print(); break;
        case 31: addPageTab(); break;
        case 32: removePageTab(); break;
        case 33: removePageTab((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 34: interpretationGraph(); break;
        case 35: autointerpretationGraphs((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 36: clean(); break;
        case 37: clearView(); break;
        case 38: showAbout(); break;
        case 39: { QLocale _r = getLocale();
            if (_a[0]) *reinterpret_cast< QLocale*>(_a[0]) = _r; }  break;
        case 40: help(); break;
        default: ;
        }
        _id -= 41;
    }
    return _id;
}

// SIGNAL 0
void MyWindow::languageChange()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MyWindow::beforeClose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
