#pragma once

#include <QObject>
#include <QMutex>
#include <QWaitCondition>

class Consumer: public QObject
{
    Q_OBJECT
public:
    explicit Consumer(QMutex *mutex, QWaitCondition *waitCondition, int *value, QObject *parent = nullptr);
    ~Consumer();

    Q_SLOT void run();
private:
    QMutex *m_mutex;
    QWaitCondition *m_condtion;
    int *m_value;
};

