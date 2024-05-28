#ifndef ATAQUEESPECIAL_H
#define ATAQUEESPECIAL_H
#include "Habilidad.h"
#include "Jugador.h"
using namespace std;
class AtaqueEspecial : public Habilidad {
private:
    int danio;
public:
    AtaqueEspecial(int _danio) : danio(_danio) {}

    void usar(Jugador* jugador, Jugador* objetivo) override {
        cout << jugador->obtenerNombre() << " usa ataque especial\n";
        objetivo->recibirDanio(danio);
    }

    string obtenerNombre() const override {
        return "Ataque Especial";
    }
};
#endif