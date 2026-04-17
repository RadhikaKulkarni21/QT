#ifndef MYQOBJECT_META_H
#define MYQOBJECT_META_H

#include <QObject>
#include <QDebug>

class MyQObject_meta : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString myValue1 MEMBER m_myValue1 NOTIFY myValue1Changed)
    Q_PROPERTY(QString myValue2 MEMBER m_myValue2 NOTIFY myValue2Changed)
public:
    explicit MyQObject_meta(QObject *parent = nullptr);

    enum MyEnum {
        Value1,
        Value2,
        Value3
    }; Q_ENUM(MyEnum)

signals:
    void myValue1Changed();
    void myValue2Changed();

private:
    QString m_myValue1;
    QString m_myValue2;
};

#endif // MYQOBJECT_META_H
