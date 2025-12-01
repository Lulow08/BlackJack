/*
     ▄▄▄▄  ▄▄▄▄▄                                   ▄▄▄  ▄▄▄▀▀█   
   ▄▀    ▀▀     ▀▀▄▄▄▀▀▀▄           ▄▀▀▄▄▄▀▀▄   ▄▀▀   ▀▀   ▄ █   
  █  ▄███▄ ▄███  ▄   ▄▄ █▄▄▄▄   ▄▄▄▄█ ▄   ▄▄ ▀▄█  ▄███  ███▀ █   
 █  █▀  ███▀ ███  █▄█▀      █▄▄▀       █▄█▀      █▀  ██████ ▄▀   
 █ █     ██   ███  ██   ███     ▄███ █  ██   █  █     ██ ██ █    
 ▀▄ █  ▄ ██   ▄▀   ██  ██  ██▀ ██   ██  ██   ██▄ █  ▄ ██ ██ █    
  ▀▄ ▀▀  █▀▄█████  ██ ██   ██ ██    █   ██  █▀▀   ▀▀  ██ ██ █    
   ▀█▄  █     ▀███ ██ ██   ██ ██        ██▄▀██        ██ ██ █▄▄▄ 
    █  █▄       ██ ██  ▀█▄▄███ █▄   █  ▄██▀  ██       ██ ██    █ 
   ▄▀ ▀▀███     █ ▄██▄▀ ▀▀  █   ████  ███   ▄███  ▄██  ▀  █ ██ █ 
  ▄█▄▄▄  ▀███▄▄▀    ▀▀    ▄   █     ▄▄  ▀██   █▀ █▀▀██   ▄▀ ██ █ 
       ▀▄▄     ▄▄▀▀▀▄▄█▀▀▀ ▀▀▀ ▀▀▀▀▀  ▀▄▄   █▄   █   ████▀    ▄▀ 
          ▀▀▀▀▀                          ▀▀▀  ▀▀▄ ▀       ▄▀▀▀   
                                                ▀▄▄▄█▀▀▀▀▀  TM
    Proyecto: BlackJack
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    
    Repositorio: https://github.com/Lulow08/BlackJack.git
*/

#include "Vista.h"
#include "Controlador.h"
#include "Jugador.h"
#include "Crupier.h"
#include "Mazo.h"
#include "Apuesta.h"
#include "Serializador.h"

#include <iostream>

// Lógica de juego

bool empezarRonda(Vista& vista, const Controlador& controlador, Jugador& jugador,
                  Crupier& crupier, Apuesta& apuesta, const std::string& nombre, Serializador& serializador) {

    crupier.empezarNuevaRonda();
    GameState estado = crupier.evaluarEstado();

    bool empezarNuevaRonda{};

    // Bucle de partida no finalizada
    while(estado == NONE) {
        vista.mostrarPantallaJuego(nombre, apuesta.getDineroTotal(), apuesta.getApuestaActual(),
                                std::to_string(jugador.getValorDeMano()), std::to_string(crupier.getValorDeManoParcial()),
                                estado);

        char opcionAccion = controlador.getOpcionChar("TP", JUEGO);

        // Menu de acciones in game
        switch (opcionAccion) {
        case 'T':
            crupier.darCartaAJugador(1);
            estado = crupier.evaluarEstado();
            break;
        
        case 'P':
            estado = crupier.decidirResultado();
            break;
        }
    } // Fin de partida

    // Mostrar resultado del juego
    vista.mostrarPantallaJuego(nombre, apuesta.getDineroTotal(), apuesta.getApuestaActual(),
                        std::to_string(jugador.getValorDeMano()), std::to_string(crupier.getValorDeMano()),
                        estado);

    // Repartir el dinero de acuerdo al resultado
    if(estado == GANAR || estado == BLACKJACK) apuesta.ganar();
    if(estado == PERDER || estado == BUST) apuesta.perder();
    if(estado == EMPATE) apuesta.empatar();

    // Menu para continuar o salir
    char opcionFinal = controlador.getOpcionChar("SN", JUEGO);

    switch (opcionFinal) {
    case 'S':
        empezarNuevaRonda = true;
        break;
    
    case 'N':
        // Menu de guardado
        vista.mostrarMenuGuardado();
            char opcionGuardado = controlador.getOpcionChar("SN", GUARDADO);

            switch (opcionGuardado) {
                case 'S':
                    serializador.guardarPartida(jugador, apuesta);
                    break;
                case 'N':
                        break;
            }
        apuesta.resetearApuesta();
        jugador.setNombre("");
        empezarNuevaRonda = false;
        break;
    }

    return empezarNuevaRonda;
}

