#ifndef GREY_H
#define GREY_H

#include <QDockWidget>
#include "klasy_miedzyplikowe.h"
#include <QPaintEvent>
#include <QPainter>

namespace Ui {
class grey;
}

class grey : public QDockWidget
{
    Q_OBJECT

public:
    explicit grey(QWidget *parent = 0);
    ~grey();
    void paintEvent(QPaintEvent *event);
    //fun do kom
    bool zmienne_z_Wincyj(QImage* l_u_img, IMG* l_u_rgb);

private slots:
    void on_pushButton_srednie_clicked();

    void on_pushButton_YUV_clicked();

    void on_pushButton_ok_clicked();

private:
    Ui::grey *ui;
    QImage *img, mod_img;
    IMG* rgb, mod_rgb;
};

#endif // GREY_H
