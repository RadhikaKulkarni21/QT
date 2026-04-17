#ifndef QOBJECT_MEMORY_H
#define QOBJECT_MEMORY_H

#include <QObject>
#include <QDebug>

class QObject_memory : public QObject
{
    Q_OBJECT
public:
    explicit QObject_memory(QString objectnamne,QObject *parent = nullptr);
    ~QObject_memory();

signals:
};

#endif // QOBJECT_MEMORY_H
