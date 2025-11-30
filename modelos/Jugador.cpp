#include "Jugador.h"
#include <iostream>

Jugador::Jugador(Vista& pVista, const std::string& pNombre) : Participante(pVista), nombre(pNombre) {}