#include "../entrada.h"
#include <stdio.h>

static int fallos = 0;

static void comprobar(int condicion, const char *descripcion) {
    if (condicion) {
        printf("OK: %s\n", descripcion);
    } else {
        printf("FALLO: %s\n", descripcion);
        fallos++;
    }
}

int main(void) {
    int entero = 99;
    Edificio edificio = {9, 10, 11};

    comprobar(convertir_entero("  8  ", &entero) == 1 && entero == 8,
              "entero con espacios");
    comprobar(convertir_entero("8x", &entero) == 0 && entero == 8,
              "entero con letras se rechaza y conserva salida");
    comprobar(convertir_entero("", &entero) == 0, "entero vacio");
    comprobar(convertir_entero("999999999999999999999999999", &entero) == 0,
              "entero fuera de rango");

    comprobar(convertir_edificio("0 4.5 7", &edificio) == 1 &&
              edificio.xi == 0 && edificio.xf == 4.5 && edificio.altura == 7,
              "edificio valido con decimal");
    comprobar(convertir_edificio("0 4", &edificio) == 0,
              "edificio incompleto");
    comprobar(convertir_edificio("0 4 7 extra", &edificio) == 0,
              "datos adicionales");
    comprobar(convertir_edificio("0 4x 7", &edificio) == 0,
              "numero seguido de letra");
    comprobar(convertir_edificio("0 4 nan", &edificio) == 0,
              "valor no finito");
    comprobar(convertir_edificio("0 4 1e9999", &edificio) == 0,
              "decimal fuera de rango");
    comprobar(convertir_edificio("2 2 1", &edificio) == 0,
              "extremos iguales");
    comprobar(convertir_edificio("0 4 0", &edificio) == 0,
              "altura cero");
    comprobar(edificio.xi == 0 && edificio.xf == 4.5 && edificio.altura == 7,
              "los errores no alteran el edificio anterior");

    printf("Fallos: %d\n", fallos);
    if (fallos > 0) {
        return 1;
    }
    return 0;
}
