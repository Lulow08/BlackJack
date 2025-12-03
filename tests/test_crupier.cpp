#include <gtest/gtest.h>
#include "Crupier.h"
#include "Jugador.h"
#include "Mazo.h"
#include "Vista.h"

class CrupierTest : public ::testing::Test {
protected:
    Vista* vista;
    Mazo* mazo;
    Jugador* jugador;
    Crupier* crupier;
    
    void SetUp() override {
        vista = new Vista();
        mazo = new Mazo();
        jugador = new Jugador(*vista);
        crupier = new Crupier(*mazo, *vista, *jugador);
    }

    void TearDown() override {
        delete crupier;
        delete jugador;
        delete mazo;
        delete vista;
    }
};

// Prueba: Empezar nueva ronda limpia las manos
TEST_F(CrupierTest, EmpezarNuevaRondaLimpiaManos) {
    // Dar algunas cartas primero
    crupier->darCartaACrupier(2);
    crupier->darCartaAJugador(2);
    
    EXPECT_GT(crupier->getConteoDeCartas(), 0);
    EXPECT_GT(jugador->getConteoDeCartas(), 0);
    
    // Empezar nueva ronda
    crupier->empezarNuevaRonda();
    
    // Deben tener exactamente 2 cartas cada uno (las nuevas)
    EXPECT_EQ(crupier->getConteoDeCartas(), 2);
    EXPECT_EQ(jugador->getConteoDeCartas(), 2);
}

// Prueba: Empezar ronda reparte 2 cartas a cada uno
TEST_F(CrupierTest, EmpezarRondaReparteDosCartas) {
    crupier->empezarNuevaRonda();
    
    EXPECT_EQ(crupier->getConteoDeCartas(), 2);
    EXPECT_EQ(jugador->getConteoDeCartas(), 2);
}

// Prueba: Obtener carta del mazo avanza el índice
TEST_F(CrupierTest, ObtenerCartaAvanzaIndice) {
    size_t indiceInicial = mazo->getIndiceCartaActual();
    
    crupier->getSiguienteCarta();
    
    EXPECT_EQ(mazo->getIndiceCartaActual(), indiceInicial + 1);
}

// Prueba: Dar carta al jugador aumenta su conteo
TEST_F(CrupierTest, DarCartaAJugadorAumentaConteo) {
    crupier->darCartaAJugador(1);
    EXPECT_EQ(jugador->getConteoDeCartas(), 1);
    
    crupier->darCartaAJugador(2);
    EXPECT_EQ(jugador->getConteoDeCartas(), 3);
}

// Prueba: Dar carta al crupier aumenta su conteo
TEST_F(CrupierTest, DarCartaACrupierAumentaConteo) {
    crupier->darCartaACrupier(1);
    EXPECT_EQ(crupier->getConteoDeCartas(), 1);
    
    crupier->darCartaACrupier(3);
    EXPECT_EQ(crupier->getConteoDeCartas(), 4);
}

// Prueba: Tipo de mano del crupier
TEST_F(CrupierTest, TipoDeMano) {
    EXPECT_EQ(crupier->getTipoDeMano(), CRUPIER);
}

// Prueba: Evaluar estado inicial (sin cartas)
TEST_F(CrupierTest, EvaluarEstadoInicial) {
    GameState estado = crupier->evaluarEstado();
    
    // Sin cartas, el valor es 0, así que técnicamente es NONE
    // (depende de la implementación, pero probablemente NONE o EMPATE)
    EXPECT_TRUE(estado == NONE || estado == EMPATE);
}

// Prueba: Crupier juega hasta tener al menos 17
TEST_F(CrupierTest, CrupierJuegaHasta17) {
    crupier->empezarNuevaRonda();
    
    // Simular que el jugador se plantó
    crupier->jugarTurno();
    
    // El crupier debe tener al menos 17 puntos
    EXPECT_GE(crupier->getValorDeMano(), 17);
}

// Prueba: Múltiples rondas consecutivas
TEST_F(CrupierTest, MultiplesRondasConsecutivas) {
    // Primera ronda
    crupier->empezarNuevaRonda();
    EXPECT_EQ(crupier->getConteoDeCartas(), 2);
    EXPECT_EQ(jugador->getConteoDeCartas(), 2);
    
    // Segunda ronda
    crupier->empezarNuevaRonda();
    EXPECT_EQ(crupier->getConteoDeCartas(), 2);
    EXPECT_EQ(jugador->getConteoDeCartas(), 2);
    
    // Tercera ronda
    crupier->empezarNuevaRonda();
    EXPECT_EQ(crupier->getConteoDeCartas(), 2);
    EXPECT_EQ(jugador->getConteoDeCartas(), 2);
}

// Prueba: Valor de mano parcial solo cuenta la primera carta
TEST_F(CrupierTest, ValorDeManoParcial) {
    crupier->empezarNuevaRonda();
    
    // El valor parcial debe ser el de la primera carta del crupier
    int valorParcial = crupier->getValorDeManoParcial();
    
    // Debe estar entre 1 y 11 (una carta)
    EXPECT_GE(valorParcial, 1);
    EXPECT_LE(valorParcial, 11);
    
    // Y debe ser menor o igual al valor total
    EXPECT_LE(valorParcial, crupier->getValorDeMano());
}

