# Proyecto Ciudad — base del equipo

Programa en C para registrar edificios, calcular el horizonte visible, obtener el área y el perímetro de su unión, mostrar gráficos y guardar los datos.

**Esta es la base para empezar el trabajo en equipo.** El menú y la validación de entrada están preparados. Los seis módulos de la tabla aún deben implementarse: por eso aparece `PENDIENTE` al probarlos.

## 1. Encuentra tu tarea

El integrador debe indicar quién asume cada número antes de repartir el trabajo.

| Responsable | Archivo que debes completar | Qué debes lograr | Tu ejemplo para probar |
|---|---|---|---|
| Compañero 1 | `gestion.c` | Registrar, modificar, eliminar y listar edificios | `pruebas/ejemplo_gestion.c` |
| Compañero 2 | `horizonte.c` | Convertir los edificios en tramos del horizonte visible | `pruebas/ejemplo_horizonte.c` |
| Compañero 3 | `medidas.c` | Calcular área y perímetro a partir del horizonte | `pruebas/ejemplo_medidas.c` |
| Compañero 4 | `grafico_edificios.c` | Mostrar los edificios como rectángulos en pantalla | `pruebas/ejemplo_grafico_edificios.c` |
| Compañero 5 | `grafico_horizonte.c` | Mostrar el perfil del horizonte en pantalla | `pruebas/ejemplo_grafico_horizonte.c` |
| Compañero 6 | `archivos.c` | Guardar y cargar los edificios en un archivo de texto | `pruebas/ejemplo_archivos.c` |

El **integrador** mantiene `main.c`, `entrada.c`, `entrada.h`, `ciudad.h`, `comun.c` y coordina las pruebas y la unión del trabajo.

## 2. Empieza por aquí

1. **Clona el repositorio y crea tu rama** siguiendo [la guía de GitHub Desktop](documentacion/github_desktop.md). Una rama es tu espacio de trabajo dentro del repositorio.
2. **Abre tu archivo `.c`** y lee el comentario inicial: explica qué recibes, qué debes hacer y cómo probarlo.
3. Consulta **tu sección** en [funciones.md](documentacion/funciones.md). Allí están los acuerdos que tu función debe respetar.
4. **Compila y ejecuta tu ejemplo** con [estos comandos](pruebas/LEEME.md#comandos-por-compañero). Al principio debe indicar `PENDIENTE`.
5. Completa tu función, guarda, vuelve a compilar y prueba. El ejemplo trae datos preparados: **puedes avanzar sin esperar a los otros módulos**.
6. Prueba más casos y envía tus cambios siguiendo el apartado «Qué entregar» de abajo.

Si necesitas repasar estructuras, `const`, punteros o `->`, consulta [la guía para entender el código](documentacion/guia_base.md).

### Reglas para que las partes encajen

- Conserva los nombres, parámetros y tipos de las funciones de `ciudad.h`. Acuerda cualquier cambio con el integrador.
- Escribe la solución en tu módulo. El archivo `ejemplo_*.c` sirve para probar; no reemplaza el menú.
- Las funciones reciben sus datos por parámetros. No agregues otro menú ni pidas datos con `scanf` dentro de ellas. El listado imprime datos y las vistas gráficas permiten terminar de ver el dibujo.
- Devuelve `ESTADO_OK` solo cuando la operación esté realizada. Reemplaza el cuerpo provisional, incluyendo los `(void)` que ya no necesites.
- Los datos usan decimales con punto: `2.5`, no `2,5`. En `.c` y `.h`, mantén comentarios y mensajes sin tildes ni ñ para facilitar el uso de Dev-C++ 5.11.

## 3. Compilar el programa completo

Necesitas un compilador de C con soporte C11. Los comandos se verificaron con **GCC en MSYS2 UCRT64 para Windows**. GitHub Desktop descarga y comparte archivos; el código se compila aparte.

En la terminal **MSYS2 UCRT64**, escribe `cd `, arrastra la carpeta clonada a la terminal y pulsa Enter. Debes quedar en la carpeta que contiene este `README.md` y `main.c`. Usa `pwd` para ver dónde estás y `gcc --version` para comprobar el compilador.

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror main.c entrada.c comun.c gestion.c horizonte.c medidas.c grafico_edificios.c grafico_horizonte.c archivos.c -o ciudad.exe
./ciudad.exe
```

**Ejecuta la segunda línea solo si la compilación termina sin errores.** Si falla, un `.exe` anterior podría seguir en la carpeta y mostrar resultados antiguos. Si `gcc` no se reconoce, pide al integrador ayuda con la instalación antes de continuar.

Por ahora el menú informa que las operaciones están pendientes. Cuando se implementen gestión y cálculos, cada cambio actualizará horizonte y medidas. Para conservar una ciudad se usará la opción de guardar.

**Si trabajas con un IDE:** crea un proyecto de consola en **C**, activa C11 y agrega los diez archivos `.c` del comando anterior. Los `.h` son cabeceras compartidas. `proto.dev` es un proyecto local de Dev-C++ que actualmente no lista archivos fuente; no está preparado como punto de entrada del equipo. No agregues todos los `.c` de `pruebas/` al programa: varios tienen su propio `main` y otros simulan funciones.

## 4. Acuerdo sobre los gráficos

Se mostrarán dos vistas sucesivas: primero edificios; al terminar esa vista, horizonte si está disponible. Cada función debe devolver el control al programa. No se generarán archivos SVG.

**La biblioteca todavía necesita confirmación del profesor.** `graphics.h` es una candidata. El integrador y los compañeros 4 y 5 deben acordar biblioteca, versión, instalación, escala y cierre de las ventanas antes de incorporarla. Mientras tanto pueden preparar los datos de prueba, los ejes y el diseño del dibujo.

La base actual compila sin biblioteca gráfica. Cuando se incorpore una, el integrador actualizará los comandos y las instrucciones de instalación para todos.

## 5. Qué entregar

- Tu módulo implementado y los ejemplos o casos que hayas añadido.
- El comando que usaste para compilar.
- Para cada caso probado: datos, resultado esperado y resultado obtenido. Empieza por tu ejemplo y continúa con los casos aplicables de [la matriz de pruebas](pruebas/casos.md).
- Si haces gráficos: captura de la vista, revisión de figuras/ejes/escala y comprobación de que regresa al programa.
- Una **pull request** (solicitud para integrar tu rama) con un resumen de los cambios y de lo que aún falte. El integrador la revisa y une a `main`.

Los ejecutables, objetos y archivos temporales están excluidos mediante `.gitignore`. Comparte el código fuente y las pruebas que permitan volver a compilarlo.

## Documentación de consulta

| Necesito… | Consulto… |
|---|---|
| Clonar, crear una rama y entregar | [GitHub Desktop](documentacion/github_desktop.md) |
| Saber qué recibe y devuelve mi función | [Fichas de los módulos](documentacion/funciones.md) |
| Entender estructuras y punteros | [Guía del código](documentacion/guia_base.md) |
| Compilar mi ejemplo | [Pruebas individuales](pruebas/LEEME.md) |
| Buscar casos adicionales | [Matriz de pruebas](pruebas/casos.md) |
| Ejecutar controles del integrador | [Pruebas de integración](documentacion/pruebas_integrador.md) |
| Ver qué se comprobó realmente | [Registro de verificación](documentacion/verificacion.md) |
