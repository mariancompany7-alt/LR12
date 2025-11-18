#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include "Firm.h"
#include "databasemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_createObj_clicked();

    void on_pbExit_clicked();

private:
    Ui::MainWindow *ui;
    Firm *ptr;
    DatabaseManager* dbManager;
    void setupTable();
};
#endif // MAINWINDOW_H
