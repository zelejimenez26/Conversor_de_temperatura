#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Conectar el dial de centigrados con el slot de ESTA clase
    connect(ui->inCent,SIGNAL(valueChanged(int)),this,SLOT(cent2fahr(int)));
    //Conectar el dial de fahrenheit con el slot de ESTA clase
    connect(ui->inFar,SIGNAL(valueChanged(int)),this,SLOT(fahr2cent(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cent2fahr(int cent)
{
    if(ui->inCent->hasFocus()){ //hasFocus cuandp el usuario esta sobre un boton o ventana
        int fahrenheit=(cent*9.0/5)+32;
        //ui->outFar->display(fahrenheit);
        ui->inFar->setValue(fahrenheit);
    }

}

void MainWindow::fahr2cent(int i)
{
    if(ui->inFar->hasFocus()){
        int c=(i-32)*5.0/9;
        ui->inCent->setValue(c);
    }
}

