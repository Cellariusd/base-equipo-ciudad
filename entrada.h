#ifndef ENTRADA_H
#define ENTRADA_H

#include <stddef.h>
#include "ciudad.h"

/* Devuelve 0 al terminar la entrada; si la linea es muy larga, la deja vacia. */
int leer_linea(char texto[], size_t capacidad);

/* Devuelven 1 si la conversion es valida y 0 si debe rechazarse. */
int convertir_entero(const char texto[], int *resultado);
int convertir_edificio(const char texto[], Edificio *resultado);

#endif
