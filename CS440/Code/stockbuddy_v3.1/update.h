#ifndef UPDATE_H
#define UPDATE_H
#include "mainwindow.h"

#include <QDialog>

namespace Ui {
class Update;
}

class Update : public QDialog
{
    Q_OBJECT

public:
    explicit Update(QWidget *parent = 0);
    ~Update();

private slots:
    void on_pushButton_update_clicked();

private:
    Ui::Update *ui;
};

#endif // UPDATE_H
