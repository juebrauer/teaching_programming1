#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton  , SIGNAL (clicked(bool)), this, SLOT (slotButton1Clicked(bool)));
    connect(ui->pushButton_2, SIGNAL (clicked(bool)), this, SLOT (slotButton2Clicked(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::slotButton1Clicked(bool checked)
{
    ui->lineEdit->setText( "Button1 clicked" );
}


void MainWindow::slotButton2Clicked(bool checked)
{
    ui->lineEdit->setText( "Button2 clicked" );
}