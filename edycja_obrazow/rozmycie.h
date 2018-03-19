#ifndef ROZMYCIE_H
#define ROZMYCIE_H

#include <QDockWidget>
#include "klasy_miedzyplikowe.h"

namespace Ui {
class rozmycie;
}

class rozmycie : public QDockWidget
{
    Q_OBJECT

public:
    explicit rozmycie(QWidget *parent = 0);
    ~rozmycie();


    //fun do kom
    bool zmienne_z_Wincyj(IMG* l_rgb, QImage* l_img, IMG* lu_rgb, QImage* lu_img);

private slots:
    void on_verticalScrollBar_rozmiar_valueChanged(int value);

    void on_verticalScrollBar_wartosc_valueChanged(int value);

    void on_pushButton_kwadrat_clicked();

    void on_pushButton_kolo_clicked();

    void on_pushButton_stozkek_clicked();

    void on_pushButton_piramida_clicked();

    void on_pushButton_Gauss_clicked();

    void on_pushButton_ok_clicked();

private:
    Ui::rozmycie *ui;
    QImage* mod_img, *u_img;
    IMG *mod_rgb, *u_rgb;
    MASK mask;
    int rozmiar, wartosc;
};

#endif // ROZMYCIE_H
