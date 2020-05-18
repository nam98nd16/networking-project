#include "Enemy.h"
#include <QTimer>
#include <QGraphicsView>

#include "stdlib.h"

Enemy::Enemy(MyRect *rect): QObject(), QGraphicsRectItem()
{
    //set random postion

  //  Enemy *enemy = new Enemy();

    srand(time(NULL));

    int random_number = (rand() % 1200);
    setPos(random_number, 0);

    setRect(0, 0, 100, 100);

    //connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);

    this->player = rect;

    QObject::connect(this, &Enemy::collidePlayer, rect, &MyRect::decreaseHealth);


//    QTimer *new_timer = new QTimer();
//    QObject::connect(new_timer, SIGNAL(timeout()), this, SLOT(spawn()));

//    new_timer->start(500);

}

void Enemy::move()
{
    setPos(x(), y() + 5);
    if (pos(). y() + rect().height() < 0) {
        scene()->removeItem((this));
        delete(this);
    }
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i) {
//           scene()->removeItem(this);
//           delete this;
           if (typeid((*colliding_items[i])) == typeid(MyRect)) {
               emit collidePlayer();
//               scene()->removeItem(colliding_items[i]);
//               scene()->removeItem(this);
//               delete colliding_items[i];
//               delete this;
//               exit(EXIT_FAILURE);
           }
    }
}

void Enemy::spawn()
{
    Enemy *enemy = new Enemy(this->player);
    scene()->addItem(enemy);
}
