#include "Apuesta.h"

Apuesta::Apuesta() 
    : dineroTotal(dineroInicial), apuestaActual(0.0), dineroInicial(1000.0) {}

bool Apuesta::aumentarApuesta(double cantidad) {
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

bool Apuesta::reducirApuesta(double cantidad) {
    if (cantidad <= 0) {
        return false;
    }
    
    if (apuestaActual >= cantidad) {
        apuestaActual -= cantidad;
        dineroTotal += cantidad;
        return true;
    }
    
    return false;
}

void Apuesta::resetearApuesta() {
    dineroTotal += apuestaActual;
    apuestaActual = 0.0;
}

void Apuesta::ganar() {
    double ganancia = apuestaActual * 2;
    dineroTotal += ganancia;
    apuestaActual = 0.0;
}

void Apuesta::perder() {
    apuestaActual = 0.0;
}

void Apuesta::empatar() {
    dineroTotal += apuestaActual;
    apuestaActual = 0.0;
}