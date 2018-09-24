#ifndef GAME_H
#define GAME_H
#include "zeichenFeld.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Enemy.h"
#include "Health.h"

class Game: public QGraphicsView{
     Q_OBJECT
public:
    Game(QWidget * parent=0);
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    QTimer * timer;
private:
    zeichenFeld *meinZeichenFeld;
public slots:
    void stop(void);
    void spawn();
private slots:
    void start(void);
    void saveFile(void);
    void loadFile(void);
};

#endif






