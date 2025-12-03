#include <gtest/gtest.h>
#include "Serializador.h"
#include "Jugador.h"
#include "Apuesta.h"
#include "Vista.h"
#include "Controlador.h"
#include <fstream>
#include <cstdio>

class SerializadorTest : public ::testing::Test {
protected:
    Vista* vista;
    Jugador* jugador;
    Crupier* crupier;
    Mazo* mazo;
    Apuesta* apuesta;
    Controlador* controlador;
    Serializador* serializador;
    std::string archivoTest = "test_partida";
    
    void SetUp() override {
        vista = new Vista();
        mazo = new Mazo();
        jugador = new Jugador(*vista);
        crupier = new Crupier(*mazo, *vista, *jugador);
        apuesta = new Apuesta();
        controlador = new Controlador(*vista, *jugador, *crupier, *apuesta);
        serializador = new Serializador(archivoTest, *vista, *controlador);
        
        // Limpiar archivo de prueba si existe
        std::remove(archivoTest.c_str());
    }

    void TearDown() override {
        delete serializador;
        delete controlador;
        delete apuesta;
        delete crupier;
        delete jugador;
        delete mazo;
        delete vista;
        
        // Limpiar archivo de prueba
        std::remove(archivoTest.c_str());
    }
    
    // Función auxiliar para crear un archivo de prueba
    void crearArchivoPrueba(const std::string& contenido) {
        std::ofstream archivo(archivoTest);
        archivo << contenido;
        archivo.close();
    }
};

// Prueba: Serializar datos correctamente
TEST_F(SerializadorTest, SerializarDatos) {
    jugador->setNombre("TestPlayer");
    apuesta->setDineroTotal(1500);
    
    std::string resultado = serializador->serializarDatos(*jugador, *apuesta);
    
    EXPECT_EQ(resultado, "TestPlayer,1500");
}

// Prueba: Serializar con nombre diferente
TEST_F(SerializadorTest, SerializarConNombreDiferente) {
    jugador->setNombre("Player123");
    apuesta->setDineroTotal(2000);
    
    std::string resultado = serializador->serializarDatos(*jugador, *apuesta);
    
    EXPECT_EQ(resultado, "Player123,2000");
}

// Prueba: Serializar con diferentes cantidades de dinero
TEST_F(SerializadorTest, SerializarDiferentesDinero) {
    jugador->setNombre("Rich");
    
    apuesta->setDineroTotal(500);
    EXPECT_EQ(serializador->serializarDatos(*jugador, *apuesta), "Rich,500");
    
    apuesta->setDineroTotal(10000);
    EXPECT_EQ(serializador->serializarDatos(*jugador, *apuesta), "Rich,10000");
}

// Prueba: Deserializar datos válidos
TEST_F(SerializadorTest, DeserializarDatosValidos) {
    crearArchivoPrueba("Player1,2500");
    
    auto resultado = serializador->deserializarDatos();
    
    EXPECT_EQ(resultado.first, "Player1");
    EXPECT_EQ(resultado.second, 2500);
}

// Prueba: Deserializar con diferentes valores
TEST_F(SerializadorTest, DeserializarDiferentesValores) {
    crearArchivoPrueba("Hero,750");
    
    auto resultado = serializador->deserializarDatos();
    
    EXPECT_EQ(resultado.first, "Hero");
    EXPECT_EQ(resultado.second, 750);
}

// Prueba: Deserializar archivo vacío retorna valores por defecto
TEST_F(SerializadorTest, DeserializarArchivoVacio) {
    crearArchivoPrueba("");
    
    auto resultado = serializador->deserializarDatos();
    
    EXPECT_EQ(resultado.first, "");
    EXPECT_EQ(resultado.second, 0);
}

// Prueba: Deserializar archivo inexistente retorna valores por defecto
TEST_F(SerializadorTest, DeserializarArchivoInexistente) {
    // No crear archivo
    auto resultado = serializador->deserializarDatos();
    
    EXPECT_EQ(resultado.first, "");
    EXPECT_EQ(resultado.second, 0);
}

// Prueba: Deserializar archivo corrupto (sin coma)
TEST_F(SerializadorTest, DeserializarArchivoSinComa) {
    crearArchivoPrueba("Player1500");
    
    auto resultado = serializador->deserializarDatos();
    
    EXPECT_EQ(resultado.first, "");
    EXPECT_EQ(resultado.second, 0);
}

