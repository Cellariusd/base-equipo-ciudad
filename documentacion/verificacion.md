# Registro de verificación de la base

## Estado inicial

La base se compiló en Windows con GCC/MinGW usando C11, `-Wall -Wextra -Wpedantic -Werror`. El menú se ejecutó y se comprobó que el registro y el guardado provisionales informan «pendiente», sin registrar datos ni afirmar que guardaron. Los módulos de los seis compañeros aún no están implementados.

Se compilaron y ejecutaron las seis pruebas iniciales por módulo. Todas informaron **pendiente**, como corresponde; no son pruebas funcionales aprobadas. También se comprobó desde el menú que `(2,2,1)` se rechaza y que una carga provisional informa pendiente. Las pruebas funcionales y la inspección visual siguen pendientes. Ver `pruebas/casos.md`.

## Revisión de legibilidad y lectura

Se separó la lectura de `main.c` en `entrada.c` y `entrada.h` sin cambiar los contratos de los módulos. Se recompilaron el programa y los ejecutables de pruebas con GCC/MinGW y las mismas advertencias estrictas.

| Comprobación ejecutada | Resultado obtenido |
|---|---|
| `pruebas_entrada.exe` | 13 comprobaciones correctas; 0 fallos. Incluyen enteros y decimales, texto adicional, rangos, no finitos y geometría inválida. |
| Menú: opción inválida, edificio inválido, alta válida, lista vacía, gráficos, guardar y cargar | Rechazos y mensajes de vacío o pendiente como correspondía. |
| Menú: línea de más de 512 caracteres seguida de una opción válida | Línea larga rechazada; la siguiente opción se reconoció. |
| Seis pruebas iniciales de módulos | Todas notificaron pendiente; no son pruebas funcionales aprobadas. |

Los caminos de registro, modificación, eliminación, carga y cálculo **exitosos** aún no se pueden verificar en esta base porque sus implementaciones están pendientes. Los casos del PDF y la revisión visual de gráficos también siguen pendientes.

## Ejemplos individuales para los compañeros

En la versión anterior se compilaron y ejecutaron los seis ejemplos `pruebas/ejemplo_*.c`; todos informaron `PENDIENTE`. Esa comprobación no verifica que los módulos resuelvan sus casos. Posteriormente se cambiaron los contratos gráficos para mostrar vistas en pantalla; los resultados exitosos y la revisión visual de esas vistas siguen pendientes.

## Adaptación a gráficos en pantalla

Se cambiaron los contratos de los compañeros 4 y 5 para que muestren vistas en pantalla y regresen al menú, sin generar archivos SVG: `graficar_edificios(const Ciudad *)` y `graficar_horizonte(const Horizonte *)`. Se agregó `ESTADO_GRAFICO` para fallos detectables de la vista. La biblioteca concreta sigue sin elegirse ni instalarse en esta base.

El programa principal, `pruebas/entrada.c`, `pruebas/modulos.c`, los dos ejemplos gráficos y `pruebas/dobles_menu.c` se compilaron en Windows con GCC 16.2.0 y `-std=c11 -Wall -Wextra -Wpedantic -Werror`, sin advertencias ni errores. Resultados:

| Comprobación ejecutada | Resultado obtenido |
|---|---|
| `pruebas_entrada.exe` | 13 comprobaciones correctas; 0 fallos. |
| Seis pruebas iniciales de módulos | Todas notificaron pendiente; exit 1 esperado. |
| `ejemplo_grafico_edificios.exe` y `ejemplo_grafico_horizonte.exe` | Ambos notificaron pendiente; exit 1 esperado. |
| `pruebas_menu.exe` con `verificar_menu.py` | Correcto: ciudad vacía, orden de las dos vistas, fallo gráfico y descarte de resultados desactualizados. Usa dobles simulados, no dibujos reales. |
| Comentarios y cadenas de `.c`/`.h` | Solo ASCII, compatibles con la codificación de Dev-C++ 5.11. |

