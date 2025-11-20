#include "Vista.h"
#include "Crupier.h"
#include "Jugador.h"
#include "Mazo.h"
#include <iostream>

// TODO: mover responsabilidad y usar controlador
int leerOpcion(int min, int max) {
    int opcion;

    while (true) {
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        // Validaciones de entrada
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Entrada inválida. Intente nuevamente\n";
            continue;
        }

        if (opcion >= min && opcion <= max)
            return opcion;

        std::cout << "Opción fuera de rango (" << min << "-" << max << ")\n";
    }
}

int main() {
    Vista vista;
    Mazo mazo;
    Crupier crupier(mazo, vista);
    Jugador jugador(vista);

    vista.mostrarTitulo();

    while (true) {
        vista.mostrarMenu();
        int opcion = leerOpcion(1, 5);

        switch (opcion) {
            case 1: {   
                vista.limpiarPantalla();

                crupier.empezarNuevaRonda(jugador);

                vista.mostrarTexto("\nCartas del jugador:");
                vista.imprimirMano(JUGADOR);

                vista.mostrarTexto("\n\nCartas del crupier:");
                vista.imprimirMano(CRUPIER);

                break;
            }

            case 2:
                vista.mostrarTexto("VERSIÓN DEMO - Funcion no implementada");
                break;
            case 3:
                vista.mostrarTexto("VERSIÓN DEMO - Funcion no implementada");
                break;
            case 4:
                vista.mostrarTexto("VERSIÓN DEMO - Funcion no implementada");
                break;

            case 5:
                return 0;
        }
    }
    return 0;
}
