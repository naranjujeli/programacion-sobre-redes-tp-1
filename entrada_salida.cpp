#ifndef ENTRADA_SALIDA_CPP
#define ENTRADA_SALIDA_CPP

#include <stdafx.h>
#include <tipos_disponibles.h>
#include <Caballo.h>
#include <entrada_salida.h>

void menuFinal() {
    std::cout << "La carrera ha finalizado" << std::endl;
    std::cout << "Ingrese un número para realizar las siguientes acciones" << std::endl;
    std::cout << "1. Volver a simular carrera" << std::endl;
    std::cout << "2. Informacion caballo" << std::endl;
    std::cout << "3. Salir" << std::endl;
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

void obtenerTipo(int &tipo) {
    mostrarTipos();
    int numero_ingresado;
    while (true) {
        std::cout << "Ingrese tipo (número correspondiente): ";
        if (!(std::cin >> numero_ingresado)) {
            std::cout << "ERROR: Ingresa un número" << std::endl;
            continue;
        }
        if (numero_ingresado < tipos_disponibles::CUARTO_DE_MILLA || numero_ingresado > tipos_disponibles::CRONO) {
            std::cout << "ERROR: El número no está en la lista" << std::endl;
            continue;
        }
        break;
    }
    tipo = numero_ingresado;
}

void obtenerNombre(std::string &nombre) {
    while (true) {
        std::cout << "Ingrese nombre: "; std::cin >> nombre;
        if (nombre.empty()) {
            std::cout << "ERROR: Ingrese un nombre valido" << std::endl;
            continue;
        }
        break;
    }
}

void obtenerCaballos(std::vector<Caballo> &caballos) {
    for (int i = 0; i < caballos.size(); i++) {
        std::cout << "CABALLO NUMERO " << i+1 << std::endl;
        obtenerTipo(caballos[i].tipo);
        obtenerNombre(caballos[i].nombre);
    }
}

#endif