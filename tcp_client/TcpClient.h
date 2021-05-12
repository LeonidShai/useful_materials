#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <TcpConfig.h>
#include <QtNetwork>

class TcpClient : public QObject
{
    Q_OBJECT
public:
    TcpClient(QObject* parent=nullptr);
    ~TcpClient();

    void connect2Server(TcpConfig tcpConfig);
    void disconnect2Sever();

private:
    QTcpSocket* _socket;

private slots:
    void slotConnected();
    void read();
    void send();

signals:
    void signalConnected();
};

#endif // TCPCLIENT_H
