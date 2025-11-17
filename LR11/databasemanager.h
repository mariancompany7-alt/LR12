#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

class DatabaseManager {

public:
    static DatabaseManager* getInstance(const QString &type, int size) {
        if(instance == nullptr) {
            instance = new DatabaseManager(type, size);
        }
        return instance;
    }

    QSqlDatabase database() const {return db;}

private:
    QSqlDatabase db;
    static DatabaseManager* instance;

    DatabaseManager(const QString &type, int size) {

        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("./LR12.db");

        if (!db.open()) {
            qDebug() << "Помилка відкриття БД";
        } else {
            qDebug() << "БД відкрита успішно!";
        }

        QSqlQuery query(db);
        query.exec("CREATE TABLE IF NOT EXISTS firms (type TEXT, size INT)");

        query.prepare("INSERT INTO firms (type, size) VALUES (:type, :size)");
        query.bindValue(":type", type);
        query.bindValue(":size", size);
    }
};

#endif // DATABASEMANAGER_H

DatabaseManager* DatabaseManager::instance = nullptr;
