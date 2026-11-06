"""Verifica el menu con dobles de prueba; no demuestra dibujos reales."""
import subprocess
from pathlib import Path

programa = Path('pruebas_menu.exe').resolve()

def ejecutar(entrada):
    proceso = subprocess.run([str(programa)], input=entrada, text=True,
                             capture_output=True, timeout=10)
    assert proceso.returncode == 0, proceso.stderr
    return proceso.stdout

vacia = ejecutar('6\n0\n')
assert 'No hay edificios para graficar.' in vacia
assert 'DOBLE DE PRUEBA: vista' not in vacia

salida = ejecutar('1\n0 4 3\n6\n2\n1\n0 4 9\n5\n6\n0\n')
assert 'Area = 12' in salida and 'Perimetro = 14' in salida
assert salida.count('DOBLE DE PRUEBA: vista de edificios.') == 2
assert salida.count('DOBLE DE PRUEBA: vista de horizonte.') == 1
assert salida.index('DOBLE DE PRUEBA: vista de edificios.') < salida.index('DOBLE DE PRUEBA: vista de horizonte.')
assert 'Horizonte no disponible: calculo pendiente o fallido.' in salida
assert 'Grafico de horizonte no disponible: calculo pendiente o fallido.' in salida

error = ejecutar('1\n0 4 8\n6\n0\n')
assert 'No se pudo mostrar el grafico.' in error
assert 'DOBLE DE PRUEBA: vista de horizonte.' in error

print('OK: ciudad vacia, orden de vistas, fallo grafico y resultados no desactualizados.')
print('Solo se probaron llamadas simuladas; los dibujos reales siguen pendientes.')
