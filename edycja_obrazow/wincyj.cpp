#include "wincyj.h"
#include "ui_wincyj.h"

Wincyj::Wincyj(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::Wincyj)
{
    ui->setupUi(this);
}

Wincyj::~Wincyj()
{
    delete ui;
}

// f do kom pom kl
bool Wincyj::zmienne_z_MainWindow(int* lR, int* lG, int* lB, IMG* l_u_rgb, QImage* l_u_img, QImage* l_r_img, QImage* l_g_img, QImage* l_b_img){
    if(lR == NULL || lG == NULL || lB == NULL)  return 0;

    r = lR;
    g = lG;
    b = lB;
    
    u_img = l_u_img;
    r_img = l_r_img;
    g_img = l_g_img;
    b_img = l_b_img;
    u_rgb = l_u_rgb;

    return 1;
}



//interfejs
void Wincyj::on_pushButton_manipulacjaRGB_clicked()
{
   // okno_manipulacjaRGB.show();
    widget_manipulacjaRGB = new manipulacja_RGB(this);
    widget_manipulacjaRGB->show();
    widget_manipulacjaRGB->zmienne_z_Wincyj(r,g,b, u_rgb, u_img, r_img, g_img, b_img);
}
