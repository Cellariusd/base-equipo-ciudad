/* Prueba independiente: usa el archivo oficial sin el menu ni gestion. */
#include "../ciudad.h"
#include <stdio.h>

int main(void) {
    Ciudad ciudad = {0};
    Ciudad recuperada = {0};
    Estado estado;
    const char *entrada = "pruebas/ejemplo.txt";
    const char *salida = "pruebas/_salida_ejemplo_ciudad.txt";
    int i;

    printf("Prueba: cargar los cinco edificios de %s.\n", entrada);
    estado = cargar_ciudad(&ciudad, entrada);
    if (estado == ESTADO_PENDIENTE) {
        printf("PENDIENTE: implementar cargar_ciudad.\n");
        return 1;
    }
    if (estado != ESTADO_OK || ciudad.cantidad != 5) {
        printf("FALLO: se esperaban cinco edificios.\n");
        return 1;
    }

    printf("Edificios cargados:\n");
    for (i = 0; i < ciudad.cantidad; i++) {
        printf("(%.2f, %.2f, %.2f)\n", ciudad.edificios[i].xi,
               ciudad.edificios[i].xf, ciudad.edificios[i].altura);
    }
    if (ciudad.edificios[0].xi != 0 || ciudad.edificios[0].xf != 4 ||
        ciudad.edificios[0].altura != 7 || ciudad.edificios[4].xi != 19 ||
        ciudad.edificios[4].xf != 21 || ciudad.edificios[4].altura != 10) {
        printf("FALLO: el primer o ultimo edificio no coincide con el ejemplo.\n");
        return 1;
    }

    printf("Prueba: guardar en %s y cargar nuevamente.\n", salida);
    estado = guardar_ciudad(&ciudad, salida);
    if (estado == ESTADO_PENDIENTE) {
        printf("PENDIENTE: implementar guardar_ciudad.\n");
        return 1;
    }
    if (estado != ESTADO_OK) {
        printf("FALLO: no se pudo guardar la ciudad.\n");
        return 1;
    }
    estado = cargar_ciudad(&recuperada, salida);
    if (estado != ESTADO_OK || recuperada.cantidad != ciudad.cantidad) {
        printf("FALLO: no se pudo recuperar la ciudad guardada.\n");
        return 1;
    }
    for (i = 0; i < ciudad.cantidad; i++) {
        if (recuperada.edificios[i].xi != ciudad.edificios[i].xi ||
            recuperada.edificios[i].xf != ciudad.edificios[i].xf ||
            recuperada.edificios[i].altura != ciudad.edificios[i].altura) {
            printf("FALLO: el edificio %d no coincide.\n", i + 1);
            return 1;
        }
    }
    printf("OK: se guardaron y recuperaron los cinco registros.\n");
    printf("Todavia faltan pruebas de archivos invalidos y recuperacion en otro proceso.\n");
    return 0;
}
