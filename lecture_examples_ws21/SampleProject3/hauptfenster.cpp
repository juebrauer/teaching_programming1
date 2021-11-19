#include "hauptfenster.h"
#include "ui_hauptfenster.h"

HauptFenster::HauptFenster(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HauptFenster)
{
    ui->setupUi(this);
}

HauptFenster::~HauptFenster()
{
    delete ui;
}

