#include "autor.h"
#include "ui_autor.h"

autor::autor(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::autor)
{
    ui->setupUi(this);
}

autor::~autor()
{
    delete ui;
}
