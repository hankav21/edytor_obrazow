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
    bool zmienne_z_Wincyj(MASK* l_mask, IMG* l_rgb, QImage* l_img);
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
    void on_horizontalScrollBar_valueChanged(int value);

private:
    Ui::Sobel *ui;



    int v, m_v, m_j = -1, j = 1, z = 0;
    int     *value = &v,
            *minus_value = &m_v,
            *minus_jeden = &m_j,
            *jeden = &j,
            *zero = &z;

    KAT Filtr;
    QLCDNumber* lcd[9];
    //QPushButton* butt[8];

    MASK* wyn_mask;
    IMG* wyn_rgb;
    QImage* wyn_img;


    //fun
    void aktualizuj();
};

#endif // SOBEL_H
