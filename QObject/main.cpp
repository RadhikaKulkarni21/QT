#include <QCoreApplication>
#include <QDebug>
#include <QMetaProperty>
#include <QMetaProperty>

#include "myqobject.h"
#include "myqobject2.h"
#include "qobject_meta.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyQObject *object1 = new MyQObject();
    MyQObject2 *object2 = new MyQObject2();
    QObject_Meta *obj = new QObject_Meta();

    //Signals and Slots
    QObject::connect(object1, &MyQObject::newSignal, object1, &MyQObject::newSlot);
    QObject::connect(object1, &MyQObject::newSignal, object2, &MyQObject2::newSlot2);

    emit object1->newSignal("Connect world");

    QObject::disconnect(object1, &MyQObject::newSignal, object1, &MyQObject::newSlot);
    QObject::disconnect(object1, &MyQObject::newSignal, object2, &MyQObject2::newSlot2);

    emit object1->newSignal("Disconnet World");

    //QProperties
    object1->setProperty("information", "Property World");
    qInfo() << "InformationProperty: " << object1->property("information");

    object1->setProperty("value", 50);
    qInfo() << "Value property:" << object1->property("value");

    //Introspection
    qInfo() << "---------- OBJECT INFO ----------";
    qInfo() << "Class name: " <<obj->metaObject()->className();
    qInfo() << "Superclass name: " <<obj->metaObject()->superClass()->className();
    qInfo() << "Property count: " <<obj->metaObject()->propertyCount();
    qInfo() << "Method count: " <<obj->metaObject()->methodCount();
    qInfo() << "Enumerator count: " <<obj->metaObject()->enumeratorCount();

    qInfo() << "\n---------- PROPERTIES ----------";
    const QMetaObject* metaObject = obj->metaObject();
    for(int i = 0; i < metaObject->propertyCount(); ++i)
        qInfo() << "Property" << i << ":" << metaObject->property(i).name();

    qInfo() << "\n---------- METHODS ----------";
    for(int i = 0; i < metaObject->methodCount(); i++)
        qInfo() << "Method" << i << ":" << metaObject->method(i).name();

    qInfo() << "\n---------- ENUMERATORS ----------";
    for(int i = 0; i < metaObject->enumeratorCount(); i++)
        qInfo() << "Enumerator" << i << ":" << metaObject->enumerator(i).name();

    return a.exec();

    //return QCoreApplication::exec();
}
