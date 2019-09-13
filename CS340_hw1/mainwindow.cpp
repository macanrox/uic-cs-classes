#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushLike_clicked()
{
    std::cout << " You liked this button. " << std::endl;
}

void MainWindow::on_pushDislike_clicked()
{
    std::cout << " You disliked this button. " << std::endl;
}

