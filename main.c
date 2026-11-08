#include "ciudad.h"
#include "entrada.h"
#include <stdio.h>

/* Estas funciones ayudan al menu; solo se usan en este archivo. */
static void mostrar_menu(void) {
    printf("\n1. Registrar edificio\n");
    printf("2. Modificar edificio\n");
    printf("3. Eliminar edificio\n");
    printf("4. Listar edificios\n");
    printf("5. Mostrar horizonte, area y perimetro\n");
    printf("6. Mostrar graficos\n");
    printf("7. Guardar ciudad\n");
    printf("8. Cargar ciudad\n");
    printf("0. Salir\n");
    printf("> ");
    printf("9");}

static void informar_estado(Estado estado) {
    switch (estado) {
        case ESTADO_OK:
            printf("Operacion completada.\n");
            break;
        case ESTADO_PENDIENTE:
            printf("Funcion pendiente de implementar por el equipo.\n");
            break;
        case ESTADO_INVALIDO:
            printf("Datos o posicion invalidos.\n");
            break;
        case ESTADO_CAPACIDAD:
            printf("Capacidad maxima alcanzada.\n");
            break;
        case ESTADO_VACIO:
            printf("No hay edificios o el archivo esta vacio.\n");
            break;
        case ESTADO_ARCHIVO:
            printf("Error al abrir, leer, escribir o validar el archivo.\n");
            break;
        case ESTADO_GRAFICO:
            printf("No se pudo mostrar el grafico.\n");
            break;
        default:
            printf("Estado desconocido: revisar la implementacion.\n");
            break;
    }
}

/* Recalcula todo despues de cambiar o cargar la ciudad. */
static void actualizar_resultados(const Ciudad *ciudad, Horizonte *horizonte,
                                  Medidas *medidas, int *horizonte_listo,
                                  int *medidas_listas) {
    Estado estado;

    /* No se vuelven a mostrar resultados anteriores si el calculo falla. */
    *horizonte_listo = 0;
    *medidas_listas = 0;
    horizonte->cantidad = 0;
    medidas->area = 0;
    medidas->perimetro = 0;

    estado = calcular_horizonte(ciudad, horizonte);
    if (estado != ESTADO_OK) {
        printf("Horizonte: ");
        informar_estado(estado);
        return;
    }
    *horizonte_listo = 1;

    estado = calcular_medidas(horizonte, medidas);
    if (estado != ESTADO_OK) {
        printf("Medidas: ");
        informar_estado(estado);
        return;
    }
    *medidas_listas = 1;
}

static void mostrar_resultados(const Ciudad *ciudad, const Horizonte *horizonte,
                               const Medidas *medidas, int horizonte_listo,
                               int medidas_listas) {
    int i;
    Segmento segmento;

    if (ciudad->cantidad == 0) {
        printf("No hay edificios registrados.\n");
        return;
    }

    if (horizonte_listo == 0) {
        printf("Horizonte no disponible: calculo pendiente o fallido.\n");
        return;
    }

    printf("Horizonte (inicio, fin, altura):\n");
    for (i = 0; i < horizonte->cantidad; i++) {
        segmento = horizonte->segmentos[i];
        printf("(%.10g, %.10g, %.10g)\n", segmento.inicio,
               segmento.fin, segmento.altura);
    }

    if (medidas_listas == 1) {
        printf("Area = %.10g\n", medidas->area);
        printf("Perimetro = %.10g\n", medidas->perimetro);
    } else {
        printf("Area y perimetro no disponibles: calculo pendiente o fallido.\n");
    }
}

