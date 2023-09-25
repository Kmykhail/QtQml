#include <QCoreApplication>
#include <QThreadPool>
#include <QThread>
#include "counter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("MAIN");
    QThreadPool *pool = QThreadPool::globalInstance();
    qInfo() << "pool capasity" << pool->maxThreadCount();

    // reused all max thread
    for (int i = 0; i < 100; i ++) {
        Counter *cnt = new Counter;
        cnt->setAutoDelete(true);
        pool->start(cnt);
    }

    return a.exec();
}
