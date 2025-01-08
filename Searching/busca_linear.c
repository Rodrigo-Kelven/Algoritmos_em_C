#include <stdio.h>

// Função para realizar a busca linear
int buscaLinear(int arr[], int tamanho, int chave) {
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] == chave) {
            return i; // Retorna o índice onde a chave foi encontrada
        }
    }
    return -1; // Retorna -1 se a chave não for encontrada
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int chave;

    printf("Digite o número a ser buscado: ");
    scanf("%d", &chave);

    int resultado = buscaLinear(arr, tamanho, chave);

    if (resultado != -1) {
        printf("Número %d encontrado no índice %d.\n", chave, resultado);
    } else {
        printf("Número %d não encontrado no array.\n", chave);
    }

    return 0;
}
