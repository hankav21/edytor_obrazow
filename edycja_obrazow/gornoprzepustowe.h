#ifndef GORNOPRZEPUSTOWE_H
#define GORNOPRZEPUSTOWE_H

#include <QDockWidget>

namespace Ui {
class gornoprzepustowe;
}

class gornoprzepustowe : public QDockWidget
{
    Q_OBJECT

public:
    explicit gornoprzepustowe(QWidget *parent = 0);
    ~gornoprzepustowe();

private:
    Ui::gornoprzepustowe *ui;
};

#endif // GORNOPRZEPUSTOWE_H
