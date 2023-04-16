#ifndef ENTRADA_SALIDA_CPP
#define ENTRADA_SALIDA_CPP

#include "stdafx.h"
#include "tipos_disponibles.h"
#include "entrada_salida.h"

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

#endif