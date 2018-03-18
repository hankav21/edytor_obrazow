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
