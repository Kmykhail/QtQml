#include <QCoreApplication>
#include <QThreadPool>
#include "widget.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Widget *producer = new Widget(true);
    producer->setObjectName("Producer");
    producer->setAutoDelete(true); // not mandatory, will work by default

    Widget *consumer = new Widget;
    consumer->setObjectName("Consumer");
    consumer->setAutoDelete(true); // not mandatory, will work by default

    a.connect(producer, &Widget::started, consumer, &Widget::workStarted);
    a.connect(producer, &Widget::generate, consumer, &Widget::workReady);
    a.connect(producer, &Widget::finished, consumer, &Widget::workFinished);

    QThreadPool::globalInstance()->start(producer);
    QThreadPool::globalInstance()->start(consumer);

    return a.exec();
}
