#ifndef ENTRADA_SALIDA_H
#define ENTRADA_SALIDA_H

#include <Caballo.h>

int obtenerNumero(const std::string &, const int &, const int &);
std::string obtenerString();
void menuFinal();
void obtenerPuesto(const std::vector<Caballo> &, int &);
void mostrarPuesto(const std::vector<Caballo> &, const int &);
void mostrarPromedioTodosLosCaballos(const std::vector<Caballo> &); 
void mostrarMejorPeor(const Caballo &, const Caballo &);
void obtenerCantidadCaballos(int &);
void mostrarTipos();
void obtenerTipo(int &);
void obtenerNombre(std::string &);
void obtenerCaballos(std::vector<Caballo> &);

#endif