#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
    _tcpClient = new TcpClient;
    _countConnect = 0;

    _ui->lineEdit_serverAddress->setText("localhost");
    _ui->lineEdit_serverPort->setText("2323");

    connect(_tcpClient, SIGNAL(signalConnected()), this, SLOT(connectionState()));
}

MainWindow::~MainWindow()
{
    delete _ui;
}

void MainWindow::connectionState()
{
    _countConnect++;
    if(_countConnect % 2 == 0){
        QString text = "disconnected from server " + _tcpConfig.serverAddresses();
        _ui->label_connectionState->setText(text);
    } else {
        QString text = "connected to server " + _tcpConfig.serverAddresses();
        _ui->label_connectionState->setText(text);
    }
}

void MainWindow::on_pushButton_connect_clicked()
{
    QString serverAddress = _ui->lineEdit_serverAddress->text();
    int serverPort = _ui->lineEdit_serverPort->text().toInt();
    _tcpConfig.setServerAddresses(serverAddress);
    _tcpConfig.setServerPort(serverPort);

    _tcpClient->connect2Server(_tcpConfig);
}

void MainWindow::on_pushButton_disconnect_clicked()
{

}

void MainWindow::on_pushButton_quit_clicked()
{
    this->close();
}
