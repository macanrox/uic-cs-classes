#include "reciept.h"
#include "ui_reciept.h"

Reciept::Reciept(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reciept)
{
    ui->setupUi(this);
}

Reciept::~Reciept()
{
    delete ui;
}

//Display the receipt to the user
void Reciept::on_pushButton_clicked()
{
    extern QString username;    //call current user

    MainWindow mw;

    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery* qry= new QSqlQuery(mw.mydb);
    qry->prepare("SELECT username,sum(VolumeInv), sum(loss), sum(Gain),sum(balance) from InvHistory WHERE username='"+username+"'");
    qry->exec();

    // Parse query and calculate total
    while(qry->next())
    {
        float userLoss = qry->value(2).toFloat();
        float userGain = qry->value(3).toFloat();
        float Volume=qry->value(1).toFloat();

        float balance=qry->value(4).toFloat();
        ui->lineEdit_2->setText(QString::number(userGain));// Display gain
        ui->lineEdit_3->setText(QString::number(balance));// Display balance
        ui->lineEdit_4->setText(QString::number(Volume));// Display volume of stocks
        ui->lineEdit_5->setText(QString::number(userLoss));// Display loss
    }

    model->setQuery(*qry);
    mw.connclose();
}

//Go back to the summary page
void Reciept::on_pushButton_2_clicked()
{
    this->hide();
    summary by;
    by.setModal(true);
    by.exec();
}
