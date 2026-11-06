#include "ciudad.h"

/*
 * COMPANERO 2: CALCULAR EL HORIZONTE
 *
 * Tu tarea es averiguar que altura se ve desde fuera en cada parte de la
 * ciudad. No necesitas dibujar: vas a entregar una lista de segmentos.
 *
 * Que recibes? `ciudad` contiene los edificios y ciudad->cantidad indica
 * cuantos hay. No debes cambiar esos edificios. `resultado` es el Horizonte
 * que debes completar: resultado->segmentos guarda cada tramo y
 * resultado->cantidad dice cuantos tramos encontraste.
 *
 * Ejemplo sencillo: edificios (0,2,2) y (4,5,3).
 * De x=0 a x=2 se ve altura 2; de x=2 a x=4 no hay edificios, asi que la
 * altura es 0; de x=4 a x=5 se ve altura 3. Por lo tanto, debes obtener:
 *     (0,2,2), (2,4,0), (4,5,3)
 *
 * Una forma de resolverlo paso a paso:
 * 1. Reune todos los inicios y finales de los edificios y ordenalos.
 * 2. Quita extremos repetidos para no crear intervalos de ancho 0.
 * 3. Entre cada par de extremos consecutivos, busca el edificio mas alto que
 *    cubre ese intervalo. Si no hay ninguno, la altura es 0.
 * 4. Guarda el segmento. Si continua con la misma altura que el anterior,
 *    extiende el anterior en lugar de crear dos tramos redundantes.
 *
 * Ciudad vacia: asigna 0 a resultado->cantidad y devuelve ESTADO_OK. Si la
 * entrada es inconsistente o no hay capacidad, devuelve un error apropiado.
 * Devuelve ESTADO_OK solo si terminaste el calculo. No dependas del orden en
 * que se registraron los edificios.
 *
 * Para probar el ejemplo anterior no necesitas el menu ni gestion.c. Abre
 * pruebas/ejemplo_horizonte.c: alli ya esta construida la ciudad temporal.
 * Desde la carpeta principal, en MSYS2 UCRT64, compila y ejecuta:
 * gcc -std=c11 -Wall -Wextra -Wpedantic -Werror pruebas/ejemplo_horizonte.c horizonte.c -o ejemplo_horizonte.exe
 * ./ejemplo_horizonte.exe
 * Al inicio veras PENDIENTE. Luego prueba superposiciones, edificios ocultos,
 * duplicados y extremos iguales. Mas casos en pruebas/casos.md.
 */
Estado calcular_horizonte(const Ciudad *ciudad, Horizonte *resultado) {
    (void)ciudad; (void)resultado;
    return ESTADO_PENDIENTE;
}
