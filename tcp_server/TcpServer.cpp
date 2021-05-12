#include "TcpServer.h"

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
}

void TcpServer::clientDisconnected()
{
    _socket->close();
    _socket = nullptr;
}

void TcpServer::read()
{

}

void TcpServer::send()
{

}
