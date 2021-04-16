#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <blkid.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonOpenImgFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Address Book"), "/nfs/share/disk/",
            tr("img file (*.img *.bin);;All Files (*)"));
    qDebug() << "img file name -> " <<  fileName << endl;
    if(fileName.size() == 0)
    {
        QMessageBox::critical(this,"open img fail","open img fail");
        return;
    }


    blkid_cache cache;
    std::string str = fileName.toStdString();
    int ret = blkid_get_cache(&cache, str.c_str());
    qDebug() << "Open file: " << fileName << " ret: " << ret;
    if(ret < 0 )
    {
        QMessageBox::critical(this,"open img fail","open img fail");
        return;
    }



}
