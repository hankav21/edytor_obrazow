#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menu_odczytu_i_zapisu.h"
#include "okno_rgb.h"
#include "wincyj.h"
#include "klasy_miedzyplikowe.h"

#include <QPainter>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);



    QImage U_img;   //wczytywane przez uzytkownika
    IMG U_rgb;

    QImage R_img, G_img, B_img;


    int R,G,B;

    //funkcje
    //bool f1(void){int x=1;};

private slots:
    void on_pushButton_menu_zapisopodobne_clicked();
    void on_pushButton_podgladRGB_clicked();

    void on_pushButton_Wincyj_clicked();

private:
    Ui::MainWindow *ui;


    QWidget okno_okolozapisu;
    menu_odczytu_i_zapisu *widget_okolozapisu;

    QWidget okno_podgladuRGB;
    Okno_RGB *widget_podgladuRGB;

    QWidget okno_wincyj;
    Wincyj *widget_wincyj;


    std:: vector<std:: vector<float> > mask;
};

#endif // MAINWINDOW_H
