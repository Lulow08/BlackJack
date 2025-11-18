#include "Mazo.h"
#include <algorithm>
#include <random>
#include <chrono>

Mazo::Mazo() {
    generarMazo();
}

void Mazo::generarMazo() {
    cartasEnMazo.clear();
    std::vector<std::string> palos = {"Corazones", "Diamantes", "Tréboles", "Picas"};
    
    for (const auto& palo : palos) {
        // Cartas del 2 al 10
        for (int valor = 2; valor <= 10; valor++) {
            cartasEnMazo.push_back(Carta(valor, palo));
        }
        
        // Figuras (J, K, Q valen 12 13 y 14 respectivamente)
        for (int valor = 12; valor <= 14; valor++) {
            cartasEnMazo.push_back(Carta(valor, palo));
        }
        
        // As (vale 11 inicialmente)
        cartasEnMazo.push_back(Carta(11, palo));
    }

    barajar();
}

void Mazo::barajar() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); // <- Semilla basada en la hora para hacer un shuffle aleatorio
    std::shuffle(cartasEnMazo.begin(), cartasEnMazo.end(), std::default_random_engine(seed)); // Baraja el vector cartas en base a la semilla
    indiceCartaActual = 0;
}

int Mazo::getCartasRestantes() const {
    return cartasEnMazo.size() - indiceCartaActual;
}