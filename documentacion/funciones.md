# Fichas y contratos para los seis compañeros

Si es la primera vez que abres tu tarea, empieza por el comentario al inicio de tu archivo `.c`: allí encontrarás una explicación paso a paso y el comando para probar un ejemplo propio. En `pruebas/LEEME.md` se explica cómo ejecutar esos ejemplos y cambiar sus datos. Esta página reúne los acuerdos comunes para que el integrador y el equipo puedan consultarlos.

## Reglas comunes: leer antes de empezar

- El integrador mantiene `ciudad.h`, `comun.c`, `main.c`, `entrada.c`, `entrada.h` y la integración. La firma es el nombre de la función, sus parámetros y el tipo que devuelve: no cambiarla ni cambiar las estructuras sin acordarlo.
- Trabajar en el archivo asignado y usar las estructuras de `ciudad.h`. La ciudad tiene máximo 100 edificios; el horizonte, 199 segmentos.
- `xi >= 0`, `xi < xf`, `altura > 0`, valores finitos y `xf` y altura como máximo 1 000 000. Se permiten decimales con punto, duplicados, superposiciones y extremos compartidos. `edificio_valido()` implementa estas reglas para reutilizarlas.
- Los índices internos son de 0 a `cantidad-1`; el menú presenta números a partir de 1.
- `ESTADO_OK` significa que la operación realmente terminó. Mientras falte implementar, conservar `ESTADO_PENDIENTE`. Usar `ESTADO_INVALIDO` para datos/índices inválidos, `ESTADO_CAPACIDAD` para capacidad insuficiente, `ESTADO_VACIO` para datos vacíos cuando corresponda, `ESTADO_ARCHIVO` para errores de archivos y `ESTADO_GRAFICO` para fallos detectables de la vista.
- Los punteros recibidos del programa están inicializados y no son nulos. Ante errores no debe destruirse la información de entrada ni quedar una ciudad parcialmente modificada. Salidas de cálculo solo son utilizables si se devuelve `ESTADO_OK`.
- Las funciones de cálculo no leen datos de consola; la interacción con el usuario pertenece al menú. El listado es la excepción: su función imprime los edificios.
- Ver [los casos](../pruebas/casos.md), [los ejemplos individuales](../pruebas/LEEME.md) y [las pruebas de contratos](pruebas_integrador.md). Los comandos `pruebas_modulos.exe` de esta página requieren compilar antes el ejecutable como explica esa última guía. Una prueba inicial aprobada no equivale a cumplir todos los casos.

## Compañero 1 — `gestion.c`

**Objetivo:** administrar el arreglo de edificios.

- `registrar_edificio(Ciudad *ciudad, Edificio edificio)`: validar con `edificio_valido`; si es válido y hay espacio, agregar al final y aumentar cantidad. Retornar `ESTADO_CAPACIDAD` si está lleno.
- `modificar_edificio(Ciudad *ciudad, int indice, Edificio edificio)`: comprobar índice y validez antes de cambiar cualquier dato.
- `eliminar_edificio(Ciudad *ciudad, int indice)`: validar índice; desplazar elementos posteriores y disminuir cantidad.
- `listar_edificios(const Ciudad *ciudad)`: imprimir número desde 1, xi, xf y altura; si está vacía, informar.

**Ejemplos:** registrar `(0,4,3)` deja cantidad 1; modificar por `(0,4,0)` debe rechazarse y conservar el original. Probar índices inválidos y capacidad. Ensayo inicial: `./pruebas_modulos.exe gestion`.

## Compañero 2 — `horizonte.c`

**Objetivo:** `calcular_horizonte(const Ciudad *ciudad, Horizonte *resultado)` calcula el perfil con la máxima altura entre cada par de extremos relevantes. No altera los edificios. Ciudad vacía produce cantidad 0 y `ESTADO_OK`. Una ciudad válida no puede superar `MAX_SEGMENTOS`; ante una entrada inconsistente devolver error.

**Estrategia sugerida:** reunir los 2n extremos, ordenarlos, quitar repetidos, revisar cada intervalo entre extremos consecutivos, buscar el máximo de los edificios que lo cubren y unir intervalos contiguos de igual altura. Conservar los espacios vacíos internos como altura 0. No se admiten tramos de ancho cero ni redundantes.

**Formato que debes entregar:** segmentos ordenados de izquierda a derecha, desde el menor `xi` hasta el mayor `xf`. Cada segmento termina donde comienza el siguiente. Los huecos internos tienen altura 0; no agregues huecos antes del primer edificio ni después del último. Dos segmentos vecinos de igual altura deben quedar unidos. Los compañeros de medidas y gráficos reciben este formato.

**Pruebas:** ejemplo oficial, lista vacía, entradas desordenadas, edificios ocultos/idénticos, extremos coincidentes y tres grupos separados. Ensayo inicial: `./pruebas_modulos.exe horizonte`.

## Compañero 3 — `medidas.c`

**Objetivo:** `calcular_medidas(const Horizonte *horizonte, Medidas *resultado)` recibe segmentos correctos y ordenados. Horizonte vacío da área 0, perímetro 0 y `ESTADO_OK`.

