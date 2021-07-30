#include "ejemplo1.h"
#include "ui_ejemplo1.h"

ejemplo1::ejemplo1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ejemplo1)
{
    ui->setupUi(this);
}

ejemplo1::~ejemplo1()
{
    delete ui;
}
