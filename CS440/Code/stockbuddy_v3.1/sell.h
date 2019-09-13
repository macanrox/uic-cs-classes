#ifndef SELL_H
#define SELL_H
#include "prompt.h"
#include "summary.h"

#include <QDialog>

namespace Ui {
class sell;
}

class sell : public QDialog
{
    Q_OBJECT

public:
    explicit sell(QWidget *parent = 0);
    ~sell();

private slots:

    void on_pushButton_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::sell *ui;
};

#endif // SELL_H
