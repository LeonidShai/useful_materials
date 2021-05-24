#ifndef SUBJECT_H
#define SUBJECT_H
#include <Observer.h>

class Subject {
 public:
  virtual ~Subject(){};
  virtual void setObserver(Observer *observer) = 0;
  virtual void notify() = 0;
};

#endif // SUBJECT_H
