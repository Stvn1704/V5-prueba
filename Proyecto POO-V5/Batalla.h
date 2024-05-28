#ifndef BATALLA_H
#define BATALLA_H
#include "Jugador.h"
using namespace std;
class Batalla {
public:
    static void simular(Jugador& jugador1, Jugador& jugador2) {
        while (jugador1.obtenerPuntosVida() > 0 && jugador2.obtenerPuntosVida() > 0) {
            cout << "\nTurno del jugador " << jugador1.obtenerNombre() << ":\n";
            jugador1.mostrarInformacionJugador();
            jugador1.usarHabilidadEspecial(&jugador2);

            if (jugador2.obtenerPuntosVida() <= 0) {
                cout << "\n¡El jugador " << jugador1.obtenerNombre() << " ha ganado la batalla!\n";
                return;
            }

            cout << "\nTurno del jugador " << jugador2.obtenerNombre() << ":\n";
            jugador2.mostrarInformacionJugador();
            jugador2.usarHabilidadEspecial(&jugador1);
            if (jugador1.obtenerPuntosVida() <= 0) {
                cout << "\n¡El jugador " << jugador2.obtenerNombre() << " ha ganado la batalla!\n";
                return;
            }
        }
    }
};
#endif
