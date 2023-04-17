#ifndef UTILIDADES_MATEMATICAS_CPP
#define UTILIDADES_MATEMATICAS_CPP

#include <stdafx.h>
#include <Caballo.h>
#include <utilidades_matematicas.h>

void reiniciarRandomSeed() {
    srand(time(NULL));
}

int enteroAleatorio(const int &minimo, const int &maximo) {
    return rand() % maximo + minimo;
}

float flotanteAleatorio(const float &minimo, const float &maximo) {
    return (float)rand() / (float)RAND_MAX * (maximo-minimo) + minimo;
}

int redondearHaciaArriba(const float &valor_flotante) {
    return std::ceil(valor_flotante);
}

float promedioTiemposCaballos(const std::vector<Caballo> &caballos) {
    int suma_tiempos = 0; 
    for (int i = 0; i < caballos.size(); i++) { 
        suma_tiempos += caballos[i].tiempo;
    }
    float promedio = suma_tiempos / caballos.size(); 
    return promedio;
}

#endif