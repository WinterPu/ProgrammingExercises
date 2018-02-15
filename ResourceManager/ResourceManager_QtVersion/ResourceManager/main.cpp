#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "MyKits.h"
#include "ResourceManager.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    qmlRegisterType<MyKits>("MyKits", 1, 0, "Kits");


    ResourceManager resource_manager;
    qmlRegisterType<ResourceManager>("ResourceManager", 1, 0, "ResourceManager");


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
