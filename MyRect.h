#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <qglobal.h>
#include <QGraphicsView>
#include <QObject>
#include <QGraphicsPixmapItem>

extern QGraphicsView *view;

class MyRect: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    int width, height;

    MyRect();

public slots:
    void spawn();
    void NewPos(char *buff);
    void handleBullet(char *buff);
    void keyPressEvent(QKeyEvent * event);


private:
    char buff[10];

signals:
   void guiSendPosition(char *buff);
   void guiSendBulletInfo(char *buff);
};


#endif // MYRECT_H
