# Pruebas del integrador

Ejecutar desde la carpeta principal, con GCC disponible. Compilar cada ejecutable antes de usarlo y continuar solo si no hubo errores. Los comandos corresponden a la base sin biblioteca gráfica; habrá que actualizar el enlace cuando se incorpore una.

## 1. Entrada del menú

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror pruebas/entrada.c entrada.c comun.c -o pruebas_entrada.exe
./pruebas_entrada.exe
```

Resultado esperado en la base: 13 comprobaciones correctas y 0 fallos.

## 2. Contratos de los módulos

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror pruebas/modulos.c comun.c gestion.c horizonte.c medidas.c grafico_edificios.c grafico_horizonte.c archivos.c -o pruebas_modulos.exe
```

Ejecutar el módulo que se esté revisando:

```bash
./pruebas_modulos.exe gestion
./pruebas_modulos.exe horizonte
./pruebas_modulos.exe medidas
./pruebas_modulos.exe grafico_edificios
./pruebas_modulos.exe grafico_horizonte
./pruebas_modulos.exe archivos
```

En esta base todos indican pendiente y terminan con código 1. Cuando se implementen, el código 0 indica que pasaron las comprobaciones automáticas seleccionadas. En gráficos, el código 2 indica revisión visual pendiente después de que la función regresó con `ESTADO_OK`. Un mensaje de uso incorrecto también termina con 2: leer siempre la salida.

Este ejecutable enlaza los seis módulos. Para probar uno sin depender de que los demás compilen, usar [su ejemplo individual](../pruebas/LEEME.md).

## 3. Conexión del menú con funciones simuladas

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror main.c entrada.c comun.c pruebas/dobles_menu.c -o pruebas_menu.exe
python pruebas/verificar_menu.py
```

Requiere Python 3 solo para esta comprobación. `dobles_menu.c` simula respuestas para revisar ciudad vacía, orden de vistas, fallo gráfico y descarte de resultados anteriores. No abre ventanas ni implementa los algoritmos generales.

Compilarlo únicamente con los archivos del comando: si se añade a los módulos reales habrá funciones duplicadas.

## 4. Integración real

Después de revisar un módulo, compilar el programa completo con el comando del README. Al estar implementadas las funciones necesarias, probar los casos de [casos.md](../pruebas/casos.md), guardar y cargar, y observar las ventanas reales. Registrar datos, resultados y pendientes en [verificacion.md](verificacion.md).
