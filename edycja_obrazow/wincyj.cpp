#include "wincyj.h"
#include "ui_wincyj.h"

Wincyj::Wincyj(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::Wincyj)
{
    ui->setupUi(this);
    R = 225;
    G = 225;
    B = 225;

}

Wincyj::~Wincyj()
{
    delete ui;
}

// f do kom pom kl
bool Wincyj::zmienne_z_MainWindow(IMG* l_u_rgb, QImage* l_u_img){
    //oryginały do zaktualizowania po zatwierdzeniu
    u_img = l_u_img;
    u_rgb = l_u_rgb;

    //do filtrow
    mod_img = QImage(*l_u_img);
    mod_rgb = new IMG(l_u_rgb);

    return 1;
}



//interfejs
void Wincyj::on_pushButton_manipulacjaRGB_clicked()
{
   // okno_manipulacjaRGB.show();
    widget_manipulacjaRGB = new manipulacja_RGB(this);
    widget_manipulacjaRGB->show();
    widget_manipulacjaRGB->zmienne_z_Wincyj(&R,&G,&B, &mod_rgb, &mod_img, &R_img, &G_img, &B_img);
}

void Wincyj::on_pushButton_Podglad_clicked()
{
    widget_podglad = new Podglad(this);
    widget_podglad->show();
    widget_podglad->zmienne_z_Wincyj(&mod_img, &mask);
}

void Wincyj::on_pushButton_Zatwierdz_clicked()
{
    //zeby w okieneczkach RGB było na bieżaco
    //B_img = u_rgb->Make_img_from_RGB_Upr(mod_rgb, 0, 0, B);
    //G_img = u_rgb->Make_img_from_RGB_Upr(mod_rgb, 0, G, 0);
    //R_img = u_rgb->Make_img_from_RGB_Upr(mod_rgb, R, 0, 0);
    //mod_img = u_rgb->Make_img_from_RGB_Upr(&mod_rgb, R, G, B);
    //zatwierdzenie zmian z maski
    //new IMG(&mod_rgb);//&mod_rgb;

    *u_img = u_rgb->Make_img_from_RGB_Upr(&mod_rgb, R, G, B);//new QImage(mod_img);//&mod_img;
    u_rgb->Make_RGB_from_img(*u_img, *u_rgb);
}

void Wincyj::on_pushButton_Sobel_clicked()
{
    widget_sobel = new Sobel(this);
    widget_sobel->show();
    widget_sobel->zmienne_z_Wincyj(&mask, &mod_rgb, &mod_img, u_rgb, u_img);
}

void Wincyj::on_pushButton_Podglad_RGB_clicked()
{
    widget_oknoRGB = new Okno_RGB(this);
    widget_oknoRGB->show();
    widget_oknoRGB->zmienne_z_Wincyj(&mod_rgb,&mod_img,&R,&G,&B,&R_img, &G_img, &B_img, &mask);
}

void Wincyj::on_pushButton_Sobel_Wytnij_clicked()
{
    widget_wytnij = new wytnij(this);
    widget_wytnij->show();
    widget_wytnij->zmienne_z_Wincyj(&mod_img, &mod_rgb);
}
