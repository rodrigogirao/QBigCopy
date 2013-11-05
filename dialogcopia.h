#ifndef DIALOGCOPIA_H
#define DIALOGCOPIA_H
#include "progess.h"
#include <QDialog>

namespace Ui {
class DialogCopia;
}

class DialogCopia : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogCopia(QWidget *parent = 0);
    ~DialogCopia();

    
private:
    Ui::DialogCopia *ui;
};

#endif // DIALOGCOPIA_H
