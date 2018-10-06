#include <QGuiApplication>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStandardPaths>

#include "sessionmodel.h"
#include "session.h"
#include "step.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    SessionModel sessionModel;
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);

    /*
    if (!sessionModel.load(path + "/sessions.json")) {
        return -1;
    }
    */
    qmlRegisterType<Session>("com.fract.model", 1, 0, "Session");
    qmlRegisterType<Step>("com.fract.model", 1, 0, "Step");

    engine.rootContext()->setContextProperty("sessionModel", &sessionModel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