bool prepararNuevaPartida(Vista& vista, const Controlador& controlador, Jugador& jugador,
                          Crupier& crupier, Apuesta& apuesta, Serializador& serializador) {

    vista.limpiarPantalla();
    vista.mostrarTitulo();

    std::string nombre{};
    bool preguntarPorGuardado = true;

    // Sección donde se solicita el nombre al jugador (Si no lo ha hecho antes)
    if(jugador.getNombre() == "") {
        std::string nombre = controlador.getNombreJugador(3, 8);
        jugador.setNombre(nombre);
        preguntarPorGuardado = false;
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
            // Listo
            case 'W':
                if(apuesta.getApuestaActual() == 0) {
                    apuestaExitosa = false;
                    break;
                }
                salirDeApuesta = true;
                apuestaExitosa = true;
                break;
            
            // Apostar 100
            case 'C':
                if(!apuesta.aumentarApuesta(100))
                dineroInsuficiente = true;

                else {
                    dineroInsuficiente = false;
                    apuestaExitosa = true;
                }
                break;

            // Apostar 250
            case 'V':
                if(!apuesta.aumentarApuesta(250))
                dineroInsuficiente = true;

                else {
                    dineroInsuficiente = false;
                    apuestaExitosa = true;
                }
                break;

            // Apostar 500
            case 'B':
                if(!apuesta.aumentarApuesta(500))
                dineroInsuficiente = true;

                else {
                    dineroInsuficiente = false;
                    apuestaExitosa = true;
                }
                break;

            // Cancelar / Salir
            case 'Q':
                apuesta.resetearApuesta();
                jugador.setNombre("");
                salirDeApuesta = true;
                apuestaExitosa = false;

                // Menu de guardado
                if(preguntarPorGuardado) {
                    vista.mostrarMenuGuardado();
                    char opcionGuardado = controlador.getOpcionChar("SN", GUARDADO);

                    switch (opcionGuardado) {
                    case 'S':
                        serializador.guardarPartida(jugador, apuesta);
                        break;
                    
                    case 'N':
                        break;
                    }
                }
                break;
        }
    } while (!salirDeApuesta);

    return apuestaExitosa;
}

// Bucle principal
void cicloJuego(Vista& vista, const Controlador& controlador, Jugador& jugador,
                Crupier& crupier, Apuesta& apuesta, Serializador& serializador) {

    bool jugando = true;
    while(jugando) {
        if(prepararNuevaPartida(vista, controlador, jugador, crupier, apuesta, serializador)){
            jugando = empezarRonda(vista, controlador, jugador, crupier, apuesta, jugador.getNombre(), serializador);
        }
        else {
            jugando = false;
        }
    }
}

int main() {
    Vista vista;
    Mazo mazo;

    Jugador jugador(vista);
    Crupier crupier(mazo, vista, jugador);
    Apuesta apuesta;
    Controlador controlador(vista, jugador, crupier, apuesta);
    Serializador serializador("partida", vista, controlador);

    while (true) {
        // Menu principal
        vista.mostrarPantallaPrincipal();
        int opcion = controlador.getOpcionInt(1, 4);

        switch (opcion) {
            // Empezar nueva partida
            case 1:
                cicloJuego(vista, controlador, jugador, crupier, apuesta, serializador);
                break;
            // Cargar partida anterior
            case 2: {
                std::pair<std::string, int> datosGuardados = serializador.deserializarDatos();
                std::string nombre = datosGuardados.first;
                int dinero = datosGuardados.second;

                if (!nombre.empty() && dinero > 0) {
                    jugador.setNombre(nombre);
                    apuesta.setDineroTotal(dinero);

                    cicloJuego(vista, controlador, jugador, crupier, apuesta, serializador);
                }
            } break;

            // Mostrar reglas
            case 3:
                vista.mostrarReglas();
                std::cin.get();
                break;

            // Salir
            case 4:
                return 0;
        }
    }
    return 0;
}