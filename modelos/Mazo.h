#pragma once

#include "Carta.h"
#include <vector>

class Mazo {
    public:
        Mazo();
        // Reparte la siguiente carta del mazo
        Carta darCarta(); // TODO: convertir en getter y mover responsabilidad a crupier

        // Getter

        int getCartasRestantes() const;
    
    private:
        std::vector<Carta> cartas;
        size_t indiceCartaActual;
        void generarMazo();
        void barajar();
};