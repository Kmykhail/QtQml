#pragma once

#include <QObject>
#include <QRunnable>

// The same class for producer and consumer
class Widget: public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Widget(bool isSender = false, QObject *parent = nullptr);
    ~Widget();

Q_SIGNALS:
    void started();
    void finished();
    void generate(int val);

public Q_SLOTS:
    void workStarted();
    void workFinished();
    void workReady(int val);

    void run() override;

private:
    bool m_isSender {false};
    bool m_isActive {false};
};

