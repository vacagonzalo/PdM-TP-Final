PdM - TP Final
==============

Trabajo final de la materia *Programación de microprocesadores* de la *Especialización en Sistemas Embebidos* de la **Universidad de Buenos Aires**.

Alumno: Gonzalo Nahuel Vaca

# Introducción

El trabajo es una implementación del algoritmo de Sarwate. Esto incluye:

* Generación de tabla de búsqueda.
* Cálculo de CRC de una trama.
* Verificación del CRC de la trama recibida.

La principal ventaja del algoritmo es que se puede procesar una trama byte a byte.
El método tradicional obliga a utilizar un ciclo de máquina por cada bit de la trama.

Adicionalmente, se implementó un módulo para realizar lecturas no bloqueantes de la UART.

# Requerimientos

* Placa **NUCLEO-F429ZI** (debería correr en cualquier placa).
* Cable USB.
* Entorno **Mbed OS 6 STD** (se usa lectura/escritura con buffer tipo POSIX).
* Intérprete de Python3 (para correr el script de prueba en su ordenador).

# Instalación
* Clonar el repositorio en su carpeta de **Mbed Programs**.
* Abrir **Mbed Studio**.
* Observe que se le indicará que el requerimiento **Mbed-OS** no se cumple.
* Puede usar el IDE para que descargue/enlace el programa a **Mbed-OS**.
* Compile para su *Target* y corra el firmware.

# Operación

Al inicializar la placa se imprimirá el polinomio usado y la tabla generada.
Luego, se escuchará el puerto serie y tomará tramas de a 10 bytes.
Finalmente, informará el mensaje obtenido, el CRC del mensaje y el CRC calculado.

Por cada trama detectada el LED *VERDE* cambiará de estado.
Si una trama no tiene un CRC válido se encenderá el LED *ROJO*.
Si la trama tiene un CRC válido el LED *ROJO* se apagará.

Nota: el byte 10 de la trama es considerado como el CRC
