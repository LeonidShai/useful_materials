#include "TcpServer.h"
#include <QDebug>

TcpServer::TcpServer(QObject* parent) : QObject(parent)
{

}

TcpServer::~TcpServer()
{
    _tcpServer->close();
    delete _tcpServer;
}

bool TcpServer::runServer(TcpConfig tcpConfig)
{
    _tcpServer = new QTcpServer(this);
    if(!_tcpServer->listen(QHostAddress(tcpConfig.listenAddresses()), tcpConfig.serverPort())){
        _serverState = false;
    } else {
        _serverState = true;
        connect(_tcpServer, SIGNAL(newConnection()), this, SLOT(newClientConnected()));
    }
    return _serverState;
}

bool TcpServer::stopServer()
{
    _serverState = false;
    _tcpServer->close();
    delete _tcpServer;
    return _serverState;
}

bool TcpServer::isConnected()
{
    return _connectionState;
}

void TcpServer::newClientConnected()
{
    _connectionState = true;
    _socket = _tcpServer->nextPendingConnection();
    connect(_socket, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
    connect(_socket, SIGNAL(readyRead()), this, SLOT(read()));

    emit newConnection();
}

void TcpServer::clientDisconnected()
{
    _socket->close();
    _socket = nullptr;
    _connectionState = false;

    emit newConnection();
}

void TcpServer::read()
{
    _buffer = _socket->readAll();
    qDebug() << _buffer.data() << Qt::endl;
    emit readSignal(_buffer);

    QString str = _buffer.data();
    if(str == "start"){
        qDebug() << "TcpServer: start task!" << Qt::endl;
        emit startTask();
    } else if(str == "stop"){
        qDebug() << "TcpServer: stop task!" << Qt::endl;
        emit stopTask();
    }
}

void TcpServer::send(QString msg)
{
    if(_connectionState){
        QByteArray buffer = msg.toUtf8();
        _socket->write(buffer);
    }
}

void TcpServer::sendData(Data2Send data2Send)
{
    QString msg = data2Send.message() + QString::number(data2Send.num());
    qDebug() << "TcpServer: sendData - " << msg << Qt::endl;
    if(_connectionState){
        QByteArray buffer = msg.toUtf8();
        _socket->write(buffer);
    }
}
