/*
    Proyecto: BlackJack
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Información CRC:
   
    Clase: Mazo

    Responsabilidades:
        - Generar un mazo completo de 52 cartas (4 palos × 13 valores)
        - Asignar colores correctos a cada palo (corazones y diamantes rojos, tréboles y picas negros)
        - Barajar las cartas aleatoriamente usando semilla basada en tiempo del sistema
        - Mantener un índice de la carta actual a repartir
        - Proporcionar información sobre cartas restantes
        - Permitir avanzar el índice para repartir cartas secuencialmente

    Colaboradores:
        - Carta (crea y almacena 52 objetos Carta)
        - Crupier (proporciona cartas al crupier para repartir)

    @details Maneja un conjunto de 52 objetos Carta que representan un mazo estándar de 
             póker. Genera las cartas en orden (2-10, J, Q, K, As para cada palo) y luego 
             las baraja usando std::shuffle con semilla temporal. Mantiene un índice que 
             apunta a la siguiente carta a repartir. El vector de cartas es público para 
             permitir acceso directo desde el Crupier
    
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

#include "Carta.h"
#include <vector>

class Mazo {
    public:
        Mazo();
        std::vector<Carta> cartasEnMazo;

        // Getter

        size_t getIndiceCartaActual() const { return indiceCartaActual; }
        size_t getCartasRestantes() const;

        void avanzarIndice() { indiceCartaActual++; }
    
    private:
        size_t indiceCartaActual{};
        void generarMazo();
        void barajar();
};