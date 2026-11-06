#include "ciudad.h"
#include <math.h>

/* Validacion comun utilizada tanto por gestion como por carga de archivos. */
int edificio_valido(Edificio edificio) {
    /* isfinite rechaza valores especiales como infinito y NaN. */
    if (isfinite(edificio.xi) == 0 || isfinite(edificio.xf) == 0 ||
        isfinite(edificio.altura) == 0) {
        return 0;
    }

    if (edificio.xi < 0 || edificio.xi >= edificio.xf) {
        return 0;
    }

    if (edificio.altura <= 0) {
        return 0;
    }

    if (edificio.xf > LIMITE_COORDENADA ||
        edificio.altura > LIMITE_COORDENADA) {
        return 0;
    }

    return 1;
}
