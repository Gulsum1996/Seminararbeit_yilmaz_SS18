#ifndef ZEICHENFELD
#define ZEICHENFELD
#include <vector>
using namespace std;
#include <QWidget>
#include <QTimer>
#include <QFile>

class zeichenFeld : public QWidget
{
public:
    zeichenFeld(QWidget *parent = 0);
    ~zeichenFeld();
    void start(void) { timer->start(10); increment=1; };
    void stop(void) { timer->stop(); increment=0; };
    void serialize(QFile &file);
    void deserialize(QFile &file);

private:
    QTimer *timer;
    int lastX;
    int lastY;
    int increment;
    int phase;

};


#endif

