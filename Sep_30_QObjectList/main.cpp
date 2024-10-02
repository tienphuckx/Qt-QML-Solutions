#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "ItemList.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    // Create an instance of ItemList
    ItemList itemList;

    // Expose ItemList to QML
    engine.rootContext()->setContextProperty("itemList", &itemList);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Sep_30_QObjectList", "Main");

    return app.exec();
}
