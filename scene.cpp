#include "Client.h"
#include "scene.h"
#include "MyRect.h"
#include "Enemy.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include <QTimer>

scene::scene()
{
    this->new_scene = new QGraphicsScene();
 //   this->player = new MyRect();


//    this->enemy = new Enemy();
    this->new_scene->setSceneRect(0, 0, 1280, 720);

    Client *new_client = new Client(this);
    this->client = new_client;

    this->client->createNewClient(this);

//    this->health = new Health();
//    this->health->setPos(this->health->x(), this->health->y()+25);
//    this->new_scene->addItem(this->health);

    this->enemy = new Enemy(this->player);

    QTimer *new_timer = new QTimer();
    connect(new_timer, &QTimer::timeout, this->enemy, &Enemy::spawn);

    new_timer->start(800);
    this->new_scene->addItem(this->enemy);
}

void scene::sceneAddPlayer(MyRect *rect)
{
    this->player = rect;
    this->new_scene->addItem(this->player);

    this->health = rect->health;
    this->health->setPos(health->x(),health->y()+25);
    this->new_scene->addItem(health);

}

QGraphicsScene *scene::getScene()
{
//    MyRect *player = new MyRect();
//    this->new_scene->setSceneRect(0, 0, 800, 600);

//    // add the item to the scene
//    this->new_scene->addItem(player);
    return this->new_scene;
}
