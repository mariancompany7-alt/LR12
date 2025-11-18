#include "databasemanager.h"

DatabaseManager* DatabaseManager::instance = nullptr;

DatabaseManager::DatabaseManager() {

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./LR12.db");

    if (!db.open()) {
        qDebug() << "Помилка відкриття БД";
    } else {
        qDebug() << "БД відкрита успішно!";
    }

    QSqlQuery query(db);
    query.exec("CREATE TABLE IF NOT EXISTS users(name TEXT, email TEXT, password TEXT)");

    tableModel = new QSqlTableModel(nullptr, db);
    tableModel->setTable("firms");
    tableModel->select();
    tableModel->setHeaderData(0, Qt::Horizontal, "Type of firm");
    tableModel->setHeaderData(1, Qt::Horizontal, "Size of firm");
}

bool DatabaseManager::addFirm(const QString& type, int size) {

    QSqlQuery query(db);
    query.prepare("INSERT INTO firms (type, size) VALUES (:type, :size)");
    query.bindValue(":type", type);
    query.bindValue(":size", size);

    if (!query.exec()) {
        qDebug() << "Помилка вставки:";
        return false;
    }

    tableModel->select();
    return true;
}

QSqlTableModel* DatabaseManager::getTableModel() {
    return tableModel;
}