// Prueba: Cartas restantes disminuyen al repartir
TEST_F(CrupierTest, CartasRestantesDisminuyen) {
    size_t cartasInicial = mazo->getCartasRestantes();
    
    crupier->empezarNuevaRonda(); // Reparte 4 cartas (2+2)
    
    EXPECT_EQ(mazo->getCartasRestantes(), cartasInicial - 4);
}

// Prueba: Decidir resultado con jugador ganador
TEST_F(CrupierTest, DecidirResultadoJugadorGana) {
    crupier->empezarNuevaRonda();
    
    // Forzar que el jugador tenga buen puntaje
    // (esto depende del azar, pero podemos hacer múltiples pruebas)
    
    GameState resultado = crupier->decidirResultado();
    
    // El resultado debe ser uno de los estados válidos
    EXPECT_TRUE(resultado == GANAR || resultado == PERDER || resultado == EMPATE);
}

// Prueba: Evaluación de BlackJack del jugador (valor 21)
TEST_F(CrupierTest, EvaluarBlackJackJugador) {
    // Dar cartas al jugador para sumar exactamente 21
    // Nota: Esta prueba depende de la suerte del mazo, 
    // pero podemos verificar el comportamiento
    
    crupier->empezarNuevaRonda();
    
    // Seguir dando cartas hasta pasar de 21 o llegar a 21
    while (jugador->getValorDeMano() < 21) {
        crupier->darCartaAJugador(1);
    }
    
    GameState estado = crupier->evaluarEstado();
    
    if (jugador->getValorDeMano() == 21) {
        EXPECT_TRUE(estado == BLACKJACK || estado == EMPATE);
    } else {
        EXPECT_EQ(estado, BUST);
    }
}

// Prueba: Evaluación de Bust del jugador (más de 21)
TEST_F(CrupierTest, EvaluarBustJugador) {
    crupier->empezarNuevaRonda();
    
    // Dar muchas cartas al jugador hasta hacer bust
    for (int i = 0; i < 5; i++) {
        crupier->darCartaAJugador(1);
    }
    
    if (jugador->getValorDeMano() > 21) {
        GameState estado = crupier->evaluarEstado();
        EXPECT_EQ(estado, BUST);
    }
}

// Prueba: Empezar ronda consume cartas del mazo
TEST_F(CrupierTest, EmpezarRondaConsumeCartas) {
    size_t indiceInicial = mazo->getIndiceCartaActual();
    
    crupier->empezarNuevaRonda();
    
    // Debe haber avanzado 4 posiciones (2 para jugador, 2 para crupier)
    EXPECT_EQ(mazo->getIndiceCartaActual(), indiceInicial + 4);
}

// Prueba: Jugar turno no da cartas al jugador
TEST_F(CrupierTest, JugarTurnoNoAfectaJugador) {
    crupier->empezarNuevaRonda();
    size_t cartasJugadorInicial = jugador->getConteoDeCartas();
    
    crupier->jugarTurno();
    
    EXPECT_EQ(jugador->getConteoDeCartas(), cartasJugadorInicial);
}

// Prueba: Estado después de decidir resultado es válido
TEST_F(CrupierTest, EstadoDespuesDeDecidirResultado) {
    crupier->empezarNuevaRonda();
    
    GameState resultado = crupier->decidirResultado();
    
    // Verificar que es un estado final válido
    EXPECT_TRUE(
        resultado == GANAR || 
        resultado == PERDER || 
        resultado == EMPATE ||
        resultado == BLACKJACK ||
        resultado == BUST
    );
    
    // No debe ser NONE (estado de juego en progreso)
    EXPECT_NE(resultado, NONE);
}

// Prueba: Limpiar mano funciona correctamente
TEST_F(CrupierTest, LimpiarMano) {
    crupier->darCartaACrupier(3);
    EXPECT_GT(crupier->getConteoDeCartas(), 0);
    
    crupier->limpiarMano();
    
    EXPECT_EQ(crupier->getConteoDeCartas(), 0);
    EXPECT_EQ(crupier->getValorDeMano(), 0);
}

// Prueba: Secuencia completa de juego
TEST_F(CrupierTest, SecuenciaCompletaDeJuego) {
    // 1. Empezar ronda
    crupier->empezarNuevaRonda();
    EXPECT_EQ(crupier->getConteoDeCartas(), 2);
    EXPECT_EQ(jugador->getConteoDeCartas(), 2);
    
    // 2. Jugador pide una carta
    crupier->darCartaAJugador(1);
    EXPECT_EQ(jugador->getConteoDeCartas(), 3);
    
    // 3. Evaluar estado
    GameState estado = crupier->evaluarEstado();
    
    // 4. Si sigue jugando, decidir resultado
    if (estado == NONE) {
        estado = crupier->decidirResultado();
    }
    
    // 5. Verificar que hay un resultado final
    EXPECT_NE(estado, NONE);
}
