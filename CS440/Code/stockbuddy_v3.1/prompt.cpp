#include "prompt.h"
#include "ui_prompt.h"

prompt::prompt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::prompt)
{
    ui->setupUi(this);
}

prompt::~prompt()
{
    delete ui;
}

// Hide prompt and go to buy page if clicked
void prompt::on_pushButton_clicked()
{
    this->hide();
    buy by;
    by.setModal(true);
    by.exec();
}

// Hide prompt and go to sell page if clicked
void prompt::on_pushButton_2_clicked()
{
    this->hide();
    sell by;
    by.setModal(true);
    by.exec();
}

void prompt::on_pushButton_3_clicked()
{
    this->hide();
    welcome wc;
    wc.setModal(true);
    wc.exec();
}
