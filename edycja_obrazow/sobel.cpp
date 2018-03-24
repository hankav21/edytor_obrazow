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
bool Sobel::zmienne_z_Wincyj( IMG* l_rgb, QImage* l_img, IMG* lu_rgb, QImage* lu_img){

    int tab[] = {0,0,0,
                  0,0,0,
                  0,0,0};

//
//    int tab2[] =  {0,0,0,
//                   0,0,0,
//                   0,0,0};

//    wyn_mask = l_mask;
//    wyn_mask->zmien(tab2,3,3);
    mask = MASK(3,3);

    wyn_rgb = l_rgb;
    wyn_img = l_img;

    u_rgb = lu_rgb;
    u_img = lu_img;

    lcd[0][0] =  ui->lcdNumber_0;
    lcd[0][1] =  ui->lcdNumber_1;
    lcd[0][2] =  ui->lcdNumber_2;
    lcd[1][0] =  ui->lcdNumber_3;
    lcd[1][1] =  ui->lcdNumber_4;
    lcd[1][2] =  ui->lcdNumber_5;
    lcd[2][0] =  ui->lcdNumber_6;
    lcd[2][1] =  ui->lcdNumber_7;
    lcd[2][2] =  ui->lcdNumber_8;

    v = ui->horizontalScrollBar->value();


//    butt[0] = ui->pushButton_0;
//    butt[1] = ui->pushButton_45;
//    butt[2] = ui->pushButton_90;
//    butt[3] = ui->pushButton_135;
//    butt[4] = ui->pushButton_180;
//    butt[5] = ui->pushButton_225;
//    butt[6] = ui->pushButton_270;
//    butt[7] = ui->pushButton_315;

    butt = ui->pushButton_Sobel;
    kat = ui->pushButton_0;

    //ui->horizontalScrollBar->valueChanged(v);
    butt->click();
    kat->click();



    return 1;
}

void Sobel::aktualizuj_zmienne_z_Wincyj(){
//    int tab_pom[9];
//    for(int i = 0; i<3; i++)
//        for(int j = 0; j<3; i++)
//            tab_pom[i] = mask.mask[i];
//    mask.zmien(tab_pom, 3,3);
    mask.obl_sume_mask();
    IMG pom(mask.szer, mask.wys, u_rgb);
    pom = wyn_rgb->Make_rgb_with_mask(&pom, &mask);
    *wyn_rgb = IMG(&pom, mask.szer, mask.wys);
    *wyn_img = wyn_rgb->Make_img_from_RGB(wyn_rgb);
}
//fun
void Sobel::aktualizuj(){
   //kat->click();
    for(int i = 0; i<mask.wys; i++)
        for(int j = 0; j<mask.szer; j++)
            lcd[i][j]->display(mask.mask[i][j]);
   // aktualizuj_zmienne_z_Wincyj();

}

bool Sobel::sobel(){

    return 1;
}

bool Sobel::laplace(){

    return 1;
}

bool Sobel::prewitt(){

    return 1;
}

//interfejs
void Sobel::on_pushButton_0_clicked()
{
    kat = ui->pushButton_0;
    if(butt == ui->pushButton_Sobel){
        qDebug() <<"Sobel";
        int tab[]={-1,         0,      1,
                   -v,         0,      v,
                   -1,         0,      1};
        mask.wyp_mask(tab);
    }
    else if(butt == ui->pushButton_Laplace){
        //e
        int tab[]={-1,         0,      1,
                   -1,         1,      1,
                   -1,         0,      1};
        mask.wyp_mask(tab);
    }else if(butt == ui->pushButton_Laplasjany){
        qDebug() <<"laplasjany";
        //czterospojny 1
        int tab[]={0,      -1,      0,
                  -1,       v,      -1,
                   0,      -1,      0};
        mask.wyp_mask(tab);
    }else if(butt == ui->pushButton_Sobel_Gradien_Robertsa){
        //ni mo
        int tab[]={-3,       -3,     5,
                   -3,      0,      5,
                   -3,     -3,      5};
        mask.wyp_mask(tab);
    }




    aktualizuj();


}

