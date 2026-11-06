/* Horizonte temporal: no depende del calculo del companero 2. */
#include "../ciudad.h"
#include <stdio.h>

int main(void) {
    Horizonte horizonte = {0};
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

    printf("Prueba: mostrar (0,2,2), (2,4,0), (4,5,3).\n");
    estado = graficar_horizonte(&horizonte);
    if (estado == ESTADO_PENDIENTE) {
        printf("PENDIENTE: implementar graficar_horizonte.\n");
        return 1;
    }
    if (estado != ESTADO_OK) {
        printf("FALLO: no se pudo mostrar el grafico.\n");
        return 1;
    }
    printf("La funcion regreso al programa. REVISION VISUAL PENDIENTE:\n");
    printf("verifica el perfil, el hueco de altura 0, los ejes y la escala.\n");
    printf("Codigo 2: la prueba no puede aprobar visualmente el dibujo por si sola.\n");
    return 2;
}
