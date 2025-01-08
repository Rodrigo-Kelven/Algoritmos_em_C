#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 9 // Número de vértices no grafo

// Função para encontrar o vértice com a distância mínima
int minDistancia(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Função para implementar o algoritmo de Dijkstra
void dijkstra(int grafo[V][V], int origem) {
    int dist[V]; // Array para armazenar a distância mínima de cada vértice
    bool sptSet[V]; // Array para rastrear os vértices incluídos no conjunto de caminhos mais curtos

    // Inicializa todas as distâncias como infinito e sptSet como falso
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // A distância do vértice de origem para ele mesmo é sempre 0
    dist[origem] = 0;

    // Encontra o caminho mais curto para todos os vértices
    for (int count = 0; count < V - 1; count++) {
        // Escolhe o vértice com a distância mínima
        int u = minDistancia(dist, sptSet);
        sptSet[u] = true; // Marca o vértice como processado

        // Atualiza a distância dos vértices adjacentes ao vértice escolhido
        for (int v = 0; v < V; v++) {
            // Atualiza dist[v] se e somente se não estiver em sptSet, há uma aresta de u para v,
            // e a distância total do caminho de origem a v através de u é menor que a distância atual
            if (!sptSet[v] && grafo[u][v] && dist[u] != INT_MAX && dist[u] + grafo[u][v] < dist[v]) {
                dist[v] = dist[u] + grafo[u][v];
            }
        }
    }

    // Imprime a distância mínima de origem a todos os vértices
    printf("Vértice \t Distância da origem\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    // Representação do grafo como uma matriz de adjacência
    int grafo[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(grafo, 0); // Chama o algoritmo de Dijkstra a partir do vértice 0

    return 0;
}
