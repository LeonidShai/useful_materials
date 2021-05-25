#include "ConcreteMediator.h"
#include <QDebug>

ConcreteMediator::ConcreteMediator(MainWindow* mainwin, Component* component) :
    _mainwin(mainwin),
    _component(component)
{
    this->_mainwin->setMediator(this);
    this->_component->setMediator(this);
}

ConcreteMediator::~ConcreteMediator()
{

}

void ConcreteMediator::notify(BaseComponent *sender, QString event, QString msg) const
{
    if (event == "A") {
         this->_component->showMessage(msg);
    } else if (event == "Q") {
        this->_component->quit();
    } else {
        qDebug() << "not matching" << endl;
    }
}
