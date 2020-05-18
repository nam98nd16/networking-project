#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>

#include "MyRect.h"

class MyRect;

class Enemy : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Enemy(MyRect *rect);
    MyRect *player;

public slots:
    void move();
    void spawn();

signals:
    void collidePlayer();

};

#endif // ENEMY_H
