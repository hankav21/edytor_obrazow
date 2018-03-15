#include "sobel.h"
#include "ui_sobel.h"

Sobel::Sobel(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::Sobel)
{
    ui->setupUi(this);
}

Sobel::~Sobel()
{
    delete ui;
}

