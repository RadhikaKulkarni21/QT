#include "ellipseobj.h"

EllipseObj::EllipseObj() {

    connect(this, &EllipseObj::borderChanged, this, &EllipseObj::onPropertyChanged);
    connect(this, &EllipseObj::colorChanged, this, &EllipseObj::onPropertyChanged);
}

float EllipseObj::border() const
{
    return m_border;
}

void EllipseObj::setBorder(float newBorder)
{
    if (qFuzzyCompare(m_border, newBorder))
        return;
    m_border = newBorder;
    emit borderChanged();
}

void EllipseObj::paint(QPainter *painter)
{
    QPen pen(m_color, m_border);
    painter->setPen(pen);
    painter->setRenderHints(QPainter::Antialiasing, true);
    painter->drawEllipse(QRect(m_border / 2, m_border / 2, width() - m_border, height() - m_border));
}

void EllipseObj::setProperties(float newBorder, QColor newColor)
{
    setBorder(newBorder);

    if (m_color != newColor) {
        m_color = newColor;
        emit colorChanged();
    }
}

void EllipseObj::ellipseInfo()
{
    qInfo() << QString("Ellipse's color: %1 - Ellipse's border: %2")
    .arg(m_color.name())
        .arg(m_border);
}

void EllipseObj::onPropertyChanged()
{
    update();
}
