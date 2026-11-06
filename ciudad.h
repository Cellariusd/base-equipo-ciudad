#ifndef CIUDAD_H
#define CIUDAD_H

/* Contrato comun: no cambiar sin coordinar con el integrador. */
#define MAX_EDIFICIOS 100
#define MAX_SEGMENTOS (2 * MAX_EDIFICIOS - 1)
#define LIMITE_COORDENADA 1000000.0

typedef struct {
    double xi;
    double xf;
    double altura;
} Edificio;

typedef struct {
    Edificio edificios[MAX_EDIFICIOS];
    int cantidad;
} Ciudad;

typedef struct {
    double inicio;
    double fin;
    double altura;
} Segmento;

typedef struct {
    Segmento segmentos[MAX_SEGMENTOS];
    int cantidad;
} Horizonte;

typedef struct {
    double area;
    double perimetro;
} Medidas;

/* Las funciones devuelven ESTADO_OK unicamente si completaron su trabajo. */
typedef enum {
    ESTADO_OK = 0,
    ESTADO_PENDIENTE,
    ESTADO_INVALIDO,
    ESTADO_CAPACIDAD,
    ESTADO_VACIO,
    ESTADO_ARCHIVO,
    ESTADO_GRAFICO
} Estado;

/* Funcion comun implementada por el integrador en comun.c. */
int edificio_valido(Edificio edificio);

/* Companero 1: indices internos empiezan en 0. En caso de error no modificar. */
Estado registrar_edificio(Ciudad *ciudad, Edificio edificio);
Estado modificar_edificio(Ciudad *ciudad, int indice, Edificio edificio);
Estado eliminar_edificio(Ciudad *ciudad, int indice);
void listar_edificios(const Ciudad *ciudad);

/* Companero 2: para ciudad vacia, horizonte vacio y ESTADO_OK. */
Estado calcular_horizonte(const Ciudad *ciudad, Horizonte *resultado);

/* Companero 3: para horizonte vacio, ambas medidas son cero y ESTADO_OK. */
Estado calcular_medidas(const Horizonte *horizonte, Medidas *resultado);

/* Companeros 4 y 5: muestran vistas en pantalla y regresan al menu. */
/* Ciudad u horizonte vacio: ESTADO_VACIO; fallo grafico: ESTADO_GRAFICO. */
Estado graficar_edificios(const Ciudad *ciudad);
Estado graficar_horizonte(const Horizonte *horizonte);

/* Companero 6: carga transaccional; archivo vacio es error. */
Estado guardar_ciudad(const Ciudad *ciudad, const char *ruta);
Estado cargar_ciudad(Ciudad *ciudad, const char *ruta);

#endif
