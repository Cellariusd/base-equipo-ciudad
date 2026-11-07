# Abrir y compilar con Code::Blocks

## 1. Abrir el proyecto

1. Abre Code::Blocks.
2. Selecciona **File → Open** y abre `base-equipo-ciudad.cbp`, en la carpeta principal del repositorio.
3. En el panel **Management → Projects** aparecerá **Proyecto Ciudad - Equipo**, con los archivos fuente y las cabeceras.

También puedes hacer doble clic en el `.cbp` si Windows lo tiene asociado a Code::Blocks. El archivo usa rutas relativas: sirve también para tus compañeros, aunque clonen en otra carpeta.

## 2. Compilar y ejecutar

1. Selecciona **Debug** en la lista de configuraciones de compilación.
2. Pulsa **Build → Build and run** o **F9**.
3. Debe abrirse la consola con el menú. Al principio las funciones de los compañeros siguen indicando que están pendientes.
4. Escribe `0` y pulsa Enter para salir.

El proyecto está configurado como aplicación de consola en C, con C11 y advertencias estrictas. **Debug** incluye información para depurar; **Release** activa optimizaciones. Los ejecutables se crean en `bin/Debug/ciudad.exe` y `bin/Release/ciudad.exe`, respectivamente, y los objetos en `obj/`. Esas carpetas están ignoradas por Git.

El directorio de ejecución es la raíz del proyecto. Así, rutas como `pruebas/ejemplo.txt` se interpretan desde la misma carpeta que al ejecutar los comandos del README.

### Si no encuentra el compilador

Abrir un `.cbp` no instala GCC. Cada compañero necesita configurar su instalación una vez:

1. Ve a **Settings → Compiler** y selecciona **GNU GCC Compiler**.
2. Abre **Toolchain executables**.
3. Usa **Auto-detect** o selecciona la carpeta donde está instalado el compilador.
4. Si Code::Blocks se instaló con MinGW, una ubicación habitual es `C:\Program Files\CodeBlocks\MinGW`. En una instalación MSYS2 UCRT64 puede ser `C:\msys64\ucrt64`.
5. Comprueba que esa carpeta contiene `bin\gcc.exe` y vuelve a compilar.

Estas ubicaciones son ejemplos de instalación local; el `.cbp` no fija ninguna ruta de compilador para el equipo.

## 3. Abrir desde GitHub Desktop

En **File → Options → Integrations → External editor → Configure custom editor…**:

**Path:** selecciona `codeblocks.exe` en tu instalación. En la computadora del integrador:

```text
C:\Program Files\CodeBlocks\codeblocks.exe
```

**Arguments:** copia exactamente, incluyendo las comillas:

```text
--multiple-instance --no-dde "%TARGET_PATH%\base-equipo-ciudad.cbp"
```

Pulsa **Save**. Selecciona el repositorio `base-equipo-ciudad` y usa **Repository → Open in external editor** (el nombre puede mostrar el editor elegido).

`%TARGET_PATH%` representa la carpeta del repositorio seleccionado. Al añadir el nombre `.cbp`, Code::Blocks recibe el archivo de proyecto, no solo una carpeta. Las comillas permiten usar rutas con espacios.

`--multiple-instance --no-dde` abre una ventana independiente. En la prueba local, enviar la ruta a una instancia ya abierta con otro proyecto produjo el mensaje «The project file does not exist»; con estas opciones la apertura fue correcta. Si pulsas varias veces, se abrirán varias ventanas: continúa trabajando en una sola para evitar editar el mismo archivo en dos sitios.

Esta preferencia de GitHub Desktop es local: cada compañero debe configurarla en su computadora. Además, el argumento presupone que el repositorio seleccionado contiene `base-equipo-ciudad.cbp`; no sirve automáticamente para repositorios con otros nombres de proyecto. La opción **Shell** es independiente del editor y puede mantenerse como está.

## 4. Qué archivos compartir

Comparte `base-equipo-ciudad.cbp` junto con los fuentes. Los archivos de sesión `.layout`, los objetos y los ejecutables se ignoran. Los ejemplos de `pruebas/` se compilan aparte como indica [su guía](../pruebas/LEEME.md): no los añadas al ejecutable principal, porque contienen otros `main` o funciones simuladas.

La biblioteca gráfica sigue pendiente de aprobación. Cuando se elija, el integrador actualizará el proyecto con sus opciones de compilación y enlace.
