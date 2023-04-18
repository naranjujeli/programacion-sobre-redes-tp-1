#include <stdafx.h> // Bibliotecas estándar de C++
#include <tipos_disponibles.h> // Tipos de caballo en un enum (1 al 6)
#include <Caballo.h> // Estructura que agrupa los datos de cada caballo
#include <entrada_salida.h> // Funciones para tomar entrada del usuario o mostrar datos en la consola
#include <utilidades_matematicas.h> // Funciones matemáticas agrupadas
#include <utilidades_algoritmicas.h> // Funciones de ordenamiento y otras
#include <caballos.h> // Procedimientos para calcular el tiempo de cada tipo caballo

void calcularTiempo(Caballo &);

int main() {
    Caballo mejor_caballo(INT32_MAX), peor_caballo(INT32_MIN);

    int opcion_ingresada = 0;
    do {
        /*** Tomar entrada del usuario ***/
        // No se vuelven a pedir los datos al usuario si se quiere volver a simular la misma carrera
        // Cantidad de caballos
        int cantidad_caballos;
        obtenerCantidadCaballos(cantidad_caballos);
        // Tipo y nombre
        std::vector<Caballo> caballos(cantidad_caballos);
        obtenerCaballos(caballos);

        /*** Calcular tiempos ***/
        for (int i = 0; i < cantidad_caballos; i++) {
            reiniciarRandomSeed();
            calcularTiempo(caballos[i]);
        }

        /*** Ordenar caballos y asignar puestos ***/
        bubbleSort(caballos);
        for (int i = 0; i < caballos.size(); i++) {
            caballos[i].puesto = i+1;
        }

        /*** Guardar datos ***/
        if (caballos[0].tiempo < mejor_caballo.tiempo) mejor_caballo = caballos[0];
        if ((caballos.end()-1)->tiempo > peor_caballo.tiempo) peor_caballo = *(caballos.end()-1);

        /*** Mostrar resultados ***/
        std::cout << "🚩 El ganador de la carrera fue: " << caballos[0].nombre << std::endl;
        std::cout << "🚧 El último de la carrera fue: " << (caballos.end()-1)->nombre << std::endl;
        
        /*** Menu final ***/
        while (opcion_ingresada != 1) {
            // Obtener una respuesta del usuario
            menuFinal();
            opcion_ingresada = obtenerNumero("Ingrese una opción: ", 5, 1); 
            // Actuar según la respuesta
            switch (opcion_ingresada) {
                case 2:
                    // Ver datos de un caballo específico
                    int puesto;
                    obtenerPuesto(caballos, puesto);
                    mostrarPuesto(caballos, puesto);
                    break;
                case 3:
                    // Promedio tiempos 
                    mostrarPromedioTodosCaballos(caballos);
                    break;
                case 4:
                    // Ver mejor y peor
                    mostrarMejorPeor(mejor_caballo, peor_caballo);
                    break;
            }
        }
    } while (opcion_ingresada != 5); 
    
    std::cout << "Nos vemos...👋" << std::endl;
    exit(1);
    
    return 0;
}

void calcularTiempo(Caballo &caballo) {
    // Definir arreglo para la comunicación con pipe()
    int arreglo_pipe[2];
    if (pipe(arreglo_pipe) == -1) {
        throw "🛑 ERROR al ejecutar la función pipe()";
    }

    // Crear un nuevo proceso hijo con fork()
    int pid = fork();
    if (pid == -1) {
        throw "🛑 ERROR al ejecutar la función fork()";
    }
    
    // Calcular el tiempo con el procedimiento que corresponda según el caballo
    if (pid == 0) {
        int tiempo;
        switch (caballo.tipo) {
            case tipos_disponibles::CUARTO_DE_MILLA:
                tiempo = caballoCuartoDeMilla();
                break;
            case tipos_disponibles::RAYO:
                tiempo = caballoRayo();
                break;
            case tipos_disponibles::LINEAL:
                tiempo = caballoLineal();
                break;
            case tipos_disponibles::EXPONENCIAL:
                tiempo = caballoExponencial();
                break;
            case tipos_disponibles::DUOBALLO:
                tiempo = caballoDuoballo();
                break;
            case tipos_disponibles::CRONO:
                tiempo = caballoCrono();
                break;
        }

        // Pasar el tiempo al proceso padre con pipe()
        write(arreglo_pipe[1], &tiempo, sizeof(int));
        close(arreglo_pipe[1]);

        std::cout << caballo.nombre << " 🔥 Terminé en " << tiempo << " segundos" << std::endl;
        exit(0);
    }

    wait(NULL);

    // Leer el tiempo calculado por el proceso hijo
    read(arreglo_pipe[0], &caballo.tiempo, sizeof(int));
}