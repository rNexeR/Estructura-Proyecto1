#include "tamagotchi.h"

Tamagotchi::Tamagotchi(string nombre, int fh, int fs, int fe, int fd){
    this->nombre = nombre;
    fhambre = fh;
    fsueno = fs;
    fenfermedad = fe;
    fdesechos = fd;
    tiempoEspera = 0;
    vida = 100;
    victConsecutivas = 0;
    resistenciaTotal = MAX_RESISTENCIA;
}

Tamagotchi::Tamagotchi(){
    nombre = "";
    fhambre = 0;
    fsueno = 0;
    fenfermedad = 0;
    fdesechos = 0;
    tiempoEspera = 0;
    vida = 100;
    victConsecutivas = 0;
    resistenciaTotal = MAX_RESISTENCIA;
}

Tamagotchi::~Tamagotchi(){

}

string Tamagotchi::getNombre(){
    return nombre;
}

int Tamagotchi::getHambre(){
    if(hambre.getTope())
        return hambre.getTope()->valor;
    return 0;
}

int Tamagotchi::getSueno(){
    if(sueno.getTope())
        return sueno.getTope()->valor;
    return 0;
}

int Tamagotchi::getEnfermo(){
    if(enfermedad.getTope())
        return enfermedad.getTope()->valor;
    return 0;
}

int Tamagotchi::getDesechos(){
    if(desechos.getTope())
        return desechos.getTope()->valor;
    return 0;
}

int Tamagotchi::getCantCoins(){
    return misCoins.size;
}

int Tamagotchi::getCantRegalos(){
    return misRegalos.size;
}

void Tamagotchi::recibirCoin(Nodo<int> regalo){
    misRegalos.agregar(regalo.tipo, regalo.valor);
}

void Tamagotchi::regalarCoin(Tamagotchi* destino){
    if(!misCoins.getFrente())
        return;
    destino->recibirCoin(*misCoins.getFrente());
    misCoins.liberarFrente();
}

bool Tamagotchi::alimentar(){
    if(hambre.getTope())
        hambre.liberarTope();
    else
        agregarActividad(3);
    return true;
}

bool Tamagotchi::dormir(){
    if(sueno.getTope())
        sueno.liberarTope();
    else
        agregarActividad(2);
    return true;
}

bool Tamagotchi::curar(){
    if(enfermedad.getTope())
        enfermedad.liberarTope();
    else
        agregarActividad(1);
    return true;
}

bool Tamagotchi::asear(){
    if(desechos.getTope())
        desechos.liberarTope();
    else
        agregarActividad(0);
    return true;
}

void Tamagotchi::usarRegalo(){
    if(!misRegalos.getFrente())
        return;
    string tipo = misRegalos.getFrente()->tipo;
    misRegalos.liberarFrente();
    if (tipo == "Hambre"){
        alimentar();
    }else if (tipo == "Sueno"){
        dormir();
    }else if (tipo == "Enfermedad"){
        curar();
    }else if (tipo == "Desechos"){
        asear();
    }
}

void Tamagotchi::agregarVictoria(string mensaje){
    logros.agregar("Victoria", mensaje);
}

void Tamagotchi::agregarDerrota(string mensaje){
    logros.agregar("Derrota", mensaje);
}

void Tamagotchi::chequiar(){
    if(vida <= 0)
        return;
    if(!hambre.getTope() && !enfermedad.getTope() && !desechos.getTope() && !sueno.getTope())
        victConsecutivas++;

    if (victConsecutivas>=5){
        victConsecutivas=0;
        int val = rand()%4;
        string tipo;
        switch (val) {
        case 0:
            tipo = "Hambre";
            break;
        case 1:
            tipo = "Desechos";
            break;
        case 2:
            tipo = "Enfermedad";
            break;
        case 3:
            tipo = "Sueno";
            break;
        }
        misCoins.agregar(tipo, 1);
    }

    int cant = 0;
    if (hambre.getTope())
        cant+=(hambre.getTope()->valor - fhambre);
    if (enfermedad.getTope())
        cant+=(enfermedad.getTope()->valor - fenfermedad);
    if (desechos.getTope())
        cant+=(desechos.getTope()->valor - fdesechos);
    if (sueno.getTope())
        cant+=(sueno.getTope()->valor - fsueno);
    cout<<cant<<endl;
    if(cant>0)
        restarVida(cant);
}

//gets y sets
int Tamagotchi::getTiempoEspera(){
    return tiempoEspera;
}

int Tamagotchi::getResistencia(){
    return resistenciaTotal;
}

int Tamagotchi::getVida(){
    return vida;
}

void Tamagotchi::setTiempoEspera(int cant){
    tiempoEspera = cant;
}

int Tamagotchi::setValoresResistencia(int rhambre, int rsueno, int renfermedad, int rdesechos){
    fhambre = rhambre;
    fsueno = rsueno;
    fenfermedad = renfermedad;
    fdesechos = rdesechos;
}

void Tamagotchi::restarVida(int cant){
    vida-=cant;
    if (vida<0)
        vida = 0;
}

void Tamagotchi::restarTiempoEspera(){
    tiempoEspera--;
}

void Tamagotchi::agregarActividad(int tipo){
    int val;
    if(tipo<0 || tipo > 3)
        val = rand()%4;
    else
        val = tipo;
    switch (val) {
    case 0:
        if(hambre.size > MAX_ACTIVIDADDES)
            break;
        if(hambre.getTope()!=NULL){
            hambre.agregar("NM", hambre.getTope()->valor+1);
        }
        else
            hambre.agregar("NM", 1);
        break;
    case 3:
        if(desechos.size > MAX_ACTIVIDADDES)
            break;
        if(desechos.getTope()!=NULL){
            desechos.agregar("NM", desechos.getTope()->valor+1);
        }
        else
            desechos.agregar("NM", 1);
        break;
    case 2:
        if(enfermedad.size >= MAX_ACTIVIDADDES)
            break;
        if(enfermedad.getTope()!=NULL)
            enfermedad.agregar("NM", enfermedad.getTope()->valor+1);
        else
            enfermedad.agregar("NM", 1);
        break;
    case 1:
        if(sueno.size > MAX_ACTIVIDADDES)
            break;
        if(sueno.getTope()!=NULL)
            sueno.agregar("NM", sueno.getTope()->valor+1);
        else
            sueno.agregar("NM", 1);
        break;
    }
}
