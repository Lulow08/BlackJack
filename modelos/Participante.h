/*
    Proyecto: BlackJack
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Información CRC:
   
    Clase: Participante

    Responsabilidades:
        - Almacenar y gestionar una mano de cartas
        - Recibir nuevas cartas y notificar a la Vista para mostrarlas
        - Calcular el valor total de la mano actual
        - Ajustar automáticamente el valor de los Ases de 11 a 1 para evitar BUST
        - Limpiar la mano y las colas visuales al iniciar nueva ronda
        - Proporcionar información sobre la mano (valor, cantidad de cartas, vector de cartas)
        - Definir método abstracto para identificar tipo de mano

    Colaboradores:
        - Carta (almacena un vector de cartas)
        - Vista (notifica para añadir cartas a cola y limpiar colas)
        - Jugador (subclase que hereda funcionalidad)
        - Crupier (subclase que hereda funcionalidad)

    @details Superclase abstracta que define el comportamiento común entre el jugador y el 
             crupier. Implementa la lógica fundamental del manejo de cartas en Blackjack 
             incluyendo el ajuste automático de Ases cuando el valor de la mano supera 21
             Al recibir una carta, la añade a la mano, ajusta Ases si es necesario y notifica 
             a la Vista. Mantiene referencia a Vista para coordinación visual
    
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