#ifndef JANELAAUXILIAR_H
#define JANELAAUXILIAR_H
#include "progesso.h"

#include <QWidget>

//namespace Ui {
//class JanelaAuxiliar;
//}

class JanelaAuxiliar : public QWidget
{
    Q_OBJECT
    //Progesso progesso;
    
public:
    explicit JanelaAuxiliar(QWidget *parent = 0);
    ~JanelaAuxiliar();
    
private:
    //Ui::JanelaAuxiliar *ui;
};

#endif // JANELAAUXILIAR_H
