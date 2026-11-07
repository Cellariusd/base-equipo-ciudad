# Tu primera prueba: empieza con datos sencillos

Imagina que te encargaron calcular el área, pero tu compañero todavía no termina el horizonte. ¿Debes esperar? **No.** Puedes preparar unos segmentos de ejemplo y usarlos para probar tu función. Eso es lo que hacen los archivos `ejemplo_*.c` de esta carpeta.

Cada ejemplo tiene un `main` pequeño que prueba un solo módulo. Es una herramienta temporal de práctica: no reemplaza el `main.c` del programa principal. Los ejemplos y sus datos permanecerán en esta carpeta para que el integrador y el resto del equipo puedan volver a ejecutar las comprobaciones.

## Cómo usar un ejemplo

1. Abre el archivo de tu tarea, por ejemplo `medidas.c`, y lee la explicación del comienzo.
2. Abre su ejemplo: en este caso, `pruebas/ejemplo_medidas.c`. Observa cómo se preparan los segmentos, se llama a la función y se comprueba el resultado.
3. Abre la terminal **MSYS2 UCRT64** y entra a la **carpeta principal** del proyecto: es la que contiene `main.c` y los archivos de tus compañeros.
4. Copia el comando de tu módulo de la sección siguiente. Si compila sin errores, ejecuta la segunda línea; por ejemplo, `./ejemplo_medidas.exe`. Si hubo errores, corrígelos antes de ejecutar: podría existir un ejecutable antiguo.
5. Al principio verás `PENDIENTE`: eso es normal porque todavía falta escribir la función. Después de implementarla, guarda tus cambios, **vuelve a compilar** y ejecuta nuevamente.
6. Compara lo obtenido con el resultado esperado. Cuando el primer ejemplo funcione, revisa los demás casos de `casos.md`.

## Comandos por compañero

Usa **solo el bloque que corresponde a tu tarea**, desde la carpeta que contiene `main.c`. Los ejemplos son programas separados: no añadas `main.c` a estos comandos.

### 1. Gestión

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror pruebas/ejemplo_gestion.c gestion.c comun.c -o ejemplo_gestion.exe
./ejemplo_gestion.exe
```

### 2. Horizonte

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror pruebas/ejemplo_horizonte.c horizonte.c -o ejemplo_horizonte.exe
./ejemplo_horizonte.exe
```

### 3. Medidas

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror pruebas/ejemplo_medidas.c medidas.c -o ejemplo_medidas.exe
./ejemplo_medidas.exe
```

### 4. Gráfico de edificios

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror pruebas/ejemplo_grafico_edificios.c grafico_edificios.c -o ejemplo_grafico_edificios.exe
./ejemplo_grafico_edificios.exe
```

### 5. Gráfico del horizonte

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror pruebas/ejemplo_grafico_horizonte.c grafico_horizonte.c -o ejemplo_grafico_horizonte.exe
./ejemplo_grafico_horizonte.exe
```

### 6. Archivos

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror pruebas/ejemplo_archivos.c archivos.c comun.c -o ejemplo_archivos.exe
./ejemplo_archivos.exe
```

**Estos comandos corresponden a la base actual.** Si tu implementación llama a `edificio_valido`, agrega `comun.c` al comando si todavía no está. Si usa `fabs`, incluye `<math.h>`; si tu compilador requiere enlazar la biblioteca matemática, añade `-lm` al final. Los dos comandos gráficos necesitarán las opciones de la biblioteca que apruebe el equipo.

## ¿Dónde se cambian los datos temporales?

Por ejemplo, en `ejemplo_medidas.c` el primer segmento se prepara así:

```c
horizonte.segmentos[0].inicio = 0;
horizonte.segmentos[0].fin = 2;
horizonte.segmentos[0].altura = 2;
```

Eso representa `(0, 2, 2)`. Las líneas siguientes preparan los otros dos tramos. Puedes modificar o agregar casos para practicar; si cambias los datos, **calcula por separado el nuevo resultado esperado y actualiza también la comparación de la prueba**. De lo contrario el ejemplo seguirá comprobando los valores originales. Si agregas segmentos, recuerda actualizar `horizonte.cantidad` sin superar `MAX_SEGMENTOS`.

El ejemplo de horizonte hace algo parecido, pero prepara edificios en una `Ciudad`. Los dos ejemplos gráficos preparan, respectivamente, edificios y segmentos. El de archivos utiliza `pruebas/ejemplo.txt`.

No combines los ejemplos con `main.c` en una misma compilación: cada uno tiene su propio `main`. Los ejecutables locales se ignoran en Git mediante `.gitignore`.

| Módulo | Ejemplo individual | Datos temporales y resultado esperado |
|---|---|---|
| `gestion.c` | `ejemplo_gestion.c` | Registrar `(0,4,3)` y rechazar `(2,2,1)` conservando el anterior. |
| `horizonte.c` | `ejemplo_horizonte.c` | Dos edificios separados: el resultado incluye `(2,4,0)`. |
| `medidas.c` | `ejemplo_medidas.c` | Tres segmentos escritos a mano: área 7, perímetro 16. |
| `grafico_edificios.c` | `ejemplo_grafico_edificios.c` | Dos rectángulos. Revisar visualmente la vista en pantalla. |
| `grafico_horizonte.c` | `ejemplo_grafico_horizonte.c` | Tres segmentos, incluido el hueco. Revisar visualmente la vista en pantalla. |
| `archivos.c` | `ejemplo_archivos.c` | Cargar `ejemplo.txt`, guardar una copia y volver a cargarla. |

La prueba de archivos puede crear o sobrescribir archivos con nombres que empiezan por `pruebas/_salida_`; no guardes allí datos personales. Los ejemplos gráficos ya no piden un archivo de imagen: al implementarlos deberán mostrar una vista y regresar. La biblioteca está pendiente de elección y, una vez seleccionada, hará falta enlazarla para compilar.

En las pruebas gráficas, el código de salida `1` indica función pendiente o error. El código `2` indica que la función regresó pero **falta la revisión visual**: comprobar rectángulos, perfil, huecos, ejes, escala y etiquetas. Es deliberado que la prueba no marque como aprobado un dibujo que no puede inspeccionar por sí sola.

`dobles_menu.c` y `verificar_menu.py` son una prueba aparte del integrador: simulan llamadas para verificar el menú, sin dibujar ni implementar el proyecto. Sus instrucciones están en [pruebas_integrador.md](../documentacion/pruebas_integrador.md).

## ¿Por qué aparece `PENDIENTE`?

Cada función provisional devuelve `ESTADO_PENDIENTE`. El ejemplo muestra ese mensaje y termina con código de error para no confundirlo con una prueba aprobada. Una vez implementada la tarea, vuelve a compilar y ejecutar.

Las líneas como `(void)ciudad;` existen únicamente para indicar que la versión provisional todavía no utiliza el parámetro y así compilar sin advertencias. Al implementar la función, se reemplaza el cuerpo provisional por la lógica real. No cambies el nombre de la función ni sus parámetros sin conversarlo con el integrador: el programa principal y las pruebas los necesitan para conectarse.

## Después del ejemplo individual

Cuando el caso sencillo funcione, agrega casos adicionales y muestra los resultados al integrador. Ejecuten también la prueba de contratos indicada en [pruebas_integrador.md](../documentacion/pruebas_integrador.md). La prueba de gráficos necesita además una revisión visual. Pasar un ejemplo no garantiza que todos los casos estén resueltos.
