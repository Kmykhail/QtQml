#pragma once

#include <QRunnable>
#include <QMutex>

class Task: public QRunnable
{
public:
    Task(QMutex *mutex, int *value);

    void run() override;
private:
    int *m_value;
    QMutex *m_mutex;
};

