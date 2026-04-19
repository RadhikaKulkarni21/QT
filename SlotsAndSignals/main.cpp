#include <QCoreApplication>

#include "sender.h"
#include "receiver.h"
#include "connections.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Sender *sender = new Sender();
    Receiver *receiver = new Receiver();

    QObject::connect(sender, &Sender::event, receiver, &Receiver::on_event);

    emit sender->event("Connect signals and slots");


    QThread::currentThread()->setObjectName("Main Thread");

    connections *source = new connections(nullptr, "source");
    connections *destination = new connections(nullptr, "destination");

    QThread thread;
    QObject::connect(&thread, &QThread::finished, destination, &QObject::deleteLater);
    QObject::connect(&thread, &QThread::finished, source, &QObject::deleteLater);
    thread.start();
    thread.setObjectName("Separate Thread");
    destination->moveToThread(&thread);

    QObject::connect(source, &connections::event, destination, &connections::on_event, Qt::QueuedConnection);

    qInfo() << "\nEmitting signal event() from" << QThread::currentThread();
    emit source->event();
    thread.wait(3000);
    thread.quit();

    return QCoreApplication::exec();
}
