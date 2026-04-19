#include "connections.h"

connections::connections(QObject *parent, const QString &name)
    : QObject{parent}
{
    setObjectName(name);
    qInfo() << this << "created on" << QThread::currentThread();
}

void connections::on_event()
{
    qInfo() << "Executing slot onEvent() on" << QThread::currentThread();
}
