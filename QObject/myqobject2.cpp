#include "myqobject2.h"

MyQObject2::MyQObject2(QObject *parent)
    : QObject{parent}
{}

void MyQObject2::newSlot2(QString message)
{
    //qInfo() << "Message received from newSlot2: "<< message;
}
