#ifndef CURACION_H
#define CURACION_H
#include "Habilidad.h"
#include "Jugador.h"
using namespace std;

class Curacion : public Habilidad {
private:
    int cantidadCuracion;
public:
    Curacion(int _cantidadCuracion) : cantidadCuracion(_cantidadCuracion) {}

    void usar(Jugador* jugador, Jugador* objetivo) override {
        cout << jugador->obtenerNombre() << " usa curación (" << cantidadCuracion << " puntos de vida)\n";
        jugador->recibirCuracion(cantidadCuracion);
    }

    string obtenerNombre() const override {
        return "Curación";
    }
};
#endif