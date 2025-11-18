#include "Crupier.h"

Crupier::Crupier() : Participante() {}

void Crupier::empezarNuevaRonda(Mazo& mazo, Jugador& jugador) {
    limpiarMano();
    jugador.limpiarMano();
    
    // Repartir 2 cartas al jugador y 2 al crupier
    darCartaAJugador(jugador, mazo);
    recibirCarta(mazo.cartasEnMazo[mazo.getIndiceCartaActual()]);
    darCartaAJugador(jugador, mazo);
    recibirCarta(mazo.cartasEnMazo[mazo.getIndiceCartaActual()]);
}

void Crupier::darCartaAJugador(Jugador& jugador, Mazo& mazo) {
    jugador.recibirCarta(mazo.cartasEnMazo[mazo.getIndiceCartaActual()]);
}

void Crupier::jugarTurno(Mazo& mazo) {
    // El crupier debe pedir carta si tiene menos de 17
    while (getValorDeMano() < 17) {
        recibirCarta(mazo.cartasEnMazo[mazo.getIndiceCartaActual()]);
    }
}