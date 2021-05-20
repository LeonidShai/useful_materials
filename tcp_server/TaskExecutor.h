#ifndef TASKEXECUTOR_H
#define TASKEXECUTOR_H

#include <QObject>
#include <QTimer>

#include <Data2Send.h>

Q_DECLARE_METATYPE(Data2Send)

class TaskExecutor : public QObject
{
    Q_OBJECT
public:
    explicit TaskExecutor(QObject *parent = nullptr);
    ~TaskExecutor();

public slots:
    void startTask();
    void stopTask();

private:
    bool        _task;
    Data2Send   _data2Send;

signals:
    void taskStarted(QString msg);
    void taskStopped(QString msg);
    void sendData(Data2Send data2Send);
};

#endif // TASKEXECUTOR_H
