#include "welcome.h"
#include "ui_welcome.h"

welcome::welcome(QWidget *parent) :
QDialog(parent),
ui(new Ui::welcome)
{
    ui->setupUi(this);
}

welcome::~welcome()
{
    delete ui;
}

// If user wants to grab the current stock rate information
void welcome::on_get_currentstockrate_clicked()
{
    MainWindow mw;

    QSqlQueryModel * modal= new QSqlQueryModel();
    QSqlQuery* qry1= new QSqlQuery(mw.mydb);
    qry1->prepare("SELECT Company_Initials FROM stockMarketData");
    qry1->exec();
    modal->setQuery(*qry1);
    ui->comboBox_2->setModel(modal);
    mw.connclose();
}

// If user wants to refresh their investment history
void welcome::on_pushButton_3_clicked()
{
    extern QString username;    //call current user

    MainWindow mw;

    QSqlQueryModel * modal= new QSqlQueryModel();
    QSqlQuery* qry1= new QSqlQuery(mw.mydb);
    qry1->prepare("SELECT Company_Initials FROM InvHistory WHERE username='"+username+"'");
    qry1->exec();
    modal->setQuery(*qry1);
    ui->comboBox->setModel(modal);

    mw.connclose();
}

// If user presses NEXT on Current Stock tab
// continue to the buy/sell prompt
void welcome::on_pushButton_2_clicked()
{
    this->hide();
    prompt pr;
    pr.setModal(true);
    pr.exec();
}

// If user presses NEXT on Investment History tab
// continue to the buy/sell prompt
void welcome::on_pushButton_4_clicked()
{
    this->hide();
    prompt pr;
    pr.setModal(true);
    pr.exec();
}

//Display window for user investment history
void welcome::on_comboBox_currentIndexChanged(const QString &arg1)
{
    extern QString username;    //call current user
    QString company=ui->comboBox->currentText();

    MainWindow mw;

    QSqlQueryModel * modal= new QSqlQueryModel();
    QSqlQuery* qry= new QSqlQuery(mw.mydb);
    qry->prepare("SELECT Company_Initials, VolumeInv, Loss, Gain, Open FROM InvHistory WHERE Company_Initials='"+company+"'and username='"+username+"'");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_2->setModel(modal);
    mw.connclose();
}

//Display window for stock market prices
void welcome::on_comboBox_2_currentIndexChanged(const QString &arg1)
{

    QString company=ui->comboBox_2->currentText();

    MainWindow mw;

    QSqlQueryModel * modal= new QSqlQueryModel();
    QSqlQuery* qry= new QSqlQuery(mw.mydb);
    qry->prepare("SELECT * FROM stockMarketData WHERE Company_Initials='"+company+"'");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    mw.connclose();
}

void welcome::on_pushButton_clicked()
{
    extern QString username;    //call current user
    MainWindow mw;

    QSqlQuery* qry2= new QSqlQuery(mw.mydb);

    qry2->prepare("SELECT sum(Gain), sum(Loss) ,sum(balance) from InvHistory WHERE username='"+username+"'");
    qry2->exec();

    // Parse query and calculate balance
    while(qry2->next())
    {

        extern QString username;    //call current user
        MainWindow mw;

        float rem_bal = qry2->value(2).toFloat();
        ui->lineEdit->setText(QString::number(rem_bal));  // Display balance
    }

    mw.connclose();
}
