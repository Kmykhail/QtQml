#pragma once

#include <QObject>
#include <QTimer>
#include <QThread>

class Producer: public QObject
{
    Q_OBJECT
public:
    explicit Producer(QObject *parent = nullptr);
    ~Producer();

    Q_SIGNAL void produce(int value);
    Q_SIGNAL void finished();

    Q_SLOT void start();

private:
    Q_SLOT void timeout();

    QTimer *m_timer;
    int m_cnt{0};
    int m_max{3};
};

