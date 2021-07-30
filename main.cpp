#include "widget.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    //fecha
    QString Fecha;
    QString nombreArchivo="C:/directorio/fecha.csv";
    QFile archivo(nombreArchivo);
    QTextStream io;
    QString FechaSistema=QDateTime::currentDateTime().toString("dd/MM/yyyy");
    qDebug()<<"Fecha Sistema= "<<FechaSistema;
    archivo.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!archivo.isOpen()){
        qDebug()<<"Error de apertura";
        return-1;

    }
    io.setDevice(&archivo);
    io>>Fecha;
    qDebug()<<"Fecha Archivo= "<<Fecha;
    archivo.flush();
    archivo.close();
    if(Fecha!=FechaSistema){
        QMessageBox::critical(0,"Aviso","Sistema no habilitado espere la fecha correcta ");
        return -1;
    }




    w.show();
    return a.exec();
}
