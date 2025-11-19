#pragma once

#include <string>
#include <vector>

#include "Carta.h"

enum Mano { JUGADOR, CRUPIER }; // Enum para elegir entre la cola de jugador o crupier

class Vista {
    public:
        Vista();

        void limpiarPantalla() const;

        void mostrarTitulo() const;
        void mostrarMenu() const;

        void mostrarTexto(const std::string& texto) const;

        void añadirCartaACola(Mano mano, const std::string& valor, const std::string& palo, Color colorEnum);

        void imprimirCola(const std::vector<std::string>& cola) const;
        bool esColaVacia(std::vector<std::string> (&cola)[3]) const;
        void limpiarColas();

        void imprimirMano(Mano mano);

    private:
        // Colores ANSI
        const std::string colNegro = "\u001B[1;30m";
        const std::string colRojo = "\u001B[1;31m";
        const std::string colAmarillo = "\u001B[1;33m";
        const std::string colCian = "\u001B[1;36m";
        const std::string colReset = "\u001B[0m";

        enum { SUPERIOR, MEDIO, INFERIOR }; // Para mayor claridad con los índices array
        std::vector<std::string> colaCartasJugador[3];
        std::vector<std::string> colaCartasCrupier[3];
};