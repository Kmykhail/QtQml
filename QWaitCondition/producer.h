#pragma once

#include <QObject>
#include <QMutex>
#include <QWaitCondition>

class Producer: public QObject
{
    Q_OBJECT
public:
    explicit Producer(QMutex *mutex, QWaitCondition *waitCondition, int *value, QObject *parent = nullptr);
    ~Producer();

    Q_SLOT void run();
private:
    QMutex *m_mutex;
    QWaitCondition *m_condtion;
    int *m_value;
};

