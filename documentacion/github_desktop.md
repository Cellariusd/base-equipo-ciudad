# Trabajo del equipo con GitHub Desktop

## 1. Preparación del integrador

El repositorio local tiene configurada esta dirección remota:

<https://github.com/Cellariusd/base-equipo-ciudad>

Antes de enviar el enlace al equipo:

1. Selecciona `base-equipo-ciudad` en GitHub Desktop y revisa la pestaña **Changes**.
2. Revisa los archivos modificados. Escribe un resumen en **Summary** y pulsa **Commit to main** si estás preparando la base en esa rama.
3. Pulsa **Push origin** para enviar los commits. Si Desktop aún muestra **Publish repository**, completa ese paso y comprueba la dirección resultante.
4. Abre **Repository → View on GitHub** y comprueba que se vea el README actualizado.
5. En GitHub, entra en **Settings → Collaborators** (el nombre puede variar según el tipo de cuenta), invita a tus compañeros y pídeles aceptar la invitación.
6. Indica quién hará cada módulo y qué compilador usarán. Comunica la biblioteca gráfica cuando esté aprobada.

## 2. Descargar tu copia — cada compañero

1. Inicia sesión en GitHub Desktop y acepta la invitación al repositorio.
2. Ve a **File → Clone repository → URL**.
3. Pega la dirección del repositorio y elige una carpeta local para tu copia.
4. Pulsa **Clone**. Así tendrás los archivos y el historial en tu computadora.
5. Abre la carpeta con **Repository → Show in Explorer** y lee `README.md`.

Para abrir el proyecto directamente en Code::Blocks desde Desktop, sigue [la configuración del editor externo](codeblocks.md#3-abrir-desde-github-desktop). El archivo que debes abrir es `base-equipo-ciudad.cbp`.

## 3. Crear tu rama antes de editar

1. En **Current Branch**, selecciona `main`.
2. Pulsa **Fetch origin** y, si aparece, **Pull origin**, para recibir lo último.
3. Ve a **Branch → New branch** y crea la rama de tu módulo:

| Módulo | Nombre sugerido |
|---|---|
| Gestión | `modulo/gestion` |
| Horizonte | `modulo/horizonte` |
| Medidas | `modulo/medidas` |
| Gráfico de edificios | `modulo/grafico-edificios` |
| Gráfico del horizonte | `modulo/grafico-horizonte` |
| Archivos | `modulo/archivos` |

4. Comprueba que **Current Branch** muestre tu rama. Ahora edita tu archivo, compila y prueba.

## 4. Guardar avances y enviarlos

1. Guarda los archivos en tu editor y vuelve a GitHub Desktop.
2. En **Changes**, revisa qué cambió. Selecciona los archivos correspondientes a tu tarea.
3. En **Summary**, escribe algo concreto, por ejemplo: `Implementar registro y eliminacion de edificios`.
4. Pulsa **Commit to …**. Un commit guarda un avance en tu computadora.
5. Pulsa **Publish branch** la primera vez; después usa **Push origin**. Eso envía tus commits a GitHub.
6. Para solicitar la integración, usa **Preview Pull Request / Create Pull Request** (según la versión). Verifica que la rama destino, **base**, sea `main` y que **compare** sea tu rama.
7. Describe los cambios y las pruebas; pulsa **Create pull request** en GitHub y comparte el enlace con el integrador.

Puedes usar este texto para la descripción:

```text
Módulo:
Qué implementé:
Comando de compilación:
Casos probados (datos / esperado / obtenido):
Capturas, si corresponde:
Qué falta o qué necesito consultar:
```

Si te piden correcciones, hazlas en la misma rama, crea otro commit y pulsa **Push origin**. La solicitud se actualiza automáticamente.

## 5. Recibir lo que ya integró el equipo

- Para consultar la versión integrada: guarda tus avances en un commit, cambia a `main`, pulsa **Fetch origin** y después **Pull origin** si aparece.
- Si necesitas esos cambios en una rama de trabajo que ya existe: vuelve a tu rama y usa **Branch → Merge into current branch**, seleccionando `main`.
- Si aparece un conflicto, avisa al integrador y revisen juntos las líneas señaladas antes de continuar.

El integrador revisa las solicitudes y las integra una a una. Cada compañero debe volver a compilar tras recibir cambios compartidos.
