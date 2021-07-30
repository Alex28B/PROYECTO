#ifndef VOTAR_H
#define VOTAR_H

#include <QWidget>

namespace Ui {
class votar;
}

class votar : public QWidget
{
    Q_OBJECT

public:
    explicit votar(QString cedula, QWidget *parent = nullptr);
    ~votar();

private:
    Ui::votar *ui;
    QString paso;
};

#endif // VOTAR_H

