#ifndef CONNECTIONS_H
#define CONNECTIONS_H

#include <QObject>
#include <QDebug>
#include <QThread>

class connections : public QObject
{
    Q_OBJECT
public:
    explicit connections(QObject *parent = nullptr, const QString &name = QString());

signals:
    void event();

public slots:
    void on_event();
};

#endif // CONNECTIONS_H
