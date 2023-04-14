#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>

enum tipos_disponibles {
    CUARTO_DE_MILLA=1,
    RAYO,
    LINEAL,
    EXPONENCIAL,
    DUOBALLO,
    CRONO //6
};

int enteroAleatorio(const int &minimo, const int &maximo) {
    return rand() % maximo + minimo;
}

float flotanteAleatorio(const float &minimo, const float &maximo) {
    return (float)rand() / (float)RAND_MAX * (maximo-minimo) + minimo;
}

void obtenerCantidadCaballos(int &cantidad_caballos) {
    std::cout << "Ingrese la cantidad de caballos: "; std::cin >> cantidad_caballos;
}

void mostrarTipos() {
    std::cout << tipos_disponibles::CUARTO_DE_MILLA << ". Cuarto de milla" << std::endl;
    std::cout << tipos_disponibles::RAYO << ". Rayo" << std::endl;
    std::cout << tipos_disponibles::LINEAL << ". Lineal" << std::endl;
    std::cout << tipos_disponibles::EXPONENCIAL << ". Exponencial" << std::endl;
    std::cout << tipos_disponibles::DUOBALLO << ". Duoballo" << std::endl;
    std::cout << tipos_disponibles::CRONO << ". Crono" << std::endl;
}

// TODO validar que sea un numero
void obtenerTipo(int &tipo) {
    mostrarTipos();
    do {
        std::cout << "Ingrese tipo (número correspondiente): "; std::cin >> tipo;
    } while (tipo < tipos_disponibles::CUARTO_DE_MILLA || tipo > tipos_disponibles::CRONO);
}

// TODO validar que no sea un string vacío
void obtenerNombre(std::string &nombre) {
    std::cout << "Ingrese nombre: "; std::cin >> nombre;
}

void obtenerCaballos(const int &cantidad_caballos, std::vector<int> &tipos_ingresados, std::vector<std::string> &nombres_ingresados) {
    for (int i = 0; i < cantidad_caballos; i++) {
        std::cout << "CABALLO NUMERO " << i+1 << std::endl;
        obtenerTipo(tipos_ingresados[i]);
        obtenerNombre(nombres_ingresados[i]);
    }
}

void reiniciarRandomSeed() {
    srand(time(NULL));
}

float calcularTiempo(const int &tipo) {
    float arreglo_pipe[2];
    if (pipe(arreglo_pipe) == -1) {
        throw Exception("Error al ejecutar la función pipe()");
    }

    int pid = fork();
    if (pid == -1) {
        throw Exception("Error al ejecutar la función fork()");
    }
    
    if (pid == 0) {
        float tiempo;
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
        write(arreglo_pipe[1], &tiempo, sizeof(float));
        close(arreglo_pipe[1]);
        exit(0);
    }

    wait(NULL);

    float *tiempo;
    read(arreglo_pipe[0], tiempo, sizeof(float));
    return *tiempo;
}

float caballoCuartoDeMilla() {
    float tiempo_total = 0.f;
    while (true) {
        tiempo_total += 2.f;
        if (enteroAleatorio(1, 100) <= 5) {
            break;
        }
    }
    return tiempo_total;
}

float caballoRayo() {
    float tiempo_total = 0.f;
    while (true) {
        tiempo_total += 1.f;
        if (enteroAleatorio(1, 100) <= 3) {
            break;
        }
    }
    return tiempo_total;
}

float caballoLineal() {
    float tiempo_total = 0.f;
    int iteraciones = 1;
    while (true) {
        tiempo_total += 3;
        if (enteroAleatorio(1, 100) <= 2*iteraciones) {
            break;
        }
        iteraciones++;
    }
    return tiempo_total;
}

float caballoExponencial() {
    float tiempo_total = 0.f;
    int iteraciones = 1;
    while (true) {
        tiempo_total += 0.5f;
        if (enteroAleatorio(1, 100) <= (1 - pow(0.98, iteraciones)) * 100) {
            break;
        }
        iteraciones++;
    }
    return tiempo_total;
}

float caballoDuoballo() {
    if (*(to_string(getppid()).back()) > '5') {
        return caballoLineal();
    } else {
        return caballoExponencial();
    }
}

float caballoCrono() {
    float tiempo_total = 0.f;
    while (true) {
        tiempo_total += flotanteAleatorio(0.1f, 3.5f);
    }
}

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
        tiempo[i] = calcularTiempo(tipos_ingresados[i]);
    }

    /*** Mostrar resultados ***/

    /*** Guardar datos */


    // Debugging
    /* 
    std::cout << "Caballo cuarto de milla: " << caballoCuartoDeMilla() << std::endl;
    std::cout << "Caballo rayo: " << caballoRayo() << std::endl;
    std::cout << "Caballo lineal: " << caballoLineal() << std::endl;
    std::cout << "Caballo exponencial: " << caballoExponencial() << std::endl;
    */

    return 0;
}