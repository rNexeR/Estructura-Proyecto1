#include "CrearTamagotchi.h"
#include "ui_CrearTamagotchi.h"

CrearTamagotchi::CrearTamagotchi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CrearTamagotchi)
{
    ui->setupUi(this);
}

CrearTamagotchi::~CrearTamagotchi()
{
    delete ui;
}
