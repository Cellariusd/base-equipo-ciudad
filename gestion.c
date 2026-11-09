#include "ciudad.h"
#include <stdio.h>

/*
 * COMPANERO 1: GESTION DE EDIFICIOS
 *
 * Tu tarea es ayudar a que el programa pueda agregar, cambiar, borrar y
 * mostrar edificios. Trabaja en las cuatro funciones que estan mas abajo.
 *
 * Antes de empezar, imagina esta ciudad:
 *     posicion en el arreglo:  0          1
 *     edificio:                (0,4,3)    (5,8,2)
 *     cantidad:                2
 * El usuario vera los edificios como 1 y 2, pero el arreglo empieza en 0.
 * El menu ya convierte ese numero antes de llamar a tus funciones.
 *
 * Que recibes? `ciudad` te permite acceder al arreglo y a su cantidad.
 * `edificio` contiene xi, xf y altura. En modificacion y eliminacion,
 * `indice` es la posicion dentro del arreglo. Consulta las estructuras en
 * ciudad.h; ciudad->cantidad y ciudad->edificios[0] son ejemplos de acceso.
 *
 * Que debe hacer cada funcion?
 * - Registrar: comprueba edificio_valido(edificio) y que haya espacio. Guarda
 *   el nuevo edificio al final y aumenta la cantidad en uno.
 * - Modificar: comprueba el indice y los nuevos datos ANTES de reemplazar.
 *   Si algo es invalido, el edificio anterior debe quedarse como estaba.
 * - Eliminar: comprueba el indice. Mueve los edificios posteriores hacia la
 *   izquierda y disminuye la cantidad, para no dejar huecos.
 * - Listar: muestra los datos y numera desde 1; si la ciudad esta vacia,
 *   muestra un mensaje. Esta funcion no devuelve Estado.
 *
 * En las tres primeras funciones devuelve ESTADO_OK cuando completes la tarea,
 * ESTADO_INVALIDO si fallan los datos o el indice, o ESTADO_CAPACIDAD si ya
 * no caben mas edificios. No cambies nombres ni parametros sin coordinar.
 * El cuerpo actual es provisional: todavia devuelve ESTADO_PENDIENTE.
 *
 * Para comenzar puedes probar SIN usar el menu ni esperar a tus companeros:
 * abre pruebas/ejemplo_gestion.c. Primero intentara registrar (0,4,3): debe
 * quedar cantidad 1. Despues intentara (2,2,1): debe rechazarse y conservar
 * el primer edificio. En la terminal MSYS2 UCRT64, desde la carpeta principal:
 * gcc -std=c11 -Wall -Wextra -Wpedantic -Werror pruebas/ejemplo_gestion.c gestion.c comun.c -o ejemplo_gestion.exe
 * ./ejemplo_gestion.exe
 * Mientras no implementes la funcion veras PENDIENTE. Despues de ese primer
 * caso, prueba tambien modificar, eliminar, listar y el limite de capacidad.
 * Mas detalles: documentacion/funciones.md y pruebas/casos.md.
 */
/* Recibe la ciudad a modificar y los datos del edificio nuevo. */
Estado registrar_edificio(Ciudad *ciudad, Edificio edificio) {
    (void)ciudad; (void)edificio;
    return ESTADO_PENDIENTE;
    printf  ("67")
}
/* Sustituye los datos de la posicion indicada solo si todo es valido. */
Estado modificar_edificio(Ciudad *ciudad, int indice, Edificio edificio) {
    (void)ciudad; (void)indice; (void)edificio;
    return ESTADO_PENDIENTE;
}
/* El indice comienza en 0; despues de eliminar no debe quedar un hueco. */
Estado eliminar_edificio(Ciudad *ciudad, int indice) {
    (void)ciudad; (void)indice;
    return ESTADO_PENDIENTE;
}
/* Solo muestra los edificios; const indica que no debe modificarlos. */
void listar_edificios(const Ciudad *ciudad) {
    (void)ciudad;
    puts("Listado pendiente de implementar.");
}
