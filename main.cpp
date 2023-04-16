#include "stdafx.h" // Bibliotecas estándar de C++
#include "tipos_disponibles.h" // Tipos de caballo en un enum (1 al 6)
#include "entrada_salida.h" // Funciones para tomar entrada del usuario o mostrar datos en la consola
#include "utilidades_matematicas.h" // Funciones matemáticas agrupadas
#include "caballos.h" // Procedimientos para calcular el tiempo de cada tipo caballo


int calcularTiempo(const int &, const std::string &);


int main() {
    // TODO Abarcar varias carreras

    /*** Tomar entrada del usuario ***/
    // Cantidad de caballos
    int cantidad_caballos;
    obtenerCantidadCaballos(cantidad_caballos);
    // Tipo y nombre
    std::vector<int> tipos_ingresados(cantidad_caballos);
    std::vector<std::string> nombres_ingresados(cantidad_caballos);
    obtenerCaballos(cantidad_caballos, tipos_ingresados, nombres_ingresados);

    // waitpid()

    /*** Calcular tiempos ***/
    std::vector<float> tiempo(cantidad_caballos);
    for (int i = 0; i < cantidad_caballos; i++) {
        reiniciarRandomSeed();
        tiempo[i] = calcularTiempo(tipos_ingresados[i], nombres_ingresados[i]);
    }

    /*** Mostrar resultados ***/

    /*** Guardar datos ***/


    // Debugging
    /* 
    std::cout << "Caballo cuarto de milla: " << caballoCuartoDeMilla() << std::endl;
    std::cout << "Caballo rayo: " << caballoRayo() << std::endl;
    std::cout << "Caballo lineal: " << caballoLineal() << std::endl;
    std::cout << "Caballo exponencial: " << caballoExponencial() << std::endl;
    std::cout << "Duoballo: " << caballoDuoballo() << std::endl;
    std::cout << "Crono caballo: " << caballoCrono() << std::endl;
    */

    return 0;
}

int calcularTiempo(const int &tipo, const std::string &nombre) {
    int arreglo_pipe[2];
    if (pipe(arreglo_pipe) == -1) {
        throw "Error al ejecutar la función pipe()";
    }

    int pid = fork();
    if (pid == -1) {
        throw "Error al ejecutar la función fork()";
    }
    
    if (pid == 0) {
        int tiempo;
        switch (tipo) {
            case tipos_disponibles::CUARTO_DE_MILLA:
                tiempo = caballoCuartoDeMilla();
                break;
            case tipos_disponibles::RAYO:
                tiempo = caballoRayo();
                break;
            case tipos_disponibles::LINEAL:
                tiempo = caballoLineal();
                break;
            case tipos_disponibles::EXPONENCIAL:
                tiempo = caballoExponencial();
                break;
            case tipos_disponibles::DUOBALLO:
                tiempo = caballoDuoballo();
                break;
            case tipos_disponibles::CRONO:
                tiempo = caballoCrono();
                break;
        }

        write(arreglo_pipe[1], &tiempo, sizeof(int));
        close(arreglo_pipe[1]);

        std::cout << nombre << " >> Terminé en " << tiempo << " segundos" << std::endl;
        exit(0);
    }

    wait(NULL);

    int *tiempo;
    read(arreglo_pipe[0], tiempo, sizeof(int));
    return *tiempo;
}