#include "hsv.h"
#include "ui_hsv.h"

hsv::hsv(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::hsv)
{
    ui->setupUi(this);
}

hsv::~hsv()
{
    delete ui;
}

//fun do kom
bool hsv::zmienne_z_Wincyj(QImage* l_u_img, IMG* l_u_rgb){
    img = l_u_img;
    rgb = l_u_rgb;

    mod_img = *img;
    mod_hsv = new IMG_HSV(&mod_rgb);

    return 1;
}

//fun
bool hsv::akcent(IMG_HSV *hsv, RGB *color, int range){
    if(hsv == NULL || color == NULL || range > 255 || range < 0)    return 0;

    for(int i = 0; i < hsv->wys; ++i){
        for(int j = 0; j < hsv->szer; ++j){
            HSV akcent_hsv;
            akcent_hsv.get_hsv_from_rgb(color);
            int h1 = (akcent_hsv.h - range/2 + 360) % 360,
                h2 = (akcent_hsv.h + range/2 + 360) % 360;
            //h1, h2 = (h_akcent -/+ range/2 +360) mod 360 == zakres
            if(hsv->hsv[i * hsv->szer + j].h > h2 &&
               hsv->hsv[i * hsv->szer + j].h < h1){

                RGB change;
                change = akcent_hsv.get_rgb_from_hsv(&hsv->hsv[i * hsv->szer + j]);
                change = change.Grey_z_YUV(&change);

                hsv->hsv[i * hsv->szer + j] = akcent_hsv.get_hsv_from_rgb(&change);
            }


        }
    }
    return 1;
}

//interfejs
void hsv::on_modyfikacje_tabBarClicked(int index)
{

}

void hsv::on_PushButton_ok_clicked()
{

    *img = mod_rgb.Make_img_from_RGB(mod_rgb);
    //*rgb = mod_rgb.wytnij(&mod_rgb,0,0,mod_rgb.szer, mod_rgb.wys);
    rgb->Make_RGB_from_img(*img, *rgb);
}
