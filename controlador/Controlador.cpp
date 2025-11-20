#include "Controlador.h"

#include <iostream>

Controlador::Controlador(Vista& pVista) : vista{pVista} {}

void Controlador::obtenerEleccionMenu() const {
    int opcion = 0;

    vista.mostrarMenu();
    vista.mostrarTexto("Seleccione una opción: ");

    switch (opcion) {
        case 1:
            // Empezar nueva partida
            break;
        case 2:
            vista.mostrarTexto("VERSIÓN DEMO, FUNCIONALIDAD NO IMPLEMENTADA");
            break;
        case 3:
            vista.mostrarTexto("VERSIÓN DEMO, FUNCIONALIDAD NO IMPLEMENTADA");
            break;
        case 4:
            vista.mostrarTexto("VERSIÓN DEMO, FUNCIONALIDAD NO IMPLEMENTADA");
            break;
        case 5:
            // Salir del juego
            break;
    }
}

void Controlador::obtenerAccionJugador() const {
    // Logica para obtener la acción del jugador
}