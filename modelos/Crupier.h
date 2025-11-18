#pragma once

#include "Mazo.h"
#include "Jugador.h" // E incluye Participante.h

class Crupier : public Participante {
    public:
        Crupier();

        void empezarNuevaRonda(Mazo& mazo, Jugador& jugador);
        void darCartaAJugador(Jugador& jugador, Mazo& mazo);
        void jugarTurno(Mazo& mazo);
};