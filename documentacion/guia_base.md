# Guía para leer la base del proyecto

Esta guía acompaña el aprendizaje del equipo. No es necesario entender todo el código de una vez: comienza por el menú y avanza hacia estructuras, punteros y validación. La base compila, pero los seis módulos de los compañeros siguen pendientes.

## 1. Por dónde empezar

1. Abre `ciudad.h`: contiene las estructuras y los nombres de las funciones compartidas.
2. Abre `main.c` y busca `int main(void)`: allí se crean las variables de la ciudad y se repite el menú.
3. Lee en `main.c` qué pasa cuando se elige una opción. El menú llama a funciones que están en los demás archivos.
4. Mira `documentacion/funciones.md` para conocer la tarea de cada compañero.
5. Cuando estudies validación de cadenas, revisa `entrada.c` y `comun.c`.

`entrada.h` declara las funciones de lectura, y `entrada.c` las implementa. Están separadas para que el menú sea más fácil de seguir. Los seis archivos de tus compañeros no necesitan implementar nuevamente esas funciones.

## 2. Estructuras

Una estructura agrupa datos relacionados. Una versión abreviada de `Edificio` es:

```c
typedef struct {
    double xi;
    double xf;
    double altura;
} Edificio;
```

Se puede crear un edificio y asignar sus datos con el punto:

```c
Edificio edificio;
edificio.xi = 0;
edificio.xf = 4;
edificio.altura = 7;
```

`Ciudad` contiene un arreglo de edificios y una variable `cantidad`. `Horizonte` contiene segmentos y su cantidad; `Medidas` reúne el área y el perímetro. En `main.c`, `Ciudad ciudad = {0};` inicializa sus campos en cero: al comenzar hay cero edificios.

## 3. Direcciones, punteros y flechas

En el menú encontrarás:

```c
estado = registrar_edificio(&ciudad, edificio);
```

`&ciudad` envía la dirección de la ciudad. La función la recibe como `Ciudad *ciudad` y puede modificar la ciudad original. El edificio se pasa por valor: la función recibe una copia de sus datos.

Dentro de una función, si `ciudad` es un puntero a una estructura, `ciudad->cantidad` accede a su campo `cantidad`. Si `ciudad` es la estructura directamente, se usa `ciudad.cantidad`. La expresión `ciudad->cantidad` equivale a `(*ciudad).cantidad`.

Una función que solo consulta puede recibir `const Ciudad *ciudad`; `const` impide modificar los datos de la ciudad mediante ese puntero. Para modificarla se usa `Ciudad *ciudad`.

## 4. Cómo sigue el programa una opción

Al elegir registrar:

```text
main pide una línea con xi, xf y altura
       ↓
convertir_edificio revisa el texto y la validez geométrica
       ↓
registrar_edificio intenta agregarlo a la ciudad
       ↓
si devuelve ESTADO_OK, se recalculan horizonte y medidas
```

Al cargar con éxito ocurre también la actualización. Si el horizonte o las medidas no pueden calcularse, se marcan como no disponibles y no se muestran resultados antiguos.

Para modificar o eliminar, el usuario numera desde 1; el arreglo empieza desde 0. Por eso el menú pasa `numero - 1` a las funciones.

## 5. Estados y funciones pendientes

`Estado` es un `enum` definido en `ciudad.h`. Cada nombre representa un resultado: por ejemplo, `ESTADO_OK`, `ESTADO_INVALIDO` o `ESTADO_PENDIENTE`. Al principio las funciones de los compañeros devuelven pendiente; no significa que sus tareas estén implementadas. La función de listado es `void` y muestra un mensaje de pendiente en su implementación provisional.

`informar_estado` muestra un mensaje según el estado recibido. Solo cuando la operación devuelve `ESTADO_OK` el menú continúa como operación exitosa.

## 6. Lectura y validación

`leer_linea` usa `fgets` para leer una línea completa. Si la línea es demasiado larga, descarta el resto y la deja vacía para rechazarla sin dejar caracteres para la siguiente pregunta. Devuelve 0 si termina la entrada.

`convertir_entero` usa `strtol`; `convertir_edificio` usa `strtod` tres veces. Estas funciones de biblioteca indican dónde terminó el texto convertido. Así se rechazan datos incompletos, letras adicionales y valores fuera de rango. La validación geométrica común está en `edificio_valido`, dentro de `comun.c`; también debe usarla quien cargue ciudades desde archivos.

Símbolos que aparecen en esas funciones:

- `errno` y `ERANGE`: ayudan a detectar conversiones fuera de rango.
- `isspace`: identifica espacios u otros separadores; la conversión a `unsigned char` permite usarla de forma segura con caracteres.
- `strcspn`: en esta base localiza el salto de línea para retirarlo de la cadena.
- `sizeof linea`: proporciona el tamaño del arreglo de caracteres creado en `main`.

Puedes estudiar estos detalles después de comprender el recorrido general. Se conservan porque la guía exige rechazar entradas inválidas rigurosamente.

## 7. Otras formas del lenguaje

- `static` delante de una función en `main.c` significa que esa función auxiliar solo puede usarse desde ese archivo.
- `while (1)` repite el menú; `break` permite salir y `continue` pasa a la siguiente vuelta.
- `switch` selecciona el mensaje según `Estado`; `break` termina cada caso.
- `%.10g` imprime un número decimal con hasta diez cifras significativas; no fija diez decimales.

Al agregar código, preferir nombres claros, llaves y un paso por línea. Si un requisito parece necesitar una técnica no estudiada, primero comentarlo con el integrador y buscar una solución que puedan explicar en equipo.
