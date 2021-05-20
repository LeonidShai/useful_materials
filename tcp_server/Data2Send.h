#ifndef DATA2SEND_H
#define DATA2SEND_H

#include <QString>

class Data2Send
{
public:
    explicit Data2Send();
    ~Data2Send();

    QString message() const;
    void setMessage(const QString &message);

    int num() const;
    void setNum(int &num);

private:
    QString _message;
    int     _num;
};

#endif // DATA2SEND_H
