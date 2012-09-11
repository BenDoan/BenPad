/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      30,   11,   11,   11, 0x08,
      48,   11,   11,   11, 0x08,
      61,   11,   11,   11, 0x08,
      76,   11,   11,   11, 0x08,
      95,   11,   11,   11, 0x08,
     122,   11,   11,   11, 0x08,
     148,   11,   11,   11, 0x08,
     173,   11,   11,   11, 0x08,
     201,   11,   11,   11, 0x08,
     231,   11,   11,   11, 0x08,
     260,   11,   11,   11, 0x08,
     286,   11,   11,   11, 0x08,
     313,   11,   11,   11, 0x08,
     339,   11,   11,   11, 0x08,
     365,   11,   11,   11, 0x08,
     394,   11,   11,   11, 0x08,
     420,   11,   11,   11, 0x08,
     452,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0switchToPrevTab()\0"
    "switchToNextTab()\0makeNewTab()\0"
    "deleteTab(int)\0deleteCurrentTab()\0"
    "on_actionAbout_triggered()\0"
    "on_actionCopy_triggered()\0"
    "on_actionCut_triggered()\0"
    "on_actionDelete_triggered()\0"
    "on_actionNew_File_triggered()\0"
    "on_actionNew_Tab_triggered()\0"
    "on_actionOpen_triggered()\0"
    "on_actionPaste_triggered()\0"
    "on_actionQuit_triggered()\0"
    "on_actionRedo_triggered()\0"
    "on_actionSave_As_triggered()\0"
    "on_actionSave_triggered()\0"
    "on_actionSelect_All_triggered()\0"
    "on_actionUndo_triggered()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->switchToPrevTab(); break;
        case 1: _t->switchToNextTab(); break;
        case 2: _t->makeNewTab(); break;
        case 3: _t->deleteTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->deleteCurrentTab(); break;
        case 5: _t->on_actionAbout_triggered(); break;
        case 6: _t->on_actionCopy_triggered(); break;
        case 7: _t->on_actionCut_triggered(); break;
        case 8: _t->on_actionDelete_triggered(); break;
        case 9: _t->on_actionNew_File_triggered(); break;
        case 10: _t->on_actionNew_Tab_triggered(); break;
        case 11: _t->on_actionOpen_triggered(); break;
        case 12: _t->on_actionPaste_triggered(); break;
        case 13: _t->on_actionQuit_triggered(); break;
        case 14: _t->on_actionRedo_triggered(); break;
        case 15: _t->on_actionSave_As_triggered(); break;
        case 16: _t->on_actionSave_triggered(); break;
        case 17: _t->on_actionSelect_All_triggered(); break;
        case 18: _t->on_actionUndo_triggered(); break;
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
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
