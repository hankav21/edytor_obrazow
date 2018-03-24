#include "gornoprzepustowe.h"
#include "ui_gornoprzepustowe.h"

gornoprzepustowe::gornoprzepustowe(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::gornoprzepustowe)
{
    ui->setupUi(this);
}

gornoprzepustowe::~gornoprzepustowe()
{
    delete ui;
}
