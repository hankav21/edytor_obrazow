#ifndef MANIPULACJA_RPG_H
#define MANIPULACJA_RPG_H

#include <QDockWidget>
#include "klasy_miedzyplikowe.h"

namespace Ui {
class Manipulacja_RPG;
}

class Manipulacja_RPG : public QDockWidget
{
    Q_OBJECT

public:
    explicit Manipulacja_RPG(QWidget *parent = 0);
    ~Manipulacja_RPG();


    //funkcje do komunikacji  pomiedzy klasami
//    bool zmienne_z_okno_rgb(int* r, int* g, int* b);

private slots:
    void on_spinBoxR_valueChanged(int arg1);
    void on_SliderR_valueChanged(int value);

private:
    Ui::Manipulacja_RPG *ui;

    int R, G, B;
};

#endif // MANIPULACJA_RPG_H
