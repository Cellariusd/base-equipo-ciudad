/* Pruebas iniciales independientes: se ejecutan por modulo desde la raiz. */
#include "../ciudad.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

static int fallos;
static int revision_visual_pendiente;
static void comprobar(int condicion, const char *mensaje) {
    if (!condicion) { printf("FALLO: %s\n", mensaje); fallos++; }
    else printf("OK: %s\n", mensaje);
}
static int listo(Estado estado, const char *modulo) {
    if (estado == ESTADO_PENDIENTE) {
        printf("PENDIENTE: %s aun no esta implementado.\n", modulo);
        fallos++; return 0;
    }
    comprobar(estado == ESTADO_OK, modulo);
    return estado == ESTADO_OK;
}
static int igual(double a, double b) { return fabs(a - b) < 1e-8; }
static Ciudad ejemplo(void) {
    Ciudad c = {{{0,4,7},{4,7,4},{7,12,5},{8,17,2},{19,21,10}},5};
    return c;
}
static Horizonte horizonte_ejemplo(void) {
    Horizonte h = {{{0,4,7},{4,7,4},{7,12,5},{12,17,2},{17,19,0},{19,21,10}},6};
    return h;
}
static void prueba_gestion(void) {
    Ciudad c = {0}; Estado e = registrar_edificio(&c, (Edificio){0,4,3});
    if (!listo(e, "registro")) return;
    comprobar(c.cantidad == 1 && igual(c.edificios[0].altura, 3), "registro conserva datos");
    comprobar(registrar_edificio(&c, (Edificio){2,2,1}) == ESTADO_INVALIDO && c.cantidad == 1, "rechazar xi igual a xf");
    comprobar(modificar_edificio(&c, 0, (Edificio){0,4,5}) == ESTADO_OK && igual(c.edificios[0].altura, 5), "modificar edificio");
    comprobar(modificar_edificio(&c, 0, (Edificio){0,4,0}) == ESTADO_INVALIDO && igual(c.edificios[0].altura, 5), "modificacion invalida conserva datos");
    comprobar(eliminar_edificio(&c, 0) == ESTADO_OK && c.cantidad == 0, "eliminar edificio");
}
static void prueba_horizonte(void) {
    Ciudad c = ejemplo(); Horizonte obtenido = {0}, esperado = horizonte_ejemplo(); int i;
    if (!listo(calcular_horizonte(&c, &obtenido), "horizonte")) return;
    comprobar(obtenido.cantidad == esperado.cantidad, "cantidad de segmentos oficial");
    if (obtenido.cantidad != esperado.cantidad) return;
    for (i = 0; i < esperado.cantidad; i++)
        comprobar(igual(obtenido.segmentos[i].inicio, esperado.segmentos[i].inicio) && igual(obtenido.segmentos[i].fin, esperado.segmentos[i].fin) && igual(obtenido.segmentos[i].altura, esperado.segmentos[i].altura), "segmento oficial");
    c = (Ciudad){0}; obtenido = esperado;
    comprobar(calcular_horizonte(&c, &obtenido) == ESTADO_OK && obtenido.cantidad == 0, "horizonte vacio");
}
static void prueba_medidas(void) {
    Horizonte h = horizonte_ejemplo(); Medidas m = {0};
    if (!listo(calcular_medidas(&h, &m), "medidas")) return;
    comprobar(igual(m.area, 95), "area oficial 95");
    comprobar(igual(m.perimetro, 74), "perimetro oficial 74");
    h = (Horizonte){0}; m = (Medidas){99,99};
    comprobar(calcular_medidas(&h, &m) == ESTADO_OK && igual(m.area, 0) && igual(m.perimetro, 0), "medidas vacias");
}
static void prueba_grafico(int perfil) {
    Ciudad c = ejemplo(); Horizonte h = horizonte_ejemplo();
    Estado e;
    if (perfil) e = graficar_horizonte(&h);
    else e = graficar_edificios(&c);
    if (e == ESTADO_PENDIENTE) {
        puts("PENDIENTE: el grafico aun no esta implementado.");
        fallos++;
        return;
    }
    if (e != ESTADO_OK) {
        puts("FALLO: la funcion no pudo mostrar el grafico.");
        fallos++;
        return;
    }
    revision_visual_pendiente = 1;
    puts("La funcion regreso. REVISION VISUAL PENDIENTE: comprobar figuras, ejes, escala y etiquetas.");
}
static void prueba_archivos(void) {
    Ciudad c = ejemplo(), leida = {0}, antes; Estado e;
    const char *ruta = "pruebas/_salida_ciudad.txt";
    e = guardar_ciudad(&c, ruta);
    if (!listo(e, "guardar")) return;
    e = cargar_ciudad(&leida, ruta);
    if (!listo(e, "cargar")) return;
    comprobar(leida.cantidad == c.cantidad && igual(leida.edificios[0].altura, 7) && igual(leida.edificios[4].xf, 21), "recuperar datos guardados");
    antes = leida;
    comprobar(cargar_ciudad(&leida, "pruebas/_archivo_inexistente_987.txt") == ESTADO_ARCHIVO && leida.cantidad == antes.cantidad && igual(leida.edificios[0].altura, antes.edificios[0].altura), "fallo de carga conserva datos");
}
int main(int argc, char **argv) {
    if (argc != 2) { puts("Uso: pruebas_modulos.exe gestion|horizonte|medidas|grafico_edificios|grafico_horizonte|archivos"); return 2; }
    if (!strcmp(argv[1], "gestion")) prueba_gestion();
    else if (!strcmp(argv[1], "horizonte")) prueba_horizonte();
    else if (!strcmp(argv[1], "medidas")) prueba_medidas();
    else if (!strcmp(argv[1], "grafico_edificios")) prueba_grafico(0);
    else if (!strcmp(argv[1], "grafico_horizonte")) prueba_grafico(1);
    else if (!strcmp(argv[1], "archivos")) prueba_archivos();
    else { puts("Modulo desconocido."); return 2; }
    printf("Fallos o funciones pendientes: %d\n", fallos);
    if (fallos) return 1;
    if (revision_visual_pendiente) return 2;
    return 0;
}
