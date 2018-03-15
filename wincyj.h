#ifndef WINCYJ_H
#define WINCYJ_H

#include <QDockWidget>

#include "manipulacja_rgb.h"
#include "klasy_miedzyplikowe.h"
#include "podglad.h"
#include "sobel.h"

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

    int *r, *g, *b;
    IMG* u_rgb, *mod_rgb;
    QImage* u_img, *r_img, *g_img, *b_img, *mod_img;
    MASK* mask;

    //f do komunikacji pomiedzy kl
    bool zmienne_z_MainWindow(int* R, int* G, int* B, IMG* l_u_rgb, QImage* l_u_img, QImage* l_r_img, QImage* l_g_img, QImage* l_b_img);

private slots:
    void on_pushButton_manipulacjaRGB_clicked();
    void on_pushButton_Podglad_clicked();

    void on_pushButton_Zatwierdz_clicked();

    void on_pushButton_Sobel_clicked();

private:
    Ui::Wincyj *ui;

    QWidget okno_manipulacjaRGB;
    manipulacja_RGB *widget_manipulacjaRGB;
    Podglad *widget_podglad;
    Sobel* widget_sobel;

    bool aktualizuj;

    //fun
    void aktualizuj_mod();

};

#endif // WINCYJ_H
