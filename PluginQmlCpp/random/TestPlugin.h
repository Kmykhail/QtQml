#pragma once
#include <QQmlExtensionPlugin>

class TestPlugin: public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "TestPlugin/1.0")
public:
    void registerTypes(const char *uri) override;
};
