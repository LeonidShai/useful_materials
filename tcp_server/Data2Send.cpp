#include "Data2Send.h"

Data2Send::Data2Send()
{

}

Data2Send::~Data2Send()
{

}

QString Data2Send::message() const
{
    return _message;
}

void Data2Send::setMessage(const QString &message)
{
    _message = message;
}

int Data2Send::num() const
{
    return _num;
}

void Data2Send::setNum(int &num)
{
    _num = num;
}
