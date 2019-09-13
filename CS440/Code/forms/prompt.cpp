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
