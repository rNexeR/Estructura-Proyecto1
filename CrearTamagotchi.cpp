#include "CrearTamagotchi.h"
#include "ui_CrearTamagotchi.h"

CrearTamagotchi::CrearTamagotchi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CrearTamagotchi)
{
    ui->setupUi(this);
}

void CrearTamagotchi::setGranja(list<Tamagotchi*> *granja){
    this->granja = granja;
}

CrearTamagotchi::~CrearTamagotchi()
{
    delete ui;
}

void CrearTamagotchi::calcularTotal(){
    int total = (ui->spinBox->value()) + (ui->spinBox_2->value()) + (ui->spinBox_3->value()) + (ui->spinBox_4->value());
    ui->txttotal->setText(QString::number(total));
}

void CrearTamagotchi::on_spinBox_valueChanged(const QString &arg1)
{
    calcularTotal();
}

void CrearTamagotchi::on_spinBox_2_editingFinished()
{
    calcularTotal();
}

void CrearTamagotchi::on_spinBox_3_valueChanged(int arg1)
{
    calcularTotal();
}

void CrearTamagotchi::on_spinBox_4_valueChanged(int arg1)
{
    calcularTotal();
}

void CrearTamagotchi::on_pushButton_clicked()
{
    string name = ui->txtnombre->text().toStdString();
    int total = ui->txttotal->text().toInt();
    if (name != "" && total<=MAX_RESISTENCIA){
        int rh, re, rs, rd;
        rh = ui->spinBox->value();
        re = ui->spinBox_2->value();
        rs = ui->spinBox_3->value();
        rd = ui->spinBox_4->value();
        //cout<<rh<<" "<<
        granja->push_back(new Tamagotchi(name, rh, rs, re, rd));
    }
    ui->txtnombre->clear();
    ui->txttotal->clear();
}
