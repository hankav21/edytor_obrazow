#ifndef OKNO_RGB_H
#define OKNO_RGB_H

#include <QDockWidget>
#include <QPainter>

#include "klasy_miedzyplikowe.h"


namespace Ui {
class Okno_RGB;
}

class Okno_RGB : public QDockWidget
{
    Q_OBJECT

public:
    explicit Okno_RGB(QWidget *parent = 0);
    ~Okno_RGB();
    
    void paintEvent(QPaintEvent *event);

    //funkcje do komunikacji pomiedzy klasami
    bool zmienne_z_Wincyj(struct IMG* rgb, QImage* img, int* lR, int* lG, int* lB, QImage* lr_img, QImage* lg_img, QImage* lb_img, MASK* l_mask);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Okno_RGB *ui;

    bool pionowo = 1;

    
    //zmienne ładowane z innych funkcji
    IMG* U_rgb;
    QImage* U_img;
    QImage *r_img, *g_img, *b_img;
    int *r, *g, *b;
    
};

#endif // OKNO_RGB_H
