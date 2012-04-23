/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Apr 22 19:17:33 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../csept_GUI/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      23,   11,   11,   11, 0x0a,
      46,   11,   11,   11, 0x0a,
      69,   11,   11,   11, 0x0a,
      91,   11,   11,   11, 0x0a,
     115,   11,   11,   11, 0x0a,
     139,   11,   11,   11, 0x0a,
     158,   11,   11,   11, 0x0a,
     183,   11,   11,   11, 0x0a,
     213,   11,   11,   11, 0x0a,
     242,   11,   11,   11, 0x0a,
     279,   11,   11,   11, 0x0a,
     305,   11,   11,   11, 0x0a,
     334,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0testSlot()\0change2calendar_Slot()\0"
    "change2todolist_Slot()\0change2memopad_Slot()\0"
    "change2eventlist_Slot()\0change2alarmlist_Slot()\0"
    "changeddate_Slot()\0alarmList_changed_slot()\0"
    "alarmList_repeatingYes_slot()\0"
    "alarmList_repeatingNo_slot()\0"
    "alarmList_newFrequency_slot(QString)\0"
    "alarmList_addalarm_slot()\0"
    "alarmList_deletealarm_slot()\0"
    "alarmList_editalarm_slot()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->testSlot(); break;
        case 1: _t->change2calendar_Slot(); break;
        case 2: _t->change2todolist_Slot(); break;
        case 3: _t->change2memopad_Slot(); break;
        case 4: _t->change2eventlist_Slot(); break;
        case 5: _t->change2alarmlist_Slot(); break;
        case 6: _t->changeddate_Slot(); break;
        case 7: _t->alarmList_changed_slot(); break;
        case 8: _t->alarmList_repeatingYes_slot(); break;
        case 9: _t->alarmList_repeatingNo_slot(); break;
        case 10: _t->alarmList_newFrequency_slot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->alarmList_addalarm_slot(); break;
        case 12: _t->alarmList_deletealarm_slot(); break;
        case 13: _t->alarmList_editalarm_slot(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
