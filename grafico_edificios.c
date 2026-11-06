#include "ciudad.h"

/*
 * COMPANERO 4: MOSTRAR LOS EDIFICIOS EN PANTALLA
 *
 * Tu tarea es mostrar todos los edificios como rectangulos. La otra persona
 * responsable de graficos mostrara el horizonte en una vista independiente.
 *
 * Que recibes? `ciudad` contiene un arreglo y su cantidad. El primer edificio
 * se consulta con ciudad->edificios[0]; sus datos son xi, xf y altura. No debes
 * modificar la ciudad. No recibes una ruta: la vista sera en pantalla.
 *
 * Tu funcion debe dibujar cada edificio, incluso cuando se superponga con
 * otro. Incluye titulo, ejes X e Y, marcas, valores legibles y escala
 * proporcional. Por ejemplo, un ancho 4 debe verse el doble de uno de 2.
 * Coordina la escala y la gestion de ventanas con el companero 5 y el
 * integrador. Espera a que el usuario termine de ver la vista y devuelve el
 * control al menu; cerrar la vista no debe cerrar todo el programa.
 *
 * Una biblioteca como graphics.h es candidata, pero aun debe confirmarla el
 * profesor. No se incluye ni se elige una biblioteca en esta base. Cuando se
 * decida, el equipo debera configurar su instalacion y enlazado en el IDE.
 *
 * Ciudad vacia: devuelve ESTADO_VACIO. Datos invalidos: ESTADO_INVALIDO.
 * Si puedes detectar un fallo al abrir o mostrar la vista: ESTADO_GRAFICO.
 * Devuelve ESTADO_OK solo despues de mostrar la vista y regresar normalmente.
 *
 * Para practicar sin esperar a gestion, abre
 * pruebas/ejemplo_grafico_edificios.c: prepara (0,2,2) y (4,5,3). Mientras
 * esta funcion es provisional, puedes compilarla desde la carpeta principal:
 * gcc -std=c11 -Wall -Wextra -Wpedantic -Werror pruebas/ejemplo_grafico_edificios.c grafico_edificios.c -o ejemplo_grafico_edificios.exe
 * ./ejemplo_grafico_edificios.exe
 * Veras PENDIENTE. Tras elegir una biblioteca, ese comando debera incluir sus
 * opciones de compilacion y enlace. Revisa visualmente la ventana y consulta
 * documentacion/funciones.md y pruebas/casos.md para mas detalles.
 */
Estado graficar_edificios(const Ciudad *ciudad) {
    (void)ciudad;
    return ESTADO_PENDIENTE;
}
