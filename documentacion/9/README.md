# Decisiones de arquitectura

Se decidió no usarse GTK ya que no pude hacerlo correctamente, pero si alguien más puede hacerlo, adelante. 

En su momento pensé usar Grep para filtrar sin que tenga >, pero tuve error de usar system (" grep -v" + filename)
system no acepta strings sino const char* entonces da problema y se optó de otra forma.

El ver el archivo en la terminal se usa cat en un reporte temporal porque la verdad no quería tocar código para leer el archivo así que más cortó re usar para escribir (el como escribir) y cambiarlo, además así pueden copiar y pegar el archivo temporal en otra parte.

Hay problema con graphviz, pero es porque no siento que se vea bien en matriz, para matriz es mejor una imagen rectangular (el cuadrado es un rectangulo con a = b), pero por tiempo lo deje con graphviz aunque se vea mal.
