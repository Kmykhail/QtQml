#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "machine.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<machine>("My.Machine", 1, 0, "Machine");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/CPPIntegrationExample/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
