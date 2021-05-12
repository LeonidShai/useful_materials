#ifndef TCPCONFIG_H
#define TCPCONFIG_H

#include <QString>

class TcpConfig
{
public:
    TcpConfig();
    ~TcpConfig();

    void setServerAddresses(QString serverAddresses);
    QString serverAddresses();

    void setServerPort(int serverPort);
    int serverPort();

private:
    QString _serverAddresses;
    int     _serverPort;
};

#endif // TCPCONFIG_H
