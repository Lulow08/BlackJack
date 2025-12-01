/*
    Proyecto: BlackJack
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Información CRC:
   
    Clase: Apuesta

    Responsabilidades:
        - Gestionar el dinero total del jugador
        - Controlar la apuesta actual en cada partida
        - Validar que las apuestas no excedan el dinero disponible
        - Actualizar el dinero según el resultado (ganar duplica la apuesta, perder la pierde, empatar la devuelve)
        - Resetear el dinero total y apuesta al estado inicial
        - Permitir modificar el dinero total manualmente

    Colaboradores:
        - Jugador (gestiona las finanzas del jugador)
        - Vista (muestra información de dinero y apuesta)
        - Controlador (coordina las acciones de apuesta)

    @details Maneja el sistema económico del juego de Blackjack. Permite aumentar apuestas
             validando que no excedan el dinero disponible. Aplica las reglas de pago del Blackjack
             ganar duplica la apuesta, perder la pierde completamente y empatar la devuelve.
             Incluye funcionalidad para resetear a valores iniciales y modificar el dinero directamente
    
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

class Apuesta {
    public:
        Apuesta();

        bool aumentarApuesta(int cantidad);
        void resetearApuesta();

        void ganar();
        void perder();
        void empatar();

        // Getters

        int getDineroTotal() const { return dineroTotal; }
        int getApuestaActual() const { return apuestaActual; }

        // Setter

        void setDineroTotal(int cantidad);

    private:
        int dineroInicial;
        int dineroTotal;
        int apuestaActual;
};