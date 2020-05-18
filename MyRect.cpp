#include "Bullet.h"
#include "Client.h"
#include "Enemy.h"
#include "Health.h"
#include "MyRect.h"

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QList>
#include <QFont>

MyRect::MyRect()
{

}

MyRect::MyRect(Client *c)
{
    this->setRect(0, 0, 100, 100); // change the rect from 0x0 (default) to 100x100 pixels
 //   setPixmap(QPixmap(":/image/airplane.jpg"));
//   QPixmap pix(":/images/airplane.png");
//   this->width = pix.width();
//   this->height = pix.height();
//setPixmap(QPixmap(":/images/airplane.png"));

    // make rect focusable
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();

//    Client *c = new Client(this);
//    c->createNewClient();

    this->health = new Health();
    QObject::connect(this, &MyRect::guiSendPosition, c, &Client::sendNewPostionToServer);
    QObject::connect(this, &MyRect::guiSendBulletInfo, c, &Client::sendBulletSignalToserver);

   // QObject::connect(this, &MyRect::guiSendPlayerDeathInfo, c, &Client::sendDeathPlayerInfoToServer);

}

//void MyRect::guiCreateNewPlayer()
//{
//    emit guiAddPlayerToScene(this);
//}


void MyRect::keyPressEvent(QKeyEvent *event)
{
   char buff[60];

   if (event->key() == Qt::Key_Left) {
       if (pos().x() > 0){
        strcpy(buff, "LEFT");
        emit guiSendPosition(buff);
        bzero(buff, sizeof(buff));
       }
   }

   if (event->key() == Qt::Key_Right) {
       if (pos().x() < 1280 - this->rect().width()){
        strcpy(buff, "RIGHT");
        emit guiSendPosition(buff);
        bzero(buff, sizeof(buff));
       }
   }

   if (event->key() == Qt::Key_Up) {
       if (pos().y() > 0){
           strcpy(buff, "UP");
           emit guiSendPosition(buff);
           bzero(buff, sizeof(buff));
       }
   }

   if (event->key() == Qt::Key_Down) {
       if (pos().y() < 720 - this->rect().height()){
        strcpy(buff, "DOWN");
        emit guiSendPosition(buff);
        bzero(buff, sizeof(buff));
       }
   }

   if (event->key() == Qt::Key_Space) {
       strcpy(buff, "BULLET");
       emit guiSendBulletInfo(buff);
       bzero(buff, sizeof(buff));

//       Bullet *bullet = new Bullet();
//       bullet->setPos(x(), y());
//       scene()->addItem(bullet);
   }

}

void MyRect::NewPos(char *buff)
{
 //   qDebug() << buff;
    if (strcmp(buff, "Client n.0:LEFT") == 0) {
        setPos(x() - 10, y());
    }

    if (strcmp(buff, "Client n.0:RIGHT") == 0) {
        setPos(x() + 10, y());
    }

    if (strcmp(buff, "Client n.0:UP") == 0) {
        setPos(x(), y() - 10);
    }

    if (strcmp(buff, "Client n.0:DOWN") == 0) {
        setPos(x(), y() + 10);
    }
}

void MyRect::handleBullet(char *buff)
{
    qDebug() << buff;
    if (strcmp(buff, "Client n.0:BULLET") == 0) {
        Bullet *bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }
}

int MyRect::decreaseHealth()
{
   this->health->decrease();
//   qDebug() << this->health->getHealth();
//   if (this->health->getHealth() == 0) {
//       char buff[60];
//       strcpy(buff, "DEATH");
//  //     emit guiSendPlayerDeathInfo(buff);
//     //  bzero(buff, sizeof(buff));
//       return 1;
//   }
   return 0;
}



//void MyRect::spawn()
//{
//    Enemy *enemy = new Enemy();
//    scene()->addItem(enemy);
//}


