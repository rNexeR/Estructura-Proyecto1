#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    granja = new list<Tamagotchi*>;

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update(){
    if(granja->size() != ui->cmbAnimales->count()){
        ui->cmbAnimales->clear();
        for(list<Tamagotchi*>::iterator i = granja->begin(); i != granja->end(); i++){
            string nombre = (*i)->getNombre();
            ui->cmbAnimales->addItem(QString::fromStdString(nombre));
        }
    }
}

void MainWindow::on_cmbAnimales_currentIndexChanged(const QString &arg1)
{
    if(ui->cmbAnimales->count()<=0)
        return;
    int x = ui->cmbAnimales->currentIndex();
    list<Tamagotchi*>::iterator i = granja->begin();
    for(int y = 0; y<x; y++)
        i++;
    Tamagotchi* cuidar = (*i);
    cout<<cuidar->getNombre()<<endl;
    int vida = cuidar->getVida();
    double hambre = (cuidar->getHambre()*100) / MAX_ACTIVIDADDES;
    double sueno = (cuidar->getSueno()*100) / MAX_ACTIVIDADDES;
    double enfermo = (cuidar->getEnfermo()*100) / MAX_ACTIVIDADDES;
    double desechos = (cuidar->getDesechos()*100) / MAX_ACTIVIDADDES;

    ui->vida->setValue(vida);
    ui->hambre->setValue(hambre);
    ui->enfermo->setValue(enfermo);
    ui->sueno->setValue(sueno);
    ui->sucio->setValue(desechos);
}

void MainWindow::on_btnCuidar_2_clicked()//Crear
{
    CrearTamagotchi* Ventana = new CrearTamagotchi();
    Ventana->setGranja(granja);
    Ventana->show();
}

void MainWindow::on_btnCuidar_clicked()
{
    int x = ui->cmbAnimales->currentIndex();
    list<Tamagotchi*>::iterator i = granja->begin();
    for(int y = 0; y<x; y++)
        i++;
    Tamagotchi* cuidar = (*i);
    Cuidar* Ventana = new Cuidar();
    Ventana->setParametros(granja, cuidar);
    Ventana->show();
}
