#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Mediator.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public BaseComponent
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_read_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_quit_clicked();

private:
    Ui::MainWindow* _ui;
    QString _msg;
};
#endif // MAINWINDOW_H