Usa el formato del compañero 2: los huecos ya aparecen como segmentos de altura 0. El perímetro incluye la base apoyada en el eje X y excluye los bordes interiores de edificios superpuestos.

**Área:** sumar `(fin - inicio) * altura`.

**Perímetro:** por cada segmento de altura positiva, sumar dos veces su ancho: techo y base. Sumar los valores absolutos de los cambios de altura, comenzando en 0 y terminando en 0. Los segmentos de altura 0 no aportan ancho horizontal al perímetro; sus transiciones separan componentes.

**Pruebas:** `(0,4,3)` produce área 12 y perímetro 14; el horizonte oficial produce 95 y 74. Ensayo inicial: `./pruebas_modulos.exe medidas`. Puede probar sin depender de `horizonte.c`, construyendo segmentos a mano.

## Compañero 4 — `grafico_edificios.c`

**Objetivo:** `graficar_edificios(const Ciudad *ciudad)` muestra una vista con cada edificio como rectángulo, incluso si está superpuesto. Debe identificar la vista e incluir ejes X/Y, marcas, valores legibles y escala proporcional. Ciudad vacía: `ESTADO_VACIO`. No modifica la ciudad y no recibe una ruta de imagen.

La biblioteca gráfica está por decidir con el profesor; `graphics.h` es una opción, no está instalada ni enlazada en esta base. El responsable coordinará con el integrador y el compañero 5 cómo abrir, mostrar y cerrar la vista sin cerrar el programa. Si la biblioteca permite detectar el fallo de apertura o dibujo, devolver `ESTADO_GRAFICO`; después de mostrar y regresar, `ESTADO_OK`. Probar con `pruebas/ejemplo_grafico_edificios.c` y revisar la ventana visualmente. El comando de compilación deberá adaptarse a la biblioteca que se elija.

Antes de programar las ventanas, acuerden tamaño, márgenes, escala por eje, colores y forma de cierre. En cada eje, una misma distancia debe representar siempre la misma cantidad de unidades. Mantengan el mismo criterio entre ambas vistas. El menú mostrará primero edificios y después horizonte; cerrar la primera vista debe permitir continuar a la siguiente.

## Compañero 5 — `grafico_horizonte.c`

**Objetivo:** `graficar_horizonte(const Horizonte *horizonte)` recibe segmentos ya calculados y muestra una vista independiente con cambios verticales, tramos horizontales, espacios vacíos, ejes X/Y, marcas y escala proporcional. Horizonte vacío: `ESTADO_VACIO`; fallo gráfico detectable: `ESTADO_GRAFICO`. Tras mostrar la vista, debe devolver el control al programa. No modifica el horizonte ni recibe una ruta.

No necesita que el compañero 2 haya terminado: `pruebas/ejemplo_grafico_horizonte.c` suministra segmentos preparados a mano. El integrador revisará visualmente la vista, coordinará escalas con el compañero 4 y documentará los resultados. La biblioteca y su configuración aún no están aprobadas ni implementadas en esta base.

## Compañero 6 — `archivos.c`

**Formato:** archivo de texto sin título ni cantidad inicial, un edificio por línea y tres números separados por espacios. Por ejemplo:

```text
0 4 7
4 7 4
```

Empieza por leer un archivo válido en una ciudad temporal y por guardar una ciudad de prueba. Después completa las validaciones y el reemplazo con respaldo descritos abajo. Una ciudad temporal es otra variable `Ciudad`: permite comprobar todo antes de sustituir la ciudad actual. Coordina con el integrador la parte de respaldo si aún no la han estudiado.

- `guardar_ciudad(const Ciudad *ciudad, const char *ruta)`: escribir un edificio por línea, `xi xf altura`, con precisión suficiente para recuperar los `double` (por ejemplo `%.17g`). Retornar `ESTADO_VACIO` para ciudad vacía y `ESTADO_ARCHIVO` en errores. Para preservar un archivo existente si falla la escritura, usar un temporal y respaldo seguros; nunca sobrescribir un temporal/respaldo preexistente. Comprobar escritura y cierre e informar al integrador si la restauración falla.
- `cargar_ciudad(Ciudad *ciudad, const char *ruta)`: leer línea completa, exigir exactamente tres números, aplicar `edificio_valido`, verificar capacidad y errores de lectura/cierre. Construir una `Ciudad` temporal y copiarla a la original solo si todo el archivo es válido. Archivo vacío: `ESTADO_VACIO`. Ante cualquier error, preservar la ciudad anterior.

Probar inexistente, vacío, incompleto, caracteres no numéricos, valores inválidos, líneas demasiado largas y más de 100 registros. Ensayo inicial: `./pruebas_modulos.exe archivos`. El archivo `pruebas/ejemplo.txt` sirve como ejemplo válido. También probar guardar, terminar el programa y recuperar en otra ejecución.

## Integrador: orden y verificación

Revisar cada pull request, compilar con advertencias estrictas y ejecutar la prueba del módulo. Después integrar con `main`, probar cambios y carga, repetir los casos del PDF y registrar resultados reales en `verificacion.md`. Nunca declarar aprobada una prueba que no se ejecutó. Si cambian las firmas o el algoritmo, actualizar esta documentación y avisar al equipo.
