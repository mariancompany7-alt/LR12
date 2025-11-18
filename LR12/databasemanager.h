#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>

class DatabaseManager {

public:
    static DatabaseManager* getInstance() {
        if(instance == nullptr) {
            instance = new DatabaseManager();
        }
        return instance;
    }

    QSqlDatabase database() const {return db;}
    bool addFirm(const QString& type, int size);
    QSqlTableModel* getTableModel();

private:
    QSqlDatabase db;
    static DatabaseManager* instance;
    QSqlTableModel* tableModel;

    DatabaseManager();
};

#endif // DATABASEMANAGER_H
