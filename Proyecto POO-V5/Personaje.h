#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <string>
using namespace std;
class Personaje {
protected:
    string nombre;
    int vida;
    int ataque;
public:
    Personaje(const string& _nombre, int _vida, int _ataque)
        : nombre(_nombre), vida(_vida), ataque(_ataque) {}

    virtual string obtenerNombre() const { return nombre; }
    virtual int obtenerVida() const { return vida; }
    virtual int obtenerAtaque() const { return ataque; }

    virtual ~Personaje() {}
};
#endif