#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QObject>
#include "Client.h"

#include "MyRect.h"
#include "Enemy.h"
#include "Health.h"

QT_FORWARD_DECLARE_CLASS(QObject);


class MyRect;
class Client;
class Enemy;

class scene : public QObject {
    Q_OBJECT

private:
   // MyRect *player;
public:
    QGraphicsScene *new_scene;
    MyRect *player;
    Client *client;
    Enemy *enemy;
    Health *health;
    scene();
    void setUp();
    QGraphicsScene *getScene();

public slots:
    void sceneAddPlayer(MyRect *rect);
};

#endif // SCENE_H
