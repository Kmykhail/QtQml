#include <QDebug>
#include <QThread>
#include <QRandomGenerator>

#include "counter.h"

Q_LOGGING_CATEGORY(cnt, "counter")

Counter::Counter(QObject *parent)
{
    qInfo(cnt) << "Constructed for thread" << QThread::currentThread();
}

Counter::~Counter()
{
    qInfo(cnt) << "Deconstructed" << QThread::currentThread();
}

void Counter::start()
{
    for (int i = 0; i < 10; i++) {
        qInfo(cnt) << QThread::currentThread()->objectName() << "=" << i;
        auto value = static_cast<ulong>(QRandomGenerator::global()->bounded(1000));
        QThread::currentThread()->msleep(value);
    }

    qInfo(cnt) << "Finished";

    // remove memory leak in manager.cpp::27
    deleteLater();
    // to call the method `threadFinished` in manager.cpp::27
    QThread::currentThread()->quit();
}
