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
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
};


#endif // MYRECT_H
