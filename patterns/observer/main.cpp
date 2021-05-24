#include "MainWindow.h"

#include <QApplication>
#include <Subscriber.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Subscriber* subscriber = new Subscriber;
    subscriber->setSubject(&w);
    w.show();
    subscriber->show();
    return a.exec();
}
