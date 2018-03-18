#ifndef WINCYJ_H
#define WINCYJ_H

#include <QDockWidget>

#include "manipulacja_rgb.h"
#include "klasy_miedzyplikowe.h"
#include "podglad.h"
#include "sobel.h"
#include "okno_rgb.h"
#include "wytnij.h"
#include "rozdzielczosc.h"

#include <QDebug>

namespace Ui {
class Wincyj;
}

class Wincyj : public QDockWidget
{
    Q_OBJECT

public:
    explicit Wincyj(QWidget *parent = 0);
    ~Wincyj();


    QImage R_img, G_img, B_img;
    int R,G,B;

    IMG mod_rgb, *u_rgb;
    QImage *u_img, mod_img;
    MASK mask;

    //f do komunikacji pomiedzy kl
    bool zmienne_z_MainWindow(IMG* l_u_rgb, QImage* l_u_img);

private slots:
    void on_pushButton_manipulacjaRGB_clicked();
    void on_pushButton_Podglad_clicked();

    void on_pushButton_Zatwierdz_clicked();

    void on_pushButton_Sobel_clicked();

    void on_pushButton_Podglad_RGB_clicked();

    void on_pushButton_Sobel_Wytnij_clicked();

    void on_pushButton_rozdzielczosc_clicked();

private:
    Ui::Wincyj *ui;

    QWidget okno_manipulacjaRGB;
    manipulacja_RGB *widget_manipulacjaRGB;
    Podglad *widget_podglad;
    Sobel* widget_sobel;
    Okno_RGB* widget_oknoRGB;
    wytnij* widget_wytnij;
    rozdzielczosc* widget_rozdzielczosc;

    bool aktualizuj;

    //fun
    void aktualizuj_mod();

};

#endif // WINCYJ_H
