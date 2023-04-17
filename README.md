# Primer TP de Programación sobre Redes

Este proyecto fue desarrollado en el lenguaje de programación C++. El objetivo del trabajo es desarrollar los conocimientos vistos en la materia de Programación sobre Redes acerca de la manipulación de procesos con las funciones `fork` y `pipe` en C/C++.

## Resumen

El programa es una simulación de una carrera de caballos de distintos tipos, donde lo que se usa para determinar el tiempo que cada tipo de caballo tarda en terminar la carrera es lo que distingue a los mismos. El programa es ejecutado por medio de la consola. El usuario ingresa cuántos caballos van a correr, el tipo de cada uno y su respectivo nombre (de manera que se los pueda identificar más tarde). Cada caballo representa un proceso, que calculará el propio tiempo que tarda en terminar la carrera y retornará al proceso padre (el proceso principal) dicho valor. Al final se muestra automáticamente quién fue el caballo ganador y quién el perdedor. Entre otras cosas, el programa facilita un menú de opciones con el que el usuario puede consultar una posición del *ranking* para ver su tiempo, pedir que se calcule el promedio de tiempos, volver a iniciar la simulación, etc.

## Distribución de los archivos

En el directorio *root* se encuentran todos los archivos .cpp, que conforman el programa en sí, junto con el archivo [makefile](/makefile), que facilita la compilación de todos aquellos archivos. Se incluye, además, la carpeta [include](/include/), contenedora de todos los *headers* que hacen posible la compilación de múltiples archivos en un solo ejecutable.

### ¿Qué es un *header*?

Los [*headers*](https://learn.microsoft.com/en-us/cpp/cpp/header-files-cpp?view=msvc-170) son un tipo de archivo específico de C/C++ que permite declarar funciones, variables, clases, estructuras. Pero sin necesidad de definirlas. Así, cada módulo puede saber de la existencia de estos elementos desde la etapa de compilación. Estas declaraciones son una promesa de que la definición está en alguna parte del código, aún si todavía no fue compilada.

### ¿Qué hacen las líneas que comienzan con '#'?

Estas son instrucciones para el pre-compilador. La pre-compilación es la etapa que viene justo antes de la compilación, y en la misma se hacen algunos cambios a los archivos antes de pasarlos a código máquina. Un ejemplo de instrucción es:
```
#include <iostream>
```
La función de `include` es incluir (pegar el contenido de) un archivo justo a partir de esa línea. En este caso es el *header* `iostream`, que posee funciones para la salida y la entrada estándar por consola, entre otras cosas.
Otro ejemplo son las líneas:
```
#ifndef CABALLOS_CPP
#define CABALLOS_CPP

// Código aquí

#endif
```
Estas líneas pueden leerse en practicamente todos los archivos del repositorio. Lo que hacen es declarar macros para verificar si el código o los archivos incluidos dentro del `if` no han sido ya compilados y se produzca una sobreescritura.

## Compilación del programa

Para compilar este proyecto se recomienda el uso de `make`, ya que existe un archivo preparado específicamente para usar dicho programa. Los pasos son los siguientes:
1. Descargar el repositorio desde github en una carpeta en nuestro sistema UNIX
2. Entrar a la carpeta de descarga con el comando `cd`
```
$ cd <ruta del archivo>
```
3. Instalar `make`
```
$ sudo apt-get install make
```
4. Ejecutar `make`
```
$ make
```
5. En este punto, el programa ya ha sido compilado y el binario ejecutable se encuentra en el directorio *root* con el nombre `tp_1_carrera_de_caballos`. Podemos iniciarlo cuando queramos así:
```
$ ./tp_1_carrera_de_caballos
```
