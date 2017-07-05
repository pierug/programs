#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Lotto winner, ps. Lowciam Ole");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_getLuckyBtn_clicked()
{
    int* numbers = lotto.createLuckySix();

    ui->lineEdit_6->setText(QString::number(numbers[0]));
    ui->lineEdit_5->setText(QString::number(numbers[1]));
    ui->lineEdit_4->setText(QString::number(numbers[2]));
    ui->lineEdit_3->setText(QString::number(numbers[3]));
    ui->lineEdit_2->setText(QString::number(numbers[4]));
    ui->lineEdit->setText(QString::number(numbers[5]));
    delete numbers;
}
