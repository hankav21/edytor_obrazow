#include "okno_rgb.h"
#include "ui_okno_rgb.h"

Okno_RGB::Okno_RGB(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::Okno_RGB)
{
    ui->setupUi(this);
}

Okno_RGB::~Okno_RGB()
{
    delete ui;
}


void Okno_RGB::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);

//    QRectF target(10, 30, width()-20, height()-40);
//    paint.drawImage(target,U_img);
    int wys1, szer1;
    QRectF target, target2, target3;
    if(pionowo){
        //wys/3 + 20 za przycisk + 10*2*2 na kazda str
        wys1 = (height()-60)/3;
        szer1 = width()-20;
        //R
        target = QRectF(10, 30, szer1, wys1);
        //G
        target2 = QRectF(10,  wys1+10+30, szer1, wys1);
        //B
        target3 = QRectF(10, 2*wys1+10+30+10, szer1, wys1);
    } else{
        //na kazda str 10 i na przycisk 20
        wys1 = height()-20-20;
        //na kazda str 10*2*2
        szer1 = (width()-40)/3;
        //R
        target = QRectF(10, 30, szer1, wys1);
        //G
        target2 = QRectF(szer1 +20, 30, szer1, wys1);
        //B
        target3 = QRectF(2*szer1+30, 30, szer1, wys1);
      }
       paint.drawImage(target,*r_img);
       paint.drawImage(target2,*g_img);
       paint.drawImage(target3,*b_img);

    update();
}


//.......Funkcje do komunikacji pomiędzy klasami

bool Okno_RGB:: zmienne_z_Wincyj(struct IMG* rgb, QImage* img, int* lR, int* lG, int* lB, QImage* lr_img, QImage* lg_img, QImage* lb_img, MASK* l_mask){
    if(rgb == NULL || img == NULL)  return 0;

    U_rgb = rgb;
    U_img = img;

    r = lR;
    g = lG;
    b = lB;

    r_img = lr_img;
    g_img = lg_img;
    b_img = lb_img;

    *r_img = U_rgb->Make_img_from_RGB_Upr(U_rgb,*r,0,0);
    *g_img = U_rgb->Make_img_from_RGB_Upr(U_rgb,0,*g,0);
    *b_img = U_rgb->Make_img_from_RGB_Upr(U_rgb,0,0,*b);

    return 1;
}


//........przyciski
void Okno_RGB::on_pushButton_clicked()
{
   pionowo = !pionowo;
}
