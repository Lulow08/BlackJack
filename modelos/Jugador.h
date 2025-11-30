/*
    Proyecto: BlackJack (Tercera entrega)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Información CRC:
   
    Clase: Jugador

    Responsabilidades:
        - Representar al jugador humano en el juego de Blackjack
        - Heredar funcionalidad de manejo de mano de Participante
        - Identificarse como tipo de mano JUGADOR para la Vista
        - Recibir y almacenar cartas durante la partida
        - Mantener el estado de su mano de cartas

    Colaboradores:
        - Participante (hereda toda la funcionalidad base)
        - Vista (para mostrar sus cartas en pantalla)
        - Crupier (recibe cartas del crupier)
        - Carta (almacena cartas en su mano)

    @details Clase simple que hereda de Participante e implementa el comportamiento 
             específico del jugador humano en Blackjack. Su principal función es identificarse 
             como JUGADOR para que la Vista pueda mostrar sus cartas en la cola correcta
             Utiliza toda la lógica de manejo de cartas heredada de Participante
    
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

#include "Participante.h"

class Jugador : public Participante {
    public:
        Jugador(Vista& pVista, const std::string& nombre);

        // Getters

        Mano getTipoDeMano() const override { return JUGADOR; }
        std::string getNombre() const { return nombre; }

    private:
        const std::string nombre;
};