#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H

#include <Mediator.h>
#include <MainWindow.h>
#include <Component.h>

class ConcreteMediator : public Mediator
{
public:
    ConcreteMediator(MainWindow *mainwin, Component *component);
    ~ConcreteMediator();

    void notify(BaseComponent *sender, QString event, QString msg) const override;

private:
    MainWindow* _mainwin;
    Component*  _component;
    QString     _msg;
};

#endif // CONCRETEMEDIATOR_H
