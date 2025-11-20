#include "Vista.h"
#include "Crupier.h"

#include <iostream>

int main() {
    Vista vista;
    Mazo mazo;
    Crupier crupier(mazo, vista);
    Jugador jugador(vista);

    crupier.empezarNuevaRonda(jugador);
    vista.imprimirMano(JUGADOR);
    std::cout << "\n\n";
    vista.imprimirMano(CRUPIER);

    std::cin.get();
    return 0;
}