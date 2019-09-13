#ifndef PROMPT_H
#define PROMPT_H
#include "welcome.h"
#include "buy.h"
#include "sell.h"

#include <QDialog>

namespace Ui {
class prompt;
}

class prompt : public QDialog
{
    Q_OBJECT

public:
    explicit prompt(QWidget *parent = 0);
    ~prompt();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::prompt *ui;
};

#endif // PROMPT_H
