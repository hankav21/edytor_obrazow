#include "rozmycie.h"
#include "ui_rozmycie.h"

rozmycie::rozmycie(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::rozmycie)
{
    ui->setupUi(this);
}

rozmycie::~rozmycie()
{
    delete ui;
}

bool rozmycie::zmienne_z_Wincyj(IMG* l_rgb, QImage* l_img, IMG* lu_rgb, QImage* lu_img){

    mod_img = l_img;
    mod_rgb = l_rgb;

    u_img = lu_img;
    u_rgb = lu_rgb;


    return 1;
}
