#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include "scene.h"

class MyView{
private:

public:
    QGraphicsView *new_view;
    static int width;
    MyView(scene *scene);

    int getWidthPlayer(scene *scene);
    int getHeightPlayer(scene *scene);
    int getWidthView();
    int getHeightView();
};

#endif // VIEW_H

