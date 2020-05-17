#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QObject>
#include "client.h"

#include "MyRect.h"
#include "Enemy.h"

QT_FORWARD_DECLARE_CLASS(QObject);


class MyRect;
class Client;
\
class scene : public QObject {
    Q_OBJECT

private:
   // MyRect *player;
public:
    QGraphicsScene *new_scene;
    MyRect *player;
    Client *client;
    Enemy *enemy;
    scene();
    void setUp();
    QGraphicsScene *getScene();

public slots:
    void sceneAddPlayer(MyRect *rect);
};

#endif // SCENE_H
