#pragma once

#include <QObject>
#include <QThread>
#include <QList>
#include <QLoggingCategory>

Q_DECLARE_LOGGING_CATEGORY(manager)

class Manager: public QObject
{
    Q_OBJECT

public:
    explicit Manager(QObject *parent = nullptr);
    ~Manager();

    void start();

    Q_SLOT void threadStarted();
    Q_SLOT void threadFinished();

private:
    QList<QThread*> m_threads;
};

