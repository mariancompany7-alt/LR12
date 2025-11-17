#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>
#include <qQebug>

class DatabaseManager {

public:
    static DatabaseManager* getInstance() {
        if(instance == nullptr) {
            instance = new DatabaseManager;
        }
        return instance;
    }

    QSqlDatabase database() const {return db;}

private:
    QSqlDatabase db;
    static DatabaseManager* instance;

    DatabaseManager::DatabaseManager() {

        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("firms.db");

        if (!db.open()) {
            qDebug() << "Помилка відкриття БД:";
        } else {
            qDebug() << "БД відкрита успішно!";
        }

    }
};

#endif // DATABASEMANAGER_H

DatabaseManager* DatabaseManager::instance = nullptr;