**No se abrió ninguna ventana gráfica**: la biblioteca está pendiente y los módulos gráficos siguen sin implementar. La aprobación visual de ejes, escala y figuras, y la compilación con una biblioteca concreta, quedan pendientes. El ejecutable `pruebas_menu.exe` es temporal y está excluido por `.gitignore`.

## Revisión para compartir con el equipo — 7 de noviembre de 2026

**Conclusión:** la base está preparada para repartir las tareas. El programa completo seguirá pendiente hasta implementar e integrar los seis módulos.

Se simplificó el README para empezar por tarea, ejemplo y entrega. Se añadieron pasos de GitHub Desktop, comandos individuales y una guía separada de pruebas del integrador. Se aclaró el formato del horizonte que comparten los módulos y el formato del archivo de datos.

Comprobaciones repetidas en esta revisión con GCC y `-std=c11 -Wall -Wextra -Wpedantic -Werror`:

| Comprobación | Resultado |
|---|---|
| Compilar programa, prueba de entrada, prueba de módulos, menú simulado y seis ejemplos | Diez ejecutables compilados sin advertencias ni errores. |
| Validación de entrada | 13 comprobaciones correctas; 0 fallos. |
| Menú con funciones simuladas | Verificación de `verificar_menu.py` correcta. |
| Menú real de la base | Opción gráfica con ciudad vacía, registro pendiente y salida correctos. |
| Seis ejemplos y seis selecciones de la prueba de módulos | Todos notifican `PENDIENTE` y terminan con código 1, como corresponde a las funciones provisionales. |
| Fuentes `.c` y `.h` | Sin caracteres fuera de ASCII. |
| Archivos registrados en Git | No hay `.exe`, `.o`, `.obj`, `.dll`, `.layout` ni `Makefile.win` registrados. Las salidas locales comprobadas están ignoradas. |

`proto.dev` sí está registrado, pero no lista archivos fuente. Se documentó cómo compilar con GCC o crear un proyecto de consola en C. Esta revisión no verificó la compilación desde la interfaz de un IDE ni una biblioteca gráfica real.

Antes de repartir: asignar los seis responsables y confirmar que todos puedan compilar su ejemplo. Antes de implementar las ventanas: acordar con el profesor la biblioteca y compartir su configuración.

## Tabla para completar durante la integración

### Proyecto de Code::Blocks

Se agregó `base-equipo-ciudad.cbp` con los nueve fuentes del programa y las dos cabeceras, rutas relativas, aplicación de consola, C11 y advertencias estrictas. Las pruebas individuales se mantienen fuera del ejecutable principal.

- Compilación por lotes con Code::Blocks 25.03 y su MinGW/GCC 14.2.0 instalado en esta computadora: **Debug y Release terminaron con código 0**.
- Se ejecutaron ambos binarios generados: opción 6 con ciudad vacía y opción 0 de salida, con mensajes correctos y código 0.
- Se abrió el proyecto en la interfaz y se confirmó el título **Proyecto Ciudad - Equipo**. Para evitar el error al enviar la ruta a otra instancia abierta se usaron `--multiple-instance --no-dde`.
- El botón F9 y el lanzamiento desde la interfaz de GitHub Desktop quedan por comprobar por el usuario. La compilación verificada se hizo con el propio Code::Blocks por línea de comandos; la configuración del editor externo está explicada en [codeblocks.md](codeblocks.md).

### Resultados funcionales pendientes

| ID | Requisito evaluado | Datos | Esperado | Obtenido | Estado |
|---|---|---|---|---|---|
| P01–P13 | Casos mínimos del profesor | Ver `pruebas/casos.md` | Resultados indicados en la matriz | No ejecutados en esta base | Pendiente |
| G01 | Gráficos de edificios y horizonte | Ciudad oficial y otros casos | Ejes, escala y figuras correctas | No generados por módulos pendientes | Pendiente |
| I01 | Integración completa | Menú y seis módulos terminados | Compilación, cálculos, archivos y gráficos correctos | Módulos aún pendientes | Pendiente |

Al integrar, sustituir las filas agrupadas por resultados individuales reales y agregar fecha, datos, evidencia y diferencias/correcciones cuando corresponda. No declarar aprobaciones anticipadas.