void Sobel::on_pushButton_45_clicked()
{
    kat = ui->pushButton_45;
    if(butt == ui->pushButton_Sobel){
        int tab[]={0,       1,      v,
                   -1,      0,      1,
                   -v,     -1,      0};
        mask.wyp_mask(tab);
    }
    else if(butt == ui->pushButton_Laplace){
        int tab[]={0,       1,      v,
                   -1,      v,      1,
                   -v,     -1,      0};
        mask.wyp_mask(tab);
    }else if(butt == ui-> pushButton_Laplasjany){
        //osmiospojny
        int tab[]={-1,      -1,      -1,
                   -1,       v,      -1,
                   -1,      -1,      -1};
        mask.wyp_mask(tab);
    }else if(butt == ui->pushButton_Sobel_Gradien_Robertsa){
        int tab[]={0,       0,      0,
                   1,      0,      0,
                   0,     -1,      0};
        mask.wyp_mask(tab);
    }



    aktualizuj();
}


void Sobel::on_pushButton_90_clicked(){
    kat = ui->pushButton_90;
    if(butt == ui->pushButton_Sobel){
      int tab[]={1,         v,        1,
               0,           0,        0,
               -1,         -v,        -1};
      mask.wyp_mask(tab);
    }
    else if(butt == ui->pushButton_Laplace){
          int tab[]={1,         v,        1,
                   0,           v,        0,
                   -1,         -v,        -1};
        mask.wyp_mask(tab);
    }else if(butt == ui-> pushButton_Laplasjany){
        //czterospojny 2
        int tab[]={-1,     0,      -1,
                   0,      v,       0,
                   -1,     0,      -1};
        mask.wyp_mask(tab);
    }else if(butt == ui->pushButton_Sobel_Gradien_Robertsa){
        int tab[]={0,       1,      v,
                   -1,      0,      1,
                   -v,     -1,      0};
        mask.wyp_mask(tab);
    }



    aktualizuj();
}

void Sobel::on_pushButton_135_clicked()
{
    kat = ui->pushButton_135;
    if(butt == ui->pushButton_Sobel){
        int tab[]={v,         1,              0,
                   1,         0,             -1,
                   0,        -1,             -v};
        mask.wyp_mask(tab);
    }
    else if(butt == ui->pushButton_Laplace){
        int tab[]={v,         1,              0,
                   1,         v,             -1,
                   0,        -1,             -v};
        mask.wyp_mask(tab);
    }else if(butt == ui-> pushButton_Laplasjany){
        //polowa wartosci na katach
        int tab[]={-v,       1,      -v,
                   1,      2*v,      1,
                   -v,     1,      -v};
        mask.wyp_mask(tab);
    }else if(butt == ui->pushButton_Sobel_Gradien_Robertsa){
        int tab[]={0,       1,      v,
                   -1,      0,      1,
                   -v,     -1,      0};
        mask.wyp_mask(tab);
    }



    aktualizuj();
}

void Sobel::on_pushButton_180_clicked()
{
    kat = ui->pushButton_180;
    if(butt == ui->pushButton_Sobel){
        int tab[]={1,                0,             -1,
                   v,                0,             -v,
                   1,                0,             -1};
        mask.wyp_mask(tab);
    }
    else if(butt == ui->pushButton_Laplace){
        int tab[]={1,                0,             -1,
                   v,                v,             -v,
                   1,                0,             -1};
        mask.wyp_mask(tab);
    }else if(butt == ui-> pushButton_Laplasjany){
        //polowa wartosci na krzyzu
        int tab[]={1,        -v,       1,
                   -v,      2*v,      -v,
                   1,        -v,       1};
        mask.wyp_mask(tab);
    }else if(butt == ui->pushButton_Sobel_Gradien_Robertsa){
        int tab[]={0,       1,      v,
                   -1,      0,      1,
                   -v,     -1,      0};
        mask.wyp_mask(tab);
    }



    aktualizuj();
}

