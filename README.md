# [ BlackJack ] 🃏
*Proyecto del curso Fundamentos de Programación Orientada a Objetos (FPOO) de la Universidad del Valle.*

Juego de BlackJack clásico desarrollado en C++ aplicando los conceptos y temas aprendidos en clase.

![showCase](~showCase.gif)

## ⭐ Features
* 💾 Guardardo y cargado de partida
* 📂 Estructura MCV
* 🎨 Arte ASCII atractivo
* 🤖 Test unitarios con Google Test

## 🛠️ Estructura del proyecto
* `controlador/`
    * `Controlador.cpp`: Gestiona inputs e interacciones
* `modelos/`
    * `Apuesta.cpp`: Manejar economía de jugador
    * `Carta.cpp`: Representa cartas con atributos como palo y valor
    * `Mazo.cpp`: Contiene objetos `Carta` y los maneja
    * `Participante.cpp`: Superclase de jugador y crupier
    * `Crupier.cpp`: Distribuye cartas y decide la partida
    * `Jugador.cpp`: Maneja su mano y su nombre para el guardado
    * `Serializador.cpp`: Serializa los datos de partida para guardado/cargado
* `vista/`
    * `Vista.cpp`: Renderizar todo el juego
* `main.cpp`: Lógica y búcle principal de juego

## 🧩 Instalación

### 1. Clonado
Debes tener [Git](https://git-scm.com/) instalado y escribir estos comandos en la terminal del directorio donde quieres clonar el proyecto:

```
$ git clone https://github.com/Lulow08/BlackJack.git
$ cd BlackJack
```

o puedes descargar el [ZIP](https://github.com/Lulow08/BlackJack/archive/refs/heads/main.zip) del proyecto

### 2. Build y Compilación
Puedes realizarlo facilmente con [CMake](https://cmake.org/) abriendo la carpeta principal del proyecto en tu IDE preferido,  ejecutar una terminal dentro de ella y poner:

### Linux
```
$ mkdir build      # crea la carpeta build
$ cd build         # ingresa a la carpeta build
$ cmake ..         # genera toda la configuración
$ make             # hace el build
$ ./blackjack      # ejecuta el programa
```

### Windows (con MinGW)
```
$ mkdir build                     # crea la carpeta build
$ cd build                        # ingresa a la carpeta build
$ cmake -G "MinGW Makefiles" ..   # genera toda la configuración
$ cmake --build .                 # hace el build
$ ./blackjack                     # ejecuta el programa
```

Asegurate de tener CMake, curl, git instalados y añadidos al PATH

## 🦺 Tests
Antes de hacerlos, asegurate de eliminar tu anterior carpeta build

### Linux
```
$ cmake -S . -B build
$ cmake --build build
$ cd build
$ ctest
```

### Windows (con MinGW)
```
$ cmake -G "MinGW Makefiles" -S . -B build
$ cmake --build build
$ cd build
$ ctest
```

## 📝 Notas
* Usa UNICODE y ANSI para que el arte ASCII se vea lo mejor posible
* Fuente de la terminal en el `showCase.gif`: fragment mono
* El proyecto no requiere dependencias, solo las mencionadas para compilación y ejecución

## 👥 Integrantes
* Yostin Ramirez - 2519674
* Lesly Zapata - 2516574
* Joseph Terreros - 2521011
* Juan Manuel Rosero - 2520822
* Juan Esteban Mina - 2518466

