#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
#include <vector>
#include <iostream>
#include "Habilidad.h"
#include "Personaje.h"
#include "Batalla.h"
using namespace std;
    
    
class Jugador {
    protected:
    string nombre;
    int vida;
    int ataque;
    int puntosHabilidad;
    Personaje* personaje;
    vector<Habilidad*> habilidadesEspeciales;

    public:
    Jugador(const string& _nombre, Personaje* _personaje, int _puntosHabilidad)
        : nombre(_nombre), vida(_personaje->obtenerVida()), ataque(_personaje->obtenerAtaque()), puntosHabilidad(_puntosHabilidad), personaje(_personaje) {}

    void agregarHabilidad(Habilidad* habilidad) {
        habilidadesEspeciales.push_back(habilidad);
    }

    void usarHabilidadEspecial(Jugador* objetivo) {
        cout << "\n" << nombre << " elige una habilidad especial:\n";
        for (size_t i = 0; i < habilidadesEspeciales.size(); ++i) {
            cout << i + 1 << ". " << habilidadesEspeciales[i]->obtenerNombre() << "\n";
        }

        int opcion;
        cout << "Selecciona una habilidad: ";
        cin >> opcion;

        if (opcion > 1 && opcion <= habilidadesEspeciales.size()) {
            if (puntosHabilidad > 0) {
                habilidadesEspeciales[opcion - 1]->usar(this, objetivo);
                puntosHabilidad--;
          } else {
                cout << "No tienes suficientes puntos de habilidad para usar esta habilidad.\n";
            }
        } else {
            if(opcion==1){
                habilidadesEspeciales[0]->usar(this, objetivo);
            }else{
                cout << "Opción inválida. Pierde su turno.\n";
            }
        }
    }

    void recibirCuracion(int cantidadCuracion) {
        vida += cantidadCuracion;
        cout << "Vida de " << nombre << " aumentada en " << cantidadCuracion << ". Vida actual: " << vida << "\n";
    }

    void mostrarInformacionJugador() {
        cout << nombre << " (" << personaje->obtenerNombre() << "), Vida: " << vida << ", Ataque: " << ataque << ", Puntos de Habilidad: " << puntosHabilidad << "\n";
    }

    void atacar(Jugador* objetivo) {
        objetivo->recibirDanio(ataque);
    }

    void recibirDanio(int cantidad) {
        vida -= cantidad;
    }

    int obtenerPuntosVida() const { return vida; }
    int obtenerPuntosHabilidad() const { return puntosHabilidad; }

    string obtenerNombre() const {
        return nombre;
    }

    virtual ~Jugador() {
        for (size_t i = 0; i < habilidadesEspeciales.size(); ++i) {
            delete habilidadesEspeciales[i];
        }
        delete personaje;
    }
};
#endif