#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Subject.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Subject
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* _ui;
    Observer*       _observer;
    QString         _msg;

    void setObserver(Observer* observer) override;
    void notify() override;

private slots:
    void on_pushButton_read_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_quit_clicked();
};
#endif // MAINWINDOW_H
