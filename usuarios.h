#ifndef USUARIOS_H
#define USUARIOS_H

#include <QObject>

class Usuarios : public QObject
{
    Q_OBJECT
public:
    explicit Usuarios(QObject *parent = nullptr);

    //constructor
    Usuarios(QString m_Id,QString m_Cedula,QString m_Nombre,QString m_Clave,QString m_Foto,QString m_voto);

    //gets

    QString getm_Codigo(){
        return m_Id;
    };
    QString getm_cedula(){
        return m_Cedula;
    };
    QString getm_Nombre(){
        return m_Nombre;
    };
    QString getm_Clave(){
        return m_Clave;
    };
    QString getm_Foto(){
        return m_Foto;
    };

signals:
private:
    QString m_Id;
    QString m_Cedula;
    QString m_Nombre;
    QString m_Clave;
    QString m_Foto;
    QString m_voto;



};

#endif // USUARIOS_H
