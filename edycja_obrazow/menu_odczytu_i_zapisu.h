#ifndef MENU_ODCZYTU_I_ZAPISU_H
#define MENU_ODCZYTU_I_ZAPISU_H

#include <QDockWidget>
#include <QFileDialog>
#include <QDialog>

//pliki
#include <stdlib.h>
#include <QInputDialog>
#include <stdio.h>

#include <string>
#include <QString>

#include <fstream>
#include <cstdio>

#include "klasy_miedzyplikowe.h"


namespace Ui {
class menu_odczytu_i_zapisu;
}

class menu_odczytu_i_zapisu : public QDockWidget
{
    Q_OBJECT

public:
    explicit menu_odczytu_i_zapisu(QWidget *parent = 0);
    ~menu_odczytu_i_zapisu();

    //funkcje do komunikacji pomiedzy klasami
    bool menu_odczytu_i_zapisu:: zmienne_z_MainWindow(struct IMG* rgb, QImage* img);
    bool menu_odczytu_i_zapisu:: zaktualizuj_MainWindow(struct IMG* rgb, QImage* img);

private slots:
    void on_pushButton_sciezka_clicked();
    void on_textEdit_textChanged(const QString &arg1);
    void on_pushButton_Wczytaj_clicked();

    void on_pushButton_Zapisz_clicked();



private:
    Ui::menu_odczytu_i_zapisu *ui;
    QString path;

    //zmienne ładowane z innych funkcji
    IMG* U_rgb;
    QImage* U_img;


    //funkcje
    bool spr_rozszerzenie(const QString s, const QString r);
    bool spr_czy_img(const QString path);

    //Zapisuje plik tekstowy RGB
    bool menu_odczytu_i_zapisu:: Write_RGB_file(const char* name, IMG rgb);
    //Wczytuje plik tekstowy RGB i tworzy vectory
    bool menu_odczytu_i_zapisu:: Read_RGB_file(const char* name, IMG& rgb);
    //Tworzy vectory RGB z obrazu
    bool menu_odczytu_i_zapisu:: Img_from_User_img(QImage& img, IMG& rgb);
   //tworzy plik .bin RGB
    bool Write_RGB_bin_file(const char* name, IMG& rgb);
    //wczytuje RGB z liku .bin
    bool Read_RGB_from_bin_file(const char* name, IMG& rgb);
    //wczytuje odcienie szarosci z pliku .txt
    bool Read_Grey_from_flile(const char* name, IMG& rgb);
    //zapisuje odcienie sarosci do .txt
    bool Write_Grey_file(const char* name, IMG& rgb);
    //zapsiuje odcienie szarosci do pliku bin
    bool Write_Grey_bin_file(const char* name, IMG& rgb);
    //wczytuje odcienie szarosci z pliku bin
    bool Read_Grey_from_bin_flile(const char* name, IMG& rgb);

};


#endif // MENU_ODCZYTU_I_ZAPISU_H
