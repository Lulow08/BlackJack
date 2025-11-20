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
██████████████████████████████████████████████████████████████████████████████████
    )" << colReset << std::endl;
}

void Vista::mostrarMenu() const {
    std::cout << R"(
                1 - Empezar una nueva partida
                2 - Cargar partida anterior
                3 - Estadisticas
                4 - Como jugar
                5 - Salir
    )" << std::endl;
}

void Vista::mostrarSubMenu() const {
    std::cout << R"(
                1 - Dar carta al jugador
                2 - Dar carta al crupier
                3 - Limpiar ambas manos
                4 - Volver al menú principal
    )" << std::endl;
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

void Vista::añadirCartaACola(Mano mano, const std::string& valor, const std::string& palo, Color colorEnum) {

    std::vector<std::string> (&cola)[3] = (mano == JUGADOR) ? colaCartasJugador : colaCartasCrupier;
    std::string color = (colorEnum == NEGRO) ? colNegro : colRojo;

    bool esDobleDigito = (valor.length() > 1);
    bool esPrimeraCarta = esColaVacia(cola);

    if (esPrimeraCarta) {
        // Ajustar el tamaño de los bordes si el valor es de 2 digitos (valor de 10)
        std::string bordeSup = esDobleDigito ? "─╮" : "──╮";
        std::string bordeInf = esDobleDigito ? "╰─" : "╰──";

        cola[SUPERIOR].push_back("╭" + color + valor + palo + colReset + bordeSup);
        cola[MEDIO].push_back("│    │");
        cola[INFERIOR].push_back(bordeInf + color + valor + palo + colReset + "╯");
    }

    else {
        std::string bordeInf = esDobleDigito ? "" : "╶";

        cola[SUPERIOR].push_back("╶──╮");
        cola[MEDIO].push_back("   │");
        cola[INFERIOR].push_back(bordeInf + color + valor + palo + colReset + "╯");
    }
}

void Vista::imprimirCola(const std::vector<std::string>& cola) const {
    for (size_t i = 0; i < cola.size(); i++) {
        std::cout << cola[i];
    }
    std::cout << "\n";
}

bool Vista::esColaVacia(std::vector<std::string> (&cola)[3]) const {
    return cola[SUPERIOR].empty() && cola[MEDIO].empty() && cola[INFERIOR].empty();
}

void Vista::limpiarColas() {
    for (size_t i = 0; i < 3; i++) {
        colaCartasJugador[i].clear();
        colaCartasCrupier[i].clear();
    }
}

void Vista::imprimirMano(Mano mano) {
    std::vector<std::string> (&cola)[3] = (mano == JUGADOR) ? colaCartasJugador : colaCartasCrupier;

    imprimirCola(cola[SUPERIOR]);

    for (int i = 0; i < 3; i++)
        imprimirCola(cola[MEDIO]);

    imprimirCola(cola[INFERIOR]);
}