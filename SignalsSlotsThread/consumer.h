#pragma once

#include <QObject>

class Consumer: public QObject
{
    Q_OBJECT
public:
    explicit Consumer(QObject *parent = nullptr);
    ~Consumer();

    Q_SLOT void consume(int value);
};

