#ifndef BASE_H
#define BASE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QLabel>


class Base: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Base(QGraphicsItem* parent = 0);
};

#endif // BASE_H
