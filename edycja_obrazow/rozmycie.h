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

private:
    Ui::rozmycie *ui;
    QImage* mod_img, *u_img;
    IMG *mod_rgb, *u_rgb;
    MASK mask;
};

#endif // ROZMYCIE_H
