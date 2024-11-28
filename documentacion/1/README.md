# Introducción y Metas

El algoritmo de Needleman-Wunsch es ampliamente reconocido en bioinformática como una herramienta clave para el alineamiento de secuencias biológicas, como ADN y proteínas. Este método permite encontrar el alineamiento global óptimo entre dos secuencias, maximizando similitudes y minimizando diferencias. Su relevancia radica en que evita la complejidad de métodos de fuerza bruta, cuya evaluación exhaustiva tendría una complejidad combinatoria:
$$
\frac{2^{2N}}{\sqrt{\pi N}}
$$

El uso de matrices y subsecuencias óptimas lo hace computacionalmente viable para secuencias de longitud moderada. Este proyecto busca implementar una versión eficiente del algoritmo que no solo permita realizar alineamientos precisos, sino también visualizar los resultados y evaluar su desempeño.

> Fuente: Likic, V. (2008). The Needleman-Wunsch algorithm for sequence alignment. Lecture given at the 7th Melbourne Bioinformatics Course, Bi021 Molecular Science and Biotechnology Institute, University of Melbourne, 1-46. Recuperado el 8 de noviembre en https://www.cs.sjsu.edu/~aid/cs152/NeedlemanWunsch.pdf

Para ser trabajado se tomará en cuenta distinta información del medio digital. Como es Wikipedia, la información de los enlaces entregados por el profesor:

>1 Lee, C. T., & Peng, S. L. (2017). A Pairwise Alignment Algorithm for Long Sequences of High Similarity. Information and Communication Technology : Proceedings of ICICT 2016, 625, 279–287. https://doi.org/10.1007/978-981-10-5508-9_27 

>2 EMBOSS Needle, para probar las secuencias actúa adecuadamente el algoritmo de comparación, consultado el 8 de noviembre de 2024 en https://www.ebi.ac.uk/jdispatcher/psa

>3 Hendrix, D. A. (2019). Chapter 3: Sequence Alignments. Applied Bioinformatics, nd. Recuperado el 8 de noviembre de 2024 en https://open.oregonstate.education/appliedbioinformatics/chapter/chapter-3/

Y se desea que se visualice el algoritmo de una forma similar a la descrita en el paper:
<image src="https://cdn.ncbi.nlm.nih.gov/pmc/blobs/94f3/7123042/a515e930ee4f/435698_1_En_27_Fig1_HTML.jpg" alt="Imagen proveniente del paper, en el enlace número 1 del profesor">

## Metas del Proyecto:

* Implementar una versión funcional del algoritmo en C++, optimizando el uso de memoria para secuencias largas.
* Comparar los resultados con herramientas estándar como EMBOSS Needle.
* Evaluar escalabilidad con secuencias de diferentes tamaños.
* Proveer visualizaciones del alineamiento mediante Graphviz.

## Vista de Requerimientos

Para el requerimienbto tenemos que realizar el trabajo mediante github siguiendo las instrucciones que el profesor ha puesto en la plataforma web de la Universidad de Talca.

## Partes interesadas (Stakeholders)

El profesor:

|Nombre|Contacto|Expectativas|
|---|---|---|
|Profesor: Roberto Rosalese| roberto.rosales@utalca.cl|Desarrollo adecuado de algoritmo de la bioinformática para el trabajo de secuencias biológicas.|