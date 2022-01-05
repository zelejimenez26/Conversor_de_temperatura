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
    connect(ui->inCent,SIGNAL(valueChanged(int)),this,SLOT(cent2kel(int)));

    //Conectar el dial de fahrenheit con el slot de ESTA clase
    connect(ui->inFar,SIGNAL(valueChanged(int)),this,SLOT(fahr2cent(int)));
    connect(ui->inFar,SIGNAL(valueChanged(int)),this,SLOT(fahr2kel(int)));

    //Conectar el dial de kelvin con el slot de ESTA clase
    connect(ui->inKel, SIGNAL(valueChanged(int)), this, SLOT(kel2cent(int)));
    connect(ui->inKel, SIGNAL(valueChanged(int)), this, SLOT(kel2fahr(int)));
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

void MainWindow::cent2kel(int i)
{
    if(ui->inCent->hasFocus()){
        int k=i+273.15;
        ui->inKel->setValue(k);
    }
}

void MainWindow::fahr2cent(int i)
{
    if(ui->inFar->hasFocus()){
        int c=(i-32)*5.0/9;
        ui->inCent->setValue(c);
    }
}

void MainWindow::fahr2kel(int i)
{
    if(ui->inFar->hasFocus()){
        float k=(i-32)*5.0/9+273.15;
        ui->inKel->setValue(k);
    }

}

void MainWindow::kel2cent(int i)
{
    if(ui->inKel->hasFocus()){
        int c=i-273.15;
        ui->inCent->setValue(c);
    }
}

void MainWindow::kel2fahr(int i)
{
    if(ui->inKel->hasFocus()){
        int f=(i-273.15)*9.0/5+32;
        ui->inFar->setValue(f);
    }

}
