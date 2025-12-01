/*
    Proyecto: BlackJack
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Información CRC:
   
    Clase: Vista

    Responsabilidades:
        - Mostrar arte ASCII
        - Renderizar menús (principal, apuesta, acciones, guardado)
        - Renderizar manos con cartas apiladas horizontalmente
        - Mostrar pantallas completas (principal, apuesta, juego)
        - Mostrar estados del juego (GANAR, PERDER, BUST, EMPATE, BLACKJACK)
        - Mostrar información del juego (nombre, dinero, apuesta)
        - Limpia la pantalla
        - Solicitar input al usuario (controlador lo recibe)
        - Mostrar mensajes de error en pantalla completa
        - Mostrar reglas del juego

    Colaboradores:
        - Carta (obtiene información para renderizar)
        - Participante (usa enum Mano para distinguir colas)
        - Controlador (recibe solicitudes de input)

    @details Maneja toda la interfaz de usuario del juego usando caracteres Unicode y 
             colores ANSI. Implementa un sistema triple de colas: cartas del jugador, cartas 
             completas del crupier y cartas parciales del crupier (primera visible, resto 
             oculto). Renderiza cartas con efecto de profundidad apilándolas horizontalmente
             Coordina múltiples pantallas del juego mostrando información contextual según 
             el estado. Utiliza sangrías para centrar contenido visualmente
    
    Autores:
    Lesly Zapata
    Yostin Ramirez
    Juan Manuel Rosero
    Joseph Terreros
    Juan Esteban Mina

    Correos:
    lesly.zapata@correounivalle.edu.co
    yostin.ramirez@correounivalle.edu.co
    joseph.terreros@correounivalle.edu.co
    juan.encarnacion@correounivalle.edu.co
    juan.esteban.mina@correounivalle.edu.co

    @date Fecha: Diciembre 2025
*/

#pragma once

#include <string>
#include <vector>

#include "Carta.h"
#include "Apuesta.h"

enum Mano { JUGADOR, CRUPIER }; // Enum para elegir entre la cola de jugador o crupier en el metodo de Vista
enum GameState { NONE, GANAR, PERDER, BUST, EMPATE, BLACKJACK };

class Vista {
    public:
        Vista();

        // Prints
        void mostrarTitulo() const;
        void mostrarMenuPrincipal() const;
        void mostrarMenuApuesta() const;
        void mostrarMenuAcciones(GameState estado) const;
        void mostrarMenuGuardado() const;
        void mostrarGameData(const std::string& nombre, int dinero, int apuesta) const;
        void mostrarEstado(GameState estado) const;
        void mostrarReglas() const;

        // Pantallas
        void mostrarPantallaPrincipal() const;
        void mostrarPantallaApuesta(const std::string& nombre, int dinero, int apuesta);
        void mostrarPantallaJuego(const std::string& nombre, int dinero, int apuesta,
                                  const std::string& valorJugador, const std::string& valorCrupier,
                                  GameState estado);
        
        // Utils
        void solicitarInput(const std::string& mensaje) const;
        void mostrarTexto(const std::string& texto) const;
        void mostrarTexto(const std::string& texto, const std::string& color) const;
        void mostrarTexto(const std::string& prefijo, const std::string& texto, const std::string& sufijo) const;
        void mostrarErrorFullScreen(const std::string& texto) const;
        void limpiarPantalla() const;

        // Cartas
        void añadirCartaACola(Mano mano, const std::string& valor, const std::string& palo, Color colorEnum);

        void imprimirCola(const std::vector<std::string>& cola) const;
        bool esColaVacia(std::vector<std::string> (&cola)[3]) const;
        void limpiarColas();

        void imprimirMano(Mano mano, GameState estado, const std::string& valor);

    private:
        // Colores ANSI
        const std::string colNegro = "\e[1;30m";
        const std::string colRojo = "\e[1;31m";
        const std::string colAmarillo = "\e[1;33m";
        const std::string colCian = "\e[1;36m";
        const std::string colReset = "\e[0m";

        const std::string sangria = "          ";
        const std::string sangriaCartas = "                     ";

        enum { SUPERIOR, MEDIO, INFERIOR }; // Para mayor claridad con los índices array
        std::vector<std::string> colaCartasJugador[3];
        std::vector<std::string> colaCartasCrupier[3];
        std::vector<std::string> colaParcialCrupier[3];
};