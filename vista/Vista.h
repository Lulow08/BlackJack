#pragma once

#include <string>
#include <vector>

class Vista {
    public:
        Vista();

        void limpiarPantalla() const;

        void mostrarTitulo() const;
        void mostrarMenu() const;

        void mostrarTexto(const std::string& texto) const;

        void añadirCartaACola(std::vector<std::string>& sup,
                              std::vector<std::string>& med,
                              std::vector<std::string>& inf,
                              const std::string& valor,
                              const std::string& palo,
                              bool esRojo);

        void imprimirCola(const std::vector<std::string>& cola);
        void limpiarColas();

        void imprimirMano(const std::vector<std::string>& sup,
                          const std::vector<std::string>& med,
                          const std::vector<std::string>& inf);
        void actualizarCartasJugador();
        void actualizarCartasCrupier();

    private:
        // Colores ANSI
        const std::string NEGRO = "\u001B[1;30m";
        const std::string ROJO = "\u001B[1;31m";
        const std::string AMARILLO = "\u001B[1;33m";
        const std::string CIAN = "\u001B[1;36m";
        const std::string RESET = "\u001B[0m";

        std::vector<std::string> colaJugadorCartaSuperior;
        std::vector<std::string> colaJugadorCartaMedio;
        std::vector<std::string> colaJugadorCartaInferior;

        std::vector<std::string> colaCrupierCartaSuperior;
        std::vector<std::string> colaCrupierCartaMedio;
        std::vector<std::string> colaCrupierCartaInferior;
};