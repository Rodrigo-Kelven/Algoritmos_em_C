#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5 // Tamanho da grade

// Estrutura para representar uma célula na grade
struct Cell {
    int x, y;
};

// Verifica se a célula (x, y) está dentro da grade e não é um obstáculo
bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// Função para encontrar o caminho mais curto usando o Algoritmo de Lee
void lee(int maze[N][N], struct Cell start, struct Cell end) {
    // Movimentos possíveis (cima, baixo, esquerda, direita)
    int row[] = {-1, 1, 0, 0};
    int col[] = {0, 0, -1, 1};

    // Cria uma matriz para rastrear as distâncias
    int dist[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dist[i][j] = -1; // Inicializa todas as distâncias como -1

    // Inicializa a fila para a BFS
    struct Cell queue[N * N];
    int front = 0, rear = 0;

    // Adiciona a célula inicial à fila e define a distância como 0
    queue[rear++] = start;
    dist[start.x][start.y] = 0;

    while (front < rear) {
        struct Cell current = queue[front++];

        // Se chegamos ao destino, imprimimos a distância
        if (current.x == end.x && current.y == end.y) {
            printf("O caminho mais curto tem comprimento: %d\n", dist[current.x][current.y]);
            return;
        }

        // Explora as células adjacentes
        for (int i = 0; i < 4; i++) {
            int newX = current.x + row[i];
            int newY = current.y + col[i];

            // Se a nova célula é segura e ainda não foi visitada
            if (isSafe(maze, newX, newY) && dist[newX][newY] == -1) {
                dist[newX][newY] = dist[current.x][current.y] + 1; // Atualiza a distância
                queue[rear++] = (struct Cell){newX, newY}; // Adiciona à fila
            }
        }
    }

    printf("Não há caminho disponível.\n");
}

int main() {
    // Representação do labirinto (1 = caminho, 0 = obstáculo)
    int maze[N][N] = {
        {1, 0, 0, 0, 1},
        {1, 1, 0, 1, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 1, 1},
        {1, 0, 0, 0, 1}
    };

    struct Cell start = {0, 0}; // Ponto de partida
    struct Cell end = {4, 4};   // Ponto de destino

    lee(maze, start, end); // Chama o algoritmo de Lee

    return 0;
}
