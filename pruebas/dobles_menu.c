/*
 * Funciones simuladas SOLO para probar que el menu conecta los modulos.
 * No forman parte de la aplicacion ni reemplazan el trabajo del equipo.
 * No dibujan ventanas y no calculan el horizonte general.
 */
#include "../ciudad.h"
#include <stdio.h>

Estado registrar_edificio(Ciudad *ciudad, Edificio edificio) {
    if (!edificio_valido(edificio)) return ESTADO_INVALIDO;
    if (ciudad->cantidad >= MAX_EDIFICIOS) return ESTADO_CAPACIDAD;
    ciudad->edificios[ciudad->cantidad++] = edificio;
    return ESTADO_OK;
}
Estado modificar_edificio(Ciudad *ciudad, int indice, Edificio edificio) {
    if (indice < 0 || indice >= ciudad->cantidad || !edificio_valido(edificio)) return ESTADO_INVALIDO;
    ciudad->edificios[indice] = edificio;
    return ESTADO_OK;
}
Estado eliminar_edificio(Ciudad *ciudad, int indice) {
    int i;
    if (indice < 0 || indice >= ciudad->cantidad) return ESTADO_INVALIDO;
    for (i = indice; i + 1 < ciudad->cantidad; i++) ciudad->edificios[i] = ciudad->edificios[i + 1];
    ciudad->cantidad--;
    return ESTADO_OK;
}
void listar_edificios(const Ciudad *ciudad) {
    printf("DOBLE DE PRUEBA: %d edificios.\n", ciudad->cantidad);
}
Estado calcular_horizonte(const Ciudad *ciudad, Horizonte *horizonte) {
    Edificio edificio;
    horizonte->cantidad = 0;
    if (ciudad->cantidad == 0) return ESTADO_OK;
    edificio = ciudad->edificios[0];
    /* El 9 provoca un fallo controlado para probar resultados desactualizados. */
    if (edificio.altura == 9) return ESTADO_INVALIDO;
    horizonte->segmentos[0].inicio = edificio.xi;
    horizonte->segmentos[0].fin = edificio.xf;
    horizonte->segmentos[0].altura = edificio.altura;
    horizonte->cantidad = 1;
    return ESTADO_OK;
}
Estado calcular_medidas(const Horizonte *horizonte, Medidas *medidas) {
    medidas->area = 0;
    medidas->perimetro = 0;
    if (horizonte->cantidad > 0) {
        Segmento s = horizonte->segmentos[0];
        medidas->area = (s.fin - s.inicio) * s.altura;
        medidas->perimetro = 2 * ((s.fin - s.inicio) + s.altura);
    }
    return ESTADO_OK;
}
Estado graficar_edificios(const Ciudad *ciudad) {
    if (ciudad->cantidad == 0) return ESTADO_VACIO;
    /* El 8 permite probar el mensaje de fallo grafico. */
    if (ciudad->edificios[0].altura == 8) return ESTADO_GRAFICO;
    printf("DOBLE DE PRUEBA: vista de edificios.\n");
    return ESTADO_OK;
}
Estado graficar_horizonte(const Horizonte *horizonte) {
    if (horizonte->cantidad == 0) return ESTADO_VACIO;
    printf("DOBLE DE PRUEBA: vista de horizonte.\n");
    return ESTADO_OK;
}
Estado guardar_ciudad(const Ciudad *ciudad, const char *ruta) {
    (void)ciudad;
    (void)ruta;
    return ESTADO_PENDIENTE;
}
Estado cargar_ciudad(Ciudad *ciudad, const char *ruta) {
    (void)ciudad;
    (void)ruta;
    return ESTADO_PENDIENTE;
}
