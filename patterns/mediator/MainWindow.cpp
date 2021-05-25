#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete _ui;
}


void MainWindow::on_pushButton_read_clicked()
{
    _msg = _ui->lineEdit->text();
    this->_mediator->notify(this, "A", _msg);
    _ui->lineEdit->clear();
}

void MainWindow::on_pushButton_clear_clicked()
{
    _ui->lineEdit->clear();
}

void MainWindow::on_pushButton_quit_clicked()
{
    _msg = "q";
    this->close();
    this->_mediator->notify(this, "Q", _msg);
}
