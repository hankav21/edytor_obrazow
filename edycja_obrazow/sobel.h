#ifndef SOBEL_H
#define SOBEL_H

#include <QDockWidget>
#include <QLCDNumber>
#include <QPushButton>
#include "klasy_miedzyplikowe.h"

namespace Ui {
class Sobel;
}

class Sobel : public QDockWidget
{
    Q_OBJECT

public:
    explicit Sobel(QWidget *parent = 0);
    ~Sobel();

    //fun do kom
    bool zmienne_z_Wincyj( IMG* l_rgb, QImage* l_img, IMG* lu_rgb, QImage* lu_img);
    void aktualizuj_zmienne_z_Wincyj();

private slots:
    void on_pushButton_0_clicked();
    void on_pushButton_45_clicked();
    void on_pushButton_90_clicked();
    void on_pushButton_135_clicked();
    void on_pushButton_180_clicked();
    void on_pushButton_225_clicked();
    void on_pushButton_270_clicked();
    void on_pushButton_315_clicked();
    void on_horizontalScrollBar_valueChanged(int va);

    void on_pushButton_clicked();

    void on_pushButton_Sobel_clicked();

    void on_pushButton_Laplasjany_clicked();

    void on_pushButton_Laplace_clicked();

    void on_pushButton_Sobel_Gradien_Robertsa_clicked();

private:
    Ui::Sobel *ui;



    int v, m_v, m_j = -1, j = 1, z = 0;
    int     value,
            *minus_value = &m_v,
            *minus_jeden = &m_j,
            *jeden = &j,
            *zero = &z;

    KAT Filtr;
    QLCDNumber* lcd[3][3];
    QPushButton* butt, *kat;

    MASK mask;
    IMG* wyn_rgb, *u_rgb;
    QImage* wyn_img, *u_img;


    //fun
    void aktualizuj();

    bool sobel();
    bool laplace();
    bool prewitt();
};

#endif // SOBEL_H
