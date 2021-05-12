#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
    _tcpServer = new TcpServer;

    _ui->lineEdit_listenAddress->setText("localhost");
    _ui->lineEdit_port->setText("2323");
}

MainWindow::~MainWindow()
{
    delete _tcpServer;
    delete _ui;
}

void MainWindow::on_pushButton_run_clicked()
{
    QString listenAddresses = _ui->lineEdit_listenAddress->text();
    int port = _ui->lineEdit_port->text().toInt();
    _tcpConfig.setListenAddresses(listenAddresses);
    _tcpConfig.setServerPort(port);

    bool serverState = _tcpServer->runServer(_tcpConfig);
    if (serverState){
        QString text = "run server at " + listenAddresses + " and port " + QString::number(port);
        _ui->label_serverState->setText(text);
    } else {
        QString text = "server failed at " + listenAddresses + " and port " + QString::number(port);
        _ui->label_serverState->setText(text);
    }
}

void MainWindow::on_pushButton_stop_clicked()
{
    bool serverState = _tcpServer->stopServer();
    if(!serverState){
        _ui->label_serverState->setText("server stopped");
    }
}

void MainWindow::on_pushButton_quit_clicked()
{
    this->close();
}
