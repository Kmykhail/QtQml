#include "task.h"
#include <QDebug>

Task::Task(QObject *parent)
{
    qInfo() << "Constructed" << this << "on" << QThread::currentThread();
}

Task::~Task()
{
    qInfo() << "Deconstructed" << this << "on" << QThread::currentThread();
}

void Task::run()
{
    qInfo() << "Hello world from thread" << QThread::currentThread();
}
