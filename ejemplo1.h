#ifndef EJEMPLO1_H
#define EJEMPLO1_H

#include <QWidget>

namespace Ui {
class ejemplo1;
}

class ejemplo1 : public QWidget
{
    Q_OBJECT

public:
    explicit ejemplo1(QWidget *parent = nullptr);
    ~ejemplo1();

private:
    Ui::ejemplo1 *ui;
};

#endif // EJEMPLO1_H