int main(void) {
    Ciudad ciudad = {0};
    Horizonte horizonte = {0};
    Medidas medidas = {0};
    Edificio edificio = {0};

    int horizonte_listo = 0;
    int medidas_listas = 0;
    int opcion;
    int numero;
    char linea[512];
    Estado estado;

    printf("PROYECTO CIUDAD: consulte el estado de los modulos en la documentacion.\n");

    while (1) {
        mostrar_menu();

        if (leer_linea(linea, sizeof linea) == 0) {
            break;
        }
        if (convertir_entero(linea, &opcion) == 0) {
            printf("Opcion invalida.\n");
            continue;
        }
        if (opcion == 0) {
            break;
        }

        if (opcion >= 1 && opcion <= 3) {
            numero = 0;

            /* Para modificar o eliminar se solicita un numero de edificio. */
            if (opcion == 2 || opcion == 3) {
                printf("Numero de edificio (desde 1): ");
                if (leer_linea(linea, sizeof linea) == 0) {
                    break;
                }
                if (convertir_entero(linea, &numero) == 0 ||
                    numero < 1 || numero > ciudad.cantidad) {
                    printf("Numero invalido.\n");
                    continue;
                }
            }

            /* Para registrar o modificar se solicitan los tres datos. */
            if (opcion == 1 || opcion == 2) {
                printf("Ingrese xi xf altura: ");
                if (leer_linea(linea, sizeof linea) == 0) {
                    break;
                }
                if (convertir_edificio(linea, &edificio) == 0) {
                    printf("Datos invalidos: se necesitan tres numeros con ");
                    printf("0 <= xi < xf y altura > 0, hasta 1000000.\n");
                    continue;
                }
            }

            if (opcion == 1) {
                estado = registrar_edificio(&ciudad, edificio);
            } else if (opcion == 2) {
                /* El usuario cuenta desde 1; el arreglo empieza en 0. */
                estado = modificar_edificio(&ciudad, numero - 1, edificio);
            } else {
                estado = eliminar_edificio(&ciudad, numero - 1);
            }

            informar_estado(estado);
            if (estado == ESTADO_OK) {
                printf("Guarde los cambios si desea conservarlos.\n");
                actualizar_resultados(&ciudad, &horizonte, &medidas,
                                      &horizonte_listo, &medidas_listas);
                mostrar_resultados(&ciudad, &horizonte, &medidas,
                                   horizonte_listo, medidas_listas);
            }
        } else if (opcion == 4) {
            if (ciudad.cantidad == 0) {
                printf("No hay edificios registrados.\n");
            } else {
                listar_edificios(&ciudad);
            }
        } else if (opcion == 5) {
            mostrar_resultados(&ciudad, &horizonte, &medidas,
                               horizonte_listo, medidas_listas);
        } else if (opcion == 6) {
            if (ciudad.cantidad == 0) {
                printf("No hay edificios para graficar.\n");
                continue;
            }

            printf("Vista de edificios:\n");
            fflush(stdout);
            estado = graficar_edificios(&ciudad);
            informar_estado(estado);

            if (horizonte_listo == 1) {
                printf("Vista del horizonte:\n");
                fflush(stdout);
                estado = graficar_horizonte(&horizonte);
                informar_estado(estado);
            } else {
                printf("Grafico de horizonte no disponible: calculo pendiente o fallido.\n");
            }
        } else if (opcion == 7 || opcion == 8) {
            printf("Ruta del archivo: ");
            if (leer_linea(linea, sizeof linea) == 0) {
                break;
            }
            if (linea[0] == '\0') {
                printf("Ruta invalida.\n");
                continue;
            }

            if (opcion == 7) {
                estado = guardar_ciudad(&ciudad, linea);
            } else {
                estado = cargar_ciudad(&ciudad, linea);
            }
            informar_estado(estado);

            if (opcion == 8 && estado == ESTADO_OK) {
                actualizar_resultados(&ciudad, &horizonte, &medidas,
                                      &horizonte_listo, &medidas_listas);
                mostrar_resultados(&ciudad, &horizonte, &medidas,
                                   horizonte_listo, medidas_listas);
            }
        } else {
            printf("Opcion invalida.\n");
        }
    }

    printf("Fin. Recuerde guardar sus cambios.\n");
    return 0;
}
