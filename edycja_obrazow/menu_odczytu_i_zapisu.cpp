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
    if(!spr_rozszerzenie(path.toLower(), ".rgb"))
        if(!spr_rozszerzenie(path.toLower(), ".jpg"))
            if(!spr_rozszerzenie(path.toLower(), ".bmp"))
                 if(!spr_rozszerzenie(path.toLower(), ".jpeg"))
                    if(!spr_rozszerzenie(path.toLower(), ".jpe"))
                        if(!spr_rozszerzenie(path.toLower(), ".dib"))
                            if(!spr_rozszerzenie(path.toLower(), ".png")) return 0;
    return 1;
}

bool menu_odczytu_i_zapisu:: Write_RGB_file(const char* name, IMG rgb)
{
    qDebug() << name;
    if(!spr_rozszerzenie(name, ".txt")) return 0;
    std::fstream f(name, std::fstream::out);
//qDebug() << f.is_open() << " Write";
    if (f.is_open() == 0)  return 0;


    f << "P1\n" << rgb.szer << " " << rgb.wys << "\n";

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
    if(head != "P1")   return 0;

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

bool menu_odczytu_i_zapisu:: Write_RGB_bin_file(const char *name, IMG &rgb){
    if(!spr_rozszerzenie(name, ".bin")) return 0;

    FILE *f = fopen(name, "wb");
    if(f == NULL)    return 0;

    char naglowek[] = "P4";
    int wyn = fwrite(&naglowek , 3, 1,f);

    fwrite(&rgb.wys, sizeof rgb.wys, 1, f);
    fwrite(&rgb.szer, sizeof rgb.szer, 1, f);

    for(int i = 0; i < rgb.wys; i++)
        for(int j=0; j < rgb.szer; j++)
            fwrite(&rgb.rgb[i *  rgb.szer + j], (sizeof RGB), 1, f);

    fclose(f);
    return 1;
}

bool menu_odczytu_i_zapisu:: Read_RGB_from_bin_file(const char *name, IMG &rgb){
    if(!spr_rozszerzenie(name, ".bin")) return 0;

    FILE *f = fopen(name, "rb");
    if(f == NULL)    return 0;

    char naglowek[3];

    fread(&naglowek , 3, 1,f);

    if(strcmp(naglowek, "P4"))    return 0;

    int wys,szer;

    fread(&wys, sizeof (int), 1, f);
    fread(&szer, sizeof (int), 1, f);

    rgb = new IMG(szer, wys);

    for(int i = 0; i < wys; i++)
        for(int j=0; j < szer; j++)
            fread(&rgb.rgb[i * szer + j], sizeof RGB, 1,f );

    fclose(f);
    return 1;
}

bool menu_odczytu_i_zapisu::Read_Grey_from_flile(const char *name, IMG &rgb){
    std::fstream f(name, std::fstream::in);
   // qDebug() << f.is_open() << " Read";
    if (f.is_open() == 0)  return 0;

    std::string head;
    f >> head;
    if(head != "P2")   return 0;

    f >> rgb.szer >> rgb.wys;

    rgb.rgb.resize(rgb.szer * rgb.wys);

    for(int i = 0; i < rgb.wys; i++)
        for(int j=0; j < rgb.szer; j++)
        {
            f >> rgb.rgb[i * rgb.szer + j].r;
            rgb.rgb[i * rgb.szer + j].b = rgb.rgb[i * rgb.szer + j].g = rgb.rgb[i * rgb.szer + j].r;
        }

    f.close();

    return 1;
}

bool menu_odczytu_i_zapisu::Write_Grey_file(const char *name, IMG &rgb){

    qDebug() << name;
    if(!spr_rozszerzenie(name, ".txt")) return 0;
    std::fstream f(name, std::fstream::out);

    if (f.is_open() == 0)  return 0;


    f << "P2\n" << rgb.szer << " " << rgb.wys << "\n";

    for(int i = 0; i < rgb.wys; i++)
        for(int j=0; j < rgb.szer; j++)
        {
            f << rgb.rgb[i * rgb.szer + j].r << " ";
        }

    f.close();

    return 1;
}

bool menu_odczytu_i_zapisu::Write_Grey_bin_file(const char *name, IMG &rgb){

    if(!spr_rozszerzenie(name, ".bin")) return 0;

    FILE *f = fopen(name, "wb");
    if(f == NULL)    return 0;

    char naglowek[] = "P5";
    int wyn = fwrite(&naglowek , 3, 1,f);

    fwrite(&rgb.wys, sizeof rgb.wys, 1, f);
    fwrite(&rgb.szer, sizeof rgb.szer, 1, f);

    for(int i = 0; i < rgb.wys; i++)
        for(int j=0; j < rgb.szer; j++)
            fwrite(&rgb.rgb[i *  rgb.szer + j].r, sizeof (int), 1, f);

    fclose(f);
    return 1;
}

bool menu_odczytu_i_zapisu::Read_Grey_from_bin_flile(const char *name, IMG &rgb){
    if(!spr_rozszerzenie(name, ".bin")) return 0;

    FILE *f = fopen(name, "rb");
    if(f == NULL)    return 0;

    char naglowek[3];

    fread(&naglowek , 3, 1,f);

    if(strcmp(naglowek, "P5"))    return 0;

    int wys,szer;

    fread(&wys, sizeof (int), 1, f);
    fread(&szer, sizeof (int), 1, f);

    rgb = new IMG(szer, wys);

    for(int i = 0; i < wys; i++)
        for(int j=0; j < szer; j++){
            fread(&rgb.rgb[i * szer + j].r, sizeof (int), 1,f );
            rgb.rgb[i * szer + j].b = rgb.rgb[i * szer + j].g = rgb.rgb[i * szer + j].r;
    }
    fclose(f);
    return 1;
}


//.......interfejs

void menu_odczytu_i_zapisu::on_textEdit_textChanged(const QString &arg1)
{
    path = arg1;
}

void menu_odczytu_i_zapisu::on_pushButton_sciezka_clicked()
{
    ui->label_komunikat->setText("");
    //robi rzecz ze recznie mozesz wyklikac scizke
    path = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*)"));

    ui->textEdit->setText(path);
}

