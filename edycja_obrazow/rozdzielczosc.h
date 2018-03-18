#ifndef ROZDZIELCZOSC_H
#define ROZDZIELCZOSC_H

#include <QDockWidget>
#include "klasy_miedzyplikowe.h"
#include <QPainter>
#include <QDebug>
#include <QVector>

namespace Ui {
class rozdzielczosc;
}

class rozdzielczosc : public QDockWidget
{
    Q_OBJECT

public:
    explicit rozdzielczosc(QWidget *parent = 0);
    ~rozdzielczosc();
    void paintEvent(QPaintEvent *event);

    //fun do kom
    bool zmienne_z_Wincyj(QImage* l_u_img, IMG* l_u_rgb);

private slots:
    void on_spinBox_szer_valueChanged(int arg1);

    void on_spinBox_wys_valueChanged(int arg1);


    void on_pushButton_sasiedztwo_clicked();

    void on_pushButton_interpolacja_clicked();

    void on_pushButton_zatwierdz_clicked();

private:
    Ui::rozdzielczosc *ui;
    QImage* img, mod_img;
    IMG* rgb, mod_rgb;
    int szer, wys;
    float ratiox,ratioy; //wspólczynniki powiekszenia w x i y
};

#endif // ROZDZIELCZOSC_H
