/*
    Proyecto: BlackJack
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Información CRC:
   
    Clase: Crupier

    Responsabilidades:
        - Gestionar el flujo de una ronda de Blackjack
        - Obtener cartas del mazo y distribuirlas
        - Ejecutar su turno siguiendo las reglas (pedir carta con menos de 17)
        - Evaluar el estado del juego (BUST, BLACKJACK, GANAR, PERDER, EMPATE)
        - Decidir el resultado final después de jugar su turno
        - Calcular el valor parcial de su mano (solo primera carta visible)

    Colaboradores:
        - Participante (hereda funcionalidad base de manejo de mano)
        - Mazo (obtiene cartas del mazo)
        - Jugador (reparte cartas al jugador y compara valores de mano)
        - Vista (muestra sus cartas)

    @details Hereda de Participante e implementa la lógica específica del crupier en 
             Blackjack. Administra el mazo y reparte cartas a ambos participantes. Ejecuta 
             las reglas automáticas del crupier (debe pedir carta con menos de 17). Evalúa 
             el estado del juego en tiempo real y decide el resultado final comparando valores 
             de mano. Mantiene referencia al jugador para coordinación del juego
    
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

    @date Fecha: Diciembre 2024
*/

#pragma once

#include "Mazo.h"
#include "Jugador.h" // E incluye Participante.h

class Crupier : public Participante {
    public:
        Crupier(Mazo& pMazo, Vista& pVista, Jugador& pJugador);

        void empezarNuevaRonda();

        int getValorDeManoParcial() const;

        Carta getSiguienteCarta();
        void darCartaAJugador(int cantidad);
        void darCartaACrupier(int cantidad);

        void jugarTurno();
        GameState evaluarEstado() const;
        GameState decidirResultado();

        Mano getTipoDeMano() const override { return CRUPIER; }

    private:
        Mazo& mazo;
        Jugador& jugador;
};