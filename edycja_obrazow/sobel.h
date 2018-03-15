#ifndef SOBEL_H
#define SOBEL_H

#include <QDockWidget>

namespace Ui {
class Sobel;
}

class Sobel : public QDockWidget
{
    Q_OBJECT

public:
    explicit Sobel(QWidget *parent = 0);
    ~Sobel();

private:
    Ui::Sobel *ui;
};

#endif // SOBEL_H
