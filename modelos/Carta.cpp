#include "Carta.h"

Carta::Carta(int pValorNominal, const std::string& pPalo, const Color& pColor)
    : valorNominal{pValorNominal}, palo{pPalo}, color{pColor} {}

void Carta::convertirAsAUno() {
    if (valorNominal == 11 && !cambioAUno) {
        valorNominal = 1;
        cambioAUno = true;
    }
}

std::string Carta::getValorASCII() const {
    std::string valorASCII;

    if (valorNominal == 11) {
        valorASCII = "A";
    } else if (valorNominal == 12) {
        valorASCII = "J";
    } else if (valorNominal == 13) {
        valorASCII = "Q";
    } else if (valorNominal == 14) {
        valorASCII = "K";
    } else {
        valorASCII = std::to_string(valorNominal);
    }

    return valorASCII;
}