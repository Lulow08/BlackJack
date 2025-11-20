/*
    Proyecto: BlackJack (Tercera entrega)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Información CRC:
   
    Clase: Apuesta
    
    Responsabilidades:
        - Gestionar el dinero total del jugador
        - Controlar la apuesta actual en cada partida
        - Permitir aumentar o reducir apuestas dentro de los límites del dinero disponible
        - Actualizar el dinero según el resultado de la partida (ganar, perder, empatar)
        - Resetear la apuesta después de cada ronda

    Colaboradores:
        - Jugador (para gestionar las finanzas del jugador)

    @details Maneja el sistema de apuestas del juego de Blackjack. Controla el flujo de 
             dinero del jugador, validando que las apuestas no excedan el dinero disponible y 
             aplicando las recompensas o pérdidas según el resultado de cada partida.
    
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

class Apuesta {
    public:
        Apuesta();

        bool aumentarApuesta(double cantidad);
        bool reducirApuesta(double cantidad);
        void resetearApuesta();

        void ganar();
        void perder();
        void empatar();

        // Getters

        double getDineroTotal() const { return dineroTotal; }
        double getApuestaActual() const { return apuestaActual; }

    private:
        double dineroTotal;
        double apuestaActual;
        double dineroInicial;
};