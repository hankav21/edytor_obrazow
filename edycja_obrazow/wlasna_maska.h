#ifndef WLASNA_MASKA_H
#define WLASNA_MASKA_H

#include <QDockWidget>
#include "klasy_miedzyplikowe.h"
#include <QLCDNumber>
#include <QVector>
#include <QPainter>

namespace Ui {
class wlasna_maska;
}

class wlasna_maska : public QDockWidget
{
    Q_OBJECT

public:
    explicit wlasna_maska(QWidget *parent = 0);
    ~wlasna_maska();
    void paintEvent(QPaintEvent *event);
    //fun do kom
    bool zmienne_z_Wincyj(IMG* l_rgb, QImage* l_img, IMG* lu_rgb, QImage* lu_img);

private slots:
    void on_spinBox_wys_valueChanged(int arg1);

    void on_spinBox_szer_valueChanged(int arg1);

    void on_pushButton_buduj_clicked();

    void on_spinBox_y_valueChanged(int arg1);

    void on_spinBox_x_valueChanged(int arg1);

    void on_spinBox_wartosc_valueChanged(int arg1);

    void on_pushButton_zatwierdz_clicked();

private:
    Ui::wlasna_maska *ui;
    IMG* u_rgb, *wyn_rgb;   //u_ sa do pobierania niezepsutego obrazu
    QImage *u_img, *wyn_img;
    MASK* mod_mask;

    int wys, szer, x, y;  //musza byc nieparzyste
    std::vector < std::vector <QLCDNumber* > > lcd;

};

#endif // WLASNA_MASKA_H
