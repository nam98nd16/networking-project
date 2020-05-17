#include "client.h"
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
    this->player = new MyRect();
 //   this->play = new Client();
   // play->createNewClient();
    this->enemy = new Enemy();
    this->new_scene->setSceneRect(0, 0, 800, 600);

    this->new_scene->addItem(this->player);

//    this->enemy = new Enemy();
//    QTimer *new_timer = new QTimer();
//    QObject::connect(new_timer, SIGNAL(timeout()), enemy, SLOT(spawn()));

//    new_timer->start(500);
}



QGraphicsScene *scene::getScene()
{
//    MyRect *player = new MyRect();
//    this->new_scene->setSceneRect(0, 0, 800, 600);

//    // add the item to the scene
//    this->new_scene->addItem(player);
    return this->new_scene;
}
