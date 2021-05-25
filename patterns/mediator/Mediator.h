#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QString>

class BaseComponent;
class Mediator
{
public:
    virtual void notify(BaseComponent *sender, QString event, QString msg) const = 0;
};


class BaseComponent {
public:
    BaseComponent(Mediator *mediator = nullptr);
    void setMediator(Mediator *mediator);

protected:
    Mediator* _mediator;
};

#endif // MEDIATOR_H
