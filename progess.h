#ifndef PROGESS_H
#define PROGESS_H

#include <QProgressBar>

class Progess : public QProgressBar
{
    Q_OBJECT
public:
    explicit Progess(QWidget *parent = 0);
    
signals:
    
public slots:
    void setValue(qint64 valor);

    
};

#endif // PROGESS_H
