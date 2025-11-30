// REPOSITORIO: https://github.com/Lulow08/BlackJack.git

#include "Vista.h"
#include "Crupier.h"
#include "Jugador.h"
#include "Mazo.h"
#include "Controlador.h"
#include "Apuesta.h"
#include <iostream>

int main() {
    Vista vista;
    Mazo mazo;
    Apuesta apuesta;

    Crupier crupier(mazo, vista);
    Jugador jugador(vista);
    Controlador controlador(vista, jugador, apuesta);

    while (true) {
        vista.mostrarPantallaPrincipal();
        int opcion = controlador.getOpcionInt(1, 5);

        switch (opcion) {
            case 1: {
                vista.limpiarPantalla();
                vista.mostrarTitulo();
                std::string nombre = controlador.getNombreJugador(3, 8);
                jugador.setNombre(nombre);

                bool salirDeApuesta{};

                do {
                    vista.mostrarPantallaApuesta(nombre, apuesta.getDineroTotal(), apuesta.getApuestaActual());
                    char opcionApuesta = controlador.getOpcionChar("WQCVB", APUESTA);

                    switch (opcionApuesta) {
                        case 'W':
                            crupier.empezarNuevaRonda(jugador);
                            vista.mostrarPantallaJuego();
                            std::cin.get();
                            salirDeApuesta = true;
                            break;
                        
                        case 'C':
                            apuesta.aumentarApuesta(100);
                            break;

                        case 'V':
                            apuesta.aumentarApuesta(250);
                            break;

                        case 'B':
                            apuesta.aumentarApuesta(500);
                            break;

                        case 'Q':
                            apuesta.resetearApuesta();
                            salirDeApuesta = true;
                            break;
                    }
                } while (!salirDeApuesta);
            }
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