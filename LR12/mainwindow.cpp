#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dbManager = DatabaseManager::getInstance();
    setupTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbExit_clicked() {
    QApplication::exit();
}

void MainWindow::setupTable() {

    QSqlTableModel* model = dbManager->getTableModel();
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::on_createObj_clicked() {

    if(ui->le_1->text().isEmpty() || ui->le_2->text().isEmpty()) {
            QMessageBox::critical(this, "Error", "You need to fill all fields");
    }
    else {
            QMessageBox::information(this, "***", "Object created successfully!");
    }

    QString type = ui->le_1->text();
    int size = ui->le_2->text().toInt();

    dbManager->addFirm(type, size);
    ui->le_1->clear();
    ui->le_2->clear();
}
