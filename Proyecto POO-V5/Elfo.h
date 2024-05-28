#ifndef ELFO_H
#define ELFO_H
#include "Personaje.h"
class Elfo : public Personaje {
public:
    Elfo() : Personaje("Elfo", 100, 30) {}
};
#endif