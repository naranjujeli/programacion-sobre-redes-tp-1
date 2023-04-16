#ifndef UTILIDADES_ALGORITMICAS_CPP
#define UTILIDADES_ALGORITMICAS_CPP

#include "stdafx.h"
#include "utilidades_algoritmicas.h"
#include "Caballo.h"

void bubbleSort(std::vector<Caballo> &caballos) {
    for (int i = 0; i < caballos.size(); i++) {
        for (int j = i; j < caballos.size()-1; j++) {
            if (caballos[j].tiempo > caballos[j+1].tiempo) {
                std::swap(caballos[j], caballos[j+1]);
            } else {
                break;
            }
        }
    }
}

#endif