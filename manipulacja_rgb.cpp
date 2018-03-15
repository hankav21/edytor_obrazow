#include "manipulacja_rgb.h"
#include "ui_manipulacja_rgb.h"

#include "klasy_miedzyplikowe.h"

manipulacja_RGB::manipulacja_RGB(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::manipulacja_RGB)
{
    ui->setupUi(this);
}

manipulacja_RGB::~manipulacja_RGB()
{
    delete ui;
}

//f do kom
bool manipulacja_RGB::zmienne_z_Wincyj(int* lR, int* lG, int* lB, IMG* l_u_rgb, QImage* l_u_img, QImage* l_r_img, QImage* l_g_img, QImage* l_b_img){
    if(lR == NULL || lG == NULL || lB == NULL)  return 0;

    r = lR;
    g = lG;
    b = lB;
    
    u_img = l_u_img;
    u_rgb = l_u_rgb;

    r_img = l_r_img;
    g_img = l_g_img;
    b_img = l_b_img;

    *r_img = u_rgb->Make_img_from_RGB_Upr(u_rgb, *r, 0, 0);
    *g_img = u_rgb->Make_img_from_RGB_Upr(u_rgb, 0, *g, 0);
    *b_img = u_rgb->Make_img_from_RGB_Upr(u_rgb, 0, 0, *b);

    return 1;
}


//interfejs

void manipulacja_RGB::on_spinBoxR_valueChanged(int arg1)
{
    //MainWindow::f1();
    //img_R = Make_img_from_RGB_Upr(U_rgb,ui->R->value(),0,0);
    *r = arg1;
    *r_img = u_rgb->Make_img_from_RGB_Upr(u_rgb, *r, 0, 0);
    *u_img = u_rgb->Make_img_from_RGB_Upr(u_rgb,*r, *g, *b);
    ui->RSlider->setValue(arg1);

}

void manipulacja_RGB::on_RSlider_valueChanged(int value)
{
    *r = value;
    ui->spinBoxR->setValue(value);
    //R_img = Make_img_from_RGB_Upr(U_rgb,ui->R->value(),0,0);
    //img_RGB = Make_img_from_RGB_Upr(U_rgb,ui->R->value(), ui->G->value(), ui->B->value());

}

void manipulacja_RGB::on_spinBoxG_valueChanged(int arg1)
{
    *g = arg1;
    *g_img = u_rgb->Make_img_from_RGB_Upr(u_rgb, 0, *g, 0);
    *u_img = u_rgb->Make_img_from_RGB_Upr(u_rgb,*r, *g, *b);
    ui->GSlider->setValue(arg1);

}

void manipulacja_RGB::on_GSlider_valueChanged(int value)
{
    *g = value;
    ui->spinBoxG->setValue(value);

}

void manipulacja_RGB::on_spinBoxB_valueChanged(int arg1)
{
    *b = arg1;
    *b_img = u_rgb->Make_img_from_RGB_Upr(u_rgb, 0, 0, *b);
    *u_img = u_rgb->Make_img_from_RGB_Upr(u_rgb,*r, *g, *b);
    ui->BSlider->setValue(arg1);

}

void manipulacja_RGB::on_BSlider_valueChanged(int value)
{
    *b = value;
    ui->spinBoxB->setValue(value);

}
