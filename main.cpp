// REPOSITORIO: https://github.com/Lulow08/BlackJack.git

#include "Vista.h"
#include "Crupier.h"
#include "Jugador.h"
#include "Mazo.h"
#include "Controlador.h"
#include "Apuesta.h"
#include <iostream>

void empezarRonda(Vista& vista, const Controlador& controlador, Jugador& jugador, Apuesta& apuesta) {
    Mazo mazo;
    Crupier crupier(mazo, vista);

    crupier.empezarNuevaRonda(jugador);
    vista.mostrarPantallaJuego();
    std::cin.get();
}

void prepararNuevaPartida(Vista& vista, const Controlador& controlador, Jugador& jugador, Apuesta& apuesta) {
    vista.limpiarPantalla();
    vista.mostrarTitulo();

    // Sección donde se solicita el nombre al jugador
    std::string nombre = controlador.getNombreJugador(3, 8);
    jugador.setNombre(nombre);

    bool salirDeApuesta{};
    bool dineroInsuficiente{};
    
    // Menu de apuesta
    do {
        vista.mostrarPantallaApuesta(nombre, apuesta.getDineroTotal(), apuesta.getApuestaActual());

        if(dineroInsuficiente)
        vista.mostrarTexto("Dinero insuficiente", "\e[1;31m");
        
        char opcionApuesta = controlador.getOpcionChar("WQCVB", APUESTA);
        switch (opcionApuesta) {
            case 'W':
                empezarRonda(vista, controlador, jugador, apuesta);
                salirDeApuesta = true;
                break;
            
            case 'C':
                if(!apuesta.aumentarApuesta(100))
                dineroInsuficiente = true;
                break;

            case 'V':
                if(!apuesta.aumentarApuesta(250))
                dineroInsuficiente = true;
                break;

            case 'B':
                if(!apuesta.aumentarApuesta(500))
                dineroInsuficiente = true;
                break;

            case 'Q':
                apuesta.resetearApuesta();
                salirDeApuesta = true;
                break;
        }
    } while (!salirDeApuesta);
}

int main() {
    Vista vista;

    Jugador jugador(vista);
    Apuesta apuesta; // Se crea aqui porque el contructor de controlador la requiere
    Controlador controlador(vista, jugador, apuesta);

    while (true) {
        // Menu principal
        vista.mostrarPantallaPrincipal();
        int opcion = controlador.getOpcionInt(1, 5);

        switch (opcion) {
            case 1:
                prepararNuevaPartida(vista, controlador,  jugador, apuesta);
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