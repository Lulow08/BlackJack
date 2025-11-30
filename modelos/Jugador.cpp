#include "Jugador.h"
#include <iostream>

Jugador::Jugador(Vista& pVista) : Participante(pVista) {}

void Jugador::setNombre(const std::string& pNombre) {
    nombre = pNombre;
}