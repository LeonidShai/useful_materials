#include "TcpConfig.h"

TcpConfig::TcpConfig()
{

}

TcpConfig::~TcpConfig()
{

}

void TcpConfig::setListenAddresses(QString listenAddresses)
{
    _listenAddresses = listenAddresses;
}

QString TcpConfig::listenAddresses()
{
    return _listenAddresses;
}

void TcpConfig::setServerPort(int serverPort)
{
    _serverPort = serverPort;
}

int TcpConfig::serverPort()
{
    return _serverPort;
}
