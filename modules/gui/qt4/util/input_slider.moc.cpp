/****************************************************************************
** Meta object code from reading C++ file 'input_slider.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "input_slider.hpp"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'input_slider.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SeekSlider[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       2,   54, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   33,   11,   11, 0x0a,
      69,   67,   11,   11, 0x0a,
      87,   11,   11,   11, 0x0a,
     110,   11,   11,   11, 0x0a,
     123,   11,   11,   11, 0x08,
     140,   11,   11,   11, 0x08,
     160,  152,   11,   11, 0x08,

 // properties: name, type, flags
     196,  190, ((uint)QMetaType::QReal << 24) | 0x00095103,
     210,  190, ((uint)QMetaType::QReal << 24) | 0x00095003,

       0        // eod
};

static const char qt_meta_stringdata_SeekSlider[] = {
    "SeekSlider\0\0sliderDragged(float)\0,,\0"
    "setPosition(float,int64_t,int)\0b\0"
    "setSeekable(bool)\0updateBuffering(float)\0"
    "hideHandle()\0startSeekTimer()\0updatePos()\0"
    "p_input\0inputUpdated(input_thread_t*)\0"
    "qreal\0handleOpacity\0loadingProperty\0"
};

void SeekSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SeekSlider *_t = static_cast<SeekSlider *>(_o);
        switch (_id) {
        case 0: _t->sliderDragged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->setPosition((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int64_t(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->setSeekable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->updateBuffering((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->hideHandle(); break;
        case 5: _t->startSeekTimer(); break;
        case 6: _t->updatePos(); break;
        case 7: _t->inputUpdated((*reinterpret_cast< input_thread_t*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SeekSlider::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SeekSlider::staticMetaObject = {
    { &QSlider::staticMetaObject, qt_meta_stringdata_SeekSlider,
      qt_meta_data_SeekSlider, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SeekSlider::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SeekSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SeekSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SeekSlider))
        return static_cast<void*>(const_cast< SeekSlider*>(this));
    return QSlider::qt_metacast(_clname);
}

int SeekSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSlider::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = handleOpacity(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = loading(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setHandleOpacity(*reinterpret_cast< qreal*>(_v)); break;
        case 1: setLoading(*reinterpret_cast< qreal*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void SeekSlider::sliderDragged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_SoundSlider[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_SoundSlider[] = {
    "SoundSlider\0"
};

void SoundSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SoundSlider::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SoundSlider::staticMetaObject = {
    { &QAbstractSlider::staticMetaObject, qt_meta_stringdata_SoundSlider,
      qt_meta_data_SoundSlider, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SoundSlider::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SoundSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SoundSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SoundSlider))
        return static_cast<void*>(const_cast< SoundSlider*>(this));
    return QAbstractSlider::qt_metacast(_clname);
}

int SoundSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractSlider::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
