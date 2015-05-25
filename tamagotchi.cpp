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
    resistenciaTotal = Constantes.MAX_RESISTENCIA;
}

Tamagotchi::~Tamagotchi(){

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
    if(tiempoEspera > 0)
        return false;
    tiempoEspera = Constantes.TIEMPO_ESPERA;
    hambre.liberarTope();
    return true;
}

bool Tamagotchi::dormir(){
    if(tiempoEspera > 0)
        return false;
    tiempoEspera = Constantes.TIEMPO_ESPERA;
    sueno.liberarTope();
    return true;
}

bool Tamagotchi::curar(){
    if(tiempoEspera > 0)
        return false;
    tiempoEspera = Constantes.TIEMPO_ESPERA;
    enfermedad.liberarTope();
    return true;
}

bool Tamagotchi::asear(){
    if(tiempoEspera > 0)
        return false;
    tiempoEspera = Constantes.TIEMPO_ESPERA;
    desechos.liberarTope();
    return true;
}

void Tamagotchi::usarRegalo(){
    if(!misRegalos.getFrente())
        return;
    string tipo = misRegalos.getFrente()->tipo;
    if (tipo == "Hambre")
        hambre.liberarTope();
    else if (tipo == "Sueno")
        sueno.liberarTope();
    else if (tipo == "Enfermedad")
        enfermedad.liberarTope();
    else if (tipo == "Desechos")
        desechos.liberarTope();
}

bool Tamagotchi::chequiar(){
    if (victConsecutivas >=3){
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
    }else if(victConsecutivas <=-3){
        int cant = 0;
        if (hambre.getTope())
            cant+=hambre.getTope()->valor;
        if (enfermedad.getTope())
            cant+=enfermedad.getTope()->valor;
        if (desechos.getTope())
            cant+=desechos.getTope()->valor;
        if (sueno.getTope())
            cant+=sueno.getTope()->valor;
        restarVida(cant);
    }
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

void Tamagotchi::agregarActividad(int tipo){
    int val;
    if(tipo<0 || tipo > 3)
        val = rand()%4;
    else
        val = tipo;
    switch (val) {
    case 0:
        if(hambre.getTope())
            hambre.agregar("NM", hambre.getTope()->valor+1);
        else
            hambre.agregar("NM", 1);
        break;
    case 1:
        if(desechos.getTope())
            desechos.agregar("NM", desechos.getTope()->valor+1);
        else
            desechos.agregar("NM", 1);
        break;
    case 2:
        if(enfermedad.getTope())
            enfermedad.agregar("NM", enfermedad.getTope()->valor+1);
        else
            enfermedad.agregar("NM", 1);
        break;
    case 3:
        if(sueno.getTope())
            sueno.agregar("NM", sueno.getTope()->valor+1);
        else
            sueno.agregar("NM", 1);
        break;
    }
}
