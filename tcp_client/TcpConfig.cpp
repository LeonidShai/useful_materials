#include "TcpConfig.h"

TcpConfig::TcpConfig()
{

}

TcpConfig::~TcpConfig()
{

}

void TcpConfig::setServerAddresses(QString serverAddress)
{
    _serverAddresses = serverAddress;
}

QString TcpConfig::serverAddresses()
{
    return _serverAddresses;
}

void TcpConfig::setServerPort(int serverPort)
{
    _serverPort = serverPort;
}

int TcpConfig::serverPort()
{
    return _serverPort;
}
