#include "scrappy.h"
#include "ui_scrappy.h"

Scrappy::Scrappy(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Scrappy)
{
    ui->setupUi(this);
}

Scrappy::~Scrappy()
{
    delete ui;
}
