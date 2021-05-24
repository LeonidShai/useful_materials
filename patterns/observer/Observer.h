#ifndef OBSERVER_H
#define OBSERVER_H
#include <QString>

class Observer{
public:
  virtual ~Observer(){};
  virtual void update(const QString str) = 0;
};

#endif // OBSERVER_H
