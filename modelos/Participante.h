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