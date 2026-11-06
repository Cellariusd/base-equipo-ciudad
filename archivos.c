#include "ciudad.h"

/*
 * COMPANERO 6: GUARDAR Y CARGAR CIUDADES
 *
 * Tu tarea es que los edificios no se pierdan al cerrar el programa. Haras
 * dos funciones: una guarda la ciudad actual y otra recupera una ciudad.
 * Ambas reciben `ruta`, que es el nombre del archivo de texto.
 *
 * 1. GUARDAR: recibes la ciudad para consultarla, sin modificarla. Escribe
 *    un edificio por linea con sus tres datos separados por espacios. Por
 *    ejemplo, una linea puede ser: 0 4 7. Usa suficiente precision para
 *    recuperar los valores double; por ejemplo, %.17g en fprintf.
 *    Revisa si se pudo abrir, escribir y cerrar el archivo. Si ya existia,
 *    evita danarlo si la escritura falla: primero escribe un temporal y
 *    protege el anterior con un respaldo. No sobrescribas temporales ni
 *    respaldos que ya existan; coordina con el integrador los errores de
 *    reemplazo y recuperacion, especialmente en Windows.
 *
 * 2. CARGAR: debes reconstruir los edificios que contiene el archivo. Primero
 *    crea una Ciudad temporal y lee alli, una linea completa a la vez. Revisa
 *    que cada linea tenga exactamente tres numeros validos y usa
 *    edificio_valido para la geometria. Comprueba tambien que no supere la
 *    capacidad. Solo cuando TODO se haya leido, validado y cerrado bien,
 *    copia la ciudad temporal a la ciudad recibida. Si hay un error, la
 *    ciudad anterior debe permanecer intacta.
 *
 * Archivo o ciudad vacios: ESTADO_VACIO. Errores de archivo o contenido
 * invalido: ESTADO_ARCHIVO. Devuelve ESTADO_OK solo al terminar bien.
 *
 * Para practicar no necesitas que funcione el menu. Abre
 * pruebas/ejemplo_archivos.c: intenta cargar pruebas/ejemplo.txt, guardar una
 * copia y recuperarla. Desde la carpeta principal en MSYS2 UCRT64:
 * gcc -std=c11 -Wall -Wextra -Wpedantic -Werror pruebas/ejemplo_archivos.c archivos.c comun.c -o ejemplo_archivos.exe
 * ./ejemplo_archivos.exe
 * Por ahora veras PENDIENTE. La prueba puede sobrescribir
 * pruebas/_salida_ejemplo_ciudad.txt; no guardes alli tus datos personales.
 * Despues prueba archivos inexistentes, vacios, incompletos o con letras, y
 * confirma que nunca cambian la ciudad anterior. Hay mas casos en
 * documentacion/funciones.md y pruebas/casos.md.
 */
/* Escribe todos los edificios. La ciudad recibida no debe modificarse. */
Estado guardar_ciudad(const Ciudad *ciudad, const char *ruta) {
    (void)ciudad; (void)ruta;
    return ESTADO_PENDIENTE;
}
/* Solo reemplaza la ciudad cuando la lectura y la validacion terminan bien. */
Estado cargar_ciudad(Ciudad *ciudad, const char *ruta) {
    (void)ciudad; (void)ruta;
    return ESTADO_PENDIENTE;
}
