#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <qglobal.h>
#include <QGraphicsView>
#include <QObject>
#include <QGraphicsPixmapItem>

#include "client.h"
//#include "scene.h"

QT_FORWARD_DECLARE_CLASS(QObject);

//class scene;
//class client;

extern QGraphicsView *view;

class MyRect: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    int width, height;

    MyRect();
    MyRect(class Client *c);



public slots:
    void spawn();
    void NewPos(char *buff);
    void handleBullet(char *buff);
 //   void guiCreateNewPlayer();

    void keyPressEvent(QKeyEvent * event);


private:
    char buff[10];

signals:
   void guiSendPosition(char *buff);
   void guiSendBulletInfo(char *buff);
   void guiAddPlayerToScene(MyRect *rect);
};


#endif // MYRECT_H
