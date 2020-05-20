# Proyecto Final 
## Sistemas Distribuidos. FI, UNAM.
<p>Se pusieron en práctica los patrones arquitectónicos de malla, árbol, pool, pipeline y estrella para sistemas paralelos 
con ayuda de MPI en el lenguaje de programación C.
El reporte proyectoSD.pdf incluye el documento con la teoría necesaria y el análisis de los programas realizados, así como sus métricas
de rendimiento y sus respectivas gráficas.
Cada carpeta contiene su implementación en secuencial y paralelo. El programa secuencial para los patrones pool, estrella y pipeline 
es el mismo, este se encuentra en la carpeta correspondiente a pipeline.</p>

### Requisitos de instalación para la ejecución:
<li>Distribución de linux, de preferencia debian.</li>
<li>MPI</li>

### Comandos de ejecución:
<li>Programas en paralelo:
<p>mpicc pool.c -o pool -lm</p>
<p>mpirun -np #numeroProcesadores pool</p></li>
<strong>Nota:</strong> La bandera -lm es necesario para poder utilizar la función pow de la biblioteca math.h
<li>Programas en secuencial:
<p>gcc secuencial.c -o secuencial -lm</p>
<p>./secuencial</p></li>

