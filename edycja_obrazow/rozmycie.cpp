#include "rozmycie.h"
#include "ui_rozmycie.h"

rozmycie::rozmycie(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::rozmycie)
{
    ui->setupUi(this);
}

rozmycie::~rozmycie()
{
    delete ui;
}

bool rozmycie::zmienne_z_Wincyj(IMG* l_rgb, QImage* l_img, IMG* lu_rgb, QImage* lu_img){

    mod_img = l_img;
    mod_rgb = l_rgb;

    u_img = lu_img;
    u_rgb = lu_rgb;

    mask = MASK();
    rozmiar = 1;
    wartosc = 0;


    return 1;
}

void rozmycie::on_verticalScrollBar_rozmiar_valueChanged(int value)
{
    rozmiar = value;
}

void rozmycie::on_verticalScrollBar_wartosc_valueChanged(int value)
{   wartosc = value;

}

void rozmycie::on_pushButton_kwadrat_clicked()
{

}

void rozmycie::on_pushButton_kolo_clicked()
{

}

void rozmycie::on_pushButton_stozkek_clicked()
{

}

void rozmycie::on_pushButton_piramida_clicked()
{

}

void rozmycie::on_pushButton_Gauss_clicked()
{

}

void rozmycie::on_pushButton_ok_clicked()
{

}
