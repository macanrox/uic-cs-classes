#include "buy.h"
#include "ui_buy.h"

buy::buy(QWidget *parent) :
QDialog(parent),
ui(new Ui::buy)
{
    ui->setupUi(this);
}

buy::~buy()
{
    delete ui;
}

// If button is clicked, displays grabs queries
void buy::on_pushButton_clicked()
{
    MainWindow mw;

    QSqlQueryModel * modal= new QSqlQueryModel();
    QSqlQuery* qry= new QSqlQuery(mw.mydb);
    qry->prepare("SELECT Company_Initials, Volume, High, Low, Close FROM stockMarketData");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    mw.connclose();
}

// If button is clicked, displays total cost
void buy::on_pushButton_2_clicked()
{
    float volume,cost,total_cost;

    volume=ui->lineEdit_6->text().toFloat();
    cost=ui->lineEdit_7->text().toFloat();
    total_cost=volume*cost;
    ui->lineEdit_15->setText(QString::number(total_cost,'f',2));    //summary float
}

// Displays specific queries
void buy::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();

    MainWindow mw;

    QSqlQuery qry;
    qry.prepare("SELECT * FROM stockMarketData WHERE Company_Initials='"+val+"'");  //change accordingly
    if(qry.exec())
    {
        while(qry.next())
        {
            // query values based on database columns
            ui->lineEdit->setText(qry.value(0).toString());
            ui->lineEdit_7->setText(qry.value(4).toString());
        }
        mw.connclose();
    }
}

// If user selects OK, execute summary
void buy::on_buttonBox_accepted()
{
    this->hide();
    summary by;
    by.setModal(true);
    by.exec();
}

// If user selects CANCEL, execute prompt
void buy::on_buttonBox_rejected()
{
    this->hide();
    prompt by;
    by.setModal(true);
    by.exec();
}

void buy::on_pushButton_3_clicked()
{
    extern QString username;    //call current user
    QString val=ui->lineEdit->text();
    QString volume,cost,total_cost;

    volume = ui->lineEdit_6->text();
    cost = ui->lineEdit_7->text();
    total_cost = ui->lineEdit_15->text();

    MainWindow mw;

    QSqlQuery qry;
    qry.prepare("UPDATE InvHistory SET VolumeInv =VolumeInv - '"+volume+"',balance =balance - '"+total_cost+"' WHERE Company_Initials='"+val+"'AND username='"+username+"'");
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Sold!"),tr("Stocks were successfully bought!"));
        mw.connclose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error!"),qry.lastError().text());
    }

}
