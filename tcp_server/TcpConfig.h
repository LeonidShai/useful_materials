#ifndef TCPCONFIG_H
#define TCPCONFIG_H

#include <QString>

class TcpConfig
{
public:
    TcpConfig();
    ~TcpConfig();

    void setListenAddresses(QString listenAddresses);
    QString listenAddresses();

    void setServerPort(int serverPort);
    int serverPort();

private:
    QString _listenAddresses;
    int     _serverPort;
};

#endif // TCPCONFIG_H
