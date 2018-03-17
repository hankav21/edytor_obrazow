#ifndef WYTNIJ_H
#define WYTNIJ_H

#include <QDockWidget>
#include <QImage>
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

private slots:
    void on_spinBox_X_valueChanged(int arg1);

    void on_spinBox_Y_valueChanged(int arg1);

    void on_spinBox_wys_valueChanged(int arg1);

    void on_spinBox_szer_valueChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::wytnij *ui;
};

#endif // WYTNIJ_H
