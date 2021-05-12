#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QtNetwork>
#include <TcpConfig.h>

class TcpServer : public QObject
{
public:
    TcpServer(QObject* parent = nullptr);
    ~TcpServer();

    bool runServer(TcpConfig tcpConfig);
    bool stopServer();

    bool isConnected();

private:
    QTcpServer* _tcpServer;
    QTcpSocket* _socket{nullptr};

    bool _serverState;
    bool _connectionState;

private slots:
    void newClientConnected();
    void clientDisconnected();
    void read();
    void send();

signals:
    void newConnection();
};

#endif // TCPSERVER_H
