#ifndef ROZMYCIE_H
#define ROZMYCIE_H

#include <QDockWidget>

namespace Ui {
class rozmycie;
}

class rozmycie : public QDockWidget
{
    Q_OBJECT

public:
    explicit rozmycie(QWidget *parent = 0);
    ~rozmycie();

private:
    Ui::rozmycie *ui;
};

#endif // ROZMYCIE_H
