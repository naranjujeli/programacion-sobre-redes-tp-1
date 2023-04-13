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

float caballoCuartoDeMilla() {
    float tiempo_total = 0.f;
    while (true) {
        if ((rand() % 100 + 1) <= 5) {
            break;
        }
        tiempo_total += 2.f;
    }
    return tiempo_total;
}

float caballoRayo() {
    float tiempo_total = 0.f;
    while (true) {
        if ((rand() % 100 + 1) <= 3) {
            break;
        }
        tiempo_total += 1.f;
    }
    return tiempo_total;
}

float caballoLineal() {
    float tiempo_total = 0.f;
    int iteraciones = 1;
    while (true) {
        if ((rand() % 100 + 1) <= 2*iteraciones) {
            break;
        }
        tiempo_total += 3;
        iteraciones++;
    }
    return tiempo_total;
}

float caballoExponencial() {
    float tiempo_total = 0.f;
    int iteraciones = 1;
    while (true) {
        if ((rand() % 100 + 1) <= (1 - pow(0.98, iteraciones)) * 100) {
            break;
        }
        tiempo_total += 0.5f;
        iteraciones++;
    }
    return tiempo_total;
}

int main() {
    /*** Tomar entrada del usuario ***/
    // Cantidad de caballos
    int cantidad_caballos;
    obtenerCantidadCaballos(cantidad_caballos);
    // Tipo y nombre
    std::vector<int> tipos_ingresados(cantidad_caballos);
    std::vector<std::string> nombres_ingresados(cantidad_caballos);
    obtenerCaballos(cantidad_caballos, tipos_ingresados, nombres_ingresados);

    /*** Calcular tiempos ***/
    reiniciarRandomSeed();

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