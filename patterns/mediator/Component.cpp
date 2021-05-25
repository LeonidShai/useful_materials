#include "Component.h"
#include "ui_Component.h"

Component::Component(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::Component)
{
    _ui->setupUi(this);
}

Component::~Component()
{
    delete _ui;
}

void Component::showMessage(QString msg)
{
    _ui->listWidget->addItem(msg);
}

void Component::on_pushButton_clear_clicked()
{
    _ui->listWidget->clear();
}

void Component::quit()
{
    this->close();
}
