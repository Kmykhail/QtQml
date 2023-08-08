#include <QDebug>
#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{
    connect(&m_timer, &QTimer::timeout, this, &Test::updateDate);
    m_timer.setInterval(1000);

    qInfo() << "TEST CONSTRUCTOR";
}

void Test::updateDate()
{
    m_display = QDateTime::currentDateTime().toString();
    emit dateChanged(m_display);

    qInfo() << "DATE:" << m_display;
}

void Test::start()
{
    m_display = "START";
    emit dateChanged(m_display);

    m_timer.start();
}

void Test::stop()
{
    m_timer.stop();
    m_display = "Staopped";
    emit dateChanged(m_display);
}

