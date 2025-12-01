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
    mostrarTexto("3. Como jugar");
    mostrarTexto("4. Salir");
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

void Vista::mostrarMenuAcciones(GameState estado) const {
    if(estado != NONE) {
        std::cout << "\n"; mostrarTexto("Desea jugar de nuevo? [S/N]\n", colNegro);
    }
    else {
        std::cout << "\n"; mostrarTexto("Tomar [T] | Plantarse [P]\n", colNegro);
    } 
}

void Vista::mostrarMenuGuardado() const {
    limpiarPantalla();
    std::cout << "\n\n\n\n\n";
    std::cout << sangriaCartas; mostrarTexto("Desea guardar la partida?");
    std::cout << sangriaCartas; mostrarTexto("          [S/N]          ", colNegro);
    std::cout << "\n\n";
}

void Vista::mostrarGameData(const std::string& nombre, int dinero, int apuesta) const {
    std::cout << sangria;

    mostrarTexto("", nombre, "  ");
    mostrarTexto(colCian, "Dinero: $", std::to_string(dinero));
    mostrarTexto(colAmarillo, "  Apuesta: $", std::to_string(apuesta));

    std::cout << colReset << "\n\n";
}

void Vista::mostrarEstado(GameState estado) const {
    std::cout << "\n" << sangriaCartas;

    if(estado == GANAR)
    std::cout << colCian << "GANASTE!\n\n" << colReset;

    else if(estado == PERDER)
    std::cout << colRojo << "Perdiste\n\n" << colReset;

    else if(estado == BUST)
    std::cout << colRojo << "BUST!\n\n" << colReset;

    else if(estado == EMPATE)
    std::cout << colNegro << "Empate\n\n" << colReset;

    else if(estado == BLACKJACK)
    std::cout << colAmarillo << "BLACK JACK!\n\n" << colReset;

    else
    std::cout << "\n\n";
}

void Vista::mostrarReglas() const {
    mostrarTitulo();
    std::cout << colAmarillo <<
R"(                      Reglas - Black Jack 21                
  ┌────────────────────────────────────────────────────────────┐
  │                                                            │
  │ Objetivo ┌   Vencer al Crupier (maquina) haciendo que   ┐  │
  │          │     la suma de los valores de tus cartas     │  │
  │          │     sea lo mas cercano a 21 sin pasarse.     │  │
  │          │      pasarse es lo mismo que hacer BUST      │  │
  │          └          y pierdes automaticamente           ┘  │
  │                                                            │
  ├────────────────────────────────────────────────────────────┤
  │                                                            │
  │ Cartas   [  Normales(2-10) Figuras(J,Q,K)(10) As(11/1)  ]  │
  │                                                            │
  ├────────────────────────────────────────────────────────────┤
  │                                                            │
  │ Acciones ┌  [T]omar: Añades una carta a tu mano para   ┐   │
  │          │           aumentar tu puntación             │   │
  │          │                                             │   │
  │          │  [P]lantarse: Mantienes tu puntuación       │   │
  │          │               actual. Se decide quien gana  │   │
  │          └                                             ┘   │
  │                                                            │
  ├────────────────────────────────────────────────────────────┤
  │                                                            │
  │ Crupier  ┌  • Juega después de ti                      ┐   │
  │          │  • Debe tomar hasta que su mano valga +16   │   │
  │          └  • Tiene mismo objetivo y reglas que tu     ┘   │
  │                                                            │
  ├─────────────────────────────┬──────────────────────────────┤
  │                             │                              │
  │    • TP - tu puntuación     │  • PC - puntuación crupier   │
  │                             │                              │
  ├─────────────────────────────┴──────────────────────────────┤
  │                                                            │
  │ Ganas    ┌            TP > PC o BlackJack             ┐    │
  │ Pierdes  │              TP < OC o BUST                │    │
  │ Empate   │                 TP = PC                    │    │
  │ BlckJck  └                 TP = 21                    ┘    │
  │                                                            │
  ├────────────────────────────────────────────────────────────┤
  │                                                            │
  │ Presiona cualquier tecla para salir...                     │
  │                                                            │
  └────────────────────────────────────────────────────────────┘)"
    << colReset << std::endl;
}

