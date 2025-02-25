#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "PrimeChecker.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    PrimeChecker primeChecker;

    engine.rootContext()->setContextProperty("primeChecker", &primeChecker);

    const QUrl url(QStringLiteral("qrc:/prime_number/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
