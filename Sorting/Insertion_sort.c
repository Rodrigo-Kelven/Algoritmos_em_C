#include <stdio.h>

// Função para realizar a ordenação por inserção
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = arr[i]; // O elemento a ser inserido
        int j = i - 1;

        // Move os elementos de arr[0..i-1], que são maiores que a chave,
        // para uma posição à frente de sua posição atual
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave; // Insere a chave na posição correta
    }
}

// Função para imprimir o array
void imprimirArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    imprimirArray(arr, n);

    insertionSort(arr, n);

    printf("Array ordenado:\n");
    imprimirArray(arr, n);

    return 0;
}
