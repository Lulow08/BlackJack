// REPOSITORIO: https://github.com/Lulow08/BlackJack.git

#include "Vista.h"
#include "Crupier.h"
#include "Jugador.h"
#include "Mazo.h"
#include <iostream>

// TODO: mover responsabilidad y usar controlador
int leerOpcion(int min, int max) {
    int opcion;

    while (true) {
        std::cout << "\n          Ingrese una opción: ";
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
        vista.mostrarMenuPrincipal();
        int opcion = leerOpcion(1, 5);

        switch (opcion) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                return 0;
        }
    }
    return 0;
}
