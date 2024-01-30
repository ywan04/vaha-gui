#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    m_v.calibrate();
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(QString::number(m_v.get_weight()));
}
