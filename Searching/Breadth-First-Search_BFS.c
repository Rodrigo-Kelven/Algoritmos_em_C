#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Definindo um tamanho máximo para o grafo

// Este é bastante interessante, coloquei pra fins de estudos, muito interessante!

// Estrutura para representar um nó da lista de adjacência
struct Node {
    int vertice;
    struct Node* proximo;
};

// Estrutura para representar um grafo
struct Grafo {
    int numVertices;
    struct Node** listaAdjacente;
};

// Função para criar um novo nó
struct Node* criarNo(int vertice) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->vertice = vertice;
    novoNo->proximo = NULL;
    return novoNo;
}

// Função para criar um grafo
struct Grafo* criarGrafo(int vertices) {
    struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
    grafo->numVertices = vertices;

    // Criar uma lista de adjacência para cada vértice
    grafo->listaAdjacente = (struct Node**)malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; i++) {
        grafo->listaAdjacente[i] = NULL;
    }
    return grafo;
}

// Função para adicionar uma aresta ao grafo
void adicionarAresta(struct Grafo* grafo, int origem, int destino) {
    // Adiciona a aresta de origem para destino
    struct Node* novoNo = criarNo(destino);
    novoNo->proximo = grafo->listaAdjacente[origem];
    grafo->listaAdjacente[origem] = novoNo;

    // Para um grafo não direcionado, adicione a aresta de destino para origem
    novoNo = criarNo(origem);
    novoNo->proximo = grafo->listaAdjacente[destino];
    grafo->listaAdjacente[destino] = novoNo;
}

// Função para realizar a busca em largura
void buscaEmLargura(struct Grafo* grafo, int inicio) {
    int visitado[MAX] = {0}; // Array para rastrear vértices visitados
    int fila[MAX], frente = 0, tras = 0; // Fila para a BFS

    // Marca o vértice inicial como visitado e o adiciona à fila
    visitado[inicio] = 1;
    fila[tras++] = inicio;

    while (frente < tras) {
        int verticeAtual = fila[frente++]; // Remove o primeiro vértice da fila
        printf("%d ", verticeAtual); // Processa o vértice atual

        // Percorre todos os vértices adjacentes
        struct Node* temp = grafo->listaAdjacente[verticeAtual];
        while (temp) {
            int adjacente = temp->vertice;
            if (!visitado[adjacente]) {
                visitado[adjacente] = 1; // Marca como visitado
                fila[tras++] = adjacente; // Adiciona à fila
            }
            temp = temp->proximo;
        }
    }
}

int main() {
    struct Grafo* grafo = criarGrafo(6); // Criar um grafo com 6 vértices

    // Adicionar arestas
    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 2);
    adicionarAresta(grafo, 1, 3);
    adicionarAresta(grafo, 1, 4);
    adicionarAresta(grafo, 2, 5);

    printf("Busca em Largura a partir do vértice 0:\n");
    buscaEmLargura(grafo, 0);

    return 0;
}
