#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
//
// Created by Fernando,Igor,Vitor on 23/03/2021.
//
#include <stdio.h>
#include "Grafo.h"

Grafo* leitura(char* nomeArquivo);

int main(int argc, char* argv[]){

    Grafo* grafo;

    grafo = leitura(argv[1]);
    //imprimeGrafo(grafo);
    Heap * heap = inicializaHeap(10);
    heap_insert(heap, 12);
    //printHeap(heap);
    heap_insert(heap, 10);
    //printHeap(heap);
    heap_insert(heap, 1);
    //printHeap(heap);
    heap_insert(heap, 2);
    //printHeap(heap);
    heap_insert(heap, 34);
    //printHeap(heap);
    heap_insert(heap, 17);
    //printHeap(heap);
    heap_insert(heap, 8);
    //printHeap(heap);
    heap_insert(heap, 9);
    //printHeap(heap);
    heap_insert(heap, 11);
    //printHeap(heap);
    heap_insert(heap, 5);
    printHeap(heap);
    freeHeap(heap);
    liberaGrafo(grafo);

    return 0;
}

Grafo* leitura(char* nomeArquivo){

    FILE* f = fopen(nomeArquivo,"r");
    if (!f){ perror("Erro ao abrir arquivo de entrada"); exit(1); }

    int nVertices, nArestas;
    int qtdServidor, qtdCliente, qtdMonitor;

    //Lê quantidade de vértices e arestas.
    fscanf(f, "%d %d", &nVertices, &nArestas);
    //Lê quantidade de vértices servidores, clientes e monitores.
    fscanf(f, "%d %d %d", &qtdServidor, &qtdCliente, &qtdMonitor);

    //Inicializa o grafo vazio.
    Grafo* grafo = inicializaGrafo(nVertices, qtdServidor, qtdCliente, qtdMonitor);

    //Insere os vértices servidores.
    for(int i = 0; i < qtdServidor; i++){
        int servidor;
        fscanf(f, "%d", &servidor);
        adicionaServidor(grafo, servidor, i);
    }
    //Insere os vértices clientes.
    for(int i = 0; i < qtdCliente; i++){
        int cliente;
        fscanf(f, "%d", &cliente);
        adicionaCliente(grafo, cliente, i);
    }
    //Insere os vértices monitores.
    for(int i = 0; i < qtdMonitor; i++){
        int monitor;
        fscanf(f, "%d", &monitor);
        adicionaMonitor(grafo, monitor, i);
    }

    Aresta* aresta;

    for(int i=0; i < nArestas; i++){
        int fonte, destino;
        double peso;
        fscanf(f, "%d %d %lf",&fonte, &destino, &peso);
        aresta = iniciaAresta(destino, peso);
        grafoAdicionaAresta(grafo, fonte, aresta);
    }

    fclose(f);
    return grafo;
}

#pragma clang diagnostic pop