// Prueba: Deserializar archivo corrupto (sin nombre)
TEST_F(SerializadorTest, DeserializarArchivoSinNombre) {
    crearArchivoPrueba(",1500");
    
    auto resultado = serializador->deserializarDatos();
    
    EXPECT_EQ(resultado.first, "");
    EXPECT_EQ(resultado.second, 0);
}

// Prueba: Deserializar archivo corrupto (sin dinero)
TEST_F(SerializadorTest, DeserializarArchivoSinDinero) {
    crearArchivoPrueba("Player,");
    
    auto resultado = serializador->deserializarDatos();
    
    EXPECT_EQ(resultado.first, "");
    EXPECT_EQ(resultado.second, 0);
}

// Prueba: Deserializar archivo corrupto (dinero no numérico)
TEST_F(SerializadorTest, DeserializarDineroNoNumerico) {
    crearArchivoPrueba("Player,abc");
    
    auto resultado = serializador->deserializarDatos();
    
    EXPECT_EQ(resultado.first, "");
    EXPECT_EQ(resultado.second, 0);
}

// Prueba: Guardar partida crea archivo correctamente
TEST_F(SerializadorTest, GuardarPartidaCreaArchivo) {
    jugador->setNombre("SaveTest");
    apuesta->setDineroTotal(3000);
    
    serializador->guardarPartida(*jugador, *apuesta);
    
    // Verificar que el archivo existe y contiene los datos correctos
    std::ifstream archivo(archivoTest);
    ASSERT_TRUE(archivo.is_open());
    
    std::string contenido;
    std::getline(archivo, contenido);
    archivo.close();
    
    EXPECT_EQ(contenido, "SaveTest,3000");
}

// Prueba: Guardar y cargar partida completa
TEST_F(SerializadorTest, GuardarYCargarPartida) {
    // Guardar datos
    jugador->setNombre("Complete");
    apuesta->setDineroTotal(4500);
    serializador->guardarPartida(*jugador, *apuesta);
    
    // Cargar datos
    auto resultado = serializador->deserializarDatos();
    
    EXPECT_EQ(resultado.first, "Complete");
    EXPECT_EQ(resultado.second, 4500);
}

// Prueba: Sobrescribir partida guardada
TEST_F(SerializadorTest, SobrescribirPartida) {
    // Primera partida
    jugador->setNombre("First");
    apuesta->setDineroTotal(1000);
    serializador->guardarPartida(*jugador, *apuesta);
    
    // Segunda partida (sobrescribe)
    jugador->setNombre("Second");
    apuesta->setDineroTotal(2000);
    serializador->guardarPartida(*jugador, *apuesta);
    
    // Verificar que solo existe la segunda
    auto resultado = serializador->deserializarDatos();
    
    EXPECT_EQ(resultado.first, "Second");
    EXPECT_EQ(resultado.second, 2000);
}

// Prueba: Nombres con caracteres especiales
TEST_F(SerializadorTest, NombreConCaracteresEspeciales) {
    jugador->setNombre("Test123");
    apuesta->setDineroTotal(1500);
    
    serializador->guardarPartida(*jugador, *apuesta);
    auto resultado = serializador->deserializarDatos();
    
    EXPECT_EQ(resultado.first, "Test123");
    EXPECT_EQ(resultado.second, 1500);
}

// Prueba: Dinero cero es válido
TEST_F(SerializadorTest, DineroCero) {
    jugador->setNombre("Broke");
    apuesta->setDineroTotal(0);
    
    serializador->guardarPartida(*jugador, *apuesta);
    auto resultado = serializador->deserializarDatos();
    
    EXPECT_EQ(resultado.first, "Broke");
    EXPECT_EQ(resultado.second, 0);
}

// Prueba: Dinero muy grande
TEST_F(SerializadorTest, DineroMuyGrande) {
    jugador->setNombre("Millionaire");
    apuesta->setDineroTotal(999999);
    
    serializador->guardarPartida(*jugador, *apuesta);
    auto resultado = serializador->deserializarDatos();
    
    EXPECT_EQ(resultado.first, "Millionaire");
    EXPECT_EQ(resultado.second, 999999);
}
