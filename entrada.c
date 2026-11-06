#include "entrada.h"
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * La lectura se hace por lineas. Asi se pueden rechazar letras, datos
 * adicionales y lineas largas sin dejar parte de la entrada para el menu.
 */
int leer_linea(char texto[], size_t capacidad) {
    int caracter;

    if (capacidad == 0 || capacidad > INT_MAX) {
        return 0;
    }

    if (fgets(texto, (int)capacidad, stdin) == NULL) {
        return 0;
    }

    /* Si no cupo la linea completa, se descarta lo que queda. */
    if (strchr(texto, '\n') == NULL && feof(stdin) == 0) {
        caracter = getchar();
        while (caracter != '\n' && caracter != EOF) {
            caracter = getchar();
        }
        texto[0] = '\0';
        return 1;
    }

    /* Quitar el salto de linea, si lo hay. */
    texto[strcspn(texto, "\r\n")] = '\0';
    return 1;
}

int convertir_entero(const char texto[], int *resultado) {
    char *fin;
    long valor;

    /* fin senala donde termino la parte que strtol pudo convertir. */
    errno = 0;
    valor = strtol(texto, &fin, 10);

    if (fin == texto || errno == ERANGE) {
        return 0;
    }
    if (valor < INT_MIN || valor > INT_MAX) {
        return 0;
    }

    /* Despues del entero solo se permiten espacios. */
    while (isspace((unsigned char)*fin)) {
        fin++;
    }
    if (*fin != '\0') {
        return 0;
    }

    *resultado = (int)valor;
    return 1;
}

int convertir_edificio(const char texto[], Edificio *resultado) {
    double valores[3];
    Edificio edificio;
    const char *posicion;
    char *fin;
    int i;

    posicion = texto;

    /* Se necesitan exactamente tres numeros separados por espacios. */
    for (i = 0; i < 3; i++) {
        while (isspace((unsigned char)*posicion)) {
            posicion++;
        }

        errno = 0;
        valores[i] = strtod(posicion, &fin);

        if (fin == posicion || errno == ERANGE) {
            return 0;
        }
        if (*fin != '\0' && isspace((unsigned char)*fin) == 0) {
            return 0;
        }
        posicion = fin;
    }

    while (isspace((unsigned char)*posicion)) {
        posicion++;
    }
    if (*posicion != '\0') {
        return 0;
    }

    edificio.xi = valores[0];
    edificio.xf = valores[1];
    edificio.altura = valores[2];

    if (edificio_valido(edificio) == 0) {
        return 0;
    }

    /* Solo se modifica la salida cuando todos los datos son validos. */
    *resultado = edificio;
    return 1;
}
