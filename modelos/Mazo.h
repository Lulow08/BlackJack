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