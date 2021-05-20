#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
    _tcpServer = new TcpServer;
    _taskExecutor = new TaskExecutor;

    _thread = new QThread(this);
    _taskExecutor->moveToThread(_thread);
    _thread->start();

    _ui->lineEdit_listenAddress->setText("localhost");
    _ui->lineEdit_port->setText("2323");

    connect(_tcpServer, SIGNAL(newConnection()), this, SLOT(connectionChanged()));
    connect(_tcpServer, &TcpServer::readSignal, this, &MainWindow::showMessage);

    connect(_tcpServer, &TcpServer::startTask, _taskExecutor, &TaskExecutor::startTask);
    connect(_tcpServer, &TcpServer::stopTask, _taskExecutor, &TaskExecutor::stopTask);

    connect(_taskExecutor, &TaskExecutor::taskStarted, _tcpServer, &TcpServer::send);
    connect(_taskExecutor, &TaskExecutor::taskStopped, _tcpServer, &TcpServer::send);
}

MainWindow::~MainWindow()
{
    _thread->terminate();
    _thread->wait();
    delete _thread;
    delete _taskExecutor;
    delete _tcpServer;
    delete _ui;
}

void MainWindow::connectionChanged()
{
    if(_tcpServer->isConnected()){
        _ui->label_connectionState->setText("new client connected");
    } else {
        _ui->label_connectionState->setText("client disconnected");
    }
}

void MainWindow::showMessage(QByteArray buffer)
{
    QString msg = buffer.data();
    _ui->label_msg->setText(msg);
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

void MainWindow::on_pushButton_send_clicked()
{
    QString msg = _ui->lineEdit_msg->text();
    _ui->lineEdit_msg->clear();
    _tcpServer->send(msg);
}

void MainWindow::on_pushButton_clear_clicked()
{
    _ui->label_msg->clear();
}
