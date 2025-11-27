#include "Controlador.h"

#include <iostream>

Controlador::Controlador(Vista& pVista) : vista{pVista} {}

int Controlador::obtenerEleccionMenu(int opcionMin, int opcionMax) const {
    int opcion;
    bool esEntradaValida{};

    while (!esEntradaValida) {
        if(!std::cin >> opcion) {

            if(opcion >= opcionMin && opcion <= opcionMax)
            esEntradaValida = true;

            else 
            std::cout << "\n-> Opción fuera de rango, ingrese un número entre\n" << "[" << opcionMin << " y " << opcionMax << "]" << std::endl;
        }

        else {
            std::cout << "\n-> La entrada NO es un número válido, Inténtalo de nuevo" << std::endl;
            std::cin.clear(); // Limpiar la bandera de error (fallbit) que se presenta en caso de error
        }
    }

    return opcion;

}

void Controlador::obtenerAccionJugador() const {
    // Logica para obtener la acción del jugador
}