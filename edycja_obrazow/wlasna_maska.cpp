#include "wlasna_maska.h"
#include "ui_wlasna_maska.h"

wlasna_maska::wlasna_maska(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::wlasna_maska)
{
    ui->setupUi(this);
}

wlasna_maska::~wlasna_maska()
{
    delete ui;
}


void wlasna_maska::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);


    update();
}


//fun do kom
bool wlasna_maska::zmienne_z_Wincyj(IMG* l_rgb, QImage* l_img, IMG* lu_rgb, QImage* lu_img){

    wyn_rgb = l_rgb;
    u_rgb = lu_rgb;
    wyn_img = l_img;
    u_img = lu_img;

    mod_mask = new MASK;

    wys = 1;
    szer = 1;
    x = 0;
    y = 0;

    return 1;
}

void wlasna_maska::on_spinBox_wys_valueChanged(int arg1)
{
    if(arg1 % 2)    wys = arg1;
}

void wlasna_maska::on_spinBox_szer_valueChanged(int arg1)
{
    if(arg1 % 2)    szer = arg1;

}

void wlasna_maska::on_pushButton_buduj_clicked()
{
    mod_mask = new MASK(wys,szer);
    //tworzenie okienek lcd
    lcd.resize(wys);
    for(int i = 0; i<wys; i++){
        lcd[i].resize(szer);
        for(int j = 0; j<szer; j++){
            lcd[i][j] = new QLCDNumber(this);

             int rozm = 30;
            (*lcd[i][j]).setSegmentStyle(QLCDNumber::Filled);
            (*lcd[i][j]).setGeometry(10+rozm*i,50 + rozm* j,rozm,rozm);
            (*lcd[i][j]).setDigitCount(3);
            (*lcd[i][j]).setSegmentStyle(QLCDNumber::Flat);
            (*lcd[i][j]).display(0);
            (*lcd[i][j]).show();


        }
    }
}

void wlasna_maska::on_spinBox_y_valueChanged(int arg1)
{
    if(arg1 < wys)  y = arg1;
    else y = 0;
}

void wlasna_maska::on_spinBox_x_valueChanged(int arg1)
{
    if(arg1 < szer) x = arg1;
    else x = 0;
}

void wlasna_maska::on_spinBox_wartosc_valueChanged(int arg1)
{
    if(x < szer && y < wys){
        mod_mask->zmien_element(arg1,x,y);
        (*lcd[x][y]).display(arg1);
    }

}

void wlasna_maska::on_pushButton_zatwierdz_clicked()
{
    mod_mask->obl_sume_mask();
    IMG pom(mod_mask->szer/2, mod_mask->wys/2, u_rgb);
    pom = wyn_rgb->Make_rgb_with_mask(&pom, mod_mask);
    *wyn_rgb = IMG(&pom, mod_mask->szer/2, mod_mask->wys/2);
    *wyn_img = wyn_rgb->Make_img_from_RGB(wyn_rgb);
}
