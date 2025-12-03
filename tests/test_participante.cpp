#include <gtest/gtest.h>
#include "Jugador.h"
#include "Vista.h"

// Nota: Como Participante es abstracto, usamos Jugador para probarlo

class ParticipanteTest : public ::testing::Test {
protected:
    Vista* vista;
    Jugador* jugador;
    
    void SetUp() override {
        vista = new Vista();
        jugador = new Jugador(*vista);
    }

    void TearDown() override {
        delete jugador;
        delete vista;
    }
};

// Prueba: Mano inicial está vacía
TEST_F(ParticipanteTest, ManoInicialVacia) {
    EXPECT_EQ(jugador->getConteoDeCartas(), 0);
    EXPECT_EQ(jugador->getValorDeMano(), 0);
}

// Prueba: Recibir una carta
TEST_F(ParticipanteTest, RecibirUnaCarta) {
    Carta carta(5, "♥", ROJO);
    jugador->recibirCarta(carta);
    
    EXPECT_EQ(jugador->getConteoDeCartas(), 1);
    EXPECT_EQ(jugador->getValorDeMano(), 5);
}

// Prueba: Recibir múltiples cartas
TEST_F(ParticipanteTest, RecibirMultiplesCartas) {
    Carta carta1(5, "♥", ROJO);
    Carta carta2(7, "♠", NEGRO);
    Carta carta3(3, "♦", ROJO);
    
    jugador->recibirCarta(carta1);
    jugador->recibirCarta(carta2);
    jugador->recibirCarta(carta3);
    
    EXPECT_EQ(jugador->getConteoDeCartas(), 3);
    EXPECT_EQ(jugador->getValorDeMano(), 15);
}

// Prueba: Limpiar mano
TEST_F(ParticipanteTest, LimpiarMano) {
    Carta carta1(5, "♥", ROJO);
    Carta carta2(7, "♠", NEGRO);
    
    jugador->recibirCarta(carta1);
    jugador->recibirCarta(carta2);
    jugador->limpiarMano();
    
    EXPECT_EQ(jugador->getConteoDeCartas(), 0);
    EXPECT_EQ(jugador->getValorDeMano(), 0);
}

// Prueba: Figuras valen 10
TEST_F(ParticipanteTest, FigurasValen10) {
    Carta cartaJ(12, "♥", ROJO);
    Carta cartaQ(13, "♠", NEGRO);
    Carta cartaK(14, "♦", ROJO);
    
    jugador->recibirCarta(cartaJ);
    EXPECT_EQ(jugador->getValorDeMano(), 10);
    
    jugador->recibirCarta(cartaQ);
    EXPECT_EQ(jugador->getValorDeMano(), 20);
    
    jugador->limpiarMano();
    jugador->recibirCarta(cartaK);
    EXPECT_EQ(jugador->getValorDeMano(), 10);
}

// Prueba: As vale 11 inicialmente
TEST_F(ParticipanteTest, AsInicial) {
    Carta as(11, "♥", ROJO);
    jugador->recibirCarta(as);
    
    EXPECT_EQ(jugador->getValorDeMano(), 11);
}

// Prueba: Ajuste automático de As (de 11 a 1) cuando se pasa de 21
TEST_F(ParticipanteTest, AjusteAutomaticoAs) {
    Carta as(11, "♥", ROJO);
    Carta carta10(10, "♠", NEGRO);
    Carta carta5(5, "♦", ROJO);
    
    jugador->recibirCarta(as);      // 11
    jugador->recibirCarta(carta10); // 11 + 10 = 21
    jugador->recibirCarta(carta5);  // 21 + 5 = 26, pero As se ajusta: 1 + 10 + 5 = 16
    
    EXPECT_EQ(jugador->getValorDeMano(), 16);
}

// Prueba: Múltiples ases se ajustan correctamente
TEST_F(ParticipanteTest, MultipleAsesSeAjustan) {
    Carta as1(11, "♥", ROJO);
    Carta as2(11, "♠", NEGRO);
    Carta carta9(9, "♦", ROJO);
    
    jugador->recibirCarta(as1);  // 11
    jugador->recibirCarta(as2);  // 11 + 11 = 22, un As se ajusta: 11 + 1 = 12
    jugador->recibirCarta(carta9); // 12 + 9 = 21
    
    EXPECT_EQ(jugador->getValorDeMano(), 21);
}

// Prueba: BlackJack (As + 10 o figura)
TEST_F(ParticipanteTest, BlackJack) {
    Carta as(11, "♥", ROJO);
    Carta rey(14, "♠", NEGRO);
    
    jugador->recibirCarta(as);
    jugador->recibirCarta(rey);
    
    EXPECT_EQ(jugador->getValorDeMano(), 21);
}

// Prueba: Bust (más de 21)
TEST_F(ParticipanteTest, Bust) {
    Carta carta10_1(10, "♥", ROJO);
    Carta carta10_2(10, "♠", NEGRO);
    Carta carta5(5, "♦", ROJO);
    
    jugador->recibirCarta(carta10_1);
    jugador->recibirCarta(carta10_2);
    jugador->recibirCarta(carta5);
    
    EXPECT_EQ(jugador->getValorDeMano(), 25);
}

// Prueba: Obtener mano
TEST_F(ParticipanteTest, ObtenerMano) {
    Carta carta1(5, "♥", ROJO);
    Carta carta2(7, "♠", NEGRO);
    
    jugador->recibirCarta(carta1);
    jugador->recibirCarta(carta2);
    
    const auto& mano = jugador->getMano();
    EXPECT_EQ(mano.size(), 2);
    EXPECT_EQ(mano[0].getValor(), 5);
    EXPECT_EQ(mano[1].getValor(), 7);
}

// Prueba: Tipo de mano del jugador
TEST_F(ParticipanteTest, TipoDeManoJugador) {
    EXPECT_EQ(jugador->getTipoDeMano(), JUGADOR);
}

// Prueba: Nombre del jugador
TEST_F(ParticipanteTest, NombreJugador) {
    jugador->setNombre("TestPlayer");
    EXPECT_EQ(jugador->getNombre(), "TestPlayer");
}

// Prueba: Escenario completo - mano soft 17
TEST_F(ParticipanteTest, ManoSoft17) {
    // Soft 17 = As + 6 (puede valer 17 o 7)
    Carta as(11, "♥", ROJO);
    Carta carta6(6, "♠", NEGRO);
    
    jugador->recibirCarta(as);
    jugador->recibirCarta(carta6);
    
    EXPECT_EQ(jugador->getValorDeMano(), 17);
    
    // Si toma otra carta de 10, el As debe ajustarse
    Carta carta10(10, "♦", ROJO);
    jugador->recibirCarta(carta10);
    
    EXPECT_EQ(jugador->getValorDeMano(), 17); // 1 + 6 + 10 = 17
}
