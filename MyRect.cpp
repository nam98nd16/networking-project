#include "Bullet.h"
#include "MyRect.h"
#include "Enemy.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QList>

MyRect::MyRect()
{
    this->setRect(0, 0, 100, 100); // change the rect from 0x0 (default) to 100x100 pixels
   // setPixmap(QPixmap(":/image/airplane.jpg"));
//   QPixmap pix(":/images/airplane.png");
//   this->width = pix.width();
//   this->height = pix.height();
//setPixmap(QPixmap(":/images/airplane.png"));
    // make rect focusable
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
}

void MyRect::keyPressEvent(QKeyEvent *event)
{
   if (event->key() == Qt::Key_Left) {
       if (pos().x() > 0){
        setPos(x() - 10, y());
       }
   }

   if (event->key() == Qt::Key_Right) {
       if (pos().x() < 800 - this->rect().width()){
        setPos(x() + 10, y());
       }
   }

   if (event->key() == Qt::Key_Up) {
       if (pos().y() > 0){
           setPos(x(), y() - 10);
       }
   }

   if (event->key() == Qt::Key_Down) {
       if (pos().y() < 600 - this->rect().height()){
        setPos(x(), y() + 10);
       }
   }

   if (event->key() == Qt::Key_Space) {
       Bullet *bullet = new Bullet();
       bullet->setPos(x(), y());
       scene()->addItem(bullet);
     //  qDebug() << "Bullet appeared";
   }
}

void MyRect::spawn()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}