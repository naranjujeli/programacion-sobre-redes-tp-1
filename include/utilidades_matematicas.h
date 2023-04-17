#ifndef UTILIDADES_MATEMATICAS_H
#define UTILIDADES_MATEMATICAS_H

#include <Caballo.h>

void reiniciarRandomSeed();
int enteroAleatorio(const int &, const int &);
float flotanteAleatorio(const float &, const float &);
int redondearHaciaArriba(const float &);
float sacarPromedio(const std::vector<Caballo> &);

#endif