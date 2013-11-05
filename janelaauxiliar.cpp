#include "janelaauxiliar.h"
#include "ui_janelaauxiliar.h"

JanelaAuxiliar::JanelaAuxiliar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JanelaAuxiliar)
{
    ui->setupUi(this);
}

JanelaAuxiliar::~JanelaAuxiliar()
{
    delete ui;
}
