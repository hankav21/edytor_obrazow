#ifndef HSV_H
#define HSV_H

#include "klasy_miedzyplikowe.h"

#include <QDockWidget>

namespace Ui {
class hsv;
}

class hsv : public QDockWidget
{
    Q_OBJECT

public:
    explicit hsv(QWidget *parent = 0);
    ~hsv();

    bool zmienne_z_Wincyj(QImage* l_u_img, IMG* l_u_rgb);




private slots:
    void on_modyfikacje_tabBarClicked(int index);

    void on_PushButton_ok_clicked();

private:
    Ui::hsv *ui;
    QImage *img, mod_img;
    IMG* rgb, mod_rgb;
    IMG_HSV* mod_hsv;

    //fun
    bool akcent(IMG_HSV* hsv, RGB* color, int range);

};

#endif // HSV_H
