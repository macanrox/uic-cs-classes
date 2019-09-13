#include "mainwindow.h"
#include "ui_mainwindow.h"

QString username;   //global variable for current user

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Registration button
void MainWindow::on_pushButton_2_clicked()
{
    Register reg;
    reg.setModal(true);
    reg.exec();
}

// Login button
void MainWindow::on_pushButton_clicked()
{
    QString password;
    username=ui->lineEdit_username->text();
    password=ui->lineEdit_password->text();

    MainWindow mw;

    QSqlQuery qry;
    qry.prepare("SELECT * FROM user_info1 WHERE username='"+username +"'AND password='"+password+"'");
    if(qry.exec())
    {
        int count=0;
        while(qry.next())
            count++;
        //If true, go to the welcome screen
        if(count==1){
            mw.connclose();
            this->hide();
            welcome wc;
            wc.setModal(true);
            wc.exec();
        }
        //Otherwise display error message
        if(count<1)
            QMessageBox::information(this,tr("Try again."),tr("Username or password incorrect."));
        if(count>1)
            QMessageBox::information(this,tr("Try again."),tr("Duplicate username and password."));
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    Update up;
    up.setModal(true);
    up.exec();

}
