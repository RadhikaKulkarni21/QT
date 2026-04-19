#include "receiver.h"

Receiver::Receiver(QObject *parent)
    : QObject{parent}
{}

void Receiver::on_event(QString message)
{
    qInfo() << "Excuting slot inside " << this;
    qInfo() << "Message received " << message;
}
