#include <QDebug>
#include <QThread>
#include <QMutexLocker>
#include "task.h"

Task::Task(QMutex *mutex, int *value) : m_mutex(mutex), m_value(value)
{
}

void Task::run()
{
    QMutexLocker locker(m_mutex);

    QThread::currentThread()->msleep(10);
    *m_value += 1;
    qInfo() << QThread::currentThread() << *m_value;
}
