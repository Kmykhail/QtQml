#include <QDebug>
#include <QThread>
#include <QRandomGenerator>
#include "producer.h"

Producer::Producer(QMutex *mutex, QWaitCondition *waitCondition, int *value, QObject *parent)
    : m_mutex(mutex)
    , m_condtion(waitCondition)
    , m_value(value)
{
}

Producer::~Producer()
{
    qInfo() << "Deconstructed" << this;
}

void Producer::run()
{
    qInfo() << "Producer running ...";
    QThread::currentThread()->msleep(1000);

    m_mutex->lock();
    qInfo() << "Producer locked mutex, thread:" << QThread::currentThread();

    *m_value = QRandomGenerator::global()->bounded(1000);
    qInfo() << "Producer updated value:" << *m_value;
    m_mutex->unlock();

    m_condtion->wakeAll();
    QThread::currentThread()->quit();
}

