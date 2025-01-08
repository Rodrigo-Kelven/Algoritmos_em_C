#include <stdio.h>

// Função para realizar a busca binária
int buscaBinaria(int arr[], int tamanho, int chave) {
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2; // Evita overflow

        // Verifica se a chave está presente no meio
        if (arr[meio] == chave) {
            return meio; // Retorna o índice onde a chave foi encontrada
        }

        // Se a chave for maior, ignora a metade esquerda
        if (arr[meio] < chave) {
            esquerda = meio + 1;
        }
        // Se a chave for menor, ignora a metade direita
        else {
            direita = meio - 1;
        }
    }

    return -1; // Retorna -1 se a chave não for encontrada
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Array deve estar ordenado
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int chave;

    printf("Digite o número a ser buscado: ");
    scanf("%d", &chave);

    int resultado = buscaBinaria(arr, tamanho, chave);

    if (resultado != -1) {
        printf("Número %d encontrado no índice %d.\n", chave, resultado);
    } else {
        printf("Número %d não encontrado no array.\n", chave);
    }

    return 0;
}
