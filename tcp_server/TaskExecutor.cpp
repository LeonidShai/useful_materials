#include "TaskExecutor.h"
#include <QDebug>
#include <QEventLoop>

TaskExecutor::TaskExecutor(QObject *parent) :
    QObject(parent),
    _task(false)
{
    qRegisterMetaType<Data2Send>("Data2Send");
}

TaskExecutor::~TaskExecutor()
{

}

void TaskExecutor::startTask()
{
    qDebug() << "TaskExecutor: start task!" << Qt::endl;
    _task = true;
    QString str("task started!");
    emit taskStarted(str);
    _data2Send.setMessage("task running, step: ");

    int count = 1;
    while(_task){
        qDebug() << "task running, step: " << count << Qt::endl;
        _data2Send.setNum(count);

        QEventLoop loop;
        QTimer::singleShot(2000, &loop, &QEventLoop::quit);
        loop.exec();
        emit sendData(_data2Send);
        count++;
    }
}

void TaskExecutor::stopTask()
{
    qDebug() << "TaskExecutor: stop task!" << Qt::endl;
    _task = false;
    QString str("task stopped!");
    emit taskStopped(str);
}
