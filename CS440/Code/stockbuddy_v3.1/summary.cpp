#include "summary.h"
#include "ui_summary.h"

summary::summary(QWidget *parent) :
QDialog(parent),
ui(new Ui::summary)
{
    ui->setupUi(this);
}

summary::~summary()
{
    delete ui;
}

// If user selects COMMIT, close program
void summary::on_pushButton_clicked()
{
    QApplication::quit();
}

// User refreshes to update the query
void summary::on_pushButton_2_clicked()
{
    extern QString username;    //call current user
    MainWindow mw;

    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery* qry= new QSqlQuery(mw.mydb);
    qry->prepare("SELECT Company_Initials, VolumeInv, Loss, Gain from InvHistory WHERE username='"+username+"'");
    qry->exec();

    // Parse query and calculate total
    while(qry->next())
    {
        float userVolume = qry->value(1).toFloat();
        float userLoss = qry->value(2).toFloat();
        float userGain = qry->value(3).toFloat();
    }

    model->setQuery(*qry);
    ui->tableView->setModel(model);
    mw.connclose();
}

void summary::on_pushButton_4_clicked()
{
    this->hide();
    welcome wc;
    wc.setModal(true);
    wc.exec();
}

void summary::on_pushButton_3_clicked()
{
    this->hide();
    Reciept rp;
    rp.setModal(true);
    rp.exec();
}
