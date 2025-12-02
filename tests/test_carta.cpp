#include <gtest/gtest.h>
#include "Carta.h"

class CartaTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Configuración antes de cada prueba
    }

    void TearDown() override {
        // Limpieza después de cada prueba
    }
};

// Prueba: Valor de carta numérica
TEST_F(CartaTest, ValorCartaNumerica) {
    Carta carta(5, "♥", ROJO);
    EXPECT_EQ(carta.getValor(), 5);
}

// Prueba: Valor de figura (J, Q, K valen 10)
TEST_F(CartaTest, ValorFigura) {
    Carta cartaJ(12, "♠", NEGRO);
    Carta cartaQ(13, "♦", ROJO);
    Carta cartaK(14, "♣", NEGRO);
    
    EXPECT_EQ(cartaJ.getValor(), 10);
    EXPECT_EQ(cartaQ.getValor(), 10);
    EXPECT_EQ(cartaK.getValor(), 10);
}

// Prueba: As inicial vale 11
TEST_F(CartaTest, AsInicial) {
    Carta as(11, "♥", ROJO);
    EXPECT_EQ(as.getValor(), 11);
}

// Prueba: Conversión de As de 11 a 1
TEST_F(CartaTest, ConversionAs) {
    Carta as(11, "♥", ROJO);
    EXPECT_EQ(as.getValor(), 11);
    EXPECT_FALSE(as.getEstado());
    
    as.convertirAsAUno();
    EXPECT_EQ(as.getValor(), 1);
    EXPECT_TRUE(as.getEstado());
}

// Prueba: As no se convierte dos veces
TEST_F(CartaTest, AsNoSeConvirteDosVeces) {
    Carta as(11, "♥", ROJO);
    as.convertirAsAUno();
    as.convertirAsAUno(); // Segunda conversión no debería hacer nada
    
    EXPECT_EQ(as.getValor(), 1);
}

// Prueba: Palo de la carta
TEST_F(CartaTest, PaloCarta) {
    Carta carta(7, "♦", ROJO);
    EXPECT_EQ(carta.getPalo(), "♦");
}

// Prueba: Color de la carta
TEST_F(CartaTest, ColorCarta) {
    Carta cartaRoja(5, "♥", ROJO);
    Carta cartaNegra(5, "♠", NEGRO);
    
    EXPECT_EQ(cartaRoja.getColor(), ROJO);
    EXPECT_EQ(cartaNegra.getColor(), NEGRO);
}

// Prueba: Representación ASCII de cartas numéricas
TEST_F(CartaTest, ValorASCIINumerico) {
    Carta carta2(2, "♥", ROJO);
    Carta carta10(10, "♦", ROJO);
    
    EXPECT_EQ(carta2.getValorASCII(), "2");
    EXPECT_EQ(carta10.getValorASCII(), "10");
}

// Prueba: Representación ASCII de figuras
TEST_F(CartaTest, ValorASCIIFiguras) {
    Carta cartaJ(12, "♠", NEGRO);
    Carta cartaQ(13, "♦", ROJO);
    Carta cartaK(14, "♣", NEGRO);
    Carta cartaA(11, "♥", ROJO);
    
    EXPECT_EQ(cartaJ.getValorASCII(), "J");
    EXPECT_EQ(cartaQ.getValorASCII(), "Q");
    EXPECT_EQ(cartaK.getValorASCII(), "K");
    EXPECT_EQ(cartaA.getValorASCII(), "A");
}
