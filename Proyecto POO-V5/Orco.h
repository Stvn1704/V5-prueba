#ifndef ORCO_H
#define ORCO_H
#include "Personaje.h"
using namespace std;
class Orco : public Personaje {
public:
    Orco() : Personaje("Orco", 150, 25) {}
};

#endif