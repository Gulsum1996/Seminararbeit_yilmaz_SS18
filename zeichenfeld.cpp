#include <QtGui>
#include <QMessageBox>
#include "zeichenFeld.h"
#include "Game.h"


zeichenFeld::zeichenFeld(QWidget *parent){

    setMouseTracking(false);
    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    lastX=100;
    lastY=100;
    increment=0;
    phase=0;
}
zeichenFeld::~zeichenFeld()
{
}
void zeichenFeld::serialize(QFile &file)
{

    QTextStream out(&file);

    out << "p " <<lastX;
}

void zeichenFeld::deserialize(QFile &file)
{ char c;

    QTextStream in(&file);
    while (in.status() == QTextStream::Ok)
    {
           in >> c;
       if (in.status() == QTextStream::ReadPastEnd) break;

       if (c!='p')
        {
       QMessageBox::warning(this, tr("Objektfehler"),
                                 tr("Folgender Objekttyp ist unbekannt: ") + c,QMessageBox::Ok);
            return; }

        in >> lastX;
        in >> c; // Leerstellen werden vom '>>' Operator 'konmsumiert';
        // Zeilenenden nicht.
    }

    update();
}
