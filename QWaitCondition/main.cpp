#include <QCoreApplication>
#include <QThread>
#include "producer.h"
#include "consumer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMutex mtx;
    QWaitCondition wCondition;
    int value = 0;

    QThread pThread;
    Producer *p = new Producer(&mtx, &wCondition, &value);

    QThread cThread;
    Consumer *c = new Consumer(&mtx, &wCondition, &value);

    p->moveToThread(&pThread);
    c->moveToThread(&cThread);
    a.connect(&pThread, &QThread::started, p, &Producer::run);
    a.connect(&cThread, &QThread::started, c, &Consumer::run);
    a.connect(&pThread, &QThread::finished, p, &QObject::deleteLater);
    a.connect(&cThread, &QThread::finished, c, &QObject::deleteLater);

    pThread.start();
    cThread.start();

    return a.exec();
}
