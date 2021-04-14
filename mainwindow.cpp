#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QString>
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
            tr("Open Address Book"), "",
            tr("img file (*.img *.bin);;All Files (*)"));
    qDebug() << "img file name -> " <<  fileName << endl;
    if(fileName.size() != 0)
    {

    }

}
