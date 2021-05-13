#include "TcpClient.h"
#include <QDebug>

TcpClient::TcpClient(QObject* parent) : QObject(parent)
{
    _socket = new QTcpSocket(this);
}

TcpClient::~TcpClient()
{

}

void TcpClient::connect2Server(TcpConfig tcpConfig)
{
    _socket->connectToHost(tcpConfig.serverAddresses(), tcpConfig.serverPort());
    connect(_socket, SIGNAL(connected()), this, SLOT(slotConnected()));
    connect(_socket, SIGNAL(readyRead()), this, SLOT(read()));
}

void TcpClient::disconnect2Sever()
{

}

void TcpClient::slotConnected()
{
    emit signalConnected();
}

void TcpClient::read()
{
    qDebug() << "read" << Qt::endl;
    _buffer = _socket->readAll();
    qDebug() << _buffer.data() << Qt::endl;
    emit readSignal(_buffer);
}

void TcpClient::send(QString msg)
{
    qDebug() << "send" << Qt::endl;
    QByteArray buffer = msg.toUtf8();
    _socket->write(buffer);
}
