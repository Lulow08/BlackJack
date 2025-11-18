#pragma once

class Apuesta {
    public:
        Apuesta();

        bool aumentarApuesta(double cantidad);
        bool reducirApuesta(double cantidad);
        void resetearApuesta();

        void ganar();
        void perder();
        void empatar();

        // Getters

        double getDineroTotal() const { return dineroTotal; }
        double getApuestaActual() const { return apuestaActual; }

    private:
        double dineroTotal;
        double apuestaActual;
        double dineroInicial;
};