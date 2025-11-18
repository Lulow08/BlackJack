#include "Crupier.h"

Crupier::Crupier() : Participante() {}

void Crupier::empezarNuevaRonda(Mazo& mazo, Jugador& jugador) {
    limpiarMano();
    jugador.limpiarMano();
    
    // Repartir 2 cartas al jugador y 2 al crupier
    jugador.recibirCarta(mazo.darCarta());
    recibirCarta(mazo.darCarta());
    jugador.recibirCarta(mazo.darCarta());
    recibirCarta(mazo.darCarta());
}

void Crupier::darCartaAJugador(Jugador& jugador, Mazo& mazo) {
    jugador.recibirCarta(mazo.darCarta());
}

void Crupier::jugarTurno(Mazo& mazo) {
    // El crupier debe pedir carta si tiene menos de 17
    while (getValorDeMano() < 17) {
        recibirCarta(mazo.darCarta());
    }
}