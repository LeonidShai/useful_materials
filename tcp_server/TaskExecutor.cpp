#include "TaskExecutor.h"
#include <QDebug>
#include <QEventLoop>

TaskExecutor::TaskExecutor(QObject *parent) :
    QObject(parent),
    _task(false)
{

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

    int count = 1;
    while(_task){
        qDebug() << "task running, step: " << count << Qt::endl;
        count++;

        QEventLoop loop;
        QTimer::singleShot(1000, &loop, &QEventLoop::quit);
        loop.exec();
    }
}

void TaskExecutor::stopTask()
{
    qDebug() << "TaskExecutor: stop task!" << Qt::endl;
    _task = false;
    QString str("task stopped!");
    emit taskStopped(str);
}
