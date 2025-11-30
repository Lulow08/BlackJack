#include "Controlador.h"

#include <iostream>

Controlador::Controlador(Vista& pVista) : vista{pVista} {}

int Controlador::obtenerEleccionMenu(int opcionMin, int opcionMax) const {
    int opcion{};

    while (true) {
        vista.mostrarTexto("          ", "Ingrese una opcion: ", "");

        if(std::cin >> opcion) {

            if(opcion >= opcionMin && opcion <= opcionMax)
            std::cin.ignore(10000, '\n');
            return opcion;
        }

        if (std::cin.fail()) {
            std::cin.clear(); // Limpiar la bandera de error (fallbit) que se presenta en caso de error
            std::cin.ignore(10000, '\n');
        }

        vista.mostrarPantallaPrincipal();
        vista.mostrarTexto("Invalido", "\u001B[1;31m");
    }
}

void Controlador::obtenerAccionJugador() const {
    // Logica para obtener la acción del jugador
}