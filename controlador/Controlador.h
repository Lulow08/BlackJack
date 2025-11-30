/*
    Proyecto: BlackJack (Tercera entrega)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Información CRC:
   
    Clase: Controlador

    Responsabilidades:
        - Gestionar la entrada del usuario en los menús
        - Validar las opciones seleccionadas
        - Coordinar las acciones del jugador durante la partida
        - Servir como intermediario entre la Vista y la lógica del juego
        - Controlar el flujo de interacción del usuario

    Colaboradores:
        - Vista (obtiene y muestra información al usuario)
        - Jugador (ejecuta acciones del jugador)
        - Crupier (coordina las acciones del juego)

    @details Implementa el patrón MVC (Model-View-Controller) actuando como controlador 
             que gestiona la interacción del usuario. Separa la lógica de presentación (Vista) de 
             la lógica de negocio (Participante, Crupier, Jugador). Está en desarrollo para 
             centralizar toda la gestión de entrada del usuario.
    
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

    @date Fecha: Noviembre 2025
*/

#pragma once

#include "Vista.h"

class Controlador {
    public:
        Controlador(Vista& pVista);

        int obtenerEleccionMenu(int opcionMin, int opcionMax) const;
        void obtenerAccionJugador() const;

    private:
        Vista& vista;
};