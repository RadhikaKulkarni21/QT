#include "qobject_memory.h"

QObject_memory::QObject_memory(QString objectname, QObject *parent)
    : QObject{parent}
{
    this->setObjectName(objectname);
    qInfo() << this->objectName() << "created";
}

QObject_memory::~QObject_memory()
{
    qInfo() << this->objectName() << "destroyed";
}
