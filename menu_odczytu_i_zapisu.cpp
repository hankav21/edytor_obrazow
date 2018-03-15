#include "menu_odczytu_i_zapisu.h"
#include "ui_menu_odczytu_i_zapisu.h"

menu_odczytu_i_zapisu::menu_odczytu_i_zapisu(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::menu_odczytu_i_zapisu)
{
    ui->setupUi(this);
}

menu_odczytu_i_zapisu::~menu_odczytu_i_zapisu()
{
    delete ui;
}

//.......Funkcje

bool menu_odczytu_i_zapisu:: spr_rozszerzenie(const QString s, const QString r)
{
    if(s.length() < r.length()) return 0;
    short j = 0;
    for(int i = s.length() - r.length(); i < s.length(); i++)
            if(s[i]!=r[j++])    return 0;
    return 1;
}

bool menu_odczytu_i_zapisu:: spr_czy_img(const QString path)
{
    if(!spr_rozszerzenie(path, ".rgb"))
        if(!spr_rozszerzenie(path, ".jpg"))
            if(!spr_rozszerzenie(path, ".bmp"))
                 if(!spr_rozszerzenie(path, ".jpeg"))
                    if(!spr_rozszerzenie(path, ".jpe"))
                        if(!spr_rozszerzenie(path, ".dib"))
                            if(!spr_rozszerzenie(path, ".png")) return 0;
    return 1;
}

bool menu_odczytu_i_zapisu:: Write_RGB_file(const char* name, IMG rgb)
{
    std::fstream f(name, std::fstream::out);
//qDebug() << f.is_open() << " Write";
    if (f.is_open() == 0)  return 0;

    f << "rgb\n" << rgb.szer << " " << rgb.wys << "\n";

    for(int i = 0; i < rgb.wys; i++)
        for(int j=0; j < rgb.szer; j++)
        {
            f << rgb.rgb[i * rgb.szer + j].r << " ";
            f << rgb.rgb[i * rgb.szer + j].g << " ";
            f << rgb.rgb[i * rgb.szer + j].b << " ";
        }

    f.close();

    return 1;
}

bool menu_odczytu_i_zapisu:: Read_RGB_file(const char* name, IMG& rgb)
{
    std::fstream f(name, std::fstream::in);
   // qDebug() << f.is_open() << " Read";
    if (f.is_open() == 0)  return 0;

    std::string head;
    f >> head;
    if(head != "rgb")   return 0;

    f >> rgb.szer >> rgb.wys;

    rgb.rgb.resize(rgb.szer * rgb.wys);

    for(int i = 0; i < rgb.wys; i++)
        for(int j=0; j < rgb.szer; j++)
        {
            f >> rgb.rgb[i * rgb.szer + j].r;
            f >> rgb.rgb[i * rgb.szer + j].g;
            f >> rgb.rgb[i * rgb.szer + j].b;

        }
    f.close();

    return 1;
}



//.......Funkcje do komunikacji pomiędzy klasami

bool menu_odczytu_i_zapisu:: zmienne_z_MainWindow(struct IMG* rgb, QImage* img){
    if(rgb == NULL || img == NULL)  return 0;

    U_rgb = rgb;
    U_img = img;

    return 1;
}

bool menu_odczytu_i_zapisu:: zaktualizuj_MainWindow(struct IMG* rgb, QImage* img){
    if(rgb == NULL || img == NULL)  return 0;

    rgb = U_rgb;
    img = U_img;

    return 1;
}

bool menu_odczytu_i_zapisu:: Img_from_User_img(QImage& img, IMG& rgb)
{
    if(!spr_czy_img(path))  return 0;

    rgb.rgb.clear();

    if(!img.load((path.toStdString()).c_str())) return 0;

    if(!rgb.Make_RGB_from_img(img, rgb)) return 0;

    return 1;
}

//.......Przyciski

void menu_odczytu_i_zapisu::on_textEdit_textChanged(const QString &arg1)
{
    path = arg1;
}

void menu_odczytu_i_zapisu::on_pushButton_sciezka_clicked()
{
    //robi rzecz ze recznie mozesz wyklikac scizke
    path = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*)"));

    ui->textEdit->setText(path);
}

void menu_odczytu_i_zapisu::on_pushButton_Wczytaj_clicked()
{
    if(spr_rozszerzenie(path,".txt")){
        //załaduj z txt
        Read_RGB_file((path.toStdString()).c_str(), *U_rgb);
    }else if (spr_czy_img(path)){
        Img_from_User_img(*U_img, *U_rgb);

    }

}
