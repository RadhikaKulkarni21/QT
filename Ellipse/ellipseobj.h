#ifndef ELLIPSEOBJ_H
#define ELLIPSEOBJ_H

#include <QQmlEngine>
#include <QQuickPaintedItem>
#include <QPainter>

class EllipseObj : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(float border READ border WRITE setBorder NOTIFY borderChanged FINAL)
    Q_PROPERTY(QColor color MEMBER m_color NOTIFY colorChanged FINAL)

public:
    EllipseObj();
    float border() const;
    void setBorder(float newBorder);
    void paint(QPainter *painter);
    Q_INVOKABLE void setProperties(float newBorder, QColor newColor);

signals:
    void borderChanged();
    void colorChanged();

public slots:
    void ellipseInfo();
    void onPropertyChanged();

private:
    float m_border;
    QColor m_color;

};

#endif // ELLIPSEOBJ_H
