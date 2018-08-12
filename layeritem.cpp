#include "layeritem.h"
#include <QtGui>
#include <QtCore>
#include <QTreeWidget>
#include <QGraphicsItem>
#include <QPaintEvent>


layerItem::layerItem()
{
    this->setFlag(ItemIsMovable);
    this->setFlag(ItemIsSelectable);
    isPressed = false;
    this->setAcceptHoverEvents(true);
    this->setAcceptDrops(true);

}

QRectF layerItem::boundingRect() const
{

    return QRectF(0,0, d.height,d.width);
}

void layerItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QRectF rec = boundingRect();
    QBrush brush(Qt::blue);
    QPen pen(Qt::black);
    pen.setWidth(2);
    painter->setPen(pen);
    QColor green30 = Qt::green;
    green30.setAlphaF(0.3);


    if(diff_value <= 4)
    {
        painter->drawRect(rec);
        brush.setColor(Qt::red);
        painter->fillRect(rec, brush);
        painter->drawText(rec, Qt::AlignLeft | Qt::AlignVCenter, n);
    }
    else if(diff_value <=7 && diff_value > 4)
    {
        painter->drawRect(rec);
        brush.setColor("orange");
        painter->fillRect(rec, brush);
        painter->drawText(rec, Qt::AlignLeft | Qt::AlignVCenter, n);
    }
    else if(diff_value <= 10 && diff_value > 7)
    {
        painter->drawRect(rec);
        brush.setColor(Qt::green);
        painter->fillRect(rec, brush);
        painter->drawText(rec, Qt::AlignLeft|Qt::AlignVCenter, n);
    }
}

void layerItem::setHeightWidth(int height, int width)
{
   d.height = height;
   d.width=width;
}

void layerItem::setName(QString name)
{
    n = name;
}

void layerItem::setDiffValue(int diff)
{
    diff_value = diff;
}

void layerItem::setIsObs(bool b)
{
    isObs = b;
}

void layerItem::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    dragStartPosition = QCursor::pos();
    QGraphicsItem::mousePressEvent(e);
}



