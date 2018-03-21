#include "rozmycie.h"
#include "ui_rozmycie.h"

rozmycie::rozmycie(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::rozmycie)
{
    ui->setupUi(this);
}

rozmycie::~rozmycie()
{
    delete ui;
}

//funkcje do kom
bool rozmycie::zmienne_z_Wincyj(IMG* l_rgb, QImage* l_img, IMG* lu_rgb, QImage* lu_img){

    mod_img = l_img;
    mod_rgb = l_rgb;

    u_img = lu_img;
    u_rgb = lu_rgb;

    mask = MASK(3,3);
    rozmiar = 3;
    wartosc = 0;

    butt = ui->pushButton_kwadrat;

    aktualizuj_lcd();

    butt->click();

    return 1;
}

//funkcje
bool rozmycie::aktualizuj_lcd(){

    //czyszczenie ekranu z obecnych lcd
    for(int i = 0; i < lcd.size(); i++)
        for(int j = 0; j < lcd[0].size(); j++)
            (*lcd[i][j]).setVisible(0);


    //tworzenie okienek lcd
    lcd.resize(rozmiar);
    for(int i = 0; i<rozmiar; i++){
        lcd[i].resize(rozmiar);
        for(int j = 0; j<rozmiar; j++){
            lcd[i][j] = new QLCDNumber(this);

             int rozm = 30;
            (*lcd[i][j]).setSegmentStyle(QLCDNumber::Filled);
            (*lcd[i][j]).setGeometry(90+rozm*i,10 + rozm* j,rozm,rozm);
            (*lcd[i][j]).setDigitCount(3);
            (*lcd[i][j]).setSegmentStyle(QLCDNumber::Flat);
            (*lcd[i][j]).display(mask.mask[i][j]);
            (*lcd[i][j]).show();


        }
    }

    return 1;
}

bool rozmycie::aktualizuj_wartosci_lcd(){
    if(rozmiar != lcd.size())   return 0;
    //if(rozmiar != sizeof(tab))   return 0;

    for(int i = 0; i<rozmiar; i++)
        for(int j = 0; j<rozmiar; j++)
            (*lcd[i][j]).display(mask.mask[i][j]);

}

bool rozmycie::kwadrat(){

        mask = MASK(rozmiar, rozmiar);

        for(int i = 0; i < rozmiar; i++){

            for(int j = 0; j < rozmiar; j++){
                mask.zmien_element(1,i,j);
            }
        }

        mask.zmien_element(wartosc, rozmiar/2, rozmiar/2);
        aktualizuj_wartosci_lcd();
        aktualizuj_lcd();

    return 1;
}

bool rozmycie::kolo(){

    mask = MASK(rozmiar, rozmiar);
    int a,x,y, r;
    a = rozmiar/2;
    r = sqr(a);
    for(int i = 0; i < rozmiar; i++){
        y = sqr(i-a);
        for(int j = 0; j < rozmiar; j++){
            x = sqr(j-a);
            if(x+y <= r)
                mask.zmien_element(1,i,j);
            else
                mask.zmien_element(0,i,j);
        }
    }

    aktualizuj_wartosci_lcd();
    aktualizuj_lcd();

    return 1;
}

bool rozmycie::piramida(){
    int roz = rozmiar/2;
    mask = MASK(rozmiar, rozmiar);
    mask.zmien_element(wartosc, roz, roz);
    mask.zmien_element(1,0,0);

    mask.zmien_element(sqrt(wartosc), 0, roz);
    mask.zmien_element(sqrt(wartosc), roz, 0);

    int pom = mask.mask[0][roz]/(roz),
        pom2 = mask.mask[roz][roz]/(roz);
    //qDebug() << "pom pom2" << pom << pom2;

    for(int i = 1; i < rozmiar/2; i++){
        //krok do sqrt(wartosci)
        mask.zmien_element(pom + mask.mask[0][i-1], 0, i);
       // mask.zmien_element(pom*i, 0, rozmiar - i - 1);
        mask.zmien_element(mask.mask[0][i], i, 0);
        //mask.zmien_element(pom*i, rozmiar - i - 1, 0);
        //krok so
        mask.zmien_element(pom2 + mask.mask[i-1][roz], i, roz);
        //mask.zmien_element(pom2 * i, roz, i);
        mask.zmien_element(mask.mask[i][roz], roz, i);
        //mask.zmien_element(pom2 * i, roz , rozmiar - i -1 );
    }

    for(int i = roz - 1; i > 0; i--){
        for(int j = roz - 1; j >= i; j--){
            int wart = (mask.mask[i][j+1] + mask.mask[i+1][j])/3;
            mask.zmien_element(wart ,i, j);
            mask.zmien_element(wart ,j, i);
        }
    }

    //kopiuj na reszte
    for(int i = 0; i<=roz; i++ )
        for(int j = 0; j<=roz; j++ ){
            mask.zmien_element(mask.mask[i][j], rozmiar - j - 1,  rozmiar - i -1);
            mask.zmien_element(mask.mask[i][j], j,  rozmiar - i -1);
            mask.zmien_element(mask.mask[i][j], rozmiar - j - 1, i);
        }


    aktualizuj_wartosci_lcd();
    aktualizuj_lcd();
    return 1;
}


//interfejs
void rozmycie::on_verticalScrollBar_rozmiar_valueChanged(int value)
{
    rozmiar = value;

    butt->click();
}

void rozmycie::on_verticalScrollBar_wartosc_valueChanged(int value)
{   wartosc = value;
    butt->click();
    //aktualizuj_wartosci_lcd();
}

void rozmycie::on_pushButton_kwadrat_clicked()
{
    kwadrat();
    butt = ui->pushButton_kwadrat;
}

void rozmycie::on_pushButton_kolo_clicked()
{
    kolo();
    butt = ui->pushButton_kolo;
}

void rozmycie::on_pushButton_stozkek_clicked()
{

}

void rozmycie::on_pushButton_piramida_clicked()
{
    piramida();
    butt = ui->pushButton_piramida;
}

void rozmycie::on_pushButton_Gauss_clicked()
{

}

void rozmycie::on_pushButton_ok_clicked()
{
    mask.obl_sume_mask();
    IMG pom(mask.szer, mask.wys, u_rgb);
    pom = mod_rgb->Make_rgb_with_mask(&pom, &mask);
    *mod_rgb = IMG(&pom, mask.szer, mask.wys);
    *mod_img = mod_rgb->Make_img_from_RGB(mod_rgb);

//    *mod_rgb = mod_rgb->Make_rgb_with_mask(u_rgb,&mask);
//    *mod_img = mod_rgb->Make_img_from_RGB(mod_rgb);
}
