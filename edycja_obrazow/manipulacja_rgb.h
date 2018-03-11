#ifndef MANIPULACJA_RGB_H
#define MANIPULACJA_RGB_H

#include <QDockWidget>
#include "klasy_miedzyplikowe.h"
#include "okno_rgb.h"

namespace Ui {
class manipulacja_RGB;
}

class manipulacja_RGB : public QDockWidget
{
    Q_OBJECT

public:
    explicit manipulacja_RGB(QWidget *parent = 0);
    ~manipulacja_RGB();

    //f do kom
    bool aktualizuj_okno_rgb(int* lr, int* lg, int* lb){
        lr = r;
        lg = g;
        lb = b;
        return 1;
    }

    bool zmienne_z_Wincyj(int* lR, int* lG, int* lB, IMG* l_u_rgb, QImage* l_u_img, QImage* l_r_img, QImage* l_g_img, QImage* l_b_img);

private slots:
    void on_spinBoxR_valueChanged(int arg1);
    void on_RSlider_valueChanged(int value);

    void on_spinBoxG_valueChanged(int arg1);

    void on_GSlider_valueChanged(int value);

    void on_spinBoxB_valueChanged(int arg1);

    void on_BSlider_valueChanged(int value);

private:
    Ui::manipulacja_RGB *ui;
    int *r,*g,*b;
    IMG* u_rgb;
    QImage* u_img, *r_img, *g_img, *b_img;
    
};

#endif // MANIPULACJA_RGB_H
