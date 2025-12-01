#include "Crupier.h"

Crupier::Crupier(Mazo& pMazo, Vista& pVista, Jugador& pJugador) : Participante(pVista), mazo{pMazo}, jugador{pJugador} {}

void Crupier::empezarNuevaRonda() {
    limpiarMano();
    jugador.limpiarMano();
    
    // Repartir 2 cartas al jugador y 2 al crupier

    darCartaAJugador(2);
    darCartaACrupier(2);
}

int Crupier::getValorDeManoParcial() const {
    return mano[0].getValor();
}

Carta Crupier::getSiguienteCarta() {
    mazo.avanzarIndice();
    return mazo.cartasEnMazo[mazo.getIndiceCartaActual()];
}

void Crupier::darCartaAJugador(int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        jugador.recibirCarta(getSiguienteCarta());
    }
}

void Crupier::darCartaACrupier(int cantidad) {
        for (int i = 0; i < cantidad; i++) {
        recibirCarta(getSiguienteCarta());
    }
}

void Crupier::jugarTurno() {
    // El crupier debe pedir carta si tiene menos de 17
    while (getValorDeMano() < 17) {
        darCartaACrupier(1);
    }
}

GameState Crupier::evaluarEstado() const {
    int valorJugador = jugador.getValorDeMano();
    int valorCrupier = getValorDeMano();

    // Casos de bust por ambas partes
    if(valorJugador > 21 && valorCrupier > 21) return EMPATE;
    if(valorJugador > 21) return BUST;
    if(valorCrupier > 21) return GANAR;

    // Caso de empate con blackJack
    if(valorJugador == 21 && valorCrupier == 21) return EMPATE;

    // Casos de blackJack ambas partes
    if(valorJugador == 21) return BLACKJACK;
    if(valorCrupier == 21) return PERDER;

    return NONE;
}

GameState Crupier::decidirResultado() {
    jugarTurno();
    int valorCrupier = getValorDeMano();
    int valorJugador = jugador.getValorDeMano();

    if(valorCrupier > 21) return GANAR;
    if(valorCrupier == 21) return PERDER;

    if(valorJugador > valorCrupier) return GANAR;
    if(valorJugador < valorCrupier) return PERDER;

    return EMPATE;
}