#include <QDebug>
#include <QThread>
#include "task.h"

Task::Task(QMutex *mutex, int *value) : m_mutex(mutex), m_value(value)
{
}

void Task::run()
{
    m_mutex->lock();

    QThread::currentThread()->msleep(10);
    *m_value += 1;
    qInfo() << QThread::currentThread() << *m_value;

    m_mutex->unlock();
}
