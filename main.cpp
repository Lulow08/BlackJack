// REPOSITORIO: https://github.com/Lulow08/BlackJack.git

#include "Vista.h"
#include "Crupier.h"
#include "Jugador.h"
#include "Mazo.h"
#include "Controlador.h"
#include "Apuesta.h"
#include <iostream>


// TODO: mover logica de juego a controlador?
GameState revisarEstadoInicial(Jugador& jugador, Crupier& crupier) {
    if(crupier.getValorDeMano() > 21)
    return GANAR;

    else if(crupier.getValorDeMano() == 21)
    return PERDER;

    else if(jugador.getValorDeMano() > 21)
    return BUST;

    else if(jugador.getValorDeMano() == 21)
    return BLACKJACK;

    else if(jugador.getValorDeMano() == crupier.getValorDeMano())
    return EMPATE; // Revisar si aplica, o solo para blackjack

    else
    return NONE;
}

GameState revisarEstadoPlantarse(Jugador& jugador, Crupier& crupier) {
    if(crupier.getValorDeMano() > 21)
    return GANAR;

    else if(jugador.getValorDeMano() > crupier.getValorDeMano())
    return GANAR;

    else if(jugador.getValorDeMano() < crupier.getValorDeMano())
    return PERDER;

    else if(crupier.getValorDeMano() == 21)
    return PERDER;

    else if(jugador.getValorDeMano() == crupier.getValorDeMano())
    return EMPATE;

    else
    return NONE;
}

GameState revisarEstadoTomar(Jugador& jugador, Crupier& crupier) {
    if(jugador.getValorDeMano() > 21)
    return BUST;

    else if(jugador.getValorDeMano() == 21)
    return BLACKJACK;

    else if(jugador.getValorDeMano() < 21)
    return NONE;

    else
    return NONE;
}

void empezarRonda(Vista& vista, const Controlador& controlador, Jugador& jugador, Crupier& crupier, Apuesta& apuesta, const std::string& nombre) {
    crupier.empezarNuevaRonda(jugador);
    vista.mostrarPantallaJuego(nombre, apuesta.getDineroTotal(), apuesta.getApuestaActual(),
                               std::to_string(jugador.getValorDeMano()), std::to_string(crupier.getValorDeMano()),
                               revisarEstadoInicial(jugador, crupier));
    char opcionAccion = controlador.getOpcionChar("TP", JUEGO);
    switch (opcionAccion) {
    case 'T':
        crupier.darCartaAJugador(jugador, 1);
        vista.mostrarPantallaJuego(nombre, apuesta.getDineroTotal(), apuesta.getApuestaActual(),
                               std::to_string(jugador.getValorDeMano()), std::to_string(crupier.getValorDeMano()),
                               revisarEstadoTomar(jugador, crupier));
        std::cin.get();
        break;
    
    case 'P':
        vista.mostrarPantallaJuego(nombre, apuesta.getDineroTotal(), apuesta.getApuestaActual(),
                               std::to_string(jugador.getValorDeMano()), std::to_string(crupier.getValorDeMano()),
                               revisarEstadoPlantarse(jugador, crupier));
        std::cin.get();
        break;
    }
}

void prepararNuevaPartida(Vista& vista, const Controlador& controlador, Jugador& jugador, Crupier& crupier, Apuesta& apuesta) {
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
                empezarRonda(vista, controlador, jugador, crupier, apuesta, nombre);
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
    Mazo mazo;

    Jugador jugador(vista);
    Crupier crupier(mazo, vista);
    Apuesta apuesta;
    Controlador controlador(vista, jugador, crupier, apuesta);

    while (true) {
        // Menu principal
        vista.mostrarPantallaPrincipal();
        int opcion = controlador.getOpcionInt(1, 5);

        switch (opcion) {
            case 1:
                prepararNuevaPartida(vista, controlador, jugador, crupier, apuesta);
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