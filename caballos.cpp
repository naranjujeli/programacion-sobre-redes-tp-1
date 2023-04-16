#ifndef CABALLOS_CPP
#define CABALLOS_CPP

#include "stdafx.h"
#include "utilidades_matematicas.h"
#include "Caballo.h"
#include "caballos.h"

int caballoCuartoDeMilla() {
    int tiempo_total = 0;
    while (true) {
        tiempo_total += 2;
        if (enteroAleatorio(1, 100) <= 5) {
            break;
        }
    }
    return tiempo_total;
}

int caballoRayo() {
    int tiempo_total = 0;
    while (true) {
        tiempo_total += 1;
        if (enteroAleatorio(1, 100) <= 3) {
            break;
        }
    }
    return tiempo_total;
}

int caballoLineal() {
    int tiempo_total = 0;
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

int caballoExponencial() {
    float tiempo_total = 0.f;
    int iteraciones = 1;
    while (true) {
        tiempo_total += 0.5f;
        if (enteroAleatorio(1, 100) <= (1 - pow(0.98, iteraciones)) * 100) {
            break;
        }
        iteraciones++;
    }
    return redondearHaciaArriba(tiempo_total);
}

int caballoDuoballo() {
    if (std::to_string(getppid()).back() > '5') {
        return caballoLineal();
    }
    return caballoExponencial();
}

int caballoCrono() {
    float tiempo_total = 0.f;
    while (true) {
        tiempo_total += flotanteAleatorio(0.1f, 3.5f);
        if (flotanteAleatorio(0.f, 100.f) < 0.05f) {
            break;
        }
    }
    return redondearHaciaArriba(tiempo_total);
}

#endif