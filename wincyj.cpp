#include "wincyj.h"
#include "ui_wincyj.h"

Wincyj::Wincyj(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::Wincyj)
{
    ui->setupUi(this);
    aktualizuj = 0;

}

Wincyj::~Wincyj()
{
    delete ui;
}

// f do kom pom kl
bool Wincyj::zmienne_z_MainWindow(int* lR, int* lG, int* lB, IMG* l_u_rgb, QImage* l_u_img, QImage* l_r_img, QImage* l_g_img, QImage* l_b_img){
    if(lR == NULL || lG == NULL || lB == NULL)  return 0;
qDebug() << "WIncyj klik";
    r = lR;
    g = lG;
    b = lB;
    
    u_img = l_u_img;
    r_img = l_r_img;
    g_img = l_g_img;
    b_img = l_b_img;
    u_rgb = l_u_rgb;

    //do filtrow
    mod_img = l_u_img;
    mod_rgb = l_u_rgb;
    mask = new MASK();


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

void Wincyj::on_pushButton_Podglad_clicked()
{
    widget_podglad = new Podglad(this);
    widget_podglad->show();
    widget_podglad->zmienne_z_Wincyj(mod_img, mask);
}

void Wincyj::on_pushButton_Zatwierdz_clicked()
{
    //zeby w okieneczkach RGB było na bieżaco
    *b_img = u_rgb->Make_img_from_RGB_Upr(mod_rgb, 0, 0, *b);
    *g_img = u_rgb->Make_img_from_RGB_Upr(mod_rgb, 0, *g, 0);
    *r_img = u_rgb->Make_img_from_RGB_Upr(mod_rgb, *r, 0, 0);
    *u_img = u_rgb->Make_img_from_RGB_Upr(mod_rgb,*r, *g, *b);
    //zatwierdzenie zmian z maski
    u_rgb = mod_rgb;
    u_img = mod_img;
}

void Wincyj::on_pushButton_Sobel_clicked()
{
    widget_sobel = new Sobel(this);
    widget_sobel->show();
    widget_sobel->zmienne_z_Wincyj(mask,mod_rgb,mod_img);
}
