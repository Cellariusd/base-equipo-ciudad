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

El programa principal, `pruebas_entrada.c`, `pruebas/modulos.c`, los dos ejemplos gráficos y `pruebas/dobles_menu.c` se compilaron en Windows con GCC 16.2.0 y `-std=c11 -Wall -Wextra -Wpedantic -Werror`, sin advertencias ni errores. Resultados:

| Comprobación ejecutada | Resultado obtenido |
|---|---|
| `pruebas_entrada.exe` | 13 comprobaciones correctas; 0 fallos. |
| Seis pruebas iniciales de módulos | Todas notificaron pendiente; exit 1 esperado. |
| `ejemplo_grafico_edificios.exe` y `ejemplo_grafico_horizonte.exe` | Ambos notificaron pendiente; exit 1 esperado. |
| `pruebas_menu.exe` con `verificar_menu.py` | Correcto: ciudad vacía, orden de las dos vistas, fallo gráfico y descarte de resultados desactualizados. Usa dobles simulados, no dibujos reales. |
| Comentarios y cadenas de `.c`/`.h` | Solo ASCII, compatibles con la codificación de Dev-C++ 5.11. |

**No se abrió ninguna ventana gráfica**: la biblioteca está pendiente y los módulos gráficos siguen sin implementar. La aprobación visual de ejes, escala y figuras, y la compilación con una biblioteca concreta, quedan pendientes. El ejecutable `pruebas_menu.exe` es temporal y está excluido por `.gitignore`.

## Tabla para completar durante la integración

| ID | Requisito evaluado | Datos | Esperado | Obtenido | Estado |
|---|---|---|---|---|---|
| P01–P13 | Casos mínimos del profesor | Ver `pruebas/casos.md` | Resultados indicados en la matriz | No ejecutados en esta base | Pendiente |
| G01 | Gráficos de edificios y horizonte | Ciudad oficial y otros casos | Ejes, escala y figuras correctas | No generados por módulos pendientes | Pendiente |
| I01 | Integración completa | Menú y seis módulos terminados | Compilación, cálculos, archivos y gráficos correctos | Módulos aún pendientes | Pendiente |

Al integrar, sustituir las filas agrupadas por resultados individuales reales y agregar fecha, datos, evidencia y diferencias/correcciones cuando corresponda. No declarar aprobaciones anticipadas.
