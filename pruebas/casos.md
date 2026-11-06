# Matriz de pruebas que el equipo debe ejecutar

Todas estas pruebas están **pendientes para esta base**. El integrador registrará los resultados reales en `documentacion/verificacion.md`. Los casos automáticos iniciales de `modulos.c` son un subconjunto y no sustituyen esta matriz ni la revisión de los gráficos.

| ID | Requisito del PDF | Datos o situación | Resultado esperado |
|---|---|---|---|
| P01 | Un edificio | `(0,4,3)` | Horizonte igual al edificio; área 12, perímetro 14. |
| P02 | Consecutivos | `(0,2,2), (2,5,4)` | Sin hueco; horizonte con ambas alturas; área 16, perímetro 18. |
| P03 | Superpuestos de distinta altura | `(0,4,2), (2,6,5)` | `(0,2,2), (2,6,5)`; área 24, perímetro 22. |
| P04 | Superpuestos de igual altura | `(0,4,3), (2,6,3)` | `(0,6,3)`; área 18, perímetro 18. |
| P05 | Separados | `(0,2,2), (4,5,3)` | `(0,2,2), (2,4,0), (4,5,3)`; área 7, perímetro 16. |
| P06 | xi igual o mayor a xf | `(2,2,1)`, `(3,2,1)` | Rechazar sin cambiar la ciudad. |
| P07 | Altura cero o negativa | `(0,2,0)`, `(0,2,-1)` | Rechazar sin cambiar la ciudad. |
| P08 | Modificar y eliminar | Cambiar `(0,3,2)` a `(0,4,3)` y eliminarlo | Recalcular: área 12, perímetro 14; luego ciudad vacía. |
| P09 | Lista vacía | Ningún edificio | Mensaje claro; ningún cálculo o gráfico inválido. |
| P10 | Guardar y volver a ejecutar | Ciudad oficial, cerrar programa y volver a abrir | Recuperar los cinco edificios originales. |
| P11 | Cargar ciudad | `pruebas/ejemplo.txt` | Horizonte oficial; área 95; perímetro 74. |
| P12 | Archivo inexistente o inválido | Inexistente, vacío, incompleto, texto y geometría inválida | Informar error y preservar ciudad anterior. |
| P13 | Cambiar después de cargar | Cargar, modificar, eliminar, guardar y volver a cargar | Cambios persistentes y cálculos actualizados. |

## Casos adicionales de la sección 11 del PDF

Registrar también entrada, horizonte esperado y obtenido, área, perímetro, conclusión y ambos gráficos cuando corresponda:

- Edificio completamente oculto y parcialmente oculto.
- Edificios anidados más bajos y más altos.
- Varios edificios con igual inicio, igual final y varios finales/inicios en la misma coordenada.
- Cambios sucesivos de altura, tanto crecientes como decrecientes.
- Tres o más grupos separados y todos sus huecos.
- Duplicados exactos, alturas iguales y extremos repetidos.
- Entrada desordenada, decimales, no finitos, valores límite y 100 edificios; rechazar el número 101.
- Archivo con más de 100 líneas, líneas largas, registro adicional inválido y error de escritura.
- Ambas representaciones gráficas con escala, ejes y etiquetas, antes y después de cargar.

Los cálculos pueden contrastarse con casos manuales y con el oráculo independiente de la solución de referencia; no copiar resultados sin ejecutarlos. Las vistas gráficas requieren observarlas en pantalla y comprobar visualmente su contenido. La biblioteca concreta todavía está por decidir.
