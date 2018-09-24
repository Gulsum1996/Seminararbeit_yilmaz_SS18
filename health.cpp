#include "Health.h"
#include <QFont>
#include "Game.h"
#include"zeichenfeld.h"



//Leben
Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth(){
    return health;
}
