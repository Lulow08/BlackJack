/*
    Proyecto: BlackJack
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Información CRC:
   
    Clase: Controlador

    Responsabilidades:
        - Gestionar y validar las entradas del usuario
        - Solicitar y validar el nombre del jugador
        - Coordinar la actualización de pantallas según el menú activo

    Colaboradores:
        - Vista (muestra pantallas, mensajes y solicita input)
        - Jugador (obtiene información del jugador)
        - Crupier (obtiene información del crupier)
        - Apuesta (obtiene información de dinero y apuestas)

    @details Implementa el patrón MVC actuando como controlador que gestiona toda la 
             interacción del usuario con el sistema. Valida entradas tanto numéricas como 
             de carácter, maneja errores de input y coordina la actualización de diferentes 
             pantallas del juego (menú principal, apuestas, juego, guardado). Es el intermediario
             entre vista y modelo
    
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

#include "Vista.h"
#include "Jugador.h"
#include "Crupier.h"
#include "Apuesta.h"

enum Menu { APUESTA, JUEGO, GUARDADO };

class Controlador {
    public:
        Controlador(Vista& pVista, Jugador& pJugador, Crupier& pCrupier, Apuesta& pApuesta);

        int getOpcionInt(int opcionMin, int opcionMax) const;
        char getOpcionChar(const std::string& opciones, Menu menu) const;
        void esperarInput(const std::string& texto) const;

        std::string getNombreJugador(size_t charMin, size_t charMax) const;

        void limpiarBuffer() const;

    private:
        Vista& vista;
        Jugador& jugador;
        Crupier& crupier;
        Apuesta& apuesta;
};