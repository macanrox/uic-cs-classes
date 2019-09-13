#ifndef WELCOME_H
#define WELCOME_H
#include "mainwindow.h"
#include "prompt.h"

#include <QDialog>
#include <QMessageBox>

namespace Ui {
    class welcome;
}

class welcome : public QDialog
{
    Q_OBJECT

public:
    explicit welcome(QWidget *parent = 0);
    ~welcome();

    private slots:
    void on_get_currentstockrate_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::welcome *ui;
};

#endif // WELCOME_H
