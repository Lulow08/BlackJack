#include <gtest/gtest.h>
#include "Mazo.h"
#include <set>

class MazoTest : public ::testing::Test {
protected:
    Mazo* mazo;
    
    void SetUp() override {
        mazo = new Mazo();
    }

    void TearDown() override {
        delete mazo;
    }
};

// Prueba: El mazo tiene 52 cartas
TEST_F(MazoTest, TamanioMazo) {
    EXPECT_EQ(mazo->cartasEnMazo.size(), 52);
}

// Prueba: Índice inicial es 0
TEST_F(MazoTest, IndiceInicial) {
    EXPECT_EQ(mazo->getIndiceCartaActual(), 0);
}

// Prueba: Cartas restantes al inicio
TEST_F(MazoTest, CartasRestantesInicio) {
    EXPECT_EQ(mazo->getCartasRestantes(), 52);
}

// Prueba: Avanzar índice
TEST_F(MazoTest, AvanzarIndice) {
    mazo->avanzarIndice();
    EXPECT_EQ(mazo->getIndiceCartaActual(), 1);
    EXPECT_EQ(mazo->getCartasRestantes(), 51);
    
    mazo->avanzarIndice();
    EXPECT_EQ(mazo->getIndiceCartaActual(), 2);
    EXPECT_EQ(mazo->getCartasRestantes(), 50);
}

// Prueba: El mazo contiene 13 cartas de cada palo
TEST_F(MazoTest, CartasPorPalo) {
    std::map<std::string, int> conteoPalos;
    
    for (const auto& carta : mazo->cartasEnMazo) {
        conteoPalos[carta.getPalo()]++;
    }
    
    EXPECT_EQ(conteoPalos.size(), 4); // 4 palos diferentes
    
    for (const auto& [palo, cantidad] : conteoPalos) {
        EXPECT_EQ(cantidad, 13) << "Palo " << palo << " no tiene 13 cartas";
    }
}

// Prueba: El mazo contiene 26 cartas rojas y 26 negras
TEST_F(MazoTest, DistribucionColores) {
    int rojas = 0, negras = 0;
    
    for (const auto& carta : mazo->cartasEnMazo) {
        if (carta.getColor() == ROJO) {
            rojas++;
        } else {
            negras++;
        }
    }
    
    EXPECT_EQ(rojas, 26);
    EXPECT_EQ(negras, 26);
}

// Prueba: Las figuras tienen valor 10
TEST_F(MazoTest, ValorFiguras) {
    int figurasConValor10 = 0;
    
    for (const auto& carta : mazo->cartasEnMazo) {
        std::string valorASCII = carta.getValorASCII();
        if (valorASCII == "J" || valorASCII == "Q" || valorASCII == "K") {
            EXPECT_EQ(carta.getValor(), 10);
            figurasConValor10++;
        }
    }
    
    EXPECT_EQ(figurasConValor10, 12); // 3 figuras × 4 palos
}

// Prueba: Los ases tienen valor inicial 11
TEST_F(MazoTest, ValorAsesInicial) {
    int ases = 0;
    
    for (const auto& carta : mazo->cartasEnMazo) {
        if (carta.getValorASCII() == "A") {
            EXPECT_EQ(carta.getValor(), 11);
            ases++;
        }
    }
    
    EXPECT_EQ(ases, 4);
}

// Prueba: El mazo está barajado (no en orden original)
TEST_F(MazoTest, MazoEstaBarajado) {
    // Crear dos mazos y verificar que son diferentes
    Mazo mazo2;
    
    bool sonDiferentes = false;
    for (size_t i = 0; i < mazo->cartasEnMazo.size(); i++) {
        if (mazo->cartasEnMazo[i].getValorASCII() != mazo2.cartasEnMazo[i].getValorASCII() ||
            mazo->cartasEnMazo[i].getPalo() != mazo2.cartasEnMazo[i].getPalo()) {
            sonDiferentes = true;
            break;
        }
    }
    
    // Es extremadamente improbable que dos mazos barajados sean idénticos
    EXPECT_TRUE(sonDiferentes) << "Los mazos no parecen estar barajados";
}

// Prueba: Simular repartir cartas
TEST_F(MazoTest, SimularRepartirCartas) {
    for (int i = 0; i < 10; i++) {
        mazo->avanzarIndice();
    }
    
    EXPECT_EQ(mazo->getIndiceCartaActual(), 10);
    EXPECT_EQ(mazo->getCartasRestantes(), 42);
}
