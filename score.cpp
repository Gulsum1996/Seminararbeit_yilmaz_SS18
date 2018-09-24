#include "Score.h"
#include <QFont>
#include "Game.h"
#include"zeichenfeld.h"

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){


    //Punkte
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore(){
    return score;
}
