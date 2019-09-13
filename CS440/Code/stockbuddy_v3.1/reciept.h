#ifndef RECIEPT_H
#define RECIEPT_H
#include "summary.h"

#include <QDialog>

namespace Ui {
class Reciept;
}

class Reciept : public QDialog
{
    Q_OBJECT

public:
    explicit Reciept(QWidget *parent = 0);
    ~Reciept();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Reciept *ui;
};

#endif // RECIEPT_H
