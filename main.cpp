#include <QApplication>
#include "Enemy.h"
#include "MyView.h"
#include "MyRect.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QDebug>

/*
Tutorial Topics:
-QGraphicsScene's sceneRect
-QGraphicView's sceneRect
-QGraphicView coordinates vs QGraphicScrene coordinates vs QGraphicItem coordinates
*/

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    scene * Ascene = new scene();

    MyView * Aview = new MyView(Ascene);

    Ascene->player->setPos((Aview->getWidthView() - Aview->getWidthPlayer(Ascene)) / 2,
                           Aview->getHeightView() - Aview->getHeightPlayer((Ascene)));

    QTimer *new_timer = new QTimer();
    QObject::connect(new_timer, SIGNAL(timeout()), Ascene->player, SLOT(spawn()));

    new_timer->start(1500);


    return a.exec();




}
