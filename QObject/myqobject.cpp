#include "myqobject.h"

MyQObject::MyQObject(QObject *parent)
    : QObject{parent}
{}

void MyQObject::newSlot(QString message)
{
    qInfo() << "Message received from newSlot1: "<< message;
}
