#ifndef PAPELETA_H
#define PAPELETA_H
#include <QWidget>
#include <usuarios.h>
#include <votacion.h>




namespace Ui {
class Papeleta;
}

class Papeleta : public QWidget
{
    Q_OBJECT

public:
    explicit Papeleta(QList<Usuarios*> m_usuario,QWidget *parent = nullptr);
    ~Papeleta();



private:
    Ui::Papeleta *ui;
};

#endif // PAPELETA_H
