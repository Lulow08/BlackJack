#pragma once

#include "Carta.h"
#include <vector>

class Participante {
    public:
        Participante();

        void recibirCarta(const Carta& carta);
        void limpiarMano();
        void ajustarMano();

        // Getters

        int getValorDeMano() const;
        size_t getConteoDeCartas() const;
        const std::vector<Carta>& getMano() const;

    protected:
        std::vector<Carta> mano;
};