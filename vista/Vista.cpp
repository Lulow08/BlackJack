#include "Vista.h"

#include <iostream>

Vista::Vista() {}

void Vista::mostrarTitulo() const {
    limpiarPantalla();
    std::cout << colAmarillo << R"(
     ▄▄▄▄  ▄▄▄▄▄                                   ▄▄▄  ▄▄▄▀▀█   
   ▄▀    ▀▀     ▀▀▄▄▄▀▀▀▄           ▄▀▀▄▄▄▀▀▄   ▄▀▀   ▀▀   ▄ █   
  █  ▄███▄ ▄███  ▄   ▄▄ █▄▄▄▄   ▄▄▄▄█ ▄   ▄▄ ▀▄█  ▄███  ███▀ █   
 █  █▀  ███▀ ███  █▄█▀      █▄▄▀       █▄█▀      █▀  ██████ ▄▀   
 █ █     ██   ███  ██   ███     ▄███ █  ██   █  █     ██ ██ █    
 ▀▄ █  ▄ ██   ▄▀   ██  ██  ██▀ ██   ██  ██   ██▄ █  ▄ ██ ██ █    
  ▀▄ ▀▀  █▀▄█████  ██ ██   ██ ██    █   ██  █▀▀   ▀▀  ██ ██ █    
   ▀█▄  █     ▀███ ██ ██   ██ ██        ██▄▀██        ██ ██ █▄▄▄ 
    █  █▄       ██ ██  ▀█▄▄███ █▄   █  ▄██▀  ██       ██ ██    █ 
   ▄▀ ▀▀███     █ ▄██▄▀ ▀▀  █   ████  ███   ▄███  ▄██  ▀  █ ██ █ 
  ▄█▄▄▄  ▀███▄▄▀    ▀▀    ▄   █     ▄▄  ▀██   █▀ █▀▀██   ▄▀ ██ █ 
       ▀▄▄     ▄▄▀▀▀▄▄█▀▀▀ ▀▀▀ ▀▀▀▀▀  ▀▄▄   █▄   █   ████▀    ▄▀ 
          ▀▀▀▀▀                          ▀▀▀  ▀▀▄ ▀       ▄▀▀▀   
                                                ▀▄▄▄█▀▀▀▀▀  TM)"
    << colReset << std::endl;
}

void Vista::mostrarMenuPrincipal() const {
    mostrarTexto("Menu Principal", colAmarillo);
    mostrarTexto("~~~~~~~~~~~~~~", colAmarillo);
    mostrarTexto("1. Empezar una nueva partida");
    mostrarTexto("2. Cargar partida anterior");
    mostrarTexto("3. Estadisticas");
    mostrarTexto("4. Como jugar");
    mostrarTexto("5. Salir");
    std::cout << std::endl;
}

void Vista::mostrarMenuApuesta() const {
    mostrarTexto(sangria,"Realiza tu apuesta: ","\n");

    std::cout << sangria; mostrarTexto(colNegro,"[W] Listo  [Q] Cancelar","\n\n");

    std::cout << sangria; mostrarTexto(colCian,"  =─=  ","  "); mostrarTexto(colRojo,"  =─=  ","  "); mostrarTexto(colAmarillo,"  =─=  ","\n");
    std::cout << sangria; mostrarTexto(colCian,"=▀ ♦ ▀=","  "); mostrarTexto(colRojo,"=▀ ♥ ▀=","  "); mostrarTexto(colAmarillo,"=▀ ♣ ▀=","\n");
    std::cout << sangria; mostrarTexto(colCian,"█ 100 █","  "); mostrarTexto(colRojo,"█ 250 █","  "); mostrarTexto(colAmarillo,"█ 500 █","\n");
    std::cout << sangria; mostrarTexto(colCian,"=▄ ♦ ▄=","  "); mostrarTexto(colRojo,"=▄ ♥ ▄=","  "); mostrarTexto(colAmarillo,"=▄ ♣ ▄=","\n");
    std::cout << sangria; mostrarTexto(colCian,"░░=─=░░","  "); mostrarTexto(colRojo,"░░=─=░░","  "); mostrarTexto(colAmarillo,"░░=─=░░","\n");
    std::cout << sangria; mostrarTexto(colCian,"  ░░░  ","  "); mostrarTexto(colRojo,"  ░░░  ","  "); mostrarTexto(colAmarillo,"  ░░░  ","\n\n");
    std::cout << sangria; mostrarTexto(colCian,"  [C]  ","  "); mostrarTexto(colRojo,"  [V]  ","  "); mostrarTexto(colAmarillo,"  [B]  ","\n");
    std::cout << colReset << std::endl;
}

void Vista::mostrarGameData(const std::string& name, int dinero, int apuesta) const {
    std::cout << sangria;

    mostrarTexto("", name, "  ");
    mostrarTexto(colCian, "Cash: $", std::to_string(dinero));
    mostrarTexto(colAmarillo, "  Bet: $", std::to_string(apuesta));

    std::cout << colReset << "\n\n";
}

void Vista::mostrarPantallaPrincipal() const {
    limpiarPantalla();
    mostrarTitulo();
    mostrarMenuPrincipal();
}

void Vista::limpiarPantalla() const {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Vista::mostrarTexto(const std::string& texto) const {
    std::cout << sangria << texto << "\n";
}

void Vista::mostrarTexto(const std::string& texto, const std::string& color) const {
    std::cout << sangria << color << texto << colReset << "\n";
}

void Vista::mostrarTexto(const std::string& prefijo, const std::string& texto, const std::string& sufijo) const {
    std::cout << prefijo << texto << sufijo;
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