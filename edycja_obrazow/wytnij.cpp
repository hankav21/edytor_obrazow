#include "wytnij.h"
#include "ui_wytnij.h"

wytnij::wytnij(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::wytnij)
{
    ui->setupUi(this);
}

wytnij::~wytnij()
{
    delete ui;
}

void wytnij::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);


    //tryb podglądu, gdzie widzimy prostokąt pokazujący obszar który zostawimy
    float skalaX = (width() -10)/(mod_rgb->szer * 1.0f),
        skalaY =   (height()-30 -10)/(mod_rgb->wys * 1.0f);

    QRectF target(
                    0,                //poziomo
                    30 ,               //pionowo
                    mod_rgb->szer * skalaX,
                    mod_rgb->wys * skalaY
                );
    paint.drawImage(target, *mod_img);

    //paint.setPen(QColor(0,0,0));
    paint.drawRect(X * skalaX,
                   Y * skalaY + 30,
                   Szer * skalaX,
                   Wys * skalaY
                   );
    // // //dodatkowy biały prostokąt
    // paint.setPen(QColor(225,225,225));
     //paint.drawPixmap(0,0,50,50, QPixmap(15,100));
 //    paint.drawRect(X * skalaX + 1,
 //                   Y * skalaY + 30 + 1,
 //                   Szer * skalaX + 1,
 //                   Wys * skalaY + 1
 //                   );


//    //tryb podglądy gdzie pokazuje sie tylko wyciety obszar
//    QRectF target(
//                       0,                //poziomo
//                       30 ,               //pionowo
//                       width()-1,
//                       height()-1
//                   );
//    paint.drawImage(target, mod_img->copy(X,Y,Szer,Wys));


    update();
}


//fun kom
bool wytnij::zmienne_z_Wincyj(QImage* l_mod_img, IMG* l_mod_rgb){
    if(l_mod_img == NULL || l_mod_rgb == NULL)  return 0;

    mod_img = l_mod_img;
    mod_rgb = l_mod_rgb;

    X = 0;
    Y = 0;
    Wys = mod_rgb->wys;
    Szer = mod_rgb->szer;

    ui->spinBox_X->setValue(X);
    ui->spinBox_Y->setValue(Y);
    ui->spinBox_wys->setValue(Wys);
    ui->spinBox_szer->setValue(Szer);

    return 1;
}

void wytnij::zatwierdz(){
    if(Wys + Y > mod_rgb->wys || Wys+Y <= 0) return;
    if(Szer + X > mod_rgb->szer || Szer+X <= 0) return;
    *mod_rgb = mod_rgb->wytnij(mod_rgb,X,Y,Wys,Szer);
    *mod_img = mod_rgb->Make_img_from_RGB(mod_rgb);
    //aktualizuje zeby bylo ladne w okienku
    X = 0;
    Y = 0;
    Wys = mod_rgb->wys;
    Szer = mod_rgb->szer;
    ui->spinBox_szer->setValue(Szer);
    ui->spinBox_wys->setValue(Wys);
    ui->spinBox_X->setValue(X);
    ui->spinBox_Y->setValue(Y);
}


//interfejs
void wytnij::on_spinBox_X_valueChanged(int arg1)
{
    if(arg1 + Szer > mod_rgb->szer) return;
    X = arg1;
}

void wytnij::on_spinBox_Y_valueChanged(int arg1)
{
    if(arg1 + Wys > mod_rgb->wys) return;
    Y = arg1;
}

void wytnij::on_spinBox_wys_valueChanged(int arg1)
{
    if(arg1 + Y > mod_rgb->wys) return;
    Wys = arg1;
}

void wytnij::on_spinBox_szer_valueChanged(int arg1)
{
    if(arg1 + X > mod_rgb->szer) return;
    Szer = arg1;
}

void wytnij::on_pushButton_clicked()
{
    zatwierdz();
}
