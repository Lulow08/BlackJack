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
        std::string getNombreCarta() const;

    private:
        int valorNominal; 
        bool cambioAUno{}; //Booleano para determinar si el valor nominal de un As en la mano se convirtió de 11 a 1
        std::string palo;
        Color color;
};