/*
    Proyecto: BlackJack (Tercera entrega)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Información CRC:
   
    Clase: Crupier

    Responsabilidades:
        - Gestionar el flujo de una ronda de Blackjack
        - Repartir cartas iniciales al jugador y a sí mismo
        - Obtener cartas del mazo y distribuirlas
        - Ejecutar su turno siguiendo las reglas (pedir carta con menos de 17)
        - Iniciar nuevas rondas limpiando las manos anteriores

    Colaboradores:
        - Participante (hereda de esta clase base)
        - Mazo (obtiene cartas del mazo)
        - Jugador (reparte cartas al jugador)
        - Vista (para mostrar sus cartas)

    @details Hereda de Participante e implementa la lógica específica del crupier en el 
             juego de Blackjack. Es responsable de administrar el mazo, repartir cartas y ejecutar 
             las reglas automáticas del crupier (debe pedir carta si tiene menos de 17 puntos).
    
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