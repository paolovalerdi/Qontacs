#pragma once

#include <QObject>
#include <QJsonObject>
#include <contacts_manager.h>

class ContactsController : public QObject
{
    Q_OBJECT
public:
    explicit ContactsController(ContactsManager manager, QObject *parent = nullptr);

public slots:
    void update();
    void insert(QString name, QString lastName, QString phone);

signals:
    void stateChange(QString state);
private:
    ContactsManager manager;
};

