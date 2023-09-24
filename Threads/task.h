#pragma once

#include <QObject>
#include <QThread>
#include <QRunnable>

class Task: public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = nullptr);
    ~Task();

    void run() override;
};

