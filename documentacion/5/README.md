# Building Block

Componentes Principales:

-----
|Componente|Descripción|
|----|---|
main.cpp|	Controlador principal; coordina la ejecución de las funciones principales.
needleman_wunsch.cpp/.h|	Implementación del algoritmo y estructuras auxiliares.
utils.cpp/.h	|Funciones auxiliares (lectura de archivos, validación de entradas).
Graphviz	|Scripts generados automáticamente para visualización del alineamiento.

Estrategia de Compilación:
g++ -o main.exe main.cpp needleman_wunsch.cpp utils.cpp
