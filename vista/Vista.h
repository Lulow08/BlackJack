/*
    Proyecto: BlackJack (Tercera entrega)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Información CRC:
   
    Clase: Vista
    
    Responsabilidades:
        - Mostrar la interfaz gráfica del juego (título, menús, mensajes)
        - Gestionar la representación visual de las cartas en consola
        - Manejar las colas de impresión para las manos del jugador y crupier
        - Proporcionar métodos para limpiar pantalla y mostrar texto
        - Renderizar las cartas con colores ANSI y formato ASCII art

    Colaboradores:
        - Carta (para obtener información de las cartas a mostrar)
        - Participante (a través del enum Mano para distinguir manos)

    @details Maneja la interfaz de usuario del juego de Blackjack utilizando caracteres 
             especiales Unicode y colores ANSI para crear una representación visual de las cartas.
             Implementa un sistema de colas para apilar cartas horizontalmente con efecto de 
             profundidad. Es responsable de toda la salida visual del programa.
    
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

    @date Fecha: Noviembre 2025
*/

#pragma once

#include <string>
#include <vector>

#include "Carta.h"

enum Mano { JUGADOR, CRUPIER }; // Enum para elegir entre la cola de jugador o crupier en el metodo de Vista

class Vista {
    public:
        Vista();

        void limpiarPantalla() const;

        void mostrarTitulo() const;
        void mostrarMenuPrincipal() const;
        void mostrarPantallaPrincipal() const;

        void mostrarTexto(const std::string& texto) const;
        void mostrarTexto(const std::string& texto, const std::string& color) const;
        void mostrarTexto(const std::string& prefijo, const std::string& texto, const std::string& sufijo) const;

        void añadirCartaACola(Mano mano, const std::string& valor, const std::string& palo, Color colorEnum);

        void imprimirCola(const std::vector<std::string>& cola) const;
        bool esColaVacia(std::vector<std::string> (&cola)[3]) const;
        void limpiarColas();

        void imprimirMano(Mano mano);

    private:
        // Colores ANSI
        const std::string colNegro = "\u001B[1;30m";
        const std::string colRojo = "\u001B[1;31m";
        const std::string colAmarillo = "\u001B[1;33m";
        const std::string colCian = "\u001B[1;36m";
        const std::string colReset = "\u001B[0m";

        const std::string sangria = "          ";

        enum { SUPERIOR, MEDIO, INFERIOR }; // Para mayor claridad con los índices array
        std::vector<std::string> colaCartasJugador[3];
        std::vector<std::string> colaCartasCrupier[3];
};