void Vista::mostrarPantallaPrincipal() const {
    mostrarTitulo();
    mostrarMenuPrincipal();
}

void Vista::mostrarPantallaApuesta(const std::string& nombre, int dinero, int apuesta) {
    mostrarTitulo();
    mostrarGameData(nombre, dinero, apuesta);
    mostrarMenuApuesta();
}

void Vista::mostrarPantallaJuego(const std::string& nombre, int dinero, int apuesta, const std::string& valorJugador, const std::string& valorCrupier, GameState estado) {
    limpiarPantalla();
    mostrarGameData(nombre, dinero, apuesta);
    imprimirMano(CRUPIER, estado, valorCrupier);
    mostrarEstado(estado);
    imprimirMano(JUGADOR, estado, valorJugador);
    mostrarMenuAcciones(estado);
}

void Vista::solicitarInput(const std::string& mensaje) const {
    mostrarTexto(sangria, mensaje, "");
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

void Vista::mostrarErrorFullScreen(const std::string& texto) const {
    limpiarPantalla();
    std::cout << "\n\n\n\n\n";
    std::cout << sangriaCartas; mostrarTexto(texto, colRojo);
    std::cout << "\n\n";
}

void Vista::limpiarPantalla() const {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Vista::añadirCartaACola(Mano mano, const std::string& valor, const std::string& palo, Color colorEnum) {

    std::vector<std::string> (&cola)[3] = (mano == JUGADOR) ? colaCartasJugador : colaCartasCrupier;
    std::string color = (colorEnum == NEGRO) ? colNegro : colRojo;

    bool esDobleDigito = (valor.length() > 1);
    bool esPrimeraCarta = esColaVacia(cola);

    if (esPrimeraCarta) {
        // Ajustar el tamaño de los bordes si el valor es de 2 digitos (valor de 10)
        const std::string bordeSup = esDobleDigito ? "─╮" : "──╮";
        const std::string bordeInf = esDobleDigito ? "╰─" : "╰──";

        cola[SUPERIOR].push_back("╭" + color + valor + palo + colReset + bordeSup);
        cola[MEDIO].push_back("│    │");
        cola[INFERIOR].push_back(bordeInf + color + valor + palo + colReset + "╯");

        // Copia para la cola de cartas parcial (con segunda carta oculta)
        if(mano == CRUPIER) {
            colaParcialCrupier[SUPERIOR].push_back("╭" + color + valor + palo + colReset + bordeSup);
            colaParcialCrupier[MEDIO].push_back("│    │");
            colaParcialCrupier[INFERIOR].push_back(bordeInf + color + valor + palo + colReset + "╯");
        }
    }

    else {
        // Añadir cartas ocultas a colaParcialCrupier
        if(mano == CRUPIER) {
            colaParcialCrupier[SUPERIOR].push_back("╶──╮");
            colaParcialCrupier[MEDIO].push_back("///│");
            colaParcialCrupier[INFERIOR].push_back("╶──╯");
        }

        const std::string bordeInf = esDobleDigito ? "" : "╶";

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
        colaParcialCrupier[i].clear();
    }
}

void Vista::imprimirMano(Mano mano, GameState estado, const std::string& valor) {
    std::vector<std::string> (&cola)[3] = (mano == JUGADOR) ? colaCartasJugador : ((estado != NONE) ? colaCartasCrupier : colaParcialCrupier);

    bool esDobleDigito = (valor.length() > 1);
    const std::string valorConSangria = esDobleDigito ? "                  " : "                   ";
    
    // Colas superiores
    std::cout << valorConSangria << valor << " "; imprimirCola(cola[SUPERIOR]);

    // Colas de en medio (3)
    for (int i = 0; i < 3; i++) {
        std::cout << sangriaCartas; imprimirCola(cola[MEDIO]);
    }

    // Colas inferiores
    std::cout << sangriaCartas; imprimirCola(cola[INFERIOR]);
}