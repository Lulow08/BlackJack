#include "Participante.h"

Participante::Participante() {};

void Participante::recibirCarta(const Carta& carta) {
    mano.push_back(carta);
    ajustarMano();
}

void Participante::limpiarMano() {
    mano.clear();
}

void Participante::ajustarMano() {
    int valorMano = getValorDeMano();
    if (valorMano > 21) {
        for (auto& carta : mano) {
            if (carta.getValor() == 11 && !carta.getEstado()) {
                carta.convertirAsAUno(); // Marcar el As como convertido
                valorMano = getValorDeMano();
                if (valorMano <= 21) {
                    break;
                }
            }
        }
    }
}

int Participante::getValorDeMano() const {
    int valorTotal = 0;

    for (const auto& carta : mano) {
        valorTotal += carta.getValor();
    }

    return valorTotal;
}

size_t Participante::getConteoDeCartas() const {
    return mano.size();
}

const std::vector<Carta>& Participante::getMano() const {
    return mano;
}