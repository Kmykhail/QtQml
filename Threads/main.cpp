#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QScopedPointer>
#include <QThreadPool>
#include "task.h"

//void test() {
//    QThread::currentThread()->setObjectName("MAIN THREAD");
//    qInfo() << "Starting work" << QThread::currentThread();

//    QThread worker;
//    worker.setObjectName("WORKER THREAD");

//    QScopedPointer<Task> task(new Task());
//    task->moveToThread(&worker);

//    worker.connect(&worker, &QThread::started, task.data(), &Task::work);
//    worker.start();

//    qInfo() << "Free to do other stuff" << QThread::currentThread();
//}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Start stuff" << QThread::currentThread();

    qInfo() << "maxThreadCount" << QThreadPool::globalInstance()->maxThreadCount();

    for (int i = 0; i < 3; i++) {
        Task *task = new Task();
        task->setAutoDelete(true);
        QThreadPool::globalInstance()->start(task);
    }

    qInfo() << "Free to do other stuff" << QThread::currentThread();

    return a.exec();
}
