#ifndef TAMAGOTCHI_H
#define TAMAGOTCHI_H
#include "Pila.h"
#include "Cola.h"
#include "constantes.h"


class Tamagotchi
{
public:
    Tamagotchi(string nombre, int fh, int fs, int fe, int fd);
    ~Tamagotchi();
    void recibirCoin(Nodo<int> regalo);
    void regalarCoin(Tamagotchi* destino);
    bool alimentar();
    bool dormir();
    bool curar();
    bool asear();
    void usarRegalo();
    bool chequiar();

    //gets y sets
    int getTiempoEspera();
    int getResistencia();
    int getVida();

    void setTiempoEspera(int cant);
    int setValoresResistencia(int rhambre, int rsueno, int renfermedad, int rdesechos);

    void restarVida(int cant);
    void agregarActividad(int tipo);

private:
    string nombre;
    int vida, tiempoEspera, resistenciaTotal;

    //atributo para la obtencion de coins
    int victConsecutivas;

    //valores de resistencias
    int fhambre, fsueno, fenfermedad, fdesechos;

    //Pilas de Actividades
    Pila<int> hambre, sueno, enfermedad, desechos;
    Cola<int> misCoins, misRegalos;
    Cola<string> logros;
};

#endif // TAMAGOTCHI_H
