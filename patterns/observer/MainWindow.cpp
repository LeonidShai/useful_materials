#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete _ui;
}

void MainWindow::setObserver(Observer *observer)
{
    _observer = observer;
}

void MainWindow::notify()
{
    _observer->update(_msg);
}

void MainWindow::on_pushButton_read_clicked()
{
    _msg = _ui->lineEdit->text();
    notify();
    _ui->lineEdit->clear();
}

void MainWindow::on_pushButton_clear_clicked()
{
    _ui->lineEdit->clear();
}

void MainWindow::on_pushButton_quit_clicked()
{
    _msg = "q";
    notify();
    this->close();
}
