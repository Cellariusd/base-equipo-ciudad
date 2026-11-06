#include "ciudad.h"

/*
 * COMPANERO 3: AREA Y PERIMETRO DE LA CIUDAD
 *
 * Tu tarea comienza cuando ya tenemos el horizonte. No necesitas volver a
 * buscar que edificio es mas alto: para probar, usaras segmentos preparados
 * a mano; despues, el programa recibira los del companero 2.
 *
 * `horizonte` contiene los tramos de entrada. Por ejemplo, accedes al primer
 * tramo con horizonte->segmentos[0] y a la cantidad con horizonte->cantidad.
 * Guarda las respuestas en resultado->area y resultado->perimetro.
 *
 * Primero piensa en el area: para cada tramo, su ancho es fin - inicio.
 * Multiplica ese ancho por su altura y suma todos los resultados.
 *
 * Para el perimetro de la union, suma techo y base de cada tramo con altura
 * positiva: 2 * ancho. Luego suma cuanto sube o baja el perfil en cada
 * cambio de altura, empezando y terminando en 0. El ancho de un hueco no
 * cuenta como techo ni como base. No sumes los perimetros individuales de
 * edificios superpuestos: contarias bordes interiores que ya no se ven.
 *
 * Ejemplo: (0,2,2), (2,4,0), (4,5,3).
 * Area: (2*2) + (2*0) + (1*3) = 7.
 * Perimetro: 6 horizontales + (2+2+3+3) verticales = 16.
 *
 * Si no hay segmentos, guarda area 0 y perimetro 0. Devuelve ESTADO_OK solo
 * cuando ambos resultados esten calculados. La version actual esta pendiente.
 *
 * Abre pruebas/ejemplo_medidas.c para ver como se preparan los datos sin
 * depender de horizonte.c. Desde la carpeta principal en MSYS2 UCRT64:
 * gcc -std=c11 -Wall -Wextra -Wpedantic -Werror pruebas/ejemplo_medidas.c medidas.c -o ejemplo_medidas.exe
 * ./ejemplo_medidas.exe
 * Al comienzo veras PENDIENTE; despues de implementar, compara con 7 y 16.
 * No olvides el ejemplo oficial: area 95 y perimetro 74. Hay mas casos en
 * pruebas/casos.md.
 */
Estado calcular_medidas(const Horizonte *horizonte, Medidas *resultado) {
    (void)horizonte; (void)resultado;
    return ESTADO_PENDIENTE;
}
