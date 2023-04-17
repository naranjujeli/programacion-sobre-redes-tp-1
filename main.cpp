#include <stdafx.h> // Bibliotecas estándar de C++
#include <tipos_disponibles.h> // Tipos de caballo en un enum (1 al 6)
#include <Caballo.h> // Estructura que agrupa los datos de cada caballo
#include <entrada_salida.h> // Funciones para tomar entrada del usuario o mostrar datos en la consola
#include <utilidades_matematicas.h> // Funciones matemáticas agrupadas
#include <utilidades_algoritmicas.h> // Funciones de ordenamiento y otras
#include <caballos.h> // Procedimientos para calcular el tiempo de cada tipo caballo

void calcularTiempo(Caballo &);


int main() {
    // TODO Abarcar varias carreras

    std::vector<std::pair<Caballo, Caballo>> ganadores_perdedores;
    
    /*** Tomar entrada del usuario ***/
    // Cantidad de caballos
    int cantidad_caballos;
    obtenerCantidadCaballos(cantidad_caballos);
    // Tipo y nombre
    std::vector<Caballo> caballos(cantidad_caballos);
    obtenerCaballos(caballos);

    /*** Calcular tiempos ***/
    for (int i = 0; i < cantidad_caballos; i++) {
        reiniciarRandomSeed();
        calcularTiempo(caballos[i]);
    }

    /*** Ordenar caballos y asignar puestos ***/
    bubbleSort(caballos);
    for (int i = 0; i < caballos.size(); i++) {
        caballos[i].puesto = i+1;
    }

    /*** Guardar datos ***/
    ganadores_perdedores.push_back(std::make_pair(caballos[0], *(caballos.end()-1)));

    /*** Mostrar resultados ***/
    std::cout << "El ganador de la carrera fue: " << (ganadores_perdedores.end()-1)->first.nombre << std::endl;
    std::cout << "El último de la carrera fue: " << (ganadores_perdedores.end()-1)->second.nombre << std::endl;
    
    return 0;
}

void calcularTiempo(Caballo &caballo) {
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
        switch (caballo.tipo) {
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

        std::cout << caballo.nombre << " >> Terminé en " << tiempo << " segundos" << std::endl;
        exit(0);
    }

    wait(NULL);

    read(arreglo_pipe[0], &caballo.tiempo, sizeof(int));
}