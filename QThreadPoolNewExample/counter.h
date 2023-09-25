#pragma once

#include <QRunnable>
#include <QThread>

class Counter: public QRunnable
{
public:
    Counter();
    ~Counter();

    void run() override;
};

