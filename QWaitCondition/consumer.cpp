#include <QDebug>
#include <QThread>
#include "consumer.h"

Consumer::Consumer(QMutex *mutex, QWaitCondition *waitCondition, int *value, QObject *parent)
    : m_mutex(mutex)
    , m_condtion(waitCondition)
    , m_value(value)
{
}

Consumer::~Consumer()
{
    qInfo() << "Deconstructed" << this;
}

void Consumer::run()
{
    qInfo() << "Consumer running ...";
    m_mutex->lock();
    qInfo() << "Consumer locked mutex, thread:" << QThread::currentThread();
    if (!*m_value) {
        qInfo() << "Consumer waiting of an value";
        m_condtion->wait(m_mutex);
    }

    qInfo() << "Consumer get an updated value:" << *m_value;
    QThread::currentThread()->quit();
}
