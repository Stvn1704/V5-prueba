#ifndef HABILIDAD_H
#define HABILIDAD_H
#include "Jugador.h"
#include <string>
using namespace std;
class Habilidad {
public:
    virtual void usar(Jugador* jugador, Jugador* objetivo) = 0;
    virtual string obtenerNombre() const = 0;
    virtual ~Habilidad() {}
};
#endif