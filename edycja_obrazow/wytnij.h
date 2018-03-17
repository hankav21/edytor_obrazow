#ifndef WYTNIJ_H
#define WYTNIJ_H

#include <QDockWidget>
#include <QPainter>
#include "klasy_miedzyplikowe.h"

namespace Ui {
class wytnij;
}

class wytnij : public QDockWidget
{
    Q_OBJECT

public:
    explicit wytnij(QWidget *parent = 0);
    ~wytnij();
    void paintEvent(QPaintEvent *event);

    //fun kom
    bool zmienne_z_Wincyj(QImage* l_mod_img, IMG* l_mod_rgb);

private slots:
    void on_spinBox_X_valueChanged(int arg1);

    void on_spinBox_Y_valueChanged(int arg1);

    void on_spinBox_wys_valueChanged(int arg1);

    void on_spinBox_szer_valueChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::wytnij *ui;

    QImage* mod_img, podglad;
    IMG* mod_rgb;
    int X,Y,Wys, Szer;

    //fun
    void zatwierdz();


};

#endif // WYTNIJ_H
