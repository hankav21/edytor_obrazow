#ifndef WINCYJ_H
#define WINCYJ_H

#include <QDockWidget>

#include "manipulacja_rgb.h"
#include "klasy_miedzyplikowe.h"

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
    IMG* u_rgb;
    QImage* u_img, *r_img, *g_img, *b_img;

    //f do komunikacji pomiedzy kl
    bool zmienne_z_MainWindow(int* R, int* G, int* B, IMG* l_u_rgb, QImage* l_u_img, QImage* l_r_img, QImage* l_g_img, QImage* l_b_img);

private slots:


    void on_pushButton_manipulacjaRGB_clicked();

private:
    Ui::Wincyj *ui;

    QWidget okno_manipulacjaRGB;
    manipulacja_RGB *widget_manipulacjaRGB;

};

#endif // WINCYJ_H
