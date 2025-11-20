/*
    Proyecto: BlackJack (Tercera entrega)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Información CRC:
   
    Clase: Mazo

    Responsabilidades:
        - Generar un mazo completo de 52 cartas (4 palos × 13 valores)
        - Asignar colores correctos a cada palo (rojo/negro)
        - Barajar las cartas aleatoriamente al inicio
        - Mantener un índice de la carta actual
        - Proporcionar información sobre cartas restantes
        - Permitir avanzar el índice para repartir cartas
        
    Colaboradores:
        - Carta (crea y almacena objetos Carta)
        - Crupier (proporciona cartas al crupier para repartir)

    @details Maneja un conjunto de 52 objetos Carta que representan un mazo estándar de 
             póker. Genera las cartas en orden y luego las baraja usando algoritmos de 
             aleatorización basados en el tiempo del sistema. Mantiene el control de qué carta 
             se debe repartir a continuación.
    
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

#include "Carta.h"
#include <vector>

class Mazo {
    public:
        Mazo();
        std::vector<Carta> cartasEnMazo;

        // Getter

        int getIndiceCartaActual() const { return indiceCartaActual; }
        int getCartasRestantes() const;

        void avanzarIndice() { indiceCartaActual++; }
    
    private:
        size_t indiceCartaActual{};
        void generarMazo();
        void barajar();
};