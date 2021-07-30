#include "votar.h"
#include "ui_votar.h"

votar::votar(QString cedula, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::votar)
{
    ui->setupUi(this);
    ui->mensaje->setText(cedula);
    paso=cedula;
}

votar::~votar()
{
    delete ui;
}
