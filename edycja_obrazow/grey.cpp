#include "grey.h"
#include "ui_grey.h"

grey::grey(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::grey)
{
    ui->setupUi(this);
}

grey::~grey()
{
    delete ui;
}



void grey::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);


    QRectF target(
                    5,                //poziomo
                    25 ,               //pionowo
                    width()-10,
                    height()-30
                );
    paint.drawImage(target, mod_img);

    update();
}

//fun do kom
bool grey::zmienne_z_Wincyj(QImage* l_u_img, IMG* l_u_rgb){
    img = l_u_img;
    rgb = l_u_rgb;

    mod_img = *img;

    return 1;
}

//interfejs
void grey::on_pushButton_srednie_clicked()
{
    mod_rgb = mod_rgb.Grey_Srednia(rgb);
    mod_img = mod_rgb.Make_img_from_RGB(mod_rgb);
}

void grey::on_pushButton_YUV_clicked()
{
    mod_rgb = mod_rgb.Grey_z_YUV(rgb);
    mod_img = mod_rgb.Make_img_from_RGB(mod_rgb);
}


void grey::on_pushButton_ok_clicked()
{
    *img = mod_rgb.Make_img_from_RGB(mod_rgb);
    //*rgb = mod_rgb.wytnij(&mod_rgb,0,0,mod_rgb.szer, mod_rgb.wys);
    rgb->Make_RGB_from_img(*img, *rgb);
}
