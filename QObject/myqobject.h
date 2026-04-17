#ifndef MYQOBJECT_H
#define MYQOBJECT_H

#include <QObject>
#include <QDebug>

class MyQObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString information MEMBER m_information NOTIFY informationChanged)
    Q_PROPERTY(int value READ setValue WRITE getValue NOTIFY valueChanged)
public:
    explicit MyQObject(QObject *parent = nullptr);

    int setValue() const;
    void getValue(int newValue);

signals:
    void newSignal(QString message);

    void informationChanged();

    void valueChanged();

public slots:
    void newSlot(QString message);
    void on_informationChanged();
    void on_valueChanged();

private:
    QString m_information;
    int m_value;
};

#endif // MYQOBJECT_H
