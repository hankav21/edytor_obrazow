#include "podglad.h"
#include "ui_podglad.h"

Podglad::Podglad(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::Podglad)
{
    ui->setupUi(this);
}

Podglad::~Podglad()
{
    delete ui;
}

void Podglad::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);

//    QRectF target(
//                    -mask->szer,                //poziomo
//                    //- mask->wys ,               //pionowo
//                    width() + mask->szer,
//                    height() + mask->wys
//                );
    QRectF target(
                    0,                //poziomo
                    0 ,               //pionowo
                    width(),
                    height()
                );
    paint.drawImage(target,*u_img_pow);
    update();
}


//...........fun do komunikacji pomiedzy plikami
bool Podglad:: zmienne_z_Wincyj(QImage* l_img, MASK* l_mask){
    if(l_img == NULL || l_mask == NULL)   return 0;

    u_img_pow = l_img;
    mask = l_mask;

    return 1;
}
