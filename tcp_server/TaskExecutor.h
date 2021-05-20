#ifndef TASKEXECUTOR_H
#define TASKEXECUTOR_H

#include <QObject>
#include <QTimer>

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
    bool _task;

signals:
    void taskStarted(QString msg);
    void taskStopped(QString msg);
};

#endif // TASKEXECUTOR_H
