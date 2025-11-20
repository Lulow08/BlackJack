#pragma once

#include "Mazo.h"
#include "Jugador.h" // E incluye Participante.h

class Crupier : public Participante {
    public:
        Crupier(Mazo& pMazo, Vista& pVista);

        void empezarNuevaRonda(Jugador& jugador);
        Carta getSiguienteCarta();
        void darCartaAJugador(Jugador& jugador, size_t cantidad);
        void darCartaACrupier(size_t cantidad);
        void jugarTurno();

        Mano getTipoDeMano() const override { return CRUPIER; }

    private:
        Mazo mazo;
};