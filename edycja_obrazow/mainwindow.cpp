#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

 }

MainWindow::~MainWindow()
{
    delete ui;
    if(widget_okolozapisu != NULL )      delete widget_okolozapisu;

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);

    QRectF target(10, 30, width()-20, height()-40);
    paint.drawImage(target,U_img);

//    if(zm == 1){
//    IMG pom(&U_rgb, 3, 3 );
//    IMG pow(3,3,&U_rgb);

//    int tabm[] = {  - 1,-2,-1,
//                    0,0,0,
//                   1,-2,1
//                };

//    MASK m(tabm,3,3);


//    QImage pomo, powo;
//    //pomo = pom.Make_img_from_RGB(pom);
//    powo = pow.Make_img_from_RGB(pow);
//    pow = pom.Make_rgb_with_mask(&pow,&m);
//    powo = pom.Make_img_from_RGB(pow);
//    IMG wyn(&pow, 3,3);
//    powo = pom.Make_img_from_RGB(wyn);
////    QRectF target1(20, 20, 150, 150);
////    paint.drawImage(target1,U_img);
//    QRectF target2(10, 30, width()-20, height()-40);


//    paint.drawImage(target2,powo);

//    }



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

//    widget_podgladuRGB = new Okno_RGB(this);
//    widget_podgladuRGB->show();
//    widget_podgladuRGB->zmienne_z_MainWindow(&U_rgb, &U_img, &R, &G, &B, &R_img, &G_img, &B_img);
}

void MainWindow::on_pushButton_Wincyj_clicked()
{
    zm = 1;
    //okno_wincyj.show();
    widget_wincyj = new Wincyj(this);
    widget_wincyj->show();
    widget_wincyj->zmienne_z_MainWindow(&U_rgb ,&U_img);
}

void MainWindow::on_pushButton_Aktualizuj_clicked()
{
    if(widget_wincyj != NULL){
        widget_wincyj->zmienne_z_MainWindow(&U_rgb ,&U_img);
    }
}
