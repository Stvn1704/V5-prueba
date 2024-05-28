#include <iostream>
#include <string>
#include <vector>
#include "Jugador.h"
#include "Habilidad.h"
#include "Personaje.h"
#include "Orco.h"
#include "Batalla.h"
#include "AtaqueNormal.h"
#include "Curacion.h"
#include "AtaqueEspecial.h"
#include "Elfo.h"
using namespace std;

// Función para seleccionar el tipo de ataque
int seleccionarTipoDeAtaque() {
    cout << "Selecciona el tipo de ataque:\n";
    cout << "1. Pequeño alcance\n";
    cout << "2. Mediano alcance\n";
    cout << "3. Largo alcance\n";

    int tipo;
    cin >> tipo;

    return tipo;
}

// Función para seleccionar el personaje
Personaje* seleccionarPersonaje() {
    cout << "Selecciona tu personaje:\n";
    cout << "1. Orco\n";
    cout << "2. Elfo\n";

    int opcion;
    cin >> opcion;

    if (opcion == 1) {
        return new Orco();
    } else if (opcion == 2) {
        return new Elfo();
    } else {
        cout << "Opción inválida, se seleccionará Orco por defecto.\n";
        return new Orco();
    }
}

// Función principal del programa
int main() {
    int tipoAtaque1 = seleccionarTipoDeAtaque();
    int tipoAtaque2 = seleccionarTipoDeAtaque();

    Personaje* personaje1 = seleccionarPersonaje();
    Personaje* personaje2 = seleccionarPersonaje();

    Jugador jugador1("Jugador 1", personaje1, 5-tipoAtaque1);
    Jugador jugador2("Jugador 2", personaje2, 5-tipoAtaque2);

    // Configurar habilidades basadas en el tipo de ataque seleccionado
    jugador1.agregarHabilidad(new AtaqueNormal(tipoAtaque1 * 10));
    jugador1.agregarHabilidad(new Curacion(20));
    jugador1.agregarHabilidad(new AtaqueEspecial(tipoAtaque1 * 15));

    jugador2.agregarHabilidad(new AtaqueNormal(tipoAtaque2 * 10));
    jugador2.agregarHabilidad(new Curacion(25));
    jugador2.agregarHabilidad(new AtaqueEspecial(tipoAtaque2 * 15));

    Batalla::simular(jugador1, jugador2);

    return 0;
}
