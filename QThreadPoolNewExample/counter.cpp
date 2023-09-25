#include <QDebug>
#include <QRandomGenerator>
#include "counter.h"

Counter::Counter()
{
    qInfo() << this << "Construted";
}

Counter::~Counter()
{
    qInfo() << this << "Deconstructed";
}

void Counter::run()
{
    for (int i = 0; i < 10; i++) {
        qInfo() << QThread::currentThread() << "=" << i;
        auto value = static_cast<ulong>(QRandomGenerator::global()->bounded(500));
        QThread::currentThread()->msleep(value);
    }

    qInfo() << this << "Finished";
}


