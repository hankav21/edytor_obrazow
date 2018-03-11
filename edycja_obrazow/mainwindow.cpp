#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    R = 225;
    G = 225;
    B = 225;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);

    QRectF target(10, 30, width()-20, height()-40);
    paint.drawImage(target,U_img);

    update();
}

//public function

void MainWindow::on_pushButton_menu_zapisopodobne_clicked()
{
    okno_okolozapisu.show();
    widget_okolozapisu = new menu_odczytu_i_zapisu(&okno_okolozapisu);
    widget_okolozapisu->show();
    widget_okolozapisu->zmienne_z_MainWindow(&U_rgb, &U_img);
    okno_okolozapisu.resize(150,300);
    okno_okolozapisu.setMinimumSize(150,300);
    okno_okolozapisu.setMaximumSize(150,300);

}

void MainWindow::on_pushButton_podgladRGB_clicked()
{
    //okno_podgladuRGB.show();
    widget_podgladuRGB = new Okno_RGB(this);
    widget_podgladuRGB->show();
    widget_podgladuRGB->zmienne_z_MainWindow(&U_rgb, &U_img, &R, &G, &B, &R_img, &G_img, &B_img);
}

void MainWindow::on_pushButton_Wincyj_clicked()
{
    //okno_wincyj.show();
    widget_wincyj = new Wincyj(this);
    widget_wincyj->show();
    widget_wincyj->zmienne_z_MainWindow(&R,&G,&B, &U_rgb ,&U_img, &R_img, &G_img, &B_img);
}
