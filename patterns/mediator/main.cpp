#include <MainWindow.h>
#include <ConcreteMediator.h>
#include <Component.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainwin;
    mainwin.show();
    Component component;
    component.show();
    ConcreteMediator mediator(&mainwin, &component);
    return a.exec();
}
