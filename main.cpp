// REPOSITORIO: https://github.com/Lulow08/BlackJack.git

#include "Vista.h"
#include "Crupier.h"
#include "Jugador.h"
#include "Mazo.h"
#include "Controlador.h"
#include <iostream>

int main() {
    Vista vista;
    Mazo mazo;
    Crupier crupier(mazo, vista);
    Jugador jugador(vista);
    Controlador controlador(vista);

    vista.mostrarPantallaPrincipal();

    while (true) {
        int opcion = controlador.obtenerEleccionMenu(1, 5);

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
