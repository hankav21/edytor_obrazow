#include "rozdzielczosc.h"
#include "ui_rozdzielczosc.h"

rozdzielczosc::rozdzielczosc(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::rozdzielczosc)
{
    ui->setupUi(this);
}

rozdzielczosc::~rozdzielczosc()
{
    delete ui;
}

void rozdzielczosc::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);


    QRectF target(
                    5,                //poziomo
                    50 ,               //pionowo
                    width()-10,
                    height()-55
                );
    paint.drawImage(target, mod_img);

    update();
}

//fun do kom
bool rozdzielczosc::zmienne_z_Wincyj(QImage* l_u_img, IMG* l_u_rgb){
    img = l_u_img;
    rgb = l_u_rgb;

    szer = rgb->szer;
    wys = rgb->wys;

    ui->spinBox_szer->setValue(szer);
    ui->spinBox_wys->setValue(wys);

    ratiox = 100;
    ratioy = 100;

    return 1;
}


//interfehsc
void rozdzielczosc::on_spinBox_szer_valueChanged(int arg1)
{
    szer = arg1;
}

void rozdzielczosc::on_spinBox_wys_valueChanged(int arg1)
{
    wys = arg1;
}


void rozdzielczosc::on_pushButton_sasiedztwo_clicked()
{
    //obliczenie wspólczynników powieksznia
    ratiox = (rgb->szer * 1.0f)/(szer * 1.0f);
    ratioy = (rgb->wys * 1.0f)/(wys * 1.0f);

    //przygotowanie nowego miejsca na obraz
    mod_rgb = new IMG(szer,wys);

    //zamienienie na tablice 2-wym bo juz nie wiem jak obliczac poł↓ożenie na jedno
    std:: vector<std:: vector<RGB> > pom;        //[rgb->wys][rgb->szer];
    pom.resize(rgb->wys);
    for(int i =0; i<rgb->wys; i++){
        pom[i].resize(rgb->szer);
        for(int j = 0; j<rgb->szer; j++){
            pom[i][j] =  rgb->rgb[i*rgb->szer+j];
        }

    }

    //
    for(int i = 0; i<wys; i++)
        for(int j = 0; j<szer; j++){
                int x = (int)j*ratiox,
                    y = (int)i*ratioy;
                mod_rgb.rgb[i * szer + j] = pom[y][x];

        }
    mod_img = mod_rgb.Make_img_from_RGB(mod_rgb);
}

void rozdzielczosc::on_pushButton_interpolacja_clicked()
{

}

void rozdzielczosc::on_pushButton_zatwierdz_clicked()
{
    *img = mod_rgb.Make_img_from_RGB(mod_rgb);
    *rgb = mod_rgb.wytnij(&mod_rgb,0,0,mod_rgb.szer, mod_rgb.wys);
}
