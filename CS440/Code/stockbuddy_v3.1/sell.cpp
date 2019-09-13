#include "sell.h"
#include "ui_sell.h"
#include <QMessageBox>

sell::sell(QWidget *parent) :
QDialog(parent),
ui(new Ui::sell)
{
    ui->setupUi(this);
}

sell::~sell()
{
    delete ui;
}

// If button is clicked, displays total cost
void sell::on_pushButton_2_clicked()
{
    float volume,cost,total_cost;

    volume = ui->lineEdit_6->text().toFloat();
    cost = ui->lineEdit_7->text().toFloat();
    total_cost = volume*cost;
    ui->lineEdit_15->setText(QString::number(total_cost,'f',2));    //summary float
}

// Displays specific queries
void sell::on_tableView_activated(const QModelIndex &index)
{
    extern QString username;    //call username
    QString val=ui->tableView->model()->data(index).toString();

    MainWindow mw;

    QSqlQuery qry;
    qry.prepare("SELECT * FROM InvHistory WHERE Company_Initials='"+val+"'AND username='"+username+"'");  //change accordingly
    if(qry.exec())
    {
        while(qry.next())
        {
            // query values based on database columns
            ui->lineEdit->setText(qry.value(1).toString()); // company initials
            ui->lineEdit_7->setText(qry.value(5).toString());   // cost
        }
        mw.connclose();
    }
}

// If user selects OK, execute summary
void sell::on_buttonBox_accepted()
{
    this->hide();
    summary by;
    by.setModal(true);
    by.exec();
}

// If user select Cancel, execute prompt
void sell::on_buttonBox_rejected()
{
    this->hide();
    prompt by;
    by.setModal(true);
    by.exec();
}

void sell::on_pushButton_clicked()
{
    extern QString username;    //call current user

    MainWindow mw;

    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery* qry= new QSqlQuery(mw.mydb);
    qry->prepare("SELECT Company_Initials, VolumeInv from InvHistory WHERE username='"+username+"'");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    mw.connclose();
}

void sell::on_pushButton_3_clicked()
{

    extern QString username;    //call current user
    QString val=ui->lineEdit->text();
    QString volume,cost,total_cost;

    volume = ui->lineEdit_6->text();
    cost = ui->lineEdit_7->text();
    total_cost = ui->lineEdit_15->text();

    MainWindow mw;

    QSqlQuery qry;
    qry.prepare("UPDATE InvHistory SET VolumeInv =VolumeInv - '"+volume+"',balance=balance + '"+total_cost +"' WHERE Company_Initials='"+val+"'AND username='"+username+"'");
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Sold!"),tr("Stocks were successfully sold!"));
        mw.connclose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error!"),qry.lastError().text());
    }

}
