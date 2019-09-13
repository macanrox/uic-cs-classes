#include "register.h"
#include "ui_register.h"
#include <QMessageBox>


Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

// User enters their information which gets sent to the db
void Register::on_pushButton_clicked()
{
    MainWindow mw;

    QString rowid,firstname,lastname,username,email,password;
    firstname=ui->text_firstname->text();
    lastname=ui->text_lastname->text();
    username=ui->text_username->text();
    email=ui->text_email->text();
    password=ui->text_password->text();

    QSqlQuery qry;
    qry.prepare("INSERT INTO user_info1 (first_name, last_name, username, email, password) values ('"+firstname+"','"+lastname+"','"+username+"','"+email+"','"+password+"')");
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Congratulations!"),tr("You have been registered. Please login to continue."));
    }
    else
    {
        QMessageBox::critical(this,tr("Error!"),qry.lastError().text());
    }

}

