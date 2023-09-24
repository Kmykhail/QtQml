#include <QCoreApplication>
#include <QSettings>
#include <QDebug>

void info(QSettings &settings) {
    qInfo() << "Settings File: " << settings.fileName() << ", allKeys: " << settings.allKeys();
}

void save(QSettings &settings) {
    settings.setValue("TestIntValue", 10);
    settings.setValue("TestStringValue", "Oksana");
    qInfo() << "Saved";
}

void load(QSettings &settings) {
    info(settings);
    qInfo() << "status: " << settings.status();
    qInfo() << settings.value("TestIntValue").toString();
    qInfo() << settings.value("TestStringValue").toString();

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setOrganizationName("KostyaOrgName");
    QCoreApplication::setOrganizationDomain("KON.com");
    QCoreApplication::setApplicationName("SettingsTest");

//    QSettings setting(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    QString filename = a.applicationDirPath() + "/setting.ini";

    QSettings setting(filename, QSettings::Format::NativeFormat);
    if (!setting.allKeys().length()) {
        qInfo() << "Need to save settings";
        save(setting);
    } else {
        qInfo() << "....Loading...settings...";
        load(setting);
    }


    return a.exec();
}
