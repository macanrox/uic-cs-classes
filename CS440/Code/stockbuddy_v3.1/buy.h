#ifndef BUY_H
#define BUY_H
#include "prompt.h"
#include "summary.h"

#include <QDialog>

namespace Ui {
class buy;
}

class buy : public QDialog
{
    Q_OBJECT

public:
    explicit buy(QWidget *parent = 0);
    ~buy();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_pushButton_3_clicked();

private:
    Ui::buy *ui;
};

#endif // BUY_H
