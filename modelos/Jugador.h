#pragma once

#include "Participante.h"

class Jugador : public Participante {
    public:
        Jugador(Vista& pVista);

        Mano getTipoDeMano() const override { return JUGADOR; }
};