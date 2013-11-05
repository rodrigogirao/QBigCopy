#include "progess.h"

Progess::Progess(QWidget *parent) :
    QProgressBar(parent)
{
}

void Progess::setValue(qint64 valor)
{
    this->setValue(valor);
}
