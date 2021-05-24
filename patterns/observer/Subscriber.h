#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <Subject.h>

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Subscriber; }
QT_END_NAMESPACE

class Subscriber : public QWidget, public Observer
{
    Q_OBJECT
public:
    Subscriber(QWidget *parent = nullptr);
    ~Subscriber();

    void setSubject(Subject* subject);

private:
    Ui::Subscriber* _ui;
    Subject*    _subject;
    QString     _msg;

    void update(const QString str) override;
    void printInfo();
    void quit();

private slots:
    void on_pushButton_clear_clicked();
};

#endif // SUBSCRIBER_H
