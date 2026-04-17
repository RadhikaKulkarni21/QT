#ifndef MYQOBJECT_H
#define MYQOBJECT_H

#include <QObject>
#include <QDebug>

class MyQObject : public QObject
{
    Q_OBJECT
public:
    explicit MyQObject(QObject *parent = nullptr);

signals:
    void newSignal(QString message);

public slots:
    void newSlot(QString message);
};

#endif // MYQOBJECT_H