void Sobel::on_pushButton_225_clicked()
{
    kat = ui->pushButton_225;
    if(butt == ui->pushButton_Sobel){
        int tab[]={0,              -1,        -v,
                   1,               0,        -1,
                   v,               1,         0};
        mask.wyp_mask(tab);
    }
    else if(butt == ui->pushButton_Laplace){
        int tab[]={0,              -1,        -v,
                   1,               v,        -1,
                   v,               1,         0};
        mask.wyp_mask(tab);
    }else if(butt == ui-> pushButton_Laplasjany){
        int tab[]={0,       1,      v,
                   -1,      0,      1,
                   -v,     -1,      0};
        mask.wyp_mask(tab);
    }else if(butt == ui->pushButton_Sobel_Gradien_Robertsa){
        int tab[]={0,       1,      v,
                   -1,      0,      1,
                   -v,     -1,      0};
        mask.wyp_mask(tab);
    }


    aktualizuj();
}

void Sobel::on_pushButton_270_clicked(){
    kat = ui->pushButton_270;
    if(butt == ui->pushButton_Sobel){
        int tab[]={-1,         -v,       -1,
                    0,          0,        0,
                    1,          v,        1};
        mask.wyp_mask(tab);
    }
    else if(butt == ui->pushButton_Laplace){
        int tab[]={-1,         -v,       -1,
                    0,          v,        0,
                    1,          v,        1};
        mask.wyp_mask(tab);
    }else if(butt == ui-> pushButton_Laplasjany){
        int tab[]={0,       1,      v,
                   -1,      0,      1,
                   -v,     -1,      0};
        mask.wyp_mask(tab);
    }else if(butt == ui->pushButton_Sobel_Gradien_Robertsa){
        int tab[]={0,       1,      v,
                   -1,      0,      1,
                   -v,     -1,      0};
        mask.wyp_mask(tab);
    }


    aktualizuj();
}

void Sobel::on_pushButton_315_clicked(){
    kat = ui->pushButton_315;
    if(butt == ui->pushButton_Sobel){
        int tab[]={-v,         -1,       0,
                    -1,         0,       1,
                    0,          1,       v};
        mask.wyp_mask(tab);
    }
    else if(butt == ui->pushButton_Laplace){
        int tab[]={-v,         -1,       0,
                    -1,         v,       1,
                    0,          1,       v};
        mask.wyp_mask(tab);
    }else if(butt == ui-> pushButton_Laplasjany){
        int tab[]={0,       1,      v,
                   -1,      0,      1,
                   -v,     -1,      0};
        mask.wyp_mask(tab);
    }else if(butt == ui->pushButton_Sobel_Gradien_Robertsa){
        int tab[]={0,       1,      v,
                   -1,      0,      1,
                   -v,     -1,      0};
        mask.wyp_mask(tab);
    }


    aktualizuj();
}

void Sobel::on_horizontalScrollBar_valueChanged(int va)
{
    v = va;

    kat->click();

}

void Sobel::on_pushButton_clicked()
{
    aktualizuj_zmienne_z_Wincyj();
}

void Sobel::on_pushButton_Sobel_clicked()
{
    sobel();
    butt = ui->pushButton_Sobel;
    aktualizuj();
}



void Sobel::on_pushButton_Laplace_clicked()
{
    laplace();
    butt = ui->pushButton_Laplace;
    aktualizuj();
}

void Sobel::on_pushButton_Laplasjany_clicked()
{

    butt = ui->pushButton_Laplasjany;
    aktualizuj();
}

void Sobel::on_pushButton_Sobel_Gradien_Robertsa_clicked()
{
    butt = ui->pushButton_Sobel_Gradien_Robertsa;
    aktualizuj();
}
