#include "Cuidar.h"
#include "ui_Cuidar.h"

Cuidar::Cuidar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cuidar)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(2000);
    segundos = 0;
}

Cuidar::~Cuidar()
{
    delete ui;
}

void Cuidar::closeEvent (QCloseEvent *event)
{
    closeWindow();
}

void Cuidar::closeWindow(){
    cout<<"cerrando"<<endl;
    timer->stop();
}

void Cuidar::setParametros(list<Tamagotchi*>* animales, Tamagotchi* cuidar){
    this->animales = animales;
    this->actual = cuidar;

    string nombre = cuidar->getNombre();
    int coins = cuidar->getCantCoins();
    int regalos = cuidar->getCantRegalos();
    int vida = cuidar->getVida();
    int hambre = (cuidar->getHambre() / MAX_ACTIVIDADDES)*100;
    int sueno = (cuidar->getSueno() / MAX_ACTIVIDADDES)*100;
    int enfermo = (cuidar->getEnfermo() / MAX_ACTIVIDADDES)*100;
    int desechos = (cuidar->getDesechos() / MAX_ACTIVIDADDES)*100;

    ui->vida->setValue(vida);
    ui->hambre->setValue(hambre);
    ui->enfermo->setValue(enfermo);
    ui->sueno->setValue(sueno);
    ui->sucio->setValue(desechos);

    ui->txtnombre->setText(QString::fromStdString(nombre));
    ui->txtcoins->setText(QString::number(coins));
    ui->txtregalos->setText(QString::number(regalos));
}

void Cuidar::update(){
    actual->chequiar();
    segundos+=1;

    if(actual->getTiempoEspera()>0)
        actual->restarTiempoEspera();
    else
        changeButtonsState(true);

    if(segundos % TIEMPO_NUEVA_ACTIVIDAD == 0)
        actual->agregarActividad(-1);

    if(animales->size() != ui->cmbanimales->count()){
        ui->cmbanimales->clear();
        for(list<Tamagotchi*>::iterator i = animales->begin(); i != animales->end(); i++){
            string nombre = (*i)->getNombre();
            ui->cmbanimales->addItem(QString::fromStdString(nombre));
        }
    }

    int coins = actual->getCantCoins();
    int regalos = actual->getCantRegalos();
    int vida = actual->getVida();
    double hambre = (actual->getHambre()*100) / MAX_ACTIVIDADDES;
    double sueno = (actual->getSueno()*100) / MAX_ACTIVIDADDES;
    double enfermo = (actual->getEnfermo()*100) / MAX_ACTIVIDADDES;
    double desechos = (actual->getDesechos()*100) / MAX_ACTIVIDADDES;

    cout<<hambre<<" , "<<sueno<<" , "<<enfermo<<" , "<<desechos<<endl;

    if(hambre == 100 || sueno == 100 || enfermo ==100 || desechos == 100)
        actual->agregarDerrota("Una o mas Pilas de Actividades estan Full");

    if(segundos > 50 && hambre < 100 && sueno < 100 && enfermo < 100 && desechos < 0)
        actual->agregarVictoria("Todas las Pilas de Actividades estan Vacias");

    ui->vida->setValue(vida);
    ui->hambre->setValue(hambre);
    ui->sueno->setValue(sueno);
    ui->enfermo->setValue(enfermo);
    ui->sucio->setValue(desechos);

    ui->txtcoins->setText(QString::number(coins));
    ui->txtregalos->setText(QString::number(regalos));
}

void Cuidar::changeButtonsState(bool state){
    ui->pushButton->setEnabled(state);
    ui->pushButton_2->setEnabled(state);
    ui->pushButton_3->setEnabled(state);
    ui->pushButton_4->setEnabled(state);
}

void Cuidar::on_pushButton_clicked()//Hambre
{
    actual->alimentar();
    actual->setTiempoEspera(TIEMPO_ESPERA);
    changeButtonsState(false);
}

void Cuidar::on_pushButton_2_clicked()//Sueno
{
    actual->dormir();
    actual->setTiempoEspera(TIEMPO_ESPERA);
    changeButtonsState(false);
}

void Cuidar::on_pushButton_3_clicked()//Enfermo
{
    actual->curar();
    actual->setTiempoEspera(TIEMPO_ESPERA);
    changeButtonsState(false);
}

void Cuidar::on_pushButton_4_clicked()//Desechos
{
    actual->asear();
    actual->setTiempoEspera(TIEMPO_ESPERA);
    changeButtonsState(false);
}

void Cuidar::on_pushButton_5_clicked()//Donar
{
    if(ui->txtcoins->text().toInt() <=0)
        return;
    int x = ui->cmbanimales->currentIndex();
    list<Tamagotchi*>::iterator i = animales->begin();
    for(int y = 0; y<x; y++)
        i++;
    Tamagotchi* donar = (*i);
    if(donar != actual)
        actual->regalarCoin(donar);
}

void Cuidar::on_pushButton_6_clicked()//Regalo
{
    if(ui->txtregalos->text().toInt() <=0)
        return;
    actual->usarRegalo();
}
