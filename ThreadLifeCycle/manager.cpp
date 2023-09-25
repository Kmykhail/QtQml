#include "manager.h"
#include "counter.h"

Q_LOGGING_CATEGORY(manager, "manager")

Manager::Manager(QObject *parent)
{
    for (int i = 0; i < 3; i++) {
        QThread *th = new QThread(this);
        th->setObjectName("Thread" + QString::number(i));
        qInfo(manager) << "Created thread -" << th->objectName();
        m_threads.append(th);

        connect(th, &QThread::started, this, &Manager::threadStarted);
        connect(th, &QThread::finished, this, &Manager::threadFinished);
    }
}

Manager::~Manager()
{
}

void Manager::start()
{
    for (auto &th: m_threads) {
        Counter *cnt = new Counter(this);
        cnt->moveToThread(th);
        connect(th, &QThread::started, cnt, &Counter::start);

        th->start();
    }
}

void Manager::threadStarted()
{
    auto senderTh = qobject_cast<QThread*>(sender());
    if (senderTh) {
        qInfo(manager) << "Thread started:" << senderTh->objectName();
    }
}

void Manager::threadFinished()
{
    auto senderTh = qobject_cast<QThread*>(sender());
    if (senderTh) {
        qInfo(manager) << "Thread finished:" << senderTh->objectName();

        m_threads.removeAll(senderTh);
        delete senderTh;
    }
}
