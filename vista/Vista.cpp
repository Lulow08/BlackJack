#include "Vista.h"

#include <iostream>

Vista::Vista() {}

void Vista::mostrarTitulo() const {
    limpiarPantalla();
    std::cout << colAmarillo << R"(
╔══════════════════════════════════════════════════════════════════════════════╗
║                                                                              ║
║ ██████╗ ██╗      █████╗  ██████╗██╗  ██╗         ██╗ █████╗  ██████╗██╗  ██╗ ║
║ ██╔══██╗██║     ██╔══██╗██╔════╝██║ ██╔╝         ██║██╔══██╗██╔════╝██║ ██╔╝ ║
║ ██████╔╝██║     ███████║██║     █████╔╝          ██║███████║██║     █████╔╝  ║
║ ██╔══██╗██║     ██╔══██║██║     ██╔═██╗     ██   ██║██╔══██║██║     ██╔═██╗  ║
║ ██████╔╝███████╗██║  ██║╚██████╗██║  ██╗    ╚█████╔╝██║  ██║╚██████╗██║  ██╗ ║
║ ╚═════╝ ╚══════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝     ╚════╝ ╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝ ║
║                                                                              ║
╚══════════════════════════════════════════════════════════════════════════════╝
    )" << colReset << std::endl;
}

void Vista::limpiarPantalla() const {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Vista::mostrarTexto(const std::string& texto) const {
    std::cout << texto << "\n";
}

void Vista::añadirCartaACola(
    Mano mano,
    const std::string& valor,
    const std::string& palo,
    Color colorEnum)
{
    std::vector<std::string> (&cola)[4] = (mano == JUGADOR) ? colaCartasJugador : colaCartasCrupier;
    std::string color = (colorEnum == NEGRO) ? colNegro : colRojo;

    cola[SUPERIOR].push_back("╭" + color + valor + palo + colReset + "──╮ ");
    cola[MEDIO].push_back("│    │ ");
    cola[INFERIOR].push_back("╰──" + color + valor + palo + colReset + "╯ ");
}

void Vista::imprimirCola(const std::vector<std::string>& cola) {
    for (size_t i = 0; i < cola.size(); i++) {
        std::cout << cola[i];
    }
    std::cout << "\n";
}

void Vista::limpiarColas() {
    for (size_t i = 0; i < 3; i++) {
        colaCartasJugador[i].clear();
        colaCartasCrupier[i].clear();
    }
}

void Vista::imprimirMano(Mano mano)
{
    std::vector<std::string> (&cola)[4] = (mano == JUGADOR) ? colaCartasJugador : colaCartasCrupier;

    imprimirCola(cola[SUPERIOR]);
    imprimirCola(cola[MEDIO]);
    imprimirCola(cola[MEDIO]);
    imprimirCola(cola[MEDIO]);
    imprimirCola(cola[INFERIOR]);
}