#ifndef UTILIDADES_MATEMATICAS_CPP
#define UTILIDADES_MATEMATICAS_CPP

#include "stdafx.h"
#include "utilidades_matematicas.h"

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

#endif