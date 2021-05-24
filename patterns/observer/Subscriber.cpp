#include "Subscriber.h"
#include <QDebug>
#include <ui_Subscriber.h>

Subscriber::Subscriber(QWidget *parent):
    QWidget(parent),
    _ui(new Ui::Subscriber)
{
    _ui->setupUi(this);
}

Subscriber::~Subscriber()
{
    delete _ui;
}

void Subscriber::setSubject(Subject *subject)
{
    _subject = subject;
    _subject->setObserver(this);
}

void Subscriber::update(const QString str)
{
    _msg = str;
    if(_msg == "q"){
        quit();
    } else {
        printInfo();
    }
}

void Subscriber::printInfo() {
    qDebug() << _msg << Qt::endl;
    _ui->lineEdit->setText(_msg);
}

void Subscriber::quit()
{
    this->close();
}

void Subscriber::on_pushButton_clear_clicked()
{
    _ui->lineEdit->clear();
}
