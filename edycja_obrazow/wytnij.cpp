#include "wytnij.h"
#include "ui_wytnij.h"

wytnij::wytnij(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::wytnij)
{
    ui->setupUi(this);
}

wytnij::~wytnij()
{
    delete ui;
}

void wytnij::on_spinBox_X_valueChanged(int arg1)
{

}

void wytnij::on_spinBox_Y_valueChanged(int arg1)
{

}

void wytnij::on_spinBox_wys_valueChanged(int arg1)
{

}

void wytnij::on_spinBox_szer_valueChanged(int arg1)
{

}

void wytnij::on_pushButton_clicked()
{

}
