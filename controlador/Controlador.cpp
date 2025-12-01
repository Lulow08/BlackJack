#include "Controlador.h"

#include <iostream>
#include <algorithm>
#include <cctype>
#include <limits>

Controlador::Controlador(Vista& pVista, Jugador& pJugador, Crupier& pCrupier, Apuesta& pApuesta) : vista{pVista}, jugador{pJugador}, crupier{pCrupier}, apuesta{pApuesta} {}

int Controlador::getOpcionInt(int opcionMin, int opcionMax) const {
    int opcion{};

    while(true) {
        vista.solicitarInput("Ingrese una opcion: ");

        if(std::cin >> opcion) {

            if(opcion >= opcionMin && opcion <= opcionMax){
                limpiarBuffer();
                return opcion;
            }
        }

        if(std::cin.fail()) {
            std::cin.clear(); // Limpiar la bandera de error (fallbit) que se presenta en caso de error
            limpiarBuffer();
        }

        vista.mostrarPantallaPrincipal();
        vista.mostrarTexto("Invalido", "\e[1;31m");
    }
}

char Controlador::getOpcionChar(const std::string& opciones, Menu menu) const {
    char opcion{};

    while(true) {
        vista.solicitarInput("Ingrese una opcion: ");

        if(std::cin >> opcion) {
            opcion = static_cast<char>(std::toupper(opcion));
            limpiarBuffer();

            if(std::find(opciones.begin(), opciones.end(), opcion) != opciones.end())
            return opcion;
        }

        std::cin.clear();

        if(menu == APUESTA)
        vista.mostrarPantallaApuesta(jugador.getNombre(), apuesta.getDineroTotal(), apuesta.getApuestaActual());

        if(menu == JUEGO)
        vista.mostrarPantallaJuego(jugador.getNombre(), apuesta.getDineroTotal(), apuesta.getApuestaActual(),
                                   std::to_string(jugador.getValorDeMano()), std::to_string(crupier.getValorDeMano()),
                                   NONE);

        if(menu == GUARDADO)
        vista.mostrarMenuGuardado();

        vista.mostrarTexto("Invalido", "\e[1;31m");
    }
}

void Controlador::esperarInput(const std::string& texto) const {
    vista.mostrarErrorFullScreen(texto);
    vista.solicitarInput("Presione cualquier tecla: ");
    std::cin.get();

    vista.mostrarPantallaPrincipal();
}

std::string Controlador::getNombreJugador(size_t charMin, size_t charMax) const {
    std::string nombre{};

    while(true) {
        vista.solicitarInput("Escriba su nickname: ");

        if(std::getline(std::cin, nombre)) {
            size_t longitud = nombre.length();

            if(longitud >= charMin && longitud <= charMax)
            return nombre;

            else {
                vista.mostrarTitulo();
                vista.mostrarTexto("Solo nombres entre " + std::to_string(charMin) + 
                                   " y " + std::to_string(charMax) + " letras", "\e[1;30m");
            }
        }

        else {
            std::cin.clear();
            limpiarBuffer();

            vista.mostrarTitulo();
            vista.mostrarTexto("Invalido", "\e[1;31m");
        }
    }
}

void Controlador::limpiarBuffer() const {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}