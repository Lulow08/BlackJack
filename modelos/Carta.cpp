#include "Carta.h"

Carta::Carta(int pValorNominal, const std::string& pPalo, const Color& pColor)
    : valorNominal{pValorNominal}, palo{pPalo}, color{pColor} {}

void Carta::convertirAsAUno() {
    if (valorNominal == 11 && !cambioAUno) {
        valorNominal = 1;
        cambioAUno = true;
    }
}

std::string Carta::getNombreCarta() const {
    std::string nombre;

    if (valorNominal == 11) {
        nombre = "A";
    } else if (valorNominal == 12) {
        nombre = "J";
    } else if (valorNominal == 13) {
        nombre = "Q";
    } else if (valorNominal == 14) {
        nombre = "K";
    } else {
        nombre = std::to_string(valorNominal);
    }

    return nombre + " de " + palo;
}