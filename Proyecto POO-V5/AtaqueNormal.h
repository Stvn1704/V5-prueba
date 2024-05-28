#ifndef ATAQUENORMAL_H
#define ATAQUENORMAL_H
#include "Habilidad.h"
#include "Jugador.h"
using namespace std;

class AtaqueNormal : public Habilidad {
private:
    int danio;
public:
    AtaqueNormal(int _danio) : danio(_danio) {}

    void usar(Jugador* jugador, Jugador* objetivo) override{
        cout << jugador->obtenerNombre() << " usa ataque normal\n";
        objetivo->recibirDanio(danio);
    }

    string obtenerNombre() const override {
        return "Ataque Normal";
    }
};
#endif