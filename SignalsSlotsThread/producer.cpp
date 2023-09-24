#include <QDebug>
#include <QRandomGenerator>
#include "producer.h"

Producer::Producer(QObject *parent)
{
    qInfo() << "Constructed producer for thread:" << QThread::currentThread();
}

Producer::~Producer()
{
    qInfo() << "Deconstructed producer for thread:" << QThread::currentThread();
}

void Producer::start()
{
    qInfo() << "Starting producer for thread" << QThread::currentThread();
    m_timer = new QTimer();
    m_timer->setInterval(500);
    connect(m_timer, &QTimer::timeout, this, &Producer::timeout);
    connect(this, &Producer::finished, m_timer, &QTimer::stop);
    m_timer->start();
}

void Producer::timeout()
{
    int randomNum = QRandomGenerator::global()->bounded(1,100);
    qInfo() << "Produced" << randomNum << "on thread" << QThread::currentThread();
    emit produce(randomNum);

    if (++m_cnt >= m_max) {
        qInfo() << "Finished" << "on thread" << QThread::currentThread();
        emit finished();
    }
}
