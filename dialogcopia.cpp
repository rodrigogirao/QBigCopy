#include "dialogcopia.h"
#include "ui_dialogcopia.h"


DialogCopia::DialogCopia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCopia)
{
    ui->setupUi(this);
  //Progess *progesso = new Progess(this);

   //progesso->setValue(30);
}

DialogCopia::~DialogCopia()
{
    delete ui;
}


