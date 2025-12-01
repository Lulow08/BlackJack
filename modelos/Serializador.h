/*
    Proyecto: BlackJack
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Información CRC:
   
    Clase: Serializador

    Responsabilidades:
        - Serializar datos del jugador y apuesta a formato CSV
        - Deserializar datos desde archivo CSV
        - Guardar partida en archivo de texto
        - Validar integridad de datos al cargar (archivo vacío, corrupto, errores de apertura)
        - Manejar errores de archivo mostrando mensajes al usuario
        - Convertir datos entre formato de almacenamiento y objetos del juego

    Colaboradores:
        - Jugador (obtiene y establece nombre del jugador)
        - Apuesta (obtiene y establece dinero total)
        - Vista (muestra información durante operaciones)
        - Controlador (utiliza para mostrar mensajes de error)

    @details Implementa el patrón de persistencia para guardar y cargar partidas del 
             juego. Utiliza formato CSV simple (nombre,dinero) para almacenar el estado de 
             la partida. Realiza validaciones al cargar, verifica apertura de 
             archivo, datos vacíos, formato corrupto y conversión numérica. Comunica errores 
             al usuario a través del Controlador. Mantiene referencias a Vista y Controlador 
             para coordinación de mensajes
    
    Autores:
    Lesly Zapata
    Yostin Ramirez
    Juan Manuel Rosero
    Joseph Terreros
    Juan Esteban Mina

    Correos:
    lesly.zapata@correounivalle.edu.co
    yostin.ramirez@correounivalle.edu.co
    joseph.terreros@correounivalle.edu.co
    juan.encarnacion@correounivalle.edu.co
    juan.esteban.mina@correounivalle.edu.co

    @date Fecha: Diciembre 2025
*/

#pragma once

#include <string>

#include "Jugador.h"
#include "Apuesta.h"
#include "Vista.h"
#include "Controlador.h"

class Serializador {
    public:
        Serializador(const std::string& pNombreArchivo, const Vista& pVista, const Controlador& pControlador);

        std::string serializarDatos(const Jugador& jugador, const Apuesta& apuesta);
        std::pair<std::string, int> deserializarDatos();

        void guardarPartida(const Jugador& jugador, const Apuesta& apuesta);

    private:
        std::string nombreArchivo;
        const Vista& vista;
        const Controlador& controlador;
};