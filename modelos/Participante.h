/*
    Proyecto: BlackJack (Tercera entrega)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Información CRC:
   
    Clase: Participante
    
    Responsabilidades:
        - Almacenar y gestionar una mano de cartas
        - Recibir nuevas cartas y añadirlas a la mano
        - Calcular el valor total de la mano actual
        - Ajustar automáticamente el valor de los Ases (de 11 a 1) para evitar pasarse de 21
        - Limpiar la mano al iniciar nueva ronda
        - Proporcionar información sobre la mano (valor, cantidad de cartas)

    Colaboradores:
        - Carta (almacena un vector de cartas)
        - Vista (notifica para mostrar las cartas recibidas)
        - Jugador (subclase que hereda funcionalidad)
        - Crupier (subclase que hereda funcionalidad)

    @details Clase abstracta que define el comportamiento común entre el jugador y el 
             crupier. Implementa la lógica fundamental del manejo de cartas en Blackjack, 
             incluyendo el ajuste automático de Ases cuando el valor de la mano supera 21.
    
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

#include <vector>

#include "Carta.h"
#include "Vista.h"

class Participante {
    public:
        Participante(Vista& pVista);
        virtual ~Participante() = default; // Destructor virtual de precaución

        void recibirCarta(const Carta& carta);
        void limpiarMano();
        void ajustarMano();

        // Getters

        virtual Mano getTipoDeMano() const = 0;

        int getValorDeMano() const;
        size_t getConteoDeCartas() const;
        const std::vector<Carta>& getMano() const;

    private:
        Vista& vista;

    protected:
        std::vector<Carta> mano;
};