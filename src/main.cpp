#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSqlDatabase>
#include <QSqlError>
#include "contacts_manager.h"
#include "contacts_controller.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    qDebug() << "####VERYFING IF SQLITE DRIVERS IS AVAILABLE###";
    if (!QSqlDatabase::isDriverAvailable("QSQLITE")) {
        qDebug() << "No SQLITE driver";
        return -1;
    } else {
        qDebug() << "Driver available";
    }


    qDebug() << "####OPENING DATABASE###";
    auto database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("../database.db");
    if (!database.open()) {
        qDebug() << "Coudln't open database";
        qDebug() << database.lastError().text();
        return -2;
    } else {
        qDebug() << "Database open";
    }


    qDebug() << "####CREATING DATABASE IF NOT EXISTS###";
    QSqlQuery query;
    auto exec = query.exec("CREATE TABLE IF NOT EXISTS contacts ("
               "id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
               "name TEXT NOT NULL, "
               "email TEXT NOT NULL, "
               "phone TEXT NOT NULL"
               ");");
    qDebug() << (exec ? "Created or ignored" : query.lastError().text());

    auto contactsManager = ContactsManager(database);


    auto contactsController = ContactsController(contactsManager);


    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("contactsController", &contactsController);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
