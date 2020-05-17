#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include "client.h"
#include "MyRect.h"
#include "Enemy.h"

QT_FORWARD_DECLARE_CLASS(QObject);


class scene {
private:
   // MyRect *player;
public:
    QGraphicsScene *new_scene;
    MyRect *player;
    Client *play;
    Enemy *enemy;
    scene();
    void setUp();
    QGraphicsScene *getScene();
};

#endif // SCENE_H
