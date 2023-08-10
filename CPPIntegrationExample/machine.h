#pragma once

#include <QObject>
#include <QTimer>

class machine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int workload READ value WRITE setValue NOTIFY progress FINAL)
public:
    explicit machine(QObject* parent = nullptr);

    int value() const;
    void setValue(int value);

    Q_SLOT void start();
    Q_SLOT void stop();
    Q_SLOT void pause();
    Q_SLOT void resume();

    Q_SIGNAL void progress();
    Q_SIGNAL void started();
    Q_SIGNAL void paused();
    Q_SIGNAL void resummed();
    Q_SIGNAL void stopped();

private:
    Q_SLOT void timeout();

private:
    QTimer m_timeout;

    int m_value;
};

