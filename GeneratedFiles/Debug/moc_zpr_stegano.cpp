/****************************************************************************
** Meta object code from reading C++ file 'zpr_stegano.h'
**
** Created: Wed 7. Nov 10:52:06 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../zpr_stegano.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zpr_stegano.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ZPR_STEGANO[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   13,   12,   12, 0x05,
      42,   12,   12,   12, 0x05,
      65,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      88,   12,   12,   12, 0x0a,
     108,   12,   12,   12, 0x0a,
     128,   12,   12,   12, 0x0a,
     148,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ZPR_STEGANO[] = {
    "ZPR_STEGANO\0\0id\0steganoMethodChoosen(int)\0"
    "encryptButtonClicked()\0decryptButtonClicked()\0"
    "updateProgress(int)\0onEncryptFinished()\0"
    "onDecryptFinished()\0displayPreview(PImage)\0"
};

void ZPR_STEGANO::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ZPR_STEGANO *_t = static_cast<ZPR_STEGANO *>(_o);
        switch (_id) {
        case 0: _t->steganoMethodChoosen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->encryptButtonClicked(); break;
        case 2: _t->decryptButtonClicked(); break;
        case 3: _t->updateProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onEncryptFinished(); break;
        case 5: _t->onDecryptFinished(); break;
        case 6: _t->displayPreview((*reinterpret_cast< PImage(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ZPR_STEGANO::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ZPR_STEGANO::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ZPR_STEGANO,
      qt_meta_data_ZPR_STEGANO, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ZPR_STEGANO::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ZPR_STEGANO::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ZPR_STEGANO::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ZPR_STEGANO))
        return static_cast<void*>(const_cast< ZPR_STEGANO*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ZPR_STEGANO::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ZPR_STEGANO::steganoMethodChoosen(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ZPR_STEGANO::encryptButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ZPR_STEGANO::decryptButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
