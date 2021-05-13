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

    void send(QString msg);

private:
    QTcpSocket* _socket;
    QByteArray _buffer;
    bool _connected;

private slots:
    void slotConnected();
    void read();

signals:
    void signalConnected();
    void readSignal(QByteArray buffer);
};

#endif // TCPCLIENT_H
