#include "update.h"
#include "ui_update.h"
#include <QMessageBox>

Update::Update(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Update)
{
    ui->setupUi(this);
}

Update::~Update()
{
    delete ui;
}

// User can update their user profile
void Update::on_pushButton_update_clicked()
{
    MainWindow mw;
    QString firstname,lastname,username,email,password;
    firstname=ui->text_firstname->text();
    lastname=ui->text_lastname->text();
    username=ui->text_username->text();
    email=ui->text_email->text();
    password=ui->text_password->text();

    QSqlQuery qry;
    qry.prepare("UPDATE user_info1 set first_name='"+firstname+"',last_name='"+lastname+"',username='"+username+"',email='"+email+"',password='"+password+"' WHERE username='"+username+"'");
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Updated!"),tr("Your records have been updated. Please login to continue."));
        mw.connclose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error!"),qry.lastError().text());
    }
}
