# Ciudad: base de trabajo del equipo

Esta es una **base educativa incompleta**, no la solución terminada. El menú, los tipos compartidos y la validación geométrica común ya existen. Los seis módulos de los compañeros contienen funciones provisionales que devuelven `ESTADO_PENDIENTE`; no se debe interpretar que funcionan solo porque compilan. El listado también está pendiente y lo indica al llamarse.

Los comentarios de los archivos `.c` y `.h` se escribieron sin tildes ni ñ para que también se lean en Dev-C++ 5.11 con su configuración predeterminada. La documentación `.md` conserva el español con tildes. Si ya tenías un archivo abierto en Dev-C++, cierra y vuelve a abrirlo para ver la versión actual; si hiciste cambios sin guardar, revísalos antes de cerrar para no perderlos ni sobrescribir la versión nueva.

## Responsabilidades

| Responsable | Archivo principal | Funciones |
|---|---|---|
| Integrador | `main.c`, `entrada.c`, `entrada.h`, `ciudad.h`, `comun.c`, documentación y pruebas | Contratos, menú, lectura, validación común e integración |
| Compañero 1 | `gestion.c` | Registrar, modificar, eliminar y listar |
| Compañero 2 | `horizonte.c` | Horizonte visible |
| Compañero 3 | `medidas.c` | Área y perímetro de la unión |
| Compañero 4 | `grafico_edificios.c` | Mostrar los rectángulos en pantalla |
| Compañero 5 | `grafico_horizonte.c` | Mostrar el horizonte en pantalla |
| Compañero 6 | `archivos.c` | Guardar y cargar ciudades |

Leer primero `documentacion/guia_base.md` para entender el menú, estructuras y punteros; después consultar `documentacion/funciones.md` para los contratos y tareas. Los archivos `entrada.c` y `entrada.h` separan la lectura y validación textual del menú. Ningún compañero debe cambiar los archivos del integrador sin coordinarlo.

## Decisión gráfica pendiente

El objetivo es mostrar **dos vistas independientes en pantalla**, sin generar archivos de imagen. `graphics.h` es una opción, pero la biblioteca y su versión todavía deben confirmarse con el profesor. La base **no instala ni incluye ninguna biblioteca gráfica**, y las dos funciones gráficas siguen pendientes. El programa de ejemplo con SDL_bgi se encuentra en otra carpeta de tu computadora; no forma parte de este repositorio y, si este se clona, tampoco estará disponible automáticamente.

Las funciones gráficas ahora reciben solo los datos que mostrarán: `graficar_edificios(&ciudad)` y `graficar_horizonte(&horizonte)`. El ejemplo anterior conservaba un parámetro `ruta` por compatibilidad con SVG: **no copies sus módulos tal cual**, pues sus firmas son diferentes. Al escoger una biblioteca, el integrador deberá acordar cómo configurar Code::Blocks, enlazarla y compartir las dependencias, además de coordinar la apertura y cierre de las ventanas con los compañeros 4 y 5.

## Compilar en Windows con GCC/MinGW

Abrir la terminal **MSYS2 UCRT64**, entrar en esta carpeta y ejecutar:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror main.c entrada.c comun.c gestion.c horizonte.c medidas.c grafico_edificios.c grafico_horizonte.c archivos.c -o ciudad.exe
./ciudad.exe
```

La entrada del menú usa decimales con punto. El programa informa que las funciones están pendientes. Si una función de gestión o carga llega a tener éxito, `main` vuelve a calcular el horizonte y las medidas; si estos cálculos fallan o siguen pendientes, no utiliza resultados anteriores. Después de cualquier cambio se debe guardar la ciudad para conservarla.

## Pruebas iniciales por módulo

Además, cada compañero tiene un ejemplo **individual y sencillo**, con datos preparados a mano, en `pruebas/ejemplo_*.c`. Los pasos para compilar su ejemplo aparecen al principio de su archivo de trabajo y en `pruebas/LEEME.md`. Por ejemplo, el compañero de medidas puede probar con un horizonte temporal sin esperar a que termine `horizonte.c`. Mientras el módulo esté pendiente, su ejemplo informa `PENDIENTE` y termina con error; eso es lo esperado para esta base.

Para comprobar por separado la conversión y validación de entradas del menú:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror pruebas/entrada.c entrada.c comun.c -o pruebas_entrada.exe
./pruebas_entrada.exe
```

Compilar este ejecutable separado desde la raíz del repositorio:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror pruebas/modulos.c comun.c gestion.c horizonte.c medidas.c grafico_edificios.c grafico_horizonte.c archivos.c -o pruebas_modulos.exe
```

Cada compañero puede probar su módulo sin esperar la implementación de los otros:

```bash
./pruebas_modulos.exe gestion
./pruebas_modulos.exe horizonte
./pruebas_modulos.exe medidas
./pruebas_modulos.exe grafico_edificios
./pruebas_modulos.exe grafico_horizonte
./pruebas_modulos.exe archivos
```

Las pruebas devuelven código `1` mientras la función esté pendiente o si falla. Los ensayos gráficos devuelven `2` cuando la función regresa correctamente, porque la **revisión visual sigue pendiente**: nadie debe interpretar ese resultado como una aprobación del dibujo. Estas pruebas son un punto de partida, no cubren todo el PDF; ver `pruebas/casos.md`. Cuando se implemente una biblioteca gráfica, los comandos de compilación deberán incluir sus dependencias.

### Probar solo la conexión del menú

El siguiente ensayo usa **funciones simuladas**, no las implementaciones de los compañeros y no abre ventanas. Comprueba el orden de las llamadas, los mensajes ante fallos y que no se reutilicen resultados antiguos:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror main.c entrada.c comun.c pruebas/dobles_menu.c -o pruebas_menu.exe
python pruebas/verificar_menu.py
```

Python 3 se necesita solo para ejecutar esta verificación automatizada. No se deben compilar `pruebas/dobles_menu.c` junto con los módulos reales: contiene funciones con los mismos nombres exclusivamente para la prueba.

Para probar manualmente la ciudad oficial en el menú, cuando la carga esté implementada, elegir `8` y escribir `pruebas/ejemplo.txt`.

## Trabajo con GitHub Desktop

1. El integrador crea y publica el repositorio después de revisar esta base e invita a los compañeros.
2. Cada compañero clona el repositorio, actualiza `main` y crea una rama propia.
3. Trabaja principalmente en su archivo, consulta su ficha y ejecuta sus pruebas.
4. Hace commit, sube la rama y crea una pull request hacia `main`.
5. El integrador revisa contratos, compila y prueba; luego une una contribución a la vez.
6. Para continuar, cada integrante actualiza su copia con los cambios integrados.

Antes de publicar, revisa en GitHub Desktop qué archivos vas a incluir. `.gitignore` excluye ejecutables, objetos, archivos de sesión de IDE y salidas temporales; no elimina archivos que ya tienes. Si deseas conservar `proto.dev`, el proyecto local que creaste con Dev-C++, decide si quieres incluirlo o mantenerlo solo en tu computadora. Code::Blocks y `graphics.h` aún no están configurados para este proyecto de equipo. No se ha publicado nada automáticamente.
