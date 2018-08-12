#ifndef LAYERITEM_H
#define LAYERITEM_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QtCore>

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTreeWidget>


struct dimensions {
    int height;
    int width;
};

class layerItem : public QGraphicsItem
{

private:
    dimensions d;
    QString n;
    int diff_value = 0;
    bool isObs = false;
    bool isPressed;

    QPointF dragStartPosition;
public:
    layerItem();

    QRectF boundingRect() const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setHeightWidth(int height, int width);

    void setName(QString name);

    void setDiffValue(int diff);

    void setIsObs(bool b);

    void mousePressEvent(QGraphicsSceneMouseEvent* e);



};

#endif // LAYERITEM_H
