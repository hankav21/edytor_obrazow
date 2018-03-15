#include "manipulacja_rpg.h"
#include "ui_manipulacja_rpg.h"

Manipulacja_RPG::Manipulacja_RPG(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::Manipulacja_RPG)
{
    ui->setupUi(this);
}

Manipulacja_RPG::~Manipulacja_RPG()
{
    delete ui;
}


//funkcje


//funkcje do komunikacji miedzy klasami

//bool Manipulacja_RPG::zmienne_z_okno_rgb(int* r, int* g, int* b){
//    if(R == NULL || G == NULL || B == NULL) return 0;

//    &R = r;
//    &G = g;
//    &B = b;

//    return 1;
//}

//przyciski
void Manipulacja_RPG::on_spinBoxR_valueChanged(int arg1)
{
//    R_img = Make_img_from_RGB_Upr(U_rgb,ui->spinBoxR->value(),0,0);
//    U_img = Make_img_from_RGB_Upr(U_rgb,ui->spinBoxR->value(), ui->spinBoxG->value(), ui->spinBoxB->value());
//    ui->SliderR->setValue(arg1);
}

void Manipulacja_RPG::on_SliderR_valueChanged(int value)
{
//    ui->spinBoxR->setValue(value);
//    R_img = Make_img_from_RGB_Upr(U_rgb,ui->spinBoxR,0,0);
//    U_img = Make_img_from_RGB_Upr(U_rgb,ui->spinBoxR->value(), ui->spinBoxG->value(), ui->spinBoxB->value());

}


