#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbExit_clicked()
{
    QApplication::exit();
}

void MainWindow::on_pbShow_clicked()
{
    ptr = new Firm(ui->le_1->text(), ui->le_2->text().toInt());
    ui->label->setText(ptr->toString());
}


void MainWindow::on_createObj_clicked()
{
    if(ui->le_1->text().isEmpty() || ui->le_2->text().isEmpty()) {
            QMessageBox::critical(this, "Error", "You need to fill all fields");
        }
    else {
            QMessageBox::information(this, "***", "Object created successfully!");
        }
}

