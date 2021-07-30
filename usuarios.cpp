#include "usuarios.h"

Usuarios::Usuarios(QObject *parent) : QObject(parent)
{

     m_Id="";
     m_Cedula="";
     m_Nombre="";
     m_Clave="";
     m_Foto="";
     m_voto="";
}

Usuarios::Usuarios(QString m_Id,QString m_Cedula,QString m_Nombre,QString m_Clave,QString m_Foto,QString m_voto){

    this->m_Id=m_Id;
    this->m_Cedula=m_Cedula;
    this->m_Nombre=m_Nombre;
    this->m_Clave=m_Clave;
    this->m_Foto=m_Foto;
    this->m_voto=m_voto;
}
