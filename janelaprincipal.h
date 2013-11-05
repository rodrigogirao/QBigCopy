#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QDirModel>
#include "dialogcopia.h"
#include "qprogressdialog.h"



namespace Ui {
class janelaPrincipal;
}

class janelaPrincipal : public QDialog
{
    Q_OBJECT
    QString path;
    QString nomeArquivo;
    qint64 written;
    QFile *fromFile;
    QFile *toFile;
    DialogCopia *dialog;
    bool iscopy;


    
public:
    explicit janelaPrincipal(QWidget *parent = 0);
    ~janelaPrincipal();
    void copiarAquivos(QFile &origem, QFile &destino);
signals:
    void bytesEscritos(qint64);

private slots:
    void on_pushButton_clicked();

    void on_pbmakedir_clicked();

    void on_pbcopyfile_clicked();

    void on_pbokorigem_clicked();

    void on_pbokdestino_clicked();

    void setValue(qint64 valor);

    void on_pbcancelar_clicked();

private:
    Ui::janelaPrincipal *ui;
    QDirModel *modeldir;

};

#endif // JANELAPRINCIPAL_H
