#ifndef PODGLAD_H
#define PODGLAD_H

#include "klasy_miedzyplikowe.h"

#include <QDockWidget>
#include <QPainter>



namespace Ui {
class Podglad;
}

class Podglad : public QDockWidget
{
    Q_OBJECT

public:
    explicit Podglad(QWidget *parent = 0);
    ~Podglad();
    bool zmienne_z_Wincyj(QImage* l_img, MASK* l_mask);

    void paintEvent(QPaintEvent *event);
private:
    Ui::Podglad *ui;
    QImage* u_img_pow; //powiekszony o maske
    IMG* u_rgb;        //jw
    MASK* mask;

};

#endif // PODGLAD_H
