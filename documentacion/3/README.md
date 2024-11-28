# Contexto del Sistema
El algoritmo de Needleman-Wunsch se integra para alineamiento de secuencias biológicas, donde interactúa con varios externos (Personas, herramienta externas para la validación). A continuación, se describe el contexto general:
## Elementos Externos (Actors):
Usuario Final:
* Interactúa con el sistema a través de la terminal.
* Realiza la carga de secuencias y consulta resultados.

Herramientas de Terceros:
* EMBOSS Needle: Herramienta utilizada para comparar los resultados del algoritmo (a gap 0.5 de penalidad).
* Graphviz: visualización del .dot para el alineamiento

Entorno de Ejecución:
* Sistema operativo Linux como base principal para el desarrollo y uso del software.

# Visión general
+-------------------+         +----------------------+
| Usuario Final       |         | EMBOSS Needle        |
|                     | <-----> | (Comparación)        |
+-------------------+         +----------------------+
         |
         v
+---------------------------------------------+
| Algoritmo de Needleman-Wunsch               |
| (Implementación en C++)                     |
+---------------------------------------------+
         |
         v
+-------------------+         +----------------------+
| Archivos de Entrada         | Graphviz             |
| (Secuencias *.fna)          | (Visualización)      |
+-------------------+         +----------------------+

# Limitaciones

El sistema no incluye una interfaz gráfica avanzada (no supe hacerlo bien :c ), pero proporciona visualizaciones a través de archivos generados por Graphviz (tampoco lo hice bien).

