#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QtNetwork>
#include <TcpConfig.h>

class TcpServer : public QObject
{
    Q_OBJECT
public:
    TcpServer(QObject* parent = nullptr);
    ~TcpServer();

    bool runServer(TcpConfig tcpConfig);
    bool stopServer();

    bool isConnected();
    void send(QString msg);

private:
    QTcpServer* _tcpServer;
    QTcpSocket* _socket{nullptr};

    bool _serverState;
    bool _connectionState;

    QByteArray _buffer;

private slots:
    void newClientConnected();
    void clientDisconnected();
    void read();

signals:
    void newConnection();
    void readSignal(QByteArray buffer);
    void startTask();
    void stopTask();
};

#endif // TCPSERVER_H
