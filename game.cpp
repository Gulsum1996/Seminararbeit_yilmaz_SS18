#include "Game.h"
#include"zeichenfeld.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
// Qt5 add:
#include <QPushButton>
#include <QGridLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QtGui>
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent){

    //Buttons definieren

    QPushButton *start = new QPushButton(tr("Start here"));
    start->setFont(QFont("Times", 15, QFont::Bold));
    connect(start, SIGNAL(clicked()), this, SLOT(start()));

    QPushButton *quit = new QPushButton(tr("End"));
    quit->setFont(QFont("Times", 15, QFont::Bold));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    QPushButton *stop = new QPushButton(tr("Stop"));
    stop->setFont(QFont("Times", 15, QFont::Bold));
    connect(stop, SIGNAL(clicked()), this, SLOT(stop()));

    QPushButton *laden = new QPushButton(tr("Load"));
    laden->setFont(QFont("Times", 15, QFont::Bold));
    connect(laden, SIGNAL(clicked()), this, SLOT(loadFile()));

    QPushButton *speichern = new QPushButton(tr("Save"));
    speichern->setFont(QFont("Times", 15, QFont::Bold));
    connect(speichern, SIGNAL(clicked()), this, SLOT(saveFile()));

    meinZeichenFeld = new zeichenFeld;

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(quit, 0, 0);
    gridLayout->addWidget(start, 1, 0);
    gridLayout->addWidget(stop, 2, 0);
    gridLayout->addWidget(speichern, 3, 0);
    gridLayout->addWidget(laden, 4, 0);
    gridLayout->addWidget(meinZeichenFeld, 0, 1, 3, 1);
    gridLayout->setColumnStretch(1, 10);
    setLayout(gridLayout);


    //Spielfeld
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    scene->addPixmap(QPixmap(":/new/prefix1/bck.png"));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //Geist
    player = new Player();
    player->setPixmap(QPixmap(":/new/prefix1/Geist.png").scaledToWidth(100).scaledToHeight(100));
    player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    //leben & Punkte
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);
    timer = new QTimer();
      QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
     show();
}


void Game::start(void)
{
       timer->start(2000);
}

void Game::spawn(){

    //Asteroid
    Enemy * enemy = new Enemy();
    scene->addItem(enemy);
}

void Game::stop(void)
{
    timer->stop();
  timer->disconnect();

}
void Game::saveFile(void)
{
    QFileDialog dialog(this);
    QString fileName;
    QFile file;
    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getSaveFileName(this,
                                      tr("Speichern als"), ".", tr("Zeichnungen (*.myz)"));

    if (fileName.isNull()==false)
    {
        file.setFileName(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Dateifehler"),
                                 tr("Folgende Datei kann nicht verwendet werden: ") + fileName,QMessageBox::Ok);
        }

        meinZeichenFeld->serialize(file);
        file.close();
        return;
    }
}

void Game::loadFile(void)
{
    QFileDialog dialog(this);
    QString fileName;
    QFile file;

    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getOpenFileName(this,
                                      tr("Speichern als"), ".", tr("Zeichnungen (*.myz)"));

    if (!fileName.isNull())
    {
        file.setFileName(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Dateifehler"),
                                 tr("Folgende Datei kann nicht geÃ¶ffnet werden: ") + fileName,QMessageBox::Ok);
        }

        meinZeichenFeld->deserialize(file);
        file.close();
        return;
    }
}
