#ifndef PROGESSO_H
#define PROGESSO_H

#include <QProgressBar>
class Progesso : public QProgressBar
{
public:
    Progesso();
    public slots:
    void setValue(qint64 valor);

#endif // PROGESSO_H
