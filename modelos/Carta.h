/*
    Proyecto: BlackJack (Tercera entrega)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Información CRC:
   
    Clase: Carta

    Responsabilidades:
        - Almacenar el valor nominal, palo y color de una carta
        - Convertir el valor de un As de 11 a 1 cuando sea necesario
        - Proporcionar representación ASCII del valor de la carta
        - Mantener el estado de conversión del As (si cambió de 11 a 1)
        - Proveer acceso a los atributos de la carta mediante getters

    Colaboradores:
        - Mazo (es creada y almacenada en el mazo)
        - Participante (es recibida y almacenada en la mano)
        - Vista (proporciona datos para la representación visual)

    @details Representa una carta individual del juego de Blackjack con sus atributos 
             fundamentales. Implementa la lógica especial del As que puede valer 11 u 1 punto 
             según convenga, y proporciona métodos para obtener su representación textual.
            
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

#include <string>

enum Color { NEGRO, ROJO };

class Carta {
    public:
        Carta(int pValorNominal, const std::string& pPalo, const Color& pColor);

        void convertirAsAUno();

        //Geters

        int getValor() const { return valorNominal; }
        std::string getPalo() const { return palo; }
        Color getColor() const { return color; }
        bool getEstado() const { return cambioAUno; }
        std::string getValorASCII() const;

    private:
        int valorNominal; 
        bool cambioAUno{}; //Booleano para determinar si el valor nominal de un As en la mano se convirtió de 11 a 1
        std::string palo;
        Color color;
};