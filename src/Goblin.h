#ifndef GOBLIN_H
#define GOBLIN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QList>
#include <QPointF>
#include <QLabel>
#include <QMediaPlayer>

#include "EnemyPoints.h"
#include "Enemy.h"

class Goblin: public QObject, public Enemy
{
            Q_OBJECT
public:
    Goblin(QGraphicsItem* parent = 0);
    ~Goblin();

public slots:
   void move();
   void closing();
};

#endif // GOBLIN_H
