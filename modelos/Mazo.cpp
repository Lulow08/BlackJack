#include "Mazo.h"
#include <algorithm>
#include <random>
#include <chrono>

Mazo::Mazo() {
    generarMazo();
}

void Mazo::generarMazo() {
    cartas.clear();
    std::vector<std::string> palos = {"Corazones", "Diamantes", "Tréboles", "Picas"};
    
    for (const auto& palo : palos) {
        // Cartas del 2 al 9
        for (int valor = 2; valor <= 9; valor++) {
            cartas.push_back(Carta(valor, palo));
        }
        
        // Figuras (valen 10)
        for (int valor = 10; valor <= 14; valor++) {
            cartas.push_back(Carta(valor, palo));
        }
        
        // As (vale 11 inicialmente)
        cartas.push_back(Carta(11, palo));
    }

    barajar();
}

void Mazo::barajar() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); // <- Semilla basada en la hora para hacer un shuffle aleatorio
    std::shuffle(cartas.begin(), cartas.end(), std::default_random_engine(seed)); // Baraja el vector cartas en base a la semilla
    indiceCartaActual = 0;
}

Carta Mazo::darCarta() {
    if (indiceCartaActual >= cartas.size()) {
        generarMazo();
    }
    return cartas[indiceCartaActual++];
}

int Mazo::getCartasRestantes() const {
    return cartas.size() - indiceCartaActual;
}