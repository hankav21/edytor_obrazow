#include "sobel.h"
#include "ui_sobel.h"

Sobel::Sobel(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::Sobel)
{
    ui->setupUi(this);
}

Sobel::~Sobel()
{
    delete ui;
}

//fun do kom
bool Sobel::zmienne_z_Wincyj(MASK* l_mask, IMG* l_rgb, QImage* l_img, IMG* lu_rgb, QImage* lu_img){

    int* tab[] = {zero,zero,zero,
                  zero,zero,zero,
                  zero,zero,zero};

    Filtr = KAT(tab);
    int tab2[] =  {0,0,0,
                   0,0,0,
                   0,0,0};

    wyn_mask = l_mask;
    wyn_mask->zmien(tab2,3,3);

    wyn_rgb = l_rgb;
    wyn_img = l_img;

    u_rgb = lu_rgb;
    u_img = lu_img;

    lcd[0] =  ui->lcdNumber_0;
    lcd[1] =  ui->lcdNumber_1;
    lcd[2] =  ui->lcdNumber_2;
    lcd[3] =  ui->lcdNumber_3;
    lcd[4] =  ui->lcdNumber_4;
    lcd[5] =  ui->lcdNumber_5;
    lcd[6] =  ui->lcdNumber_6;
    lcd[7] =  ui->lcdNumber_7;
    lcd[8] =  ui->lcdNumber_8;

    *value = ui->horizontalScrollBar->value();
    *minus_value = - (*(value));


//    butt[0] = ui->pushButton_0;
//    butt[1] = ui->pushButton_45;
//    butt[2] = ui->pushButton_90;
//    butt[3] = ui->pushButton_135;
//    butt[4] = ui->pushButton_180;
//    butt[5] = ui->pushButton_225;
//    butt[6] = ui->pushButton_270;
//    butt[7] = ui->pushButton_315;


    ui->pushButton_0->click();
    ui->horizontalScrollBar->valueChanged(2);


    return 1;
}

void Sobel::aktualizuj_zmienne_z_Wincyj(){
    int tab_pom[9];
    for(int i = 0; i<9; i++)
        tab_pom[i] = *Filtr.mask[i];
    wyn_mask->zmien(tab_pom, 3,3);
    *wyn_rgb = wyn_rgb->Make_rgb_with_mask(u_rgb,wyn_mask);
    *wyn_img = wyn_rgb->Make_img_from_RGB(wyn_rgb);
};

//fun
void Sobel::aktualizuj(){
    for(int i = 0; i<9; i++)
        lcd[i]->display(*Filtr.mask[i]);
    aktualizuj_zmienne_z_Wincyj();

}

//interfejs
void Sobel::on_pushButton_0_clicked()
{
    int* tab[]={minus_jeden,             zero,      jeden,
               minus_value,              zero,      value,
               minus_jeden,              zero,      jeden};

    Filtr = KAT(tab);
    aktualizuj();


}

void Sobel::on_pushButton_45_clicked()
{
    int* tab[]={zero,                 jeden,      value,
               minus_jeden,            zero,      jeden,
               minus_value,     minus_jeden,      zero};

    Filtr = KAT(tab);
    aktualizuj();
}

void Sobel::on_pushButton_90_clicked()
{
    int* tab[]={jeden,              value,              jeden,
               zero,                zero,               zero,
               minus_jeden,         minus_value,        minus_jeden};

    Filtr = KAT(tab);
    aktualizuj();
}

void Sobel::on_pushButton_135_clicked()
{
    int* tab[]={value,              jeden,              zero,
               jeden,                zero,              minus_jeden,
               zero,         minus_jeden,               minus_value};

    Filtr = KAT(tab);
    aktualizuj();
}

void Sobel::on_pushButton_180_clicked()
{
    int* tab[]={jeden,                zero,              minus_jeden,
                value,                zero,              minus_value,
                jeden,                zero,              minus_jeden};

    Filtr = KAT(tab);
    aktualizuj();
}

void Sobel::on_pushButton_225_clicked()
{
    int* tab[]={zero,                minus_jeden,       minus_value,
                jeden,               zero,              minus_jeden,
                value,               jeden,             zero};

    Filtr = KAT(tab);
    aktualizuj();
}

void Sobel::on_pushButton_270_clicked()
{
    int* tab[]={minus_jeden,         minus_value,       minus_jeden,
                zero,                zero,              zero,
                jeden,               value,             jeden};

    Filtr = KAT(tab);
    aktualizuj();
}

void Sobel::on_pushButton_315_clicked()
{
    int* tab[]={minus_value,         minus_jeden,       zero,
                minus_jeden,         zero,              jeden,
                zero,                jeden,             value};

    Filtr = KAT(tab);
    aktualizuj();
}

void Sobel::on_horizontalScrollBar_valueChanged(int value)
{
    *this->value = value;
    *this->minus_value = -value;
    aktualizuj();

}
