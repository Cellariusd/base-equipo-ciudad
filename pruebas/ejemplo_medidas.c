/* Horizonte temporal escrito a mano; no depende de horizonte.c. */
#include "../ciudad.h"
#include <stdio.h>

int main(void) {
    Horizonte horizonte = {0};
    Medidas medidas = {0};
    Estado estado;

    horizonte.cantidad = 3;
    horizonte.segmentos[0].inicio = 0;
    horizonte.segmentos[0].fin = 2;
    horizonte.segmentos[0].altura = 2;
    horizonte.segmentos[1].inicio = 2;
    horizonte.segmentos[1].fin = 4;
    horizonte.segmentos[1].altura = 0;
    horizonte.segmentos[2].inicio = 4;
    horizonte.segmentos[2].fin = 5;
    horizonte.segmentos[2].altura = 3;

    printf("Horizonte: (0,2,2), (2,4,0), (4,5,3).\n");
    printf("Esperado: area 7, perimetro 16.\n");
    estado = calcular_medidas(&horizonte, &medidas);
    if (estado == ESTADO_PENDIENTE) {
        printf("PENDIENTE: implementar calcular_medidas.\n");
        return 1;
    }
    if (estado != ESTADO_OK) {
        printf("FALLO: no se pudieron calcular las medidas.\n");
        return 1;
    }
    printf("Obtenido: area %.2f, perimetro %.2f.\n", medidas.area, medidas.perimetro);
    if (medidas.area != 7 || medidas.perimetro != 16) {
        printf("FALLO: los resultados no coinciden.\n");
        return 1;
    }
    printf("OK: medidas para dos componentes separados.\n");
    printf("Todavia faltan el ejemplo oficial y las demas pruebas.\n");
    return 0;
}
