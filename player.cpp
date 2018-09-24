#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include"zeichenfeld.h"
#include "Game.h"



Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

}

void Player::keyPressEvent(QKeyEvent *event){


    //Bewegung vom Geist

    if (event->key() == Qt::Key_Left){
        if (pos().x() > 160)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }


    //Leertaste zum abfeuern der Laser
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+40,y()-50);
        scene()->addItem(bullet);
    }
}


