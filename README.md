# Proyecto Final 
## Sistemas Distribuidos. FI, UNAM.
<p>Se pusieron en práctica los patrones arquitectónicos de malla, árbol, pool, pipeline y estrella para sistemas paralelos 
con ayuda de MPI en el lenguaje de programación C.
El reporte proyectoSD.pdf incluye el documento con la teoría necesaria y el análisis de los programas realizados, así como sus métricas
de rendimiento y sus respectivas gráficas.
Cada carpeta contiene su implementación en secuencial y paralelo. El programa secuencial para los patrones pool, estrella y pipeline 
es el mismo, este se encuentra en la carpeta correspondiente a pipeline.</p>

### Requisitos de instalación para la ejecución:
<ul>
<li>Distribución de linux, de preferencia debian.</li>
<li>MPI</li>
<\ul>

### Comandos de ejecución:
<li>Programas en paralelo:</li>
<p>mpicc pool.c -o pool -lm</p>
<p>mpirun -np #numeroProcesadores pool</p>
<strong>Nota:</strong> el lm es necesario para poder utilizar la función pow de la biblioteca math.h
<li>Programas en secuencial:</li>
<p>gcc secuencial.c -o secuencial -lm</p>
<p>./secuencial</p>
