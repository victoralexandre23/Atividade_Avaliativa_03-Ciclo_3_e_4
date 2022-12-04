// ALGORITMO IMPLEMENTADO: INSERTION SORT

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_LENGTH 5 // definir tamanho da array

void insertionSort(int a[]){
    for (int i = 1; i < ARRAY_LENGTH; ++i) {// considera o primeiro valor como correto
        int aux = a[i]; // Variavel auxiliar recebe o valor do array
        int j = i - 1; // j é definido como o valor a esquerda do número atual
        while (j >= 0 && a[j] > aux){ // caso os numeros sejam maiores que aux, movem a direita, não deixando passar do primeiro elemento do array
            a[j + 1] = a[j]; // Move o número para direita
            j--;
        }
        a[j + 1] = aux; // Coloca o número no local correto
    }
}

void printArray(int a[]){
    for (int i = 0; i < ARRAY_LENGTH; ++i) {
        printf("%d ", a[i]);
    }
}

int main(){
    int array[ARRAY_LENGTH];

    // define uma array com números aleatórios
    srand(time(NULL));
    for (int i = 0; i < ARRAY_LENGTH; ++i) {
        array[i] = rand()%10;
    }

    printf("Lista Original: ");
    printArray(array);

    printf("\n");
    insertionSort(array);

    printf("Lista Ordenada: ");
    printArray(array);
}