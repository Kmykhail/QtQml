#pragma once

#include <QObject>
#include <QLoggingCategory>
#include <QScopedPointer>

Q_DECLARE_LOGGING_CATEGORY(counter)

class Counter: public QObject
{
    Q_OBJECT
public:
    explicit Counter(QObject *parent = nullptr);
    ~Counter();

    Q_SLOT void start();
};

