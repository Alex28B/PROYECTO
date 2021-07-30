#include "votacion.h"
#include "ui_votacion.h"
#include <QPainter>
#include <QPen>
#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>
#include <QFile>
#include <QTextStream>

Votacion::Votacion(QList<Usuarios*> m_usuario, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Votacion)
{
    ui->setupUi(this);
    QString cedula1="c:/directorio/alex.png";
    //definir el fondo
    QImage Foto( cedula1);
    pixmap.fill(Qt::white);
    ui->imagen->setPixmap(pixmap);
    pixmap.fill(Qt::white);
    ui->imagen->setPixmap(pixmap);

     nombre=m_usuario.at(0)->getm_Nombre();
     cedula=m_usuario.at(0)->getm_cedula();
    ui->lblNombre->setText(nombre);
    //definir el tamaño de área de trabajo - Qlabel(Tamaño de la etiqueta)
    pixmap=QPixmap(ui->imagen->size());

    //definir el fondo
    pixmap.fill(Qt::white);
    ui->imagen->setPixmap(pixmap);
}

Votacion::~Votacion()
{
    delete ui;
}

void Votacion::generacarnet(QString cedula, QString nombre,QImage Foto)
{

    QPainter painter(&pixmap);
    QPainter(this);
    QPixmap img("c:/directorio/alex.png");
    painter.drawPixmap(10,0,img);
    QPen pen;//(Qt::red);
    pen.setColor(Qt::white);
    painter.drawText(150,10," CNE ");
    painter.drawText(80,25," Papeleta de votación ");
    painter.drawText(80,50,nombre);
    painter.drawText(80,75,cedula);
    painter.drawText(80,100,"--PRESIDENTE DE MESA--");
    painter.drawText(90,125,"CRISTHIAN NARANJO");
    ui->imagen->setPixmap(pixmap);
    guardarImagen(1);
}


void Votacion::on_btnGenerar_clicked()
{
    generacarnet(cedula,nombre,Foto);
}

void Votacion::on_btnGuadar_clicked()
{
    guardarImagen(0);

}

void Votacion::on_pushButton_clicked()
{
    QFile archivo;
    QTextStream io;
    int horavotacion=QDateTime::currentDateTime().time().hour();
    int minutovotacion=QDateTime::currentDateTime().time().minute();    
    //pasar datos de usuario conectado
    QString nombreArchivo="c:/directorio/Votos.csv";
    archivo.setFileName(nombreArchivo);
    archivo.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text);
    if (!archivo.isOpen()){
        QMessageBox::critical(0,"Error",archivo.errorString());
        return;
    }
    io.setDevice(&archivo);
    io<<"Arauz"<<";"
      <<QString::number(horavotacion)<<";"
      <<QString::number(minutovotacion)<<endl;
    archivo.flush();
    archivo.close();

    generacarnet(cedula,nombre,Foto);

}

void Votacion::on_lasso_clicked()
{
    QFile archivo;
    QTextStream io;
    int horavotacion=QDateTime::currentDateTime().time().hour();
    int minutovotacion=QDateTime::currentDateTime().time().minute();
    //pasar datos de usuario conectado
    QString nombreArchivo="c:/directorio/Votos.csv";
    archivo.setFileName(nombreArchivo);
    archivo.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text);
    if (!archivo.isOpen()){
        QMessageBox::critical(0,"Error",archivo.errorString());
        return;
    }
    io.setDevice(&archivo);
    io<<"Lasso"<<";"
      <<QString::number(horavotacion)<<";"
      <<QString::number(minutovotacion)<<endl;
    archivo.flush();
    archivo.close();

    generacarnet(cedula,nombre,Foto);

}

void Votacion::on_pushButtonnulo_clicked()
{
    QFile archivo;
    QTextStream io;
    int horavotacion=QDateTime::currentDateTime().time().hour();
    int minutovotacion=QDateTime::currentDateTime().time().minute();
    //pasar datos de usuario conectado
    QString nombreArchivo="c:/directorio/Votos.csv";
    archivo.setFileName(nombreArchivo);
    archivo.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text);
    if (!archivo.isOpen()){
        QMessageBox::critical(0,"Error",archivo.errorString());
        return;
    }
    io.setDevice(&archivo);
    io<<"nulo"<<";"
      <<QString::number(horavotacion)<<";"
      <<QString::number(minutovotacion)<<endl;
    archivo.flush();
    archivo.close();

    generacarnet(cedula,nombre,Foto);

}

void Votacion::on_pushButtonblanco_clicked()
{
    QFile archivo;
    QTextStream io;

    int horavotacion=QDateTime::currentDateTime().time().hour();
    int minutovotacion=QDateTime::currentDateTime().time().minute();
    //pasar datos de usuario conectado
    QString nombreArchivo="c:/directorio/Votos.csv";
    archivo.setFileName(nombreArchivo);
    archivo.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text);
    if (!archivo.isOpen()){
        QMessageBox::critical(0,"Error",archivo.errorString());
        return;
    }
    io.setDevice(&archivo);
    io<<"blanco"<<";"
      <<QString::number(horavotacion)<<";"
      <<QString::number(minutovotacion)<<endl;
    archivo.flush();
    archivo.close();

    generacarnet(cedula,nombre,Foto);

}

void Votacion::guardarImagen(int tipo)
{
    QString nombreArchivo;
    if (tipo==0){
         nombreArchivo=QFileDialog::getSaveFileName(this,"Guardar",QString(),"Imagen(*.png)");
    }else{
        nombreArchivo="c:/directorio/carnets/carnet.png";
    }

    if(!nombreArchivo.isEmpty()){
        QImage img=ui->imagen->pixmap()->toImage();
        img.save(nombreArchivo);
    }else{
        QMessageBox::information(0,"Aviso","Error");
    }
}

QImage Votacion::juntarImagenes(const QImage &baseImage, const QImage &Foto)
{
    QImage imageWithOverlay = QImage(baseImage.size(), QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&imageWithOverlay);

    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(imageWithOverlay.rect(), Qt::transparent);

    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawImage(0, 0, baseImage);

    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawImage(10, 50, Foto);

    painter.end();

    return imageWithOverlay;
}



