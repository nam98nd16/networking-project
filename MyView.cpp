#include "MyView.h"
#include "MyRect.h"
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

MyView::MyView(scene *scene)
{
    this->new_view = new QGraphicsView(scene->getScene());
    this->new_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->new_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view
    this->new_view->show();
    this->new_view->setFixedSize(1280, 720);
}

int MyView::getWidthPlayer(scene *scene)
{
   return scene->player->rect().width();
}

int MyView::getHeightPlayer(scene *scene)
{
   return scene->player->rect().height();
}

int MyView::getWidthView()
{
    return this->new_view->width();
}

int MyView::getHeightView()
{
    return this->new_view->height();
}
