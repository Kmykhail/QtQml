#include <QDebug>
#include <QThread>
#include "consumer.h"

Consumer::Consumer(QObject *parent)
{
    qInfo() << "Constructed consumer for thread:" << QThread::currentThread();
}

Consumer::~Consumer()
{
    qInfo() << "Deconstructed consumer for thread:" << QThread::currentThread();
}

void Consumer::consume(int value)
{
    qInfo() << "Consumed value" << value << "on thread" << QThread::currentThread();
}
