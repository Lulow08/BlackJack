// REPOSITORIO: https://github.com/Lulow08/BlackJack.git

#include "Vista.h"
#include "Controlador.h"
#include "Jugador.h"
#include "Crupier.h"
#include "Mazo.h"
#include "Apuesta.h"

#include <iostream>

bool empezarRonda(Vista& vista, const Controlador& controlador, Jugador& jugador, Crupier& crupier, Apuesta& apuesta, const std::string& nombre) {
    crupier.empezarNuevaRonda();
    GameState estado = crupier.evaluarEstado();

    bool empezarNuevaRonda{};

    while(estado == NONE) {
        vista.mostrarPantallaJuego(nombre, apuesta.getDineroTotal(), apuesta.getApuestaActual(),
                                std::to_string(jugador.getValorDeMano()), std::to_string(crupier.getValorDeMano()),
                                estado);

        char opcionAccion = controlador.getOpcionChar("TP", JUEGO);

        // Menu de acciones
        switch (opcionAccion) {
        case 'T':
            crupier.darCartaAJugador(1);
            estado = crupier.evaluarEstado();
            break;
        
        case 'P':
            estado = crupier.decidirResultado();
            break;
        }
    }

    // Mostrar resultado del juego
    vista.mostrarPantallaJuego(nombre, apuesta.getDineroTotal(), apuesta.getApuestaActual(),
                        std::to_string(jugador.getValorDeMano()), std::to_string(crupier.getValorDeMano()),
                        estado);

    // Repartir el dinero de acuerdo al resultado
    if(estado == GANAR || estado == BLACKJACK) apuesta.ganar();
    if(estado == PERDER || estado == BUST) apuesta.perder();
    if(estado == EMPATE) apuesta.empatar();

    char opcionFinal = controlador.getOpcionChar("SN", JUEGO);

    switch (opcionFinal) {
    case 'S':
        empezarNuevaRonda = true;
        break;
    
    case 'N':
        // Solicitar Guardar partida (cuando se añada)
        apuesta.resetearApuesta();
        jugador.setNombre("");
        empezarNuevaRonda = false;
        break;
    }

    return empezarNuevaRonda;
}

bool prepararNuevaPartida(Vista& vista, const Controlador& controlador, Jugador& jugador, Crupier& crupier, Apuesta& apuesta) {
    vista.limpiarPantalla();
    vista.mostrarTitulo();

    std::string nombre{};

    // Sección donde se solicita el nombre al jugador (Si no lo ha hecho antes)
    if(jugador.getNombre() == "") {
        std::string nombre = controlador.getNombreJugador(3, 8);
        jugador.setNombre(nombre);
    }

    nombre = jugador.getNombre();

    bool salirDeApuesta{};
    bool dineroInsuficiente{};
    bool apuestaExitosa = true;
    
    // Menu de apuesta
    do {
        vista.mostrarPantallaApuesta(nombre, apuesta.getDineroTotal(), apuesta.getApuestaActual());

        if(dineroInsuficiente)
        vista.mostrarTexto("Dinero insuficiente", "\e[1;31m");

        if(!apuestaExitosa)
        vista.mostrarTexto("Debes apostar algo", "\e[1;31m");
        
        char opcionApuesta = controlador.getOpcionChar("WQCVB", APUESTA);
        switch (opcionApuesta) {
            case 'W':
                if(apuesta.getApuestaActual() == 0) {
                    apuestaExitosa = false;
                    break;
                }
                salirDeApuesta = true;
                apuestaExitosa = true;
                break;
            
            case 'C':
                if(!apuesta.aumentarApuesta(100))
                dineroInsuficiente = true;
                apuestaExitosa = true;
                break;

            case 'V':
                if(!apuesta.aumentarApuesta(250))
                dineroInsuficiente = true;
                apuestaExitosa = true;
                break;

            case 'B':
                if(!apuesta.aumentarApuesta(500))
                dineroInsuficiente = true;
                apuestaExitosa = true;
                break;

            case 'Q':
                apuesta.resetearApuesta();
                jugador.setNombre("");
                salirDeApuesta = true;
                apuestaExitosa = false;
                break;
        }
    } while (!salirDeApuesta);

    return apuestaExitosa;
}

int main() {
    Vista vista;
    Mazo mazo;

    Jugador jugador(vista);
    Crupier crupier(mazo, vista, jugador);
    Apuesta apuesta;
    Controlador controlador(vista, jugador, crupier, apuesta);

    while (true) {
        // Menu principal
        vista.mostrarPantallaPrincipal();
        int opcion = controlador.getOpcionInt(1, 5);

        switch (opcion) {
            // Empezar nueva partida
            case 1: {
                bool jugando = true;
                while(jugando) {
                    if(prepararNuevaPartida(vista, controlador, jugador, crupier, apuesta)){
                        jugando = empezarRonda(vista, controlador, jugador, crupier, apuesta, jugador.getNombre());
                    }
                    else {
                        jugando = false;
                    }
                }
            } break;
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