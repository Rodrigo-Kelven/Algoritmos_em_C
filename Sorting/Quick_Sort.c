#include <stdio.h>

// Função para mesclar duas sublistas
void merge(int arr[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1; // Tamanho da sublista esquerda
    int n2 = direita - meio;      // Tamanho da sublista direita

    // Cria arrays temporários
    int L[n1], R[n2];

    // Copia os dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[esquerda + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    // Mescla os arrays temporários de volta em arr[esquerda..direita]
    i = 0; // Índice inicial do primeiro subarray
    j = 0; // Índice inicial do segundo subarray
    k = esquerda; // Índice inicial da mesclagem

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal que ordena arr[esquerda..direita] usando merge()
void mergeSort(int arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        // Encontra o ponto médio
        int meio = esquerda + (direita - esquerda) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(arr, esquerda, meio);
        mergeSort(arr, meio + 1, direita);

        // Mescla as duas metades ordenadas
        merge(arr, esquerda, meio, direita);
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
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    imprimirArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Array ordenado:\n");
    imprimirArray(arr, n);

    return 0;
}
