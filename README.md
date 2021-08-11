PdM - TP Final
==============

Alumno: Gonzalo Nahuel Vaca

# Introducción

Este es el trabajo final de la asignatura *Programación de microprocesadores* de la *Especialización en Sistemas Embebidos* de la **Universidad de Buenos Aires**.

El trabajo es una implementación del algoritmo de Sarwate. Esto incluye:

* Generación de tabla de búsqueda
* Cálculo de CRC de una trama

La principal ventaja del algoritmo es que se puede procesar una trama byte a byte. El método tradicional obliga a utilizar un ciclo de máquina por cada bit de la trama.

# Requerimientos

* Placa **NUCLEO-F429ZI**
* Cable USB
* Entorno **Mbed OS 6 STD**
* Intérprete de Python3

# Instrucciones

Al inicializar la placa se imprimirá el polinomio usado y la tabla generada.
Luego, se escuchará el puerto serie y tomará tramas de a 10 bytes.
Finalmente, informará el mensaje obtenido, el CRC del mensaje y el CRC calculado.

Nota: el byte 10 de la trama es considerado como el CRC
