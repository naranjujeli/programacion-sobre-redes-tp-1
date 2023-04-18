#ifndef CABALLO_H
#define CABALLO_H

#include <stdafx.h>

struct Caballo {
    std::string nombre;
    int tipo;
    int tiempo=0;
    int puesto;

    Caballo(int tiempo=0) : tiempo(tiempo) {}
};

#endif