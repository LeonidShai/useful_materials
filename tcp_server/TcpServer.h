#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QtNetwork>

class TcpServer
{
public:
    TcpServer();
    ~TcpServer();

    void runServer();
    void stopServer();

    bool isConnected();

private:
    QTcpServer* _tcpServer;
    QTcpSocket* _socket;

    void read();
    void send();

    bool _serverState;
    bool _connectionState;
};

#endif // TCPSERVER_H
