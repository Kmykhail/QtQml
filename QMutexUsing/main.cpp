#include <QCoreApplication>
#include <QThreadPool>
#include <QThread>
#include "task.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("MAIN");
    QThreadPool *pool = QThreadPool::globalInstance();

    // common data for all threads
    QMutex mutex;
    int value = 0;

    for (int i = 0; i < 100; i++) {
        Task *task = new Task(&mutex, &value);
        task->setAutoDelete(true);
        pool->start(task);
    }

    return a.exec();
}
