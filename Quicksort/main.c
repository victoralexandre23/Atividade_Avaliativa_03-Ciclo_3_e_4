// ALGORITMO IMPLEMENTADO: QUICKSORT

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_LENGTH 10 // Define o tamanho do array

void printArray(int array[]);
void swap(int *x, int *y);
void quicksort(int array[]);
void quicksortRecursion(int array[], int low, int high);
int partition(int array[], int low, int high);

int main(){
    int array[ARRAY_LENGTH];
    srand(time(NULL));
    for (int i = 0; i < ARRAY_LENGTH; ++i){ // define um array com números aleatórios
        array[i] = rand()%20;
    }

    printf("Array Original: ");
    printArray(array);

    printf("\n");
    quicksort(array);

    printf("Array Ordenado: ");
    printArray(array);
}

void printArray(int array[]){
    for (int i = 0; i < ARRAY_LENGTH; ++i) {
        printf("%d ", array[i]);
    }
}

void swap(int *x, int *y){ // alterna dois valores de lugar
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int array[]){ // Função criada por comodidade (só é necessário passar o array)
    srand(time(NULL));
    quicksortRecursion(array, 0, ARRAY_LENGTH - 1);
}

void quicksortRecursion(int array[], int low, int high){
    if (low < high){
        int pivotIndex = partition(array, low, high); // Particiona o array e retorna a posição do pivo
        quicksortRecursion(array, low, pivotIndex - 1); // Faz o quicksort a esquerda do pivo
        quicksortRecursion(array, pivotIndex + 1, high); // Faz o quicksort à direita do pivo
    }
}

int partition(int array[], int low, int high){
    int pivotIndex = low + (rand() % (high - low)); // Escolhe um elemento aleatório (entre low e high) para ser o pivo

    if (pivotIndex != high){ // Troca o pivo de lugar com o último elemento da partição atual
        swap(&array[pivotIndex], &array[high]);
    }

    int pivotValue = array[high];

    int i = low; // Guarda a posição que começa os valores maiores que o pivo
    for (int j = low; j < high; j++){
        if (array[j] <= pivotValue){ // Coloca os valores menores ou iguais ao pivo a esquerda
            swap(&array[i], &array[j]);
            i++;
        }
    }

    // Como sabemos que a variavel i é o começo dos números maiores que o pivo trocamos ela de lugar com o pivo
    swap(&array[i], &array[high]);

    return i; // agora i contém a posição do pivo
}
