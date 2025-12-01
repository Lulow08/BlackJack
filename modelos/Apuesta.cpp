#include "Apuesta.h"

Apuesta::Apuesta() 
    : dineroInicial(1000), dineroTotal(dineroInicial), apuestaActual(0) {}

bool Apuesta::aumentarApuesta(int cantidad) {
    if (cantidad <= 0) {
        return false;
    }
    
    if (dineroTotal >= cantidad) {
        apuestaActual += cantidad;
        dineroTotal -= cantidad;
        return true;
    }
    
    return false;
}

void Apuesta::resetearApuesta() {
    dineroTotal = dineroInicial;
    apuestaActual = 0;
}

void Apuesta::ganar() {
    int ganancia = apuestaActual * 2;
    dineroTotal += ganancia;
    apuestaActual = 0;
}

void Apuesta::perder() {
    apuestaActual = 0;
}

void Apuesta::empatar() {
    dineroTotal += apuestaActual;
    apuestaActual = 0;
}

void Apuesta::setDineroTotal(int cantidad) {
    dineroTotal = cantidad;
}