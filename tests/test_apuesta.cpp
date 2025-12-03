#include <gtest/gtest.h>
#include "Apuesta.h"

class ApuestaTest : public ::testing::Test {
protected:
    Apuesta* apuesta;
    
    void SetUp() override {
        apuesta = new Apuesta();
    }

    void TearDown() override {
        delete apuesta;
    }
};

// Prueba: Dinero inicial
TEST_F(ApuestaTest, DineroInicial) {
    EXPECT_EQ(apuesta->getDineroTotal(), 1000);
    EXPECT_EQ(apuesta->getApuestaActual(), 0);
}

// Prueba: Aumentar apuesta válida
TEST_F(ApuestaTest, AumentarApuestaValida) {
    bool resultado = apuesta->aumentarApuesta(100);
    
    EXPECT_TRUE(resultado);
    EXPECT_EQ(apuesta->getDineroTotal(), 900);
    EXPECT_EQ(apuesta->getApuestaActual(), 100);
}

// Prueba: Aumentar apuesta múltiples veces
TEST_F(ApuestaTest, AumentarApuestaMultiple) {
    apuesta->aumentarApuesta(100);
    apuesta->aumentarApuesta(250);
    apuesta->aumentarApuesta(500);
    
    EXPECT_EQ(apuesta->getDineroTotal(), 150);
    EXPECT_EQ(apuesta->getApuestaActual(), 850);
}

// Prueba: No se puede apostar más dinero del disponible
TEST_F(ApuestaTest, ApuestaSuperaDineroDisponible) {
    bool resultado = apuesta->aumentarApuesta(1500);
    
    EXPECT_FALSE(resultado);
    EXPECT_EQ(apuesta->getDineroTotal(), 1000);
    EXPECT_EQ(apuesta->getApuestaActual(), 0);
}

// Prueba: No se puede apostar cantidad negativa
TEST_F(ApuestaTest, ApuestaNegativa) {
    bool resultado = apuesta->aumentarApuesta(-100);
    
    EXPECT_FALSE(resultado);
    EXPECT_EQ(apuesta->getDineroTotal(), 1000);
}

// Prueba: No se puede apostar cero
TEST_F(ApuestaTest, ApuestaCero) {
    bool resultado = apuesta->aumentarApuesta(0);
    
    EXPECT_FALSE(resultado);
}

// Prueba: Ganar duplica la apuesta
TEST_F(ApuestaTest, Ganar) {
    apuesta->aumentarApuesta(200);
    apuesta->ganar();
    
    EXPECT_EQ(apuesta->getDineroTotal(), 1200); // 800 + (200*2)
    EXPECT_EQ(apuesta->getApuestaActual(), 0);
}

// Prueba: Perder elimina la apuesta
TEST_F(ApuestaTest, Perder) {
    apuesta->aumentarApuesta(300);
    apuesta->perder();
    
    EXPECT_EQ(apuesta->getDineroTotal(), 700);
    EXPECT_EQ(apuesta->getApuestaActual(), 0);
}

// Prueba: Empate devuelve la apuesta
TEST_F(ApuestaTest, Empatar) {
    apuesta->aumentarApuesta(150);
    apuesta->empatar();
    
    EXPECT_EQ(apuesta->getDineroTotal(), 1000);
    EXPECT_EQ(apuesta->getApuestaActual(), 0);
}

// Prueba: Resetear apuesta
TEST_F(ApuestaTest, ResetearApuesta) {
    apuesta->aumentarApuesta(500);
    apuesta->resetearApuesta();
    
    EXPECT_EQ(apuesta->getDineroTotal(), 1000);
    EXPECT_EQ(apuesta->getApuestaActual(), 0);
}

// Prueba: Setter de dinero total
TEST_F(ApuestaTest, SetDineroTotal) {
    apuesta->setDineroTotal(2500);
    
    EXPECT_EQ(apuesta->getDineroTotal(), 2500);
}

// Prueba: Escenario completo - ganar varias rondas
TEST_F(ApuestaTest, EscenarioGanarVariasRondas) {
    // Ronda 1: apostar 100, ganar
    apuesta->aumentarApuesta(100);
    apuesta->ganar();
    EXPECT_EQ(apuesta->getDineroTotal(), 1100);
    
    // Ronda 2: apostar 200, ganar
    apuesta->aumentarApuesta(200);
    apuesta->ganar();
    EXPECT_EQ(apuesta->getDineroTotal(), 1300);
    
    // Ronda 3: apostar 300, perder
    apuesta->aumentarApuesta(300);
    apuesta->perder();
    EXPECT_EQ(apuesta->getDineroTotal(), 1000);
}
