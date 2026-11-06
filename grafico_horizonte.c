#include "ciudad.h"

/*
 * COMPANERO 5: MOSTRAR EL HORIZONTE EN PANTALLA
 *
 * Tu tarea es dibujar el perfil visible de la ciudad en una vista distinta de
 * la de los edificios. No calculas el horizonte: recibes los tramos ya listos.
 *
 * Que recibes? `horizonte` contiene un arreglo de segmentos y su cantidad.
 * Cada tramo tiene inicio, fin y altura. Consultalo sin modificarlo. No se
 * recibe una ruta de archivo: la vista se mostrara directamente en pantalla.
 *
 * Representa los tramos horizontales, las subidas y las bajadas. Incluye los
 * huecos de altura 0, titulo, ejes X e Y, marcas y valores legibles. Mantiene
 * una escala proporcional. Coordina la gestion de la ventana con el otro
 * responsable de graficos y el integrador: el usuario debe poder terminar de
 * verla y regresar al menu, sin cerrar todo el programa.
 *
 * Aun no se ha elegido la biblioteca: graphics.h es una opcion a confirmar
 * con el profesor. Cuando se decida, habra que instalarla y enlazarla al IDE.
 * Horizonte vacio: ESTADO_VACIO; datos invalidos: ESTADO_INVALIDO; fallo
 * detectable de la vista: ESTADO_GRAFICO. Al mostrar y regresar: ESTADO_OK.
 *
 * Para probar sin esperar al algoritmo abre
 * pruebas/ejemplo_grafico_horizonte.c. Sus segmentos temporales son:
 *     (0,2,2), (2,4,0), (4,5,3)
 * El perfil baja al eje X entre x=2 y x=4 y luego vuelve a subir. Mientras
 * esta funcion es provisional, compila desde la carpeta principal:
 * gcc -std=c11 -Wall -Wextra -Wpedantic -Werror pruebas/ejemplo_grafico_horizonte.c grafico_horizonte.c -o ejemplo_grafico_horizonte.exe
 * ./ejemplo_grafico_horizonte.exe
 * Veras PENDIENTE. Al implementar la biblioteca se necesitaran sus opciones
 * de compilacion y enlace. Revisa la vista y consulta pruebas/casos.md.
 */
Estado graficar_horizonte(const Horizonte *horizonte) {
    (void)horizonte;
    return ESTADO_PENDIENTE;
}
