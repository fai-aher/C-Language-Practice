/* 
   Desarrollo del Trabajo Práctico 3 para el curso de Infraestructura Tecnologica

   Este programa fue desarrollado por: Faiber Alonso Hernandez Tavera, con codigo
   de estudiante: 202012367 y correo institucional: f.hernandezt@uniandes.edu.co

   El programa consta de tres funciones principales:
   - main()
   - invertirVector()
   - reversarInt()

   Y se encarga de, dado un vector de numeros enteros, tratarlos como uno solo,
   convertirlos a digitos binarios e invertir el orden de esos digitos binarios
   para al final retornar el resultado en digitos hexadecimales separados por
   grupos de 8.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Declaracion de prototipos de 2 de las funciones
void invertirVector(int *vector, int n);
unsigned int reversarInt(unsigned int valor);


/* Metodo principal para pedir los datos de entrada al usuario y devolver
   el resultado en el formato solicitado. Se realizan los siguientes procedimientos:

   ▪ Se le pide al usuario el tamaño del vector (n) para inicializar la respectiva variable
        (validar que n > 0).
    ▪ Declara e inicializa el apuntador al vector de int. La inicialización consiste en
        ponerlo a apuntar a un vector de int del tamaño pedido. El vector se crea
        dinámicamente usando la función de C calloc.
    ▪ Inicializa el vector: le pide al usuario que teclee el valor de cada elemento.
    ▪ Invoca el procedimiento invertirVector.
    ▪ Imprime el resultado (el vector de int) posición por posición en hexadecimal.
*/

int main() {
    int n;
    char input[100];
    int valid;

    // Se Solicita y valida el tamanio del vector, debe ser mayor a 0.
    do {
        printf("Ingrese el tamanio del vector cuyo contenido se desea invertir (debe ser un numero entero mayor a 0): ");
        fgets(input, sizeof(input), stdin);
    } while (sscanf(input, "%d", &n) != 1 || n <= 0);

    // Se Crea y reserva memoria para manejar el vector
    int *vector = (int *)calloc(n, sizeof(int));

    // Se Solicitan y validan los elementos del vector uno por uno, deben ser numeros enteros.
    for (int i = 0; i < n; i++) {
        do {
            printf("Ingrese el elemento %d del vector (debe ser un numero entero): ", i + 1);
            fgets(input, sizeof(input), stdin);
        } while (sscanf(input, "%d", &vector[i]) != 1);
    }

    // Se llama a la funcion que invierte los elementos del vector
    invertirVector(vector, n);

    // Se Imprime el vector invertido en formato hexadecimal, separado en 
    // grupos de 8 digitos hexadecimales.
    printf("\n> El vector resultante en hexadecimal es: \n\n");

    for (int i = n - 1; i >= 0; i--) {
        printf("0x%.8X ", vector[i]);
    }
    printf("\n\n");

    // Se Libera la memoria que habia sido reservada para el vector
    free(vector);
    return 0;
}

/*Función para invertir el vector utilizando reversarInt.

    ▪ Tiene dos parametros: un apuntador al vector de enteros y un entero con el tamanio
        del vector.
    ▪ Realiza la inversión sobre el mismo vector.
    ▪ Utiliza reversarInt para invertir cada posicion.
*/
void invertirVector(int *vector, int n) {
    for (int i = 0; i < n; i++) {
        vector[i] = reversarInt((unsigned int)vector[i]);
    }
}

/* Funcion para reversar los bits de un entero

    ▪ Tiene un parametro: el valor del int que se desea reversar.
    ▪ Reversa el valor y lo retorna (con return).

    La funcion recorre los bits del numero de entrada, uno por uno, 
    desde el bit menos significativo hasta el bit mas significativo.
    En cada iteracion, toma el bit actual (menos significativo) del
    numero de entrada y lo coloca en el bit correspondiente al bit
    mas significativo del resultado.

    Luego, desplaza los bits del numero de entrada hacia la derecha y
    los bits del resultado hacia la izquierda.
    Este proceso se repite 32 veces, que es la cantidad de bits en un
    unsigned int de 4 bytes.
*/
unsigned int reversarInt(unsigned int valor) {
    unsigned int resultado = 0;
    for (int i = 0; i < 32; i++) {
        resultado = (resultado << 1) | (valor & 1);
        valor >>= 1;
    }
    return resultado;
}
