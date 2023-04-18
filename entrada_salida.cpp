#ifndef ENTRADA_SALIDA_CPP
#define ENTRADA_SALIDA_CPP

#include <stdafx.h>
#include <tipos_disponibles.h>
#include <Caballo.h>
#include <entrada_salida.h>
#include <utilidades_matematicas.h>

// Obtener por consola un valor numérico y validarlo
int obtenerNumero(const std::string &mensaje, const int &maximo, const int &minimo) {
    int entrada_como_numero;
    std::string entrada_usuario;
    bool entrada_es_valida = false;
    while (!entrada_es_valida) {
        std::cout << mensaje;
        std::cin >> entrada_usuario;

        entrada_es_valida = true;
        // Corroborar si la entrada está vacía
        if (entrada_usuario.empty()) {
            std::cout << "La entrada está vacía" << std::endl;
            entrada_es_valida = false;
        } else {
            // La entrada no está vacía
            // Corroborar si es un número
            for (auto i = entrada_usuario.begin(); i != entrada_usuario.end() && entrada_es_valida; i++) {
                if (!std::isdigit(*i)) {
                    std::cout << "La entrada no es un número" << std::endl;
                    entrada_es_valida = false;
                }
            }
            if (entrada_es_valida) {
                // La entrada es un número
                // Corroborar si está dentro del rango
                entrada_como_numero = stoi(entrada_usuario);
                if (entrada_como_numero < minimo || entrada_como_numero > maximo) {
                    entrada_es_valida = false;
                    std::cout << "La entrada está fuera de rango" << std::endl;
                }
            }
        }
    } 
    
    return entrada_como_numero;
}

// Obtener por consola un valor string y validarlo
std::string obtenerString(const std::string &mensaje) {
    std::string entrada_usuario;
    bool entrada_es_valida = false;
    while (!entrada_es_valida) {
        entrada_es_valida = true;

        std::cout << mensaje;
        std::cin >> entrada_usuario;
        if (entrada_usuario.empty()) {
            entrada_es_valida = false;
            std::cout << "No se admiten respuestas vacías" << std::endl;
        } else {
            // La entrada no está vacía
            for (auto i = entrada_usuario.begin(); i != entrada_usuario.end() && entrada_es_valida; i++) {
                if (std::isdigit(*i)) {
                    std::cout << "La entrada es o contiene un número" << std::endl;
                    entrada_es_valida = false;
                }
            }
        }
    }

    return entrada_usuario;
}

// Mostrar el menú al final de la simulación
void menuFinal() {
    std::cout << "🚧 La carrera ha finalizado ✨" << std::endl;
    std::cout << "1. Simular otra carrera 🏃‍♂️" << std::endl;
    std::cout << "2. Informacion de un caballo 🤓" << std::endl;
    std::cout << "3. Promedio de los tiempos 🔍" << std::endl;
    std::cout << "4. Ver mejor y peor caballo de todos los tiempos ✅" << std::endl;
    std::cout << "5. Terminar programa 🛑" << std::endl;
}

// Solicitar al usuario el número puesto que quiere revisar
void obtenerPuesto(const std::vector<Caballo> &caballos, int &puesto) {
    std::cout << "Los caballos en esta carrera fueron " << caballos.size() << ":" << std::endl;
    for (int i = 0; i < caballos.size(); i++) {
        std::cout << i+1 << ". " << caballos[i].nombre << std::endl;
    }
    puesto = obtenerNumero("🧠 Ingrese el caballo que quiere revisar: ", caballos.size()-1, 1);
}

// Mostrar información de un determinado puesto
void mostrarPuesto(const std::vector<Caballo> &caballos, const int &puesto) {
    std::cout << "✨ Aquí van los datos del caballo " << caballos[puesto].nombre << ":" << std::endl;
    std::cout << "🕒 Tiempo: " << caballos[puesto].tiempo << std::endl;
    std::cout << "⚡ Tipo: " << caballos[puesto].tipo << std::endl;
}

// Mostrar en la pantalla el promedio de los tiempos de todos los caballos de la carrera
void mostrarPromedioTodosCaballos(const std::vector<Caballo> &caballos) { 
    std::cout << "🔍 El promedio de los caballos es " << promedioTiemposCaballos(caballos) << std::endl;
}

// Mostrar el mejor y el peor caballo hasta el momento
void mostrarMejorPeor(const Caballo &mejor_caballo, const Caballo &peor_caballo) {
    std::cout << "✅ El mejor caballo hasta el momento ha sido " << mejor_caballo.nombre << ", con " << mejor_caballo.tiempo << " segundos" << std::endl;
    std::cout << "⛔ El peor caballo hasta el momento ha sido " << peor_caballo.nombre << ", con " << peor_caballo.tiempo << " segundos" << std::endl;
}

// Solicitar al usuario la cantidad de caballos con los que contará la carrera
void obtenerCantidadCaballos(int &cantidad_caballos) {
    cantidad_caballos = obtenerNumero("Ingrese la cantidad de caballos de esta carrera: ", INT32_MAX, 1);
}

// Mostrar los tipos disponibles que el usuario puede elegir
void mostrarTipos() {
    std::cout << tipos_disponibles::CUARTO_DE_MILLA << ". Cuarto de milla" << std::endl;
    std::cout << tipos_disponibles::RAYO << ". Rayo" << std::endl;
    std::cout << tipos_disponibles::LINEAL << ". Lineal" << std::endl;
    std::cout << tipos_disponibles::EXPONENCIAL << ". Exponencial" << std::endl;
    std::cout << tipos_disponibles::DUOBALLO << ". Duoballo" << std::endl;
    std::cout << tipos_disponibles::CRONO << ". Crono" << std::endl;
}

// Solicitar el número que representa el tipo del nuevo caballo
void obtenerTipo(int &tipo) {
    mostrarTipos();
    tipo = obtenerNumero("👀 Ingrese el tipo (número correspondiente): ", tipos_disponibles::CRONO, tipos_disponibles::CUARTO_DE_MILLA);
    std::cout << "El tipo elegido fue: " << tipo << std::endl;
}

// Solicitar al usuario el nombre del nuevo caballo
void obtenerNombre(std::string &nombre) {
    while (true) {
        std::cout << "📣 Ingrese nombre: "; std::cin >> nombre;
        if (nombre.empty()) {
            std::cout << "🛑 ERROR: Ingrese un nombre valido" << std::endl;
            continue;
        }
        break;
    }
}

// Solicitar información de cada caballo de la carrera
void obtenerCaballos(std::vector<Caballo> &caballos) {
    for (int i = 0; i < caballos.size(); i++) {
        std::cout << "CABALLO NUMERO " << i+1 << std::endl;
        obtenerTipo(caballos[i].tipo);
        obtenerNombre(caballos[i].nombre);
    }
}

#endif