void menu_odczytu_i_zapisu::on_pushButton_Wczytaj_clicked()
{
    path = ui->textEdit->toPlainText();
    ui->label_komunikat->setText("");

    if(spr_rozszerzenie(path.toLower(),".txt")){
        //załaduj z txt
        bool wyn = Read_RGB_file((path.toStdString()).c_str(), *U_rgb);
        if(wyn == 0)    Read_Grey_from_flile((path.toStdString()).c_str(), *U_rgb);
        *U_img = U_rgb->Make_img_from_RGB(*U_rgb);

    }else if (spr_czy_img(path)){
        Img_from_User_img(*U_img, *U_rgb);

    }else if(spr_rozszerzenie(path.toLower(),".bin")){
        bool wyn = Read_RGB_from_bin_file((path.toStdString()).c_str(), *U_rgb);
        if(!wyn)    Read_Grey_from_bin_flile((path.toStdString()).c_str(), *U_rgb);
        *U_img = U_rgb->Make_img_from_RGB(*U_rgb);
    }

}

void menu_odczytu_i_zapisu::on_pushButton_Zapisz_clicked()
{
    path = ui->textEdit->toPlainText();

    ui->label_komunikat->setText("");

    if(ui->radioButton_rgb->isChecked() && ui->radioButton_txt->isChecked()){
        // rgb.txt
        if(!Write_RGB_file((path.toStdString()).c_str(), *U_rgb))
            ui->label_komunikat->setText("blad zapisu rgb.txt");
    }else if(ui->radioButton_rgb->isChecked() && ui->radioButton_jpg->isChecked()){
        //rgb.jpg
        if(!((*U_img).save(path) && spr_czy_img((path.toStdString()).c_str()) ));
            ui->label_komunikat->setText("blad zapisu rgb.jpg");
    }else if(ui->radioButton_bin->isChecked() && ui->radioButton_rgb->isChecked()){
        //rgb.bin
        qDebug() << "rgb.bin";
        Write_RGB_bin_file((path.toStdString()).c_str(), *U_rgb);
    }else if(ui->radioButton_szary->isChecked() && ui->radioButton_txt->isChecked()){
        //sz.txt
        if(!Write_Grey_file((path.toStdString()).c_str(), *U_rgb))
            ui->label_komunikat->setText("blad zapisu grey.txt");

    }else if(ui->radioButton_szary->isChecked() && ui->radioButton_bin->isChecked()){
        //sz.bin
        if(!Write_Grey_bin_file((path.toStdString()).c_str(), *U_rgb))
            ui->label_komunikat->setText("blad zapisu grey.bin");
    }else if(ui->radioButton_szary->isChecked() && ui->radioButton_jpg->isChecked()){
        //sz.jpg

    }else if(ui->radioButton_hsv->isChecked() && ui->radioButton_txt->isChecked()){
        //hsv.txt

    }else if(ui->radioButton_hsv->isChecked() && ui->radioButton_bin->isChecked()){
        //hsv.bin

    }else if(ui->radioButton_hsv->isChecked() && ui->radioButton_jpg->isChecked()){
        //hsv.jpg

    }
}



