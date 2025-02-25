/****************************************************************************
** Meta object code from reading C++ file 'primechecker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../primechecker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'primechecker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PrimeChecker_t {
    uint offsetsAndSizes[28];
    char stringdata0[13];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[12];
    char stringdata5[8];
    char stringdata6[13];
    char stringdata7[8];
    char stringdata8[16];
    char stringdata9[14];
    char stringdata10[7];
    char stringdata11[13];
    char stringdata12[14];
    char stringdata13[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_PrimeChecker_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_PrimeChecker_t qt_meta_stringdata_PrimeChecker = {
    {
        QT_MOC_LITERAL(0, 12),  // "PrimeChecker"
        QT_MOC_LITERAL(13, 15),  // "progressUpdated"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 8),  // "progress"
        QT_MOC_LITERAL(39, 11),  // "resultReady"
        QT_MOC_LITERAL(51, 7),  // "isPrime"
        QT_MOC_LITERAL(59, 12),  // "errorMessage"
        QT_MOC_LITERAL(72, 7),  // "message"
        QT_MOC_LITERAL(80, 15),  // "processNextStep"
        QT_MOC_LITERAL(96, 13),  // "startChecking"
        QT_MOC_LITERAL(110, 6),  // "number"
        QT_MOC_LITERAL(117, 12),  // "stopChecking"
        QT_MOC_LITERAL(130, 13),  // "pauseChecking"
        QT_MOC_LITERAL(144, 11)   // "getProgress"
    },
    "PrimeChecker",
    "progressUpdated",
    "",
    "progress",
    "resultReady",
    "isPrime",
    "errorMessage",
    "message",
    "processNextStep",
    "startChecking",
    "number",
    "stopChecking",
    "pauseChecking",
    "getProgress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PrimeChecker[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       4,    1,   65,    2, 0x06,    3 /* Public */,
       6,    1,   68,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   71,    2, 0x08,    7 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,   72,    2, 0x02,    8 /* Public */,
      11,    0,   75,    2, 0x02,   10 /* Public */,
      12,    0,   76,    2, 0x02,   11 /* Public */,
      13,    0,   77,    2, 0x102,   12 /* Public | MethodIsConst  */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::LongLong,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Double,

       0        // eod
};

void PrimeChecker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PrimeChecker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->progressUpdated((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 1: _t->resultReady((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->errorMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->processNextStep(); break;
        case 4: _t->startChecking((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 5: _t->stopChecking(); break;
        case 6: _t->pauseChecking(); break;
        case 7: { double _r = _t->getProgress();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PrimeChecker::*)(double );
            if (_t _q_method = &PrimeChecker::progressUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PrimeChecker::*)(bool );
            if (_t _q_method = &PrimeChecker::resultReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PrimeChecker::*)(QString );
            if (_t _q_method = &PrimeChecker::errorMessage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject PrimeChecker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_PrimeChecker.offsetsAndSizes,
    qt_meta_data_PrimeChecker,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PrimeChecker_t
, QtPrivate::TypeAndForceComplete<PrimeChecker, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<qint64, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>

>,
    nullptr
} };


const QMetaObject *PrimeChecker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PrimeChecker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PrimeChecker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PrimeChecker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void PrimeChecker::progressUpdated(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PrimeChecker::resultReady(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PrimeChecker::errorMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
