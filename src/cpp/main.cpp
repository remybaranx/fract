#include <QGuiApplication>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStandardPaths>

#include "applicationdata.h"
#include "session.h"
#include "step.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    ApplicationData appData;

    if (!appData.loadSessions(path + "/sessions.json")) {
        return -1;
    }

    qmlRegisterType<Session>();
    qmlRegisterType<Step>();

    engine.rootContext()->setContextProperty("appData", &appData);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
