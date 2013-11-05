#include "janelaprincipal.h"
#include "ui_janelaprincipal.h"
#include "qinputdialog.h"
#include <QScrollArea>
#include "qdebug.h"
#include "QtDebug"
#include <QLockFile>
#include <QIODevice>

janelaPrincipal::janelaPrincipal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::janelaPrincipal)
{
    ui->setupUi(this);
    dialog = new DialogCopia();
    modeldir = new QDirModel(this);
    modeldir->setReadOnly(false);
    ui->treeView->setModel(modeldir);
    ui->progressBarGeral->setValue(0);
    //ui->progressBarGeral->setVisible(false);
    //dialog = new DialogCopia(this);
    toFile = new QFile("/aaa/novo");
    fromFile = new QFile("/initrd.img");



    //written = 0;


   //QFile::connect(toFile, SIGNAL(bytesWritten(qint64)),this, SLOT(setValue(qint64)));


}

janelaPrincipal::~janelaPrincipal()
{
    delete ui;

}

void janelaPrincipal::copiarAquivos(QFile &origem, QFile &destino)
{

    qint64 nCopySize = origem.size();
    ui->progressBarGeral->setMaximum(nCopySize);
    if(!(origem.open(QFile::ReadOnly) && destino.open(QFile::ReadWrite))){
        return;
    }


  qDebug() << QString::number(nCopySize)+" o tamanho do arquivo";
  //dialog->show();

     for (qint64 i = 0; i < nCopySize; i += 1024*1024) {
         if(iscopy){
         destino.write(origem.read(i)); // write a byte
         destino.seek(i);  // move to next byte to read
         origem.seek(i); // move to next byte to write
         ui->progressBarGeral->setValue(i);
    }else {
             destino.remove();
             break;
         }

         // ui->progressBarGeral->;
     }
     ui->progressBarGeral->setVisible(false);
     ui->progressBarGeral->setValue(0);
      modeldir->refresh();
}

void janelaPrincipal::on_pushButton_clicked()
{
    //delet

    QModelIndex idex = ui->treeView->currentIndex();
    if(!idex.isValid()) return;

    if(modeldir->fileInfo(idex).isDir()){
        modeldir->rmdir(idex);
    }else{

        modeldir->remove(idex);
    }

}

void janelaPrincipal::on_pbmakedir_clicked()
{
    //make dir

    QModelIndex idex = ui->treeView->currentIndex();
    if(!idex.isValid()) return;

    QString nome = QInputDialog::getText(this,"nome da pasta","digite um nome para a nova pasta");
    if(nome.isEmpty()) return;

    modeldir->mkdir(idex,nome);
}

void janelaPrincipal::on_pbcopyfile_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid()) return;
    QString path = modeldir->fileInfo(index).absolutePath();
    QString nomea = modeldir->fileInfo(index).fileName();
iscopy = true;
    // QFile::copy(path+"/"+nomea, path+"/"+nomea+"2");
   ui->progressBarGeral->setVisible(true);
   QFile fileOrigem(ui->leorigem->text());
   QFile fileDestino(ui->ledestino->text()+nomea);
   qDebug() << " o origem é" << ui->leorigem->text();
   qDebug() << QString::number(QFileInfo(fileOrigem).size())+" o tamanho do arquivo";







copiarAquivos(fileOrigem,fileDestino);

//   fromFile->copy(toFile->fileName());
//   connect(toFile, SIGNAL(bytesWritten(qint64)), SLOT(setValue(qint64)));
   modeldir->refresh();

   //this->copiarAquivos(fileOrigem,fileDestino);



}

void janelaPrincipal::on_pbokorigem_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid()) return;
    path = modeldir->fileInfo(index).absolutePath();
    nomeArquivo = modeldir->fileInfo(index).fileName();
    if(path == "/") ui->leorigem->setText(path+nomeArquivo+"");
    else ui->leorigem->setText(path+"/"+nomeArquivo+"");
}

void janelaPrincipal::on_pbokdestino_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid()) return;
    path = modeldir->fileInfo(index).absolutePath();
    nomeArquivo = modeldir->fileInfo(index).fileName();
    if(path == "/") ui->ledestino->setText(path+nomeArquivo+"");
    else ui->ledestino->setText(path+"/"+nomeArquivo+"");
}

void janelaPrincipal::setValue(qint64 valor)
{
    written += (int)valor;
    ui->progressBarGeral->setValue((int) valor);
}

void janelaPrincipal::on_pbcancelar_clicked()
{
    iscopy = false;
}
