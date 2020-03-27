#include "Bullet.h"
#include "Enemy.h"

#include <QList>
#include <QTimer>
#include <QGraphicsView>


Bullet::Bullet()
{
    setRect(0, 0, 10, 50);

    //connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    //if bullet collide enemy,delete both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    setPos(x(), y() - 10);
    if (pos(). y() + rect().height() < 0) {
        scene()->removeItem((this));
        delete(this);
    }
}
