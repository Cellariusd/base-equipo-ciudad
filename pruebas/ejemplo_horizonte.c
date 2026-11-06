/* Datos escritos a mano: no depende de la gestion de edificios. */
#include "../ciudad.h"
#include <stdio.h>

int main(void) {
    Ciudad ciudad = {0};
    Horizonte horizonte = {0};
    Estado estado;
    int i;

    ciudad.cantidad = 2;
    ciudad.edificios[0].xi = 0;
    ciudad.edificios[0].xf = 2;
    ciudad.edificios[0].altura = 2;
    ciudad.edificios[1].xi = 4;
    ciudad.edificios[1].xf = 5;
    ciudad.edificios[1].altura = 3;

    printf("Edificios: (0,2,2), (4,5,3).\n");
    printf("Horizonte esperado: (0,2,2), (2,4,0), (4,5,3).\n");
    estado = calcular_horizonte(&ciudad, &horizonte);
    if (estado == ESTADO_PENDIENTE) {
        printf("PENDIENTE: implementar calcular_horizonte.\n");
        return 1;
    }
    if (estado != ESTADO_OK || horizonte.cantidad != 3) {
        printf("FALLO: se esperaban tres segmentos.\n");
        return 1;
    }

    printf("Horizonte obtenido:\n");
    for (i = 0; i < horizonte.cantidad; i++) {
        printf("(%.2f, %.2f, %.2f)\n", horizonte.segmentos[i].inicio,
               horizonte.segmentos[i].fin, horizonte.segmentos[i].altura);
    }
    if (horizonte.segmentos[0].inicio != 0 || horizonte.segmentos[0].fin != 2 ||
        horizonte.segmentos[0].altura != 2 || horizonte.segmentos[1].inicio != 2 ||
        horizonte.segmentos[1].fin != 4 || horizonte.segmentos[1].altura != 0 ||
        horizonte.segmentos[2].inicio != 4 || horizonte.segmentos[2].fin != 5 ||
        horizonte.segmentos[2].altura != 3) {
        printf("FALLO: uno o mas segmentos no coinciden.\n");
        return 1;
    }
    printf("OK: el horizonte incluye el espacio vacio.\n");
    printf("Todavia faltan las demas configuraciones de pruebas/casos.md.\n");
    return 0;
}
