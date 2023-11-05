#include "Base.h"

#include <QTimer>

Base::Base(QGraphicsItem* parent) : QGraphicsPixmapItem(parent)
{
    //set the picture of the base
    setPixmap(QPixmap(":/images/images/base.png"));
}