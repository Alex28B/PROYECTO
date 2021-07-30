#ifndef VOTACION_H
#define VOTACION_H
#include <QWidget>
#include <usuarios.h>


QT_BEGIN_NAMESPACE
namespace Ui {
class Votacion;
}
QT_END_NAMESPACE
class Votacion : public QWidget
{
    Q_OBJECT

public:
    explicit Votacion(QList<Usuarios*> m_usuario,QWidget *parent = nullptr);
    ~Votacion();
    QString cedula , nombre;
    QImage Foto;

void generacarnet(QString cedula, QString nombre,QImage Foto );

private slots:
    void on_btnGenerar_clicked();

    void on_btnGuadar_clicked();
    void on_pushButton_clicked();
    void on_lasso_clicked();
    void on_pushButtonnulo_clicked();
    void on_pushButtonblanco_clicked();
    void guardarImagen(int tipo);
    QImage juntarImagenes(const QImage& baseImage, const QImage& Foto);


private:
    Ui::Votacion *ui;
    QPixmap pixmap;

};

#endif // VOTACION_H
