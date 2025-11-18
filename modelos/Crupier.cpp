#include "Crupier.h"

Crupier::Crupier() : Participante() {}

void Crupier::empezarNuevaRonda(Mazo& mazo, Jugador& jugador) {
    limpiarMano();
    jugador.limpiarMano();
    
    // Repartir 2 cartas al jugador y 2 al crupier

    darCartaAJugador(jugador, mazo, 2);
    darCartaACrupier(mazo, 2);
}

Carta Crupier::getSiguienteCarta(Mazo& mazo) {
    return mazo.cartasEnMazo[mazo.getIndiceCartaActual()];
    mazo.avanzarIndice();
}

void Crupier::darCartaAJugador(Jugador& jugador, Mazo& mazo, size_t cantidad) {
    for (int i = 0; i < cantidad; i++) {
        jugador.recibirCarta(getSiguienteCarta(mazo));
    }
}

void Crupier::darCartaACrupier(Mazo& mazo, size_t cantidad) {
        for (int i = 0; i < cantidad; i++) {
        recibirCarta(getSiguienteCarta(mazo));
    }
}

void Crupier::jugarTurno(Mazo& mazo) {
    // El crupier debe pedir carta si tiene menos de 17
    while (getValorDeMano() < 17) {
        recibirCarta(getSiguienteCarta(mazo));
    }
}