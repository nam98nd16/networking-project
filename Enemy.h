#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>

class Enemy : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Enemy();

public slots:
    void move();
    void spawn();
};

#endif // ENEMY_H
