/* Ciudad temporal: se construye aqui sin registrar desde el menu. */
#include "../ciudad.h"
#include <stdio.h>

int main(void) {
    Ciudad ciudad = {0};
    Estado estado;

    ciudad.cantidad = 2;
    ciudad.edificios[0].xi = 0;
    ciudad.edificios[0].xf = 2;
    ciudad.edificios[0].altura = 2;
    ciudad.edificios[1].xi = 4;
    ciudad.edificios[1].xf = 5;
    ciudad.edificios[1].altura = 3;

    printf("Prueba: mostrar (0,2,2) y (4,5,3) como dos rectangulos.\n");
    estado = graficar_edificios(&ciudad);
    if (estado == ESTADO_PENDIENTE) {
        printf("PENDIENTE: implementar graficar_edificios.\n");
        return 1;
    }
    if (estado != ESTADO_OK) {
        printf("FALLO: no se pudo mostrar el grafico.\n");
        return 1;
    }
    printf("La funcion regreso al programa. REVISION VISUAL PENDIENTE:\n");
    printf("verifica los dos rectangulos, sus posiciones, ejes, etiquetas y escala.\n");
    printf("Codigo 2: la prueba no puede aprobar visualmente el dibujo por si sola.\n");
    return 2;
}
