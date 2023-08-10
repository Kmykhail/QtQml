#include <QDebug>
#include "machine.h"

machine::machine(QObject *parent) : QObject(parent)
{
    m_timeout.setInterval(800);
    connect(&m_timeout, &QTimer::timeout, this, &machine::timeout);
}

int machine::value() const
{
    return m_value;
}

void machine::setValue(int value)
{
    m_value = value;
    emit progress();
}

void machine::start()
{
    setValue(0);
    m_timeout.start();
    emit started();
}

void machine::stop()
{
    m_timeout.stop();
    emit stopped();
}

void machine::pause()
{
    m_timeout.stop();
    emit paused();
}

void machine::resume()
{
    m_timeout.start();
    emit resummed();
}

void machine::timeout()
{
    setValue(m_value + 1);
    if (m_value > 99) {
        stop();
    }
}
