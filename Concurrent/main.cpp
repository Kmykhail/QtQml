#include <QCoreApplication>
#include <QtConcurrent/QtConcurrent>
#include <QThread>

int test() {
    auto thread = QThread::currentThread();
    qInfo() << "Starting test for thread" << thread;

    int value = 0;
    for (int i = 0; i< 3; i++) {
        qInfo() << i << "on" << thread;
        value += i;
    }

    qInfo() << "Finished test for thread" << thread;

    return value;
}

void test2() {
    qInfo() << "Hello world Q" << QThread::currentThread();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo() << "MAIN THREAD START" << QThread::currentThread();

    QFuture<int> future1 = QtConcurrent::run(test);
    QFuture<int> future2 = QtConcurrent::run(test);
    QFuture<int> future3 = QtConcurrent::run(test);
    QFuture<void> f4 = QtConcurrent::run(test2);

    qInfo() << "future1.result()" << future1.result();
    qInfo() << "future2.result()" << future2.result();
    qInfo() << "future3.result()" << future3.result();


    qInfo() << "MAIN THREAD FINISH" << QThread::currentThread();
    return a.exec();
}
