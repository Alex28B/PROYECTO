#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <usuarios.h>
#include <QPen>
#include <QPainter>
struct nodo{
    QString dato;
    struct nodo *enlace;
};
typedef struct nodo *lista_simple;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void insertar(lista_simple &nuevo_nodo, QString valor);
    void imprimir(lista_simple lista);
    int buscarElemento(lista_simple lista, QString valor);
    int registros=0;
    QString Fecha;
    void generacarnet(QString cedula , QString nombre);



private slots:
    void on_btnEnviar_clicked();




private:
    Ui::Widget *ui;
    lista_simple lista = NULL;
    QList<Usuarios*> m_usuarios;//lista de usuarios
    QList<Usuarios*> m_usuario;//lista de usuario conectado
    QPixmap pixmap;
    QPen pen;
    QPainter painter;



};
#endif // WIDGET_H
