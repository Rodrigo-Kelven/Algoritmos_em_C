#include <stdio.h>

// Função para realizar a ordenação por seleção
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Encontra o índice do menor elemento na parte não ordenada
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Troca o menor elemento encontrado com o primeiro elemento da parte não ordenada
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
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
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    imprimirArray(arr, n);

    selectionSort(arr, n);

    printf("Array ordenado:\n");
    imprimirArray(arr, n);

    return 0;
}
