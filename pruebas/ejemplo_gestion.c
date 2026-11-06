/* Prueba independiente del companero 1. Compilar desde la carpeta principal. */
#include "../ciudad.h"
#include <stdio.h>

int main(void) {
    Ciudad ciudad = {0};
    Edificio edificio;
    Estado estado;

    edificio.xi = 0;
    edificio.xf = 4;
    edificio.altura = 3;

    printf("Prueba: registrar (0, 4, 3). Esperado: cantidad 1.\n");
    estado = registrar_edificio(&ciudad, edificio);
    if (estado == ESTADO_PENDIENTE) {
        printf("PENDIENTE: implementar registrar_edificio.\n");
        return 1;
    }
    if (estado != ESTADO_OK || ciudad.cantidad != 1 ||
        ciudad.edificios[0].xi != 0 || ciudad.edificios[0].xf != 4 ||
        ciudad.edificios[0].altura != 3) {
        printf("FALLO: el edificio no se registro correctamente.\n");
        return 1;
    }

    printf("Prueba: rechazar (2, 2, 1) y conservar el registro anterior.\n");
    edificio.xi = 2;
    edificio.xf = 2;
    edificio.altura = 1;
    estado = registrar_edificio(&ciudad, edificio);
    if (estado != ESTADO_INVALIDO || ciudad.cantidad != 1 ||
        ciudad.edificios[0].xi != 0 || ciudad.edificios[0].xf != 4 ||
        ciudad.edificios[0].altura != 3) {
        printf("FALLO: se esperaba ESTADO_INVALIDO y conservar el edificio.\n");
        return 1;
    }

    printf("OK: registro valido y rechazo del edificio invalido.\n");
    printf("Falta probar modificar, eliminar, listar y el limite de capacidad.\n");
    return 0;
}
