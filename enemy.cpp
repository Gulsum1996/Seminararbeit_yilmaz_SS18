#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"
#include"zeichenfeld.h"


extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    int random_number = rand() % 600 + 170;
    setPos(random_number,0);


    setPixmap(QPixmap(":/new/prefix1/asteroid-icon.png").scaledToWidth(80).scaledToHeight(80));
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Enemy::move(){
    setPos(x(),y()+5);
    if (pos().y() > 600){

        game->health->decrease();
        if(game->health->getHealth() < 1){
            game->stop();
        }else{
            scene()->removeItem(this);
        }
        delete this;
    }

}



