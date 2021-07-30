#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>
#include <QtDebug>
#include <QMessageBox>
#include <usuarios.h>
#include <votacion.h>
#include <papeleta.h>
#include <votar.h>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->txtClave->setEchoMode(QLineEdit::Password);
    //cargar la lista de usuarios del archivo csv
    QString nombreArchivo="c:/directorio/usuarios.csv";
    QString nombreArchivo2="c:/directorio/users.csv";

    QFile archivo;
    QFile archivo2;
    QTextStream io;
    archivo.setFileName(nombreArchivo);
    archivo2.setFileName(nombreArchivo2);

    archivo.open(QIODevice::ReadOnly | QIODevice::Text );
    if(!archivo.isOpen()){
        QMessageBox::information(0,"Aviso","Error de Apertura");
        return;
    };

    io.setDevice(&archivo);
    int filacodigo=0,filacedula=0, filanombre=0, filaclave=0, filafoto=0;
    QString codigo,cedula,nombre, clave, foto;
    while(!io.atEnd()){
        auto linea = io.readLine();
        auto valores=linea.split(";");
        int numeroColumnas=valores.size();

        for(int i=0; i<numeroColumnas;i++){
            auto dato=valores.at(i);


            if(i==0 or filacodigo==i){
                codigo=dato;
                filacodigo+=5;
            };

            //cedula
            if(i==1 or filacedula==i){
                cedula=dato;
                filacedula+=5;
            };
            //nombre
            if(i==2 or filanombre==i){
                nombre=dato;
                filanombre+=5;
            };
            //clave
            if(i==3 or filaclave==i){
                clave=dato;
                filaclave+=5;
            };
            //foto
            if(i==4 or filafoto==i){
                foto=dato;
                filafoto+=5;
                m_usuarios.append(new Usuarios(codigo,cedula,nombre,clave,foto,""));
                qDebug()<<codigo<<cedula<<nombre<<clave<<foto;
            };

        }

    }



    ui->txtUsuario->setFocus();

    archivo2.open(QIODevice::ReadOnly | QIODevice::Text );
    if(!archivo.isOpen()){
        QMessageBox::information(0,"Aviso","Error de Apertura");
        return;
    };


    io.setDevice(&archivo2);
    while(!io.atEnd()){
        auto linea = io.readLine();
        auto valores=linea.split(";");
        int numeroColumnas=valores.size();
        for(int i=0; i<numeroColumnas;i++){
            auto dato=valores.at(i);
            if (i==1){
                insertar(lista, dato);
            }
        }
     }
    imprimir(lista);
    ui->txtUsuario->setFocus();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::insertar(lista_simple &nuevo_nodo, QString valor){
    lista_simple nodo1;
    nodo1 = new(struct nodo);
    nodo1->dato = valor;
    nodo1->enlace = nuevo_nodo;
    nuevo_nodo = nodo1;
}

void Widget::imprimir(lista_simple lista){
    while(lista != NULL){
        qDebug()<< lista->dato <<endl;
        lista = lista->enlace;
    }
}

int Widget::buscarElemento(lista_simple lista, QString valor){
    lista_simple lista_buscar;
    lista_buscar = lista;
    int i = 1, band = 0;
    while(lista_buscar!=NULL){
        if(lista_buscar->dato==valor){
            //qDebug()<<"Encontrador en"<<i<<endl;
            band = 1;
        }
        lista_buscar = lista_buscar->enlace;
        i++;
    }
    //if(band==0)
         //qDebug()<<"No encontrado"<<endl;
    return band;
}

void Widget::on_btnEnviar_clicked()
{

    QString cedula=ui->txtUsuario->text();
    QString clave=ui->txtClave->text();
    bool bandera=false;
    if(cedula.isEmpty() or clave.isEmpty()){
        QMessageBox::information(0,"Aviso","Revise los Datos");
        return;
    }
    for(int i=1;i<m_usuarios.length();i++){
        if(m_usuarios.at(i)->getm_cedula()==cedula && m_usuarios.at(i)->getm_Clave()==clave){
            QMessageBox::information(0,"Aviso","Recuerde que su voto es secreto");
            bandera=true;
           m_usuario.append(new Usuarios(m_usuarios.at(i)->getm_Codigo(),m_usuarios.at(i)->getm_cedula(),m_usuarios.at(i)->getm_Nombre(),m_usuarios.at(i)->getm_Clave(), m_usuarios.at(i)->getm_Foto(),""));
        }
    }

    if(bandera==false){
        QMessageBox::information(0,"Aviso","Usuario no valido");

    }else{
        if (buscarElemento(lista, cedula)){
             QMessageBox::information(0,"Aviso","Ya voto");
            return;

    }else{
        //llamar a la nueva ventana
        ui->txtClave->setText("");
        ui->txtUsuario->setText("");
        Votacion *ingresoVotacion = new Votacion(m_usuario);
        ingresoVotacion->show();

    } 
   }
}


