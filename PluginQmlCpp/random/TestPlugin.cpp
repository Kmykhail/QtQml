#include "TestPlugin.h"
#include "Test.h"

#include <QQmlEngine>

void TestPlugin::registerTypes(const char *uri)
{
    qInfo() << "URI: " << uri;

    Q_UNUSED(uri)
    qmlRegisterType<Test>("test", 1, 0, "Test");
}
