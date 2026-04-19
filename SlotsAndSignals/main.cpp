#include <QCoreApplication>

#include "sender.h"
#include "receiver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Sender *sender = new Sender();
    Receiver *receiver = new Receiver();

    QObject::connect(sender, &Sender::event, receiver, &Receiver::on_event);

    emit sender->event("Connect signals and slots");

    return QCoreApplication::exec();
}
