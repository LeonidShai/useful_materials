#ifndef COMPONENT_H
#define COMPONENT_H

#include <QWidget>
#include <Mediator.h>
#include <QStringList>

namespace Ui {
class Component;
}

class Component : public QWidget, public BaseComponent
{
    Q_OBJECT

public:
    explicit Component(QWidget *parent = nullptr);
    ~Component();

    void showMessage(QString msg);
    void quit();

private:
    Ui::Component* _ui;

private slots:
    void on_pushButton_clear_clicked();
};

#endif // COMPONENT_H
