#include <stdio.h>
#include <string.h>

void compressRLE(char *input) {
    int n = strlen(input);
    int count;
    
    for (int i = 0; i < n; i++) {
        // Contar o número de ocorrências do caractere atual
        count = 1;
        while (i < n - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        // Imprimir o caractere e sua contagem
        printf("%d%c", count, input[i]);
    }
    printf("\n");
}

int main() {
    char input[] = "AAAABBBCCDAA";
    printf("String original: %s\n", input);
    printf("String comprimida: ");
    compressRLE(input);
    return 0;
}
