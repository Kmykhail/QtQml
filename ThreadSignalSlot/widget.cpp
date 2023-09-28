#include <QRandomGenerator>
#include <QThread>
#include <QDebug>
#include "widget.h"

Widget::Widget(bool isSender, QObject *parent) : m_isSender(isSender), QObject(parent)
{
}

Widget::~Widget()
{
    qInfo() << this << "destructed";
}

void Widget::workStarted()
{
    qInfo() << this <<  "Started" << sender() << QThread::currentThread();
}

void Widget::workFinished()
{
    qInfo() << this <<  "Finished" << sender() << QThread::currentThread();
    m_isActive = false;
}

void Widget::workReady(int val)
{
    qInfo() << this << "Generated" << val << sender() << QThread::currentThread();
}

void Widget::run()
{
    if (m_isSender) { // producer section
        qInfo() << this << "Starting work..." << QThread::currentThread();
        emit started();

        for (int i = 0; i < 3; i++) {
            int val = static_cast<int>(QRandomGenerator::global()->bounded(i+1, 100));

            qInfo() << this << "Value generated:" << val << QThread::currentThread();
            emit generate(val);
            QThread::currentThread()->msleep(500);
        }

        qInfo() << this << "Finished..." << QThread::currentThread();
        emit finished();
    } else { // consumer section
        qInfo() << this << "Waiting for signals ..." << QThread::currentThread();
        m_isActive = true;
        while (m_isActive) {
            QThread::currentThread()->msleep(100);
        }
    }

    qInfo() << this << "Done" << QThread::currentThread();
}
