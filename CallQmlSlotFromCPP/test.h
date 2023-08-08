#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDateTime>
#include <QTimer>
#include <QVariant>

class Test : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString date READ date NOTIFY dateChanged)
public:
    explicit Test(QObject *parent = nullptr);

    QString date() {
        return m_display;
    }

    Q_SLOT void start();
    Q_SLOT void stop();

signals:
    void dateChanged(QString display);

private:
    Q_SLOT void updateDate();

    QTimer m_timer;
    QString m_display;
};

#endif // TEST_H
