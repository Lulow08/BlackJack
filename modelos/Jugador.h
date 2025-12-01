/*
    Proyecto: BlackJack
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Información CRC:
   
    Clase: Jugador

    Responsabilidades:
        - Representar al jugador humano en el juego de Blackjack
        - Almacenar y proporcionar el nombre del jugador
        - Heredar funcionalidad de manejo de mano de Participante
        - Identificarse como tipo de mano JUGADOR para la Vista
        - Recibir y almacenar cartas durante la partida

    Colaboradores:
        - Participante (hereda toda la funcionalidad base)
        - Vista (muestra sus cartas en pantalla)
        - Crupier (recibe cartas del crupier)
        - Carta (almacena cartas en su mano)

    @details Clase simple que hereda de Participante e implementa el comportamiento 
             específico del jugador humano en Blackjack. Añade la funcionalidad de almacenar 
             el nombre del jugador mediante setter y getter. Su principal función es 
             identificarse como JUGADOR para que la Vista muestre sus cartas en la cola 
             correcta. Utiliza toda la lógica de manejo de cartas heredada de Participante
    
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

#include "Participante.h"

class Jugador : public Participante {
    public:
        Jugador(Vista& pVista);

        // Getters

        Mano getTipoDeMano() const override { return JUGADOR; }
        std::string getNombre() const { return nombre; }

        // Setter

        void setNombre(const std::string& pNombre);

    private:
        std::string nombre{};
};