#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>

#include"register.h"
#include"welcome.h"
#include"update.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:

    //Database
    QSqlDatabase mydb;

    //Open connection
    bool connopen(){

       mydb = QSqlDatabase::addDatabase("QSQLITE");

       //Change the file path accordingly
       mydb.setDatabaseName("/Users/macanrox/Desktop/stockbuddy_v3.1/login.db");

       //Sanity check
       if(!mydb.open()){
           qDebug()<<("Failed to open database.");
           return false;
       }
       else {
           qDebug()<<("Connected...");
           return true;
       }
    }//end connopen

    //Close connection
    void connclose(){
        qDebug() << "Closing database...";
        QString connection;
        connection = mydb.connectionName();
        mydb.close();
        mydb = QSqlDatabase();
        mydb.removeDatabase(connection);

        qDebug() << "Database successfully closed.";
    }//end connclose

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
