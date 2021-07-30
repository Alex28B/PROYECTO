#include "papeleta.h"
#include "ui_papeleta.h"
#include <QFile>
#include <QTextStream>
#include <QtDebug>
#include <QMessageBox>
#include <usuarios.h>
#include <widget.h>


Papeleta::Papeleta(QList<Usuarios*> m_usuario, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Papeleta)
{
    ui->setupUi(this);
    QString nombre=m_usuario.at(0)->getm_Nombre();
    ui->lblNombre->setText(nombre);
}

Papeleta::~Papeleta()
{
    delete ui;
}
